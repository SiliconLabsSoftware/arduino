/***************************************************************************//**
 * @file
 * @brief Utilities for forming and joining networks.
 *
 * See @ref networks for documentation.
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

#ifndef SILABS_FORM_AND_JOIN_H
#define SILABS_FORM_AND_JOIN_H

/**
 * @addtogroup networks
 * Functions for finding an existing network to join and for
 * finding an unused PAN id with which to form a network.
 *
 * Summary of application requirements:
 *
 * For the SoC:
 * - Define ::SL_ZIGBEE_APPLICATION_HAS_ENERGY_SCAN_RESULT_HANDLER
 *   in the configuration header.
 * - Call ::sl_zigbee_form_and_join_tick() regularly in the main loop.
 * - Include form-and-join.c and form-and-join-node-adapter.c in the build.
 * - Optionally include form-and-join-node-callbacks.c in the build.
 * - If processor idling is desired:
 *   -- Call ::sl_zigbee_form_and_join_task_init() to initialize the form and join task
 *   -- Call ::sl_zigbee_form_and_join_run_task() regularly in the main loop instead of
 *      ::sl_zigbee_form_and_join_tick()
 *
 * For an EZSP Host:
 * - Define ::EZSP_APPLICATION_HAS_ENERGY_SCAN_RESULT_HANDLER
 *   in the configuration header.
 * - Include form-and-join.c and form-and-join-host-adapter.c in the build.
 * - Optionally include form-and-join-host-callbacks.c in the build.
 *
 * For either platform, the application can omit the
 * form-and-join-*-callback.c file from the build and implement
 * the callbacks itself if necessary.  In this case, the appropriate
 * form-and-join callback function must be called from within each callback
 * as within the form-and-join-*-callback.c files.
 *
 * On either platform, FORM_AND_JOIN_MAX_NETWORKS can be explicitly defined to
 * limit (or expand) the number of joinable networks that the library will
 * save for consideration during the scan process.
 *
 * The library can resume scanning for joinable networks from where it
 * left off, via a call to sl_zigbee_scan_for_next_joinable_network(). Therefore, if the
 * first joinable network found is not the correct one, the application can
 * continue scanning without starting from the beginning and without finding
 * the same network that it has already rejected.  The library can also be used
 * on the host processor.
 *
 * @{
 */

/** @brief Number of bytes required to store relevant info for a saved network.
 *
 * This constant represents the minimum number of bytes required to store all
 * members of the sli_zigbee_network_info_t struct used in the adapter code.  Its value should
 * not be changed unless the underlying adapter code is updated accordingly.
 * Note that this constant's value may be different than sizeof(sli_zigbee_network_info_t)
 * because some compilers pad the structs to align on word boundaries.
 * Thus, the adapter code stores/retrieves these pieces of data individually
 * (to be platform-agnostic) rather than as a struct.
 *
 * For efficiency's sake, this number should be kept to a power of 2 and not
 * and not exceed 32 (PACKET_BUFFER_SIZE).
 */
#define NETWORK_STORAGE_SIZE  16

/** @brief Log_base2 of ::NETWORK_STORAGE_SIZE
 */
#define NETWORK_STORAGE_SIZE_SHIFT 4

/** @brief Number of joinable networks that can be remembered during the scan
 * process.
 *
 * Note for EZSP Host Platforms: In the host implementation of this library,
 * the storage size for the detected networks buffer is controlled by
 * ::EZSP_HOST_FORM_AND_JOIN_BUFFER_SIZE, so that limits the highest value that
 * the host can set for FORM_AND_JOIN_MAX_NETWORKS.
 */
#ifndef FORM_AND_JOIN_MAX_NETWORKS
  #ifdef EZSP_HOST
// the host's buffer is 16-bit array, so translate to bytes for comparison
    #define FORM_AND_JOIN_MAX_NETWORKS \
  (EZSP_HOST_FORM_AND_JOIN_BUFFER_SIZE * 2 / NETWORK_STORAGE_SIZE)
  #else
//matching the default config value on host
    #define FORM_AND_JOIN_MAX_NETWORKS 5
  #endif
#endif

