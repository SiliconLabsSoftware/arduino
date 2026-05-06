/*******************************************************************************
 * @file
 * @brief Event System - A publish/subscribe inter-process communication API.
 *******************************************************************************
 * # License
 * <b>Copyright 2023 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#ifndef SL_EVENT_SYSTEM_H
#define SL_EVENT_SYSTEM_H

#include <stdint.h>
#include "cmsis_os2.h"
#include "sl_slist.h"
#include "sl_status.h"
#include "sl_enum.h"
#include "sl_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************//**
 * @addtogroup event-system Event System
 * @brief
 *  A publish/subscribe inter-process communication system.
 *  The source files for the event system software module are present under platform/common.
 *
 * @details
 * ## Overview
 * The event system is a software component enabling the development of event-driven
 * software systems for Simplicity SDK based firmware's by managing publisher creation,
 * event dispatching/filtering and event listening.
 *
 * The event system has multiple types of event classes that subscribers can listen to.
 * Event classes identify the event source from which the event originates such as Bluetooth
 * or Zigbee. See @ref sl_event_class_t.
 *
 * Subclasses further refine the event by offering information related to a particular
 * functionality. A unique bit is assigned to each subclass which will have a specific meaning
 * for each event publisher.
 *
 * ## Initialization
 * The initialization of the event system occurs during the general system initialization.
 * This happens when the application calls the sl_system_init() function. All the basic event system
 * data structures will be initialized along with every publisher available in your project.
 *
 * ## Event subscription
 *
 * The event subscription takes place when the user establishes a communication pipeline
 * between the listener and the publisher by calling @ref sl_event_subscribe.
 * The user shall provide the type of event class that he wants to listen to, an event mask
 * to further refine the set of events that he wants to listen to. Finally, an event queue must
 * be created and initialized by the event listening code by using @ref sl_event_queue_create
 * which will allocate the necessary memory and initialize an event system event queue.
 * This queue is the main communication channel between the publisher and the listener.
 *
 * ## Event notification
 *
 * When a new event is generated, the publisher will enqueue it in the event listener
 * provided queue. At this point, the listener will be able to recover this event by calling
 * @ref sl_event_queue_get function. In the case where no event is ready for processing
 * the calling process will pend on the message queue for a predetermined amount of time.
 * After consuming the event, the @sl_event_process function must be called for each
 * event instance. This will ensure that the memory and resources used by the event
 * data structure is properly deallocated.
 * @{
 ******************************************************************************/

/*******************************************************************************
 *********************************  TYPEDEFS ***********************************
 ******************************************************************************/
typedef osMessageQueueId_t sl_event_queue_t;
typedef void (*sl_event_free_data_cb_t)(void *data);

SL_ENUM(sl_event_class_t) {
  SL_EVENT_CLASS_IRQ,
  SL_EVENT_CLASS_BLUETOOTH,
  SL_EVENT_CLASS_ZIGBEE,
  SL_EVENT_CLASS_BLUETOOTH_MESH,
  SL_EVENT_CLASS_MAX,
};

typedef struct {
  sl_slist_node_t  node;
  uint32_t         event_mask;
  sl_event_queue_t event_queue;
} sl_event_subscriber_t;

typedef struct {
  sl_slist_node_t         node;
  sl_event_class_t        event_class;
  sl_event_free_data_cb_t free_data_callback;
  uint8_t                 subscriber_count;
  sl_slist_node_t         *subscribers;
  bool                    is_registered;
} sl_event_publisher_t;

typedef struct {
  sl_event_free_data_cb_t free_data_callback;
  uint8_t                 reference_count;
  void*                   event_data;
  bool                    pre_allocated;
} sl_event_t;

/*******************************************************************************
 ******************************** PROTOTYPES ***********************************
 ******************************************************************************/

/*******************************************************************************
 * @brief
 *  Initialize the event system.
 ******************************************************************************/
void sl_event_system_init(void);

