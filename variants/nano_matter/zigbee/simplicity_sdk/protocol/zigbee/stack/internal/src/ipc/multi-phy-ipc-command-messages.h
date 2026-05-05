/***************************************************************************//**
 * @file multi-phy-ipc-command-messages.h
 * @brief defines structured format for 'multi-phy' ipc messages
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
// automatically generated from multi-phy.h.  Do not manually edit
#ifndef MULTI_PHY_IPC_COMMAND_MESSAGES_H
#define MULTI_PHY_IPC_COMMAND_MESSAGES_H

#include "stack/include/multi-phy.h"
#include "stack/internal/inc/multi-phy-internal-def.h"

typedef struct {
  uint8_t phyIndex;
  uint8_t page;
  uint8_t channel;
} sli_zigbee_stack_multi_phy_set_radio_channel_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_multi_phy_set_radio_channel_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_multi_phy_set_radio_channel_ipc_req_t request;
  sli_zigbee_stack_multi_phy_set_radio_channel_ipc_rsp_t response;
} sli_zigbee_stack_multi_phy_set_radio_channel_ipc_msg_t;

typedef struct {
  uint8_t phyIndex;
  int8_t power;
} sli_zigbee_stack_multi_phy_set_radio_power_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_multi_phy_set_radio_power_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_multi_phy_set_radio_power_ipc_req_t request;
  sli_zigbee_stack_multi_phy_set_radio_power_ipc_rsp_t response;
} sli_zigbee_stack_multi_phy_set_radio_power_ipc_msg_t;

typedef struct {
  uint8_t phyIndex;
  uint8_t page;
  uint8_t channel;
  int8_t power;
  sl_zigbee_multi_phy_nwk_config_t bitmask;
} sli_zigbee_stack_multi_phy_start_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_multi_phy_start_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_multi_phy_start_ipc_req_t request;
  sli_zigbee_stack_multi_phy_start_ipc_rsp_t response;
} sli_zigbee_stack_multi_phy_start_ipc_msg_t;

typedef struct {
  uint8_t phyIndex;
} sli_zigbee_stack_multi_phy_stop_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_multi_phy_stop_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_multi_phy_stop_ipc_req_t request;
  sli_zigbee_stack_multi_phy_stop_ipc_rsp_t response;
} sli_zigbee_stack_multi_phy_stop_ipc_msg_t;

#endif // MULTI_PHY_IPC_COMMAND_MESSAGES_H
