/***************************************************************************//**
 * @file child_ipc_command_messages.h
 * @brief defines structured format for 'child' ipc messages
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
// automatically generated from child.h.  Do not manually edit
#ifndef CHILD_IPC_COMMAND_MESSAGES_H
#define CHILD_IPC_COMMAND_MESSAGES_H

#include "stack/include/child.h"
#include "stack/internal/inc/child_internal_def.h"

typedef struct {
  sl_802154_short_addr_t shortId;
  sl_802154_long_addr_t longId;
  sl_zigbee_node_type_t nodeType;
} sli_zigbee_stack_add_child_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_add_child_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_add_child_ipc_req_t request;
  sli_zigbee_stack_add_child_ipc_rsp_t response;
} sli_zigbee_stack_add_child_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_child_count_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_child_count_ipc_rsp_t response;
} sli_zigbee_stack_child_count_ipc_msg_t;

typedef struct {
  uint8_t childIndex;
} sli_zigbee_stack_child_id_ipc_req_t;

typedef struct {
  sl_802154_short_addr_t result;
} sli_zigbee_stack_child_id_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_child_id_ipc_req_t request;
  sli_zigbee_stack_child_id_ipc_rsp_t response;
} sli_zigbee_stack_child_id_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t childId;
} sli_zigbee_stack_child_index_ipc_req_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_child_index_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_child_index_ipc_req_t request;
  sli_zigbee_stack_child_index_ipc_rsp_t response;
} sli_zigbee_stack_child_index_ipc_msg_t;

typedef struct {
  uint8_t childIndex;
} sli_zigbee_stack_child_power_ipc_req_t;

typedef struct {
  int8_t result;
} sli_zigbee_stack_child_power_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_child_power_ipc_req_t request;
  sli_zigbee_stack_child_power_ipc_rsp_t response;
} sli_zigbee_stack_child_power_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t childId;
} sli_zigbee_stack_clear_message_flag_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_clear_message_flag_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_clear_message_flag_ipc_req_t request;
  sli_zigbee_stack_clear_message_flag_ipc_rsp_t response;
} sli_zigbee_stack_clear_message_flag_ipc_msg_t;

typedef struct {
  uint16_t result;
} sli_zigbee_stack_current_stack_tasks_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_current_stack_tasks_ipc_rsp_t response;
} sli_zigbee_stack_current_stack_tasks_ipc_msg_t;

typedef struct {
  int8_t result;
} sli_zigbee_stack_get_avg_parent_rssi_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_avg_parent_rssi_ipc_rsp_t response;
} sli_zigbee_stack_get_avg_parent_rssi_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_zigbee_child_data_t childData;
} sli_zigbee_stack_get_child_data_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_child_data_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_child_data_ipc_req_t request;
  sli_zigbee_stack_get_child_data_ipc_rsp_t response;
} sli_zigbee_stack_get_child_data_ipc_msg_t;

typedef struct {
  sl_zigbee_keep_alive_mode_t result;
} sli_zigbee_stack_get_keep_alive_mode_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_keep_alive_mode_ipc_rsp_t response;
} sli_zigbee_stack_get_keep_alive_mode_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_max_end_device_children_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_max_end_device_children_ipc_rsp_t response;
} sli_zigbee_stack_get_max_end_device_children_ipc_msg_t;

typedef struct {
  uint8_t * result;
} sli_zigbee_stack_get_parent_eui64_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_parent_eui64_ipc_rsp_t response;
} sli_zigbee_stack_get_parent_eui64_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t result;
} sli_zigbee_stack_get_parent_id_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_parent_id_ipc_rsp_t response;
} sli_zigbee_stack_get_parent_id_ipc_msg_t;

typedef struct {
  uint32_t result;
} sli_zigbee_stack_get_parent_incoming_nwk_frame_counter_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_parent_incoming_nwk_frame_counter_ipc_rsp_t response;
} sli_zigbee_stack_get_parent_incoming_nwk_frame_counter_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t result;
} sli_zigbee_stack_get_parent_node_id_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_parent_node_id_ipc_rsp_t response;
} sli_zigbee_stack_get_parent_node_id_ipc_msg_t;

typedef struct {
  bool result;
} sli_zigbee_stack_parent_token_set_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_parent_token_set_ipc_rsp_t response;
} sli_zigbee_stack_parent_token_set_ipc_msg_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_poll_for_data_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_poll_for_data_ipc_rsp_t response;
} sli_zigbee_stack_poll_for_data_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t childEui64;
} sli_zigbee_stack_remove_child_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_remove_child_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_remove_child_ipc_req_t request;
  sli_zigbee_stack_remove_child_ipc_rsp_t response;
} sli_zigbee_stack_remove_child_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t shortId;
  sl_802154_long_addr_t longId;
} sli_zigbee_stack_remove_neighbor_ipc_req_t;

typedef struct {
  sli_zigbee_stack_remove_neighbor_ipc_req_t request;
} sli_zigbee_stack_remove_neighbor_ipc_msg_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_send_link_power_delta_request_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_link_power_delta_request_ipc_rsp_t response;
} sli_zigbee_stack_send_link_power_delta_request_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_zigbee_child_data_t childData;
} sli_zigbee_stack_set_child_data_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_child_data_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_child_data_ipc_req_t request;
  sli_zigbee_stack_set_child_data_ipc_rsp_t response;
} sli_zigbee_stack_set_child_data_ipc_msg_t;

typedef struct {
  uint8_t childIndex;
  int8_t newPower;
} sli_zigbee_stack_set_child_power_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_child_power_ipc_req_t request;
} sli_zigbee_stack_set_child_power_ipc_msg_t;

typedef struct {
  uint16_t mask;
} sli_zigbee_stack_set_child_timeout_option_mask_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_child_timeout_option_mask_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_child_timeout_option_mask_ipc_req_t request;
  sli_zigbee_stack_set_child_timeout_option_mask_ipc_rsp_t response;
} sli_zigbee_stack_set_child_timeout_option_mask_ipc_msg_t;

typedef struct {
  sl_zigbee_keep_alive_mode_t mode;
} sli_zigbee_stack_set_keep_alive_mode_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_keep_alive_mode_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_keep_alive_mode_ipc_req_t request;
  sli_zigbee_stack_set_keep_alive_mode_ipc_rsp_t response;
} sli_zigbee_stack_set_keep_alive_mode_ipc_msg_t;

typedef struct {
  uint32_t waitBeforeRetryIntervalMs;
} sli_zigbee_stack_set_mac_poll_failure_wait_time_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_mac_poll_failure_wait_time_ipc_req_t request;
} sli_zigbee_stack_set_mac_poll_failure_wait_time_ipc_msg_t;

typedef struct {
  uint8_t max;
} sli_zigbee_stack_set_max_end_device_children_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_max_end_device_children_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_max_end_device_children_ipc_req_t request;
  sli_zigbee_stack_set_max_end_device_children_ipc_rsp_t response;
} sli_zigbee_stack_set_max_end_device_children_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t childId;
} sli_zigbee_stack_set_message_flag_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_message_flag_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_message_flag_ipc_req_t request;
  sli_zigbee_stack_set_message_flag_ipc_rsp_t response;
} sli_zigbee_stack_set_message_flag_ipc_msg_t;

typedef struct {
  uint32_t value;
} sli_zigbee_stack_set_parent_incoming_nwk_frame_counter_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_parent_incoming_nwk_frame_counter_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_parent_incoming_nwk_frame_counter_ipc_req_t request;
  sli_zigbee_stack_set_parent_incoming_nwk_frame_counter_ipc_rsp_t response;
} sli_zigbee_stack_set_parent_incoming_nwk_frame_counter_ipc_msg_t;

#endif // CHILD_IPC_COMMAND_MESSAGES_H
