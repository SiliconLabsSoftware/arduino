/***************************************************************************//**
 * @file sl_zigbee_duty_cycle_ipc_callback_events.h
 * @brief callback struct and event handlers for sl_zigbee_duty_cycle
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
#ifndef SL_ZIGBEE_DUTY_CYCLE_IPC_CALLBACK_EVENTS_H
#define SL_ZIGBEE_DUTY_CYCLE_IPC_CALLBACK_EVENTS_H

#include "stack/internal/inc/sl_zigbee_duty_cycle_internal_def.h"

typedef struct {
  uint8_t channelPage;
  uint8_t channel;
  sl_zigbee_duty_cycle_state_t state;
  uint8_t totalDevices;
  sl_zigbee_per_device_duty_cycle_t arrayOfDeviceDutyCycles[SL_ZIGBEE_MAX_CHILDREN_FOR_PER_DEVICE_DUTY_CYCLE_MONITOR];
} sli_zigbee_stack_duty_cycle_handler_ipc_event_t;

#endif // SL_ZIGBEE_DUTY_CYCLE_IPC_CALLBACK_EVENTS_H
