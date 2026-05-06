/***************************************************************************//**
 * @file
 * @brief Zigbee GP sink definitions used by the framework and stack.
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

#ifndef _GP_SINK_TABLE_
#define _GP_SINK_TABLE_

#include "sl_zigbee_types.h"
#include "gp-types.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef __cplusplus
extern "C" {
#endif
#endif // DOXYGEN_SHOULD_SKIP_THIS

/**
 * @addtogroup gp_sink_table
 *
 * This file describes APIs for Zigbee Green Power Sink Table functionality.
 *
 * @{
 */

/******************************************************************************
 * @brief @brief Clear the sink table
 *
 * @return void
 *
 *****************************************************************************/
void sl_zigbee_gp_sink_table_clear_all(void);

/******************************************************************************
 * @brief Initialize the sink table entries in the sink table.
 *
 * @return void
 *
 * @details This function initializes the sink table in RAM. It copies the non-volatile sink table entries to
 *          a RAM table which is used during operation. By design,the non-volatile token entry for the sink table
 *          are compressed and does not hold the data that can be derived. This function is only called during
 *          initialization of the green power stack to initialize the entire table with derived data.
 *****************************************************************************/
void sl_zigbee_gp_sink_table_init(void);

/******************************************************************************
 * @brief Add a sink table entry for a given index.
 *
 * @param sinkIndex This is the proxy / combo table index for the new entry
 * @param entry This is a pointer to the sink table data to add. If 0
 *              the entry at the specified indexis set to unused.
 * @return A valid error code.
 *
 * @details If the entry parameter is set to 0, the entry is set to
 *          SL_ZIGBEE_GP_SINK_TABLE_ENTRY_STATUS_UNUSED. Otherwise the entry is set
 *          to the value pointed at by entry and SL_STATUS_OK returned.
 *****************************************************************************/
sl_status_t sl_zigbee_gp_sink_table_set_entry(uint8_t sinkTableIndex,
                                              sl_zigbee_gp_sink_table_entry_t *entry);

/**************************************************************************//**
 * @brief Fetch the sink table entry at the given index.
 *
 * @param sinkIndex This is the proxy / combo table index for the entry
 * @param entry This is a pointer to the buffer where the entry is to be copied
 * @return A valid error code.
 *****************************************************************************/
sl_status_t sl_zigbee_gp_sink_table_get_entry(uint8_t sinkTableIndex,
                                              sl_zigbee_gp_sink_table_entry_t *entry);

/******************************************************************************
 * @brief Determine if an entry is currently an active sink entry.
 *
 * @param sinkTableIndex The index to an entry in the sink / combo table
 * @return  0xFF if the index is invalid or contains a proxy table entry.
 *          If a sink table entry is present at the given index 0 (true) is
 *          returned else 1 (false) is returned.
 *****************************************************************************/
uint8_t sl_zigbee_gp_sink_table_entry_in_use(uint8_t sinkTableIndex);

/**************************************************************************//**
 * @brief Return the index of the first free table entry.
 *
 * @return  0xFF if no free entry exists, else a value within the table's
 *          maximum size.
 *****************************************************************************/
uint8_t sl_zigbee_gp_sink_table_get_free_entry_index(void);

/******************************************************************************
 * @brief Find the sink table entry which matches the address of the GPD device
 * supplied. If the entry is not found, create a sink entry.
 *
 * @param addr Pointer containing the GPD address to match
 * @returns The index of a unused entry or one that contains the address
 *                 passed in. If the address cannot be matched and a free entry
 *                 cannot be found, 0xFF is returned.
 *****************************************************************************/
uint8_t sl_zigbee_gp_sink_table_find_or_allocate_entry(sl_zigbee_gp_address_t *addr);

/******************************************************************************
 * @brief Add a sink group entry for a given index.
 *
 * @param index The proxy / combo table index for the entry
 * @param sinkGroupId ID of the group to add to the sink list
 * @param assignedAlias Alias of the group to add.
 * @return void
 *
 * @details For a given index, the entry in the proxy/combo table is accessed.
 *          If it is an illegal index or a proxy entry, this function returns
 *          with no action. If the groupId, alias pair already exist, this
 *          function returns with no action.
 *          Else, the entry is added to an unused slot in the sink group list,
 *          and the entry is then written to non volatile storage.
 *****************************************************************************/
void sl_zigbee_gp_sink_table_add_group(uint8_t index,
                                       uint16_t sinkGroupId,
                                       uint16_t assignedAlias);

/******************************************************************************
 * @bief Remove a sink group entry for a given index.
 *
 * @param index The proxy / combo table index for the entry
 * @param sinkGroupId This is the ID of the group to remove from the sink list
 * @param assignedAlias this is the alias of the group to remove.
 * @return true if the entry is removed, else false if it cannot be found.
 *****************************************************************************/
bool sl_zigbee_gp_sink_table_remove_group(uint8_t index,
                                          uint16_t sinkGroupId,
                                          uint16_t assignedAlias);

/******************************************************************************
 * @brief Find the sink table entry which matches the address
 * of the GPD device supplied and, if found, return the index of that entry.
 *
 * @param addr Pointer to the address to match.
 * @return The index of the entry that contains the address passed in. If the
 *  address cannot be matched, 0xFF is returned.
 *****************************************************************************/
uint8_t sl_zigbee_gp_sink_table_lookup(sl_zigbee_gp_address_t *addr);

/**************************************************************************//**
 * @brief Remove a sink table entry by setting the entry to unused.
 *
 * @param index This is the sink table index of the entry to be removed. If
 *  index is 0xFF, all entries are removed.
 *
 * @returns void
 *****************************************************************************/
void sl_zigbee_gp_sink_table_remove_entry(uint8_t index);

/******************************************************************************
 * @brief Set the security frame counter in the sink table.
 *
 * @param index Index to the sink table
 * @param scf Security frame counter
 * @return void
 *****************************************************************************/
void sl_zigbee_gp_sink_table_set_security_frame_counter(uint8_t index,
                                                        uint32_t sfc);

/******************************************************************************
 * @brief Fetch the number of active entries in sink table.
 *
 * @returns Number of active entries in sink table.
 *
 *****************************************************************************/
uint8_t sl_zigbee_gp_sink_table_get_number_of_active_entries(void);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#ifdef __cplusplus
}
#endif
#endif // DOXYGEN_SHOULD_SKIP_THIS

/** @} END addtogroup */

#endif // _GP_SINK_TABLE_