/** @brief Find an unused PAN ID.
 *
 * Does an energy scan on the indicated channels and randomly chooses
 * one from amongst those with the least average energy. Then
 * picks a short PAN ID that does not appear during an active
 * scan on the chosen channel.  The chosen PAN ID and channel are returned
 * via the ::sl_zigbee_unused_pan_id_found_handler() callback.  If an error occurs, the
 * application is informed via the ::sl_zigbee_scan_error_handler().
 *
 * @param channelMask
 * @param duration  The duration of the energy scan.  See the documentation
 * for ::sl_zigbee_start_scan() in stack/include/network-formation.h for information
 * on duration values.
 * @return SL_STATUS_NOT_AVAILABLE if the form and join library is not
 * available.
 */
sl_status_t sl_zigbee_scan_for_unused_pan_id(uint32_t channelMask, uint8_t duration);

/** @brief Find a joinable network.
 *
 * Performs an active scan on the specified channels looking for networks that:
 * -# currently permit joining,
 * -# match the stack profile of the application,
 * -# match the extended PAN id argument if it is not NULL.
 *
 * Upon finding a matching network, the application is notified via the
 * sl_zigbee_joinable_network_found_handler() callback, and scanning stops.
 * If an error occurs during the scanning process, the application is
 * informed via the sl_zigbee_scan_error_handler(), and scanning stops.
 *
 * If the application determines that the discovered network is not the correct
 * one, it may call sl_zigbee_scan_for_next_joinable_network() to continue the scanning
 * process where it was left off and find a different joinable network.  If the
 * next network is not the correct one, the application can continue to call
 * sl_zigbee_scan_for_next_joinable_network().  Each call must
 * occur within 30 seconds of the previous one, otherwise the state of the scan
 * process is deleted to free up memory.  Calling sl_zigbee_scan_for_joinable_network()
 * causes any old state to be forgotten and starts scanning from the beginning.
 *
 * @param channelMask
 * @param extendedPanId
 * @return SL_STATUS_NOT_AVAILABLE if the form and join library is not
 * available.
 */
sl_status_t sl_zigbee_scan_for_joinable_network(uint32_t channelMask, uint8_t* extendedPanId);

/** @brief See sl_zigbee_scan_for_joinable_network(). */
sl_status_t sl_zigbee_scan_for_next_joinable_network(void);

/** @brief Return true if and only if the form and join library is in the
 * process of scanning and is therefore expecting scan results to be passed
 * to it from the application.
 */
bool sl_zigbee_form_and_join_is_scanning(void);

/** @brief Return true if and only if the application can continue a joinable
 * network scan by calling sl_zigbee_scan_for_next_joinable_network().  See
 * sl_zigbee_scan_for_joinable_network().
 */
bool sl_zigbee_form_and_join_can_continue_joinable_network_scan(void);

//------------------------------------------------------------------------------
// Callbacks the application needs to implement.

/** @brief A callback the application needs to implement.
 *
 * Notifies the application of the network found after a call
 * to ::sl_zigbee_scan_for_joinable_network() or
 * ::sl_zigbee_scan_for_next_joinable_network().
 *
 * @param networkFound
 * @param lqi  The LQI value of the received beacon.
 * @param rssi The RSSI value of the received beacon.
 */
void sl_zigbee_joinable_network_found_handler(sl_zigbee_zigbee_network_t *networkFound,
                                              uint8_t lqi,
                                              int8_t rssi);

/** @brief A callback the application needs to implement.
 *
 * If an error occurs while scanning,
 * this function is called and the scan effort is aborted.
 *
 * Possible return status values are:
 * <ul>
 * <li> SL_STATUS_INVALID_STATE: if sl_zigbee_scan_for_next_joinable_network() is called
 * more than 30 seconds after a previous call to sl_zigbee_scan_for_joinable_network()
 * or sl_zigbee_scan_for_next_joinable_network().
 * <li> SL_STATUS_ALLOCATION_FAILED: if there is not enough memory to start a scan.
 * <li> SL_STATUS_NO_BEACONS: if no joinable beacons are found.
 * <li> SL_STATUS_MAC_SCANNING: if a scan is already in progress.
 * </ul>
 *
 * @param status
 */
