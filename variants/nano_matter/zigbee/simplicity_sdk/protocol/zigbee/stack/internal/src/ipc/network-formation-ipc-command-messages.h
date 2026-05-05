/***************************************************************************//**
 * @file network-formation-ipc-command-messages.h
 * @brief defines structured format for 'network-formation' ipc messages
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
#ifndef NETWORK_FORMATION_IPC_COMMAND_MESSAGES_H
#define NETWORK_FORMATION_IPC_COMMAND_MESSAGES_H

#include "stack/include/network-formation.h"
#include "stack/internal/inc/network-formation-internal-def.h"

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_clear_stored_beacons_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_clear_stored_beacons_ipc_rsp_t response;
} sli_zigbee_stack_clear_stored_beacons_ipc_msg_t;

typedef struct {
  bool activated;
} sli_zigbee_stack_delayed_join_activate_ipc_req_t;

typedef struct {
  sli_zigbee_stack_delayed_join_activate_ipc_req_t request;
} sli_zigbee_stack_delayed_join_activate_ipc_msg_t;

typedef struct {
  bool result;
} sli_zigbee_stack_delayed_join_is_activated_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_delayed_join_is_activated_ipc_rsp_t response;
} sli_zigbee_stack_delayed_join_is_activated_ipc_msg_t;

typedef struct {
  bool haveCurrentNetworkKey;
  uint32_t channelMask;
  sl_zigbee_rejoin_reason_t reason;
  sl_zigbee_node_type_t nodeType;
} sli_zigbee_stack_find_and_rejoin_network_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_find_and_rejoin_network_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_find_and_rejoin_network_ipc_req_t request;
  sli_zigbee_stack_find_and_rejoin_network_ipc_rsp_t response;
} sli_zigbee_stack_find_and_rejoin_network_ipc_msg_t;

typedef struct {
  uint32_t channelMask;
  uint8_t duration;
} sli_zigbee_stack_find_unused_pan_id_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_find_unused_pan_id_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_find_unused_pan_id_ipc_req_t request;
  sli_zigbee_stack_find_unused_pan_id_ipc_rsp_t response;
} sli_zigbee_stack_find_unused_pan_id_ipc_msg_t;

typedef struct {
  sl_zigbee_network_parameters_t parameters;
} sli_zigbee_stack_form_network_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_form_network_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_form_network_ipc_req_t request;
  sli_zigbee_stack_form_network_ipc_rsp_t response;
} sli_zigbee_stack_form_network_ipc_msg_t;

typedef struct {
  sl_zigbee_beacon_classification_params_t param;
} sli_zigbee_stack_get_beacon_classification_params_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_beacon_classification_params_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_beacon_classification_params_ipc_req_t request;
  sli_zigbee_stack_get_beacon_classification_params_ipc_rsp_t response;
} sli_zigbee_stack_get_beacon_classification_params_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t returnNodeIdThatSentLeave;
} sli_zigbee_stack_get_last_leave_reason_ipc_req_t;

typedef struct {
  sl_zigbee_leave_reason_t result;
} sli_zigbee_stack_get_last_leave_reason_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_last_leave_reason_ipc_req_t request;
  sli_zigbee_stack_get_last_leave_reason_ipc_rsp_t response;
} sli_zigbee_stack_get_last_leave_reason_ipc_msg_t;

typedef struct {
  sl_zigbee_rejoin_reason_t result;
} sli_zigbee_stack_get_last_rejoin_reason_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_last_rejoin_reason_ipc_rsp_t response;
} sli_zigbee_stack_get_last_rejoin_reason_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_network_key_timeout_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_network_key_timeout_ipc_rsp_t response;
} sli_zigbee_stack_get_network_key_timeout_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_num_stored_beacons_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_num_stored_beacons_ipc_rsp_t response;
} sli_zigbee_stack_get_num_stored_beacons_ipc_msg_t;

typedef struct {
  bool result;
} sli_zigbee_stack_get_permit_joining_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_permit_joining_ipc_rsp_t response;
} sli_zigbee_stack_get_permit_joining_ipc_msg_t;

typedef struct {
  uint8_t beacon_number;
  sl_zigbee_beacon_data_t beacon;
} sli_zigbee_stack_get_stored_beacon_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_stored_beacon_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_stored_beacon_ipc_req_t request;
  sli_zigbee_stack_get_stored_beacon_ipc_rsp_t response;
} sli_zigbee_stack_get_stored_beacon_ipc_msg_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_init_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_init_ipc_rsp_t response;
} sli_zigbee_stack_init_ipc_msg_t;

typedef struct {
  bool result;
} sli_zigbee_stack_is_performing_rejoin_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_is_performing_rejoin_ipc_rsp_t response;
} sli_zigbee_stack_is_performing_rejoin_ipc_msg_t;

typedef struct {
  sl_zigbee_node_type_t nodeType;
  sl_zigbee_network_parameters_t parameters;
} sli_zigbee_stack_join_network_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_join_network_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_join_network_ipc_req_t request;
  sli_zigbee_stack_join_network_ipc_rsp_t response;
} sli_zigbee_stack_join_network_ipc_msg_t;

typedef struct {
  sl_zigbee_node_type_t localNodeType;
  sl_zigbee_beacon_data_t beacon;
  int8_t radioTxPower;
  bool clearBeaconsAfterNetworkUp;
} sli_zigbee_stack_join_network_directly_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_join_network_directly_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_join_network_directly_ipc_req_t request;
  sli_zigbee_stack_join_network_directly_ipc_rsp_t response;
} sli_zigbee_stack_join_network_directly_ipc_msg_t;

typedef struct {
  sl_zigbee_leave_network_option_t options;
} sli_zigbee_stack_leave_network_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_leave_network_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_leave_network_ipc_req_t request;
  sli_zigbee_stack_leave_network_ipc_rsp_t response;
} sli_zigbee_stack_leave_network_ipc_msg_t;

typedef struct {
  sl_zigbee_network_init_struct_t networkInitStruct;
} sli_zigbee_stack_network_init_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_network_init_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_network_init_ipc_req_t request;
  sli_zigbee_stack_network_init_ipc_rsp_t response;
} sli_zigbee_stack_network_init_ipc_msg_t;

typedef struct {
  uint8_t duration;
} sli_zigbee_stack_permit_joining_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_permit_joining_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_permit_joining_ipc_req_t request;
  sli_zigbee_stack_permit_joining_ipc_rsp_t response;
} sli_zigbee_stack_permit_joining_ipc_msg_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_reschedule_link_status_msg_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_reschedule_link_status_msg_ipc_rsp_t response;
} sli_zigbee_stack_reschedule_link_status_msg_ipc_msg_t;

typedef struct {
  sl_802154_pan_id_t newPan;
} sli_zigbee_stack_send_pan_id_update_ipc_req_t;

typedef struct {
  bool result;
} sli_zigbee_stack_send_pan_id_update_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_pan_id_update_ipc_req_t request;
  sli_zigbee_stack_send_pan_id_update_ipc_rsp_t response;
} sli_zigbee_stack_send_pan_id_update_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t destination;
  sl_zigbee_leave_request_flags_t flags;
} sli_zigbee_stack_send_zigbee_leave_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_send_zigbee_leave_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_zigbee_leave_ipc_req_t request;
  sli_zigbee_stack_send_zigbee_leave_ipc_rsp_t response;
} sli_zigbee_stack_send_zigbee_leave_ipc_msg_t;

typedef struct {
  sl_zigbee_beacon_classification_params_t param;
} sli_zigbee_stack_set_beacon_classification_params_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_beacon_classification_params_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_beacon_classification_params_ipc_req_t request;
  sli_zigbee_stack_set_beacon_classification_params_ipc_rsp_t response;
} sli_zigbee_stack_set_beacon_classification_params_ipc_msg_t;

typedef struct {
  uint8_t beaconJitterDuration;
} sli_zigbee_stack_set_beacon_jitter_duration_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_beacon_jitter_duration_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_beacon_jitter_duration_ipc_req_t request;
  sli_zigbee_stack_set_beacon_jitter_duration_ipc_rsp_t response;
} sli_zigbee_stack_set_beacon_jitter_duration_ipc_msg_t;

typedef struct {
  uint8_t numBeacons;
} sli_zigbee_stack_set_num_beacons_to_store_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_num_beacons_to_store_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_num_beacons_to_store_ipc_req_t request;
  sli_zigbee_stack_set_num_beacons_to_store_ipc_rsp_t response;
} sli_zigbee_stack_set_num_beacons_to_store_ipc_msg_t;

typedef struct {
  uint8_t nwkUpdateId;
  bool set_when_on_network;
} sli_zigbee_stack_set_nwk_update_id_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_nwk_update_id_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_nwk_update_id_ipc_req_t request;
  sli_zigbee_stack_set_nwk_update_id_ipc_rsp_t response;
} sli_zigbee_stack_set_nwk_update_id_ipc_msg_t;

typedef struct {
  uint16_t panId;
} sli_zigbee_stack_set_pending_network_update_pan_id_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_pending_network_update_pan_id_ipc_req_t request;
} sli_zigbee_stack_set_pending_network_update_pan_id_ipc_msg_t;

typedef struct {
  bool allow;
} sli_zigbee_stack_set_tc_rejoins_using_well_known_key_allowed_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_tc_rejoins_using_well_known_key_allowed_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_tc_rejoins_using_well_known_key_allowed_ipc_req_t request;
  sli_zigbee_stack_set_tc_rejoins_using_well_known_key_allowed_ipc_rsp_t response;
} sli_zigbee_stack_set_tc_rejoins_using_well_known_key_allowed_ipc_msg_t;

typedef struct {
  uint16_t timeout_sec;
} sli_zigbee_stack_set_tc_rejoins_using_well_known_key_timeout_sec_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_tc_rejoins_using_well_known_key_timeout_sec_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_tc_rejoins_using_well_known_key_timeout_sec_ipc_req_t request;
  sli_zigbee_stack_set_tc_rejoins_using_well_known_key_timeout_sec_ipc_rsp_t response;
} sli_zigbee_stack_set_tc_rejoins_using_well_known_key_timeout_sec_ipc_msg_t;

typedef struct {
  uint8_t networkKeyTimeoutS;
} sli_zigbee_stack_setup_delayed_join_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_setup_delayed_join_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_setup_delayed_join_ipc_req_t request;
  sli_zigbee_stack_setup_delayed_join_ipc_rsp_t response;
} sli_zigbee_stack_setup_delayed_join_ipc_msg_t;

typedef struct {
  sl_zigbee_network_parameters_t parameters;
  bool initiator;
} sli_zigbee_stack_sleepy_to_sleepy_network_start_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_sleepy_to_sleepy_network_start_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_sleepy_to_sleepy_network_start_ipc_req_t request;
  sli_zigbee_stack_sleepy_to_sleepy_network_start_ipc_rsp_t response;
} sli_zigbee_stack_sleepy_to_sleepy_network_start_ipc_msg_t;

typedef struct {
  sl_zigbee_network_scan_type_t scanType;
  uint32_t channelMask;
  uint8_t duration;
} sli_zigbee_stack_start_scan_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_start_scan_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_start_scan_ipc_req_t request;
  sli_zigbee_stack_start_scan_ipc_rsp_t response;
} sli_zigbee_stack_start_scan_ipc_msg_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_stop_scan_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_stop_scan_ipc_rsp_t response;
} sli_zigbee_stack_stop_scan_ipc_msg_t;

typedef struct {
  bool useStandardBeacons;
  uint32_t channel_mask;
  sl_zigbee_network_found_callback_t networkFoundCallback;
  sl_zigbee_scan_complete_callback_t scanCompleteCallback;
} sli_zigbee_stack_survey_beacons_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_survey_beacons_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_survey_beacons_ipc_req_t request;
  sli_zigbee_stack_survey_beacons_ipc_rsp_t response;
} sli_zigbee_stack_survey_beacons_ipc_msg_t;

typedef struct {
  bool result;
} sli_zigbee_stack_tc_rejoins_using_well_known_key_allowed_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_tc_rejoins_using_well_known_key_allowed_ipc_rsp_t response;
} sli_zigbee_stack_tc_rejoins_using_well_known_key_allowed_ipc_msg_t;

#endif // NETWORK_FORMATION_IPC_COMMAND_MESSAGES_H
