/***************************************************************************//**
 * @file binding-table-ipc-callback-events.h
 * @brief callback struct and event handlers for binding-table
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
// automatically generated from binding-table.h.  Do not manually edit
#ifndef BINDING_TABLE_IPC_CALLBACK_EVENTS_H
#define BINDING_TABLE_IPC_CALLBACK_EVENTS_H

#include "stack/internal/inc/binding-table-internal-def.h"

typedef struct {
  uint8_t index;
  sl_zigbee_zdo_status_t status;
} sli_zigbee_stack_remote_delete_binding_handler_ipc_event_t;

typedef struct {
  sl_zigbee_binding_table_entry_t entry;
  sl_zigbee_zdo_status_t status;
} sli_zigbee_stack_remote_set_binding_handler_ipc_event_t;

#endif // BINDING_TABLE_IPC_CALLBACK_EVENTS_H
