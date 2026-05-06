/***************************************************************************//**
 * @file raw-message-ipc-command-messages.h
 * @brief defines structured format for 'raw-message' ipc messages
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
#ifndef RAW_MESSAGE_IPC_COMMAND_MESSAGES_H
#define RAW_MESSAGE_IPC_COMMAND_MESSAGES_H

#include "stack/include/raw-message.h"
#include "stack/internal/inc/raw-message-internal-def.h"

typedef struct {
  sl_802154_short_addr_t result;
} sli_zigbee_stack_get_embernet_passthrough_source_address_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_embernet_passthrough_source_address_ipc_rsp_t response;
} sli_zigbee_stack_get_embernet_passthrough_source_address_ipc_msg_t;

typedef struct {
  sl_zigbee_mac_passthrough_type_t result;
} sli_zigbee_stack_get_mac_passthrough_flags_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_mac_passthrough_flags_ipc_rsp_t response;
} sli_zigbee_stack_get_mac_passthrough_flags_ipc_msg_t;

typedef struct {
  uint8_t message[MAX_IPC_VEC_ARG_CAPACITY];
  uint8_t message_length;
  sl_zigbee_transmit_priority_t priority;
  bool useCca;
} sli_zigbee_stack_send_raw_message_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_send_raw_message_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_raw_message_ipc_req_t request;
  sli_zigbee_stack_send_raw_message_ipc_rsp_t response;
} sli_zigbee_stack_send_raw_message_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t address;
} sli_zigbee_stack_set_embernet_passthrough_source_address_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_embernet_passthrough_source_address_ipc_req_t request;
} sli_zigbee_stack_set_embernet_passthrough_source_address_ipc_msg_t;

typedef struct {
  sl_zigbee_mac_filter_match_data_t macFilterMatchList[MAX_IPC_VEC_ARG_CAPACITY];
  uint8_t listLength;
} sli_zigbee_stack_set_mac_filter_match_list_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_mac_filter_match_list_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_mac_filter_match_list_ipc_req_t request;
  sli_zigbee_stack_set_mac_filter_match_list_ipc_rsp_t response;
} sli_zigbee_stack_set_mac_filter_match_list_ipc_msg_t;

typedef struct {
  sl_zigbee_mac_passthrough_type_t type;
} sli_zigbee_stack_set_mac_passthrough_flags_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_mac_passthrough_flags_ipc_req_t request;
} sli_zigbee_stack_set_mac_passthrough_flags_ipc_msg_t;

#endif // RAW_MESSAGE_IPC_COMMAND_MESSAGES_H
