/***************************************************************************//**
 * @file
 * @brief EmberZNet API for sending and receiving messages.
 * See @ref message for documentation.
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

#ifndef SILABS_MESSAGE_H
#define SILABS_MESSAGE_H

#include "stack/include/sl_zigbee_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup message
 *
 * See message.h for source code.
 * @{
 */

/** @brief Return the maximum size of the payload that the Application
 * Support sub-layer will accept.
 *
 * The size depends on the security level in use.
 * The value is the same as that found in the node descriptor.
 *
 * @return The maximum APS payload length.
 */
uint8_t sl_zigbee_maximum_aps_payload_length(void);

/** @brief The per-hop delay allowed for in the calculation of the
 * APS ACK timeout value.  This is defined in the Zigbee specification.
 * This times the maximum number of hops (SL_ZIGBEE_MAX_HOPS)
 * plus the terminal encrypt/decrypt time is the timeout between retries of an
 * APS ACKed message in milliseconds.
 */
#define SL_ZIGBEE_APSC_MAX_ACK_WAIT_HOPS_MULTIPLIER_MS     50

/** @brief The terminal encrypt/decrypt time allowed for in the calculation
 * of the APS ACK timeout value.  This is defined in the ZigBee specification.
 */
#define SL_ZIGBEE_APSC_MAX_ACK_WAIT_TERMINAL_SECURITY_MS  100

/** @brief Return the APS ACK timeout value.
 * The stack waits this amount of time between resends of APS retried messages.
 * The default value is:
 * <pre>
 *   ((SL_ZIGBEE_APSC_MAX_ACK_WAIT_HOPS_MULTIPLIER_MS
 *     * SL_ZIGBEE_MAX_HOPS)
 *    + SL_ZIGBEE_APSC_MAX_ACK_WAIT_TERMINAL_SECURITY_MS)
 * </pre>
 */
uint16_t sl_zigbee_get_aps_ack_timeout_ms(void);

/** @brief Set the APS ACK timeout value.
 *
 */
void sl_zigbee_set_aps_ack_timeout_ms(uint16_t timeout);

/** @brief Send a multicast message to all endpoints that share
 * a specific multicast ID and are within a specified number of hops of the
 * sender.
 *
 * @param apsFrame       The APS frame for the message.  The multicast will be sent to the groupId
 *                       in this frame.
 *
 * @param radius         The message will be delivered to all nodes within this number of hops of the sender.
 *                       A value of zero is converted to SL_ZIGBEE_MAX_HOPS.
 *
 * @param broadcastAddr  A specific broadcast addrs that is prefered. If a non broadcast address is used here,
 *                       the stack will either use ::SL_ZIGBEE_SLEEPY_BROADCAST_ADDRESS or
 *                       ::SL_ZIGBEE_RX_ON_WHEN_IDLE_BROADCAST_ADDRESS depending on if multicasts are to be sent to
 *                       sleepies.
 *
 * @param alias          The alias from which to send the multicast. If not needed use ::SL_ZIGBEE_NULL_NODE_ID
 *
 * @param nwkSequence    The aliased NWK sequence number for the message. Only used if there is an alias source.
 *
 * @param messageTag     A value chosen by the application. It gets passed back up in
 *                       ::sl_zigbee_message_sent_handler().
 *
 * @param messageLength  The length of the message parameter in bytes.
 *
 * @param message        Content of the message.
 *
 * @param apsSequence    Return: The APS sequencer number that will be used when this message is transmitted.
 *
 * @return An ::sl_status_t value. For any result other than ::SL_STATUS_OK,
 *  the message will not be sent.\n\n
 * - ::SL_STATUS_OK - The message has been submitted for
 * transmission.
 * - ::SL_STATUS_INVALID_INDEX - The \c bindingTableIndex
 * refers to a non-multicast binding.
 * - ::SL_STATUS_NETWORK_DOWN - The node is not part of a network.
 * - ::SL_STATUS_MESSAGE_TOO_LONG - The message is too large to
 * fit in a MAC layer frame.
 * - ::SL_STATUS_ALLOCATION_FAILED  - The free packet buffer pool is empty.
 * - ::SL_STATUS_BUSY - Insufficient resources available
 * in Network or MAC layers to send message.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# message | length: messageLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 * {# apsSequence #}
 */
sl_status_t sl_zigbee_send_multicast(sl_zigbee_aps_frame_t *apsFrame,
                                     uint8_t radius,
                                     uint16_t broadcastAddr,
                                     sl_802154_short_addr_t alias,
                                     uint8_t nwkSequence,
                                     uint16_t messageTag,
                                     uint8_t messageLength,
                                     const uint8_t *message,
                                     uint8_t *apsSequence);

