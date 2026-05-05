/***************************************************************************//**
 * @file
 * @brief schedulable events
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef SILABS_EVENT_QUEUE_H
#define SILABS_EVENT_QUEUE_H

// Forward declarations to make up for C's one-pass type checking.
struct Event_s;
struct EventQueue_s;

// We use this instead of NULL at the end of a list so that unscheduled
// events can be marked by having a 'next' field of NULL.  This makes them
// easier to initialize.
#define EVENT_QUEUE_LIST_END ((sli_zigbee_event_t *) 1)

/** @brief The static part of an event.  Each event can be used with only one
 * event queue.
 */

typedef struct {
  struct EventQueue_s *queue;           // the queue this event goes on
  void (*handler)(struct Event_s *);    // called when the event fires
  void (*marker)(struct Event_s *);     // marking function, can be NULL
  const char *name;                     // event name for debugging purposes
} EmberEventActions;

typedef struct Event_s {
  EmberEventActions actions;            // static data

  // For internal use only, but the 'next' field must be initialized
  // to NULL.
  struct Event_s *next;
  uint32_t timeToExecute;

  // Owned by zigbee, do not touch
  uint32_t data;                        // a generic 4-byte data field

  // Owned by the end user
  void *dataPtr;                        // a generic pointer
} sli_zigbee_event_t;

/** @brief An event queue is currently just a list of events ordered by
 * execution time.
 */
typedef struct EventQueue_s {
  sli_zigbee_event_t *isrEvents;
  sli_zigbee_event_t *events;
  uint32_t runTime;
  bool running;
} sli_zigbee_event_queue_t;

/**
 * @addtogroup event
 *
 * @{

 * An event queue is a queue of events that will be run at some future time(s).
 * The Event type is declared in sl_zigbee_types.h and has three fields:
 *
   @verbatim
   EmberEventActions *actions;      // see below
   sli_zigbee_event_t *next;                // internal use only, but must be
                                    //  initialized to NULL
   uint32_t timeToExecute;       // internal use only
   @endverbatim
 *
 * The EmberEventAction struct also has three fields:
 *
   @verbatim
   struct EventQueue_s *queue; // the queue this event goes on
   void (*handler)(Event *);   // called when the event fires
   void (*marker)(Event *);    // marking fuction, can be NULL
   @endverbatim
 *
 * The marker function is needed if an event refers to a buffer or is
 * itself a buffer; see the dynamic event example below.
 *
 *
 * Sample static event declaration:
 *
   @verbatim
   static void fooEventHandler(Event *event);
   static EmberEventActions fooEventActions = {
   &emStackEventQueue,
   fooEventHandler,
   NULL          // no marking function is needed
   };

   Initialize the event as unscheduled.
   static sli_zigbee_event_t fooEvent = { &fooEventActions, NULL };

   static void fooEventHandler(Event *event)
   {
   ...
   }
   @endverbatim
 *
 * Sample dynamic event:
   @verbatim

   typedef struct {
   sli_zigbee_event_t event;
   sli_zigbee_packet_header_t someBuffer;
   // plus other values as needed
   } BarEvent;

   static void barEventHandler(BarEvent *event);
   static void barEventMarker(BarEvent *event);

   static EmberEventActions barEventActions = {
   &emStackEventQueue,
   (void (*)(Event *)) barEventHandler,
   (void (*)(Event *)) barEventMarker // required for all dynamic events
   };

   static void barEventHandler(BarEvent *event)
   {
   ...
   };

   static void barEventMarker(BarEvent *event)
   {
   // The Buffer that holds BarEvent itself is not marked, but any Buffers
   // within the BarEvent must be marked.  If BarEvent doesn't contain any
   // Buffers, the marking function is still required, but will be empty.
   emMarkBuffer(&event->someBuffer);
   }

   static void addBarEvent(sli_buffer_manager_buffer_t someBuffer, uint32_t delayMs)
   {
   sli_buffer_manager_buffer_t eventBuffer = emAllocateBuffer(sizeof(BarEvent));
   if (eventBuffer == NULL_BUFFER) {
     return;
   }
   BarEvent *barEvent = (BarEvent *) emGetBufferPointer(eventBuffer);
   barEvent->event.actions = &barEventActions;
   barEvent->event.next = NULL;       // initialize as unscheduled
   barEvent->someBuffer = someBuffer;
   sli_zigbee_event_set_delay_ms((Event *) barEvent, delayMs);
   }
   @endverbatim

 * Cancelling a dynamic event:
   @verbatim

   static bool barEventPredicate(sli_zigbee_event_t *event,
                                 void *castBuffer)
   {
   return (((BarEvent *) event)->someBuffer) == (sli_buffer_manager_buffer_t) castBuffer;
   }

   static void cancelBarEvent(sli_buffer_manager_buffer_t someBuffer)
   {
   sli_zigbee_find_event(&emStackEventQueue,
                  &barEventActions,
                  barEventPredicate,
                  (void *) someBuffer);
   }
   @endverbatim
 * Delays greater than this will cause the scheduled execution time to
 * wrap around into the past and the event will be executed immediately.
 *
 * Event Queue operations
 */

