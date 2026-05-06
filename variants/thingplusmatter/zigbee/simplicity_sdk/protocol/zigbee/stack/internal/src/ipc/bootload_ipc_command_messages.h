/***************************************************************************//**
 * @file bootload_ipc_command_messages.h
 * @brief defines structured format for 'bootload' ipc messages
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
// automatically generated from bootload.h.  Do not manually edit
#ifndef BOOTLOAD_IPC_COMMAND_MESSAGES_H
#define BOOTLOAD_IPC_COMMAND_MESSAGES_H

#include "stack/include/bootload.h"
#include "stack/internal/inc/bootload_internal_def.h"

typedef struct {
  bool broadcast;
  sl_802154_long_addr_t destEui64;
  uint8_t messageLength;
  uint8_t messageContents;
} sli_zigbee_stack_send_bootload_message_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_send_bootload_message_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_bootload_message_ipc_req_t request;
  sli_zigbee_stack_send_bootload_message_ipc_rsp_t response;
} sli_zigbee_stack_send_bootload_message_ipc_msg_t;

#endif // BOOTLOAD_IPC_COMMAND_MESSAGES_H
