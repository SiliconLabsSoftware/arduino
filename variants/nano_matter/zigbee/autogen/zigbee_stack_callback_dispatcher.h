/*****************************************************************************/
/**
 * Copyright 2020 Silicon Laboratories, Inc.
 *
 *****************************************************************************/
//
// *** Generated file. Do not edit! ***
//

#include PLATFORM_HEADER
#ifdef EZSP_HOST
#include "stack/include/sl_zigbee_types.h"
#else
#include "stack/include/sl_zigbee.h"
#endif // EZSP_HOST



#if defined(SL_ZIGBEE_AF_NCP) && defined(SL_CATALOG_ZIGBEE_AF_SUPPORT_PRESENT)
// Incoming Message
bool sli_zb_af_support_incoming_message(
      // The aps Frame
      sl_zigbee_aps_frame_t *apsFrame);
#endif // defined(SL_ZIGBEE_AF_NCP) && defined(SL_CATALOG_ZIGBEE_AF_SUPPORT_PRESENT)


// Incoming Message
void sli_zb_af_incoming_message(
      // Incoming message type
      sl_zigbee_incoming_message_type_t type,
      // The aps Frame
      sl_zigbee_aps_frame_t *apsFrame,
      // Received packet information
      sl_zigbee_rx_packet_info_t *packetInfo,
      // Message length
      uint8_t messageLength,
      // Message pointer
      uint8_t *message)
;
void sli_zigbee_af_incoming_message_callback(
      // Incoming message type
      sl_zigbee_incoming_message_type_t type,
      // The aps Frame
      sl_zigbee_aps_frame_t *apsFrame,
      // Received packet information
      sl_zigbee_rx_packet_info_t *packetInfo,
      // Message length
      uint8_t messageLength,
      // Message pointer
      uint8_t *message)
;

// Message Sent
void sli_zigbee_af_message_sent(
      // Message delivery status
      sl_status_t status,
      // Outgoing message type
      sl_zigbee_outgoing_message_type_t type,
      // Index or destination of the message
      uint16_t indexOrDestination,
      // The aps Frame
      sl_zigbee_aps_frame_t *apsFrame,
      // Message tag
      uint16_t messageTag,
      // The length of the message
      uint8_t messageLength,
      // Message data
      uint8_t *message)
;

// Trust Center post-join handler
void sli_zigbee_af_trust_center_post_join(
      // Joining node's id
      sl_802154_short_addr_t newNodeId,
      // Joining node's Eui64
      sl_802154_long_addr_t newNodeEui64,
      // Status
      sl_zigbee_device_update_t status,
      // Policy Decision
      sl_zigbee_join_decision_t policyDecision,
      // Parent Id of the joining node
      sl_802154_short_addr_t parentOfNewNode)
;

// Mark Buffers
void sli_zigbee_af_mark_buffers(void)
;

// Packet Handoff Incoming
void sli_zigbee_af_packet_handoff_incoming(
      sl_zigbee_zigbee_packet_type_t packetType,
      sli_buffer_manager_buffer_t packetBuffer,
      uint8_t index,
      // Return: 
      void *data)
;

// Packet Handoff Outgoing
void sli_zigbee_af_packet_handoff_outgoing(
      sl_zigbee_zigbee_packet_type_t packetType,
      sli_buffer_manager_buffer_t packetBuffer,
      uint8_t index,
      // Return: 
      void *data)
;

// Incoming Mfg Test Message
void sli_zigbee_af_incoming_mfg_test_message(
      uint8_t messageType,
      uint8_t dataLength,
      // Return: 
      uint8_t *data)
;

// Override Incoming Route Record
void sli_zigbee_af_override_incoming_route_record(
  sl_zigbee_rx_packet_info_t *packetInfo,
  uint8_t relayCount,
  uint8_t *relayList,
      // Return: 
      bool *consumed)
;

// Override Append Source Route
// Return: Added bytes
void sli_zigbee_af_override_append_source_route(
      sl_802154_short_addr_t destination,
      // Return: 
      sli_buffer_manager_buffer_t *header,
      // Return: 
      bool *consumed)
