/***************************************************************************//**
 * @file gp-proxy-table-ipc-command-messages.h
 * @brief defines structured format for 'gp-proxy-table' ipc messages
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
// automatically generated from gp-proxy-table.h.  Do not manually edit
#ifndef GP_PROXY_TABLE_IPC_COMMAND_MESSAGES_H
#define GP_PROXY_TABLE_IPC_COMMAND_MESSAGES_H

#include "stack/include/gp-proxy-table.h"
#include "stack/internal/inc/gp-proxy-table-internal-def.h"

typedef struct {
  uint8_t proxyIndex;
  sl_zigbee_gp_proxy_table_entry_t entry;
} sli_zigbee_stack_gp_proxy_table_get_entry_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_gp_proxy_table_get_entry_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_proxy_table_get_entry_ipc_req_t request;
  sli_zigbee_stack_gp_proxy_table_get_entry_ipc_rsp_t response;
} sli_zigbee_stack_gp_proxy_table_get_entry_ipc_msg_t;

typedef struct {
  sl_zigbee_gp_address_t addr;
} sli_zigbee_stack_gp_proxy_table_lookup_ipc_req_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_gp_proxy_table_lookup_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_proxy_table_lookup_ipc_req_t request;
  sli_zigbee_stack_gp_proxy_table_lookup_ipc_rsp_t response;
} sli_zigbee_stack_gp_proxy_table_lookup_ipc_msg_t;

typedef struct {
  uint32_t options;
  sl_zigbee_gp_address_t addr;
  uint8_t commMode;
  uint16_t sinkNwkAddress;
  uint16_t sinkGroupId;
  uint16_t assignedAlias;
  uint8_t sinkIeeeAddress;
  sl_zigbee_key_data_t gpdKey;
  uint32_t gpdSecurityFrameCounter;
  uint8_t forwardingRadius;
} sli_zigbee_stack_gp_proxy_table_process_gp_pairing_ipc_req_t;

typedef struct {
  bool result;
} sli_zigbee_stack_gp_proxy_table_process_gp_pairing_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_gp_proxy_table_process_gp_pairing_ipc_req_t request;
  sli_zigbee_stack_gp_proxy_table_process_gp_pairing_ipc_rsp_t response;
} sli_zigbee_stack_gp_proxy_table_process_gp_pairing_ipc_msg_t;

#endif // GP_PROXY_TABLE_IPC_COMMAND_MESSAGES_H
