/***************************************************************************//**
 * @file
 * @brief This is the source for the plugin used to add an IAS Zone cluster server
 * to a project. This source handles zone enrollment and storing of
 * attributes from a CIE device and provides an API for different plugins to
 * post updated zone status values.
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

//-----------------------------------------------------------------------------
#ifndef SILABS_IAS_ZONE_SERVER_H
#define SILABS_IAS_ZONE_SERVER_H

/**
 * @defgroup ias-zone-server IAS Zone Server
 * @ingroup component cluster
 * @brief API and Callbacks for the IAS Zone Server Component
 *
 * An IAS Server implementation that reports notifications
 * to the client that has configured it. This requires extending to
 * trigger alarms. The component must store the client IEEE address attribute
 * to flash. This means, for the IAS CIE address attribute (0x0010) of the
 * IAS Zone cluster (0x500), the user must select the check box that
 * stores that attribute to flash.
 *
 */

/**
 * @addtogroup ias-zone-server
 * @{
 */

#define EM_AF_UNKNOWN_ENDPOINT  0
// Absolute max backoff time, at least one retry a day
// (ie. 24 hours * 60 minutes * 60 seconds).
#define IAS_ZONE_STATUS_QUEUE_RETRY_ABS_MAX_BACKOFF_TIME_SEC (24 * 60 * 60)

// Definitions for the IAS Zone enrollment mode.
typedef enum {
  SL_ZIGBEE_ZCL_IAS_ZONE_ENROLLMENT_MODE_TRIP_TO_PAIR = 0x00,
  SL_ZIGBEE_ZCL_IAS_ZONE_ENROLLMENT_MODE_AUTO_ENROLLMENT_RESPONSE = 0x01,
  SL_ZIGBEE_ZCL_IAS_ZONE_ENROLLMENT_MODE_REQUEST = 0x02
} sl_zigbee_af_ias_zone_enrollment_mode_t;

// Status queue retry parameters
typedef struct {
  uint8_t firstBackoffTimeSec;
  uint8_t backoffSeqCommonRatio;
  uint32_t maxBackoffTimeSec;
  bool unlimitedRetries;
  uint8_t maxRetryAttempts;
} sli_zigbee_ias_zone_status_queue_retry_config_t;

/**
 * @name API
 * @{
 */

/** @brief Update the zone status for an endpoint.
 *
 * This function  updates the zone status attribute of the specified endpoint
 * using the specified new zone status. Then, it notifies the CIE of the
 * updated status.
 *
 * @param endpoint The endpoint whose zone status attribute is to be updated.
 * @param newStatus The new status to write to the attribute.
 * @param timeSinceStatusOccurredQs The amount of time (in quarter seconds) that
 *   has passed since the status change occurred.
 *
 * @return SL_STATUS_OK if the attribute update and notify succeeded, error
 * code otherwise.
 */
sl_status_t sl_zigbee_af_ias_zone_server_update_zone_status(
  uint8_t endpoint,
  uint16_t newStatus,
  uint16_t  timeSinceStatusOccurredQs);

/** @brief Get the CIE assigned zone ID of a given endpoint.
 *
 * This function returns the zone ID that was assigned to the given
 * endpoint by the CIE at time of enrollment.
 *
 * @param endpoint The endpoint whose ID is to be queried.
 *
 * @return The zone ID assigned by the CIE at time of enrollment.
 */
uint8_t sl_zigbee_af_ias_zone_server_get_zone_id(uint8_t endpoint);

/** @brief Determine the enrollment status of a given endpoint.
 *
 * This function returns true or false depending on whether the specified
 * endpoint has undergone IAS Zone Enrollment.
 *
 * @param endpoint The endpoint whose enrollment status is to be queried.
 *
 * @return True if enrolled, false otherwise.
 */
bool sl_zigbee_af_ias_zone_cluster_am_i_enrolled(uint8_t endpoint);

/** @brief Set the enrollment status.
 *
 * This function returns the status of the set enrollment method attempt.
 *
 * @param endpoint The endpoint whose enrollment method is to be set
 * @param method The enrollment method that should be set
 *
 * @return An ::sl_zigbee_af_status_t value indicating the status of the set action.
 */
sl_zigbee_af_status_t sl_zigbee_af_ias_zone_cluster_set_enrollment_method(uint8_t endpoint,
                                                                          sl_zigbee_af_ias_zone_enrollment_mode_t method);

/** @brief Configure the retry parameters of the status queue.
 *
 * This function configures the status queue retry parameters.
 *
 * @param retryConfig Status queue retry configuration.
 */
sl_status_t sl_zigbee_af_ias_zone_server_config_status_queue_retry_params(sli_zigbee_ias_zone_status_queue_retry_config_t *retryConfig);

/** @brief Set the retry parameters of the status queue to default.
 *
 * This function sets the status queue retry parameters to their default values.
 */
void sl_zigbee_af_ias_zone_server_set_status_queue_retry_params_to_default(void);

/** @brief Discard any pending events in the status queue and sets it inactive.
 *
 * This function discards any pending event pending in the status queue.
 * Also, the status queue event control manager will be inactivated.
 */
void sl_zigbee_af_ias_zone_server_discard_pending_events_in_status_queue(void);

/** @brief Print information on the status queue.
 */
void sl_zigbee_af_ias_zone_server_print_queue(void);

/** @brief Print the status queue config.
 */
void sl_zigbee_af_ias_zone_server_print_queue_config(void);

/** @} */ // end of name API
/** @} */ // end of ias-zone-server

#endif //__IAS_ZONE_SERVER_H__