/** @brief Send a unicast message per the Zigbee specification.
 *
 * The message will arrive at its destination only if there is a known route
 * to the destination node.  Setting the ::ENABLE_ROUTE_DISCOVERY
 * option will cause a route to be discovered if none is known.  Setting the
 * ::FORCE_ROUTE_DISCOVERY option will force route discovery.
 * Routes to end-device children of the local node are always known.
 *
 * Setting the @c APS_RETRY option will cause the message to be
 * retransmitted until either a matching acknowledgment is received or three
 * transmissions have been made.
 *
 * @note Using the ::FORCE_ROUTE_DISCOVERY option will cause the first
 * transmission to be consumed by a route request as part of discovery, so
 * the application payload of this packet will not reach its destination on
 * the first attempt.  For the packet to reach its destination, the
 * APS_RETRY option must be set so that another attempt is made to transmit
 * the message with its application payload after the route has been
 * constructed.
 *
 * Setting the ::DESTINATION_EUI64 option will cause the long
 * ID of the destination to be included in the network header.  This is
 * the only way to absolutely guarantee that the message is delivered to
 * the correct node.  Without it, a message may on occasion be delivered
 * to the wrong destination in the event of an ID conflict that has
 * not yet been detected and resolved by the network layer.
 *
 * @note When sending fragmented messages, the stack will only assign a new APS
 * sequence number for the first fragment of the message (i.e.,
 * ::SL_ZIGBEE_APS_OPTION_FRAGMENT is set and the low-order byte of the groupId
 * field in the APS frame is zero).  For all subsequent fragments of the same
 * message, the application must set the sequence number field in the APS frame
 * to the sequence number assigned by the stack to the first fragment.
 *
 * @param type               Specifies the outgoing message type.  Must be one of
 * ::SL_ZIGBEE_OUTGOING_DIRECT, ::SL_ZIGBEE_OUTGOING_VIA_ADDRESS_TABLE, or
 * ::SL_ZIGBEE_OUTGOING_VIA_BINDING.
 *
 * @param indexOrDestination Depending on the type of addressing used, this
 *  is either the sl_802154_short_addr_t of the destination, an index into the address table,
 *  or an index into the binding table.
 *
 * @param apsFrame           The APS frame which is to be added to the message.
 *
 * @param messageTag         A value chosen by the application. It gets passed back up in
 *                           ::sl_zigbee_message_sent_handler().
 *
 * @param messageLength      The length of the message parameter in bytes.
 *
 * @param message            Content of the message.
 *
 * @param apsSequence        Return: The APS sequencer number that will be used when this
 *                           message is transmitted.
 *
 * @return An ::sl_status_t value. For any result other than
 *   ::SL_STATUS_OK, the message will not be sent.
 * - ::SL_STATUS_OK - The message has been submitted for transmission.
 * - ::SL_STATUS_INVALID_PARAMETER The passed message pointer is NULL and the messageLength is > 0
 * - ::SL_STATUS_ALLOCATION_FAILED The stack failed to allocate a buffer to store the message.
 * - ::SL_STATUS_INVALID_INDEX - The \c bindingTableIndex
 * refers to a non-unicast binding.
 * - ::SL_STATUS_NETWORK_DOWN - The node is not part of a network.
 * - ::SL_STATUS_MESSAGE_TOO_LONG - The message is too large to
 * fit in a MAC layer frame.
 * - ::SL_STATUS_ZIGBEE_MAX_MESSAGE_LIMIT_REACHED - The
 * ::SL_ZIGBEE_APS_UNICAST_MESSAGE_COUNT limit has been reached.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# message | length: messageLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 * {# apsSequence #}
 */
sl_status_t sl_zigbee_send_unicast(sl_zigbee_outgoing_message_type_t type,
                                   uint16_t indexOrDestination,
                                   sl_zigbee_aps_frame_t *apsFrame,
                                   uint16_t messageTag,
                                   uint8_t messageLength,
                                   const uint8_t *message,
                                   uint8_t *apsSequence);

/** @brief Send a broadcast message as per the ZigBee specification.
 *
 * The message will be delivered to all nodes within @c radius
 * hops of the sender. A radius of zero is converted to ::SL_ZIGBEE_MAX_HOPS.
 *
 * @param alias          The aliased source from which to send the broadcast.
 *                       ::SL_ZIGBEE__NULL_NODE_ID could be used if this is a simple broadcast message,
 *                       and not aliased/proxied.
 *
 * @param destination    The destination to which to send the broadcast.
 *                       This must be one of three ZigBee broadcast addresses.
 *
 * @param nwkSequence    The NWK sequence number for the message, if there is a non-null alias source.
 *
 * @param apsFrame       The APS frame data to be included in the message.
 *
 * @param radius         The maximum number of hops the message will be relayed.
 *
 * @param messageTag     A value chosen by the application. It gets passed back up in
 *                       ::sl_zigbee_message_sent_handler().
 *
 * @param messageLength  The length of the message parameter in bytes.
 *
 * @param message        Content of the message.
 *
 * @param apsSequence    Return: The APS sequencer number that will be used when this
 *                       message is transmitted.
 *
 * @return An ::sl_status_t value indicating success or the reason for failure.
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# message | length: messageLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 * {# apsSequence #}
 */
sl_status_t sl_zigbee_send_broadcast(sl_802154_short_addr_t alias,
                                     sl_802154_short_addr_t destination,
                                     uint8_t nwkSequence,
                                     sl_zigbee_aps_frame_t *apsFrame,
                                     uint8_t radius,
                                     uint16_t messageTag,
                                     uint8_t messageLength,
                                     const uint8_t *message,
                                     uint8_t *apsSequence);

/** @brief Proxy a broadcast message for another node.
 *
 * The function is used in conjunction with aliased/proxied sl_zigbee_send_broadcast,
 * a message from a short ID. This function is used where a long source is also
 * specified in the NWK frame control.
 *
 * @param euiSource    The long source from which to send the broadcast.
 *
 * @return An ::sl_status_t value.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# euiSource | length: EUI64_SIZE | max: EUI64_SIZE #}
 */
sl_status_t sl_zigbee_proxy_next_broadcast_from_long(const uint8_t* euiSource);

/**
 * @brief Indicate that a many-to-one route to the concentrator
 * with the given short and long ID is available for use.
 *
 * The application must define
 * @c SL_ZIGBEE_APPLICATION_HAS_INCOMING_MANY_TO_ONE_ROUTE_REQUEST_HANDLER
 * in its configuration header to use this.
 *
 * @param source  The short ID of the concentrator that initiated the
 * many-to-one route request.
 * @param longId  The EUI64 of the concentrator.
 * @param cost    The path cost to the concentrator.
 */
