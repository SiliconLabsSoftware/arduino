/***************************************************************************//**
 * @file
 * @brief EmberZNet security API.
 * See @ref security for documentation.
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

#ifndef SILABS_SECURITY_H
#define SILABS_SECURITY_H

/**
 * @addtogroup security
 *
 * This file describes the functions necessary to manage security for a
 * regular device.  These are the three major modes for security and applications,
 * which should link in the appropriate library:
 * - Residential security uses only network keys. This is the only supported
 *     option for ZigBee 2006 devices.
 * - Standard security uses network keys with optional link keys. Ember
 *     strongly recommends using Link Keys. It is possible for 2006 devices
 *     to run on a network that uses Standard Security.
 *
 * See security.h for source code.
 * @{
 */

#include "stack/include/trust-center.h"

/**
 * @brief The block size in bytes of the encryption cypher (AES-MMO-128).
 */
 #define SECURITY_BLOCK_SIZE         16 // Key, Nonce, and standalone block size

/** @brief Set the initial security state that will be used by
 * the device when it forms or joins a network.  If security is enabled,
 * this function <b>must</b> be called prior to forming or joining the network.
 * It must also be called if the device left the network and wishes to form
 * or join another network.
 *
 * This call <b>should not</b> be used when restoring prior network operation
 * from saved state via ::sl_zigbee_network_init because this will cause saved
 * security settings and keys table from the prior network to be erased,
 * resulting in improper keys and/or frame counter values being used, which will
 * prevent proper communication with other devices in the network.
 * Calling ::sl_zigbee_network_init is sufficient to restore all saved security
 * settings after a reboot and re-enter the network.
 *
 * The call may be used by either the Trust Center or non Trust Center devices,
 * the options that are set are different depending on which role the device
 * will assume. See the ::sl_zigbee_initial_security_state_t structure for more
 * explanation about the various security settings.
 *
 * The function will return ::SL_STATUS_INVALID_CONFIGURATION
 * in the following cases:
 *   <ul>
 *   <li>Distributed Trust Center Mode was enabled with Hashed Link Keys.</li>
 * </ul>
 *
 * @param state The security configuration to be set.
 *
 * @return An ::sl_status_t value. ::SL_STATUS_OK if the security
 *   state has been set successfully. ::SL_STATUS_INVALID_STATE if the device
 *   is not in the ::SL_ZIGBEE_NO_NETWORK state. The value
 *   ::SL_STATUS_INVALID_CONFIGURATION is returned if the combination
 *   of security parameters is not valid. ::SL_STATUS_INVALID_KEY is returned
 *   if a reserved or invalid key value was passed in the key structure for
 *   one of the keys.
 */
sl_status_t sl_zigbee_set_initial_security_state(sl_zigbee_initial_security_state_t* state);

/** @brief Set the extended initial security bitmask.
 *
 * @param mask An object of type ::sl_zigbee_extended_security_bitmask_t that indicates
 * what the extended security bitmask should be set to.
 *
 * @return ::SL_STATUS_OK if the security settings were successfully retrieved.
 *   ::SL_STATUS_INVALID_STATE otherwise.
 */
sl_status_t sl_zigbee_set_extended_security_bitmask(sl_zigbee_extended_security_bitmask_t mask);

/** @brief Get the extended security bitmask that is used by a device.
 *
 * @param mask A pointer to an ::sl_zigbee_extended_security_bitmask_t value into which
 * the extended security bitmask will be copied.
 *
 * @return ::SL_STATUS_OK if the security settings were successfully retrieved.
 *   ::SL_STATUS_INVALID_STATE otherwise.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# mask #}
 */
sl_status_t sl_zigbee_get_extended_security_bitmask(sl_zigbee_extended_security_bitmask_t* mask);

/**
 * @brief A non-trust center device configuration bitmask example.
 *    There is no Preconfigured Link Key, so the NWK key is expected to
 *    be sent in-the-clear.  The device will request a Trust Center Link key
 *    after getting the Network Key.
 */
#define SL_ZIGBEE_JOIN_NO_PRECONFIG_KEY_BITMASK \
  (SL_ZIGBEE_STANDARD_SECURITY_MODE             \
   | SL_ZIGBEE_GET_LINK_KEY_WHEN_JOINING)

/**
 * @brief A non-trust center device configuration bitmask example.
 *   The device has a Preconfigured Link Key and expects to receive
 *   a NWK Key encrypted at the APS Layer.  A NWK key sent in-the-clear
 *   will be rejected.
 */
