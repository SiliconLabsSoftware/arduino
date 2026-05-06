/***************************************************************************//**
 * @file
 * @brief A library to tally up Ember stack counter events.
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

#ifndef SILABS_APP_UTIL_COUNTERS_H
#define SILABS_APP_UTIL_COUNTERS_H

/**
 * The ith entry in this array is the count of events of sl_zigbee_counter_type_t i.
 */
extern uint16_t sli_zigbee_counters[SL_ZIGBEE_COUNTER_TYPE_COUNT];
/**
 * The ith entry in this array is the count of threshold values set for
 * the corresponding ith event in sli_zigbee_counters. The default value is set to
 * 0xFFFF and can be changed by an application by calling
 * sl_zigbee_set
 */
#ifdef SL_ZIGBEE_APPLICATION_HAS_COUNTER_ROLLOVER_HANDLER
extern uint16_t sli_zigbee_counters_thresholds[SL_ZIGBEE_COUNTER_TYPE_COUNT];
#endif

#if !defined(SL_ZIGBEE_MULTI_NETWORK_STRIPPED)
#define MULTI_NETWORK_COUNTER_TYPE_COUNT 17
/**
 * The value at the position [n,i] in this matrix is the count of events of
 * per-network sl_zigbee_counter_type_t i for network n.
 */
extern uint16_t sli_zigbee_multi_network_counters[SL_ZIGBEE_MAX_SUPPORTED_NETWORKS]
[MULTI_NETWORK_COUNTER_TYPE_COUNT];
#endif // SL_ZIGBEE_MULTI_NETWORK_STRIPPED

/** Reset the counters to zero. */
sl_status_t sli_zigbee_stack_clear_counters(void);
sl_status_t sli_zigbee_stack_reset_counters_thresholds(void);
sl_status_t sli_zigbee_stack_set_counter_threshold(sl_zigbee_counter_type_t type, uint16_t threshold);
void sl_zigbee_counter_rollover_handler(sl_zigbee_counter_type_t type);

#endif // SILABS_APP_UTIL_COUNTERS_H
