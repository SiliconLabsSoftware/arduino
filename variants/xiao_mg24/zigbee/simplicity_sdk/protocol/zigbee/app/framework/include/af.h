/***************************************************************************//**
 * @file
 * @brief The master include file for the Ember ApplicationFramework  API.
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

#ifndef SILABS_AF_API
#define SILABS_AF_API

#ifdef __cplusplus
extern "C" {
#endif

// Micro and compiler-specific typedefs and macros
#include PLATFORM_HEADER

#ifndef CONFIGURATION_HEADER
  #define CONFIGURATION_HEADER "app/framework/util/config.h"
#endif
#include CONFIGURATION_HEADER

// The ZCL Long String type data type takes first 2 bytes as the length
// And the sl_zigbee_af_read_attribute takes an uint8_t as the output length.
// So, it is important to ensure the largest value is less than the 253.
// NOTE : SL_MIN is not used instead following MIN is created using macro comparison.
//        because, SL_MIN for GCC expands to creating variable of same type using __typeof__,
//        assigning the supplied values and comparing, which causes a gcc error
//        "error: variable length array declaration not allowed at file scope" for unit tests
//        where ZCL_ATTRIBUTE_MAX_DATA_SIZE used in definition local arrays for attribute
//        inside a function.
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define ZCL_ATTRIBUTE_MAX_DATA_SIZE MIN(ZCL_ATTRIBUTE_LARGEST, 253)

// Includes needed for ember related functions for the EZSP host
#include "stack/include/sl_zigbee_types.h"
#include "stack/include/sl_zigbee_random_api.h"
#ifdef EZSP_HOST
  #include "app/util/ezsp/ezsp-protocol.h"
  #include "app/util/ezsp/ezsp.h"
  #include "app/util/ezsp/ezsp-utils.h"
  #include "app/util/ezsp/serial-interface.h"
#else
// Includes needed for ember related functions for the SoC
  #include "stack/include/sl_zigbee.h"
#endif // EZSP_HOST

#include "hal/hal.h"
#include "event_queue/event-queue.h"
#include "app/framework/include/af-types.h"
#include "app/framework/util/print.h"
#include "app/framework/util/time-util.h"

#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"

#ifdef SL_CATALOG_ZIGBEE_ZCL_FRAMEWORK_CORE_PRESENT
#include "zcl-framework-core-config.h"
#endif // SL_CATALOG_ZIGBEE_ZCL_FRAMEWORK_CORE_PRESENT

#ifdef SL_CATALOG_BYTE_UTILITIES_PRESENT
#include "byte-utilities.h"
#endif // SL_CATALOG_BYTE_UTILITIES_PRESENT

#ifdef SL_CATALOG_ZIGBEE_TEST_HARNESS_Z3_PRESENT
extern void sl_zigbee_af_test_harness_z3_beacon_send_event_handler(sl_zigbee_af_event_t * event);
extern void sl_zigbee_af_test_harness_z3_open_network_event_handler(sl_zigbee_af_event_t * event);
extern void sl_zigbee_af_test_harness_z3_reset_key_event_handler(sl_zigbee_af_event_t * event);
extern void sl_zigbee_af_test_harness_z3_zdo_send_event_handler(sl_zigbee_af_event_t * event);
extern void sl_zigbee_af_test_harness_z3_zll_stuff_event_handler(sl_zigbee_af_event_t * event);
extern void sl_zigbee_af_test_harness_z3_reset_event_handler(sl_zigbee_af_event_t * event);
#endif //SL_CATALOG_ZIGBEE_TEST_HARNESS_Z3_PRESENT

#endif // SL_COMPONENT_CATALOG_PRESENT

#ifdef SL_CATALOG_CLI_PRESENT
#include "sl_cli.h"
#define SL_CLI_COMMAND_ARG sl_cli_command_arg_t * arguments
#else // !SL_CATALOG_CLI_PRESENT
#define SL_CLI_COMMAND_ARG void
#endif // SL_CATALOG_CLI_PRESENT

#if defined(SL_CATALOG_ZIGBEE_DEBUG_PRINT_PRESENT) && !defined(SL_ZIGBEE_SCRIPTED_TEST)
#include "sl_zigbee_debug_print.h"
#endif // SL_CATALOG_ZIGBEE_DEBUG_PRINT_PRESENT

#include "serial/serial.h"
#include "sl_endianness.h"
// Temporary fix for UC_ALPHA_2, see EMZIGBEE-6782
#include "plugin-component-mappings.h"
#include "af-storage.h"

#include "zap-command.h"
#include "zap-id.h"
#include "zap-print.h"
#include "zap-enabled-incoming-commands.h"
#include "zap-type.h"
#include "app/framework/common/sl_zigbee_system_common.h"

#include "app/framework/util/util.h"
#include "app/framework/util/global-callback.h"
#include "app/framework/util/global-other-callback.h"
#include "app/framework/service-function/sl_service_function.h"

#include "app/framework/util/zcl-debug-print.h"

#include "app/framework/util/client-api.h"

#ifdef SL_CATALOG_ZIGBEE_CLI_PRESENT
#include "app/util/serial/sl_zigbee_command_interpreter.h"
#endif // SL_CATALOG_ZIGBEE_CLI_PRESENT

extern uint8_t ascii_lut[];
/**
 * @defgroup attribute-storage Attribute Storage
 * @ingroup af
 * @brief API for the Attribute Storage functionality
 * in the Application Framework
 *
 * Attribute Storage description.
 *
 */

/**
 * @addtogroup attribute-storage
 * @{
 */

/** @name API */
// @{

/**
 * @brief Locate attribute metadata.
 *
 * This function returns a pointer to the attribute metadata structure
 * or NULL if attribute is not found.
 *
 * @param endpoint Zigbee endpoint number.
 * @param clusterId Cluster ID of the sought cluster.
 * @param attributeId Attribute ID of the sought attribute.
 * @param mask CLUSTER_MASK_SERVER or CLUSTER_MASK_CLIENT
 * @param manufacturerCode Manufacturer code of the sough attribute.
 *
 * @return Returns pointer to the attribute metadata location.
 */
sl_zigbee_af_attribute_metadata_t *sl_zigbee_af_locate_attribute_metadata(uint8_t endpoint,
                                                                          sl_zigbee_af_cluster_id_t clusterId,
                                                                          sl_zigbee_af_attribute_id_t attributeId,
                                                                          uint8_t mask,
                                                                          uint16_t manufacturerCode);

#ifdef DOXYGEN_SHOULD_SKIP_THIS
/** @brief Return true if the attribute exists. */
bool sl_zigbee_af_contains_attribute(uint8_t endpoint,
                                     sl_zigbee_af_cluster_id_t clusterId,
                                     sl_zigbee_af_attribute_id_t attributeId,
                                     uint8_t mask,
                                     uint16_t manufacturerCode);
#else
  #define sl_zigbee_af_contains_attribute(endpoint, clusterId, attributeId, mask, manufacturerCode) \
  (sl_zigbee_af_locate_attribute_metadata(endpoint, clusterId, attributeId, mask, manufacturerCode) != NULL)
#endif

/**
 * @brief Return true if an endpoint contains a cluster, checking for mfg code.
 *
 * This function returns true regardless of whether
 * the endpoint contains server, client or both.
 * For standard libraries (when ClusterId < FC00),
 * the manufacturerCode is ignored.
 *
 * @param endpoint Zigbee endpoint number.
 * @param clusterId Cluster ID of the sought cluster.
 * @param manufacturerCode Manufacturer code of the sought endpoint.
 */
bool sl_zigbee_af_contains_cluster_with_mfg_code(uint8_t endpoint, sl_zigbee_af_cluster_id_t clusterId, uint16_t manufacturerCode);

/**
 * @brief Return true if the endpoint contains the ZCL cluster with specified ID.
 *
 * This function returns true regardless of whether
 * the endpoint contains server, client or both in the Zigbee Cluster Library.
 * This wraps sl_zigbee_af_contains_cluster_with_mfg_code with
 * manufacturerCode = SL_ZIGBEE_AF_NULL_MANUFACTURER_CODE
 * If this function is used with a manufacturer specific clusterId,
 * it returns the first cluster that it finds in the Cluster table.
 * It does not return any other clusters that share that ID.
 *
 * @param endpoint Zigbee endpoint number.
 * @param clusterId Cluster ID of the sought cluster.
 */
bool sl_zigbee_af_contains_cluster(uint8_t endpoint, sl_zigbee_af_cluster_id_t clusterId);

/**
 * @brief Return true if the endpoint has a cluster server, checking for the mfg code.
 *
 * This function returns true if
 * the endpoint contains server of a given cluster.
 * For standard libraries (when ClusterId < FC00), the manufacturerCode is ignored.
 *
 * @param endpoint Zigbee endpoint number.
 * @param clusterId Cluster ID of the sought cluster.
 * @param manufacturerCode Manufacturer code of the sought cluster.
 */
bool sl_zigbee_af_contains_server_with_mfg_code(uint8_t endpoint, sl_zigbee_af_cluster_id_t clusterId, uint16_t manufacturerCode);

/**
 * @brief Return true if the endpoint contains the ZCL server with a specified ID.
 *
 * This function returns true if
 * the endpoint contains server of a given cluster.
 * This wraps sl_zigbee_af_contains_server with
 * manufacturerCode = SL_ZIGBEE_AF_NULL_MANUFACTURER_CODE
 * If this function is used with a manufacturer specific clusterId,
 * it returns the first cluster that it finds in the Cluster table.
 * It does not return any other clusters that share that ID.
 *
 * @param endpoint Zigbee endpoint number.
 * @param clusterId Cluster ID of the sought cluster.
 */
bool sl_zigbee_af_contains_server(uint8_t endpoint, sl_zigbee_af_cluster_id_t clusterId);

/**
 * @brief Return true if the endpoint contains the cluster client.
 *
 * This function returns true if
 * the endpoint contains client of a given cluster.
 * For standard library clusters (when ClusterId < FC00),
 * the manufacturerCode is ignored.
 *
 * @param endpoint Zigbee endpoint number.
 * @param clusterId Cluster ID of the sought cluster.
 * @param manufacturerCode Manufacturer code of the sought cluster.
 */
bool sl_zigbee_af_contains_client_with_mfg_code(uint8_t endpoint, sl_zigbee_af_cluster_id_t clusterId, uint16_t manufacturerCode);

/**
 * @brief Return true if the endpoint contains the ZCL client with a specified ID.
 *
 * This function returns true if
 * the endpoint contains client of a given cluster.
 * It wraps sl_zigbee_af_contains_client with
 * manufacturerCode = SL_ZIGBEE_AF_NULL_MANUFACTURER_CODE
 * If this function is used with a manufacturer-specific clusterId,
 * it returns the first cluster that it finds in the Cluster table.
 * It does not return any other clusters that share that ID.
 *
 * @param endpoint Zigbee endpoint number.
 * @param clusterId Cluster ID of the sought cluster.
 */
bool sl_zigbee_af_contains_client(uint8_t endpoint, sl_zigbee_af_cluster_id_t clusterId);

/**
 * @brief Write an attribute performing all checks.
 *
 * This function attempts to write the attribute value from
 * the provided pointer. It only checks that the
 * attribute exists. If it does, it writes the value into
 * the attribute table for the given attribute.
 *
 * This function does not check if the attribute is
 * writable since the read only / writable characteristic
 * of an attribute only pertains to external devices writing
 * over the air. Because this function is called locally,
 * it assumes that the device knows what it is doing and has permission
 * to perform the given operation.
 *
 * @see sl_zigbee_af_write_client_attribute, sl_zigbee_af_write_server_attribute,
 *      sl_zigbee_af_write_manufacturer_specific_client_attribute,
 *      sl_zigbee_af_write_manufacturer_specific_server_attribute
 *
 * @param endpoint Zigbee endpoint number.
 * @param cluster Cluster ID of the sought cluster.
 * @param attributeID Attribute ID of the sought attribute.
 * @param mask CLUSTER_MASK_SERVER or CLUSTER_MASK_CLIENT.
 * @param dataPtr Pointer to the ZCL attribute.
 * @param dataType ZCL attribute type.
 */
