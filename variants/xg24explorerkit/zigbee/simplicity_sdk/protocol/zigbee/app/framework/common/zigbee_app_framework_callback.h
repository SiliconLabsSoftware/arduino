/***************************************************************************//**
 * @file
 * @brief Zigbee application framework stack callbacks
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

// *** Generated file. Do not edit! ***
#ifndef ZIGBEE_APP_FRAMEWORK_CALLBACK_H
#define ZIGBEE_APP_FRAMEWORK_CALLBACK_H

/**
 * @addtogroup stack_callback
 * @{
 */

/** @brief
 * A callback invoked when receiving a message.
 * @param type Incoming message type
 * @param apsFrame The aps Frame
 * @param packetInfo Packet info
 * @param messageLength Message length
 * @param message message
 */
void sl_zigbee_af_incoming_message_cb(
  // Incoming message type
  sl_zigbee_incoming_message_type_t type,
  // The aps Frame
  sl_zigbee_aps_frame_t *apsFrame,
  // Rx packet information
  sl_zigbee_rx_packet_info_t *packetInfo,
  // Message length
  uint8_t messageLength,
  // Message pointer
  uint8_t *message);

/** @brief
 * A callback that allows marking application buffers
 */
void sl_zigbee_af_mark_buffers_cb(void);

/** @brief
 * incomingMfgTestMessageHandler
 */
void sl_zigbee_af_incoming_mfg_test_message_cb(
  uint8_t messageType,
  uint8_t dataLength,
  // Return:
  uint8_t *data);

/** @brief
 * Allow the application to decide if it wants to append a source route to
 * packet header itself
 *
 * @return Added bytes
 */
uint8_t sl_zigbee_af_override_append_source_route_cb(
  sl_802154_short_addr_t destination,
  // Return:
  sli_buffer_manager_buffer_t *header,
  // Return:
  bool *consumed);

/** @brief
 * A callback invoked when the status of the stack changes. If the status
 * parameter equals SL_STATUS_NETWORK_UP, then the getNetworkParameters command can
 * be called to obtain the new network parameters. If any of the parameters are
 * being stored in nonvolatile memory by the Host, the stored values should be
 * updated.
 * @param status Stack status
 */
void sl_zigbee_af_stack_status_cb(
  // Stack status
  sl_status_t status);

/** @brief
 * A callback that allows the app to redirect the packet
 * @param mac_index The mac index used to redirect messages
 * @param packet_length Length of the packet
 * @param packet_contents Contents of the packet
 * @param priority Transmit priority
 */
void sl_zigbee_af_redirect_outgoing_message_cb(
  // The mac index used to redirect messages
  uint8_t mac_index,
  // Packet length
  uint8_t packet_length,
  // Packet contents
  uint8_t* packet_contents,
  // Transmit priority
  uint8_t priority);

/** @brief
 * Reports the result of an energy scan for a single channel. The scan is not
 * complete until the scanCompleteHandler callback is called.
 * @param channel The 802.15.4 channel number that was scanned.
 * @param maxRssiValue The maximum RSSI value found on the channel.
 */
void sl_zigbee_af_energy_scan_result_cb(
  // The 802.15.4 channel number that was scanned.
  uint8_t channel,
  // The maximum RSSI value found on the channel.
  int8_t maxRssiValue);

/** @brief
 * Reports that a network was found as a result of a prior call to startScan.
 * Gives the network parameters useful for deciding which network to join.
 * @param networkFound The parameters associated with the network found.
 * @param lqi The link quality indication of the network found.
 * @param rssi The received signal strength indication of the network found.
 */
void sl_zigbee_af_network_found_cb(
  // The parameters associated with the network found.
  sl_zigbee_zigbee_network_t *networkFound,
  // The link quality indication of the network found.
  uint8_t lqi,
  // The received signal strength indication of the network found.
  int8_t rssi);

