/***************************************************************************//**
 * @file zigbee_app_framework_event.h
 * @brief Zigbee Application Framework Event releated macros and definitions.
 *******************************************************************************
 * # License
 * <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef ZIGBEE_APP_FRAMEWORK_EVENT_H
#define ZIGBEE_APP_FRAMEWORK_EVENT_H

#include PLATFORM_HEADER
#include "event_queue/event-queue.h"
#include "stack/include/sl_zigbee_types.h"

#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif // SL_COMPONENT_CATALOG_PRESENT

#ifdef SL_CATALOG_ZIGBEE_CORE_CLI_PRESENT
#include "zigbee_core_cli_config.h"
#endif // SL_CATALOG_ZIGBEE_CORE_CLI_PRESENT

#ifdef SL_CATALOG_KERNEL_PRESENT
#include "cmsis_os2.h"
#include "sl_cmsis_os2_common.h"
#endif // SL_CATALOG_KERNEL_PRESENT

/**
 * @brief  ZigBee App Framework Event.
 */
typedef sli_zigbee_event_t sl_zigbee_af_event_t;

void sli_zigbee_af_event_set_delay_ms(sl_zigbee_af_event_t *event, uint8_t endpoint, uint32_t delay);
void sli_zigbee_af_event_set_active(sl_zigbee_af_event_t *event, uint8_t endpoint);
void sli_zigbee_af_event_set_inactive(sl_zigbee_af_event_t *event, uint8_t endpoint);
uint32_t sli_zigbee_af_event_get_remaining_ms(sl_zigbee_af_event_t *event, uint8_t endpoint);
bool sli_zigbee_af_event_is_scheduled(sl_zigbee_af_event_t *event, uint8_t endpoint);

/**
 * @defgroup zigbee_event Event System
 * @ingroup af
 * @brief Zigbee event system API
 *
 * See zigbee_app_framework_event.h for source code.
 *
 */

/**
 * @addtogroup zigbee_event
 *
 * Following a brief usage example that demonstrate how to create an event,
 * initialize it and use it. In this example, the event is initialized and set
 * to pending, then it gets rescheduled every second.
 *
 * @code
 * // Declare event as global
 * sl_zigbee_af_event_t my_event;
 * sl_zigbee_af_event_t my_isr_event;
 *
 * void SOME_IRQHandler(void)
 * {
 *    // Activates the ISR type event from IRQ Handler.
 *    sl_zigbee_af_event_set_active(&my_isr_event);
 * }
 *
 * void my_isr_event_handler(sl_zigbee_af_event_t *event)
 * {
 *    // Event expired, do something
 * }
 *
 * void my_event_hendler(sl_zigbee_af_event_t *event)
 * {
 *    // Event expired, do something
 *
 *    // Reschedule the event to expire again in 1 second
 *    sl_zigbee_af_event_set_delay_ms(&my_event, 1000);
 * }
 *
 * void app_init(void)
 * {
 *    // Initialize event
 *    sl_zigbee_af_event_init(&my_event, my_event_handler);
 *
 *    // Initialise an event type that can be activated from the ISR.
 *    sl_zigbee_af_isr_event_init(&my_isr_event, my_isr_event_handler);
 *
 *    // Set the event to expire immediately (that is, in the next iteration of the main loop)
 *    sl_zigbee_af_event_set_active(&my_event);
 * }
 * @endcode
 *
 * @{
 */

/** @name API */
// @{

/** @brief Application event initialization routine for events intended to be activated in ISR.
 * An event that is activated in ISR context must be initialized using this API.
 * Such event can only be scheduled to expire immediately using \ref sl_zigbee_af_event_set_active.
 * The event handler will be executed from DSR context either from the application main loop in
 * a bare metal setup or in the Application Framework Task main loop in an OS setup.
 * Any attempt to schedule a non zero delay or deactivation for an event initialized as ISR event
 * will result in an assert.
 *
 * @param[in] event  A pointer to the \ref sl_zigbee_af_event_t object to be
 *                   initialized. Event objects must be global.
 *
 * @param[in] handler Handler function that shall be called when the event runs.
 */
void sl_zigbee_af_isr_event_init(sl_zigbee_af_event_t *event,
                                 void (*handler)(sl_zigbee_af_event_t *));