sl_zigbee_af_status_t sl_zigbee_af_write_attribute(uint8_t endpoint,
                                                   sl_zigbee_af_cluster_id_t cluster,
                                                   sl_zigbee_af_attribute_id_t attributeID,
                                                   uint8_t mask,
                                                   uint8_t* dataPtr,
                                                   sl_zigbee_af_attribute_type_t dataType);

/**
 * @brief Write a cluster server attribute.
 *
 * This function is the same as sl_zigbee_af_write_attribute
 * except that it saves having to pass the cluster mask.
 * This is useful for code saving because the write attribute
 * is used frequently throughout the framework
 *
 * @see sl_zigbee_af_write_client_attribute,
 *      sl_zigbee_af_write_manufacturer_specific_client_attribute,
 *      sl_zigbee_af_write_manufacturer_specific_server_attribute
 *
 * @param endpoint Zigbee endpoint number.
 * @param cluster Cluster ID of the sought cluster.
 * @param attributeID Attribute ID of the sought attribute.
 * @param dataPtr Pointer to the ZCL attribute.
 * @param dataType ZCL attribute type.
 */
sl_zigbee_af_status_t sl_zigbee_af_write_server_attribute(uint8_t endpoint,
                                                          sl_zigbee_af_cluster_id_t cluster,
                                                          sl_zigbee_af_attribute_id_t attributeID,
                                                          uint8_t* dataPtr,
                                                          sl_zigbee_af_attribute_type_t dataType);

/**
 * @brief Write a cluster client attribute.
 *
 * This function is the same as sl_zigbee_af_write_attribute
 * except that it saves having to pass the cluster mask.
 * This is useful for code saving because the write attribute
 * is used frequently throughout the framework.
 *
 * @see sl_zigbee_af_write_server_attribute,
 *      sl_zigbee_af_write_manufacturer_specific_client_attribute,
 *      sl_zigbee_af_write_manufacturer_specific_server_attribute
 *
 * @param endpoint Zigbee endpoint number.
 * @param cluster Cluster ID of the sought cluster.
 * @param attributeID Attribute ID of the sought attribute.
 * @param dataPtr Pointer to the ZCL attribute.
 * @param dataType ZCL attribute type.
 */
sl_zigbee_af_status_t sl_zigbee_af_write_client_attribute(uint8_t endpoint,
                                                          sl_zigbee_af_cluster_id_t cluster,
                                                          sl_zigbee_af_attribute_id_t attributeID,
                                                          uint8_t* dataPtr,
                                                          sl_zigbee_af_attribute_type_t dataType);

/**
 * @brief Write a manufacturer-specific server attribute.
 *
 * This function is the same as sl_zigbee_af_write_attribute
 * except that it saves having to pass the cluster mask
 * and allows passing a manufacturer code.
 * This is useful for code saving because the write attribute
 * is used frequently throughout the framework.
 *
 * @see sl_zigbee_af_write_client_attribute, sl_zigbee_af_write_server_attribute,
 *      sl_zigbee_af_write_manufacturer_specific_client_attribute
 *
 * @param endpoint Zigbee endpoint number.
 * @param cluster Cluster ID of the sought cluster.
 * @param attributeID Attribute ID of the sought attribute.
 * @param manufacturerCode Manufacturer code of the sought cluster.
 * @param dataPtr Pointer to the ZCL attribute.
 * @param dataType ZCL attribute type.
 */
sl_zigbee_af_status_t sl_zigbee_af_write_manufacturer_specific_server_attribute(uint8_t endpoint,
                                                                                sl_zigbee_af_cluster_id_t cluster,
                                                                                sl_zigbee_af_attribute_id_t attributeID,
                                                                                uint16_t manufacturerCode,
                                                                                uint8_t* dataPtr,
                                                                                sl_zigbee_af_attribute_type_t dataType);

/**
 * @brief Write a manufacturer-specific client attribute.
 *
 * This function is the same as sl_zigbee_af_write_attribute
 * except that it saves having to pass the cluster mask
 * and allows passing of a manufacturer code.
 * This is useful for code saving because the write attribute
 * is used frequently throughout the framework.
 *
 * @see sl_zigbee_af_write_client_attribute, sl_zigbee_af_write_server_attribute,
 *      sl_zigbee_af_write_manufacturer_specific_server_attribute
 *
 * @param endpoint Zigbee endpoint number.
 * @param cluster Cluster ID of the sought cluster.
 * @param attributeID Attribute ID of the sought attribute.
 * @param manufacturerCode Manufacturer code of the sought cluster.
 * @param dataPtr Pointer to the ZCL attribute.
 * @param dataType ZCL attribute type.
 */
sl_zigbee_af_status_t sl_zigbee_af_write_manufacturer_specific_client_attribute(uint8_t endpoint,
                                                                                sl_zigbee_af_cluster_id_t cluster,
                                                                                sl_zigbee_af_attribute_id_t attributeID,
                                                                                uint16_t manufacturerCode,
                                                                                uint8_t* dataPtr,
                                                                                sl_zigbee_af_attribute_type_t dataType);

/**
 * @brief Test the success of attribute write.
 *
 * This function returns success if the attribute write is successful.
 * It does not actually write anything, just validates for read-only and
 * data-type.
 *
 * @param endpoint Zigbee endpoint number
 * @param cluster Cluster ID of the sought cluster.
 * @param attributeID Attribute ID of the sought attribute.
 * @param mask CLUSTER_MASK_SERVER or CLUSTER_MASK_CLIENT
 * @param buffer Location where attribute will be written from.
 * @param dataType ZCL attribute type.
 */
sl_zigbee_af_status_t sl_zigbee_af_verify_attribute_write(uint8_t endpoint,
                                                          sl_zigbee_af_cluster_id_t cluster,
                                                          sl_zigbee_af_attribute_id_t attributeID,
                                                          uint8_t mask,
                                                          uint16_t manufacturerCode,
                                                          uint8_t* dataPtr,
                                                          sl_zigbee_af_attribute_type_t dataType);

/**
 * @brief Read the attribute value performing all the checks.
 *
 * This function attempts to read the attribute and store
 * it into the pointer. It also reads the data type.
 * Both dataPtr and dataType may be NULL, signifying that either
 * value or type is not desired.
 *
 * @see sl_zigbee_af_read_client_attribute, sl_zigbee_af_read_server_attribute,
 *      sl_zigbee_af_read_manufacturer_specific_client_attribute,
 *      sl_zigbee_af_read_manufacturer_specific_server_attribute
 *
 * @param endpoint Zigbee endpoint number
 * @param cluster Cluster ID of the sought cluster.
 * @param attributeID Attribute ID of the sought attribute.
 * @param mask CLUSTER_MASK_SERVER or CLUSTER_MASK_CLIENT
 * @param dataPtr Pointer to the ZCL attribute.
 * @param readLength Length of the attribute to be read.
 * @param dataType ZCL attribute type.
 */
sl_zigbee_af_status_t sl_zigbee_af_read_attribute(uint8_t endpoint,
                                                  sl_zigbee_af_cluster_id_t cluster,
                                                  sl_zigbee_af_attribute_id_t attributeID,
                                                  uint8_t mask,
                                                  uint8_t* dataPtr,
                                                  uint8_t readLength,
                                                  sl_zigbee_af_attribute_type_t* dataType);

/**
 * @brief Read the server attribute value performing all the checks.
 *
 * This function attempts to read the attribute and store
 * it into the pointer. It also reads the data type.
 * Both dataPtr and dataType may be NULL, signifying that either
 * value or type is not desired.
 *
 * @see sl_zigbee_af_read_client_attribute,
 *      sl_zigbee_af_read_manufacturer_specific_client_attribute,
 *      sl_zigbee_af_read_manufacturer_specific_server_attribute
 *
 * @param endpoint Zigbee endpoint number
 * @param cluster Cluster ID of the sought cluster.
 * @param attributeID Attribute ID of the sought attribute.
 * @param dataPtr Pointer to the server attribute.
 * @param readLength Length of the attribute to be read.
 */
sl_zigbee_af_status_t sl_zigbee_af_read_server_attribute(uint8_t endpoint,
                                                         sl_zigbee_af_cluster_id_t cluster,
                                                         sl_zigbee_af_attribute_id_t attributeID,
                                                         uint8_t* dataPtr,
                                                         uint8_t readLength);

/**
 * @brief Read the client attribute value, performing all the checks.
 *
 * This function attempts to read the attribute and store
 * it into the pointer. It also reads the data type.
 * Both dataPtr and dataType may be NULL, signifying that either
 * value or type is not desired.
 *
 * @see sl_zigbee_af_read_server_attribute,
 *      sl_zigbee_af_read_manufacturer_specific_client_attribute,
 *      sl_zigbee_af_read_manufacturer_specific_server_attribute
 *
 * @param endpoint Zigbee endpoint number
 * @param cluster Cluster ID of the sought cluster.
 * @param attributeID Attribute ID of the sought attribute.
 * @param dataPtr Pointer to the client attribute.
 * @param readLength Length of the attribute to be read.
 */
sl_zigbee_af_status_t sl_zigbee_af_read_client_attribute(uint8_t endpoint,
                                                         sl_zigbee_af_cluster_id_t cluster,
                                                         sl_zigbee_af_attribute_id_t attributeID,
                                                         uint8_t* dataPtr,
                                                         uint8_t readLength);

/**
 * @brief Read the manufacturer-specific server attribute value, performing all checks.
 *
 * This function attempts to read the attribute and store
 * it into the pointer. It also reads the data type.
 * Both dataPtr and dataType may be NULL, signifying that either
 * value or type is not desired.
 *
 * @see sl_zigbee_af_read_client_attribute, sl_zigbee_af_read_server_attribute,
 *      sl_zigbee_af_read_manufacturer_specific_client_attribute
 *
 * @param endpoint Zigbee endpoint number
 * @param cluster Cluster ID of the sought cluster.
 * @param attributeID Attribute ID of the sought attribute.
 * @param manufacturerCode Manufacturer code of the sought cluster.
 * @param dataPtr Pointer to the server attribute.
 * @param readLength Length of the attribute to be read.
 */
sl_zigbee_af_status_t sl_zigbee_af_read_manufacturer_specific_server_attribute(uint8_t endpoint,
                                                                               sl_zigbee_af_cluster_id_t cluster,
                                                                               sl_zigbee_af_attribute_id_t attributeID,
                                                                               uint16_t manufacturerCode,
                                                                               uint8_t* dataPtr,
                                                                               uint8_t readLength);

/**
 * @brief Read the manufacturer-specific client attribute value, performing all checks.
 *
 * This function attempts to read the attribute and store
 * it into the pointer. It also reads the data type.
 * Both dataPtr and dataType may be NULL, signifying that either
 * value or type is not desired.
 *
 * @see sl_zigbee_af_read_client_attribute, sl_zigbee_af_read_server_attribute,
 *      sl_zigbee_af_read_manufacturer_specific_server_attribute
 *
 * @param endpoint Zigbee endpoint number
 * @param cluster Cluster ID of the sought cluster.
 * @param attributeID Attribute ID of the sought attribute.
 * @param manufacturerCode Manufacturer code of the sought cluster.
 * @param dataPtr Pointer to the server attribute.
 * @param readLength Length of the attribute to be read.
 */
