/***************************************************************************//**
 * @file
 * @brief Contains the per-endpoint configuration of attribute tables.
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

#ifndef __AF_ATTRIBUTE_STORAGE__
#define __AF_ATTRIBUTE_STORAGE__

#include PLATFORM_HEADER
#include "../include/af.h"
#if defined(SL_CATALOG_ZIGBEE_ZCL_FRAMEWORK_CORE_PRESENT) || defined(SL_CATALOG_ZIGBEE_GREEN_POWER_ADAPTER_PRESENT)
#include "zap-config.h"
#endif
// If we have fixed number of endpoints, then max is the same.
#ifdef SL_ZIGBEE_SCRIPTED_TEST
#define MAX_ENDPOINT_COUNT 10
#else
#ifdef ZCL_FIXED_ENDPOINT_COUNT
#define MAX_ENDPOINT_COUNT ZCL_FIXED_ENDPOINT_COUNT
#endif
#endif

#define CLUSTER_TICK_FREQ_ALL            (0x00)
#define CLUSTER_TICK_FREQ_QUARTER_SECOND (0x04)
#define CLUSTER_TICK_FREQ_HALF_SECOND    (0x08)
#define CLUSTER_TICK_FREQ_SECOND         (0x0C)

extern uint8_t sl_zigbee_attribute_data[]; // main storage bucket for all attributes

extern uint8_t attributeDefaults[]; // storage bucked for > 2b default values

void sli_zigbee_af_call_inits(void);

#define sl_zigbee_af_cluster_is_client(cluster) ((bool)(((cluster)->mask & CLUSTER_MASK_CLIENT) != 0))
#define sl_zigbee_af_cluster_is_server(cluster) ((bool)(((cluster)->mask & CLUSTER_MASK_SERVER) != 0))
#define sl_zigbee_af_does_cluster_have_init_function(cluster) ((bool)(((cluster)->mask & CLUSTER_MASK_INIT_FUNCTION) != 0))
#define sl_zigbee_af_does_cluster_have_attribute_changed_function(cluster) ((bool)(((cluster)->mask & CLUSTER_MASK_ATTRIBUTE_CHANGED_FUNCTION) != 0))
#define sl_zigbee_af_does_cluster_have_default_response_function(cluster) ((bool)(((cluster)->mask & CLUSTER_MASK_DEFAULT_RESPONSE_FUNCTION) != 0))
#define sl_zigbee_af_does_cluster_have_message_sent_function(cluster) ((bool)(((cluster)->mask & CLUSTER_MASK_MESSAGE_SENT_FUNCTION) != 0))

// Initial configuration
void sl_zigbee_af_endpoint_configure(void);
bool sl_zigbee_af_extract_command_ids(bool outgoing,
                                      sl_zigbee_af_cluster_command_t *cmd,
                                      uint16_t clusterId,
                                      uint8_t *buffer,
                                      uint16_t bufferLength,
                                      uint16_t *bufferIndex,
                                      uint8_t startId,
                                      uint8_t maxIdCount);

sl_zigbee_af_status_t sli_zigbee_af_read_or_write_attribute(sl_zigbee_af_attribute_search_record_t *attRecord,
                                                            sl_zigbee_af_attribute_metadata_t **metadata,
                                                            uint8_t *buffer,
                                                            uint16_t readLength,
                                                            bool write);

bool sli_zigbee_af_match_cluster(sl_zigbee_af_cluster_t *cluster,
                                 sl_zigbee_af_attribute_search_record_t *attRecord);
bool sli_zigbee_af_match_attribute(sl_zigbee_af_cluster_t *cluster,
                                   sl_zigbee_af_attribute_metadata_t *am,
                                   sl_zigbee_af_attribute_search_record_t *attRecord);

sl_zigbee_af_cluster_t *sl_zigbee_af_find_cluster_in_type_with_mfg_code(sl_zigbee_af_endpoint_type_t *endpointType,
                                                                        sl_zigbee_af_cluster_id_t clusterId,
                                                                        sl_zigbee_af_cluster_mask_t mask,
                                                                        uint16_t manufacturerCode);

sl_zigbee_af_cluster_t *sl_zigbee_af_find_cluster_in_type(sl_zigbee_af_endpoint_type_t *endpointType,
                                                          sl_zigbee_af_cluster_id_t clusterId,
                                                          sl_zigbee_af_cluster_mask_t mask);

// This function returns the index of cluster for the particular endpoint.
// Mask is either CLUSTER_MASK_CLIENT or CLUSTER_MASK_SERVER
// For example, if you have 3 endpoints, 10, 11, 12, and cluster X server is
// located on 11 and 12, and cluster Y server is located only on 10 then
//    clusterIndex(X,11,CLUSTER_MASK_SERVER) returns 0,
//    clusterIndex(X,12,CLUSTER_MASK_SERVER) returns 1,
//    clusterIndex(X,10,CLUSTER_MASK_SERVER) returns 0xFF
//    clusterIndex(Y,10,CLUSTER_MASK_SERVER) returns 0
//    clusterIndex(Y,11,CLUSTER_MASK_SERVER) returns 0xFF
//    clusterIndex(Y,12,CLUSTER_MASK_SERVER) returns 0xFF
uint8_t sl_zigbee_af_cluster_index(uint8_t endpoint,
                                   sl_zigbee_af_cluster_id_t clusterId,
                                   sl_zigbee_af_cluster_mask_t mask);

// If server == true, returns the number of server clusters,
// otherwise number of client clusters on this endpoint
uint8_t sl_zigbee_af_cluster_count(uint8_t endpoint, bool server);

// Returns the clusterId of Nth server or client cluster,
// depending on server toggle.
sl_zigbee_af_cluster_t *sl_zigbee_af_get_nth_cluster(uint8_t endpoint, uint8_t n, bool server);

// Returns number of clusters put into the passed cluster list
// for the given endpoint and client/server polarity
uint8_t sl_zigbee_af_get_clusters_from_endpoint(uint8_t endpoint, sl_zigbee_af_cluster_id_t *clusterList, uint8_t listLen, bool server);

// Returns cluster within the endpoint, or NULL if it isn't there
sl_zigbee_af_cluster_t *sl_zigbee_af_find_cluster_with_mfg_code(uint8_t endpoint, sl_zigbee_af_cluster_id_t clusterId, sl_zigbee_af_cluster_mask_t mask, uint16_t manufacturerCode);

// Returns cluster within the endpoint, or NULL if it isn't there
// This wraps sl_zigbee_af_find_cluster_with_mfg_code with SL_ZIGBEE_AF_NULL_MANUFACTURER_CODE
sl_zigbee_af_cluster_t *sl_zigbee_af_find_cluster(uint8_t endpoint, sl_zigbee_af_cluster_id_t clusterId, sl_zigbee_af_cluster_mask_t mask);

// Returns cluster within the endpoint; Does not ignore disabled endpoints
sl_zigbee_af_cluster_t *sl_zigbee_af_find_cluster_including_disabled_endpoints_with_mfg_code(uint8_t endpoint,
                                                                                             sl_zigbee_af_cluster_id_t clusterId,
                                                                                             sl_zigbee_af_cluster_mask_t mask,
                                                                                             uint16_t manufacturerCode);

// Returns cluster within the endpoint; Does not ignore disabled endpoints
// This wraps sl_zigbee_af_find_cluster_including_disabled_endpoints_with_mfg_code with SL_ZIGBEE_AF_NULL_MANUFACTURER_CODE
sl_zigbee_af_cluster_t *sl_zigbee_af_find_cluster_including_disabled_endpoints(uint8_t endpoint,
                                                                               sl_zigbee_af_cluster_id_t clusterId,
                                                                               sl_zigbee_af_cluster_mask_t mask);

// Function mask must contain one of the CLUSTER_MASK function macros,
// then this method either returns the function pointer or null if
// function doesn't exist. Before you call the function, you must
// cast it.
sl_zigbee_af_generic_cluster_function_t sl_zigbee_af_find_cluster_function(sl_zigbee_af_cluster_t *cluster, sl_zigbee_af_cluster_mask_t functionMask);

// Public APIs for loading attributes
void sl_zigbee_af_initialize_attributes(uint8_t endpoint);
void sl_zigbee_af_reset_attributes(uint8_t endpoint);

// Loads the attributes from built-in default and / or tokens
void sli_zigbee_af_load_attribute_defaults(uint8_t endpoint, bool writeTokens);

// This function loads from tokens all the attributes that
// are defined to be stored in tokens.
void sli_zigbee_af_load_attributes_from_tokens(uint8_t endpoint);

// This function is called to update attributes in NVM after the RAM
// counterpart has been written. This function updates NVM immediately,
// as opposed to defer_attribute_write_to_token, which updates NVM after a delay.
// If the attribute is not stored in NVM, then this function does nothing
void sli_zigbee_af_save_attribute_to_token(uint8_t *data,
                                           uint8_t endpoint,
                                           sl_zigbee_af_cluster_id_t clusterId,
                                           sl_zigbee_af_attribute_metadata_t *metadata);

// This function is called to update attributes in NVM after the RAM
// counterpart has been written. This function updates NVM after a delay,
// as opposed to sli_zigbee_af_save_attribute_to_token, which updates NVM immediately.
// If the attribute is changed before the deferred write has occurred, then the
// deferral will be delayed again by the original delay amount.
// If the attribute is not stored in NVM, then this function does nothing
void defer_attribute_write_to_token(uint8_t *data,
                                    uint8_t endpoint,
                                    sl_zigbee_af_cluster_id_t clusterId,
                                    sl_zigbee_af_attribute_metadata_t *metadata,
                                    sl_zigbee_af_cluster_mask_t clusterMask,
                                    uint16_t manufacturerCode);

void sli_zigbee_af_init_attribute_storage(void);

// Calls the attribute changed callback
void sli_zigbee_af_cluster_attribute_changed_callback(uint8_t endpoint,
                                                      sl_zigbee_af_cluster_id_t clusterId,
                                                      sl_zigbee_af_attribute_id_t attributeId,
                                                      uint8_t clientServerMask,
                                                      uint16_t manufacturerCode);

// Calls the attribute changed callback for a specific cluster.
sl_zigbee_af_status_t sli_zigbee_af_cluster_pre_attribute_changed_callback(uint8_t endpoint,
                                                                           sl_zigbee_af_cluster_id_t clusterId,
                                                                           sl_zigbee_af_attribute_id_t attributeId,
                                                                           uint8_t clientServerMask,
                                                                           uint16_t manufacturerCode,
                                                                           sl_zigbee_af_attribute_type_t attributeType,
                                                                           uint8_t size,
                                                                           uint8_t* value);

// Calls the default response callback for a specific cluster, and wraps sl_zigbee_af_cluster_default_response_with_mfg_code_cb
// with the SL_ZIGBEE_NULL_MANUFACTURER_CODE
void sl_zigbee_af_cluster_default_response_cb(uint8_t endpoint,
                                              sl_zigbee_af_cluster_id_t clusterId,
                                              uint8_t commandId,
                                              sl_zigbee_af_status_t status,
                                              uint8_t clientServerMask);

// Calls the default response callback for a specific cluster.
void sl_zigbee_af_cluster_default_response_with_mfg_code_cb(uint8_t endpoint,
                                                            sl_zigbee_af_cluster_id_t clusterId,
                                                            uint8_t commandId,
                                                            sl_zigbee_af_status_t status,
                                                            uint8_t clientServerMask,
                                                            uint16_t manufacturerCode);

// Calls the message sent callback for a specific cluster, and wraps sl_zigbee_af_cluster_message_sent_with_mfg_code_cb
void sl_zigbee_af_cluster_message_sent_cb(sl_zigbee_outgoing_message_type_t type,
                                          uint16_t indexOrDestination,
                                          sl_zigbee_aps_frame_t *apsFrame,
                                          uint16_t msgLen,
                                          uint8_t *message,
                                          sl_status_t status);

// Calls the message sent callback for a specific cluster.
void sl_zigbee_af_cluster_message_sent_with_mfg_code_cb(sl_zigbee_outgoing_message_type_t type,
                                                        uint16_t indexOrDestination,
                                                        sl_zigbee_aps_frame_t *apsFrame,
                                                        uint16_t msgLen,
                                                        uint8_t *message,
                                                        sl_status_t status,
                                                        uint16_t manufacturerCode);

// Used to retrieve a manufacturer code from an attribute metadata
uint16_t sli_zigbee_af_get_manufacturer_code_for_cluster(sl_zigbee_af_cluster_t *cluster);
uint16_t sli_zigbee_af_get_manufacturer_code_for_attribute(sl_zigbee_af_cluster_t *cluster,
                                                           sl_zigbee_af_attribute_metadata_t *attMetaData);

// Checks a cluster mask byte against ticks passed bitmask
// returns true if the mask matches a passed interval
bool sl_zigbee_af_check_tick(sl_zigbee_af_cluster_mask_t mask,
                             uint8_t passedMask);

bool sl_zigbee_af_endpoint_is_enabled(uint8_t endpoint);

// Note the difference in implementation from sl_zigbee_af_get_nth_cluster().
// sl_zigbee_af_get_cluster_by_index() retrieves the cluster by index regardless of server/client
// and those indexes may be DIFFERENT than the indexes returned from
// sl_zigbee_af_get_nth_cluster().  In other words:
//
//  - Use sl_zigbee_af_get_clusters_from_endpoint()  with sl_zigbee_af_get_nth_cluster()
//  - Use sl_zigbee_af_get_cluster_count_for_endpoint() with sl_zigbee_af_get_cluster_by_index()
//
// Don't mix them.
uint8_t sl_zigbee_af_get_cluster_count_for_endpoint(uint8_t endpoint);
sl_zigbee_af_cluster_t* sl_zigbee_af_get_cluster_by_index(uint8_t endpoint, uint8_t clusterIndex);

sl_zigbee_af_profile_id_t sl_zigbee_af_get_profile_id_for_endpoint(uint8_t endpoint);
uint16_t sl_zigbee_af_get_device_id_for_endpoint(uint8_t endpoint);

// Resolve mfg code for command discovery with mfg code wildcard
uint16_t sli_zigbee_af_resolve_mfg_code_for_discover_command(bool outgoing,
                                                             sl_zigbee_af_cluster_command_t *cmd,
                                                             uint16_t clusterId,
                                                             uint8_t startId);

#endif // __AF_ATTRIBUTE_STORAGE__
