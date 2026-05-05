/***************************************************************************//**
 * @file
 * @brief EmberZNet Smart Energy security API.
 * See @ref smart_energy_security for documention.
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

#ifndef SILABS_CBKE_CRYPTO_ENGINE_H
#define SILABS_CBKE_CRYPTO_ENGINE_H

#include "stack/include/sl_zigbee_types.h"

/**
 * @addtogroup smart_energy_security
 *
 * This file describes functionality for Certificate Based Key Exchange (CBKE).
 * This is used by Smart Energy devices to generate and store ephemeral ECC
 * keys, derive the SMACs for the Key establishment protocol, and sign messages
 * using their private key for the Demand Response Load Control client cluster.
 *
 * See cbke-crypto-engine.h for source code.
 * @{
 */

/** @brief Retrieve the implicit certificate stored in the MFG tokens of the
 *  device.
 *
 * @param result A pointer to an ::sl_zigbee_certificate_data_t structure where the
 * retrieved certificate will be stored.
 *
 * @return ::SL_STATUS_OK if the certificate was successfully retrieved.
 *   ::SL_STATUS_FAIL if the token contains uninitialized data.
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# result #}
 */
sl_status_t sl_zigbee_get_certificate(sl_zigbee_certificate_data_t* result);

/** @brief Begin the process of generating an ephemeral
 *  public/private ECC key pair.
 *
 *  If no other ECC operation is going on,
 *  it will immediately return with ::SL_STATUS_IN_PROGRESS.  It will
 *  delay a period of time to let APS retries take place, but then it will
 *  shutdown the radio and consume the CPU processing until the key generation
 *  is complete.  This may take up to 1 second.
 *
 *  The generated results of the key generation is returned
 *  via ::sl_zigbee_generate_cbke_keys_handler().
 *
 * @return ::SL_STATUS_IN_PROGRESS if the stack has queued up the
 *   operation for execution.
 */
sl_status_t sl_zigbee_generate_cbke_keys(void);

/** @brief Begin the process of generating the shared
 *  secret, the new link key, and the Secured Message Authentication Code (SMAC).
 *
 *  If no other ECC operation is going on, it will immediately return with
 *  ::SL_STATUS_IN_PROGRESS.  It will delay a period of time to let APS
 *  retries take place, but then it will shutdown the radio and consume the
 *  CPU processing until SMACs calculations are complete.  This may take up to
 *  3.5 seconds.
 *
 *  The calculated SMACS are returned via ::sl_zigbee_calculate_smacs_handler().
 *
 * @param amInitiator This bool indicates whether or not the device is the
 *   one that initiated the CBKE with the remote device, or whether it was the
 *   responder to the exchange.
 * @param partnerCert A pointer to an ::sl_zigbee_certificate_data_t structure that
 *   contains the CBKE partner's implicit certificate.
 * @param partnerEphemeralPublicKey A pointer to an ::sl_zigbee_public_key_data_t
 *   structure that contains the CBKE partner's ephemeral public key.
 *
 * @return ::SL_STATUS_IN_PROGRESS if the stack has queued up the
 *   operation for execution.
 */
sl_status_t sl_zigbee_calculate_smacs(bool amInitiator,
                                      sl_zigbee_certificate_data_t* partnerCert,
                                      sl_zigbee_public_key_data_t* partnerEphemeralPublicKey);

/** @brief Call when all CBKE operations are done.
 *  Any temporary data created during calls to sl_zigbee_generate_cbke_keys() or
 *  sl_zigbee_calculate_smacs() is wiped out.  If the local device has validated
 *  that the partner device has generated the same SMACS as itself, it should
 *  set 'storeLinkKey' to true.  Otherwise it should pass in false.
 *
 * @param storeLinkKey This tells the stack whether to store the newly
 *   generated link key, or discard it.
 *
 * @return If storeLinkkey is false, this function returns ::SL_STATUS_FAIL
 *   always.  If storeLinkKey is true, then this function returns the results
 *   of whether or not the link key was stored.  ::SL_STATUS_OK is
 *   returned when key was stored successfully.
 */
sl_status_t sl_zigbee_clear_temporary_data_maybe_store_link_key(bool storeLinkKey);