sl_zigbee_af_status_t sl_zigbee_af_read_manufacturer_specific_client_attribute(uint8_t endpoint,
                                                                               sl_zigbee_af_cluster_id_t cluster,
                                                                               sl_zigbee_af_attribute_id_t attributeID,
                                                                               uint16_t manufacturerCode,
                                                                               uint8_t* dataPtr,
                                                                               uint8_t readLength);

/**
 * @brief Return the size of the ZCL data in bytes.
 *
 * @param dataType ZCL data type
 * @return Size in bytes or 0 if invalid data type
 */
uint8_t sl_zigbee_af_get_data_size(uint8_t dataType);

/**
 * @brief Return the number of seconds the network remains open.
 *
 * @return A return value of 0 indicates that the network is closed.
 */
uint8_t sl_zigbee_af_get_open_network_duration_sec(void);

/**
 * @brief Return true if the cluster is in the manufacturer-specific range.
 *
 * @param cluster sl_zigbee_af_cluster_t* to consider
 */
#define sl_zigbee_af_cluster_is_manufacturer_specific(cluster) ((cluster)->clusterId >= 0xFC00u)

/**
 * @brief Return true if the attribute is read only.
 *
 * @param metadata sl_zigbee_af_attribute_metadata_t* to consider.
 */
#define sl_zigbee_af_attribute_is_read_only(metadata) (((metadata)->mask & ATTRIBUTE_MASK_WRITABLE) == 0)

/**
 * @brief Return true if this is a client attribute and false if
 * if it is a server attribute.
 *
 * @param metadata sl_zigbee_af_attribute_metadata_t* to consider.
 */
#define sl_zigbee_af_attribute_is_client(metadata) (((metadata)->mask & ATTRIBUTE_MASK_CLIENT) != 0)

/**
 * @brief Return true if the attribute is saved to a token.
 *
 * @param metadata sl_zigbee_af_attribute_metadata_t* to consider.
 */
#define sl_zigbee_af_attribute_is_tokenized(metadata) (metadata != NULL && (((metadata)->mask & ATTRIBUTE_MASK_TOKENIZE) != 0))

/**
 * @brief Return true if the attribute is saved in external storage.
 *
 * @param metadata sl_zigbee_af_attribute_metadata_t* to consider.
 */
#define sl_zigbee_af_attribute_is_external(metadata) (((metadata)->mask & ATTRIBUTE_MASK_EXTERNAL_STORAGE) != 0)

/**
 * @brief Return true if the attribute is a singleton.
 *
 * @param metadata sl_zigbee_af_attribute_metadata_t* to consider.
 */
#define sl_zigbee_af_attribute_is_singleton(metadata) (((metadata)->mask & ATTRIBUTE_MASK_SINGLETON) != 0)

/**
 * @brief Return true if the attribute is manufacturer specific.
 *
 * @param metadata sl_zigbee_af_attribute_metadata_t* to consider.
 */
#define sl_zigbee_af_attribute_is_manufacturer_specific(metadata) (((metadata)->mask & ATTRIBUTE_MASK_MANUFACTURER_SPECIFIC) != 0)

/**
 * @brief Return the size of attribute in bytes.
 *
 * @param metadata sl_zigbee_af_attribute_metadata_t* to consider.
 */
#define sl_zigbee_af_attribute_size(metadata) ((metadata)->size)

#if !defined(DOXYGEN_SHOULD_SKIP_THIS)
// master array of all defined endpoints
extern sl_zigbee_af_defined_endpoint_t sli_zigbee_af_endpoints[];

#ifdef SL_CATALOG_ZIGBEE_TEST_HARNESS_Z3_PRESENT
// Master array of all zigbee PRO networks - not 'const', since the
// node type may be changed at run-time.
extern sli_zigbee_af_zigbee_pro_network sli_zigbee_af_zigbee_pro_networks[];

// The current zigbee PRO network or NULL.
extern sli_zigbee_af_zigbee_pro_network *sli_zigbee_af_current_zigbee_pro_network;
#else
// Master array of all Zigbee PRO networks.
extern const sli_zigbee_af_zigbee_pro_network sli_zigbee_af_zigbee_pro_networks[];

// The current Zigbee PRO network or NULL.
extern const sli_zigbee_af_zigbee_pro_network *sli_zigbee_af_current_zigbee_pro_network;
#endif
// True if the current network is a Zigbee PRO network.
#define sli_zigbee_af_pro_is_current_network() (sli_zigbee_af_current_zigbee_pro_network != NULL)
#endif

/**
 * @brief Take an index of an endpoint and return the Zigbee endpoint.
 *
 *@param index Index of an endpoint.
 *@return Zigbee endpoint.
 */
uint8_t sl_zigbee_af_endpoint_from_index(uint8_t index);

/**
 * Return the index of a given endpoint.
 *
 *@param endpoint Zigbee endpoint.
 *@return Index of a Zigbee endpoint.
 */
uint8_t sl_zigbee_af_index_from_endpoint(uint8_t endpoint);

/**
 * Return the index of a given endpoint. It does not ignore disabled endpoints.
 *
 *@param endpoint Zigbee endpoint.
 *@return Index of a Zigbee endpoint.
 */
uint8_t sl_zigbee_af_index_from_endpoint_including_disabled_endpoints(uint8_t endpoint);

/**
 * Return the endpoint index within a given cluster (Client-side),
 * looking only for standard clusters.
 *
 *@param endpoint Zigbee endpoint.
 *@param clusterId Cluster ID of a sought cluster.
 *@return Index of a Zigbee endpoint.
 */
uint8_t sl_zigbee_af_find_cluster_client_endpoint_index(uint8_t endpoint, sl_zigbee_af_cluster_id_t clusterId);

/**
 * Return the endpoint index within a given cluster (Server-side),
 * looking only for standard clusters.
 *
 *@param endpoint Zigbee endpoint.
 *@param clusterId Cluster ID of a sought cluster.
 *@return Index of a Zigbee endpoint.
 */
uint8_t sl_zigbee_af_find_cluster_server_endpoint_index(uint8_t endpoint, sl_zigbee_af_cluster_id_t clusterId);

/**
 * @brief Take an index of an endpoint and return the profile ID for it.
 */
#define sl_zigbee_af_profile_id_from_index(index) (sli_zigbee_af_endpoints[(index)].profileId)

/**
 * @brief Take an index of an endpoint and return the device ID for it.
 */
#define sl_zigbee_af_device_id_from_index(index) (sli_zigbee_af_endpoints[(index)].deviceId)

/**
 * @brief Take an index of an endpoint and return the device version for it.
 */
#define sl_zigbee_af_device_version_from_index(index) (sli_zigbee_af_endpoints[(index)].deviceVersion)

/**
 * @brief Take an index of an endpoint and return the network index for it.
 */
#define sl_zigbee_af_network_index_from_endpoint_index(index) (sli_zigbee_af_endpoints[(index)].networkIndex)

/**
 * @brief Return the network index of a given endpoint.
 *
 *@param endpoint Zigbee endpoint.
 *@return Network index of a Zigbee endpoint.
 */
uint8_t sl_zigbee_af_network_index_from_endpoint(uint8_t endpoint);

/**
 * @brief Return the primary profile ID.
 *
 * Primary profile is the profile of a primary endpoint as defined
 * in AppBuilder.
 */
#define sl_zigbee_af_primary_profile_id()       sl_zigbee_af_profile_id_from_index(0)

/**
 * @brief Return the primary endpoint.
 */
#define sl_zigbee_af_primary_endpoint() (sli_zigbee_af_endpoints[0].endpoint)

/**
 * @brief Return the total number of endpoints (dynamic and pre-compiled).
 */
uint8_t sl_zigbee_af_endpoint_count(void);

/**
 * @brief Return the number of pre-compiled endpoints.
 */
uint8_t sl_zigbee_af_fixed_endpoint_count(void);

#if (SL_ZIGBEE_AF_PLUGIN_ZCL_CLUSTER_ENABLE_DISABLE_RUN_TIME == 1)
#if !defined(SL_ZIGBEE_TEST)
/**
 * Enable/disable cluster.
 *
 *@param endpoint Zigbee endpoint.
 *@param clusterId the ID of cluster that will be enabled/disabled.
 *@param mask Mask is either 0 (both client or server) or CLUSTER_MASK_CLIENT or CLUSTER_MASK_SERVER.
 *@param enable 1 to enable, 0 to disable.
 *@return true if success, false if not success.
 */
bool sl_zigbee_af_cluster_enable_disable(uint8_t endpoint,
                                         sl_zigbee_af_cluster_id_t clusterId,
                                         sl_zigbee_af_cluster_mask_t mask,
                                         bool enable);

/**
 * Determine if a cluster is enabled or disabled.
 *
 *@param endpoint Zigbee endpoint.
 *@param clusterId the ID of cluster that will be enabled/disabled.
 *@param mask Mask is either 0 (both client or server) or CLUSTER_MASK_CLIENT or CLUSTER_MASK_SERVER.
 *@return true if specified cluster is enabled, false if it is disabled.
 */
bool sl_zigbee_af_is_cluster_enabled(uint8_t endpoint,
                                     sl_zigbee_af_cluster_id_t clusterId,
                                     sl_zigbee_af_cluster_mask_t mask);
#endif //!SL_ZIGBEE_TEST
#endif //SL_ZIGBEE_AF_PLUGIN_ZCL_CLUSTER_ENABLE_DISABLE_RUN_TIME

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/**
 * Data types are either analog or discrete. This makes a difference for
 * some of the ZCL global commands
 */
