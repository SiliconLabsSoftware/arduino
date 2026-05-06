/***************************************************************************//**
 * @file mac-layer-internal-def.h
 * @brief internal names for 'mac-layer' declarations
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
// automatically generated from mac-layer.h.  Do not manually edit
#ifndef MAC_LAYER_INTERNAL_DEF_H
#define MAC_LAYER_INTERNAL_DEF_H

#include "stack/include/mac-layer.h"

// Command Indirection

sl_status_t sli_zigbee_stack_force_tx_after_failed_cca(uint8_t csmaAttempts);

uint8_t sli_zigbee_stack_get_max_mac_retries(void);

#endif // MAC_LAYER_INTERNAL_DEF_H
