/***************************************************************************//**
 * @file network-formation-ipc-callback-events.h
 * @brief callback struct and event handlers for network-formation
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
// automatically generated from network-formation.h.  Do not manually edit
#ifndef NETWORK_FORMATION_IPC_CALLBACK_EVENTS_H
#define NETWORK_FORMATION_IPC_CALLBACK_EVENTS_H

#include "stack/internal/inc/network-formation-internal-def.h"

typedef struct {
  uint8_t channel;
  int8_t maxRssiValue;
} sli_zigbee_stack_energy_scan_result_handler_ipc_event_t;

typedef struct {
  sl_zigbee_zigbee_network_t networkFound;
  uint8_t lqi;
  int8_t rssi;
} sli_zigbee_stack_network_found_handler_ipc_event_t;

typedef struct {
  sl_802154_long_addr_t longId;
} sli_zigbee_stack_orphan_notification_handler_ipc_event_t;

typedef struct {
  uint8_t channel;
  sl_status_t status;
} sli_zigbee_stack_scan_complete_handler_ipc_event_t;

typedef struct {
  sl_802154_pan_id_t panId;
  uint8_t channel;
} sli_zigbee_stack_unused_pan_id_found_handler_ipc_event_t;

#endif // NETWORK_FORMATION_IPC_CALLBACK_EVENTS_H
