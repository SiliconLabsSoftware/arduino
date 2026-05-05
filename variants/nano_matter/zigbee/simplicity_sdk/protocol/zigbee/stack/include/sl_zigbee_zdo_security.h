/***************************************************************************//**
 * @file  sl_zigbee_zdo_security.h
 * @brief ZDO Security functionality described in R23 including retrieving and
 * generating Authentication Token
 *******************************************************************************
 * # License
 * <b>Copyright 2023 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SL_ZIGBEE_ZDO_SECURITY_H
#define SL_ZIGBEE_ZDO_SECURITY_H

#include "stack/include/sl_zigbee_types.h"
#include "sl_enum.h"

SL_ENUM(sl_zigbee_initial_join_method) {
  INITIAL_JOIN_METHOD_TYPE_ANONYMOUS               = 0,
  INITIAL_JOIN_METHOD_TYPE_INSTALL_CODE_KEY        = 1,
  INITIAL_JOIN_METHOD_TYPE_WELL_KNOWN_PASSPHRASE   = 2,
  INITIAL_JOIN_METHOD_TYPE_INSTALL_CODE_PASSPHRASE = 3,
};

SL_ENUM(sl_zigbee_active_link_key_type) {
  ACITVE_LINK_KEY_TYPE_NOT_UPDATED                    = 0,
  ACITVE_LINK_KEY_TYPE_KEY_REQUEST_METHOD             = 1,
  ACITVE_LINK_KEY_TYPE_ANONYMOUS_KEY_NEGOTIATION      = 2,
  ACITVE_LINK_KEY_TYPE_AUTHENTICATED_KEY_NEGOTIATION  = 3,
  ACITVE_LINK_KEY_TYPE_CERTIFICATE_BASED_KEY_EXCHANGE = 4,
};

/** @brief Gets Authentication Level of queried device
 *
 * @param dest Short address of where you want to send the request (trust center)
 * @param target EUI64 of queried device
 *
 * @return An ::sl_status value that indicates whether the request was
 * successful or if an error status needs to be sent back.
 */
sl_status_t sl_zigbee_get_authentication_level(sl_802154_short_addr_t dest, sl_802154_long_addr_t target);

extern void sl_zigbee_set_authenticaion_level_callback(sl_802154_long_addr_t target,
                                                       sl_zigbee_initial_join_method *initial_join_method,
                                                       sl_zigbee_active_link_key_type *active_link_key_type);

extern void sl_zigbee_get_authentication_level_callback(sl_zigbee_zdo_status_t rsp_status, sl_802154_long_addr_t target, uint8_t join_method, uint8_t link_key_update);

/** @brief Get the Symmetric Passphrase for a device.
 * This function will return the Symmetric Passphrase for a device if one exists.
 * If a long address (EUI64) is provided, that will be checked first.
 * If the long address is set to NULL, then the Short Id is used.
 * If a matching entry is found, then return SUCCESS, else FAILURE.
 *
 * @param eui64 Long Address of device to match in the passphrase key store
 * @param short_id Short Address of device to match in the passphrase key store
 * @param passphrase Pointer to the buffer for the passphrase to be copied into
 *
 * @return An ::sl_status value that indicates outcome of the operation.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# passphrase | length: 16 | max: 16 #}
 */
sl_status_t sl_zigbee_get_symmetric_passphrase(sl_802154_long_addr_t eui64,
                                               sl_802154_short_addr_t short_id,
                                               uint8_t *passphrase);

/** @brief Application-defined callback to notify completion of symmetric passphrase operation
 *
 * @param status status of processing this response (SL_STATUS_OK if successful op)
 */
extern void sl_zigbee_zdo_retrieve_authentication_token_complete_callback(sl_status_t status);

/** @brief Schedules sending the Security Retrieve Authentication Token Request.
 *
 * This function will schedule an event to send the Retrieve Authentication Token
 * request after a short delay. This allows the calling function to continue
 * and have the event framework send out the command.
 *
 * @param destination Device to send the request to
 * @param options APS Options
 *
 */
void sl_zigbee_retrieve_authentication_token(sl_802154_short_addr_t destination,
                                             sl_zigbee_aps_option_t options);

sl_status_t sl_zigbee_initiate_security_challenge(sl_802154_short_addr_t partnerNodeId,
                                                  sl_802154_long_addr_t partnerLong,
                                                  uint8_t keyIndex);
#endif // SL_ZIGBEE_ZDO_SECURITY_H
