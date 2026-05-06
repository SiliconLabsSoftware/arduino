/***************************************************************************//**
 * @file
 * @brief Dispatching 802.15.4 scan results to interested parties.
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

#ifndef SILABS_SCAN_DISPATCH_H
#define SILABS_SCAN_DISPATCH_H
#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif
#ifdef SL_CATALOG_ZIGBEE_SCAN_DISPATCH_PRESENT
#include "scan-dispatch-config.h"
#else
#include "app/framework/plugin/scan-dispatch/config/scan-dispatch-config.h"
#endif

/**
 * @defgroup scan-dispatch  Scan Dispatch
 * @ingroup component
 * @brief API and Callbacks for the scan-dispatch Component
 *
 * This component allows existence of multiple consumers of the stack 802.15.4
 * scan results.
 *
 */

/** @addtogroup scan-dispatch Scan Dispatch
 *
 * This plugin allows for multiple consumers of stack
 * 802.15.4 scan callbacks.
 *
 * @{
 */

/**
 * @brief The size of the dispatch queue.
 */
#ifndef SL_ZIGBEE_AF_PLUGIN_SCAN_DISPATCH_SCAN_QUEUE_SIZE
  #define SL_ZIGBEE_AF_PLUGIN_SCAN_DISPATCH_SCAN_QUEUE_SIZE 10
#endif

/**
 * @brief The information regarding scan results.
 */
typedef struct {
  /** The status indicating the success or failure of a scan.
   *
   * This member is only valid when
   * ::sl_zigbee_af_scan_dispatch_scan_results_are_complete returns true.
   */
  sl_status_t status;

  /** The RSSI found during a scan.
   *
   * This member is only valid when
   * ::sl_zigbee_af_scan_dispatch_scan_results_are_complete returns false.
   */
  int8_t rssi;

  /** The channel on which the scan is taking place.
   *
   * This member is only valid when the results are for an energy scan or
   * ::sl_zigbee_af_scan_dispatch_scan_results_are_complete returns true and
   * ::sl_zigbee_af_scan_dispatch_scan_results_are_failure returns false. Note
   * that in active scan results, users can find the channel on which the network
   * was found using the network member of this structure.
   */
  uint8_t channel;

  /** The LQI found during the scan.
   *
   * This member is only valid when the result are for an active scan.
   */
  uint8_t lqi;

  /** The Zigbee network found in the scan.
   *
   * This member is only valid when the result are for an active scan.
   */
  sl_zigbee_zigbee_network_t *network;

  /** A mask containing information about the scan. */
  uint16_t mask;
} sl_zigbee_af_plugin_scan_dispatch_scan_results_t;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  #define EM_AF_PLUGIN_SCAN_DISPATCH_SCAN_RESULTS_MASK_SCAN_TYPE (0x00FF)
  #define EM_AF_PLUGIN_SCAN_DISPATCH_SCAN_RESULTS_MASK_COMPLETE  (0x0100)
  #define EM_AF_PLUGIN_SCAN_DISPATCH_SCAN_RESULTS_MASK_FAILURE   (0x0200)
#endif

/**
 * @brief Handle scan results.
 */
typedef void (*sl_zigbee_af_plugin_scan_dispatch_scan_results_handler_t)(sl_zigbee_af_plugin_scan_dispatch_scan_results_t *results);

/**
 * @brief A structure containing data for scheduling a scan.
 */
typedef struct {
  /** The 802.15.4 scan type to be scheduled. */
  sl_zigbee_network_scan_type_t scanType;
  /** The channel mask to be scanned. */
  uint32_t channelMask;
  /** The duration of the scan period, as an exponent. */
  uint8_t duration;
  /** The handler to be called with the scan results. */
  sl_zigbee_af_plugin_scan_dispatch_scan_results_handler_t handler;
} sl_zigbee_af_plugin_scan_dispatch_scan_data_t;

/**
 * @name API
 * @{
 */

