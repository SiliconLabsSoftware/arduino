/***************************************************************************//**
 * @file mac-types.h
 * @brief
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef MAC_TYPES_H
#define MAC_TYPES_H
#include "sl_status.h"
#include "buffer_manager/buffer-management.h"

typedef uint16_t sl_mac_node_id_t;
typedef uint16_t sl_mac_pan_id_t;

typedef uint16_t sl_802154_pan_id_t;
typedef uint16_t sl_802154_short_addr_t;

#define EUI64_SIZE 8
typedef uint8_t sl_802154_long_addr_t[EUI64_SIZE];

typedef uint8_t sl_802154_message_length_t;

// SL_EMPTY_CHILD_NODE_ID is used only when (re)initializing the child node ID (especially in NVM)
// to a default/unused value as it corresponds to the token init default.
// It is never returned from the child node ID lookup functions.
// Only use this when setting/examining the raw data for the child table entry.
#define SL_EMPTY_CHILD_NODE_ID   0x0000u

// SL_ZIGBEE_NULL_NODE_ID is the node ID that higher layers expect to see for failed child table
// lookups.  Use this instead of SL_EMPTY_CHILD_NODE_ID as a return value for this interface.
#define SL_ZIGBEE_NULL_NODE_ID       0xFFFFu
#define SL_ZIGBEE_USE_LONG_ADDRESS   0xFFFEu
#define SL_ZIGBEE_BROADCAST_PAN_ID   0xFFFFu

// -----------------------------------------------------------------------------
// MAC Filters

/** @brief This is a bitmask describing a filter for MAC
 *    data messages that the stack should accept and pass through
 *    to the application.
 */
typedef uint16_t sl_zigbee_mac_filter_match_data_t;

#define SL_802154_FILTER_MATCH_ENABLED_MASK            0x0001
#define SL_802154_FILTER_MATCH_ON_PAN_DEST_MASK        0x0003
#define SL_802154_FILTER_MATCH_ON_PAN_SOURCE_MASK      0x000C
#define SL_802154_FILTER_MATCH_ON_DEST_MASK            0x0030
#define SL_802154_FILTER_MATCH_ON_SOURCE_MASK          0x0080

// Globally turn on/off this filter.
#define SL_802154_FILTER_MATCH_ENABLED                 0x0000
#define SL_802154_FILTER_MATCH_DISABLED                0x0001

// Pick either one of these.
#define SL_802154_FILTER_MATCH_ON_PAN_DEST_NONE        0x0000
#define SL_802154_FILTER_MATCH_ON_PAN_DEST_LOCAL       0x0001
#define SL_802154_FILTER_MATCH_ON_PAN_DEST_BROADCAST   0x0002

// and one of these.
#define SL_802154_FILTER_MATCH_ON_PAN_SOURCE_NONE      0x0000
#define SL_802154_FILTER_MATCH_ON_PAN_SOURCE_NON_LOCAL 0x0004
#define SL_802154_FILTER_MATCH_ON_PAN_SOURCE_LOCAL     0x0008

// and one of these.
#define SL_802154_FILTER_MATCH_ON_DEST_BROADCAST_SHORT 0x0000
#define SL_802154_FILTER_MATCH_ON_DEST_UNICAST_SHORT   0x0010
#define SL_802154_FILTER_MATCH_ON_DEST_UNICAST_LONG    0x0020

// and one of these.
#define SL_802154_FILTER_MATCH_ON_SOURCE_LONG          0x0000
#define SL_802154_FILTER_MATCH_ON_SOURCE_SHORT         0x0080
#define SL_802154_FILTER_MATCH_ON_SOURCE_NONE          0x0100

// Intended to mark the end of the mac filter list, although
// a valid list is no longer required to include this value.
#define SL_802154_FILTER_MATCH_END                     0x8000

// determines the maximum capacity of the mac filter list
#define SL_802154MAC_FILTER_MATCH_LIST_MAX_LENGTH      32

typedef uint64_t sl_mac_child_status_flags_t;

typedef struct {
  uint8_t mac_index;
  sl_802154_short_addr_t short_id;
  sl_802154_long_addr_t long_id;
  sl_mac_child_status_flags_t info;
} sl_mac_child_entry_t;

#endif
