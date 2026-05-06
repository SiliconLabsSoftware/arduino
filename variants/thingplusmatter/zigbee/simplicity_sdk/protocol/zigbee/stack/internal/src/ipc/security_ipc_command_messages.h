/***************************************************************************//**
 * @file security_ipc_command_messages.h
 * @brief defines structured format for 'security' ipc messages
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
#ifndef SECURITY_IPC_COMMAND_MESSAGES_H
#define SECURITY_IPC_COMMAND_MESSAGES_H

#include "stack/include/security.h"
#include "stack/internal/inc/security_internal_def.h"

typedef struct {
  bool encrypt;
  uint8_t length;
  uint8_t message[MAX_IPC_VEC_ARG_CAPACITY];
  uint8_t apsHeaderEndIndex;
  sl_802154_long_addr_t remoteEui64;
} sli_zigbee_stack_aps_crypt_message_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_aps_crypt_message_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_aps_crypt_message_ipc_req_t request;
  sli_zigbee_stack_aps_crypt_message_ipc_rsp_t response;
} sli_zigbee_stack_aps_crypt_message_ipc_msg_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_clear_key_table_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_clear_key_table_ipc_rsp_t response;
} sli_zigbee_stack_clear_key_table_ipc_msg_t;

typedef struct {
  uint8_t index;
} sli_zigbee_stack_erase_key_table_entry_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_erase_key_table_entry_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_erase_key_table_entry_ipc_req_t request;
  sli_zigbee_stack_erase_key_table_entry_ipc_rsp_t response;
} sli_zigbee_stack_erase_key_table_entry_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t address;
  bool linkKey;
} sli_zigbee_stack_find_key_table_entry_ipc_req_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_find_key_table_entry_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_find_key_table_entry_ipc_req_t request;
  sli_zigbee_stack_find_key_table_entry_ipc_rsp_t response;
} sli_zigbee_stack_find_key_table_entry_ipc_msg_t;

typedef struct {
  sl_zigbee_key_data_t keyAddress;
} sli_zigbee_stack_generate_random_key_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_generate_random_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_generate_random_key_ipc_req_t request;
  sli_zigbee_stack_generate_random_key_ipc_rsp_t response;
} sli_zigbee_stack_generate_random_key_ipc_msg_t;

typedef struct {
  uint32_t result;
} sli_zigbee_stack_get_aps_frame_counter_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_aps_frame_counter_ipc_rsp_t response;
} sli_zigbee_stack_get_aps_frame_counter_ipc_msg_t;

typedef struct {
  sl_zigbee_current_security_state_t state;
} sli_zigbee_stack_get_current_security_state_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_current_security_state_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_current_security_state_ipc_req_t request;
  sli_zigbee_stack_get_current_security_state_ipc_rsp_t response;
} sli_zigbee_stack_get_current_security_state_ipc_msg_t;

typedef struct {
  sl_zigbee_extended_security_bitmask_t mask;
} sli_zigbee_stack_get_extended_security_bitmask_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_extended_security_bitmask_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_extended_security_bitmask_ipc_req_t request;
  sli_zigbee_stack_get_extended_security_bitmask_ipc_rsp_t response;
} sli_zigbee_stack_get_extended_security_bitmask_ipc_msg_t;

typedef struct {
  uint32_t result;
} sli_zigbee_stack_get_incoming_tc_link_key_frame_counter_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_incoming_tc_link_key_frame_counter_ipc_rsp_t response;
} sli_zigbee_stack_get_incoming_tc_link_key_frame_counter_ipc_msg_t;

typedef struct {
  sl_zigbee_mfg_security_struct_t settings;
} sli_zigbee_stack_get_mfg_security_config_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_mfg_security_config_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_mfg_security_config_ipc_req_t request;
  sli_zigbee_stack_get_mfg_security_config_ipc_rsp_t response;
} sli_zigbee_stack_get_mfg_security_config_ipc_msg_t;

typedef struct {
  sl_zigbee_aps_rejoin_mode_t result;
} sli_zigbee_stack_get_rejoin_mode_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_rejoin_mode_ipc_rsp_t response;
} sli_zigbee_stack_get_rejoin_mode_ipc_msg_t;

typedef struct {
  uint32_t result;
} sli_zigbee_stack_get_security_frame_counter_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_security_frame_counter_ipc_rsp_t response;
} sli_zigbee_stack_get_security_frame_counter_ipc_msg_t;

typedef struct {
  uint16_t result;
} sli_zigbee_stack_get_transient_key_timeout_s_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_transient_key_timeout_s_ipc_rsp_t response;
} sli_zigbee_stack_get_transient_key_timeout_s_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t partner;
} sli_zigbee_stack_request_link_key_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_request_link_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_request_link_key_ipc_req_t request;
  sli_zigbee_stack_request_link_key_ipc_rsp_t response;
} sli_zigbee_stack_request_link_key_ipc_msg_t;

typedef struct {
  sl_zigbee_extended_security_bitmask_t mask;
} sli_zigbee_stack_set_extended_security_bitmask_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_extended_security_bitmask_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_extended_security_bitmask_ipc_req_t request;
  sli_zigbee_stack_set_extended_security_bitmask_ipc_rsp_t response;
} sli_zigbee_stack_set_extended_security_bitmask_ipc_msg_t;

typedef struct {
  uint32_t frameCounter;
} sli_zigbee_stack_set_incoming_tc_link_key_frame_counter_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_incoming_tc_link_key_frame_counter_ipc_req_t request;
} sli_zigbee_stack_set_incoming_tc_link_key_frame_counter_ipc_msg_t;

typedef struct {
  sl_zigbee_initial_security_state_t state;
} sli_zigbee_stack_set_initial_security_state_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_initial_security_state_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_initial_security_state_ipc_req_t request;
  sli_zigbee_stack_set_initial_security_state_ipc_rsp_t response;
} sli_zigbee_stack_set_initial_security_state_ipc_msg_t;

typedef struct {
  uint32_t magicNumber;
  sl_zigbee_mfg_security_struct_t settings;
} sli_zigbee_stack_set_mfg_security_config_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_mfg_security_config_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_mfg_security_config_ipc_req_t request;
  sli_zigbee_stack_set_mfg_security_config_ipc_rsp_t response;
} sli_zigbee_stack_set_mfg_security_config_ipc_msg_t;

typedef struct {
  uint32_t desiredValue;
} sli_zigbee_stack_set_outgoing_aps_frame_counter_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_outgoing_aps_frame_counter_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_outgoing_aps_frame_counter_ipc_req_t request;
  sli_zigbee_stack_set_outgoing_aps_frame_counter_ipc_rsp_t response;
} sli_zigbee_stack_set_outgoing_aps_frame_counter_ipc_msg_t;

typedef struct {
  uint32_t desiredValue;
} sli_zigbee_stack_set_outgoing_nwk_frame_counter_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_outgoing_nwk_frame_counter_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_outgoing_nwk_frame_counter_ipc_req_t request;
  sli_zigbee_stack_set_outgoing_nwk_frame_counter_ipc_rsp_t response;
} sli_zigbee_stack_set_outgoing_nwk_frame_counter_ipc_msg_t;

typedef struct {
  sl_zigbee_aps_rejoin_mode_t mode;
} sli_zigbee_stack_set_rejoin_mode_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_rejoin_mode_ipc_req_t request;
} sli_zigbee_stack_set_rejoin_mode_ipc_msg_t;

typedef struct {
  uint16_t seconds;
} sli_zigbee_stack_set_transient_key_timeout_s_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_transient_key_timeout_s_ipc_req_t request;
} sli_zigbee_stack_set_transient_key_timeout_s_ipc_msg_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_start_writing_stack_tokens_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_start_writing_stack_tokens_ipc_rsp_t response;
} sli_zigbee_stack_start_writing_stack_tokens_ipc_msg_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_stop_writing_stack_tokens_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_stop_writing_stack_tokens_ipc_rsp_t response;
} sli_zigbee_stack_stop_writing_stack_tokens_ipc_msg_t;

typedef struct {
  uint8_t maxAttempts;
} sli_zigbee_stack_update_tc_link_key_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_update_tc_link_key_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_update_tc_link_key_ipc_req_t request;
  sli_zigbee_stack_update_tc_link_key_ipc_rsp_t response;
} sli_zigbee_stack_update_tc_link_key_ipc_msg_t;

typedef struct {
  bool result;
} sli_zigbee_stack_writing_stack_tokens_enabled_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_writing_stack_tokens_enabled_ipc_rsp_t response;
} sli_zigbee_stack_writing_stack_tokens_enabled_ipc_msg_t;

#endif // SECURITY_IPC_COMMAND_MESSAGES_H