void sl_zigbee_incoming_many_to_one_route_request_handler(sl_802154_short_addr_t source,
                                                          sl_802154_long_addr_t longId,
                                                          uint8_t cost);

/**
 * @brief Invoke when a route error message is received.
 *
 * A status of ::SL_STATUS_ZIGBEE_SOURCE_ROUTE_FAILURE indicates that a
 * source-routed unicast sent from this node encountered a
 * broken link.  Note that this case occurs only if this node is
 * a concentrator using many-to-one routing for inbound
 * messages and source-routing for outbound messages.
 * The node prior to the broken link generated the route
 * error message and returned it to us along the many-to-one route.
 *
 * A status of ::SL_STATUS_ZIGBEE_MANY_TO_ONE_ROUTE_FAILURE also occurs only
 * if the local device is a concentrator, and indicates that
 * a unicast sent to the local device along a many-to-one route
 * encountered a broken link.  The node prior to the broken
 * link generated the route error message and forwarded it
 * to the local device via a randomly chosen neighbor, taking advantage
 * of the many-to-one nature of the route.
 *
 * A status of ::SL_STATUS_MAC_INDIRECT_TIMEOUT indicates that a
 * message sent to the target end device could not be delivered
 * by the parent because the indirect transaction timer expired.
 * Upon receipt of the route error, the stack sets the extended
 * timeout for the target node in the address table, if present.
 * It then calls this handler to indicate receipt of the error.
 *
 * Note that if the original unicast data message is sent using
 * the ::SL_ZIGBEE_APS_OPTION_RETRY option, a new route error message
 * is generated for each failed retry. Therefore, it is not unusual
 * to receive three route error messages in succession for a
 * single failed retried APS unicast. On the other hand, it is also
 * not guaranteed that any route error messages will be
 * delivered successfully at all. The only sure way to detect
 * a route failure is to use retried APS messages and to check the
 * status of the ::sl_zigbee_message_sent_handler().
 *
 * If the application includes this callback,
 * it must define @c SL_ZIGBEE_APPLICATION_HAS_INCOMING_ROUTE_ERROR_HANDLER
 * in its configuration header.
 *
 * @param status  ::SL_STATUS_ZIGBEE_SOURCE_ROUTE_FAILURE,
 * ::SL_STATUS_ZIGBEE_MANY_TO_ONE_ROUTE_FAILURE,
 * ::SL_STATUS_MAC_INDIRECT_TIMEOUT
 * @param target  The short ID of the remote node.
 */
void sl_zigbee_incoming_route_error_handler(sl_status_t status,
                                            sl_802154_short_addr_t target);

/**
 * @brief Invoke when a network status message
 * is received that informs the application of the Over-the-Air
 * error codes for the specific destination.
 *
 * Note: Network analyzer may flag this message as "route error" which
 * is the old name for the "network status" command.
 *
 * This handler is a superset of sl_zigbee_incoming_route_error_handler.
 * The old API was only invoking the handler for a couple of the possible
 * error codes and these were being translated into sl_status_t.
 *
 * To make the API more generic and extensible in future, the new
 * API sl_zigbee_incoming_network_status_handler simply copies the OTA
 * error code as is. If the application includes this callback,
 * it must define @c SL_ZIGBEE_APPLICATION_HAS_INCOMING_NETWORK_STATUS_HANDLER
 * in its configuration header.
 * @param errorCode  uint8_t
 * @param target  The short ID of the remote node.
 */
void sl_zigbee_incoming_network_status_handler(uint8_t errorCode,
                                               sl_802154_short_addr_t target);

/** @brief SoC only. It reports the arrival of a route record command frame
 * to the application.
 *
 * The route record command frame lists the short
 * IDs of the relays that were used along the route from the source to us.
 * This information is used by aggregators to be able to initiate
 * source routed messages.  The application must
 * define @c SL_ZIGBEE_APPLICATION_HAS_OVERRIDE_SOURCE_ROUTING in its
 * configuration header to use this.
 *
 * @param packetInfo      The received message information.
 * @param relayCount      The number of relays in relayList.
 * @param *relayList      The route record. Each relay in the list is an uint16_t node ID. The
 * list is passed as uint8_t * to avoid alignment problems.
 * @param consumed if set to true stack won't process the Incoming route record
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# relayList | length: relayCount | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
void sl_zigbee_override_incoming_route_record_handler(sl_zigbee_rx_packet_info_t *packetInfo,
                                                      uint8_t relayCount,
                                                      uint8_t *relayList,
                                                      bool* consumed);

/** @brief SoC only. The application can implement this callback to
 * supply source routes to outgoing messages.
 *
 * The application must define :SL_ZIGBEE_APPLICATION_HAS_OVERRIDE_SOURCE_ROUTING in its
 * configuration header to use this.  The application uses the
 * supplied destination to look up a source route.  If available,
 * the application appends the source route to the supplied header
 * using the proper frame format, as described in section 3.4.1.9
 * "Source Route Subframe Field" of the ZigBee specification.
 * If a source route is appended, the stack takes care of
 * setting the proper flag in the network frame control field.
 * See app/util/source-route.c for a sample implementation.
 *
 * If header is :SL_ZIGBEE_NULL_MESSAGE_BUFFER the only action is to return
 * the size of the source route frame needed to the destination.
 *
 * @param destination   The network destination of the message.
 * @param *header        Pointer to the message buffer containing the partially
 * complete packet header.  The application appends the source
 * route frame to this header.
 * @param consumed if set to true stack would skip appending the existing source route entry from the table
 *
 * @return The size in bytes of the source route frame, or zero
 * if there is not one available.
 */
