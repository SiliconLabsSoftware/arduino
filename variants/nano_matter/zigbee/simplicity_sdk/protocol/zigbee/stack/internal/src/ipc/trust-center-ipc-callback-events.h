/***************************************************************************//**
 * @file trust-center-ipc-callback-events.h
 * @brief callback struct and event handlers for trust-center
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
// automatically generated from trust-center.h.  Do not manually edit
#ifndef TRUST_CENTER_IPC_CALLBACK_EVENTS_H
#define TRUST_CENTER_IPC_CALLBACK_EVENTS_H

#include "stack/internal/inc/trust-center-internal-def.h"

typedef struct {
  sl_802154_short_addr_t newNodeId;
  sl_802154_long_addr_t newNodeEui64;
  sl_zigbee_device_update_t status;
  sl_zigbee_join_decision_t policyDecision;
  sl_802154_short_addr_t parentOfNewNode;
} sli_zigbee_stack_trust_center_post_join_handler_ipc_event_t;

#endif // TRUST_CENTER_IPC_CALLBACK_EVENTS_H
