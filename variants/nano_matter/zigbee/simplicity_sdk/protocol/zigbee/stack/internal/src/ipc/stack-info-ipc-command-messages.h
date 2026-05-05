/***************************************************************************//**
 * @file stack-info-ipc-command-messages.h
 * @brief defines structured format for 'stack-info' ipc messages
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
// automatically generated from stack-info.h.  Do not manually edit
#ifndef STACK_INFO_IPC_COMMAND_MESSAGES_H
#define STACK_INFO_IPC_COMMAND_MESSAGES_H

#include "stack/include/stack-info.h"
#include "stack/internal/inc/stack-info-internal-def.h"

typedef struct {
  uint16_t result;
} sli_802154_stack_get_tx_power_mode_ipc_rsp_t;

typedef struct {
  sli_802154_stack_get_tx_power_mode_ipc_rsp_t response;
} sli_802154_stack_get_tx_power_mode_ipc_msg_t;

typedef struct {
  sl_802154_radio_priorities_t priorities;
} sli_802154_stack_radio_get_scheduler_priorities_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_802154_stack_radio_get_scheduler_priorities_ipc_rsp_t;

typedef struct {
  sli_802154_stack_radio_get_scheduler_priorities_ipc_req_t request;
  sli_802154_stack_radio_get_scheduler_priorities_ipc_rsp_t response;
} sli_802154_stack_radio_get_scheduler_priorities_ipc_msg_t;

typedef struct {
  uint32_t slipTime;
} sli_802154_stack_radio_get_scheduler_sliptime_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_802154_stack_radio_get_scheduler_sliptime_ipc_rsp_t;

typedef struct {
  sli_802154_stack_radio_get_scheduler_sliptime_ipc_req_t request;
  sli_802154_stack_radio_get_scheduler_sliptime_ipc_rsp_t response;
} sli_802154_stack_radio_get_scheduler_sliptime_ipc_msg_t;

typedef struct {
  sl_802154_radio_priorities_t priorities;
} sli_802154_stack_radio_set_scheduler_priorities_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_802154_stack_radio_set_scheduler_priorities_ipc_rsp_t;

typedef struct {
  sli_802154_stack_radio_set_scheduler_priorities_ipc_req_t request;
  sli_802154_stack_radio_set_scheduler_priorities_ipc_rsp_t response;
} sli_802154_stack_radio_set_scheduler_priorities_ipc_msg_t;

typedef struct {
  uint32_t slipTime;
} sli_802154_stack_radio_set_scheduler_sliptime_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_802154_stack_radio_set_scheduler_sliptime_ipc_rsp_t;

typedef struct {
  sli_802154_stack_radio_set_scheduler_sliptime_ipc_req_t request;
  sli_802154_stack_radio_set_scheduler_sliptime_ipc_rsp_t response;
} sli_802154_stack_radio_set_scheduler_sliptime_ipc_msg_t;

typedef struct {
  uint16_t txPowerMode;
} sli_802154_stack_set_tx_power_mode_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_802154_stack_set_tx_power_mode_ipc_rsp_t;

typedef struct {
  sli_802154_stack_set_tx_power_mode_ipc_req_t request;
  sli_802154_stack_set_tx_power_mode_ipc_rsp_t response;
} sli_802154_stack_set_tx_power_mode_ipc_msg_t;

typedef struct {
  sl_mac_csma_parameters_t csma_params;
} sli_mac_stack_get_csma_params_ipc_req_t;

typedef struct {
  sli_mac_stack_get_csma_params_ipc_req_t request;
} sli_mac_stack_get_csma_params_ipc_msg_t;

typedef struct {
  int8_t result;
} sli_mac_stack_get_ed_cca_threshold_ipc_rsp_t;

typedef struct {
  sli_mac_stack_get_ed_cca_threshold_ipc_rsp_t response;
} sli_mac_stack_get_ed_cca_threshold_ipc_msg_t;

typedef struct {
  int8_t threshold;
} sli_mac_stack_set_cca_threshold_ipc_req_t;

typedef struct {
  sli_mac_stack_set_cca_threshold_ipc_req_t request;
} sli_mac_stack_set_cca_threshold_ipc_msg_t;

typedef struct {
  sl_mac_csma_parameters_t csma_params;
} sli_mac_stack_set_csma_params_ipc_req_t;

typedef struct {
  sli_mac_stack_set_csma_params_ipc_req_t request;
} sli_mac_stack_set_csma_params_ipc_msg_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_clear_counters_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_clear_counters_ipc_rsp_t response;
} sli_zigbee_stack_clear_counters_ipc_msg_t;

typedef struct {
  sl_zigbee_counter_type_t type;
} sli_zigbee_stack_counter_requires_destination_node_id_ipc_req_t;

typedef struct {
  bool result;
} sli_zigbee_stack_counter_requires_destination_node_id_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_counter_requires_destination_node_id_ipc_req_t request;
  sli_zigbee_stack_counter_requires_destination_node_id_ipc_rsp_t response;
} sli_zigbee_stack_counter_requires_destination_node_id_ipc_msg_t;

typedef struct {
  sl_zigbee_counter_type_t type;
} sli_zigbee_stack_counter_requires_phy_index_ipc_req_t;

typedef struct {
  bool result;
} sli_zigbee_stack_counter_requires_phy_index_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_counter_requires_phy_index_ipc_req_t request;
  sli_zigbee_stack_counter_requires_phy_index_ipc_rsp_t response;
} sli_zigbee_stack_counter_requires_phy_index_ipc_msg_t;

typedef struct {
  uint8_t index;
} sli_zigbee_stack_get_endpoint_ipc_req_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_endpoint_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_endpoint_ipc_req_t request;
  sli_zigbee_stack_get_endpoint_ipc_rsp_t response;
} sli_zigbee_stack_get_endpoint_ipc_msg_t;

typedef struct {
  uint8_t endpoint;
  sl_zigbee_cluster_list_id_t listId;
  uint8_t listIndex;
} sli_zigbee_stack_get_endpoint_cluster_ipc_req_t;

typedef struct {
  uint16_t result;
} sli_zigbee_stack_get_endpoint_cluster_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_endpoint_cluster_ipc_req_t request;
  sli_zigbee_stack_get_endpoint_cluster_ipc_rsp_t response;
} sli_zigbee_stack_get_endpoint_cluster_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_endpoint_count_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_endpoint_count_ipc_rsp_t response;
} sli_zigbee_stack_get_endpoint_count_ipc_msg_t;

typedef struct {
  uint8_t endpoint;
  sl_zigbee_endpoint_description_t result;
} sli_zigbee_stack_get_endpoint_description_ipc_req_t;

typedef struct {
  bool result;
} sli_zigbee_stack_get_endpoint_description_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_endpoint_description_ipc_req_t request;
  sli_zigbee_stack_get_endpoint_description_ipc_rsp_t response;
} sli_zigbee_stack_get_endpoint_description_ipc_msg_t;

typedef struct {
  uint8_t * result;
} sli_zigbee_stack_get_eui64_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_eui64_ipc_rsp_t response;
} sli_zigbee_stack_get_eui64_ipc_msg_t;

typedef struct {
  uint8_t resultLocation[16];
} sli_zigbee_stack_get_extended_pan_id_ipc_req_t;

typedef struct {
  sli_zigbee_stack_get_extended_pan_id_ipc_req_t request;
} sli_zigbee_stack_get_extended_pan_id_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_initial_neighbor_outgoing_cost_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_initial_neighbor_outgoing_cost_ipc_rsp_t response;
} sli_zigbee_stack_get_initial_neighbor_outgoing_cost_ipc_msg_t;

typedef struct {
  uint16_t result;
} sli_zigbee_stack_get_manufacturer_code_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_manufacturer_code_ipc_rsp_t response;
} sli_zigbee_stack_get_manufacturer_code_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_max_nwk_retries_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_max_nwk_retries_ipc_rsp_t response;
} sli_zigbee_stack_get_max_nwk_retries_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_zigbee_neighbor_table_entry_t result;
} sli_zigbee_stack_get_neighbor_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_neighbor_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_neighbor_ipc_req_t request;
  sli_zigbee_stack_get_neighbor_ipc_rsp_t response;
} sli_zigbee_stack_get_neighbor_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t nodeEui64;
  uint32_t returnFrameCounter;
} sli_zigbee_stack_get_neighbor_frame_counter_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_neighbor_frame_counter_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_neighbor_frame_counter_ipc_req_t request;
  sli_zigbee_stack_get_neighbor_frame_counter_ipc_rsp_t response;
} sli_zigbee_stack_get_neighbor_frame_counter_ipc_msg_t;

typedef struct {
  sl_zigbee_node_type_t node_type;
  sl_zigbee_network_parameters_t parameters;
} sli_zigbee_stack_get_network_parameters_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_network_parameters_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_network_parameters_ipc_req_t request;
  sli_zigbee_stack_get_network_parameters_ipc_rsp_t response;
} sli_zigbee_stack_get_network_parameters_ipc_msg_t;

typedef struct {
  sl_zigbee_node_descriptor_info_t descriptor;
} sli_zigbee_stack_get_node_descriptor_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_node_descriptor_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_node_descriptor_ipc_req_t request;
  sli_zigbee_stack_get_node_descriptor_ipc_rsp_t response;
} sli_zigbee_stack_get_node_descriptor_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t result;
} sli_zigbee_stack_get_node_id_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_node_id_ipc_rsp_t response;
} sli_zigbee_stack_get_node_id_ipc_msg_t;

typedef struct {
  sl_802154_pan_id_t result;
} sli_zigbee_stack_get_pan_id_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_pan_id_ipc_rsp_t response;
} sli_zigbee_stack_get_pan_id_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_phy_interface_count_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_phy_interface_count_ipc_rsp_t response;
} sli_zigbee_stack_get_phy_interface_count_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_radio_channel_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_radio_channel_ipc_rsp_t response;
} sli_zigbee_stack_get_radio_channel_ipc_msg_t;

typedef struct {
  uint8_t phyIndex;
  sl_zigbee_multi_phy_radio_parameters_t parameters;
} sli_zigbee_stack_get_radio_parameters_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_radio_parameters_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_radio_parameters_ipc_req_t request;
  sli_zigbee_stack_get_radio_parameters_ipc_rsp_t response;
} sli_zigbee_stack_get_radio_parameters_ipc_msg_t;

typedef struct {
  int8_t result;
} sli_zigbee_stack_get_radio_power_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_radio_power_ipc_rsp_t response;
} sli_zigbee_stack_get_radio_power_ipc_msg_t;

typedef struct {
  void * result;
} sli_zigbee_stack_get_rail_handle_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_rail_handle_ipc_rsp_t response;
} sli_zigbee_stack_get_rail_handle_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_zigbee_route_table_entry_t result;
} sli_zigbee_stack_get_route_table_entry_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_route_table_entry_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_route_table_entry_ipc_req_t request;
  sli_zigbee_stack_get_route_table_entry_ipc_rsp_t response;
} sli_zigbee_stack_get_route_table_entry_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_route_table_size_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_route_table_size_ipc_rsp_t response;
} sli_zigbee_stack_get_route_table_size_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_routing_shortcut_threshold_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_routing_shortcut_threshold_ipc_rsp_t response;
} sli_zigbee_stack_get_routing_shortcut_threshold_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_source_route_table_size_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_source_route_table_size_ipc_rsp_t response;
} sli_zigbee_stack_get_source_route_table_size_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_stack_compliance_revision_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_stack_compliance_revision_ipc_rsp_t response;
} sli_zigbee_stack_get_stack_compliance_revision_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_token_count_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_token_count_ipc_rsp_t response;
} sli_zigbee_stack_get_token_count_ipc_msg_t;

typedef struct {
  uint32_t token;
  uint32_t index;
  sl_zigbee_token_data_t tokenData;
} sli_zigbee_stack_get_token_data_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_token_data_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_token_data_ipc_req_t request;
  sli_zigbee_stack_get_token_data_ipc_rsp_t response;
} sli_zigbee_stack_get_token_data_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_zigbee_token_info_t tokenInfo;
} sli_zigbee_stack_get_token_info_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_token_info_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_token_info_ipc_req_t request;
  sli_zigbee_stack_get_token_info_ipc_rsp_t response;
} sli_zigbee_stack_get_token_info_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t eui64;
} sli_zigbee_stack_is_local_eui64_ipc_req_t;

typedef struct {
  bool result;
} sli_zigbee_stack_is_local_eui64_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_is_local_eui64_ipc_req_t request;
  sli_zigbee_stack_is_local_eui64_ipc_rsp_t response;
} sli_zigbee_stack_is_local_eui64_ipc_msg_t;

typedef struct {
  bool result;
} sli_zigbee_stack_is_reset_rejoining_neighbors_frame_counter_enabled_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_is_reset_rejoining_neighbors_frame_counter_enabled_ipc_rsp_t response;
} sli_zigbee_stack_is_reset_rejoining_neighbors_frame_counter_enabled_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t nodeId;
  sl_802154_long_addr_t eui64Return;
} sli_zigbee_stack_lookup_eui64_by_node_id_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_lookup_eui64_by_node_id_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_lookup_eui64_by_node_id_ipc_req_t request;
  sli_zigbee_stack_lookup_eui64_by_node_id_ipc_rsp_t response;
} sli_zigbee_stack_lookup_eui64_by_node_id_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t eui64;
  sl_802154_short_addr_t node_id;
} sli_zigbee_stack_lookup_node_id_by_eui64_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_lookup_node_id_by_eui64_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_lookup_node_id_by_eui64_ipc_req_t request;
  sli_zigbee_stack_lookup_node_id_by_eui64_ipc_rsp_t response;
} sli_zigbee_stack_lookup_node_id_by_eui64_ipc_msg_t;

typedef struct {
  uint32_t result;
} sli_zigbee_stack_ms_to_next_stack_event_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_ms_to_next_stack_event_ipc_rsp_t response;
} sli_zigbee_stack_ms_to_next_stack_event_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_neighbor_count_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_neighbor_count_ipc_rsp_t response;
} sli_zigbee_stack_neighbor_count_ipc_msg_t;

typedef struct {
  sl_zigbee_network_status_t result;
} sli_zigbee_stack_network_state_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_network_state_ipc_rsp_t response;
} sli_zigbee_stack_network_state_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_next_zigbee_sequence_number_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_next_zigbee_sequence_number_ipc_rsp_t response;
} sli_zigbee_stack_next_zigbee_sequence_number_ipc_msg_t;

typedef struct {
  uint16_t counter_array[SL_ZIGBEE_COUNTER_TYPE_COUNT];
  uint8_t len;
} sli_zigbee_stack_read_and_clear_counters_ipc_req_t;

typedef struct {
  sli_zigbee_stack_read_and_clear_counters_ipc_req_t request;
} sli_zigbee_stack_read_and_clear_counters_ipc_msg_t;

typedef struct {
  uint16_t counter_array[SL_ZIGBEE_COUNTER_TYPE_COUNT];
  uint8_t len;
} sli_zigbee_stack_read_counters_ipc_req_t;

typedef struct {
  sli_zigbee_stack_read_counters_ipc_req_t request;
} sli_zigbee_stack_read_counters_ipc_msg_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_reset_counters_thresholds_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_reset_counters_thresholds_ipc_rsp_t response;
} sli_zigbee_stack_reset_counters_thresholds_ipc_msg_t;

typedef struct {
  bool reset;
} sli_zigbee_stack_reset_rejoining_neighbors_frame_counter_ipc_req_t;

typedef struct {
  sli_zigbee_stack_reset_rejoining_neighbors_frame_counter_ipc_req_t request;
} sli_zigbee_stack_reset_rejoining_neighbors_frame_counter_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_security_level_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_security_level_ipc_rsp_t response;
} sli_zigbee_stack_security_level_ipc_msg_t;

typedef struct {
  uint8_t errorCode;
} sli_zigbee_stack_set_broken_route_error_code_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_broken_route_error_code_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_broken_route_error_code_ipc_req_t request;
  sli_zigbee_stack_set_broken_route_error_code_ipc_rsp_t response;
} sli_zigbee_stack_set_broken_route_error_code_ipc_msg_t;

typedef struct {
  sl_zigbee_counter_type_t type;
  uint16_t threshold;
} sli_zigbee_stack_set_counter_threshold_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_counter_threshold_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_counter_threshold_ipc_req_t request;
  sli_zigbee_stack_set_counter_threshold_ipc_rsp_t response;
} sli_zigbee_stack_set_counter_threshold_ipc_msg_t;

typedef struct {
  uint8_t cost;
} sli_zigbee_stack_set_initial_neighbor_outgoing_cost_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_initial_neighbor_outgoing_cost_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_initial_neighbor_outgoing_cost_ipc_req_t request;
  sli_zigbee_stack_set_initial_neighbor_outgoing_cost_ipc_rsp_t response;
} sli_zigbee_stack_set_initial_neighbor_outgoing_cost_ipc_msg_t;

typedef struct {
  uint8_t channel;
} sli_zigbee_stack_set_logical_and_radio_channel_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_logical_and_radio_channel_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_logical_and_radio_channel_ipc_req_t request;
  sli_zigbee_stack_set_logical_and_radio_channel_ipc_rsp_t response;
} sli_zigbee_stack_set_logical_and_radio_channel_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t nodeEui64;
  uint32_t frameCounter;
} sli_zigbee_stack_set_neighbor_frame_counter_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_neighbor_frame_counter_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_neighbor_frame_counter_ipc_req_t request;
  sli_zigbee_stack_set_neighbor_frame_counter_ipc_rsp_t response;
} sli_zigbee_stack_set_neighbor_frame_counter_ipc_msg_t;

typedef struct {
  sl_zigbee_node_descriptor_info_t descriptor;
} sli_zigbee_stack_set_node_descriptor_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_node_descriptor_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_node_descriptor_ipc_req_t request;
  sli_zigbee_stack_set_node_descriptor_ipc_rsp_t response;
} sli_zigbee_stack_set_node_descriptor_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t nodeId;
} sli_zigbee_stack_set_node_id_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_node_id_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_node_id_ipc_req_t request;
  sli_zigbee_stack_set_node_id_ipc_rsp_t response;
} sli_zigbee_stack_set_node_id_ipc_msg_t;

typedef struct {
  uint16_t descriptor;
} sli_zigbee_stack_set_power_descriptor_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_power_descriptor_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_power_descriptor_ipc_req_t request;
  sli_zigbee_stack_set_power_descriptor_ipc_rsp_t response;
} sli_zigbee_stack_set_power_descriptor_ipc_msg_t;

typedef struct {
  uint8_t channel;
} sli_zigbee_stack_set_radio_channel_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_radio_channel_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_radio_channel_ipc_req_t request;
  sli_zigbee_stack_set_radio_channel_ipc_rsp_t response;
} sli_zigbee_stack_set_radio_channel_ipc_msg_t;

typedef struct {
  uint8_t ccaMode;
} sli_zigbee_stack_set_radio_ieee802154_cca_mode_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_radio_ieee802154_cca_mode_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_radio_ieee802154_cca_mode_ipc_req_t request;
  sli_zigbee_stack_set_radio_ieee802154_cca_mode_ipc_rsp_t response;
} sli_zigbee_stack_set_radio_ieee802154_cca_mode_ipc_msg_t;

typedef struct {
  int8_t power;
} sli_zigbee_stack_set_radio_power_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_radio_power_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_radio_power_ipc_req_t request;
  sli_zigbee_stack_set_radio_power_ipc_rsp_t response;
} sli_zigbee_stack_set_radio_power_ipc_msg_t;

typedef struct {
  uint8_t size;
} sli_zigbee_stack_set_route_table_size_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_route_table_size_ipc_req_t request;
} sli_zigbee_stack_set_route_table_size_ipc_msg_t;

typedef struct {
  uint8_t costThresh;
} sli_zigbee_stack_set_routing_shortcut_threshold_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_routing_shortcut_threshold_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_routing_shortcut_threshold_ipc_req_t request;
  sli_zigbee_stack_set_routing_shortcut_threshold_ipc_rsp_t response;
} sli_zigbee_stack_set_routing_shortcut_threshold_ipc_msg_t;

typedef struct {
  uint8_t securityLevel;
} sli_zigbee_stack_set_security_level_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_security_level_ipc_req_t request;
} sli_zigbee_stack_set_security_level_ipc_msg_t;

typedef struct {
  uint8_t size;
} sli_zigbee_stack_set_source_route_table_size_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_source_route_table_size_ipc_req_t request;
} sli_zigbee_stack_set_source_route_table_size_ipc_msg_t;

typedef struct {
  uint8_t stackProfile;
} sli_zigbee_stack_set_stack_profile_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_stack_profile_ipc_req_t request;
} sli_zigbee_stack_set_stack_profile_ipc_msg_t;

typedef struct {
  uint32_t token;
  uint32_t index;
  sl_zigbee_token_data_t tokenData;
} sli_zigbee_stack_set_token_data_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_token_data_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_token_data_ipc_req_t request;
  sli_zigbee_stack_set_token_data_ipc_rsp_t response;
} sli_zigbee_stack_set_token_data_ipc_msg_t;

typedef struct {
  bool result;
} sli_zigbee_stack_stack_is_up_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_stack_is_up_ipc_rsp_t response;
} sli_zigbee_stack_stack_is_up_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_stack_profile_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_stack_profile_ipc_rsp_t response;
} sli_zigbee_stack_stack_profile_ipc_msg_t;

typedef struct {
  bool exclude_outgoing_fc;
  bool exclude_boot_counter;
} sli_zigbee_stack_token_factory_reset_ipc_req_t;

typedef struct {
  sli_zigbee_stack_token_factory_reset_ipc_req_t request;
} sli_zigbee_stack_token_factory_reset_ipc_msg_t;

typedef struct {
  bool erase;
} sli_zigbee_stack_write_node_data_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_write_node_data_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_write_node_data_ipc_req_t request;
  sli_zigbee_stack_write_node_data_ipc_rsp_t response;
} sli_zigbee_stack_write_node_data_ipc_msg_t;

typedef struct {
  uint8_t result;
} slxi_zigbee_stack_routing_get_route_record_policy_ipc_rsp_t;

typedef struct {
  slxi_zigbee_stack_routing_get_route_record_policy_ipc_rsp_t response;
} slxi_zigbee_stack_routing_get_route_record_policy_ipc_msg_t;

typedef struct {
  sl_zigbee_route_record_policy_type_t policy;
} slxi_zigbee_stack_routing_set_route_record_policy_ipc_req_t;

typedef struct {
  sl_status_t result;
} slxi_zigbee_stack_routing_set_route_record_policy_ipc_rsp_t;

typedef struct {
  slxi_zigbee_stack_routing_set_route_record_policy_ipc_req_t request;
  slxi_zigbee_stack_routing_set_route_record_policy_ipc_rsp_t response;
} slxi_zigbee_stack_routing_set_route_record_policy_ipc_msg_t;

#endif // STACK_INFO_IPC_COMMAND_MESSAGES_H