void sl_zigbee_scan_error_handler(sl_status_t status);

//------------------------------------------------------------------------------
// Library functions the application must call from within the
// corresponding EmberZNet or EZSP callback.

/** @brief The application must call this function from within its
 * sl_zigbee_scan_complete_handler() (on the node) or sl_zigbee_ezsp_scan_complete_handler()
 * (on an EZSP host).  Default callback implementations are provided
 * in the form-and-join-*-callbacks.c files.
 *
 * @return true if the library made use of the call.
 */
bool sl_zigbee_form_and_join_scan_complete_handler(uint8_t channel, sl_status_t status);

/** @brief The application must call this function from within its
 * sl_zigbee_network_found_handler() (on the node) or sl_zigbee_ezsp_network_found_handler()
 * (on an EZSP host).  Default callback implementations are provided
 * in the form-and-join-*-callbacks.c files.
 *
 * @return true if the library made use of the call.
 */
bool sl_zigbee_form_and_join_network_found_handler(sl_zigbee_zigbee_network_t *networkFound,
                                                   uint8_t lqi,
                                                   int8_t rssi);

/** @brief The application must call this function from within its
 * sl_zigbee_energy_scan_result_handler() (on the node) or sl_zigbee_ezsp_energy_scan_result_handler()
 * (on an EZSP host).  Default callback implementations are provided
 * in the form-and-join-*-callbacks.c files.
 *
 * @return true if the library made use of the call.
 */
bool sl_zigbee_form_and_join_energy_scan_result_handler(uint8_t channel, int8_t maxRssiValue);

/** @brief The application must call this function from within its
 * sl_zigbee_unused_pand_id_found_handler() (on the node) or sl_zigbee_ezsp_energy_scan_result_handler()
 * (on an EZSP host). Default callback implementations are provided
 * in the form-and-join-*-callbacks.c files.
 */
bool sl_zigbee_form_and_join_unused_pan_id_found_handler(sl_802154_pan_id_t panId, uint8_t channel);

/** Used by the form and join code on the node to time out a joinable scan after
 * 30 seconds of inactivity. The application must call sl_zigbee_form_and_join_tick()
 * regularly.  This function does not exist for the EZSP host library.
 */
void sl_zigbee_form_and_join_tick(void);

/** @brief When processor idling is desired on the SOC, this must be called to
 *   properly initialize the form and join library
 */
void sl_zigbee_form_and_join_task_init(void);

/** @brief When processor idling is desired on the SOC, this should be called
 *   regularly instead of ::sl_zigbee_form_and_join_tick()
 */
void sl_zigbee_form_and_join_run_task(void);

/** @brief When form-and-join state is no longer needed, the application
 *   can call this routine to cleanup and free resources.  On the SOC
 *   platforms this will free the allocated message buffer.
 */
void sl_zigbee_form_and_join_cleanup(sl_status_t status);

/** @brief Network found.
 *
 * This is called by the form-and-join library to notify the application of the
 * network found after a call to ::sl_zigbee_scan_for_joinable_network() or
 * ::sl_zigbee_scan_for_next_joinable_network(). See form-and-join documentation for
 * more information.
 *
 * @param networkFound   Ver.: always
 * @param lqi   Ver.: always
 * @param rssi   Ver.: always
 */
void sl_zigbee_af_form_and_join_network_found_cb(sl_zigbee_zigbee_network_t *networkFound,
                                                 uint8_t lqi,
                                                 int8_t rssi);

/** @brief Unused Pan ID found.
 *
 * This function is called when the form-and-join library finds an unused PAN
 * ID that can be used to form a new network on.
 *
 * @param panId A randomly generated PAN ID without other devices on it.
 * Ver.: always
 * @param channel The channel where the PAN ID can be used to form a new
 * network. Ver.: always
 */
void sl_zigbee_af_form_and_join_unused_pan_id_found_cb(sl_802154_pan_id_t panId,
                                                       uint8_t channel);

/** @} END addtogroup
 */

#endif // SILABS_FORM_AND_JOIN_H
