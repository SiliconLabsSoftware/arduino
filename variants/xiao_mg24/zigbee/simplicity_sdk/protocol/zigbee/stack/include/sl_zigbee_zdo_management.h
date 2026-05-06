/***************************************************************************//**
 * @file  sl_zigbee_zdo_management.h
 * @brief ZDO Management functionality described in R23 including performing
 * beacon surveys of Zigbee network
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

#ifndef SL_ZIGBEE_ZDO_MANAGEMENT_H
#define SL_ZIGBEE_ZDO_MANAGEMENT_H

#include "stack/include/sl_zigbee_types.h"

// a cache to store potential parents
// NOTE this limit is imposed by the ZigBee spec (2.4.4.3.13)
#define BEACON_SURVEY_POTENTIAL_PARENTS_MAX_CANDIDATES 5

typedef struct {
  uint8_t total_beacons;
  uint8_t on_network_beacons;
  uint8_t potential_parent_beacons;
  uint8_t other_network_beacons;
} sl_zigbee_beacon_survey_results_t;

typedef struct {
  sl_802154_short_addr_t short_id;
  // says lqa, really lqi
  uint8_t lqa;
} sl_zigbee_potential_parent_t;

typedef struct {
  sl_802154_short_addr_t requester;
  uint8_t sequence;
  sl_zigbee_beacon_survey_results_t results;
  uint16_t observed_pan_ids[SL_ZIGBEE_ZDO_BEACON_SURVEY_MAX_UNIQUE_NETWORKS];
  sl_zigbee_beacon_data_t potential_parents[BEACON_SURVEY_POTENTIAL_PARENTS_MAX_CANDIDATES];
} sl_zigbee_beacon_survey_data_t;

// channel field determines which channels to scan
#define BEACON_SURVEY_CONFIG_CHANNEL_BITMASK
// there is a 1-byte bitmask with a couple of fields
#define BEACON_SURVEY_CONFIG_BITMASK 0x01
#define BEACON_SURVEY_CONFIG_BITMASK_ENHANCED_SCAN BIT(0)

/**
 * @brief issues a survey beacon request to the given destination
 * @param dest the short id of the node intended to fulfill the request
 * @param channel_mask a mask representing the range of channels that should be scanned
 * @param scan_config_mask is a bitmask that helps configure the scan parameters for the survey
 * @note bit 1 indicates an enhanced scan
 * @return a status code indicating whether or not the request was sent successfully
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# channel_masks | length: channel_page_count | max: 5 #}
 */
sl_status_t sl_zigbee_request_beacon_survey(sl_802154_short_addr_t dest,
                                            uint8_t channel_page_count,
                                            uint32_t *channel_masks,
                                            uint8_t scan_config_mask);

/**
 * @brief application defined procedure called on completion of the ZDO beacon survey
 * @param status the status of handling the beacon survey response
 * @param survey_results the tallied results of the beacon survey
 * @param potential_parent_count the number of candidate parent beacons
 * @param potential_parents the potential_parent data received
 * @param pan_id_conflicts the number of recorded pan id conflicts in range
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# potential_parents | length: potential_parent_count | max: 16 #}
 */
extern void sl_zigbee_beacon_survey_complete_callback(sl_zigbee_zdo_status_t status,
                                                      sl_zigbee_beacon_survey_results_t *survey_results,
                                                      uint8_t potential_parent_count,
                                                      sl_zigbee_potential_parent_t *potential_parents,
                                                      uint16_t pan_id_conflicts);

#endif // SL_ZIGBEE_ZDO_MANAGEMENT_H