uint8_t sl_zigbee_internal_override_append_source_route_handler(sl_802154_short_addr_t destination,
                                                                sli_buffer_manager_buffer_t* header,
                                                                bool* consumed);

/** @brief DEPRECTAED sl_zigbee_override_incoming_route_record_handler should be used
 *  Reports the arrival of a route record command frame
 * to the application.
 *
 * The route record command frame lists the short
 * IDs of the relays that were used along the route from the source to us.
 * This information is used by aggregators to be able to initiate
 * source routed messages.  The application must
 * define @c SL_ZIGBEE_APPLICATION_HAS_SOURCE_ROUTING in its
 * configuration header to use this.
 *
 * @param packetInfo      The received message information.
 * @param relayCount      The number of relays in relayList.
 * @param *relayList      The route record. Each relay in the list is an uint16_t node ID. The
 * list is passed as uint8_t * to avoid alignment problems.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# relayList | length: relayCount | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
void sl_zigbee_incoming_route_record_handler(sl_zigbee_rx_packet_info_t *packetInfo,
                                             uint8_t relayCount,
                                             uint8_t *relayList);

/** @brief DEPRECATED sl_zigbee_internal_override_append_source_route_handler should be used
 * The application can implement this callback to
 * supply source routes to outgoing messages.
 *
 * The application must define :SL_ZIGBEE_APPLICATION_HAS_SOURCE_ROUTING in its
 * configuration header to use this.  The application uses the
 * supplied destination to look up a source route.  If available,
 * the application appends the source route to the supplied header
 * using the proper frame format, as described in section 3.4.1.9
 * "Source Route Subframe Field" of the ZigBee specification.
 * If a source route is appended, the stack takes care of
 * setting the proper flag in the network frame control field.
 * See app/util/source-route.c for a sample implementation.
 *
 * If header is :SL_ZIGBEE_NULL_MESSAGE_BUFFER the only action is to return
 * the size of the source route frame needed to the destination.
 *
 * @param destination   The network destination of the message.
 * @param header        The message buffer containing the partially
 * complete packet header.  The application appends the source
 * route frame to this header.
 *
 * @return The size in bytes of the source route frame, or zero
 * if there is not one available.
 */
uint8_t sl_zigbee_append_source_route_handler(sl_802154_short_addr_t destination,
                                              sli_buffer_manager_buffer_t header);

/** @brief Invoke by the stack when it has completed sending a message.
 *
 * @param status              An ::sl_status_t value of ::SL_STATUS_OK if an ACK was received from
 *                            the destination (for unicast requring an ACK) or
 *                            ::SL_STATUS_ZIGBEE_DELIVERY_FAILED if no ACK was received in case an
 *                            ACK was required.
 *
 * @param type                The type of message sent.
 *
 * @param indexOrDestination  The destination to which the message was sent.
 *                            For direct unicasts, the destination to which the message was sent;
 *                            for other unicasts, the address table or binding index to which the
 *                            message was sent.
 *                            The value is unspecified for multicasts and broadcasts.
 *
 * @param apsFrame            The APS frame for the message.
 *
 * @param messageTag          The value supplied in the ::sl_zigbee_send_unicast,
 *                            ::sl_zigbee_send_multivast or ::sl_zigbee_send_broadcast API.
 *
 * @param messageLength       The length of the message parameter in bytes.
 *
 * @param message             The message that was sent.
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# message | length: messageLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
void sl_zigbee_message_sent_handler(sl_status_t status,
                                    sl_zigbee_outgoing_message_type_t type,
                                    uint16_t indexOrDestination,
                                    sl_zigbee_aps_frame_t *apsFrame,
                                    uint16_t messageTag,
                                    uint8_t messageLength,
                                    uint8_t *message);

/** @brief Invoke by the EmberZNet stack when a message is received.
 *
 * The following functions may be called from ::sl_zigbee_incoming_message_handler():
 * - ::sl_zigbee_send_reply() (for incoming APS retried unicasts only)
 * - ::sl_zigbee_set_reply_binding()
 * - ::sl_zigbee_note_senders_binding()
 *
 * @param type      The type of the incoming message. One of the following:
 *  - ::SL_ZIGBEE_INCOMING_UNICAST
 *  - ::SL_ZIGBEE_INCOMING_UNICAST_REPLY
 *  - ::SL_ZIGBEE_INCOMING_MULTICAST
 *  - ::SL_ZIGBEE_INCOMING_MULTICAST_LOOPBACK
 *  - ::SL_ZIGBEE_INCOMING_BROADCAST
 *  - ::SL_ZIGBEE_INCOMING_BROADCAST_LOOPBACK
 *
 * @param apsFrame  The APS frame from the incoming message.
 *
 * @param packetInfo The received message information.
 *
 * @param messageLength The length of the received message in bytes.
 *
 * @param message   The incoming message.
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# message | length: messageLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
void sl_zigbee_incoming_message_handler(sl_zigbee_incoming_message_type_t type,
                                        sl_zigbee_aps_frame_t *apsFrame,
                                        sl_zigbee_rx_packet_info_t *packetInfo,
                                        uint8_t messageLength,
                                        uint8_t *message);

/** @brief Send a reply for an application that has received a unicast message.
 *
 * The reply will be included with the ACK that the stack
 * automatically sends back.
 *
 * @param destination      Node ID of the original message's sender
 *
 * @param apsFrame         APS Frame for the reply.
 *
 * @param messageLength    Length of the reply message.
 *
 * @param messageContents  A reply message.
 *
 * @return An ::sl_status_t value. For any result other than ::SL_STATUS_OK,
 * the message will not be sent.
 * - ::SL_STATUS_OK - The message has been submitted for transmission.
 * - ::SL_STATUS_INVALID_STATE - apsFrame's options do not include
 *     EMBER_APS_OPTION_REPLY and ZIGBEE_APS_FRAME_CONTROL_WANT_ACK.
 * - ::SL_STATUS_ALLOCATION_FAILED - Not enough memory was available to send the
 *     reply.
 * - ::SL_STATUS_BUSY - Either:
 *   -# No route available.
 *   -# Insufficient resources available in Network or MAC layers to send
 *      message.
 */
