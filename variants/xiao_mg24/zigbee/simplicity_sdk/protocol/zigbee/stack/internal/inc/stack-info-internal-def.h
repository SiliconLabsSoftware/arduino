/***************************************************************************//**
 * @file stack-info-internal-def.h
 * @brief internal names for 'stack-info' declarations
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
#ifndef STACK_INFO_INTERNAL_DEF_H
#define STACK_INFO_INTERNAL_DEF_H

#include "stack/include/stack-info.h"

// Command Indirection

uint16_t sli_802154_stack_get_tx_power_mode(void);

sl_status_t sli_802154_stack_radio_get_scheduler_priorities(sl_802154_radio_priorities_t *priorities);

sl_status_t sli_802154_stack_radio_get_scheduler_sliptime(uint32_t *slipTime);

sl_status_t sli_802154_stack_radio_set_scheduler_priorities(const sl_802154_radio_priorities_t *priorities);

sl_status_t sli_802154_stack_radio_set_scheduler_sliptime(uint32_t slipTime);

sl_status_t sli_802154_stack_set_tx_power_mode(uint16_t txPowerMode);

void sli_mac_stack_calibrate_current_channel(void);

void sli_mac_stack_get_csma_params(sl_mac_csma_parameters_t *csma_params);

int8_t sli_mac_stack_get_ed_cca_threshold(void);

void sli_mac_stack_set_cca_threshold(int8_t threshold);

void sli_mac_stack_set_csma_params(sl_mac_csma_parameters_t *csma_params);

sl_status_t sli_zigbee_stack_clear_counters(void);

bool sli_zigbee_stack_counter_requires_destination_node_id(sl_zigbee_counter_type_t type);

bool sli_zigbee_stack_counter_requires_phy_index(sl_zigbee_counter_type_t type);

uint8_t sli_zigbee_stack_get_endpoint(uint8_t index);

uint16_t sli_zigbee_stack_get_endpoint_cluster(uint8_t endpoint,
                                               sl_zigbee_cluster_list_id_t listId,
                                               uint8_t listIndex);

uint8_t sli_zigbee_stack_get_endpoint_count(void);

bool sli_zigbee_stack_get_endpoint_description(uint8_t endpoint,
                                               sl_zigbee_endpoint_description_t *result);

uint8_t * sli_zigbee_stack_get_eui64(void);

void sli_zigbee_stack_get_extended_pan_id(uint8_t *resultLocation);

uint8_t sli_zigbee_stack_get_initial_neighbor_outgoing_cost(void);

uint16_t sli_zigbee_stack_get_manufacturer_code(void);

uint8_t sli_zigbee_stack_get_max_nwk_retries(void);

sl_status_t sli_zigbee_stack_get_neighbor(uint8_t index,
                                          sl_zigbee_neighbor_table_entry_t *result);

sl_status_t sli_zigbee_stack_get_neighbor_frame_counter(sl_802154_long_addr_t nodeEui64,
                                                        uint32_t *returnFrameCounter);

sl_status_t sli_zigbee_stack_get_network_parameters(sl_zigbee_node_type_t *node_type,
                                                    sl_zigbee_network_parameters_t *parameters);

sl_status_t sli_zigbee_stack_get_node_descriptor(sl_zigbee_node_descriptor_info_t *descriptor);

sl_802154_short_addr_t sli_zigbee_stack_get_node_id(void);

sl_802154_pan_id_t sli_zigbee_stack_get_pan_id(void);

uint8_t sli_zigbee_stack_get_phy_interface_count(void);

uint8_t sli_zigbee_stack_get_radio_channel(void);

sl_status_t sli_zigbee_stack_get_radio_parameters(uint8_t phyIndex,
                                                  sl_zigbee_multi_phy_radio_parameters_t *parameters);

int8_t sli_zigbee_stack_get_radio_power(void);

void * sli_zigbee_stack_get_rail_handle(void);

sl_status_t sli_zigbee_stack_get_route_table_entry(uint8_t index,
                                                   sl_zigbee_route_table_entry_t *result);

uint8_t sli_zigbee_stack_get_route_table_size(void);

uint8_t sli_zigbee_stack_get_routing_shortcut_threshold(void);

uint8_t sli_zigbee_stack_get_source_route_table_size(void);

uint8_t sli_zigbee_stack_get_stack_compliance_revision(void);

uint8_t sli_zigbee_stack_get_token_count(void);

sl_status_t sli_zigbee_stack_get_token_data(uint32_t token,
                                            uint32_t index,
                                            sl_zigbee_token_data_t *tokenData);

sl_status_t sli_zigbee_stack_get_token_info(uint8_t index,
                                            sl_zigbee_token_info_t *tokenInfo);

bool sli_zigbee_stack_is_local_eui64(sl_802154_long_addr_t eui64);

bool sli_zigbee_stack_is_reset_rejoining_neighbors_frame_counter_enabled(void);

sl_status_t sli_zigbee_stack_lookup_eui64_by_node_id(sl_802154_short_addr_t nodeId,
                                                     sl_802154_long_addr_t eui64Return);

sl_status_t sli_zigbee_stack_lookup_node_id_by_eui64(sl_802154_long_addr_t eui64,
                                                     sl_802154_short_addr_t *node_id);

uint32_t sli_zigbee_stack_ms_to_next_stack_event(void);

uint8_t sli_zigbee_stack_neighbor_count(void);

sl_zigbee_network_status_t sli_zigbee_stack_network_state(void);

uint8_t sli_zigbee_stack_next_zigbee_sequence_number(void);

void sli_zigbee_stack_read_and_clear_counters(uint16_t *counter_array,
                                              uint8_t len);

void sli_zigbee_stack_read_counters(uint16_t *counter_array,
                                    uint8_t len);

sl_status_t sli_zigbee_stack_reset_counters_thresholds(void);

void sli_zigbee_stack_reset_rejoining_neighbors_frame_counter(bool reset);

uint8_t sli_zigbee_stack_security_level(void);

sl_status_t sli_zigbee_stack_set_broken_route_error_code(uint8_t errorCode);

sl_status_t sli_zigbee_stack_set_counter_threshold(sl_zigbee_counter_type_t type,
                                                   uint16_t threshold);

sl_status_t sli_zigbee_stack_set_initial_neighbor_outgoing_cost(uint8_t cost);

sl_status_t sli_zigbee_stack_set_logical_and_radio_channel(uint8_t channel);

sl_status_t sli_zigbee_stack_set_neighbor_frame_counter(sl_802154_long_addr_t nodeEui64,
                                                        uint32_t frameCounter);

sl_status_t sli_zigbee_stack_set_node_descriptor(sl_zigbee_node_descriptor_info_t *descriptor);

sl_status_t sli_zigbee_stack_set_node_id(sl_802154_short_addr_t nodeId);

sl_status_t sli_zigbee_stack_set_power_descriptor(uint16_t descriptor);

sl_status_t sli_zigbee_stack_set_radio_channel(uint8_t channel);

sl_status_t sli_zigbee_stack_set_radio_ieee802154_cca_mode(uint8_t ccaMode);

sl_status_t sli_zigbee_stack_set_radio_power(int8_t power);

void sli_zigbee_stack_set_route_table_size(uint8_t size);

sl_status_t sli_zigbee_stack_set_routing_shortcut_threshold(uint8_t costThresh);

void sli_zigbee_stack_set_security_level(uint8_t securityLevel);

void sli_zigbee_stack_set_source_route_table_size(uint8_t size);

void sli_zigbee_stack_set_stack_profile(uint8_t stackProfile);

sl_status_t sli_zigbee_stack_set_token_data(uint32_t token,
                                            uint32_t index,
                                            sl_zigbee_token_data_t *tokenData);

bool sli_zigbee_stack_stack_is_up(void);

uint8_t sli_zigbee_stack_stack_profile(void);

void sli_zigbee_stack_token_factory_reset(bool exclude_outgoing_fc,
                                          bool exclude_boot_counter);

sl_status_t sli_zigbee_stack_write_node_data(bool erase);

uint8_t slxi_zigbee_stack_routing_get_route_record_policy(void);

sl_status_t slxi_zigbee_stack_routing_set_route_record_policy(sl_zigbee_route_record_policy_type_t policy);

// Callback Indirection

void sli_zigbee_stack_radio_needs_calibrating_handler(void);

void sli_zigbee_stack_stack_status_handler(sl_status_t status);

void sli_zigbee_stack_stack_token_changed_handler(uint16_t tokenAddress);

#endif // STACK_INFO_INTERNAL_DEF_H
