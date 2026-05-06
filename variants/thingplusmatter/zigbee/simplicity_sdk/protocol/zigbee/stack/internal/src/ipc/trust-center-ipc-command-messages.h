/***************************************************************************//**
 * @file trust-center-ipc-command-messages.h
 * @brief defines structured format for 'trust-center' ipc messages
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
// automatically generated from trust-center.h.  Do not manually edit
#ifndef TRUST_CENTER_IPC_COMMAND_MESSAGES_H
#define TRUST_CENTER_IPC_COMMAND_MESSAGES_H

#include "stack/include/trust-center.h"
#include "stack/internal/inc/trust-center-internal-def.h"

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_broadcast_network_key_switch_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_broadcast_network_key_switch_ipc_rsp_t response;
} sli_zigbee_stack_broadcast_network_key_switch_ipc_msg_t;

typedef struct {
  sl_zigbee_key_data_t key;
} sli_zigbee_stack_broadcast_next_network_key_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_broadcast_next_network_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_broadcast_next_network_key_ipc_req_t request;
  sli_zigbee_stack_broadcast_next_network_key_ipc_rsp_t response;
} sli_zigbee_stack_broadcast_next_network_key_ipc_msg_t;

typedef struct {
  sl_zigbee_app_link_key_request_policy_t result;
} sli_zigbee_stack_get_app_link_key_request_policy_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_app_link_key_request_policy_ipc_rsp_t response;
} sli_zigbee_stack_get_app_link_key_request_policy_ipc_msg_t;

typedef struct {
  uint16_t result;
} sli_zigbee_stack_get_transient_device_table_timeout_ms_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_transient_device_table_timeout_ms_ipc_rsp_t response;
} sli_zigbee_stack_get_transient_device_table_timeout_ms_ipc_msg_t;

typedef struct {
  sl_zigbee_tc_link_key_request_policy_t result;
} sli_zigbee_stack_get_trust_center_link_key_request_policy_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_trust_center_link_key_request_policy_ipc_rsp_t response;
} sli_zigbee_stack_get_trust_center_link_key_request_policy_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t destShort;
  sl_802154_long_addr_t destLong;
  sl_802154_long_addr_t deviceToRemoveLong;
} sli_zigbee_stack_send_remove_device_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_send_remove_device_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_remove_device_ipc_req_t request;
  sli_zigbee_stack_send_remove_device_ipc_rsp_t response;
} sli_zigbee_stack_send_remove_device_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t destinationNodeId;
  sl_802154_long_addr_t destinationEui64;
} sli_zigbee_stack_send_trust_center_link_key_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_send_trust_center_link_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_trust_center_link_key_ipc_req_t request;
  sli_zigbee_stack_send_trust_center_link_key_ipc_rsp_t response;
} sli_zigbee_stack_send_trust_center_link_key_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t targetShort;
  sl_802154_long_addr_t targetLong;
  sl_zigbee_key_data_t newKey;
} sli_zigbee_stack_send_unicast_network_key_update_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_send_unicast_network_key_update_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_unicast_network_key_update_ipc_req_t request;
  sli_zigbee_stack_send_unicast_network_key_update_ipc_rsp_t response;
} sli_zigbee_stack_send_unicast_network_key_update_ipc_msg_t;

typedef struct {
  sl_zigbee_app_link_key_request_policy_t policy;
} sli_zigbee_stack_set_app_link_key_request_policy_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_app_link_key_request_policy_ipc_req_t request;
} sli_zigbee_stack_set_app_link_key_request_policy_ipc_msg_t;

typedef struct {
  uint16_t timeout;
} sli_zigbee_stack_set_transient_device_table_timeout_ms_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_transient_device_table_timeout_ms_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_transient_device_table_timeout_ms_ipc_req_t request;
  sli_zigbee_stack_set_transient_device_table_timeout_ms_ipc_rsp_t response;
} sli_zigbee_stack_set_transient_device_table_timeout_ms_ipc_msg_t;

typedef struct {
  sl_zigbee_tc_link_key_request_policy_t policy;
} sli_zigbee_stack_set_trust_center_link_key_request_policy_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_trust_center_link_key_request_policy_ipc_req_t request;
} sli_zigbee_stack_set_trust_center_link_key_request_policy_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t targetShort;
  sl_802154_long_addr_t targetLong;
  sl_802154_short_addr_t parentShortId;
} sli_zigbee_stack_unicast_current_network_key_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_unicast_current_network_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_unicast_current_network_key_ipc_req_t request;
  sli_zigbee_stack_unicast_current_network_key_ipc_rsp_t response;
} sli_zigbee_stack_unicast_current_network_key_ipc_msg_t;

#endif // TRUST_CENTER_IPC_COMMAND_MESSAGES_H