#define SL_ZIGBEE_JOIN_PRECONFIG_KEY_BITMASK \
  (SL_ZIGBEE_STANDARD_SECURITY_MODE          \
   | SL_ZIGBEE_HAVE_PRECONFIGURED_KEY        \
   | SL_ZIGBEE_REQUIRE_ENCRYPTED_KEY)

/** @brief Get the security state that is used by a device joined
 *  into the Network. We can still get current security state by calling this
 *  function and the return value can be SL_STATUS_NOT_JOINED or SL_STATUS_OK.
 *
 * @param state A pointer to an ::sl_zigbee_current_security_state_t value into which
 * the security configuration will be copied.
 *
 * @return ::SL_STATUS_OK if the security settings were successfully retrieved.
 *   ::SL_STATUS_NOT_JOINED if the device is not currently joined in the network.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# state #}
 */
sl_status_t sl_zigbee_get_current_security_state(sl_zigbee_current_security_state_t* state);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern uint8_t sl_zigbee_key_table_size;
#endif

/** @brief Generate a Random Key (link, network, or master) and returns
 * the result.
 *
 * It copies the key into the array that \c result points to.
 * This is an time-expensive operation as it needs to obtain truly
 * random numbers.
 *
 * @param keyAddress  A pointer to the location in which to copy the
 * generated key.
 *
 * @return ::SL_STATUS_OK on success, ::SL_STATUS_ZIGBEE_INSUFFICIENT_RANDOM_DATA
 *   on failure.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# keyAddress #}
 */
sl_status_t sl_zigbee_generate_random_key(sl_zigbee_key_data_t* keyAddress);

/** @brief Inform the application that the Network Key
 * has been updated and the node has been switched over to use the new
 * key. The actual key being used is not passed up, but the sequence number
 * is.
 *
 * @param sequenceNumber  The sequence number of the new network key.
 */
void sl_zigbee_switch_network_key_handler(uint8_t sequenceNumber);

/** @brief Request a Link Key from the
 *  Trust Center with another device device on the Network (which could
 *  be the Trust Center).  A Link Key with the Trust Center is possible
 *  but the requesting device can't be the Trust Center.
 *  Link Keys are optional in ZigBee Standard Security. Therefore, the stack
 *  can't know whether the other device supports them.
 *
 *  If the partner device is the Trust Center, only that device
 *  needs to request the key.  The Trust Center will immediately respond to
 *  those requests and send the key back to the device.
 *
 *  If the partner device is not the Trust Center, both devices
 *  must request an Application Link Key with each other. The requests
 *  will be sent to the Trust Center for it to answer. The Trust
 *  Center will store the first request and wait ::SL_ZIGBEE_REQUEST_KEY_TIMEOUT
 *  for the second request to be received.  The Trust Center only supports one
 *  outstanding Application key request at a time and therefore will ignore
 *  other requests that are not associated with the first request.
 *
 *  Sleepy devices should poll at a higher rate until a response
 *  is received or the request times out.
 *
 *  The success or failure of the request is returned via
 *  ::sl_zigbee_zigbee_key_establishment_handler(...)
 *
 * @param partner The IEEE address of the partner device. If NULL is passed
 *    in, the Trust Center IEEE Address is assumed.
 * @return SL_STATUS_OK if the call succeeds, or SL_STATUS_ALLOCATION_FAILED.
 */
sl_status_t sl_zigbee_request_link_key(sl_802154_long_addr_t partner);

/** @brief Request a new link link key from the Trust Center. This
 * function starts by sending a Node Descriptor request to the Trust Center to
 * verify its R21+ stack version compliance. A Request Key message will then be
 * sent, followed by a Verify Key Confirm message.
 *
 * @param maxAttempts The maximum number of attempts a node should make when
 * sending the Node Decriptor, Request Key, and Verify Key Confirm messages. The
 * number of attempts resets for each message type sent (e.g., if maxAttempts is
 * 3, up to 3 Node Descriptors are sent, up to 3 Request Keys, and up to 3
 * Verify Key Confirm messages are sent).
 *
 * @return SL_STATUS_FAIL is the Security Core Library is not included.
 * SL_STATUS_INVALID_STATE if already requesting a key from TC, not on network, or if
 * local node is Trust Center.
 * SL_STATUS_INVALID_CONFIGURATION if the Trust Center's EUI is unknown.
 * Otherwise, the return status from sending the initial Node Descriptor is
 * returned.
 */
