/***************************************************************************//**
 * @file
 * @brief User-configurable stack memory allocation and convenience stubs
 * for little-used callbacks.
 *
 *
 * \b Note: Application developers should \b not modify any portion
 * of this file. Doing so may lead to mysterious bugs. Allocations should be
 * adjusted only with macros in a custom CONFIGURATION_HEADER.
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
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
#ifndef INTERNAL_CALLBACKS_PATCH_H
#define INTERNAL_CALLBACKS_PATCH_H
#include PLATFORM_HEADER
#include "stack/include/sl_zigbee.h"
#include "stack/include/message.h" // Required for packetHandlers
#include "mac-child.h" // unified-mac
#include "scan.h" // Required for PG_CH_BITMASK32
#include "stack/include/sl_zigbee_types_internal.h"

sl_zigbee_join_decision_t sl_zigbee_internal_trust_center_join_handler(sl_802154_short_addr_t newNodeId,
                                                                       sl_802154_long_addr_t newNodeEui64,
                                                                       sl_zigbee_device_update_t status,
                                                                       sl_802154_short_addr_t parentOfNewNode);

void sli_zigbee_stack_trust_center_post_join_handler(sl_802154_short_addr_t newNodeId,
                                                     sl_802154_long_addr_t newNodeEui64,
                                                     sl_zigbee_device_update_t status,
                                                     sl_zigbee_join_decision_t policyDecision,
                                                     sl_802154_short_addr_t parentOfNewNode);

void sli_zigbee_stack_switch_network_key_handler(uint8_t sequenceNumber);

void sli_zigbee_stack_zigbee_key_establishment_handler(sl_802154_long_addr_t partner, sl_zigbee_key_status_t status);

void sli_zigbee_stack_child_join_handler(uint8_t index,
                                         bool joining,
                                         sl_802154_short_addr_t childId,
                                         sl_802154_long_addr_t childEui64,
                                         sl_zigbee_node_type_t childType);
void sli_zigbee_stack_poll_complete_handler(sl_status_t status);

void sli_zigbee_stack_incoming_bootload_message_handler(sl_802154_long_addr_t longId,
                                                        sl_zigbee_rx_packet_info_t *packetInfo,
                                                        uint8_t  messageLength,
                                                        uint8_t *messageContents);
void sli_zigbee_stack_bootload_transmit_complete_handler(sl_status_t status,
                                                         uint8_t messageLength,
                                                         uint8_t *messageContents);

void sli_zigbee_stack_raw_transmit_complete_handler(uint8_t messageLength,
                                                    uint8_t* messageContents,
                                                    sl_status_t status);

void sli_zigbee_stack_energy_scan_result_handler(uint8_t channel, int8_t maxRssiValue);
void sl_zigbee_debug_handler(uint8_t messageLength, uint8_t *messageContents);

void sli_zigbee_stack_poll_handler(sl_802154_short_addr_t childId, bool transmitExpected);

sl_zigbee_zdo_status_t sl_zigbee_internal_remote_set_binding_handler(sl_zigbee_binding_table_entry_t *entry);
sl_zigbee_zdo_status_t sl_zigbee_internal_remote_delete_binding_handler(uint8_t index);

void sli_zigbee_stack_incoming_many_to_one_route_request_handler(sl_802154_short_addr_t source,
                                                                 sl_802154_long_addr_t longId,
                                                                 uint8_t cost);

void sli_zigbee_stack_incoming_route_error_handler(sl_status_t status,
                                                   sl_802154_short_addr_t target);
void sli_zigbee_stack_incoming_network_status_handler(uint8_t errorCode,
                                                      sl_802154_short_addr_t target);

void sli_zigbee_stack_incoming_route_record_handler(
  sl_zigbee_rx_packet_info_t *packetInfo,
  uint8_t relayCount,
  uint8_t *relayList);

//Deprecated
uint8_t sli_zigbee_stack_append_source_route_handler(sl_802154_short_addr_t destination,
                                                     sli_buffer_manager_buffer_t header);

void sli_zigbee_stack_override_incoming_route_record_handler(sl_zigbee_rx_packet_info_t *packetInfo,
                                                             uint8_t relayCount,
                                                             uint8_t *relayList,
                                                             bool* consumed);

sl_status_t sli_zigbee_stack_pan_id_conflict_handler(int8_t conflictCount);

void sl_zigbee_counter_rollover_handler(sl_zigbee_counter_type_t type);

void sl_zigbee_mux_invalid_rx_handler(uint8_t new_rx_channel, uint8_t old_rx_channel);

void sli_zigbee_stack_stack_token_changed_handler(uint16_t tokenAddress);

void sli_zigbee_stack_id_conflict_handler(sl_802154_short_addr_t conflictingId);

void sli_zigbee_stack_zll_address_assignment_handler(sl_zigbee_zll_address_assignment_t* addressInfo,
                                                     sl_zigbee_rx_packet_info_t *packetInfo);

void sli_zigbee_stack_zll_network_found_handler(sl_zigbee_zll_network_t* networkInfo,
                                                bool isDeviceInfoNull,
                                                sl_zigbee_zll_device_info_record_t* deviceInfo,
                                                sl_zigbee_rx_packet_info_t *packetInfo);

void sli_zigbee_stack_zll_scan_complete_handler(sl_status_t status);

void sl_zigbee_zll_touch_link_target_handler(const sl_zigbee_zll_network_t* networkInfo);

void sli_zigbee_stack_calculate_smacs_handler(sl_status_t status,
                                              sl_zigbee_smac_data_t* initiatorSmac,
                                              sl_zigbee_smac_data_t* responderSmac);

void sli_zigbee_stack_generate_cbke_keys_handler(sl_status_t status,
                                                 sl_zigbee_public_key_data_t *ephemeralPublicKey);

void sli_zigbee_stack_calculate_smacs_283k1_handler(sl_status_t status,
                                                    sl_zigbee_smac_data_t *initiatorSmac,
                                                    sl_zigbee_smac_data_t *responderSmac);
void sli_zigbee_stack_generate_cbke_keys_283k1_handler(sl_status_t status,
                                                       sl_zigbee_public_key_283k1_data_t *ephemeralPublicKey);

void sli_zigbee_stack_dsa_sign_handler(sl_status_t status,
                                       uint8_t messageLength,
                                       uint8_t *messageContents);

void sli_zigbee_stack_dsa_verify_handler(sl_status_t status);

void sli_zigbee_stack_rtos_stack_wakeup_isr_handler(void);

void sli_zigbee_stack_duty_cycle_handler(uint8_t channelPage,
                                         uint8_t channel,
                                         sl_zigbee_duty_cycle_state_t state,
                                         uint8_t totalDevices,
                                         sl_zigbee_per_device_duty_cycle_t *arrayOfLocalDeviceDutyCycles);

sl_zigbee_packet_action_t sl_zigbee_intersl_zigbee_internal_packet_handoff_r(sl_zigbee_zigbee_packet_type_t packetType,
                                                                             sli_buffer_manager_buffer_t packetBuffer,
                                                                             uint8_t index,
                                                                             void *data);

sl_zigbee_packet_action_t sl_zigbeesl_zigbee_internal_packet_handoff_handler(sl_zigbee_zigbee_packet_type_t packetType,
                                                                             sli_buffer_manager_buffer_t packetBuffer,
                                                                             uint8_t index,
                                                                             void *data);
void sli_zigbee_stack_stack_status_handler(sl_status_t status);

void sli_zigbee_stack_incoming_message_handler(sl_zigbee_incoming_message_type_t type,
                                               sl_zigbee_aps_frame_t *apsFrame,
                                               sl_zigbee_rx_packet_info_t *packetInfo,
                                               uint8_t messageLength,
                                               uint8_t *message);

void sli_zigbee_stack_message_sent_handler(sl_status_t status,
                                           sl_zigbee_outgoing_message_type_t type,
                                           uint16_t indexOrDestination,
                                           sl_zigbee_aps_frame_t *apsFrame,
                                           uint16_t messageTag,
                                           uint8_t messageLength,
                                           uint8_t *message);

void sli_zigbee_stack_zll_touch_link_target_handler(const sl_zigbee_zll_network_t* networkInfo);
void sli_zigbee_stack_scan_complete_handler(uint8_t channel, sl_status_t status);
void sli_zigbee_stack_network_found_handler(sl_zigbee_zigbee_network_t *networkFound, uint8_t lqi, int8_t rssi);

void sli_zigbee_stack_radio_needs_calibrating_handler(void);
void sli_zigbee_stack_unused_pan_id_found_handler(sl_802154_pan_id_t panId, uint8_t channel);

//why did we need these sl_.. prefixed handlers here
void sl_802154_filter_match_message_handler(uint8_t filterIndexMatch,
                                            uint8_t legacyPassthroughType,
                                            sl_zigbee_rx_packet_info_t *packetInfo,
                                            uint8_t messageLength,
                                            uint8_t *messageContents);

void sl_802154_passthrough_message_handler(sl_zigbee_mac_passthrough_type_t messageType,
                                           sl_zigbee_rx_packet_info_t *packetInfo,
                                           uint8_t messageLength,
                                           uint8_t *messageContents);

void sl_zigbee_incoming_mfg_test_message_handler(uint8_t messageType,
                                                 uint8_t dataLength,
                                                 uint8_t *data);

void sl_zigbee_orphan_notification_handler(sl_802154_long_addr_t longId);

void sl_zigbee_mark_buffers_handler();

void sli_zigbee_stack_remote_delete_binding_handler(uint8_t index,
                                                    sl_zigbee_zdo_status_t status);

void sli_zigbee_stack_remote_set_binding_handler(sl_zigbee_binding_table_entry_t * entry,
                                                 sl_zigbee_zdo_status_t status);

void sli_zigbee_stack_gpep_incoming_message_handler(sl_zigbee_gp_status_t status,
                                                    uint8_t gpdLink,
                                                    uint8_t sequenceNumber,
                                                    sl_zigbee_gp_address_t *addr,
                                                    sl_zigbee_gp_security_level_t gpdfSecurityLevel,
                                                    sl_zigbee_gp_key_type_t gpdfSecurityKeyType,
                                                    bool autoCommissioning,
                                                    uint8_t bidirectionalInfo,
                                                    uint32_t gpdSecurityFrameCounter,
                                                    uint8_t gpdCommandId,
                                                    uint32_t mic,
                                                    uint8_t proxyTableIndex,
                                                    uint8_t gpdCommandPayloadLength,
                                                    uint8_t *gpdCommandPayload,
                                                    sl_zigbee_rx_packet_info_t *packetInfo);

#endif //INTERNAL_CALLBACKS_PATCH_H
