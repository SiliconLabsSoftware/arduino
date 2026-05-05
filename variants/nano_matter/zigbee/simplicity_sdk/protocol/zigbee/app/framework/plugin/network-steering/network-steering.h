/***************************************************************************//**
 * @file
 * @brief APIs and defines for the Network Steering plugin.
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

#ifndef SILABS_NETWORK_STEERING_H
#define SILABS_NETWORK_STEERING_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif
#ifndef SL_ZIGBEE_SCRIPTED_TEST
#ifdef SL_CATALOG_ZIGBEE_NETWORK_STEERING_PRESENT
#include "network-steering-config.h"
#else
#include "config/network-steering-config.h"
#endif
#endif
#if (SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_OPTIMIZE_SCANS == 1)
#define OPTIMIZE_SCANS
#endif
#if (SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_RADIO_TX_CALLBACK == 1)
#define RADIO_TX_CALLBACK
#endif
#if (SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_TRY_ALL_KEYS == 1)
#define TRY_ALL_KEYS
#endif
#if (SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_ENABLE_AUTOSTART == 1)
#define ENABLE_STEERING_AUTOSTART
#endif

/**
 * @defgroup network-steering Network Steering
 * @ingroup component
 * @brief API and Callbacks for the Network Steering Component
 *
 * This component performs the necessary steps to join the network of any Zigbee
 * Profile. It first tries to perform a join using an install code using the
 * primary channel mask, and then the secondary channel mask. If that does not
 * work, it then tries to use the default well-known link key (ZigBeeAlliance09)
 * to join on the primary channel mask, and then the secondary channel mask.
 * Finally, if the previous two key types fail, the component tries to use the
 * distributed security link key (D0D1D2...) to join on the primary channel
 * mask, and then the secondary channel mask.
 *
 */

/**
 * @addtogroup network-steering
 * @{
 */

// -----------------------------------------------------------------------------
// Constants
#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern const uint8_t sli_zigbee_af_network_steering_plugin_name[];
#endif //DOXYGEN_SHOULD_SKIP_THIS

// -----------------------------------------------------------------------------
// Types

#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_af_plugin_network_steering_state_t
#else
enum
#endif //DOXYGEN_SHOULD_SKIP_THIS
{
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_NONE                         = 0x00,
  // The Use Configured Key states are only run if explicitly configured to do
  // so. See sli_zigbee_af_network_steering_set_configured_key()

#ifndef OPTIMIZE_SCANS
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_PRIMARY_CONFIGURED      = 0x01,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_SECONDARY_CONFIGURED    = 0x02,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_PRIMARY_INSTALL_CODE    = 0x03,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_SECONDARY_INSTALL_CODE  = 0x04,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_PRIMARY_CENTRALIZED     = 0x05,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_SECONDARY_CENTRALIZED   = 0x06,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_PRIMARY_DISTRIBUTED     = 0x07,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_SECONDARY_DISTRIBUTED   = 0x08,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_FINISHED                = 0x09,
#else // !OPTIMIZE_SCANS
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_PRIMARY_CONFIGURED      = 0x01,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_PRIMARY_INSTALL_CODE    = 0x02,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_PRIMARY_CENTRALIZED     = 0x03,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_PRIMARY_DISTRIBUTED     = 0x04,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_SECONDARY_CONFIGURED    = 0x05,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_SECONDARY_INSTALL_CODE  = 0x06,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_SECONDARY_CENTRALIZED   = 0x07,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_SECONDARY_DISTRIBUTED   = 0x08,

  // Either the USE_ALL_KEY states are run or the non USE_ALL_KEY states are
  // run, but never both
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_PRIMARY_USE_ALL_KEYS    = 0x09,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_SECONDARY_USE_ALL_KEYS  = 0x0A,

  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_SCAN_FINISHED                = 0x0B,
#endif // OPTIMIZE_SCANS

  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_UPDATE_TCLK                  = 0x10,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_STATE_VERIFY_TCLK                  = 0x20,
};
typedef uint8_t sl_zigbee_af_plugin_network_steering_joining_state_t;

#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_af_plugin_network_steering_options_t
#else
enum
#endif //DOXYGEN_SHOULD_SKIP_THIS
{
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_OPTIONS_NONE                       = 0x00,
  SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_OPTIONS_NO_TCLK_UPDATE             = 0x01,
};
typedef uint8_t sl_zigbee_af_plugin_network_steering_options_t;

extern sl_zigbee_af_plugin_network_steering_options_t sli_zigbee_af_network_steering_options_mask;

// -----------------------------------------------------------------------------
// Globals

/** @brief The first set of channels on which to search for joinable networks. */
extern uint32_t sli_zigbee_af_network_steering_primary_channel_mask;
/** @brief The second set of channels on which to search for joinable networks. */
extern uint32_t sli_zigbee_af_network_steering_secondary_channel_mask;

/**
 * @name API
 * @{
 */

// -----------------------------------------------------------------------------
// API

