/***************************************************************************//**
 * @file
 * @brief ZigBee Device Object (ZDO) functions not provided by the stack.
 * See @ref util_zdo for documentation.
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

#ifndef SILABS_ZIGBEE_DEVICE_LIBRARY_H
#define SILABS_ZIGBEE_DEVICE_LIBRARY_H

/// @addtogroup util_zdo
/// For getting information about nodes of a ZigBee network via a
/// ZigBee Device Object (ZDO). See zigbee-device-library.h and
/// zigbee-device-common.h for source code.
///
/// The ZDO library provides functions that construct and send several common ZDO
/// requests. It also provides a function for extracting the two addresses from
/// a ZDO address response. The format of all the ZDO requests and responses that
/// the stack supports is described in stack/include/zigbee-device-stack.h.
/// Since the library doesn't handle all of these requests and responses,
/// the application must construct any other requests it wishes to send
/// and decode any other responses it wishes to receive.
///
/// The request sending functions do the following:
///  -# Construct a correctly formatted payload buffer.
///  -# Fill in the APS frame with the correct values.
///  -# Send the message by calling either ::sl_zigbee_send_broadcast()
///    or ::sl_zigbee_send_unicast().
///
/// The result of the send is reported to the application as normal
/// via ::sl_zigbee_message_sent_handler().
///
///
/// The following code shows an example of an application's use of
/// ::sl_zigbee_simple_descriptor_request().
/// The command interpreter would call this function and supply the arguments.
/// @code
/// void sendSimpleDescriptorRequest(sl_zigbee_command_state_t *state)
/// {
///   sl_802154_short_addr_t target = sl_zigbee_unsigned_command_argument(state, 0);
///   uint8_t targetEndpoint = sl_zigbee_unsigned_command_argument(state, 1);
///   if (sl_zigbee_simple_descriptor_request(target,
///                                    targetEndpoint,
///                                    SL_ZIGBEE_APS_OPTION_NONE) != SL_STATUS_OK) {
///     sli_legacy_serial_printf(SERIAL_PORT, "sl_zigbee_simple_descriptor_request failed\r\n");
///   }
/// }
/// @endcode
///
/// The following code shows an example of an application's use of
/// ::sl_zigbee_decode_address_response().
/// @code
/// void sl_zigbee_incoming_message_handler(sl_zigbee_incoming_message_type_t type,
///                                         sl_zigbee_aps_frame_t *apsFrame,
///                                         sl_zigbee_rx_packet_info_t *packetInfo,
///                                         uint8_t messageLength,
///                                         uint8_t *message)
/// {
///   if (apsFrame->profileId == SL_ZIGBEE_ZDO_PROFILE_ID) {
///     switch (apsFrame->clusterId) {
///     case NETWORK_ADDRESS_RESPONSE:
///     case IEEE_ADDRESS_RESPONSE:
///       {
///         sl_802154_long_addr_t eui64;
///         sl_802154_short_addr_t nodeId = sl_zigbee_decode_address_response(messageLength, message, eui64);
///         // Use nodeId and eui64 here.
///         break;
///       }
///     default:
///       // Handle other incoming ZDO responses here.
///     }
///   } else {
///     // Handle incoming application messages here.
///   }
/// }
/// @endcode
///
/// @{

/** @name Service Discovery Functions
 * @{
 */

/** Request the specified node to send a list of its endpoints that
 * match the specified application profile and, optionally, lists of input
 * and/or output clusters.
 *
 * @param target  The node whose matching endpoints are desired. The request can
 * be sent unicast or broadcast ONLY to the "RX-on-when-idle-address" (0xFFFD)
 * If sent as a broadcast, any node that has matching endpoints will send a
 * response.
 * @param profile  The application profile to match.
 * @param inCount Number of clusters in the input list.
 * @param inClusters  The list of input clusters. To not match any input
 * clusters, use NULL.
 * @param outCount Number of clusters in the output list.
 * @param outClusters  The list of output clusters. To not match any output
 * clusters, use NULL.
 * @param options  The options to use when sending the unicast request. See
 * sl_zigbee_send_unicast() for a description. This parameter is ignored if the target
 * is a broadcast address.
 *
 * @return An sl_status_t value. ::SL_STATUS_OK, ::SL_STATUS_ALLOCATION_FAILED,
 * ::SL_STATUS_NETWORK_DOWN or ::SL_STATUS_BUSY.
 */
sl_status_t sl_zigbee_match_descriptors_request(sl_802154_short_addr_t target,
                                                uint16_t profile,
                                                uint8_t inCount,
                                                uint16_t* inClusters,
                                                uint8_t outCount,
                                                uint16_t* outClusters,
                                                sl_zigbee_aps_option_t options);
/** @} END name group */

/** @} END addtogroup */

#endif // SILABS_ZIGBEE_DEVICE_LIBRARY_H