/** @brief
 * Returns the status of the current scan of type SL_ZIGBEE_ENERGY_SCAN or
 * SL_ZIGBEE_ACTIVE_SCAN. SL_STATUS_OK signals that the scan has completed. Other
 * error conditions signify a failure to scan on the channel specified.
 * @param channel The channel on which the current error occurred. Undefined for
   the case of SL_STATUS_OK.
 * @param status The error condition that occurred on the current channel. Value
   will be SL_STATUS_OK when the scan has completed.
 */
void sl_zigbee_af_scan_complete_cb(
  // The channel on which the current error occurred. Undefined for the case
  // of SL_STATUS_OK.
  uint8_t channel,
  // The error condition that occurred on the current channel. Value will be
  // SL_STATUS_OK when the scan has completed.
  sl_status_t status);

/** @brief
 * This function returns an unused panID and channel pair found via the find
 * unused panId scan procedure.
 * @param panId The unused panID which has been found.
 * @param channel The channel that the unused panID was found on.
 */
void sl_zigbee_af_unused_pan_id_found_cb(
  // The unused panID which has been found.
  sl_802154_pan_id_t panId,
  // The channel that the unused panID was found on.
  uint8_t channel);

/** @brief
 * Indicates that a child has joined or left.
 * @param index The index of the child of interest.
 * @param joining True if the child is joining. False the child is leaving.
 */
void sl_zigbee_af_child_join_cb(
  // The index of the child of interest.
  uint8_t index,
  // True if the child is joining. False the child is leaving.
  bool joining,
  // The node ID of the child.
  sl_802154_short_addr_t childId,
  // The EUI64 of the child.
  sl_802154_long_addr_t childEui64,
  // The node type of the child.
  sl_zigbee_node_type_t childType);

/** @brief
 * Callback fires when the duty cycle state has changed
 * @param channelPage The channel page whose duty cycle state has changed.
 * @param channel The channel number whose duty cycle state has changed.
 * @param state The current duty cycle state.
 */
void sl_zigbee_af_duty_cycle_cb(
  // The channel page whose duty cycle state has changed.
  uint8_t channelPage,
  // The channel number whose duty cycle state has changed.
  uint8_t channel,
  // The current duty cycle state.
  sl_zigbee_duty_cycle_state_t state,
  uint8_t totalDevices,
  sl_zigbee_per_device_duty_cycle_t *arrayOfDeviceDutyCycles);

/** @brief
 * The NCP used the external binding modification policy to decide how to handle
 * a remote set binding request. The Host cannot change the current decision, but
 * it can change the policy for future decisions using the setPolicy command.
 * @param entry The contents of the binding entry.
 * @param status ZDO status.
 */
void sl_zigbee_af_remote_set_binding_cb(
  // The contents of the binding entry.
  sl_zigbee_binding_table_entry_t *entry,
  // ZDO status.
  sl_zigbee_zdo_status_t status);

/** @brief
 * The NCP used the external binding modification policy to decide how to handle
 * a remote delete binding request. The Host cannot change the current decision,
 * but it can change the policy for future decisions using the setPolicy command.
 * @param index The index of the binding whose deletion was requested.
 * @param status ZDO status
 */
void sl_zigbee_af_remote_delete_binding_cb(
  // The index of the binding whose deletion was requested.
  uint8_t index,
  // ZDO status
  sl_zigbee_zdo_status_t status);

/** @brief
 * Indicates the result of a data poll to the parent of the local node.
 * @param status An sl_status_t value: SL_STATUS_OK - Data was received in
   response to the poll. SL_STATUS_MAC_NO_DATA - No data was pending.
   SL_STATUS_ZIGBEE_DELIVERY_FAILED - The poll message could not be sent.
   SL_STATUS_MAC_NO_ACK_RECEIVED - The poll message was sent but not acknowledged by
   the parent.
 */
void sl_zigbee_af_poll_complete_cb(
  // An sl_status_t value: SL_STATUS_OK - Data was received in response to
  // the poll. SL_STATUS_MAC_NO_DATA - No data was pending.
  // SL_STATUS_ZIGBEE_DELIVERY_FAILED - The poll message could not be sent.
  // SL_STATUS_MAC_NO_ACK_RECEIVED - The poll message was sent but not
  // acknowledged by the parent.
  sl_status_t status);

