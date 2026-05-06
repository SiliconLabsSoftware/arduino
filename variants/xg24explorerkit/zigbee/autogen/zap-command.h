/***************************************************************************//**
 * @file  zap-command.h
 * @brief This file contains the generated client API
 * This file is generated. Do not update file manually.
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

// Enclosing macro to prevent multiple inclusion
#ifndef SILABS_CLUSTER_CLIENT_API
#define SILABS_CLUSTER_CLIENT_API

// This is generated client API

#include "app/framework/include/af.h"
#include "zap-id.h"

/**
* @addtogroup command Application Framework command interface Reference
* This document describes the ZCL command interface used by the Silabs
* Application Framework for filling ZCL command buffers.
* @{
*/

// Global, non-cluster-specific Commands

/** @brief Command description for ReadAttributes
*
* Command: ReadAttributes
* @param clusterId sl_zigbee_af_cluster_id_t
* @param attributeIds uint8_t *
* @param attributeIdsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_read_attributes(clusterId, \
  attributeIds, attributeIdsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_READ_ATTRIBUTES_COMMAND_ID, \
                           "b", \
							  attributeIds, attributeIdsLen);

/** @brief Command description for ReadAttributes
*
* Command: ReadAttributes
* @param clusterId sl_zigbee_af_cluster_id_t
* @param attributeIds uint8_t *
* @param attributeIdsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_read_attributes(clusterId, \
  attributeIds, attributeIdsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_READ_ATTRIBUTES_COMMAND_ID, \
                           "b", \
							  attributeIds, attributeIdsLen);
/** @brief Command description for ReadAttributesResponse
*
* Command: ReadAttributesResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param readAttributeStatusRecords uint8_t *
* @param readAttributeStatusRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_read_attributes_response(clusterId, \
  readAttributeStatusRecords, readAttributeStatusRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_READ_ATTRIBUTES_RESPONSE_COMMAND_ID, \
                           "b", \
							  readAttributeStatusRecords, readAttributeStatusRecordsLen);

/** @brief Command description for ReadAttributesResponse
*
* Command: ReadAttributesResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param readAttributeStatusRecords uint8_t *
* @param readAttributeStatusRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_read_attributes_response(clusterId, \
  readAttributeStatusRecords, readAttributeStatusRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_READ_ATTRIBUTES_RESPONSE_COMMAND_ID, \
                           "b", \
							  readAttributeStatusRecords, readAttributeStatusRecordsLen);
/** @brief Command description for WriteAttributes
*
* Command: WriteAttributes
* @param clusterId sl_zigbee_af_cluster_id_t
* @param writeAttributeRecords uint8_t *
* @param writeAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_write_attributes(clusterId, \
  writeAttributeRecords, writeAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_WRITE_ATTRIBUTES_COMMAND_ID, \
                           "b", \
							  writeAttributeRecords, writeAttributeRecordsLen);

/** @brief Command description for WriteAttributes
*
* Command: WriteAttributes
* @param clusterId sl_zigbee_af_cluster_id_t
* @param writeAttributeRecords uint8_t *
* @param writeAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_write_attributes(clusterId, \
  writeAttributeRecords, writeAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_WRITE_ATTRIBUTES_COMMAND_ID, \
                           "b", \
							  writeAttributeRecords, writeAttributeRecordsLen);
/** @brief Command description for WriteAttributesUndivided
*
* Command: WriteAttributesUndivided
* @param clusterId sl_zigbee_af_cluster_id_t
* @param writeAttributeRecords uint8_t *
* @param writeAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_write_attributes_undivided(clusterId, \
  writeAttributeRecords, writeAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_WRITE_ATTRIBUTES_UNDIVIDED_COMMAND_ID, \
                           "b", \
							  writeAttributeRecords, writeAttributeRecordsLen);

/** @brief Command description for WriteAttributesUndivided
*
* Command: WriteAttributesUndivided
* @param clusterId sl_zigbee_af_cluster_id_t
* @param writeAttributeRecords uint8_t *
* @param writeAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_write_attributes_undivided(clusterId, \
  writeAttributeRecords, writeAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_WRITE_ATTRIBUTES_UNDIVIDED_COMMAND_ID, \
                           "b", \
							  writeAttributeRecords, writeAttributeRecordsLen);
/** @brief Command description for WriteAttributesResponse
*
* Command: WriteAttributesResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param writeAttributeStatusRecords uint8_t *
* @param writeAttributeStatusRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_write_attributes_response(clusterId, \
  writeAttributeStatusRecords, writeAttributeStatusRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_WRITE_ATTRIBUTES_RESPONSE_COMMAND_ID, \
                           "b", \
							  writeAttributeStatusRecords, writeAttributeStatusRecordsLen);

/** @brief Command description for WriteAttributesResponse
*
* Command: WriteAttributesResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param writeAttributeStatusRecords uint8_t *
* @param writeAttributeStatusRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_write_attributes_response(clusterId, \
  writeAttributeStatusRecords, writeAttributeStatusRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_WRITE_ATTRIBUTES_RESPONSE_COMMAND_ID, \
                           "b", \
							  writeAttributeStatusRecords, writeAttributeStatusRecordsLen);
/** @brief Command description for WriteAttributesNoResponse
*
* Command: WriteAttributesNoResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param writeAttributeRecords uint8_t *
* @param writeAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_write_attributes_no_response(clusterId, \
  writeAttributeRecords, writeAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_WRITE_ATTRIBUTES_NO_RESPONSE_COMMAND_ID, \
                           "b", \
							  writeAttributeRecords, writeAttributeRecordsLen);

/** @brief Command description for WriteAttributesNoResponse
*
* Command: WriteAttributesNoResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param writeAttributeRecords uint8_t *
* @param writeAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_write_attributes_no_response(clusterId, \
  writeAttributeRecords, writeAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_WRITE_ATTRIBUTES_NO_RESPONSE_COMMAND_ID, \
                           "b", \
							  writeAttributeRecords, writeAttributeRecordsLen);
/** @brief Command description for ConfigureReporting
*
* Command: ConfigureReporting
* @param clusterId sl_zigbee_af_cluster_id_t
* @param configureReportingRecords uint8_t *
* @param configureReportingRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_configure_reporting(clusterId, \
  configureReportingRecords, configureReportingRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_CONFIGURE_REPORTING_COMMAND_ID, \
                           "b", \
							  configureReportingRecords, configureReportingRecordsLen);

/** @brief Command description for ConfigureReporting
*
* Command: ConfigureReporting
* @param clusterId sl_zigbee_af_cluster_id_t
* @param configureReportingRecords uint8_t *
* @param configureReportingRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_configure_reporting(clusterId, \
  configureReportingRecords, configureReportingRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_CONFIGURE_REPORTING_COMMAND_ID, \
                           "b", \
							  configureReportingRecords, configureReportingRecordsLen);
/** @brief Command description for ConfigureReportingResponse
*
* Command: ConfigureReportingResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param configureReportingStatusRecords uint8_t *
* @param configureReportingStatusRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_configure_reporting_response(clusterId, \
  configureReportingStatusRecords, configureReportingStatusRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_CONFIGURE_REPORTING_RESPONSE_COMMAND_ID, \
                           "b", \
							  configureReportingStatusRecords, configureReportingStatusRecordsLen);

/** @brief Command description for ConfigureReportingResponse
*
* Command: ConfigureReportingResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param configureReportingStatusRecords uint8_t *
* @param configureReportingStatusRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_configure_reporting_response(clusterId, \
  configureReportingStatusRecords, configureReportingStatusRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_CONFIGURE_REPORTING_RESPONSE_COMMAND_ID, \
                           "b", \
							  configureReportingStatusRecords, configureReportingStatusRecordsLen);
/** @brief Command description for ReadReportingConfiguration
*
* Command: ReadReportingConfiguration
* @param clusterId sl_zigbee_af_cluster_id_t
* @param readReportingConfigurationAttributeRecords uint8_t *
* @param readReportingConfigurationAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_read_reporting_configuration(clusterId, \
  readReportingConfigurationAttributeRecords, readReportingConfigurationAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_READ_REPORTING_CONFIGURATION_COMMAND_ID, \
                           "b", \
							  readReportingConfigurationAttributeRecords, readReportingConfigurationAttributeRecordsLen);

/** @brief Command description for ReadReportingConfiguration
*
* Command: ReadReportingConfiguration
* @param clusterId sl_zigbee_af_cluster_id_t
* @param readReportingConfigurationAttributeRecords uint8_t *
* @param readReportingConfigurationAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_read_reporting_configuration(clusterId, \
  readReportingConfigurationAttributeRecords, readReportingConfigurationAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_READ_REPORTING_CONFIGURATION_COMMAND_ID, \
                           "b", \
							  readReportingConfigurationAttributeRecords, readReportingConfigurationAttributeRecordsLen);
/** @brief Command description for ReadReportingConfigurationResponse
*
* Command: ReadReportingConfigurationResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param readReportingConfigurationRecords uint8_t *
* @param readReportingConfigurationRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_read_reporting_configuration_response(clusterId, \
  readReportingConfigurationRecords, readReportingConfigurationRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_READ_REPORTING_CONFIGURATION_RESPONSE_COMMAND_ID, \
                           "b", \
							  readReportingConfigurationRecords, readReportingConfigurationRecordsLen);

/** @brief Command description for ReadReportingConfigurationResponse
*
* Command: ReadReportingConfigurationResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param readReportingConfigurationRecords uint8_t *
* @param readReportingConfigurationRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_read_reporting_configuration_response(clusterId, \
  readReportingConfigurationRecords, readReportingConfigurationRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_READ_REPORTING_CONFIGURATION_RESPONSE_COMMAND_ID, \
                           "b", \
							  readReportingConfigurationRecords, readReportingConfigurationRecordsLen);
/** @brief Command description for ReportAttributes
*
* Command: ReportAttributes
* @param clusterId sl_zigbee_af_cluster_id_t
* @param reportAttributeRecords uint8_t *
* @param reportAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_report_attributes(clusterId, \
  reportAttributeRecords, reportAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_REPORT_ATTRIBUTES_COMMAND_ID, \
                           "b", \
							  reportAttributeRecords, reportAttributeRecordsLen);

/** @brief Command description for ReportAttributes
*
* Command: ReportAttributes
* @param clusterId sl_zigbee_af_cluster_id_t
* @param reportAttributeRecords uint8_t *
* @param reportAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_report_attributes(clusterId, \
  reportAttributeRecords, reportAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_REPORT_ATTRIBUTES_COMMAND_ID, \
                           "b", \
							  reportAttributeRecords, reportAttributeRecordsLen);
/** @brief Command description for DefaultResponse
*
* Command: DefaultResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param commandId uint8_t

* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_global_server_to_client_default_response(clusterId, \
  commandId,  status) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_DEFAULT_RESPONSE_COMMAND_ID, \
                           "uu", \
							  commandId,							  status);

/** @brief Command description for DefaultResponse
*
* Command: DefaultResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param commandId uint8_t

* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_global_client_to_server_default_response(clusterId, \
  commandId,  status) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_DEFAULT_RESPONSE_COMMAND_ID, \
                           "uu", \
							  commandId,							  status);
/** @brief Command description for DiscoverAttributes
*
* Command: DiscoverAttributes
* @param clusterId sl_zigbee_af_cluster_id_t
* @param startId uint16_t

* @param maxAttributeIds uint8_t

*/
#define sl_zigbee_af_fill_command_global_server_to_client_discover_attributes(clusterId, \
  startId,  maxAttributeIds) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_DISCOVER_ATTRIBUTES_COMMAND_ID, \
                           "vu", \
							  startId,							  maxAttributeIds);

/** @brief Command description for DiscoverAttributes
*
* Command: DiscoverAttributes
* @param clusterId sl_zigbee_af_cluster_id_t
* @param startId uint16_t

* @param maxAttributeIds uint8_t

*/
#define sl_zigbee_af_fill_command_global_client_to_server_discover_attributes(clusterId, \
  startId,  maxAttributeIds) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_DISCOVER_ATTRIBUTES_COMMAND_ID, \
                           "vu", \
							  startId,							  maxAttributeIds);
/** @brief Command description for DiscoverAttributesResponse
*
* Command: DiscoverAttributesResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param discoveryComplete uint8_t

* @param discoverAttributesInfoRecords uint8_t *
* @param discoverAttributesInfoRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_discover_attributes_response(clusterId, \
  discoveryComplete,  discoverAttributesInfoRecords, discoverAttributesInfoRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_DISCOVER_ATTRIBUTES_RESPONSE_COMMAND_ID, \
                           "ub", \
							  discoveryComplete,							  discoverAttributesInfoRecords, discoverAttributesInfoRecordsLen);

/** @brief Command description for DiscoverAttributesResponse
*
* Command: DiscoverAttributesResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param discoveryComplete uint8_t

* @param discoverAttributesInfoRecords uint8_t *
* @param discoverAttributesInfoRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_discover_attributes_response(clusterId, \
  discoveryComplete,  discoverAttributesInfoRecords, discoverAttributesInfoRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_DISCOVER_ATTRIBUTES_RESPONSE_COMMAND_ID, \
                           "ub", \
							  discoveryComplete,							  discoverAttributesInfoRecords, discoverAttributesInfoRecordsLen);
/** @brief Command description for ReadAttributesStructured
*
* Command: ReadAttributesStructured
* @param clusterId sl_zigbee_af_cluster_id_t
* @param readStructuredAttributeRecords uint8_t *
* @param readStructuredAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_read_attributes_structured(clusterId, \
  readStructuredAttributeRecords, readStructuredAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_READ_ATTRIBUTES_STRUCTURED_COMMAND_ID, \
                           "b", \
							  readStructuredAttributeRecords, readStructuredAttributeRecordsLen);

/** @brief Command description for ReadAttributesStructured
*
* Command: ReadAttributesStructured
* @param clusterId sl_zigbee_af_cluster_id_t
* @param readStructuredAttributeRecords uint8_t *
* @param readStructuredAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_read_attributes_structured(clusterId, \
  readStructuredAttributeRecords, readStructuredAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_READ_ATTRIBUTES_STRUCTURED_COMMAND_ID, \
                           "b", \
							  readStructuredAttributeRecords, readStructuredAttributeRecordsLen);
/** @brief Command description for WriteAttributesStructured
*
* Command: WriteAttributesStructured
* @param clusterId sl_zigbee_af_cluster_id_t
* @param writeStructuredAttributeRecords uint8_t *
* @param writeStructuredAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_write_attributes_structured(clusterId, \
  writeStructuredAttributeRecords, writeStructuredAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_WRITE_ATTRIBUTES_STRUCTURED_COMMAND_ID, \
                           "b", \
							  writeStructuredAttributeRecords, writeStructuredAttributeRecordsLen);

/** @brief Command description for WriteAttributesStructured
*
* Command: WriteAttributesStructured
* @param clusterId sl_zigbee_af_cluster_id_t
* @param writeStructuredAttributeRecords uint8_t *
* @param writeStructuredAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_write_attributes_structured(clusterId, \
  writeStructuredAttributeRecords, writeStructuredAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_WRITE_ATTRIBUTES_STRUCTURED_COMMAND_ID, \
                           "b", \
							  writeStructuredAttributeRecords, writeStructuredAttributeRecordsLen);
/** @brief Command description for WriteAttributesStructuredResponse
*
* Command: WriteAttributesStructuredResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param writeStructuredAttributeStatusRecords uint8_t *
* @param writeStructuredAttributeStatusRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_write_attributes_structured_response(clusterId, \
  writeStructuredAttributeStatusRecords, writeStructuredAttributeStatusRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_WRITE_ATTRIBUTES_STRUCTURED_RESPONSE_COMMAND_ID, \
                           "b", \
							  writeStructuredAttributeStatusRecords, writeStructuredAttributeStatusRecordsLen);

/** @brief Command description for WriteAttributesStructuredResponse
*
* Command: WriteAttributesStructuredResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param writeStructuredAttributeStatusRecords uint8_t *
* @param writeStructuredAttributeStatusRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_write_attributes_structured_response(clusterId, \
  writeStructuredAttributeStatusRecords, writeStructuredAttributeStatusRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_WRITE_ATTRIBUTES_STRUCTURED_RESPONSE_COMMAND_ID, \
                           "b", \
							  writeStructuredAttributeStatusRecords, writeStructuredAttributeStatusRecordsLen);
/** @brief Command description for DiscoverCommandsReceived
*
* Command: DiscoverCommandsReceived
* @param clusterId sl_zigbee_af_cluster_id_t
* @param startCommandId uint8_t

* @param maxCommandIds uint8_t

*/
#define sl_zigbee_af_fill_command_global_server_to_client_discover_commands_received(clusterId, \
  startCommandId,  maxCommandIds) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_DISCOVER_COMMANDS_RECEIVED_COMMAND_ID, \
                           "uu", \
							  startCommandId,							  maxCommandIds);

/** @brief Command description for DiscoverCommandsReceived
*
* Command: DiscoverCommandsReceived
* @param clusterId sl_zigbee_af_cluster_id_t
* @param startCommandId uint8_t

* @param maxCommandIds uint8_t

*/
#define sl_zigbee_af_fill_command_global_client_to_server_discover_commands_received(clusterId, \
  startCommandId,  maxCommandIds) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_DISCOVER_COMMANDS_RECEIVED_COMMAND_ID, \
                           "uu", \
							  startCommandId,							  maxCommandIds);
/** @brief Command description for DiscoverCommandsReceivedResponse
*
* Command: DiscoverCommandsReceivedResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param discoveryComplete uint8_t

* @param commandIds uint8_t *
* @param commandIdsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_discover_commands_received_response(clusterId, \
  discoveryComplete,  commandIds, commandIdsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_DISCOVER_COMMANDS_RECEIVED_RESPONSE_COMMAND_ID, \
                           "ub", \
							  discoveryComplete,							  commandIds, commandIdsLen);

/** @brief Command description for DiscoverCommandsReceivedResponse
*
* Command: DiscoverCommandsReceivedResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param discoveryComplete uint8_t

* @param commandIds uint8_t *
* @param commandIdsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_discover_commands_received_response(clusterId, \
  discoveryComplete,  commandIds, commandIdsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_DISCOVER_COMMANDS_RECEIVED_RESPONSE_COMMAND_ID, \
                           "ub", \
							  discoveryComplete,							  commandIds, commandIdsLen);
/** @brief Command description for DiscoverCommandsGenerated
*
* Command: DiscoverCommandsGenerated
* @param clusterId sl_zigbee_af_cluster_id_t
* @param startCommandId uint8_t

* @param maxCommandIds uint8_t

*/
#define sl_zigbee_af_fill_command_global_server_to_client_discover_commands_generated(clusterId, \
  startCommandId,  maxCommandIds) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_DISCOVER_COMMANDS_GENERATED_COMMAND_ID, \
                           "uu", \
							  startCommandId,							  maxCommandIds);

/** @brief Command description for DiscoverCommandsGenerated
*
* Command: DiscoverCommandsGenerated
* @param clusterId sl_zigbee_af_cluster_id_t
* @param startCommandId uint8_t

* @param maxCommandIds uint8_t

*/
#define sl_zigbee_af_fill_command_global_client_to_server_discover_commands_generated(clusterId, \
  startCommandId,  maxCommandIds) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_DISCOVER_COMMANDS_GENERATED_COMMAND_ID, \
                           "uu", \
							  startCommandId,							  maxCommandIds);
/** @brief Command description for DiscoverCommandsGeneratedResponse
*
* Command: DiscoverCommandsGeneratedResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param discoveryComplete uint8_t

* @param commandIds uint8_t *
* @param commandIdsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_discover_commands_generated_response(clusterId, \
  discoveryComplete,  commandIds, commandIdsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_DISCOVER_COMMANDS_GENERATED_RESPONSE_COMMAND_ID, \
                           "ub", \
							  discoveryComplete,							  commandIds, commandIdsLen);

/** @brief Command description for DiscoverCommandsGeneratedResponse
*
* Command: DiscoverCommandsGeneratedResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param discoveryComplete uint8_t

* @param commandIds uint8_t *
* @param commandIdsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_discover_commands_generated_response(clusterId, \
  discoveryComplete,  commandIds, commandIdsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_DISCOVER_COMMANDS_GENERATED_RESPONSE_COMMAND_ID, \
                           "ub", \
							  discoveryComplete,							  commandIds, commandIdsLen);
/** @brief Command description for DiscoverAttributesExtended
*
* Command: DiscoverAttributesExtended
* @param clusterId sl_zigbee_af_cluster_id_t
* @param startId uint16_t

* @param maxAttributeIds uint8_t

*/
#define sl_zigbee_af_fill_command_global_server_to_client_discover_attributes_extended(clusterId, \
  startId,  maxAttributeIds) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_DISCOVER_ATTRIBUTES_EXTENDED_COMMAND_ID, \
                           "vu", \
							  startId,							  maxAttributeIds);

/** @brief Command description for DiscoverAttributesExtended
*
* Command: DiscoverAttributesExtended
* @param clusterId sl_zigbee_af_cluster_id_t
* @param startId uint16_t

* @param maxAttributeIds uint8_t

*/
#define sl_zigbee_af_fill_command_global_client_to_server_discover_attributes_extended(clusterId, \
  startId,  maxAttributeIds) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_DISCOVER_ATTRIBUTES_EXTENDED_COMMAND_ID, \
                           "vu", \
							  startId,							  maxAttributeIds);
/** @brief Command description for DiscoverAttributesExtendedResponse
*
* Command: DiscoverAttributesExtendedResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param discoveryComplete uint8_t

* @param extendedDiscoverAttributesInfoRecords uint8_t *
* @param extendedDiscoverAttributesInfoRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_server_to_client_discover_attributes_extended_response(clusterId, \
  discoveryComplete,  extendedDiscoverAttributesInfoRecords, extendedDiscoverAttributesInfoRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT ), \
                           clusterId, \
                           ZCL_DISCOVER_ATTRIBUTES_EXTENDED_RESPONSE_COMMAND_ID, \
                           "ub", \
							  discoveryComplete,							  extendedDiscoverAttributesInfoRecords, extendedDiscoverAttributesInfoRecordsLen);

/** @brief Command description for DiscoverAttributesExtendedResponse
*
* Command: DiscoverAttributesExtendedResponse
* @param clusterId sl_zigbee_af_cluster_id_t
* @param discoveryComplete uint8_t

* @param extendedDiscoverAttributesInfoRecords uint8_t *
* @param extendedDiscoverAttributesInfoRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_global_client_to_server_discover_attributes_extended_response(clusterId, \
  discoveryComplete,  extendedDiscoverAttributesInfoRecords, extendedDiscoverAttributesInfoRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_GLOBAL_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           clusterId, \
                           ZCL_DISCOVER_ATTRIBUTES_EXTENDED_RESPONSE_COMMAND_ID, \
                           "ub", \
							  discoveryComplete,							  extendedDiscoverAttributesInfoRecords, extendedDiscoverAttributesInfoRecordsLen);
/** @} END Global Commands */


// Cluster Specific Commands


/** @brief Command that resets all attribute values to factory default.
* Cluster: Basic, Attributes for determining basic information about a device, setting user device information such as location, and enabling a device.
* Command: ResetToFactoryDefaults
*/
#define sl_zigbee_af_fill_command_basic_cluster_reset_to_factory_defaults( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_BASIC_CLUSTER_ID, \
                           ZCL_RESET_TO_FACTORY_DEFAULTS_COMMAND_ID, \
                           "" \
);



/** @brief This command gets locales supported.
* Cluster: Basic, Attributes for determining basic information about a device, setting user device information such as location, and enabling a device.
* Command: GetLocalesSupported
* @param startLocale uint8_t *

* @param maxLocalesRequested uint8_t

*/
#define sl_zigbee_af_fill_command_basic_cluster_get_locales_supported( \
  startLocale,  maxLocalesRequested) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_BASIC_CLUSTER_ID, \
                           ZCL_GET_LOCALES_SUPPORTED_COMMAND_ID, \
                           "su", \
							  startLocale,							  maxLocalesRequested);



/** @brief The locales supported response command is sent in response to a get locales supported command, and is used to discover which locales the device supports.
* Cluster: Basic, Attributes for determining basic information about a device, setting user device information such as location, and enabling a device.
* Command: GetLocalesSupportedResponse
* @param discoveryComplete uint8_t

* @param localeSupported uint8_t *
* @param localeSupportedLen uint16_t 
*/
#define sl_zigbee_af_fill_command_basic_cluster_get_locales_supported_response( \
  discoveryComplete,  localeSupported, localeSupportedLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_BASIC_CLUSTER_ID, \
                           ZCL_GET_LOCALES_SUPPORTED_RESPONSE_COMMAND_ID, \
                           "ub", \
							  discoveryComplete,							  localeSupported, localeSupportedLen);



/** @brief Command description for Identify
* Cluster: Identify, Attributes and commands for putting a device into Identification mode (e.g. flashing a light).
* Command: Identify
* @param identifyTime uint16_t

*/
#define sl_zigbee_af_fill_command_identify_cluster_identify( \
  identifyTime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IDENTIFY_CLUSTER_ID, \
                           ZCL_IDENTIFY_COMMAND_ID, \
                           "v", \
							  identifyTime);



/** @brief Command description for IdentifyQueryResponse
* Cluster: Identify, Attributes and commands for putting a device into Identification mode (e.g. flashing a light).
* Command: IdentifyQueryResponse
* @param timeout uint16_t

*/
#define sl_zigbee_af_fill_command_identify_cluster_identify_query_response( \
  timeout) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_IDENTIFY_CLUSTER_ID, \
                           ZCL_IDENTIFY_QUERY_RESPONSE_COMMAND_ID, \
                           "v", \
							  timeout);



/** @brief Command description for IdentifyQuery
* Cluster: Identify, Attributes and commands for putting a device into Identification mode (e.g. flashing a light).
* Command: IdentifyQuery
*/
#define sl_zigbee_af_fill_command_identify_cluster_identify_query( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IDENTIFY_CLUSTER_ID, \
                           ZCL_IDENTIFY_QUERY_COMMAND_ID, \
                           "" \
);



/** @brief Invoke EZMode on an Identify Server
* Cluster: Identify, Attributes and commands for putting a device into Identification mode (e.g. flashing a light).
* Command: EZModeInvoke
* @param action uint8_t

*/
#define sl_zigbee_af_fill_command_identify_cluster_ez_mode_invoke( \
  action) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IDENTIFY_CLUSTER_ID, \
                           ZCL_EZ_MODE_INVOKE_COMMAND_ID, \
                           "u", \
							  action);



/** @brief Update Commission State on the server device.
* Cluster: Identify, Attributes and commands for putting a device into Identification mode (e.g. flashing a light).
* Command: UpdateCommissionState
* @param action uint8_t

* @param commissionStateMask uint8_t

*/
#define sl_zigbee_af_fill_command_identify_cluster_update_commission_state( \
  action,  commissionStateMask) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IDENTIFY_CLUSTER_ID, \
                           ZCL_UPDATE_COMMISSION_STATE_COMMAND_ID, \
                           "uu", \
							  action,							  commissionStateMask);



/** @brief Command description for TriggerEffect
* Cluster: Identify, Attributes and commands for putting a device into Identification mode (e.g. flashing a light).
* Command: TriggerEffect
* @param effectId uint8_t

* @param effectVariant uint8_t

*/
#define sl_zigbee_af_fill_command_identify_cluster_trigger_effect( \
  effectId,  effectVariant) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IDENTIFY_CLUSTER_ID, \
                           ZCL_TRIGGER_EFFECT_COMMAND_ID, \
                           "uu", \
							  effectId,							  effectVariant);



/** @brief Command description for AddGroup
* Cluster: Groups, Attributes and commands for group configuration and manipulation.
* Command: AddGroup
* @param groupId uint16_t

* @param groupName uint8_t *

*/
#define sl_zigbee_af_fill_command_groups_cluster_add_group( \
  groupId,  groupName) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GROUPS_CLUSTER_ID, \
                           ZCL_ADD_GROUP_COMMAND_ID, \
                           "vs", \
							  groupId,							  groupName);



/** @brief Command description for AddGroupResponse
* Cluster: Groups, Attributes and commands for group configuration and manipulation.
* Command: AddGroupResponse
* @param status uint8_t

* @param groupId uint16_t

*/
#define sl_zigbee_af_fill_command_groups_cluster_add_group_response( \
  status,  groupId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GROUPS_CLUSTER_ID, \
                           ZCL_ADD_GROUP_RESPONSE_COMMAND_ID, \
                           "uv", \
							  status,							  groupId);



/** @brief Command description for ViewGroup
* Cluster: Groups, Attributes and commands for group configuration and manipulation.
* Command: ViewGroup
* @param groupId uint16_t

*/
#define sl_zigbee_af_fill_command_groups_cluster_view_group( \
  groupId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GROUPS_CLUSTER_ID, \
                           ZCL_VIEW_GROUP_COMMAND_ID, \
                           "v", \
							  groupId);



/** @brief Command description for ViewGroupResponse
* Cluster: Groups, Attributes and commands for group configuration and manipulation.
* Command: ViewGroupResponse
* @param status uint8_t

* @param groupId uint16_t

* @param groupName uint8_t *

*/
#define sl_zigbee_af_fill_command_groups_cluster_view_group_response( \
  status,  groupId,  groupName) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GROUPS_CLUSTER_ID, \
                           ZCL_VIEW_GROUP_RESPONSE_COMMAND_ID, \
                           "uvs", \
							  status,							  groupId,							  groupName);



/** @brief Command description for GetGroupMembership
* Cluster: Groups, Attributes and commands for group configuration and manipulation.
* Command: GetGroupMembership
* @param groupCount uint8_t

* @param groupList uint8_t *
* @param groupListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_groups_cluster_get_group_membership( \
  groupCount,  groupList, groupListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GROUPS_CLUSTER_ID, \
                           ZCL_GET_GROUP_MEMBERSHIP_COMMAND_ID, \
                           "ub", \
							  groupCount,							  groupList, groupListLen);



/** @brief Command description for GetGroupMembershipResponse
* Cluster: Groups, Attributes and commands for group configuration and manipulation.
* Command: GetGroupMembershipResponse
* @param capacity uint8_t

* @param groupCount uint8_t

* @param groupList uint8_t *
* @param groupListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_groups_cluster_get_group_membership_response( \
  capacity,  groupCount,  groupList, groupListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GROUPS_CLUSTER_ID, \
                           ZCL_GET_GROUP_MEMBERSHIP_RESPONSE_COMMAND_ID, \
                           "uub", \
							  capacity,							  groupCount,							  groupList, groupListLen);



/** @brief Command description for RemoveGroup
* Cluster: Groups, Attributes and commands for group configuration and manipulation.
* Command: RemoveGroup
* @param groupId uint16_t

*/
#define sl_zigbee_af_fill_command_groups_cluster_remove_group( \
  groupId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GROUPS_CLUSTER_ID, \
                           ZCL_REMOVE_GROUP_COMMAND_ID, \
                           "v", \
							  groupId);



/** @brief Command description for RemoveGroupResponse
* Cluster: Groups, Attributes and commands for group configuration and manipulation.
* Command: RemoveGroupResponse
* @param status uint8_t

* @param groupId uint16_t

*/
#define sl_zigbee_af_fill_command_groups_cluster_remove_group_response( \
  status,  groupId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GROUPS_CLUSTER_ID, \
                           ZCL_REMOVE_GROUP_RESPONSE_COMMAND_ID, \
                           "uv", \
							  status,							  groupId);



/** @brief Command description for RemoveAllGroups
* Cluster: Groups, Attributes and commands for group configuration and manipulation.
* Command: RemoveAllGroups
*/
#define sl_zigbee_af_fill_command_groups_cluster_remove_all_groups( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GROUPS_CLUSTER_ID, \
                           ZCL_REMOVE_ALL_GROUPS_COMMAND_ID, \
                           "" \
);



/** @brief Command description for AddGroupIfIdentifying
* Cluster: Groups, Attributes and commands for group configuration and manipulation.
* Command: AddGroupIfIdentifying
* @param groupId uint16_t

* @param groupName uint8_t *

*/
#define sl_zigbee_af_fill_command_groups_cluster_add_group_if_identifying( \
  groupId,  groupName) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GROUPS_CLUSTER_ID, \
                           ZCL_ADD_GROUP_IF_IDENTIFYING_COMMAND_ID, \
                           "vs", \
							  groupId,							  groupName);



/** @brief Add a scene to the scene table. Extension field sets are supported, and are inputed as arrays of the form [[cluster ID] [length] [value0...n] ...]
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: AddScene
* @param groupId uint16_t

* @param sceneId uint8_t

* @param transitionTime uint16_t

* @param sceneName uint8_t *

* @param extensionFieldSets uint8_t *
* @param extensionFieldSetsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_scenes_cluster_add_scene( \
  groupId,  sceneId,  transitionTime,  sceneName,  extensionFieldSets, extensionFieldSetsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_ADD_SCENE_COMMAND_ID, \
                           "vuvsb", \
							  groupId,							  sceneId,							  transitionTime,							  sceneName,							  extensionFieldSets, extensionFieldSetsLen);



/** @brief Command description for AddSceneResponse
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: AddSceneResponse
* @param status uint8_t

* @param groupId uint16_t

* @param sceneId uint8_t

*/
#define sl_zigbee_af_fill_command_scenes_cluster_add_scene_response( \
  status,  groupId,  sceneId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_ADD_SCENE_RESPONSE_COMMAND_ID, \
                           "uvu", \
							  status,							  groupId,							  sceneId);



/** @brief Command description for ViewScene
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: ViewScene
* @param groupId uint16_t

* @param sceneId uint8_t

*/
#define sl_zigbee_af_fill_command_scenes_cluster_view_scene( \
  groupId,  sceneId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_VIEW_SCENE_COMMAND_ID, \
                           "vu", \
							  groupId,							  sceneId);



/** @brief Command description for ViewSceneResponse
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: ViewSceneResponse
* @param status uint8_t

* @param groupId uint16_t

* @param sceneId uint8_t

* @param transitionTime uint16_t

* @param sceneName uint8_t *

* @param extensionFieldSets uint8_t *
* @param extensionFieldSetsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_scenes_cluster_view_scene_response( \
  status,  groupId,  sceneId,  transitionTime,  sceneName,  extensionFieldSets, extensionFieldSetsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_VIEW_SCENE_RESPONSE_COMMAND_ID, \
                           "uvuvsb", \
							  status,							  groupId,							  sceneId,							  transitionTime,							  sceneName,							  extensionFieldSets, extensionFieldSetsLen);



/** @brief Command description for RemoveScene
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: RemoveScene
* @param groupId uint16_t

* @param sceneId uint8_t

*/
#define sl_zigbee_af_fill_command_scenes_cluster_remove_scene( \
  groupId,  sceneId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_REMOVE_SCENE_COMMAND_ID, \
                           "vu", \
							  groupId,							  sceneId);



/** @brief Command description for RemoveSceneResponse
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: RemoveSceneResponse
* @param status uint8_t

* @param groupId uint16_t

* @param sceneId uint8_t

*/
#define sl_zigbee_af_fill_command_scenes_cluster_remove_scene_response( \
  status,  groupId,  sceneId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_REMOVE_SCENE_RESPONSE_COMMAND_ID, \
                           "uvu", \
							  status,							  groupId,							  sceneId);



/** @brief Command description for RemoveAllScenes
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: RemoveAllScenes
* @param groupId uint16_t

*/
#define sl_zigbee_af_fill_command_scenes_cluster_remove_all_scenes( \
  groupId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_REMOVE_ALL_SCENES_COMMAND_ID, \
                           "v", \
							  groupId);



/** @brief Command description for RemoveAllScenesResponse
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: RemoveAllScenesResponse
* @param status uint8_t

* @param groupId uint16_t

*/
#define sl_zigbee_af_fill_command_scenes_cluster_remove_all_scenes_response( \
  status,  groupId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_REMOVE_ALL_SCENES_RESPONSE_COMMAND_ID, \
                           "uv", \
							  status,							  groupId);



/** @brief Command description for StoreScene
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: StoreScene
* @param groupId uint16_t

* @param sceneId uint8_t

*/
#define sl_zigbee_af_fill_command_scenes_cluster_store_scene( \
  groupId,  sceneId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_STORE_SCENE_COMMAND_ID, \
                           "vu", \
							  groupId,							  sceneId);



/** @brief Command description for StoreSceneResponse
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: StoreSceneResponse
* @param status uint8_t

* @param groupId uint16_t

* @param sceneId uint8_t

*/
#define sl_zigbee_af_fill_command_scenes_cluster_store_scene_response( \
  status,  groupId,  sceneId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_STORE_SCENE_RESPONSE_COMMAND_ID, \
                           "uvu", \
							  status,							  groupId,							  sceneId);



/** @brief Command description for RecallScene
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: RecallScene
* @param groupId uint16_t

* @param sceneId uint8_t

* @param transitionTime uint16_t

*/
#define sl_zigbee_af_fill_command_scenes_cluster_recall_scene( \
  groupId,  sceneId,  transitionTime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_RECALL_SCENE_COMMAND_ID, \
                           "vuv", \
							  groupId,							  sceneId,							  transitionTime);



/** @brief Command description for GetSceneMembership
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: GetSceneMembership
* @param groupId uint16_t

*/
#define sl_zigbee_af_fill_command_scenes_cluster_get_scene_membership( \
  groupId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_GET_SCENE_MEMBERSHIP_COMMAND_ID, \
                           "v", \
							  groupId);



/** @brief Command description for GetSceneMembershipResponse
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: GetSceneMembershipResponse
* @param status uint8_t

* @param capacity uint8_t

* @param groupId uint16_t

* @param sceneCount uint8_t

* @param sceneList uint8_t *
* @param sceneListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_scenes_cluster_get_scene_membership_response( \
  status,  capacity,  groupId,  sceneCount,  sceneList, sceneListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_GET_SCENE_MEMBERSHIP_RESPONSE_COMMAND_ID, \
                           "uuvub", \
							  status,							  capacity,							  groupId,							  sceneCount,							  sceneList, sceneListLen);



/** @brief Command description for EnhancedAddScene
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: EnhancedAddScene
* @param groupId uint16_t

* @param sceneId uint8_t

* @param transitionTime uint16_t

* @param sceneName uint8_t *

* @param extensionFieldSets uint8_t *
* @param extensionFieldSetsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_scenes_cluster_enhanced_add_scene( \
  groupId,  sceneId,  transitionTime,  sceneName,  extensionFieldSets, extensionFieldSetsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_ENHANCED_ADD_SCENE_COMMAND_ID, \
                           "vuvsb", \
							  groupId,							  sceneId,							  transitionTime,							  sceneName,							  extensionFieldSets, extensionFieldSetsLen);



/** @brief Command description for EnhancedAddSceneResponse
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: EnhancedAddSceneResponse
* @param status uint8_t

* @param groupId uint16_t

* @param sceneId uint8_t

*/
#define sl_zigbee_af_fill_command_scenes_cluster_enhanced_add_scene_response( \
  status,  groupId,  sceneId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_ENHANCED_ADD_SCENE_RESPONSE_COMMAND_ID, \
                           "uvu", \
							  status,							  groupId,							  sceneId);



/** @brief Command description for EnhancedViewScene
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: EnhancedViewScene
* @param groupId uint16_t

* @param sceneId uint8_t

*/
#define sl_zigbee_af_fill_command_scenes_cluster_enhanced_view_scene( \
  groupId,  sceneId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_ENHANCED_VIEW_SCENE_COMMAND_ID, \
                           "vu", \
							  groupId,							  sceneId);



/** @brief Command description for EnhancedViewSceneResponse
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: EnhancedViewSceneResponse
* @param status uint8_t

* @param groupId uint16_t

* @param sceneId uint8_t

* @param transitionTime uint16_t

* @param sceneName uint8_t *

* @param extensionFieldSets uint8_t *
* @param extensionFieldSetsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_scenes_cluster_enhanced_view_scene_response( \
  status,  groupId,  sceneId,  transitionTime,  sceneName,  extensionFieldSets, extensionFieldSetsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_ENHANCED_VIEW_SCENE_RESPONSE_COMMAND_ID, \
                           "uvuvsb", \
							  status,							  groupId,							  sceneId,							  transitionTime,							  sceneName,							  extensionFieldSets, extensionFieldSetsLen);



/** @brief Command description for CopyScene
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: CopyScene
* @param mode uint8_t

* @param groupIdFrom uint16_t

* @param sceneIdFrom uint8_t

* @param groupIdTo uint16_t

* @param sceneIdTo uint8_t

*/
#define sl_zigbee_af_fill_command_scenes_cluster_copy_scene( \
  mode,  groupIdFrom,  sceneIdFrom,  groupIdTo,  sceneIdTo) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_COPY_SCENE_COMMAND_ID, \
                           "uvuvu", \
							  mode,							  groupIdFrom,							  sceneIdFrom,							  groupIdTo,							  sceneIdTo);



/** @brief Command description for CopySceneResponse
* Cluster: Scenes, Attributes and commands for scene configuration and manipulation.
* Command: CopySceneResponse
* @param status uint8_t

* @param groupIdFrom uint16_t

* @param sceneIdFrom uint8_t

*/
#define sl_zigbee_af_fill_command_scenes_cluster_copy_scene_response( \
  status,  groupIdFrom,  sceneIdFrom) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SCENES_CLUSTER_ID, \
                           ZCL_COPY_SCENE_RESPONSE_COMMAND_ID, \
                           "uvu", \
							  status,							  groupIdFrom,							  sceneIdFrom);



/** @brief Command description for Off
* Cluster: On/off, Attributes and commands for switching devices between 'On' and 'Off' states.
* Command: Off
*/
#define sl_zigbee_af_fill_command_on_off_cluster_off( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ON_OFF_CLUSTER_ID, \
                           ZCL_OFF_COMMAND_ID, \
                           "" \
);



/** @brief Client command that turns the device off with a transition given
        by the transition time in the Ember Sample transition time attribute.
* Cluster: On/off, Attributes and commands for switching devices between 'On' and 'Off' states.
* Command: SampleMfgSpecificOffWithTransition
*/
#define sl_zigbee_af_fill_command_on_off_cluster_sample_mfg_specific_off_with_transition( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ON_OFF_CLUSTER_ID, \
                              4098, \
                           ZCL_SAMPLE_MFG_SPECIFIC_OFF_WITH_TRANSITION_COMMAND_ID, \
                           "" \
);



/** @brief Command description for On
* Cluster: On/off, Attributes and commands for switching devices between 'On' and 'Off' states.
* Command: On
*/
#define sl_zigbee_af_fill_command_on_off_cluster_on( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ON_OFF_CLUSTER_ID, \
                           ZCL_ON_COMMAND_ID, \
                           "" \
);



/** @brief Client command that turns the device on with a transition given
        by the transition time in the Ember Sample transition time attribute.
* Cluster: On/off, Attributes and commands for switching devices between 'On' and 'Off' states.
* Command: SampleMfgSpecificOnWithTransition
*/
#define sl_zigbee_af_fill_command_on_off_cluster_sample_mfg_specific_on_with_transition( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ON_OFF_CLUSTER_ID, \
                              4098, \
                           ZCL_SAMPLE_MFG_SPECIFIC_ON_WITH_TRANSITION_COMMAND_ID, \
                           "" \
);



/** @brief Client command that turns the device on with a transition given
        by the transition time in the Ember Sample transition time attribute.
* Cluster: On/off, Attributes and commands for switching devices between 'On' and 'Off' states.
* Command: SampleMfgSpecificOnWithTransition2
*/
#define sl_zigbee_af_fill_command_on_off_cluster_sample_mfg_specific_on_with_transition2( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ON_OFF_CLUSTER_ID, \
                              4169, \
                           ZCL_SAMPLE_MFG_SPECIFIC_ON_WITH_TRANSITION2_COMMAND_ID, \
                           "" \
);



/** @brief Command description for Toggle
* Cluster: On/off, Attributes and commands for switching devices between 'On' and 'Off' states.
* Command: Toggle
*/
#define sl_zigbee_af_fill_command_on_off_cluster_toggle( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ON_OFF_CLUSTER_ID, \
                           ZCL_TOGGLE_COMMAND_ID, \
                           "" \
);



/** @brief Client command that toggles the device with a transition given
        by the transition time in the Ember Sample transition time attribute.
* Cluster: On/off, Attributes and commands for switching devices between 'On' and 'Off' states.
* Command: SampleMfgSpecificToggleWithTransition
*/
#define sl_zigbee_af_fill_command_on_off_cluster_sample_mfg_specific_toggle_with_transition( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ON_OFF_CLUSTER_ID, \
                              4098, \
                           ZCL_SAMPLE_MFG_SPECIFIC_TOGGLE_WITH_TRANSITION_COMMAND_ID, \
                           "" \
);



/** @brief Client command that toggles the device with a transition given
        by the transition time in the Ember Sample transition time attribute.
* Cluster: On/off, Attributes and commands for switching devices between 'On' and 'Off' states.
* Command: SampleMfgSpecificToggleWithTransition2
*/
#define sl_zigbee_af_fill_command_on_off_cluster_sample_mfg_specific_toggle_with_transition2( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ON_OFF_CLUSTER_ID, \
                              4169, \
                           ZCL_SAMPLE_MFG_SPECIFIC_TOGGLE_WITH_TRANSITION2_COMMAND_ID, \
                           "" \
);



/** @brief Command description for OffWithEffect
* Cluster: On/off, Attributes and commands for switching devices between 'On' and 'Off' states.
* Command: OffWithEffect
* @param effectId uint8_t

* @param effectVariant uint8_t

*/
#define sl_zigbee_af_fill_command_on_off_cluster_off_with_effect( \
  effectId,  effectVariant) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ON_OFF_CLUSTER_ID, \
                           ZCL_OFF_WITH_EFFECT_COMMAND_ID, \
                           "uu", \
							  effectId,							  effectVariant);



/** @brief Command description for OnWithRecallGlobalScene
* Cluster: On/off, Attributes and commands for switching devices between 'On' and 'Off' states.
* Command: OnWithRecallGlobalScene
*/
#define sl_zigbee_af_fill_command_on_off_cluster_on_with_recall_global_scene( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ON_OFF_CLUSTER_ID, \
                           ZCL_ON_WITH_RECALL_GLOBAL_SCENE_COMMAND_ID, \
                           "" \
);



/** @brief Command description for OnWithTimedOff
* Cluster: On/off, Attributes and commands for switching devices between 'On' and 'Off' states.
* Command: OnWithTimedOff
* @param onOffControl uint8_t

* @param onTime uint16_t

* @param offWaitTime uint16_t

*/
#define sl_zigbee_af_fill_command_on_off_cluster_on_with_timed_off( \
  onOffControl,  onTime,  offWaitTime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ON_OFF_CLUSTER_ID, \
                           ZCL_ON_WITH_TIMED_OFF_COMMAND_ID, \
                           "uvv", \
							  onOffControl,							  onTime,							  offWaitTime);



/** @brief Command description for MoveToLevel
* Cluster: Level Control, Attributes and commands for controlling devices that can be set to a level between fully 'On' and fully 'Off.'
* Command: MoveToLevel
* @param level uint8_t

* @param transitionTime uint16_t

* @param optionMask uint8_t

* @param optionOverride uint8_t

*/
#define sl_zigbee_af_fill_command_level_control_cluster_move_to_level( \
  level,  transitionTime,  optionMask,  optionOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_LEVEL_CONTROL_CLUSTER_ID, \
                           ZCL_MOVE_TO_LEVEL_COMMAND_ID, \
                           "uvuu", \
							  level,							  transitionTime,							  optionMask,							  optionOverride);



/** @brief Command description for Move
* Cluster: Level Control, Attributes and commands for controlling devices that can be set to a level between fully 'On' and fully 'Off.'
* Command: Move
* @param moveMode uint8_t

* @param rate uint8_t

* @param optionMask uint8_t

* @param optionOverride uint8_t

*/
#define sl_zigbee_af_fill_command_level_control_cluster_move( \
  moveMode,  rate,  optionMask,  optionOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_LEVEL_CONTROL_CLUSTER_ID, \
                           ZCL_MOVE_COMMAND_ID, \
                           "uuuu", \
							  moveMode,							  rate,							  optionMask,							  optionOverride);



/** @brief Command description for Step
* Cluster: Level Control, Attributes and commands for controlling devices that can be set to a level between fully 'On' and fully 'Off.'
* Command: Step
* @param stepMode uint8_t

* @param stepSize uint8_t

* @param transitionTime uint16_t

* @param optionMask uint8_t

* @param optionOverride uint8_t

*/
#define sl_zigbee_af_fill_command_level_control_cluster_step( \
  stepMode,  stepSize,  transitionTime,  optionMask,  optionOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_LEVEL_CONTROL_CLUSTER_ID, \
                           ZCL_STEP_COMMAND_ID, \
                           "uuvuu", \
							  stepMode,							  stepSize,							  transitionTime,							  optionMask,							  optionOverride);



/** @brief Command description for Stop
* Cluster: Level Control, Attributes and commands for controlling devices that can be set to a level between fully 'On' and fully 'Off.'
* Command: Stop
* @param optionMask uint8_t

* @param optionOverride uint8_t

*/
#define sl_zigbee_af_fill_command_level_control_cluster_stop( \
  optionMask,  optionOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_LEVEL_CONTROL_CLUSTER_ID, \
                           ZCL_STOP_COMMAND_ID, \
                           "uu", \
							  optionMask,							  optionOverride);



/** @brief Command description for MoveToLevelWithOnOff
* Cluster: Level Control, Attributes and commands for controlling devices that can be set to a level between fully 'On' and fully 'Off.'
* Command: MoveToLevelWithOnOff
* @param level uint8_t

* @param transitionTime uint16_t

*/
#define sl_zigbee_af_fill_command_level_control_cluster_move_to_level_with_on_off( \
  level,  transitionTime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_LEVEL_CONTROL_CLUSTER_ID, \
                           ZCL_MOVE_TO_LEVEL_WITH_ON_OFF_COMMAND_ID, \
                           "uv", \
							  level,							  transitionTime);



/** @brief Command description for MoveWithOnOff
* Cluster: Level Control, Attributes and commands for controlling devices that can be set to a level between fully 'On' and fully 'Off.'
* Command: MoveWithOnOff
* @param moveMode uint8_t

* @param rate uint8_t

*/
#define sl_zigbee_af_fill_command_level_control_cluster_move_with_on_off( \
  moveMode,  rate) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_LEVEL_CONTROL_CLUSTER_ID, \
                           ZCL_MOVE_WITH_ON_OFF_COMMAND_ID, \
                           "uu", \
							  moveMode,							  rate);



/** @brief Command description for StepWithOnOff
* Cluster: Level Control, Attributes and commands for controlling devices that can be set to a level between fully 'On' and fully 'Off.'
* Command: StepWithOnOff
* @param stepMode uint8_t

* @param stepSize uint8_t

* @param transitionTime uint16_t

*/
#define sl_zigbee_af_fill_command_level_control_cluster_step_with_on_off( \
  stepMode,  stepSize,  transitionTime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_LEVEL_CONTROL_CLUSTER_ID, \
                           ZCL_STEP_WITH_ON_OFF_COMMAND_ID, \
                           "uuv", \
							  stepMode,							  stepSize,							  transitionTime);



/** @brief Command description for StopWithOnOff
* Cluster: Level Control, Attributes and commands for controlling devices that can be set to a level between fully 'On' and fully 'Off.'
* Command: StopWithOnOff
*/
#define sl_zigbee_af_fill_command_level_control_cluster_stop_with_on_off( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_LEVEL_CONTROL_CLUSTER_ID, \
                           ZCL_STOP_WITH_ON_OFF_COMMAND_ID, \
                           "" \
);



/** @brief Command description for MoveToClosestFrequency
* Cluster: Level Control, Attributes and commands for controlling devices that can be set to a level between fully 'On' and fully 'Off.'
* Command: MoveToClosestFrequency
* @param frequency uint16_t

*/
#define sl_zigbee_af_fill_command_level_control_cluster_move_to_closest_frequency( \
  frequency) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_LEVEL_CONTROL_CLUSTER_ID, \
                           ZCL_MOVE_TO_CLOSEST_FREQUENCY_COMMAND_ID, \
                           "v", \
							  frequency);



/** @brief Command description for ResetAlarm
* Cluster: Alarms, Attributes and commands for sending notifications and configuring alarm functionality.
* Command: ResetAlarm
* @param alarmCode uint8_t

* @param clusterId uint16_t

*/
#define sl_zigbee_af_fill_command_alarm_cluster_reset_alarm( \
  alarmCode,  clusterId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ALARM_CLUSTER_ID, \
                           ZCL_RESET_ALARM_COMMAND_ID, \
                           "uv", \
							  alarmCode,							  clusterId);



/** @brief Command description for Alarm
* Cluster: Alarms, Attributes and commands for sending notifications and configuring alarm functionality.
* Command: Alarm
* @param alarmCode uint8_t

* @param clusterId uint16_t

*/
#define sl_zigbee_af_fill_command_alarm_cluster_alarm( \
  alarmCode,  clusterId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_ALARM_CLUSTER_ID, \
                           ZCL_ALARM_COMMAND_ID, \
                           "uv", \
							  alarmCode,							  clusterId);



/** @brief Command description for ResetAllAlarms
* Cluster: Alarms, Attributes and commands for sending notifications and configuring alarm functionality.
* Command: ResetAllAlarms
*/
#define sl_zigbee_af_fill_command_alarm_cluster_reset_all_alarms( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ALARM_CLUSTER_ID, \
                           ZCL_RESET_ALL_ALARMS_COMMAND_ID, \
                           "" \
);



/** @brief Command description for GetAlarmResponse
* Cluster: Alarms, Attributes and commands for sending notifications and configuring alarm functionality.
* Command: GetAlarmResponse
* @param status uint8_t

* @param alarmCode uint8_t

* @param clusterId uint16_t

* @param timeStamp uint32_t

*/
#define sl_zigbee_af_fill_command_alarm_cluster_get_alarm_response( \
  status,  alarmCode,  clusterId,  timeStamp) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_ALARM_CLUSTER_ID, \
                           ZCL_GET_ALARM_RESPONSE_COMMAND_ID, \
                           "uuvw", \
							  status,							  alarmCode,							  clusterId,							  timeStamp);



/** @brief Command description for GetAlarm
* Cluster: Alarms, Attributes and commands for sending notifications and configuring alarm functionality.
* Command: GetAlarm
*/
#define sl_zigbee_af_fill_command_alarm_cluster_get_alarm( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ALARM_CLUSTER_ID, \
                           ZCL_GET_ALARM_COMMAND_ID, \
                           "" \
);



/** @brief Command description for ResetAlarmLog
* Cluster: Alarms, Attributes and commands for sending notifications and configuring alarm functionality.
* Command: ResetAlarmLog
*/
#define sl_zigbee_af_fill_command_alarm_cluster_reset_alarm_log( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ALARM_CLUSTER_ID, \
                           ZCL_RESET_ALARM_LOG_COMMAND_ID, \
                           "" \
);



/** @brief Command description for SetAbsoluteLocation
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: SetAbsoluteLocation
* @param coordinate1 int16_t

* @param coordinate2 int16_t

* @param coordinate3 int16_t

* @param power int16_t

* @param pathLossExponent uint16_t

*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_set_absolute_location( \
  coordinate1,  coordinate2,  coordinate3,  power,  pathLossExponent) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_SET_ABSOLUTE_LOCATION_COMMAND_ID, \
                           "vvvvv", \
							  coordinate1,							  coordinate2,							  coordinate3,							  power,							  pathLossExponent);



/** @brief Command description for DeviceConfigurationResponse
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: DeviceConfigurationResponse
* @param status uint8_t

* @param power int16_t

* @param pathLossExponent uint16_t

* @param calculationPeriod uint16_t

* @param numberRssiMeasurements uint8_t

* @param reportingPeriod uint16_t

*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_device_configuration_response( \
  status,  power,  pathLossExponent,  calculationPeriod,  numberRssiMeasurements,  reportingPeriod) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_DEVICE_CONFIGURATION_RESPONSE_COMMAND_ID, \
                           "uvvvuv", \
							  status,							  power,							  pathLossExponent,							  calculationPeriod,							  numberRssiMeasurements,							  reportingPeriod);



/** @brief Command description for SetDeviceConfiguration
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: SetDeviceConfiguration
* @param power int16_t

* @param pathLossExponent uint16_t

* @param calculationPeriod uint16_t

* @param numberRssiMeasurements uint8_t

* @param reportingPeriod uint16_t

*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_set_device_configuration( \
  power,  pathLossExponent,  calculationPeriod,  numberRssiMeasurements,  reportingPeriod) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_SET_DEVICE_CONFIGURATION_COMMAND_ID, \
                           "vvvuv", \
							  power,							  pathLossExponent,							  calculationPeriod,							  numberRssiMeasurements,							  reportingPeriod);



/** @brief Command description for LocationDataResponse
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: LocationDataResponse
* @param status uint8_t

* @param locationType uint8_t

* @param coordinate1 int16_t

* @param coordinate2 int16_t

* @param coordinate3 int16_t

* @param power int16_t

* @param pathLossExponent uint16_t

* @param locationMethod uint8_t

* @param qualityMeasure uint8_t

* @param locationAge uint16_t

*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_location_data_response( \
  status,  locationType,  coordinate1,  coordinate2,  coordinate3,  power,  pathLossExponent,  locationMethod,  qualityMeasure,  locationAge) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_LOCATION_DATA_RESPONSE_COMMAND_ID, \
                           "uuvvvvvuuv", \
							  status,							  locationType,							  coordinate1,							  coordinate2,							  coordinate3,							  power,							  pathLossExponent,							  locationMethod,							  qualityMeasure,							  locationAge);



/** @brief Command description for GetDeviceConfiguration
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: GetDeviceConfiguration
* @param targetAddress uint8_t *

*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_get_device_configuration( \
  targetAddress) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_GET_DEVICE_CONFIGURATION_COMMAND_ID, \
                           "8", \
							  targetAddress);



/** @brief Command description for LocationDataNotification
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: LocationDataNotification
* @param locationType uint8_t

* @param coordinate1 int16_t

* @param coordinate2 int16_t

* @param coordinate3 int16_t

* @param power int16_t

* @param pathLossExponent uint16_t

* @param locationMethod uint8_t

* @param qualityMeasure uint8_t

* @param locationAge uint16_t

*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_location_data_notification( \
  locationType,  coordinate1,  coordinate2,  coordinate3,  power,  pathLossExponent,  locationMethod,  qualityMeasure,  locationAge) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_LOCATION_DATA_NOTIFICATION_COMMAND_ID, \
                           "uvvvvvuuv", \
							  locationType,							  coordinate1,							  coordinate2,							  coordinate3,							  power,							  pathLossExponent,							  locationMethod,							  qualityMeasure,							  locationAge);



/** @brief Command description for GetLocationData
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: GetLocationData
* @param flags uint8_t

* @param numberResponses uint8_t

* @param targetAddress uint8_t *

*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_get_location_data( \
  flags,  numberResponses,  targetAddress) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_GET_LOCATION_DATA_COMMAND_ID, \
                           "uu8", \
							  flags,							  numberResponses,							  targetAddress);



/** @brief Command description for CompactLocationDataNotification
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: CompactLocationDataNotification
* @param locationType uint8_t

* @param coordinate1 int16_t

* @param coordinate2 int16_t

* @param coordinate3 int16_t

* @param qualityMeasure uint8_t

* @param locationAge uint16_t

*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_compact_location_data_notification( \
  locationType,  coordinate1,  coordinate2,  coordinate3,  qualityMeasure,  locationAge) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_COMPACT_LOCATION_DATA_NOTIFICATION_COMMAND_ID, \
                           "uvvvuv", \
							  locationType,							  coordinate1,							  coordinate2,							  coordinate3,							  qualityMeasure,							  locationAge);



/** @brief Command description for RssiResponse
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: RssiResponse
* @param replyingDevice uint8_t *

* @param coordinate1 int16_t

* @param coordinate2 int16_t

* @param coordinate3 int16_t

* @param rssi int8_t

* @param numberRssiMeasurements uint8_t

*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_rssi_response( \
  replyingDevice,  coordinate1,  coordinate2,  coordinate3,  rssi,  numberRssiMeasurements) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_RSSI_RESPONSE_COMMAND_ID, \
                           "8vvvuu", \
							  replyingDevice,							  coordinate1,							  coordinate2,							  coordinate3,							  rssi,							  numberRssiMeasurements);



/** @brief Command description for RssiPing
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: RssiPing
* @param locationType uint8_t

*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_rssi_ping( \
  locationType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_RSSI_PING_COMMAND_ID, \
                           "u", \
							  locationType);



/** @brief Command description for SendPings
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: SendPings
* @param targetAddress uint8_t *

* @param numberRssiMeasurements uint8_t

* @param calculationPeriod uint16_t

*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_send_pings( \
  targetAddress,  numberRssiMeasurements,  calculationPeriod) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_SEND_PINGS_COMMAND_ID, \
                           "8uv", \
							  targetAddress,							  numberRssiMeasurements,							  calculationPeriod);



/** @brief Command description for RssiRequest
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: RssiRequest
*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_rssi_request( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_RSSI_REQUEST_COMMAND_ID, \
                           "" \
);



/** @brief Command description for AnchorNodeAnnounce
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: AnchorNodeAnnounce
* @param anchorNodeIeeeAddress uint8_t *

* @param coordinate1 int16_t

* @param coordinate2 int16_t

* @param coordinate3 int16_t

*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_anchor_node_announce( \
  anchorNodeIeeeAddress,  coordinate1,  coordinate2,  coordinate3) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_ANCHOR_NODE_ANNOUNCE_COMMAND_ID, \
                           "8vvv", \
							  anchorNodeIeeeAddress,							  coordinate1,							  coordinate2,							  coordinate3);



/** @brief Command description for ReportRssiMeasurements
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: ReportRssiMeasurements
* @param measuringDevice uint8_t *

* @param neighbors uint8_t

* @param neighborsInfo uint8_t *
* @param neighborsInfoLen uint16_t 
*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_report_rssi_measurements( \
  measuringDevice,  neighbors,  neighborsInfo, neighborsInfoLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_REPORT_RSSI_MEASUREMENTS_COMMAND_ID, \
                           "8ub", \
							  measuringDevice,							  neighbors,							  neighborsInfo, neighborsInfoLen);



/** @brief Command description for RequestOwnLocation
* Cluster: RSSI Location, Attributes and commands that provide a means for exchanging location information and channel parameters among devices.
* Command: RequestOwnLocation
* @param blindNode uint8_t *

*/
#define sl_zigbee_af_fill_command_rssi_location_cluster_request_own_location( \
  blindNode) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_RSSI_LOCATION_CLUSTER_ID, \
                           ZCL_REQUEST_OWN_LOCATION_COMMAND_ID, \
                           "8", \
							  blindNode);



/** @brief Command description for RestartDevice
* Cluster: Commissioning, Attributes and commands for commissioning and managing a ZigBee device.
* Command: RestartDevice
* @param options uint8_t

* @param delay uint8_t

* @param jitter uint8_t

*/
#define sl_zigbee_af_fill_command_commissioning_cluster_restart_device( \
  options,  delay,  jitter) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_RESTART_DEVICE_COMMAND_ID, \
                           "uuu", \
							  options,							  delay,							  jitter);



/** @brief Command description for RestartDeviceResponse
* Cluster: Commissioning, Attributes and commands for commissioning and managing a ZigBee device.
* Command: RestartDeviceResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_commissioning_cluster_restart_device_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_RESTART_DEVICE_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Command description for SaveStartupParameters
* Cluster: Commissioning, Attributes and commands for commissioning and managing a ZigBee device.
* Command: SaveStartupParameters
* @param options uint8_t

* @param index uint8_t

*/
#define sl_zigbee_af_fill_command_commissioning_cluster_save_startup_parameters( \
  options,  index) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_SAVE_STARTUP_PARAMETERS_COMMAND_ID, \
                           "uu", \
							  options,							  index);



/** @brief Command description for SaveStartupParametersResponse
* Cluster: Commissioning, Attributes and commands for commissioning and managing a ZigBee device.
* Command: SaveStartupParametersResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_commissioning_cluster_save_startup_parameters_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_SAVE_STARTUP_PARAMETERS_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Command description for RestoreStartupParameters
* Cluster: Commissioning, Attributes and commands for commissioning and managing a ZigBee device.
* Command: RestoreStartupParameters
* @param options uint8_t

* @param index uint8_t

*/
#define sl_zigbee_af_fill_command_commissioning_cluster_restore_startup_parameters( \
  options,  index) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_RESTORE_STARTUP_PARAMETERS_COMMAND_ID, \
                           "uu", \
							  options,							  index);



/** @brief Command description for RestoreStartupParametersResponse
* Cluster: Commissioning, Attributes and commands for commissioning and managing a ZigBee device.
* Command: RestoreStartupParametersResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_commissioning_cluster_restore_startup_parameters_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_RESTORE_STARTUP_PARAMETERS_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Command description for ResetStartupParameters
* Cluster: Commissioning, Attributes and commands for commissioning and managing a ZigBee device.
* Command: ResetStartupParameters
* @param options uint8_t

* @param index uint8_t

*/
#define sl_zigbee_af_fill_command_commissioning_cluster_reset_startup_parameters( \
  options,  index) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_RESET_STARTUP_PARAMETERS_COMMAND_ID, \
                           "uu", \
							  options,							  index);



/** @brief Command description for ResetStartupParametersResponse
* Cluster: Commissioning, Attributes and commands for commissioning and managing a ZigBee device.
* Command: ResetStartupParametersResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_commissioning_cluster_reset_startup_parameters_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_RESET_STARTUP_PARAMETERS_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief The TransferPartitionedFrame command is used to send a partitioned frame to another Partition cluster.
* Cluster: Partition, Commands and attributes for enabling partitioning of large frame to be carried from other clusters of ZigBee devices.
* Command: TransferPartitionedFrame
* @param fragmentationOptions uint8_t

* @param partitionedIndicatorAndFrame uint8_t *
* @param partitionedIndicatorAndFrameLen uint16_t 
*/
#define sl_zigbee_af_fill_command_partition_cluster_transfer_partitioned_frame( \
  fragmentationOptions,  partitionedIndicatorAndFrame, partitionedIndicatorAndFrameLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PARTITION_CLUSTER_ID, \
                           ZCL_TRANSFER_PARTITIONED_FRAME_COMMAND_ID, \
                           "ub", \
							  fragmentationOptions,							  partitionedIndicatorAndFrame, partitionedIndicatorAndFrameLen);



/** @brief MultipleACK command.
* Cluster: Partition, Commands and attributes for enabling partitioning of large frame to be carried from other clusters of ZigBee devices.
* Command: MultipleAck
* @param ackOptions uint8_t

* @param firstFrameIdAndNackList uint8_t *
* @param firstFrameIdAndNackListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_partition_cluster_multiple_ack( \
  ackOptions,  firstFrameIdAndNackList, firstFrameIdAndNackListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PARTITION_CLUSTER_ID, \
                           ZCL_MULTIPLE_ACK_COMMAND_ID, \
                           "ub", \
							  ackOptions,							  firstFrameIdAndNackList, firstFrameIdAndNackListLen);



/** @brief The ReadHandshakeParam command is used in order to read the appropriate set of parameters for each transaction to be performed by the Partition Cluster.
* Cluster: Partition, Commands and attributes for enabling partitioning of large frame to be carried from other clusters of ZigBee devices.
* Command: ReadHandshakeParam
* @param partitionedClusterId uint16_t

* @param attributeList uint8_t *
* @param attributeListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_partition_cluster_read_handshake_param( \
  partitionedClusterId,  attributeList, attributeListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PARTITION_CLUSTER_ID, \
                           ZCL_READ_HANDSHAKE_PARAM_COMMAND_ID, \
                           "vb", \
							  partitionedClusterId,							  attributeList, attributeListLen);



/** @brief The ReadHandshakeParamResponse command is used in order to response to the corresponding ReadHandshakeParam command in order to communicate the appropriate set of parameters configured for each transaction to be performed by the Partition Cluster.
* Cluster: Partition, Commands and attributes for enabling partitioning of large frame to be carried from other clusters of ZigBee devices.
* Command: ReadHandshakeParamResponse
* @param partitionedClusterId uint16_t

* @param readAttributeStatusRecords uint8_t *
* @param readAttributeStatusRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_partition_cluster_read_handshake_param_response( \
  partitionedClusterId,  readAttributeStatusRecords, readAttributeStatusRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PARTITION_CLUSTER_ID, \
                           ZCL_READ_HANDSHAKE_PARAM_RESPONSE_COMMAND_ID, \
                           "vb", \
							  partitionedClusterId,							  readAttributeStatusRecords, readAttributeStatusRecordsLen);



/** @brief The WriteHandshakeParam command is used during the handshake phase in order to write the appropriate parameters for each transaction to be performed by the Partition Cluster.
* Cluster: Partition, Commands and attributes for enabling partitioning of large frame to be carried from other clusters of ZigBee devices.
* Command: WriteHandshakeParam
* @param partitionedClusterId uint16_t

* @param writeAttributeRecords uint8_t *
* @param writeAttributeRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_partition_cluster_write_handshake_param( \
  partitionedClusterId,  writeAttributeRecords, writeAttributeRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PARTITION_CLUSTER_ID, \
                           ZCL_WRITE_HANDSHAKE_PARAM_COMMAND_ID, \
                           "vb", \
							  partitionedClusterId,							  writeAttributeRecords, writeAttributeRecordsLen);



/** @brief This command is generated when the upgrade server wishes to notify the clients of the available OTA upgrade image.  The command can be sent as unicast which provides a way for the server to force the upgrade on the client.  The command can also be sent as broadcast or multicast to certain class of clients (for example, the ones that have matching manufacturing and device ids).
* Cluster: Over the Air Bootloading, This cluster contains commands and attributes that act as an interface for ZigBee Over-the-air bootloading.
* Command: ImageNotify
* @param payloadType uint8_t

* @param queryJitter uint8_t

* @param manufacturerId uint16_t

* @param imageType uint16_t

* @param newFileVersion uint32_t

*/
#define sl_zigbee_af_fill_command_ota_bootload_cluster_image_notify( \
  payloadType,  queryJitter,  manufacturerId,  imageType,  newFileVersion) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_OTA_BOOTLOAD_CLUSTER_ID, \
                           ZCL_IMAGE_NOTIFY_COMMAND_ID, \
                           "uuvvw", \
							  payloadType,							  queryJitter,							  manufacturerId,							  imageType,							  newFileVersion);



/** @brief This command is generated upon receipt of an Image Notify command to indicate that the client is looking for the next firmware image to upgrade to.  The client may also choose to send the command periodically to the server.
* Cluster: Over the Air Bootloading, This cluster contains commands and attributes that act as an interface for ZigBee Over-the-air bootloading.
* Command: QueryNextImageRequest
* @param fieldControl uint8_t

* @param manufacturerId uint16_t

* @param imageType uint16_t

* @param currentFileVersion uint32_t

* @param hardwareVersion uint16_t

*/
#define sl_zigbee_af_fill_command_ota_bootload_cluster_query_next_image_request( \
  fieldControl,  manufacturerId,  imageType,  currentFileVersion,  hardwareVersion) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_OTA_BOOTLOAD_CLUSTER_ID, \
                           ZCL_QUERY_NEXT_IMAGE_REQUEST_COMMAND_ID, \
                           "uvvwv", \
							  fieldControl,							  manufacturerId,							  imageType,							  currentFileVersion,							  hardwareVersion);



/** @brief This command is generated upon receipt of an QueryNextImageRequest command to response whether the server has a valid OTA upgrade image for the client or not.  If the server has the file, information regarding the file and OTA upgrade process will be included in the command.
* Cluster: Over the Air Bootloading, This cluster contains commands and attributes that act as an interface for ZigBee Over-the-air bootloading.
* Command: QueryNextImageResponse
* @param status uint8_t

* @param manufacturerId uint16_t

* @param imageType uint16_t

* @param fileVersion uint32_t

* @param imageSize uint32_t

*/
#define sl_zigbee_af_fill_command_ota_bootload_cluster_query_next_image_response( \
  status,  manufacturerId,  imageType,  fileVersion,  imageSize) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_OTA_BOOTLOAD_CLUSTER_ID, \
                           ZCL_QUERY_NEXT_IMAGE_RESPONSE_COMMAND_ID, \
                           "uvvww", \
							  status,							  manufacturerId,							  imageType,							  fileVersion,							  imageSize);



/** @brief This command is generated by the client to request blocks of OTA upgrade file data.
* Cluster: Over the Air Bootloading, This cluster contains commands and attributes that act as an interface for ZigBee Over-the-air bootloading.
* Command: ImageBlockRequest
* @param fieldControl uint8_t

* @param manufacturerId uint16_t

* @param imageType uint16_t

* @param fileVersion uint32_t

* @param fileOffset uint32_t

* @param maxDataSize uint8_t

* @param requestNodeAddress uint8_t *

*/
#define sl_zigbee_af_fill_command_ota_bootload_cluster_image_block_request( \
  fieldControl,  manufacturerId,  imageType,  fileVersion,  fileOffset,  maxDataSize,  requestNodeAddress) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_OTA_BOOTLOAD_CLUSTER_ID, \
                           ZCL_IMAGE_BLOCK_REQUEST_COMMAND_ID, \
                           "uvvwwu8", \
							  fieldControl,							  manufacturerId,							  imageType,							  fileVersion,							  fileOffset,							  maxDataSize,							  requestNodeAddress);



/** @brief This command is generated by the client to request pages of OTA upgrade file data. A page would contain multiple blocks of data.
* Cluster: Over the Air Bootloading, This cluster contains commands and attributes that act as an interface for ZigBee Over-the-air bootloading.
* Command: ImagePageRequest
* @param fieldControl uint8_t

* @param manufacturerId uint16_t

* @param imageType uint16_t

* @param fileVersion uint32_t

* @param fileOffset uint32_t

* @param maxDataSize uint8_t

* @param pageSize uint16_t

* @param responseSpacing uint16_t

* @param requestNodeAddress uint8_t *

*/
#define sl_zigbee_af_fill_command_ota_bootload_cluster_image_page_request( \
  fieldControl,  manufacturerId,  imageType,  fileVersion,  fileOffset,  maxDataSize,  pageSize,  responseSpacing,  requestNodeAddress) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_OTA_BOOTLOAD_CLUSTER_ID, \
                           ZCL_IMAGE_PAGE_REQUEST_COMMAND_ID, \
                           "uvvwwuvv8", \
							  fieldControl,							  manufacturerId,							  imageType,							  fileVersion,							  fileOffset,							  maxDataSize,							  pageSize,							  responseSpacing,							  requestNodeAddress);



/** @brief This command is generated by the server in response to the block or page request command.  If the server has the data available, it will reply back with a SUCCESS status.  For other error cases, it may reply with status WAIT_FOR_DATA (server does not have the data available yet) or ABORT (invalid requested parameters or other failure cases).
* Cluster: Over the Air Bootloading, This cluster contains commands and attributes that act as an interface for ZigBee Over-the-air bootloading.
* Command: ImageBlockResponse
* @param status uint8_t

* @param manufacturerId uint16_t

* @param imageType uint16_t

* @param fileVersion uint32_t

* @param fileOffset uint32_t

* @param dataSize uint8_t

* @param imageData uint8_t *
* @param imageDataLen uint16_t 
*/
#define sl_zigbee_af_fill_command_ota_bootload_cluster_image_block_response( \
  status,  manufacturerId,  imageType,  fileVersion,  fileOffset,  dataSize,  imageData, imageDataLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_OTA_BOOTLOAD_CLUSTER_ID, \
                           ZCL_IMAGE_BLOCK_RESPONSE_COMMAND_ID, \
                           "uvvwwub", \
							  status,							  manufacturerId,							  imageType,							  fileVersion,							  fileOffset,							  dataSize,							  imageData, imageDataLen);



/** @brief This command is generated by the client to notify the server of the end of the upgrade process.  The process may end with success or error status.
* Cluster: Over the Air Bootloading, This cluster contains commands and attributes that act as an interface for ZigBee Over-the-air bootloading.
* Command: UpgradeEndRequest
* @param status uint8_t

* @param manufacturerId uint16_t

* @param imageType uint16_t

* @param fileVersion uint32_t

*/
#define sl_zigbee_af_fill_command_ota_bootload_cluster_upgrade_end_request( \
  status,  manufacturerId,  imageType,  fileVersion) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_OTA_BOOTLOAD_CLUSTER_ID, \
                           ZCL_UPGRADE_END_REQUEST_COMMAND_ID, \
                           "uvvw", \
							  status,							  manufacturerId,							  imageType,							  fileVersion);



/** @brief This command is generated by the server in response to the upgrade request in order to let the client know when to upgrade to running new firmware image.
* Cluster: Over the Air Bootloading, This cluster contains commands and attributes that act as an interface for ZigBee Over-the-air bootloading.
* Command: UpgradeEndResponse
* @param manufacturerId uint16_t

* @param imageType uint16_t

* @param fileVersion uint32_t

* @param currentTime uint32_t

* @param upgradeTime uint32_t

*/
#define sl_zigbee_af_fill_command_ota_bootload_cluster_upgrade_end_response( \
  manufacturerId,  imageType,  fileVersion,  currentTime,  upgradeTime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_OTA_BOOTLOAD_CLUSTER_ID, \
                           ZCL_UPGRADE_END_RESPONSE_COMMAND_ID, \
                           "vvwww", \
							  manufacturerId,							  imageType,							  fileVersion,							  currentTime,							  upgradeTime);



/** @brief This command is generated by the client to request a file that is specific to itself.  The intention is to provide a way for the client to request non-OTA upgrade file.
* Cluster: Over the Air Bootloading, This cluster contains commands and attributes that act as an interface for ZigBee Over-the-air bootloading.
* Command: QuerySpecificFileRequest
* @param requestNodeAddress uint8_t *

* @param manufacturerId uint16_t

* @param imageType uint16_t

* @param fileVersion uint32_t

* @param currentZigbeeStackVersion uint16_t

*/
#define sl_zigbee_af_fill_command_ota_bootload_cluster_query_specific_file_request( \
  requestNodeAddress,  manufacturerId,  imageType,  fileVersion,  currentZigbeeStackVersion) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_OTA_BOOTLOAD_CLUSTER_ID, \
                           ZCL_QUERY_SPECIFIC_FILE_REQUEST_COMMAND_ID, \
                           "8vvwv", \
							  requestNodeAddress,							  manufacturerId,							  imageType,							  fileVersion,							  currentZigbeeStackVersion);



/** @brief This command is generated upon receipt of an QuerySpecificFileRequest command to response whether the server has a valid file for the client or not.  If the server has the file, information regarding the file and OTA process will be included in the command.
* Cluster: Over the Air Bootloading, This cluster contains commands and attributes that act as an interface for ZigBee Over-the-air bootloading.
* Command: QuerySpecificFileResponse
* @param status uint8_t

* @param manufacturerId uint16_t

* @param imageType uint16_t

* @param fileVersion uint32_t

* @param imageSize uint32_t

*/
#define sl_zigbee_af_fill_command_ota_bootload_cluster_query_specific_file_response( \
  status,  manufacturerId,  imageType,  fileVersion,  imageSize) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_OTA_BOOTLOAD_CLUSTER_ID, \
                           ZCL_QUERY_SPECIFIC_FILE_RESPONSE_COMMAND_ID, \
                           "uvvww", \
							  status,							  manufacturerId,							  imageType,							  fileVersion,							  imageSize);



/** @brief The PowerProfileRequest Command is generated by a device supporting the client side of the Power Profile cluster in order to request the Power Profile of a server device.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: PowerProfileRequest
* @param powerProfileId uint8_t

*/
#define sl_zigbee_af_fill_command_power_profile_cluster_power_profile_request( \
  powerProfileId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_POWER_PROFILE_REQUEST_COMMAND_ID, \
                           "u", \
							  powerProfileId);



/** @brief The PowerProfileNotification Command is generated by a device supporting the server side of the Power Profile cluster in order to send the information of the specific parameters (such as Peak power and others) belonging to each phase.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: PowerProfileNotification
* @param totalProfileNum uint8_t

* @param powerProfileId uint8_t

* @param numOfTransferredPhases uint8_t

* @param transferredPhases uint8_t *
* @param transferredPhasesLen uint16_t 
*/
#define sl_zigbee_af_fill_command_power_profile_cluster_power_profile_notification( \
  totalProfileNum,  powerProfileId,  numOfTransferredPhases,  transferredPhases, transferredPhasesLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_POWER_PROFILE_NOTIFICATION_COMMAND_ID, \
                           "uuub", \
							  totalProfileNum,							  powerProfileId,							  numOfTransferredPhases,							  transferredPhases, transferredPhasesLen);



/** @brief The PowerProfileStateRequest Command is generated in order to retrieve the identifiers of current Power Profiles.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: PowerProfileStateRequest
*/
#define sl_zigbee_af_fill_command_power_profile_cluster_power_profile_state_request( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_POWER_PROFILE_STATE_REQUEST_COMMAND_ID, \
                           "" \
);



/** @brief This command is generated by the server side of Power Profile cluster as a reply to the PowerProfileRequest command.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: PowerProfileResponse
* @param totalProfileNum uint8_t

* @param powerProfileId uint8_t

* @param numOfTransferredPhases uint8_t

* @param transferredPhases uint8_t *
* @param transferredPhasesLen uint16_t 
*/
#define sl_zigbee_af_fill_command_power_profile_cluster_power_profile_response( \
  totalProfileNum,  powerProfileId,  numOfTransferredPhases,  transferredPhases, transferredPhasesLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_POWER_PROFILE_RESPONSE_COMMAND_ID, \
                           "uuub", \
							  totalProfileNum,							  powerProfileId,							  numOfTransferredPhases,							  transferredPhases, transferredPhasesLen);



/** @brief The GetPowerProfilePriceResponse command allows a device (client) to communicate the cost associated to the selected Power Profile to another device (server) requesting it.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: GetPowerProfilePriceResponse
* @param powerProfileId uint8_t

* @param currency uint16_t

* @param price uint32_t

* @param priceTrailingDigit uint8_t

*/
#define sl_zigbee_af_fill_command_power_profile_cluster_get_power_profile_price_response( \
  powerProfileId,  currency,  price,  priceTrailingDigit) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_GET_POWER_PROFILE_PRICE_RESPONSE_COMMAND_ID, \
                           "uvwu", \
							  powerProfileId,							  currency,							  price,							  priceTrailingDigit);



/** @brief The PowerProfileStateResponse command allows a device (server) to communicate its current Power Profile(s) to another device (client) that previously requested them.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: PowerProfileStateResponse
* @param powerProfileCount uint8_t

* @param powerProfileRecords uint8_t *
* @param powerProfileRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_power_profile_cluster_power_profile_state_response( \
  powerProfileCount,  powerProfileRecords, powerProfileRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_POWER_PROFILE_STATE_RESPONSE_COMMAND_ID, \
                           "ub", \
							  powerProfileCount,							  powerProfileRecords, powerProfileRecordsLen);



/** @brief The GetOverallSchedulePriceResponse command allows a device (client) to communicate the overall cost associated to all Power Profiles scheduled to another device (server) requesting it.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: GetOverallSchedulePriceResponse
* @param currency uint16_t

* @param price uint32_t

* @param priceTrailingDigit uint8_t

*/
#define sl_zigbee_af_fill_command_power_profile_cluster_get_overall_schedule_price_response( \
  currency,  price,  priceTrailingDigit) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_GET_OVERALL_SCHEDULE_PRICE_RESPONSE_COMMAND_ID, \
                           "vwu", \
							  currency,							  price,							  priceTrailingDigit);



/** @brief The GetPowerProfilePrice Command is generated by the server (e.g. White goods) in order to retrieve the cost associated to a specific Power profile.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: GetPowerProfilePrice
* @param powerProfileId uint8_t

*/
#define sl_zigbee_af_fill_command_power_profile_cluster_get_power_profile_price( \
  powerProfileId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_GET_POWER_PROFILE_PRICE_COMMAND_ID, \
                           "u", \
							  powerProfileId);



/** @brief The EnergyPhasesScheduleNotification Command is generated by a device supporting the client side of the Power Profile cluster in order to schedule the start of the selected Power Profile and its phases.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: EnergyPhasesScheduleNotification
* @param powerProfileId uint8_t

* @param numOfScheduledPhases uint8_t

* @param scheduledPhases uint8_t *
* @param scheduledPhasesLen uint16_t 
*/
#define sl_zigbee_af_fill_command_power_profile_cluster_energy_phases_schedule_notification( \
  powerProfileId,  numOfScheduledPhases,  scheduledPhases, scheduledPhasesLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_ENERGY_PHASES_SCHEDULE_NOTIFICATION_COMMAND_ID, \
                           "uub", \
							  powerProfileId,							  numOfScheduledPhases,							  scheduledPhases, scheduledPhasesLen);



/** @brief The PowerProfileStateNotification Command is generated by the server (e.g. White goods) in order to update the state of the power profile and the current energy phase.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: PowerProfilesStateNotification
* @param powerProfileCount uint8_t

* @param powerProfileRecords uint8_t *
* @param powerProfileRecordsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_power_profile_cluster_power_profiles_state_notification( \
  powerProfileCount,  powerProfileRecords, powerProfileRecordsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_POWER_PROFILES_STATE_NOTIFICATION_COMMAND_ID, \
                           "ub", \
							  powerProfileCount,							  powerProfileRecords, powerProfileRecordsLen);



/** @brief This command is generated by the client side of Power Profile cluster as a reply to the EnergyPhasesScheduleRequest command.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: EnergyPhasesScheduleResponse
* @param powerProfileId uint8_t

* @param numOfScheduledPhases uint8_t

* @param scheduledPhases uint8_t *
* @param scheduledPhasesLen uint16_t 
*/
#define sl_zigbee_af_fill_command_power_profile_cluster_energy_phases_schedule_response( \
  powerProfileId,  numOfScheduledPhases,  scheduledPhases, scheduledPhasesLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_ENERGY_PHASES_SCHEDULE_RESPONSE_COMMAND_ID, \
                           "uub", \
							  powerProfileId,							  numOfScheduledPhases,							  scheduledPhases, scheduledPhasesLen);



/** @brief The GetOverallSchedulePrice Command is generated by the server (e.g. White goods) in order to retrieve the overall cost associated to all the Power Profiles scheduled by the scheduler (the device supporting the Power Profile cluster client side) for the next 24 hours.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: GetOverallSchedulePrice
*/
#define sl_zigbee_af_fill_command_power_profile_cluster_get_overall_schedule_price( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_GET_OVERALL_SCHEDULE_PRICE_COMMAND_ID, \
                           "" \
);



/** @brief The PowerProfileScheduleConstraintsRequest Command is generated by a device supporting the client side of the Power Profile cluster in order to request the constraints -if set- of Power Profile of a client device, in order to set the proper boundaries for the scheduling when calculating the schedules.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: PowerProfileScheduleConstraintsRequest
* @param powerProfileId uint8_t

*/
#define sl_zigbee_af_fill_command_power_profile_cluster_power_profile_schedule_constraints_request( \
  powerProfileId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_POWER_PROFILE_SCHEDULE_CONSTRAINTS_REQUEST_COMMAND_ID, \
                           "u", \
							  powerProfileId);



/** @brief The EnergyPhasesScheduleRequest Command is generated by the server (e.g. White goods) in order to retrieve from the scheduler (e.g. Home Gateway) the schedule (if available) associated to the specific Power Profile carried in the payload.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: EnergyPhasesScheduleRequest
* @param powerProfileId uint8_t

*/
#define sl_zigbee_af_fill_command_power_profile_cluster_energy_phases_schedule_request( \
  powerProfileId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_ENERGY_PHASES_SCHEDULE_REQUEST_COMMAND_ID, \
                           "u", \
							  powerProfileId);



/** @brief The EnergyPhasesScheduleStateRequest  Command is generated by a device supporting the client side of the Power Profile cluster to check the states of the scheduling of a power profile, which is supported in the device implementing the server side of Power Profile cluster.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: EnergyPhasesScheduleStateRequest
* @param powerProfileId uint8_t

*/
#define sl_zigbee_af_fill_command_power_profile_cluster_energy_phases_schedule_state_request( \
  powerProfileId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_ENERGY_PHASES_SCHEDULE_STATE_REQUEST_COMMAND_ID, \
                           "u", \
							  powerProfileId);



/** @brief The EnergyPhasesScheduleStateResponse Command is generated by the server (e.g. White goods) in order to reply to a EnergyPhasesScheduleStateRequest command about the scheduling states that are set in the server side.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: EnergyPhasesScheduleStateResponse
* @param powerProfileId uint8_t

* @param numOfScheduledPhases uint8_t

* @param scheduledPhases uint8_t *
* @param scheduledPhasesLen uint16_t 
*/
#define sl_zigbee_af_fill_command_power_profile_cluster_energy_phases_schedule_state_response( \
  powerProfileId,  numOfScheduledPhases,  scheduledPhases, scheduledPhasesLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_ENERGY_PHASES_SCHEDULE_STATE_RESPONSE_COMMAND_ID, \
                           "uub", \
							  powerProfileId,							  numOfScheduledPhases,							  scheduledPhases, scheduledPhasesLen);



/** @brief The Get Power Profile Price Extended Response command allows a device (client) to communicate the cost associated to all Power Profiles scheduled to another device (server) requesting it according to the specific options contained in the Get Power Profile Price Extended Response.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: GetPowerProfilePriceExtendedResponse
* @param powerProfileId uint8_t

* @param currency uint16_t

* @param price uint32_t

* @param priceTrailingDigit uint8_t

*/
#define sl_zigbee_af_fill_command_power_profile_cluster_get_power_profile_price_extended_response( \
  powerProfileId,  currency,  price,  priceTrailingDigit) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_GET_POWER_PROFILE_PRICE_EXTENDED_RESPONSE_COMMAND_ID, \
                           "uvwu", \
							  powerProfileId,							  currency,							  price,							  priceTrailingDigit);



/** @brief The EnergyPhasesScheduleStateNotification Command is generated by the server (e.g. White goods) in order to notify (un-solicited command) a client side about the scheduling states that are set in the server side.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: EnergyPhasesScheduleStateNotification
* @param powerProfileId uint8_t

* @param numOfScheduledPhases uint8_t

* @param scheduledPhases uint8_t *
* @param scheduledPhasesLen uint16_t 
*/
#define sl_zigbee_af_fill_command_power_profile_cluster_energy_phases_schedule_state_notification( \
  powerProfileId,  numOfScheduledPhases,  scheduledPhases, scheduledPhasesLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_ENERGY_PHASES_SCHEDULE_STATE_NOTIFICATION_COMMAND_ID, \
                           "uub", \
							  powerProfileId,							  numOfScheduledPhases,							  scheduledPhases, scheduledPhasesLen);



/** @brief The PowerProfileScheduleConstraintsNotification Command is generated by a device supporting the server side of the Power Profile cluster to notify the client side of this cluster about the imposed constraints and let the scheduler (i.e. the entity supporting the Power Profile cluster client side) to set the proper boundaries for the scheduling.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: PowerProfileScheduleConstraintsNotification
* @param powerProfileId uint8_t

* @param startAfter uint16_t

* @param stopBefore uint16_t

*/
#define sl_zigbee_af_fill_command_power_profile_cluster_power_profile_schedule_constraints_notification( \
  powerProfileId,  startAfter,  stopBefore) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_POWER_PROFILE_SCHEDULE_CONSTRAINTS_NOTIFICATION_COMMAND_ID, \
                           "uvv", \
							  powerProfileId,							  startAfter,							  stopBefore);



/** @brief The PowerProfileScheduleConstraintsResponse Command is generated by a device supporting the server side of the Power Profile cluster to reply to a client side of this cluster which sent a PowerProfileScheduleConstraintsRequest.
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: PowerProfileScheduleConstraintsResponse
* @param powerProfileId uint8_t

* @param startAfter uint16_t

* @param stopBefore uint16_t

*/
#define sl_zigbee_af_fill_command_power_profile_cluster_power_profile_schedule_constraints_response( \
  powerProfileId,  startAfter,  stopBefore) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_POWER_PROFILE_SCHEDULE_CONSTRAINTS_RESPONSE_COMMAND_ID, \
                           "uvv", \
							  powerProfileId,							  startAfter,							  stopBefore);



/** @brief The Get Power Profile Price Extended command is generated by the server (e.g., White Goods) in order to retrieve the cost associated to a specific Power profile considering specific conditions described in the option field (e.g., a specific time).
* Cluster: Power Profile, This cluster provides an interface for transferring power profile information from a device (e.g. Whitegood) to a controller (e.g. the Home Gateway).  The Power Profile transferred can be solicited by client side (request command) or can be notified directly from the device (server side).
* Command: GetPowerProfilePriceExtended
* @param options uint8_t

* @param powerProfileId uint8_t

* @param powerProfileStartTime uint16_t

*/
#define sl_zigbee_af_fill_command_power_profile_cluster_get_power_profile_price_extended( \
  options,  powerProfileId,  powerProfileStartTime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_POWER_PROFILE_CLUSTER_ID, \
                           ZCL_GET_POWER_PROFILE_PRICE_EXTENDED_COMMAND_ID, \
                           "uuv", \
							  options,							  powerProfileId,							  powerProfileStartTime);



/** @brief This basic message is used to remotely control and to program household appliances.
* Cluster: Appliance Control, This cluster provides an interface to remotely control and to program household appliances.
* Command: ExecutionOfACommand
* @param commandId uint8_t

*/
#define sl_zigbee_af_fill_command_appliance_control_cluster_execution_of_a_command( \
  commandId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_APPLIANCE_CONTROL_CLUSTER_ID, \
                           ZCL_EXECUTION_OF_A_COMMAND_COMMAND_ID, \
                           "u", \
							  commandId);



/** @brief This command shall be used to return household appliance status, according to Appliance Status Values and Remote Enable Flags Values.
* Cluster: Appliance Control, This cluster provides an interface to remotely control and to program household appliances.
* Command: SignalStateResponse
* @param applianceStatus uint8_t

* @param remoteEnableFlagsAndDeviceStatus2 uint8_t

* @param applianceStatus2 uint32_t

*/
#define sl_zigbee_af_fill_command_appliance_control_cluster_signal_state_response( \
  applianceStatus,  remoteEnableFlagsAndDeviceStatus2,  applianceStatus2) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_APPLIANCE_CONTROL_CLUSTER_ID, \
                           ZCL_SIGNAL_STATE_RESPONSE_COMMAND_ID, \
                           "uux", \
							  applianceStatus,							  remoteEnableFlagsAndDeviceStatus2,							  applianceStatus2);



/** @brief This basic message is used to retrieve Household Appliances status.
* Cluster: Appliance Control, This cluster provides an interface to remotely control and to program household appliances.
* Command: SignalState
*/
#define sl_zigbee_af_fill_command_appliance_control_cluster_signal_state( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_APPLIANCE_CONTROL_CLUSTER_ID, \
                           ZCL_SIGNAL_STATE_COMMAND_ID, \
                           "" \
);



/** @brief This command shall be used to return household appliance status, automatically when appliance status changes.
* Cluster: Appliance Control, This cluster provides an interface to remotely control and to program household appliances.
* Command: SignalStateNotification
* @param applianceStatus uint8_t

* @param remoteEnableFlagsAndDeviceStatus2 uint8_t

* @param applianceStatus2 uint32_t

*/
#define sl_zigbee_af_fill_command_appliance_control_cluster_signal_state_notification( \
  applianceStatus,  remoteEnableFlagsAndDeviceStatus2,  applianceStatus2) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_APPLIANCE_CONTROL_CLUSTER_ID, \
                           ZCL_SIGNAL_STATE_NOTIFICATION_COMMAND_ID, \
                           "uux", \
							  applianceStatus,							  remoteEnableFlagsAndDeviceStatus2,							  applianceStatus2);



/** @brief This basic message is used to set appliance functions, i.e. information regarding the execution of an appliance cycle.  Condition parameters such as start time or finish time information could be provided through this command.
* Cluster: Appliance Control, This cluster provides an interface to remotely control and to program household appliances.
* Command: WriteFunctions
* @param functionId uint16_t

* @param functionDataType uint8_t

* @param functionData uint8_t *
* @param functionDataLen uint16_t 
*/
#define sl_zigbee_af_fill_command_appliance_control_cluster_write_functions( \
  functionId,  functionDataType,  functionData, functionDataLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_APPLIANCE_CONTROL_CLUSTER_ID, \
                           ZCL_WRITE_FUNCTIONS_COMMAND_ID, \
                           "vub", \
							  functionId,							  functionDataType,							  functionData, functionDataLen);



/** @brief This command shall be used to resume the normal behavior of a household appliance being in pause mode after receiving a Overload Pause command.
* Cluster: Appliance Control, This cluster provides an interface to remotely control and to program household appliances.
* Command: OverloadPauseResume
*/
#define sl_zigbee_af_fill_command_appliance_control_cluster_overload_pause_resume( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_APPLIANCE_CONTROL_CLUSTER_ID, \
                           ZCL_OVERLOAD_PAUSE_RESUME_COMMAND_ID, \
                           "" \
);



/** @brief This command shall be used to pause the household appliance as a consequence of an imminent overload event.
* Cluster: Appliance Control, This cluster provides an interface to remotely control and to program household appliances.
* Command: OverloadPause
*/
#define sl_zigbee_af_fill_command_appliance_control_cluster_overload_pause( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_APPLIANCE_CONTROL_CLUSTER_ID, \
                           ZCL_OVERLOAD_PAUSE_COMMAND_ID, \
                           "" \
);



/** @brief This basic message is used to send warnings the household appliance as a consequence of a possible overload event, or the notification of the end of the warning state.
* Cluster: Appliance Control, This cluster provides an interface to remotely control and to program household appliances.
* Command: OverloadWarning
* @param warningEvent uint8_t

*/
#define sl_zigbee_af_fill_command_appliance_control_cluster_overload_warning( \
  warningEvent) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_APPLIANCE_CONTROL_CLUSTER_ID, \
                           ZCL_OVERLOAD_WARNING_COMMAND_ID, \
                           "u", \
							  warningEvent);



/** @brief The Poll Control Cluster server sends out a Check-in command to the devices to which it is paired based on the server's Check-in Interval attribute.
* Cluster: Poll Control, This cluster provides a mechanism for the management of an end device's MAC Data Poll rate.  For the purposes of this cluster, the term "poll" always refers to the sending of a MAC Data Poll from the end device to the end device's parent.
* Command: CheckIn
*/
#define sl_zigbee_af_fill_command_poll_control_cluster_check_in( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_POLL_CONTROL_CLUSTER_ID, \
                           ZCL_CHECK_IN_COMMAND_ID, \
                           "" \
);



/** @brief The Check-in Response is sent in response to the receipt of a Check-in command.
* Cluster: Poll Control, This cluster provides a mechanism for the management of an end device's MAC Data Poll rate.  For the purposes of this cluster, the term "poll" always refers to the sending of a MAC Data Poll from the end device to the end device's parent.
* Command: CheckInResponse
* @param startFastPolling uint8_t

* @param fastPollTimeout uint16_t

*/
#define sl_zigbee_af_fill_command_poll_control_cluster_check_in_response( \
  startFastPolling,  fastPollTimeout) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_POLL_CONTROL_CLUSTER_ID, \
                           ZCL_CHECK_IN_RESPONSE_COMMAND_ID, \
                           "uv", \
							  startFastPolling,							  fastPollTimeout);



/** @brief The Fast Poll Stop command is used to stop the fast poll mode initiated by the Check-in response.
* Cluster: Poll Control, This cluster provides a mechanism for the management of an end device's MAC Data Poll rate.  For the purposes of this cluster, the term "poll" always refers to the sending of a MAC Data Poll from the end device to the end device's parent.
* Command: FastPollStop
*/
#define sl_zigbee_af_fill_command_poll_control_cluster_fast_poll_stop( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_POLL_CONTROL_CLUSTER_ID, \
                           ZCL_FAST_POLL_STOP_COMMAND_ID, \
                           "" \
);



/** @brief The Set Long Poll Interval command is used to set the read only Long Poll Interval Attribute.
* Cluster: Poll Control, This cluster provides a mechanism for the management of an end device's MAC Data Poll rate.  For the purposes of this cluster, the term "poll" always refers to the sending of a MAC Data Poll from the end device to the end device's parent.
* Command: SetLongPollInterval
* @param newLongPollInterval uint32_t

*/
#define sl_zigbee_af_fill_command_poll_control_cluster_set_long_poll_interval( \
  newLongPollInterval) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_POLL_CONTROL_CLUSTER_ID, \
                           ZCL_SET_LONG_POLL_INTERVAL_COMMAND_ID, \
                           "w", \
							  newLongPollInterval);



/** @brief The Set Short Poll Interval command is used to set the read only Short Poll Interval Attribute.
* Cluster: Poll Control, This cluster provides a mechanism for the management of an end device's MAC Data Poll rate.  For the purposes of this cluster, the term "poll" always refers to the sending of a MAC Data Poll from the end device to the end device's parent.
* Command: SetShortPollInterval
* @param newShortPollInterval uint16_t

*/
#define sl_zigbee_af_fill_command_poll_control_cluster_set_short_poll_interval( \
  newShortPollInterval) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_POLL_CONTROL_CLUSTER_ID, \
                           ZCL_SET_SHORT_POLL_INTERVAL_COMMAND_ID, \
                           "v", \
							  newShortPollInterval);



/** @brief From GPP to GPS to tunnel GP frame.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpNotification
* @param options uint16_t

* @param gpdSrcId uint32_t

* @param gpdIeee uint8_t *

* @param gpdEndpoint uint8_t

* @param gpdSecurityFrameCounter uint32_t

* @param gpdCommandId uint8_t

* @param gpdCommandPayload uint8_t *

* @param gppShortAddress uint16_t

* @param gppDistance uint8_t

*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_notification( \
  options,  gpdSrcId,  gpdIeee,  gpdEndpoint,  gpdSecurityFrameCounter,  gpdCommandId,  gpdCommandPayload,  gppShortAddress,  gppDistance) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_NOTIFICATION_COMMAND_ID, \
                           "vw8uwusvu", \
							  options,							  gpdSrcId,							  gpdIeee,							  gpdEndpoint,							  gpdSecurityFrameCounter,							  gpdCommandId,							  gpdCommandPayload,							  gppShortAddress,							  gppDistance);



/** @brief From GPS to GPP to acknowledge GP Notification received in unicast mode.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpNotificationResponse
* @param options uint8_t

* @param gpdSrcId uint32_t

* @param gpdIeee uint8_t *

* @param endpoint uint8_t

* @param gpdSecurityFrameCounter uint32_t

*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_notification_response( \
  options,  gpdSrcId,  gpdIeee,  endpoint,  gpdSecurityFrameCounter) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_NOTIFICATION_RESPONSE_COMMAND_ID, \
                           "uw8uw", \
							  options,							  gpdSrcId,							  gpdIeee,							  endpoint,							  gpdSecurityFrameCounter);



/** @brief From GPP to GPSs in entire network to get pairing indication related to GPD for Proxy Table update.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpPairingSearch
* @param options uint16_t

* @param gpdSrcId uint32_t

* @param gpdIeee uint8_t *

* @param endpoint uint8_t

*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_pairing_search( \
  options,  gpdSrcId,  gpdIeee,  endpoint) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_PAIRING_SEARCH_COMMAND_ID, \
                           "vw8u", \
							  options,							  gpdSrcId,							  gpdIeee,							  endpoint);



/** @brief From GPS to the entire network to (de)register for tunneling service, or for removing GPD from the network.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpPairing
* @param options uint32_t

* @param gpdSrcId uint32_t

* @param gpdIeee uint8_t *

* @param endpoint uint8_t

* @param sinkIeeeAddress uint8_t *

* @param sinkNwkAddress uint16_t

* @param sinkGroupId uint16_t

* @param deviceId uint8_t

* @param gpdSecurityFrameCounter uint32_t

* @param gpdKey uint8_t *

* @param assignedAlias uint16_t

* @param groupcastRadius uint8_t

*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_pairing( \
  options,  gpdSrcId,  gpdIeee,  endpoint,  sinkIeeeAddress,  sinkNwkAddress,  sinkGroupId,  deviceId,  gpdSecurityFrameCounter,  gpdKey,  assignedAlias,  groupcastRadius) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_PAIRING_COMMAND_ID, \
                           "xw8u8vvuwGvu", \
							  options,							  gpdSrcId,							  gpdIeee,							  endpoint,							  sinkIeeeAddress,							  sinkNwkAddress,							  sinkGroupId,							  deviceId,							  gpdSecurityFrameCounter,							  gpdKey,							  assignedAlias,							  groupcastRadius);



/** @brief From GPS to GPPs in the whole network to indicate commissioning mode.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpProxyCommissioningMode
* @param options uint8_t

* @param commissioningWindow uint16_t

* @param channel uint8_t

*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_proxy_commissioning_mode( \
  options,  commissioningWindow,  channel) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_PROXY_COMMISSIONING_MODE_COMMAND_ID, \
                           "uvu", \
							  options,							  commissioningWindow,							  channel);



/** @brief From GPP to neighbor GPPs to indicate GP Notification sent in unicast mode.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpTunnelingStop
* @param options uint8_t

* @param gpdSrcId uint32_t

* @param gpdIeee uint8_t *

* @param endpoint uint8_t

* @param gpdSecurityFrameCounter uint32_t

* @param gppShortAddress uint16_t

* @param gppDistance int8_t

*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_tunneling_stop( \
  options,  gpdSrcId,  gpdIeee,  endpoint,  gpdSecurityFrameCounter,  gppShortAddress,  gppDistance) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_TUNNELING_STOP_COMMAND_ID, \
                           "uw8uwvu", \
							  options,							  gpdSrcId,							  gpdIeee,							  endpoint,							  gpdSecurityFrameCounter,							  gppShortAddress,							  gppDistance);



/** @brief From GPP to GPS to tunnel GPD commissioning data.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpCommissioningNotification
* @param options uint16_t

* @param gpdSrcId uint32_t

* @param gpdIeee uint8_t *

* @param endpoint uint8_t

* @param gpdSecurityFrameCounter uint32_t

* @param gpdCommandId uint8_t

* @param gpdCommandPayload uint8_t *

* @param gppShortAddress uint16_t

* @param gppLink uint8_t

* @param mic uint32_t

*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_commissioning_notification( \
  options,  gpdSrcId,  gpdIeee,  endpoint,  gpdSecurityFrameCounter,  gpdCommandId,  gpdCommandPayload,  gppShortAddress,  gppLink,  mic) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_COMMISSIONING_NOTIFICATION_COMMAND_ID, \
                           "vw8uwusvuw", \
							  options,							  gpdSrcId,							  gpdIeee,							  endpoint,							  gpdSecurityFrameCounter,							  gpdCommandId,							  gpdCommandPayload,							  gppShortAddress,							  gppLink,							  mic);



/** @brief To enable commissioning mode of the sink, over the air
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpSinkCommissioningMode
* @param options uint8_t

* @param gpmAddrForSecurity uint16_t

* @param gpmAddrForPairing uint16_t

* @param sinkEndpoint uint8_t

*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_sink_commissioning_mode( \
  options,  gpmAddrForSecurity,  gpmAddrForPairing,  sinkEndpoint) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_SINK_COMMISSIONING_MODE_COMMAND_ID, \
                           "uvvu", \
							  options,							  gpmAddrForSecurity,							  gpmAddrForPairing,							  sinkEndpoint);



/** @brief From GPS to selected GPP, to provide data to be transmitted to Rx-capable GPD.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpResponse
* @param options uint8_t

* @param tempMasterShortAddress uint16_t

* @param tempMasterTxChannel uint8_t

* @param gpdSrcId uint32_t

* @param gpdIeee uint8_t *

* @param endpoint uint8_t

* @param gpdCommandId uint8_t

* @param gpdCommandPayload uint8_t *

*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_response( \
  options,  tempMasterShortAddress,  tempMasterTxChannel,  gpdSrcId,  gpdIeee,  endpoint,  gpdCommandId,  gpdCommandPayload) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_RESPONSE_COMMAND_ID, \
                           "uvuw8uus", \
							  options,							  tempMasterShortAddress,							  tempMasterTxChannel,							  gpdSrcId,							  gpdIeee,							  endpoint,							  gpdCommandId,							  gpdCommandPayload);



/** @brief To configure GPD Command Translation Table.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpTranslationTableUpdate
* @param options uint16_t

* @param gpdSrcId uint32_t

* @param gpdIeee uint8_t *

* @param endpoint uint8_t

* @param translations uint8_t *
* @param translationsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_translation_table_update( \
  options,  gpdSrcId,  gpdIeee,  endpoint,  translations, translationsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_TRANSLATION_TABLE_UPDATE_COMMAND_ID, \
                           "vw8ub", \
							  options,							  gpdSrcId,							  gpdIeee,							  endpoint,							  translations, translationsLen);



/** @brief To provide GPD Command Translation Table content.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpTranslationTableRequest
* @param startIndex uint8_t

*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_translation_table_request( \
  startIndex) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_TRANSLATION_TABLE_REQUEST_COMMAND_ID, \
                           "u", \
							  startIndex);



/** @brief To provide GPD Command Translation Table content.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpTranslationTableResponse
* @param status uint8_t

* @param options uint8_t

* @param totalNumberOfEntries uint8_t

* @param startIndex uint8_t

* @param entriesCount uint8_t

* @param translationTableList uint8_t *
* @param translationTableListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_translation_table_response( \
  status,  options,  totalNumberOfEntries,  startIndex,  entriesCount,  translationTableList, translationTableListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_TRANSLATION_TABLE_RESPONSE_COMMAND_ID, \
                           "uuuuub", \
							  status,							  options,							  totalNumberOfEntries,							  startIndex,							  entriesCount,							  translationTableList, translationTableListLen);



/** @brief To configure Sink Table.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpPairingConfiguration
* @param actions uint8_t

* @param options uint16_t

* @param gpdSrcId uint32_t

* @param gpdIeee uint8_t *

* @param endpoint uint8_t

* @param deviceId uint8_t

* @param groupListCount uint8_t

* @param groupList uint8_t *
* @param groupListLen uint16_t 
* @param gpdAssignedAlias uint16_t

* @param groupcastRadius uint8_t

* @param securityOptions uint8_t

* @param gpdSecurityFrameCounter uint32_t

* @param gpdSecurityKey uint8_t *

* @param numberOfPairedEndpoints uint8_t

* @param pairedEndpoints uint8_t *
* @param pairedEndpointsLen uint16_t 
* @param applicationInformation uint8_t

* @param manufacturerId uint16_t

* @param modeId uint16_t

* @param numberOfGpdCommands uint8_t

* @param gpdCommandIdList uint8_t *
* @param gpdCommandIdListLen uint16_t 
* @param clusterIdListCount uint8_t

* @param clusterListServer uint8_t *
* @param clusterListServerLen uint16_t 
* @param clusterListClient uint8_t *
* @param clusterListClientLen uint16_t 
* @param switchInformationLength uint8_t

* @param switchConfiguration uint8_t

* @param currentContactStatus uint8_t

* @param totalNumberOfReports uint8_t

* @param numberOfReports uint8_t

* @param reportDescriptor uint8_t *
* @param reportDescriptorLen uint16_t 
*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_pairing_configuration( \
  actions,  options,  gpdSrcId,  gpdIeee,  endpoint,  deviceId,  groupListCount,  groupList, groupListLen,  gpdAssignedAlias,  groupcastRadius,  securityOptions,  gpdSecurityFrameCounter,  gpdSecurityKey,  numberOfPairedEndpoints,  pairedEndpoints, pairedEndpointsLen,  applicationInformation,  manufacturerId,  modeId,  numberOfGpdCommands,  gpdCommandIdList, gpdCommandIdListLen,  clusterIdListCount,  clusterListServer, clusterListServerLen,  clusterListClient, clusterListClientLen,  switchInformationLength,  switchConfiguration,  currentContactStatus,  totalNumberOfReports,  numberOfReports,  reportDescriptor, reportDescriptorLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_PAIRING_CONFIGURATION_COMMAND_ID, \
                           "uvw8uuubvuuwGubuvvububbuuuuub", \
							  actions,							  options,							  gpdSrcId,							  gpdIeee,							  endpoint,							  deviceId,							  groupListCount,							  groupList, groupListLen,							  gpdAssignedAlias,							  groupcastRadius,							  securityOptions,							  gpdSecurityFrameCounter,							  gpdSecurityKey,							  numberOfPairedEndpoints,							  pairedEndpoints, pairedEndpointsLen,							  applicationInformation,							  manufacturerId,							  modeId,							  numberOfGpdCommands,							  gpdCommandIdList, gpdCommandIdListLen,							  clusterIdListCount,							  clusterListServer, clusterListServerLen,							  clusterListClient, clusterListClientLen,							  switchInformationLength,							  switchConfiguration,							  currentContactStatus,							  totalNumberOfReports,							  numberOfReports,							  reportDescriptor, reportDescriptorLen);



/** @brief To read out selected Sink Table Entries, by index or by GPD ID.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpSinkTableRequest
* @param options uint8_t

* @param gpdSrcId uint32_t

* @param gpdIeee uint8_t *

* @param endpoint uint8_t

* @param index uint8_t

*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_sink_table_request( \
  options,  gpdSrcId,  gpdIeee,  endpoint,  index) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_SINK_TABLE_REQUEST_COMMAND_ID, \
                           "uw8uu", \
							  options,							  gpdSrcId,							  gpdIeee,							  endpoint,							  index);



/** @brief To selected Proxy Table entries, by index or by GPD ID.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpSinkTableResponse
* @param status uint8_t

* @param totalNumberofNonEmptySinkTableEntries uint8_t

* @param startIndex uint8_t

* @param sinkTableEntriesCount uint8_t

* @param sinkTableEntries uint8_t *
* @param sinkTableEntriesLen uint16_t 
*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_sink_table_response( \
  status,  totalNumberofNonEmptySinkTableEntries,  startIndex,  sinkTableEntriesCount,  sinkTableEntries, sinkTableEntriesLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_SINK_TABLE_RESPONSE_COMMAND_ID, \
                           "uuuub", \
							  status,							  totalNumberofNonEmptySinkTableEntries,							  startIndex,							  sinkTableEntriesCount,							  sinkTableEntries, sinkTableEntriesLen);



/** @brief To reply with read-out Proxy Table entries, by index or by GPD ID.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpProxyTableResponse
* @param status uint8_t

* @param totalNumberOfNonEmptyProxyTableEntries uint8_t

* @param startIndex uint8_t

* @param entriesCount uint8_t

* @param proxyTableEntries uint8_t *
* @param proxyTableEntriesLen uint16_t 
*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_proxy_table_response( \
  status,  totalNumberOfNonEmptyProxyTableEntries,  startIndex,  entriesCount,  proxyTableEntries, proxyTableEntriesLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_PROXY_TABLE_RESPONSE_COMMAND_ID, \
                           "uuuub", \
							  status,							  totalNumberOfNonEmptyProxyTableEntries,							  startIndex,							  entriesCount,							  proxyTableEntries, proxyTableEntriesLen);



/** @brief To request selected Proxy Table entries, by index or by GPD ID.
* Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
* Command: GpProxyTableRequest
* @param options uint8_t

* @param gpdSrcId uint32_t

* @param gpdIeee uint8_t *

* @param endpoint uint8_t

* @param index uint8_t

*/
#define sl_zigbee_af_fill_command_green_power_cluster_gp_proxy_table_request( \
  options,  gpdSrcId,  gpdIeee,  endpoint,  index) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GREEN_POWER_CLUSTER_ID, \
                           ZCL_GP_PROXY_TABLE_REQUEST_COMMAND_ID, \
                           "uw8uu", \
							  options,							  gpdSrcId,							  gpdIeee,							  endpoint,							  index);



/** @brief Configure Zigbee Direct Interface
* Cluster: Zigbee Direct Configuration, Attributes and commands for Zigbee Direct configuration.
* Command: ConfigureInterface
* @param InterfaceState uint8_t

*/
#define sl_zigbee_af_fill_command_zigbee_direct_cluster_configure_interface( \
  InterfaceState) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ZIGBEE_DIRECT_CLUSTER_ID, \
                           ZCL_CONFIGURE_INTERFACE_COMMAND_ID, \
                           "u", \
							  InterfaceState);



/** @brief Configure Zigbee Direct AnonymousJoinTimeout
* Cluster: Zigbee Direct Configuration, Attributes and commands for Zigbee Direct configuration.
* Command: ConfigureAnonymousJoinTimeout
* @param AnonymousJoinTimeout uint32_t

*/
#define sl_zigbee_af_fill_command_zigbee_direct_cluster_configure_anonymous_join_timeout( \
  AnonymousJoinTimeout) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ZIGBEE_DIRECT_CLUSTER_ID, \
                           ZCL_CONFIGURE_ANONYMOUS_JOIN_TIMEOUT_COMMAND_ID, \
                           "x", \
							  AnonymousJoinTimeout);



/** @brief Locks the door
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: LockDoor
* @param PIN uint8_t *

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_lock_door( \
  PIN) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_LOCK_DOOR_COMMAND_ID, \
                           "s", \
							  PIN);



/** @brief Indicates lock success or failure
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: LockDoorResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_lock_door_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_LOCK_DOOR_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Unlocks the door
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: UnlockDoor
* @param PIN uint8_t *

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_unlock_door( \
  PIN) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_UNLOCK_DOOR_COMMAND_ID, \
                           "s", \
							  PIN);



/** @brief Indicates unlock success or failure
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: UnlockDoorResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_unlock_door_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_UNLOCK_DOOR_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Toggles the door lock from its current state to the opposite state locked or unlocked.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: Toggle
* @param pin uint8_t *

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_toggle( \
  pin) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_TOGGLE_COMMAND_ID, \
                           "s", \
							  pin);



/** @brief Response provided to the toggle command, indicates whether the toggle was successful or not.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ToggleResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_toggle_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_TOGGLE_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Unlock the door with a timeout. When the timeout expires, the door will automatically re-lock.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: UnlockWithTimeout
* @param timeoutInSeconds uint16_t

* @param pin uint8_t *

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_unlock_with_timeout( \
  timeoutInSeconds,  pin) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_UNLOCK_WITH_TIMEOUT_COMMAND_ID, \
                           "vs", \
							  timeoutInSeconds,							  pin);



/** @brief Response provided to unlock with specific timeout. This command indicates whether the unlock command was successful or not.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: UnlockWithTimeoutResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_unlock_with_timeout_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_UNLOCK_WITH_TIMEOUT_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Retrieve a log record at a specified index.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetLogRecord
* @param logIndex uint16_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_log_record( \
  logIndex) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_LOG_RECORD_COMMAND_ID, \
                           "v", \
							  logIndex);



/** @brief Returns the specific log record requested.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetLogRecordResponse
* @param logEntryId uint16_t

* @param timestamp uint32_t

* @param eventType uint8_t

* @param source uint8_t

* @param eventIdOrAlarmCode uint8_t

* @param userId uint16_t

* @param pin uint8_t *

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_log_record_response( \
  logEntryId,  timestamp,  eventType,  source,  eventIdOrAlarmCode,  userId,  pin) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_LOG_RECORD_RESPONSE_COMMAND_ID, \
                           "vwuuuvs", \
							  logEntryId,							  timestamp,							  eventType,							  source,							  eventIdOrAlarmCode,							  userId,							  pin);



/** @brief Set the PIN for a specified user id.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetPin
* @param userId uint16_t

* @param userStatus uint8_t

* @param userType uint8_t

* @param pin uint8_t *

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_pin( \
  userId,  userStatus,  userType,  pin) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_PIN_COMMAND_ID, \
                           "vuus", \
							  userId,							  userStatus,							  userType,							  pin);



/** @brief Indicates whether the setting of the PIN was successful or not.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetPinResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_pin_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_PIN_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Retrieve PIN information for a user with a specific user ID.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetPin
* @param userId uint16_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_pin( \
  userId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_PIN_COMMAND_ID, \
                           "v", \
							  userId);



/** @brief Returns the PIN requested according to the user ID passed.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetPinResponse
* @param userId uint16_t

* @param userStatus uint8_t

* @param userType uint8_t

* @param pin uint8_t *

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_pin_response( \
  userId,  userStatus,  userType,  pin) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_PIN_RESPONSE_COMMAND_ID, \
                           "vuus", \
							  userId,							  userStatus,							  userType,							  pin);



/** @brief Clear the PIN for a user with a specific user ID
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearPin
* @param userId uint16_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_pin( \
  userId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_PIN_COMMAND_ID, \
                           "v", \
							  userId);



/** @brief Returns success or failure depending on whether the PIN was cleared or not.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearPinResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_pin_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_PIN_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Clear all PIN codes on the lock for all users.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearAllPins
*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_all_pins( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_ALL_PINS_COMMAND_ID, \
                           "" \
);



/** @brief Returns success or failure depending on whether the PINs were cleared or not.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearAllPinsResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_all_pins_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_ALL_PINS_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Set the status value for a specified user ID.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetUserStatus
* @param userId uint16_t

* @param userStatus uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_user_status( \
  userId,  userStatus) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_USER_STATUS_COMMAND_ID, \
                           "vu", \
							  userId,							  userStatus);



/** @brief Returns success or failure depending on whether the user status was set or not.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetUserStatusResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_user_status_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_USER_STATUS_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Retrieve the status byte for a specific user.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetUserStatus
* @param userId uint16_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_user_status( \
  userId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_USER_STATUS_COMMAND_ID, \
                           "v", \
							  userId);



/** @brief Returns the user status.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetUserStatusResponse
* @param userId uint16_t

* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_user_status_response( \
  userId,  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_USER_STATUS_RESPONSE_COMMAND_ID, \
                           "vu", \
							  userId,							  status);



/** @brief Set the schedule of days during the week that the associated user based on the user ID will have access to the lock and will be able to operate it.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetWeekdaySchedule
* @param scheduleId uint8_t

* @param userId uint16_t

* @param daysMask uint8_t

* @param startHour uint8_t

* @param startMinute uint8_t

* @param endHour uint8_t

* @param endMinute uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_weekday_schedule( \
  scheduleId,  userId,  daysMask,  startHour,  startMinute,  endHour,  endMinute) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_WEEKDAY_SCHEDULE_COMMAND_ID, \
                           "uvuuuuu", \
							  scheduleId,							  userId,							  daysMask,							  startHour,							  startMinute,							  endHour,							  endMinute);



/** @brief Returns the status of setting the weekday schedule
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetWeekdayScheduleResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_weekday_schedule_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_WEEKDAY_SCHEDULE_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Retrieve a weekday schedule for doorlock user activation for a specific schedule id and user id.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetWeekdaySchedule
* @param scheduleId uint8_t

* @param userId uint16_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_weekday_schedule( \
  scheduleId,  userId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_WEEKDAY_SCHEDULE_COMMAND_ID, \
                           "uv", \
							  scheduleId,							  userId);



/** @brief Returns the weekday schedule requested.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetWeekdayScheduleResponse
* @param scheduleId uint8_t

* @param userId uint16_t

* @param status uint8_t

* @param daysMask uint8_t

* @param startHour uint8_t

* @param startMinute uint8_t

* @param endHour uint8_t

* @param endMinute uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_weekday_schedule_response( \
  scheduleId,  userId,  status,  daysMask,  startHour,  startMinute,  endHour,  endMinute) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_WEEKDAY_SCHEDULE_RESPONSE_COMMAND_ID, \
                           "uvuuuuuu", \
							  scheduleId,							  userId,							  status,							  daysMask,							  startHour,							  startMinute,							  endHour,							  endMinute);



/** @brief Clear a weekday schedule for doorlock user activation for a specific schedule id and user id.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearWeekdaySchedule
* @param scheduleId uint8_t

* @param userId uint16_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_weekday_schedule( \
  scheduleId,  userId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_WEEKDAY_SCHEDULE_COMMAND_ID, \
                           "uv", \
							  scheduleId,							  userId);



/** @brief Returns the status of clearing the weekday schedule
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearWeekdayScheduleResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_weekday_schedule_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_WEEKDAY_SCHEDULE_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Set a door lock user id activation schedule according to a specific absolute local start and end time
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetYeardaySchedule
* @param scheduleId uint8_t

* @param userId uint16_t

* @param localStartTime uint32_t

* @param localEndTime uint32_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_yearday_schedule( \
  scheduleId,  userId,  localStartTime,  localEndTime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_YEARDAY_SCHEDULE_COMMAND_ID, \
                           "uvww", \
							  scheduleId,							  userId,							  localStartTime,							  localEndTime);



/** @brief Returns success or failure depending on whether the yearday schedule was set or not.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetYeardayScheduleResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_yearday_schedule_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_YEARDAY_SCHEDULE_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Retrieve a yearday schedule for a specific scheduleId and userId
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetYeardaySchedule
* @param scheduleId uint8_t

* @param userId uint16_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_yearday_schedule( \
  scheduleId,  userId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_YEARDAY_SCHEDULE_COMMAND_ID, \
                           "uv", \
							  scheduleId,							  userId);



/** @brief Returns the yearday schedule requested
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetYeardayScheduleResponse
* @param scheduleId uint8_t

* @param userId uint16_t

* @param status uint8_t

* @param localStartTime uint32_t

* @param localEndTime uint32_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_yearday_schedule_response( \
  scheduleId,  userId,  status,  localStartTime,  localEndTime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_YEARDAY_SCHEDULE_RESPONSE_COMMAND_ID, \
                           "uvuww", \
							  scheduleId,							  userId,							  status,							  localStartTime,							  localEndTime);



/** @brief Clear a yearday schedule for a specific scheduleId and userId
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearYeardaySchedule
* @param scheduleId uint8_t

* @param userId uint16_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_yearday_schedule( \
  scheduleId,  userId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_YEARDAY_SCHEDULE_COMMAND_ID, \
                           "uv", \
							  scheduleId,							  userId);



/** @brief Returns success or failure depending on whether the yearday schedule was removed or not.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearYeardayScheduleResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_yearday_schedule_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_YEARDAY_SCHEDULE_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Set the holiday schedule for a specific user
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetHolidaySchedule
* @param scheduleId uint8_t

* @param localStartTime uint32_t

* @param localEndTime uint32_t

* @param operatingModeDuringHoliday uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_holiday_schedule( \
  scheduleId,  localStartTime,  localEndTime,  operatingModeDuringHoliday) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_HOLIDAY_SCHEDULE_COMMAND_ID, \
                           "uwwu", \
							  scheduleId,							  localStartTime,							  localEndTime,							  operatingModeDuringHoliday);



/** @brief Returns success or failure depending on whether the holiday schedule was set or not.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetHolidayScheduleResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_holiday_schedule_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_HOLIDAY_SCHEDULE_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Retrieve a holiday schedule for a specific scheduleId
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetHolidaySchedule
* @param scheduleId uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_holiday_schedule( \
  scheduleId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_HOLIDAY_SCHEDULE_COMMAND_ID, \
                           "u", \
							  scheduleId);



/** @brief Returns the holiday schedule requested
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetHolidayScheduleResponse
* @param scheduleId uint8_t

* @param status uint8_t

* @param localStartTime uint32_t

* @param localEndTime uint32_t

* @param operatingModeDuringHoliday uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_holiday_schedule_response( \
  scheduleId,  status,  localStartTime,  localEndTime,  operatingModeDuringHoliday) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_HOLIDAY_SCHEDULE_RESPONSE_COMMAND_ID, \
                           "uuwwu", \
							  scheduleId,							  status,							  localStartTime,							  localEndTime,							  operatingModeDuringHoliday);



/** @brief Clear a holiday schedule for a specific scheduleId
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearHolidaySchedule
* @param scheduleId uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_holiday_schedule( \
  scheduleId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_HOLIDAY_SCHEDULE_COMMAND_ID, \
                           "u", \
							  scheduleId);



/** @brief Returns success or failure depending on whether the holiday schedule was removed or not.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearHolidayScheduleResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_holiday_schedule_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_HOLIDAY_SCHEDULE_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Set the type value for a user based on user ID.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetUserType
* @param userId uint16_t

* @param userType uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_user_type( \
  userId,  userType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_USER_TYPE_COMMAND_ID, \
                           "vu", \
							  userId,							  userType);



/** @brief returns success or failure depending on whether the user type was set or not.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetUserTypeResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_user_type_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_USER_TYPE_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Retrieve the type for a specific user based on the user ID.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetUserType
* @param userId uint16_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_user_type( \
  userId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_USER_TYPE_COMMAND_ID, \
                           "v", \
							  userId);



/** @brief Returns the user type for the user ID requested.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetUserTypeResponse
* @param userId uint16_t

* @param userType uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_user_type_response( \
  userId,  userType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_USER_TYPE_RESPONSE_COMMAND_ID, \
                           "vu", \
							  userId,							  userType);



/** @brief Set the PIN for a specified user id.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetRfid
* @param userId uint16_t

* @param userStatus uint8_t

* @param userType uint8_t

* @param id uint8_t *

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_rfid( \
  userId,  userStatus,  userType,  id) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_RFID_COMMAND_ID, \
                           "vuus", \
							  userId,							  userStatus,							  userType,							  id);



/** @brief Indicates whether the setting of the RFID ID was successful or not.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetRfidResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_rfid_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_RFID_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Retrieve RFID ID information for a user with a specific user ID.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetRfid
* @param userId uint16_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_rfid( \
  userId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_RFID_COMMAND_ID, \
                           "v", \
							  userId);



/** @brief Returns the RFID ID requested according to the user ID passed.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetRfidResponse
* @param userId uint16_t

* @param userStatus uint8_t

* @param userType uint8_t

* @param rfid uint8_t *

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_rfid_response( \
  userId,  userStatus,  userType,  rfid) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_RFID_RESPONSE_COMMAND_ID, \
                           "vuus", \
							  userId,							  userStatus,							  userType,							  rfid);



/** @brief Clear the RFID ID for a user with a specific user ID
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearRfid
* @param userId uint16_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_rfid( \
  userId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_RFID_COMMAND_ID, \
                           "v", \
							  userId);



/** @brief Returns success or failure depending on whether the RFID ID was cleared or not.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearRfidResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_rfid_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_RFID_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Clear all RFID ID codes on the lock for all users.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearAllRfids
*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_all_rfids( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_ALL_RFIDS_COMMAND_ID, \
                           "" \
);



/** @brief Returns success or failure depending on whether the RFID IDs were cleared or not.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearAllRfidsResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_all_rfids_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_ALL_RFIDS_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Set the Disposable Schedule by specifying local start time and local end time for the specific user.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetDisposableSchedule
* @param userId uint16_t

* @param localStartTime uint32_t

* @param localEndTime uint32_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_disposable_schedule( \
  userId,  localStartTime,  localEndTime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_DISPOSABLE_SCHEDULE_COMMAND_ID, \
                           "vww", \
							  userId,							  localStartTime,							  localEndTime);



/** @brief Returns pass/fail of the SetDisposableSchedule command
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: SetDisposableScheduleResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_set_disposable_schedule_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_SET_DISPOSABLE_SCHEDULE_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Retrieve the disposable schedule for the specific user.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetDisposableSchedule
* @param userId uint16_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_disposable_schedule( \
  userId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_DISPOSABLE_SCHEDULE_COMMAND_ID, \
                           "v", \
							  userId);



/** @brief Returns the Disposable schedule data for the User ID.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: GetDisposableScheduleResponse
* @param userId uint16_t

* @param status uint8_t

* @param localStartTime uint32_t

* @param localEndTime uint32_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_get_disposable_schedule_response( \
  userId,  status,  localStartTime,  localEndTime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_GET_DISPOSABLE_SCHEDULE_RESPONSE_COMMAND_ID, \
                           "vuww", \
							  userId,							  status,							  localStartTime,							  localEndTime);



/** @brief Clear the Disposable schedule for the specific user
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearDisposableSchedule
* @param userId uint16_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_disposable_schedule( \
  userId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_DISPOSABLE_SCHEDULE_COMMAND_ID, \
                           "v", \
							  userId);



/** @brief Returns pass/fail of the command
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearDisposableScheduleResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_disposable_schedule_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_DISPOSABLE_SCHEDULE_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Clear the Biometric Credential for the specific user
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearBiometricCredential
* @param userId uint16_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_biometric_credential( \
  userId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_BIOMETRIC_CREDENTIAL_COMMAND_ID, \
                           "v", \
							  userId);



/** @brief Returns pass/fail of the command
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearBiometricCredentialResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_biometric_credential_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_BIOMETRIC_CREDENTIAL_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Clear out all Biometric Credentials on the lock
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearAllBiometricCredentials
*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_all_biometric_credentials( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_ALL_BIOMETRIC_CREDENTIALS_COMMAND_ID, \
                           "" \
);



/** @brief Returns pass/fail of the command
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ClearAllBiometricCredentialsResponse
* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_clear_all_biometric_credentials_response( \
  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_CLEAR_ALL_BIOMETRIC_CREDENTIALS_RESPONSE_COMMAND_ID, \
                           "u", \
							  status);



/** @brief Indicates that an operation event has taken place. Includes the associated event information.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: OperationEventNotification
* @param source uint8_t

* @param eventCode uint8_t

* @param userId uint16_t

* @param pin uint8_t *

* @param timeStamp uint32_t

* @param data uint8_t *

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_operation_event_notification( \
  source,  eventCode,  userId,  pin,  timeStamp,  data) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_OPERATION_EVENT_NOTIFICATION_COMMAND_ID, \
                           "uuvsws", \
							  source,							  eventCode,							  userId,							  pin,							  timeStamp,							  data);



/** @brief Indicates that a programming event has taken place. Includes the associated programming event information.
* Cluster: Door Lock, Provides an interface into a generic way to secure a door.
* Command: ProgrammingEventNotification
* @param source uint8_t

* @param eventCode uint8_t

* @param userId uint16_t

* @param pin uint8_t *

* @param userType uint8_t

* @param userStatus uint8_t

* @param timeStamp uint32_t

* @param data uint8_t *

*/
#define sl_zigbee_af_fill_command_door_lock_cluster_programming_event_notification( \
  source,  eventCode,  userId,  pin,  userType,  userStatus,  timeStamp,  data) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DOOR_LOCK_CLUSTER_ID, \
                           ZCL_PROGRAMMING_EVENT_NOTIFICATION_COMMAND_ID, \
                           "uuvsuuws", \
							  source,							  eventCode,							  userId,							  pin,							  userType,							  userStatus,							  timeStamp,							  data);



/** @brief Moves window covering to InstalledOpenLimit - Lift and InstalledOpenLimit - Tilt
* Cluster: Window Covering, Provides an interface for controlling and adjusting automatic window coverings.
* Command: WindowCoveringUpOpen
*/
#define sl_zigbee_af_fill_command_window_covering_cluster_window_covering_up_open( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_WINDOW_COVERING_CLUSTER_ID, \
                           ZCL_WINDOW_COVERING_UP_OPEN_COMMAND_ID, \
                           "" \
);



/** @brief Moves window covering to InstalledClosedLimit - Lift and InstalledCloseLimit - Tilt
* Cluster: Window Covering, Provides an interface for controlling and adjusting automatic window coverings.
* Command: WindowCoveringDownClose
*/
#define sl_zigbee_af_fill_command_window_covering_cluster_window_covering_down_close( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_WINDOW_COVERING_CLUSTER_ID, \
                           ZCL_WINDOW_COVERING_DOWN_CLOSE_COMMAND_ID, \
                           "" \
);



/** @brief Stop any adjusting of window covering
* Cluster: Window Covering, Provides an interface for controlling and adjusting automatic window coverings.
* Command: WindowCoveringStop
*/
#define sl_zigbee_af_fill_command_window_covering_cluster_window_covering_stop( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_WINDOW_COVERING_CLUSTER_ID, \
                           ZCL_WINDOW_COVERING_STOP_COMMAND_ID, \
                           "" \
);



/** @brief Goto lift value specified
* Cluster: Window Covering, Provides an interface for controlling and adjusting automatic window coverings.
* Command: WindowCoveringGoToLiftValue
* @param liftValue uint16_t

*/
#define sl_zigbee_af_fill_command_window_covering_cluster_window_covering_go_to_lift_value( \
  liftValue) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_WINDOW_COVERING_CLUSTER_ID, \
                           ZCL_WINDOW_COVERING_GO_TO_LIFT_VALUE_COMMAND_ID, \
                           "v", \
							  liftValue);



/** @brief Goto lift percentage specified
* Cluster: Window Covering, Provides an interface for controlling and adjusting automatic window coverings.
* Command: WindowCoveringGoToLiftPercentage
* @param percentageLiftValue uint8_t

*/
#define sl_zigbee_af_fill_command_window_covering_cluster_window_covering_go_to_lift_percentage( \
  percentageLiftValue) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_WINDOW_COVERING_CLUSTER_ID, \
                           ZCL_WINDOW_COVERING_GO_TO_LIFT_PERCENTAGE_COMMAND_ID, \
                           "u", \
							  percentageLiftValue);



/** @brief Goto tilt value specified
* Cluster: Window Covering, Provides an interface for controlling and adjusting automatic window coverings.
* Command: WindowCoveringGoToTiltValue
* @param tiltValue uint16_t

*/
#define sl_zigbee_af_fill_command_window_covering_cluster_window_covering_go_to_tilt_value( \
  tiltValue) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_WINDOW_COVERING_CLUSTER_ID, \
                           ZCL_WINDOW_COVERING_GO_TO_TILT_VALUE_COMMAND_ID, \
                           "v", \
							  tiltValue);



/** @brief Goto tilt percentage specified
* Cluster: Window Covering, Provides an interface for controlling and adjusting automatic window coverings.
* Command: WindowCoveringGoToTiltPercentage
* @param percentageTiltValue uint8_t

*/
#define sl_zigbee_af_fill_command_window_covering_cluster_window_covering_go_to_tilt_percentage( \
  percentageTiltValue) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_WINDOW_COVERING_CLUSTER_ID, \
                           ZCL_WINDOW_COVERING_GO_TO_TILT_PERCENTAGE_COMMAND_ID, \
                           "u", \
							  percentageTiltValue);



/** @brief Command to instruct a barrier to go to a percent open state.
* Cluster: Barrier Control, This cluster provides control of a barrier (garage door).
* Command: BarrierControlGoToPercent
* @param percentOpen uint8_t

*/
#define sl_zigbee_af_fill_command_barrier_control_cluster_barrier_control_go_to_percent( \
  percentOpen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_BARRIER_CONTROL_CLUSTER_ID, \
                           ZCL_BARRIER_CONTROL_GO_TO_PERCENT_COMMAND_ID, \
                           "u", \
							  percentOpen);



/** @brief Command that instructs the barrier to stop moving.
* Cluster: Barrier Control, This cluster provides control of a barrier (garage door).
* Command: BarrierControlStop
*/
#define sl_zigbee_af_fill_command_barrier_control_cluster_barrier_control_stop( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_BARRIER_CONTROL_CLUSTER_ID, \
                           ZCL_BARRIER_CONTROL_STOP_COMMAND_ID, \
                           "" \
);



/** @brief Command description for SetpointRaiseLower
* Cluster: Thermostat, An interface for configuring and controlling the functionality of a thermostat.
* Command: SetpointRaiseLower
* @param mode uint8_t

* @param amount int8_t

*/
#define sl_zigbee_af_fill_command_thermostat_cluster_setpoint_raise_lower( \
  mode,  amount) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_THERMOSTAT_CLUSTER_ID, \
                           ZCL_SETPOINT_RAISE_LOWER_COMMAND_ID, \
                           "uu", \
							  mode,							  amount);



/** @brief The Current Weekly Schedule Command is sent from the server in response to the Get Weekly Schedule Command.
* Cluster: Thermostat, An interface for configuring and controlling the functionality of a thermostat.
* Command: CurrentWeeklySchedule
* @param numberOfTransitionsForSequence uint8_t

* @param dayOfWeekForSequence uint8_t

* @param modeForSequence uint8_t

* @param payload uint8_t *
* @param payloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_thermostat_cluster_current_weekly_schedule( \
  numberOfTransitionsForSequence,  dayOfWeekForSequence,  modeForSequence,  payload, payloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_THERMOSTAT_CLUSTER_ID, \
                           ZCL_CURRENT_WEEKLY_SCHEDULE_COMMAND_ID, \
                           "uuub", \
							  numberOfTransitionsForSequence,							  dayOfWeekForSequence,							  modeForSequence,							  payload, payloadLen);



/** @brief Command description for SetWeeklySchedule
* Cluster: Thermostat, An interface for configuring and controlling the functionality of a thermostat.
* Command: SetWeeklySchedule
* @param numberOfTransitionsForSequence uint8_t

* @param dayOfWeekForSequence uint8_t

* @param modeForSequence uint8_t

* @param payload uint8_t *
* @param payloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_thermostat_cluster_set_weekly_schedule( \
  numberOfTransitionsForSequence,  dayOfWeekForSequence,  modeForSequence,  payload, payloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_THERMOSTAT_CLUSTER_ID, \
                           ZCL_SET_WEEKLY_SCHEDULE_COMMAND_ID, \
                           "uuub", \
							  numberOfTransitionsForSequence,							  dayOfWeekForSequence,							  modeForSequence,							  payload, payloadLen);



/** @brief This command is sent from the thermostat cluster server in response to the Get  Relay Status Log.
* Cluster: Thermostat, An interface for configuring and controlling the functionality of a thermostat.
* Command: RelayStatusLog
* @param timeOfDay uint16_t

* @param relayStatus uint16_t

* @param localTemperature int16_t

* @param humidityInPercentage uint8_t

* @param setpoint int16_t

* @param unreadEntries uint16_t

*/
#define sl_zigbee_af_fill_command_thermostat_cluster_relay_status_log( \
  timeOfDay,  relayStatus,  localTemperature,  humidityInPercentage,  setpoint,  unreadEntries) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_THERMOSTAT_CLUSTER_ID, \
                           ZCL_RELAY_STATUS_LOG_COMMAND_ID, \
                           "vvvuvv", \
							  timeOfDay,							  relayStatus,							  localTemperature,							  humidityInPercentage,							  setpoint,							  unreadEntries);



/** @brief Command description for GetWeeklySchedule
* Cluster: Thermostat, An interface for configuring and controlling the functionality of a thermostat.
* Command: GetWeeklySchedule
* @param daysToReturn uint8_t

* @param modeToReturn uint8_t

*/
#define sl_zigbee_af_fill_command_thermostat_cluster_get_weekly_schedule( \
  daysToReturn,  modeToReturn) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_THERMOSTAT_CLUSTER_ID, \
                           ZCL_GET_WEEKLY_SCHEDULE_COMMAND_ID, \
                           "uu", \
							  daysToReturn,							  modeToReturn);



/** @brief The Clear Weekly Schedule command is used to clear the weekly schedule.
* Cluster: Thermostat, An interface for configuring and controlling the functionality of a thermostat.
* Command: ClearWeeklySchedule
*/
#define sl_zigbee_af_fill_command_thermostat_cluster_clear_weekly_schedule( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_THERMOSTAT_CLUSTER_ID, \
                           ZCL_CLEAR_WEEKLY_SCHEDULE_COMMAND_ID, \
                           "" \
);



/** @brief The Get Relay Status Log command is used to query the thermostat internal relay status log.
* Cluster: Thermostat, An interface for configuring and controlling the functionality of a thermostat.
* Command: GetRelayStatusLog
*/
#define sl_zigbee_af_fill_command_thermostat_cluster_get_relay_status_log( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_THERMOSTAT_CLUSTER_ID, \
                           ZCL_GET_RELAY_STATUS_LOG_COMMAND_ID, \
                           "" \
);



/** @brief Move to specified hue.
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: MoveToHue
* @param hue uint8_t

* @param direction uint8_t

* @param transitionTime uint16_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_move_to_hue( \
  hue,  direction,  transitionTime,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_MOVE_TO_HUE_COMMAND_ID, \
                           "uuvuu", \
							  hue,							  direction,							  transitionTime,							  optionsMask,							  optionsOverride);



/** @brief Move hue up or down at specified rate.
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: MoveHue
* @param moveMode uint8_t

* @param rate uint8_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_move_hue( \
  moveMode,  rate,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_MOVE_HUE_COMMAND_ID, \
                           "uuuu", \
							  moveMode,							  rate,							  optionsMask,							  optionsOverride);



/** @brief Step hue up or down by specified size at specified rate.
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: StepHue
* @param stepMode uint8_t

* @param stepSize uint8_t

* @param transitionTime uint8_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_step_hue( \
  stepMode,  stepSize,  transitionTime,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_STEP_HUE_COMMAND_ID, \
                           "uuuuu", \
							  stepMode,							  stepSize,							  transitionTime,							  optionsMask,							  optionsOverride);



/** @brief Move to specified saturation.
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: MoveToSaturation
* @param saturation uint8_t

* @param transitionTime uint16_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_move_to_saturation( \
  saturation,  transitionTime,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_MOVE_TO_SATURATION_COMMAND_ID, \
                           "uvuu", \
							  saturation,							  transitionTime,							  optionsMask,							  optionsOverride);



/** @brief Move saturation up or down at specified rate.
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: MoveSaturation
* @param moveMode uint8_t

* @param rate uint8_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_move_saturation( \
  moveMode,  rate,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_MOVE_SATURATION_COMMAND_ID, \
                           "uuuu", \
							  moveMode,							  rate,							  optionsMask,							  optionsOverride);



/** @brief Step saturation up or down by specified size at specified rate.
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: StepSaturation
* @param stepMode uint8_t

* @param stepSize uint8_t

* @param transitionTime uint8_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_step_saturation( \
  stepMode,  stepSize,  transitionTime,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_STEP_SATURATION_COMMAND_ID, \
                           "uuuuu", \
							  stepMode,							  stepSize,							  transitionTime,							  optionsMask,							  optionsOverride);



/** @brief Move to hue and saturation.
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: MoveToHueAndSaturation
* @param hue uint8_t

* @param saturation uint8_t

* @param transitionTime uint16_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_move_to_hue_and_saturation( \
  hue,  saturation,  transitionTime,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_MOVE_TO_HUE_AND_SATURATION_COMMAND_ID, \
                           "uuvuu", \
							  hue,							  saturation,							  transitionTime,							  optionsMask,							  optionsOverride);



/** @brief Move to specified color.
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: MoveToColor
* @param colorX uint16_t

* @param colorY uint16_t

* @param transitionTime uint16_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_move_to_color( \
  colorX,  colorY,  transitionTime,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_MOVE_TO_COLOR_COMMAND_ID, \
                           "vvvuu", \
							  colorX,							  colorY,							  transitionTime,							  optionsMask,							  optionsOverride);



/** @brief Moves the color.
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: MoveColor
* @param rateX int16_t

* @param rateY int16_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_move_color( \
  rateX,  rateY,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_MOVE_COLOR_COMMAND_ID, \
                           "vvuu", \
							  rateX,							  rateY,							  optionsMask,							  optionsOverride);



/** @brief Steps the lighting to a specific color.
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: StepColor
* @param stepX int16_t

* @param stepY int16_t

* @param transitionTime uint16_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_step_color( \
  stepX,  stepY,  transitionTime,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_STEP_COLOR_COMMAND_ID, \
                           "vvvuu", \
							  stepX,							  stepY,							  transitionTime,							  optionsMask,							  optionsOverride);



/** @brief Move to a specific color temperature.
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: MoveToColorTemperature
* @param colorTemperature uint16_t

* @param transitionTime uint16_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_move_to_color_temperature( \
  colorTemperature,  transitionTime,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_MOVE_TO_COLOR_TEMPERATURE_COMMAND_ID, \
                           "vvuu", \
							  colorTemperature,							  transitionTime,							  optionsMask,							  optionsOverride);



/** @brief Command description for EnhancedMoveToHue
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: EnhancedMoveToHue
* @param enhancedHue uint16_t

* @param direction uint8_t

* @param transitionTime uint16_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_enhanced_move_to_hue( \
  enhancedHue,  direction,  transitionTime,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_ENHANCED_MOVE_TO_HUE_COMMAND_ID, \
                           "vuvuu", \
							  enhancedHue,							  direction,							  transitionTime,							  optionsMask,							  optionsOverride);



/** @brief Command description for EnhancedMoveHue
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: EnhancedMoveHue
* @param moveMode uint8_t

* @param rate uint16_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_enhanced_move_hue( \
  moveMode,  rate,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_ENHANCED_MOVE_HUE_COMMAND_ID, \
                           "uvuu", \
							  moveMode,							  rate,							  optionsMask,							  optionsOverride);



/** @brief Command description for EnhancedStepHue
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: EnhancedStepHue
* @param stepMode uint8_t

* @param stepSize uint16_t

* @param transitionTime uint16_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_enhanced_step_hue( \
  stepMode,  stepSize,  transitionTime,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_ENHANCED_STEP_HUE_COMMAND_ID, \
                           "uvvuu", \
							  stepMode,							  stepSize,							  transitionTime,							  optionsMask,							  optionsOverride);



/** @brief Command description for EnhancedMoveToHueAndSaturation
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: EnhancedMoveToHueAndSaturation
* @param enhancedHue uint16_t

* @param saturation uint8_t

* @param transitionTime uint16_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_enhanced_move_to_hue_and_saturation( \
  enhancedHue,  saturation,  transitionTime,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_ENHANCED_MOVE_TO_HUE_AND_SATURATION_COMMAND_ID, \
                           "vuvuu", \
							  enhancedHue,							  saturation,							  transitionTime,							  optionsMask,							  optionsOverride);



/** @brief Command description for ColorLoopSet
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: ColorLoopSet
* @param updateFlags uint8_t

* @param action uint8_t

* @param direction uint8_t

* @param time uint16_t

* @param startHue uint16_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_color_loop_set( \
  updateFlags,  action,  direction,  time,  startHue,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_COLOR_LOOP_SET_COMMAND_ID, \
                           "uuuvvuu", \
							  updateFlags,							  action,							  direction,							  time,							  startHue,							  optionsMask,							  optionsOverride);



/** @brief Command description for StopMoveStep
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: StopMoveStep
* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_stop_move_step( \
  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_STOP_MOVE_STEP_COMMAND_ID, \
                           "uu", \
							  optionsMask,							  optionsOverride);



/** @brief Command description for MoveColorTemperature
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: MoveColorTemperature
* @param moveMode uint8_t

* @param rate uint16_t

* @param colorTemperatureMinimum uint16_t

* @param colorTemperatureMaximum uint16_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_move_color_temperature( \
  moveMode,  rate,  colorTemperatureMinimum,  colorTemperatureMaximum,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_MOVE_COLOR_TEMPERATURE_COMMAND_ID, \
                           "uvvvuu", \
							  moveMode,							  rate,							  colorTemperatureMinimum,							  colorTemperatureMaximum,							  optionsMask,							  optionsOverride);



/** @brief Command description for StepColorTemperature
* Cluster: Color Control, Attributes and commands for controlling the color properties of a color-capable light.
* Command: StepColorTemperature
* @param stepMode uint8_t

* @param stepSize uint16_t

* @param transitionTime uint16_t

* @param colorTemperatureMinimum uint16_t

* @param colorTemperatureMaximum uint16_t

* @param optionsMask uint8_t

* @param optionsOverride uint8_t

*/
#define sl_zigbee_af_fill_command_color_control_cluster_step_color_temperature( \
  stepMode,  stepSize,  transitionTime,  colorTemperatureMinimum,  colorTemperatureMaximum,  optionsMask,  optionsOverride) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_COLOR_CONTROL_CLUSTER_ID, \
                           ZCL_STEP_COLOR_TEMPERATURE_COMMAND_ID, \
                           "uvvvvuu", \
							  stepMode,							  stepSize,							  transitionTime,							  colorTemperatureMinimum,							  colorTemperatureMaximum,							  optionsMask,							  optionsOverride);



/** @brief Command description for zoneEnrollResponse
* Cluster: IAS Zone, Attributes and commands for IAS security zone devices.
* Command: ZoneEnrollResponse
* @param enrollResponseCode uint8_t

* @param zoneId uint8_t

*/
#define sl_zigbee_af_fill_command_ias_zone_cluster_zone_enroll_response( \
  enrollResponseCode,  zoneId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_ZONE_CLUSTER_ID, \
                           ZCL_ZONE_ENROLL_RESPONSE_COMMAND_ID, \
                           "uu", \
							  enrollResponseCode,							  zoneId);



/** @brief Command description for zoneStatusChangeNotification
* Cluster: IAS Zone, Attributes and commands for IAS security zone devices.
* Command: ZoneStatusChangeNotification
* @param zoneStatus uint16_t

* @param extendedStatus uint8_t

* @param zoneId uint8_t

* @param delay uint16_t

*/
#define sl_zigbee_af_fill_command_ias_zone_cluster_zone_status_change_notification( \
  zoneStatus,  extendedStatus,  zoneId,  delay) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_IAS_ZONE_CLUSTER_ID, \
                           ZCL_ZONE_STATUS_CHANGE_NOTIFICATION_COMMAND_ID, \
                           "vuuv", \
							  zoneStatus,							  extendedStatus,							  zoneId,							  delay);



/** @brief Used to tell the IAS Zone server to commence normal operation mode
* Cluster: IAS Zone, Attributes and commands for IAS security zone devices.
* Command: InitiateNormalOperationMode
*/
#define sl_zigbee_af_fill_command_ias_zone_cluster_initiate_normal_operation_mode( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_ZONE_CLUSTER_ID, \
                           ZCL_INITIATE_NORMAL_OPERATION_MODE_COMMAND_ID, \
                           "" \
);



/** @brief Command description for zoneEnrollRequest
* Cluster: IAS Zone, Attributes and commands for IAS security zone devices.
* Command: ZoneEnrollRequest
* @param zoneType uint16_t

* @param manufacturerCode uint16_t

*/
#define sl_zigbee_af_fill_command_ias_zone_cluster_zone_enroll_request( \
  zoneType,  manufacturerCode) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_IAS_ZONE_CLUSTER_ID, \
                           ZCL_ZONE_ENROLL_REQUEST_COMMAND_ID, \
                           "vv", \
							  zoneType,							  manufacturerCode);



/** @brief Certain IAS Zone servers may have operational configurations that could be configured OTA or locally on the device. This command enables them to be remotely placed into a test mode so that the user or installer may configure their field of view, sensitivity, and other operational parameters.
* Cluster: IAS Zone, Attributes and commands for IAS security zone devices.
* Command: InitiateTestMode
* @param testModeDuration uint8_t

* @param currentZoneSensitivityLevel uint8_t

*/
#define sl_zigbee_af_fill_command_ias_zone_cluster_initiate_test_mode( \
  testModeDuration,  currentZoneSensitivityLevel) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_ZONE_CLUSTER_ID, \
                           ZCL_INITIATE_TEST_MODE_COMMAND_ID, \
                           "uu", \
							  testModeDuration,							  currentZoneSensitivityLevel);



/** @brief Confirms that the IAS Zone server has commenced normal operation mode.
* Cluster: IAS Zone, Attributes and commands for IAS security zone devices.
* Command: InitiateNormalOperationModeResponse
*/
#define sl_zigbee_af_fill_command_ias_zone_cluster_initiate_normal_operation_mode_response( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_IAS_ZONE_CLUSTER_ID, \
                           ZCL_INITIATE_NORMAL_OPERATION_MODE_RESPONSE_COMMAND_ID, \
                           "" \
);



/** @brief Confirms that the IAS Zone server has commenced test mode and that the IAS Zone client should treat any Zone Status Change Notification commands received from the sending IAS Zone server as being in response to test events.
* Cluster: IAS Zone, Attributes and commands for IAS security zone devices.
* Command: InitiateTestModeResponse
*/
#define sl_zigbee_af_fill_command_ias_zone_cluster_initiate_test_mode_response( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_IAS_ZONE_CLUSTER_ID, \
                           ZCL_INITIATE_TEST_MODE_RESPONSE_COMMAND_ID, \
                           "" \
);



/** @brief Command description for Arm
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: Arm
* @param armMode uint8_t

* @param armDisarmCode uint8_t *

* @param zoneId uint8_t

*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_arm( \
  armMode,  armDisarmCode,  zoneId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_ARM_COMMAND_ID, \
                           "usu", \
							  armMode,							  armDisarmCode,							  zoneId);



/** @brief Command description for ArmResponse
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: ArmResponse
* @param armNotification uint8_t

*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_arm_response( \
  armNotification) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_ARM_RESPONSE_COMMAND_ID, \
                           "u", \
							  armNotification);



/** @brief Command description for Bypass
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: Bypass
* @param numberOfZones uint8_t

* @param zoneIds uint8_t *
* @param zoneIdsLen uint16_t 
* @param armDisarmCode uint8_t *

*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_bypass( \
  numberOfZones,  zoneIds, zoneIdsLen,  armDisarmCode) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_BYPASS_COMMAND_ID, \
                           "ubs", \
							  numberOfZones,							  zoneIds, zoneIdsLen,							  armDisarmCode);



/** @brief Command description for GetZoneIdMapResponse
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: GetZoneIdMapResponse
* @param section0 uint16_t

* @param section1 uint16_t

* @param section2 uint16_t

* @param section3 uint16_t

* @param section4 uint16_t

* @param section5 uint16_t

* @param section6 uint16_t

* @param section7 uint16_t

* @param section8 uint16_t

* @param section9 uint16_t

* @param section10 uint16_t

* @param section11 uint16_t

* @param section12 uint16_t

* @param section13 uint16_t

* @param section14 uint16_t

* @param section15 uint16_t

*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_get_zone_id_map_response( \
  section0,  section1,  section2,  section3,  section4,  section5,  section6,  section7,  section8,  section9,  section10,  section11,  section12,  section13,  section14,  section15) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_GET_ZONE_ID_MAP_RESPONSE_COMMAND_ID, \
                           "vvvvvvvvvvvvvvvv", \
							  section0,							  section1,							  section2,							  section3,							  section4,							  section5,							  section6,							  section7,							  section8,							  section9,							  section10,							  section11,							  section12,							  section13,							  section14,							  section15);



/** @brief Command description for Emergency
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: Emergency
*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_emergency( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_EMERGENCY_COMMAND_ID, \
                           "" \
);



/** @brief Command description for GetZoneInformationResponse
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: GetZoneInformationResponse
* @param zoneId uint8_t

* @param zoneType uint16_t

* @param ieeeAddress uint8_t *

* @param zoneLabel uint8_t *

*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_get_zone_information_response( \
  zoneId,  zoneType,  ieeeAddress,  zoneLabel) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_GET_ZONE_INFORMATION_RESPONSE_COMMAND_ID, \
                           "uv8s", \
							  zoneId,							  zoneType,							  ieeeAddress,							  zoneLabel);



/** @brief Command description for Fire
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: Fire
*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_fire( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_FIRE_COMMAND_ID, \
                           "" \
);



/** @brief This command updates ACE clients in the system of changes to zone status recorded by the ACE server (e.g., IAS CIE device).
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: ZoneStatusChanged
* @param zoneId uint8_t

* @param zoneStatus uint16_t

* @param audibleNotification uint8_t

* @param zoneLabel uint8_t *

*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_zone_status_changed( \
  zoneId,  zoneStatus,  audibleNotification,  zoneLabel) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_ZONE_STATUS_CHANGED_COMMAND_ID, \
                           "uvus", \
							  zoneId,							  zoneStatus,							  audibleNotification,							  zoneLabel);



/** @brief Command description for Panic
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: Panic
*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_panic( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_PANIC_COMMAND_ID, \
                           "" \
);



/** @brief This command updates ACE clients in the system of changes to panel status recorded by the ACE server (e.g., IAS CIE device).
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: PanelStatusChanged
* @param panelStatus uint8_t

* @param secondsRemaining uint8_t

* @param audibleNotification uint8_t

* @param alarmStatus uint8_t

*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_panel_status_changed( \
  panelStatus,  secondsRemaining,  audibleNotification,  alarmStatus) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_PANEL_STATUS_CHANGED_COMMAND_ID, \
                           "uuuu", \
							  panelStatus,							  secondsRemaining,							  audibleNotification,							  alarmStatus);



/** @brief Command description for GetZoneIdMap
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: GetZoneIdMap
*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_get_zone_id_map( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_GET_ZONE_ID_MAP_COMMAND_ID, \
                           "" \
);



/** @brief Command updates requesting IAS ACE clients in the system of changes to the security panel status recorded by the ACE server.
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: GetPanelStatusResponse
* @param panelStatus uint8_t

* @param secondsRemaining uint8_t

* @param audibleNotification uint8_t

* @param alarmStatus uint8_t

*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_get_panel_status_response( \
  panelStatus,  secondsRemaining,  audibleNotification,  alarmStatus) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_GET_PANEL_STATUS_RESPONSE_COMMAND_ID, \
                           "uuuu", \
							  panelStatus,							  secondsRemaining,							  audibleNotification,							  alarmStatus);



/** @brief Command description for GetZoneInformation
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: GetZoneInformation
* @param zoneId uint8_t

*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_get_zone_information( \
  zoneId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_GET_ZONE_INFORMATION_COMMAND_ID, \
                           "u", \
							  zoneId);



/** @brief Sets the list of bypassed zones on the IAS ACE client
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: SetBypassedZoneList
* @param numberOfZones uint8_t

* @param zoneIds uint8_t *
* @param zoneIdsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_set_bypassed_zone_list( \
  numberOfZones,  zoneIds, zoneIdsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_SET_BYPASSED_ZONE_LIST_COMMAND_ID, \
                           "ub", \
							  numberOfZones,							  zoneIds, zoneIdsLen);



/** @brief Used by the ACE client to request an update to the status of the ACE server
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: GetPanelStatus
*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_get_panel_status( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_GET_PANEL_STATUS_COMMAND_ID, \
                           "" \
);



/** @brief Provides the response of the security panel to the request from the IAS ACE client to bypass zones via a Bypass command.
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: BypassResponse
* @param numberOfZones uint8_t

* @param bypassResult uint8_t *
* @param bypassResultLen uint16_t 
*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_bypass_response( \
  numberOfZones,  bypassResult, bypassResultLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_BYPASS_RESPONSE_COMMAND_ID, \
                           "ub", \
							  numberOfZones,							  bypassResult, bypassResultLen);



/** @brief Used by the ACE client to retrieve the bypassed zones
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: GetBypassedZoneList
*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_get_bypassed_zone_list( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_GET_BYPASSED_ZONE_LIST_COMMAND_ID, \
                           "" \
);



/** @brief This command updates requesting IAS ACE clients in the system of changes to the IAS Zone server statuses recorded by the ACE server (e.g., IAS CIE device).
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: GetZoneStatusResponse
* @param zoneStatusComplete uint8_t

* @param numberOfZones uint8_t

* @param zoneStatusResult uint8_t *
* @param zoneStatusResultLen uint16_t 
*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_get_zone_status_response( \
  zoneStatusComplete,  numberOfZones,  zoneStatusResult, zoneStatusResultLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_GET_ZONE_STATUS_RESPONSE_COMMAND_ID, \
                           "uub", \
							  zoneStatusComplete,							  numberOfZones,							  zoneStatusResult, zoneStatusResultLen);



/** @brief Used by the ACE client to request an update to the zone status of the ACE server
* Cluster: IAS ACE, Attributes and commands for IAS Ancillary Control Equipment.
* Command: GetZoneStatus
* @param startingZoneId uint8_t

* @param maxNumberOfZoneIds uint8_t

* @param zoneStatusMaskFlag uint8_t

* @param zoneStatusMask uint16_t

*/
#define sl_zigbee_af_fill_command_ias_ace_cluster_get_zone_status( \
  startingZoneId,  maxNumberOfZoneIds,  zoneStatusMaskFlag,  zoneStatusMask) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_ACE_CLUSTER_ID, \
                           ZCL_GET_ZONE_STATUS_COMMAND_ID, \
                           "uuuv", \
							  startingZoneId,							  maxNumberOfZoneIds,							  zoneStatusMaskFlag,							  zoneStatusMask);



/** @brief Command description for StartWarning
* Cluster: IAS WD, Attributes and commands for IAS Warning Devices.
* Command: StartWarning
* @param warningInfo uint8_t

* @param warningDuration uint16_t

* @param strobeDutyCycle uint8_t

* @param strobeLevel uint8_t

*/
#define sl_zigbee_af_fill_command_ias_wd_cluster_start_warning( \
  warningInfo,  warningDuration,  strobeDutyCycle,  strobeLevel) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_WD_CLUSTER_ID, \
                           ZCL_START_WARNING_COMMAND_ID, \
                           "uvuu", \
							  warningInfo,							  warningDuration,							  strobeDutyCycle,							  strobeLevel);



/** @brief Command description for Squawk
* Cluster: IAS WD, Attributes and commands for IAS Warning Devices.
* Command: Squawk
* @param squawkInfo uint8_t

*/
#define sl_zigbee_af_fill_command_ias_wd_cluster_squawk( \
  squawkInfo) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_IAS_WD_CLUSTER_ID, \
                           ZCL_SQUAWK_COMMAND_ID, \
                           "u", \
							  squawkInfo);



/** @brief This command is generated when an application wishes to find the ZigBee address (node, endpoint) of the Generic Tunnel server cluster with a given ProtocolAddress attribute. The command is typically multicast to a group of inter-communicating Generic Tunnel clusters
* Cluster: Generic Tunnel, The minimum common commands and attributes required to tunnel any protocol.
* Command: MatchProtocolAddress
* @param protocolAddress uint8_t *

*/
#define sl_zigbee_af_fill_command_generic_tunnel_cluster_match_protocol_address( \
  protocolAddress) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GENERIC_TUNNEL_CLUSTER_ID, \
                           ZCL_MATCH_PROTOCOL_ADDRESS_COMMAND_ID, \
                           "s", \
							  protocolAddress);



/** @brief This command is generated upon receipt of a Match Protocol Address command to indicate that the Protocol Address was successfully matched.
* Cluster: Generic Tunnel, The minimum common commands and attributes required to tunnel any protocol.
* Command: MatchProtocolAddressResponse
* @param deviceIeeeAddress uint8_t *

* @param protocolAddress uint8_t *

*/
#define sl_zigbee_af_fill_command_generic_tunnel_cluster_match_protocol_address_response( \
  deviceIeeeAddress,  protocolAddress) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GENERIC_TUNNEL_CLUSTER_ID, \
                           ZCL_MATCH_PROTOCOL_ADDRESS_RESPONSE_COMMAND_ID, \
                           "8s", \
							  deviceIeeeAddress,							  protocolAddress);



/** @brief This command is typically sent upon startup, and whenever the ProtocolAddress attribute changes. It is typically multicast to a group of inter-communicating Generic Tunnel clusters.
* Cluster: Generic Tunnel, The minimum common commands and attributes required to tunnel any protocol.
* Command: AdvertiseProtocolAddress
* @param protocolAddress uint8_t *

*/
#define sl_zigbee_af_fill_command_generic_tunnel_cluster_advertise_protocol_address( \
  protocolAddress) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GENERIC_TUNNEL_CLUSTER_ID, \
                           ZCL_ADVERTISE_PROTOCOL_ADDRESS_COMMAND_ID, \
                           "s", \
							  protocolAddress);



/** @brief This command is generated when a BACnet network layer wishes to transfer a BACnet NPDU across a ZigBee tunnel to another BACnet network layer.
* Cluster: BACnet Protocol Tunnel, Commands and attributes required to tunnel the BACnet protocol.
* Command: TransferNpdu
* @param npdu uint8_t *
* @param npduLen uint16_t 
*/
#define sl_zigbee_af_fill_command_bacnet_protocol_tunnel_cluster_transfer_npdu( \
  npdu, npduLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_BACNET_PROTOCOL_TUNNEL_CLUSTER_ID, \
                           ZCL_TRANSFER_NPDU_COMMAND_ID, \
                           "b", \
							  npdu, npduLen);



/** @brief This command is generated when an 11073 network layer wishes to transfer an 11073 APDU across a ZigBee tunnel to another 11073 network layer.
* Cluster: 11073 Protocol Tunnel, Attributes and commands for the 11073 protocol tunnel used for ZigBee Health Care.
* Command: TransferAPDU
* @param apdu uint8_t *

*/
#define sl_zigbee_af_fill_command_11073_protocol_tunnel_cluster_transfer_apdu( \
  apdu) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_11073_PROTOCOL_TUNNEL_CLUSTER_ID, \
                           ZCL_TRANSFER_APDU_COMMAND_ID, \
                           "s", \
							  apdu);



/** @brief This command is generated when an Health Care client wishes to connect to a Health Care server for the purposes of transmitting 11073 APDUs across the 11073 tunnel.
* Cluster: 11073 Protocol Tunnel, Attributes and commands for the 11073 protocol tunnel used for ZigBee Health Care.
* Command: ConnectRequest
* @param connectControl uint8_t

* @param idleTimeout uint16_t

* @param managerTarget uint8_t *

* @param managerEndpoint uint8_t

*/
#define sl_zigbee_af_fill_command_11073_protocol_tunnel_cluster_connect_request( \
  connectControl,  idleTimeout,  managerTarget,  managerEndpoint) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_11073_PROTOCOL_TUNNEL_CLUSTER_ID, \
                           ZCL_CONNECT_REQUEST_COMMAND_ID, \
                           "uv8u", \
							  connectControl,							  idleTimeout,							  managerTarget,							  managerEndpoint);



/** @brief This command is generated when an Health Care client wishes to disconnect from a Health Care server.
* Cluster: 11073 Protocol Tunnel, Attributes and commands for the 11073 protocol tunnel used for ZigBee Health Care.
* Command: DisconnectRequest
* @param managerIEEEAddress uint8_t *

*/
#define sl_zigbee_af_fill_command_11073_protocol_tunnel_cluster_disconnect_request( \
  managerIEEEAddress) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_11073_PROTOCOL_TUNNEL_CLUSTER_ID, \
                           ZCL_DISCONNECT_REQUEST_COMMAND_ID, \
                           "8", \
							  managerIEEEAddress);



/** @brief Generated in response to requests related to connection or any event that causes the tunnel to become disconnected.
* Cluster: 11073 Protocol Tunnel, Attributes and commands for the 11073 protocol tunnel used for ZigBee Health Care.
* Command: ConnectStatusNotification
* @param connectStatus uint8_t

*/
#define sl_zigbee_af_fill_command_11073_protocol_tunnel_cluster_connect_status_notification( \
  connectStatus) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_11073_PROTOCOL_TUNNEL_CLUSTER_ID, \
                           ZCL_CONNECT_STATUS_NOTIFICATION_COMMAND_ID, \
                           "u", \
							  connectStatus);



/** @brief Command description for TransferApdu
* Cluster: ISO 7816 Protocol Tunnel, Commands and attributes for mobile office solutions including ZigBee devices.
* Command: TransferApduFromClient
* @param apdu uint8_t *

*/
#define sl_zigbee_af_fill_command_iso7816_protocol_tunnel_cluster_transfer_apdu_from_client( \
  apdu) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ISO7816_PROTOCOL_TUNNEL_CLUSTER_ID, \
                           ZCL_TRANSFER_APDU_FROM_CLIENT_COMMAND_ID, \
                           "s", \
							  apdu);



/** @brief Command description for TransferApdu
* Cluster: ISO 7816 Protocol Tunnel, Commands and attributes for mobile office solutions including ZigBee devices.
* Command: TransferApduFromServer
* @param apdu uint8_t *

*/
#define sl_zigbee_af_fill_command_iso7816_protocol_tunnel_cluster_transfer_apdu_from_server( \
  apdu) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_ISO7816_PROTOCOL_TUNNEL_CLUSTER_ID, \
                           ZCL_TRANSFER_APDU_FROM_SERVER_COMMAND_ID, \
                           "s", \
							  apdu);



/** @brief Command description for InsertSmartCard
* Cluster: ISO 7816 Protocol Tunnel, Commands and attributes for mobile office solutions including ZigBee devices.
* Command: InsertSmartCard
*/
#define sl_zigbee_af_fill_command_iso7816_protocol_tunnel_cluster_insert_smart_card( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ISO7816_PROTOCOL_TUNNEL_CLUSTER_ID, \
                           ZCL_INSERT_SMART_CARD_COMMAND_ID, \
                           "" \
);



/** @brief Command description for ExtractSmartCard
* Cluster: ISO 7816 Protocol Tunnel, Commands and attributes for mobile office solutions including ZigBee devices.
* Command: ExtractSmartCard
*/
#define sl_zigbee_af_fill_command_iso7816_protocol_tunnel_cluster_extract_smart_card( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ISO7816_PROTOCOL_TUNNEL_CLUSTER_ID, \
                           ZCL_EXTRACT_SMART_CARD_COMMAND_ID, \
                           "" \
);



/** @brief The PublishPrice command is generated in response to receiving a Get Current Price command, in response to a Get Scheduled Prices command, and when an update to the pricing information is available from the commodity provider, either before or when a TOU price becomes active.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PublishPrice
* @param providerId uint32_t

* @param rateLabel uint8_t *

* @param issuerEventId uint32_t

* @param currentTime uint32_t

* @param unitOfMeasure uint8_t

* @param currency uint16_t

* @param priceTrailingDigitAndPriceTier uint8_t

* @param numberOfPriceTiersAndRegisterTier uint8_t

* @param startTime uint32_t

* @param durationInMinutes uint16_t

* @param price uint32_t

* @param priceRatio uint8_t

* @param generationPrice uint32_t

* @param generationPriceRatio uint8_t

* @param alternateCostDelivered uint32_t

* @param alternateCostUnit uint8_t

* @param alternateCostTrailingDigit uint8_t

* @param numberOfBlockThresholds uint8_t

* @param priceControl uint8_t

* @param numberOfGenerationTiers uint8_t

* @param generationTier uint8_t

* @param extendedNumberOfPriceTiers uint8_t

* @param extendedPriceTier uint8_t

* @param extendedRegisterTier uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_publish_price( \
  providerId,  rateLabel,  issuerEventId,  currentTime,  unitOfMeasure,  currency,  priceTrailingDigitAndPriceTier,  numberOfPriceTiersAndRegisterTier,  startTime,  durationInMinutes,  price,  priceRatio,  generationPrice,  generationPriceRatio,  alternateCostDelivered,  alternateCostUnit,  alternateCostTrailingDigit,  numberOfBlockThresholds,  priceControl,  numberOfGenerationTiers,  generationTier,  extendedNumberOfPriceTiers,  extendedPriceTier,  extendedRegisterTier) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PUBLISH_PRICE_COMMAND_ID, \
                           "wswwuvuuwvwuwuwuuuuuuuuu", \
							  providerId,							  rateLabel,							  issuerEventId,							  currentTime,							  unitOfMeasure,							  currency,							  priceTrailingDigitAndPriceTier,							  numberOfPriceTiersAndRegisterTier,							  startTime,							  durationInMinutes,							  price,							  priceRatio,							  generationPrice,							  generationPriceRatio,							  alternateCostDelivered,							  alternateCostUnit,							  alternateCostTrailingDigit,							  numberOfBlockThresholds,							  priceControl,							  numberOfGenerationTiers,							  generationTier,							  extendedNumberOfPriceTiers,							  extendedPriceTier,							  extendedRegisterTier);



/** @brief The GetCurrentPrice command initiates a PublishPrice command for the current time.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetCurrentPrice
* @param commandOptions uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_get_current_price( \
  commandOptions) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_CURRENT_PRICE_COMMAND_ID, \
                           "u", \
							  commandOptions);



/** @brief The PublishBlockPeriod command is generated in response to receiving a GetBlockPeriod(s) command or when an update to the block tariff schedule is available from the commodity provider.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PublishBlockPeriod
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param blockPeriodStartTime uint32_t

* @param blockPeriodDuration uint32_t

* @param blockPeriodControl uint8_t

* @param blockPeriodDurationType uint8_t

* @param tariffType uint8_t

* @param tariffResolutionPeriod uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_publish_block_period( \
  providerId,  issuerEventId,  blockPeriodStartTime,  blockPeriodDuration,  blockPeriodControl,  blockPeriodDurationType,  tariffType,  tariffResolutionPeriod) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PUBLISH_BLOCK_PERIOD_COMMAND_ID, \
                           "wwwxuuuu", \
							  providerId,							  issuerEventId,							  blockPeriodStartTime,							  blockPeriodDuration,							  blockPeriodControl,							  blockPeriodDurationType,							  tariffType,							  tariffResolutionPeriod);



/** @brief The GetScheduledPrices command initiates a PublishPrice command for available price events.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetScheduledPrices
* @param startTime uint32_t

* @param numberOfEvents uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_get_scheduled_prices( \
  startTime,  numberOfEvents) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_SCHEDULED_PRICES_COMMAND_ID, \
                           "wu", \
							  startTime,							  numberOfEvents);



/** @brief The PublishConversionFactor command is sent in response to a GetConversionFactor command or if a new Conversion factor is available.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PublishConversionFactor
* @param issuerEventId uint32_t

* @param startTime uint32_t

* @param conversionFactor uint32_t

* @param conversionFactorTrailingDigit uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_publish_conversion_factor( \
  issuerEventId,  startTime,  conversionFactor,  conversionFactorTrailingDigit) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PUBLISH_CONVERSION_FACTOR_COMMAND_ID, \
                           "wwwu", \
							  issuerEventId,							  startTime,							  conversionFactor,							  conversionFactorTrailingDigit);



/** @brief The PriceAcknowledgement command described provides the ability to acknowledge a previously sent PublishPrice command.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PriceAcknowledgement
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param priceAckTime uint32_t

* @param control uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_price_acknowledgement( \
  providerId,  issuerEventId,  priceAckTime,  control) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PRICE_ACKNOWLEDGEMENT_COMMAND_ID, \
                           "wwwu", \
							  providerId,							  issuerEventId,							  priceAckTime,							  control);



/** @brief The PublishCalorificValue command is sent in response to a GetCalorificValue command or if a new calorific value is available.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PublishCalorificValue
* @param issuerEventId uint32_t

* @param startTime uint32_t

* @param calorificValue uint32_t

* @param calorificValueUnit uint8_t

* @param calorificValueTrailingDigit uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_publish_calorific_value( \
  issuerEventId,  startTime,  calorificValue,  calorificValueUnit,  calorificValueTrailingDigit) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PUBLISH_CALORIFIC_VALUE_COMMAND_ID, \
                           "wwwuu", \
							  issuerEventId,							  startTime,							  calorificValue,							  calorificValueUnit,							  calorificValueTrailingDigit);



/** @brief The GetBlockPeriods command initiates a PublishBlockPeriod command for the currently scheduled block periods.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetBlockPeriods
* @param startTime uint32_t

* @param numberOfEvents uint8_t

* @param tariffType uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_get_block_periods( \
  startTime,  numberOfEvents,  tariffType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_BLOCK_PERIODS_COMMAND_ID, \
                           "wuu", \
							  startTime,							  numberOfEvents,							  tariffType);



/** @brief The PublishTariffInformation command is sent in response to a GetTariffInformation command or if new tariff information is available (including price matrix and block thresholds).
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PublishTariffInformation
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param issuerTariffId uint32_t

* @param startTime uint32_t

* @param tariffTypeChargingScheme uint8_t

* @param tariffLabel uint8_t *

* @param numberOfPriceTiersInUse uint8_t

* @param numberOfBlockThresholdsInUse uint8_t

* @param unitOfMeasure uint8_t

* @param currency uint16_t

* @param priceTrailingDigit uint8_t

* @param standingCharge uint32_t

* @param tierBlockMode uint8_t

* @param blockThresholdMultiplier uint32_t

* @param blockThresholdDivisor uint32_t

*/
#define sl_zigbee_af_fill_command_price_cluster_publish_tariff_information( \
  providerId,  issuerEventId,  issuerTariffId,  startTime,  tariffTypeChargingScheme,  tariffLabel,  numberOfPriceTiersInUse,  numberOfBlockThresholdsInUse,  unitOfMeasure,  currency,  priceTrailingDigit,  standingCharge,  tierBlockMode,  blockThresholdMultiplier,  blockThresholdDivisor) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PUBLISH_TARIFF_INFORMATION_COMMAND_ID, \
                           "wwwwusuuuvuwuxx", \
							  providerId,							  issuerEventId,							  issuerTariffId,							  startTime,							  tariffTypeChargingScheme,							  tariffLabel,							  numberOfPriceTiersInUse,							  numberOfBlockThresholdsInUse,							  unitOfMeasure,							  currency,							  priceTrailingDigit,							  standingCharge,							  tierBlockMode,							  blockThresholdMultiplier,							  blockThresholdDivisor);



/** @brief The GetConversionFactor command initiates a PublishConversionFactor command for the scheduled conversion factor updates.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetConversionFactor
* @param earliestStartTime uint32_t

* @param minIssuerEventId uint32_t

* @param numberOfCommands uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_get_conversion_factor( \
  earliestStartTime,  minIssuerEventId,  numberOfCommands) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_CONVERSION_FACTOR_COMMAND_ID, \
                           "wwu", \
							  earliestStartTime,							  minIssuerEventId,							  numberOfCommands);



/** @brief PublishPriceMatrix command is used to publish the Block Price Information Set (up to 15 tiers x 15 blocks) and the Extended Price Information Set (up to 48 tiers).  The PublishPriceMatrix command is sent in response to a GetPriceMatrix command.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PublishPriceMatrix
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param startTime uint32_t

* @param issuerTariffId uint32_t

* @param commandIndex uint8_t

* @param numberOfCommands uint8_t

* @param subPayloadControl uint8_t

* @param payload uint8_t *
* @param payloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_price_cluster_publish_price_matrix( \
  providerId,  issuerEventId,  startTime,  issuerTariffId,  commandIndex,  numberOfCommands,  subPayloadControl,  payload, payloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PUBLISH_PRICE_MATRIX_COMMAND_ID, \
                           "wwwwuuub", \
							  providerId,							  issuerEventId,							  startTime,							  issuerTariffId,							  commandIndex,							  numberOfCommands,							  subPayloadControl,							  payload, payloadLen);



/** @brief The GetCalorificValue command initiates a PublishCalorificValue command for the scheduled conversion factor updates.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetCalorificValue
* @param earliestStartTime uint32_t

* @param minIssuerEventId uint32_t

* @param numberOfCommands uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_get_calorific_value( \
  earliestStartTime,  minIssuerEventId,  numberOfCommands) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_CALORIFIC_VALUE_COMMAND_ID, \
                           "wwu", \
							  earliestStartTime,							  minIssuerEventId,							  numberOfCommands);



/** @brief The PublishBlockThreshold command is sent in response to a GetBlockThreshold command.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PublishBlockThresholds
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param startTime uint32_t

* @param issuerTariffId uint32_t

* @param commandIndex uint8_t

* @param numberOfCommands uint8_t

* @param subPayloadControl uint8_t

* @param payload uint8_t *
* @param payloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_price_cluster_publish_block_thresholds( \
  providerId,  issuerEventId,  startTime,  issuerTariffId,  commandIndex,  numberOfCommands,  subPayloadControl,  payload, payloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PUBLISH_BLOCK_THRESHOLDS_COMMAND_ID, \
                           "wwwwuuub", \
							  providerId,							  issuerEventId,							  startTime,							  issuerTariffId,							  commandIndex,							  numberOfCommands,							  subPayloadControl,							  payload, payloadLen);



/** @brief The GetTariffInformation command initiates a PublishTariffInformation command for the scheduled tariff updates.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetTariffInformation
* @param earliestStartTime uint32_t

* @param minIssuerEventId uint32_t

* @param numberOfCommands uint8_t

* @param tariffType uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_get_tariff_information( \
  earliestStartTime,  minIssuerEventId,  numberOfCommands,  tariffType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_TARIFF_INFORMATION_COMMAND_ID, \
                           "wwuu", \
							  earliestStartTime,							  minIssuerEventId,							  numberOfCommands,							  tariffType);



/** @brief The PublishCO2Value command is sent in response to a GetCO2Value command or if a new CO2 conversion factor is available.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PublishCO2Value
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param startTime uint32_t

* @param tariffType uint8_t

* @param cO2Value uint32_t

* @param cO2ValueUnit uint8_t

* @param cO2ValueTrailingDigit uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_publish_co2_value( \
  providerId,  issuerEventId,  startTime,  tariffType,  cO2Value,  cO2ValueUnit,  cO2ValueTrailingDigit) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PUBLISH_CO2_VALUE_COMMAND_ID, \
                           "wwwuwuu", \
							  providerId,							  issuerEventId,							  startTime,							  tariffType,							  cO2Value,							  cO2ValueUnit,							  cO2ValueTrailingDigit);



/** @brief The GetPriceMatrix command initiates a PublishPriceMatrix command for the scheduled Price Matrix updates.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetPriceMatrix
* @param issuerTariffId uint32_t

*/
#define sl_zigbee_af_fill_command_price_cluster_get_price_matrix( \
  issuerTariffId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_PRICE_MATRIX_COMMAND_ID, \
                           "w", \
							  issuerTariffId);



/** @brief The PublishTierLabels command is generated in response to receiving a GetTierLabels command or when there is a tier label change.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PublishTierLabels
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param issuerTariffId uint32_t

* @param commandIndex uint8_t

* @param numberOfCommands uint8_t

* @param numberOfLabels uint8_t

* @param tierLabelsPayload uint8_t *
* @param tierLabelsPayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_price_cluster_publish_tier_labels( \
  providerId,  issuerEventId,  issuerTariffId,  commandIndex,  numberOfCommands,  numberOfLabels,  tierLabelsPayload, tierLabelsPayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PUBLISH_TIER_LABELS_COMMAND_ID, \
                           "wwwuuub", \
							  providerId,							  issuerEventId,							  issuerTariffId,							  commandIndex,							  numberOfCommands,							  numberOfLabels,							  tierLabelsPayload, tierLabelsPayloadLen);



/** @brief The GetBlockThresholds command initiates a PublishBlockThreshold command for the scheduled Block Threshold updates.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetBlockThresholds
* @param issuerTariffId uint32_t

*/
#define sl_zigbee_af_fill_command_price_cluster_get_block_thresholds( \
  issuerTariffId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_BLOCK_THRESHOLDS_COMMAND_ID, \
                           "w", \
							  issuerTariffId);



/** @brief The PublishBillingPeriod command is generated in response to receiving a GetBillingPeriod(s) command or when an update to the Billing schedule is available from the commodity Supplier.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PublishBillingPeriod
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param billingPeriodStartTime uint32_t

* @param billingPeriodDuration uint32_t

* @param billingPeriodDurationType uint8_t

* @param tariffType uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_publish_billing_period( \
  providerId,  issuerEventId,  billingPeriodStartTime,  billingPeriodDuration,  billingPeriodDurationType,  tariffType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PUBLISH_BILLING_PERIOD_COMMAND_ID, \
                           "wwwxuu", \
							  providerId,							  issuerEventId,							  billingPeriodStartTime,							  billingPeriodDuration,							  billingPeriodDurationType,							  tariffType);



/** @brief The GetCO2Value command initiates a PublishCO2Value command for the scheduled CO2 conversion factor updates.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetCO2Value
* @param earliestStartTime uint32_t

* @param minIssuerEventId uint32_t

* @param numberOfCommands uint8_t

* @param tariffType uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_get_co2_value( \
  earliestStartTime,  minIssuerEventId,  numberOfCommands,  tariffType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_CO2_VALUE_COMMAND_ID, \
                           "wwuu", \
							  earliestStartTime,							  minIssuerEventId,							  numberOfCommands,							  tariffType);



/** @brief The PublishConsolidatedBill command is used to make consolidated billing information of previous billing periods available to other end devices.  This command is issued in response to a GetConsolidatedBill command or if new billing information is available.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PublishConsolidatedBill
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param billingPeriodStartTime uint32_t

* @param billingPeriodDuration uint32_t

* @param billingPeriodDurationType uint8_t

* @param tariffType uint8_t

* @param consolidatedBill uint32_t

* @param currency uint16_t

* @param billTrailingDigit uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_publish_consolidated_bill( \
  providerId,  issuerEventId,  billingPeriodStartTime,  billingPeriodDuration,  billingPeriodDurationType,  tariffType,  consolidatedBill,  currency,  billTrailingDigit) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PUBLISH_CONSOLIDATED_BILL_COMMAND_ID, \
                           "wwwxuuwvu", \
							  providerId,							  issuerEventId,							  billingPeriodStartTime,							  billingPeriodDuration,							  billingPeriodDurationType,							  tariffType,							  consolidatedBill,							  currency,							  billTrailingDigit);



/** @brief The GetTierLabels command allows a client to retrieve the tier labels associated with a given tariff; this command initiates a PublishTierLabels command from the server.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetTierLabels
* @param issuerTariffId uint32_t

*/
#define sl_zigbee_af_fill_command_price_cluster_get_tier_labels( \
  issuerTariffId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_TIER_LABELS_COMMAND_ID, \
                           "w", \
							  issuerTariffId);



/** @brief The PublishCPPEvent command is sent from an ESI to its price clients to notify them of a Critical Peak Pricing event.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PublishCppEvent
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param startTime uint32_t

* @param durationInMinutes uint16_t

* @param tariffType uint8_t

* @param cppPriceTier uint8_t

* @param cppAuth uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_publish_cpp_event( \
  providerId,  issuerEventId,  startTime,  durationInMinutes,  tariffType,  cppPriceTier,  cppAuth) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PUBLISH_CPP_EVENT_COMMAND_ID, \
                           "wwwvuuu", \
							  providerId,							  issuerEventId,							  startTime,							  durationInMinutes,							  tariffType,							  cppPriceTier,							  cppAuth);



/** @brief The GetBillingPeriod command initiates one or more PublishBillingPeriod commands for the currently scheduled billing periods.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetBillingPeriod
* @param earliestStartTime uint32_t

* @param minIssuerEventId uint32_t

* @param numberOfCommands uint8_t

* @param tariffType uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_get_billing_period( \
  earliestStartTime,  minIssuerEventId,  numberOfCommands,  tariffType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_BILLING_PERIOD_COMMAND_ID, \
                           "wwuu", \
							  earliestStartTime,							  minIssuerEventId,							  numberOfCommands,							  tariffType);



/** @brief The PublishCreditPayment command is used to update the credit payment information is available.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PublishCreditPayment
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param creditPaymentDueDate uint32_t

* @param creditPaymentOverDueAmount uint32_t

* @param creditPaymentStatus uint8_t

* @param creditPayment uint32_t

* @param creditPaymentDate uint32_t

* @param creditPaymentRef uint8_t *

*/
#define sl_zigbee_af_fill_command_price_cluster_publish_credit_payment( \
  providerId,  issuerEventId,  creditPaymentDueDate,  creditPaymentOverDueAmount,  creditPaymentStatus,  creditPayment,  creditPaymentDate,  creditPaymentRef) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PUBLISH_CREDIT_PAYMENT_COMMAND_ID, \
                           "wwwwuwws", \
							  providerId,							  issuerEventId,							  creditPaymentDueDate,							  creditPaymentOverDueAmount,							  creditPaymentStatus,							  creditPayment,							  creditPaymentDate,							  creditPaymentRef);



/** @brief The GetConsolidatedBill command initiates one or more PublishConsolidatedBill commands with the requested billing information.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetConsolidatedBill
* @param earliestStartTime uint32_t

* @param minIssuerEventId uint32_t

* @param numberOfCommands uint8_t

* @param tariffType uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_get_consolidated_bill( \
  earliestStartTime,  minIssuerEventId,  numberOfCommands,  tariffType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_CONSOLIDATED_BILL_COMMAND_ID, \
                           "wwuu", \
							  earliestStartTime,							  minIssuerEventId,							  numberOfCommands,							  tariffType);



/** @brief The PublishCurrencyConversion command is sent in response to a GetCurrencyConversion command or when a new currency becomes available.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: PublishCurrencyConversion
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param startTime uint32_t

* @param oldCurrency uint16_t

* @param newCurrency uint16_t

* @param conversionFactor uint32_t

* @param conversionFactorTrailingDigit uint8_t

* @param currencyChangeControlFlags uint32_t

*/
#define sl_zigbee_af_fill_command_price_cluster_publish_currency_conversion( \
  providerId,  issuerEventId,  startTime,  oldCurrency,  newCurrency,  conversionFactor,  conversionFactorTrailingDigit,  currencyChangeControlFlags) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_PUBLISH_CURRENCY_CONVERSION_COMMAND_ID, \
                           "wwwvvwuw", \
							  providerId,							  issuerEventId,							  startTime,							  oldCurrency,							  newCurrency,							  conversionFactor,							  conversionFactorTrailingDigit,							  currencyChangeControlFlags);



/** @brief The CPPEventResponse command is sent from a Client (IHD) to the ESI to notify it of a Critical Peak Pricing event authorization.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: CppEventResponse
* @param issuerEventId uint32_t

* @param cppAuth uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_cpp_event_response( \
  issuerEventId,  cppAuth) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_CPP_EVENT_RESPONSE_COMMAND_ID, \
                           "wu", \
							  issuerEventId,							  cppAuth);



/** @brief The CancelTariff command indicates that all data associated with a particular tariff instance should be discarded.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: CancelTariff
* @param providerId uint32_t

* @param issuerTariffId uint32_t

* @param tariffType uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_cancel_tariff( \
  providerId,  issuerTariffId,  tariffType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_CANCEL_TARIFF_COMMAND_ID, \
                           "wwu", \
							  providerId,							  issuerTariffId,							  tariffType);



/** @brief The GetCreditPayment command initiates PublishCreditPayment commands for the requested credit payment information.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetCreditPayment
* @param latestEndTime uint32_t

* @param numberOfRecords uint8_t

*/
#define sl_zigbee_af_fill_command_price_cluster_get_credit_payment( \
  latestEndTime,  numberOfRecords) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_CREDIT_PAYMENT_COMMAND_ID, \
                           "wu", \
							  latestEndTime,							  numberOfRecords);



/** @brief The GetCurrencyConversionCommand command initiates a PublishCurrencyConversion command for the currency conversion factor updates. A server shall be capable of storing both the old and the new currencies.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetCurrencyConversionCommand
*/
#define sl_zigbee_af_fill_command_price_cluster_get_currency_conversion_command( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_CURRENCY_CONVERSION_COMMAND_COMMAND_ID, \
                           "" \
);



/** @brief The GetTariffCancellation command initiates the return of the last CancelTariff command held on the associated server.
* Cluster: Price, The Price Cluster provides the mechanism for communicating Gas, Energy, or Water pricing information within the premises.
* Command: GetTariffCancellation
*/
#define sl_zigbee_af_fill_command_price_cluster_get_tariff_cancellation( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PRICE_CLUSTER_ID, \
                           ZCL_GET_TARIFF_CANCELLATION_COMMAND_ID, \
                           "" \
);



/** @brief Command description for LoadControlEvent
* Cluster: Demand Response and Load Control, This cluster provides an interface to the functionality of Smart Energy Demand Response and Load Control. Devices targeted by this cluster include thermostats and devices that support load control.
* Command: LoadControlEvent
* @param issuerEventId uint32_t

* @param deviceClass uint16_t

* @param utilityEnrollmentGroup uint8_t

* @param startTime uint32_t

* @param durationInMinutes uint16_t

* @param criticalityLevel uint8_t

* @param coolingTemperatureOffset uint8_t

* @param heatingTemperatureOffset uint8_t

* @param coolingTemperatureSetPoint int16_t

* @param heatingTemperatureSetPoint int16_t

* @param averageLoadAdjustmentPercentage int8_t

* @param dutyCycle uint8_t

* @param eventControl uint8_t

*/
#define sl_zigbee_af_fill_command_demand_response_load_control_cluster_load_control_event( \
  issuerEventId,  deviceClass,  utilityEnrollmentGroup,  startTime,  durationInMinutes,  criticalityLevel,  coolingTemperatureOffset,  heatingTemperatureOffset,  coolingTemperatureSetPoint,  heatingTemperatureSetPoint,  averageLoadAdjustmentPercentage,  dutyCycle,  eventControl) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DEMAND_RESPONSE_LOAD_CONTROL_CLUSTER_ID, \
                           ZCL_LOAD_CONTROL_EVENT_COMMAND_ID, \
                           "wvuwvuuuvvuuu", \
							  issuerEventId,							  deviceClass,							  utilityEnrollmentGroup,							  startTime,							  durationInMinutes,							  criticalityLevel,							  coolingTemperatureOffset,							  heatingTemperatureOffset,							  coolingTemperatureSetPoint,							  heatingTemperatureSetPoint,							  averageLoadAdjustmentPercentage,							  dutyCycle,							  eventControl);



/** @brief Command description for ReportEventStatus
* Cluster: Demand Response and Load Control, This cluster provides an interface to the functionality of Smart Energy Demand Response and Load Control. Devices targeted by this cluster include thermostats and devices that support load control.
* Command: ReportEventStatus
* @param issuerEventId uint32_t

* @param eventStatus uint8_t

* @param eventStatusTime uint32_t

* @param criticalityLevelApplied uint8_t

* @param coolingTemperatureSetPointApplied uint16_t

* @param heatingTemperatureSetPointApplied uint16_t

* @param averageLoadAdjustmentPercentageApplied int8_t

* @param dutyCycleApplied uint8_t

* @param eventControl uint8_t

* @param signatureType uint8_t

* @param signature Signature

*/
#define sl_zigbee_af_fill_command_demand_response_load_control_cluster_report_event_status( \
  issuerEventId,  eventStatus,  eventStatusTime,  criticalityLevelApplied,  coolingTemperatureSetPointApplied,  heatingTemperatureSetPointApplied,  averageLoadAdjustmentPercentageApplied,  dutyCycleApplied,  eventControl,  signatureType,  signature) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DEMAND_RESPONSE_LOAD_CONTROL_CLUSTER_ID, \
                           ZCL_REPORT_EVENT_STATUS_COMMAND_ID, \
                           "wuwuvvuuuub", \
							  issuerEventId,							  eventStatus,							  eventStatusTime,							  criticalityLevelApplied,							  coolingTemperatureSetPointApplied,							  heatingTemperatureSetPointApplied,							  averageLoadAdjustmentPercentageApplied,							  dutyCycleApplied,							  eventControl,							  signatureType,							  signature);



/** @brief Command description for CancelLoadControlEvent
* Cluster: Demand Response and Load Control, This cluster provides an interface to the functionality of Smart Energy Demand Response and Load Control. Devices targeted by this cluster include thermostats and devices that support load control.
* Command: CancelLoadControlEvent
* @param issuerEventId uint32_t

* @param deviceClass uint16_t

* @param utilityEnrollmentGroup uint8_t

* @param cancelControl uint8_t

* @param effectiveTime uint32_t

*/
#define sl_zigbee_af_fill_command_demand_response_load_control_cluster_cancel_load_control_event( \
  issuerEventId,  deviceClass,  utilityEnrollmentGroup,  cancelControl,  effectiveTime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DEMAND_RESPONSE_LOAD_CONTROL_CLUSTER_ID, \
                           ZCL_CANCEL_LOAD_CONTROL_EVENT_COMMAND_ID, \
                           "wvuuw", \
							  issuerEventId,							  deviceClass,							  utilityEnrollmentGroup,							  cancelControl,							  effectiveTime);



/** @brief Command description for GetScheduledEvents
* Cluster: Demand Response and Load Control, This cluster provides an interface to the functionality of Smart Energy Demand Response and Load Control. Devices targeted by this cluster include thermostats and devices that support load control.
* Command: GetScheduledEvents
* @param startTime uint32_t

* @param numberOfEvents uint8_t

* @param issuerEventId uint32_t

*/
#define sl_zigbee_af_fill_command_demand_response_load_control_cluster_get_scheduled_events( \
  startTime,  numberOfEvents,  issuerEventId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DEMAND_RESPONSE_LOAD_CONTROL_CLUSTER_ID, \
                           ZCL_GET_SCHEDULED_EVENTS_COMMAND_ID, \
                           "wuw", \
							  startTime,							  numberOfEvents,							  issuerEventId);



/** @brief Command description for CancelAllLoadControlEvents
* Cluster: Demand Response and Load Control, This cluster provides an interface to the functionality of Smart Energy Demand Response and Load Control. Devices targeted by this cluster include thermostats and devices that support load control.
* Command: CancelAllLoadControlEvents
* @param cancelControl uint8_t

*/
#define sl_zigbee_af_fill_command_demand_response_load_control_cluster_cancel_all_load_control_events( \
  cancelControl) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DEMAND_RESPONSE_LOAD_CONTROL_CLUSTER_ID, \
                           ZCL_CANCEL_ALL_LOAD_CONTROL_EVENTS_COMMAND_ID, \
                           "u", \
							  cancelControl);



/** @brief This command is generated when the Client command GetProfile is received.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: GetProfileResponse
* @param endTime uint32_t

* @param status uint8_t

* @param profileIntervalPeriod uint8_t

* @param numberOfPeriodsDelivered uint8_t

* @param intervals uint8_t *
* @param intervalsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_get_profile_response( \
  endTime,  status,  profileIntervalPeriod,  numberOfPeriodsDelivered,  intervals, intervalsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_GET_PROFILE_RESPONSE_COMMAND_ID, \
                           "wuuub", \
							  endTime,							  status,							  profileIntervalPeriod,							  numberOfPeriodsDelivered,							  intervals, intervalsLen);



/** @brief The GetProfile command is generated when a client device wishes to retrieve a list of captured Energy, Gas or water consumption for profiling purposes.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: GetProfile
* @param intervalChannel uint8_t

* @param endTime uint32_t

* @param numberOfPeriods uint8_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_get_profile( \
  intervalChannel,  endTime,  numberOfPeriods) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_GET_PROFILE_COMMAND_ID, \
                           "uwu", \
							  intervalChannel,							  endTime,							  numberOfPeriods);



/** @brief This command is used to request the ESI to mirror Metering Device data.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: RequestMirror
*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_request_mirror( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_REQUEST_MIRROR_COMMAND_ID, \
                           "" \
);



/** @brief The Request Mirror Response Command allows the ESI to inform a sleepy Metering Device it has the ability to store and mirror its data.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: RequestMirrorResponse
* @param endpointId uint16_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_request_mirror_response( \
  endpointId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_REQUEST_MIRROR_RESPONSE_COMMAND_ID, \
                           "v", \
							  endpointId);



/** @brief This command is used to request the ESI to remove its mirror of Metering Device data.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: RemoveMirror
*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_remove_mirror( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_REMOVE_MIRROR_COMMAND_ID, \
                           "" \
);



/** @brief The Mirror Removed Command allows the ESI to inform a sleepy Metering Device mirroring support has been removed or halted.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: MirrorRemoved
* @param endpointId uint16_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_mirror_removed( \
  endpointId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_MIRROR_REMOVED_COMMAND_ID, \
                           "v", \
							  endpointId);



/** @brief This command is generated when the client command Request Fast Poll Mode is received.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: RequestFastPollModeResponse
* @param appliedUpdatePeriod uint8_t

* @param fastPollModeEndtime uint32_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_request_fast_poll_mode_response( \
  appliedUpdatePeriod,  fastPollModeEndtime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_REQUEST_FAST_POLL_MODE_RESPONSE_COMMAND_ID, \
                           "uw", \
							  appliedUpdatePeriod,							  fastPollModeEndtime);



/** @brief The Request Fast Poll Mode command is generated when the metering client wishes to receive near real-time updates of InstantaneousDemand.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: RequestFastPollMode
* @param fastPollUpdatePeriod uint8_t

* @param duration uint8_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_request_fast_poll_mode( \
  fastPollUpdatePeriod,  duration) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_REQUEST_FAST_POLL_MODE_COMMAND_ID, \
                           "uu", \
							  fastPollUpdatePeriod,							  duration);



/** @brief This command is generated in response to a ScheduleSnapshot command, and is sent to confirm whether the requested snapshot schedule has been set up.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: ScheduleSnapshotResponse
* @param issuerEventId uint32_t

* @param snapshotResponsePayload uint8_t *
* @param snapshotResponsePayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_schedule_snapshot_response( \
  issuerEventId,  snapshotResponsePayload, snapshotResponsePayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_SCHEDULE_SNAPSHOT_RESPONSE_COMMAND_ID, \
                           "wb", \
							  issuerEventId,							  snapshotResponsePayload, snapshotResponsePayloadLen);



/** @brief This command is used to set up a schedule of when the device shall create snapshot data.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: ScheduleSnapshot
* @param issuerEventId uint32_t

* @param commandIndex uint8_t

* @param commandCount uint8_t

* @param snapshotSchedulePayload uint8_t *
* @param snapshotSchedulePayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_schedule_snapshot( \
  issuerEventId,  commandIndex,  commandCount,  snapshotSchedulePayload, snapshotSchedulePayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_SCHEDULE_SNAPSHOT_COMMAND_ID, \
                           "wuub", \
							  issuerEventId,							  commandIndex,							  commandCount,							  snapshotSchedulePayload, snapshotSchedulePayloadLen);



/** @brief This command is generated in response to a TakeSnapshot command, and is sent to confirm whether the requested snapshot has been accepted and successfully taken.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: TakeSnapshotResponse
* @param snapshotId uint32_t

* @param snapshotConfirmation uint8_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_take_snapshot_response( \
  snapshotId,  snapshotConfirmation) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_TAKE_SNAPSHOT_RESPONSE_COMMAND_ID, \
                           "wu", \
							  snapshotId,							  snapshotConfirmation);



/** @brief This command is used to instruct the cluster server to take a single snapshot.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: TakeSnapshot
* @param snapshotCause uint32_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_take_snapshot( \
  snapshotCause) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_TAKE_SNAPSHOT_COMMAND_ID, \
                           "w", \
							  snapshotCause);



/** @brief This command is generated in response to a GetSnapshot command. It is used to return a single snapshot to the client.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: PublishSnapshot
* @param snapshotId uint32_t

* @param snapshotTime uint32_t

* @param totalSnapshotsFound uint8_t

* @param commandIndex uint8_t

* @param totalCommands uint8_t

* @param snapshotCause uint32_t

* @param snapshotPayloadType uint8_t

* @param snapshotPayload uint8_t *
* @param snapshotPayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_publish_snapshot( \
  snapshotId,  snapshotTime,  totalSnapshotsFound,  commandIndex,  totalCommands,  snapshotCause,  snapshotPayloadType,  snapshotPayload, snapshotPayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_PUBLISH_SNAPSHOT_COMMAND_ID, \
                           "wwuuuwub", \
							  snapshotId,							  snapshotTime,							  totalSnapshotsFound,							  commandIndex,							  totalCommands,							  snapshotCause,							  snapshotPayloadType,							  snapshotPayload, snapshotPayloadLen);



/** @brief This command is used to request snapshot data from the cluster server.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: GetSnapshot
* @param earliestStartTime uint32_t

* @param latestEndTime uint32_t

* @param snapshotOffset uint8_t

* @param snapshotCause uint32_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_get_snapshot( \
  earliestStartTime,  latestEndTime,  snapshotOffset,  snapshotCause) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_GET_SNAPSHOT_COMMAND_ID, \
                           "wwuw", \
							  earliestStartTime,							  latestEndTime,							  snapshotOffset,							  snapshotCause);



/** @brief This command is used to send the requested sample data to the client. It is generated in response to a GetSampledData command.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: GetSampledDataResponse
* @param sampleId uint16_t

* @param sampleStartTime uint32_t

* @param sampleType uint8_t

* @param sampleRequestInterval uint16_t

* @param numberOfSamples uint16_t

* @param samples uint8_t *
* @param samplesLen uint16_t 
*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_get_sampled_data_response( \
  sampleId,  sampleStartTime,  sampleType,  sampleRequestInterval,  numberOfSamples,  samples, samplesLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_GET_SAMPLED_DATA_RESPONSE_COMMAND_ID, \
                           "vwuvvb", \
							  sampleId,							  sampleStartTime,							  sampleType,							  sampleRequestInterval,							  numberOfSamples,							  samples, samplesLen);



/** @brief The sampling mechanism allows a set of samples of the specified type of data to be taken, commencing at the stipulated start time. This mechanism may run concurrently with the capturing of profile data, and may refer the same parameters, albeit possibly at a different sampling rate.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: StartSampling
* @param issuerEventId uint32_t

* @param startSamplingTime uint32_t

* @param sampleType uint8_t

* @param sampleRequestInterval uint16_t

* @param maxNumberOfSamples uint16_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_start_sampling( \
  issuerEventId,  startSamplingTime,  sampleType,  sampleRequestInterval,  maxNumberOfSamples) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_START_SAMPLING_COMMAND_ID, \
                           "wwuvv", \
							  issuerEventId,							  startSamplingTime,							  sampleType,							  sampleRequestInterval,							  maxNumberOfSamples);



/** @brief ConfigureMirror is sent to the mirror once the mirror has been created. The command deals with the operational configuration of the Mirror.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: ConfigureMirror
* @param issuerEventId uint32_t

* @param reportingInterval uint32_t

* @param mirrorNotificationReporting uint8_t

* @param notificationScheme uint8_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_configure_mirror( \
  issuerEventId,  reportingInterval,  mirrorNotificationReporting,  notificationScheme) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_CONFIGURE_MIRROR_COMMAND_ID, \
                           "wxuu", \
							  issuerEventId,							  reportingInterval,							  mirrorNotificationReporting,							  notificationScheme);



/** @brief This command is used to request sampled data from the server. Note that it is the responsibility of the client to ensure that it does not request more samples than can be held in a single command payload.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: GetSampledData
* @param sampleId uint16_t

* @param earliestSampleTime uint32_t

* @param sampleType uint8_t

* @param numberOfSamples uint16_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_get_sampled_data( \
  sampleId,  earliestSampleTime,  sampleType,  numberOfSamples) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_GET_SAMPLED_DATA_COMMAND_ID, \
                           "vwuv", \
							  sampleId,							  earliestSampleTime,							  sampleType,							  numberOfSamples);



/** @brief The ConfigureNotificationScheme is sent to the mirror once the mirror has been created. The command deals with the operational configuration of the Mirror and the device that reports to the mirror. No default schemes are allowed to be overwritten.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: ConfigureNotificationScheme
* @param issuerEventId uint32_t

* @param notificationScheme uint8_t

* @param notificationFlagOrder uint32_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_configure_notification_scheme( \
  issuerEventId,  notificationScheme,  notificationFlagOrder) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_CONFIGURE_NOTIFICATION_SCHEME_COMMAND_ID, \
                           "wuw", \
							  issuerEventId,							  notificationScheme,							  notificationFlagOrder);



/** @brief This command is sent in response to the ReportAttribute command when the MirrorReporting attribute is set.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: MirrorReportAttributeResponse
* @param notificationScheme uint8_t

* @param notificationFlags uint8_t *
* @param notificationFlagsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_mirror_report_attribute_response( \
  notificationScheme,  notificationFlags, notificationFlagsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_MIRROR_REPORT_ATTRIBUTE_RESPONSE_COMMAND_ID, \
                           "ub", \
							  notificationScheme,							  notificationFlags, notificationFlagsLen);



/** @brief The ConfigureNotificationFlags command is used to set the commands relating to the bit value for each NotificationFlags attribute that the scheme is proposing to use.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: ConfigureNotificationFlags
* @param issuerEventId uint32_t

* @param notificationScheme uint8_t

* @param notificationFlagAttributeId uint16_t

* @param clusterId uint16_t

* @param manufacturerCode uint16_t

* @param numberOfCommands uint8_t

* @param commandIds uint8_t *
* @param commandIdsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_configure_notification_flags( \
  issuerEventId,  notificationScheme,  notificationFlagAttributeId,  clusterId,  manufacturerCode,  numberOfCommands,  commandIds, commandIdsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_CONFIGURE_NOTIFICATION_FLAGS_COMMAND_ID, \
                           "wuvvvub", \
							  issuerEventId,							  notificationScheme,							  notificationFlagAttributeId,							  clusterId,							  manufacturerCode,							  numberOfCommands,							  commandIds, commandIdsLen);



/** @brief The ResetLoadLimitCounter command shall cause the LoadLimitCounter attribute to be reset.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: ResetLoadLimitCounter
* @param providerId uint32_t

* @param issuerEventId uint32_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_reset_load_limit_counter( \
  providerId,  issuerEventId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_RESET_LOAD_LIMIT_COUNTER_COMMAND_ID, \
                           "ww", \
							  providerId,							  issuerEventId);



/** @brief The GetNotifiedMessage command is used only when a BOMD is being mirrored. This command provides a method for the BOMD to notify the Mirror message queue that it wants to receive commands that the Mirror has queued. The Notification flags set within the command shall inform the mirror of the commands that the BOMD is requesting.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: GetNotifiedMessage
* @param notificationScheme uint8_t

* @param notificationFlagAttributeId uint16_t

* @param notificationFlagsN uint32_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_get_notified_message( \
  notificationScheme,  notificationFlagAttributeId,  notificationFlagsN) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_GET_NOTIFIED_MESSAGE_COMMAND_ID, \
                           "uvw", \
							  notificationScheme,							  notificationFlagAttributeId,							  notificationFlagsN);



/** @brief This command is sent from the Head-end or ESI to the Metering Device to instruct it to change the status of the valve or load switch, i.e. the supply.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: ChangeSupply
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param requestDateTime uint32_t

* @param implementationDateTime uint32_t

* @param proposedSupplyStatus uint8_t

* @param supplyControlBits uint8_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_change_supply( \
  providerId,  issuerEventId,  requestDateTime,  implementationDateTime,  proposedSupplyStatus,  supplyControlBits) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_CHANGE_SUPPLY_COMMAND_ID, \
                           "wwwwuu", \
							  providerId,							  issuerEventId,							  requestDateTime,							  implementationDateTime,							  proposedSupplyStatus,							  supplyControlBits);



/** @brief This command is transmitted by a Metering Device in response to a ChangeSupply command.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: SupplyStatusResponse
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param implementationDateTime uint32_t

* @param supplyStatus uint8_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_supply_status_response( \
  providerId,  issuerEventId,  implementationDateTime,  supplyStatus) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_SUPPLY_STATUS_RESPONSE_COMMAND_ID, \
                           "wwwu", \
							  providerId,							  issuerEventId,							  implementationDateTime,							  supplyStatus);



/** @brief This command is a simplified version of the ChangeSupply command, intended to be sent from an IHD to a meter as the consequence of a user action on the IHD. Its purpose is to provide a local disconnection/reconnection button on the IHD in addition to the one on the meter.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: LocalChangeSupply
* @param proposedSupplyStatus uint8_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_local_change_supply( \
  proposedSupplyStatus) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_LOCAL_CHANGE_SUPPLY_COMMAND_ID, \
                           "u", \
							  proposedSupplyStatus);



/** @brief This command is transmitted by a Metering Device in response to a StartSampling command.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: StartSamplingResponse
* @param sampleId uint16_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_start_sampling_response( \
  sampleId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_START_SAMPLING_RESPONSE_COMMAND_ID, \
                           "v", \
							  sampleId);



/** @brief This command is used to specify the required status of the supply following the occurance of certain events on the meter.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: SetSupplyStatus
* @param issuerEventId uint32_t

* @param supplyTamperState uint8_t

* @param supplyDepletionState uint8_t

* @param supplyUncontrolledFlowState uint8_t

* @param loadLimitSupplyState uint8_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_set_supply_status( \
  issuerEventId,  supplyTamperState,  supplyDepletionState,  supplyUncontrolledFlowState,  loadLimitSupplyState) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_SET_SUPPLY_STATUS_COMMAND_ID, \
                           "wuuuu", \
							  issuerEventId,							  supplyTamperState,							  supplyDepletionState,							  supplyUncontrolledFlowState,							  loadLimitSupplyState);



/** @brief This command is used to update the 'Uncontrolled Flow Rate' configuration data used by flow meters.
* Cluster: Simple Metering, The Metering Cluster provides a mechanism to retrieve usage information from Electric, Gas, Water, and potentially Thermal metering devices.
* Command: SetUncontrolledFlowThreshold
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param uncontrolledFlowThreshold uint16_t

* @param unitOfMeasure uint8_t

* @param multiplier uint16_t

* @param divisor uint16_t

* @param stabilisationPeriod uint8_t

* @param measurementPeriod uint16_t

*/
#define sl_zigbee_af_fill_command_simple_metering_cluster_set_uncontrolled_flow_threshold( \
  providerId,  issuerEventId,  uncontrolledFlowThreshold,  unitOfMeasure,  multiplier,  divisor,  stabilisationPeriod,  measurementPeriod) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SIMPLE_METERING_CLUSTER_ID, \
                           ZCL_SET_UNCONTROLLED_FLOW_THRESHOLD_COMMAND_ID, \
                           "wwvuvvuv", \
							  providerId,							  issuerEventId,							  uncontrolledFlowThreshold,							  unitOfMeasure,							  multiplier,							  divisor,							  stabilisationPeriod,							  measurementPeriod);



/** @brief Command description for DisplayMessage
* Cluster: Messaging, This cluster provides an interface for passing text messages between SE devices.
* Command: DisplayMessage
* @param messageId uint32_t

* @param messageControl uint8_t

* @param startTime uint32_t

* @param durationInMinutes uint16_t

* @param message uint8_t *

* @param optionalExtendedMessageControl uint8_t

*/
#define sl_zigbee_af_fill_command_messaging_cluster_display_message( \
  messageId,  messageControl,  startTime,  durationInMinutes,  message,  optionalExtendedMessageControl) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_MESSAGING_CLUSTER_ID, \
                           ZCL_DISPLAY_MESSAGE_COMMAND_ID, \
                           "wuwvsu", \
							  messageId,							  messageControl,							  startTime,							  durationInMinutes,							  message,							  optionalExtendedMessageControl);



/** @brief Command description for GetLastMessage
* Cluster: Messaging, This cluster provides an interface for passing text messages between SE devices.
* Command: GetLastMessage
*/
#define sl_zigbee_af_fill_command_messaging_cluster_get_last_message( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_MESSAGING_CLUSTER_ID, \
                           ZCL_GET_LAST_MESSAGE_COMMAND_ID, \
                           "" \
);



/** @brief The CancelMessage command provides the ability to cancel the sending or acceptance of previously sent messages.
* Cluster: Messaging, This cluster provides an interface for passing text messages between SE devices.
* Command: CancelMessage
* @param messageId uint32_t

* @param messageControl uint8_t

*/
#define sl_zigbee_af_fill_command_messaging_cluster_cancel_message( \
  messageId,  messageControl) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_MESSAGING_CLUSTER_ID, \
                           ZCL_CANCEL_MESSAGE_COMMAND_ID, \
                           "wu", \
							  messageId,							  messageControl);



/** @brief The Message Confirmation command provides an indication that a Utility Customer has acknowledged and/or accepted the contents of a previously sent message.  Enhanced Message Confirmation commands shall contain an answer of 'NO', 'YES' and/or a message confirmation string.
* Cluster: Messaging, This cluster provides an interface for passing text messages between SE devices.
* Command: MessageConfirmation
* @param messageId uint32_t

* @param confirmationTime uint32_t

* @param messageConfirmationControl uint8_t

* @param messageResponse uint8_t *

*/
#define sl_zigbee_af_fill_command_messaging_cluster_message_confirmation( \
  messageId,  confirmationTime,  messageConfirmationControl,  messageResponse) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_MESSAGING_CLUSTER_ID, \
                           ZCL_MESSAGE_CONFIRMATION_COMMAND_ID, \
                           "wwus", \
							  messageId,							  confirmationTime,							  messageConfirmationControl,							  messageResponse);



/** @brief The DisplayProtected Message command is for use with messages that are protected by a password or PIN.
* Cluster: Messaging, This cluster provides an interface for passing text messages between SE devices.
* Command: DisplayProtectedMessage
* @param messageId uint32_t

* @param messageControl uint8_t

* @param startTime uint32_t

* @param durationInMinutes uint16_t

* @param message uint8_t *

* @param optionalExtendedMessageControl uint8_t

*/
#define sl_zigbee_af_fill_command_messaging_cluster_display_protected_message( \
  messageId,  messageControl,  startTime,  durationInMinutes,  message,  optionalExtendedMessageControl) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_MESSAGING_CLUSTER_ID, \
                           ZCL_DISPLAY_PROTECTED_MESSAGE_COMMAND_ID, \
                           "wuwvsu", \
							  messageId,							  messageControl,							  startTime,							  durationInMinutes,							  message,							  optionalExtendedMessageControl);



/** @brief This command initiates the return of the first (and maybe only) Cancel All Messages command held on the associated server, and which has an implementation time equal to or later than the value indicated in the payload.
* Cluster: Messaging, This cluster provides an interface for passing text messages between SE devices.
* Command: GetMessageCancellation
* @param earliestImplementationTime uint32_t

*/
#define sl_zigbee_af_fill_command_messaging_cluster_get_message_cancellation( \
  earliestImplementationTime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_MESSAGING_CLUSTER_ID, \
                           ZCL_GET_MESSAGE_CANCELLATION_COMMAND_ID, \
                           "w", \
							  earliestImplementationTime);



/** @brief The CancelAllMessages command indicates to a client device that it should cancel all display messages currently held by it.
* Cluster: Messaging, This cluster provides an interface for passing text messages between SE devices.
* Command: CancelAllMessages
* @param implementationDateTime uint32_t

*/
#define sl_zigbee_af_fill_command_messaging_cluster_cancel_all_messages( \
  implementationDateTime) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_MESSAGING_CLUSTER_ID, \
                           ZCL_CANCEL_ALL_MESSAGES_COMMAND_ID, \
                           "w", \
							  implementationDateTime);



/** @brief RequestTunnel is the client command used to setup a tunnel association with the server. The request payload specifies the protocol identifier for the requested tunnel, a manufacturer code in case of proprietary protocols and the use of flow control for streaming protocols.
* Cluster: Tunneling, The tunneling cluster provides an interface for tunneling protocols.
* Command: RequestTunnel
* @param protocolId uint8_t

* @param manufacturerCode uint16_t

* @param flowControlSupport uint8_t

* @param maximumIncomingTransferSize uint16_t

*/
#define sl_zigbee_af_fill_command_tunneling_cluster_request_tunnel( \
  protocolId,  manufacturerCode,  flowControlSupport,  maximumIncomingTransferSize) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_TUNNELING_CLUSTER_ID, \
                           ZCL_REQUEST_TUNNEL_COMMAND_ID, \
                           "uvuv", \
							  protocolId,							  manufacturerCode,							  flowControlSupport,							  maximumIncomingTransferSize);



/** @brief RequestTunnelResponse is sent by the server in response to a RequestTunnel command previously received from the client. The response contains the status of the RequestTunnel command and a tunnel identifier corresponding to the tunnel that has been set-up in the server in case of success.
* Cluster: Tunneling, The tunneling cluster provides an interface for tunneling protocols.
* Command: RequestTunnelResponse
* @param tunnelId uint16_t

* @param tunnelStatus uint8_t

* @param maximumIncomingTransferSize uint16_t

*/
#define sl_zigbee_af_fill_command_tunneling_cluster_request_tunnel_response( \
  tunnelId,  tunnelStatus,  maximumIncomingTransferSize) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_TUNNELING_CLUSTER_ID, \
                           ZCL_REQUEST_TUNNEL_RESPONSE_COMMAND_ID, \
                           "vuv", \
							  tunnelId,							  tunnelStatus,							  maximumIncomingTransferSize);



/** @brief Client command used to close the tunnel with the server. The parameter in the payload specifies the tunnel identifier of the tunnel that has to be closed. The server leaves the tunnel open and the assigned resources allocated until the client sends the CloseTunnel command or the CloseTunnelTimeout fires.
* Cluster: Tunneling, The tunneling cluster provides an interface for tunneling protocols.
* Command: CloseTunnel
* @param tunnelId uint16_t

*/
#define sl_zigbee_af_fill_command_tunneling_cluster_close_tunnel( \
  tunnelId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_TUNNELING_CLUSTER_ID, \
                           ZCL_CLOSE_TUNNEL_COMMAND_ID, \
                           "v", \
							  tunnelId);



/** @brief Command that transfers data from server to the client. The data itself has to be placed within the payload.
* Cluster: Tunneling, The tunneling cluster provides an interface for tunneling protocols.
* Command: TransferDataServerToClient
* @param tunnelId uint16_t

* @param data uint8_t *
* @param dataLen uint16_t 
*/
#define sl_zigbee_af_fill_command_tunneling_cluster_transfer_data_server_to_client( \
  tunnelId,  data, dataLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_TUNNELING_CLUSTER_ID, \
                           ZCL_TRANSFER_DATA_SERVER_TO_CLIENT_COMMAND_ID, \
                           "vb", \
							  tunnelId,							  data, dataLen);



/** @brief Command that indicates (if received) that the client has sent data to the server. The data itself is contained within the payload.
* Cluster: Tunneling, The tunneling cluster provides an interface for tunneling protocols.
* Command: TransferDataClientToServer
* @param tunnelId uint16_t

* @param data uint8_t *
* @param dataLen uint16_t 
*/
#define sl_zigbee_af_fill_command_tunneling_cluster_transfer_data_client_to_server( \
  tunnelId,  data, dataLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_TUNNELING_CLUSTER_ID, \
                           ZCL_TRANSFER_DATA_CLIENT_TO_SERVER_COMMAND_ID, \
                           "vb", \
							  tunnelId,							  data, dataLen);



/** @brief This command is generated by the receiver of a TransferData command if the tunnel status indicates that something is wrong. There are two three cases in which TransferDataError is sent: (1) The TransferData received contains a TunnelID that does not match to any of the active tunnels of the receiving device. This could happen if a (sleeping) device sends a TransferData command to a tunnel that has been closed by the server after the CloseTunnelTimeout.  (2) The TransferData received contains a proper TunnelID of an active tunnel, but the device sending the data does not match to it.  (3) The TransferData received contains more data than indicated by the MaximumIncomingTransferSize of the receiving device.
* Cluster: Tunneling, The tunneling cluster provides an interface for tunneling protocols.
* Command: TransferDataErrorServerToClient
* @param tunnelId uint16_t

* @param transferDataStatus uint8_t

*/
#define sl_zigbee_af_fill_command_tunneling_cluster_transfer_data_error_server_to_client( \
  tunnelId,  transferDataStatus) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_TUNNELING_CLUSTER_ID, \
                           ZCL_TRANSFER_DATA_ERROR_SERVER_TO_CLIENT_COMMAND_ID, \
                           "vu", \
							  tunnelId,							  transferDataStatus);



/** @brief This command is generated by the receiver of a TransferData command if the tunnel status indicates that something is wrong. There are two three cases in which TransferDataError is sent: (1) The TransferData received contains a TunnelID that does not match to any of the active tunnels of the receiving device. This could happen if a (sleeping) device sends a TransferData command to a tunnel that has been closed by the server after the CloseTunnelTimeout.  (2) The TransferData received contains a proper TunnelID of an active tunnel, but the device sending the data does not match to it.  (3) The TransferData received contains more data than indicated by the MaximumIncomingTransferSize of the receiving device.
* Cluster: Tunneling, The tunneling cluster provides an interface for tunneling protocols.
* Command: TransferDataErrorClientToServer
* @param tunnelId uint16_t

* @param transferDataStatus uint8_t

*/
#define sl_zigbee_af_fill_command_tunneling_cluster_transfer_data_error_client_to_server( \
  tunnelId,  transferDataStatus) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_TUNNELING_CLUSTER_ID, \
                           ZCL_TRANSFER_DATA_ERROR_CLIENT_TO_SERVER_COMMAND_ID, \
                           "vu", \
							  tunnelId,							  transferDataStatus);



/** @brief Command sent in response to each TransferData command in case - and only in case - flow control has been requested by the client in the TunnelRequest command and is supported by both tunnel endpoints. The response payload indicates the number of octets that may still be received by the receiver.
* Cluster: Tunneling, The tunneling cluster provides an interface for tunneling protocols.
* Command: AckTransferDataServerToClient
* @param tunnelId uint16_t

* @param numberOfBytesLeft uint16_t

*/
#define sl_zigbee_af_fill_command_tunneling_cluster_ack_transfer_data_server_to_client( \
  tunnelId,  numberOfBytesLeft) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_TUNNELING_CLUSTER_ID, \
                           ZCL_ACK_TRANSFER_DATA_SERVER_TO_CLIENT_COMMAND_ID, \
                           "vv", \
							  tunnelId,							  numberOfBytesLeft);



/** @brief Command sent in response to each TransferData command in case - and only in case - flow control has been requested by the client in the TunnelRequest command and is supported by both tunnel endpoints. The response payload indicates the number of octets that may still be received by the receiver.
* Cluster: Tunneling, The tunneling cluster provides an interface for tunneling protocols.
* Command: AckTransferDataClientToServer
* @param tunnelId uint16_t

* @param numberOfBytesLeft uint16_t

*/
#define sl_zigbee_af_fill_command_tunneling_cluster_ack_transfer_data_client_to_server( \
  tunnelId,  numberOfBytesLeft) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_TUNNELING_CLUSTER_ID, \
                           ZCL_ACK_TRANSFER_DATA_CLIENT_TO_SERVER_COMMAND_ID, \
                           "vv", \
							  tunnelId,							  numberOfBytesLeft);



/** @brief The ReadyData command is generated - after a receiver had to stop the dataflow using the AckTransferData(0) command - to indicate that the device is now ready to continue receiving data. The parameter NumberOfOctetsLeft gives a hint on how much space is left for the next data transfer. The ReadyData command is only issued if flow control is enabled.
* Cluster: Tunneling, The tunneling cluster provides an interface for tunneling protocols.
* Command: ReadyDataServerToClient
* @param tunnelId uint16_t

* @param numberOfOctetsLeft uint16_t

*/
#define sl_zigbee_af_fill_command_tunneling_cluster_ready_data_server_to_client( \
  tunnelId,  numberOfOctetsLeft) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_TUNNELING_CLUSTER_ID, \
                           ZCL_READY_DATA_SERVER_TO_CLIENT_COMMAND_ID, \
                           "vv", \
							  tunnelId,							  numberOfOctetsLeft);



/** @brief The ReadyData command is generated - after a receiver had to stop the dataflow using the AckTransferData(0) command - to indicate that the device is now ready to continue receiving data. The parameter NumberOfOctetsLeft gives a hint on how much space is left for the next data transfer. The ReadyData command is only issued if flow control is enabled.
* Cluster: Tunneling, The tunneling cluster provides an interface for tunneling protocols.
* Command: ReadyDataClientToServer
* @param tunnelId uint16_t

* @param numberOfOctetsLeft uint16_t

*/
#define sl_zigbee_af_fill_command_tunneling_cluster_ready_data_client_to_server( \
  tunnelId,  numberOfOctetsLeft) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_TUNNELING_CLUSTER_ID, \
                           ZCL_READY_DATA_CLIENT_TO_SERVER_COMMAND_ID, \
                           "vv", \
							  tunnelId,							  numberOfOctetsLeft);



/** @brief Supported Tunnel Protocol Response is sent in response to a Get Supported Tunnel Protocols command previously received. The response contains a list of Tunnel protocols supported by the device; the payload of the response should be capable of holding up to 16 protocols.
* Cluster: Tunneling, The tunneling cluster provides an interface for tunneling protocols.
* Command: SupportedTunnelProtocolsResponse
* @param protocolListComplete uint8_t

* @param protocolCount uint8_t

* @param protocolList uint8_t *
* @param protocolListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_tunneling_cluster_supported_tunnel_protocols_response( \
  protocolListComplete,  protocolCount,  protocolList, protocolListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_TUNNELING_CLUSTER_ID, \
                           ZCL_SUPPORTED_TUNNEL_PROTOCOLS_RESPONSE_COMMAND_ID, \
                           "uub", \
							  protocolListComplete,							  protocolCount,							  protocolList, protocolListLen);



/** @brief Get Supported Tunnel Protocols is the client command used to determine the Tunnel protocols supported on another device.
* Cluster: Tunneling, The tunneling cluster provides an interface for tunneling protocols.
* Command: GetSupportedTunnelProtocols
* @param protocolOffset uint8_t

*/
#define sl_zigbee_af_fill_command_tunneling_cluster_get_supported_tunnel_protocols( \
  protocolOffset) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_TUNNELING_CLUSTER_ID, \
                           ZCL_GET_SUPPORTED_TUNNEL_PROTOCOLS_COMMAND_ID, \
                           "u", \
							  protocolOffset);



/** @brief TunnelClosureNotification is sent by the server to indicate that a tunnel has been closed due to expiration of a CloseTunnelTimeout.
* Cluster: Tunneling, The tunneling cluster provides an interface for tunneling protocols.
* Command: TunnelClosureNotification
* @param tunnelId uint16_t

*/
#define sl_zigbee_af_fill_command_tunneling_cluster_tunnel_closure_notification( \
  tunnelId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_TUNNELING_CLUSTER_ID, \
                           ZCL_TUNNEL_CLOSURE_NOTIFICATION_COMMAND_ID, \
                           "v", \
							  tunnelId);



/** @brief This command is sent to the Metering Device to activate the use of any Emergency Credit available on the Metering Device.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: SelectAvailableEmergencyCredit
* @param commandIssueDateTime uint32_t

* @param originatingDevice uint8_t

*/
#define sl_zigbee_af_fill_command_prepayment_cluster_select_available_emergency_credit( \
  commandIssueDateTime,  originatingDevice) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_SELECT_AVAILABLE_EMERGENCY_CREDIT_COMMAND_ID, \
                           "wu", \
							  commandIssueDateTime,							  originatingDevice);



/** @brief This command is generated in response to a GetPrepaySnapshot command. It is used to return a single snapshot to the client.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: PublishPrepaySnapshot
* @param snapshotId uint32_t

* @param snapshotTime uint32_t

* @param totalSnapshotsFound uint8_t

* @param commandIndex uint8_t

* @param totalNumberOfCommands uint8_t

* @param snapshotCause uint32_t

* @param snapshotPayloadType uint8_t

* @param snapshotPayload uint8_t *
* @param snapshotPayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_prepayment_cluster_publish_prepay_snapshot( \
  snapshotId,  snapshotTime,  totalSnapshotsFound,  commandIndex,  totalNumberOfCommands,  snapshotCause,  snapshotPayloadType,  snapshotPayload, snapshotPayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_PUBLISH_PREPAY_SNAPSHOT_COMMAND_ID, \
                           "wwuuuwub", \
							  snapshotId,							  snapshotTime,							  totalSnapshotsFound,							  commandIndex,							  totalNumberOfCommands,							  snapshotCause,							  snapshotPayloadType,							  snapshotPayload, snapshotPayloadLen);



/** @brief The ChangeDebt command is send to the Metering Device to change the fuel or Non fuel debt values.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: ChangeDebt
* @param issuerEventId uint32_t

* @param debtLabel uint8_t *

* @param debtAmount uint32_t

* @param debtRecoveryMethod uint8_t

* @param debtAmountType uint8_t

* @param debtRecoveryStartTime uint32_t

* @param debtRecoveryCollectionTime uint16_t

* @param debtRecoveryFrequency uint8_t

* @param debtRecoveryAmount uint32_t

* @param debtRecoveryBalancePercentage uint16_t

*/
#define sl_zigbee_af_fill_command_prepayment_cluster_change_debt( \
  issuerEventId,  debtLabel,  debtAmount,  debtRecoveryMethod,  debtAmountType,  debtRecoveryStartTime,  debtRecoveryCollectionTime,  debtRecoveryFrequency,  debtRecoveryAmount,  debtRecoveryBalancePercentage) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_CHANGE_DEBT_COMMAND_ID, \
                           "wswuuwvuwv", \
							  issuerEventId,							  debtLabel,							  debtAmount,							  debtRecoveryMethod,							  debtAmountType,							  debtRecoveryStartTime,							  debtRecoveryCollectionTime,							  debtRecoveryFrequency,							  debtRecoveryAmount,							  debtRecoveryBalancePercentage);



/** @brief This command is send in response to the ChangePaymentMode Command.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: ChangePaymentModeResponse
* @param friendlyCredit uint8_t

* @param friendlyCreditCalendarId uint32_t

* @param emergencyCreditLimit uint32_t

* @param emergencyCreditThreshold uint32_t

*/
#define sl_zigbee_af_fill_command_prepayment_cluster_change_payment_mode_response( \
  friendlyCredit,  friendlyCreditCalendarId,  emergencyCreditLimit,  emergencyCreditThreshold) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_CHANGE_PAYMENT_MODE_RESPONSE_COMMAND_ID, \
                           "uwww", \
							  friendlyCredit,							  friendlyCreditCalendarId,							  emergencyCreditLimit,							  emergencyCreditThreshold);



/** @brief This command is a method to set up the parameters for the emergency credit.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: EmergencyCreditSetup
* @param issuerEventId uint32_t

* @param startTime uint32_t

* @param emergencyCreditLimit uint32_t

* @param emergencyCreditThreshold uint32_t

*/
#define sl_zigbee_af_fill_command_prepayment_cluster_emergency_credit_setup( \
  issuerEventId,  startTime,  emergencyCreditLimit,  emergencyCreditThreshold) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_EMERGENCY_CREDIT_SETUP_COMMAND_ID, \
                           "wwww", \
							  issuerEventId,							  startTime,							  emergencyCreditLimit,							  emergencyCreditThreshold);



/** @brief This command is send in response to the ConsumerTopUp Command.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: ConsumerTopUpResponse
* @param resultType uint8_t

* @param topUpValue uint32_t

* @param sourceOfTopUp uint8_t

* @param creditRemaining uint32_t

*/
#define sl_zigbee_af_fill_command_prepayment_cluster_consumer_top_up_response( \
  resultType,  topUpValue,  sourceOfTopUp,  creditRemaining) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_CONSUMER_TOP_UP_RESPONSE_COMMAND_ID, \
                           "uwuw", \
							  resultType,							  topUpValue,							  sourceOfTopUp,							  creditRemaining);



/** @brief The ConsumerTopUp command is used by the IPD and the ESI as a method of applying credit top up values to the prepayment meter.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: ConsumerTopUp
* @param originatingDevice uint8_t

* @param topUpCode uint8_t *

*/
#define sl_zigbee_af_fill_command_prepayment_cluster_consumer_top_up( \
  originatingDevice,  topUpCode) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_CONSUMER_TOP_UP_COMMAND_ID, \
                           "us", \
							  originatingDevice,							  topUpCode);



/** @brief The CreditAdjustment command is sent to update the accounting base for the Prepayment meter.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: CreditAdjustment
* @param issuerEventId uint32_t

* @param startTime uint32_t

* @param creditAdjustmentType uint8_t

* @param creditAdjustmentValue uint32_t

*/
#define sl_zigbee_af_fill_command_prepayment_cluster_credit_adjustment( \
  issuerEventId,  startTime,  creditAdjustmentType,  creditAdjustmentValue) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_CREDIT_ADJUSTMENT_COMMAND_ID, \
                           "wwuw", \
							  issuerEventId,							  startTime,							  creditAdjustmentType,							  creditAdjustmentValue);



/** @brief This command is used to send the Top Up Code Log entries to the client.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: PublishTopUpLog
* @param commandIndex uint8_t

* @param totalNumberOfCommands uint8_t

* @param topUpPayload uint8_t *
* @param topUpPayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_prepayment_cluster_publish_top_up_log( \
  commandIndex,  totalNumberOfCommands,  topUpPayload, topUpPayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_PUBLISH_TOP_UP_LOG_COMMAND_ID, \
                           "uub", \
							  commandIndex,							  totalNumberOfCommands,							  topUpPayload, topUpPayloadLen);



/** @brief This command is sent to a Metering Device to instruct it to change its mode of operation. i.e. from Credit to Prepayment.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: ChangePaymentMode
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param implementationDateTime uint32_t

* @param proposedPaymentControlConfiguration uint16_t

* @param cutOffValue uint32_t

*/
#define sl_zigbee_af_fill_command_prepayment_cluster_change_payment_mode( \
  providerId,  issuerEventId,  implementationDateTime,  proposedPaymentControlConfiguration,  cutOffValue) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_CHANGE_PAYMENT_MODE_COMMAND_ID, \
                           "wwwvw", \
							  providerId,							  issuerEventId,							  implementationDateTime,							  proposedPaymentControlConfiguration,							  cutOffValue);



/** @brief This command is used to send the contents of the Repayment Log.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: PublishDebtLog
* @param commandIndex uint8_t

* @param totalNumberOfCommands uint8_t

* @param debtPayload uint8_t *
* @param debtPayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_prepayment_cluster_publish_debt_log( \
  commandIndex,  totalNumberOfCommands,  debtPayload, debtPayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_PUBLISH_DEBT_LOG_COMMAND_ID, \
                           "uub", \
							  commandIndex,							  totalNumberOfCommands,							  debtPayload, debtPayloadLen);



/** @brief This command is used to request the cluster server for snapshot data.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: GetPrepaySnapshot
* @param earliestStartTime uint32_t

* @param latestEndTime uint32_t

* @param snapshotOffset uint8_t

* @param snapshotCause uint32_t

*/
#define sl_zigbee_af_fill_command_prepayment_cluster_get_prepay_snapshot( \
  earliestStartTime,  latestEndTime,  snapshotOffset,  snapshotCause) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_GET_PREPAY_SNAPSHOT_COMMAND_ID, \
                           "wwuw", \
							  earliestStartTime,							  latestEndTime,							  snapshotOffset,							  snapshotCause);



/** @brief This command is sent to the Metering Device to retrieve the log of Top Up codes received by the meter.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: GetTopUpLog
* @param latestEndTime uint32_t

* @param numberOfRecords uint8_t

*/
#define sl_zigbee_af_fill_command_prepayment_cluster_get_top_up_log( \
  latestEndTime,  numberOfRecords) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_GET_TOP_UP_LOG_COMMAND_ID, \
                           "wu", \
							  latestEndTime,							  numberOfRecords);



/** @brief This command is sent from client to a Prepayment server to set the warning level for low credit.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: SetLowCreditWarningLevel
* @param lowCreditWarningLevel uint32_t

*/
#define sl_zigbee_af_fill_command_prepayment_cluster_set_low_credit_warning_level( \
  lowCreditWarningLevel) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_SET_LOW_CREDIT_WARNING_LEVEL_COMMAND_ID, \
                           "w", \
							  lowCreditWarningLevel);



/** @brief This command is used to request the contents of the repayment log.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: GetDebtRepaymentLog
* @param latestEndTime uint32_t

* @param numberOfDebts uint8_t

* @param debtType uint8_t

*/
#define sl_zigbee_af_fill_command_prepayment_cluster_get_debt_repayment_log( \
  latestEndTime,  numberOfDebts,  debtType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_GET_DEBT_REPAYMENT_LOG_COMMAND_ID, \
                           "wuu", \
							  latestEndTime,							  numberOfDebts,							  debtType);



/** @brief This command is sent from a client to the Prepayment server to set the maximum credit level allowed in the meter.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: SetMaximumCreditLimit
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param implementationDateTime uint32_t

* @param maximumCreditLevel uint32_t

* @param maximumCreditPerTopUp uint32_t

*/
#define sl_zigbee_af_fill_command_prepayment_cluster_set_maximum_credit_limit( \
  providerId,  issuerEventId,  implementationDateTime,  maximumCreditLevel,  maximumCreditPerTopUp) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_SET_MAXIMUM_CREDIT_LIMIT_COMMAND_ID, \
                           "wwwww", \
							  providerId,							  issuerEventId,							  implementationDateTime,							  maximumCreditLevel,							  maximumCreditPerTopUp);



/** @brief This command is sent from a client to the Prepayment server to set the overall debt cap allowed in the meter.
* Cluster: Prepayment, The Prepayment Cluster provides the facility to pass messages relating to prepayment between devices on the HAN.
* Command: SetOverallDebtCap
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param implementationDateTime uint32_t

* @param overallDebtCap uint32_t

*/
#define sl_zigbee_af_fill_command_prepayment_cluster_set_overall_debt_cap( \
  providerId,  issuerEventId,  implementationDateTime,  overallDebtCap) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PREPAYMENT_CLUSTER_ID, \
                           ZCL_SET_OVERALL_DEBT_CAP_COMMAND_ID, \
                           "wwww", \
							  providerId,							  issuerEventId,							  implementationDateTime,							  overallDebtCap);



/** @brief This command is reused from the DRLC cluster. This command is generated in response to the Manage Event command.
* Cluster: Energy Management, This cluster provides attributes and commands to assist applications in creating resource monitoring protocols.
* Command: ReportEventStatus
* @param issuerEventId uint32_t

* @param eventStatus uint8_t

* @param eventStatusTime uint32_t

* @param criticalityLevelApplied uint8_t

* @param coolingTemperatureSetPointApplied uint16_t

* @param heatingTemperatureSetPointApplied uint16_t

* @param averageLoadAdjustmentPercentageApplied int8_t

* @param dutyCycleApplied uint8_t

* @param eventControl uint8_t

*/
#define sl_zigbee_af_fill_command_energy_management_cluster_report_event_status( \
  issuerEventId,  eventStatus,  eventStatusTime,  criticalityLevelApplied,  coolingTemperatureSetPointApplied,  heatingTemperatureSetPointApplied,  averageLoadAdjustmentPercentageApplied,  dutyCycleApplied,  eventControl) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_ENERGY_MANAGEMENT_CLUSTER_ID, \
                           ZCL_REPORT_EVENT_STATUS_COMMAND_ID, \
                           "wuwuvvuuu", \
							  issuerEventId,							  eventStatus,							  eventStatusTime,							  criticalityLevelApplied,							  coolingTemperatureSetPointApplied,							  heatingTemperatureSetPointApplied,							  averageLoadAdjustmentPercentageApplied,							  dutyCycleApplied,							  eventControl);



/** @brief The Manage Event command allows a remote device (such as an IHD or web portal) to change the behavior of a DRLC cluster client when responding to a DRLC Load Control Event.
* Cluster: Energy Management, This cluster provides attributes and commands to assist applications in creating resource monitoring protocols.
* Command: ManageEvent
* @param issuerEventId uint32_t

* @param deviceClass uint16_t

* @param utilityEnrollmentGroup uint8_t

* @param actionRequired uint8_t

*/
#define sl_zigbee_af_fill_command_energy_management_cluster_manage_event( \
  issuerEventId,  deviceClass,  utilityEnrollmentGroup,  actionRequired) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ENERGY_MANAGEMENT_CLUSTER_ID, \
                           ZCL_MANAGE_EVENT_COMMAND_ID, \
                           "wvuu", \
							  issuerEventId,							  deviceClass,							  utilityEnrollmentGroup,							  actionRequired);



/** @brief The PublishCalendar command is published in response to a GetCalendar command or if new calendar information is available.
* Cluster: Calendar, This cluster provides attributes and commands to assist applications in developing time and date based protocol.
* Command: PublishCalendar
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param issuerCalendarId uint32_t

* @param startTime uint32_t

* @param calendarType uint8_t

* @param calendarTimeReference uint8_t

* @param calendarName uint8_t *

* @param numberOfSeasons uint8_t

* @param numberOfWeekProfiles uint8_t

* @param numberOfDayProfiles uint8_t

*/
#define sl_zigbee_af_fill_command_calendar_cluster_publish_calendar( \
  providerId,  issuerEventId,  issuerCalendarId,  startTime,  calendarType,  calendarTimeReference,  calendarName,  numberOfSeasons,  numberOfWeekProfiles,  numberOfDayProfiles) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CALENDAR_CLUSTER_ID, \
                           ZCL_PUBLISH_CALENDAR_COMMAND_ID, \
                           "wwwwuusuuu", \
							  providerId,							  issuerEventId,							  issuerCalendarId,							  startTime,							  calendarType,							  calendarTimeReference,							  calendarName,							  numberOfSeasons,							  numberOfWeekProfiles,							  numberOfDayProfiles);



/** @brief This command initiates PublishCalendar command(s) for scheduled Calendar updates.
* Cluster: Calendar, This cluster provides attributes and commands to assist applications in developing time and date based protocol.
* Command: GetCalendar
* @param earliestStartTime uint32_t

* @param minIssuerEventId uint32_t

* @param numberOfCalendars uint8_t

* @param calendarType uint8_t

* @param providerId uint32_t

*/
#define sl_zigbee_af_fill_command_calendar_cluster_get_calendar( \
  earliestStartTime,  minIssuerEventId,  numberOfCalendars,  calendarType,  providerId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_CALENDAR_CLUSTER_ID, \
                           ZCL_GET_CALENDAR_COMMAND_ID, \
                           "wwuuw", \
							  earliestStartTime,							  minIssuerEventId,							  numberOfCalendars,							  calendarType,							  providerId);



/** @brief The PublishDayProfile command is published in response to a GetDayProfile command.
* Cluster: Calendar, This cluster provides attributes and commands to assist applications in developing time and date based protocol.
* Command: PublishDayProfile
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param issuerCalendarId uint32_t

* @param dayId uint8_t

* @param totalNumberOfScheduleEntries uint8_t

* @param commandIndex uint8_t

* @param totalNumberOfCommands uint8_t

* @param calendarType uint8_t

* @param dayScheduleEntries uint8_t *
* @param dayScheduleEntriesLen uint16_t 
*/
#define sl_zigbee_af_fill_command_calendar_cluster_publish_day_profile( \
  providerId,  issuerEventId,  issuerCalendarId,  dayId,  totalNumberOfScheduleEntries,  commandIndex,  totalNumberOfCommands,  calendarType,  dayScheduleEntries, dayScheduleEntriesLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CALENDAR_CLUSTER_ID, \
                           ZCL_PUBLISH_DAY_PROFILE_COMMAND_ID, \
                           "wwwuuuuub", \
							  providerId,							  issuerEventId,							  issuerCalendarId,							  dayId,							  totalNumberOfScheduleEntries,							  commandIndex,							  totalNumberOfCommands,							  calendarType,							  dayScheduleEntries, dayScheduleEntriesLen);



/** @brief This command initiates one or more PublishDayProfile commands for the referenced Calendar.
* Cluster: Calendar, This cluster provides attributes and commands to assist applications in developing time and date based protocol.
* Command: GetDayProfiles
* @param providerId uint32_t

* @param issuerCalendarId uint32_t

* @param startDayId uint8_t

* @param numberOfDays uint8_t

*/
#define sl_zigbee_af_fill_command_calendar_cluster_get_day_profiles( \
  providerId,  issuerCalendarId,  startDayId,  numberOfDays) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_CALENDAR_CLUSTER_ID, \
                           ZCL_GET_DAY_PROFILES_COMMAND_ID, \
                           "wwuu", \
							  providerId,							  issuerCalendarId,							  startDayId,							  numberOfDays);



/** @brief The PublishWeekProfile command is published in response to a GetWeekProfile command.
* Cluster: Calendar, This cluster provides attributes and commands to assist applications in developing time and date based protocol.
* Command: PublishWeekProfile
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param issuerCalendarId uint32_t

* @param weekId uint8_t

* @param dayIdRefMonday uint8_t

* @param dayIdRefTuesday uint8_t

* @param dayIdRefWednesday uint8_t

* @param dayIdRefThursday uint8_t

* @param dayIdRefFriday uint8_t

* @param dayIdRefSaturday uint8_t

* @param dayIdRefSunday uint8_t

*/
#define sl_zigbee_af_fill_command_calendar_cluster_publish_week_profile( \
  providerId,  issuerEventId,  issuerCalendarId,  weekId,  dayIdRefMonday,  dayIdRefTuesday,  dayIdRefWednesday,  dayIdRefThursday,  dayIdRefFriday,  dayIdRefSaturday,  dayIdRefSunday) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CALENDAR_CLUSTER_ID, \
                           ZCL_PUBLISH_WEEK_PROFILE_COMMAND_ID, \
                           "wwwuuuuuuuu", \
							  providerId,							  issuerEventId,							  issuerCalendarId,							  weekId,							  dayIdRefMonday,							  dayIdRefTuesday,							  dayIdRefWednesday,							  dayIdRefThursday,							  dayIdRefFriday,							  dayIdRefSaturday,							  dayIdRefSunday);



/** @brief This command initiates one or more PublishWeekProfile commands for the referenced Calendar.
* Cluster: Calendar, This cluster provides attributes and commands to assist applications in developing time and date based protocol.
* Command: GetWeekProfiles
* @param providerId uint32_t

* @param issuerCalendarId uint32_t

* @param startWeekId uint8_t

* @param numberOfWeeks uint8_t

*/
#define sl_zigbee_af_fill_command_calendar_cluster_get_week_profiles( \
  providerId,  issuerCalendarId,  startWeekId,  numberOfWeeks) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_CALENDAR_CLUSTER_ID, \
                           ZCL_GET_WEEK_PROFILES_COMMAND_ID, \
                           "wwuu", \
							  providerId,							  issuerCalendarId,							  startWeekId,							  numberOfWeeks);



/** @brief The PublishSeasons command is published in response to a GetSeason command.
* Cluster: Calendar, This cluster provides attributes and commands to assist applications in developing time and date based protocol.
* Command: PublishSeasons
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param issuerCalendarId uint32_t

* @param commandIndex uint8_t

* @param totalNumberOfCommands uint8_t

* @param seasonEntries uint8_t *
* @param seasonEntriesLen uint16_t 
*/
#define sl_zigbee_af_fill_command_calendar_cluster_publish_seasons( \
  providerId,  issuerEventId,  issuerCalendarId,  commandIndex,  totalNumberOfCommands,  seasonEntries, seasonEntriesLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CALENDAR_CLUSTER_ID, \
                           ZCL_PUBLISH_SEASONS_COMMAND_ID, \
                           "wwwuub", \
							  providerId,							  issuerEventId,							  issuerCalendarId,							  commandIndex,							  totalNumberOfCommands,							  seasonEntries, seasonEntriesLen);



/** @brief This command initiates one or more PublishSeasons commands for the referenced Calendar.
* Cluster: Calendar, This cluster provides attributes and commands to assist applications in developing time and date based protocol.
* Command: GetSeasons
* @param providerId uint32_t

* @param issuerCalendarId uint32_t

*/
#define sl_zigbee_af_fill_command_calendar_cluster_get_seasons( \
  providerId,  issuerCalendarId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_CALENDAR_CLUSTER_ID, \
                           ZCL_GET_SEASONS_COMMAND_ID, \
                           "ww", \
							  providerId,							  issuerCalendarId);



/** @brief The PublishSpecialDays command is published in response to a GetSpecialDays command or if a calendar update is available.
* Cluster: Calendar, This cluster provides attributes and commands to assist applications in developing time and date based protocol.
* Command: PublishSpecialDays
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param issuerCalendarId uint32_t

* @param startTime uint32_t

* @param calendarType uint8_t

* @param totalNumberOfSpecialDays uint8_t

* @param commandIndex uint8_t

* @param totalNumberOfCommands uint8_t

* @param specialDayEntries uint8_t *
* @param specialDayEntriesLen uint16_t 
*/
#define sl_zigbee_af_fill_command_calendar_cluster_publish_special_days( \
  providerId,  issuerEventId,  issuerCalendarId,  startTime,  calendarType,  totalNumberOfSpecialDays,  commandIndex,  totalNumberOfCommands,  specialDayEntries, specialDayEntriesLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CALENDAR_CLUSTER_ID, \
                           ZCL_PUBLISH_SPECIAL_DAYS_COMMAND_ID, \
                           "wwwwuuuub", \
							  providerId,							  issuerEventId,							  issuerCalendarId,							  startTime,							  calendarType,							  totalNumberOfSpecialDays,							  commandIndex,							  totalNumberOfCommands,							  specialDayEntries, specialDayEntriesLen);



/** @brief This command initiates one or more PublishSpecialDays commands for the scheduled Special Day Table updates.
* Cluster: Calendar, This cluster provides attributes and commands to assist applications in developing time and date based protocol.
* Command: GetSpecialDays
* @param startTime uint32_t

* @param numberOfEvents uint8_t

* @param calendarType uint8_t

* @param providerId uint32_t

* @param issuerCalendarId uint32_t

*/
#define sl_zigbee_af_fill_command_calendar_cluster_get_special_days( \
  startTime,  numberOfEvents,  calendarType,  providerId,  issuerCalendarId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_CALENDAR_CLUSTER_ID, \
                           ZCL_GET_SPECIAL_DAYS_COMMAND_ID, \
                           "wuuww", \
							  startTime,							  numberOfEvents,							  calendarType,							  providerId,							  issuerCalendarId);



/** @brief The CancelCalendar command indicates that all data associated with a particular calendar instance should be discarded.
* Cluster: Calendar, This cluster provides attributes and commands to assist applications in developing time and date based protocol.
* Command: CancelCalendar
* @param providerId uint32_t

* @param issuerCalendarId uint32_t

* @param calendarType uint8_t

*/
#define sl_zigbee_af_fill_command_calendar_cluster_cancel_calendar( \
  providerId,  issuerCalendarId,  calendarType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CALENDAR_CLUSTER_ID, \
                           ZCL_CANCEL_CALENDAR_COMMAND_ID, \
                           "wwu", \
							  providerId,							  issuerCalendarId,							  calendarType);



/** @brief This command initiates the return of the last CancelCalendar command held on the associated server.
* Cluster: Calendar, This cluster provides attributes and commands to assist applications in developing time and date based protocol.
* Command: GetCalendarCancellation
*/
#define sl_zigbee_af_fill_command_calendar_cluster_get_calendar_cancellation( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_CALENDAR_CLUSTER_ID, \
                           ZCL_GET_CALENDAR_CANCELLATION_COMMAND_ID, \
                           "" \
);



/** @brief This command is used to request the ESI to respond with information regarding any available change of tenancy.
* Cluster: Device Management, This cluster provides attributes and commands to support device-cognisant application layer protocols.
* Command: GetChangeOfTenancy
*/
#define sl_zigbee_af_fill_command_device_management_cluster_get_change_of_tenancy( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DEVICE_MANAGEMENT_CLUSTER_ID, \
                           ZCL_GET_CHANGE_OF_TENANCY_COMMAND_ID, \
                           "" \
);



/** @brief This command is used to change the tenancy of a meter.
* Cluster: Device Management, This cluster provides attributes and commands to support device-cognisant application layer protocols.
* Command: PublishChangeOfTenancy
* @param providerId uint32_t

* @param issuerEventId uint32_t

* @param tariffType uint8_t

* @param implementationDateTime uint32_t

* @param proposedTenancyChangeControl uint32_t

*/
#define sl_zigbee_af_fill_command_device_management_cluster_publish_change_of_tenancy( \
  providerId,  issuerEventId,  tariffType,  implementationDateTime,  proposedTenancyChangeControl) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DEVICE_MANAGEMENT_CLUSTER_ID, \
                           ZCL_PUBLISH_CHANGE_OF_TENANCY_COMMAND_ID, \
                           "wwuww", \
							  providerId,							  issuerEventId,							  tariffType,							  implementationDateTime,							  proposedTenancyChangeControl);



/** @brief This command is used to request the ESI to respond with information regarding any available change of supplier.
* Cluster: Device Management, This cluster provides attributes and commands to support device-cognisant application layer protocols.
* Command: GetChangeOfSupplier
*/
#define sl_zigbee_af_fill_command_device_management_cluster_get_change_of_supplier( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DEVICE_MANAGEMENT_CLUSTER_ID, \
                           ZCL_GET_CHANGE_OF_SUPPLIER_COMMAND_ID, \
                           "" \
);



/** @brief This command is used to change the Supplier (energy supplier) that is supplying the meter (s).
* Cluster: Device Management, This cluster provides attributes and commands to support device-cognisant application layer protocols.
* Command: PublishChangeOfSupplier
* @param currentProviderId uint32_t

* @param issuerEventId uint32_t

* @param tariffType uint8_t

* @param proposedProviderId uint32_t

* @param providerChangeImplementationTime uint32_t

* @param providerChangeControl uint32_t

* @param proposedProviderName uint8_t *

* @param proposedProviderContactDetails uint8_t *

*/
#define sl_zigbee_af_fill_command_device_management_cluster_publish_change_of_supplier( \
  currentProviderId,  issuerEventId,  tariffType,  proposedProviderId,  providerChangeImplementationTime,  providerChangeControl,  proposedProviderName,  proposedProviderContactDetails) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DEVICE_MANAGEMENT_CLUSTER_ID, \
                           ZCL_PUBLISH_CHANGE_OF_SUPPLIER_COMMAND_ID, \
                           "wwuwwwss", \
							  currentProviderId,							  issuerEventId,							  tariffType,							  proposedProviderId,							  providerChangeImplementationTime,							  providerChangeControl,							  proposedProviderName,							  proposedProviderContactDetails);



/** @brief This command is used to request the current password from the server.
* Cluster: Device Management, This cluster provides attributes and commands to support device-cognisant application layer protocols.
* Command: RequestNewPassword
* @param passwordType uint8_t

*/
#define sl_zigbee_af_fill_command_device_management_cluster_request_new_password( \
  passwordType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DEVICE_MANAGEMENT_CLUSTER_ID, \
                           ZCL_REQUEST_NEW_PASSWORD_COMMAND_ID, \
                           "u", \
							  passwordType);



/** @brief This command is used to send the current password to the client.
* Cluster: Device Management, This cluster provides attributes and commands to support device-cognisant application layer protocols.
* Command: RequestNewPasswordResponse
* @param issuerEventId uint32_t

* @param implementationDateTime uint32_t

* @param durationInMinutes uint16_t

* @param passwordType uint8_t

* @param password uint8_t *

*/
#define sl_zigbee_af_fill_command_device_management_cluster_request_new_password_response( \
  issuerEventId,  implementationDateTime,  durationInMinutes,  passwordType,  password) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DEVICE_MANAGEMENT_CLUSTER_ID, \
                           ZCL_REQUEST_NEW_PASSWORD_RESPONSE_COMMAND_ID, \
                           "wwvus", \
							  issuerEventId,							  implementationDateTime,							  durationInMinutes,							  passwordType,							  password);



/** @brief This command is used to request the ESI to respond with information regarding any pending change of Site ID.
* Cluster: Device Management, This cluster provides attributes and commands to support device-cognisant application layer protocols.
* Command: GetSiteId
*/
#define sl_zigbee_af_fill_command_device_management_cluster_get_site_id( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DEVICE_MANAGEMENT_CLUSTER_ID, \
                           ZCL_GET_SITE_ID_COMMAND_ID, \
                           "" \
);



/** @brief This command is used to set the siteID.
* Cluster: Device Management, This cluster provides attributes and commands to support device-cognisant application layer protocols.
* Command: UpdateSiteId
* @param issuerEventId uint32_t

* @param siteIdTime uint32_t

* @param providerId uint32_t

* @param siteId uint8_t *

*/
#define sl_zigbee_af_fill_command_device_management_cluster_update_site_id( \
  issuerEventId,  siteIdTime,  providerId,  siteId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DEVICE_MANAGEMENT_CLUSTER_ID, \
                           ZCL_UPDATE_SITE_ID_COMMAND_ID, \
                           "wwws", \
							  issuerEventId,							  siteIdTime,							  providerId,							  siteId);



/** @brief This command is sent in response to a GetEventConfiguration command.
* Cluster: Device Management, This cluster provides attributes and commands to support device-cognisant application layer protocols.
* Command: ReportEventConfiguration
* @param commandIndex uint8_t

* @param totalCommands uint8_t

* @param eventConfigurationPayload uint8_t *
* @param eventConfigurationPayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_device_management_cluster_report_event_configuration( \
  commandIndex,  totalCommands,  eventConfigurationPayload, eventConfigurationPayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DEVICE_MANAGEMENT_CLUSTER_ID, \
                           ZCL_REPORT_EVENT_CONFIGURATION_COMMAND_ID, \
                           "uub", \
							  commandIndex,							  totalCommands,							  eventConfigurationPayload, eventConfigurationPayloadLen);



/** @brief This command provides a method to set the event configuration attributes, held in a client device.
* Cluster: Device Management, This cluster provides attributes and commands to support device-cognisant application layer protocols.
* Command: SetEventConfiguration
* @param issuerEventId uint32_t

* @param startDateTime uint32_t

* @param eventConfiguration uint8_t

* @param configurationControl uint8_t

* @param eventConfigurationPayload uint8_t *
* @param eventConfigurationPayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_device_management_cluster_set_event_configuration( \
  issuerEventId,  startDateTime,  eventConfiguration,  configurationControl,  eventConfigurationPayload, eventConfigurationPayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DEVICE_MANAGEMENT_CLUSTER_ID, \
                           ZCL_SET_EVENT_CONFIGURATION_COMMAND_ID, \
                           "wwuub", \
							  issuerEventId,							  startDateTime,							  eventConfiguration,							  configurationControl,							  eventConfigurationPayload, eventConfigurationPayloadLen);



/** @brief This command is used to request the ESI to respond with information regarding any pending change of Customer ID Number.
* Cluster: Device Management, This cluster provides attributes and commands to support device-cognisant application layer protocols.
* Command: GetCIN
*/
#define sl_zigbee_af_fill_command_device_management_cluster_get_cin( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DEVICE_MANAGEMENT_CLUSTER_ID, \
                           ZCL_GET_CIN_COMMAND_ID, \
                           "" \
);



/** @brief This command allows the server to request details of event configurations.
* Cluster: Device Management, This cluster provides attributes and commands to support device-cognisant application layer protocols.
* Command: GetEventConfiguration
* @param eventId uint16_t

*/
#define sl_zigbee_af_fill_command_device_management_cluster_get_event_configuration( \
  eventId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DEVICE_MANAGEMENT_CLUSTER_ID, \
                           ZCL_GET_EVENT_CONFIGURATION_COMMAND_ID, \
                           "v", \
							  eventId);



/** @brief This command is used to set the CustomerIDNumber attribute held in the Metering cluster.
* Cluster: Device Management, This cluster provides attributes and commands to support device-cognisant application layer protocols.
* Command: UpdateCIN
* @param issuerEventId uint32_t

* @param implementationTime uint32_t

* @param providerId uint32_t

* @param customerIdNumber uint8_t *

*/
#define sl_zigbee_af_fill_command_device_management_cluster_update_cin( \
  issuerEventId,  implementationTime,  providerId,  customerIdNumber) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DEVICE_MANAGEMENT_CLUSTER_ID, \
                           ZCL_UPDATE_CIN_COMMAND_ID, \
                           "wwws", \
							  issuerEventId,							  implementationTime,							  providerId,							  customerIdNumber);



/** @brief The GetEventLog command allows a client to request events from a server's event logs. One or more PublishEventLog commands are returned on receipt of this command.
* Cluster: Events, This cluster provides an interface on which applications can use event-based protocols.
* Command: GetEventLog
* @param eventControlLogId uint8_t

* @param eventId uint16_t

* @param startTime uint32_t

* @param endTime uint32_t

* @param numberOfEvents uint8_t

* @param eventOffset uint16_t

*/
#define sl_zigbee_af_fill_command_events_cluster_get_event_log( \
  eventControlLogId,  eventId,  startTime,  endTime,  numberOfEvents,  eventOffset) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_EVENTS_CLUSTER_ID, \
                           ZCL_GET_EVENT_LOG_COMMAND_ID, \
                           "uvwwuv", \
							  eventControlLogId,							  eventId,							  startTime,							  endTime,							  numberOfEvents,							  eventOffset);



/** @brief The PublishEvent command is generated upon an event trigger from within the reporting device and, if supported, the associated Event Configuration attribute in the Device Management cluster.
* Cluster: Events, This cluster provides an interface on which applications can use event-based protocols.
* Command: PublishEvent
* @param logId uint8_t

* @param eventId uint16_t

* @param eventTime uint32_t

* @param eventControl uint8_t

* @param eventData uint8_t *

*/
#define sl_zigbee_af_fill_command_events_cluster_publish_event( \
  logId,  eventId,  eventTime,  eventControl,  eventData) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_EVENTS_CLUSTER_ID, \
                           ZCL_PUBLISH_EVENT_COMMAND_ID, \
                           "uvwus", \
							  logId,							  eventId,							  eventTime,							  eventControl,							  eventData);



/** @brief The ClearEventLogRequest command requests that an Events server device clear the specified event log(s).
* Cluster: Events, This cluster provides an interface on which applications can use event-based protocols.
* Command: ClearEventLogRequest
* @param logId uint8_t

*/
#define sl_zigbee_af_fill_command_events_cluster_clear_event_log_request( \
  logId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_EVENTS_CLUSTER_ID, \
                           ZCL_CLEAR_EVENT_LOG_REQUEST_COMMAND_ID, \
                           "u", \
							  logId);



/** @brief This command is generated on receipt of a GetEventLog command. The command returns the most recent event first and up to the number of events requested.
* Cluster: Events, This cluster provides an interface on which applications can use event-based protocols.
* Command: PublishEventLog
* @param totalNumberOfEvents uint16_t

* @param commandIndex uint8_t

* @param totalCommands uint8_t

* @param logPayloadControl uint8_t

* @param logPayload uint8_t *
* @param logPayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_events_cluster_publish_event_log( \
  totalNumberOfEvents,  commandIndex,  totalCommands,  logPayloadControl,  logPayload, logPayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_EVENTS_CLUSTER_ID, \
                           ZCL_PUBLISH_EVENT_LOG_COMMAND_ID, \
                           "vuuub", \
							  totalNumberOfEvents,							  commandIndex,							  totalCommands,							  logPayloadControl,							  logPayload, logPayloadLen);



/** @brief This command is generated on receipt of a Clear Event Log Request command.
* Cluster: Events, This cluster provides an interface on which applications can use event-based protocols.
* Command: ClearEventLogResponse
* @param clearedEventsLogs uint8_t

*/
#define sl_zigbee_af_fill_command_events_cluster_clear_event_log_response( \
  clearedEventsLogs) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_EVENTS_CLUSTER_ID, \
                           ZCL_CLEAR_EVENT_LOG_RESPONSE_COMMAND_ID, \
                           "u", \
							  clearedEventsLogs);



/** @brief The Pairing Response command provides a device joining a MDU network with a list of the devices that will constitute the 'virtual HAN' for the household in which the joining device is to operate.
* Cluster: MDU Pairing, This cluster seeks to assist in the commissioning of networks that include multi-dwelling units (MDUs).
* Command: PairingResponse
* @param pairingInformationVersion uint32_t

* @param totalNumberOfDevices uint8_t

* @param commandIndex uint8_t

* @param totalNumberOfCommands uint8_t

* @param eui64s uint8_t *
* @param eui64sLen uint16_t 
*/
#define sl_zigbee_af_fill_command_mdu_pairing_cluster_pairing_response( \
  pairingInformationVersion,  totalNumberOfDevices,  commandIndex,  totalNumberOfCommands,  eui64s, eui64sLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_MDU_PAIRING_CLUSTER_ID, \
                           ZCL_PAIRING_RESPONSE_COMMAND_ID, \
                           "wuuub", \
							  pairingInformationVersion,							  totalNumberOfDevices,							  commandIndex,							  totalNumberOfCommands,							  eui64s, eui64sLen);



/** @brief The Pairing Request command allows a device joining a MDU network to determine the devices that will constitute the 'virtual HAN' for the household in which it is to operate.
* Cluster: MDU Pairing, This cluster seeks to assist in the commissioning of networks that include multi-dwelling units (MDUs).
* Command: PairingRequest
* @param localPairingInformationVersion uint32_t

* @param eui64OfRequestingDevice uint8_t *

*/
#define sl_zigbee_af_fill_command_mdu_pairing_cluster_pairing_request( \
  localPairingInformationVersion,  eui64OfRequestingDevice) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_MDU_PAIRING_CLUSTER_ID, \
                           ZCL_PAIRING_REQUEST_COMMAND_ID, \
                           "w8", \
							  localPairingInformationVersion,							  eui64OfRequestingDevice);



/** @brief The server sends it to temporarily suspend ZCL messages from clients it identifies as causing too much traffic.
* Cluster: Sub-GHz, Used by the Smart Energy profile for duty cycle monitoring and frequency agility.
* Command: SuspendZclMessages
* @param period uint8_t

*/
#define sl_zigbee_af_fill_command_sub_ghz_cluster_suspend_zcl_messages( \
  period) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SUB_GHZ_CLUSTER_ID, \
                           ZCL_SUSPEND_ZCL_MESSAGES_COMMAND_ID, \
                           "u", \
							  period);



/** @brief The client sends it to determine the current status of its ZCL communications from the server.
* Cluster: Sub-GHz, Used by the Smart Energy profile for duty cycle monitoring and frequency agility.
* Command: GetSuspendZclMessagesStatus
*/
#define sl_zigbee_af_fill_command_sub_ghz_cluster_get_suspend_zcl_messages_status( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SUB_GHZ_CLUSTER_ID, \
                           ZCL_GET_SUSPEND_ZCL_MESSAGES_STATUS_COMMAND_ID, \
                           "" \
);



/** @brief Command description for InitiateKeyEstablishmentRequest
* Cluster: Key Establishment, Key Establishment cluster
* Command: InitiateKeyEstablishmentRequest
* @param keyEstablishmentSuite uint16_t

* @param ephemeralDataGenerateTime uint8_t

* @param confirmKeyGenerateTime uint8_t

* @param identity Identity

*/
#define sl_zigbee_af_fill_command_key_establishment_cluster_initiate_key_establishment_request( \
  keyEstablishmentSuite,  ephemeralDataGenerateTime,  confirmKeyGenerateTime,  identity) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_KEY_ESTABLISHMENT_CLUSTER_ID, \
                           ZCL_INITIATE_KEY_ESTABLISHMENT_REQUEST_COMMAND_ID, \
                           "vuub", \
							  keyEstablishmentSuite,							  ephemeralDataGenerateTime,							  confirmKeyGenerateTime,							  identity);



/** @brief Command description for InitiateKeyEstablishmentResponse
* Cluster: Key Establishment, Key Establishment cluster
* Command: InitiateKeyEstablishmentResponse
* @param requestedKeyEstablishmentSuite uint16_t

* @param ephemeralDataGenerateTime uint8_t

* @param confirmKeyGenerateTime uint8_t

* @param identity Identity

*/
#define sl_zigbee_af_fill_command_key_establishment_cluster_initiate_key_establishment_response( \
  requestedKeyEstablishmentSuite,  ephemeralDataGenerateTime,  confirmKeyGenerateTime,  identity) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_KEY_ESTABLISHMENT_CLUSTER_ID, \
                           ZCL_INITIATE_KEY_ESTABLISHMENT_RESPONSE_COMMAND_ID, \
                           "vuub", \
							  requestedKeyEstablishmentSuite,							  ephemeralDataGenerateTime,							  confirmKeyGenerateTime,							  identity);



/** @brief Command description for EphemeralDataRequest
* Cluster: Key Establishment, Key Establishment cluster
* Command: EphemeralDataRequest
* @param ephemeralData EphemeralData

*/
#define sl_zigbee_af_fill_command_key_establishment_cluster_ephemeral_data_request( \
  ephemeralData) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_KEY_ESTABLISHMENT_CLUSTER_ID, \
                           ZCL_EPHEMERAL_DATA_REQUEST_COMMAND_ID, \
                           "b", \
							  ephemeralData);



/** @brief Command description for EphemeralDataResponse
* Cluster: Key Establishment, Key Establishment cluster
* Command: EphemeralDataResponse
* @param ephemeralData EphemeralData

*/
#define sl_zigbee_af_fill_command_key_establishment_cluster_ephemeral_data_response( \
  ephemeralData) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_KEY_ESTABLISHMENT_CLUSTER_ID, \
                           ZCL_EPHEMERAL_DATA_RESPONSE_COMMAND_ID, \
                           "b", \
							  ephemeralData);



/** @brief Command description for ConfirmKeyDataRequest
* Cluster: Key Establishment, Key Establishment cluster
* Command: ConfirmKeyDataRequest
* @param secureMessageAuthenticationCode Smac

*/
#define sl_zigbee_af_fill_command_key_establishment_cluster_confirm_key_data_request( \
  secureMessageAuthenticationCode) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_KEY_ESTABLISHMENT_CLUSTER_ID, \
                           ZCL_CONFIRM_KEY_DATA_REQUEST_COMMAND_ID, \
                           "b", \
							  secureMessageAuthenticationCode);



/** @brief Command description for ConfirmKeyDataResponse
* Cluster: Key Establishment, Key Establishment cluster
* Command: ConfirmKeyDataResponse
* @param secureMessageAuthenticationCode Smac

*/
#define sl_zigbee_af_fill_command_key_establishment_cluster_confirm_key_data_response( \
  secureMessageAuthenticationCode) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_KEY_ESTABLISHMENT_CLUSTER_ID, \
                           ZCL_CONFIRM_KEY_DATA_RESPONSE_COMMAND_ID, \
                           "b", \
							  secureMessageAuthenticationCode);



/** @brief Command description for TerminateKeyEstablishment
* Cluster: Key Establishment, Key Establishment cluster
* Command: TerminateKeyEstablishmentFromClient
* @param statusCode uint8_t

* @param waitTime uint8_t

* @param keyEstablishmentSuite uint16_t

*/
#define sl_zigbee_af_fill_command_key_establishment_cluster_terminate_key_establishment_from_client( \
  statusCode,  waitTime,  keyEstablishmentSuite) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_KEY_ESTABLISHMENT_CLUSTER_ID, \
                           ZCL_TERMINATE_KEY_ESTABLISHMENT_FROM_CLIENT_COMMAND_ID, \
                           "uuv", \
							  statusCode,							  waitTime,							  keyEstablishmentSuite);



/** @brief Command description for TerminateKeyEstablishment
* Cluster: Key Establishment, Key Establishment cluster
* Command: TerminateKeyEstablishmentFromServer
* @param statusCode uint8_t

* @param waitTime uint8_t

* @param keyEstablishmentSuite uint16_t

*/
#define sl_zigbee_af_fill_command_key_establishment_cluster_terminate_key_establishment_from_server( \
  statusCode,  waitTime,  keyEstablishmentSuite) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_KEY_ESTABLISHMENT_CLUSTER_ID, \
                           ZCL_TERMINATE_KEY_ESTABLISHMENT_FROM_SERVER_COMMAND_ID, \
                           "uuv", \
							  statusCode,							  waitTime,							  keyEstablishmentSuite);



/** @brief Command description for RequestInformation
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: RequestInformation
* @param inquiryId uint8_t

* @param dataTypeId uint8_t

* @param requestInformationPayload uint8_t *
* @param requestInformationPayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_information_cluster_request_information( \
  inquiryId,  dataTypeId,  requestInformationPayload, requestInformationPayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_REQUEST_INFORMATION_COMMAND_ID, \
                           "uub", \
							  inquiryId,							  dataTypeId,							  requestInformationPayload, requestInformationPayloadLen);



/** @brief Command description for RequestInformationResponse
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: RequestInformationResponse
* @param number uint8_t

* @param buffer uint8_t *
* @param bufferLen uint16_t 
*/
#define sl_zigbee_af_fill_command_information_cluster_request_information_response( \
  number,  buffer, bufferLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_REQUEST_INFORMATION_RESPONSE_COMMAND_ID, \
                           "ub", \
							  number,							  buffer, bufferLen);



/** @brief Command description for PushInformationResponse
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: PushInformationResponse
* @param notificationList uint8_t *
* @param notificationListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_information_cluster_push_information_response( \
  notificationList, notificationListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_PUSH_INFORMATION_RESPONSE_COMMAND_ID, \
                           "b", \
							  notificationList, notificationListLen);



/** @brief Command description for PushInformation
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: PushInformation
* @param contents uint8_t *
* @param contentsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_information_cluster_push_information( \
  contents, contentsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_PUSH_INFORMATION_COMMAND_ID, \
                           "b", \
							  contents, contentsLen);



/** @brief Command description for SendPreference
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: SendPreference
* @param preferenceType uint16_t

* @param preferencePayload uint8_t *
* @param preferencePayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_information_cluster_send_preference( \
  preferenceType,  preferencePayload, preferencePayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_SEND_PREFERENCE_COMMAND_ID, \
                           "vb", \
							  preferenceType,							  preferencePayload, preferencePayloadLen);



/** @brief Command description for SendPreferenceResponse
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: SendPreferenceResponse
* @param statusFeedbackList uint8_t *
* @param statusFeedbackListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_information_cluster_send_preference_response( \
  statusFeedbackList, statusFeedbackListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_SEND_PREFERENCE_RESPONSE_COMMAND_ID, \
                           "b", \
							  statusFeedbackList, statusFeedbackListLen);



/** @brief Command description for RequestPreferenceResponse
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: RequestPreferenceResponse
* @param statusFeedback uint8_t

* @param preferenceType uint16_t

* @param preferencePayload uint8_t *
* @param preferencePayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_information_cluster_request_preference_response( \
  statusFeedback,  preferenceType,  preferencePayload, preferencePayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_REQUEST_PREFERENCE_RESPONSE_COMMAND_ID, \
                           "uvb", \
							  statusFeedback,							  preferenceType,							  preferencePayload, preferencePayloadLen);



/** @brief Command description for ServerRequestPreference
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: ServerRequestPreference
*/
#define sl_zigbee_af_fill_command_information_cluster_server_request_preference( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_SERVER_REQUEST_PREFERENCE_COMMAND_ID, \
                           "" \
);



/** @brief Command description for Update
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: Update
* @param accessControl uint8_t

* @param option uint8_t

* @param contents uint8_t *
* @param contentsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_information_cluster_update( \
  accessControl,  option,  contents, contentsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_UPDATE_COMMAND_ID, \
                           "uub", \
							  accessControl,							  option,							  contents, contentsLen);



/** @brief Command description for RequestPreferenceConfirmation
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: RequestPreferenceConfirmation
* @param statusFeedbackList uint8_t *
* @param statusFeedbackListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_information_cluster_request_preference_confirmation( \
  statusFeedbackList, statusFeedbackListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_REQUEST_PREFERENCE_CONFIRMATION_COMMAND_ID, \
                           "b", \
							  statusFeedbackList, statusFeedbackListLen);



/** @brief Command description for Delete
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: Delete
* @param deletionOptions uint8_t

* @param contentIds uint8_t *
* @param contentIdsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_information_cluster_delete( \
  deletionOptions,  contentIds, contentIdsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_DELETE_COMMAND_ID, \
                           "ub", \
							  deletionOptions,							  contentIds, contentIdsLen);



/** @brief Command description for UpdateResponse
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: UpdateResponse
* @param notificationList uint8_t *
* @param notificationListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_information_cluster_update_response( \
  notificationList, notificationListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_UPDATE_RESPONSE_COMMAND_ID, \
                           "b", \
							  notificationList, notificationListLen);



/** @brief Command description for ConfigureNodeDescription
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: ConfigureNodeDescription
* @param description uint8_t *

*/
#define sl_zigbee_af_fill_command_information_cluster_configure_node_description( \
  description) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_CONFIGURE_NODE_DESCRIPTION_COMMAND_ID, \
                           "s", \
							  description);



/** @brief Command description for DeleteResponse
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: DeleteResponse
* @param notificationList uint8_t *
* @param notificationListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_information_cluster_delete_response( \
  notificationList, notificationListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_DELETE_RESPONSE_COMMAND_ID, \
                           "b", \
							  notificationList, notificationListLen);



/** @brief Command description for ConfigureDeliveryEnable
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: ConfigureDeliveryEnable
* @param enable uint8_t

*/
#define sl_zigbee_af_fill_command_information_cluster_configure_delivery_enable( \
  enable) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_CONFIGURE_DELIVERY_ENABLE_COMMAND_ID, \
                           "u", \
							  enable);



/** @brief Command description for ConfigurePushInformationTimer
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: ConfigurePushInformationTimer
* @param timer uint32_t

*/
#define sl_zigbee_af_fill_command_information_cluster_configure_push_information_timer( \
  timer) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_CONFIGURE_PUSH_INFORMATION_TIMER_COMMAND_ID, \
                           "w", \
							  timer);



/** @brief Command description for ConfigureSetRootId
* Cluster: Information, Provides commands and attributes for information delivery service on ZigBee networks.
* Command: ConfigureSetRootId
* @param rootId uint16_t

*/
#define sl_zigbee_af_fill_command_information_cluster_configure_set_root_id( \
  rootId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_INFORMATION_CLUSTER_ID, \
                           ZCL_CONFIGURE_SET_ROOT_ID_COMMAND_ID, \
                           "v", \
							  rootId);



/** @brief Command description for ReadFileRequest
* Cluster: Data Sharing, Commands and attributes for small data sharing among ZigBee devices.
* Command: ReadFileRequest
* @param fileIndex uint16_t

* @param fileStartPositionAndRequestedOctetCount uint8_t *
* @param fileStartPositionAndRequestedOctetCountLen uint16_t 
*/
#define sl_zigbee_af_fill_command_data_sharing_cluster_read_file_request( \
  fileIndex,  fileStartPositionAndRequestedOctetCount, fileStartPositionAndRequestedOctetCountLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DATA_SHARING_CLUSTER_ID, \
                           ZCL_READ_FILE_REQUEST_COMMAND_ID, \
                           "vb", \
							  fileIndex,							  fileStartPositionAndRequestedOctetCount, fileStartPositionAndRequestedOctetCountLen);



/** @brief Command description for WriteFileRequest
* Cluster: Data Sharing, Commands and attributes for small data sharing among ZigBee devices.
* Command: WriteFileRequest
* @param writeOptions uint8_t

* @param fileSize uint8_t *
* @param fileSizeLen uint16_t 
*/
#define sl_zigbee_af_fill_command_data_sharing_cluster_write_file_request( \
  writeOptions,  fileSize, fileSizeLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DATA_SHARING_CLUSTER_ID, \
                           ZCL_WRITE_FILE_REQUEST_COMMAND_ID, \
                           "ub", \
							  writeOptions,							  fileSize, fileSizeLen);



/** @brief Command description for ReadRecordRequest
* Cluster: Data Sharing, Commands and attributes for small data sharing among ZigBee devices.
* Command: ReadRecordRequest
* @param fileIndex uint16_t

* @param fileStartRecordAndRequestedRecordCount uint8_t *
* @param fileStartRecordAndRequestedRecordCountLen uint16_t 
*/
#define sl_zigbee_af_fill_command_data_sharing_cluster_read_record_request( \
  fileIndex,  fileStartRecordAndRequestedRecordCount, fileStartRecordAndRequestedRecordCountLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DATA_SHARING_CLUSTER_ID, \
                           ZCL_READ_RECORD_REQUEST_COMMAND_ID, \
                           "vb", \
							  fileIndex,							  fileStartRecordAndRequestedRecordCount, fileStartRecordAndRequestedRecordCountLen);



/** @brief Command description for ModifyFileRequest
* Cluster: Data Sharing, Commands and attributes for small data sharing among ZigBee devices.
* Command: ModifyFileRequest
* @param fileIndex uint16_t

* @param fileStartPosition uint32_t

* @param octetCount uint32_t

*/
#define sl_zigbee_af_fill_command_data_sharing_cluster_modify_file_request( \
  fileIndex,  fileStartPosition,  octetCount) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DATA_SHARING_CLUSTER_ID, \
                           ZCL_MODIFY_FILE_REQUEST_COMMAND_ID, \
                           "vww", \
							  fileIndex,							  fileStartPosition,							  octetCount);



/** @brief Command description for WriteFileResponse
* Cluster: Data Sharing, Commands and attributes for small data sharing among ZigBee devices.
* Command: WriteFileResponse
* @param status uint8_t

* @param fileIndex uint8_t *
* @param fileIndexLen uint16_t 
*/
#define sl_zigbee_af_fill_command_data_sharing_cluster_write_file_response( \
  status,  fileIndex, fileIndexLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DATA_SHARING_CLUSTER_ID, \
                           ZCL_WRITE_FILE_RESPONSE_COMMAND_ID, \
                           "ub", \
							  status,							  fileIndex, fileIndexLen);



/** @brief Command description for ModifyRecordRequest
* Cluster: Data Sharing, Commands and attributes for small data sharing among ZigBee devices.
* Command: ModifyRecordRequest
* @param fileIndex uint16_t

* @param fileStartRecord uint16_t

* @param recordCount uint16_t

*/
#define sl_zigbee_af_fill_command_data_sharing_cluster_modify_record_request( \
  fileIndex,  fileStartRecord,  recordCount) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DATA_SHARING_CLUSTER_ID, \
                           ZCL_MODIFY_RECORD_REQUEST_COMMAND_ID, \
                           "vvv", \
							  fileIndex,							  fileStartRecord,							  recordCount);



/** @brief Command description for FileTransmission
* Cluster: Data Sharing, Commands and attributes for small data sharing among ZigBee devices.
* Command: FileTransmission
* @param transmitOptions uint8_t

* @param buffer uint8_t *
* @param bufferLen uint16_t 
*/
#define sl_zigbee_af_fill_command_data_sharing_cluster_file_transmission( \
  transmitOptions,  buffer, bufferLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DATA_SHARING_CLUSTER_ID, \
                           ZCL_FILE_TRANSMISSION_COMMAND_ID, \
                           "ub", \
							  transmitOptions,							  buffer, bufferLen);



/** @brief Command description for RecordTransmission
* Cluster: Data Sharing, Commands and attributes for small data sharing among ZigBee devices.
* Command: RecordTransmission
* @param transmitOptions uint8_t

* @param buffer uint8_t *
* @param bufferLen uint16_t 
*/
#define sl_zigbee_af_fill_command_data_sharing_cluster_record_transmission( \
  transmitOptions,  buffer, bufferLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DATA_SHARING_CLUSTER_ID, \
                           ZCL_RECORD_TRANSMISSION_COMMAND_ID, \
                           "ub", \
							  transmitOptions,							  buffer, bufferLen);



/** @brief Command description for SearchGame
* Cluster: Gaming, Attributes and commands to support gaming functions of ZigBee-enabled mobile terminals.
* Command: SearchGame
* @param specificGame uint8_t

* @param gameId uint16_t

*/
#define sl_zigbee_af_fill_command_gaming_cluster_search_game( \
  specificGame,  gameId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GAMING_CLUSTER_ID, \
                           ZCL_SEARCH_GAME_COMMAND_ID, \
                           "uv", \
							  specificGame,							  gameId);



/** @brief Command description for GameAnnouncement
* Cluster: Gaming, Attributes and commands to support gaming functions of ZigBee-enabled mobile terminals.
* Command: GameAnnouncement
* @param gameId uint16_t

* @param gameMaster uint8_t

* @param listOfGame uint8_t *

*/
#define sl_zigbee_af_fill_command_gaming_cluster_game_announcement( \
  gameId,  gameMaster,  listOfGame) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GAMING_CLUSTER_ID, \
                           ZCL_GAME_ANNOUNCEMENT_COMMAND_ID, \
                           "vus", \
							  gameId,							  gameMaster,							  listOfGame);



/** @brief Command description for JoinGame
* Cluster: Gaming, Attributes and commands to support gaming functions of ZigBee-enabled mobile terminals.
* Command: JoinGame
* @param gameId uint16_t

* @param joinAsMaster uint8_t

* @param nameOfGame uint8_t *

*/
#define sl_zigbee_af_fill_command_gaming_cluster_join_game( \
  gameId,  joinAsMaster,  nameOfGame) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GAMING_CLUSTER_ID, \
                           ZCL_JOIN_GAME_COMMAND_ID, \
                           "vus", \
							  gameId,							  joinAsMaster,							  nameOfGame);



/** @brief Command description for GeneralResponse
* Cluster: Gaming, Attributes and commands to support gaming functions of ZigBee-enabled mobile terminals.
* Command: GeneralResponse
* @param commandId uint8_t

* @param status uint8_t

* @param message uint8_t *

*/
#define sl_zigbee_af_fill_command_gaming_cluster_general_response( \
  commandId,  status,  message) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_GAMING_CLUSTER_ID, \
                           ZCL_GENERAL_RESPONSE_COMMAND_ID, \
                           "uus", \
							  commandId,							  status,							  message);



/** @brief Command description for StartGame
* Cluster: Gaming, Attributes and commands to support gaming functions of ZigBee-enabled mobile terminals.
* Command: StartGame
*/
#define sl_zigbee_af_fill_command_gaming_cluster_start_game( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GAMING_CLUSTER_ID, \
                           ZCL_START_GAME_COMMAND_ID, \
                           "" \
);



/** @brief Command description for PauseGame
* Cluster: Gaming, Attributes and commands to support gaming functions of ZigBee-enabled mobile terminals.
* Command: PauseGame
*/
#define sl_zigbee_af_fill_command_gaming_cluster_pause_game( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GAMING_CLUSTER_ID, \
                           ZCL_PAUSE_GAME_COMMAND_ID, \
                           "" \
);



/** @brief Command description for ResumeGame
* Cluster: Gaming, Attributes and commands to support gaming functions of ZigBee-enabled mobile terminals.
* Command: ResumeGame
*/
#define sl_zigbee_af_fill_command_gaming_cluster_resume_game( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GAMING_CLUSTER_ID, \
                           ZCL_RESUME_GAME_COMMAND_ID, \
                           "" \
);



/** @brief Command description for QuitGame
* Cluster: Gaming, Attributes and commands to support gaming functions of ZigBee-enabled mobile terminals.
* Command: QuitGame
*/
#define sl_zigbee_af_fill_command_gaming_cluster_quit_game( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GAMING_CLUSTER_ID, \
                           ZCL_QUIT_GAME_COMMAND_ID, \
                           "" \
);



/** @brief Command description for EndGame
* Cluster: Gaming, Attributes and commands to support gaming functions of ZigBee-enabled mobile terminals.
* Command: EndGame
*/
#define sl_zigbee_af_fill_command_gaming_cluster_end_game( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GAMING_CLUSTER_ID, \
                           ZCL_END_GAME_COMMAND_ID, \
                           "" \
);



/** @brief Command description for StartOver
* Cluster: Gaming, Attributes and commands to support gaming functions of ZigBee-enabled mobile terminals.
* Command: StartOver
*/
#define sl_zigbee_af_fill_command_gaming_cluster_start_over( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GAMING_CLUSTER_ID, \
                           ZCL_START_OVER_COMMAND_ID, \
                           "" \
);



/** @brief Command description for ActionControl
* Cluster: Gaming, Attributes and commands to support gaming functions of ZigBee-enabled mobile terminals.
* Command: ActionControl
* @param actions uint32_t

*/
#define sl_zigbee_af_fill_command_gaming_cluster_action_control( \
  actions) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GAMING_CLUSTER_ID, \
                           ZCL_ACTION_CONTROL_COMMAND_ID, \
                           "w", \
							  actions);



/** @brief Command description for DownloadGame
* Cluster: Gaming, Attributes and commands to support gaming functions of ZigBee-enabled mobile terminals.
* Command: DownloadGame
*/
#define sl_zigbee_af_fill_command_gaming_cluster_download_game( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_GAMING_CLUSTER_ID, \
                           ZCL_DOWNLOAD_GAME_COMMAND_ID, \
                           "" \
);



/** @brief Command description for PathCreation
* Cluster: Data Rate Control, This cluster seeks to give applications a means to managing data rate. It provides commands and attributes which form this interface.
* Command: PathCreation
* @param originatorAddress uint16_t

* @param destinationAddress uint16_t

* @param dataRate uint8_t

*/
#define sl_zigbee_af_fill_command_data_rate_control_cluster_path_creation( \
  originatorAddress,  destinationAddress,  dataRate) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DATA_RATE_CONTROL_CLUSTER_ID, \
                           ZCL_PATH_CREATION_COMMAND_ID, \
                           "vvu", \
							  originatorAddress,							  destinationAddress,							  dataRate);



/** @brief Command description for DataRateControl
* Cluster: Data Rate Control, This cluster seeks to give applications a means to managing data rate. It provides commands and attributes which form this interface.
* Command: DataRateControl
* @param originatorAddress uint16_t

* @param destinationAddress uint16_t

* @param dataRate uint8_t

*/
#define sl_zigbee_af_fill_command_data_rate_control_cluster_data_rate_control( \
  originatorAddress,  destinationAddress,  dataRate) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_DATA_RATE_CONTROL_CLUSTER_ID, \
                           ZCL_DATA_RATE_CONTROL_COMMAND_ID, \
                           "vvu", \
							  originatorAddress,							  destinationAddress,							  dataRate);



/** @brief Command description for DataRateNotification
* Cluster: Data Rate Control, This cluster seeks to give applications a means to managing data rate. It provides commands and attributes which form this interface.
* Command: DataRateNotification
* @param originatorAddress uint16_t

* @param destinationAddress uint16_t

* @param dataRate uint8_t

*/
#define sl_zigbee_af_fill_command_data_rate_control_cluster_data_rate_notification( \
  originatorAddress,  destinationAddress,  dataRate) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DATA_RATE_CONTROL_CLUSTER_ID, \
                           ZCL_DATA_RATE_NOTIFICATION_COMMAND_ID, \
                           "vvu", \
							  originatorAddress,							  destinationAddress,							  dataRate);



/** @brief Command description for PathDeletion
* Cluster: Data Rate Control, This cluster seeks to give applications a means to managing data rate. It provides commands and attributes which form this interface.
* Command: PathDeletion
* @param originatorAddress uint16_t

* @param destinationAddress uint16_t

*/
#define sl_zigbee_af_fill_command_data_rate_control_cluster_path_deletion( \
  originatorAddress,  destinationAddress) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_DATA_RATE_CONTROL_CLUSTER_ID, \
                           ZCL_PATH_DELETION_COMMAND_ID, \
                           "vv", \
							  originatorAddress,							  destinationAddress);



/** @brief Command description for EstablishmentRequest
* Cluster: Voice over ZigBee, This cluster seeks to provide an interface to a voice over ZigBee protocol.
* Command: EstablishmentRequest
* @param flag uint8_t

* @param codecType uint8_t

* @param sampFreq uint8_t

* @param codecRate uint8_t

* @param serviceType uint8_t

* @param buffer uint8_t *
* @param bufferLen uint16_t 
*/
#define sl_zigbee_af_fill_command_voice_over_zigbee_cluster_establishment_request( \
  flag,  codecType,  sampFreq,  codecRate,  serviceType,  buffer, bufferLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_VOICE_OVER_ZIGBEE_CLUSTER_ID, \
                           ZCL_ESTABLISHMENT_REQUEST_COMMAND_ID, \
                           "uuuuub", \
							  flag,							  codecType,							  sampFreq,							  codecRate,							  serviceType,							  buffer, bufferLen);



/** @brief Command description for EstablishmentResponse
* Cluster: Voice over ZigBee, This cluster seeks to provide an interface to a voice over ZigBee protocol.
* Command: EstablishmentResponse
* @param ackNack uint8_t

* @param codecType uint8_t

*/
#define sl_zigbee_af_fill_command_voice_over_zigbee_cluster_establishment_response( \
  ackNack,  codecType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_VOICE_OVER_ZIGBEE_CLUSTER_ID, \
                           ZCL_ESTABLISHMENT_RESPONSE_COMMAND_ID, \
                           "uu", \
							  ackNack,							  codecType);



/** @brief Command description for VoiceTransmission
* Cluster: Voice over ZigBee, This cluster seeks to provide an interface to a voice over ZigBee protocol.
* Command: VoiceTransmission
* @param voiceData uint8_t *
* @param voiceDataLen uint16_t 
*/
#define sl_zigbee_af_fill_command_voice_over_zigbee_cluster_voice_transmission( \
  voiceData, voiceDataLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_VOICE_OVER_ZIGBEE_CLUSTER_ID, \
                           ZCL_VOICE_TRANSMISSION_COMMAND_ID, \
                           "b", \
							  voiceData, voiceDataLen);



/** @brief Command description for VoiceTransmissionResponse
* Cluster: Voice over ZigBee, This cluster seeks to provide an interface to a voice over ZigBee protocol.
* Command: VoiceTransmissionResponse
* @param sequenceNumber uint8_t

* @param errorFlag uint8_t

*/
#define sl_zigbee_af_fill_command_voice_over_zigbee_cluster_voice_transmission_response( \
  sequenceNumber,  errorFlag) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_VOICE_OVER_ZIGBEE_CLUSTER_ID, \
                           ZCL_VOICE_TRANSMISSION_RESPONSE_COMMAND_ID, \
                           "uu", \
							  sequenceNumber,							  errorFlag);



/** @brief Command description for VoiceTransmissionCompletion
* Cluster: Voice over ZigBee, This cluster seeks to provide an interface to a voice over ZigBee protocol.
* Command: VoiceTransmissionCompletion
*/
#define sl_zigbee_af_fill_command_voice_over_zigbee_cluster_voice_transmission_completion( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_VOICE_OVER_ZIGBEE_CLUSTER_ID, \
                           ZCL_VOICE_TRANSMISSION_COMPLETION_COMMAND_ID, \
                           "" \
);



/** @brief Command description for Control
* Cluster: Voice over ZigBee, This cluster seeks to provide an interface to a voice over ZigBee protocol.
* Command: Control
* @param controlType uint8_t

*/
#define sl_zigbee_af_fill_command_voice_over_zigbee_cluster_control( \
  controlType) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_VOICE_OVER_ZIGBEE_CLUSTER_ID, \
                           ZCL_CONTROL_COMMAND_ID, \
                           "u", \
							  controlType);



/** @brief Command description for ControlResponse
* Cluster: Voice over ZigBee, This cluster seeks to provide an interface to a voice over ZigBee protocol.
* Command: ControlResponse
* @param ackNack uint8_t

*/
#define sl_zigbee_af_fill_command_voice_over_zigbee_cluster_control_response( \
  ackNack) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_VOICE_OVER_ZIGBEE_CLUSTER_ID, \
                           ZCL_CONTROL_RESPONSE_COMMAND_ID, \
                           "u", \
							  ackNack);



/** @brief Command description for JoinChatRequest
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: JoinChatRequest
* @param uid uint16_t

* @param nickname uint8_t *

* @param cid uint16_t

*/
#define sl_zigbee_af_fill_command_chatting_cluster_join_chat_request( \
  uid,  nickname,  cid) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_JOIN_CHAT_REQUEST_COMMAND_ID, \
                           "vsv", \
							  uid,							  nickname,							  cid);



/** @brief Command description for StartChatResponse
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: StartChatResponse
* @param status uint8_t

* @param cid uint16_t

*/
#define sl_zigbee_af_fill_command_chatting_cluster_start_chat_response( \
  status,  cid) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_START_CHAT_RESPONSE_COMMAND_ID, \
                           "uv", \
							  status,							  cid);



/** @brief Command description for LeaveChatRequest
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: LeaveChatRequest
* @param cid uint16_t

* @param uid uint16_t

*/
#define sl_zigbee_af_fill_command_chatting_cluster_leave_chat_request( \
  cid,  uid) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_LEAVE_CHAT_REQUEST_COMMAND_ID, \
                           "vv", \
							  cid,							  uid);



/** @brief Command description for JoinChatResponse
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: JoinChatResponse
* @param status uint8_t

* @param cid uint16_t

* @param chatParticipantList uint8_t *
* @param chatParticipantListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_chatting_cluster_join_chat_response( \
  status,  cid,  chatParticipantList, chatParticipantListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_JOIN_CHAT_RESPONSE_COMMAND_ID, \
                           "uvb", \
							  status,							  cid,							  chatParticipantList, chatParticipantListLen);



/** @brief Command description for SearchChatRequest
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: SearchChatRequest
*/
#define sl_zigbee_af_fill_command_chatting_cluster_search_chat_request( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_SEARCH_CHAT_REQUEST_COMMAND_ID, \
                           "" \
);



/** @brief Command description for UserLeft
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: UserLeft
* @param cid uint16_t

* @param uid uint16_t

* @param nickname uint8_t *

*/
#define sl_zigbee_af_fill_command_chatting_cluster_user_left( \
  cid,  uid,  nickname) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_USER_LEFT_COMMAND_ID, \
                           "vvs", \
							  cid,							  uid,							  nickname);



/** @brief Command description for SwitchChairmanResponse
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: SwitchChairmanResponse
* @param cid uint16_t

* @param uid uint16_t

*/
#define sl_zigbee_af_fill_command_chatting_cluster_switch_chairman_response( \
  cid,  uid) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_SWITCH_CHAIRMAN_RESPONSE_COMMAND_ID, \
                           "vv", \
							  cid,							  uid);



/** @brief Command description for UserJoined
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: UserJoined
* @param cid uint16_t

* @param uid uint16_t

* @param nickname uint8_t *

*/
#define sl_zigbee_af_fill_command_chatting_cluster_user_joined( \
  cid,  uid,  nickname) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_USER_JOINED_COMMAND_ID, \
                           "vvs", \
							  cid,							  uid,							  nickname);



/** @brief Command description for StartChatRequest
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: StartChatRequest
* @param name uint8_t *

* @param uid uint16_t

* @param nickname uint8_t *

*/
#define sl_zigbee_af_fill_command_chatting_cluster_start_chat_request( \
  name,  uid,  nickname) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_START_CHAT_REQUEST_COMMAND_ID, \
                           "svs", \
							  name,							  uid,							  nickname);



/** @brief Command description for SearchChatResponse
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: SearchChatResponse
* @param options uint8_t

* @param chatRoomList uint8_t *
* @param chatRoomListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_chatting_cluster_search_chat_response( \
  options,  chatRoomList, chatRoomListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_SEARCH_CHAT_RESPONSE_COMMAND_ID, \
                           "ub", \
							  options,							  chatRoomList, chatRoomListLen);



/** @brief Command description for ChatMessage
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: ChatMessage
* @param destinationUid uint16_t

* @param sourceUid uint16_t

* @param cid uint16_t

* @param nickname uint8_t *

* @param message uint8_t *

*/
#define sl_zigbee_af_fill_command_chatting_cluster_chat_message( \
  destinationUid,  sourceUid,  cid,  nickname,  message) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_CHAT_MESSAGE_COMMAND_ID, \
                           "vvvss", \
							  destinationUid,							  sourceUid,							  cid,							  nickname,							  message);



/** @brief Command description for SwitchChairmanRequest
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: SwitchChairmanRequest
* @param cid uint16_t

*/
#define sl_zigbee_af_fill_command_chatting_cluster_switch_chairman_request( \
  cid) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_SWITCH_CHAIRMAN_REQUEST_COMMAND_ID, \
                           "v", \
							  cid);



/** @brief Command description for GetNodeInformationRequest
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: GetNodeInformationRequest
* @param cid uint16_t

* @param uid uint16_t

*/
#define sl_zigbee_af_fill_command_chatting_cluster_get_node_information_request( \
  cid,  uid) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_GET_NODE_INFORMATION_REQUEST_COMMAND_ID, \
                           "vv", \
							  cid,							  uid);



/** @brief Command description for SwitchChairmanConfirm
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: SwitchChairmanConfirm
* @param cid uint16_t

* @param nodeInformationList uint8_t *
* @param nodeInformationListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_chatting_cluster_switch_chairman_confirm( \
  cid,  nodeInformationList, nodeInformationListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_SWITCH_CHAIRMAN_CONFIRM_COMMAND_ID, \
                           "vb", \
							  cid,							  nodeInformationList, nodeInformationListLen);



/** @brief Command description for SwitchChairmanNotification
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: SwitchChairmanNotification
* @param cid uint16_t

* @param uid uint16_t

* @param address uint16_t

* @param endpoint uint8_t

*/
#define sl_zigbee_af_fill_command_chatting_cluster_switch_chairman_notification( \
  cid,  uid,  address,  endpoint) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_SWITCH_CHAIRMAN_NOTIFICATION_COMMAND_ID, \
                           "vvvu", \
							  cid,							  uid,							  address,							  endpoint);



/** @brief Command description for GetNodeInformationResponse
* Cluster: Chatting, Commands and attributes for sending chat messages among ZigBee devices.
* Command: GetNodeInformationResponse
* @param status uint8_t

* @param cid uint16_t

* @param uid uint16_t

* @param addressEndpointAndNickname uint8_t *
* @param addressEndpointAndNicknameLen uint16_t 
*/
#define sl_zigbee_af_fill_command_chatting_cluster_get_node_information_response( \
  status,  cid,  uid,  addressEndpointAndNickname, addressEndpointAndNicknameLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_CHATTING_CLUSTER_ID, \
                           ZCL_GET_NODE_INFORMATION_RESPONSE_COMMAND_ID, \
                           "uvvb", \
							  status,							  cid,							  uid,							  addressEndpointAndNickname, addressEndpointAndNicknameLen);



/** @brief Command description for BuyRequest
* Cluster: Payment, Commands and attributes for payment scenarios including ZigBee devices.
* Command: BuyRequest
* @param userId uint8_t *

* @param userType uint16_t

* @param serviceId uint16_t

* @param goodId uint8_t *

*/
#define sl_zigbee_af_fill_command_payment_cluster_buy_request( \
  userId,  userType,  serviceId,  goodId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PAYMENT_CLUSTER_ID, \
                           ZCL_BUY_REQUEST_COMMAND_ID, \
                           "svvs", \
							  userId,							  userType,							  serviceId,							  goodId);



/** @brief Command description for BuyConfirm
* Cluster: Payment, Commands and attributes for payment scenarios including ZigBee devices.
* Command: BuyConfirm
* @param serialNumber uint8_t *

* @param currency uint32_t

* @param priceTrailingDigit uint8_t

* @param price uint32_t

* @param timestamp uint8_t *

* @param transId uint16_t

* @param transStatus uint8_t

*/
#define sl_zigbee_af_fill_command_payment_cluster_buy_confirm( \
  serialNumber,  currency,  priceTrailingDigit,  price,  timestamp,  transId,  transStatus) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PAYMENT_CLUSTER_ID, \
                           ZCL_BUY_CONFIRM_COMMAND_ID, \
                           "swuwsvu", \
							  serialNumber,							  currency,							  priceTrailingDigit,							  price,							  timestamp,							  transId,							  transStatus);



/** @brief Command description for AcceptPayment
* Cluster: Payment, Commands and attributes for payment scenarios including ZigBee devices.
* Command: AcceptPayment
* @param userId uint8_t *

* @param userType uint16_t

* @param serviceId uint16_t

* @param goodId uint8_t *

*/
#define sl_zigbee_af_fill_command_payment_cluster_accept_payment( \
  userId,  userType,  serviceId,  goodId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PAYMENT_CLUSTER_ID, \
                           ZCL_ACCEPT_PAYMENT_COMMAND_ID, \
                           "svvs", \
							  userId,							  userType,							  serviceId,							  goodId);



/** @brief Command description for ReceiptDelivery
* Cluster: Payment, Commands and attributes for payment scenarios including ZigBee devices.
* Command: ReceiptDelivery
* @param serialNumber uint8_t *

* @param currency uint32_t

* @param priceTrailingDigit uint8_t

* @param price uint32_t

* @param timestamp uint8_t *

*/
#define sl_zigbee_af_fill_command_payment_cluster_receipt_delivery( \
  serialNumber,  currency,  priceTrailingDigit,  price,  timestamp) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PAYMENT_CLUSTER_ID, \
                           ZCL_RECEIPT_DELIVERY_COMMAND_ID, \
                           "swuws", \
							  serialNumber,							  currency,							  priceTrailingDigit,							  price,							  timestamp);



/** @brief Command description for PaymentConfirm
* Cluster: Payment, Commands and attributes for payment scenarios including ZigBee devices.
* Command: PaymentConfirm
* @param serialNumber uint8_t *

* @param transId uint16_t

* @param transStatus uint8_t

*/
#define sl_zigbee_af_fill_command_payment_cluster_payment_confirm( \
  serialNumber,  transId,  transStatus) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_PAYMENT_CLUSTER_ID, \
                           ZCL_PAYMENT_CONFIRM_COMMAND_ID, \
                           "svu", \
							  serialNumber,							  transId,							  transStatus);



/** @brief Command description for TransactionEnd
* Cluster: Payment, Commands and attributes for payment scenarios including ZigBee devices.
* Command: TransactionEnd
* @param serialNumber uint8_t *

* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_payment_cluster_transaction_end( \
  serialNumber,  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_PAYMENT_CLUSTER_ID, \
                           ZCL_TRANSACTION_END_COMMAND_ID, \
                           "su", \
							  serialNumber,							  status);



/** @brief Command description for Subscribe
* Cluster: Billing, Attributes and commands to enable billing of users for provided services through the use of a billing platform.
* Command: Subscribe
* @param userId uint8_t *

* @param serviceId uint16_t

* @param serviceProviderId uint16_t

*/
#define sl_zigbee_af_fill_command_billing_cluster_subscribe( \
  userId,  serviceId,  serviceProviderId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_BILLING_CLUSTER_ID, \
                           ZCL_SUBSCRIBE_COMMAND_ID, \
                           "svv", \
							  userId,							  serviceId,							  serviceProviderId);



/** @brief Command description for CheckBillStatus
* Cluster: Billing, Attributes and commands to enable billing of users for provided services through the use of a billing platform.
* Command: CheckBillStatus
* @param userId uint8_t *

* @param serviceId uint16_t

* @param serviceProviderId uint16_t

*/
#define sl_zigbee_af_fill_command_billing_cluster_check_bill_status( \
  userId,  serviceId,  serviceProviderId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_BILLING_CLUSTER_ID, \
                           ZCL_CHECK_BILL_STATUS_COMMAND_ID, \
                           "svv", \
							  userId,							  serviceId,							  serviceProviderId);



/** @brief Command description for Unsubscribe
* Cluster: Billing, Attributes and commands to enable billing of users for provided services through the use of a billing platform.
* Command: Unsubscribe
* @param userId uint8_t *

* @param serviceId uint16_t

* @param serviceProviderId uint16_t

*/
#define sl_zigbee_af_fill_command_billing_cluster_unsubscribe( \
  userId,  serviceId,  serviceProviderId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_BILLING_CLUSTER_ID, \
                           ZCL_UNSUBSCRIBE_COMMAND_ID, \
                           "svv", \
							  userId,							  serviceId,							  serviceProviderId);



/** @brief Command description for SendBillRecord
* Cluster: Billing, Attributes and commands to enable billing of users for provided services through the use of a billing platform.
* Command: SendBillRecord
* @param userId uint8_t *

* @param serviceId uint16_t

* @param serviceProviderId uint16_t

* @param timestamp uint8_t *

* @param duration uint16_t

*/
#define sl_zigbee_af_fill_command_billing_cluster_send_bill_record( \
  userId,  serviceId,  serviceProviderId,  timestamp,  duration) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_BILLING_CLUSTER_ID, \
                           ZCL_SEND_BILL_RECORD_COMMAND_ID, \
                           "svvsv", \
							  userId,							  serviceId,							  serviceProviderId,							  timestamp,							  duration);



/** @brief Command description for StartBillingSession
* Cluster: Billing, Attributes and commands to enable billing of users for provided services through the use of a billing platform.
* Command: StartBillingSession
* @param userId uint8_t *

* @param serviceId uint16_t

* @param serviceProviderId uint16_t

*/
#define sl_zigbee_af_fill_command_billing_cluster_start_billing_session( \
  userId,  serviceId,  serviceProviderId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_BILLING_CLUSTER_ID, \
                           ZCL_START_BILLING_SESSION_COMMAND_ID, \
                           "svv", \
							  userId,							  serviceId,							  serviceProviderId);



/** @brief Command description for StopBillingSession
* Cluster: Billing, Attributes and commands to enable billing of users for provided services through the use of a billing platform.
* Command: StopBillingSession
* @param userId uint8_t *

* @param serviceId uint16_t

* @param serviceProviderId uint16_t

*/
#define sl_zigbee_af_fill_command_billing_cluster_stop_billing_session( \
  userId,  serviceId,  serviceProviderId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_BILLING_CLUSTER_ID, \
                           ZCL_STOP_BILLING_SESSION_COMMAND_ID, \
                           "svv", \
							  userId,							  serviceId,							  serviceProviderId);



/** @brief Command description for BillStatusNotification
* Cluster: Billing, Attributes and commands to enable billing of users for provided services through the use of a billing platform.
* Command: BillStatusNotification
* @param userId uint8_t *

* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_billing_cluster_bill_status_notification( \
  userId,  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_BILLING_CLUSTER_ID, \
                           ZCL_BILL_STATUS_NOTIFICATION_COMMAND_ID, \
                           "su", \
							  userId,							  status);



/** @brief Command description for SessionKeepAlive
* Cluster: Billing, Attributes and commands to enable billing of users for provided services through the use of a billing platform.
* Command: SessionKeepAlive
* @param userId uint8_t *

* @param serviceId uint16_t

* @param serviceProviderId uint16_t

*/
#define sl_zigbee_af_fill_command_billing_cluster_session_keep_alive( \
  userId,  serviceId,  serviceProviderId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_BILLING_CLUSTER_ID, \
                           ZCL_SESSION_KEEP_ALIVE_COMMAND_ID, \
                           "svv", \
							  userId,							  serviceId,							  serviceProviderId);



/** @brief This basic message is used to retrieve Household Appliance current alerts.
* Cluster: Appliance Events and Alert, Attributes and commands for transmitting or notifying the occurrence of an event, such as "temperature reached" and of an alert such as alarm, fault or warning.
* Command: GetAlerts
*/
#define sl_zigbee_af_fill_command_appliance_events_and_alert_cluster_get_alerts( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_APPLIANCE_EVENTS_AND_ALERT_CLUSTER_ID, \
                           ZCL_GET_ALERTS_COMMAND_ID, \
                           "" \
);



/** @brief This message is used to return household appliance current alerts.
* Cluster: Appliance Events and Alert, Attributes and commands for transmitting or notifying the occurrence of an event, such as "temperature reached" and of an alert such as alarm, fault or warning.
* Command: GetAlertsResponse
* @param alertsCount uint8_t

* @param alertStructures uint8_t *
* @param alertStructuresLen uint16_t 
*/
#define sl_zigbee_af_fill_command_appliance_events_and_alert_cluster_get_alerts_response( \
  alertsCount,  alertStructures, alertStructuresLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_APPLIANCE_EVENTS_AND_ALERT_CLUSTER_ID, \
                           ZCL_GET_ALERTS_RESPONSE_COMMAND_ID, \
                           "ub", \
							  alertsCount,							  alertStructures, alertStructuresLen);



/** @brief This message is used to notify the current modification of warning and/or fault conditions.
* Cluster: Appliance Events and Alert, Attributes and commands for transmitting or notifying the occurrence of an event, such as "temperature reached" and of an alert such as alarm, fault or warning.
* Command: AlertsNotification
* @param alertsCount uint8_t

* @param alertStructures uint8_t *
* @param alertStructuresLen uint16_t 
*/
#define sl_zigbee_af_fill_command_appliance_events_and_alert_cluster_alerts_notification( \
  alertsCount,  alertStructures, alertStructuresLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_APPLIANCE_EVENTS_AND_ALERT_CLUSTER_ID, \
                           ZCL_ALERTS_NOTIFICATION_COMMAND_ID, \
                           "ub", \
							  alertsCount,							  alertStructures, alertStructuresLen);



/** @brief This message is used to notify an event occurred during the normal working of the appliance.
* Cluster: Appliance Events and Alert, Attributes and commands for transmitting or notifying the occurrence of an event, such as "temperature reached" and of an alert such as alarm, fault or warning.
* Command: EventsNotification
* @param eventHeader uint8_t

* @param eventId uint8_t

*/
#define sl_zigbee_af_fill_command_appliance_events_and_alert_cluster_events_notification( \
  eventHeader,  eventId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_APPLIANCE_EVENTS_AND_ALERT_CLUSTER_ID, \
                           ZCL_EVENTS_NOTIFICATION_COMMAND_ID, \
                           "uu", \
							  eventHeader,							  eventId);



/** @brief The Appliance Statistics Cluster server occasionally sends out a Log Notification command to the devices to which it needs to log information related to statistics (e.g., home gateways) which implement the client side of Appliance Statistics Cluster.
* Cluster: Appliance Statistics, This cluster provides a mechanism for the transmitting appliance statistics to a collection unit (gateway). The statistics can be in format of data logs. In case of statistic information that will not fit the single ZigBee payload, the Partition cluster should be used.
* Command: LogNotification
* @param timeStamp uint32_t

* @param logId uint32_t

* @param logLength uint32_t

* @param logPayload uint8_t *
* @param logPayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_appliance_statistics_cluster_log_notification( \
  timeStamp,  logId,  logLength,  logPayload, logPayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_APPLIANCE_STATISTICS_CLUSTER_ID, \
                           ZCL_LOG_NOTIFICATION_COMMAND_ID, \
                           "wwwb", \
							  timeStamp,							  logId,							  logLength,							  logPayload, logPayloadLen);



/** @brief The Log request command is sent from a device supporting the client side of the Appliance Statistics cluster (e.g., Home Gateway) to retrieve the log from the device supporting the server side (e.g., appliance).
* Cluster: Appliance Statistics, This cluster provides a mechanism for the transmitting appliance statistics to a collection unit (gateway). The statistics can be in format of data logs. In case of statistic information that will not fit the single ZigBee payload, the Partition cluster should be used.
* Command: LogRequest
* @param logId uint32_t

*/
#define sl_zigbee_af_fill_command_appliance_statistics_cluster_log_request( \
  logId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_APPLIANCE_STATISTICS_CLUSTER_ID, \
                           ZCL_LOG_REQUEST_COMMAND_ID, \
                           "w", \
							  logId);



/** @brief The Appliance Statistics Cluster server sends out a Log Response command to respond to a Log Request command generated by the client side of the Appliance Statistics cluster.
* Cluster: Appliance Statistics, This cluster provides a mechanism for the transmitting appliance statistics to a collection unit (gateway). The statistics can be in format of data logs. In case of statistic information that will not fit the single ZigBee payload, the Partition cluster should be used.
* Command: LogResponse
* @param timeStamp uint32_t

* @param logId uint32_t

* @param logLength uint32_t

* @param logPayload uint8_t *
* @param logPayloadLen uint16_t 
*/
#define sl_zigbee_af_fill_command_appliance_statistics_cluster_log_response( \
  timeStamp,  logId,  logLength,  logPayload, logPayloadLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_APPLIANCE_STATISTICS_CLUSTER_ID, \
                           ZCL_LOG_RESPONSE_COMMAND_ID, \
                           "wwwb", \
							  timeStamp,							  logId,							  logLength,							  logPayload, logPayloadLen);



/** @brief The Log Queue Request command is send from a device supporting the client side of the Appliance Statistics cluster (e.g. Home Gateway) to retrieve the information about the logs inserted in the queue, from the device supporting the server side (e.g. appliance).
* Cluster: Appliance Statistics, This cluster provides a mechanism for the transmitting appliance statistics to a collection unit (gateway). The statistics can be in format of data logs. In case of statistic information that will not fit the single ZigBee payload, the Partition cluster should be used.
* Command: LogQueueRequest
*/
#define sl_zigbee_af_fill_command_appliance_statistics_cluster_log_queue_request( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_APPLIANCE_STATISTICS_CLUSTER_ID, \
                           ZCL_LOG_QUEUE_REQUEST_COMMAND_ID, \
                           "" \
);



/** @brief The Log Queue Response command is generated as a response to a LogQueueRequest command in order to notify the client side of the Appliance statistics cluster about the logs stored in the server side (queue) that can be retrieved by the client side of this cluster through a LogRequest command.
* Cluster: Appliance Statistics, This cluster provides a mechanism for the transmitting appliance statistics to a collection unit (gateway). The statistics can be in format of data logs. In case of statistic information that will not fit the single ZigBee payload, the Partition cluster should be used.
* Command: LogQueueResponse
* @param logQueueSize uint8_t

* @param logIds uint8_t *
* @param logIdsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_appliance_statistics_cluster_log_queue_response( \
  logQueueSize,  logIds, logIdsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_APPLIANCE_STATISTICS_CLUSTER_ID, \
                           ZCL_LOG_QUEUE_RESPONSE_COMMAND_ID, \
                           "ub", \
							  logQueueSize,							  logIds, logIdsLen);



/** @brief The Appliance Statistics Cluster server sends out a Statistic Available command to notify the client side of the Appliance Statistics cluster that there are statistics that can be retrieved by using the Log Request command.
* Cluster: Appliance Statistics, This cluster provides a mechanism for the transmitting appliance statistics to a collection unit (gateway). The statistics can be in format of data logs. In case of statistic information that will not fit the single ZigBee payload, the Partition cluster should be used.
* Command: StatisticsAvailable
* @param logQueueSize uint8_t

* @param logIds uint8_t *
* @param logIdsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_appliance_statistics_cluster_statistics_available( \
  logQueueSize,  logIds, logIdsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_APPLIANCE_STATISTICS_CLUSTER_ID, \
                           ZCL_STATISTICS_AVAILABLE_COMMAND_ID, \
                           "ub", \
							  logQueueSize,							  logIds, logIdsLen);



/** @brief A function which returns the power profiling information requested in the GetProfileInfo command. The power profiling information consists of a list of attributes which are profiled along with the period used to profile them.
* Cluster: Electrical Measurement, Attributes related to the electrical properties of a device. This cluster is used by power outlets and other devices that need to provide instantaneous data as opposed to metrology data which should be retrieved from the metering cluster..
* Command: GetProfileInfoResponseCommand
* @param profileCount uint8_t

* @param profileIntervalPeriod uint8_t

* @param maxNumberOfIntervals uint8_t

* @param listOfAttributes uint8_t *
* @param listOfAttributesLen uint16_t 
*/
#define sl_zigbee_af_fill_command_electrical_measurement_cluster_get_profile_info_response_command( \
  profileCount,  profileIntervalPeriod,  maxNumberOfIntervals,  listOfAttributes, listOfAttributesLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_ELECTRICAL_MEASUREMENT_CLUSTER_ID, \
                           ZCL_GET_PROFILE_INFO_RESPONSE_COMMAND_COMMAND_ID, \
                           "uuub", \
							  profileCount,							  profileIntervalPeriod,							  maxNumberOfIntervals,							  listOfAttributes, listOfAttributesLen);



/** @brief A function which retrieves the power profiling information from the electrical measurement server.
* Cluster: Electrical Measurement, Attributes related to the electrical properties of a device. This cluster is used by power outlets and other devices that need to provide instantaneous data as opposed to metrology data which should be retrieved from the metering cluster..
* Command: GetProfileInfoCommand
*/
#define sl_zigbee_af_fill_command_electrical_measurement_cluster_get_profile_info_command( \
) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ELECTRICAL_MEASUREMENT_CLUSTER_ID, \
                           ZCL_GET_PROFILE_INFO_COMMAND_COMMAND_ID, \
                           "" \
);



/** @brief A function which returns the electricity measurement profile. The electricity measurement profile includes information regarding the amount of time used to capture data related to the flow of electricity as well as the intervals thes
* Cluster: Electrical Measurement, Attributes related to the electrical properties of a device. This cluster is used by power outlets and other devices that need to provide instantaneous data as opposed to metrology data which should be retrieved from the metering cluster..
* Command: GetMeasurementProfileResponseCommand
* @param startTime uint32_t

* @param status uint8_t

* @param profileIntervalPeriod uint8_t

* @param numberOfIntervalsDelivered uint8_t

* @param attributeId uint16_t

* @param intervals uint8_t *
* @param intervalsLen uint16_t 
*/
#define sl_zigbee_af_fill_command_electrical_measurement_cluster_get_measurement_profile_response_command( \
  startTime,  status,  profileIntervalPeriod,  numberOfIntervalsDelivered,  attributeId,  intervals, intervalsLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_ELECTRICAL_MEASUREMENT_CLUSTER_ID, \
                           ZCL_GET_MEASUREMENT_PROFILE_RESPONSE_COMMAND_COMMAND_ID, \
                           "wuuuvb", \
							  startTime,							  status,							  profileIntervalPeriod,							  numberOfIntervalsDelivered,							  attributeId,							  intervals, intervalsLen);



/** @brief A function which retrieves an electricity measurement profile from the electricity measurement server for a specific attribute Id requested.
* Cluster: Electrical Measurement, Attributes related to the electrical properties of a device. This cluster is used by power outlets and other devices that need to provide instantaneous data as opposed to metrology data which should be retrieved from the metering cluster..
* Command: GetMeasurementProfileCommand
* @param attributeId uint16_t

* @param startTime uint32_t

* @param numberOfIntervals uint8_t

*/
#define sl_zigbee_af_fill_command_electrical_measurement_cluster_get_measurement_profile_command( \
  attributeId,  startTime,  numberOfIntervals) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ELECTRICAL_MEASUREMENT_CLUSTER_ID, \
                           ZCL_GET_MEASUREMENT_PROFILE_COMMAND_COMMAND_ID, \
                           "vwu", \
							  attributeId,							  startTime,							  numberOfIntervals);



/** @brief Command description for ScanRequest
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: ScanRequest
* @param transaction uint32_t

* @param zigbeeInformation uint8_t

* @param zllInformation uint8_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_scan_request( \
  transaction,  zigbeeInformation,  zllInformation) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_SCAN_REQUEST_COMMAND_ID, \
                           "wuu", \
							  transaction,							  zigbeeInformation,							  zllInformation);



/** @brief Command description for ScanResponse
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: ScanResponse
* @param transaction uint32_t

* @param rssiCorrection uint8_t

* @param zigbeeInformation uint8_t

* @param zllInformation uint8_t

* @param keyBitmask uint16_t

* @param responseId uint32_t

* @param extendedPanId uint8_t *

* @param networkUpdateId uint8_t

* @param logicalChannel uint8_t

* @param panId uint16_t

* @param networkAddress uint16_t

* @param numberOfSubDevices uint8_t

* @param totalGroupIds uint8_t

* @param endpointId uint8_t

* @param profileId uint16_t

* @param deviceId uint16_t

* @param version uint8_t

* @param groupIdCount uint8_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_scan_response( \
  transaction,  rssiCorrection,  zigbeeInformation,  zllInformation,  keyBitmask,  responseId,  extendedPanId,  networkUpdateId,  logicalChannel,  panId,  networkAddress,  numberOfSubDevices,  totalGroupIds,  endpointId,  profileId,  deviceId,  version,  groupIdCount) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_SCAN_RESPONSE_COMMAND_ID, \
                           "wuuuvw8uuvvuuuvvuu", \
							  transaction,							  rssiCorrection,							  zigbeeInformation,							  zllInformation,							  keyBitmask,							  responseId,							  extendedPanId,							  networkUpdateId,							  logicalChannel,							  panId,							  networkAddress,							  numberOfSubDevices,							  totalGroupIds,							  endpointId,							  profileId,							  deviceId,							  version,							  groupIdCount);



/** @brief Command description for DeviceInformationRequest
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: DeviceInformationRequest
* @param transaction uint32_t

* @param startIndex uint8_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_device_information_request( \
  transaction,  startIndex) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_DEVICE_INFORMATION_REQUEST_COMMAND_ID, \
                           "wu", \
							  transaction,							  startIndex);



/** @brief Command description for DeviceInformationResponse
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: DeviceInformationResponse
* @param transaction uint32_t

* @param numberOfSubDevices uint8_t

* @param startIndex uint8_t

* @param deviceInformationRecordCount uint8_t

* @param deviceInformationRecordList uint8_t *
* @param deviceInformationRecordListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_device_information_response( \
  transaction,  numberOfSubDevices,  startIndex,  deviceInformationRecordCount,  deviceInformationRecordList, deviceInformationRecordListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_DEVICE_INFORMATION_RESPONSE_COMMAND_ID, \
                           "wuuub", \
							  transaction,							  numberOfSubDevices,							  startIndex,							  deviceInformationRecordCount,							  deviceInformationRecordList, deviceInformationRecordListLen);



/** @brief Command description for IdentifyRequest
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: IdentifyRequest
* @param transaction uint32_t

* @param identifyDuration uint16_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_identify_request( \
  transaction,  identifyDuration) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_IDENTIFY_REQUEST_COMMAND_ID, \
                           "wv", \
							  transaction,							  identifyDuration);



/** @brief Command description for ResetToFactoryNewRequest
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: ResetToFactoryNewRequest
* @param transaction uint32_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_reset_to_factory_new_request( \
  transaction) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_RESET_TO_FACTORY_NEW_REQUEST_COMMAND_ID, \
                           "w", \
							  transaction);



/** @brief Command description for NetworkStartRequest
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: NetworkStartRequest
* @param transaction uint32_t

* @param extendedPanId uint8_t *

* @param keyIndex uint8_t

* @param encryptedNetworkKey uint8_t *

* @param logicalChannel uint8_t

* @param panId uint16_t

* @param networkAddress uint16_t

* @param groupIdentifiersBegin uint16_t

* @param groupIdentifiersEnd uint16_t

* @param freeNetworkAddressRangeBegin uint16_t

* @param freeNetworkAddressRangeEnd uint16_t

* @param freeGroupIdentifierRangeBegin uint16_t

* @param freeGroupIdentifierRangeEnd uint16_t

* @param initiatorIeeeAddress uint8_t *

* @param initiatorNetworkAddress uint16_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_network_start_request( \
  transaction,  extendedPanId,  keyIndex,  encryptedNetworkKey,  logicalChannel,  panId,  networkAddress,  groupIdentifiersBegin,  groupIdentifiersEnd,  freeNetworkAddressRangeBegin,  freeNetworkAddressRangeEnd,  freeGroupIdentifierRangeBegin,  freeGroupIdentifierRangeEnd,  initiatorIeeeAddress,  initiatorNetworkAddress) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_NETWORK_START_REQUEST_COMMAND_ID, \
                           "w8uGuvvvvvvvv8v", \
							  transaction,							  extendedPanId,							  keyIndex,							  encryptedNetworkKey,							  logicalChannel,							  panId,							  networkAddress,							  groupIdentifiersBegin,							  groupIdentifiersEnd,							  freeNetworkAddressRangeBegin,							  freeNetworkAddressRangeEnd,							  freeGroupIdentifierRangeBegin,							  freeGroupIdentifierRangeEnd,							  initiatorIeeeAddress,							  initiatorNetworkAddress);



/** @brief Command description for NetworkStartResponse
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: NetworkStartResponse
* @param transaction uint32_t

* @param status uint8_t

* @param extendedPanId uint8_t *

* @param networkUpdateId uint8_t

* @param logicalChannel uint8_t

* @param panId uint16_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_network_start_response( \
  transaction,  status,  extendedPanId,  networkUpdateId,  logicalChannel,  panId) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_NETWORK_START_RESPONSE_COMMAND_ID, \
                           "wu8uuv", \
							  transaction,							  status,							  extendedPanId,							  networkUpdateId,							  logicalChannel,							  panId);



/** @brief Command description for NetworkJoinRouterRequest
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: NetworkJoinRouterRequest
* @param transaction uint32_t

* @param extendedPanId uint8_t *

* @param keyIndex uint8_t

* @param encryptedNetworkKey uint8_t *

* @param networkUpdateId uint8_t

* @param logicalChannel uint8_t

* @param panId uint16_t

* @param networkAddress uint16_t

* @param groupIdentifiersBegin uint16_t

* @param groupIdentifiersEnd uint16_t

* @param freeNetworkAddressRangeBegin uint16_t

* @param freeNetworkAddressRangeEnd uint16_t

* @param freeGroupIdentifierRangeBegin uint16_t

* @param freeGroupIdentifierRangeEnd uint16_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_network_join_router_request( \
  transaction,  extendedPanId,  keyIndex,  encryptedNetworkKey,  networkUpdateId,  logicalChannel,  panId,  networkAddress,  groupIdentifiersBegin,  groupIdentifiersEnd,  freeNetworkAddressRangeBegin,  freeNetworkAddressRangeEnd,  freeGroupIdentifierRangeBegin,  freeGroupIdentifierRangeEnd) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_NETWORK_JOIN_ROUTER_REQUEST_COMMAND_ID, \
                           "w8uGuuvvvvvvvv", \
							  transaction,							  extendedPanId,							  keyIndex,							  encryptedNetworkKey,							  networkUpdateId,							  logicalChannel,							  panId,							  networkAddress,							  groupIdentifiersBegin,							  groupIdentifiersEnd,							  freeNetworkAddressRangeBegin,							  freeNetworkAddressRangeEnd,							  freeGroupIdentifierRangeBegin,							  freeGroupIdentifierRangeEnd);



/** @brief Command description for NetworkJoinRouterResponse
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: NetworkJoinRouterResponse
* @param transaction uint32_t

* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_network_join_router_response( \
  transaction,  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_NETWORK_JOIN_ROUTER_RESPONSE_COMMAND_ID, \
                           "wu", \
							  transaction,							  status);



/** @brief Command description for NetworkJoinEndDeviceRequest
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: NetworkJoinEndDeviceRequest
* @param transaction uint32_t

* @param extendedPanId uint8_t *

* @param keyIndex uint8_t

* @param encryptedNetworkKey uint8_t *

* @param networkUpdateId uint8_t

* @param logicalChannel uint8_t

* @param panId uint16_t

* @param networkAddress uint16_t

* @param groupIdentifiersBegin uint16_t

* @param groupIdentifiersEnd uint16_t

* @param freeNetworkAddressRangeBegin uint16_t

* @param freeNetworkAddressRangeEnd uint16_t

* @param freeGroupIdentifierRangeBegin uint16_t

* @param freeGroupIdentifierRangeEnd uint16_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_network_join_end_device_request( \
  transaction,  extendedPanId,  keyIndex,  encryptedNetworkKey,  networkUpdateId,  logicalChannel,  panId,  networkAddress,  groupIdentifiersBegin,  groupIdentifiersEnd,  freeNetworkAddressRangeBegin,  freeNetworkAddressRangeEnd,  freeGroupIdentifierRangeBegin,  freeGroupIdentifierRangeEnd) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_NETWORK_JOIN_END_DEVICE_REQUEST_COMMAND_ID, \
                           "w8uGuuvvvvvvvv", \
							  transaction,							  extendedPanId,							  keyIndex,							  encryptedNetworkKey,							  networkUpdateId,							  logicalChannel,							  panId,							  networkAddress,							  groupIdentifiersBegin,							  groupIdentifiersEnd,							  freeNetworkAddressRangeBegin,							  freeNetworkAddressRangeEnd,							  freeGroupIdentifierRangeBegin,							  freeGroupIdentifierRangeEnd);



/** @brief Command description for NetworkJoinEndDeviceResponse
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: NetworkJoinEndDeviceResponse
* @param transaction uint32_t

* @param status uint8_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_network_join_end_device_response( \
  transaction,  status) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_NETWORK_JOIN_END_DEVICE_RESPONSE_COMMAND_ID, \
                           "wu", \
							  transaction,							  status);



/** @brief Command description for NetworkUpdateRequest
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: NetworkUpdateRequest
* @param transaction uint32_t

* @param extendedPanId uint8_t *

* @param networkUpdateId uint8_t

* @param logicalChannel uint8_t

* @param panId uint16_t

* @param networkAddress uint16_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_network_update_request( \
  transaction,  extendedPanId,  networkUpdateId,  logicalChannel,  panId,  networkAddress) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_NETWORK_UPDATE_REQUEST_COMMAND_ID, \
                           "w8uuvv", \
							  transaction,							  extendedPanId,							  networkUpdateId,							  logicalChannel,							  panId,							  networkAddress);



/** @brief Command description for EndpointInformation
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: EndpointInformation
* @param ieeeAddress uint8_t *

* @param networkAddress uint16_t

* @param endpointId uint8_t

* @param profileId uint16_t

* @param deviceId uint16_t

* @param version uint8_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_endpoint_information( \
  ieeeAddress,  networkAddress,  endpointId,  profileId,  deviceId,  version) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_ENDPOINT_INFORMATION_COMMAND_ID, \
                           "8vuvvu", \
							  ieeeAddress,							  networkAddress,							  endpointId,							  profileId,							  deviceId,							  version);



/** @brief Command description for GetGroupIdentifiersRequest
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: GetGroupIdentifiersRequest
* @param startIndex uint8_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_get_group_identifiers_request( \
  startIndex) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_GET_GROUP_IDENTIFIERS_REQUEST_COMMAND_ID, \
                           "u", \
							  startIndex);



/** @brief Command description for GetGroupIdentifiersResponse
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: GetGroupIdentifiersResponse
* @param total uint8_t

* @param startIndex uint8_t

* @param count uint8_t

* @param groupInformationRecordList uint8_t *
* @param groupInformationRecordListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_get_group_identifiers_response( \
  total,  startIndex,  count,  groupInformationRecordList, groupInformationRecordListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_GET_GROUP_IDENTIFIERS_RESPONSE_COMMAND_ID, \
                           "uuub", \
							  total,							  startIndex,							  count,							  groupInformationRecordList, groupInformationRecordListLen);



/** @brief Command description for GetEndpointListRequest
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: GetEndpointListRequest
* @param startIndex uint8_t

*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_get_endpoint_list_request( \
  startIndex) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_GET_ENDPOINT_LIST_REQUEST_COMMAND_ID, \
                           "u", \
							  startIndex);



/** @brief Command description for GetEndpointListResponse
* Cluster: ZLL Commissioning, The ZLL commissioning cluster provides commands to support touch link commissioning.
* Command: GetEndpointListResponse
* @param total uint8_t

* @param startIndex uint8_t

* @param count uint8_t

* @param endpointInformationRecordList uint8_t *
* @param endpointInformationRecordListLen uint16_t 
*/
#define sl_zigbee_af_fill_command_zll_commissioning_cluster_get_endpoint_list_response( \
  total,  startIndex,  count,  endpointInformationRecordList, endpointInformationRecordListLen) \
sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_ZLL_COMMISSIONING_CLUSTER_ID, \
                           ZCL_GET_ENDPOINT_LIST_RESPONSE_COMMAND_ID, \
                           "uuub", \
							  total,							  startIndex,							  count,							  endpointInformationRecordList, endpointInformationRecordListLen);



/** @brief A sample manufacturer specific command within the sample manufacturer specific
        cluster.
* Cluster: Sample Mfg Specific Cluster, This cluster provides an example of how the Application 
      Framework can be extended to include manufacturer specific clusters.
* Command: CommandOne
* @param argOne uint8_t

*/
#define sl_zigbee_af_fill_command_sample_mfg_specific_cluster_command_one( \
  argOne) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SAMPLE_MFG_SPECIFIC_CLUSTER_ID, \
4098, \
                           ZCL_COMMAND_ONE_COMMAND_ID, \
                           "u", \
							  argOne);



/** @brief A sample manufacturer specific command within the sample manufacturer specific
        cluster.
* Cluster: Sample Mfg Specific Cluster 2, This cluster provides an example of how the Application 
      Framework can be extended to include manufacturer specific clusters.
* Command: CommandTwo
* @param argOne uint8_t

*/
#define sl_zigbee_af_fill_command_sample_mfg_specific_cluster_2_command_two( \
  argOne) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SAMPLE_MFG_SPECIFIC_CLUSTER_2_ID, \
4169, \
                           ZCL_COMMAND_TWO_COMMAND_ID, \
                           "u", \
							  argOne);



/** @brief Command to write a token value over the air.
* Cluster: Configuration Cluster, This cluster allows for the OTA configuration of firmware
	  parameters.
* Command: SetToken
* @param token uint16_t

* @param data uint8_t *

*/
#define sl_zigbee_af_fill_command_ota_configuration_cluster_set_token( \
  token,  data) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_OTA_CONFIGURATION_CLUSTER_ID, \
4098, \
                           ZCL_SET_TOKEN_COMMAND_ID, \
                           "vs", \
							  token,							  data);



/** @brief Response to a token value read.
* Cluster: Configuration Cluster, This cluster allows for the OTA configuration of firmware
	  parameters.
* Command: ReturnToken
* @param token uint16_t

* @param data uint8_t *

*/
#define sl_zigbee_af_fill_command_ota_configuration_cluster_return_token( \
  token,  data) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_OTA_CONFIGURATION_CLUSTER_ID, \
4098, \
                           ZCL_RETURN_TOKEN_COMMAND_ID, \
                           "vs", \
							  token,							  data);



/** @brief Command to lock the token values.
* Cluster: Configuration Cluster, This cluster allows for the OTA configuration of firmware
	  parameters.
* Command: LockTokens
*/
#define sl_zigbee_af_fill_command_ota_configuration_cluster_lock_tokens( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_OTA_CONFIGURATION_CLUSTER_ID, \
4098, \
                           ZCL_LOCK_TOKENS_COMMAND_ID, \
                           "" \
);



/** @brief Command to read a token value.
* Cluster: Configuration Cluster, This cluster allows for the OTA configuration of firmware
	  parameters.
* Command: ReadTokens
* @param token uint16_t

*/
#define sl_zigbee_af_fill_command_ota_configuration_cluster_read_tokens( \
  token) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_OTA_CONFIGURATION_CLUSTER_ID, \
4098, \
                           ZCL_READ_TOKENS_COMMAND_ID, \
                           "v", \
							  token);



/** @brief Command to unlock tokens with a device-specific password (if allowed).
* Cluster: Configuration Cluster, This cluster allows for the OTA configuration of firmware
	  parameters.
* Command: UnlockTokens
* @param data uint8_t *

*/
#define sl_zigbee_af_fill_command_ota_configuration_cluster_unlock_tokens( \
  data) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_OTA_CONFIGURATION_CLUSTER_ID, \
4098, \
                           ZCL_UNLOCK_TOKENS_COMMAND_ID, \
                           "s", \
							  data);



/** @brief Command to put the device into streaming mode.
* Cluster: MFGLIB Cluster, This cluster provides commands to kick off MFGLIB actions 
	  over the air.
* Command: stream
* @param channel uint8_t

* @param power int8_t

* @param time uint16_t

*/
#define sl_zigbee_af_fill_command_mfglib_cluster_stream( \
  channel,  power,  time) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_MFGLIB_CLUSTER_ID, \
4098, \
                           ZCL_STREAM_COMMAND_ID, \
                           "uuv", \
							  channel,							  power,							  time);



/** @brief Command to put the device into tone mode.
* Cluster: MFGLIB Cluster, This cluster provides commands to kick off MFGLIB actions 
	  over the air.
* Command: tone
* @param channel uint8_t

* @param power int8_t

* @param time uint16_t

*/
#define sl_zigbee_af_fill_command_mfglib_cluster_tone( \
  channel,  power,  time) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_MFGLIB_CLUSTER_ID, \
4098, \
                           ZCL_TONE_COMMAND_ID, \
                           "uuv", \
							  channel,							  power,							  time);



/** @brief Command to put the device into RX mode.
* Cluster: MFGLIB Cluster, This cluster provides commands to kick off MFGLIB actions 
	  over the air.
* Command: rxMode
* @param channel uint8_t

* @param power int8_t

* @param time uint16_t

*/
#define sl_zigbee_af_fill_command_mfglib_cluster_rx_mode( \
  channel,  power,  time) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_MFGLIB_CLUSTER_ID, \
4098, \
                           ZCL_RX_MODE_COMMAND_ID, \
                           "uuv", \
							  channel,							  power,							  time);



/** @brief Enable enforcement of APS-level security for all cluster commands.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: EnableApsLinkKeyAuthorization
* @param numberExemptClusters uint8_t

* @param clusterId uint8_t *
* @param clusterIdLen uint16_t 
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_enable_aps_link_key_authorization( \
  numberExemptClusters,  clusterId, clusterIdLen) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_ENABLE_APS_LINK_KEY_AUTHORIZATION_COMMAND_ID, \
                           "ub", \
							  numberExemptClusters,							  clusterId, clusterIdLen);



/** @brief Command description for SlAPSLinkKeyAuthorizationQueryResponse
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: ApsLinkKeyAuthorizationQueryResponse
* @param clusterId uint16_t

* @param apsLinkKeyAuthStatus uint8_t

*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_aps_link_key_authorization_query_response( \
  clusterId,  apsLinkKeyAuthStatus) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_APS_LINK_KEY_AUTHORIZATION_QUERY_RESPONSE_COMMAND_ID, \
                           "vu", \
							  clusterId,							  apsLinkKeyAuthStatus);



/** @brief Disable enforcement of APS-level security for all cluster commands.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: DisableApsLinkKeyAuthorization
* @param numberExemptClusters uint8_t

* @param clusterId uint8_t *
* @param clusterIdLen uint16_t 
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_disable_aps_link_key_authorization( \
  numberExemptClusters,  clusterId, clusterIdLen) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_DISABLE_APS_LINK_KEY_AUTHORIZATION_COMMAND_ID, \
                           "ub", \
							  numberExemptClusters,							  clusterId, clusterIdLen);



/** @brief Command description for SlPoweringOffNotification
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: PoweringOffNotification
* @param powerNotificationReason uint8_t

* @param manufacturerId uint16_t

* @param manufacturerReasonLength uint8_t

* @param manufacturerReason uint8_t *
* @param manufacturerReasonLen uint16_t 
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_powering_off_notification( \
  powerNotificationReason,  manufacturerId,  manufacturerReasonLength,  manufacturerReason, manufacturerReasonLen) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_POWERING_OFF_NOTIFICATION_COMMAND_ID, \
                           "uvub", \
							  powerNotificationReason,							  manufacturerId,							  manufacturerReasonLength,							  manufacturerReason, manufacturerReasonLen);



/** @brief Query status of APS-level security enforcement for a specified cluster.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: ApsLinkKeyAuthorizationQuery
* @param clusterId uint16_t

*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_aps_link_key_authorization_query( \
  clusterId) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_APS_LINK_KEY_AUTHORIZATION_QUERY_COMMAND_ID, \
                           "v", \
							  clusterId);



/** @brief Command description for SlPoweringOnNotification
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: PoweringOnNotification
* @param powerNotificationReason uint8_t

* @param manufacturerId uint16_t

* @param manufacturerReasonLength uint8_t

* @param manufacturerReason uint8_t *
* @param manufacturerReasonLen uint16_t 
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_powering_on_notification( \
  powerNotificationReason,  manufacturerId,  manufacturerReasonLength,  manufacturerReason, manufacturerReasonLen) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_POWERING_ON_NOTIFICATION_COMMAND_ID, \
                           "uvub", \
							  powerNotificationReason,							  manufacturerId,							  manufacturerReasonLength,							  manufacturerReason, manufacturerReasonLen);



/** @brief Trigger device to request a new APS link key from the Trust Center.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: RequestNewApsLinkKey
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_request_new_aps_link_key( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_REQUEST_NEW_APS_LINK_KEY_COMMAND_ID, \
                           "" \
);



/** @brief Command description for SlShortAddressChange
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: ShortAddressChange
* @param deviceEui64 uint8_t *

* @param deviceShort uint16_t

*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_short_address_change( \
  deviceEui64,  deviceShort) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_SHORT_ADDRESS_CHANGE_COMMAND_ID, \
                           "8v", \
							  deviceEui64,							  deviceShort);



/** @brief Enable WWAH App Event retry algorithm.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: EnableWwahAppEventRetryAlgorithm
* @param firstBackoffTimeSeconds uint8_t

* @param backoffSeqCommonRatio uint8_t

* @param maxBackoffTimeSeconds uint32_t

* @param maxRedeliveryAttempts uint8_t

*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_enable_wwah_app_event_retry_algorithm( \
  firstBackoffTimeSeconds,  backoffSeqCommonRatio,  maxBackoffTimeSeconds,  maxRedeliveryAttempts) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_ENABLE_WWAH_APP_EVENT_RETRY_ALGORITHM_COMMAND_ID, \
                           "uuwu", \
							  firstBackoffTimeSeconds,							  backoffSeqCommonRatio,							  maxBackoffTimeSeconds,							  maxRedeliveryAttempts);



/** @brief Command description for SlAPSAckEnablementQueryResponse
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: ApsAckEnablementQueryResponse
* @param numberExemptClusters uint8_t

* @param clusterId uint8_t *
* @param clusterIdLen uint16_t 
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_aps_ack_enablement_query_response( \
  numberExemptClusters,  clusterId, clusterIdLen) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_APS_ACK_ENABLEMENT_QUERY_RESPONSE_COMMAND_ID, \
                           "ub", \
							  numberExemptClusters,							  clusterId, clusterIdLen);



/** @brief Disable WWAH App Event retry algorithm.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: DisableWwahAppEventRetryAlgorithm
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_disable_wwah_app_event_retry_algorithm( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_DISABLE_WWAH_APP_EVENT_RETRY_ALGORITHM_COMMAND_ID, \
                           "" \
);



/** @brief Command description for SlPowerDescriptorChange
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: PowerDescriptorChange
* @param currentPowerMode uint32_t

* @param availablePowerSources uint32_t

* @param currentPowerSource uint32_t

* @param currentPowerSourceLevel uint32_t

*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_power_descriptor_change( \
  currentPowerMode,  availablePowerSources,  currentPowerSource,  currentPowerSourceLevel) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_POWER_DESCRIPTOR_CHANGE_COMMAND_ID, \
                           "wwww", \
							  currentPowerMode,							  availablePowerSources,							  currentPowerSource,							  currentPowerSourceLevel);



/** @brief Trigger device to request current attribute values from Time Cluster server.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: RequestTime
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_request_time( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_REQUEST_TIME_COMMAND_ID, \
                           "" \
);



/** @brief Command description for SlNewDebugReportNotification
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: NewDebugReportNotification
* @param debugReportId uint8_t

* @param debugReportSize uint32_t

*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_new_debug_report_notification( \
  debugReportId,  debugReportSize) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_NEW_DEBUG_REPORT_NOTIFICATION_COMMAND_ID, \
                           "uw", \
							  debugReportId,							  debugReportSize);



/** @brief Enable WWAH rejoin algorithm.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: EnableWwahRejoinAlgorithm
* @param fastRejoinTimeoutSeconds uint16_t

* @param durationBetweenRejoinsSeconds uint16_t

* @param fastRejoinFirstBackoffSeconds uint16_t

* @param maxBackoffTimeSeconds uint16_t

* @param maxBackoffIterations uint16_t

*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_enable_wwah_rejoin_algorithm( \
  fastRejoinTimeoutSeconds,  durationBetweenRejoinsSeconds,  fastRejoinFirstBackoffSeconds,  maxBackoffTimeSeconds,  maxBackoffIterations) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_ENABLE_WWAH_REJOIN_ALGORITHM_COMMAND_ID, \
                           "vvvvv", \
							  fastRejoinTimeoutSeconds,							  durationBetweenRejoinsSeconds,							  fastRejoinFirstBackoffSeconds,							  maxBackoffTimeSeconds,							  maxBackoffIterations);



/** @brief Command description for SlDebugReportQueryResponse
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: DebugReportQueryResponse
* @param debugReportId uint8_t

* @param debugReportData uint8_t *
* @param debugReportDataLen uint16_t 
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_debug_report_query_response( \
  debugReportId,  debugReportData, debugReportDataLen) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_DEBUG_REPORT_QUERY_RESPONSE_COMMAND_ID, \
                           "ub", \
							  debugReportId,							  debugReportData, debugReportDataLen);



/** @brief Disable WWAH rejoin algorithm.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: DisableWwahRejoinAlgorithm
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_disable_wwah_rejoin_algorithm( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_DISABLE_WWAH_REJOIN_ALGORITHM_COMMAND_ID, \
                           "" \
);



/** @brief Command description for SlTrustCenterForClusterServerQueryResponse
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: TrustCenterForClusterServerQueryResponse
* @param numberOfClusters uint8_t

* @param clusterId uint8_t *
* @param clusterIdLen uint16_t 
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_trust_center_for_cluster_server_query_response( \
  numberOfClusters,  clusterId, clusterIdLen) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_TRUST_CENTER_FOR_CLUSTER_SERVER_QUERY_RESPONSE_COMMAND_ID, \
                           "ub", \
							  numberOfClusters,							  clusterId, clusterIdLen);



/** @brief Set the enrollment method of an IAS Zone server.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: SetIasZoneEnrollmentMethod
* @param enrollmentMode uint8_t

*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_set_ias_zone_enrollment_method( \
  enrollmentMode) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_SET_IAS_ZONE_ENROLLMENT_METHOD_COMMAND_ID, \
                           "u", \
							  enrollmentMode);



/** @brief Command description for SlSurveyBeaconsResponse
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: SurveyBeaconsResponse
* @param numberOfBeacons uint8_t

* @param beacon uint8_t *
* @param beaconLen uint16_t 
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_survey_beacons_response( \
  numberOfBeacons,  beacon, beaconLen) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_SURVEY_BEACONS_RESPONSE_COMMAND_ID, \
                           "ub", \
							  numberOfBeacons,							  beacon, beaconLen);



/** @brief Clear the binding table.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: ClearBindingTable
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_clear_binding_table( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_CLEAR_BINDING_TABLE_COMMAND_ID, \
                           "" \
);



/** @brief Enable device to periodically check connectivity with Zigbee Coordinator.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: EnablePeriodicRouterCheckIns
* @param checkInInterval uint16_t

*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_enable_periodic_router_check_ins( \
  checkInInterval) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_ENABLE_PERIODIC_ROUTER_CHECK_INS_COMMAND_ID, \
                           "v", \
							  checkInInterval);



/** @brief Disable device from periodically checking connectivity with Zigbee Coordinator.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: DisablePeriodicRouterCheckIns
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_disable_periodic_router_check_ins( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_DISABLE_PERIODIC_ROUTER_CHECK_INS_COMMAND_ID, \
                           "" \
);



/** @brief Set MAC poll failure wait time.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: SetMacPollFailureWaitTime
* @param waitTime uint8_t

*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_set_mac_poll_failure_wait_time( \
  waitTime) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_SET_MAC_POLL_FAILURE_WAIT_TIME_COMMAND_ID, \
                           "u", \
							  waitTime);



/** @brief Set pending network update parameters.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: SetPendingNetworkUpdate
* @param channel uint8_t

* @param panId uint16_t

*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_set_pending_network_update( \
  channel,  panId) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_SET_PENDING_NETWORK_UPDATE_COMMAND_ID, \
                           "uv", \
							  channel,							  panId);



/** @brief Require all unicast commands to have APS ACKs enabled.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: RequireApsAcksOnUnicasts
* @param numberExemptClusters uint8_t

* @param clusterId uint8_t *
* @param clusterIdLen uint16_t 
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_require_aps_acks_on_unicasts( \
  numberExemptClusters,  clusterId, clusterIdLen) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_REQUIRE_APS_ACKS_ON_UNICASTS_COMMAND_ID, \
                           "ub", \
							  numberExemptClusters,							  clusterId, clusterIdLen);



/** @brief Roll back changes made by Require APS ACK on Unicasts.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: RemoveApsAcksOnUnicastsRequirement
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_remove_aps_acks_on_unicasts_requirement( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_REMOVE_APS_ACKS_ON_UNICASTS_REQUIREMENT_COMMAND_ID, \
                           "" \
);



/** @brief Query whether unicast commands are required to have APS ACKs enabled.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: ApsAckRequirementQuery
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_aps_ack_requirement_query( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_APS_ACK_REQUIREMENT_QUERY_COMMAND_ID, \
                           "" \
);



/** @brief Query for specified debug report.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: DebugReportQuery
* @param debugReportId uint8_t

*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_debug_report_query( \
  debugReportId) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_DEBUG_REPORT_QUERY_COMMAND_ID, \
                           "u", \
							  debugReportId);



/** @brief Causes device to perform a scan for beacons advertising the device's network.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: SurveyBeacons
* @param standardBeacons uint8_t

*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_survey_beacons( \
  standardBeacons) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_SURVEY_BEACONS_COMMAND_ID, \
                           "u", \
							  standardBeacons);



/** @brief Disallow OTA downgrade of all device firmware components.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: DisableOtaDowngrades
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_disable_ota_downgrades( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_DISABLE_OTA_DOWNGRADES_COMMAND_ID, \
                           "" \
);



/** @brief Causes device to ignore MGMT Leave Without Rejoin commands.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: DisableMgmtLeaveWithoutRejoin
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_disable_mgmt_leave_without_rejoin( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_DISABLE_MGMT_LEAVE_WITHOUT_REJOIN_COMMAND_ID, \
                           "" \
);



/** @brief Causes device to ignore Touchlink Interpan messages.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: DisableTouchlinkInterpanMessageSupport
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_disable_touchlink_interpan_message_support( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_DISABLE_TOUCHLINK_INTERPAN_MESSAGE_SUPPORT_COMMAND_ID, \
                           "" \
);



/** @brief Enable WWAH Parent Classification advertisements.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: EnableWwahParentClassification
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_enable_wwah_parent_classification( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_ENABLE_WWAH_PARENT_CLASSIFICATION_COMMAND_ID, \
                           "" \
);



/** @brief Disable WWAH Parent Classification advertisements.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: DisableWwahParentClassification
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_disable_wwah_parent_classification( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_DISABLE_WWAH_PARENT_CLASSIFICATION_COMMAND_ID, \
                           "" \
);



/** @brief Process only network key rotation commands sent via unicast and encrypted by Trust Center Link Key.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: EnableTcSecurityOnNtwkKeyRotation
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_enable_tc_security_on_ntwk_key_rotation( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_ENABLE_TC_SECURITY_ON_NTWK_KEY_ROTATION_COMMAND_ID, \
                           "" \
);



/** @brief Enable WWAH Bad Parent Recovery feature.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: EnableWwahBadParentRecovery
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_enable_wwah_bad_parent_recovery( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_ENABLE_WWAH_BAD_PARENT_RECOVERY_COMMAND_ID, \
                           "" \
);



/** @brief Disable WWAH Bad Parent Recovery feature.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: DisableWwahBadParentRecovery
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_disable_wwah_bad_parent_recovery( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_DISABLE_WWAH_BAD_PARENT_RECOVERY_COMMAND_ID, \
                           "" \
);



/** @brief Enable Configuration Mode.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: EnableConfigurationMode
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_enable_configuration_mode( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_ENABLE_CONFIGURATION_MODE_COMMAND_ID, \
                           "" \
);



/** @brief Disable Configuration Mode.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: DisableConfigurationMode
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_disable_configuration_mode( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_DISABLE_CONFIGURATION_MODE_COMMAND_ID, \
                           "" \
);



/** @brief Use only the Trust Center as cluster server for the set of clusters specified.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: UseTrustCenterForClusterServer
* @param numberOfClusters uint8_t

* @param clusterId uint8_t *
* @param clusterIdLen uint16_t 
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_use_trust_center_for_cluster_server( \
  numberOfClusters,  clusterId, clusterIdLen) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_USE_TRUST_CENTER_FOR_CLUSTER_SERVER_COMMAND_ID, \
                           "ub", \
							  numberOfClusters,							  clusterId, clusterIdLen);



/** @brief Causes device to send an appropriate Trust Center for Cluster Server Query Response command.
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: TrustCenterForClusterServerQuery
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_trust_center_for_cluster_server_query( \
) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_TRUST_CENTER_FOR_CLUSTER_SERVER_QUERY_COMMAND_ID, \
                           "" \
);



/** @brief Command description for SlUseTrustCenterForClusterServerResponse
* Cluster: SL Works With All Hubs, Silicon Labs proprietary attributes and commands for Works With All Hubs functional extensions.
* Command: UseTrustCenterForClusterServerResponse
* @param status uint8_t

* @param clusterStatusLength uint8_t

* @param clusterStatus uint8_t *
* @param clusterStatusLen uint16_t 
*/
#define sl_zigbee_af_fill_command_sl_wwah_cluster_use_trust_center_for_cluster_server_response( \
  status,  clusterStatusLength,  clusterStatus, clusterStatusLen) \
sl_zigbee_af_fill_external_manufacturer_specific_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_MANUFACTURER_SPECIFIC_MASK \
                           | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), \
                           ZCL_SL_WWAH_CLUSTER_ID, \
4631, \
                           ZCL_USE_TRUST_CENTER_FOR_CLUSTER_SERVER_RESPONSE_COMMAND_ID, \
                           "uub", \
							  status,							  clusterStatusLength,							  clusterStatus, clusterStatusLen);


// End Cluster Specific Commands

/** @} END addtogroup */
#endif // SILABS_CLUSTER_CLIENT_API
