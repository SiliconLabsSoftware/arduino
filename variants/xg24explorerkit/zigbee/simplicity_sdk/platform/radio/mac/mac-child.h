/***************************************************************************//**
 * @file mac-child.h
 *
 * @brief MAC layer child interface
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

#ifndef MAC_CHILD_H
#define MAC_CHILD_H

#include "sl_status.h"
#include "mac-types.h"
#include "buffer_manager/buffer-management.h"

#define SL_MAC_CHILD_IS_PRESENT                             0x01
#define SL_MAC_CHILD_IS_RX_ON_WHEN_IDLE                     0x02 // Set by stack
#define SL_MAC_CHILD_HAS_PENDING_SHORT_INDIRECT_MESSAGE     0x04
#define SL_MAC_CHILD_HAS_PENDING_LONG_INDIRECT_MESSAGE      0x08
#define SL_MAC_CHILD_EXPECTING_JIT_MESSAGE                  0x10 // Set by stack
#define SL_MAC_CHILD_HAS_SECURE_DATA_REQUESTS               0x20 // Set by stack
#define SL_MAC_CHILD_INVALID_INDEX                          0xFF
// Pick out the flags that indicate that a MAC indirect message is pending.
#define SL_MAC_CHILD_HAS_PENDING_MESSAGE           \
  (SL_MAC_CHILD_HAS_PENDING_SHORT_INDIRECT_MESSAGE \
   | SL_MAC_CHILD_HAS_PENDING_LONG_INDIRECT_MESSAGE)

#define SL_MAC_MAX_CHILD_TABLE_SIZE 64

extern uint8_t sli_mac_child_table_size;

sl_status_t sli_mac_child_table_init(sl_mac_child_entry_t *childTable,
                                     uint16_t *childStatus,
                                     uint8_t childTableSize);

sl_status_t sli_mac_add_child(uint8_t macIndex,
                              uint8_t childIndex,
                              sl_802154_short_addr_t shortId,
                              sl_802154_long_addr_t longId,
                              sl_mac_child_status_flags_t info);

sl_status_t sli_mac_remove_child(uint8_t childIndex);

sl_status_t sli_mac_update_child(uint8_t macIndex,
                                 uint8_t childIndex,
                                 sl_802154_short_addr_t shortId,
                                 sl_802154_long_addr_t longId,
                                 sl_mac_child_status_flags_t info);

sl_802154_short_addr_t sli_mac_child_short_id(uint8_t childIndex);
uint8_t *sli_mac_child_long_id(uint8_t childIndex);

sl_802154_short_addr_t sli_mac_find_child_short_id(sl_802154_long_addr_t longId);
uint8_t sli_mac_child_find_long_index(uint8_t startIndex, sl_802154_long_addr_t longId);
#define sli_mac_child_find_free_index(startIndex) \
  (sli_mac_child_find_long_index((startIndex), NULL))

bool sli_mac_child_lookup_eui64_by_id(sl_802154_short_addr_t id, sl_802154_long_addr_t eui64);

// Legacy APIs sl_zigbee_child_index / emberChildLongIndex will be replaced by these
// MAC layer functions
uint8_t sli_mac_child_index(sl_802154_short_addr_t shortId);
uint8_t sli_mac_child_long_index(sl_802154_long_addr_t longId);

sl_status_t sli_mac_set_child_id(uint8_t childIndex, sl_802154_short_addr_t nodeId);
sl_status_t sli_mac_set_child_long_id(uint8_t childIndex, sl_802154_long_addr_t longId);

uint8_t sli_mac_header_outgoing_child_index(sli_zigbee_packet_header_t header);
uint8_t sli_mac_header_incoming_child_index(sli_zigbee_packet_header_t header);

bool sli_mac_child_has_pending_message(uint8_t childIndex);
bool sli_mac_child_expecting_jit_message(uint8_t childIndex);

uint8_t sli_mac_get_child_mac_index(uint8_t childIndex);
bool sli_mac_set_child_mac_index(uint8_t childIndex, uint8_t macIndex);

sl_mac_child_status_flags_t sli_mac_get_child_info_flags(uint8_t childIndex);

// Set or clear 'mask' bits for specific children.
sl_status_t sli_mac_set_child_flag(uint8_t childIndex, sl_mac_child_status_flags_t flags, bool set);

// Set or clear 'mask' bits for all sleepy children.
sl_status_t sli_mac_set_sleepy_children_flags(sl_mac_child_status_flags_t mask, bool set);

// True if any child has all of the given flags set.
bool sli_mac_check_any_child_flags(sl_mac_child_status_flags_t flags);

#define sli_mac_have_pending_jit_messages() \
  (sli_mac_check_any_child_flags(SL_MAC_CHILD_EXPECTING_JIT_MESSAGE))

#define sli_mac_have_child(childIndex) \
  (sli_mac_get_child_info_flags(childIndex) & SL_MAC_CHILD_IS_PRESENT)

#define sli_mac_child_is_sleepy(childIndex) \
  (sli_mac_have_child(childIndex)           \
   && !(sli_mac_get_child_info_flags(childIndex) & SL_MAC_CHILD_IS_RX_ON_WHEN_IDLE))

bool sli_mac_child_id_is_sleepy(sl_802154_short_addr_t id);
bool sli_mac_child_id_is_valid(sl_802154_short_addr_t id);

extern sl_mac_child_entry_t *sli_mac_child_table;
extern uint16_t *sli_mac_child_status;
#define sli_mac_change_child_table(childTable, childStatus) \
  do {                                                      \
    sli_mac_child_table = (childTable);                     \
    sli_mac_child_status = (childStatus);                   \
  } while (0)
#endif // MAC_CHILD_H
