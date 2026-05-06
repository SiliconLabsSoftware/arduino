/***************************************************************************//**
 * @file
 * @brief legacy packet buffer support
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

#ifndef LEGACY_PACKET_BUFFER_H
#define LEGACY_PACKET_BUFFER_H

#include "sl_status.h"

uint8_t *sl_legacy_buffer_manager_get_linked_buffers_pointer(sli_buffer_manager_buffer_t buffer, uint16_t index);

sl_status_t sl_legacy_buffer_manager_really_append_to_linked_buffers(sli_buffer_manager_buffer_t *buffer,
                                                                     uint8_t *contents,
                                                                     uint16_t length,
                                                                     bool reallyAppend);
sl_status_t sl_legacy_buffer_manager_really_set_linked_buffers_length(sli_buffer_manager_buffer_t *buffer,
                                                                      uint16_t newLength);

uint8_t sl_legacy_buffer_manager_get_linked_buffers_byte(sli_buffer_manager_buffer_t buffer, uint16_t index);
void sl_legacy_buffer_manager_set_linked_buffers_byte(sli_buffer_manager_buffer_t buffer, uint16_t index, uint8_t byte);

sli_buffer_manager_buffer_t sl_legacy_buffer_manager_copy_linked_buffers(sli_buffer_manager_buffer_t buffer);
void sl_legacy_buffer_manager_copy_buffer_bytes(sli_buffer_manager_buffer_t to,
                                                uint16_t toIndex,
                                                sli_buffer_manager_buffer_t from,
                                                uint16_t fromIndex,
                                                uint16_t count);

uint16_t sl_legacy_buffer_manager_get_linked_buffers_low_high_int16u(sli_buffer_manager_buffer_t buffer,
                                                                     uint16_t index);
sl_status_t sl_legacy_buffer_manager_set_linked_buffers_low_high_int16u(sli_buffer_manager_buffer_t buffer,
                                                                        uint16_t index,
                                                                        uint16_t value);
uint32_t sl_legacy_buffer_manager_get_linked_buffers_low_high_int32u(sli_buffer_manager_buffer_t buffer,
                                                                     uint16_t index);
sl_status_t sl_legacy_buffer_manager_set_linked_buffers_low_high_int32u(sli_buffer_manager_buffer_t buffer,
                                                                        uint16_t index,
                                                                        uint32_t value);

sli_buffer_manager_buffer_t
sl_legacy_buffer_manager_fill_stack_buffer(unsigned int count, ...);

#define sl_legacy_buffer_manager_linked_buffer_contents(buffer) sl_legacy_buffer_manager_message_buffer_contents(buffer)

#define sl_legacy_buffer_manager_release_message_buffer(buffer) do {} while (0)
#define sl_legacy_buffer_manager_hold_message_buffer(buffer) do {} while (0)

#define sl_legacy_buffer_manager_append_to_linked_buffers(buffer, contents, length) \
  sl_legacy_buffer_manager_really_append_to_linked_buffers(&(buffer), (contents), (length), true)

#define sl_legacy_buffer_manager_extend_linked_buffer(buffer, length) \
  sl_legacy_buffer_manager_really_append_to_linked_buffers(&(buffer), NULL, (length), false)

#define sl_legacy_buffer_manager_set_linked_buffers_length(buffer, newlength) \
  sl_legacy_buffer_manager_really_set_linked_buffers_length(&(buffer), newlength)

#define sl_legacy_buffer_manager_set_message_buffer_length sl_legacy_buffer_manager_set_linked_buffers_length

//----------------------------------------------------------------
// Macros for the MessageBuffer interface.

#define sl_legacy_buffer_manager_message_buffer_contents sli_legacy_buffer_manager_get_buffer_pointer
#define sl_legacy_buffer_manager_message_buffer_length sli_legacy_buffer_manager_get_buffer_length

#define sli_legacy_packet_buffer_packet_header_payload(header) sli_legacy_buffer_manager_get_payload_link(header)

#define sli_legacy_packet_buffer_set_packet_header_payload(header, payload) \
  sli_legacy_buffer_manager_set_payload_link((header), (payload))

#define sl_legacy_buffer_manager_fill_linked_buffers(contents, length) \
  sli_legacy_buffer_manager_really_fill_buffer((contents), (length), false)

 #define sl_legacy_buffer_manager_fill_linked_async_buffers(contents, length) \
  sli_legacy_buffer_manager_really_fill_buffer((contents), (length), true)

#define sli_legacy_packet_buffer_queue_add sli_legacy_buffer_manager_buffer_queue_add
#define sli_legacy_packet_buffer_queue_remove_head sli_legacy_buffer_manager_buffer_queue_remove_head
#define sli_legacy_packet_buffer_queue_remove sli_legacy_buffer_manager_buffer_queue_remove
#define sli_legacy_packet_buffer_queue_is_empty sli_legacy_buffer_manager_buffer_queue_is_empty

#undef SL_ZIGBEE_NULL_MESSAGE_BUFFER
#define SL_ZIGBEE_NULL_MESSAGE_BUFFER NULL_BUFFER

#define sl_legacy_buffer_manager_copy_from_linked_buffers(buffer, startIndex, contents, length) \
  sli_legacy_packet_buffer_really_copy_to_linked_buffers((const uint8_t *) (contents), (buffer), (startIndex), (length), 0)

#define sl_legacy_buffer_manager_copy_to_linked_buffers(contents, buffer, startIndex, length) \
  sli_legacy_packet_buffer_really_copy_to_linked_buffers((const uint8_t *) (contents), (buffer), (startIndex), (length), 1)

#define sli_legacy_buffer_manager_copy_from_linked_buffers(contents, buffer, length) \
  sli_legacy_packet_buffer_really_copy_to_linked_buffers((const uint8_t *) (contents), (buffer), (0), (length), 0)

#define sl_legacy_buffer_manager_allocate_stack_buffer() \
  sli_legacy_buffer_manager_really_allocate_buffer(0, false)

#define PACKET_BUFFER_SIZE 32

#endif // LEGACY_PACKET_BUFFER_H