/* @brief LEGACY FUNCTION:  This functionality has been replaced by a single
 * bit in the ::sl_zigbee_aps_frame_t, ::SL_ZIGBEE_APS_OPTION_DSA_SIGN.  Devices wishing
 * to send signed messages should use that as it requires fewer function calls
 * and message buffering.  sl_zigbee_dsa_sign_handler() is still called when using
 * ::SL_ZIGBEE_APS_OPTION_DSA_SIGN.  However, this function is still supported.
 *
 * This function begins the process of signing the passed message
 * contained within the buffer.  If no other ECC operation is going on,
 * it will immediately return with ::SL_STATUS_IN_PROGRESS.
 * It will delay a period of time to let APS retries take place, but then it
 * will shutdown the radio and consume the CPU processing until the signing
 * is complete.  This may take up to 1 second.
 *
 * The signed message will be returned in ::sl_zigbee_dsa_sign_handler().
 *
 * Note that the last byte of the buffer contents passed to this function has
 * special significance.  As the typical use case for DSA signing is to sign the
 * ZCL payload of a DRLC Report Event Status message in SE 1.0, there is often
 * both a signed portion (ZCL payload) and an unsigned portion (ZCL header).
 * The last byte in the content of messageToSign is therefore used as a
 * special indicator to signify how many bytes of leading data in the buffer
 * should be excluded from consideration during the signing process.  If the
 * signature needs to cover the entire buffer (all bytes except last one),
 * the caller should ensure that the last byte of the buffer contents is 0.
 * When the signature operation is complete, this final byte will be replaced
 * by the signature type indicator (0x01 for ECDSA signatures), and the
 * actual signature will be appended to the buffer after this byte.
 *
 * @param messageToSign The message buffer containing the complete message,
 *   both the to-be-signed portion as well as any leading data excluded from
 *   the signing operation.  See note above regarding special requirements
 *   for this buffer.
 *
 * @return ::SL_STATUS_IN_PROGRESS if the stack has queued up the
 *   operation for execution.  ::SL_STATUS_INVALID_STATE if the operation can't be
 *   performed in this context (possibly because another ECC operation is
 *   pending.)
 */
sl_status_t sl_zigbee_dsa_sign(sli_buffer_manager_buffer_t messageToSign);

/* @brief This function is an application callback that must be defined
 * when using CBKE.  It is called when the ephemeral key generation operation
 * is complete.  The newly generated public key is passed back to the
 * application to be sent to the CBKE partner over-the-air.  Internally
 * the stack saves the public and private key pair until it the function
 * ::sl_zigbee_clear_temporary_data_maybe_store_link_key() is called by the application.
 *
 * @param status This is the ::sl_status_t value indicating the success or
 *   failure of the operation.
 * @param ephemeralPublicKey A pointer to an ::sl_zigbee_public_key_data_t structure
 *   containing the newly generated public key.
 */
void sl_zigbee_generate_cbke_keys_handler(sl_status_t status,
                                          sl_zigbee_public_key_data_t* ephemeralPublicKey);

/* @brief Application callback that must be defined
 * when using CBKE.  It is called when the shared secret generation is
 * complete and the link key and SMACs have been derived.  The link key is
 * stored in a temporary location until the application decides to
 * store or discard the key by calling
 * ::sl_zigbee_clear_temporary_data_maybe_store_link_key().
 *
 * @param status This is the ::sl_status_t value indicating the success or
 *   failure of the operation.
 * @param initiatorSmac This is a pointer to the ::sl_zigbee_smac_data_t structure
 *   to the initiator's version of the SMAC.
 * @param responderSmac This is a pointer to the ::sl_zigbee_smac_data_t structure
 *   to the responder's version of the SMAC.
 */
void sl_zigbee_calculate_smacs_handler(sl_status_t status,
                                       sl_zigbee_smac_data_t* initiatorSmac,
                                       sl_zigbee_smac_data_t* responderSmac);