sl_status_t sl_zigbee_update_tc_link_key(uint8_t maxAttempts);

/** @brief Notify the application about the status
 *  of the request for a Link Key.  The application should define
 *  SL_ZIGBEE_APPLICATION_HAS_ZIGBEE_KEY_ESTABLISHMENT_HANDLER to implement
 *  its own handler.
 *
 * @param partner The IEEE address of the partner device or all zeros if
 *   the Key establishment failed.
 * @param status The status of the key establishment.
 */
void sl_zigbee_zigbee_key_establishment_handler(sl_802154_long_addr_t partner, sl_zigbee_key_status_t status);

/** @brief Search the key table to find an entry
 *  matching the specified IEEE address and key type.
 *
 * @param address The IEEE Address of the partner device that shares
 *   the key. To find the first empty entry, pass in an address
 *   of all zeros.
 * @param linkKey A bool indicating whether to search for an entry
 *   containing a Link or Master Key.
 * @return The index that matches the search criteria, or 0xFF if
 *   no matching entry was found.
 */
uint8_t sl_zigbee_find_key_table_entry(sl_802154_long_addr_t address,
                                       bool linkKey);

/** @brief Clear a single entry in the key table.
 *
 * @param index The index in the key table of the entry to erase.
 *
 * @return ::SL_STATUS_OK if the index is valid and the key data was erased.
 *   ::SL_STATUS_INVALID_KEY if the index is out of range for the size of
 *   the key table.
 */
sl_status_t sl_zigbee_erase_key_table_entry(uint8_t index);

/**
 * @brief Clear the key table of the current network.
 *
 * @return ::SL_STATUS_OK if the key table was successfully cleared.
 *   ::SL_STATUS_INVALID_STATE otherwise.
 */
sl_status_t sl_zigbee_clear_key_table(void);

/** @brief Suppress normal write operations of the stack
 *    tokens.  This is only done in rare circumstances when the device already
 *    has network parameters but needs to conditionally rejoin a network in order to
 *    perform a security message exchange (i.e., key establishment). If the
 *    network is not authenticated properly, it needs to forget any stack
 *    data it used and return to the old network. By suppressing writing
 *    of the stack tokens the device will not have stored any persistent data
 *    about the network and a reboot will clear the RAM copies. The Smart Energy
 *    profile feature Trust Center Swap-out uses this to securely replace
 *    the Trust Center and re-authenticate to it.
 *
 * @return ::SL_STATUS_OK if it could allocate temporary buffers to
 *    store network information.  ::SL_STATUS_ALLOCATION_FAILED otherwise.
 */
sl_status_t sl_zigbee_stop_writing_stack_tokens(void);

/** @brief Immediately write the value of stack tokens
 *    and then resume normal network operation by writing the stack tokens
 *    at appropriate intervals or changes in state.
 *    It has no effect unless
 *    a previous call was made to ::sl_zigbee_stop_writing_stack_tokens().
 *
 *  @return ::SL_STATUS_OK if it had previously unwritten tokens from a call to
 *    ::sl_zigbee_stop_writing_stack_tokens() that it now wrote to the token system.
 *    ::SL_STATUS_INVALID_STATE otherwise.
 */
sl_status_t sl_zigbee_start_writing_stack_tokens(void);

/** @brief Determine whether stack tokens will be written
 *    to persistent storage when they change. By default, it is set to true
 *    meaning the stack will update its internal tokens via HAL calls when the
 *    associated RAM values change.
 *
 * @return True if the device will update the persistent storage for tokens
 *    when values in RAM change. False otherwise.
 */
bool sl_zigbee_writing_stack_tokens_enabled(void);

