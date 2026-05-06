/***************************************************************************//**
 * @file mac-layer-ipc-command-messages.h
 * @brief defines structured format for 'mac-layer' ipc messages
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
// automatically generated from mac-layer.h.  Do not manually edit
#ifndef MAC_LAYER_IPC_COMMAND_MESSAGES_H
#define MAC_LAYER_IPC_COMMAND_MESSAGES_H

#include "stack/include/mac-layer.h"
#include "stack/internal/inc/mac-layer-internal-def.h"

typedef struct {
  uint8_t csmaAttempts;
} sli_zigbee_stack_force_tx_after_failed_cca_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_force_tx_after_failed_cca_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_force_tx_after_failed_cca_ipc_req_t request;
  sli_zigbee_stack_force_tx_after_failed_cca_ipc_rsp_t response;
} sli_zigbee_stack_force_tx_after_failed_cca_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_max_mac_retries_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_max_mac_retries_ipc_rsp_t response;
} sli_zigbee_stack_get_max_mac_retries_ipc_msg_t;

#endif // MAC_LAYER_IPC_COMMAND_MESSAGES_H
