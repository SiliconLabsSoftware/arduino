/***************************************************************************//**
 * @file
 * @brief See @ref network_formation for documentation.
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

#ifndef SILABS_NETWORK_INFORMATION_H
#define SILABS_NETWORK_INFORMATION_H

#include "stack/include/sl_zigbee_types.h"

/**
 * @addtogroup network_formation
 * @brief EmberZNet API for finding, forming, joining, and leaving
 * Zigbee networks.
 *
 * See network-formation.h for source code.
 * @{
 */

/** @brief Initialize the radio and the EmberZNet stack.
 *
 * Device configuration functions must be called before ::sl_zigbee_init()
 * is called.
 *
 * @note Users do not normally need to call this API, as the Applicaton Framework
 * code automatically calls this routine upon startup.
 * The application must check the return value of this function. If the
 * initialization fails, normal messaging functions will not be available.
 * Some failure modes are not fatal, but the application must follow certain
 * procedures to permit recovery.
 * Ignoring the return code will result in unpredictable radio and API behavior.
 * (In particular, problems with association will occur.)
 *
 * @return An ::sl_status_t value indicating successful initialization or the
 * reason for failure.
 */
sl_status_t sl_zigbee_init(void);

/** @brief A periodic tick routine that should be called:
 * - in the application's main event loop,
 * - as soon as possible after any radio interrupts, and
 * - after ::sl_zigbee_init().
 *
 * @note Users do not normally need to call this API, as the Applicaton Framework
 * code automatically calls this routine upon startup.
 */
void sl_zigbee_tick(void);

/** @brief Resume network operation after a reboot.
 *
 *   Call this function on boot prior to **any**
 *   network operations. It will initialize the networking system
 *   and attempt to resume the previous network identity and configuration.
 *   If the node was not previously joined, this routine should still be called.
 *
 *   If the node was previously joined to a network, it will retain its original
 *   type (e.g., coordinator, router, end device, and so on.)
 *
 *   ::SL_STATUS_NOT_JOINED is returned
 *   if the node is not part of a network.
 *
 *.  This function has encapsulated the old behavior of emberNetworkInitExtended().
 *
 * @param networkInitStruct  Defines whether an orphan scan/rejoin request/or neither
 *   is performed during network initialization.
 *
 * @return An ::sl_status_t value that indicates one of the following:
 * - successful initialization,
 * - ::SL_STATUS_NOT_JOINED if the node is not part of a network, or
 * - the reason for failure.
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# networkInitStruct #}
 */
sl_status_t sl_zigbee_network_init(sl_zigbee_network_init_struct_t* networkInitStruct);

/** @brief Form a new network by becoming the coordinator.
 *
 * @note If using security, the application must call
 *   ::sl_zigbee_set_initial_security_state() prior to joining the network.  This also
 *   applies when a device leaves a network and wants to form another one.

 * @param parameters  Specification of the new network.
 *
 * @return An ::sl_status_t value that indicates either the successful formation
 * of the new network, or the reason that the network formation failed.
 */
sl_status_t sl_zigbee_form_network(sl_zigbee_network_parameters_t *parameters);

/** @brief Form a new Sleepy-to-Sleepy network.
 *
 * @note If using security, the application must call
 *   ::sl_zigbee_set_initial_security_state() prior to joining the network.  This also
 *   applies when a device leaves a network and wants to form another one.

 * @param parameters  Specification of the new network.
 * @param initiator  Indicates if the device is a initiator or a joiner.
 *
 * @return An ::sl_status_t value that indicates either the successful formation
 * of the new network, or the reason that the network formation failed.
 */
sl_status_t sl_zigbee_sleepy_to_sleepy_network_start(sl_zigbee_network_parameters_t *parameters, bool initiator);

/** @brief Tell the stack to allow other nodes to join the network
 * with this node as their parent. Joining is initially disabled by default.
 * This function may only be called after the node is part of a network
 * and the stack is up.
 *
 * @param duration  A value of 0x00 disables joining. A value of 0xFF
 *  enables joining. Any other value enables joining for that number of
 *  seconds.
 */
