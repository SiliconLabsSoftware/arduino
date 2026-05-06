/***************************************************************************//**
 * @file zigbee-device-stack-ipc-command-messages.h
 * @brief defines structured format for 'zigbee-device-stack' ipc messages
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
// automatically generated from zigbee-device-stack.h.  Do not manually edit
#ifndef ZIGBEE_DEVICE_STACK_IPC_COMMAND_MESSAGES_H
#define ZIGBEE_DEVICE_STACK_IPC_COMMAND_MESSAGES_H

#include "stack/include/zigbee-device-stack.h"
#include "stack/internal/inc/zigbee-device-stack-internal-def.h"

typedef struct {
  sl_802154_short_addr_t target;
  uint32_t scanChannels;
  uint8_t scanDuration;
  uint16_t scanCount;
} sli_zigbee_stack_energy_scan_request_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_energy_scan_request_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_energy_scan_request_ipc_req_t request;
  sli_zigbee_stack_energy_scan_request_ipc_rsp_t response;
} sli_zigbee_stack_energy_scan_request_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_last_stack_zig_dev_request_sequence_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_last_stack_zig_dev_request_sequence_ipc_rsp_t response;
} sli_zigbee_stack_get_last_stack_zig_dev_request_sequence_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t target;
  bool reportKids;
  uint8_t childStartIndex;
  sl_zigbee_aps_option_t options;
} sli_zigbee_stack_ieee_address_request_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_ieee_address_request_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_ieee_address_request_ipc_req_t request;
  sli_zigbee_stack_ieee_address_request_ipc_rsp_t response;
} sli_zigbee_stack_ieee_address_request_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t discoveryNodeId;
  bool reportKids;
  uint8_t childStartIndex;
  sl_zigbee_aps_option_t options;
  sl_802154_short_addr_t targetNodeIdOfRequest;
} sli_zigbee_stack_ieee_address_request_to_target_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_ieee_address_request_to_target_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_ieee_address_request_to_target_ipc_req_t request;
  sli_zigbee_stack_ieee_address_request_to_target_ipc_rsp_t response;
} sli_zigbee_stack_ieee_address_request_to_target_ipc_msg_t;

typedef struct {
  sl_802154_long_addr_t target;
  bool reportKids;
  uint8_t childStartIndex;
} sli_zigbee_stack_network_address_request_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_network_address_request_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_network_address_request_ipc_req_t request;
  sli_zigbee_stack_network_address_request_ipc_rsp_t response;
} sli_zigbee_stack_network_address_request_ipc_msg_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_send_device_announcement_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_device_announcement_ipc_rsp_t response;
} sli_zigbee_stack_send_device_announcement_ipc_msg_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_send_parent_announcement_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_parent_announcement_ipc_rsp_t response;
} sli_zigbee_stack_send_parent_announcement_ipc_msg_t;

typedef struct {
  uint16_t code;
} sli_zigbee_stack_set_manufacturer_code_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_manufacturer_code_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_manufacturer_code_ipc_req_t request;
  sli_zigbee_stack_set_manufacturer_code_ipc_rsp_t response;
} sli_zigbee_stack_set_manufacturer_code_ipc_msg_t;

typedef struct {
  uint8_t channel;
} sli_zigbee_stack_set_pending_network_update_channel_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_pending_network_update_channel_ipc_req_t request;
} sli_zigbee_stack_set_pending_network_update_channel_ipc_msg_t;

typedef struct {
  bool enabled;
} sli_zigbee_stack_set_zdo_configuration_mode_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_zdo_configuration_mode_ipc_req_t request;
} sli_zigbee_stack_set_zdo_configuration_mode_ipc_msg_t;

#endif // ZIGBEE_DEVICE_STACK_IPC_COMMAND_MESSAGES_H
