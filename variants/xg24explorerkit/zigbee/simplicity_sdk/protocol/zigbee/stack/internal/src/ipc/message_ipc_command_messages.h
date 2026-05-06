/***************************************************************************//**
 * @file message_ipc_command_messages.h
 * @brief defines structured format for 'message' ipc messages
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
// automatically generated from message.h.  Do not manually edit
#ifndef MESSAGE_IPC_COMMAND_MESSAGES_H
#define MESSAGE_IPC_COMMAND_MESSAGES_H

#include "stack/include/message.h"
#include "stack/internal/inc/message_internal_def.h"

typedef struct {
  uint8_t addressTableIndex;
} sli_zigbee_stack_address_table_entry_is_active_ipc_req_t;

typedef struct {
  bool result;
} sli_zigbee_stack_address_table_entry_is_active_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_address_table_entry_is_active_ipc_req_t request;
  sli_zigbee_stack_address_table_entry_is_active_ipc_rsp_t response;
} sli_zigbee_stack_address_table_entry_is_active_ipc_msg_t;

typedef struct {
  uint8_t addressTableIndex;
  sl_802154_short_addr_t nodeId;
  sl_802154_long_addr_t eui64;
} sli_zigbee_stack_get_address_table_info_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_address_table_info_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_address_table_info_ipc_req_t request;
  sli_zigbee_stack_get_address_table_info_ipc_rsp_t response;
} sli_zigbee_stack_get_address_table_info_ipc_msg_t;

typedef struct {
  uint16_t result;
} sli_zigbee_stack_get_aps_ack_timeout_ms_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_aps_ack_timeout_ms_ipc_rsp_t response;
} sli_zigbee_stack_get_aps_ack_timeout_ms_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t remoteEui64;
} sli_zigbee_stack_get_extended_timeout_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_extended_timeout_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_extended_timeout_ipc_req_t request;
  sli_zigbee_stack_get_extended_timeout_ipc_rsp_t response;
} sli_zigbee_stack_get_extended_timeout_ipc_msg_t;

typedef struct {
  sl_zigbee_multicast_table_entry_t * result;
} sli_zigbee_stack_get_multicast_table_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_multicast_table_ipc_rsp_t response;
} sli_zigbee_stack_get_multicast_table_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_multicast_table_size_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_multicast_table_size_ipc_rsp_t response;
} sli_zigbee_stack_get_multicast_table_size_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_maximum_aps_payload_length_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_maximum_aps_payload_length_ipc_rsp_t response;
} sli_zigbee_stack_maximum_aps_payload_length_ipc_msg_t;

typedef struct {
  bool result;
} sli_zigbee_stack_pending_acked_messages_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_pending_acked_messages_ipc_rsp_t response;
} sli_zigbee_stack_pending_acked_messages_ipc_msg_t;

typedef struct {
  uint8_t euiSource[EUI64_SIZE];
} sli_zigbee_stack_proxy_next_broadcast_from_long_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_proxy_next_broadcast_from_long_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_proxy_next_broadcast_from_long_ipc_req_t request;
  sli_zigbee_stack_proxy_next_broadcast_from_long_ipc_rsp_t response;
} sli_zigbee_stack_proxy_next_broadcast_from_long_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t alias;
  sl_802154_short_addr_t destination;
  uint8_t nwkSequence;
  sl_zigbee_aps_frame_t apsFrame;
  uint8_t radius;
  uint16_t messageTag;
  uint8_t messageLength;
  uint8_t message[MAX_IPC_VEC_ARG_CAPACITY];
  uint8_t apsSequence;
} sli_zigbee_stack_send_broadcast_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_send_broadcast_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_broadcast_ipc_req_t request;
  sli_zigbee_stack_send_broadcast_ipc_rsp_t response;
} sli_zigbee_stack_send_broadcast_ipc_msg_t;

typedef struct {
  sl_zigbee_aps_frame_t apsFrame;
  uint8_t radius;
  uint16_t broadcastAddr;
  sl_802154_short_addr_t alias;
  uint8_t nwkSequence;
  uint16_t messageTag;
  uint8_t messageLength;
  uint8_t message[MAX_IPC_VEC_ARG_CAPACITY];
  uint8_t apsSequence;
} sli_zigbee_stack_send_multicast_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_send_multicast_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_multicast_ipc_req_t request;
  sli_zigbee_stack_send_multicast_ipc_rsp_t response;
} sli_zigbee_stack_send_multicast_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t destination;
  sl_zigbee_aps_frame_t apsFrame;
  uint8_t messageLength;
  uint8_t messageContents;
} sli_zigbee_stack_send_reply_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_send_reply_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_reply_ipc_req_t request;
  sli_zigbee_stack_send_reply_ipc_rsp_t response;
} sli_zigbee_stack_send_reply_ipc_msg_t;

typedef struct {
  sl_zigbee_outgoing_message_type_t type;
  uint16_t indexOrDestination;
  sl_zigbee_aps_frame_t apsFrame;
  uint16_t messageTag;
  uint8_t messageLength;
  uint8_t message[MAX_IPC_VEC_ARG_CAPACITY];
  uint8_t apsSequence;
} sli_zigbee_stack_send_unicast_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_send_unicast_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_unicast_ipc_req_t request;
  sli_zigbee_stack_send_unicast_ipc_rsp_t response;
} sli_zigbee_stack_send_unicast_ipc_msg_t;

typedef struct {
  uint8_t addressTableIndex;
  sl_802154_long_addr_t eui64;
  sl_802154_short_addr_t id;
} sli_zigbee_stack_set_address_table_info_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_address_table_info_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_address_table_info_ipc_req_t request;
  sli_zigbee_stack_set_address_table_info_ipc_rsp_t response;
} sli_zigbee_stack_set_address_table_info_ipc_msg_t;

typedef struct {
  uint16_t timeout;
} sli_zigbee_stack_set_aps_ack_timeout_ms_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_aps_ack_timeout_ms_ipc_req_t request;
} sli_zigbee_stack_set_aps_ack_timeout_ms_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t remoteEui64;
  bool extendedTimeout;
} sli_zigbee_stack_set_extended_timeout_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_extended_timeout_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_extended_timeout_ipc_req_t request;
  sli_zigbee_stack_set_extended_timeout_ipc_rsp_t response;
} sli_zigbee_stack_set_extended_timeout_ipc_msg_t;

typedef struct {
  sl_zigbee_multicast_table_entry_t entry;
} sli_zigbee_stack_set_multicast_table_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_multicast_table_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_multicast_table_ipc_req_t request;
  sli_zigbee_stack_set_multicast_table_ipc_rsp_t response;
} sli_zigbee_stack_set_multicast_table_ipc_msg_t;

typedef struct {
  uint8_t size;
} sli_zigbee_stack_set_multicast_table_size_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_multicast_table_size_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_multicast_table_size_ipc_req_t request;
  sli_zigbee_stack_set_multicast_table_size_ipc_rsp_t response;
} sli_zigbee_stack_set_multicast_table_size_ipc_msg_t;

typedef struct {
  sl_passive_ack_config_enum_t config;
  uint8_t minAcksNeeded;
} sli_zigbee_stack_set_passive_ack_config_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_passive_ack_config_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_passive_ack_config_ipc_req_t request;
  sli_zigbee_stack_set_passive_ack_config_ipc_rsp_t response;
} sli_zigbee_stack_set_passive_ack_config_ipc_msg_t;

typedef struct {
  uint16_t fragmentData;
} sli_zigbee_stack_set_reply_fragment_data_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_reply_fragment_data_ipc_req_t request;
} sli_zigbee_stack_set_reply_fragment_data_ipc_msg_t;

typedef struct {
  int8_t rssi;
  uint8_t lqi;
  sl_nwk_packet_exchange_t nwk_packet;
} slxi_zigbee_stack_add_to_incoming_network_queue_ipc_req_t;

typedef struct {
  sl_status_t result;
} slxi_zigbee_stack_add_to_incoming_network_queue_ipc_rsp_t;

typedef struct {
  slxi_zigbee_stack_add_to_incoming_network_queue_ipc_req_t request;
  slxi_zigbee_stack_add_to_incoming_network_queue_ipc_rsp_t response;
} slxi_zigbee_stack_add_to_incoming_network_queue_ipc_msg_t;

#endif // MESSAGE_IPC_COMMAND_MESSAGES_H