;

// Override Furthur Index For Source Route Add Entry
void sli_zigbee_af_override_furthur_index_for_source_route_add_entry(
      sl_802154_short_addr_t id,
      // Return: 
      uint8_t *furtherIndex)
;

// Stack Status
void sli_zigbee_af_stack_status(
      // Stack status
      sl_status_t status)
;
void sli_zigbee_af_stack_status_callback(
      // Stack status
      sl_status_t status)
;
void sli_zigbee_af_green_power_client_stack_status_callback(
      // Stack status
      sl_status_t status)
;
void sli_zigbee_af_network_creator_security_stack_status_callback(
      // Stack status
      sl_status_t status)
;
void sli_zigbee_af_network_steering_stack_status_callback(
      // Stack status
      sl_status_t status)
;
void sli_zigbee_af_reporting_stack_status_callback(
      // Stack status
      sl_status_t status)
;
void sli_zigbee_af_zll_commissioning_common_stack_status_callback(
      // Stack status
      sl_status_t status)
;

// Redirect Outgoing Message
void sli_zigbee_af_redirect_outgoing_message(
      // The mac index used to redirect messages
      uint8_t mac_index,
      // Packet length
      uint8_t packet_length,
      // Packet contents
      uint8_t* packet_contents,
      // Transmit priority
      uint8_t priority)
;

// Energy Scan Result
void sli_zigbee_af_energy_scan_result(
      // The 802.15.4 channel number that was scanned.
      uint8_t channel,
      // The maximum RSSI value found on the channel.
      int8_t maxRssiValue)
;
void sli_zigbee_af_scan_dispatch_energy_scan_result_callback(
      // The 802.15.4 channel number that was scanned.
      uint8_t channel,
      // The maximum RSSI value found on the channel.
      int8_t maxRssiValue)
;

// Network Found
void sli_zigbee_af_network_found(
      // The parameters associated with the network found.
      sl_zigbee_zigbee_network_t *networkFound,
      // The link quality indication of the network found.
      uint8_t lqi,
      // The received signal strength indication of the network found.
      int8_t rssi)
;
void sli_zigbee_af_scan_dispatch_network_found_callback(
      // The parameters associated with the network found.
      sl_zigbee_zigbee_network_t *networkFound,
      // The link quality indication of the network found.
      uint8_t lqi,
      // The received signal strength indication of the network found.
      int8_t rssi)
;

// Scan Complete
void sli_zigbee_af_scan_complete(
      // The channel on which the current error occurred. Undefined for the case
      // of SL_STATUS_OK.
      uint8_t channel,
      // The error condition that occurred on the current channel. Value will be
      // SL_STATUS_OK when the scan has completed.
      sl_status_t status)
;
void sli_zigbee_af_scan_dispatch_scan_complete_callback(
      // The channel on which the current error occurred. Undefined for the case
      // of SL_STATUS_OK.
      uint8_t channel,
      // The error condition that occurred on the current channel. Value will be
      // SL_STATUS_OK when the scan has completed.
      sl_status_t status)
;

// Unused Pan Id Found
void sli_zigbee_af_unused_pan_id_found(
      // The unused panID which has been found.
      sl_802154_pan_id_t panId,
      // The channel that the unused panID was found on.
      uint8_t channel)
;

// Child Join
void sli_zigbee_af_child_join(
      // The index of the child of interest.
      uint8_t index,
      // True if the child is joining. False the child is leaving.
      bool joining,
      // The node ID of the child.
      sl_802154_short_addr_t childId,
      // The EUI64 of the child.
      sl_802154_long_addr_t childEui64,
      // The node type of the child.
      sl_zigbee_node_type_t childType)
;

