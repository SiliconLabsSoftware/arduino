/***************************************************************************//**
 * @file zll-api-ipc-command-messages.h
 * @brief defines structured format for 'zll-api' ipc messages
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
// automatically generated from zll-api.h.  Do not manually edit
#ifndef ZLL_API_IPC_COMMAND_MESSAGES_H
#define ZLL_API_IPC_COMMAND_MESSAGES_H

#include "stack/include/zll-api.h"
#include "stack/internal/inc/zll-api-internal-def.h"

typedef struct {
  uint32_t result;
} sli_zigbee_stack_get_zll_primary_channel_mask_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_zll_primary_channel_mask_ipc_rsp_t response;
} sli_zigbee_stack_get_zll_primary_channel_mask_ipc_msg_t;

typedef struct {
  uint32_t result;
} sli_zigbee_stack_get_zll_secondary_channel_mask_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_zll_secondary_channel_mask_ipc_rsp_t response;
} sli_zigbee_stack_get_zll_secondary_channel_mask_ipc_msg_t;

typedef struct {
  bool result;
} sli_zigbee_stack_is_zll_network_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_is_zll_network_ipc_rsp_t response;
} sli_zigbee_stack_is_zll_network_ipc_msg_t;

typedef struct {
  uint16_t mask;
} sli_zigbee_stack_set_zll_additional_state_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_zll_additional_state_ipc_req_t request;
} sli_zigbee_stack_set_zll_additional_state_ipc_msg_t;

typedef struct {
  sl_zigbee_node_type_t nodeType;
} sli_zigbee_stack_set_zll_node_type_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_zll_node_type_ipc_req_t request;
} sli_zigbee_stack_set_zll_node_type_ipc_msg_t;

typedef struct {
  uint32_t mask;
} sli_zigbee_stack_set_zll_primary_channel_mask_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_zll_primary_channel_mask_ipc_req_t request;
} sli_zigbee_stack_set_zll_primary_channel_mask_ipc_msg_t;

typedef struct {
  uint32_t mask;
} sli_zigbee_stack_set_zll_secondary_channel_mask_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_zll_secondary_channel_mask_ipc_req_t request;
} sli_zigbee_stack_set_zll_secondary_channel_mask_ipc_msg_t;

typedef struct {
  sl_zigbee_zll_network_t networkInfo;
  int8_t radioTxPower;
} sli_zigbee_stack_zll_form_network_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_zll_form_network_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_zll_form_network_ipc_req_t request;
  sli_zigbee_stack_zll_form_network_ipc_rsp_t response;
} sli_zigbee_stack_zll_form_network_ipc_msg_t;

typedef struct {
  sl_zigbee_zll_policy_t result;
} sli_zigbee_stack_zll_get_policy_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_zll_get_policy_ipc_rsp_t response;
} sli_zigbee_stack_zll_get_policy_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_zll_get_radio_idle_mode_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_zll_get_radio_idle_mode_ipc_rsp_t response;
} sli_zigbee_stack_zll_get_radio_idle_mode_ipc_msg_t;

typedef struct {
  sl_zigbee_tok_type_stack_zll_data_t token;
} sli_zigbee_stack_zll_get_token_stack_zll_data_ipc_req_t;

typedef struct {
  sli_zigbee_stack_zll_get_token_stack_zll_data_ipc_req_t request;
} sli_zigbee_stack_zll_get_token_stack_zll_data_ipc_msg_t;

typedef struct {
  sl_zigbee_tok_type_stack_zll_security_t token;
} sli_zigbee_stack_zll_get_token_stack_zll_security_ipc_req_t;

typedef struct {
  sli_zigbee_stack_zll_get_token_stack_zll_security_ipc_req_t request;
} sli_zigbee_stack_zll_get_token_stack_zll_security_ipc_msg_t;

typedef struct {
  sl_zigbee_tok_type_stack_zll_data_t data;
  sl_zigbee_tok_type_stack_zll_security_t security;
} sli_zigbee_stack_zll_get_tokens_stack_zll_ipc_req_t;

typedef struct {
  sli_zigbee_stack_zll_get_tokens_stack_zll_ipc_req_t request;
} sli_zigbee_stack_zll_get_tokens_stack_zll_ipc_msg_t;

typedef struct {
  sl_zigbee_zll_network_t targetNetworkInfo;
} sli_zigbee_stack_zll_join_target_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_zll_join_target_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_zll_join_target_ipc_req_t request;
  sli_zigbee_stack_zll_join_target_ipc_rsp_t response;
} sli_zigbee_stack_zll_join_target_ipc_msg_t;

typedef struct {
  bool result;
} sli_zigbee_stack_zll_operation_in_progress_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_zll_operation_in_progress_ipc_rsp_t response;
} sli_zigbee_stack_zll_operation_in_progress_ipc_msg_t;

typedef struct {
  bool result;
} sli_zigbee_stack_zll_rx_on_when_idle_get_active_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_zll_rx_on_when_idle_get_active_ipc_rsp_t response;
} sli_zigbee_stack_zll_rx_on_when_idle_get_active_ipc_msg_t;

typedef struct {
  sl_zigbee_key_data_t networkKey;
  sl_zigbee_zll_initial_security_state_t securityState;
} sli_zigbee_stack_zll_set_initial_security_state_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_zll_set_initial_security_state_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_zll_set_initial_security_state_ipc_req_t request;
  sli_zigbee_stack_zll_set_initial_security_state_ipc_rsp_t response;
} sli_zigbee_stack_zll_set_initial_security_state_ipc_msg_t;

typedef struct {
  sl_zigbee_zll_policy_t policy;
} sli_zigbee_stack_zll_set_policy_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_zll_set_policy_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_zll_set_policy_ipc_req_t request;
  sli_zigbee_stack_zll_set_policy_ipc_rsp_t response;
} sli_zigbee_stack_zll_set_policy_ipc_msg_t;

typedef struct {
  sl_zigbee_radio_power_mode_t mode;
} sli_zigbee_stack_zll_set_radio_idle_mode_ipc_req_t;

typedef struct {
  sli_zigbee_stack_zll_set_radio_idle_mode_ipc_req_t request;
} sli_zigbee_stack_zll_set_radio_idle_mode_ipc_msg_t;

typedef struct {
  uint32_t durationMs;
} sli_zigbee_stack_zll_set_rx_on_when_idle_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_zll_set_rx_on_when_idle_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_zll_set_rx_on_when_idle_ipc_req_t request;
  sli_zigbee_stack_zll_set_rx_on_when_idle_ipc_rsp_t response;
} sli_zigbee_stack_zll_set_rx_on_when_idle_ipc_msg_t;

typedef struct {
  sl_zigbee_zll_initial_security_state_t securityState;
} sli_zigbee_stack_zll_set_security_state_without_key_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_zll_set_security_state_without_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_zll_set_security_state_without_key_ipc_req_t request;
  sli_zigbee_stack_zll_set_security_state_without_key_ipc_rsp_t response;
} sli_zigbee_stack_zll_set_security_state_without_key_ipc_msg_t;

typedef struct {
  sl_zigbee_tok_type_stack_zll_data_t token;
} sli_zigbee_stack_zll_set_token_stack_zll_data_ipc_req_t;

typedef struct {
  sli_zigbee_stack_zll_set_token_stack_zll_data_ipc_req_t request;
} sli_zigbee_stack_zll_set_token_stack_zll_data_ipc_msg_t;

typedef struct {
  uint32_t channelMask;
  int8_t radioPowerForScan;
  sl_zigbee_node_type_t nodeType;
} sli_zigbee_stack_zll_start_scan_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_zll_start_scan_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_zll_start_scan_ipc_req_t request;
  sli_zigbee_stack_zll_start_scan_ipc_rsp_t response;
} sli_zigbee_stack_zll_start_scan_ipc_msg_t;

#endif // ZLL_API_IPC_COMMAND_MESSAGES_H