/** @brief
 * Indicates that the local node received a data poll from a child.
 * @param childId The node ID of the child that is requesting data.
 * @param transmitExpected True if transmit expected, false otherwise.
 */
void sl_zigbee_af_poll_cb(
  // The node ID of the child that is requesting data.
  sl_802154_short_addr_t childId,
  // True if transmit expected, false otherwise.
  bool transmitExpected);

/** @brief
 * debugHandler
 * @param messageLength debug message length
 * @param messageContents debug message
 */
void sl_zigbee_af_debug_cb(
  // debug message length
  uint8_t messageLength,
  // debug message
  uint8_t *messageContents);

/** @brief
 * A callback indicating that a many-to-one route to the concentrator with the
 * given short and long ID is available for use.
 * @param source The short id of the concentrator.
 * @param longId The EUI64 of the concentrator.
 * @param cost The path cost to the concentrator. The cost may decrease as
   additional route request packets for this discovery arrive, but the callback is
   made only once.
 */
void sl_zigbee_af_incoming_many_to_one_route_request_cb(
  // The short id of the concentrator.
  sl_802154_short_addr_t source,
  // The EUI64 of the concentrator.
  sl_802154_long_addr_t longId,
  // The path cost to the concentrator. The cost may decrease as additional
  // route request packets for this discovery arrive, but the callback is
  // made only once.
  uint8_t cost);

/** @brief
 * A callback invoked when a route error message is received. The error indicates
 * that a problem routing to or from the target node was encountered.
 * @param status SL_STATUS_ZIGBEE_SOURCE_ROUTE_FAILURE or SL_STATUS_ZIGBEE_MANY_TO_ONE_ROUTE_FAILURE.
 * @param target The short id of the remote node.
 */
void sl_zigbee_af_incoming_route_error_cb(
  // SL_STATUS_ZIGBEE_SOURCE_ROUTE_FAILURE or SL_STATUS_ZIGBEE_MANY_TO_ONE_ROUTE_FAILURE.
  sl_status_t status,
  // The short id of the remote node.
  sl_802154_short_addr_t target);

/** @brief
 * A callback invoked when a network status/route error message is received. The
 * error indicates that there was a problem sending/receiving messages from the
 * target node
 * @param errorCode One byte over-the-air error code from network status message
 * @param target The short ID of the remote node
 */
void sl_zigbee_af_incoming_network_status_cb(
  // One byte over-the-air error code from network status message
  uint8_t errorCode,
  // The short ID of the remote node
  sl_802154_short_addr_t target);

/** @brief
 * Reports the arrival of a route record command frame.
 * @param packetInfo The received message information.
 * @param relayCount The number of relays in relayList.
 * @param header Header.
 * @param relayListIndex The relay List Index.
 */
void sl_zigbee_af_incoming_route_record_cb(
  sl_zigbee_rx_packet_info_t *packetInfo,
  uint8_t relayCount,
  uint8_t *relayList);

/** @brief
 * A callback invoked by the EmberZNet stack when an id conflict is discovered,
 * that is, two different nodes in the network were found to be using the same
 * short id. The stack automatically removes the conflicting short id from its
 * internal tables (address, binding, route, neighbor, and child tables). The
 * application should discontinue any other use of the id.
 * @param conflictingId The short id for which a conflict was detected
 */
void sl_zigbee_af_id_conflict_cb(
  // The short id for which a conflict was detected
  sl_802154_short_addr_t conflictingId);

/** @brief
 * A callback invoked by the EmberZNet stack when a MAC passthrough message is
 * received.
 * @param messageType The type of MAC passthrough message received.
 * @param packetInfo  Info about incoming packet.
 * @param messageLength message length.
 * @param messageContents The raw message that was received.
 */
void sl_zigbee_af_mac_passthrough_message_cb(
  // The type of MAC passthrough message received.
  sl_zigbee_mac_passthrough_type_t messageType,
  // RX packet info
  sl_zigbee_rx_packet_info_t *packetInfo,
  // message length.
  uint8_t messageLength,
  // The raw message that was received.
  uint8_t *messageContents);

