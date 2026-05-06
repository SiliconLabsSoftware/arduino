/***************************************************************************//**
 * @file
 * @brief EmberZNet API for sending and receiving RAW messages, which
 *   do not go out over the Zigbee network.  These messages have MAC
 *   headers formatted by the application.
 *
 * See @ref raw-message for documentation.
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

#ifndef SILABS_RAW_MESSAGE_H
#define SILABS_RAW_MESSAGE_H

#include "stack/include/sl_zigbee_types.h"
#include "mac-header.h"

/**
 * @addtogroup raw_message
 *
 * This file defines routines and callbacks for dealing with the transmission
 * and reception of rawly constructed messages.
 *
 * See raw-message.h for source code.
 * @{
 */

/** @brief This function allows the application to configure the stack to
 *    accept raw MAC data messages that it normally would not accept.
 *    When the stack receives a message matching one of the filters it
 *    will call ::sl_802154_filter_match_message_handler().
 *    This function should point to a list of ::sl_zigbee_mac_filter_match_data_t.
 *    To clear all filters, call this function with listLength equal to 0.
 *
 * @param macFilterMatchList A pointer to a list of ::sl_zigbee_mac_filter_match_data_t values.
 *   The length of this list is limited to SL_802154MAC_FILTER_MATCH_LIST_MAX_LENGTH entries.
 *
 * @param listLength Length of macFilterMatchList in entries (each entry of type
 *   ::sl_zigbee_mac_filter_match_data_t is 2 bytes), or 0 if filters are being cleared.
 *
 * @return ::SL_STATUS_OK if the MAC filter match list has been configured correctly.
 *   ::SL_STATUS_INVALID_PARAMETER if one of the filters matches a Zigbee MAC header and cannot
 *   be used, or if the filter list exceeds the supported length.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# macFilterMatchList | length: listLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
sl_status_t sl_zigbee_set_mac_filter_match_list(const sl_zigbee_mac_filter_match_data_t* macFilterMatchList,
                                                uint8_t listLength);

/** @brief Called when the stack has received a raw MAC message that has
 *    matched one of the application's configured MAC filters.
 *
 * @param filterIndexMatch       Index of the filter that was matched.
 * @param legacyPassthroughType  Legacy passthrough message type.
 * @param packetInfo             Struct containing information about the packet, like last LQI/RSSI.
 * @param messageLength          Length of the matching message.
 * @param messageContents        Pointer to the message contents.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# messageContents | length: messageLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
void sl_802154_filter_match_message_handler(uint8_t filterIndexMatch,
                                            uint8_t legacyPassthroughType,
                                            sl_zigbee_rx_packet_info_t *packetInfo,
                                            uint8_t messageLength,
                                            uint8_t *messageContents);

/**@brief A callback invoked by the EmberZNet stack to filter out incoming
 * application MAC passthrough messages.  If this returns true for a message
 * the complete message will be passed to sl_802154_passthrough_message_handler()
 * with a type of SL_802154_PASSTHROUGH_APPLICATION.
 *
 * Note that this callback may be invoked in ISR context and should execute as
 * quickly as possible.
 *
 * Note that this callback may be called more than once per incoming message.
 * Therefore the callback code should not depend on being called only once,
 * and should return the same value each time it is called with a given header.
 *
 * If the application includes this callback, it must define
 * SL_ZIGBEE_APPLICATION_HAS_MAC_PASSTHROUGH_FILTER_HANDLER in its
 * CONFIGURATION_HEADER.
 *
 * @param macHeader        A pointer to the initial portion of the
 *     incoming MAC header.  This contains the MAC frame control and
 *     addressing fields.  Subsequent MAC fields, and the MAC payload,
 *     may not be present.
 * @return true if the messages is an application MAC passthrough message.
 */
bool sl_802154_internal_passthrough_filter_handler(uint8_t *macHeader);

