/***************************************************************************//**
 * @file child_ipc_callback_events.h
 * @brief callback struct and event handlers for child
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
// automatically generated from child.h.  Do not manually edit
#ifndef CHILD_IPC_CALLBACK_EVENTS_H
#define CHILD_IPC_CALLBACK_EVENTS_H

#include "stack/internal/inc/child_internal_def.h"

typedef struct {
  uint8_t index;
  bool joining;
  sl_802154_short_addr_t childId;
  sl_802154_long_addr_t childEui64;
  sl_zigbee_node_type_t childType;
} sli_zigbee_stack_child_join_handler_ipc_event_t;

typedef struct {
  sl_status_t status;
} sli_zigbee_stack_poll_complete_handler_ipc_event_t;

typedef struct {
  sl_802154_short_addr_t childId;
  bool transmitExpected;
} sli_zigbee_stack_poll_handler_ipc_event_t;

#endif // CHILD_IPC_CALLBACK_EVENTS_H