/** @brief Application callback that must be defined
 * when using CBKE.  This callback is provided to the application to let
 * it know that the ECC operations have completed and the radio has been turned
 * back on.  When using the sign-and-send option of the ::sl_zigbee_aps_frame_t,
 * ::SL_ZIGBEE_APS_OPTION_DSA_SIGN, the handler will NOT return the complete
 * signed message.  This callback is merely informative.  If ::sl_zigbee_dsa_sign()
 * has been called, the message plus signature will be returned to the caller
 * and it must be sent separately by one of the message send primitives
 * (such as ::sl_zigbee_send_unicast()).
 *
 * @param status This is the ::sl_status_t value indicating the success or
 *   failure of the operation.
 * @param messageLength   Length of the newly signed message, if ::sl_zigbee_dsa_sign() was called.
 * @param messageContents This is the newly signed message, if ::sl_zigbee_dsa_sign() was called.
 * If message was signed using ::SL_ZIGBEE_APS_OPTION_DSA_SIGN then this will be NULL.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# messageContents | length: messageLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
void sl_zigbee_dsa_sign_handler(sl_status_t status,
                                uint8_t messageLength,
                                uint8_t *messageContents);

/* @brief Update the Smart Energy certificate,
 * CA public key, and local private key that the device uses for CBKE.
 * The preferred method for adding certificates is to pre-install them
 * in MFG tokens when the chip is manufactured.  However this function
 * allows the certificate to be updated at runtime after the device has
 * been deployed.
 *   The behavior of this function differs based on the hardware platform.
 *
 * For the 2xx:
 * To use this functionality the application must also set
 * the stack configuration value ::SL_ZIGBEE_CERTIFICATE_TABLE_SIZE to 1.
 * Attempts to call this function with ::SL_ZIGBEE_CERTIFICATE_TABLE_SIZE of 0
 * will return ::SL_STATUS_INVALID_CONFIGURATION.
 * The passed security data will be persistently stored in stack tokens.
 * The certificate contains the EUI64 it is associated with.  If that
 * EUI64 matches the EUI64 currently in use by the device, this
 * function may be called at any time, even while running in a network.
 * If the EUI64 does not match, this function may only be called when the
 * network is in a state of ::SL_ZIGBEE_NO_NETWORK.  Attempts to do otherwise
 * will result in a return value of ::SL_STATUS_INVALID_STATE.
 *
 * For the 3xx:
 * This function allows a one-time write of the MFG token if it has not
 * already been set.  It does NOT utilize the ::SL_ZIGBEE_CERTIFICATE_TABLE_SIZE
 * so that should remain set at 0.  Attempts to write the certificate that
 * has already been written will return a result of
 * ::SL_STATUS_FLASH_WRITE_INHIBITED.  If the EUI64 in the certificate is
 * the same as the current EUI of the device then this function may be called
 * while the stack is up.  If the EUI in the certificate is different than
 * the current value, this function may only be called when the network is in
 * a state of ::SL_ZIGBEE_NO_NETWORK.  Attempts to do otherwise will result in a
 * return value of ::SL_STATUS_INVALID_STATE.  If the EUI in the certificate is
 * different than the current value this function will also write the
 * Custom EUI64 MFG token.  If that token has already been written the operation
 * will fail and return a result of ::SL_STATUS_INVALID_PARAMETER.
 * If all the above criteria is met the token will be written and
 * ::SL_STATUS_OK will be returned.
 *
 * @note The device will immediately and persistently <b>change its EUI64
 * to match the value in the certificate</b>.
 *
 * @param caPublic A pointer to the CA public key data that will be stored
 *   in stack tokens.
 * @param myCert A pointer to the certificate data that will be stored in
 *   stack tokens.
 * @param mykey A pointer to the private key data that will be stored in
 *   stack tokens.
 * @return The ::sl_status_t value indicating success or failure of the
 *   operation.
 */
sl_status_t sl_zigbee_set_preinstalled_cbke_data(sl_zigbee_public_key_data_t* caPublic,
                                                 sl_zigbee_certificate_data_t* myCert,
                                                 sl_zigbee_private_key_data_t* myKey);

/* @brief Retrieve the EUI64 from the stack token
 * Smart Energy Certificate (it does not examine the MFG token certificate)
 * and returns the value in the "Subject" field (the EUI64) to the caller.
 * If no stack token is set, the ::SL_ZIGBEE_CERTIFICATE_TABLE_SIZE is zero
 * or if the CBKE library is not present, this function returns false
 * and the EUI64 for the return value is not set.
 *
 * @param certEui64 The location of the return value for the EUI64.
 * @return true if the stack token certificate is set and the EUI64
 *   return value is valid.  false otherwise.
 */
bool sl_zigbee_get_stack_certificate_eui64(sl_802154_long_addr_t certEui64);