/** @brief Send the given message over the air without higher layer
 * network headers.
 *
 * The first two bytes are interpreted as the 802.15.4 frame control field.
 * If the Ack Request bit is set, the packet will be retried as necessary.
 * Completion is reported via ::sl_zigbee_raw_transmit_complete_handler().
 * Note that the sequence number specified in this packet is not taken into
 * account by the MAC layer. The MAC layer overwrites the sequence number field
 * with the next available sequence number.
 *
 * @param message        The message to transmit.
 * @param mesage_length  The message length to transmit.
 * @param priority       Transmit priority
 * @param useCca         Flag should the CCA stay on or not
 *
 * @return ::SL_STATUS_OK if the message was successfully submitted to
 * the transmit queue, and ::SL_STATUS_FAIL otherwise.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# message | length: message_length | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
sl_status_t sl_zigbee_send_raw_message(const uint8_t *message, uint8_t message_length, sl_zigbee_transmit_priority_t priority, bool useCca);

/**@brief A callback invoked by the EmberZNet stack when the
 * MAC has finished transmitting a raw message.
 *
 * If the application includes this callback, it must define
 * SL_ZIGBEE_APPLICATION_HAS_RAW_HANDLER in its CONFIGURATION_HEADER.
 *
 * @param messageLength    Length of the raw message that was sent.
 * @param messageContents  The raw message that was sent.
 * @param status           ::SL_STATUS_OK if the transmission was successful,
 *                         or ::SL_STATUS_ZIGBEE_DELIVERY_FAILED if not.
 */
void sl_zigbee_raw_transmit_complete_handler(uint8_t message,
                                             uint8_t* messageContents,
                                             sl_status_t status);

// Old APIs

/**@brief A callback invoked by the EmberZNet stack when a
 * MAC passthrough message is received.  These are messages that
 * applications may wish to receive but that do
 * not follow the normal ZigBee format.
 *
 * Examples of MAC passthrough messages are Embernet
 * messages and first generation (v1) standalone bootloader messages,
 * and SE (Smart Energy) InterPAN messages.
 * These messages are handed directly to the application and are not
 * otherwise handled by the EmberZNet stack.
 * Other uses of this API are not tested or supported at this time.
 * If the application includes this callback, it must define
 * SL_ZIGBEE_APPLICATION_HAS_MAC_PASSTHROUGH_HANDLER in its CONFIGURATION_HEADER
 * and call sl_zigbee_set_mac_passthrough_flags() to indicate the kind(s) of messages
 * that the application wishes to receive.
 *
 * @param messageType       The type of MAC passthrough message received.
 * @param packetInfo        Information about the received packet.
 * @param messageLength     Length of the MAC passthrough message that was received.
 * @param messageContents   The MAC passthrough message that was received.
 */
void sl_802154_passthrough_message_handler(sl_zigbee_mac_passthrough_type_t messageType,
                                           sl_zigbee_rx_packet_info_t *packetInfo,
                                           uint8_t messageLength,
                                           uint8_t *messageContents);

/**@brief Applications wishing to receive MAC passthrough messages must
 * set this to indicate the types of messages they wish to receive.
 */
sl_zigbee_mac_passthrough_type_t sl_zigbee_get_mac_passthrough_flags(void);
void sl_zigbee_set_mac_passthrough_flags(sl_zigbee_mac_passthrough_type_t type);

/**@brief Applications wishing to receive EmberNet messages filtered by
 * source address must set this to the desired source address, as well as
 * setting the SL_802154_PASSTHROUGH_EMBERNET_SOURCE bit when using
 * sl_zigbee_set_mac_passthrough_flags().
 */
sl_802154_short_addr_t sl_zigbee_get_embernet_passthrough_source_address(void);
void sl_zigbee_set_embernet_passthrough_source_address(sl_802154_short_addr_t address);

/** @} END addtogroup */

#endif // SILABS_RAW_MESSAGE_H
