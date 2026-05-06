/***************************************************************************//**
 * @file
 * @brief Interface for initiating and processing ZDO service discovery
 * (match descriptor) requests and response.
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

#ifndef SILABS_SERVICE_DISCOVERY_H
#define SILABS_SERVICE_DISCOVERY_H

#include "../include/af.h"
#define SL_ZIGBEE_SUPPORTED_SERVICE_DISCOVERY_STATES_PER_NETWORK 4u
// Internal Functions
void sli_zigbee_af_service_discovery_matched(sl_802154_short_addr_t nodeId,
                                             uint8_t endpointListLength,
                                             uint8_t* endpointList);

// Platform specific call to send a match descriptor request.
sl_status_t sli_zigbee_af_send_match_descriptor(sl_802154_short_addr_t target,
                                                sl_zigbee_af_profile_id_t profileId,
                                                sl_zigbee_af_cluster_id_t clusterId,
                                                bool serverCluster);

bool sli_zigbee_af_service_discovery_incoming(sl_802154_short_addr_t sender,
                                              sl_zigbee_aps_frame_t* apsFrame,
                                              const uint8_t* message,
                                              uint16_t length);

void sli_zigbee_af_service_discovery_complete(uint8_t networkIndex, uint8_t sequenceNumber);

#ifndef SL_ZIGBEE_AF_DISCOVERY_TIMEOUT_QS
// NOTE 2.25 seconds
  #define SL_ZIGBEE_AF_DISCOVERY_TIMEOUT_QS (2u * 4u + 1u)
#endif

extern sl_zigbee_af_event_t sli_zigbee_af_service_discovery_events[SL_ZIGBEE_SUPPORTED_SERVICE_DISCOVERY_STATES_PER_NETWORK][SL_ZIGBEE_SUPPORTED_NETWORKS];
void sli_zigbee_af_service_discovery_timeout_handler(sl_zigbee_af_event_t *event);

#endif // SILABS_SERVICE_DISCOVERY_H
