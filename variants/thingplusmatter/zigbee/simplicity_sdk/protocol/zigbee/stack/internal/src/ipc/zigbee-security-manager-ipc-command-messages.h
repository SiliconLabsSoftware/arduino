/***************************************************************************//**
 * @file zigbee-security-manager-ipc-command-messages.h
 * @brief defines structured format for 'zigbee-security-manager' ipc messages
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
#ifndef ZIGBEE_SECURITY_MANAGER_IPC_COMMAND_MESSAGES_H
#define ZIGBEE_SECURITY_MANAGER_IPC_COMMAND_MESSAGES_H

#include "stack/include/zigbee-security-manager.h"
#include "stack/internal/inc/zigbee-security-manager-internal-def.h"

typedef struct {
  bool encrypt;
  uint8_t input[16];
  uint8_t output[16];
} sli_zigbee_stack_sec_man_aes_128_crypt_block_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_aes_128_crypt_block_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_aes_128_crypt_block_ipc_req_t request;
  sli_zigbee_stack_sec_man_aes_128_crypt_block_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_aes_128_crypt_block_ipc_msg_t;

typedef struct {
  uint8_t nonce[NONCE_LENGTH];
  bool encrypt;
  uint8_t input[MAX_IPC_VEC_ARG_CAPACITY];
  uint8_t encryption_start_index;
  uint8_t length;
  uint8_t mic_length;
  uint8_t output[MAX_IPC_VEC_ARG_CAPACITY];
} sli_zigbee_stack_sec_man_aes_ccm_extended_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_aes_ccm_extended_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_aes_ccm_extended_ipc_req_t request;
  sli_zigbee_stack_sec_man_aes_ccm_extended_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_aes_ccm_extended_ipc_msg_t;

typedef struct {
  sl_zigbee_sec_man_context_t context;
} sli_zigbee_stack_sec_man_check_key_context_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_check_key_context_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_check_key_context_ipc_req_t request;
  sli_zigbee_stack_sec_man_check_key_context_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_check_key_context_ipc_msg_t;

typedef struct {
  sl_zigbee_sec_man_context_t context;
  sl_zigbee_sec_man_key_t test_key;
} sli_zigbee_stack_sec_man_compare_key_to_value_ipc_req_t;

typedef struct {
  bool result;
} sli_zigbee_stack_sec_man_compare_key_to_value_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_compare_key_to_value_ipc_req_t request;
  sli_zigbee_stack_sec_man_compare_key_to_value_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_compare_key_to_value_ipc_msg_t;

typedef struct {
  sl_zigbee_sec_man_context_t context;
} sli_zigbee_stack_sec_man_delete_key_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_delete_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_delete_key_ipc_req_t request;
  sli_zigbee_stack_sec_man_delete_key_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_delete_key_ipc_msg_t;

typedef struct {
  sl_zigbee_sec_man_context_t context;
} sli_zigbee_stack_sec_man_delete_key_table_key_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_delete_key_table_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_delete_key_table_key_ipc_req_t request;
  sli_zigbee_stack_sec_man_delete_key_table_key_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_delete_key_table_key_ipc_msg_t;

typedef struct {
  sl_zigbee_sec_man_context_t context;
} sli_zigbee_stack_sec_man_delete_transient_key_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_delete_transient_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_delete_transient_key_ipc_req_t request;
  sli_zigbee_stack_sec_man_delete_transient_key_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_delete_transient_key_ipc_msg_t;

typedef struct {
  sl_zigbee_sec_man_context_t context;
  sl_zigbee_sec_man_key_t plaintext_key;
} sli_zigbee_stack_sec_man_export_key_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_export_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_export_key_ipc_req_t request;
  sli_zigbee_stack_sec_man_export_key_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_export_key_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t eui;
  sl_zigbee_sec_man_context_t context;
  sl_zigbee_sec_man_key_t plaintext_key;
  sl_zigbee_sec_man_aps_key_metadata_t key_data;
} sli_zigbee_stack_sec_man_export_link_key_by_eui_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_export_link_key_by_eui_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_export_link_key_by_eui_ipc_req_t request;
  sli_zigbee_stack_sec_man_export_link_key_by_eui_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_export_link_key_by_eui_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_zigbee_sec_man_context_t context;
  sl_zigbee_sec_man_key_t plaintext_key;
  sl_zigbee_sec_man_aps_key_metadata_t key_data;
} sli_zigbee_stack_sec_man_export_link_key_by_index_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_export_link_key_by_index_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_export_link_key_by_index_ipc_req_t request;
  sli_zigbee_stack_sec_man_export_link_key_by_index_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_export_link_key_by_index_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t address;
  sl_zigbee_key_data_t key_data;
} sli_zigbee_stack_sec_man_export_symmetric_passphrase_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_export_symmetric_passphrase_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_export_symmetric_passphrase_ipc_req_t request;
  sli_zigbee_stack_sec_man_export_symmetric_passphrase_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_export_symmetric_passphrase_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t eui64;
  sl_zigbee_sec_man_context_t context;
  sl_zigbee_sec_man_key_t plaintext_key;
  sl_zigbee_sec_man_aps_key_metadata_t key_data;
} sli_zigbee_stack_sec_man_export_transient_key_by_eui_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_export_transient_key_by_eui_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_export_transient_key_by_eui_ipc_req_t request;
  sli_zigbee_stack_sec_man_export_transient_key_by_eui_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_export_transient_key_by_eui_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_zigbee_sec_man_context_t context;
  sl_zigbee_sec_man_key_t plaintext_key;
  sl_zigbee_sec_man_aps_key_metadata_t key_data;
} sli_zigbee_stack_sec_man_export_transient_key_by_index_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_export_transient_key_by_index_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_export_transient_key_by_index_ipc_req_t request;
  sli_zigbee_stack_sec_man_export_transient_key_by_index_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_export_transient_key_by_index_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t address;
} sli_zigbee_stack_sec_man_find_symmetric_passphrase_key_table_index_ipc_req_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_sec_man_find_symmetric_passphrase_key_table_index_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_find_symmetric_passphrase_key_table_index_ipc_req_t request;
  sli_zigbee_stack_sec_man_find_symmetric_passphrase_key_table_index_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_find_symmetric_passphrase_key_table_index_ipc_msg_t;

typedef struct {
  sl_zigbee_sec_man_context_t context;
  sl_zigbee_sec_man_aps_key_metadata_t key_data;
} sli_zigbee_stack_sec_man_get_aps_key_info_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_get_aps_key_info_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_get_aps_key_info_ipc_req_t request;
  sli_zigbee_stack_sec_man_get_aps_key_info_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_get_aps_key_info_ipc_msg_t;

typedef struct {
  sl_zigbee_sec_man_network_key_info_t network_key_info;
} sli_zigbee_stack_sec_man_get_network_key_info_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_get_network_key_info_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_get_network_key_info_ipc_req_t request;
  sli_zigbee_stack_sec_man_get_network_key_info_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_get_network_key_info_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t eui;
} sli_zigbee_stack_sec_man_have_link_key_ipc_req_t;

typedef struct {
  bool result;
} sli_zigbee_stack_sec_man_have_link_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_have_link_key_ipc_req_t request;
  sli_zigbee_stack_sec_man_have_link_key_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_have_link_key_ipc_msg_t;

typedef struct {
  uint8_t input[MAX_IPC_VEC_ARG_CAPACITY];
  uint8_t data_length;
  uint8_t output[MAX_IPC_VEC_ARG_CAPACITY];
} sli_zigbee_stack_sec_man_hmac_aes_mmo_ipc_req_t;

typedef struct {
  sli_zigbee_stack_sec_man_hmac_aes_mmo_ipc_req_t request;
} sli_zigbee_stack_sec_man_hmac_aes_mmo_ipc_msg_t;

typedef struct {
  sl_zigbee_sec_man_context_t context;
  sl_zigbee_sec_man_key_t plaintext_key;
} sli_zigbee_stack_sec_man_import_key_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_import_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_import_key_ipc_req_t request;
  sli_zigbee_stack_sec_man_import_key_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_import_key_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_802154_long_addr_t address;
  sl_zigbee_sec_man_key_t plaintext_key;
} sli_zigbee_stack_sec_man_import_link_key_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_import_link_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_import_link_key_ipc_req_t request;
  sli_zigbee_stack_sec_man_import_link_key_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_import_link_key_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_802154_long_addr_t address;
  sl_zigbee_key_data_t key_data;
} sli_zigbee_stack_sec_man_import_symmetric_passphrase_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_import_symmetric_passphrase_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_import_symmetric_passphrase_ipc_req_t request;
  sli_zigbee_stack_sec_man_import_symmetric_passphrase_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_import_symmetric_passphrase_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t eui64;
  sl_zigbee_sec_man_key_t plaintext_key;
} sli_zigbee_stack_sec_man_import_transient_key_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_import_transient_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_import_transient_key_ipc_req_t request;
  sli_zigbee_stack_sec_man_import_transient_key_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_import_transient_key_ipc_msg_t;

typedef struct {
  sl_zigbee_sec_man_context_t context;
} sli_zigbee_stack_sec_man_init_context_ipc_req_t;

typedef struct {
  sli_zigbee_stack_sec_man_init_context_ipc_req_t request;
} sli_zigbee_stack_sec_man_init_context_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t eui64;
} sli_zigbee_stack_sec_man_link_key_slot_available_ipc_req_t;

typedef struct {
  bool result;
} sli_zigbee_stack_sec_man_link_key_slot_available_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_link_key_slot_available_ipc_req_t request;
  sli_zigbee_stack_sec_man_link_key_slot_available_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_link_key_slot_available_ipc_msg_t;

typedef struct {
  sl_zigbee_sec_man_context_t context;
} sli_zigbee_stack_sec_man_load_key_context_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_load_key_context_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_load_key_context_ipc_req_t request;
  sli_zigbee_stack_sec_man_load_key_context_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_load_key_context_ipc_msg_t;

typedef struct {
  sl_zigbee_sec_man_context_t context;
} sli_zigbee_stack_sec_man_set_context_aes_ecb_alg_ipc_req_t;

typedef struct {
  sli_zigbee_stack_sec_man_set_context_aes_ecb_alg_ipc_req_t request;
} sli_zigbee_stack_sec_man_set_context_aes_ecb_alg_ipc_msg_t;

typedef struct {
  sl_zigbee_sec_man_context_t context;
} sli_zigbee_stack_sec_man_set_context_extended_ccm_alg_ipc_req_t;

typedef struct {
  sli_zigbee_stack_sec_man_set_context_extended_ccm_alg_ipc_req_t request;
} sli_zigbee_stack_sec_man_set_context_extended_ccm_alg_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t old_eui64;
  sl_802154_long_addr_t new_eui64;
} sli_zigbee_stack_sec_man_update_symmetric_passphrase_eui_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sec_man_update_symmetric_passphrase_eui_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sec_man_update_symmetric_passphrase_eui_ipc_req_t request;
  sli_zigbee_stack_sec_man_update_symmetric_passphrase_eui_ipc_rsp_t response;
} sli_zigbee_stack_sec_man_update_symmetric_passphrase_eui_ipc_msg_t;

#endif // ZIGBEE_SECURITY_MANAGER_IPC_COMMAND_MESSAGES_H