/*******************************************************************************
 * @brief
 *  Initialize a publisher context and register it in the event system
 *  with a given event class.
 *
 * @description
 *  Only one publisher context is allowed per event class.
 *
 * @param[in] publisher           Pointer to a publisher context.
 * @param[in] event_class         The class of events published by the publisher.
 * @param[in] free_data_callback  Callback to free the publisher's event data.
 *
 * @return
 *    SL_STATUS_OK if successful, otherwise an error code is returned.
 ******************************************************************************/
sl_status_t sl_event_publisher_register(sl_event_publisher_t *publisher,
                                        sl_event_class_t event_class,
                                        sl_event_free_data_cb_t free_data_callback);

/*******************************************************************************
 * @brief
 *  Unregister a publisher context from its event class.
 *
 * @description
 *  When a publisher context is unregistered, it can no longer publish messages
 *  until it is registered again. After a publisher context is unregistered, the
 *  event class it was registered with can be reused.
 *
 * @param[in] publisher           Pointer to a publisher context.
 *
 * @return
 *    SL_STATUS_OK if successful, otherwise an error code is returned.
 ******************************************************************************/
sl_status_t sl_event_publisher_unregister(sl_event_publisher_t *publisher);

/*******************************************************************************
 * @brief
 *  Publish an event, with data, within the event class of the publisher.
 *
 * @param[in] publisher           Pointer to a publisher context.
 * @param[in] event_mask          Event mask corresponding to the type of event.
 * @param[in] event_prio          The priority of the event published.
 * @param[in] event_data          The event data.
 *
 * @return
 *    SL_STATUS_OK if successful, otherwise an error code is returned.
 ******************************************************************************/
sl_status_t sl_event_publish(sl_event_publisher_t *publisher,
                             uint32_t event_mask,
                             uint8_t event_prio,
                             void *event_data);

/*******************************************************************************
 * @brief
 *  Publish an event, with data, with a pre-allocated event handle, within the
 *  event class of the publisher.
 *
 * @param[in] publisher           Pointer to a publisher context.
 * @param[in] event_mask          Event mask corresponding to the type of event.
 * @param[in] event_prio          The priority of the event published.
 * @param[in] event               The pre-allocated event structure handle
 * @param[in] event_data          The event data.
 *
 * @return
 *    SL_STATUS_OK if successful, otherwise an error code is returned.
 ******************************************************************************/
sl_status_t sl_event_publish_static(sl_event_publisher_t *publisher,
                                    uint32_t event_mask,
                                    uint8_t event_prio,
                                    sl_event_t* event,
                                    void *event_data);

/*******************************************************************************
 * @brief
 *  Subscribe to one or more events for a given event class.
 *
 * @description
 *  The subscribed event(s) is/are placed in the queue identified by event_queue.
 *
 * @param[in] event_class    The class of events to subscribe to.
 * @param[in] event_mask     The event(s) to subscribe to.
 * @param[in] event_queue    The identifier of an event queue.
 *
 * @return
 *    SL_STATUS_OK if successful, otherwise an error code is returned.
 ******************************************************************************/
sl_status_t sl_event_subscribe(sl_event_class_t event_class,
                               uint32_t event_mask,
                               sl_event_queue_t event_queue);

/*******************************************************************************
 * @brief
 *  Unsubscribe from one or more events for a given event class.
 *
 * @description
 *  The unsubscribed event(s) will no longer be placed in the queue identified
 *  by event_queue.
 *
 * @param[in] event_class    The class of events to subscribe to.
 * @param[in] event_mask     The event(s) to subscribe to.
 * @param[in] event_queue    The identifier of an event queue.
 *
 * @return
 *    SL_STATUS_OK if successful, otherwise an error code is returned.
 ******************************************************************************/
sl_status_t sl_event_unsubscribe(sl_event_class_t event_class,
                                 uint32_t event_mask,
                                 sl_event_queue_t event_queue);

/*******************************************************************************
 * @brief
 *  Signal to the event system that a subscriber has processed an event.
 *
 * @description
 *  This must be called by subscribers after consuming an event so that the
 *  event data may eventually be freed. The event reference passed to this
 *  function is nullified before returning.
 *
 * @param[in] event          Pointer to an event reference.
 *
 * @return
 *    SL_STATUS_OK if successful, otherwise an error code is returned.
 ******************************************************************************/