sl_status_t sl_zigbee_permit_joining(uint8_t duration);

/** @brief Cause the stack to associate with the network using the
 * specified network parameters. It can take several seconds for the stack to
 * associate with the local network. Do not send messages until a call to the
 * ::sl_zigbee_stack_status_handler() callback informs you that the stack is up.
 *
 * @note If using security, the application must call
 *   ::sl_zigbee_set_initial_security_state() prior to joining the network.  This also
 *   applies when a device leaves a network and wants to join another one.
 *
 * @param nodeType    Specification of the role that this node will have in
 *   the network. This role must not be ::SL_ZIGBEE_COORDINATOR. To be a coordinator,
 *   call ::sl_zigbee_form_network().
 *
 * @param parameters  Specification of the network with which the node
 *   should associate.
 *
 * @return An ::sl_status_t value that indicates either:
 * - that the association process began successfully, or
 * - the reason for failure.
 */
sl_status_t sl_zigbee_join_network(sl_zigbee_node_type_t nodeType,
                                   sl_zigbee_network_parameters_t *parameters);

/** @brief Cause the stack to associate with the network using the
 * specified network parameters in the beacon parameter. It can take several
 * seconds for the stack to associate with the local network. Do not send
 * messages until a call to the ::sl_zigbee_stack_status_handler() callback informs you
 * that the stack is up. This function, unlike ::sl_zigbee_join_network(), does not
 * issue an active scan before joining. Instead, this function will cause the
 * local node to issue a MAC Association Request directly to the specified
 * target node. It is assumed that the beacon parameter is an artifact after
 * issuing an active scan (see ::sl_zigbee_get_stored_beacon() for more).
 *
 * @note If using security, the application must call
 *   ::sl_zigbee_set_initial_security_state() prior to joining the network. This also
 *   applies when a device leaves a network and wants to join another one.
 *
 * @param localNodeType  Specification of the role that this node will have in
 *   the network. This role must not be ::SL_ZIGBEE_COORDINATOR. To be a
 *   coordinator, call ::sl_zigbee_form_network().
 *
 * @param beacon  Specification of the network with which the node should
 *   associate.
 *
 * @param radioTxPower  The radio transmit power to use, specified in dBm.
 *
 * @param clearBeaconsAfterNetworkUp  If true, clear beacons in cache upon join
 *   success. Do nothing for join failure.
 *
 * @return An ::sl_status_t value that indicates either:
 * - that the association process began successfully, or
 * - the reason for failure.
 */

sl_status_t sl_zigbee_join_network_directly(sl_zigbee_node_type_t localNodeType,
                                            sl_zigbee_beacon_data_t* beacon,
                                            int8_t radioTxPower,
                                            bool clearBeaconsAfterNetworkUp);

/** @brief Cause the stack to leave the current network.
 * This generates a call to the ::sl_zigbee_stack_status_handler() callback to indicate
 * that the network is down. The radio will not be used until after a later call
 * to ::sl_zigbee_form_network() or ::sl_zigbee_join_network().
 *
 * @param options gives options when leave network.
 * See ::sl_zigbee_leave_network_option_t enumeration for more information.
 *
 * @return An ::sl_status_t value indicating success or reason for failure.
 * A status of ::SL_STATUS_INVALID_STATE indicates that the node is either not
 * joined to a network or is already in the process of leaving.
 */
sl_status_t sl_zigbee_leave_network(sl_zigbee_leave_network_option_t options);

/** @brief Send a Zigbee NWK leave command to the specified destination.
 *
 * @param destination is the node ID of the device that is being told to
 *   leave.
 *
 * @param flags is a bitmask indicating additional considerations for
 *   the leave request.  See the ::sl_zigbee_leave_request_flags_t enumeration for more
 *   information.  Multiple bits may be set.
 *
 * @return An ::sl_status_t value indicating success or reason for failure.
 * A status of ::SL_STATUS_INVALID_STATE indicates that the node not currently
 * joined to the network, or the destination is the local node.  To tell
 * the local device to leave, use the ::sl_zigbee_leave_network() API.
 */