/** @brief Initiate a network-steering procedure.
 *
 *
 * If the node is currently on a network, it performs network steering
 * in which it opens up the network with a broadcast
 * permit join message.
 *
 * If the node is not on a network, it scans a series of primary channels
 * (see ::sli_zigbee_af_network_steering_primary_channel_mask) to find possible
 * networks to join. If it is unable to join any of those networks, it
 * tries scanning on a set of secondary channels
 * (see ::sli_zigbee_af_network_steering_secondary_channel_mask). Upon completion of
 * this process, the plugin calls
 * ::sl_zigbee_af_network_steering_complete_cb with information regarding
 * the success or failure of the procedure.
 *
 * This procedure will try to join networks using install codes, the centralized
 * default key, and the distributed default key.
 *
 * @return An ::sl_status_t value that indicates the success or failure of
 * the initiating of the network steering process.
 *
 * @note Do not call this API from a stack status callback, as this plugin acts
 * when its own stack status callback is invoked.
 */
sl_status_t sl_zigbee_af_network_steering_start(void);

/** @brief Stops the network steering procedure.
 *
 *
 * @return An ::sl_status_t value that indicates the success or failure of
 * the initiating of the network steering process.
 */
sl_status_t sl_zigbee_af_network_steering_stop(void);

/** @} */ // end of name API

/**
 * @name Callbacks
 * @{
 */

/**
 * @defgroup nw_steering_cb Network Steering
 * @ingroup af_callback
 * @brief Callbacks for Network Steering Component
 *
 */

/**
 * @addtogroup nw_steering_cb
 * @{
 */

/** @brief Complete network steering.
 *
 * This callback is fired when the Network Steering plugin is complete.
 *
 * @param status On success this will be set to SL_STATUS_OK to indicate a
 * network was joined successfully. On failure this will be the status code of
 * the last join or scan attempt. Ver.: always
 *
 * @param totalBeacons The total number of 802.15.4 beacons that were heard,
 * including beacons from different devices with the same PAN ID. Ver.: always
 * @param joinAttempts The number of join attempts that were made to get onto
 * an open Zigbee network. Ver.: always
 *
 * @param finalState The finishing state of the network steering process. From
 * this, one is able to tell on which channel mask and with which key the
 * process was complete. Ver.: always
 */
void sl_zigbee_af_network_steering_complete_cb(sl_status_t status,
                                               uint8_t totalBeacons,
                                               uint8_t joinAttempts,
                                               uint8_t finalState);

/** @brief Get power for a radio channel.
 *
 * This callback is fired when the Network Steering plugin needs to set the
 * power level. The application has the ability to change the max power level
 * used for this particular channel.
 *
 * @param channel The channel that the plugin is inquiring about the power
 * level. Ver.: always
 */
int8_t sl_zigbee_af_network_steering_get_power_for_radio_channel_cb(uint8_t channel);

/** @brief Get the distributed key.
 *
 * This callback is fired when the Network Steering plugin needs to set the distributed
 * key. The application set the distributed key from Zigbee Alliance through this callback
 * or the network steering will use the default test key.
 *
 * @param pointer to the distributed key struct
 * @return true if the key is loaded successfully, otherwise false.
 * level. Ver.: always
 */
bool sl_zigbee_af_network_steering_get_distributed_key_cb(sl_zigbee_key_data_t * key);

/** @brief Get the node type.
 *
 * This callback allows the application to set the node type that the network
 * steering process will use in joining a network.
 *
 * @param state The current ::sl_zigbee_af_plugin_network_steering_joining_state_t.
 *
 * @return An ::sl_zigbee_node_type_t value that the network steering process will
 * try to join a network as.
 */
sl_zigbee_node_type_t sl_zigbee_af_network_steering_get_node_type_cb(sl_zigbee_af_plugin_network_steering_joining_state_t state);

/** @} */ // end of nw_steering_cb
/** @} */ // end of name Callbacks
/** @} */ // end of network-steering

/** @brief Override the channel mask. */
void sli_zigbee_af_network_steering_set_channel_mask(uint32_t mask, bool secondaryMask);

/** @brief Set extended PAN ID to search for. */
void sli_zigbee_af_network_steering_set_extended_pan_id_filter(uint8_t* extendedPanId,
                                                               bool turnFilterOn);

/** @brief Set a different key to use when joining. */
void sli_zigbee_af_network_steering_set_configured_key(const uint8_t *key,
                                                       bool useConfiguredKey);

/** @brief Clean up the network steering process which took place */
void sli_zigbee_af_network_steering_cleanup(sl_status_t status);

/** @brief Configurable wrapper for sl_zigbee_af_network_steering_start.
 * Calls sl_zigbee_af_network_steering_start and prints its status if
 * SL_ZIGBEE_AF_PLUGIN_NETWORK_STEERING_ENABLE_AUTOSTART is configured to be true,
 * will do nothing if it is false.
 */
void sl_zigbee_af_network_steering_autostart(void);

#ifdef __cplusplus
}
#endif

#endif /* __NETWORK_STEERING_H__ */
