/***************************************************************************//**
 * @file zigbee-security-manager-internal-def.h
 * @brief internal names for 'zigbee-security-manager' declarations
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
// automatically generated from zigbee-security-manager.h.  Do not manually edit
#ifndef ZIGBEE_SECURITY_MANAGER_INTERNAL_DEF_H
#define ZIGBEE_SECURITY_MANAGER_INTERNAL_DEF_H

#include "stack/include/zigbee-security-manager.h"

// Command Indirection

sl_status_t sli_zigbee_stack_sec_man_aes_128_crypt_block(bool encrypt,
                                                         const uint8_t *input,
                                                         uint8_t *output);

sl_status_t sli_zigbee_stack_sec_man_aes_ccm_extended(uint8_t *nonce,
                                                      bool encrypt,
                                                      const uint8_t *input,
                                                      uint8_t encryption_start_index,
                                                      uint8_t length,
                                                      uint8_t mic_length,
                                                      uint8_t *output);

sl_status_t sli_zigbee_stack_sec_man_check_key_context(sl_zigbee_sec_man_context_t *context);

bool sli_zigbee_stack_sec_man_compare_key_to_value(sl_zigbee_sec_man_context_t *context,
                                                   const sl_zigbee_sec_man_key_t *test_key);

sl_status_t sli_zigbee_stack_sec_man_delete_key(sl_zigbee_sec_man_context_t *context);

sl_status_t sli_zigbee_stack_sec_man_delete_key_table_key(sl_zigbee_sec_man_context_t *context);

sl_status_t sli_zigbee_stack_sec_man_delete_transient_key(sl_zigbee_sec_man_context_t *context);

sl_status_t sli_zigbee_stack_sec_man_export_key(sl_zigbee_sec_man_context_t *context,
                                                sl_zigbee_sec_man_key_t *plaintext_key);

sl_status_t sli_zigbee_stack_sec_man_export_link_key_by_eui(sl_802154_long_addr_t eui,
                                                            sl_zigbee_sec_man_context_t *context,
                                                            sl_zigbee_sec_man_key_t *plaintext_key,
                                                            sl_zigbee_sec_man_aps_key_metadata_t *key_data);

sl_status_t sli_zigbee_stack_sec_man_export_link_key_by_index(uint8_t index,
                                                              sl_zigbee_sec_man_context_t *context,
                                                              sl_zigbee_sec_man_key_t *plaintext_key,
                                                              sl_zigbee_sec_man_aps_key_metadata_t *key_data);

sl_status_t sli_zigbee_stack_sec_man_export_symmetric_passphrase(sl_802154_long_addr_t address,
                                                                 sl_zigbee_key_data_t *key_data);

sl_status_t sli_zigbee_stack_sec_man_export_transient_key_by_eui(sl_802154_long_addr_t eui64,
                                                                 sl_zigbee_sec_man_context_t *context,
                                                                 sl_zigbee_sec_man_key_t *plaintext_key,
                                                                 sl_zigbee_sec_man_aps_key_metadata_t *key_data);

sl_status_t sli_zigbee_stack_sec_man_export_transient_key_by_index(uint8_t index,
                                                                   sl_zigbee_sec_man_context_t *context,
                                                                   sl_zigbee_sec_man_key_t *plaintext_key,
                                                                   sl_zigbee_sec_man_aps_key_metadata_t *key_data);

uint8_t sli_zigbee_stack_sec_man_find_symmetric_passphrase_key_table_index(sl_802154_long_addr_t address);

sl_status_t sli_zigbee_stack_sec_man_get_aps_key_info(sl_zigbee_sec_man_context_t *context,
                                                      sl_zigbee_sec_man_aps_key_metadata_t *key_data);

sl_status_t sli_zigbee_stack_sec_man_get_network_key_info(sl_zigbee_sec_man_network_key_info_t *network_key_info);

bool sli_zigbee_stack_sec_man_have_link_key(sl_802154_long_addr_t eui);

void sli_zigbee_stack_sec_man_hmac_aes_mmo(const uint8_t *input,
                                           const uint8_t data_length,
                                           uint8_t *output);

sl_status_t sli_zigbee_stack_sec_man_import_key(sl_zigbee_sec_man_context_t *context,
                                                const sl_zigbee_sec_man_key_t *plaintext_key);

sl_status_t sli_zigbee_stack_sec_man_import_link_key(uint8_t index,
                                                     sl_802154_long_addr_t address,
                                                     sl_zigbee_sec_man_key_t *plaintext_key);

sl_status_t sli_zigbee_stack_sec_man_import_symmetric_passphrase(uint8_t index,
                                                                 sl_802154_long_addr_t address,
                                                                 const sl_zigbee_key_data_t *key_data);

sl_status_t sli_zigbee_stack_sec_man_import_transient_key(sl_802154_long_addr_t eui64,
                                                          sl_zigbee_sec_man_key_t *plaintext_key);

void sli_zigbee_stack_sec_man_init_context(sl_zigbee_sec_man_context_t *context);

bool sli_zigbee_stack_sec_man_link_key_slot_available(sl_802154_long_addr_t eui64);

sl_status_t sli_zigbee_stack_sec_man_load_key_context(sl_zigbee_sec_man_context_t *context);

void sli_zigbee_stack_sec_man_set_context_aes_ecb_alg(sl_zigbee_sec_man_context_t *context);

void sli_zigbee_stack_sec_man_set_context_extended_ccm_alg(sl_zigbee_sec_man_context_t *context);

sl_status_t sli_zigbee_stack_sec_man_update_symmetric_passphrase_eui(sl_802154_long_addr_t old_eui64,
                                                                     sl_802154_long_addr_t new_eui64);

#endif // ZIGBEE_SECURITY_MANAGER_INTERNAL_DEF_H