// Duty Cycle
void sli_zigbee_af_duty_cycle(
      // The channel page whose duty cycle state has changed.
      uint8_t channelPage,
      // The channel number whose duty cycle state has changed.
      uint8_t channel,
      // The current duty cycle state.
      sl_zigbee_duty_cycle_state_t state,
      // The total number of connected end devices that are being monitored for
      // duty cycle.
      uint8_t totalDevices,
      // Consumed duty cycles of end devices that are being monitored. The first
      // entry always be the local stack's nodeId, and thus the total aggregate
      // duty cycle for the device.
      sl_zigbee_per_device_duty_cycle_t *arrayOfDeviceDutyCycles)
;

// Remote Set Binding
void sli_zigbee_af_remote_set_binding(
      // The contents of the binding entry.
      sl_zigbee_binding_table_entry_t *entry,
      // ZDO response status.
      sl_zigbee_zdo_status_t status)
;

// Remote Delete Binding
void sli_zigbee_af_remote_delete_binding(
      // The index of the binding whose deletion was requested.
      uint8_t index,
      // ZDO response status
      sl_zigbee_zdo_status_t status)
;

// Poll Complete
void sli_zigbee_af_poll_complete(
      // An sl_status_t value: SL_STATUS_OK - Data was received in response to
      // the poll. SL_STATUS_MAC_NO_DATA - No data was pending.
      // SL_STATUS_ZIGBEE_DELIVERY_FAILED - The poll message could not be sent.
      // SL_STATUS_MAC_NO_ACK_RECEIVED - The poll message was sent but not
      // acknowledged by the parent.
      sl_status_t status)
;

// Poll
void sli_zigbee_af_poll(
      // The node ID of the child that is requesting data.
      sl_802154_short_addr_t childId,
      // True if transmit expected, false otherwise.
      bool transmitExpected)
;

// Debug
void sli_zigbee_af_debug(
      // debug message length
      uint8_t messageLength,
      // debug message
      uint8_t *messageContents)
;

// Incoming Many To One Route Request
void sli_zigbee_af_incoming_many_to_one_route_request(
      // The short id of the concentrator.
      sl_802154_short_addr_t source,
      // The EUI64 of the concentrator.
      sl_802154_long_addr_t longId,
      // The path cost to the concentrator. The cost may decrease as additional
      // route request packets for this discovery arrive, but the callback is
      // made only once.
      uint8_t cost)
;

// Incoming Route Error
void sli_zigbee_af_incoming_route_error(
      // SL_STATUS_ZIGBEE_SOURCE_ROUTE_FAILURE or SL_STATUS_ZIGBEE_MANY_TO_ONE_ROUTE_FAILURE.
      sl_status_t status,
      // The short id of the remote node.
      sl_802154_short_addr_t target)
;

// Incoming Network Status
void sli_zigbee_af_incoming_network_status(
      // One byte over-the-air error code from network status message
      uint8_t errorCode,
      // The short ID of the remote node
      sl_802154_short_addr_t target)
;

// Incoming Route Record
void sli_zigbee_af_incoming_route_record(
  sl_zigbee_rx_packet_info_t *packetInfo,
  uint8_t relayCount,
  uint8_t *relayList)
;

// Id Conflict
void sli_zigbee_af_id_conflict(
      // The short id for which a conflict was detected
      sl_802154_short_addr_t conflictingId)
;

// Mac Passthrough Message
void sli_zigbee_af_mac_passthrough_message(
      // The type of MAC passthrough message received.
      sl_zigbee_mac_passthrough_type_t messageType,
      // RX packet info.
      sl_zigbee_rx_packet_info_t *packetInfo,
      // message length.
      uint8_t messageLength,
      // The raw message that was received.
      uint8_t *messageContents)
;

// Stack Token Changed
void sli_zigbee_af_stack_token_changed(
      // The address of the stack token that has changed.
      uint16_t tokenAddress)
;

// Timer
void sli_zigbee_af_timer(
      // Which timer generated the callback (0 or 1).
      uint8_t timerId)
;

// Counter Rollover
void sli_zigbee_af_counter_rollover(
      // Type of Counter
      sl_zigbee_counter_type_t type)
;
void sli_zigbee_af_counter_rollover_callback(
      // Type of Counter
      sl_zigbee_counter_type_t type)
