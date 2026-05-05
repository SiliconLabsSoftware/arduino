/***************************************************************************//**
 * @file sl_zigbee_duty_cycle_ipc_command_messages.h
 * @brief defines structured format for 'sl_zigbee_duty_cycle' ipc messages
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
#ifndef SL_ZIGBEE_DUTY_CYCLE_IPC_COMMAND_MESSAGES_H
#define SL_ZIGBEE_DUTY_CYCLE_IPC_COMMAND_MESSAGES_H

#include "stack/include/sl_zigbee_duty_cycle.h"
#include "stack/internal/inc/sl_zigbee_duty_cycle_internal_def.h"

typedef struct {
  uint8_t maxDevices;
  sl_zigbee_per_device_duty_cycle_t arrayOfDeviceDutyCycles[SL_ZIGBEE_MAX_CHILDREN_FOR_PER_DEVICE_DUTY_CYCLE_MONITOR];
} sli_zigbee_stack_get_current_duty_cycle_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_current_duty_cycle_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_current_duty_cycle_ipc_req_t request;
  sli_zigbee_stack_get_current_duty_cycle_ipc_rsp_t response;
} sli_zigbee_stack_get_current_duty_cycle_ipc_msg_t;

typedef struct {
  sl_zigbee_duty_cycle_limits_t returnedLimits;
} sli_zigbee_stack_get_duty_cycle_limits_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_duty_cycle_limits_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_duty_cycle_limits_ipc_req_t request;
  sli_zigbee_stack_get_duty_cycle_limits_ipc_rsp_t response;
} sli_zigbee_stack_get_duty_cycle_limits_ipc_msg_t;

typedef struct {
  sl_zigbee_duty_cycle_state_t returnedState;
} sli_zigbee_stack_get_duty_cycle_state_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_duty_cycle_state_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_duty_cycle_state_ipc_req_t request;
  sli_zigbee_stack_get_duty_cycle_state_ipc_rsp_t response;
} sli_zigbee_stack_get_duty_cycle_state_ipc_msg_t;

typedef struct {
  sl_zigbee_duty_cycle_limits_t limits;
} sli_zigbee_stack_set_duty_cycle_limits_in_stack_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_duty_cycle_limits_in_stack_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_duty_cycle_limits_in_stack_ipc_req_t request;
  sli_zigbee_stack_set_duty_cycle_limits_in_stack_ipc_rsp_t response;
} sli_zigbee_stack_set_duty_cycle_limits_in_stack_ipc_msg_t;

#endif // SL_ZIGBEE_DUTY_CYCLE_IPC_COMMAND_MESSAGES_H
