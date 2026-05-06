/***************************************************************************//**
 * @file raw-message-internal-def.h
 * @brief internal names for 'raw-message' declarations
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
// automatically generated from raw-message.h.  Do not manually edit
#ifndef RAW_MESSAGE_INTERNAL_DEF_H
#define RAW_MESSAGE_INTERNAL_DEF_H

#include "stack/include/raw-message.h"

// Command Indirection

sl_802154_short_addr_t sli_zigbee_stack_get_embernet_passthrough_source_address(void);

sl_zigbee_mac_passthrough_type_t sli_zigbee_stack_get_mac_passthrough_flags(void);

sl_status_t sli_zigbee_stack_send_raw_message(const uint8_t *message,
                                              uint8_t message_length,
                                              sl_zigbee_transmit_priority_t priority,
                                              bool useCca);

void sli_zigbee_stack_set_embernet_passthrough_source_address(sl_802154_short_addr_t address);

sl_status_t sli_zigbee_stack_set_mac_filter_match_list(const sl_zigbee_mac_filter_match_data_t *macFilterMatchList,
                                                       uint8_t listLength);

void sli_zigbee_stack_set_mac_passthrough_flags(sl_zigbee_mac_passthrough_type_t type);

// Callback Indirection

void sli_802154_stack_filter_match_message_handler(uint8_t filterIndexMatch,
                                                   uint8_t legacyPassthroughType,
                                                   sl_zigbee_rx_packet_info_t *packetInfo,
                                                   uint8_t messageLength,
                                                   uint8_t *messageContents);

void sli_802154_stack_passthrough_message_handler(sl_zigbee_mac_passthrough_type_t messageType,
                                                  sl_zigbee_rx_packet_info_t *packetInfo,
                                                  uint8_t messageLength,
                                                  uint8_t *messageContents);

void sli_zigbee_stack_raw_transmit_complete_handler(uint8_t message,
                                                    uint8_t *messageContents,
                                                    sl_status_t status);

#endif // RAW_MESSAGE_INTERNAL_DEF_H
