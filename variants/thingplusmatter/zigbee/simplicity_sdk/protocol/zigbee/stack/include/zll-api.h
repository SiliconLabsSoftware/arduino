/***************************************************************************//**
 * @file
 * @brief API for sending and receiving touchlink (formerly Zigbee Light Link) commissioning messages.
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

#ifndef SILABS_ZLL_API_H
#define SILABS_ZLL_API_H

#include "stack/include/sl_zigbee_types.h"

/**
 * @addtogroup zll
 * See zll-api.h for source code.
 * @{
 */

/** @brief Set the device type as a router or end device
 * (depending on the passed nodeType) and set up a distributed
 * commissioning network with the passed parameters.  If panId is 0xFFFF,
 * a random PAN ID will be generated.  If extendedPanId is set to all F's,
 * a random extended PAN ID will be generated.  If channel is 0xFF,
 * channel 11 will be used.
 * If all F values are passed for PAN ID or Extended PAN ID, the
 * randomly generated values will be returned in the passed structure.
 *
 * @param networkInfo A pointer to an ::sl_zigbee_zll_network_t struct indicating the
 *   network parameters to use when forming the network. If random values are
 *   requested, the stack's randomly generated values will be returned in the
 *   structure.
 * @param radioTxPower The radio output power at which a node is to operate.
 *
 * @return An ::sl_status_t value indicating whether the operation
 *   succeeded or why it failed.
 */
sl_status_t sl_zigbee_zll_form_network(sl_zigbee_zll_network_t* networkInfo,
                                       int8_t radioTxPower);

/** @brief Cause the device to send a NWK start or join to the
 *  target device, which causes the remote AND local device to start operating
 *  on a network together. If the local device is a factory new end device,
 *  it will send a touchlink NWK start to the target requesting that the
 *  target generate new network parameters. If the local device
 *  is a router, it will form a new touchlink network itself.
 *  If the device is not factory new, the local device will
 *  send a NWK join request using the current network parameters.
 *
 * @param targetNetworkInfo A pointer to an ::sl_zigbee_zll_network_t structure that
 *   indicates the info about what device to send the NWK start/join
 *   request to. This information must have previously been returned
 *   from a touchlink scan.
 *
 * @return An ::sl_status_t value indicating whether the operation
 *   succeeded or why it failed.
 */
sl_status_t sl_zigbee_zll_join_target(const sl_zigbee_zll_network_t* targetNetworkInfo);

/** @brief Update the touchlink security token information. Unlike
 *    sl_zigbee_zll_set_initial_security_state, this can be called while a network is
 *    already established.
 *
 * @param securityState The security configuration to be set.
 *
 * @return An ::sl_status_t value indicating whether the operation
 *   succeeded or why it failed.
 */
sl_status_t sl_zigbee_zll_set_security_state_without_key(const sl_zigbee_zll_initial_security_state_t *securityState);

/** @brief Cause the device to set up the security information
 *    used in its network. Must be called prior to forming, starting, or
 *    joining a network.
 *
 * @param networkKey A pointer to an ::sl_zigbee_key_data_t structure containing the
 *   value for the network key. If the value is set to all F's, then a random
 *   network key will be generated.
 * @param securityState The security configuration to be set.
 *
 * @return An ::sl_status_t value indicating whether the operation
 *   succeeded or why it failed.
 */
sl_status_t sl_zigbee_zll_set_initial_security_state(const sl_zigbee_key_data_t *networkKey,
                                                     const sl_zigbee_zll_initial_security_state_t *securityState);

/**
 * @brief Initiate a touchlink network scan on all the specified
 *   channels. Results will be returned in ::sl_zigbee_zll_network_found_handler().
 *
 * @param channelMask Indicates the range of channels to scan.
 * @param radioPowerForScan The radio output power used for the scan requests.
 * @param nodeType The node type of the local device.
 *
 * @return An ::sl_status_t value indicating whether the operation
 *   succeeded or why it failed.
 */
sl_status_t sl_zigbee_zll_start_scan(uint32_t channelMask,
                                     int8_t radioPowerForScan,
                                     sl_zigbee_node_type_t nodeType);