#define SL_ZIGBEE_MAX_EVENT_DELAY_MS (HALF_MAX_INT32U_VALUE - 1)

/**
 * Marker function for ISR event types.  Events that are scheduled from
 * ISR context must use this as their marker function (and must not
 * required an actual marker function.
 *
 * Events with this in their type may only be scheduled with a zero delay.
 */
void sli_zigbee_isr_event_marker(struct Event_s *event);

/**
 * Initialize 'queue'.  This must be called before any use of 'queue'
 * or any of its events.
 */
void sli_zigbee_initialize_event_queue(sli_zigbee_event_queue_t *queue);

/**
 * Unschedule all the events.
 */
void sli_zigbee_cancel_all_events(sli_zigbee_event_queue_t *queue);

/**
 * Return the number of milliseconds until the next event fires, or -1 if
 * there are no scheduled events.
 */
uint32_t sli_zigbee_ms_to_next_queue_event(sli_zigbee_event_queue_t *queue);

/**
 * Run any and all events which have fired since the last time this queue's
 * events were run.
 */
void sli_zigbee_run_event_queue(sli_zigbee_event_queue_t *queue);

/**
 * If any scheduled events have mark functions, mark those events, if
 * they are buffers, and call the mark functions.
 */
void sli_zigbee_mark_event_queue(sli_zigbee_event_queue_t *queue);

/**
 * Returns the first scheduled event that has 'actions' and for which
 * 'predicate' returns true.  The returned event has been cancelled.
 */
#define sli_zigbee_find_event(queue, actions, predicate, data) \
  (emFindEvents((queue), &(actions), (predicate), (data), false))

/**
 * Returns the scheduled events that have 'actions' and for which
 * 'predicate' returns true.  If 'predicate' is NULL then all events
 * that have 'actions' are returned.  The returned events are linked
 * through the 'next' field and have been cancelled.
 *
 * WARNING: the 'next' field of the returned events must be set to
 * NULL before the event is passed to any event operation.
 */

#define sli_zigbee_find_all_events(queue, actions, predicate, data) \
  (emFindEvents((queue), &(actions), (predicate), (data), true))

typedef bool (*EmberEventPredicate)(sli_zigbee_event_t *, void *);

sli_zigbee_event_t *emFindEvents(sli_zigbee_event_queue_t *queue,
                                 EmberEventActions *actions,
                                 EmberEventPredicate predicate,
                                 void *data,
                                 bool all);

/**
 * Returns the first scheduled event that has 'actions' and for which
 * 'predicate' returns true.  The returned event is not cancelled.
 */
sli_zigbee_event_t *emFindEventWithoutRemoving(sli_zigbee_event_queue_t *queue,
                                               EmberEventActions *actions,
                                               EmberEventPredicate predicate,
                                               void *data);

/**
 * Event operations
 */

/**
 * Schedule 'event' to run after 'delay' milliseconds.  Delays greater than
 * SL_ZIGBEE_MAX_EVENT_DELAY_MS will be reduced to SL_ZIGBEE_MAX_EVENT_DELAY_MS.
 */
void sli_zigbee_event_set_delay_ms(sli_zigbee_event_t *event, uint32_t delay);

/**
 * Schedule 'event' to run immediately.
 */
#define sli_zigbee_event_set_active(event) sli_zigbee_event_set_delay_ms((event), 0)

/**
 * Cancel 'event'.
 */
void sli_zigbee_event_set_inactive(sli_zigbee_event_t *event);

/**
 * Return true if the event is scheduled to run.
 */
bool sli_zigbee_event_is_scheduled(sli_zigbee_event_t *event);

/**
 * Return true if the event queue is empty.
 */
bool sli_zigbee_event_queue_is_empty(sli_zigbee_event_queue_t *queue);

/**
 * Return the number of milliseconds before 'event' runs, or -1 if 'event'
 * is not scheduled to run.
 */
uint32_t sli_zigbee_event_get_remaining_ms(sli_zigbee_event_t *event);

/**
 * @}
 */

#endif // SILABS_EVENT_QUEUE_H
