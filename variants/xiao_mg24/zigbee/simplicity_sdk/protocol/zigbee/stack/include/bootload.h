/***************************************************************************//**
 * @file
 * @brief See @ref znet_bootload for documentation.
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

#ifndef SILABS_BOOTLOAD_H
#define SILABS_BOOTLOAD_H

#include "stack/include/sl_zigbee_types.h"

/**
 * @addtogroup znet_bootload
 * @brief EmberZNet bootload API.
 *
 * See bootload.h for source code.
 * @{
 */

/** @brief Transmit the given bootload message to a neighboring
 * node using a specific 802.15.4 header that allows the EmberZNet stack
 * and the Ember bootloader to recognize the message but will not
 * interfere with other Zigbee stacks.
 *
 * @param broadcast        If true, the destination address and PAN ID are
 *     both set to the broadcast address.
 * @param destEui64        The EUI64 of the target node. Ignored if
 *     the broadcast field is set to true.
 * @param messageLength    Length of the message to be sent.
 * @param messageContents  The bootloader message to send.
 *
 * @return ::SL_STATUS_OK if the message was successfully submitted to
 * the transmit queue, and ::SL_STATUS_FAIL otherwise.
 */
sl_status_t sl_zigbee_send_bootload_message(bool broadcast,
                                            sl_802154_long_addr_t destEui64,
                                            uint8_t messageLength,
                                            uint8_t *messageContents);

/** @brief Invoked by the EmberZNet stack when a
 * bootload message is received. If the application includes
 * ::sl_zigbee_incoming_bootload_message_handler(),
 * it must define SL_ZIGBEE_APPLICATION_HAS_BOOTLOAD_HANDLERS in its
 * CONFIGURATION_HEADER.
 *
 * @param longId            The EUI64 of the sending node.
 * @param packetInfo        Information about the incoming packet.
 * @param messageLength     Length of the bootload message that was sent.
 * @param messageContents   The bootload message that was sent.
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# messageContents | length: messageLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
void sl_zigbee_incoming_bootload_message_handler(sl_802154_long_addr_t longId,
                                                 sl_zigbee_rx_packet_info_t *packetInfo,
                                                 uint8_t  messageLength,
                                                 uint8_t *messageContents);

/** @brief Invoked by the EmberZNet stack when the
 * MAC has finished transmitting a bootload message. If the
 * application includes this callback, it must define
 * SL_ZIGBEE_APPLICATION_HAS_BOOTLOAD_HANDLERS in its CONFIGURATION_HEADER.
 *
 * @param status   ::SL_STATUS_OK if the transmission was successful,
 *    or ::SL_STATUS_ZIGBEE_DELIVERY_FAILED if not.
 * @param messageLength Length of the message that was sent.
 * @param messageContents The message that was sent.
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# messageContents | length: messageLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
void sl_zigbee_bootload_transmit_complete_handler(sl_status_t status,
                                                  uint8_t messageLength,
                                                  uint8_t *messageContents);

/** @} END addtogroup */

/**
 * <!-- HIDDEN
 * @page 2p5_to_3p0
 * <hr>
 * The file bootload.h is new and is described in @ref znet_bootload.
 *
 * - <b>Items moved from sl_zigbee.h</b>
 *   - sl_zigbee_bootload_transmit_complete_handler()
 *   - sl_zigbee_incoming_bootload_message_handler()
 *   - sl_zigbee_send_bootload_message()
 *   .
 * .
 * HIDDEN -->
 */

#endif // SILABS_BOOTLOAD_H
