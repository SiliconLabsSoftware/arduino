/***************************************************************************//**
 * @file multi-network-ipc-command-messages.h
 * @brief defines structured format for 'multi-network' ipc messages
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
#ifndef MULTI_NETWORK_IPC_COMMAND_MESSAGES_H
#define MULTI_NETWORK_IPC_COMMAND_MESSAGES_H

#include "stack/include/multi-network.h"
#include "stack/internal/inc/multi-network-internal-def.h"

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_callback_network_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_callback_network_ipc_rsp_t response;
} sli_zigbee_stack_get_callback_network_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_current_network_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_current_network_ipc_rsp_t response;
} sli_zigbee_stack_get_current_network_ipc_msg_t;

typedef struct {
  uint8_t index;
} sli_zigbee_stack_set_current_network_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_current_network_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_current_network_ipc_req_t request;
  sli_zigbee_stack_set_current_network_ipc_rsp_t response;
} sli_zigbee_stack_set_current_network_ipc_msg_t;

#endif // MULTI_NETWORK_IPC_COMMAND_MESSAGES_H
