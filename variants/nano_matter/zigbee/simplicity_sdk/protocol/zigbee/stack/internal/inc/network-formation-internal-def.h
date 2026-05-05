/***************************************************************************//**
 * @file network-formation-internal-def.h
 * @brief internal names for 'network-formation' declarations
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
// automatically generated from network-formation.h.  Do not manually edit
#ifndef NETWORK_FORMATION_INTERNAL_DEF_H
#define NETWORK_FORMATION_INTERNAL_DEF_H

#include "stack/include/network-formation.h"

// Command Indirection

sl_status_t sli_zigbee_stack_clear_stored_beacons(void);

void sli_zigbee_stack_delayed_join_activate(bool activated);

bool sli_zigbee_stack_delayed_join_is_activated(void);

sl_status_t sli_zigbee_stack_find_and_rejoin_network(bool haveCurrentNetworkKey,
                                                     uint32_t channelMask,
                                                     sl_zigbee_rejoin_reason_t reason,
                                                     sl_zigbee_node_type_t nodeType);

sl_status_t sli_zigbee_stack_find_unused_pan_id(uint32_t channelMask,
                                                uint8_t duration);

sl_status_t sli_zigbee_stack_form_network(sl_zigbee_network_parameters_t *parameters);

sl_status_t sli_zigbee_stack_get_beacon_classification_params(sl_zigbee_beacon_classification_params_t *param);

sl_zigbee_leave_reason_t sli_zigbee_stack_get_last_leave_reason(sl_802154_short_addr_t *returnNodeIdThatSentLeave);

sl_zigbee_rejoin_reason_t sli_zigbee_stack_get_last_rejoin_reason(void);

uint8_t sli_zigbee_stack_get_network_key_timeout(void);

uint8_t sli_zigbee_stack_get_num_stored_beacons(void);

bool sli_zigbee_stack_get_permit_joining(void);

sl_status_t sli_zigbee_stack_get_stored_beacon(uint8_t beacon_number,
                                               sl_zigbee_beacon_data_t *beacon);

sl_status_t sli_zigbee_stack_init(void);

bool sli_zigbee_stack_is_performing_rejoin(void);

sl_status_t sli_zigbee_stack_join_network(sl_zigbee_node_type_t nodeType,
                                          sl_zigbee_network_parameters_t *parameters);

sl_status_t sli_zigbee_stack_join_network_directly(sl_zigbee_node_type_t localNodeType,
                                                   sl_zigbee_beacon_data_t *beacon,
                                                   int8_t radioTxPower,
                                                   bool clearBeaconsAfterNetworkUp);

sl_status_t sli_zigbee_stack_leave_network(sl_zigbee_leave_network_option_t options);

sl_status_t sli_zigbee_stack_network_init(sl_zigbee_network_init_struct_t *networkInitStruct);

sl_status_t sli_zigbee_stack_permit_joining(uint8_t duration);

sl_status_t sli_zigbee_stack_reschedule_link_status_msg(void);

bool sli_zigbee_stack_send_pan_id_update(sl_802154_pan_id_t newPan);

sl_status_t sli_zigbee_stack_send_zigbee_leave(sl_802154_short_addr_t destination,
                                               sl_zigbee_leave_request_flags_t flags);

sl_status_t sli_zigbee_stack_set_beacon_classification_params(sl_zigbee_beacon_classification_params_t *param);

sl_status_t sli_zigbee_stack_set_beacon_jitter_duration(uint8_t beaconJitterDuration);

sl_status_t sli_zigbee_stack_set_num_beacons_to_store(uint8_t numBeacons);

sl_status_t sli_zigbee_stack_set_nwk_update_id(uint8_t nwkUpdateId,
                                               bool set_when_on_network);

void sli_zigbee_stack_set_pending_network_update_pan_id(uint16_t panId);

sl_status_t sli_zigbee_stack_set_tc_rejoins_using_well_known_key_allowed(bool allow);

sl_status_t sli_zigbee_stack_set_tc_rejoins_using_well_known_key_timeout_sec(uint16_t timeout_sec);

sl_status_t sli_zigbee_stack_setup_delayed_join(uint8_t networkKeyTimeoutS);

sl_status_t sli_zigbee_stack_sleepy_to_sleepy_network_start(sl_zigbee_network_parameters_t *parameters,
                                                            bool initiator);

sl_status_t sli_zigbee_stack_start_scan(sl_zigbee_network_scan_type_t scanType,
                                        uint32_t channelMask,
                                        uint8_t duration);

sl_status_t sli_zigbee_stack_stop_scan(void);

sl_status_t sli_zigbee_stack_survey_beacons(bool useStandardBeacons,
                                            uint32_t channel_mask,
                                            sl_zigbee_network_found_callback_t networkFoundCallback,
                                            sl_zigbee_scan_complete_callback_t scanCompleteCallback);

bool sli_zigbee_stack_tc_rejoins_using_well_known_key_allowed(void);

// Callback Indirection

void sli_zigbee_stack_energy_scan_result_handler(uint8_t channel,
                                                 int8_t maxRssiValue);

void sli_zigbee_stack_network_found_handler(sl_zigbee_zigbee_network_t *networkFound,
                                            uint8_t lqi,
                                            int8_t rssi);

void sli_zigbee_stack_orphan_notification_handler(sl_802154_long_addr_t longId);

void sli_zigbee_stack_scan_complete_handler(uint8_t channel,
                                            sl_status_t status);

void sli_zigbee_stack_unused_pan_id_found_handler(sl_802154_pan_id_t panId,
                                                  uint8_t channel);

#endif // NETWORK_FORMATION_INTERNAL_DEF_H