/** @brief
 * A callback invoked to inform the application that a stack token has changed.
 * @param tokenAddress The address of the stack token that has changed.
 */
void sl_zigbee_af_stack_token_changed_cb(
  // The address of the stack token that has changed.
  uint16_t tokenAddress);

/** @brief
 * A callback from the timer.
 * @param timerId Which timer generated the callback (0 or 1).
 */
void sl_zigbee_af_timer_cb(
  // Which timer generated the callback (0 or 1).
  uint8_t timerId);

/** @brief
 * This call is fired when a counter exceeds its threshold
 * @param type Type of Counter
 */
void sl_zigbee_af_counter_rollover_cb(
  // Type of Counter
  sl_zigbee_counter_type_t type);

/**
 * @brief Callback function invoked when an invalid RX channel is detected.
 *
 * This function is called when the RX channel changes to an invalid state.
 *
 * @param new_rx_channel The new RX channel that has been detected as invalid.
 * @param old_rx_channel The previous RX channel before the change.
 */
void sl_zigbee_af_mux_invalid_rx_cb(uint8_t new_rx_channel, uint8_t old_rx_channel);

/** @brief
 * A callback invoked by the EmberZNet stack when the MAC has finished
 * transmitting a raw message.
 * @param message message, message always returns SL_ZIGBEE_NULL_MESSAGE_BUFFER on
   host
 * @param status SL_STATUS_OK if the transmission was successful, or
   SL_STATUS_ZIGBEE_DELIVERY_FAILED if not
 */
void sl_zigbee_af_raw_transmit_complete_cb(
  // message
  uint8_t  messageLength,
  uint8_t* messageContents,
  // SL_STATUS_OK if the transmission was successful, or
  // SL_STATUS_ZIGBEE_DELIVERY_FAILED if not
  sl_status_t status);

/** @brief
 * A callback to inform the application that the Network Key has been updated and
 * the node has been switched over to use the new key. The actual key being used
 * is not passed up, but the sequence number is.
 * @param sequenceNumber The sequence number of the new network key.
 */
void sl_zigbee_af_switch_network_key_cb(
  // The sequence number of the new network key.
  uint8_t sequenceNumber);

/** @brief
 * This is a callback that indicates the success or failure of an attempt to
 * establish a key with a partner device.
 * @param partner This is the IEEE address of the partner that the device
   successfully established a key with. This value is all zeros on a failure.
 * @param status This is the status indicating what was established or why the
   key establishment failed.
 */
void sl_zigbee_af_zigbee_key_establishment_cb(
  // This is the IEEE address of the partner that the device successfully
  // established a key with. This value is all zeros on a failure.
  sl_802154_long_addr_t partner,
  // This is the status indicating what was established or why the key
  // establishment failed.
  sl_zigbee_key_status_t status);

/** @brief
 * A callback by the Crypto Engine indicating that a new ephemeral public/private
 * key pair has been generated. The public/private key pair is stored on the NCP,
 * but only the associated public key is returned to the host. The node's
 * associated certificate is also returned.
 * @param status The result of the CBKE operation.
 * @return ephemeralPublicKey The generated ephemeral public key.
 */
void sl_zigbee_af_generate_cbke_keys_cb(
  // The result of the CBKE operation.
  sl_status_t status,
  // Return: The generated ephemeral public key.
  sl_zigbee_public_key_data_t *ephemeralPublicKey);

/** @brief
 * A callback to indicate that the NCP has finished calculating the Secure
 * Message Authentication Codes (SMAC) for both the initiator and responder. The
 * associated link key is kept in temporary storage until the host tells the NCP
 * to store or discard the key via sl_zigbee_clear_temporary_data_maybe_store_link_key().
 * @param status The Result of the CBKE operation.
 * @return initiatorSmac The calculated value of the initiator's SMAC
 * @return responderSmac The calculated value of the responder's SMAC
 */
void sl_zigbee_af_calculate_smacs_cb(
  // The Result of the CBKE operation.
  sl_status_t status,
  // Return: The calculated value of the initiator's SMAC
  sl_zigbee_smac_data_t *initiatorSmac,
  // Return: The calculated value of the responder's SMAC
  sl_zigbee_smac_data_t *responderSmac);

