/***************************************************************************//**
 * @file
 * @brief Zigbee GP token definitions used by the stack.
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef _GP_PROXY_TABLE_H_
#define _GP_PROXY_TABLE_H_

#include "sl_zigbee_types.h"
#include "gp-types.h"

/**
 * @addtogroup gp_proxy_table
 *
 * This file describes APIs for Zigbee Green Power Proxy Table functionality.
 *
 * @{
 */

/** @brief Get Proxy table entry
 *
 * This function gets an entry from proxy table at the supplied index.
 *
 * @param proxyIndex a valid index to proxy table.
 * @param entry proxy table entry
 *
 * @return An ::sl_status_t as status.
 */
sl_status_t sl_zigbee_gp_proxy_table_get_entry(uint8_t proxyIndex,
                                               sl_zigbee_gp_proxy_table_entry_t *entry);

/** @brief Proxy table look up
 *
 * This function looks up a gpd address in the Gp Proxy Table and returns index of the entry.
 *
 * @param addr The gpd address ::sl_zigbee_gp_address_t to look up.
 *
 * @return a valid index to the entry in proxy table and 0xFF in case of not found.
 */
uint8_t sl_zigbee_gp_proxy_table_lookup(sl_zigbee_gp_address_t *addr);

/** @brief Process Gp Pairing
 *
 * This function adds or updates the entry in the proxy table as part of Gp Pairing command processing.
 * All the input arguments for this API is derived directly from the incoming GP Pairing command
 *
 * @param options option field of the Gp Pairing command, this holds the validity of other inputs.
 * @param addr The gpd address ::sl_zigbee_gp_address_t.
 * @param commMode Communication mode as supplied in the Gp Pairing command.
 * @param sinkNwkAddress Network address of the sink.
 * @param sinkGroupId Group Id of the sink.
 * @param assignedAlias Assigned alias for the GPD under commissioning.
 * @param sinkIeeeAddress sink EUI64 address
 * @param gpdKey GPD key
 * @param gpdSecurityFrameCounter security frame counter from GPD.
 * @param forwardingRadius forwarding radius
 *
 * @return true on success and false for failure.
 */
bool sl_zigbee_gp_proxy_table_process_gp_pairing(uint32_t options,
                                                 sl_zigbee_gp_address_t* addr,
                                                 uint8_t commMode,
                                                 uint16_t sinkNwkAddress,
                                                 uint16_t sinkGroupId,
                                                 uint16_t assignedAlias,
                                                 uint8_t* sinkIeeeAddress,
                                                 sl_zigbee_key_data_t *gpdKey,
                                                 uint32_t gpdSecurityFrameCounter,
                                                 uint8_t forwardingRadius);

/** @} END addtogroup */

#endif // _GP_PROXY_TABLE_H_
