/***************************************************************************//**
 * @file security_ipc_callback_events.h
 * @brief callback struct and event handlers for security
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
// automatically generated from security.h.  Do not manually edit
#ifndef SECURITY_IPC_CALLBACK_EVENTS_H
#define SECURITY_IPC_CALLBACK_EVENTS_H

#include "stack/internal/inc/security_internal_def.h"

typedef struct {
  uint8_t sequenceNumber;
} sli_zigbee_stack_switch_network_key_handler_ipc_event_t;

typedef struct {
  sl_802154_long_addr_t partner;
  sl_zigbee_key_status_t status;
} sli_zigbee_stack_zigbee_key_establishment_handler_ipc_event_t;

#endif // SECURITY_IPC_CALLBACK_EVENTS_H