enum {
  SL_ZIGBEE_AF_DATA_TYPE_ANALOG     = 0,
  SL_ZIGBEE_AF_DATA_TYPE_DISCRETE   = 1,
  SL_ZIGBEE_AF_DATA_TYPE_NONE       = 2
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

/**
 * @brief Return the type of the attribute, either ANALOG, DISCRETE, or NONE.
 */
uint8_t sl_zigbee_af_get_attribute_analog_or_discrete_type(uint8_t dataType);

/**
 *@brief Return true if type is signed, false otherwise.
 */
bool sl_zigbee_af_is_type_signed(sl_zigbee_af_attribute_type_t dataType);

/**
 * @brief Extract a 32-bit integer from the message buffer.
 */
uint32_t sl_zigbee_af_get_int32u(const uint8_t* message, uint16_t currentIndex, uint16_t msgLen);

/**
 * @brief Extract a 24-bit integer from the message buffer.
 */
uint32_t sl_zigbee_af_get_int24u(const uint8_t* message, uint16_t currentIndex, uint16_t msgLen);

/**
 * @brief Extract a 16-bit integer from the message buffer.
 */
uint16_t sl_zigbee_af_get_int16u(const uint8_t* message, uint16_t currentIndex, uint16_t msgLen);
/**
 * @brief Extract a ZCL string from the message buffer.
 */
uint8_t* sl_zigbee_af_get_string(uint8_t* message, uint16_t currentIndex, uint16_t msgLen);
/**
 * @brief Extract a ZCL long string from the message buffer.
 */
uint8_t* sl_zigbee_af_get_long_string(uint8_t* message, uint16_t currentIndex, uint16_t msgLen);
/*
 * @brief Extract a ZCL Date from the message buffer and returns it
 * in the given destination. Returns the number of bytes copied.
 */
uint8_t sl_zigbee_af_get_date(uint8_t* message, uint16_t currentIndex, uint16_t msgLen, sl_zigbee_af_date_t *destination);

/**
 * @brief Extract a single byte out of the message.
 */
#define sl_zigbee_af_get_int8u(message, currentIndex, msgLen) message[currentIndex]

/**
 * @brief Copy a uint8_t from variable into buffer.
 */
#define sl_zigbee_af_copy_int8u(data, index, x) (data[index] = (x))
/**
 * @brief Copy a uint16_t value into a buffer.
 */
void sl_zigbee_af_copy_int16u(uint8_t *data, uint16_t index, uint16_t x);
/**
 * @brief Copy a uint24_t value into a buffer.
 */
void sl_zigbee_af_copy_int24u(uint8_t *data, uint16_t index, uint32_t x);
/**
 * @brief Copy a uint32_t value into a buffer.
 */
void sl_zigbee_af_copy_int32u(uint8_t *data, uint16_t index, uint32_t x);
/*
 * @brief Copy a ZCL string type into a buffer.  The size
 * parameter should indicate the maximum number of characters to copy to the
 * destination buffer not including the length byte.
 */
void sl_zigbee_af_copy_string(uint8_t *dest, uint8_t *src, uint8_t size);
/*
 * @brief Copy a ZCL long string into a buffer.  The size
 * parameter should indicate the maximum number of characters to copy to the
 * destination buffer not including the length bytes.
 */
void sl_zigbee_af_copy_long_string(uint8_t *dest, uint8_t *src, uint16_t size);
/*
 * @brief Determine the length of a Zigbee Cluster Library string
 *   (where the first byte is assumed to be the length).
 */
uint8_t sl_zigbee_af_string_length(const uint8_t *buffer);
/*
 * @brief Determine the length of a Zigbee Cluster Library long string.
 *   (where the first two bytes are assumed to be the length).
 */
uint16_t sl_zigbee_af_long_string_length(const uint8_t *buffer);

/*
 * @brief Determine the size of a Zigbee Cluster Library
 * attribute value.
 *
 * The attribute could be non-string, string, or long string. For strings,
 * the size includes the length of the string plus the number of the string's
 * length prefix byte(s).
 *
 * Additionally, checks that the resulting size does not exceed the
 * specified buffer size.
 *
 * @param dataType Zigbee data type
 * @param buffer pointer to a buffer containing a string value
 * @param bufferSize size of the buffer
 *
 * @return 0 if dataType is unrecognized or data size exceeds buffer size
 *.        nonzero for valid data size
 */
uint16_t sl_zigbee_af_attribute_value_size(sl_zigbee_af_attribute_type_t dataType,
                                           const uint8_t *buffer,
                                           const uint16_t bufferSize);

/** @} */ // end of name API
/** @} */ // end of attribute-storage

/**
 * @defgroup device-control Device Control
 * @ingroup af
 * @brief API for the Device Control functionality
 * in the Application Framework
 *
 * Device Control description.
 *
 */

/**
 * @addtogroup device-control
 * @{
 */

/** @name API */
// @{

/**
 * @brief Check whether the endpoint is enabled.
 *
 * This function returns true if device at a given endpoint is
 * enabled. At startup, all endpoints are enabled.
 *
 * @param endpoint Zigbee endpoint number
 */
bool sl_zigbee_af_is_device_enabled(uint8_t endpoint);

/**
 * @brief Check whether the endpoint is identifying.
 *
 * This function returns true if the device at a given endpoint is
 * identifying.
 *
 * @param endpoint Zigbee endpoint number
 */
bool sl_zigbee_af_is_device_identifying(uint8_t endpoint);

/**
 * @brief Enable or disable an endpoint.
 *
 * By calling this function, you turn off all processing of incoming traffic
 * for a given endpoint.
 *
 * @param endpoint Zigbee endpoint number
 */
void sl_zigbee_af_set_device_enabled(uint8_t endpoint, bool enabled);

/** @} */ // end of name API
/** @} */ // end of device-control

/**
 * @defgroup miscellaneous Miscellaneous
 * @ingroup af
 * @brief API for the Miscellaneous functionality
 * in the Application Framework
 *
 * Miscellaneous description.
 *
 */

/**
 * @addtogroup miscellaneous
 * @{
 */

/** @name API */
// @{

/**
 * @brief Set the Zigbee stack task to ready when running on an OS.
 */
void sl_zigbee_wakeup_common_task(void);

/**
 * @brief Enable/disable endpoints.
 */
bool sl_zigbee_af_endpoint_enable_disable(uint8_t endpoint, bool enable);

/**
 * @brief Determine if an endpoint at the specified index is enabled or disabled.
 */
bool sl_zigbee_af_endpoint_index_is_enabled(uint8_t index);

/**
 * @brief Indicate a new image verification is taking place.
 */
#define SL_ZIGBEE_AF_NEW_IMAGE_VERIFICATION true

/**
 * @brief Indicate the continuation of an image verification already
 * in progress.
 */
#define SL_ZIGBEE_AF_CONTINUE_IMAGE_VERIFY  false

/**
 * @brief This variable defines an invalid image ID.  It is used
 *   to determine if a returned sl_zigbee_af_ota_image_id_t is valid or not
 *   by passing the data to the function
 *   sl_zigbee_af_is_ota_image_id_valid().
 */
extern const sl_zigbee_af_ota_image_id_t sl_zigbee_af_invalid_image_id;

/**
 * @brief Return true if a given ZCL data type is a string type.
 *
 * Use this function to perform a different
 * memory operation on a certain attribute because it is a string type.
 * Since ZCL strings carry length as the first byte(s), it is often required
 * to treat them differently than regular data types.
 *
 * @return true if data type is a string.
 */
bool sl_zigbee_af_is_this_data_type_a_string_type(sl_zigbee_af_attribute_type_t dataType);

/** @brief Return true if the given attribute type is a string. */
bool sl_zigbee_af_is_string_attribute_type(sl_zigbee_af_attribute_type_t attributeType);

/** @brief Return true if the given attribute type is a long string. */
bool sl_zigbee_af_is_long_string_attribute_type(sl_zigbee_af_attribute_type_t attributeType);

/**
 * @brief The mask applied by ::sl_zigbee_af_next_sequence when generating ZCL
 * sequence numbers.
 */
#define SL_ZIGBEE_AF_ZCL_SEQUENCE_MASK 0x7Fu

/**
 * @brief The mask applied to generated message tags used by the framework when sending messages via EZSP.
 * Customers who call ezspSend functions directly must use message tags outside this mask.
 */
#define SL_ZIGBEE_AF_MESSAGE_TAG_MASK 0x7Fu

/**
 * @brief Increment the ZCL sequence number and return the value.
 *
 * ZCL messages have sequence numbers so that they can be matched up with other
 * messages in the transaction.  To avoid conflicts with sequence numbers
 * generated independently by the application, this API returns sequence
 * numbers with the high bit clear.  If the application generates its own
 * sequence numbers, it should use numbers with the high bit set.
 *
 * @return The next ZCL sequence number.
 */
uint8_t sl_zigbee_af_next_sequence(void);

/**
 * @brief Retrieve the last sequence number that was used.
 *
 */
uint8_t sl_zigbee_af_get_last_sequence_number(void);

/**
 * @brief Compare two values of known length as integers.
 * .
 * Simple integer comparison function.
 * Signed integer comparison are supported for numbers with length of
 * 4 (bytes) or less.
 * The integers are in native endianness.
 *
 * @return -1, if val1 is smaller
 *          0, if they are the same or if two negative numbers with length
 *          greater than 4 is being compared
 *          1, if val2 is smaller.
 */
int8_t sl_zigbee_af_compare_values(uint8_t* val1, uint8_t* val2, uint8_t len, bool signedNumber);

/**
 * @brief Populate the passed EUI64 with the local EUI64 MAC address.
 */
void sl_zigbee_af_get_eui64(sl_802154_long_addr_t returnEui64);

#ifdef EZSP_HOST
// Normally this is provided by the stack code, but on the host
// it is provided by the application code.
void sl_util_reverse_mem_copy(uint8_t* dest, const uint8_t* src, uint16_t length);

/** @brief Read the EZSP status of the most recent command sent.
 *
 * @return An sl_zigbee_ezsp_status_t value indicating whether the last EZSP command
 * sent successfully or not.
 */
sl_zigbee_ezsp_status_t sl_zigbee_ezsp_get_last_status();
#endif // EZSP_HOST

/**
 * @brief Return the node ID of the local node.
 */
sl_802154_short_addr_t sl_zigbee_af_get_node_id(void);

#if defined(DOXYGEN_SHOULD_SKIP_THIS) || defined(EZSP_HOST)
/**
 * @brief Generate a random key (link, network, or master).
 */
sl_status_t sl_zigbee_af_generate_random_key(sl_zigbee_key_data_t *result);
#else
  #define sl_zigbee_af_generate_random_key(result) sl_zigbee_generate_random_key(result)
#endif

/**
 * @brief Return the PAN ID of the local node.
 */
sl_802154_pan_id_t sl_zigbee_af_get_pan_id(void);

/**
 * @brief Return the radioChannel of the current network.
 */
uint8_t sl_zigbee_af_get_radio_channel(void);

/**
 * @brief Return the current network state.  This call caches the results
 *   on the host to prevent frequent EZSP transactions.
 */
sl_zigbee_network_status_t sl_zigbee_af_network_state(void);

/**
 * @brief Return the current network parameters.
 */
sl_status_t sl_zigbee_af_get_network_parameters(sl_zigbee_node_type_t *nodeType,
                                                sl_zigbee_network_parameters_t *parameters);

/**
 * @brief Return the current node type.
 */
sl_status_t sl_zigbee_af_get_node_type(sl_zigbee_node_type_t *nodeType);

/**
 */
#define SL_ZIGBEE_AF_REJOIN_DUE_TO_END_DEVICE_MOVE            0xA0u
#define SL_ZIGBEE_AF_REJOIN_DUE_TO_TC_KEEPALIVE_FAILURE       0xA1u
#define SL_ZIGBEE_AF_REJOIN_DUE_TO_CLI_COMMAND                0xA2u
#define SL_ZIGBEE_AF_REJOIN_DUE_TO_WWAH_CONNECTIVITY_MANAGER  0xA3u

#define SL_ZIGBEE_AF_REJOIN_FIRST_REASON                SL_ZIGBEE_AF_REJOIN_DUE_TO_END_DEVICE_MOVE
#define SL_ZIGBEE_AF_REJOIN_LAST_REASON                 SL_ZIGBEE_AF_REJOIN_DUE_TO_END_DEVICE_MOVE

/**
 * @brief Enable local permit join and optionally broadcast the ZDO
 * Mgmt_Permit_Join_req message. This API can be called from any device
 * type and still return SL_STATUS_OK. If the API is called from an
 * end device, the permit association bit will just be left off.
 *
 * @param duration The duration that the permit join bit will remain on
 * and other devices will be able to join the current network.
 * @param broadcastMgmtPermitJoin whether or not to broadcast the ZDO
 * Mgmt_Permit_Join_req message.
 *
 * @returns status of whether or not permit join was enabled.
 */
sl_status_t sl_zigbee_af_permit_join(uint8_t duration,
                                     bool broadcastMgmtPermitJoin);

#ifdef DOXYGEN_SHOULD_SKIP_THIS
/**
 * @brief Enable local permit join and broadcast the ZDO
 * Mgmt_Permit_Join_req message. This API can be called from any device
 * type and still return SL_STATUS_OK. If the API is called from an
 * end device, the permit association bit will just be left off.
 *
 * @param duration The duration that the permit join bit will remain on
 * and other devices will be able to join the current network.
 *
 * @returns status of whether or not permit join was enabled.
 */
sl_status_t sl_zigbee_af_broadcast_permit_join(uint8_t duration);
#else
  #define sl_zigbee_af_broadcast_permit_join(duration) \
  sl_zigbee_af_permit_join((duration), true)
#endif

/** @brief Acquire the app framework mutex (for RTOS builds).
 * This should be done if code run from outside of the app framework (callback)
 * context in RTOS builds needs to call app framework APIs, as interactions
 * between app framework and other application tasks are not otherwise designed
 * to be thread-safe.
 * Note that APIs relating to app framework events are included in this category
 * of app framework APIs (so thread-safe interactions with the event queue from
 * other tasks require the acquisition of this lock).
 *
 */
void sl_zigbee_af_acquire_lock(void);

/** @brief Release the app framework mutex (for RTOS builds), allowing other
 * application tasks (like the app framework task) waiting on this mutex to run.
 * This should be done once the application code has finished its calls
 * to app framework data or APIs.
 *
 */
void sl_zigbee_af_release_lock(void);

/** @} */ // end of name API
/** @} */ // end of miscellaneous

/**
 * @defgroup sleep-control Sleep Control
 * @ingroup af
 * @brief API for the Sleep Control functionality
 * in the Application Framework
 *
 * Sleep Control description.
 *
 */

/**
 * @addtogroup sleep-control
 * @{
 */

/** @name API */
// @{

/**
 * @brief Friendly define for use in the scheduling or canceling client events
 * with sl_zigbee_zcl_schedule_cluster_tick() and
 * sl_zigbee_zcl_deactivate_cluster_tick().
 */
#define SL_ZIGBEE_AF_CLIENT_CLUSTER_TICK true

/**
 * @brief Friendly define for use in the scheduling or canceling server events
 * with sl_zigbee_zcl_schedule_cluster_tick() and
 * sl_zigbee_zcl_deactivate_cluster_tick().
 */
#define SL_ZIGBEE_AF_SERVER_CLUSTER_TICK false

/**
 * @brief Schedule a cluster-related event inside the
 * application framework's event mechanism.  This function provides a wrapper
 * for the Ember stack event mechanism which allows the cluster code to access
 * its events by their endpoint, cluster ID, and client/server identity.  The
 * passed poll and sleep controls allow the cluster to indicate whether it
 * needs to long or short poll and whether it needs to stay awake or if it can
 * sleep.
 *
 * @param endpoint The endpoint of the event to be scheduled.
 * @param clusterId The cluster id of the event to be scheduled.
 * @param isClient ::SL_ZIGBEE_AF_CLIENT_CLUSTER_TICK if the event to be scheduled
 *        is associated with a client cluster or ::SL_ZIGBEE_AF_SERVER_CLUSTER_TICK
 *        otherwise.
 * @param delayMs The number of milliseconds until the event should be called.
 * @param pollControl ::SL_ZIGBEE_AF_SHORT_POLL if the cluster needs to short poll
 *        or ::SL_ZIGBEE_AF_LONG_POLL otherwise.
 * @param sleepControl ::SL_ZIGBEE_AF_STAY_AWAKE if the cluster needs to stay awake
 *        or SL_ZIGBEE_AF_OK_TO_SLEEP otherwise.
 *
 * @return SL_STATUS_OK if the event was scheduled or an error otherwise.
 */
sl_status_t sl_zigbee_zcl_schedule_tick_extended(uint8_t endpoint,
                                                 sl_zigbee_af_cluster_id_t clusterId,
                                                 bool isClient,
                                                 uint32_t delayMs,
                                                 sl_zigbee_af_event_poll_control_t pollControl,
                                                 sl_zigbee_af_event_sleep_control_t sleepControl);

/**
 * @brief Schedule a cluster-related event inside the application
 * framework's event mechanism.
 * This function is a wrapper for ::sl_zigbee_af_schedule_tick_extended.  The cluster
 * on the given endpoint will be set to long poll if sleepControl is set to
 * ::SL_ZIGBEE_AF_OK_TO_HIBERNATE or will be set to short poll otherwise.  It will
 * stay awake if sleepControl is ::SL_ZIGBEE_AF_STAY_AWAKE and will sleep
 * otherwise.
 *
 * @param endpoint The endpoint of the event to be scheduled.
 * @param clusterId The cluster id of the event to be scheduled.
 * @param isClient ::SL_ZIGBEE_AF_CLIENT_CLUSTER_TICK if the event to be scheduled
 *        is associated with a client cluster or ::SL_ZIGBEE_AF_SERVER_CLUSTER_TICK
 *        otherwise.
 * @param delayMs The number of milliseconds until the event should be called.
 * @param sleepControl the priority of the event, what the processor should
 *        be allowed to do in terms of sleeping while the event is active.
 *
 * @return SL_STATUS_OK if the event was scheduled or an error otherwise.
 */
sl_status_t sl_zigbee_zcl_schedule_cluster_tick(uint8_t endpoint,
                                                sl_zigbee_af_cluster_id_t clusterId,
                                                bool isClient,
                                                uint32_t delayMs,
                                                sl_zigbee_af_event_sleep_control_t sleepControl);

/**
 * @brief Schedule a cluster client event.  This function
 * is a wrapper for ::sl_zigbee_zcl_schedule_tick_extended.
 *
 * @param endpoint The endpoint of the event to be scheduled
 * @param clusterId The cluster id of the event to be scheduled
 * @param delayMs The number of milliseconds until the event should be called.
 * @param pollControl ::SL_ZIGBEE_AF_SHORT_POLL if the cluster needs to short poll
 *        or ::SL_ZIGBEE_AF_LONG_POLL otherwise.
 * @param sleepControl ::SL_ZIGBEE_AF_STAY_AWAKE if the cluster needs to stay awake
 *        or SL_ZIGBEE_AF_OK_TO_SLEEP otherwise.
 *
 * @return SL_STATUS_OK if the event was scheduled or an error otherwise.
 */
sl_status_t sl_zigbee_zcl_schedule_client_tick_extended(uint8_t endpoint,
                                                        sl_zigbee_af_cluster_id_t clusterId,
                                                        uint32_t delayMs,
                                                        sl_zigbee_af_event_poll_control_t pollControl,
                                                        sl_zigbee_af_event_sleep_control_t sleepControl);

/**
 * @brief Schedule a cluster client event.  This function
 * is a wrapper for ::sl_zigbee_zcl_schedule_client_tick_extended.  It indicates
 * that the cluster client on the given endpoint can long poll and can sleep.
 *
 * @param endpoint The endpoint of the event to be scheduled.
 * @param clusterId The cluster id of the event to be scheduled.
 * @param delayMs The number of milliseconds until the event should be called.
 *
 * @return SL_STATUS_OK if the event was scheduled or an error otherwise.
 */
sl_status_t sl_zigbee_zcl_schedule_client_tick(uint8_t endpoint,
                                               sl_zigbee_af_cluster_id_t clusterId,
                                               uint32_t delayMs);

/**
 * @brief Schedule a cluster server event.  This function
 * is a wrapper for ::sl_zigbee_zcl_schedule_tick_extended.
 *
 * @param endpoint The endpoint of the event to be scheduled.
 * @param clusterId The cluster id of the event to be scheduled.
 * @param delayMs The number of milliseconds until the event should be called.
 * @param pollControl ::SL_ZIGBEE_AF_SHORT_POLL if the cluster needs to short poll
 *        or ::SL_ZIGBEE_AF_LONG_POLL otherwise.
 * @param sleepControl ::SL_ZIGBEE_AF_STAY_AWAKE if the cluster needs to stay awake
 *        or SL_ZIGBEE_AF_OK_TO_SLEEP otherwise.
 *
 * @return SL_STATUS_OK if the event was scheduled or an error otherwise.
 */
sl_status_t sl_zigbee_zcl_schedule_server_tick_extended(uint8_t endpoint,
                                                        sl_zigbee_af_cluster_id_t clusterId,
                                                        uint32_t delayMs,
                                                        sl_zigbee_af_event_poll_control_t pollControl,
                                                        sl_zigbee_af_event_sleep_control_t sleepControl);

/**
 * @brief Schedule a cluster server event.  This function
 * is a wrapper for ::sl_zigbee_zcl_schedule_server_tick_extended.  It indicates
 * that the cluster server on the given endpoint can long poll and can sleep.
 *
 * @param endpoint The endpoint of the event to be scheduled
 * @param clusterId The cluster id of the event to be scheduled.
 * @param delayMs The number of milliseconds until the event should be called.
 *
 * @return SL_STATUS_OK if the event was scheduled or an error otherwise.
 */
sl_status_t sl_zigbee_zcl_schedule_server_tick(uint8_t endpoint,
                                               sl_zigbee_af_cluster_id_t clusterId,
                                               uint32_t delayMs);

/**
 * @brief Deactivate a cluster-related event.  This function
 * provides a wrapper for the Ember stack's event mechanism, which allows an
 * event to be accessed by its endpoint, cluster ID, and client/server
 * identity.
 *
 * @param endpoint The endpoint of the event to be deactivated.
 * @param clusterId The cluster id of the event to be deactivated.
 * @param isClient ::SL_ZIGBEE_AF_CLIENT_CLUSTER_TICK if the event to be
 *        deactivated is a client cluster ::SL_ZIGBEE_AF_SERVER_CLUSTER_TICK
 *        otherwise.
 *
 * @return SL_STATUS_OK if the event was deactivated or an error otherwise.
 */
sl_status_t sl_zigbee_zcl_deactivate_cluster_tick(uint8_t endpoint,
                                                  sl_zigbee_af_cluster_id_t clusterId,
                                                  bool isClient);

/**
 * @brief Deactivate a cluster client event.  This function
 * is a wrapper for ::sl_zigbee_zcl_deactivate_cluster_tick.
 *
 * @param endpoint The endpoint of the event to be deactivated.
 * @param clusterId The cluster id of the event to be deactivated.
 *
 * @return SL_STATUS_OK if the event was deactivated or an error otherwise.
 */
sl_status_t sl_zigbee_zcl_deactivate_client_tick(uint8_t endpoint,
                                                 sl_zigbee_af_cluster_id_t clusterId);

/**
 * @brief Deactivate a cluster server event.  This function
 * is a wrapper for ::sl_zigbee_zcl_deactivate_cluster_tick.
 *
 * @param endpoint The endpoint of the event to be deactivated.
 * @param clusterId The cluster ID of the event to be deactivated.
 *
 * @return SL_STATUS_OK if the event was deactivated or an error otherwise.
 */
sl_status_t sl_zigbee_zcl_deactivate_server_tick(uint8_t endpoint,
                                                 sl_zigbee_af_cluster_id_t clusterId);

/**
 * @brief Retrieve the most restrictive sleep
 * control value for all scheduled events. This function is
 * used by sl_zigbee_af_ok_to_nap and emberAfOkToHibernate to makes sure
 * that there are no events scheduled, which will keep the device
 * from hibernating or napping.
 * @return The most restrictive sleep control value for all
 *         scheduled events or the value returned by
 *         sl_zigbee_af_get_default_sleep_control()
 *         if no events are currently scheduled. The default
 *         sleep control value is initialized to
 *         SL_ZIGBEE_AF_OK_TO_HIBERNATE but can be changed at any
 *         time using the sl_zigbee_af_set_default_sleep_control() function.
 */
#define sl_zigbee_af_get_current_sleep_control() \
  sl_zigbee_af_get_current_sleep_control_cb()

/**
 * @brief Set the default sleep control
 *        value against which all scheduled event sleep control
 *        values will be evaluated. This can be used to keep
 *        a device awake for an extended period of time by setting
 *        the default to SL_ZIGBEE_AF_STAY_AWAKE and then resetting
 *        the value to SL_ZIGBEE_AF_OK_TO_HIBERNATE once the wake
 *        period is complete.
 */
#define  sl_zigbee_af_set_default_sleep_control(x) \
  sl_zigbee_af_set_default_sleep_control_cb(x)

/**
 * @brief Retrieve the default sleep control against
 *        which all event sleep control values are evaluated. The
 *        default sleep control value is initialized to
 *        SL_ZIGBEE_AF_OK_TO_HIBERNATE but can be changed by the application
 *        at any time using the sl_zigbee_af_set_default_sleep_control() function.
 * @return The current default sleep control value.
 */
#define sl_zigbee_af_get_default_sleep_control() \
  sl_zigbee_af_get_default_sleep_control_cb()

#if !defined(DOXYGEN_SHOULD_SKIP_THIS)
/**
 * @brief Add a task to the task register.
 */
#define sl_zigbee_af_add_to_current_app_tasks(x) \
  sl_zigbee_af_add_to_current_app_tasks_cb(x)

/**
 * @brief Remove a task from the task register.
 */
#define sl_zigbee_af_remove_from_current_app_tasks(x) \
  sl_zigbee_af_remove_from_current_app_tasks_cb(x)

/**
 * @brief Retrieve the bitmask of all application
 * framework tasks currently in progress. This can be useful for debugging if
 * some task is holding the device out of hibernation.
 */
#define sl_zigbee_af_current_app_tasks() sl_zigbee_af_get_current_app_tasks_cb()
#endif // !DOXYGEN_SHOULD_SKIP_THIS

/** @} */ // end of name API
/** @} */ // end of sleep-control

/**
 * @defgroup messaging Messaging
 * @ingroup af
 * @brief API for the Messaging functionality
 * in the Application Framework
 *
 * Messaging description.
 *
 */

/**
 * @addtogroup messaging
 * @{
 */

/** @name API */
// @{

/**
 * @brief Send a ZCL response, based on the information
 * that is currently in the outgoing buffer. It is expected that a complete
 * ZCL message is present, including header. The application may use
 * this method directly from within the message handling function
 * and associated callbacks. However, this will result in the
 * response being sent before the APS ACK is sent, which is not
 * ideal.
 *
 * NOTE:  This will overwrite the ZCL sequence number of the message
 * to use the LAST received sequence number.
 */
sl_status_t sl_zigbee_af_send_response(void);

/**
 * @brief Send ZCL response with attached message sent callback
 */
sl_status_t sl_zigbee_af_send_response_with_cb(sl_zigbee_af_message_sent_function_t callback);

/** @brief Send a multicast message to all endpoints that share
 * a specific multicast ID and are within a specified number of hops of the
 * sender.
 *
 * @param multicastId     The multicastId
 *
 * @param alias The alias from which to send the multicast. If not needed use SL_ZIGBEE_NULL_NODE_ID
 *
 * @param sequence The aliased NWK sequence number for the message. Only used if there is an alias source.
 *
 * @param apsFrame The aps frame
 *
 * @param messageLength The mmessageLength
 *
 * @param message          A message.
 *
 * @return An ::sl_status_t value. For any result other than ::SL_STATUS_OK,
 *  the message will not be sent.\n\n
 */
sl_status_t sl_zigbee_af_send_multicast(sl_zigbee_multicast_id_t multicastId,
                                        sl_802154_short_addr_t alias,
                                        uint8_t sequence,
                                        sl_zigbee_aps_frame_t *apsFrame,
                                        uint16_t messageLength,
                                        uint8_t* message);

/**
 * @brief Multicast the message to the group in the binding table that
 * match the cluster and source endpoint in the APS frame.  Note: if the
 * binding table contains many matching entries, calling this API cause a
 * significant amount of network traffic. Care should be taken when considering
 * the effects of broadcasts in a network.
 */
sl_status_t sl_zigbee_af_send_multicast_to_bindings(sl_zigbee_aps_frame_t *apsFrame,
                                                    uint16_t messageLength,
                                                    uint8_t* message);

/**
 * @brief Send multicast with attached message sent callback.
 */
sl_status_t sl_zigbee_af_send_multicast_with_cb(sl_zigbee_multicast_id_t multicastId,
                                                sl_802154_short_addr_t alias,
                                                uint8_t sequence,
                                                sl_zigbee_aps_frame_t *apsFrame,
                                                uint16_t messageLength,
                                                uint8_t* message,
                                                sl_zigbee_af_message_sent_function_t callback);

/** @brief Send a broadcast message as per the ZigBee specification.
 *
 * The message will be delivered to all nodes within @c radius
 * hops of the sender. A radius of zero is converted to ::SL_ZIGBEE_MAX_HOPS.
 *
 * @param alias       The aliased source from which to send the broadcast.
 * SL_ZIGBEE__NULL_NODE_ID could be used if this is a simple broadcast message, and not aliased/proxied
 *
 * @param destination  The destination to which to send the broadcast.
 *  This must be one of three ZigBee broadcast addresses.
 *
 * @param sequence     The NWK sequence number for the message,
 * if there is a non-null alias source
 *
 * @param apsFrame     The APS frame data to be included in the message.
 *
 *  @param messageLength     messageLength
 * @param message      The actual message to be sent.
 *
 * @return An ::sl_status_t value.
 */
sl_status_t sl_zigbee_af_send_broadcast(sl_802154_short_addr_t alias,
                                        sl_802154_short_addr_t destination,
                                        uint8_t sequence,
                                        sl_zigbee_aps_frame_t *apsFrame,
                                        uint16_t messageLength,
                                        uint8_t* message);

/**
 * @brief Send broadcast with attached message sent callback.
 */
sl_status_t sl_zigbee_af_send_broadcast_with_cb(sl_802154_short_addr_t destination,
                                                sl_zigbee_aps_frame_t *apsFrame,
                                                uint16_t messageLength,
                                                uint8_t *message,
                                                sl_802154_short_addr_t alias,
                                                uint8_t sequence,
                                                sl_zigbee_af_message_sent_function_t callback);

/**
 * @brief Send unicast.
 */
sl_status_t sl_zigbee_af_send_unicast(sl_zigbee_outgoing_message_type_t type,
                                      uint16_t indexOrDestination,
                                      sl_zigbee_aps_frame_t *apsFrame,
                                      uint16_t messageLength,
                                      uint8_t* message);

/**
 * @brief Send unicast with attached message sent callback.
 */
sl_status_t sl_zigbee_af_send_unicast_with_cb(sl_zigbee_outgoing_message_type_t type,
                                              uint16_t indexOrDestination,
                                              sl_zigbee_aps_frame_t *apsFrame,
                                              uint16_t messageLength,
                                              uint8_t* message,
                                              sl_zigbee_af_message_sent_function_t callback);

/**
 * @brief Unicast the message to each remote node in the binding table that
 * matches the cluster and source endpoint in the APS frame.  Note: if the
 * binding table contains many matching entries, calling this API cause a
 * significant amount of network traffic.
 */
sl_status_t sl_zigbee_af_send_unicast_to_bindings(sl_zigbee_aps_frame_t *apsFrame,
                                                  uint16_t messageLength,
                                                  uint8_t* message);

/**
 * @brief sl_zigbee_af_send_unicast_to_bindings with attached message sent callback.
 */
sl_status_t sl_zigbee_af_send_unicast_to_bindings_with_cb(sl_zigbee_aps_frame_t *apsFrame,
                                                          uint16_t messageLength,
                                                          uint8_t* message,
                                                          sl_zigbee_af_message_sent_function_t callback);

/**
 * @brief Send interpan message.
 */
sl_status_t sl_zigbee_af_send_inter_pan(sl_802154_pan_id_t panId,
                                        const sl_802154_long_addr_t destinationLongId,
                                        sl_802154_short_addr_t destinationShortId,
                                        sl_zigbee_multicast_id_t multicastId,
                                        sl_zigbee_af_cluster_id_t clusterId,
                                        sl_zigbee_af_profile_id_t profileId,
                                        uint16_t messageLength,
                                        uint8_t* messageBytes);

/**
 * @brief Send the command prepared with sl_zigbee_af_fill.... macro.
 *
 * This function is used to send a command that was previously prepared
 * using the sl_zigbee_af_fill... macros from the client command API. It
 * will be sent as unicast to each remote node in the binding table that
 * matches the cluster and source endpoint in the APS frame.  Note: if the
 * binding table contains many matching entries, calling this API cause a
 * significant amount of network traffic.
 */
sl_status_t sl_zigbee_af_send_command_unicast_to_bindings(void);

/**
 * @brief sl_zigbee_af_send_command_unicast_to_bindings with attached message sent callback.
 */
sl_status_t sl_zigbee_af_send_command_unicast_to_bindings_with_cb(sl_zigbee_af_message_sent_function_t callback);

/**
 * @brief Send the command prepared with sl_zigbee_af_fill.... macro.
 *
 * This function is used to send a command that was previously prepared
 * using the sl_zigbee_af_fill... macros from the client command API. It
 * will be sent as multicast.
 */
sl_status_t sl_zigbee_af_send_command_multicast(sl_zigbee_multicast_id_t multicastId, sl_802154_short_addr_t alias, uint8_t sequence);

/**
 * @brief sl_zigbee_af_send_command_multicast with attached message sent callback.
 */
sl_status_t sl_zigbee_af_send_command_multicast_with_cb(sl_zigbee_multicast_id_t multicastId, sl_802154_short_addr_t alias, uint8_t sequence,
                                                        sl_zigbee_af_message_sent_function_t callback);

/**
 * @brief Send the command prepared with sl_zigbee_af_fill.... macro.
 *
 * This function is used to send a command that was previously prepared
 * using the sl_zigbee_af_fill... macros from the client command API. It
 * will be sent as multicast to the group specified in the binding table that
 * matches the cluster and source endpoint in the APS frame.  Note: if the
 * binding table contains many matching entries, calling this API cause a
 * significant amount of network traffic.
 */
sl_status_t sl_zigbee_af_send_command_multicast_to_bindings(void);
/**
 * @brief Send the command prepared with sl_zigbee_af_fill.... macro.
 *
 * This function is used to send a command that was previously prepared
 * using the sl_zigbee_af_fill... macros from the client command API.
 * It will be sent as unicast.
 */
sl_status_t sl_zigbee_af_send_command_unicast(sl_zigbee_outgoing_message_type_t type,
                                              uint16_t indexOrDestination);

/**
 * @brief sl_zigbee_af_send_command_unicast with attached message sent callback.
 */
sl_status_t sl_zigbee_af_send_command_unicast_with_cb(sl_zigbee_outgoing_message_type_t type,
                                                      uint16_t indexOrDestination,
                                                      sl_zigbee_af_message_sent_function_t callback);

/**
 * @brief Send the command prepared with sl_zigbee_af_fill.... macro.
 *
 * This function is used to send a command that was previously prepared
 * using the sl_zigbee_af_fill... macros from the client command API.
 */
sl_status_t sl_zigbee_af_send_command_broadcast(sl_802154_short_addr_t destination,
                                                sl_802154_short_addr_t alias,
                                                uint8_t sequence);

/**
 * @brief sl_zigbee_af_send_command_broadcast with attached message sent callback.
 */
sl_status_t sl_zigbee_af_send_command_broadcast_with_cb(sl_802154_short_addr_t destination,
                                                        sl_802154_short_addr_t alias,
                                                        uint8_t sequence,
                                                        sl_zigbee_af_message_sent_function_t callback);

/**
 * @brief Send the command prepared with sl_zigbee_af_fill.... macro.
 *
 * This function is used to send a command that was previously prepared
 * using the sl_zigbee_af_fill... macros from the client command API.
 * It will be sent via inter-PAN.  If destinationLongId is not NULL, the message
 * will be sent to that long address using long addressing mode; otherwise, the
 * message will be sent to destinationShortId using short address mode.  IF
 * multicastId is not zero, the message will be sent using multicast mode.
 */
sl_status_t sl_zigbee_af_send_command_inter_pan(sl_802154_pan_id_t panId,
                                                const sl_802154_long_addr_t destinationLongId,
                                                sl_802154_short_addr_t destinationShortId,
                                                sl_zigbee_multicast_id_t multicastId,
                                                sl_zigbee_af_profile_id_t profileId);

/**
 * @brief Send a default response to a cluster command.
 *
 * This function is used to prepare and send a default response to a cluster
 * command.
 *
 * @param cmd The cluster command to which to respond.
 * @param status Status code for the default response command.
 * @return An ::sl_status_t value that indicates the success or failure of
 * sending the response.
 */
sl_status_t sl_zigbee_af_send_default_response(const sl_zigbee_af_cluster_command_t *cmd,
                                               sl_zigbee_af_status_t status);

/**
 * @brief sl_zigbee_af_send_default_response with attached message sent callback.
 */
sl_status_t sl_zigbee_af_send_default_response_with_cb(const sl_zigbee_af_cluster_command_t *cmd,
                                                       sl_zigbee_af_status_t status,
                                                       sl_zigbee_af_message_sent_function_t callback);

/**
 * @brief Send a default response to a cluster command using the
 * current command.
 *
 * This function is used to prepare and send a default response to a cluster
 * command.
 *
 * @param status Status code for the default response command.
 * @return An ::sl_status_t value that indicates the success or failure of
 * sending the response.
 */
sl_status_t sl_zigbee_af_send_immediate_default_response(sl_zigbee_af_status_t status);

/**
 * @brief sl_zigbee_af_send_immediate_default_response with attached message sent callback.
 */
sl_status_t sl_zigbee_af_send_immediate_default_response_with_cb(sl_zigbee_af_status_t status,
                                                                 sl_zigbee_af_message_sent_function_t callback);

/**
 * @brief Return the maximum size of the payload that the Application
 * Support sub-layer will accept for the given message type, destination, and
 * APS frame.
 *
 * The size depends on multiple factors, including the security level in use
 * and additional information added to the message to support the various
 * options.
 *
 * @param type The outgoing message type.
 * @param indexOrDestination Depending on the message type, this is either the
 *  sl_802154_short_addr_t of the destination, an index into the address table, an index
 *  into the binding table, the multicast identifier, or a broadcast address.
 * @param apsFrame The APS frame for the message.
 * @return The maximum APS payload length for the given message.
 */
uint8_t sl_zigbee_af_maximum_aps_payload_length(sl_zigbee_outgoing_message_type_t type,
                                                uint16_t indexOrDestination,
                                                sl_zigbee_aps_frame_t *apsFrame);

/**
 * @brief Access to client API APS frame.
 */
sl_zigbee_aps_frame_t *sl_zigbee_af_get_command_aps_frame(void);

/**
 * @brief Set the source and destination endpoints in the client API APS frame.
 */
void sl_zigbee_af_set_command_endpoints(uint8_t sourceEndpoint, uint8_t destinationEndpoint);

/**
 * @brief Friendly define for use in discovering client clusters with
 * ::sl_zigbee_af_find_devices_by_profile_and_cluster().
 */
#define SL_ZIGBEE_AF_CLIENT_CLUSTER_DISCOVERY false

/**
 * @brief Friendly define for use in discovering server clusters with
 * ::sl_zigbee_af_find_devices_by_profile_and_cluster().
 */
#define SL_ZIGBEE_AF_SERVER_CLUSTER_DISCOVERY true

/**
 * @brief Find devices in the network with endpoints
 *   matching a given profile ID and cluster ID in their descriptors.
 *   Target may either be a specific device, or the broadcast
 *   address SL_ZIGBEE_RX_ON_WHEN_IDLE_BROADCAST_ADDRESS.
 *
 * This function initiates a service discovery. Received
 * responses are returned by executing the callback function passed in.
 * For unicast discoveries, the callback will be executed only once.
 * Either the target will return a result or a timeout will occur.
 * For broadcast discoveries, the callback may be called multiple times
 * and after a period of time the discovery will be finished with a final
 * call to the callback.
 *
 * @param target The destination node ID for the discovery; either a specific
 *  node's ID or SL_ZIGBEE_RX_ON_WHEN_IDLE_BROADCAST_ADDRESS.
 * @param profileId The application profile for the cluster being discovered.
 * @param clusterId The cluster being discovered.
 * @param serverCluster SL_ZIGBEE_AF_SERVER_CLUSTER_DISCOVERY (true) if discovering
 *  servers for the target cluster; SL_ZIGBEE_AF_CLIENT_CLUSTER_DISCOVERY (false)
 *  if discovering clients for that cluster.
 * @param callback Function pointer for the callback function triggered when
 *  a match is discovered.  (For broadcast discoveries, this is called once per
 *  matching node, even if a node has multiple matching endpoints.)
 */
sl_status_t sl_zigbee_af_find_devices_by_profile_and_cluster(sl_802154_short_addr_t target,
                                                             sl_zigbee_af_profile_id_t profileId,
                                                             sl_zigbee_af_cluster_id_t clusterId,
                                                             bool serverCluster,
                                                             sl_zigbee_af_service_discovery_callback_t *callback);

/**
 * @brief Find all of the given in and out clusters
 *   implemented on a devices given endpoint. Target should only be the
 *   short address of a specific device.
 *
 * This function initiates a single service discovery and the response
 * is passed back to the passed callback.
 *
 * @param target The destination node ID for the discovery. This should be a
 *  specific node's ID and should not be a broadcast address.
 * @param targetEndpoint The endpoint to target with the discovery process.
 * @param callback Function pointer for the callback function triggered when
 *  the discovery is returned.
 */
sl_status_t sl_zigbee_af_find_clusters_by_device_and_endpoint(sl_802154_short_addr_t target,
                                                              uint8_t targetEndpoint,
                                                              sl_zigbee_af_service_discovery_callback_t *callback);

/**
 * @brief Initiate a discovery for the IEEE address
 *   of the specified node ID.  This will send a unicast sent to the target
 *   node ID.
 */
sl_status_t sl_zigbee_af_find_ieee_address(sl_802154_short_addr_t shortAddress,
                                           sl_zigbee_af_service_discovery_callback_t *callback);

/**
 * @brief Initiate a discovery for the short ID of the
 *   specified long address.  This will send a broadcast to all
 *   RX-on-when-idle devices (non-sleepies).
 */
sl_status_t sl_zigbee_af_find_node_id(sl_802154_long_addr_t longAddress,
                                      sl_zigbee_af_service_discovery_callback_t *callback);

/**
 * @brief Initiate an Active Endpoint request ZDO message to the target node ID.
 */
sl_status_t sl_zigbee_af_find_active_endpoints(sl_802154_short_addr_t target,
                                               sl_zigbee_af_service_discovery_callback_t *callback);

/**
 * @brief Add an entry for a remote device to the address
 * table.
 *
 * If the EUI64 already exists in the address table, the index of the existing
 * entry will be returned.  Otherwise, a new entry will be created and the new
 * new index will be returned.  The framework will remember how many times the
 * returned index has been referenced.  When the address table entry is no
 * longer needed, the application should remove its reference by calling
 * ::sl_zigbee_af_remove_address_table_entry.
 *
 * @param longId The EUI64 of the remote device.
 * @param shortId The node ID of the remote device or ::SL_ZIGBEE_UNKNOWN_NODE_ID
 * if the node ID is currently unknown.
 * @return The index of the address table entry for this remove device or
 * ::SL_ZIGBEE_NULL_ADDRESS_TABLE_INDEX if an error occurred (e.g., the address
 * table is full).
 */
uint8_t sl_zigbee_af_add_address_table_entry(sl_802154_long_addr_t longId, sl_802154_short_addr_t shortId);

/**
 * @brief Add an entry for a remote device to the address
 * table at a specific location.
 *
 * The framework will remember how many times an address table index has been
 * referenced through ::sl_zigbee_af_add_address_table_entry.  If the reference count
 * for the index passed to this function is not zero, the entry will be not
 * changed.   When the address table entry is no longer needed, the application
 * should remove its reference by calling ::sl_zigbee_af_remove_address_table_entry.
 *
 * @param index The index of the address table entry.
 * @param longId The EUI64 of the remote device.
 * @param shortId The node id of the remote device or ::SL_ZIGBEE_UNKNOWN_NODE_ID
 * if the node id is currently unknown.
 * @return ::SL_STATUS_OK if the address table entry was successfully set,
 * ::SL_STATUS_ZIGBEE_ADDRESS_TABLE_ENTRY_IS_ACTIVE if any messages are being sent using
 * the existing entry at that index or the entry is still referenced in the
 * framework, or ::SL_STATUS_INVALID_RANGE if the index is out
 * of range.
 */
sl_status_t sl_zigbee_af_set_address_table_entry(uint8_t index,
                                                 sl_802154_long_addr_t longId,
                                                 sl_802154_short_addr_t shortId);

/**
 * @brief Remove a specific entry from the address table.
 *
 * The framework will remember how many times an address table index has been
 * referenced through ::sl_zigbee_af_add_address_table_entry and
 * ::sl_zigbee_af_set_address_table_entry.  The address table entry at this index will
 * not actually be removed until its reference count reaches zero.
 *
 * @param index The index of the address table entry.
 * @return ::SL_STATUS_OK if the address table entry was successfully removed
 * or ::SL_STATUS_INVALID_RANGE if the index is out of range.
 */
sl_status_t sl_zigbee_af_remove_address_table_entry(uint8_t index);

#if !defined(DOXYGEN_SHOULD_SKIP_THIS)
/**
 * @brief Retrieve the current command. This
 * macro may only be used within the command parsing context. For instance,
 * any of the command handling callbacks may use this macro. If this macro
 * is used outside the command context, the returned sl_zigbee_af_cluster_command_t pointer
 * will be null.
 */
#define sl_zigbee_af_current_command() (sli_zigbee_af_current_command)
extern sl_zigbee_af_cluster_command_t *sli_zigbee_af_current_command;
#endif

/**
 * @brief Return the current endpoint that is being served.
 *
 * The purpose of this macro is mostly to access endpoint that
 * is being served in the command callbacks.
 */
#define sl_zigbee_af_current_endpoint() (sl_zigbee_af_current_command()->apsFrame->destinationEndpoint)

#ifdef DOXYGEN_SHOULD_SKIP_THIS
/** @brief Initiate key establishment with a remote node.
 * ::sl_zigbee_af_key_establishment_cb will be called as events occur and when
 * key establishment completes.
 *
 * @param nodeId The node ID of the remote device.
 * @param endpoint The endpoint on the remote device.
 * @return ::SL_STATUS_OK if key establishment was initiated successfully
 */
sl_status_t sl_zigbee_af_initiate_key_establishment(sl_802154_short_addr_t nodeId, uint8_t endpoint);

/** @brief Initiate key establishment with a remote node on
 * a different PAN.  ::sl_zigbee_af_inter_pan_key_establishment_cb will be called
 * as events occur and when key establishment completes.
 *
 * @param panId The PAN ID of the remote device.
 * @param eui64 The EUI64 of the remote device.
 * @return ::SL_STATUS_OK if key establishment was initiated successfully
 */
sl_status_t sl_zigbee_af_initiate_inter_pan_key_establishment(sl_802154_pan_id_t panId,
                                                              const sl_802154_long_addr_t eui64);

/** @brief Indicate whether the device is in the process of
 * performing key establishment.
 *
 * @return ::true if key establishment is in progress.
 */
bool sl_zigbee_af_performing_key_establishment(void);

/** @brief Initiate partner link key exchange with a
 * remote node.
 *
 * @param target The node ID of the remote device.
 * @param endpoint The key establishment endpoint of the remote device.
 * @param callback The callback that should be called when the partner link
 * key exchange completes.
 * @return ::SL_STATUS_OK if the partner link key exchange was initiated
 * successfully.
 */
sl_status_t sl_zigbee_af_initiate_partner_link_key_exchange(sl_802154_short_addr_t target,
                                                            uint8_t endpoint,
                                                            sl_zigbee_af_partner_link_key_exchange_callback_t *callback);
#else
  #define sl_zigbee_af_initiate_key_establishment(nodeId, endpoint) \
  sl_zigbee_af_initiate_key_establishment_cb(nodeId, endpoint)
  #define sl_zigbee_af_initiate_inter_pan_key_establishment(panId, eui64) \
  sl_zigbee_af_initiate_inter_pan_key_establishment_cb(panId, eui64)
  #define sl_zigbee_af_performing_key_establishment() \
  sl_zigbee_af_performing_key_establishment_cb()
  #define sl_zigbee_af_initiate_partner_link_key_exchange(target, endpoint, callback) \
  sl_zigbee_af_initiate_partner_link_key_exchange_cb(target, endpoint, callback)
#endif

/** @brief Use this function to determine if the security profile of the
 * current network was set to Smart Energy.  The security profile is configured
 * in AppBuilder.
   @ return true if the security profile is Smart Energy or false otherwise.
 */
bool sl_zigbee_af_is_current_security_profile_smart_energy(void);

/** @} */ // end of name API
/** @} */ // end of messaging

/**
 * @defgroup zcl_commands ZCL Commands
 * @ingroup af
 * @brief API for runtime subscription to ZCL commands
 *
 */

/**
 * @addtogroup zcl_commands
 *
 * Following a brief usage example that demonstrate how to subscribe to the ZCL
 * "Level Control" cluster commands, client side, with no manufacturer ID.
 * In this example we only handle only "Stop" command.
 * The subscribed callback must return a value of:
 * - ::SL_ZIGBEE_ZCL_STATUS_SUCCESS if the received ZCL command was handled.
 * - ::SL_ZIGBEE_ZCL_STATUS_UNSUP_COMMAND if the received ZCL command was not
 * handled.
 *
 * @code
 * void my_zcl_command_handler(sl_service_opcode_t opcode,
 *                             sl_service_function_context_t *context)
 * {
 *   assert(opcode == SL_SERVICE_FUNCTION_TYPE_ZCL_COMMAND);
 *
 *   sl_zigbee_af_cluster_command_t *cmd = (sl_zigbee_af_cluster_command_t *)context->data;
 *
 *   switch (cmd->commandId) {
 *     case ZCL_STOP_COMMAND_ID:
 *     {
 *       // ZCL command structs and parsing functions are implemented in the
 *       // generated zap-cluster-command-parser.[c,h] files.
 *       sl_zcl_level_control_cluster_stop_command_t cmd_data;
 *
 *       if (zcl_decode_level_control_cluster_stop_command(cmd, &cmd_data)
 *           != SL_ZIGBEE_ZCL_STATUS_SUCCESS) {
 *         return SL_ZIGBEE_ZCL_STATUS_UNSUP_COMMAND;
 *       }
 *
 *       // Handle the command here
 *
 *       // Send a default response back to the client
 *       sl_zigbee_af_send_default_response(SL_ZIGBEE_ZCL_STATUS_SUCCESS);
 *
 *       return SL_ZIGBEE_ZCL_STATUS_SUCCESS;
 *     }
 *   }
 *
 *   return SL_ZIGBEE_ZCL_STATUS_UNSUP_COMMAND;
 * }
 *
 * void app_init(void)
 * {
 *   sl_zigbee_subscribe_to_zcl_commands(ZCL_LEVEL_CONTROL_CLUSTER_ID,
 *                                       0xFFFF, // not manufacturer specific
 *                                       ZCL_DIRECTION_SERVER_TO_CLIENT,
 *                                       my_zcl_command_handler);
 * }
 * @endcode
 *
 * @{
 */

/** @name API */
// @{

/** @brief Runtime subscription to specific incoming ZCL commands.
 *
 * @param cluster_id    The cluster ID of the ZCL messages to subscribe to.
 *
 * @param manufacturer_id   The manufacturer ID if any. If not set, a value of
 *                          0xFFFF should be passed in.
 *
 * @param direction  A value of ::ZCL_DIRECTION_CLIENT_TO_SERVER or
 *                   ::ZCL_DIRECTION_SERVER_TO_CLIENT specifying the side
 *                   (client or server) of the ZCL messages to subscribe to.
 *
 * @param service_function   A ::sl_service_function_t function pointer
 *                           specifying the function to be invoked when an
 *                           incoming ZCL command matches the criteria specified
 *                           in this API.
 *
 * @return A ::sl_status_t value of:
 * - ::SL_STATUS_OK - If the subscription was successful.
 * - ::SL_STATUS_INVALID_PARAMETER - If one or more passed parameters are
 *   invalid.
 * - ::SL_STATUS_ALLOCATION_FAILED - If the system failed to allocate the
 *   necessary data structures.
 */
sl_status_t sl_zigbee_subscribe_to_zcl_commands(uint16_t cluster_id,
                                                uint16_t manufacturer_id,
                                                uint8_t direction,
                                                sl_service_function_t service_function);

/** @} */ // end of name API
/** @} */ // end of zcl_commands

/**
 * @defgroup zcl-macros ZCL Macros
 * @ingroup af
 * @brief ZCL Macros in the Application Framework
 *
 * ZCL Macro description.
 *
 */

/**
 * @addtogroup zcl-macros
 * @{
 */

// Frame control fields (8 bits total)
// Bits 0 and 1 are Frame Type Sub-field
#define ZCL_FRAME_CONTROL_FRAME_TYPE_MASK     (BIT(0) | BIT(1))
#define ZCL_CLUSTER_SPECIFIC_COMMAND          BIT(0)
#define ZCL_PROFILE_WIDE_COMMAND              0u
#define ZCL_GLOBAL_COMMAND                    (ZCL_PROFILE_WIDE_COMMAND)
// Bit 2 is Manufacturer Specific Sub-field
#define ZCL_MANUFACTURER_SPECIFIC_MASK        BIT(2)
// Bit 3 is Direction Sub-field
#define ZCL_FRAME_CONTROL_DIRECTION_MASK      BIT(3)
#define ZCL_FRAME_CONTROL_SERVER_TO_CLIENT    BIT(3)
#define ZCL_FRAME_CONTROL_CLIENT_TO_SERVER    0u
// Bit 4 is Disable Default Response Sub-field
#define ZCL_DISABLE_DEFAULT_RESPONSE_MASK     BIT(4)
// Bits 5 to 7 are reserved

#define ZCL_DIRECTION_CLIENT_TO_SERVER 0u
#define ZCL_DIRECTION_SERVER_TO_CLIENT 1u

// Packet must be at least 3 bytes for ZCL overhead.
//   Frame Control (1-byte)
//   Sequence Number (1-byte)
//   Command Id (1-byte)
#define SL_ZIGBEE_AF_ZCL_OVERHEAD                       3
#define SL_ZIGBEE_AF_ZCL_MANUFACTURER_SPECIFIC_OVERHEAD 5

// Permitted values for sl_zigbee_af_set_form_and_join_mode
#define FIND_AND_JOIN_MODE_ALLOW_2_4_GHZ        BIT(0)
#define FIND_AND_JOIN_MODE_ALLOW_SUB_GHZ        BIT(1)
#define FIND_AND_JOIN_MODE_ALLOW_BOTH           (FIND_AND_JOIN_MODE_ALLOW_2_4_GHZ | FIND_AND_JOIN_MODE_ALLOW_SUB_GHZ)

/** @} */ // end of zcl-macros

/**
 * @defgroup network-utility-functions Network Utility Functions
 * @ingroup af
 * @brief API and Callbacks for the Network Utility functionality
 * in the Application Framework
 *
 * Network Utility Functions description.
 *
 */

/**
 * @addtogroup network-utility-functions
 * @{
 */

/** @name API */
// @{

/** @brief Form a new network using the specified network
 * parameters.
 *
 * @param parameters Specification of the new network.
 * @return An ::sl_status_t value that indicates either the successful formation
 * of the new network or the reason that the network formation failed.
 */
sl_status_t sl_zigbee_af_form_network(sl_zigbee_network_parameters_t *parameters);

/** @brief Associate with the network using the specified
 * network parameters.
 *
 * @param parameters Specification of the network with which the node should
 * associate.
 * @return An ::sl_status_t value that indicates either that the association
 * process began successfully or the reason for failure.
 */
sl_status_t sl_zigbee_af_join_network(sl_zigbee_network_parameters_t *parameters);

#ifdef DOXYGEN_SHOULD_SKIP_THIS
/** @brief Find an unused PAN ID and form a new network.
 *
 * @return An ::sl_status_t value that indicates either the process begin
 * successfully or the reason for failure.
 */
sl_status_t sl_zigbee_af_find_unused_pan_id_and_form(void);
/** @brief Find a joinable network and join it.
 *
 * @return An ::sl_status_t value that indicates either the process begin
 * successfully or the reason for failure.
 */
sl_status_t sl_zigbee_af_start_search_for_joinable_network(void);
#else
  #define sl_zigbee_af_find_unused_pan_id_and_form()        sl_zigbee_af_find_unused_pan_id_and_form_cb()
  #define sl_zigbee_af_start_search_for_joinable_network() sl_zigbee_af_start_search_for_joinable_network_cb()
#endif

/** @brief Set the current network to that of the given index and add it to
 * the stack of networks maintained by the framework.  Every call to this API
 * must be paired with a subsequent call to ::sl_zigbee_af_pop_network_index.
 */

sl_status_t sl_zigbee_af_push_network_index(uint8_t networkIndex);
/** @brief Set the current network to the callback network and adds it to
 * the stack of networks maintained by the framework.  Every call to this API
 * must be paired with a subsequent call to ::sl_zigbee_af_pop_network_index.
 */

sl_status_t sl_zigbee_af_push_callback_network_index(void);
/** @brief Set the current network to that of the given endpoint and adds it
 * to the stack of networks maintained by the framework.  Every call to this
 * API must be paired with a subsequent call to ::sl_zigbee_af_pop_network_index.
 */

sl_status_t sl_zigbee_af_push_endpoint_network_index(uint8_t endpoint);
/** @brief Remove the topmost network from the stack of networks maintained by
 * the framework and sets the current network to the new topmost network.
 * Every call to this API must be paired with a prior call to
 * ::sl_zigbee_af_push_network_index, ::sl_zigbee_af_push_callback_network_index, or
 * ::sl_zigbee_af_push_endpoint_network_index.
 */

sl_status_t sl_zigbee_af_pop_network_index(void);
/** @brief Return the primary endpoint of the given network index or 0xFF if
 * no endpoints belong to the network.sl_zigbee_af_status
 */

uint8_t sl_zigbee_af_primary_endpoint_for_network_index(uint8_t networkIndex);
/** @brief Return the primary endpoint of the current network index or 0xFF if
 * no endpoints belong to the current network.
 */

uint8_t sl_zigbee_af_primary_endpoint_for_current_network_index(void);

#if !defined(DOXYGEN_SHOULD_SKIP_THIS)
/** @brief Initialize the stack of networks maintained by the framework,
 * including setting the default network.
 *
 * @return An ::sl_status_t value that indicates either that the network stack
 * has been successfully initialized or the reason for failure.
 */
sl_status_t sli_zigbee_af_initialize_network_index_stack(void);
void sli_zigbee_af_assert_network_index_stack_is_empty(void);
#endif

/** @} */ // end of API
/** @} */ // end of network-utility-functions

#if !defined(DOXYGEN_SHOULD_SKIP_THIS)
  #if defined(SL_ZIGBEE_TEST)
    #define SL_ZIGBEE_TEST_ASSERT(x) assert(x)
  #else
    #define SL_ZIGBEE_TEST_ASSERT(x)
  #endif
#endif

/** @brief The maximum power level that can be used by the chip.
 */
// Note:  This is a #define for now but could be a real function call in the future.
#define sl_zigbee_af_max_power_level() (3)

#if !defined(DOXYGEN_SHOULD_SKIP_THIS)
// This macro used to be generated by AppBuilder, defining it disables legacy CLI commands.
// Legacy CLI is no longer supported and will eventually be cleaned up (see EMZIGBEE-868),
// until then define this statically.
#define SL_ZIGBEE_AF_GENERATE_CLI
#endif // !DOXYGEN_SHOULD_SKIP_THIS

#ifdef __cplusplus
}
#endif

#endif // SILABS_AF_API