;

// mux_invalid_rx
void sli_zigbee_af_mux_invalid_rx(uint8_t new_rx_channel, uint8_t old_rx_channel)
;

// Raw Transmit Complete
void sli_zigbee_af_raw_transmit_complete(
      // message
      uint8_t  messageLength,
      uint8_t* messageContents,
      // SL_STATUS_OK if the transmission was successful, or
      // SL_STATUS_ZIGBEE_DELIVERY_FAILED if not
      sl_status_t status)
;

// Switch Network Key
void sli_zigbee_af_switch_network_key(
      // The sequence number of the new network key.
      uint8_t sequenceNumber)
;

// Zigbee Key Establishment
void sli_zigbee_af_zigbee_key_establishment(
      // This is the IEEE address of the partner that the device successfully
      // established a key with. This value is all zeros on a failure.
      sl_802154_long_addr_t partner,
      // This is the status indicating what was established or why the key
      // establishment failed.
      sl_zigbee_key_status_t status)
;
void sl_zigbee_af_network_creator_security_zigbee_key_establishment_cb(
      // This is the IEEE address of the partner that the device successfully
      // established a key with. This value is all zeros on a failure.
      sl_802154_long_addr_t partner,
      // This is the status indicating what was established or why the key
      // establishment failed.
      sl_zigbee_key_status_t status)
;
void sl_zigbee_af_update_tc_link_key_zigbee_key_establishment_cb(
      // This is the IEEE address of the partner that the device successfully
      // established a key with. This value is all zeros on a failure.
      sl_802154_long_addr_t partner,
      // This is the status indicating what was established or why the key
      // establishment failed.
      sl_zigbee_key_status_t status)
;

// Generate Cbke Keys
void sli_zigbee_af_generate_cbke_keys(
      // The result of the CBKE operation.
      sl_status_t status,
      // Return: The generated ephemeral public key.
      sl_zigbee_public_key_data_t *ephemeralPublicKey)
;

// Calculate Smacs
void sli_zigbee_af_calculate_smacs(
      // The Result of the CBKE operation.
      sl_status_t status,
      // Return: The calculated value of the initiator's SMAC
      sl_zigbee_smac_data_t *initiatorSmac,
      // Return: The calculated value of the responder's SMAC
      sl_zigbee_smac_data_t *responderSmac)
;

// Dsa Sign
void sli_zigbee_af_dsa_sign(
      // The result of the DSA signing operation.
      sl_status_t status,
      // Message length
      uint8_t messageLength,
      // The message that includes the original message and the
      // appended signature.
      uint8_t *message)
;

// Dsa Verify
void sli_zigbee_af_dsa_verify(
      // The result of the DSA verification operation.
      sl_status_t status)
;

// Incoming Bootload Message
void sli_zigbee_af_incoming_bootload_message(
      // The EUI64 of the sending node.
      sl_802154_long_addr_t longId,
      // RX packet info.
      sl_zigbee_rx_packet_info_t *packetInfo,
      // message length.
      uint8_t messageLength,
      // The bootload message that was sent.
      uint8_t *messageContents)
;

// Bootload Transmit Complete
void sli_zigbee_af_bootload_transmit_complete(
      // An sl_status_t value of SL_STATUS_OK if an ACK was received from the
      // destination or SL_STATUS_ZIGBEE_DELIVERY_FAILED if no ACK was received.
      sl_status_t status,
      // message length.
      uint8_t messageLength,
      // The bootload message that was sent.
      uint8_t *messageContents)
;

// Zll Network Found
void sli_zigbee_af_zll_network_found(
      // Information about the network.
      sl_zigbee_zll_network_t *networkInfo,
      // Used to interpret deviceInfo field.
      bool isDeviceInfoNull,
      // Device specific information.
      sl_zigbee_zll_device_info_record_t *deviceInfo,
      // RX packet info.
      sl_zigbee_rx_packet_info_t *packetInfo)
;

