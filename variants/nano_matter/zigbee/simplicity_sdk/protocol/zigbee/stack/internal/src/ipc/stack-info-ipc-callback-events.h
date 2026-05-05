/***************************************************************************//**
 * @file stack-info-ipc-callback-events.h
 * @brief callback struct and event handlers for stack-info
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
// automatically generated from stack-info.h.  Do not manually edit
#ifndef STACK_INFO_IPC_CALLBACK_EVENTS_H
#define STACK_INFO_IPC_CALLBACK_EVENTS_H

#include "stack/internal/inc/stack-info-internal-def.h"

typedef struct {
  sl_status_t status;
} sli_zigbee_stack_stack_status_handler_ipc_event_t;

typedef struct {
  uint16_t tokenAddress;
} sli_zigbee_stack_stack_token_changed_handler_ipc_event_t;

#endif // STACK_INFO_IPC_CALLBACK_EVENTS_H
