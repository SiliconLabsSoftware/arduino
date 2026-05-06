/***************************************************************************//**
 * @file
 * @brief Code for multi-network support.
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

#ifndef SILABS_MAC_MULTI_NETWORK_H
#define SILABS_MAC_MULTI_NETWORK_H

#include "include/sl_zigbee.h" // For SL_ZIGBEE_MULTI_NETWORK_STRIPPED
#include "mac-child.h" // For sl_mac_child_entry_t

#ifdef SL_ZIGBEE_MULTI_NETWORK_STRIPPED
#define SL_MAC_MAX_SUPPORTED_NETWORKS 1
#define SL_MAC_MULTI_PAN_CODE(body)
#define sli_mac_set_callback_network_index(nwk_index)
#define sli_mac_push_child_table_pointer(nwk_index) SL_STATUS_OK
#define sli_mac_pop_child_table_pointer()
#define sli_mac_get_current_child_table_network_index() NWK_INDEX
#else
#define SL_MAC_MAX_SUPPORTED_NETWORKS 2
#define SL_MAC_MULTI_PAN_CODE(body) do { body } while (0)
// Network Index to be used by the stack
extern uint8_t sli_mac_nwk_index_for_stack;
// sets the network index that needs to be used by the stack
// this is called from the mac before making a stack call
#define sli_mac_set_callback_network_index(nwk_index) (sli_mac_nwk_index_for_stack = (nwk_index))
// returns the network index to be used by the stack
// this is called from the stack
#define sli_mac_get_callback_network_index() (sli_mac_nwk_index_for_stack)
typedef struct {
  sl_mac_child_entry_t *child_table;
  uint16_t *child_status;
} sl_mac_child_table_pointers_t;
sl_status_t sli_mac_init_child_table_pointers(uint8_t nwk_index,
                                              sl_mac_child_entry_t *child_table,
                                              uint16_t *child_status);
sl_status_t sli_mac_push_child_table_pointer(uint8_t nwk_index);
sl_status_t sli_mac_pop_child_table_pointer(void);
uint8_t sli_mac_get_current_child_table_network_index(void);
#endif // SL_ZIGBEE_MULTI_NETWORK_STRIPPED

extern uint8_t sli_mac_network_poll_queue[SL_MAC_MAX_SUPPORTED_NETWORKS];

void sli_mac_add_current_network_to_polling_queue(uint8_t nwk_index);
uint8_t sli_mac_dequeue_polling_network(void);
bool sli_mac_multi_network_poll_pending(void);

#endif // SILABS_MAC_MULTI_NETWORK_H