/** @brief Perform APS encryption/decryption of messages
 *    directly.  Normally, the stack handles all APS encryption/decryption
 *    automatically and there is no need to call this function. If APS data
 *    is sent or received via some other means (such as over interpan),
 *    APS encryption/decryption must be done manually. If the decryption
 *    is performed, the Auxiliary security header and MIC will be removed
 *    from the message. If encrypting, the auxiliary header and
 *    MIC will be added to the message.
 *
 * @param encrypt A bool indicating whether perform encryption (true) or
 *   decryption (false).
 *
 * @param length (Pointer to the) length of the array being used to store message.
 * This must be large enough to include the auxiliary header and MIC,
 * regardless of the value of encrypt.
 *
 * @param message A pointer to a ::uint8_t array containing the APS frame
 * to decrypt or encrypt.
 *
 * @param apsHeaderEndIndex The index in the buffer where the APS header ends.
 *   If encryption is being performed, this should point to the APS payload, where
 *   an Auxiliary header will be inserted. If decryption is being
 *   performed, this should point to the start of the Auxiliary header frame.
 *
 * @param remoteEui64 the ::sl_802154_long_addr_t of the remote device the message was
 *   received from (decryption) or being sent to (encryption).
 *
 * @return ::SL_STATUS_OK if encryption/decryption was performed successfully.
 *   An appropriate ::sl_status_t code on failure.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# message | length: length | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
sl_status_t sl_zigbee_aps_crypt_message(bool encrypt,
                                        uint8_t length,
                                        const uint8_t *message,
                                        uint8_t apsHeaderEndIndex,
                                        sl_802154_long_addr_t remoteEui64);

/** @brief Retrieve the security configuration stored
 *    in manufacturing tokens.  It is only available on the 35x series.
 *    See ::sl_zigbee_set_mfg_security_config() for more details.
 *
 *  @param settings A pointer to the ::sl_zigbee_mfg_security_struct_t variable
 *    that will contain the returned data.
 *
 *  @return ::SL_STATUS_OK if the tokens were successfully read.
 *    ::sl_status_t error code otherwise.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# settings #}
 */
sl_status_t sl_zigbee_get_mfg_security_config(sl_zigbee_mfg_security_struct_t* settings);

/** @brief Set the security configuration to be stored
 *    in manufacturing tokens.  It is only available on the 35x series.
 *    This API must be called with care.  Once set, a manufacturing token
 *    CANNOT BE UNSET without using the ISA3 tools and connecting the chip
 *    via JTAG.  Additionally, a chip with read protection enabled cannot have
 *    its configuration changed without a full chip erase. Therefore, this provides
 *    a way to disallow access to the keys at runtime that cannot be undone.
 *
 *    To call this API, the magic number must be passed in corresponding to
 *    ::SL_LEGACY_SECURITY_CONFIG_MAGIC_NUMBER.  This prevents accidental
 *    calls to this function when ::sl_zigbee_get_mfg_security_config() was actually
 *    intended.
 *
 *    This function will disable external access to the actual
 *    key data used for decryption/encryption outside the stack.
 *    Attempts to export the key will return the metadata if applicable
 *    (e.g., sequence number, associated EUI64, frame counters)
 *    but the key value may be modified, see below.
 *
 *    The stack always has access to the actual key data.
 *
 *    If the ::sl_zigbee_key_settings_t within the ::sl_zigbee_mfg_security_struct_t are set to
 *    ::SL_ZIGBEE_KEY_PERMISSIONS_NONE, the key value will be set to zero
 *    when ::sl_zigbee_sec_man_export_key() or similar functions are called.
 *    If the ::sl_zigbee_key_settings_t within the ::sl_zigbee_mfg_security_struct_t are set to
 *    ::SL_ZIGBEE_KEY_PERMISSIONS_HASHING_ALLOWED, the AES-MMO hash of the key
 *    will replace the actual key data when calls to functions like
 *    ::sl_zigbee_sec_man_export_key() are made.
 *    If the ::sl_zigbee_key_settings_t within the ::sl_zigbee_mfg_security_struct_t are set to
 *    ::SL_ZIGBEE_KEY_PERMISSIONS_READING_ALLOWED, the actual key data is
 *    returned.  This is the default value of the token.
 *
 *  @param magicNumber A 32-bit value that must correspond to
 *    ::SL_LEGACY_SECURITY_CONFIG_MAGIC_NUMBER, otherwise ::SL_STATUS_INVALID_STATE
 *    will be returned.
 *
 *  @param settings The security settings that are intended to be set by the
 *    application and written to manufacturing token.
 *
 *  @return ::SL_STATUS_INVALID_PARAMETER if the passed magic number is invalid.
 *    ::SL_STATUS_INVALID_STATE if the chip does not support writing MFG tokens
 *    ::SL_STATUS_INVALID_CONFIGURATION if there was an attempt to write an
 *    unerased manufacturing token (i.e., the token has already been set).
 */
sl_status_t sl_zigbee_set_mfg_security_config(uint32_t magicNumber,
                                              const sl_zigbee_mfg_security_struct_t* settings);