/**
 * @brief Change the mode of the radio so that the receiver is
 * on when the device is idle. This permits a touchlink target to receive incoming
 * scan requests and an initiator to communicate with a target before the network is
 * established. The idle mode will be set to 'Rx On' until either the duration
 * expires or is set to zero, or unless sl_zigbee_zll_cancel_rx_on_when_idle is called.
 *
 * Note that, if the device joins or attempts to join a network during this period,
 * then the Stack will suspend the special touchlink radio idle mode, and the Stack's
 * radio idle mode will revert to the joined default appropriate to the node type.
 * If, however, the device leaves, or the join fails, then the touchlink radio
 * idle mode will be resumed, provided that the duration timer has not expired.
 *
 * Also note that a subsequent call to sl_zigbee_zll_set_rx_on_when_idle may only
 * extend the (currently outstanding) 'Rx On' duration. If a shorter duration is required,
 * (or if an indefinite duration is currently set) then sl_zigbee_zll_set_rx_on_when_idle must
 * be called first with a duration of 0, in order to cancel the current touchlink
 * radio idle mode.
 *
 * @param durationMs The duration in milliseconds for which to set the idle mode to 'Rx On'.
 * A duration of 0xffffffff indicates an indefinite duration, so that the device
 * will always be able to respond to touchlink requests when not joined.
 * A duration of 0 will cancel the current touchlink radio idle mode.
 *
 * @return An ::sl_status_t value indicating whether the operation succeeded or
 * why it failed. A return value of SL_STATUS_INVALID_STATE indicates that the
 * special touchlink radio idle mode is active, but has been suspended by the Stack,
 * because the device has joined a network, or is in the process of joining, or
 * that an attempt was made to reduce the 'Rx On' duration without canceling
 * the existing touchlink radio idle mode.
 *
 */
sl_status_t sl_zigbee_zll_set_rx_on_when_idle(uint32_t durationMs);

/**
 * @brief Cancel the special touchlink radio idle mode immediately,
 * without reverting the Stack's radio idle mode to its original setting.
 *
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
void sl_zigbee_zll_cancel_rx_on_when_idle(void);
#else
#define sl_zigbee_zll_cancel_rx_on_when_idle() sl_zigbee_zll_set_rx_on_when_idle(0)
#endif

/**
 * @brief Set the default radio power mode directly (This is the
 * radio state when the device is not actively transmitting, and may be either
 * SL_ZIGBEE_RADIO_POWER_MODE_RX_ON or SL_ZIGBEE_RADIO_POWER_MODE_RX_OFF.)
 *
 * @param mode The power mode to set.
 */
void sl_zigbee_zll_set_radio_idle_mode(sl_zigbee_radio_power_mode_t mode);

/**
 * @brief Get the default radio power mode
 *
 * @return The current default radio power mode
 */
uint8_t sl_zigbee_zll_get_radio_idle_mode(void);

/**
 * @brief Called when a touchlink network scan finds a touchlinkable
 *   device, which may be joined on either a centralized or a distributed network,
 *   or may not be joined at all.
 *   The network information will be returned to the application for
 *   processing.
 *
 * @param networkInfo A pointer to an ::sl_zigbee_zll_network_t struct containing
 *   the Zigbee and touchlink specific information about the discovered network.
 * @param isDeviceInfoNull Whether or not deviceInfo is NULL.
 * @param deviceInfo A pointer to an ::sl_zigbee_zll_device_info_record_t struct
 *   containing the device specific info. This pointer may be NULL,
 *   indicating the device has either 0 sub-devices or more than 1
 *   sub-devices.
 * @param packetInfo Information about the packet received from discovered network.
 */
void sl_zigbee_zll_network_found_handler(sl_zigbee_zll_network_t* networkInfo,
                                         bool isDeviceInfoNull,
                                         sl_zigbee_zll_device_info_record_t* deviceInfo,
                                         sl_zigbee_rx_packet_info_t *packetInfo);

/**
 * @brief Called when a touchlink network scan is complete.
 *
 * @param status An ::sl_status_t value indicating whether the operation
 * succeeded, or why it failed. If the status is not ::SL_STATUS_OK, the
 * application should not attempt to start or join a network returned via
 * ::sl_zigbee_zll_network_found_handler.
 */
void sl_zigbee_zll_scan_complete_handler(sl_status_t status);

/**
 * @brief Called when network and group addresses are assigned to
 * a remote mode in a network start or network join request.
 *
 * @param addressInfo A pointer to an ::sl_zigbee_zll_address_assignment_t struct
 *   containing the address assignment information.
 * @param packetInfo Information about incomng packet.
 */
