/***************************************************************************//**
 * @file zigbee_ipc_command_messages.h
 * @brief struct definitions for zigbee ipc command messages
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
// automatically generated from stack headers.  Do not manually edit
#ifndef ZIGBEE_IPC_COMMAND_MESSAGES_H
#define ZIGBEE_IPC_COMMAND_MESSAGES_H

#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif

#include "stack/internal/src/ipc/aes-mmo-ipc-command-messages.h"
#include "stack/internal/src/ipc/binding-table-ipc-command-messages.h"
#include "stack/internal/src/ipc/bootload_ipc_command_messages.h"
#ifdef SL_CATALOG_ZIGBEE_CBKE_CORE_PRESENT
#include "stack/internal/src/ipc/cbke-crypto-engine-ipc-command-messages.h"
#endif
#include "stack/internal/src/ipc/child_ipc_command_messages.h"
#ifdef SL_CATALOG_ZIGBEE_FORCE_SLEEP_WAKEUP_PRESENT
#include "stack/internal/src/ipc/force_sleep_wakeup_stack_interface_ipc_command_messages.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_GREEN_POWER_PRESENT
#include "stack/internal/src/ipc/gp-proxy-table-ipc-command-messages.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_GREEN_POWER_PRESENT
#include "stack/internal/src/ipc/gp-sink-table-ipc-command-messages.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_GREEN_POWER_PRESENT
#include "stack/internal/src/ipc/gp-types-ipc-command-messages.h"
#endif
#ifdef SL_CATALOG_HIGH_DATARATE_PHY_PRESENT
#include "stack/internal/src/ipc/high_datarate_phy_stack_interface_ipc_command_messages.h"
#endif
#include "stack/internal/src/ipc/library_ipc_command_messages.h"
#include "stack/internal/src/ipc/mac-layer-ipc-command-messages.h"
#include "stack/internal/src/ipc/message_ipc_command_messages.h"
#include "stack/internal/src/ipc/mfglib_ipc_command_messages.h"
#include "stack/internal/src/ipc/multi-network-ipc-command-messages.h"
#include "stack/internal/src/ipc/multi-phy-ipc-command-messages.h"
#include "stack/internal/src/ipc/network-formation-ipc-command-messages.h"
#ifdef SL_CATALOG_ZIGBEE_PRO_COMPLIANCE_PRESENT
#include "stack/internal/src/ipc/pro_compliance_stack_interface_ipc_command_messages.h"
#endif
#include "stack/internal/src/ipc/raw-message-ipc-command-messages.h"
#include "stack/internal/src/ipc/security_ipc_command_messages.h"
#include "stack/internal/src/ipc/sl_zigbee_address_info_ipc_command_messages.h"
#ifdef SL_CATALOG_ZIGBEE_PRO_STACK_ALT_MAC_PRESENT
#include "stack/internal/src/ipc/sl_zigbee_alternate_mac_ipc_command_messages.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
#include "stack/internal/src/ipc/sl_zigbee_dlk_negotiation_ipc_command_messages.h"
#endif
#include "stack/internal/src/ipc/sl_zigbee_duty_cycle_ipc_command_messages.h"
#ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
#include "stack/internal/src/ipc/sl_zigbee_dynamic_commissioning_ipc_command_messages.h"
#endif
#include "stack/internal/src/ipc/sl_zigbee_random_api_ipc_command_messages.h"
#ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
#include "stack/internal/src/ipc/sl_zigbee_security_manager_dlk_ecc_ipc_command_messages.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
#include "stack/internal/src/ipc/sl_zigbee_security_manager_dlk_ecc_test_vectors_ipc_command_messages.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
#include "stack/internal/src/ipc/sl_zigbee_stack_specific_tlv_ipc_command_messages.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
#include "stack/internal/src/ipc/sl_zigbee_zdo_configuration_ipc_command_messages.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
#include "stack/internal/src/ipc/sl_zigbee_zdo_dlk_negotiation_ipc_command_messages.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
#include "stack/internal/src/ipc/sl_zigbee_zdo_management_ipc_command_messages.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
#include "stack/internal/src/ipc/sl_zigbee_zdo_security_ipc_command_messages.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_SOURCE_ROUTE_PRESENT
#include "stack/internal/src/ipc/source-route-ipc-command-messages.h"
#endif
#include "stack/internal/src/ipc/stack-info-ipc-command-messages.h"
#include "stack/internal/src/ipc/trust-center-ipc-command-messages.h"
#include "stack/internal/src/ipc/zigbee-device-stack-ipc-command-messages.h"
#include "stack/internal/src/ipc/zigbee-security-manager-ipc-command-messages.h"
#ifdef SL_CATALOG_ZIGBEE_DIRECT_ZDD_PRESENT
#include "stack/internal/src/ipc/zigbee_direct_stack_interface_ipc_command_messages.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_LIGHT_LINK_PRESENT
#include "stack/internal/src/ipc/zll-api-ipc-command-messages.h"
#endif

typedef struct {
  union {
    sli_zigbee_stack_aes_hash_simple_ipc_msg_t aes_hash_simple;
    sli_zigbee_stack_aes_mmo_hash_final_ipc_msg_t aes_mmo_hash_final;
    sli_zigbee_stack_aes_mmo_hash_init_ipc_msg_t aes_mmo_hash_init;
    sli_zigbee_stack_aes_mmo_hash_update_ipc_msg_t aes_mmo_hash_update;
    sli_zigbee_stack_binding_is_active_ipc_msg_t binding_is_active;
    sli_zigbee_stack_clear_binding_table_ipc_msg_t clear_binding_table;
    sli_zigbee_stack_delete_binding_ipc_msg_t delete_binding;
    sli_zigbee_stack_get_binding_ipc_msg_t get_binding;
    sli_zigbee_stack_get_binding_remote_node_id_ipc_msg_t get_binding_remote_node_id;
    sli_zigbee_stack_get_binding_table_size_ipc_msg_t get_binding_table_size;
    sli_zigbee_stack_note_senders_binding_ipc_msg_t note_senders_binding;
    sli_zigbee_stack_set_binding_ipc_msg_t set_binding;
    sli_zigbee_stack_set_binding_remote_node_id_ipc_msg_t set_binding_remote_node_id;
    sli_zigbee_stack_set_binding_table_size_ipc_msg_t set_binding_table_size;
    sli_zigbee_stack_set_reply_binding_ipc_msg_t set_reply_binding;
    sli_zigbee_stack_send_bootload_message_ipc_msg_t send_bootload_message;
    #ifdef SL_CATALOG_ZIGBEE_CBKE_CORE_PRESENT
    sli_zigbee_stack_calculate_smacs_ipc_msg_t calculate_smacs;
    sli_zigbee_stack_calculate_smacs_283k1_ipc_msg_t calculate_smacs_283k1;
    sli_zigbee_stack_clear_temporary_data_maybe_store_link_key_ipc_msg_t clear_temporary_data_maybe_store_link_key;
    sli_zigbee_stack_clear_temporary_data_maybe_store_link_key_283k1_ipc_msg_t clear_temporary_data_maybe_store_link_key_283k1;
    sli_zigbee_stack_dsa_sign_ipc_msg_t dsa_sign;
    sli_zigbee_stack_dsa_verify_ipc_msg_t dsa_verify;
    sli_zigbee_stack_dsa_verify_283k1_ipc_msg_t dsa_verify_283k1;
    sli_zigbee_stack_generate_cbke_keys_ipc_msg_t generate_cbke_keys;
    sli_zigbee_stack_generate_cbke_keys_283k1_ipc_msg_t generate_cbke_keys_283k1;
    sli_zigbee_stack_get_certificate_ipc_msg_t get_certificate;
    sli_zigbee_stack_get_certificate_283k1_ipc_msg_t get_certificate_283k1;
    sli_zigbee_stack_get_stack_certificate_eui64_ipc_msg_t get_stack_certificate_eui64;
    sli_zigbee_stack_set_preinstalled_cbke_data_ipc_msg_t set_preinstalled_cbke_data;
    sli_zigbee_stack_set_preinstalled_cbke_data_283k1_ipc_msg_t set_preinstalled_cbke_data_283k1;
    #endif
    sli_zigbee_stack_add_child_ipc_msg_t add_child;
    sli_zigbee_stack_child_count_ipc_msg_t child_count;
    sli_zigbee_stack_child_id_ipc_msg_t child_id;
    sli_zigbee_stack_child_index_ipc_msg_t child_index;
    sli_zigbee_stack_child_power_ipc_msg_t child_power;
    sli_zigbee_stack_clear_message_flag_ipc_msg_t clear_message_flag;
    sli_zigbee_stack_current_stack_tasks_ipc_msg_t current_stack_tasks;
    sli_zigbee_stack_get_avg_parent_rssi_ipc_msg_t get_avg_parent_rssi;
    sli_zigbee_stack_get_child_data_ipc_msg_t get_child_data;
    sli_zigbee_stack_get_keep_alive_mode_ipc_msg_t get_keep_alive_mode;
    sli_zigbee_stack_get_max_end_device_children_ipc_msg_t get_max_end_device_children;
    sli_zigbee_stack_get_parent_eui64_ipc_msg_t get_parent_eui64;
    sli_zigbee_stack_get_parent_id_ipc_msg_t get_parent_id;
    sli_zigbee_stack_get_parent_incoming_nwk_frame_counter_ipc_msg_t get_parent_incoming_nwk_frame_counter;
    sli_zigbee_stack_get_parent_node_id_ipc_msg_t get_parent_node_id;
    sli_zigbee_stack_parent_token_set_ipc_msg_t parent_token_set;
    sli_zigbee_stack_poll_for_data_ipc_msg_t poll_for_data;
    sli_zigbee_stack_remove_child_ipc_msg_t remove_child;
    sli_zigbee_stack_remove_neighbor_ipc_msg_t remove_neighbor;
    sli_zigbee_stack_send_link_power_delta_request_ipc_msg_t send_link_power_delta_request;
    sli_zigbee_stack_set_child_data_ipc_msg_t set_child_data;
    sli_zigbee_stack_set_child_power_ipc_msg_t set_child_power;
    sli_zigbee_stack_set_child_timeout_option_mask_ipc_msg_t set_child_timeout_option_mask;
    sli_zigbee_stack_set_keep_alive_mode_ipc_msg_t set_keep_alive_mode;
    sli_zigbee_stack_set_mac_poll_failure_wait_time_ipc_msg_t set_mac_poll_failure_wait_time;
    sli_zigbee_stack_set_max_end_device_children_ipc_msg_t set_max_end_device_children;
    sli_zigbee_stack_set_message_flag_ipc_msg_t set_message_flag;
    sli_zigbee_stack_set_parent_incoming_nwk_frame_counter_ipc_msg_t set_parent_incoming_nwk_frame_counter;
    #ifdef SL_CATALOG_ZIGBEE_FORCE_SLEEP_WAKEUP_PRESENT
    sli_mac_stack_lower_mac_force_sleep_ipc_msg_t lower_mac_force_sleep;
    #endif
    #ifdef SL_CATALOG_ZIGBEE_GREEN_POWER_PRESENT
    sli_zigbee_stack_gp_proxy_table_get_entry_ipc_msg_t gp_proxy_table_get_entry;
    sli_zigbee_stack_gp_proxy_table_lookup_ipc_msg_t gp_proxy_table_lookup;
    sli_zigbee_stack_gp_proxy_table_process_gp_pairing_ipc_msg_t gp_proxy_table_process_gp_pairing;
    #endif
    #ifdef SL_CATALOG_ZIGBEE_GREEN_POWER_PRESENT
    sli_zigbee_stack_gp_sink_table_add_group_ipc_msg_t gp_sink_table_add_group;
    sli_zigbee_stack_gp_sink_table_entry_in_use_ipc_msg_t gp_sink_table_entry_in_use;
    sli_zigbee_stack_gp_sink_table_find_or_allocate_entry_ipc_msg_t gp_sink_table_find_or_allocate_entry;
    sli_zigbee_stack_gp_sink_table_get_entry_ipc_msg_t gp_sink_table_get_entry;
    sli_zigbee_stack_gp_sink_table_get_free_entry_index_ipc_msg_t gp_sink_table_get_free_entry_index;
    sli_zigbee_stack_gp_sink_table_get_number_of_active_entries_ipc_msg_t gp_sink_table_get_number_of_active_entries;
    sli_zigbee_stack_gp_sink_table_lookup_ipc_msg_t gp_sink_table_lookup;
    sli_zigbee_stack_gp_sink_table_remove_entry_ipc_msg_t gp_sink_table_remove_entry;
    sli_zigbee_stack_gp_sink_table_remove_group_ipc_msg_t gp_sink_table_remove_group;
    sli_zigbee_stack_gp_sink_table_set_entry_ipc_msg_t gp_sink_table_set_entry;
    sli_zigbee_stack_gp_sink_table_set_security_frame_counter_ipc_msg_t gp_sink_table_set_security_frame_counter;
    #endif
    #ifdef SL_CATALOG_ZIGBEE_GREEN_POWER_PRESENT
    sli_zigbee_stack_d_gp_send_ipc_msg_t d_gp_send;
    sli_zigbee_stack_get_gp_max_tx_q_list_count_ipc_msg_t get_gp_max_tx_q_list_count;
    sli_zigbee_stack_get_gp_tx_q_list_count_ipc_msg_t get_gp_tx_q_list_count;
    sli_zigbee_stack_gp_add_gp_tx_queue_entry_with_payload_ipc_msg_t gp_add_gp_tx_queue_entry_with_payload;
    sli_zigbee_stack_gp_get_tx_queue_entry_from_queue_ipc_msg_t gp_get_tx_queue_entry_from_queue;
    sli_zigbee_stack_gp_get_tx_queue_entry_from_queue_index_ipc_msg_t gp_get_tx_queue_entry_from_queue_index;
    sli_zigbee_stack_gp_get_tx_queue_head_ipc_msg_t gp_get_tx_queue_head;
    sli_zigbee_stack_gp_remove_from_tx_queue_ipc_msg_t gp_remove_from_tx_queue;
    sli_zigbee_stack_gp_set_max_tx_queue_entry_ipc_msg_t gp_set_max_tx_queue_entry;
    #endif
    #ifdef SL_CATALOG_HIGH_DATARATE_PHY_PRESENT
    sli_mac_stack_lower_mac_set_high_datarate_csma_params_ipc_msg_t lower_mac_set_high_datarate_csma_params;
    sli_mac_stack_lower_mac_set_high_datarate_phy_radio_priorities_ipc_msg_t lower_mac_set_high_datarate_phy_radio_priorities;
    sli_mac_stack_send_raw_high_datarate_phy_message_ipc_msg_t send_raw_high_datarate_phy_message;
    sli_mac_stack_send_raw_high_datarate_phy_scheduled_message_ipc_msg_t send_raw_high_datarate_phy_scheduled_message;
    sli_mac_stack_set_mode_switch_sync_detect_ipc_msg_t set_mode_switch_sync_detect;
    #endif
    sli_zigbee_stack_get_library_status_ipc_msg_t get_library_status;
    sli_zigbee_stack_force_tx_after_failed_cca_ipc_msg_t force_tx_after_failed_cca;
    sli_zigbee_stack_get_max_mac_retries_ipc_msg_t get_max_mac_retries;
    sli_zigbee_stack_address_table_entry_is_active_ipc_msg_t address_table_entry_is_active;
    sli_zigbee_stack_get_address_table_info_ipc_msg_t get_address_table_info;
    sli_zigbee_stack_get_aps_ack_timeout_ms_ipc_msg_t get_aps_ack_timeout_ms;
    sli_zigbee_stack_get_extended_timeout_ipc_msg_t get_extended_timeout;
    sli_zigbee_stack_get_multicast_table_ipc_msg_t get_multicast_table;
    sli_zigbee_stack_get_multicast_table_size_ipc_msg_t get_multicast_table_size;
    sli_zigbee_stack_maximum_aps_payload_length_ipc_msg_t maximum_aps_payload_length;
    sli_zigbee_stack_pending_acked_messages_ipc_msg_t pending_acked_messages;
    sli_zigbee_stack_proxy_next_broadcast_from_long_ipc_msg_t proxy_next_broadcast_from_long;
    sli_zigbee_stack_send_broadcast_ipc_msg_t send_broadcast;
    sli_zigbee_stack_send_multicast_ipc_msg_t send_multicast;
    sli_zigbee_stack_send_reply_ipc_msg_t send_reply;
    sli_zigbee_stack_send_unicast_ipc_msg_t send_unicast;
    sli_zigbee_stack_set_address_table_info_ipc_msg_t set_address_table_info;
    sli_zigbee_stack_set_aps_ack_timeout_ms_ipc_msg_t set_aps_ack_timeout_ms;
    sli_zigbee_stack_set_extended_timeout_ipc_msg_t set_extended_timeout;
    sli_zigbee_stack_set_multicast_table_ipc_msg_t set_multicast_table;
    sli_zigbee_stack_set_multicast_table_size_ipc_msg_t set_multicast_table_size;
    sli_zigbee_stack_set_passive_ack_config_ipc_msg_t set_passive_ack_config;
    sli_zigbee_stack_set_reply_fragment_data_ipc_msg_t set_reply_fragment_data;
    slxi_zigbee_stack_add_to_incoming_network_queue_ipc_msg_t add_to_incoming_network_queue;
    mfglibInternalEnd_ipc_msg_t mfgEnd;
    mfglibInternalGetChannel_ipc_msg_t mfgGetChannel;
    mfglibInternalGetCtune_ipc_msg_t mfgGetCtune;
    mfglibInternalGetOptions_ipc_msg_t mfgGetOptions;
    mfglibInternalGetPower_ipc_msg_t mfgGetPower;
    mfglibInternalGetSynOffset_ipc_msg_t mfgGetSynOffset;
    mfglibInternalSendPacket_ipc_msg_t mfgSendPacket;
    mfglibInternalSetChannel_ipc_msg_t mfgSetChannel;
    mfglibInternalSetCtune_ipc_msg_t mfgSetCtune;
    mfglibInternalSetOptions_ipc_msg_t mfgSetOptions;
    mfglibInternalSetPower_ipc_msg_t mfgSetPower;
    mfglibInternalSetSynOffset_ipc_msg_t mfgSetSynOffset;
    mfglibInternalStart_ipc_msg_t mfgStart;
    mfglibInternalStartStream_ipc_msg_t mfgStartStream;
    mfglibInternalStartTone_ipc_msg_t mfgStartTone;
    mfglibInternalStopStream_ipc_msg_t mfgStopStream;
    mfglibInternalStopTone_ipc_msg_t mfgStopTone;
    sli_zigbee_stack_get_callback_network_ipc_msg_t get_callback_network;
    sli_zigbee_stack_get_current_network_ipc_msg_t get_current_network;
    sli_zigbee_stack_set_current_network_ipc_msg_t set_current_network;
    sli_zigbee_stack_multi_phy_set_radio_channel_ipc_msg_t multi_phy_set_radio_channel;
    sli_zigbee_stack_multi_phy_set_radio_power_ipc_msg_t multi_phy_set_radio_power;
    sli_zigbee_stack_multi_phy_start_ipc_msg_t multi_phy_start;
    sli_zigbee_stack_multi_phy_stop_ipc_msg_t multi_phy_stop;
    sli_zigbee_stack_clear_stored_beacons_ipc_msg_t clear_stored_beacons;
    sli_zigbee_stack_delayed_join_activate_ipc_msg_t delayed_join_activate;
    sli_zigbee_stack_delayed_join_is_activated_ipc_msg_t delayed_join_is_activated;
    sli_zigbee_stack_find_and_rejoin_network_ipc_msg_t find_and_rejoin_network;
    sli_zigbee_stack_find_unused_pan_id_ipc_msg_t find_unused_pan_id;
    sli_zigbee_stack_form_network_ipc_msg_t form_network;
    sli_zigbee_stack_get_beacon_classification_params_ipc_msg_t get_beacon_classification_params;
    sli_zigbee_stack_get_last_leave_reason_ipc_msg_t get_last_leave_reason;
    sli_zigbee_stack_get_last_rejoin_reason_ipc_msg_t get_last_rejoin_reason;
    sli_zigbee_stack_get_network_key_timeout_ipc_msg_t get_network_key_timeout;
    sli_zigbee_stack_get_num_stored_beacons_ipc_msg_t get_num_stored_beacons;
    sli_zigbee_stack_get_permit_joining_ipc_msg_t get_permit_joining;
    sli_zigbee_stack_get_stored_beacon_ipc_msg_t get_stored_beacon;
    sli_zigbee_stack_init_ipc_msg_t init;
    sli_zigbee_stack_is_performing_rejoin_ipc_msg_t is_performing_rejoin;
    sli_zigbee_stack_join_network_ipc_msg_t join_network;
    sli_zigbee_stack_join_network_directly_ipc_msg_t join_network_directly;
    sli_zigbee_stack_leave_network_ipc_msg_t leave_network;
    sli_zigbee_stack_network_init_ipc_msg_t network_init;
    sli_zigbee_stack_permit_joining_ipc_msg_t permit_joining;
    sli_zigbee_stack_reschedule_link_status_msg_ipc_msg_t reschedule_link_status_msg;
    sli_zigbee_stack_send_pan_id_update_ipc_msg_t send_pan_id_update;
    sli_zigbee_stack_send_zigbee_leave_ipc_msg_t send_zigbee_leave;
    sli_zigbee_stack_set_beacon_classification_params_ipc_msg_t set_beacon_classification_params;
    sli_zigbee_stack_set_beacon_jitter_duration_ipc_msg_t set_beacon_jitter_duration;
    sli_zigbee_stack_set_num_beacons_to_store_ipc_msg_t set_num_beacons_to_store;
    sli_zigbee_stack_set_nwk_update_id_ipc_msg_t set_nwk_update_id;
    sli_zigbee_stack_set_pending_network_update_pan_id_ipc_msg_t set_pending_network_update_pan_id;
    sli_zigbee_stack_set_tc_rejoins_using_well_known_key_allowed_ipc_msg_t set_tc_rejoins_using_well_known_key_allowed;
    sli_zigbee_stack_set_tc_rejoins_using_well_known_key_timeout_sec_ipc_msg_t set_tc_rejoins_using_well_known_key_timeout_sec;
    sli_zigbee_stack_setup_delayed_join_ipc_msg_t setup_delayed_join;
    sli_zigbee_stack_sleepy_to_sleepy_network_start_ipc_msg_t sleepy_to_sleepy_network_start;
    sli_zigbee_stack_start_scan_ipc_msg_t start_scan;
    sli_zigbee_stack_stop_scan_ipc_msg_t stop_scan;
    sli_zigbee_stack_survey_beacons_ipc_msg_t survey_beacons;
    sli_zigbee_stack_tc_rejoins_using_well_known_key_allowed_ipc_msg_t tc_rejoins_using_well_known_key_allowed;
    #ifdef SL_CATALOG_ZIGBEE_PRO_COMPLIANCE_PRESENT
    sli_mac_stack_find_child_short_id_ipc_msg_t find_child_short_id;
    sli_mac_stack_get_child_info_flags_ipc_msg_t get_child_info_flags;
    sli_mac_stack_indirect_purge_ipc_msg_t indirect_purge;
    sli_mac_stack_kickstart_ipc_msg_t kickstart;
    sli_mac_stack_lower_mac_radio_is_on_ipc_msg_t lower_mac_radio_is_on;
    sli_mac_stack_lower_mac_set_radio_channel_ipc_msg_t lower_mac_set_radio_channel;
    sli_mac_stack_lower_mac_set_radio_idle_mode_ipc_msg_t lower_mac_set_radio_idle_mode;
    sli_mac_stack_lower_mac_set_radio_power_ipc_msg_t lower_mac_set_radio_power;
    sli_mac_stack_set_coordinator_ipc_msg_t set_coordinator;
    sli_mac_stack_test_associate_command_ipc_msg_t test_associate_command;
    sli_mac_stack_test_send_mac_command_ipc_msg_t test_send_mac_command;
    sli_mac_stack_test_set_nwk_radio_params_channel_ipc_msg_t test_set_nwk_radio_params_channel;
    sli_mac_stack_test_set_nwk_radio_params_eui_ipc_msg_t test_set_nwk_radio_params_eui;
    sli_mac_stack_test_set_tx_power_ipc_msg_t test_set_tx_power;
    sli_zigbee_stack_set_end_device_poll_timeout_ipc_msg_t set_end_device_poll_timeout;
    sli_zigbee_stack_set_packet_validate_library_state_ipc_msg_t set_packet_validate_library_state;
    sli_zigbee_stack_set_pan_id_ipc_msg_t set_pan_id;
    sli_zigbee_stack_set_pan_id_conflict_report_ipc_msg_t set_pan_id_conflict_report;
    sli_zigbee_stack_test_aps_key_in_sync_ipc_msg_t test_aps_key_in_sync;
    sli_zigbee_stack_test_aps_key_set_sync_status_ipc_msg_t test_aps_key_set_sync_status;
    sli_zigbee_stack_test_custom_send_security_challenge_request_ipc_msg_t test_custom_send_security_challenge_request;
    sli_zigbee_stack_test_ieee_address_request_to_target_ipc_msg_t test_ieee_address_request_to_target;
    sli_zigbee_stack_test_join_list_add_ipc_msg_t test_join_list_add;
    sli_zigbee_stack_test_join_list_request_ipc_msg_t test_join_list_request;
    sli_zigbee_stack_test_network_send_command_ipc_msg_t test_network_send_command;
    sli_zigbee_stack_test_perform_raw_active_scan_ipc_msg_t test_perform_raw_active_scan;
    sli_zigbee_stack_test_reset_frame_counter_ipc_msg_t test_reset_frame_counter;
    sli_zigbee_stack_test_send_device_update_ipc_msg_t test_send_device_update;
    sli_zigbee_stack_test_send_leave_request_command_ipc_msg_t test_send_leave_request_command;
    sli_zigbee_stack_test_send_link_key_ipc_msg_t test_send_link_key;
    sli_zigbee_stack_test_send_network_rejoin_command_ipc_msg_t test_send_network_rejoin_command;
    sli_zigbee_stack_test_send_network_timeout_request_ipc_msg_t test_send_network_timeout_request;
    sli_zigbee_stack_test_send_remove_device_command_ipc_msg_t test_send_remove_device_command;
    sli_zigbee_stack_test_send_report_or_update_ipc_msg_t test_send_report_or_update;
    sli_zigbee_stack_test_send_route_error_payload_ipc_msg_t test_send_route_error_payload;
    sli_zigbee_stack_test_send_route_error_payload_no_network_encryption_ipc_msg_t test_send_route_error_payload_no_network_encryption;
    sli_zigbee_stack_test_set_network_tokens_ipc_msg_t test_set_network_tokens;
    sli_zigbee_stack_test_spoof_device_announcement_ipc_msg_t test_spoof_device_announcement;
    sli_zigbee_stack_test_zdo_generate_clear_all_bindings_req_ipc_msg_t test_zdo_generate_clear_all_bindings_req;
    sli_zigbee_stack_test_zdo_generate_get_authentication_level_req_ipc_msg_t test_zdo_generate_get_authentication_level_req;
    sli_zigbee_stack_test_zdo_generate_security_decommission_req_ipc_msg_t test_zdo_generate_security_decommission_req;
    sli_zigbee_stack_zigbee_remove_child_ipc_msg_t zigbee_remove_child;
    #endif
    sli_zigbee_stack_get_embernet_passthrough_source_address_ipc_msg_t get_embernet_passthrough_source_address;
    sli_zigbee_stack_get_mac_passthrough_flags_ipc_msg_t get_mac_passthrough_flags;
    sli_zigbee_stack_send_raw_message_ipc_msg_t send_raw_message;
    sli_zigbee_stack_set_embernet_passthrough_source_address_ipc_msg_t set_embernet_passthrough_source_address;
    sli_zigbee_stack_set_mac_filter_match_list_ipc_msg_t set_mac_filter_match_list;
    sli_zigbee_stack_set_mac_passthrough_flags_ipc_msg_t set_mac_passthrough_flags;
    sli_zigbee_stack_aps_crypt_message_ipc_msg_t aps_crypt_message;
    sli_zigbee_stack_clear_key_table_ipc_msg_t clear_key_table;
    sli_zigbee_stack_erase_key_table_entry_ipc_msg_t erase_key_table_entry;
    sli_zigbee_stack_find_key_table_entry_ipc_msg_t find_key_table_entry;
    sli_zigbee_stack_generate_random_key_ipc_msg_t generate_random_key;
    sli_zigbee_stack_get_aps_frame_counter_ipc_msg_t get_aps_frame_counter;
    sli_zigbee_stack_get_current_security_state_ipc_msg_t get_current_security_state;
    sli_zigbee_stack_get_extended_security_bitmask_ipc_msg_t get_extended_security_bitmask;
    sli_zigbee_stack_get_incoming_tc_link_key_frame_counter_ipc_msg_t get_incoming_tc_link_key_frame_counter;
    sli_zigbee_stack_get_mfg_security_config_ipc_msg_t get_mfg_security_config;
    sli_zigbee_stack_get_rejoin_mode_ipc_msg_t get_rejoin_mode;
    sli_zigbee_stack_get_security_frame_counter_ipc_msg_t get_security_frame_counter;
    sli_zigbee_stack_get_transient_key_timeout_s_ipc_msg_t get_transient_key_timeout_s;
    sli_zigbee_stack_request_link_key_ipc_msg_t request_link_key;
    sli_zigbee_stack_set_extended_security_bitmask_ipc_msg_t set_extended_security_bitmask;
    sli_zigbee_stack_set_incoming_tc_link_key_frame_counter_ipc_msg_t set_incoming_tc_link_key_frame_counter;
    sli_zigbee_stack_set_initial_security_state_ipc_msg_t set_initial_security_state;
    sli_zigbee_stack_set_mfg_security_config_ipc_msg_t set_mfg_security_config;
    sli_zigbee_stack_set_outgoing_aps_frame_counter_ipc_msg_t set_outgoing_aps_frame_counter;
    sli_zigbee_stack_set_outgoing_nwk_frame_counter_ipc_msg_t set_outgoing_nwk_frame_counter;
    sli_zigbee_stack_set_rejoin_mode_ipc_msg_t set_rejoin_mode;
    sli_zigbee_stack_set_transient_key_timeout_s_ipc_msg_t set_transient_key_timeout_s;
    sli_zigbee_stack_start_writing_stack_tokens_ipc_msg_t start_writing_stack_tokens;
    sli_zigbee_stack_stop_writing_stack_tokens_ipc_msg_t stop_writing_stack_tokens;
    sli_zigbee_stack_update_tc_link_key_ipc_msg_t update_tc_link_key;
    sli_zigbee_stack_writing_stack_tokens_enabled_ipc_msg_t writing_stack_tokens_enabled;
    sli_zigbee_stack_device_id_matches_ipc_msg_t device_id_matches;
    sli_zigbee_stack_make_device_id_pair_ipc_msg_t make_device_id_pair;
    #ifdef SL_CATALOG_ZIGBEE_PRO_STACK_ALT_MAC_PRESENT
    sli_zigbee_stack_alt_mac_init_ipc_msg_t alt_mac_init;
    #endif
    #ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
    sli_zigbee_stack_dlk_close_key_exchange_ipc_msg_t dlk_close_key_exchange;
    sli_zigbee_stack_dlk_finish_key_exchange_ipc_msg_t dlk_finish_key_exchange;
    sli_zigbee_stack_dlk_open_key_exchange_ipc_msg_t dlk_open_key_exchange;
    sli_zigbee_stack_dlk_start_key_exchange_ipc_msg_t dlk_start_key_exchange;
    #endif
    sli_zigbee_stack_get_current_duty_cycle_ipc_msg_t get_current_duty_cycle;
    sli_zigbee_stack_get_duty_cycle_limits_ipc_msg_t get_duty_cycle_limits;
    sli_zigbee_stack_get_duty_cycle_state_ipc_msg_t get_duty_cycle_state;
    sli_zigbee_stack_set_duty_cycle_limits_in_stack_ipc_msg_t set_duty_cycle_limits_in_stack;
    #ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
    sli_zigbee_stack_device_interview_status_update_ipc_msg_t device_interview_status_update;
    sli_zigbee_stack_dynamic_commissioning_is_open_for_interview_ipc_msg_t dynamic_commissioning_is_open_for_interview;
    sli_zigbee_stack_dynamic_commissioning_set_open_for_interview_ipc_msg_t dynamic_commissioning_set_open_for_interview;
    #endif
    sli_zigbee_stack_get_pseudo_random_number_ipc_msg_t get_pseudo_random_number;
    sli_zigbee_stack_get_strong_random_entropy_source_ipc_msg_t get_strong_random_entropy_source;
    sli_zigbee_stack_get_strong_random_number_array_ipc_msg_t get_strong_random_number_array;
    #ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
    sli_zigbee_stack_sec_man_ecc_derive_link_key_ipc_msg_t sec_man_ecc_derive_link_key;
    sli_zigbee_stack_sec_man_ecc_expand_shared_secret_ipc_msg_t sec_man_ecc_expand_shared_secret;
    sli_zigbee_stack_sec_man_ecc_extract_shared_secret_ipc_msg_t sec_man_ecc_extract_shared_secret;
    sli_zigbee_stack_sec_man_ecc_free_ipc_msg_t sec_man_ecc_free;
    sli_zigbee_stack_sec_man_ecc_generate_keypair_ipc_msg_t sec_man_ecc_generate_keypair;
    sli_zigbee_stack_sec_man_ecc_init_ipc_msg_t sec_man_ecc_init;
    sli_zigbee_stack_sec_man_speke_expand_shared_secret_ipc_msg_t sec_man_speke_expand_shared_secret;
    #endif
    #ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
    sli_zigbee_stack_dlk_ecc_test_vector_get_profile_ipc_msg_t dlk_ecc_test_vector_get_profile;
    sli_zigbee_stack_dlk_ecc_test_vector_set_profile_ipc_msg_t dlk_ecc_test_vector_set_profile;
    sli_zigbee_stack_sec_man_ecc_init_with_test_vector_ipc_msg_t sec_man_ecc_init_with_test_vector;
    #endif
    #ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
    sli_zigbee_stack_global_tlv_add_configurations_ipc_msg_t global_tlv_add_configurations;
    sli_zigbee_stack_global_tlv_beacon_appendix_encapsulation_ipc_msg_t global_tlv_beacon_appendix_encapsulation;
    sli_zigbee_stack_global_tlv_configuration_params_from_bitmask_ipc_msg_t global_tlv_configuration_params_from_bitmask;
    sli_zigbee_stack_global_tlv_configuration_params_get_bitmask_ipc_msg_t global_tlv_configuration_params_get_bitmask;
    sli_zigbee_stack_global_tlv_device_capability_extension_param_ipc_msg_t global_tlv_device_capability_extension_param;
    sli_zigbee_stack_global_tlv_fragmentation_param_ipc_msg_t global_tlv_fragmentation_param;
    sli_zigbee_stack_global_tlv_get_configurations_ipc_msg_t global_tlv_get_configurations;
    sli_zigbee_stack_global_tlv_joiner_encapsulation_ipc_msg_t global_tlv_joiner_encapsulation;
    sli_zigbee_stack_global_tlv_next_channel_change_get_bitmask_ipc_msg_t global_tlv_next_channel_change_get_bitmask;
    sli_zigbee_stack_global_tlv_next_channel_from_pg_ch_ipc_msg_t global_tlv_next_channel_from_pg_ch;
    sli_zigbee_stack_global_tlv_next_pan_from_pan_ipc_msg_t global_tlv_next_pan_from_pan;
    sli_zigbee_stack_global_tlv_next_pan_get_pan_ipc_msg_t global_tlv_next_pan_get_pan;
    sli_zigbee_stack_global_tlv_pan_id_conflict_ipc_msg_t global_tlv_pan_id_conflict;
    sli_zigbee_stack_global_tlv_router_information_ipc_msg_t global_tlv_router_information;
    sli_zigbee_stack_global_tlv_router_information_get_bitmask_ipc_msg_t global_tlv_router_information_get_bitmask;
    sli_zigbee_stack_global_tlv_supp_key_negotiation_ipc_msg_t global_tlv_supp_key_negotiation;
    sli_zigbee_stack_global_tlv_symmetric_passphrase_ipc_msg_t global_tlv_symmetric_passphrase;
    #endif
    #ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
    sli_zigbee_stack_zdo_get_configuration_req_ipc_msg_t zdo_get_configuration_req;
    sli_zigbee_stack_zdo_set_add_configuration_ipc_msg_t zdo_set_add_configuration;
    sli_zigbee_stack_zdo_set_send_configuration_req_ipc_msg_t zdo_set_send_configuration_req;
    #endif
    #ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
    sli_zigbee_stack_zdo_dlk_enabled_ipc_msg_t zdo_dlk_enabled;
    sli_zigbee_stack_zdo_dlk_get_supported_negotiation_parameters_ipc_msg_t zdo_dlk_get_supported_negotiation_parameters;
    sli_zigbee_stack_zdo_dlk_start_key_negotiation_ipc_msg_t zdo_dlk_start_key_negotiation;
    sli_zigbee_stack_zdo_dlk_start_key_update_ipc_msg_t zdo_dlk_start_key_update;
    slxi_zigbee_stack_gu_zdo_dlk_mangle_packet_ipc_msg_t gu_zdo_dlk_mangle_packet;
    slxi_zigbee_stack_gu_zdo_dlk_override_psk_ipc_msg_t gu_zdo_dlk_override_psk;
    slxi_zigbee_stack_gu_zdo_dlk_override_supported_params_ipc_msg_t gu_zdo_dlk_override_supported_params;
    #endif
    #ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
    sli_zigbee_stack_request_beacon_survey_ipc_msg_t request_beacon_survey;
    #endif
    #ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
    sli_zigbee_stack_get_authentication_level_ipc_msg_t get_authentication_level;
    sli_zigbee_stack_get_symmetric_passphrase_ipc_msg_t get_symmetric_passphrase;
    sli_zigbee_stack_initiate_security_challenge_ipc_msg_t initiate_security_challenge;
    sli_zigbee_stack_retrieve_authentication_token_ipc_msg_t retrieve_authentication_token;
    #endif
    #ifdef SL_CATALOG_ZIGBEE_SOURCE_ROUTE_PRESENT
    sli_zigbee_stack_concentrator_note_delivery_failure_ipc_msg_t concentrator_note_delivery_failure;
    sli_zigbee_stack_concentrator_note_route_error_ipc_msg_t concentrator_note_route_error;
    sli_zigbee_stack_get_assumed_trust_center_concentrator_type_ipc_msg_t get_assumed_trust_center_concentrator_type;
    sli_zigbee_stack_get_source_route_overhead_ipc_msg_t get_source_route_overhead;
    sli_zigbee_stack_get_source_route_table_entry_ipc_msg_t get_source_route_table_entry;
    sli_zigbee_stack_get_source_route_table_filled_size_ipc_msg_t get_source_route_table_filled_size;
    sli_zigbee_stack_get_source_route_table_total_size_ipc_msg_t get_source_route_table_total_size;
    sli_zigbee_stack_send_many_to_one_route_request_ipc_msg_t send_many_to_one_route_request;
    sli_zigbee_stack_set_assumed_trust_center_concentrator_type_ipc_msg_t set_assumed_trust_center_concentrator_type;
    sli_zigbee_stack_set_concentrator_ipc_msg_t set_concentrator;
    sli_zigbee_stack_set_source_route_discovery_mode_ipc_msg_t set_source_route_discovery_mode;
    #endif
    sli_802154_stack_get_tx_power_mode_ipc_msg_t get_tx_power_mode;
    sli_802154_stack_radio_get_scheduler_priorities_ipc_msg_t radio_get_scheduler_priorities;
    sli_802154_stack_radio_get_scheduler_sliptime_ipc_msg_t radio_get_scheduler_sliptime;
    sli_802154_stack_radio_set_scheduler_priorities_ipc_msg_t radio_set_scheduler_priorities;
    sli_802154_stack_radio_set_scheduler_sliptime_ipc_msg_t radio_set_scheduler_sliptime;
    sli_802154_stack_set_tx_power_mode_ipc_msg_t set_tx_power_mode;
    sli_mac_stack_get_csma_params_ipc_msg_t get_csma_params;
    sli_mac_stack_get_ed_cca_threshold_ipc_msg_t get_ed_cca_threshold;
    sli_mac_stack_set_cca_threshold_ipc_msg_t set_cca_threshold;
    sli_mac_stack_set_csma_params_ipc_msg_t set_csma_params;
    sli_zigbee_stack_clear_counters_ipc_msg_t clear_counters;
    sli_zigbee_stack_counter_requires_destination_node_id_ipc_msg_t counter_requires_destination_node_id;
    sli_zigbee_stack_counter_requires_phy_index_ipc_msg_t counter_requires_phy_index;
    sli_zigbee_stack_get_endpoint_ipc_msg_t get_endpoint;
    sli_zigbee_stack_get_endpoint_cluster_ipc_msg_t get_endpoint_cluster;
    sli_zigbee_stack_get_endpoint_count_ipc_msg_t get_endpoint_count;
    sli_zigbee_stack_get_endpoint_description_ipc_msg_t get_endpoint_description;
    sli_zigbee_stack_get_eui64_ipc_msg_t get_eui64;
    sli_zigbee_stack_get_extended_pan_id_ipc_msg_t get_extended_pan_id;
    sli_zigbee_stack_get_initial_neighbor_outgoing_cost_ipc_msg_t get_initial_neighbor_outgoing_cost;
    sli_zigbee_stack_get_manufacturer_code_ipc_msg_t get_manufacturer_code;
    sli_zigbee_stack_get_max_nwk_retries_ipc_msg_t get_max_nwk_retries;
    sli_zigbee_stack_get_neighbor_ipc_msg_t get_neighbor;
    sli_zigbee_stack_get_neighbor_frame_counter_ipc_msg_t get_neighbor_frame_counter;
    sli_zigbee_stack_get_network_parameters_ipc_msg_t get_network_parameters;
    sli_zigbee_stack_get_node_descriptor_ipc_msg_t get_node_descriptor;
    sli_zigbee_stack_get_node_id_ipc_msg_t get_node_id;
    sli_zigbee_stack_get_pan_id_ipc_msg_t get_pan_id;
    sli_zigbee_stack_get_phy_interface_count_ipc_msg_t get_phy_interface_count;
    sli_zigbee_stack_get_radio_channel_ipc_msg_t get_radio_channel;
    sli_zigbee_stack_get_radio_parameters_ipc_msg_t get_radio_parameters;
    sli_zigbee_stack_get_radio_power_ipc_msg_t get_radio_power;
    sli_zigbee_stack_get_rail_handle_ipc_msg_t get_rail_handle;
    sli_zigbee_stack_get_route_table_entry_ipc_msg_t get_route_table_entry;
    sli_zigbee_stack_get_route_table_size_ipc_msg_t get_route_table_size;
    sli_zigbee_stack_get_routing_shortcut_threshold_ipc_msg_t get_routing_shortcut_threshold;
    sli_zigbee_stack_get_source_route_table_size_ipc_msg_t get_source_route_table_size;
    sli_zigbee_stack_get_stack_compliance_revision_ipc_msg_t get_stack_compliance_revision;
    sli_zigbee_stack_get_token_count_ipc_msg_t get_token_count;
    sli_zigbee_stack_get_token_data_ipc_msg_t get_token_data;
    sli_zigbee_stack_get_token_info_ipc_msg_t get_token_info;
    sli_zigbee_stack_is_local_eui64_ipc_msg_t is_local_eui64;
    sli_zigbee_stack_is_reset_rejoining_neighbors_frame_counter_enabled_ipc_msg_t is_reset_rejoining_neighbors_frame_counter_enabled;
    sli_zigbee_stack_lookup_eui64_by_node_id_ipc_msg_t lookup_eui64_by_node_id;
    sli_zigbee_stack_lookup_node_id_by_eui64_ipc_msg_t lookup_node_id_by_eui64;
    sli_zigbee_stack_ms_to_next_stack_event_ipc_msg_t ms_to_next_stack_event;
    sli_zigbee_stack_neighbor_count_ipc_msg_t neighbor_count;
    sli_zigbee_stack_network_state_ipc_msg_t network_state;
    sli_zigbee_stack_next_zigbee_sequence_number_ipc_msg_t next_zigbee_sequence_number;
    sli_zigbee_stack_read_and_clear_counters_ipc_msg_t read_and_clear_counters;
    sli_zigbee_stack_read_counters_ipc_msg_t read_counters;
    sli_zigbee_stack_reset_counters_thresholds_ipc_msg_t reset_counters_thresholds;
    sli_zigbee_stack_reset_rejoining_neighbors_frame_counter_ipc_msg_t reset_rejoining_neighbors_frame_counter;
    sli_zigbee_stack_security_level_ipc_msg_t security_level;
    sli_zigbee_stack_set_broken_route_error_code_ipc_msg_t set_broken_route_error_code;
    sli_zigbee_stack_set_counter_threshold_ipc_msg_t set_counter_threshold;
    sli_zigbee_stack_set_initial_neighbor_outgoing_cost_ipc_msg_t set_initial_neighbor_outgoing_cost;
    sli_zigbee_stack_set_logical_and_radio_channel_ipc_msg_t set_logical_and_radio_channel;
    sli_zigbee_stack_set_neighbor_frame_counter_ipc_msg_t set_neighbor_frame_counter;
    sli_zigbee_stack_set_node_descriptor_ipc_msg_t set_node_descriptor;
    sli_zigbee_stack_set_node_id_ipc_msg_t set_node_id;
    sli_zigbee_stack_set_power_descriptor_ipc_msg_t set_power_descriptor;
    sli_zigbee_stack_set_radio_channel_ipc_msg_t set_radio_channel;
    sli_zigbee_stack_set_radio_ieee802154_cca_mode_ipc_msg_t set_radio_ieee802154_cca_mode;
    sli_zigbee_stack_set_radio_power_ipc_msg_t set_radio_power;
    sli_zigbee_stack_set_route_table_size_ipc_msg_t set_route_table_size;
    sli_zigbee_stack_set_routing_shortcut_threshold_ipc_msg_t set_routing_shortcut_threshold;
    sli_zigbee_stack_set_security_level_ipc_msg_t set_security_level;
    sli_zigbee_stack_set_source_route_table_size_ipc_msg_t set_source_route_table_size;
    sli_zigbee_stack_set_stack_profile_ipc_msg_t set_stack_profile;
    sli_zigbee_stack_set_token_data_ipc_msg_t set_token_data;
    sli_zigbee_stack_stack_is_up_ipc_msg_t stack_is_up;
    sli_zigbee_stack_stack_profile_ipc_msg_t stack_profile;
    sli_zigbee_stack_token_factory_reset_ipc_msg_t token_factory_reset;
    sli_zigbee_stack_write_node_data_ipc_msg_t write_node_data;
    slxi_zigbee_stack_routing_get_route_record_policy_ipc_msg_t routing_get_route_record_policy;
    slxi_zigbee_stack_routing_set_route_record_policy_ipc_msg_t routing_set_route_record_policy;
    sli_zigbee_stack_broadcast_network_key_switch_ipc_msg_t broadcast_network_key_switch;
    sli_zigbee_stack_broadcast_next_network_key_ipc_msg_t broadcast_next_network_key;
    sli_zigbee_stack_get_app_link_key_request_policy_ipc_msg_t get_app_link_key_request_policy;
    sli_zigbee_stack_get_transient_device_table_timeout_ms_ipc_msg_t get_transient_device_table_timeout_ms;
    sli_zigbee_stack_get_trust_center_link_key_request_policy_ipc_msg_t get_trust_center_link_key_request_policy;
    sli_zigbee_stack_send_remove_device_ipc_msg_t send_remove_device;
    sli_zigbee_stack_send_trust_center_link_key_ipc_msg_t send_trust_center_link_key;
    sli_zigbee_stack_send_unicast_network_key_update_ipc_msg_t send_unicast_network_key_update;
    sli_zigbee_stack_set_app_link_key_request_policy_ipc_msg_t set_app_link_key_request_policy;
    sli_zigbee_stack_set_transient_device_table_timeout_ms_ipc_msg_t set_transient_device_table_timeout_ms;
    sli_zigbee_stack_set_trust_center_link_key_request_policy_ipc_msg_t set_trust_center_link_key_request_policy;
    sli_zigbee_stack_unicast_current_network_key_ipc_msg_t unicast_current_network_key;
    sli_zigbee_stack_energy_scan_request_ipc_msg_t energy_scan_request;
    sli_zigbee_stack_get_last_stack_zig_dev_request_sequence_ipc_msg_t get_last_stack_zig_dev_request_sequence;
    sli_zigbee_stack_ieee_address_request_ipc_msg_t ieee_address_request;
    sli_zigbee_stack_ieee_address_request_to_target_ipc_msg_t ieee_address_request_to_target;
    sli_zigbee_stack_network_address_request_ipc_msg_t network_address_request;
    sli_zigbee_stack_send_device_announcement_ipc_msg_t send_device_announcement;
    sli_zigbee_stack_send_parent_announcement_ipc_msg_t send_parent_announcement;
    sli_zigbee_stack_set_manufacturer_code_ipc_msg_t set_manufacturer_code;
    sli_zigbee_stack_set_pending_network_update_channel_ipc_msg_t set_pending_network_update_channel;
    sli_zigbee_stack_set_zdo_configuration_mode_ipc_msg_t set_zdo_configuration_mode;
    sli_zigbee_stack_sec_man_aes_128_crypt_block_ipc_msg_t sec_man_aes_128_crypt_block;
    sli_zigbee_stack_sec_man_aes_ccm_extended_ipc_msg_t sec_man_aes_ccm_extended;
    sli_zigbee_stack_sec_man_check_key_context_ipc_msg_t sec_man_check_key_context;
    sli_zigbee_stack_sec_man_compare_key_to_value_ipc_msg_t sec_man_compare_key_to_value;
    sli_zigbee_stack_sec_man_delete_key_ipc_msg_t sec_man_delete_key;
    sli_zigbee_stack_sec_man_delete_key_table_key_ipc_msg_t sec_man_delete_key_table_key;
    sli_zigbee_stack_sec_man_delete_transient_key_ipc_msg_t sec_man_delete_transient_key;
    sli_zigbee_stack_sec_man_export_key_ipc_msg_t sec_man_export_key;
    sli_zigbee_stack_sec_man_export_link_key_by_eui_ipc_msg_t sec_man_export_link_key_by_eui;
    sli_zigbee_stack_sec_man_export_link_key_by_index_ipc_msg_t sec_man_export_link_key_by_index;
    sli_zigbee_stack_sec_man_export_symmetric_passphrase_ipc_msg_t sec_man_export_symmetric_passphrase;
    sli_zigbee_stack_sec_man_export_transient_key_by_eui_ipc_msg_t sec_man_export_transient_key_by_eui;
    sli_zigbee_stack_sec_man_export_transient_key_by_index_ipc_msg_t sec_man_export_transient_key_by_index;
    sli_zigbee_stack_sec_man_find_symmetric_passphrase_key_table_index_ipc_msg_t sec_man_find_symmetric_passphrase_key_table_index;
    sli_zigbee_stack_sec_man_get_aps_key_info_ipc_msg_t sec_man_get_aps_key_info;
    sli_zigbee_stack_sec_man_get_network_key_info_ipc_msg_t sec_man_get_network_key_info;
    sli_zigbee_stack_sec_man_have_link_key_ipc_msg_t sec_man_have_link_key;
    sli_zigbee_stack_sec_man_hmac_aes_mmo_ipc_msg_t sec_man_hmac_aes_mmo;
    sli_zigbee_stack_sec_man_import_key_ipc_msg_t sec_man_import_key;
    sli_zigbee_stack_sec_man_import_link_key_ipc_msg_t sec_man_import_link_key;
    sli_zigbee_stack_sec_man_import_symmetric_passphrase_ipc_msg_t sec_man_import_symmetric_passphrase;
    sli_zigbee_stack_sec_man_import_transient_key_ipc_msg_t sec_man_import_transient_key;
    sli_zigbee_stack_sec_man_init_context_ipc_msg_t sec_man_init_context;
    sli_zigbee_stack_sec_man_link_key_slot_available_ipc_msg_t sec_man_link_key_slot_available;
    sli_zigbee_stack_sec_man_load_key_context_ipc_msg_t sec_man_load_key_context;
    sli_zigbee_stack_sec_man_set_context_aes_ecb_alg_ipc_msg_t sec_man_set_context_aes_ecb_alg;
    sli_zigbee_stack_sec_man_set_context_extended_ccm_alg_ipc_msg_t sec_man_set_context_extended_ccm_alg;
    sli_zigbee_stack_sec_man_update_symmetric_passphrase_eui_ipc_msg_t sec_man_update_symmetric_passphrase_eui;
    #ifdef SL_CATALOG_ZIGBEE_DIRECT_ZDD_PRESENT
    sli_zigbee_stack_direct_send_commissioning_response_ipc_msg_t direct_send_commissioning_response;
    sli_zigbee_stack_direct_send_ephemeral_key_ipc_msg_t direct_send_ephemeral_key;
    sli_zigbee_stack_get_nwk_update_id_ipc_msg_t get_nwk_update_id;
    sli_zigbee_stack_transient_device_mgmt_finish_ipc_msg_t transient_device_mgmt_finish;
    #endif
    #ifdef SL_CATALOG_ZIGBEE_LIGHT_LINK_PRESENT
    sli_zigbee_stack_get_zll_primary_channel_mask_ipc_msg_t get_zll_primary_channel_mask;
    sli_zigbee_stack_get_zll_secondary_channel_mask_ipc_msg_t get_zll_secondary_channel_mask;
    sli_zigbee_stack_is_zll_network_ipc_msg_t is_zll_network;
    sli_zigbee_stack_set_zll_additional_state_ipc_msg_t set_zll_additional_state;
    sli_zigbee_stack_set_zll_node_type_ipc_msg_t set_zll_node_type;
    sli_zigbee_stack_set_zll_primary_channel_mask_ipc_msg_t set_zll_primary_channel_mask;
    sli_zigbee_stack_set_zll_secondary_channel_mask_ipc_msg_t set_zll_secondary_channel_mask;
    sli_zigbee_stack_zll_form_network_ipc_msg_t zll_form_network;
    sli_zigbee_stack_zll_get_policy_ipc_msg_t zll_get_policy;
    sli_zigbee_stack_zll_get_radio_idle_mode_ipc_msg_t zll_get_radio_idle_mode;
    sli_zigbee_stack_zll_get_token_stack_zll_data_ipc_msg_t zll_get_token_stack_zll_data;
    sli_zigbee_stack_zll_get_token_stack_zll_security_ipc_msg_t zll_get_token_stack_zll_security;
    sli_zigbee_stack_zll_get_tokens_stack_zll_ipc_msg_t zll_get_tokens_stack_zll;
    sli_zigbee_stack_zll_join_target_ipc_msg_t zll_join_target;
    sli_zigbee_stack_zll_operation_in_progress_ipc_msg_t zll_operation_in_progress;
    sli_zigbee_stack_zll_rx_on_when_idle_get_active_ipc_msg_t zll_rx_on_when_idle_get_active;
    sli_zigbee_stack_zll_set_initial_security_state_ipc_msg_t zll_set_initial_security_state;
    sli_zigbee_stack_zll_set_policy_ipc_msg_t zll_set_policy;
    sli_zigbee_stack_zll_set_radio_idle_mode_ipc_msg_t zll_set_radio_idle_mode;
    sli_zigbee_stack_zll_set_rx_on_when_idle_ipc_msg_t zll_set_rx_on_when_idle;
    sli_zigbee_stack_zll_set_security_state_without_key_ipc_msg_t zll_set_security_state_without_key;
    sli_zigbee_stack_zll_set_token_stack_zll_data_ipc_msg_t zll_set_token_stack_zll_data;
    sli_zigbee_stack_zll_start_scan_ipc_msg_t zll_start_scan;
    #endif
  } data;
} sli_zigbee_ipc_cmd_t;

typedef void (*sli_zigbee_ipc_cmd_handler_t)(sli_zigbee_ipc_cmd_t *msg);
void sli_zigbee_send_ipc_cmd(sli_zigbee_ipc_cmd_handler_t handler, sli_zigbee_ipc_cmd_t *msg);

#endif // ZIGBEE_IPC_COMMAND_MESSAGES_H
