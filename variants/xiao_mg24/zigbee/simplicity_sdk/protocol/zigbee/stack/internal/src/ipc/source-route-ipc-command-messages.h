/***************************************************************************//**
 * @file source-route-ipc-command-messages.h
 * @brief defines structured format for 'source-route' ipc messages
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
// automatically generated from source-route.h.  Do not manually edit
#ifndef SOURCE_ROUTE_IPC_COMMAND_MESSAGES_H
#define SOURCE_ROUTE_IPC_COMMAND_MESSAGES_H

#include "stack/include/source-route.h"
#include "stack/internal/inc/source-route-internal-def.h"

typedef struct {
  sl_zigbee_outgoing_message_type_t type;
  sl_status_t status;
} sli_zigbee_stack_concentrator_note_delivery_failure_ipc_req_t;

typedef struct {
  sli_zigbee_stack_concentrator_note_delivery_failure_ipc_req_t request;
} sli_zigbee_stack_concentrator_note_delivery_failure_ipc_msg_t;

typedef struct {
  sl_status_t status;
  sl_802154_short_addr_t nodeId;
} sli_zigbee_stack_concentrator_note_route_error_ipc_req_t;

typedef struct {
  sli_zigbee_stack_concentrator_note_route_error_ipc_req_t request;
} sli_zigbee_stack_concentrator_note_route_error_ipc_msg_t;

typedef struct {
  sl_zigbee_assume_trust_center_concentrator_type_t result;
} sli_zigbee_stack_get_assumed_trust_center_concentrator_type_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_assumed_trust_center_concentrator_type_ipc_rsp_t response;
} sli_zigbee_stack_get_assumed_trust_center_concentrator_type_ipc_msg_t;

typedef struct {
  sl_802154_short_addr_t destination;
} sli_zigbee_stack_get_source_route_overhead_ipc_req_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_source_route_overhead_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_source_route_overhead_ipc_req_t request;
  sli_zigbee_stack_get_source_route_overhead_ipc_rsp_t response;
} sli_zigbee_stack_get_source_route_overhead_ipc_msg_t;

typedef struct {
  uint8_t index;
  sl_802154_short_addr_t destination;
  uint8_t closerIndex;
} sli_zigbee_stack_get_source_route_table_entry_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_get_source_route_table_entry_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_source_route_table_entry_ipc_req_t request;
  sli_zigbee_stack_get_source_route_table_entry_ipc_rsp_t response;
} sli_zigbee_stack_get_source_route_table_entry_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_source_route_table_filled_size_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_source_route_table_filled_size_ipc_rsp_t response;
} sli_zigbee_stack_get_source_route_table_filled_size_ipc_msg_t;

typedef struct {
  uint8_t result;
} sli_zigbee_stack_get_source_route_table_total_size_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_get_source_route_table_total_size_ipc_rsp_t response;
} sli_zigbee_stack_get_source_route_table_total_size_ipc_msg_t;

typedef struct {
  uint16_t concentratorType;
  uint8_t radius;
} sli_zigbee_stack_send_many_to_one_route_request_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_send_many_to_one_route_request_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_send_many_to_one_route_request_ipc_req_t request;
  sli_zigbee_stack_send_many_to_one_route_request_ipc_rsp_t response;
} sli_zigbee_stack_send_many_to_one_route_request_ipc_msg_t;

typedef struct {
  sl_zigbee_assume_trust_center_concentrator_type_t type;
} sli_zigbee_stack_set_assumed_trust_center_concentrator_type_ipc_req_t;

typedef struct {
  sli_zigbee_stack_set_assumed_trust_center_concentrator_type_ipc_req_t request;
} sli_zigbee_stack_set_assumed_trust_center_concentrator_type_ipc_msg_t;

typedef struct {
  bool on;
  uint16_t concentratorTypeParam;
  uint16_t minTime;
  uint16_t maxTime;
  uint8_t routeErrorThresholdParam;
  uint8_t deliveryFailureThresholdParam;
  uint8_t maxHopsParam;
} sli_zigbee_stack_set_concentrator_ipc_req_t;

typedef struct {
  sl_status_t result;
} sli_zigbee_stack_set_concentrator_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_concentrator_ipc_req_t request;
  sli_zigbee_stack_set_concentrator_ipc_rsp_t response;
} sli_zigbee_stack_set_concentrator_ipc_msg_t;

typedef struct {
  sl_zigbee_source_route_discovery_mode_t mode;
} sli_zigbee_stack_set_source_route_discovery_mode_ipc_req_t;

typedef struct {
  uint32_t result;
} sli_zigbee_stack_set_source_route_discovery_mode_ipc_rsp_t;

typedef struct {
  sli_zigbee_stack_set_source_route_discovery_mode_ipc_req_t request;
  sli_zigbee_stack_set_source_route_discovery_mode_ipc_rsp_t response;
} sli_zigbee_stack_set_source_route_discovery_mode_ipc_msg_t;

#endif // SOURCE_ROUTE_IPC_COMMAND_MESSAGES_H