sl_status_t sl_zigbee_send_zigbee_leave(sl_802154_short_addr_t destination,
                                        sl_zigbee_leave_request_flags_t flags);

/** @brief Call this function when contact with the
 * network has been lost. The most common use case is when an end device
 * can no longer communicate with its parent and wishes to find a new one.
 * Another case is when a device has missed a Network Key update and no
 * longer has the current Network Key.
 *
 * Note that a call to ::sl_zigbee_poll_for_data() on an end device that has lost
 * contact with its parent will automatically call ::emberRejoinNetwork(true).
 *
 * The stack will call ::sl_zigbee_stack_status_handler() to indicate that the network
 * is down, then try to re-establish contact with the network by performing
 * an active scan, choosing a network with matching extended pan ID, and
 * sending a Zigbee network rejoin request.  A second call to the
 * ::sl_zigbee_stack_status_handler() callback indicates either the success
 * or the failure of the attempt.  The process takes
 * approximately 150 milliseconds per channel to complete.
 *
 * This call replaces the ::emberMobileNodeHasMoved() API from EmberZNet 2.x,
 * which used MAC association and consequently took half a second longer
 * to complete.
 *
 * @param haveCurrentNetworkKey  This parameter determines whether the request
 * to rejoin the Network is sent encrypted (true) or unencrypted (false). The
 * application should first try to use encryption. If that fails,
 * the application should call this function again and use no encryption.
 * If the unencrypted rejoin is successful then device will be in the joined but
 * unauthenticated state. The Trust Center will be notified of the rejoin and
 * send an updated Network encrypted using the device's Link Key. Sending the
 * rejoin unencrypted is only supported on networks using Standard Security
 * with link keys (i.e., ZigBee 2006 networks do not support it).
 *
 * @param channelMask A mask indicating the channels to be scanned.
 * See ::sl_zigbee_start_scan() for format details.
 *
 * @param reason An enumeration indicating why the rejoin occurred.
 * The stack will set the reason based on the ::sl_zigbee_rejoin_reason_t.
 * An application should use one of the APP_EVENT rejoin reasons.  The stack
 * will never use these.  Only if the function return code is SL_STATUS_OK
 * will the rejoin reason be set.
 *
 * @param nodeType An enumeration indicating the device type to rejoin as. For this to be effective the
 * stack only accepts ::SL_ZIGBEE_END_DEVICE and ::SL_ZIGBEE_SLEEPY_END_DEVICE.
 * This value could be set to 0 or SL_ZIGBEE_DEVICE_TYPE_UNCHANGED if not needed.
 *
 * @return An ::sl_status_t value indicating success or reason for failure.
 */
sl_status_t sl_zigbee_find_and_rejoin_network(bool haveCurrentNetworkKey,
                                              uint32_t channelMask,
                                              sl_zigbee_rejoin_reason_t reason,
                                              sl_zigbee_node_type_t nodeType);

/** @brief Return the enumeration for why a previous rejoin.
 */
sl_zigbee_rejoin_reason_t sl_zigbee_get_last_rejoin_reason(void);

