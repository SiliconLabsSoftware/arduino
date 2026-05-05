/***************************************************************************//**
 * @file message_ipc_callback_events.h
 * @brief callback struct and event handlers for message
 *******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories Inc. www.silabs.com</b>
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
// automatically generated from message.h.  Do not manually edit
#ifndef MESSAGE_IPC_CALLBACK_EVENTS_H
#define MESSAGE_IPC_CALLBACK_EVENTS_H

#include "stack/internal/inc/message_internal_def.h"

typedef struct {
  sl_zigbee_gp_status_t status;
  uint8_t gpdLink;
  uint8_t sequenceNumber;
  sl_zigbee_gp_address_t addr;
  sl_zigbee_gp_security_level_t gpdfSecurityLevel;
  sl_zigbee_gp_key_type_t gpdfSecurityKeyType;
  bool autoCommissioning;
  uint8_t bidirectionalInfo;
  uint32_t gpdSecurityFrameCounter;
  uint8_t gpdCommandId;
  uint32_t mic;
  uint8_t proxyTableIndex;
  uint8_t gpdCommandPayloadLength;
  uint8_t gpdCommandPayload[MAX_IPC_VEC_ARG_CAPACITY];
  sl_zigbee_rx_packet_info_t packetInfo;
} sli_zigbee_stack_gpep_incoming_message_handler_ipc_event_t;

typedef struct {
  sl_802154_short_addr_t conflictingId;
} sli_zigbee_stack_id_conflict_handler_ipc_event_t;

typedef struct {
  sl_802154_short_addr_t source;
  sl_802154_long_addr_t longId;
  uint8_t cost;
} sli_zigbee_stack_incoming_many_to_one_route_request_handler_ipc_event_t;

typedef struct {
  sl_zigbee_incoming_message_type_t type;
  sl_zigbee_aps_frame_t apsFrame;
  sl_zigbee_rx_packet_info_t packetInfo;
  uint8_t messageLength;
  uint8_t message[MAX_IPC_VEC_ARG_CAPACITY];
} sli_zigbee_stack_incoming_message_handler_ipc_event_t;

typedef struct {
  uint8_t errorCode;
  sl_802154_short_addr_t target;
} sli_zigbee_stack_incoming_network_status_handler_ipc_event_t;

typedef struct {
  sl_status_t status;
  sl_802154_short_addr_t target;
} sli_zigbee_stack_incoming_route_error_handler_ipc_event_t;

typedef struct {
  sl_zigbee_rx_packet_info_t packetInfo;
  uint8_t relayCount;
  uint8_t relayList[MAX_IPC_VEC_ARG_CAPACITY];
} sli_zigbee_stack_incoming_route_record_handler_ipc_event_t;

typedef struct {
  sl_status_t status;
  sl_zigbee_outgoing_message_type_t type;
  uint16_t indexOrDestination;
  sl_zigbee_aps_frame_t apsFrame;
  uint16_t messageTag;
  uint8_t messageLength;
  uint8_t message[MAX_IPC_VEC_ARG_CAPACITY];
} sli_zigbee_stack_message_sent_handler_ipc_event_t;

typedef struct {
  sl_zigbee_rx_packet_info_t packetInfo;
  uint8_t relayCount;
  uint8_t relayList[MAX_IPC_VEC_ARG_CAPACITY];
  bool consumed;
} sli_zigbee_stack_override_incoming_route_record_handler_ipc_event_t;

typedef struct {
  uint8_t mac_index;
  uint8_t packet_length;
  uint8_t packet_contents[MAX_IPC_VEC_ARG_CAPACITY];
  uint8_t priority;
} sli_zigbee_stack_redirect_outgoing_message_handler_ipc_event_t;

#endif // MESSAGE_IPC_CALLBACK_EVENTS_H
