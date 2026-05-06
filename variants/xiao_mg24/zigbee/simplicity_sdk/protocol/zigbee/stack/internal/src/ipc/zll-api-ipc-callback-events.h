/***************************************************************************//**
 * @file zll-api-ipc-callback-events.h
 * @brief callback struct and event handlers for zll-api
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
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
// automatically generated from zll-api.h.  Do not manually edit
#ifndef ZLL_API_IPC_CALLBACK_EVENTS_H
#define ZLL_API_IPC_CALLBACK_EVENTS_H

#include "stack/internal/inc/zll-api-internal-def.h"

typedef struct {
  sl_zigbee_zll_address_assignment_t addressInfo;
  sl_zigbee_rx_packet_info_t packetInfo;
} sli_zigbee_stack_zll_address_assignment_handler_ipc_event_t;

typedef struct {
  sl_zigbee_zll_network_t networkInfo;
  bool isDeviceInfoNull;
  sl_zigbee_zll_device_info_record_t deviceInfo;
  sl_zigbee_rx_packet_info_t packetInfo;
} sli_zigbee_stack_zll_network_found_handler_ipc_event_t;

typedef struct {
  sl_status_t status;
} sli_zigbee_stack_zll_scan_complete_handler_ipc_event_t;

typedef struct {
  sl_zigbee_zll_network_t networkInfo;
} sli_zigbee_stack_zll_touch_link_target_handler_ipc_event_t;

#endif // ZLL_API_IPC_CALLBACK_EVENTS_H
