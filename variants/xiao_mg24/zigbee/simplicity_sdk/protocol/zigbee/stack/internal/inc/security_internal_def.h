/***************************************************************************//**
 * @file security_internal_def.h
 * @brief internal names for 'security' declarations
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
// automatically generated from security.h.  Do not manually edit
#ifndef SECURITY_INTERNAL_DEF_H
#define SECURITY_INTERNAL_DEF_H

#include "stack/include/security.h"

// Command Indirection

sl_status_t sli_zigbee_stack_aps_crypt_message(bool encrypt,
                                               uint8_t length,
                                               const uint8_t *message,
                                               uint8_t apsHeaderEndIndex,
                                               sl_802154_long_addr_t remoteEui64);

sl_status_t sli_zigbee_stack_clear_key_table(void);

void sli_zigbee_stack_clear_transient_link_keys(void);

sl_status_t sli_zigbee_stack_erase_key_table_entry(uint8_t index);

uint8_t sli_zigbee_stack_find_key_table_entry(sl_802154_long_addr_t address,
                                              bool linkKey);

sl_status_t sli_zigbee_stack_generate_random_key(sl_zigbee_key_data_t *keyAddress);

uint32_t sli_zigbee_stack_get_aps_frame_counter(void);

sl_status_t sli_zigbee_stack_get_current_security_state(sl_zigbee_current_security_state_t *state);

sl_status_t sli_zigbee_stack_get_extended_security_bitmask(sl_zigbee_extended_security_bitmask_t *mask);

uint32_t sli_zigbee_stack_get_incoming_tc_link_key_frame_counter(void);

sl_status_t sli_zigbee_stack_get_mfg_security_config(sl_zigbee_mfg_security_struct_t *settings);

sl_zigbee_aps_rejoin_mode_t sli_zigbee_stack_get_rejoin_mode(void);

uint32_t sli_zigbee_stack_get_security_frame_counter(void);

uint16_t sli_zigbee_stack_get_transient_key_timeout_s(void);

sl_status_t sli_zigbee_stack_request_link_key(sl_802154_long_addr_t partner);

sl_status_t sli_zigbee_stack_set_extended_security_bitmask(sl_zigbee_extended_security_bitmask_t mask);

void sli_zigbee_stack_set_incoming_tc_link_key_frame_counter(uint32_t frameCounter);

sl_status_t sli_zigbee_stack_set_initial_security_state(sl_zigbee_initial_security_state_t *state);

sl_status_t sli_zigbee_stack_set_mfg_security_config(uint32_t magicNumber,
                                                     const sl_zigbee_mfg_security_struct_t *settings);

sl_status_t sli_zigbee_stack_set_outgoing_aps_frame_counter(uint32_t desiredValue);

sl_status_t sli_zigbee_stack_set_outgoing_nwk_frame_counter(uint32_t desiredValue);

void sli_zigbee_stack_set_rejoin_mode(sl_zigbee_aps_rejoin_mode_t mode);

void sli_zigbee_stack_set_transient_key_timeout_s(uint16_t seconds);

sl_status_t sli_zigbee_stack_start_writing_stack_tokens(void);

sl_status_t sli_zigbee_stack_stop_writing_stack_tokens(void);

sl_status_t sli_zigbee_stack_update_tc_link_key(uint8_t maxAttempts);

bool sli_zigbee_stack_writing_stack_tokens_enabled(void);

// Callback Indirection

void sli_zigbee_stack_switch_network_key_handler(uint8_t sequenceNumber);

void sli_zigbee_stack_zigbee_key_establishment_handler(sl_802154_long_addr_t partner,
                                                       sl_zigbee_key_status_t status);

#endif // SECURITY_INTERNAL_DEF_H