/** @brief
 * The handler that returns the results of the signing operation. On success, the
 * signature will be appended to the original message (including the signature
 * type indicator that replaced the startIndex field for the signing) and both
 * are returned via this callback.
 * @param status The result of the DSA signing operation.
 * @param messageLength The length of message.
 * @param messageContents The message and attached which includes the original
   message and the appended signature.
 */
void sl_zigbee_af_dsa_sign_cb(
  // The result of the DSA signing operation.
  sl_status_t status,
  // The length of message.
  uint8_t messageLength,
  // The message and attached which includes the original message and the
  // appended signature.
  uint8_t *messageContents);

/** @brief
 * This callback is executed by the stack when the DSA verification has completed
 * and has a result. If the result is SL_STATUS_OK, the signature is valid. If
 * the result is SL_STATUS_ZIGBEE_SIGNATURE_VERIFY_FAILURE then the signature is invalid. If
 * the result is anything else then the signature verify operation failed and the
 * validity is unknown.
 * @param status The result of the DSA verification operation.
 */
void sl_zigbee_af_dsa_verify_cb(
  // The result of the DSA verification operation.
  sl_status_t status);

/** @brief
 * A callback invoked by the EmberZNet stack when a bootload message is received.
 * @param longId The EUI64 of the sending node.
 * @param packetInfo  Info about incoming packet.
 * @param messageLength message length.
 * @param messageContents The bootload message that was sent.
 */
void sl_zigbee_af_incoming_bootload_message_cb(
  // The EUI64 of the sending node.
  sl_802154_long_addr_t longId,
  // packet info.
  sl_zigbee_rx_packet_info_t *packetInfo,
  // message length.
  uint8_t messageLength,
  // The bootload message that was sent.
  uint8_t *messageContents);

/** @brief
 * A callback invoked by the EmberZNet stack when the MAC has finished
 * transmitting a bootload message.
 * @param status An sl_status_t value of SL_STATUS_OK if an ACK was received
   from the destination or SL_STATUS_ZIGBEE_DELIVERY_FAILED if no ACK was received.
 * @param messageLength message length.
 * @param messageContents The bootload message that was sent.
 */
void sl_zigbee_af_bootload_transmit_complete_cb(
  // An sl_status_t value of SL_STATUS_OK if an ACK was received from the
  // destination or SL_STATUS_ZIGBEE_DELIVERY_FAILED if no ACK was received.
  sl_status_t status,
  // message length.
  uint8_t messageLength,
  // The bootload message that was sent.
  uint8_t *messageContents);

/** @brief
 * This callback is invoked when a ZLL network scan finds a ZLL network.
 * @param isDeviceInfoNull Used to interpret deviceInfo field.
 * @param packetInfo  Information about the packet received from the network.
 * @return networkInfo Information about the network.
 * @return deviceInfo Device specific information.
 */
void sl_zigbee_af_zll_network_found_cb(
  // Used to interpret deviceInfo field.
  bool isDeviceInfoNull,
  // Information about the received packet.
  sl_zigbee_rx_packet_info_t *packetInfo,
  // Return: Information about the network.
  const sl_zigbee_zll_network_t *networkInfo,
  // Return: Device specific information.
  const sl_zigbee_zll_device_info_record_t *deviceInfo);

/** @brief
 * This callback is invoked when a ZLL network scan is complete.
 * @param status Status of the operation.
 */
void sl_zigbee_af_zll_scan_complete_cb(
  // Status of the operation.
  sl_status_t status);

/** @brief
 * This callback is invoked when network and group addresses are assigned to a remote
 * mode in a network start or network join request.
 * @param packetInfo Information about the received packet.
 * @return addressInfo Address assignment information.
 */
void sl_zigbee_af_zll_address_assignment_cb(
  // Return: Address assignment information.
  const sl_zigbee_zll_address_assignment_t *addressInfo,
  // Information about the received packet.
  sl_zigbee_rx_packet_info_t *packetInfo);