// Zll Scan Complete
void sli_zigbee_af_zll_scan_complete(
      // Status of the operation.
      sl_status_t status)
;

// Zll Address Assignment
void sli_zigbee_af_zll_address_assignment(
      // Address assignment information.
      sl_zigbee_zll_address_assignment_t *addressInfo,
      // Information about incoming packet.
      sl_zigbee_rx_packet_info_t *packetInfo)
;

// Zll Touch Link Target
void sli_zigbee_af_zll_touch_link_target(
      // Return: Information about the network.
      const sl_zigbee_zll_network_t *networkInfo)
;
void sli_zigbee_af_zll_touch_link_target_callback(
      // Return: Information about the network.
      const sl_zigbee_zll_network_t *networkInfo)
;

// Mac Filter Match Message
void sli_zigbee_af_mac_filter_match_message(
      // filter index match.
      uint8_t filterIndexMatch,
      // message type.
      sl_zigbee_mac_passthrough_type_t messageType,
      // RX packet info
      sl_zigbee_rx_packet_info_t *packetInfo,
      // message length.
      uint8_t messageLength,
      // message contents.
      uint8_t *messageContents)
;
void sli_zigbee_af_interpan_mac_filter_match_message_callback(
      // filter index match.
      uint8_t filterIndexMatch,
      // message type.
      sl_zigbee_mac_passthrough_type_t messageType,
      // RX packet info
      sl_zigbee_rx_packet_info_t *packetInfo,
      // message length.
      uint8_t messageLength,
      // message contents.
      uint8_t *messageContents)
;

// D Gp Sent
void sli_zigbee_af_d_gp_sent(
      // An sl_status_t value indicating success or the reason for failure.
      sl_status_t status,
      // The handle of the GPDF.
      uint8_t gpepHandle)
;
void sli_zigbee_af_green_power_client_d_gp_sent_callback(
      // An sl_status_t value indicating success or the reason for failure.
      sl_status_t status,
      // The handle of the GPDF.
      uint8_t gpepHandle)
;

// Pan Id Conflict
// Return: An sl_status_t value indicating success or the reason for failure.
void sli_zigbee_af_pan_id_conflict(
      // Number of conflict reports
      int8_t conflictCount)
;

// Orphan Notification
void sli_zigbee_af_orphan_notification(
      // The 8 byte EUI64 of the sender.
      sl_802154_long_addr_t longId)
;

// Mac Passthrough Filter
// Return: True if mac passthrough filter was matched. False otherwise.
void sli_zigbee_af_mac_passthrough_filter(
      // Return: Mac Header of the matched messgae
      uint8_t *macHeader)
;

// Generate Cbke Keys Handler283k1
void sli_zigbee_af_generate_cbke_keys_handler283k1(
      // The result of the CBKE operation.
      sl_status_t status,
      // Return: The generated ephemeral public key.
      sl_zigbee_public_key_283k1_data_t *ephemeralPublicKey)
;

// Calculate Smacs Handler283k1
void sli_zigbee_af_calculate_smacs_283k1_handler(
      // The Result of the CBKE operation.
      sl_status_t status,
      // Return: The calculated value of the initiator's SMAC
      sl_zigbee_smac_data_t *initiatorSmac,
      // Return: The calculated value of the responder's SMAC
      sl_zigbee_smac_data_t *responderSmac)
;

// Gpep Incoming Message
void sli_zigbee_af_gpep_incoming_message(
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
      sl_zigbee_rx_packet_info_t *packetInfo)
;
void sli_zigbee_af_green_power_client_gpep_incoming_message_callback(
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
      sl_zigbee_rx_packet_info_t *packetInfo)
;

// Rtos Idle
// Return: True or False.
void sli_zigbee_af_rtos_idle(
      // Return: Idle time duration
      uint32_t *idleTimeMs)
;

// Radio Needs Calibrating
void sli_zigbee_af_radio_needs_calibrating(void)
;

// Scan Error
void sli_zigbee_af_scan_error(
      // The error status of a scan
      sl_status_t status)
;