sl_status_t sl_event_process(sl_event_t **event);

/*******************************************************************************
 * @brief
 *  Create an event queue.
 *
 * @param[in]  event_count    The maximum number of events in the event queue.
 * @param[out] event_queue    The event queue that is created.
 *
 * @return
 *    SL_STATUS_OK if successful, otherwise an error code is returned.
 ******************************************************************************/
sl_status_t sl_event_queue_create(uint32_t event_count,
                                  sl_event_queue_t *event_queue);

/*******************************************************************************
 * @brief
 *  Delete an event queue.
 *
 * @param[in] event_queue   The event queue to delete.
 *
 *  @return
 *    SL_STATUS_OK if successful, otherwise an error code is returned.
 *
 * @note
 *    In the process of deleting an event queue, all events that the queue
 *    was subscribed to will be unsubscribed from.
 ******************************************************************************/
sl_status_t sl_event_queue_delete(sl_event_queue_t event_queue);

/*******************************************************************************
 * @brief
 *  Get an event from an event queue.
 *
 * @param[in]  event_queue  The identifier of an event queue.
 * @param[in]  event_prio   The priority of event(s) to get.
 * @param[in]  timeout      Maximum time to pend on the event queue.
 * @param[out] event        The event reference retrieved from the event queue.
 *
 * @return
 *    SL_STATUS_OK if successful, otherwise an error code is returned.
 ******************************************************************************/
sl_status_t sl_event_queue_get(sl_event_queue_t event_queue,
                               uint8_t *event_prio,
                               uint32_t timeout,
                               sl_event_t **event);

/*******************************************************************************
 * @brief
 *  Get the size of the event publisher structure.
 *
 * @return              Size of the event publisher structure.
 ******************************************************************************/
size_t sl_event_publisher_get_size(void);

/*******************************************************************************
 * @brief
 *  Allocate the publisher structure to the heap using the common memory
 *  manager with a long-term lifespan.
 *
 * @param[in] publisher    address of a pointer to a publisher context
 *
 * @return
 *    SL_STATUS_OK if successful, otherwise an error code is returned.
 ******************************************************************************/
sl_status_t sl_event_publisher_alloc(sl_event_publisher_t **publisher);

/*******************************************************************************
 * @brief
 *  Free a publisher context structure from the heap, as well as its list of
 *  subscriber entries using the common memory manager.
 *
 * @description
 *  Using this function to free a publisher context will also free its list of
 *  subscribers, which will cause subscribers to no longer receive events from
 *  the publisher context's event class.
 *
 * @param[in] publisher    address of a pointer to a publisher context
 *
 * @return
 *    SL_STATUS_OK if successful, otherwise an error code is returned.
 ******************************************************************************/
sl_status_t sl_event_publisher_free(sl_event_publisher_t *publisher);

/*******************************************************************************
 * @brief
 *  Get the size of the event structure.
 *
 * @return              Size of the event structure.
 ******************************************************************************/
size_t sl_event_get_size(void);

/*******************************************************************************
 * @brief
 *  Allocate the event structure to the heap using the common memory
 *  manager with a long-term lifespan.
 *
 * @param[in] event    address of a pointer to an event struct
 *
 * @return
 *    SL_STATUS_OK if successful, otherwise an error code is returned.
 ******************************************************************************/
sl_status_t sl_event_alloc(sl_event_t **event);

/*******************************************************************************
 * @brief
 *  Free an event structure from the heap using the common memory manager.
 *
 * @note
 *  Freeing an event structure that has not yet been processed by all
 *  subscribers will
 *
 * @param[in] event    address of a pointer to an event struct
 *
 * @return
 *    SL_STATUS_OK if successful, otherwise an error code is returned.
 ******************************************************************************/
sl_status_t sl_event_free(sl_event_t *event);

/** @} (end addtogroup event-system) */

#ifdef __cplusplus
}
#endif

#endif /* SL_EVENT_SYSTEM_H */