sl_status_t sl_zigbee_send_reply(sl_802154_short_addr_t destination,
                                 sl_zigbee_aps_frame_t* apsFrame,
                                 uint8_t messageLength,
                                 uint8_t* messageContents);

/**@brief Set the fragment data to be used when sending a reply to a unicast
 * message.
 * @note  This function may be called only from within
 * ::sl_zigbee_incoming_message_handler().
 *
 * @param fragmentData The low byte is the block number of the reply. The high
 * byte is the ACK bitfield of the reply.
 */
void sl_zigbee_set_reply_fragment_data(uint16_t fragmentData);

/** @brief Setter function for address table entry
 *
 * This function will also check other address table entries, the child
 * table and the neighbor table to see if the node ID for the given
 * EUI64 is already known. If known, this function will also set
 * the node ID. If not known, it will set the node ID to ::SL_ZIGBEE_UNKNOWN_NODE_ID.
 *
 * Usually the application will not need to set the short ID in the address
 * table. Once the remote EUI64 is set, the stack is capable of figuring
 * out the short ID on its own.  However, in cases where the
 * application does set the short ID, the application must set the
 * remote EUI64 prior to setting the short ID.
 *
 * @param addressTableIndex  The index of an address table entry.
 * @eui64                    The EUI64 to use for the address table entry.
 * @param id                 The short ID corresponding to the remote node whose
 *                           EUI64 is stored in the address table at the given index or
 *                           ::SL_ZIGBEE_TABLE_ENTRY_UNUSED_NODE_ID which indicates that the entry
 *                           stored in the address table at the given index is not in use.
 *
 * @return ::SL_STATUS_OK if the info was successfully set,
 * and ::SL_STATUS_ZIGBEE_ADDRESS_TABLE_ENTRY_IS_ACTIVE otherwise.
 */
sl_status_t sl_zigbee_set_address_table_info(uint8_t addressTableIndex,
                                             sl_802154_long_addr_t eui64,
                                             sl_802154_short_addr_t id);

/** @brief Indicate whether any messages are currently being
 * sent using this address table entry.
 *
 * Note that this function does
 * not indicate whether the address table entry is unused. To
 * determine whether an address table entry is unused, check the
 * remote node ID.  The remote node ID will have the value
 * ::SL_ZIGBEE_TABLE_ENTRY_UNUSED_NODE_ID when the address table entry is
 * not in use.
 *
 * @param addressTableIndex  The index of an address table entry.
 *
 * @return True if the address table entry is active, false otherwise.
 */
bool sl_zigbee_address_table_entry_is_active(uint8_t addressTableIndex);

/** @brief Getter function for address table entry info
 *
 * @param addressTableIndex  The index of an address table entry.
 * @param eui64              The EUI64 of the address table entry is copied
 *                           to this location.
 *
 * @param nodeId             One of the following is copied to this location:
 *                           - The short ID corresponding to the remote node
 *                           whose EUI64 is stored in the address table at the given index.
 *                           - ::SL_ZIGBEE_UNKNOWN_NODE_ID - Indicates that the EUI64 stored in the
 *                           address table at the given index is valid but the short ID is
 *                           currently unknown.
 *                           - ::SL_ZIGBEE_DISCOVERY_ACTIVE_NODE_ID - Indicates that the EUI64 stored
 *                           in the address table at the given location is valid and network
 *                           address discovery is underway.
 *                           - ::SL_ZIGBEE_TABLE_ENTRY_UNUSED_NODE_ID - Indicates that the entry
 *                           stored in the address table at the given index is not in use.
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# nodeId #}
 * {# eui64 #}
 */
sl_status_t sl_zigbee_get_address_table_info(uint8_t addressTableIndex,
                                             sl_802154_short_addr_t *nodeId,
                                             sl_802154_long_addr_t eui64);

/** @brief Tell the stack whether or not the normal interval between
 * retransmissions of a retried unicast message should be increased by
 * ::SL_ZIGBEE_INDIRECT_TRANSMISSION_TIMEOUT.
 *
 * The interval needs to be increased when
 * sending to a sleepy node so that the message is not retransmitted until the
 * destination has had time to wake up and poll its parent. The stack will
 * automatically extend the timeout:
 * - For our own sleepy children.
 * - When an address response is received from a parent on behalf of its child.
 * - When an indirect transaction expiry route error is received.
 * - When an end device announcement is received from a sleepy node.
 *
 * @param remoteEui64      The address of the node for which the timeout
 *                         is to be set.
 *
 * @param extendedTimeout  True if the retry interval should be increased by
 *                         ::SL_ZIGBEE_INDIRECT_TRANSMISSION_TIMEOUT.
 *                         False if the normal retry interval should be used.
 *
 * @return SL_STATUS_OK if successful, else SL_STATUS_FAIL
 */
sl_status_t sl_zigbee_set_extended_timeout(sl_802154_long_addr_t remoteEui64, bool extendedTimeout);

