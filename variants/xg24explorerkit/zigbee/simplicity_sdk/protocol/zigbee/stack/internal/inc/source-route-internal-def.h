/***************************************************************************//**
 * @file source-route-internal-def.h
 * @brief internal names for 'source-route' declarations
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
#ifndef SOURCE_ROUTE_INTERNAL_DEF_H
#define SOURCE_ROUTE_INTERNAL_DEF_H

#include "stack/include/source-route.h"

// Command Indirection

void sli_zigbee_stack_concentrator_note_delivery_failure(sl_zigbee_outgoing_message_type_t type,
                                                         sl_status_t status);

void sli_zigbee_stack_concentrator_note_route_error(sl_status_t status,
                                                    sl_802154_short_addr_t nodeId);

void sli_zigbee_stack_concentrator_start_discovery(void);

void sli_zigbee_stack_concentrator_stop_discovery(void);

sl_zigbee_assume_trust_center_concentrator_type_t sli_zigbee_stack_get_assumed_trust_center_concentrator_type(void);

uint8_t sli_zigbee_stack_get_source_route_overhead(sl_802154_short_addr_t destination);

sl_status_t sli_zigbee_stack_get_source_route_table_entry(uint8_t index,
                                                          sl_802154_short_addr_t *destination,
                                                          uint8_t *closerIndex);

uint8_t sli_zigbee_stack_get_source_route_table_filled_size(void);

uint8_t sli_zigbee_stack_get_source_route_table_total_size(void);

sl_status_t sli_zigbee_stack_send_many_to_one_route_request(uint16_t concentratorType,
                                                            uint8_t radius);

void sli_zigbee_stack_set_assumed_trust_center_concentrator_type(sl_zigbee_assume_trust_center_concentrator_type_t type);

sl_status_t sli_zigbee_stack_set_concentrator(bool on,
                                              uint16_t concentratorTypeParam,
                                              uint16_t minTime,
                                              uint16_t maxTime,
                                              uint8_t routeErrorThresholdParam,
                                              uint8_t deliveryFailureThresholdParam,
                                              uint8_t maxHopsParam);

uint32_t sli_zigbee_stack_set_source_route_discovery_mode(sl_zigbee_source_route_discovery_mode_t mode);

#endif // SOURCE_ROUTE_INTERNAL_DEF_H
