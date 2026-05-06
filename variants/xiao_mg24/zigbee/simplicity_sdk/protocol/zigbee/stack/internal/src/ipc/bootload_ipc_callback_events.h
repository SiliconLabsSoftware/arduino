/***************************************************************************//**
 * @file bootload_ipc_callback_events.h
 * @brief callback struct and event handlers for bootload
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
// automatically generated from bootload.h.  Do not manually edit
#ifndef BOOTLOAD_IPC_CALLBACK_EVENTS_H
#define BOOTLOAD_IPC_CALLBACK_EVENTS_H

#include "stack/internal/inc/bootload_internal_def.h"

typedef struct {
  sl_status_t status;
  uint8_t messageLength;
  uint8_t messageContents[MAX_IPC_VEC_ARG_CAPACITY];
} sli_zigbee_stack_bootload_transmit_complete_handler_ipc_event_t;

typedef struct {
  sl_802154_long_addr_t longId;
  sl_zigbee_rx_packet_info_t packetInfo;
  uint8_t messageLength;
  uint8_t messageContents[MAX_IPC_VEC_ARG_CAPACITY];
} sli_zigbee_stack_incoming_bootload_message_handler_ipc_event_t;

#endif // BOOTLOAD_IPC_CALLBACK_EVENTS_H
