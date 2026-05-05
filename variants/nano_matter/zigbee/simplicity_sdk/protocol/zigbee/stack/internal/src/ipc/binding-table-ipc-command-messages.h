/***************************************************************************//**
 * @file binding-table-ipc-command-messages.h
 * @brief defines structured format for 'binding-table' ipc messages
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
// automatically generated from binding-table.h.  Do not manually edit
#ifndef BINDING_TABLE_IPC_COMMAND_MESSAGES_H
#define BINDING_TABLE_IPC_COMMAND_MESSAGES_H

#include "stack/include/binding-table.h"
#include "stack/internal/inc/binding-table-internal-def.h"

typedef struct {
  uint8_t index;
} sli_zigbee_stack_binding_is_active_ipc_req_t;

typedef struct {
  bool result;
} sli_zigbee_stack_binding_is_active_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_binding_is_active_ipc_req_t request;
  sli_zigbee_stack_binding_is_active_ipc_rsp_t response;
} sli_zigbee_stack_binding_is_active_ipc_msg_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_clear_binding_table_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_clear_binding_table_ipc_rsp_t response;
} sli_zigbee_stack_clear_binding_table_ipc_msg_t;

typedef struct {
  uint8_t index;
} sli_zigbee_stack_delete_binding_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_delete_binding_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_delete_binding_ipc_req_t request;
  sli_zigbee_stack_delete_binding_ipc_rsp_t response;
} sli_zigbee_stack_delete_binding_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_zigbee_binding_table_entry_t result;
} sli_zigbee_stack_get_binding_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_binding_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_binding_ipc_req_t request;
  sli_zigbee_stack_get_binding_ipc_rsp_t response;
} sli_zigbee_stack_get_binding_ipc_msg_t;

typedef struct {
  uint8_t index;
} sli_zigbee_stack_get_binding_remote_node_id_ipc_req_t;

typedef struct {
  sl_802154_short_addr_t result;
} sli_zigbee_stack_get_binding_remote_node_id_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_binding_remote_node_id_ipc_req_t request;
  sli_zigbee_stack_get_binding_remote_node_id_ipc_rsp_t response;
} sli_zigbee_stack_get_binding_remote_node_id_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_binding_table_size_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_binding_table_size_ipc_rsp_t response;
} sli_zigbee_stack_get_binding_table_size_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_802154_short_addr_t source;
} sli_zigbee_stack_note_senders_binding_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_note_senders_binding_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_note_senders_binding_ipc_req_t request;
  sli_zigbee_stack_note_senders_binding_ipc_rsp_t response;
} sli_zigbee_stack_note_senders_binding_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_zigbee_binding_table_entry_t value;
} sli_zigbee_stack_set_binding_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_binding_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_binding_ipc_req_t request;
  sli_zigbee_stack_set_binding_ipc_rsp_t response;
} sli_zigbee_stack_set_binding_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_802154_short_addr_t id;
} sli_zigbee_stack_set_binding_remote_node_id_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_binding_remote_node_id_ipc_req_t request;
} sli_zigbee_stack_set_binding_remote_node_id_ipc_msg_t;

typedef struct {
  uint8_t size;
} sli_zigbee_stack_set_binding_table_size_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_binding_table_size_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_binding_table_size_ipc_req_t request;
  sli_zigbee_stack_set_binding_table_size_ipc_rsp_t response;
} sli_zigbee_stack_set_binding_table_size_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_zigbee_binding_table_entry_t entry;
  sl_802154_short_addr_t source;
} sli_zigbee_stack_set_reply_binding_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_reply_binding_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_reply_binding_ipc_req_t request;
  sli_zigbee_stack_set_reply_binding_ipc_rsp_t response;
} sli_zigbee_stack_set_reply_binding_ipc_msg_t;

#endif // BINDING_TABLE_IPC_COMMAND_MESSAGES_H