/** @brief Start a scan. ::SL_STATUS_OK signals that
 * the scan successfully started. Note that although a scan can be initiated
 * while the node is currently joined to a network, the node will generally
 * be unable to communicate with its PAN during the scan period.
 * Take care when performing scans of any significant duration while
 * presently joined to an existing PAN.
 *
 * Possible error responses and their meanings:
 * - ::SL_STATUS_MAC_SCANNING, already scanning.
 * - ::SL_STATUS_BAD_SCAN_DURATION, a duration value that is
 *   not 0..14 inclusive is set.
 * - ::SL_STATUS_MAC_INCORRECT_SCAN_TYPE, an undefined
 *   scanning type is requested;
 * - ::SL_STATUS_INVALID_CHANNEL_MASK, the channel mask did not specify any
 *   valid channels on the current platform.
 *
 * @param scanType     Indicates the type of scan to be performed.
 *  Possible values:  ::SL_ZIGBEE_ENERGY_SCAN, ::SL_ZIGBEE_ACTIVE_SCAN.
 *
 * @param channelMask  Bits set as 1 indicate that this particular channel
 * should be scanned. Bits set to 0 indicate that this particular channel
 * should not be scanned. For example, a channelMask value of 0x00000001
 * indicates that only channel 0 should be scanned. Valid channels range
 * from 11 to 26 inclusive. This translates to a channel mask value of 0x07
 * FF F8 00. As a convenience, a channelMask of 0 is reinterpreted as the
 * mask for the current channel.
 *
 * @param duration     Sets the exponent of the number of scan periods,
 * where a scan period is 960 symbols, and a symbol is 16 microseconds.
 * The scan will occur for ((2^duration) + 1) scan periods.  The value
 * of duration must be less than 15.  The time corresponding to the first
 * few values is as follows: 0 = 31 msec, 1 = 46 msec, 2 = 77 msec,
 * 3 = 138 msec, 4 = 261 msec, 5 = 507 msec, 6 = 998 msec.
 */
sl_status_t sl_zigbee_start_scan(sl_zigbee_network_scan_type_t scanType, uint32_t channelMask, uint8_t duration);

/** @brief Handle the reception of a beacon.
 *
 * NOTE: SoC only
 */
typedef bool (*sl_zigbee_network_found_callback_t)(sl_zigbee_zigbee_network_t *network, sl_zigbee_beacon_data_t *beacon);

/** @brief Handle the conclusion of an active
 * or energy scan.
 *
 * NOTE: SoC only
 */
typedef bool (*sl_zigbee_scan_complete_callback_t)(uint8_t channel, sl_status_t status);

#ifndef EZSP_HOST

/** @brief Kick off a procedure to scan for beacons, filter results, and
 * provide a response ZCL frame including the best eligible parents. This
 * procedure uses the sl_zigbee_start_scan() API.
 *
 * @param useStandardBeacons If true, the surveyBeacon procedure will use
 * standard beacons. If false, the surveyBeacon procedure will use enhanced
 * beacons.
 *
 * @param networkFoundCallback The function pointer that is called after
 * the reception of a beacon.
 *
 * @param scanCompleteCallback The function pointer that is called after
 * the beacon collection phase of the surveyBeacon procedure is over.
 *
 * NOTE: SoC only
 */
sl_status_t sl_zigbee_survey_beacons(bool useStandardBeacons,
                                     uint32_t channel_mask,
                                     sl_zigbee_network_found_callback_t networkFoundCallback,
                                     sl_zigbee_scan_complete_callback_t scanCompleteCallback);
#endif

/** @brief Kick off a procedure to find an unused panId on a low-activity
 * channel that is included in the passed-in channel mask. This procedure
 * uses the sl_zigbee_start_scan() API.
 *
 * @param channelMask The set of channels that will be scanned to find an
 * available panId.
 *
 * @param duration The length of time that will be spent scanning for an
 * available panId.
 */
sl_status_t sl_zigbee_find_unused_pan_id(uint32_t channelMask, uint8_t duration);

/** @brief Terminate a scan in progress.
 *
 * @return Returns ::SL_STATUS_OK if successful.
 */
sl_status_t sl_zigbee_stop_scan(void);

/** @brief Indicate the status of the current scan. When the scan has
 * completed, the stack will call this function with status set to
 * ::SL_STATUS_OK. Prior to the scan completing, the stack may call this
 * function with other status values. Non-SL_STATUS_OK status values indicate
 * that the scan failed to start successfully on the channel indicated by the
 * channel parameter. The current scan is ongoing until the stack calls this
 * function with status set to ::SL_STATUS_OK.
 *
 * @param channel  The channel on which the current error occurred.
 * Undefined for the case of ::SL_STATUS_OK.
 *
 * @param status   The error condition that occurred on the current channel.
 * Value will be ::SL_STATUS_OK when the scan has completed.
 */
