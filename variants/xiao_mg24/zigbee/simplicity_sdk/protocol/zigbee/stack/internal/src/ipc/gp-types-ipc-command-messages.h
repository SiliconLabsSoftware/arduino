/***************************************************************************//**
 * @file gp-types-ipc-command-messages.h
 * @brief defines structured format for 'gp-types' ipc messages
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
// automatically generated from gp-types.h.  Do not manually edit
#ifndef GP_TYPES_IPC_COMMAND_MESSAGES_H
#define GP_TYPES_IPC_COMMAND_MESSAGES_H

#include "stack/include/gp-types.h"
#include "stack/internal/inc/gp-types-internal-def.h"

typedef struct {
  bool action;
  bool useCca;
  sl_zigbee_gp_address_t addr;
  uint8_t gpdCommandId;
  uint8_t gpdAsduLength;
  uint8_t gpdAsdu[MAX_IPC_VEC_ARG_CAPACITY];
  uint8_t gpepHandle;
  uint16_t gpTxQueueEntryLifetimeMs;
} sli_zigbee_stack_d_gp_send_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_d_gp_send_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_d_gp_send_ipc_req_t request;
  sli_zigbee_stack_d_gp_send_ipc_rsp_t response;
} sli_zigbee_stack_d_gp_send_ipc_msg_t;

typedef struct {
  uint16_t result;
} sli_zigbee_stack_get_gp_max_tx_q_list_count_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_gp_max_tx_q_list_count_ipc_rsp_t response;
} sli_zigbee_stack_get_gp_max_tx_q_list_count_ipc_msg_t;

typedef struct {
  uint16_t result;
} sli_zigbee_stack_get_gp_tx_q_list_count_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_gp_tx_q_list_count_ipc_rsp_t response;
} sli_zigbee_stack_get_gp_tx_q_list_count_ipc_msg_t;

typedef struct {
  sl_zigbee_gp_tx_queue_entry_t txQueue;
  uint8_t data[MAX_IPC_VEC_ARG_CAPACITY];
  uint16_t dataLength;
} sli_zigbee_stack_gp_add_gp_tx_queue_entry_with_payload_ipc_req_t;

typedef struct {
  sli_buffer_manager_buffer_t result;
} sli_zigbee_stack_gp_add_gp_tx_queue_entry_with_payload_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_add_gp_tx_queue_entry_with_payload_ipc_req_t request;
  sli_zigbee_stack_gp_add_gp_tx_queue_entry_with_payload_ipc_rsp_t response;
} sli_zigbee_stack_gp_add_gp_tx_queue_entry_with_payload_ipc_msg_t;

typedef struct {
  sl_zigbee_gp_tx_queue_entry_t txQueue;
  uint8_t data[MAX_IPC_VEC_ARG_CAPACITY];
  uint16_t dataLength;
  uint16_t allocatedDataLength;
} sli_zigbee_stack_gp_get_tx_queue_entry_from_queue_ipc_req_t;

typedef struct {
  sli_buffer_manager_buffer_t result;
} sli_zigbee_stack_gp_get_tx_queue_entry_from_queue_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_get_tx_queue_entry_from_queue_ipc_req_t request;
  sli_zigbee_stack_gp_get_tx_queue_entry_from_queue_ipc_rsp_t response;
} sli_zigbee_stack_gp_get_tx_queue_entry_from_queue_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_zigbee_gp_tx_queue_entry_t txQueue;
  uint8_t payload[MAX_IPC_VEC_ARG_CAPACITY];
  uint16_t payload_len;
} sli_zigbee_stack_gp_get_tx_queue_entry_from_queue_index_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_gp_get_tx_queue_entry_from_queue_index_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_get_tx_queue_entry_from_queue_index_ipc_req_t request;
  sli_zigbee_stack_gp_get_tx_queue_entry_from_queue_index_ipc_rsp_t response;
} sli_zigbee_stack_gp_get_tx_queue_entry_from_queue_index_ipc_msg_t;

typedef struct {
  sli_zigbee_message_buffer_queue_t * result;
} sli_zigbee_stack_gp_get_tx_queue_head_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_get_tx_queue_head_ipc_rsp_t response;
} sli_zigbee_stack_gp_get_tx_queue_head_ipc_msg_t;

typedef struct {
  sl_zigbee_gp_tx_queue_entry_t txQueue;
} sli_zigbee_stack_gp_remove_from_tx_queue_ipc_req_t;

typedef struct {
  bool result;
} sli_zigbee_stack_gp_remove_from_tx_queue_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_remove_from_tx_queue_ipc_req_t request;
  sli_zigbee_stack_gp_remove_from_tx_queue_ipc_rsp_t response;
} sli_zigbee_stack_gp_remove_from_tx_queue_ipc_msg_t;

typedef struct {
  uint16_t maxEntries;
} sli_zigbee_stack_gp_set_max_tx_queue_entry_ipc_req_t;

typedef struct {
  sli_zigbee_stack_gp_set_max_tx_queue_entry_ipc_req_t request;
} sli_zigbee_stack_gp_set_max_tx_queue_entry_ipc_msg_t;

#endif // GP_TYPES_IPC_COMMAND_MESSAGES_H
