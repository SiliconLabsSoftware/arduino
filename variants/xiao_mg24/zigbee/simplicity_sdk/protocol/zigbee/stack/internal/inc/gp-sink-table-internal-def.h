/***************************************************************************//**
 * @file gp-sink-table-internal-def.h
 * @brief internal names for 'gp-sink-table' declarations
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
// automatically generated from gp-sink-table.h.  Do not manually edit
#ifndef GP_SINK_TABLE_INTERNAL_DEF_H
#define GP_SINK_TABLE_INTERNAL_DEF_H

#include "stack/include/gp-sink-table.h"

// Command Indirection

void sli_zigbee_stack_gp_sink_table_add_group(uint8_t index,
                                              uint16_t sinkGroupId,
                                              uint16_t assignedAlias);

void sli_zigbee_stack_gp_sink_table_clear_all(void);

uint8_t sli_zigbee_stack_gp_sink_table_entry_in_use(uint8_t sinkTableIndex);

uint8_t sli_zigbee_stack_gp_sink_table_find_or_allocate_entry(sl_zigbee_gp_address_t *addr);

sl_status_t sli_zigbee_stack_gp_sink_table_get_entry(uint8_t sinkTableIndex,
                                                     sl_zigbee_gp_sink_table_entry_t *entry);

uint8_t sli_zigbee_stack_gp_sink_table_get_free_entry_index(void);

uint8_t sli_zigbee_stack_gp_sink_table_get_number_of_active_entries(void);

void sli_zigbee_stack_gp_sink_table_init(void);

uint8_t sli_zigbee_stack_gp_sink_table_lookup(sl_zigbee_gp_address_t *addr);

void sli_zigbee_stack_gp_sink_table_remove_entry(uint8_t index);

bool sli_zigbee_stack_gp_sink_table_remove_group(uint8_t index,
                                                 uint16_t sinkGroupId,
                                                 uint16_t assignedAlias);

sl_status_t sli_zigbee_stack_gp_sink_table_set_entry(uint8_t sinkTableIndex,
                                                     sl_zigbee_gp_sink_table_entry_t *entry);

void sli_zigbee_stack_gp_sink_table_set_security_frame_counter(uint8_t index,
                                                               uint32_t sfc);

#endif // GP_SINK_TABLE_INTERNAL_DEF_H