void sl_zigbee_scan_complete_handler(uint8_t channel, sl_status_t status);

/** @brief Report the maximum RSSI value measured on the channel.
 *
 * @param channel       The 802.15.4 channel number on which the RSSI value.
 *   was measured.
 *
 * @param maxRssiValue  The maximum RSSI value measured (in units of dBm).
 *
 */
void sl_zigbee_energy_scan_result_handler(uint8_t channel, int8_t maxRssiValue);

/** @brief Report that a network was found and gives the network
 * parameters used for deciding which network to join.
 *
 * @param networkFound A pointer to a ::sl_zigbee_zigbee_network_t structure
 *   that contains the discovered network and its associated parameters.
 *
 * @param lqi  The link quality indication of the network found.
 *
 * @param rssi  The received signal strength indication of the network found.
 */
void sl_zigbee_network_found_handler(sl_zigbee_zigbee_network_t *networkFound,
                                     uint8_t lqi,
                                     int8_t rssi);

/** @brief Return an unused panID and channel pair
 * found via the find unused panId scan procedure.
 *
 * @param panId The unused panID.
 *
 * @param channel The channel which the unused panId was found on.
 */
void sl_zigbee_unused_pan_id_found_handler(sl_802154_pan_id_t panId, uint8_t channel);

/**
 * @brief Handle the orphan notification for a Zigbee network.
 *
 * This function is called when an orphan notification is received for a Zigbee network.
 * The function takes the long address of the orphaned device as a parameter.
 *
 * @param longId The long address of the orphaned device.
 */
void sl_zigbee_orphan_notification_handler(sl_802154_long_addr_t longId);

/** @brief Indicate whether the stack is in the process of performing
 *  a rejoin.
 *
 * @return Returns true if the device is in the process of performing a rejoin.
 *         Returns false otherwise.
 */
bool sl_zigbee_is_performing_rejoin(void);

/** @brief Indicate the reason why the device left the network (if any). This also
 *    will return the device that sent the leave message, if the leave
 *    was due to an over-the-air message.
 *
 *    If returnNodeIdThatSentLeave is a non-NULL pointer, the node ID
 *    of the device that sent the leave message will be written to the value
 *    indicated by the pointer. If the leave was not due to an over-the-air
 *    message (but an internal API call instead), SL_ZIGBEE_UNKNOWN_NODE_ID is
 *    returned.
 *
 *  @return Returns sl_zigbee_leave_reason_t enumeration, or SL_ZIGBEE_LEAVE_REASON_NONE
 *    if the device has not left the network.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# returnNodeIdThatSentLeave #}
 */
sl_zigbee_leave_reason_t sl_zigbee_get_last_leave_reason(sl_802154_short_addr_t* returnNodeIdThatSentLeave);

/** @brief Indicate the state of the permit joining in the MAC.
 *
 *  @return Returns true if permit, else returns false.
 */
bool sl_zigbee_get_permit_joining(void);

/** @brief Set the Network Update ID to the desired value. If this function is called
 *   when the node is not part of a network, the desired Network Update ID is saved and
 *   will be aplied to the newly formed network when calling sl_zigbee_form_network.
 *   If this function is called in case the node is part of a network, the node's
 *   Network Update ID will only be updated in case set_even_if_on_network is set to TRUE
 *
 *  @param nwkUpdateId The Network Update ID.
 *  @param set_even_if_on_network set to TRUE if Network Update ID is to be applied even when on network.
 *
 *  @note When on a network, the Network Update ID should not normally be changed, as it is used
 *    by the stack to track changes in the network. Unless specifically required
 *    set_even_if_on_network should always be set to FALSE
 *
 *  @return SL_STATUS_OK if update was successful, else SL_STATUS_INVALID_STATE.
 */
sl_status_t sl_zigbee_set_nwk_update_id(uint8_t nwkUpdateId, bool set_when_on_network);