/** @brief Indicate whether or not the stack will extend the normal
 * interval between retransmissions of a retried unicast message by
 * ::SL_ZIGBEE_INDIRECT_TRANSMISSION_TIMEOUT.
 *
 * @param remoteEui64  The address of the node for which the timeout is to be
 * returned.
 *
 * @return SL_STATUS_OK if the retry interval will be increased by
 * ::SL_ZIGBEE_INDIRECT_TRANSMISSION_TIMEOUT and SL_STATUS_FAIL if the normal retry interval
 * will be used.
 */
sl_status_t sl_zigbee_get_extended_timeout(sl_802154_long_addr_t remoteEui64);

/** @brief Invoke by the EmberZNet stack when an ID conflict is
 * discovered, that is, two different nodes in the network were found
 * to be using the same short ID.
 *
 * The stack automatically removes the conflicting short ID
 * from its internal tables (address, binding, route, neighbor, and
 * child tables).  The application should discontinue any other use
 * of the ID.  If the application includes this callback, it must
 * define ::SL_ZIGBEE_APPLICATION_HAS_ID_CONFLICT_HANDLER in its configuration
 * header.
 *
 * @param conflictingId  The short ID for which a conflict was detected.
 */
void sl_zigbee_id_conflict_handler(sl_802154_short_addr_t conflictingId);

/** @brief Indicate whether there are pending messages in the APS retry queue.
 *
 * @return True if there is at least a pending message belonging to the current
 * network in the APS retry queue, false otherwise.
 */
bool sl_zigbee_pending_acked_messages(void);

/** @brief Returns the multicast table.
 *
 * Each entry contains a multicast ID
 * and an endpoint, indicating that the endpoint is a member of the multicast
 * group.  Only devices with an endpoint in a multicast group will receive
 * messages sent to that multicast group.
 *
 * Entries with with an endpoint of 0 are ignored (the ZDO does not a member
 * of any multicast groups).  All endpoints are initialized to 0 on startup.
 */
sl_zigbee_multicast_table_entry_t* sl_zigbee_get_multicast_table(void);

/** @brief Sets the multicast table pointer.
 *
 */
sl_status_t sl_zigbee_set_multicast_table(const sl_zigbee_multicast_table_entry_t* entry);

/** @brief Return the number of entries in the multicast table.
 */
uint8_t sl_zigbee_get_multicast_table_size(void);

/** @brief Set the number of entries in the multicast table.
 */
sl_status_t sl_zigbee_set_multicast_table_size(uint8_t size);

/** @brief Allows the higher layers to control the broadcast behavior of
 * a routing device. The originating device will rebroadcast the maximum number of times and
 * The configurations below only restrict the number of broadcasts from neighboring routers.
 * The configuration settings must be done on each node.
 *
 * @param config         of the type sl_passive_ack_config_enum_t
 *                        SL_PASSIVE_ACK_DEFAULT_CONFIG - All non originating configured nodes check for passive acks from
 *                                                all neighbors. If no passive acks received it will rebroadcast max times.
 *                        SL_PASSIVE_ACK_DISABLE - Disable passive ack. All configured nodes rebroadcast the incoming processed
 *                                                broadcast the maximum configured number of times.
 *                        SL_PASSIVE_ACK_THRESHOLD_WITH_REBROADCAST - All non originating configured nodes check for passive acks from
 *                                                minAcksNeeded neighbors. They will rebroadcast received message at least once even
 *                                                if all passive acks have been received. If no passive acks received it will rebroadcast max times.
 *
 *                        SL_PASSIVE_ACK_THRESHOLD_NO_REBROADCAST - All non originating configured nodes check for passive acks from
 *                                                minAcksNeeded neighbors. They will not rebroadcast received message
 *                                                if all passive acks have been received. If no passive acks received it will rebroadcast max times.
 *                        SL_PASSIVE_ACK_THRESHOLD_WITH_REBROADCAST_ALL_NODES - This configuration is for both originating and relaying (non originating nodes).
 *                                                All configured nodes check for passive acks from
 *                                                minAcksNeeded neighbors. They will not rebroadcast received message if all passive acks have been received.
 *                                                If no passive acks received it will rebroadcast max times if minAcksNeeded is not set to 0
 *
 *
 *
 *  @param minAcksNeeded  The minimum number of acknowledgments (re-broadcasts)
 * to wait for until deeming the broadcast transmission complete.
 *
 * @return ::SL_STATUS_OK if set passive ack success; SL_STATUS_INVALID_PARAMETER when
 * pass wrong config argument
 */
sl_status_t sl_zigbee_set_passive_ack_config(sl_passive_ack_config_enum_t config, uint8_t minAcksNeeded);

/** @brief Set the number of broadcast passive acknowledgments required before
 * terminating a broadcast transmission. A value of 0xFF causes the node to wait
 * for all neighbors to re-broadcast the packet before terminating the
 * transmission. The default value is 0xFF.
 * API is kept for backwards compatibility.
 *
 * @param minAcksNeeded  The minimum number of acknowledgments (re-broadcasts)
 * to wait for until deeming the broadcast transmission complete.
 *
 * @return ::SL_STATUS_OK if set passive ack success; SL_STATUS_INVALID_PARAMETER when
 * pass wrong config argument
 */
#define sl_zigbee_broadcast_set_min_acks_needed(minAcksNeeded) \
  sl_zigbee_set_passive_ack_config(SL_PASSIVE_ACK_THRESHOLD_WITH_REBROADCAST, minAcksNeeded)

/** @brief Intercept an incoming packet from the stack and hands off to a plugin
 * for further processing
 *
 * @param packetType  The type of packet and the target stack layer.  See
 * ::sl_zigbee_zigbee_packet_type_t.
 * @param packetBuffer  The ::sli_buffer_manager_buffer_t containing the packet.
 * @parma index  The starting index of the relevant packet data.  The plugin\
 * will receive a flat copy of the packet starting from this index.
 * @param data  Auxiliary data pointer
 *
 * @return  See ::sl_zigbee_packet_action_t
 */
