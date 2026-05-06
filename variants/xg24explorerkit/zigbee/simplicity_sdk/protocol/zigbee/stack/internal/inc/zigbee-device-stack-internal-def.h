/***************************************************************************//**
 * @file zigbee-device-stack-internal-def.h
 * @brief internal names for 'zigbee-device-stack' declarations
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
// automatically generated from zigbee-device-stack.h.  Do not manually edit
#ifndef ZIGBEE_DEVICE_STACK_INTERNAL_DEF_H
#define ZIGBEE_DEVICE_STACK_INTERNAL_DEF_H

#include "stack/include/zigbee-device-stack.h"

// Command Indirection

sl_status_t sli_zigbee_stack_energy_scan_request(sl_802154_short_addr_t target,
                                                 uint32_t scanChannels,
                                                 uint8_t scanDuration,
                                                 uint16_t scanCount);

uint8_t sli_zigbee_stack_get_last_stack_zig_dev_request_sequence(void);

sl_status_t sli_zigbee_stack_ieee_address_request(sl_802154_short_addr_t target,
                                                  bool reportKids,
                                                  uint8_t childStartIndex,
                                                  sl_zigbee_aps_option_t options);

sl_status_t sli_zigbee_stack_ieee_address_request_to_target(sl_802154_short_addr_t discoveryNodeId,
                                                            bool reportKids,
                                                            uint8_t childStartIndex,
                                                            sl_zigbee_aps_option_t options,
                                                            sl_802154_short_addr_t targetNodeIdOfRequest);

sl_status_t sli_zigbee_stack_network_address_request(sl_802154_long_addr_t target,
                                                     bool reportKids,
                                                     uint8_t childStartIndex);

sl_status_t sli_zigbee_stack_send_device_announcement(void);

sl_status_t sli_zigbee_stack_send_parent_announcement(void);

sl_status_t sli_zigbee_stack_set_manufacturer_code(uint16_t code);

void sli_zigbee_stack_set_pending_network_update_channel(uint8_t channel);

void sli_zigbee_stack_set_zdo_configuration_mode(bool enabled);

#endif // ZIGBEE_DEVICE_STACK_INTERNAL_DEF_H