/** @brief Set the duration of a beacon jitter, in the units used by the 15.4
 *    scan parameter (((1 << duration) + 1) * 15 ms), when responding to a beacon
 *    request.
 *
 *  @note Because the recommended scan duration of a joining device is 3 for 2.4
 *    GHz devices, any value passed in to this function greater than 3 will be
 *    rejected.
 *
 *  @return SL_STATUS_INVALID_PARAMETER if the argument is invalid, else SL_STATUS_OK.
 */
sl_status_t sl_zigbee_set_beacon_jitter_duration(uint8_t beaconJitterDuration);

/**
 * @brief Set the policy decision for Trust Center (insecure)
 *   rejoins for devices using the well-known link key. If rejoining using the
 *   well-known key is allowed, it is disabled again after
 *   sli_zigbee_allow_tc_rejoins_using_well_known_key_timeout_sec seconds.
 *
 * @return A valid error code.
 */
sl_status_t sl_zigbee_set_tc_rejoins_using_well_known_key_allowed(bool allow);

/**
 * @brief Set the timeout in seconds for Trust Center (insecure)
 *   rejoins for devices using the well-known link key. If rejoining using the
 *   well-known key is allowed, it is disabled again after this timeout.
 *
 * @return A valid error code.
 */
sl_status_t sl_zigbee_set_tc_rejoins_using_well_known_key_timeout_sec(uint16_t timeout_sec);

/**
 * @brief Get the policy decision for Trust Center (insecure)
 *   rejoins for devices using the well-known link key.
 *
 * @return Return true if allowed, else false.
 */
bool sl_zigbee_tc_rejoins_using_well_known_key_allowed(void);

/*
 * @brief Extend a joiner's timeout to wait for the network key
 * on the joiner default key timeout is 3 sec, and only values greater equal to 3 sec are accepted.
 *
 * @return SL_STATUS_INVALID_PARAMETER if the argument is invalid, else SL_STATUS_OK.
 */
sl_status_t sl_zigbee_setup_delayed_join(uint8_t networkKeyTimeoutS);

/**
 * @brief Return true if the TC is delaying in sending the network key to newly joining devices. The delay amount is configured via the Delayed Join component.
 */
bool sl_zigbee_delayed_join_is_activated(void);

/**
 * @brief Set the activation state of Delayed Join. If Delayed Join is activated, the TC will delay in sending network key to newly joining devices
 */
void sl_zigbee_delayed_join_activate(bool activated);

/*
 * @brief Return the value of network key timeout in seconds.
 *
 * @return value of network key timeout in seconds
 */
uint8_t sl_zigbee_get_network_key_timeout(void);

/**
 * @brief Reschedule sending link status message, first one being sent immediately.
 *
 * @return A valid error code.
 */
sl_status_t sl_zigbee_reschedule_link_status_msg(void);

/** @brief Set the short PAN ID the device will accept in a NLME Network Update command.
 *
 * If a NLME Network Update command is received by the device specifying
 * a short PAN ID that does not match with the given PAN ID, then the NLME Network
 * Update message will be ignored by the device. A value of 0xFFFF indicates
 * that any short PAN ID received in a NLME Network Update command will be accepted
 * which is also the default value set by the stack.
 *
 * @param panId     A pending network update short PAN ID.
 */
void sl_zigbee_set_pending_network_update_pan_id(uint16_t panId);

/*
 * @brief Send an update PAN ID message with the new PanID and can be called
 *  within the context of sl_zigbee_internal_pan_id_conflict_handler,( the handler itself is called by the
 *  stack to report the number of conflict reports exceeds
 *  SL_ZIGBEE_PAN_ID_CONFLICT_REPORT_THRESHOLD within a period of 1 minute )
 *
 *  @param new PAN ID that we want to advertise
 *
 *  @returns true if sending an update was successful, false otherwise
 */
bool sl_zigbee_send_pan_id_update(sl_802154_pan_id_t newPan);

/** @brief Clear all cached beacons that have been collected from an active scan.
 *
 * @return An appropriate error code.
 */
sl_status_t sl_zigbee_clear_stored_beacons(void);

