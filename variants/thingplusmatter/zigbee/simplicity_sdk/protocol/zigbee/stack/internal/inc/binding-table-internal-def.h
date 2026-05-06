/***************************************************************************//**
 * @file binding-table-internal-def.h
 * @brief internal names for 'binding-table' declarations
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
// automatically generated from binding-table.h.  Do not manually edit
#ifndef BINDING_TABLE_INTERNAL_DEF_H
#define BINDING_TABLE_INTERNAL_DEF_H

#include "stack/include/binding-table.h"

// Command Indirection

bool sli_zigbee_stack_binding_is_active(uint8_t index);

sl_status_t sli_zigbee_stack_clear_binding_table(void);

sl_status_t sli_zigbee_stack_delete_binding(uint8_t index);

sl_status_t sli_zigbee_stack_get_binding(uint8_t index,
                                         sl_zigbee_binding_table_entry_t *result);

sl_802154_short_addr_t sli_zigbee_stack_get_binding_remote_node_id(uint8_t index);

uint8_t sli_zigbee_stack_get_binding_table_size(void);

sl_status_t sli_zigbee_stack_note_senders_binding(uint8_t index,
                                                  sl_802154_short_addr_t source);

sl_status_t sli_zigbee_stack_set_binding(uint8_t index,
                                         sl_zigbee_binding_table_entry_t *value);

void sli_zigbee_stack_set_binding_remote_node_id(uint8_t index,
                                                 sl_802154_short_addr_t id);

sl_status_t sli_zigbee_stack_set_binding_table_size(uint8_t size);

sl_status_t sli_zigbee_stack_set_reply_binding(uint8_t index,
                                               sl_zigbee_binding_table_entry_t *entry,
                                               sl_802154_short_addr_t source);

// Callback Indirection

void sli_zigbee_stack_remote_delete_binding_handler(uint8_t index,
                                                    sl_zigbee_zdo_status_t status);

void sli_zigbee_stack_remote_set_binding_handler(sl_zigbee_binding_table_entry_t *entry,
                                                 sl_zigbee_zdo_status_t status);

#endif // BINDING_TABLE_INTERNAL_DEF_H
