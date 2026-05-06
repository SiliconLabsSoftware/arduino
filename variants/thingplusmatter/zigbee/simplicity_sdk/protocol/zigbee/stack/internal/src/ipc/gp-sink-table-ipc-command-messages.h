/***************************************************************************//**
 * @file gp-sink-table-ipc-command-messages.h
 * @brief defines structured format for 'gp-sink-table' ipc messages
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
// automatically generated from gp-sink-table.h.  Do not manually edit
#ifndef GP_SINK_TABLE_IPC_COMMAND_MESSAGES_H
#define GP_SINK_TABLE_IPC_COMMAND_MESSAGES_H

#include "stack/include/gp-sink-table.h"
#include "stack/internal/inc/gp-sink-table-internal-def.h"

typedef struct {
  uint8_t index;
  uint16_t sinkGroupId;
  uint16_t assignedAlias;
} sli_zigbee_stack_gp_sink_table_add_group_ipc_req_t;

typedef struct {
  sli_zigbee_stack_gp_sink_table_add_group_ipc_req_t request;
} sli_zigbee_stack_gp_sink_table_add_group_ipc_msg_t;

typedef struct {
  uint8_t sinkTableIndex;
} sli_zigbee_stack_gp_sink_table_entry_in_use_ipc_req_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_gp_sink_table_entry_in_use_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_sink_table_entry_in_use_ipc_req_t request;
  sli_zigbee_stack_gp_sink_table_entry_in_use_ipc_rsp_t response;
} sli_zigbee_stack_gp_sink_table_entry_in_use_ipc_msg_t;

typedef struct {
  sl_zigbee_gp_address_t addr;
} sli_zigbee_stack_gp_sink_table_find_or_allocate_entry_ipc_req_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_gp_sink_table_find_or_allocate_entry_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_sink_table_find_or_allocate_entry_ipc_req_t request;
  sli_zigbee_stack_gp_sink_table_find_or_allocate_entry_ipc_rsp_t response;
} sli_zigbee_stack_gp_sink_table_find_or_allocate_entry_ipc_msg_t;

typedef struct {
  uint8_t sinkTableIndex;
  sl_zigbee_gp_sink_table_entry_t entry;
} sli_zigbee_stack_gp_sink_table_get_entry_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_gp_sink_table_get_entry_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_sink_table_get_entry_ipc_req_t request;
  sli_zigbee_stack_gp_sink_table_get_entry_ipc_rsp_t response;
} sli_zigbee_stack_gp_sink_table_get_entry_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_gp_sink_table_get_free_entry_index_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_sink_table_get_free_entry_index_ipc_rsp_t response;
} sli_zigbee_stack_gp_sink_table_get_free_entry_index_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_gp_sink_table_get_number_of_active_entries_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_sink_table_get_number_of_active_entries_ipc_rsp_t response;
} sli_zigbee_stack_gp_sink_table_get_number_of_active_entries_ipc_msg_t;

typedef struct {
  sl_zigbee_gp_address_t addr;
} sli_zigbee_stack_gp_sink_table_lookup_ipc_req_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_gp_sink_table_lookup_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_sink_table_lookup_ipc_req_t request;
  sli_zigbee_stack_gp_sink_table_lookup_ipc_rsp_t response;
} sli_zigbee_stack_gp_sink_table_lookup_ipc_msg_t;

typedef struct {
  uint8_t index;
} sli_zigbee_stack_gp_sink_table_remove_entry_ipc_req_t;

typedef struct {
  sli_zigbee_stack_gp_sink_table_remove_entry_ipc_req_t request;
} sli_zigbee_stack_gp_sink_table_remove_entry_ipc_msg_t;

typedef struct {
  uint8_t index;
  uint16_t sinkGroupId;
  uint16_t assignedAlias;
} sli_zigbee_stack_gp_sink_table_remove_group_ipc_req_t;

typedef struct {
  bool result;
} sli_zigbee_stack_gp_sink_table_remove_group_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_sink_table_remove_group_ipc_req_t request;
  sli_zigbee_stack_gp_sink_table_remove_group_ipc_rsp_t response;
} sli_zigbee_stack_gp_sink_table_remove_group_ipc_msg_t;

typedef struct {
  uint8_t sinkTableIndex;
  sl_zigbee_gp_sink_table_entry_t entry;
} sli_zigbee_stack_gp_sink_table_set_entry_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_gp_sink_table_set_entry_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_sink_table_set_entry_ipc_req_t request;
  sli_zigbee_stack_gp_sink_table_set_entry_ipc_rsp_t response;
} sli_zigbee_stack_gp_sink_table_set_entry_ipc_msg_t;

typedef struct {
  uint8_t index;
  uint32_t sfc;
} sli_zigbee_stack_gp_sink_table_set_security_frame_counter_ipc_req_t;

typedef struct {
  sli_zigbee_stack_gp_sink_table_set_security_frame_counter_ipc_req_t request;
} sli_zigbee_stack_gp_sink_table_set_security_frame_counter_ipc_msg_t;

#endif // GP_SINK_TABLE_IPC_COMMAND_MESSAGES_H
