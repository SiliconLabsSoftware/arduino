/***************************************************************************//**
 * @file aes-mmo-internal-def.h
 * @brief internal names for 'aes-mmo' declarations
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
// automatically generated from aes-mmo.h.  Do not manually edit
#ifndef AES_MMO_INTERNAL_DEF_H
#define AES_MMO_INTERNAL_DEF_H

#include "stack/include/aes-mmo.h"

// Command Indirection

sl_status_t sli_zigbee_stack_aes_hash_simple(uint8_t totalLength,
                                             const uint8_t *data,
                                             uint8_t *result);

sl_status_t sli_zigbee_stack_aes_mmo_hash_final(sl_zigbee_aes_mmo_hash_context_t *context,
                                                uint32_t length,
                                                const uint8_t *finalData);

void sli_zigbee_stack_aes_mmo_hash_init(sl_zigbee_aes_mmo_hash_context_t *context);

sl_status_t sli_zigbee_stack_aes_mmo_hash_update(sl_zigbee_aes_mmo_hash_context_t *context,
                                                 uint32_t length,
                                                 const uint8_t *data);

#endif // AES_MMO_INTERNAL_DEF_H