/** @brief
 * This callback is invoked when the device is a target of a touch link.
 * @return networkInfo Information about the network.
 */
void sl_zigbee_af_zll_touch_link_target_cb(
  // Return: Information about the network.
  const sl_zigbee_zll_network_t *networkInfo);

/** @brief
 * A callback invoked by the EmberZNet stack when a raw MAC message that has
 * matched one of the application's configured MAC filters.
 * @param filterIndexMatch filter index match.
 * @param messageType message type.
 * @param packetInfo RX packet info.
 * @param messageLength message length.
 * @param messageContents message contents.
 */
void sl_zigbee_af_mac_filter_match_message_cb(
  // filter index match.
  uint8_t filterIndexMatch,
  // message type.
  sl_zigbee_mac_passthrough_type_t messageType,
  // RX packet info.
  sl_zigbee_rx_packet_info_t *packetInfo,
  // message length.
  uint8_t messageLength,
  // message contents.
  uint8_t *messageContents);

/** @brief
 * A callback to the GP endpoint to indicate the result of the GPDF transmission.
 * @param status An sl_status_t value indicating success or the reason for
   failure.
 * @param gpepHandle The handle of the GPDF.
 */
void sl_zigbee_af_d_gp_sent_cb(
  // An sl_status_t value indicating success or the reason for failure.
  sl_status_t status,
  // The handle of the GPDF.
  uint8_t gpepHandle);

/** @brief
 * This handler is called by the stack to report the number of conflict reports
 * exceeds SL_ZIGBEE_PAN_ID_CONFLICT_REPORT_THRESHOLD within a period of 1 minute )
 *
 * @return An sl_status_t value indicating success or the reason for failure.
 */
sl_status_t sl_zigbee_af_pan_id_conflict_cb(
  // Number of conflict reports
  int8_t conflictCount);

/** @brief
 * Inform the application that an orphan notification has been received. This is
 * generally not useful for applications. It could be useful in testing and is
 * included for this purpose.
 * @param longId The 8 byte EUI64 of the sender.
 */
void sl_zigbee_af_orphan_notification_cb(
  // The 8 byte EUI64 of the sender.
  sl_802154_long_addr_t longId);

/** @brief
 * This handler is called when the value of a counter has changed
 * @param type Type of Counter
 * @param Info Counter Info and value
 */
void sl_zigbee_af_counters_cb(
  // Type of Counter
  sl_zigbee_counter_type_t type,
  // Counter Info and value
  sl_zigbee_counter_info_t Info);

/** @brief
 * This handler is called for messages that need to be matched against mac
 * passthrough filter
 *
 * @return True if mac passthrough filter was matched. False otherwise.
 */
bool sl_zigbee_af_mac_passthrough_filter_cb(
  // Return: Mac Header of the matched messgae
  uint8_t *macHeader);

/** @brief
 * A callback by the Crypto Engine indicating that a new ephemeral public/private
 * key pair has been generated. The public/private key pair is stored on the NCP,
 * but only the associated public key is returned to the host. The node's
 * associated certificate is also returned.
 * @param status The result of the CBKE operation.
 * @return ephemeralPublicKey The generated ephemeral public key.
 */
void sl_zigbee_af_generate_cbke_keys_283k1_handler_cb(
  // The result of the CBKE operation.
  sl_status_t status,
  // Return: The generated ephemeral public key.
  sl_zigbee_public_key_283k1_data_t *ephemeralPublicKey);

/** @brief
 * A callback to indicate that the NCP has finished calculating the Secure
 * Message Authentication Codes (SMAC) for both the initiator and responder. The
 * associated link key is kept in temporary storage until the host tells the NCP
 * to store or discard the key via sl_zigbee_clear_temporary_data_maybe_store_link_key().
 * @param status The Result of the CBKE operation.
 * @return initiatorSmac The calculated value of the initiator's SMAC
 * @return responderSmac The calculated value of the responder's SMAC
 */
