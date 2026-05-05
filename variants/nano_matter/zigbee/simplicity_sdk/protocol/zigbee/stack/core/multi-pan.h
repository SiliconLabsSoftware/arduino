/***************************************************************************//**
 * @file
 * @brief Code for multi PAN support.
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SILABS_MULTI_PAN_H
#define SILABS_MULTI_PAN_H

#include "stack/include/library.h"
#include "event_queue/event-queue.h"
#include "stack/include/sl_zigbee_types.h"

extern uint8_t sli_zigbee_num_multi_pan_forks;
extern const sl_zigbee_library_status_t sli_zigbee_multi_pan_library_status;
extern uint8_t sli_zigbee_route_table_size;

void sli_zigbee_network_pan_info_data_init(uint8_t nwkIndex, sl_zigbee_network_info_t *curNetwork);
void sli_zigbee_multi_pan_init(void);

#ifdef SL_ZIGBEE_MULTI_NETWORK_STRIPPED
#define sli_zigbee_get_network_index_for_forked_global()  0
#define sli_zigbee_get_forked_event(x)  (x)
// void(control) to make compiler happy for unused warning.
#define sli_zigbee_get_network_index_from_event(event, list) SL_ZIGBEE_NULL_NETWORK_INDEX
#define sli_zigbee_set_child_table_for_current_network()
#define sli_zigbee_is_pan_id_in_use(panId) 0
#define LOOP_NUM_MULTI_PAN_FORKS(body) \
  do {                                 \
    uint8_t nwkIndex = 0;              \
    { body }                           \
  } while (0)
#else // !SL_ZIGBEE_MULTI_NETWORK_STRIPPED
void sli_zigbee_get_child_token_for_current_network(void *data,
                                                    uint16_t tokenAddress,
                                                    uint8_t childIndex);

void sli_zigbee_set_child_token_for_current_network(uint16_t tokenAddress,
                                                    uint8_t childIndex,
                                                    void *data);

void sli_zigbee_set_child_table_for_current_network(void);

// For a forked PAN event, gets the correct event control pointer based on the
// current network index. This should be used when arming an event to fire. The
// correct event control must be armed so that the event handler knows which
// network index is the right one.
// NOTE: not all events are forked. See multi-pan-common.c for a list of those
// which are. This API should only be called on those lists of events. In
// multi-PAN, events are forked so that the handlers can tell which network
// index armed the event (the triggering sl_zigbee_event_control_t pointer is checked in
// the handler. There is only one handler for all forked events.)
sl_zigbee_event_control_t* sli_zigbee_get_forked_event_control(sl_zigbee_event_control_t *list);

sli_zigbee_event_t* sli_zigbee_get_forked_event(sli_zigbee_event_t *list);
uint8_t sli_zigbee_get_network_index_from_event(sli_zigbee_event_t *event,
                                                sli_zigbee_event_t *list);

// When dereferencing forked PAN globals, we need to read and write to the
// correct index. For multi PAN, this is the current network index returned by
// sli_zigbee_get_current_network_index. For multi network, there's only one copy of the
// data, so we always return index 0.
uint8_t sli_zigbee_get_network_index_for_forked_global(void);

// For a forked PAN event, gets the network index that this event control
// maps to. This should be called in an event handler, so that the code can
// determine which network index is the right one.
uint8_t sli_zigbee_get_network_index_from_event_control(sl_zigbee_event_control_t *control,
                                                        sl_zigbee_event_control_t *list);

// This api can be used to check given panId is used by other multi PANs.
// This can be used to restrict using same PAN while forming or setting new
// PAN during PAN conflict resolution.
bool sli_zigbee_is_pan_id_in_use(sl_802154_pan_id_t panId);

#define LOOP_NUM_MULTI_PAN_FORKS(body)            \
  for (uint8_t nwkIndex = 0;                      \
       nwkIndex < sli_zigbee_num_multi_pan_forks; \
       nwkIndex++)                                \
  { body }
#endif // SL_ZIGBEE_MULTI_NETWORK_STRIPPED
#endif // SILABS_MULTI_PAN_H
