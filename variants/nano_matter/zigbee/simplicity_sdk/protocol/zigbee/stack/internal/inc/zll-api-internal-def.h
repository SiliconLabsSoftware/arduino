/***************************************************************************//**
 * @file zll-api-internal-def.h
 * @brief internal names for 'zll-api' declarations
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
#ifndef ZLL_API_INTERNAL_DEF_H
#define ZLL_API_INTERNAL_DEF_H

#include "stack/include/zll-api.h"

// Command Indirection

uint32_t sli_zigbee_stack_get_zll_primary_channel_mask(void);

uint32_t sli_zigbee_stack_get_zll_secondary_channel_mask(void);

bool sli_zigbee_stack_is_zll_network(void);

void sli_zigbee_stack_set_zll_additional_state(uint16_t mask);

void sli_zigbee_stack_set_zll_node_type(sl_zigbee_node_type_t nodeType);

void sli_zigbee_stack_set_zll_primary_channel_mask(uint32_t mask);

void sli_zigbee_stack_set_zll_secondary_channel_mask(uint32_t mask);

void sli_zigbee_stack_zll_clear_tokens(void);

sl_status_t sli_zigbee_stack_zll_form_network(sl_zigbee_zll_network_t *networkInfo,
                                              int8_t radioTxPower);

sl_zigbee_zll_policy_t sli_zigbee_stack_zll_get_policy(void);

uint8_t sli_zigbee_stack_zll_get_radio_idle_mode(void);

void sli_zigbee_stack_zll_get_token_stack_zll_data(sl_zigbee_tok_type_stack_zll_data_t *token);

void sli_zigbee_stack_zll_get_token_stack_zll_security(sl_zigbee_tok_type_stack_zll_security_t *token);

void sli_zigbee_stack_zll_get_tokens_stack_zll(sl_zigbee_tok_type_stack_zll_data_t *data,
                                               sl_zigbee_tok_type_stack_zll_security_t *security);

sl_status_t sli_zigbee_stack_zll_join_target(const sl_zigbee_zll_network_t *targetNetworkInfo);

bool sli_zigbee_stack_zll_operation_in_progress(void);

bool sli_zigbee_stack_zll_rx_on_when_idle_get_active(void);

void sli_zigbee_stack_zll_scanning_complete(void);

sl_status_t sli_zigbee_stack_zll_set_initial_security_state(const sl_zigbee_key_data_t *networkKey,
                                                            const sl_zigbee_zll_initial_security_state_t *securityState);

void sli_zigbee_stack_zll_set_non_zll_network(void);

sl_status_t sli_zigbee_stack_zll_set_policy(sl_zigbee_zll_policy_t policy);

void sli_zigbee_stack_zll_set_radio_idle_mode(sl_zigbee_radio_power_mode_t mode);

sl_status_t sli_zigbee_stack_zll_set_rx_on_when_idle(uint32_t durationMs);

sl_status_t sli_zigbee_stack_zll_set_security_state_without_key(const sl_zigbee_zll_initial_security_state_t *securityState);

void sli_zigbee_stack_zll_set_token_stack_zll_data(sl_zigbee_tok_type_stack_zll_data_t *token);

sl_status_t sli_zigbee_stack_zll_start_scan(uint32_t channelMask,
                                            int8_t radioPowerForScan,
                                            sl_zigbee_node_type_t nodeType);

// Callback Indirection

void sli_zigbee_stack_zll_address_assignment_handler(sl_zigbee_zll_address_assignment_t *addressInfo,
                                                     sl_zigbee_rx_packet_info_t *packetInfo);

void sli_zigbee_stack_zll_network_found_handler(sl_zigbee_zll_network_t *networkInfo,
                                                bool isDeviceInfoNull,
                                                sl_zigbee_zll_device_info_record_t *deviceInfo,
                                                sl_zigbee_rx_packet_info_t *packetInfo);

void sli_zigbee_stack_zll_scan_complete_handler(sl_status_t status);

void sli_zigbee_stack_zll_touch_link_target_handler(const sl_zigbee_zll_network_t *networkInfo);

#endif // ZLL_API_INTERNAL_DEF_H