/* @brief Verify the ECDSA signature of the
 * calculated digest and the associated received signature, using
 * the signerCertificate passed in.  It is expected that the application
 * obtains the signerCertificate and performs the message digest calculation
 * on its own.
 */
sl_status_t sl_zigbee_dsa_verify(sl_zigbee_message_digest_t* digest,
                                 sl_zigbee_certificate_data_t* signerCertificate,
                                 sl_zigbee_signature_data_t* receivedSig);

/* @brief Executed by the stack when the DSA verification
 * has completed and has a result.  If the result is SL_STATUS_OK, the
 * signature is valid.  If the result is SL_STATUS_ZIGBEE_SIGNATURE_VERIFY_FAILURE
 * then the signature is invalid.  If the result is anything else then the
 * signature verify operation failed and the validity is unknown.
 */
void sl_zigbee_dsa_verify_handler(sl_status_t status);

// Start of 283k1 Curve Definitions

/** @brief Retrieves the implicit certificate stored in the MFG tokens of the
 *  device.
 *
 * @param result A pointer to an ::sl_zigbee_certificate_283k1_data_t structure where the
 * retrieved certificate will be stored.
 *
 * @return ::SL_STATUS_OK if the certificate was successfully retrieved.
 *   ::SL_STATUS_FAIL if the token contains uninitialized data.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# result #}
 */
sl_status_t sl_zigbee_get_certificate_283k1(sl_zigbee_certificate_283k1_data_t* result);

/** @brief Begin the process of generating an ephemeral
 *  public/private ECC key pair.
 *
 *  If no other ECC operation is going on,
 *  it will immediately return with ::SL_STATUS_IN_PROGRESS.  It will
 *  delay a period of time to let APS retries take place, but then it will
 *  shutdown the radio and consume the CPU processing until the key generation
 *  is complete.  This may take up to 1 second.
 *
 *  The generated results of the key generation is returned
 *  via ::sl_zigbee_generate_cbke_keys_283k1_handler().
 *
 * @return ::SL_STATUS_IN_PROGRESS if the stack has queued up the
 *   operation for execution.
 */
sl_status_t sl_zigbee_generate_cbke_keys_283k1(void);

/** @brief Begin the process of generating the shared
 *  secret, the new link key, and the Secured Message Authentication Code (SMAC).
 *
 *  If no other ECC operation is going on, it will immediately return with
 *  ::SL_STATUS_IN_PROGRESS.  It will delay a period of time to let APS
 *  retries take place, but then it will shutdown the radio and consume the
 *  CPU processing until SMACs calculations are complete.  This may take up to
 *  3.5 seconds.
 *
 *  The calculated SMACS are returned via ::sl_zigbee_calculate_smacs_handler().
 *
 * @param amInitiator This bool indicates whether or not the device is the
 *   one that initiated the CBKE with the remote device, or whether it was the
 *   responder to the exchange.
 * @param partnerCert A pointer to an ::sl_zigbee_certificate_283k1_data_t structure that
 *   contains the CBKE partner's implicit certificate.
 * @param partnerEphemeralPublicKey A pointer to an ::sl_zigbee_public_key_283k1_data_t
 *   structure that contains the CBKE partner's ephemeral public key.
 *
 * @return ::SL_STATUS_IN_PROGRESS if the stack has queued up the
 *   operation for execution.
 */
sl_status_t sl_zigbee_calculate_smacs_283k1(bool amInitiator,
                                            sl_zigbee_certificate_283k1_data_t* partnerCert,
                                            sl_zigbee_public_key_283k1_data_t* partnerEphemeralPublicKey);

/** @brief Call when all CBKE 283k1 operations are done.
 *  Any temporary data created during calls to sl_zigbee_generate_cbke_keys_283k1() or
 *  sl_zigbee_calculate_smacs_283k1() is wiped out.  If the local device has validated
 *  that the partner device has generated the same SMACS as itself, it should
 *  set 'storeLinkKey' to true.  Otherwise it should pass in false.
 *
 * @param storeLinkKey This tells the stack whether to store the newly
 *   generated link key, or discard it.
 *
 * @return If storeLinkkey is false, this function returns ::SL_STATUS_FAIL
 *   always.  If storeLinkKey is true, then this function returns the results
 *   of whether or not the link key was stored.  ::SL_STATUS_OK is
 *   returned when key was stored successfully.
 */
