/***************************************************************************//**
 * @file gp-types-internal-def.h
 * @brief internal names for 'gp-types' declarations
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
// automatically generated from gp-types.h.  Do not manually edit
#ifndef GP_TYPES_INTERNAL_DEF_H
#define GP_TYPES_INTERNAL_DEF_H

#include "stack/include/gp-types.h"

// Command Indirection

sl_status_t sli_zigbee_stack_d_gp_send(bool action,
                                       bool useCca,
                                       sl_zigbee_gp_address_t *addr,
                                       uint8_t gpdCommandId,
                                       uint8_t gpdAsduLength,
                                       const uint8_t *gpdAsdu,
                                       uint8_t gpepHandle,
                                       uint16_t gpTxQueueEntryLifetimeMs);

uint16_t sli_zigbee_stack_get_gp_max_tx_q_list_count(void);

uint16_t sli_zigbee_stack_get_gp_tx_q_list_count(void);

sli_buffer_manager_buffer_t sli_zigbee_stack_gp_add_gp_tx_queue_entry_with_payload(sl_zigbee_gp_tx_queue_entry_t *txQueue,
                                                                                   uint8_t *data,
                                                                                   uint16_t dataLength);

void sli_zigbee_stack_gp_clear_tx_queue(void);

sli_buffer_manager_buffer_t sli_zigbee_stack_gp_get_tx_queue_entry_from_queue(sl_zigbee_gp_tx_queue_entry_t *txQueue,
                                                                              uint8_t *data,
                                                                              uint16_t *dataLength,
                                                                              uint16_t allocatedDataLength);

sl_status_t sli_zigbee_stack_gp_get_tx_queue_entry_from_queue_index(uint8_t index,
                                                                    sl_zigbee_gp_tx_queue_entry_t *txQueue,
                                                                    uint8_t *payload,
                                                                    uint16_t *payload_len);

sli_zigbee_message_buffer_queue_t * sli_zigbee_stack_gp_get_tx_queue_head(void);

bool sli_zigbee_stack_gp_remove_from_tx_queue(sl_zigbee_gp_tx_queue_entry_t *txQueue);

void sli_zigbee_stack_gp_set_max_tx_queue_entry(uint16_t maxEntries);

#endif // GP_TYPES_INTERNAL_DEF_H