void sl_zigbee_af_calculate_smacs_283k1_handler_cb(
  // The Result of the CBKE operation.
  sl_status_t status,
  // Return: The calculated value of the initiator's SMAC
  sl_zigbee_smac_data_t *initiatorSmac,
  // Return: The calculated value of the responder's SMAC
  sl_zigbee_smac_data_t *responderSmac);

/** @brief
 * A callback invoked by the ZigBee GP stack when a GPDF is received.
 * @param status The status of the GPDF receive.
 * @param gpdLink The gpdLink value of the received GPDF.
 * @param sequenceNumber The GPDF sequence number.
 * @param addr The address of the source GPD.
 * @param gpdfSecurityLevel The security level of the received GPDF.
 * @param gpdfSecurityKeyType The securityKeyType used to decrypt/authenticate
   the incoming GPDF.
 * @param autoCommissioning Whether the incoming GPDF had the auto-commissioning
   bit set.
 * @param bidirectionalInfo Bidirectional information represented in bitfields,
   where bit0 holds the rxAfterTx of incoming gpdf and bit1 holds if tx queue is
   available for outgoing gpdf.
 * @param gpdSecurityFrameCounter The security frame counter of the incoming
   GDPF.
 * @param gpdCommandId The gpdCommandId of the incoming GPDF.
 * @param mic The received MIC of the GPDF.
 * @param proxyTableIndex The proxy table index of the corresponding proxy table
   entry to the incoming GPDF.
 * @param gpdCommandPayloadLength The length of the GPD command payload.
 * @param gpdCommandPayload The GPD command payload.
 */
void sl_zigbee_af_gpep_incoming_message_cb(
  // The status of the GPDF receive.
  sl_zigbee_gp_status_t status,
  // The gpdLink value of the received GPDF.
  uint8_t gpdLink,
  // The GPDF sequence number.
  uint8_t sequenceNumber,
  // The address of the source GPD.
  sl_zigbee_gp_address_t *addr,
  // The security level of the received GPDF.
  sl_zigbee_gp_security_level_t gpdfSecurityLevel,
  // The securityKeyType used to decrypt/authenticate the incoming GPDF.
  sl_zigbee_gp_key_type_t gpdfSecurityKeyType,
  // Whether the incoming GPDF had the auto-commissioning bit set.
  bool autoCommissioning,
  // Bidirectional information represented in bitfields, where bit0 holds
  // the rxAfterTx of incoming gpdf and bit1 holds if tx queue is available
  // for outgoing gpdf.
  uint8_t bidirectionalInfo,
  // The security frame counter of the incoming GDPF.
  uint32_t gpdSecurityFrameCounter,
  // The gpdCommandId of the incoming GPDF.
  uint8_t gpdCommandId,
  // The received MIC of the GPDF.
  uint32_t mic,
  // The proxy table index of the corresponding proxy table entry to the
  // incoming GPDF.
  uint8_t proxyTableIndex,
  // The length of the GPD command payload.
  uint8_t gpdCommandPayloadLength,
  // The GPD command payload.
  uint8_t *gpdCommandPayload,
  // Rx packet information
  sl_zigbee_rx_packet_info_t *packetInfo);

/** @brief
 * Rtos Stack Wakeup Isr Handler
 */
void sl_zigbee_af_rtos_stack_wakeup_isr_cb(void);

/** @brief
 * RadioNeedsCalibratingHandler
 */
void sl_zigbee_af_radio_needs_calibrating_cb(void);

/** @brief
 * scanErrorHandler
 * @param status The error status of a scan
 */
void sl_zigbee_af_scan_error_cb(
  // The error status of a scan
  sl_status_t status);

/** @brief
 * A callback invoked when receiving a message.
 * Used when AF Support component is enabled on NCP.
 * User can use apsFrame to filter for which ZCL messages they want to process on NCP.
 * If this function returns true then the message is being processed on NCP, otherwise it
 * will be forwarded to the Host.
 * @param apsFrame The aps Frame
 */
bool sl_zigbee_af_support_incoming_message_cb(
  // The aps Frame
  sl_zigbee_aps_frame_t *apsFrame);

/** @} */ // stack-callback group

#endif // ZIGBEE_APP_FRAMEWORK_CALLBACK_H
