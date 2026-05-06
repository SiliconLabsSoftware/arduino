/***************************************************************************//**
 * @file
 * @brief APIs and defines for the Counters plugin.
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

#ifndef SILABS_PLUGIN_COUNTERS_H
#define SILABS_PLUGIN_COUNTERS_H

#include "counters-config.h"
#if (SL_ZIGBEE_AF_PLUGIN_COUNTERS_OTA == 1)
#define OTA_COUNTERS_ENABLED
#endif

#define SL_ZIGBEE_APPLICATION_HAS_COUNTER_ROLLOVER_HANDLER
/**
 * The ith entry in this array is the count of events of sl_zigbee_counter_type_t i.
 */
extern uint16_t sl_zigbee_counters[SL_ZIGBEE_COUNTER_TYPE_COUNT];
/**
 * The ith entry in this array is the count of threshold values set for
 * the corresponding ith event in sl_zigbee_counters. The default value is set to
 * 0xFFFF and can be changed by an application by calling
 * sl_zigbee_set
 */
#ifdef SL_ZIGBEE_APPLICATION_HAS_COUNTER_ROLLOVER_HANDLER
extern uint16_t sl_zigbee_counters_thresholds[SL_ZIGBEE_COUNTER_TYPE_COUNT];
#endif

#if !defined(SL_ZIGBEE_MULTI_NETWORK_STRIPPED)
#define MULTI_NETWORK_COUNTER_TYPE_COUNT 17
/**
 * The value at the position [n,i] in this matrix is the count of events of
 * per-network sl_zigbee_counter_type_t i for network n.
 */
extern uint16_t sl_zigbee_multi_network_counters[SL_ZIGBEE_SUPPORTED_NETWORKS]
[MULTI_NETWORK_COUNTER_TYPE_COUNT];
#endif // SL_ZIGBEE_MULTI_NETWORK_STRIPPED

/** Reset the counters to zero. */
void sl_zigbee_af_counters_clear(void);
/** Resets counter thresholds to 0xFFFF. **/
void sl_zigbee_af_counters_reset_thresholds(void);
/** Set the threshold for a particular counter type **/
void sl_zigbee_af_counters_set_threshold(sl_zigbee_counter_type_t type, uint16_t threshold);

/** @brief Rollover
 *
 * This function is called every time a counter exceeds its threshold.
 *
 * @param type The counter that rolled over Ver.: always
 */
void sl_zigbee_af_counter_rollover_cb(sl_zigbee_counter_type_t type);

#endif // SILABS_PLUGIN_COUNTERS_H
