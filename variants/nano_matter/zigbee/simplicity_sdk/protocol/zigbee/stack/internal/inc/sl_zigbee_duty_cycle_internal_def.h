/***************************************************************************//**
 * @file sl_zigbee_duty_cycle_internal_def.h
 * @brief internal names for 'sl_zigbee_duty_cycle' declarations
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
// automatically generated from sl_zigbee_duty_cycle.h.  Do not manually edit
#ifndef SL_ZIGBEE_DUTY_CYCLE_INTERNAL_DEF_H
#define SL_ZIGBEE_DUTY_CYCLE_INTERNAL_DEF_H

#include "stack/include/sl_zigbee_duty_cycle.h"

// Command Indirection

sl_status_t sli_zigbee_stack_get_current_duty_cycle(uint8_t maxDevices,
                                                    sl_zigbee_per_device_duty_cycle_t *arrayOfDeviceDutyCycles);

sl_status_t sli_zigbee_stack_get_duty_cycle_limits(sl_zigbee_duty_cycle_limits_t *returnedLimits);

sl_status_t sli_zigbee_stack_get_duty_cycle_state(sl_zigbee_duty_cycle_state_t *returnedState);

sl_status_t sli_zigbee_stack_set_duty_cycle_limits_in_stack(const sl_zigbee_duty_cycle_limits_t *limits);

// Callback Indirection

void sli_zigbee_stack_duty_cycle_handler(uint8_t channelPage,
                                         uint8_t channel,
                                         sl_zigbee_duty_cycle_state_t state,
                                         uint8_t totalDevices,
                                         sl_zigbee_per_device_duty_cycle_t *arrayOfDeviceDutyCycles);

#endif // SL_ZIGBEE_DUTY_CYCLE_INTERNAL_DEF_H
