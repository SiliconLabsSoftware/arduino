/***************************************************************************//**
 * @file child_internal_def.h
 * @brief internal names for 'child' declarations
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
// automatically generated from child.h.  Do not manually edit
#ifndef CHILD_INTERNAL_DEF_H
#define CHILD_INTERNAL_DEF_H

#include "stack/include/child.h"

// Command Indirection

sl_status_t sli_zigbee_stack_add_child(sl_802154_short_addr_t shortId,
                                       sl_802154_long_addr_t longId,
                                       sl_zigbee_node_type_t nodeType);

uint8_t sli_zigbee_stack_child_count(void);

sl_802154_short_addr_t sli_zigbee_stack_child_id(uint8_t childIndex);

uint8_t sli_zigbee_stack_child_index(sl_802154_short_addr_t childId);

int8_t sli_zigbee_stack_child_power(uint8_t childIndex);

sl_status_t sli_zigbee_stack_clear_message_flag(sl_802154_short_addr_t childId);

uint16_t sli_zigbee_stack_current_stack_tasks(void);

int8_t sli_zigbee_stack_get_avg_parent_rssi(void);

sl_status_t sli_zigbee_stack_get_child_data(uint8_t index,
                                            sl_zigbee_child_data_t *childData);

sl_zigbee_keep_alive_mode_t sli_zigbee_stack_get_keep_alive_mode(void);

uint8_t sli_zigbee_stack_get_max_end_device_children(void);

uint8_t * sli_zigbee_stack_get_parent_eui64(void);

sl_802154_short_addr_t sli_zigbee_stack_get_parent_id(void);

uint32_t sli_zigbee_stack_get_parent_incoming_nwk_frame_counter(void);

sl_802154_short_addr_t sli_zigbee_stack_get_parent_node_id(void);

bool sli_zigbee_stack_parent_token_set(void);

sl_status_t sli_zigbee_stack_poll_for_data(void);

sl_status_t sli_zigbee_stack_remove_child(sl_802154_long_addr_t childEui64);

void sli_zigbee_stack_remove_neighbor(sl_802154_short_addr_t shortId,
                                      sl_802154_long_addr_t longId);

sl_status_t sli_zigbee_stack_send_link_power_delta_request(void);

sl_status_t sli_zigbee_stack_set_child_data(uint8_t index,
                                            const sl_zigbee_child_data_t *childData);

void sli_zigbee_stack_set_child_power(uint8_t childIndex,
                                      int8_t newPower);

sl_status_t sli_zigbee_stack_set_child_timeout_option_mask(uint16_t mask);

sl_status_t sli_zigbee_stack_set_keep_alive_mode(sl_zigbee_keep_alive_mode_t mode);

void sli_zigbee_stack_set_mac_poll_failure_wait_time(uint32_t waitBeforeRetryIntervalMs);

sl_status_t sli_zigbee_stack_set_max_end_device_children(uint8_t max);

sl_status_t sli_zigbee_stack_set_message_flag(sl_802154_short_addr_t childId);

sl_status_t sli_zigbee_stack_set_parent_incoming_nwk_frame_counter(uint32_t value);

void sli_zigbee_stack_stack_power_down(void);

void sli_zigbee_stack_stack_power_up(void);

// Callback Indirection

void sli_zigbee_stack_child_join_handler(uint8_t index,
                                         bool joining,
                                         sl_802154_short_addr_t childId,
                                         sl_802154_long_addr_t childEui64,
                                         sl_zigbee_node_type_t childType);

void sli_zigbee_stack_poll_complete_handler(sl_status_t status);

void sli_zigbee_stack_poll_handler(sl_802154_short_addr_t childId,
                                   bool transmitExpected);

#endif // CHILD_INTERNAL_DEF_H
