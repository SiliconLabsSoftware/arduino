/***************************************************************************//**
 * @file multi-network-internal-def.h
 * @brief internal names for 'multi-network' declarations
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
// automatically generated from multi-network.h.  Do not manually edit
#ifndef MULTI_NETWORK_INTERNAL_DEF_H
#define MULTI_NETWORK_INTERNAL_DEF_H

#include "stack/include/multi-network.h"

// Command Indirection

uint8_t sli_zigbee_stack_get_callback_network(void);

uint8_t sli_zigbee_stack_get_current_network(void);

sl_status_t sli_zigbee_stack_set_current_network(uint8_t index);

#endif // MULTI_NETWORK_INTERNAL_DEF_H
