/***************************************************************************//**
 * @file zigbee_ipc_callback_events.h
 * @brief struct definitions for zigbee calllback events
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
#ifndef ZIGBEE_IPC_CALLBACK_EVENTS_H
#define ZIGBEE_IPC_CALLBACK_EVENTS_H

#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif

#include "sl_enum.h"
#include "sl_event_system.h"
#include "sl_memory_manager.h"
#include "stack/internal/src/ipc/binding-table-ipc-callback-events.h"
#include "stack/internal/src/ipc/bootload_ipc_callback_events.h"
#ifdef SL_CATALOG_ZIGBEE_CBKE_CORE_PRESENT
#include "stack/internal/src/ipc/cbke-crypto-engine-ipc-callback-events.h"
#endif
#include "stack/internal/src/ipc/child_ipc_callback_events.h"
#ifdef SL_CATALOG_HIGH_DATARATE_PHY_PRESENT
#include "stack/internal/src/ipc/high_datarate_phy_stack_interface_ipc_callback_events.h"
#endif
#include "stack/internal/src/ipc/message_ipc_callback_events.h"
#include "stack/internal/src/ipc/network-formation-ipc-callback-events.h"
#include "stack/internal/src/ipc/raw-message-ipc-callback-events.h"
#include "stack/internal/src/ipc/security_ipc_callback_events.h"
#include "stack/internal/src/ipc/sl_zigbee_duty_cycle_ipc_callback_events.h"
#ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
#include "stack/internal/src/ipc/sl_zigbee_dynamic_commissioning_ipc_callback_events.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
#include "stack/internal/src/ipc/sl_zigbee_zdo_management_ipc_callback_events.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
#include "stack/internal/src/ipc/sl_zigbee_zdo_security_ipc_callback_events.h"
#endif
#include "stack/internal/src/ipc/stack-info-ipc-callback-events.h"
#include "stack/internal/src/ipc/trust-center-ipc-callback-events.h"
#ifdef SL_CATALOG_ZIGBEE_LIGHT_LINK_PRESENT
#include "stack/internal/src/ipc/zll-api-ipc-callback-events.h"
#endif

SL_ENUM_GENERIC(sl_zigbee_stack_cb_event_tag_t, uint16_t) {
  SLI_ZIGBEE_STACK_REMOTE_DELETE_BINDING_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_REMOTE_SET_BINDING_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_BOOTLOAD_TRANSMIT_COMPLETE_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_INCOMING_BOOTLOAD_MESSAGE_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_CALCULATE_SMACS_283K1_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_CALCULATE_SMACS_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_DSA_SIGN_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_DSA_VERIFY_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_GENERATE_CBKE_KEYS_283K1_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_GENERATE_CBKE_KEYS_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_CHILD_JOIN_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_POLL_COMPLETE_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_POLL_HANDLER_IPC_EVENT_TYPE,
  SLI_MAC_STACK_HIGH_DATARATE_PHY_RX_CALLBACK_IPC_EVENT_TYPE,
  SLI_MAC_STACK_HIGH_DATARATE_PHY_TX_CALLBACK_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_GPEP_INCOMING_MESSAGE_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_ID_CONFLICT_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_INCOMING_MANY_TO_ONE_ROUTE_REQUEST_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_INCOMING_MESSAGE_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_INCOMING_NETWORK_STATUS_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_INCOMING_ROUTE_ERROR_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_INCOMING_ROUTE_RECORD_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_MESSAGE_SENT_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_OVERRIDE_INCOMING_ROUTE_RECORD_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_REDIRECT_OUTGOING_MESSAGE_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_ENERGY_SCAN_RESULT_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_NETWORK_FOUND_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_ORPHAN_NOTIFICATION_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_SCAN_COMPLETE_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_UNUSED_PAN_ID_FOUND_HANDLER_IPC_EVENT_TYPE,
  SLI_802154_STACK_FILTER_MATCH_MESSAGE_HANDLER_IPC_EVENT_TYPE,
  SLI_802154_STACK_PASSTHROUGH_MESSAGE_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_RAW_TRANSMIT_COMPLETE_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_SWITCH_NETWORK_KEY_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_ZIGBEE_KEY_ESTABLISHMENT_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_DUTY_CYCLE_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_DYNAMIC_COMMISSIONING_ALERT_CALLBACK_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_BEACON_SURVEY_COMPLETE_CALLBACK_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_GET_AUTHENTICATION_LEVEL_CALLBACK_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_SET_AUTHENTICAION_LEVEL_CALLBACK_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_ZDO_RETRIEVE_AUTHENTICATION_TOKEN_COMPLETE_CALLBACK_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_RADIO_NEEDS_CALIBRATING_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_STACK_STATUS_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_STACK_TOKEN_CHANGED_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_TRUST_CENTER_POST_JOIN_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_ZLL_ADDRESS_ASSIGNMENT_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_ZLL_NETWORK_FOUND_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_ZLL_SCAN_COMPLETE_HANDLER_IPC_EVENT_TYPE,
  SLI_ZIGBEE_STACK_ZLL_TOUCH_LINK_TARGET_HANDLER_IPC_EVENT_TYPE
};

typedef struct {
  sl_zigbee_stack_cb_event_tag_t tag;
  union {
    sli_zigbee_stack_remote_delete_binding_handler_ipc_event_t remote_delete_binding_handler;
    sli_zigbee_stack_remote_set_binding_handler_ipc_event_t remote_set_binding_handler;
    sli_zigbee_stack_bootload_transmit_complete_handler_ipc_event_t bootload_transmit_complete_handler;
    sli_zigbee_stack_incoming_bootload_message_handler_ipc_event_t incoming_bootload_message_handler;
    #ifdef SL_CATALOG_ZIGBEE_CBKE_CORE_PRESENT
    sli_zigbee_stack_calculate_smacs_283k1_handler_ipc_event_t calculate_smacs_283k1_handler;
    sli_zigbee_stack_calculate_smacs_handler_ipc_event_t calculate_smacs_handler;
    sli_zigbee_stack_dsa_sign_handler_ipc_event_t dsa_sign_handler;
    sli_zigbee_stack_dsa_verify_handler_ipc_event_t dsa_verify_handler;
    sli_zigbee_stack_generate_cbke_keys_283k1_handler_ipc_event_t generate_cbke_keys_283k1_handler;
    sli_zigbee_stack_generate_cbke_keys_handler_ipc_event_t generate_cbke_keys_handler;
    #endif
    sli_zigbee_stack_child_join_handler_ipc_event_t child_join_handler;
    sli_zigbee_stack_poll_complete_handler_ipc_event_t poll_complete_handler;
    sli_zigbee_stack_poll_handler_ipc_event_t poll_handler;
    #ifdef SL_CATALOG_HIGH_DATARATE_PHY_PRESENT
    sli_mac_stack_high_datarate_phy_rx_callback_ipc_event_t high_datarate_phy_rx_callback;
    sli_mac_stack_high_datarate_phy_tx_callback_ipc_event_t high_datarate_phy_tx_callback;
    #endif
    sli_zigbee_stack_gpep_incoming_message_handler_ipc_event_t gpep_incoming_message_handler;
    sli_zigbee_stack_id_conflict_handler_ipc_event_t id_conflict_handler;
    sli_zigbee_stack_incoming_many_to_one_route_request_handler_ipc_event_t incoming_many_to_one_route_request_handler;
    sli_zigbee_stack_incoming_message_handler_ipc_event_t incoming_message_handler;
    sli_zigbee_stack_incoming_network_status_handler_ipc_event_t incoming_network_status_handler;
    sli_zigbee_stack_incoming_route_error_handler_ipc_event_t incoming_route_error_handler;
    sli_zigbee_stack_incoming_route_record_handler_ipc_event_t incoming_route_record_handler;
    sli_zigbee_stack_message_sent_handler_ipc_event_t message_sent_handler;
    sli_zigbee_stack_override_incoming_route_record_handler_ipc_event_t override_incoming_route_record_handler;
    sli_zigbee_stack_redirect_outgoing_message_handler_ipc_event_t redirect_outgoing_message_handler;
    sli_zigbee_stack_energy_scan_result_handler_ipc_event_t energy_scan_result_handler;
    sli_zigbee_stack_network_found_handler_ipc_event_t network_found_handler;
    sli_zigbee_stack_orphan_notification_handler_ipc_event_t orphan_notification_handler;
    sli_zigbee_stack_scan_complete_handler_ipc_event_t scan_complete_handler;
    sli_zigbee_stack_unused_pan_id_found_handler_ipc_event_t unused_pan_id_found_handler;
    sli_802154_stack_filter_match_message_handler_ipc_event_t filter_match_message_handler;
    sli_802154_stack_passthrough_message_handler_ipc_event_t passthrough_message_handler;
    sli_zigbee_stack_raw_transmit_complete_handler_ipc_event_t raw_transmit_complete_handler;
    sli_zigbee_stack_switch_network_key_handler_ipc_event_t switch_network_key_handler;
    sli_zigbee_stack_zigbee_key_establishment_handler_ipc_event_t zigbee_key_establishment_handler;
    sli_zigbee_stack_duty_cycle_handler_ipc_event_t duty_cycle_handler;
    #ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
    sli_zigbee_stack_dynamic_commissioning_alert_callback_ipc_event_t dynamic_commissioning_alert_callback;
    #endif
    #ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
    sli_zigbee_stack_beacon_survey_complete_callback_ipc_event_t beacon_survey_complete_callback;
    #endif
    #ifdef SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT
    sli_zigbee_stack_get_authentication_level_callback_ipc_event_t get_authentication_level_callback;
    sli_zigbee_stack_set_authenticaion_level_callback_ipc_event_t set_authenticaion_level_callback;
    sli_zigbee_stack_zdo_retrieve_authentication_token_complete_callback_ipc_event_t zdo_retrieve_authentication_token_complete_callback;
    #endif
    sli_zigbee_stack_stack_status_handler_ipc_event_t stack_status_handler;
    sli_zigbee_stack_stack_token_changed_handler_ipc_event_t stack_token_changed_handler;
    sli_zigbee_stack_trust_center_post_join_handler_ipc_event_t trust_center_post_join_handler;
    #ifdef SL_CATALOG_ZIGBEE_LIGHT_LINK_PRESENT
    sli_zigbee_stack_zll_address_assignment_handler_ipc_event_t zll_address_assignment_handler;
    sli_zigbee_stack_zll_network_found_handler_ipc_event_t zll_network_found_handler;
    sli_zigbee_stack_zll_scan_complete_handler_ipc_event_t zll_scan_complete_handler;
    sli_zigbee_stack_zll_touch_link_target_handler_ipc_event_t zll_touch_link_target_handler;
    #endif
  } data;
} sl_zigbee_stack_cb_event_t;

// module specific handlers

void sli_zigbee_binding_table_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_bootload_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_cbke_crypto_engine_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_child_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_high_datarate_phy_stack_interface_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_message_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_network_formation_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_raw_message_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_security_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_sl_zigbee_duty_cycle_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_sl_zigbee_dynamic_commissioning_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_sl_zigbee_zdo_management_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_sl_zigbee_zdo_security_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_stack_info_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_trust_center_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

void sli_zigbee_zll_api_process_ipc_event(sl_zigbee_stack_cb_event_t *cb_event);

extern sl_event_publisher_t sli_zigbee_ipc_publisher;
void sli_zigbee_process_stack_callbacks_event(sl_event_t *sys_event);

#endif // ZIGBEE_IPC_CALLBACK_EVENTS_H
