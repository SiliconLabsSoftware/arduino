/***************************************************************************//**
 * @file zigbee_common_callback_dispatcher.h
 * @brief ZigBee common dispatcher declarations.
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SL_ZIGBEE_COMMON_CALLBACK_DISPATCHER_H
#define SL_ZIGBEE_COMMON_CALLBACK_DISPATCHER_H

#include PLATFORM_HEADER
#include "stack/include/sl_zigbee.h"

// Event Init
void sli_zigbee_af_event_init(void);
void sli_zigbee_af_zcl_framework_core_init_events_callback(uint8_t init_level);
void sli_zigbee_af_service_discovery_init_events_callback(uint8_t init_level);
void sli_zigbee_af_color_control_server_init_callback(uint8_t init_level);
void sl_zigbee_af_green_power_client_init_cb(uint8_t init_level);
void sl_zigbee_af_interpan_init_cb(uint8_t init_level);
void sli_zigbee_af_network_steering_init_callback(uint8_t init_level);
void sl_zigbee_af_reporting_init_cb(uint8_t init_level);
void sli_zigbee_af_scan_dispatch_init_callback(uint8_t init_level);
void sli_zigbee_af_update_tc_link_key_begin_tc_link_key_update_init(uint8_t init_level);
void sli_zigbee_af_zll_identify_server_init_callback(uint8_t init_level);
// Local data Init
void sli_zigbee_af_local_data_init(void);
void sl_zigbee_af_counters_init_cb(uint8_t init_level);
void sl_zigbee_af_green_power_client_init_cb(uint8_t init_level);
void sl_zigbee_af_interpan_init_cb(uint8_t init_level);
// Init done
void sli_zigbee_af_init_done(void);
void sli_zigbee_af_init_cb(uint8_t init_level);
void sl_zigbee_af_init(uint8_t init_level);
void sl_zigbee_af_green_power_client_init_cb(uint8_t init_level);
void sl_zigbee_af_network_creator_security_init_cb(uint8_t init_level);
void sl_zigbee_af_reporting_init_cb(uint8_t init_level);
void sl_zigbee_af_zll_commissioning_common_init_cb(uint8_t init_level);
void sli_zigbee_af_network_init(uint8_t init_level);

// Tick
void sli_zigbee_af_tick(void);

#endif // SL_ZIGBEE_COMMON_CALLBACK_DISPATCHER_H