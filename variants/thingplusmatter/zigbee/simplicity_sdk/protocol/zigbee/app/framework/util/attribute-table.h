/***************************************************************************//**
 * @file
 * @brief This file contains the definitions for the attribute table, its
 * sizes, count, and API.
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

#ifndef ZCL_UTIL_ATTRIBUTE_TABLE_H
#define ZCL_UTIL_ATTRIBUTE_TABLE_H

#include "../include/af.h"

#define ZCL_NULL_ATTRIBUTE_TABLE_INDEX 0xFFFF

// Remote devices writing attributes of local device
sl_zigbee_af_status_t sl_zigbee_af_write_attribute_external(uint8_t endpoint,
                                                            sl_zigbee_af_cluster_id_t cluster,
                                                            sl_zigbee_af_attribute_id_t attributeID,
                                                            uint8_t mask,
                                                            uint16_t manufacturerCode,
                                                            uint8_t* dataPtr,
                                                            sl_zigbee_af_attribute_type_t dataType);

sl_zigbee_af_status_t sl_zigbee_af_retrieve_attribute_and_craft_response(uint8_t endpoint,
                                                                         sl_zigbee_af_cluster_id_t clusterId,
                                                                         sl_zigbee_af_attribute_id_t attrId,
                                                                         uint8_t mask,
                                                                         uint16_t manufacturerCode,
                                                                         uint16_t readLength);
sl_zigbee_af_status_t sl_zigbee_af_append_attribute_report_fields(uint8_t endpoint,
                                                                  sl_zigbee_af_cluster_id_t clusterId,
                                                                  sl_zigbee_af_attribute_id_t attributeId,
                                                                  uint8_t mask,
                                                                  uint8_t *buffer,
                                                                  uint8_t bufLen,
                                                                  uint8_t *bufIndex);
void sl_zigbee_af_print_attribute_table(void);

bool sl_zigbee_af_read_sequential_attributes_add_to_response(uint8_t endpoint,
                                                             sl_zigbee_af_cluster_id_t clusterId,
                                                             sl_zigbee_af_attribute_id_t startAttributeId,
                                                             uint8_t mask,
                                                             uint16_t manufacturerCode,
                                                             uint8_t maxAttributeIds,
                                                             bool includeAccessControl);

sl_zigbee_af_status_t sli_zigbee_af_write_attribute(uint8_t endpoint,
                                                    sl_zigbee_af_cluster_id_t cluster,
                                                    sl_zigbee_af_attribute_id_t attributeID,
                                                    uint8_t mask,
                                                    uint16_t manufacturerCode,
                                                    uint8_t* data,
                                                    sl_zigbee_af_attribute_type_t dataType,
                                                    bool overrideReadOnlyAndDataType,
                                                    bool justTest,
                                                    bool updateNvm);

sl_zigbee_af_status_t sli_zigbee_af_read_attribute(uint8_t endpoint,
                                                   sl_zigbee_af_cluster_id_t cluster,
                                                   sl_zigbee_af_attribute_id_t attributeID,
                                                   uint8_t mask,
                                                   uint16_t manufacturerCode,
                                                   uint8_t* dataPtr,
                                                   uint16_t readLength,
                                                   sl_zigbee_af_attribute_type_t* dataType);

uint16_t sli_zigbee_af_resolve_mfg_code_for_discover_attribute(uint8_t endpoint,
                                                               sl_zigbee_af_cluster_id_t clusterId,
                                                               sl_zigbee_af_attribute_id_t startAttributeId,
                                                               uint8_t clientServerMask);
#endif // ZCL_UTIL_ATTRIBUTE_TABLE_H
