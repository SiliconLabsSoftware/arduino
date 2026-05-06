/***************************************************************************//**
 * @file raw-message-ipc-callback-events.h
 * @brief callback struct and event handlers for raw-message
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
// automatically generated from raw-message.h.  Do not manually edit
#ifndef RAW_MESSAGE_IPC_CALLBACK_EVENTS_H
#define RAW_MESSAGE_IPC_CALLBACK_EVENTS_H

#include "stack/internal/inc/raw-message-internal-def.h"

typedef struct {
  uint8_t filterIndexMatch;
  uint8_t legacyPassthroughType;
  sl_zigbee_rx_packet_info_t packetInfo;
  uint8_t messageLength;
  uint8_t messageContents[MAX_IPC_VEC_ARG_CAPACITY];
} sli_802154_stack_filter_match_message_handler_ipc_event_t;

typedef struct {
  sl_zigbee_mac_passthrough_type_t messageType;
  sl_zigbee_rx_packet_info_t packetInfo;
  uint8_t messageLength;
  uint8_t messageContents;
} sli_802154_stack_passthrough_message_handler_ipc_event_t;

typedef struct {
  uint8_t message;
  uint8_t messageContents;
  sl_status_t status;
} sli_zigbee_stack_raw_transmit_complete_handler_ipc_event_t;

#endif // RAW_MESSAGE_IPC_CALLBACK_EVENTS_H
