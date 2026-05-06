/***************************************************************************//**
 * @file sl_zigbee_random_api_internal_def.h
 * @brief internal names for 'sl_zigbee_random_api' declarations
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
// automatically generated from sl_zigbee_random_api.h.  Do not manually edit
#ifndef SL_ZIGBEE_RANDOM_API_INTERNAL_DEF_H
#define SL_ZIGBEE_RANDOM_API_INTERNAL_DEF_H

#include "stack/include/sl_zigbee_random_api.h"

// Command Indirection

uint16_t sli_zigbee_stack_get_pseudo_random_number(void);

sl_zigbee_entropy_source_t sli_zigbee_stack_get_strong_random_entropy_source(void);

sl_status_t sli_zigbee_stack_get_strong_random_number_array(uint16_t *randomNumber,
                                                            uint8_t count);

#endif // SL_ZIGBEE_RANDOM_API_INTERNAL_DEF_H
