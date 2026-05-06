/***************************************************************************//**
 * @file library_ipc_command_messages.h
 * @brief defines structured format for 'library' ipc messages
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
// automatically generated from library.h.  Do not manually edit
#ifndef LIBRARY_IPC_COMMAND_MESSAGES_H
#define LIBRARY_IPC_COMMAND_MESSAGES_H

#include "stack/include/library.h"
#include "stack/internal/inc/library_internal_def.h"

typedef struct {
  sl_zigbee_library_id_t libraryId;
} sli_zigbee_stack_get_library_status_ipc_req_t;

typedef struct {
  sl_zigbee_library_status_t result;
} sli_zigbee_stack_get_library_status_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_library_status_ipc_req_t request;
  sli_zigbee_stack_get_library_status_ipc_rsp_t response;
} sli_zigbee_stack_get_library_status_ipc_msg_t;

#endif // LIBRARY_IPC_COMMAND_MESSAGES_H
