/***************************************************************************//**
 * @file gp-proxy-table-internal-def.h
 * @brief internal names for 'gp-proxy-table' declarations
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
// automatically generated from gp-proxy-table.h.  Do not manually edit
#ifndef GP_PROXY_TABLE_INTERNAL_DEF_H
#define GP_PROXY_TABLE_INTERNAL_DEF_H

#include "stack/include/gp-proxy-table.h"

// Command Indirection

sl_status_t sli_zigbee_stack_gp_proxy_table_get_entry(uint8_t proxyIndex,
                                                      sl_zigbee_gp_proxy_table_entry_t *entry);

uint8_t sli_zigbee_stack_gp_proxy_table_lookup(sl_zigbee_gp_address_t *addr);

bool sli_zigbee_stack_gp_proxy_table_process_gp_pairing(uint32_t options,
                                                        sl_zigbee_gp_address_t *addr,
                                                        uint8_t commMode,
                                                        uint16_t sinkNwkAddress,
                                                        uint16_t sinkGroupId,
                                                        uint16_t assignedAlias,
                                                        uint8_t *sinkIeeeAddress,
                                                        sl_zigbee_key_data_t *gpdKey,
                                                        uint32_t gpdSecurityFrameCounter,
                                                        uint8_t forwardingRadius);

#endif // GP_PROXY_TABLE_INTERNAL_DEF_H