/*
 * @brief Configure the number of beacons to store when issuing active scans
 *  for networks. For classical (Home Automation and Smart Energy) joining, the
 *  most prioritized beacon is chosen to join to. For network steering (Z3.0
 *  joining), all beacons are tried until a successful join.
 *  The existing join and rejoin APIs, such as sl_zigbee_join_network and the several
 *  sl_zigbee_find_and_rejoin_network APIs, set the maximum number of beacons to store
 *  to 1.
 *
 *  @param numBeacons The number of beacons to cache when scanning.
 *
 *  @returns SL_STATUS_INVALID_PARAMETER if numBeacons is greater than
 *   SL_ZIGBEE_MAX_BEACONS_TO_STORE, otherwise SL_STATUS_OK
 */
sl_status_t sl_zigbee_set_num_beacons_to_store(uint8_t numBeacons);

/**
 * @brief Fetches the specified beacon in the cache. User should first issue an
 *  active scan to populate the beacon cache, then users may call
 *  ::sl_zigbee_get_num_stored_beacons to identify how many beacons have been
 *  stored in cache. Following that, users may retrieve beacons based on the
 *  number of cached beacons.
 *
 *  @param beacon_number The beacon index to fetch. Valid values range from 0 to
 *  ::sl_zigbee_get_num_stored_beacons-1.
 *
 *  @param beacon The beacon to populate upon success.
 *
 *  @returns An appropriate sl_status_t status code.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# beacon #}
 */
sl_status_t sl_zigbee_get_stored_beacon(uint8_t beacon_number, sl_zigbee_beacon_data_t* beacon);

/** @brief Return the number of cached beacons that have been collected from a
   scan. */
uint8_t sl_zigbee_get_num_stored_beacons(void);

/** @brief Get current beacon classification parameter settings.
 *  The parameters related to beacon prioritization, could be all accessed with this function.
 *  The values returned in beaconClassificationMask must be decoded by using sl_zigbee_beacon_classification_flags_t
 *
 * @param sl_zigbee_beacon_classification_params_t* could be used to get all possible priorities,
 * e.g. (beaconClassificationMask | TC_CONNECTIVITY)
 *
 * @return  SL_STATUS_OK if successful, and error code otherwise.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# param #}
 */
sl_status_t sl_zigbee_get_beacon_classification_params(sl_zigbee_beacon_classification_params_t* param);

/** @brief Set current beacon classification parameters.
 *  The parameters related to beacon prioritization, could be all set with this function.
 *  The values in beaconClassificationMask must be encoded by using sl_zigbee_beacon_classification_flags_t
 *
 * @param sl_zigbee_beacon_classification_params_t* could be used to set all possible priorities,
 *  e.g. beaconClassificationMask &= ~TC_CONNECTIVITY
 *
 * @return  SL_STATUS_OK if successful, and error code otherwise.
 */
sl_status_t sl_zigbee_set_beacon_classification_params(sl_zigbee_beacon_classification_params_t* param);

/** @} END addtogroup */

/**
 * <!-- HIDDEN
 * @page 2p5_to_3p0
 * <hr>
 * The file network-formation.h is new and is described in @ref network_formation.
 * <ul>
 * <li> <b>New items</b>
 *   - sl_zigbee_find_and_rejoin_network() - replaced emberMobileNodeHasMoved()
 *   - emberRejoinNetwork()
 *   .
 * <li> <b>Items moved from sl_zigbee.h</b>
 *   - sl_zigbee_energy_scan_result_handler()
 *   - sl_zigbee_form_network()
 *   - sl_zigbee_init()
 *   - sl_zigbee_join_network()
 *   - sl_zigbee_leave_network()
 *   - sl_zigbee_network_found_handler()
 *   - sl_zigbee_network_init()
 *   - sl_zigbee_permit_joining()
 *   - sl_zigbee_scan_complete_handler()
 *   - sl_zigbee_start_scan()
 *   - sl_zigbee_stop_scan()
 *   - sl_zigbee_tick()
 * </ul>
 * HIDDEN -->
 */

#endif // SILABS_NETWORK_INFORMATION_H