void sl_zigbee_zll_address_assignment_handler(sl_zigbee_zll_address_assignment_t* addressInfo,
                                              sl_zigbee_rx_packet_info_t *packetInfo);

/**
 * @brief Called when the device is a target of a touch link.
 *
 * @param networkInfo A pointer to an ::sl_zigbee_zll_network_t struct containing
 *   the Zigbee and touchlink specific information about the initiator.
 */
void sl_zigbee_zll_touch_link_target_handler(const sl_zigbee_zll_network_t *networkInfo);

/**
 * @brief Read the touchlink stack data token.
 */
void sl_zigbee_zll_get_token_stack_zll_data(sl_zigbee_tok_type_stack_zll_data_t *token);

/**
 * @brief Read the touchlink stack security token.
 */
void sl_zigbee_zll_get_token_stack_zll_security(sl_zigbee_tok_type_stack_zll_security_t *token);

/**
 * @brief Read both the touchlink stack data and security tokens.
 */
void sl_zigbee_zll_get_tokens_stack_zll(sl_zigbee_tok_type_stack_zll_data_t *data,
                                        sl_zigbee_tok_type_stack_zll_security_t *security);

/**
 * @brief Set the touchlink stack data token.
 */
void sl_zigbee_zll_set_token_stack_zll_data(sl_zigbee_tok_type_stack_zll_data_t *token);

/**
 * @brief Return whether or not the network is a touchlink network, that is,
 * a distributed network formed by touchlink commissioning, and supporting
 * touchlink-compliant address and group id assignment.
 */
bool sl_zigbee_is_zll_network(void);

/**
 * @brief Alter the touchlink data token to reflect the fact that the
 * network is non-touchlink-compliant.
 */
void sl_zigbee_zll_set_non_zll_network(void);

/**
 * @brief Get the policy that enables or disables touchlink processing
 * and enable or disable stealing a non-factory-new device.
 */
sl_zigbee_zll_policy_t sl_zigbee_zll_get_policy(void);

/**
 * @brief Set the policy to enable or disable touchlink processing,
 * and enable or disable stealing a non-factory-new device.
 */
sl_status_t sl_zigbee_zll_set_policy(sl_zigbee_zll_policy_t policy);

/**
 * @brief Set the default node type for a factory new device.
 *
 * @param The node type to be set.
 */
void sl_zigbee_set_zll_node_type(sl_zigbee_node_type_t nodeType);

/**
 * @brief Set additional capability bits in the touchlink state.
 *
 * @param A mask with the bits to be set or cleared.
 */
void sl_zigbee_set_zll_additional_state(uint16_t mask);

/**
 * @brief Indicate that a touchlink network operation is in progress,
 * that is, a network start or a network join.
 */
bool sl_zigbee_zll_operation_in_progress(void);

/**
 * @brief Indicate whether the special touchlink
 * radio idle mode is active, i.e., whether the radio receiver will remain on when
 * the device is not transmitting and when the device is not on a network.
 */
bool sl_zigbee_zll_rx_on_when_idle_get_active(void);

/**
 * @brief Get the primary touchlink channel mask.
 *
 * @return The touchlink primary channel mask.
 */
uint32_t sl_zigbee_get_zll_primary_channel_mask(void);

/**
 * @brief Get the secondary touchlink channel mask.
 *
 * @return The touchlink secondary channel mask.
 */
uint32_t sl_zigbee_get_zll_secondary_channel_mask(void);

/**
 * @brief Set the primary touchlink channel mask.
 *
 * @param The touchlink primary channel mask.
 */
void sl_zigbee_set_zll_primary_channel_mask(uint32_t mask);

/**
 * @brief Set the secondary touchlink channel mask.
 *
 * @param The touchlink secondary channel mask.
 */
void sl_zigbee_set_zll_secondary_channel_mask(uint32_t mask);

/**
 * @brief Clear the ZLL stack tokens.
 *
 */
void sl_zigbee_zll_clear_tokens(void);

/**
 * @brief Inform the API that all scanning is complete.
 *
 */
void sl_zigbee_zll_scanning_complete(void);

/** @} */ // END addtogroup

#endif // SILABS_ZLL_API_H