sl_zigbee_packet_action_t sl_zigbee_internal_packet_handoff_incoming_handler(sl_zigbee_zigbee_packet_type_t packetType,
                                                                             sli_buffer_manager_buffer_t packetBuffer,
                                                                             uint8_t index,
                                                                             void *data);

/** @brief Intercept an outgoing packet from the stack and hands off to a plugin
 * for further processing
 *
 * @param packetType  The type of packet and the source stack layer.  See
 * ::sl_zigbee_zigbee_packet_type_t.
 * @param packetBuffer  The ::sli_buffer_manager_buffer_t containing the packet.
 * @param index  The starting index of the relevant packet data.  The plugin\
 * will receive a flat copy of the packet starting from this index.
 * @param data  Auxiliary data pointer
 *
 * @return  See ::sl_zigbee_packet_action_t
 */
sl_zigbee_packet_action_t sl_zigbee_internal_packet_handoff_outgoing_handler(sl_zigbee_zigbee_packet_type_t packetType,
                                                                             sli_buffer_manager_buffer_t packetBuffer,
                                                                             uint8_t index,
                                                                             void *data);

/** @brief Intercept an outgoing packet from the Zigbee stack and hands it off
 * to the relevant plugins for possible further processing and forwarding to
 * non 15.4 interfaces
 *
 * @param mac_index  The interface id from which this packet would need to be
 * sent out
 * @param packet_length Length of this packet.
 * @param packet_contents Pointer to the contents of this packet.
 * @param priority  Possible priority of this packet vs other packets that need to
 * be sent out on the same interface
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# packet_contents | length: packet_length | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
void sl_zigbee_redirect_outgoing_message_handler(uint8_t mac_index,
                                                 uint8_t packet_length,
                                                 uint8_t* packet_contents,
                                                 uint8_t priority);

/** @brief Call when the stack receives a packet that is meant
 * for one of the protocol layers specified in ::sl_zigbee_zigbee_packet_type_t.
 *
 *
 * The packetType argument is one of the values of the
 * ::sl_zigbee_zigbee_packet_type_t enum. If the stack receives an 802.15.4
 * MAC beacon, it will call this function with the packetType argument
 * set to ::SL_ZIGBEE_ZIGBEE_PACKET_TYPE_BEACON.
 *
 * The implementation of this callback may alter the data contained in
 * packetData, modify options and flags in the axillary data, or
 * consume the packet itself, either sending the message, or discarding
 * it as it sees fit.
 *
 * @param packetType The type of packet received. See
 * ::sl_zigbee_zigbee_packet_type_t.
 * @param packetData A flat buffer containing the packet contents
 * the buffer starts with the command id followed by the payload
 * @param size_p a pointer to the size of the packet data
 * @param data This is a pointer to auxiliary data for the command.
 *
 * @return a ::sl_zigbee_packet_action_t indicating what action should be taken for
 * the packet, SL_ZIGBEE_ACCEPT_PACKET, SL_ZIGBEE_DROP_PACKET, or SL_ZIGBEE_MANGLE_PACKET
 */
sl_zigbee_packet_action_t sl_zigbee_af_incoming_packet_filter_cb(sl_zigbee_zigbee_packet_type_t packetType,
                                                                 uint8_t* packetData,
                                                                 uint8_t* size_p,
                                                                 void *data);

/** @brief The stack is preparing to send a protocol layer packet.
 *
 * This is called when the stack is preparing to send a packet from one
 * of the protocol layers specified in ::sl_zigbee_zigbee_packet_type_t.
 *
 * The packetType argument is one of the values of the
 * ::sl_zigbee_zigbee_packet_type_t enum. If the stack is preparing to send an
 * 802.15.4 MAC beacon, it will call this function with the packetType
 * argument set to ::SL_ZIGBEE_ZIGBEE_PACKET_TYPE_BEACON.
 *
 * The implementation of this callback may alter the data contained in
 * packetData, modify options and flags in the axillary data, or
 * consume the packet itself, either sending the message, or discarding
 * it as it sees fit.
 *
 * @param packetType The type of packet received. See
 * ::sl_zigbee_zigbee_packet_type_t.
 * @param packetData A flat buffer containing the packet contents
 * the buffer starts with the command id followed by the payload
 * @param size_p a pointer to the size of the packet data
 * @param data This is a pointer to auxiliary data for the command. ZDO
 * commands pass the ::sl_zigbee_aps_frame_t associated with the packet here. Otherwise,
 * this value is NULL.
 *
 * @return a ::sl_zigbee_packet_action_t indicating what action should be taken for
 * the packet, SL_ZIGBEE_ACCEPT_PACKET, SL_ZIGBEE_DROP_PACKET, or SL_ZIGBEE_MANGLE_PACKET
 */
sl_zigbee_packet_action_t sl_zigbee_af_outgoing_packet_filter_cb(sl_zigbee_zigbee_packet_type_t packetType,
                                                                 uint8_t* packetData,
                                                                 uint8_t* size_p,
                                                                 void* data);