/** @brief Set the NWK layer outgoing frame counter
 *    (intended for device restoration purposes).  Caveats:
 *    - Can only be called before NetworkInit / FormNetwork / JoinNetwork,
 *      when sl_zigbee_network_state()==SL_ZIGBEE_NO_NETWORK.
 *    - This function should be called before ::sl_zigbee_set_initial_security_state,
 *      and the SL_ZIGBEE_NO_FRAME_COUNTER_RESET bitmask should be added to the
 *      initial security bitmask when ::emberSetInitialSecuritState is called.
 *    - If used in multi-network context, ::sl_zigbee_set_current_network() must
 *      be called prior to calling this function.
 *
 * @param desiredValue The desired outgoing NWK frame counter value.  This
 *   needs to be less than MAX_INT32U_VALUE to ensure that rollover
 *   does not occur on the next encrypted transmission.
 *
 * @return ::SL_STATUS_OK if calling context is valid (sl_zigbee_network_state()
 *   == SL_ZIGBEE_NO_NETWORK) and desiredValue < MAX_INT32U_VALUE. Otherwise,
 *   ::SL_STATUS_INVALID_STATE.
 */
sl_status_t sl_zigbee_set_outgoing_nwk_frame_counter(uint32_t desiredValue);

/** @brief Set the APS layer outgoing frame counter for Trust Center
 *    Link Key (intended for device restoration purposes).  Caveats:
 *    - Can only be called before NetworkInit / FormNetwork / JoinNetwork,
 *      when sl_zigbee_network_state()==SL_ZIGBEE_NO_NETWORK.
 *    - This function should be called before ::sl_zigbee_set_initial_security_state,
 *      and the SL_ZIGBEE_NO_FRAME_COUNTER_RESET bitmask should be added to the
 *      initial security bitmask when ::emberSetInitialSecuritState is called.
 *    - If used in multi-network context, call
 *      ::sl_zigbee_set_current_network() prior to calling this function.
 *
 * @param desiredValue The desired outgoing APS frame counter value.  This
 *   needs to be less than MAX_INT32U_VALUE to ensure that rollover
 *   does not occur on the next encrypted transmission.
 *
 * @return ::SL_STATUS_OK if calling context is valid (sl_zigbee_network_state()
 *   == SL_ZIGBEE_NO_NETWORK) and desiredValue < MAX_INT32U_VALUE. Otherwise,
 *   ::SL_STATUS_INVALID_STATE.
 */
sl_status_t sl_zigbee_set_outgoing_aps_frame_counter(uint32_t desiredValue);

/** @brief Clear all transient link keys from RAM. */
void sl_zigbee_clear_transient_link_keys(void);

/** @brief The length of time, in seconds, that a trust center will store
 *  a transient link key that a device can use to join its network. A
 *  transient key is added with a call to sl_zigbee_sec_man_import_transient_key. After the
 *  transient key is added, it will be removed once this amount of time has
 *  passed. A joining device will not be able to use that key to join until
 *  it is added again on the trust center. The default value is 300 seconds,
 *  i.e., 5 minutes.
 */
uint16_t sl_zigbee_get_transient_key_timeout_s(void);
void sl_zigbee_set_transient_key_timeout_s(uint16_t seconds);

/*
 * @brief Return the current rejoin policy, which can either allow no rejoin
 * at all, allow rejoin only with non-default link keys, or allow all kinds of rejoins.
 * There are no EZSP/NCP implementations for this function.
 *
 *  @return NO_REJOIN, REJOIN_ANY_LINK_KEY, REJOIN_NON_DEFAULT_LINK_KEY.
 */
sl_zigbee_aps_rejoin_mode_t sl_zigbee_get_rejoin_mode(void);

/*
 * @brief Set the current rejoin policy, which can either allow no rejoin
 * at all, allow rejoin only with non-default link keys, or allow all kinds of
 * rejoins.
 *
 * @param NO_REJOIN, REJOIN_ANY_LINK_KEY, REJOIN_NON_DEFAULT_LINK_KEY.
 *
 * There are no EZSP/NCP implementations for this function.
 */
void sl_zigbee_set_rejoin_mode(sl_zigbee_aps_rejoin_mode_t mode);

/* return the (security framecounter) */
uint32_t sl_zigbee_get_security_frame_counter(void);
uint32_t sl_zigbee_get_aps_frame_counter(void);
uint32_t sl_zigbee_get_incoming_tc_link_key_frame_counter(void);
void sl_zigbee_set_incoming_tc_link_key_frame_counter(uint32_t frameCounter);
// @} END addtogroup

#endif // SILABS_SECURITY_H
