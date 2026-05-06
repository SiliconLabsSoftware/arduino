/*******************************************************************************
 * @file zigbee_af_cluster_functions.h
 * @brief Cluster action callback definitions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
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
//
// *** Generated file. Do not edit! ***
//

#include "af.h"


void sl_zigbee_af_groups_cluster_server_init_cb (uint8_t endpoint);
void sl_zigbee_af_identify_cluster_server_init_cb (uint8_t endpoint);
void sl_zigbee_af_identify_cluster_server_attribute_changed_cb (uint8_t endpoint, sl_zigbee_af_attribute_id_t attributeId);
void sl_zigbee_af_on_off_cluster_server_init_cb (uint8_t endpoint);
void sl_zigbee_af_scenes_cluster_server_in (uint8_t endpoint);

// Array of cluster function (aka cluster action callbacks) structures.
// Last entry is a dummy, otherwise an empty array would fail IAR builds.
#define GENERATED_FUNCTION_STRUCTURES_ARRAY  { \
  {\
    4u,\
    (CLUSTER_MASK_SERVER | CLUSTER_MASK_INIT_FUNCTION),\
    (sl_zigbee_af_generic_cluster_function_t)sl_zigbee_af_groups_cluster_server_init_cb\
  },\
  {\
    3u,\
    (CLUSTER_MASK_SERVER | CLUSTER_MASK_INIT_FUNCTION),\
    (sl_zigbee_af_generic_cluster_function_t)sl_zigbee_af_identify_cluster_server_init_cb\
  },\
  {\
    3u,\
    (CLUSTER_MASK_SERVER | CLUSTER_MASK_ATTRIBUTE_CHANGED_FUNCTION),\
    (sl_zigbee_af_generic_cluster_function_t)sl_zigbee_af_identify_cluster_server_attribute_changed_cb\
  },\
  {\
    6u,\
    (CLUSTER_MASK_SERVER | CLUSTER_MASK_INIT_FUNCTION),\
    (sl_zigbee_af_generic_cluster_function_t)sl_zigbee_af_on_off_cluster_server_init_cb\
  },\
  {\
    5u,\
    (CLUSTER_MASK_SERVER | CLUSTER_MASK_INIT_FUNCTION),\
    (sl_zigbee_af_generic_cluster_function_t)sl_zigbee_af_scenes_cluster_server_in\
  },\
  { 0x8000u,\
    0x00u,\
    (sl_zigbee_af_generic_cluster_function_t)((void *)0)\
  }\
}


// The following structure is not used anywhere in the code, its purpose is 
// compile-time detection of duplicate cluster action callbacks.
// Only a single instance of a given callback type (e.g. default_response_function)
// can exist for a given cluster and side (client/server).
// A compilation error in this structure indicates a duplicate "cluster_functions"
// template contribution.

struct unused_structure {
int clust_4_server_init_function; 
int clust_3_server_init_function; 
int clust_3_server_attribute_changed_function; 
int clust_6_server_init_function; 
int clust_5_server_init_function; 
};