/** @brief A callback invoked by the ZigBee GP stack when a GPDF is received..
 *
 * @param status The status of the GPDF receive.
 * @param gpdLink The gpdLink value of the received GPDF.
 * @param sequenceNumber The GPDF sequence number.
 * @param addr The address of the source GPD.

 * @param gpdfSecurityLevel The security level of the received GPDF.
 * @param gpdfSecurityKeyType The securityKeyType used to decrypt/authenticate the incoming GPDF.
 * @param autoCommissioning Whether the incoming GPDF had the auto-commissioning bit set.
 * @param bidirectionalInfo Bidirectional information represented in bitfields, where bit0 holds
 * the rxAfterTx of incoming gpdf and bit1 holds if tx queue is available
 * for outgoing gpdf.
 * @param gpdSecurityFrameCounter The security frame counter of the incoming GDPF.
 * @param gpdCommandId The gpdCommandId of the incoming GPDF.
 * @param mic The received MIC of the GPDF.
 * @param proxyTableIndex The proxy table index of the corresponding proxy table entry to the
 * incoming GPDF.
 * @param gpdCommandPayloadLength The length of the GPD command payload.
 * @param gpdCommandPayload The GPD command payload.
 * @param packetInfo Rx packet information.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# gpdCommandPayload | length: gpdCommandPayloadLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
void sl_zigbee_gpep_incoming_message_handler(
  sl_zigbee_gp_status_t status,
  uint8_t gpdLink,
  uint8_t sequenceNumber,
  sl_zigbee_gp_address_t *addr,
  sl_zigbee_gp_security_level_t gpdfSecurityLevel,
  sl_zigbee_gp_key_type_t gpdfSecurityKeyType,
  bool autoCommissioning,
  uint8_t bidirectionalInfo,
  uint32_t gpdSecurityFrameCounter,
  uint8_t gpdCommandId,
  uint32_t mic,
  uint8_t proxyTableIndex,
  uint8_t gpdCommandPayloadLength,
  uint8_t *gpdCommandPayload,
  sl_zigbee_rx_packet_info_t *packetInfo);

/** @brief Add a network packet into the incoming network queue.
 *
 * Quality: Experimental API for prototyping.
 *
 * The content of the networkPacket follows the formats below:
 * ----Encrypted NWK Packet----
 * NWK Header   (8 bytes)
 * NWK Security (14 bytes)
 * APS Header   (8 bytes)
 * APS Payload  (Variable)
 * NWK MIC      (4 bytes)
 *
 * ----Unencrypted NWK Packet----
 * NWK Header   (8 bytes)
 * APS Header   (8 bytes)
 * APS Payload  (Variable)
 *
 * Noted: This function does not free up the memory pointed by
 * the networkPacket pointer. Users may need to free up the memory
 * after calling this function. The network packet should not be larger than
 * 115 bytes (TRANSMIT_BUFFER_SIZE 126 bytes - PACKET_HEADER_OVERHEAD 11 bytes).
 *
 * @param rssi                 The RSSI of the incoming packet.
 * @param lqi                  The LQI of the incoming packet.
 * @param nwk_packet           The network packet, for more information see
 * ::sl_nwk_packet_exchange_t.
 *
 * @return ::SL_STATUS_OK if the network packet was successfully added into
 * the network queue, otherwise ::SL_STATUS_ALLOCATION_FAILED or ::SL_STATUS_MESSAGE_TOO_LONG.
 */
sl_status_t slx_zigbee_add_to_incoming_network_queue(int8_t rssi,
                                                     uint8_t lqi,
                                                     const sl_nwk_packet_exchange_t *nwk_packet);

/** @} END addtogroup */

/**
 * <!-- HIDDEN
 * @page 2p5_to_3p0
 * <hr>
 * The file message.h has been added to this documentation for @ref message API
 * and includes these changes:
 * <ul>
 * <li> <b>New items</b>
 * <ul>
 * <li> sl_zigbee_send_many_to_one_route_request()
 * <li> sl_zigbee_address_table_entry_is_active()
 * <li> sl_zigbee_set_address_table_remote_eui64()
 * <li> sl_zigbee_set_address_table_remote_node_id()
 * <li> sl_zigbee_get_extended_timeout()
 * <li> sl_zigbee_get_address_table_remote_eui64()
 * <li> sl_zigbee_get_address_table_remote_node_id()
 * <li> sl_zigbee_id_conflict_handler()
 * <li> sl_zigbee_incoming_many_to_one_route_request_handler()
 * <li> sli_zigbee_incoming_route_record()
 * <li> sl_zigbee_set_extended_timeout()
 * <li> ::sli_zigbee_multicast_table
 * <li> ::sli_zigbee_multicast_table_size
 * <li> ::SL_ZIGBEE_PRIVATE_PROFILE_ID
 * </ul>
 * <li> <b>Changed items</b>
 * <ul>
 * <li> sl_zigbee_message_sent() - Name changed to sl_zigbee_message_sent_handler(),
 *      new type, index, and apsFrame arguments, and moved from sl_zigbee.h.
 * <li> sl_zigbee_send_multicast() - The arguments and over-the-air protocol have
 *      changed and moved from sl_zigbee.h.
 * <li> sl_zigbee_send_unicast() - The arguments and over-the-air protocol have
 *      changed and moved from sl_zigbee.h.
 *      New functionality subsumes the former emberSendDatagram().
 * <li> sl_zigbee_send_broadcast() - New destination argument and moved from sl_zigbee.h.
 * <li> sl_zigbee_send_reply() - Cluster id argument changed from uint8_t to uint16_t
 *      and moved from sl_zigbee.h.
 * </ul>
 * <li> <b>Removed items</b>
 * <ul>
 * <li>
 * </ul>
 * </ul>
 * HIDDEN -->
 */

//retrieve packet info from stack globals for callbacks
void sli_zigbee_fill_rx_packet_info(sl_zigbee_rx_packet_info_t* packetInfo);

#ifdef __cplusplus
}
#endif

#endif // SILABS_MESSAGE_H