/** @brief Get the scan type.
 *
 * Gets the scan type from an ::sl_zigbee_af_plugin_scan_dispatch_scan_results_t.
 * This value will either be ::SL_ZIGBEE_ENERGY_SCAN, ::SL_ZIGBEE_ACTIVE_SCAN
 * or ::SL_ZIGBEE_ACTIVE_SCAN_ROUTER
 *
 * @param results The ::sl_zigbee_af_plugin_scan_dispatch_scan_results_t for which
 * the scan type will be found.
 *
 * @return The ::sl_zigbee_network_scan_type_t of the scan results.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
sl_zigbee_network_scan_type_t
sl_zigbee_af_scan_dispatch_scan_results_get_scan_type(sl_zigbee_af_plugin_scan_dispatch_scan_results_t *results);
#else
  #define sl_zigbee_af_scan_dispatch_scan_results_get_scan_type(results) \
  ((sl_zigbee_network_scan_type_t)((results)->mask                       \
                                   & EM_AF_PLUGIN_SCAN_DISPATCH_SCAN_RESULTS_MASK_SCAN_TYPE))
#endif

/** @brief Get whether the originally requested scan has completed.
 *
 * This can happen either when the dispatcher
 * asks the stack for a scan (see ::sl_zigbee_start_scan) or after all of
 * the scan results have been delivered to the consumer (see
 * ::sl_zigbee_af_scan_complete_cb).
 *
 * @param results The ::sl_zigbee_af_plugin_scan_dispatch_scan_results_t that belong
 * to a potentially complete scan.
 *
 * @return Indicates whether or not the scan for the scan results is complete.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
bool
sl_zigbee_af_scan_dispatch_scan_results_are_complete(sl_zigbee_af_plugin_scan_dispatch_scan_results_t *results);
#else
  #define sl_zigbee_af_scan_dispatch_scan_results_are_complete(results) \
  HIGH_BYTE(((results)->mask                                            \
             & EM_AF_PLUGIN_SCAN_DISPATCH_SCAN_RESULTS_MASK_COMPLETE))
#endif

/** @brief Result in a failure.
 *
 * Gets whether or not the scan results are from a failed call
 * to ::sl_zigbee_start_scan.
 *
 * @param results The ::sl_zigbee_af_plugin_scan_dispatch_scan_results_t for which
 * the call to ::sl_zigbee_start_scan may have failed.
 *
 * @return Indicates whether or not the call to ::sl_zigbee_start_scan failed for these
 * results.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
bool
sl_zigbee_af_scan_dispatch_scan_results_are_failure(sl_zigbee_af_plugin_scan_dispatch_scan_results_t *results);
#else
  #define sl_zigbee_af_scan_dispatch_scan_results_are_failure(results) \
  HIGH_BYTE(((results)->mask                                           \
             & EM_AF_PLUGIN_SCAN_DISPATCH_SCAN_RESULTS_MASK_FAILURE))
#endif

/** @brief Schedule a scan.
 *
 * This API schedules an 802.15.4 scan. The results will be delivered to
 * the consumer via a handler in the passed ::sl_zigbee_af_plugin_scan_dispatch_scan_data_t.
 *
 * @param data An ::sl_zigbee_af_plugin_scan_dispatch_scan_data_t that holds the scanType,
 * channelMask, duration, and ::sl_zigbee_af_plugin_scan_dispatch_scan_results_handler_t for
 * the scan.
 *
 * @return An ::sl_status_t value describing the result of the scheduling of
 * a scan.
 */
sl_status_t sl_zigbee_af_scan_dispatch_schedule_scan(sl_zigbee_af_plugin_scan_dispatch_scan_data_t *data);

/** @brief Remove all consumers in the queue.
 *
 * A call to this function will remove all consumers in the queue for scan
 * results. It will also cancel any 802.15.4 scan that the stack is currently
 * performing.
 */
void sl_zigbee_af_scan_dispatch_clear(void);

/** @} */ // end of name API
/** @} */ // end of scan-dispatch

#endif /* __SCAN_DISPATCH_H__ */
