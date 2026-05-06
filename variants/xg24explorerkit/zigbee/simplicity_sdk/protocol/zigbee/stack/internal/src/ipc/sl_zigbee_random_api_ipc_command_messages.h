/***************************************************************************//**
 * @file sl_zigbee_random_api_ipc_command_messages.h
 * @brief defines structured format for 'sl_zigbee_random_api' ipc messages
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
#ifndef SL_ZIGBEE_RANDOM_API_IPC_COMMAND_MESSAGES_H
#define SL_ZIGBEE_RANDOM_API_IPC_COMMAND_MESSAGES_H

#include "stack/include/sl_zigbee_random_api.h"
#include "stack/internal/inc/sl_zigbee_random_api_internal_def.h"

typedef struct {
  uint16_t result;
} sli_zigbee_stack_get_pseudo_random_number_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_pseudo_random_number_ipc_rsp_t response;
} sli_zigbee_stack_get_pseudo_random_number_ipc_msg_t;

typedef struct {
  sl_zigbee_entropy_source_t result;
} sli_zigbee_stack_get_strong_random_entropy_source_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_strong_random_entropy_source_ipc_rsp_t response;
} sli_zigbee_stack_get_strong_random_entropy_source_ipc_msg_t;

typedef struct {
  uint16_t randomNumber[MAX_IPC_VEC_ARG_CAPACITY / sizeof(uint16_t)];
  uint8_t count;
} sli_zigbee_stack_get_strong_random_number_array_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_strong_random_number_array_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_strong_random_number_array_ipc_req_t request;
  sli_zigbee_stack_get_strong_random_number_array_ipc_rsp_t response;
} sli_zigbee_stack_get_strong_random_number_array_ipc_msg_t;

#endif // SL_ZIGBEE_RANDOM_API_IPC_COMMAND_MESSAGES_H