#if defined(DOXYGEN_SHOULD_SKIP_THIS)
/** @brief Application event initialization routine. Every application event
 * must be initialized.
 *
 * @param[in] event  A pointer to the \ref sl_zigbee_af_event_t object to be
 *                   initalized. Event objects must be global.
 *
 * @param[in] handler Handler function that shall be called when the event runs.
 */
void sl_zigbee_af_event_init(sl_zigbee_af_event_t *event,
                             void (*handler)(sl_zigbee_af_event_t *));
#else
#if (SL_ZIGBEE_EVENT_DEBUG_ENABLED)
  #define sl_zigbee_af_event_init(event, handler) \
  sli_zigbee_af_event_internal_init((event), (#event), (void *)(handler), 0xFF, 0xFF)
#else
  #define sl_zigbee_af_event_init(event, handler) \
  sli_zigbee_af_event_internal_init((event), NULL, (void *)(handler), 0xFF, 0xFF)
#endif // SL_ZIGBEE_EVENT_DEBUG_ENABLED
#endif // DOXYGEN_SHOULD_SKIP_THIS

#if defined(DOXYGEN_SHOULD_SKIP_THIS)
/** @brief Schedule an event to run after a delay expressed in milliseconds.
 *
 * @param[in] event  A pointer to the \ref sl_zigbee_af_event_t object to be
 *                   scheduled to run after a delay.
 *
 * @param[in] delay  The delay in milliseconds after which the event shall run.
 */
void sl_zigbee_af_event_set_delay_ms(sl_zigbee_af_event_t *event, uint32_t delay);
#else
#define sl_zigbee_af_event_set_delay_ms(event, delay) \
  sli_zigbee_af_event_set_delay_ms((event), (0xFF), (delay))
#endif // DOXYGEN_SHOULD_SKIP_THIS

#if defined(DOXYGEN_SHOULD_SKIP_THIS)
/** @brief Schedule an event to run immediately.
 *
 * @param[in] event  A pointer to the \ref sl_zigbee_af_event_t object to be
 *                   scheduled to run immediately.
 */
void sl_zigbee_af_event_set_active(sl_zigbee_af_event_t *event);
#else
#define sl_zigbee_af_event_set_active(event) \
  sli_zigbee_af_event_set_active((event), 0xFF)
#endif // DOXYGEN_SHOULD_SKIP_THIS

#if defined(DOXYGEN_SHOULD_SKIP_THIS)
/** @brief Cancel an event.
 *
 * @param[in] event  A pointer to the \ref sl_zigbee_af_event_t object to be
 *                   cancelled.
 */
void sl_zigbee_af_event_set_inactive(sl_zigbee_af_event_t *event);
#else
#define sl_zigbee_af_event_set_inactive(event) \
  sli_zigbee_af_event_set_inactive((event), 0xFF)
#endif // DOXYGEN_SHOULD_SKIP_THIS

#if defined(DOXYGEN_SHOULD_SKIP_THIS)
/** @brief Returns true if the event is scheduled to run, false otherwise.
 *
 * @param[in] event  A pointer to an \ref sl_zigbee_af_event_t object.
 *
 * @return \b true if the passed event is scheduled to run, \b false otherwise.
 */
bool sl_zigbee_af_event_is_scheduled(sl_zigbee_af_event_t *event);
#else
#define sl_zigbee_af_event_is_scheduled(event) \
  sli_zigbee_af_event_is_scheduled((event), 0xFF)
#endif // DOXYGEN_SHOULD_SKIP_THIS

#if defined(DOXYGEN_SHOULD_SKIP_THIS)
/** @brief Returns the number of milliseconds before the event runs, or -1 if
 * the event is not scheduled to run.
 *
 * @param[in] event  A pointer to an \ref sl_zigbee_af_event_t object.
 *
 * @return The number of milliseconds before the event runs, or -1 if the event
 *         is not scheduled to run.
 */
uint32_t sl_zigbee_af_event_get_remaining_ms(sl_zigbee_af_event_t *event);
#else
#define sl_zigbee_af_event_get_remaining_ms(event) \
  sli_zigbee_af_event_get_remaining_ms((event), 0xFF)
#endif // DOXYGEN_SHOULD_SKIP_THIS

/** @} */ // end of name API
/** @} */ // end of zigbee_event

//------------------------------------------------------------------------------
// Internal

#if !defined(DOXYGEN_SHOULD_SKIP_THIS)

// The data field is currently utilized as follows:
// byte 0 is a control field, whereas:
// - bit 0 is a flag indicating whether the event is multiplexed by network
// - bit 1 is a flag indicating whether the event is multiplexed by endpoint
// - bits [2-3] are used to store the network index (if the event is multiplexed
//              by network)
// - bits [4-7] are currently unused
// byte 1 is used to store the endpoint (if the event is multiplexed by endpoint)
// bytes [2-3] are unused
#define SLI_ZIGBEE_EVENT_CONTROL_FIELD_MASK             0x000000FFu
#define SLI_ZIGBEE_EVENT_CONTROL_FIELD_OFFSET           0u
#define SLI_ZIGBEE_EVENT_CONTROL_IS_NETWORK_EVENT_BIT   0x01u
#define SLI_ZIGBEE_EVENT_CONTROL_IS_ENDPOINT_EVENT_BIT  0x02u
#define SLI_ZIGBEE_EVENT_CONTROL_NETWORK_INDEX_MASK     0x0Cu
#define SLI_ZIGBEE_EVENT_CONTROL_NETWORK_INDEX_OFFSET   2u
#define SLI_ZIGBEE_EVENT_CONTROL_UNUSED_MASK            0xF0u
#define SLI_ZIGBEE_EVENT_ENDPOINT_FIELD_MASK            0x0000FF00u
#define SLI_ZIGBEE_EVENT_ENDPOINT_FIELD_OFFSET          8u

#define sli_zigbee_af_event_get_control_field(event)               \
  ((uint8_t)(((event)->data & SLI_ZIGBEE_EVENT_CONTROL_FIELD_MASK) \
             >> SLI_ZIGBEE_EVENT_CONTROL_FIELD_OFFSET))

#define sli_zigbee_af_event_set_control_field(event, control)                         \
  do {                                                                                \
    (event)->data &= ~SLI_ZIGBEE_EVENT_CONTROL_FIELD_MASK;                            \
    (event)->data |= (((uint8_t)(control)) << SLI_ZIGBEE_EVENT_CONTROL_FIELD_OFFSET); \
  } while (0)

#define sli_zigbee_af_event_is_network_event(event) \
  ((sli_zigbee_af_event_get_control_field(event)    \
    & SLI_ZIGBEE_EVENT_CONTROL_IS_NETWORK_EVENT_BIT) > 0)

#define sli_zigbee_af_event_set_network_event(event)                                          \
  do {                                                                                        \
    uint8_t control = sli_zigbee_af_event_get_control_field(event);                           \
    sli_zigbee_af_event_set_control_field((event),                                            \
                                          (control                                            \
                                           | SLI_ZIGBEE_EVENT_CONTROL_IS_NETWORK_EVENT_BIT)); \
  } while (0)

#define sli_zigbee_af_event_is_endpoint_event(event) \
  ((sli_zigbee_af_event_get_control_field(event)     \
    & SLI_ZIGBEE_EVENT_CONTROL_IS_ENDPOINT_EVENT_BIT) > 0)

#define sli_zigbee_af_event_set_endpoint_event(event)                                          \
  do {                                                                                         \
    uint8_t control = sli_zigbee_af_event_get_control_field(event);                            \
    sli_zigbee_af_event_set_control_field((event),                                             \
                                          (control                                             \
                                           | SLI_ZIGBEE_EVENT_CONTROL_IS_ENDPOINT_EVENT_BIT)); \
  } while (0)

#define sli_zigbee_af_event_get_network_index(event)         \
  ((uint8_t)((sli_zigbee_af_event_get_control_field(event)   \
              & SLI_ZIGBEE_EVENT_CONTROL_NETWORK_INDEX_MASK) \
             >> SLI_ZIGBEE_EVENT_CONTROL_NETWORK_INDEX_OFFSET))

#define sli_zigbee_af_event_set_network_index(event, network_index)                                \
  do {                                                                                             \
    uint8_t control = sli_zigbee_af_event_get_control_field(event);                                \
    sli_zigbee_af_event_set_control_field((event),                                                 \
                                          (control                                                 \
                                           | ((network_index)                                      \
                                              << SLI_ZIGBEE_EVENT_CONTROL_NETWORK_INDEX_OFFSET))); \
  } while (0)

#define sli_zigbee_af_event_get_endpoint(event)                     \
  ((uint8_t)(((event)->data & SLI_ZIGBEE_EVENT_ENDPOINT_FIELD_MASK) \
             >> SLI_ZIGBEE_EVENT_ENDPOINT_FIELD_OFFSET))

#define sli_zigbee_af_event_set_endpoint(event, endpoint)                               \
  do {                                                                                  \
    (event)->data &= ~SLI_ZIGBEE_EVENT_ENDPOINT_FIELD_MASK;                             \
    (event)->data |= (((uint8_t)(endpoint)) << SLI_ZIGBEE_EVENT_ENDPOINT_FIELD_OFFSET); \
  } while (0)

void sli_zigbee_af_event_internal_init(sl_zigbee_af_event_t *event,
                                       const char* event_name,
                                       void *handler,
                                       uint8_t network_index,
                                       uint8_t endpoint);

sl_zigbee_af_event_t* sli_zigbee_af_event_get_event_ptr(sl_zigbee_af_event_t *event,
                                                        uint8_t endpoint);
void sli_zigbee_af_event_network_event_init(sl_zigbee_af_event_t *event,
                                            const char* event_name,
                                            void (*handler)(sl_zigbee_af_event_t *));

extern sli_zigbee_event_queue_t sli_zigbee_af_app_event_queue;
#define sl_zigbee_af_event_set_delay_qs(event, delay) \
  sli_zigbee_af_event_set_delay_ms((event), (0xFF), ((delay) * 250u))

// For conversion from minutes to ms, multiply by 60,000 instead of << 16
// This leads to a 10% difference between the time requested vs the actual time
// leading to a large discrepancy for longer delays
#define sl_zigbee_af_event_set_delay_minutes(event, delay) \
  sli_zigbee_af_event_set_delay_ms((event), (0xFF), ((delay) * 60000u))

#define sl_zigbee_af_endpoint_event_set_delay_ms(event, endpoint, delay) \
  sli_zigbee_af_event_set_delay_ms((event), (endpoint), (delay))

#define sl_zigbee_af_endpoint_event_set_delay_qs(event, endpoint, delay) \
  sli_zigbee_af_event_set_delay_ms((event), (endpoint), ((delay) * 250u))

// For conversion from minutes to ms, multiply by 60,000 instead of << 16
// This leads to a 10% difference between the time requested vs the actual time
// leading to a large discrepancy for longer delays
#define sl_zigbee_af_endpoint_event_set_delay_minutes(event, endpoint, delay) \
  sli_zigbee_af_event_set_delay_ms((event), (endpoint), ((delay) * 60000u))

#define sl_zigbee_af_endpoint_event_get_remaining_ms(event, endpoint) \
  sli_zigbee_af_event_get_remaining_ms((event), (endpoint))

#define sl_zigbee_af_endpoint_event_is_scheduled(event, endpoint) \
  sli_zigbee_af_event_is_scheduled((event), (endpoint))

#define sl_zigbee_af_endpoint_event_set_active(event, endpoint) \
  sli_zigbee_af_event_set_active((event), (endpoint))

#define sl_zigbee_af_endpoint_event_set_inactive(event, endpoint) \
  sli_zigbee_af_event_set_inactive((event), (endpoint))

uint32_t sli_zigbee_af_ms_to_next_event();
void sli_zigbee_af_run_events();

#if (SL_ZIGBEE_EVENT_DEBUG_ENABLED)
  #define sl_zigbee_af_endpoint_event_init(event, handler, endpoint) \
  sli_zigbee_af_event_internal_init((event), (#event), (void *)(handler), 0xFF, (endpoint))

  #define sl_zigbee_af_network_event_init(event, handler) \
  sli_zigbee_af_event_network_event_init((event), (#event), (handler))
#else
  #define sl_zigbee_af_endpoint_event_init(event, handler, endpoint) \
  sli_zigbee_af_event_internal_init((event), NULL, (void *)(handler), 0xFF, (endpoint))

  #define sl_zigbee_af_network_event_init(event, handler) \
  sli_zigbee_af_event_network_event_init((event), NULL, (handler))
#endif // SL_ZIGBEE_EVENT_DEBUG_ENABLED

#endif // !DOXYGEN_SHOULD_SKIP_THIS

#endif // ZIGBEE_APP_FRAMEWORK_EVENT_H