sl_status_t sl_zigbee_clear_temporary_data_maybe_store_link_key_283k1(bool storeLinkKey);

/* @brief Application callback that must be defined
 * when using the CBKE 283k1 Library.  It is called when the ephemeral key
 * generation operation is complete.  The newly generated public key is passed
 * back to the application to be sent to the CBKE partner over-the-air. Internally
 * the stack saves the public and private key pair until it the function
 * ::sl_zigbee_clear_temporary_data_maybe_store_link_key_283k1() is called by the application.
 *
 * @param status This is the ::sl_status_t value indicating the success or
 *   failure of the operation.
 * @param ephemeralPublicKey A pointer to an ::sl_zigbee_public_key_data_t structure
 *   containing the newly generated public key.
 */
void sl_zigbee_generate_cbke_keys_283k1_handler(sl_status_t status,
                                                sl_zigbee_public_key_283k1_data_t* ephemeralPublicKey);

/* @brief Application callback that must be defined
 * when using CBKE.  It is called when the shared secret generation is
 * complete and the link key and SMACs have been derived.  The link key is
 * stored in a temporary location until the application decides to
 * store or discard the key by calling
 * ::sl_zigbee_clear_temporary_data_maybe_store_link_key_283k1().
 *
 * @param status This is the ::sl_status_t value indicating the success or
 *   failure of the operation.
 * @param initiatorSmac This is a pointer to the ::sl_zigbee_smac_data_t structure
 *   to the initiator's version of the SMAC.
 * @param responderSmac This is a pointer to the ::sl_zigbee_smac_data_t structure
 *   to the responder's version of the SMAC.
 */
void sl_zigbee_calculate_smacs_283k1_handler(sl_status_t status,
                                             sl_zigbee_smac_data_t* initiatorSmac,
                                             sl_zigbee_smac_data_t* responderSmac);

/* Allow a one-time write of the MFG token if it has not
 * already been set.  It does NOT utilize the ::SL_ZIGBEE_CERTIFICATE_TABLE_SIZE
 * so that should remain set at 0.  Attempts to write the certificate that
 * has already been written will return a result of
 * ::SL_STATUS_FLASH_WRITE_INHIBITED.  If the EUI64 in the certificate is
 * the same as the current EUI of the device then this function may be called
 * while the stack is up.  If the EUI in the certificate is different than
 * the current value, this function may only be called when the network is in
 * a state of ::SL_ZIGBEE_NO_NETWORK.  Attempts to do otherwise will result in a
 * return value of ::SL_STATUS_INVALID_STATE.  If the EUI in the certificate is
 * different than the current value this function will also write the
 * Custom EUI64 MFG token.  If that token has already been written the operation
 * will fail and return a result of ::SL_STATUS_INVALID_PARAMETER.
 * If all the above criteria is met the token will be written and
 * ::SL_STATUS_OK will be returned.
 *
 * @note The device will immediately and persistently <b>change its EUI64
 * to match the value in the certificate</b>.
 *
 * @param caPublic A pointer to the 283k1 CA public key data that will be stored
 *   in stack tokens.
 * @param myCert A pointer to the 283k1 certificate data that will be stored in
 *   stack tokens.
 * @param mykey A pointer to the 283k1 private key data that will be stored in
 *   stack tokens.
 * @return The ::sl_status_t value indicating success or failure of the
 *   operation.
 */
sl_status_t sl_zigbee_set_preinstalled_cbke_data_283k1(const sl_zigbee_public_key_283k1_data_t* caPublic,
                                                       const sl_zigbee_certificate_283k1_data_t* myCert,
                                                       const sl_zigbee_private_key_283k1_data_t* myKey);

/* @brief Verify the ECDSA signature of the
 * calculated digest and the associated received signature, using
 * the signerCertificate passed in.  It is expected that the application
 * obtains the signerCertificate and performs the message digest calculation
 * on its own.
 */
sl_status_t sl_zigbee_dsa_verify_283k1(const sl_zigbee_message_digest_t* digest,
                                       const sl_zigbee_certificate_283k1_data_t* signerCertificate,
                                       const sl_zigbee_signature_283k1_data_t* receivedSig);

/** @} END addtogroup */

#endif // SILABS_CBKE_CRYPTO_ENGINE_H
