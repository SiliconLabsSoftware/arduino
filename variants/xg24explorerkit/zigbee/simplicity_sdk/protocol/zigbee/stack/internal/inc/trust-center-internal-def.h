/***************************************************************************//**
 * @file trust-center-internal-def.h
 * @brief internal names for 'trust-center' declarations
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
// automatically generated from trust-center.h.  Do not manually edit
#ifndef TRUST_CENTER_INTERNAL_DEF_H
#define TRUST_CENTER_INTERNAL_DEF_H

#include "stack/include/trust-center.h"

// Command Indirection

sl_status_t sli_zigbee_stack_broadcast_network_key_switch(void);

sl_status_t sli_zigbee_stack_broadcast_next_network_key(sl_zigbee_key_data_t *key);

sl_zigbee_app_link_key_request_policy_t sli_zigbee_stack_get_app_link_key_request_policy(void);

uint16_t sli_zigbee_stack_get_transient_device_table_timeout_ms(void);

sl_zigbee_tc_link_key_request_policy_t sli_zigbee_stack_get_trust_center_link_key_request_policy(void);

sl_status_t sli_zigbee_stack_send_remove_device(sl_802154_short_addr_t destShort,
                                                sl_802154_long_addr_t destLong,
                                                sl_802154_long_addr_t deviceToRemoveLong);

sl_status_t sli_zigbee_stack_send_trust_center_link_key(sl_802154_short_addr_t destinationNodeId,
                                                        sl_802154_long_addr_t destinationEui64);

sl_status_t sli_zigbee_stack_send_unicast_network_key_update(sl_802154_short_addr_t targetShort,
                                                             sl_802154_long_addr_t targetLong,
                                                             const sl_zigbee_key_data_t *newKey);

void sli_zigbee_stack_set_app_link_key_request_policy(sl_zigbee_app_link_key_request_policy_t policy);

sl_status_t sli_zigbee_stack_set_transient_device_table_timeout_ms(uint16_t timeout);

void sli_zigbee_stack_set_trust_center_link_key_request_policy(sl_zigbee_tc_link_key_request_policy_t policy);

sl_status_t sli_zigbee_stack_unicast_current_network_key(sl_802154_short_addr_t targetShort,
                                                         sl_802154_long_addr_t targetLong,
                                                         sl_802154_short_addr_t parentShortId);

// Callback Indirection

void sli_zigbee_stack_trust_center_post_join_handler(sl_802154_short_addr_t newNodeId,
                                                     sl_802154_long_addr_t newNodeEui64,
                                                     sl_zigbee_device_update_t status,
                                                     sl_zigbee_join_decision_t policyDecision,
                                                     sl_802154_short_addr_t parentOfNewNode);

#endif // TRUST_CENTER_INTERNAL_DEF_H
