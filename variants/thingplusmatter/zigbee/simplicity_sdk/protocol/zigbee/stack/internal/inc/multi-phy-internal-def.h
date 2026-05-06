/***************************************************************************//**
 * @file multi-phy-internal-def.h
 * @brief internal names for 'multi-phy' declarations
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
// automatically generated from multi-phy.h.  Do not manually edit
#ifndef MULTI_PHY_INTERNAL_DEF_H
#define MULTI_PHY_INTERNAL_DEF_H

#include "stack/include/multi-phy.h"

// Command Indirection

sl_status_t sli_zigbee_stack_multi_phy_set_radio_channel(uint8_t phyIndex,
                                                         uint8_t page,
                                                         uint8_t channel);

sl_status_t sli_zigbee_stack_multi_phy_set_radio_power(uint8_t phyIndex,
                                                       int8_t power);

sl_status_t sli_zigbee_stack_multi_phy_start(uint8_t phyIndex,
                                             uint8_t page,
                                             uint8_t channel,
                                             int8_t power,
                                             sl_zigbee_multi_phy_nwk_config_t bitmask);

sl_status_t sli_zigbee_stack_multi_phy_stop(uint8_t phyIndex);

#endif // MULTI_PHY_INTERNAL_DEF_H
