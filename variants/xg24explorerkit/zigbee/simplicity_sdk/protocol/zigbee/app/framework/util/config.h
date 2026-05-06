/***************************************************************************//**
 * @brief This file is the main configuration settings for the Zigbee app.
 * The zigbee app can become a Home Automation (HA) device, a Smart
 * Energy (SE) device, or a Custom Zigbee device.
 *
 * This application can be configured using AppBuilder. AppBuilder
 * generates a file containing defines that setup what pieces of the
 * code is used (which clusters, security settings, zigbee device type,
 * serial port, etc). These defines are added to a new file and included
 * by setting ZA_GENERATED_HEADER to the new filename so these defines are
 * sourced first.
 *
 * This file also contains default values for the defines so some can
 * be set by the user but defaults are always available.
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories, Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc.  Your use of this
 * software is governed by the terms of  Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement.  This
 * software  is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef __EMBER_AF_CONFIG_H__
#define __EMBER_AF_CONFIG_H__

// include generated configuration information from AppBuilder.
// ZA_GENERATED_HEADER is defined in the project file
#ifdef ZA_GENERATED_HEADER
  #include ZA_GENERATED_HEADER
#endif

#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif

#ifdef SL_CATALOG_ZIGBEE_ZCL_FRAMEWORK_CORE_PRESENT
#include "zap-config.h"
#endif

#ifdef SL_CATALOG_ZIGBEE_DEVICE_CONFIG_PRESENT
#include "zigbee_device_config.h"
#endif
#ifdef  SL_CATALOG_ZIGBEE_FRAGMENTATION_PRESENT
#include "fragmentation-config.h"
#endif

#if (SLI_ZIGBEE_DEFAULT_NETWORK == SLI_ZIGBEE_DEFAULT_NETWORK_PRIMARY)
#define SL_ZIGBEE_AF_DEFAULT_NETWORK_INDEX 0
#else
#define SL_ZIGBEE_AF_DEFAULT_NETWORK_INDEX 1
#endif

#if (SLI_ZIGBEE_SECONDARY_NETWORK_ENABLED == 0)
#define SL_ZIGBEE_AF_GENERATED_NETWORK_STRINGS \
  "Primary (pro)",
#else
#define SL_ZIGBEE_AF_GENERATED_NETWORK_STRINGS \
  "Primary (pro)",                             \
  "Secondary (pro)",
#endif

#if ((SLI_ZIGBEE_PRIMARY_NETWORK_DEVICE_TYPE == SLI_ZIGBEE_NETWORK_DEVICE_TYPE_COORDINATOR_OR_ROUTER) \
  || (SLI_ZIGBEE_SECONDARY_NETWORK_ENABLED == 1                                                       \
      && SLI_ZIGBEE_SECONDARY_NETWORK_DEVICE_TYPE == SLI_ZIGBEE_NETWORK_DEVICE_TYPE_COORDINATOR_OR_ROUTER))
#define SL_ZIGBEE_AF_HAS_COORDINATOR_NETWORK
#endif

#if (!defined(SL_ZIGBEE_ZC_AND_ZR_DEVICE_COUNT) || SL_ZIGBEE_ZC_AND_ZR_DEVICE_COUNT == 0)
#define SL_ZIGBEE_AF_HAS_ROUTER_NETWORK
#endif

#if (SLI_ZIGBEE_PRIMARY_NETWORK_DEVICE_TYPE == SLI_ZIGBEE_NETWORK_DEVICE_TYPE_END_DEVICE           \
     || SLI_ZIGBEE_PRIMARY_NETWORK_DEVICE_TYPE == SLI_ZIGBEE_NETWORK_DEVICE_TYPE_SLEEPY_END_DEVICE \
     || (SLI_ZIGBEE_SECONDARY_NETWORK_ENABLED == 1                                                 \
         && (SLI_ZIGBEE_SECONDARY_NETWORK_DEVICE_TYPE == SLI_ZIGBEE_NETWORK_DEVICE_TYPE_END_DEVICE \
             || SLI_ZIGBEE_SECONDARY_NETWORK_DEVICE_TYPE == SLI_ZIGBEE_NETWORK_DEVICE_TYPE_SLEEPY_END_DEVICE)))
#define SL_ZIGBEE_AF_HAS_END_DEVICE_NETWORK
#endif

#if (SLI_ZIGBEE_PRIMARY_NETWORK_DEVICE_TYPE == SLI_ZIGBEE_NETWORK_DEVICE_TYPE_SLEEPY_END_DEVICE \
     || (SLI_ZIGBEE_SECONDARY_NETWORK_ENABLED == 1                                              \
         && SLI_ZIGBEE_SECONDARY_NETWORK_DEVICE_TYPE == SLI_ZIGBEE_NETWORK_DEVICE_TYPE_SLEEPY_END_DEVICE))
#define SL_ZIGBEE_AF_HAS_SLEEPY_NETWORK
#endif

#define SL_ZIGBEE_AF_TX_POWER_MODE SLI_ZIGBEE_TX_POWER_MODE

// Additional security profile macros referenced in zcl-core and other plugins
#if defined(SLI_ZIGBEE_PRIMARY_NETWORK_SECURITY_TYPE)
  #if (SLI_ZIGBEE_PRIMARY_NETWORK_SECURITY_TYPE == SLI_ZIGBEE_NETWORK_SECURITY_TYPE_NO_SECURITY)
  #define SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_NONE
  #endif
  #if (SLI_ZIGBEE_PRIMARY_NETWORK_SECURITY_TYPE == SLI_ZIGBEE_NETWORK_SECURITY_TYPE_HA) \
  || (SLI_ZIGBEE_SECONDARY_NETWORK_ENABLED == 1                                         \
      && SLI_ZIGBEE_SECONDARY_NETWORK_SECURITY_TYPE == SLI_ZIGBEE_NETWORK_SECURITY_TYPE_HA)
  #define SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_HA
  #endif
  #if (SLI_ZIGBEE_PRIMARY_NETWORK_SECURITY_TYPE == SLI_ZIGBEE_NETWORK_SECURITY_TYPE_HA_1_2) \
  || (SLI_ZIGBEE_SECONDARY_NETWORK_ENABLED == 1                                             \
      && SLI_ZIGBEE_SECONDARY_NETWORK_SECURITY_TYPE == SLI_ZIGBEE_NETWORK_SECURITY_TYPE_HA_1_2)
  #define SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_HA12
  #endif
  #if (SLI_ZIGBEE_PRIMARY_NETWORK_SECURITY_TYPE == SLI_ZIGBEE_NETWORK_SECURITY_TYPE_SE_FULL) \
  || (SLI_ZIGBEE_SECONDARY_NETWORK_ENABLED == 1                                              \
      && SLI_ZIGBEE_SECONDARY_NETWORK_SECURITY_TYPE == SLI_ZIGBEE_NETWORK_SECURITY_TYPE_SE_FULL)
  #define SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_SE_FULL
  #endif
  #if (SLI_ZIGBEE_PRIMARY_NETWORK_SECURITY_TYPE == SLI_ZIGBEE_NETWORK_SECURITY_TYPE_SE_TEST) \
  || (SLI_ZIGBEE_SECONDARY_NETWORK_ENABLED == 1                                              \
      && SLI_ZIGBEE_SECONDARY_NETWORK_SECURITY_TYPE == SLI_ZIGBEE_NETWORK_SECURITY_TYPE_SE_TEST)
  #ifndef SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_SE_TEST
  #define SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_SE_TEST
  #endif
  #endif
  #if (SLI_ZIGBEE_PRIMARY_NETWORK_SECURITY_TYPE == SLI_ZIGBEE_NETWORK_SECURITY_TYPE_CUSTOM)
  #define SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_CUSTOM
  #endif
  #if (SLI_ZIGBEE_PRIMARY_NETWORK_SECURITY_TYPE == SLI_ZIGBEE_NETWORK_SECURITY_TYPE_3_0) \
  || (SLI_ZIGBEE_SECONDARY_NETWORK_ENABLED == 1                                          \
      && SLI_ZIGBEE_SECONDARY_NETWORK_SECURITY_TYPE == SLI_ZIGBEE_NETWORK_SECURITY_TYPE_3_0)
  #define SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_Z3
  #endif
#endif // defined(SLI_ZIGBEE_PRIMARY_NETWORK_SECURITY_TYPE)

// *******************************************************************
// pre-defined Devices
//
// use these to determine which type of device the current application is.
// do not use the EMBER_* versions from sl_zigbee_types.h as these are in an
// enum and are not available at preprocessor time. These need to be set
// before the devices are loaded from ha-devices.h and se-devices.h

#define CBA_PROFILE_ID (0x0105)
#define HA_PROFILE_ID (0x0104)
#define SE_PROFILE_ID (0x0109)

// A subtle distinction:
//   SL_ZIGBEE_ZCL_MANUFACTURER_CODE is the MFG code set by AppBuilder
//     for use in the App Framework (AF).  If not set by AppBuilder we default
//     it to 0x0000. The customer should be setting this value.
//   SL_ZIGBEE_COMPANY_MANUFACTURER_CODE is the Ember Corporation's Manufacturer
//     ID allocated by the Zigbee alliance.  This shall not change.
#define SL_ZIGBEE_COMPANY_MANUFACTURER_CODE 0x1002

// This is now generated in zap-type.h

// This file determines the security profile used, and from that various
// other security parameters.
#include "app/framework/security/security-config.h"

// *******************************************************************
// Application configuration of RAM for cluster usage
//
// This section defines constants that size the tables used by the cluster
// code.

// This is the max hops that the network can support - used to determine
// the max source route overhead and broadcast radius
// if we havent defined MAX_HOPS then define based on profile ID
#ifndef ZA_MAX_HOPS
  #ifdef SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_SE
    #define ZA_MAX_HOPS 6
  #else
    #define ZA_MAX_HOPS 12
  #endif
#endif

#ifndef SL_ZIGBEE_AF_SOURCE_ROUTING_RESERVED_PAYLOAD_LENGTH
#define SL_ZIGBEE_AF_SOURCE_ROUTING_RESERVED_PAYLOAD_LENGTH 0
#endif

// The maximum APS payload, not including any APS options.  This value is also
// available from sl_zigbee_maximum_aps_payload_length() or sl_zigbee_ezsp_maximum_payload_length().
// See http://portal.ember.com/faq/payload for more information.
#if ((defined(SL_ZIGBEE_AF_NCP) && defined(SL_CATALOG_ZIGBEE_AF_SUPPORT_PRESENT)) \
  || !defined(SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_NONE))
  #define SL_ZIGBEE_AF_MAXIMUM_APS_PAYLOAD_LENGTH \
  (82 - SL_ZIGBEE_AF_SOURCE_ROUTING_RESERVED_PAYLOAD_LENGTH)
#else
  #define SL_ZIGBEE_AF_MAXIMUM_APS_PAYLOAD_LENGTH \
  (100 - SL_ZIGBEE_AF_SOURCE_ROUTING_RESERVED_PAYLOAD_LENGTH)
#endif

// Max PHY size = 128
//   -1 byte for PHY length
//   -2 bytes for MAC CRC
#define SL_ZIGBEE_AF_MAXIMUM_INTERPAN_LENGTH 125

// The additional overhead required for APS encryption (security = 5, MIC = 4).
#define SL_ZIGBEE_AF_APS_ENCRYPTION_OVERHEAD 9

// The additional overhead required for APS fragmentation.
#define SL_ZIGBEE_AF_APS_FRAGMENTATION_OVERHEAD 2

// The additional overhead required for network source routing (relay count = 1,
// relay index = 1).  This does not include the size of the relay list itself.
#define SL_ZIGBEE_AF_NWK_SOURCE_ROUTE_OVERHEAD 2

// The additional overhead required per relay address for network source
// routing.  This is in addition to the overhead defined above.
#define SL_ZIGBEE_AF_NWK_SOURCE_ROUTE_PER_RELAY_ADDRESS_OVERHEAD 2

// defines the largest size payload allowed to send and receive. This
// affects the payloads generated from the CLI and the payloads generated
// as responses.
// Maximum payload length.
// If fragmenation is enabled, and fragmentation length is bigger than default, then use that
#if (defined(SL_ZIGBEE_AF_PLUGIN_FRAGMENTATION) || defined(SL_CATALOG_ZIGBEE_FRAGMENTATION_PRESENT)) \
  && (SL_ZIGBEE_AF_PLUGIN_FRAGMENTATION_BUFFER_SIZE > SL_ZIGBEE_AF_MAXIMUM_APS_PAYLOAD_LENGTH)
  #define SL_ZIGBEE_AF_MAXIMUM_SEND_PAYLOAD_LENGTH SL_ZIGBEE_AF_PLUGIN_FRAGMENTATION_BUFFER_SIZE
  #define SL_ZIGBEE_AF_INCOMING_BUFFER_LENGTH      SL_ZIGBEE_AF_PLUGIN_FRAGMENTATION_BUFFER_SIZE
#else
  #define SL_ZIGBEE_AF_MAXIMUM_SEND_PAYLOAD_LENGTH SL_ZIGBEE_AF_MAXIMUM_APS_PAYLOAD_LENGTH
  #define SL_ZIGBEE_AF_INCOMING_BUFFER_LENGTH      SL_ZIGBEE_AF_MAXIMUM_APS_PAYLOAD_LENGTH
#endif

// *******************************************************************
// Application configuration of Flash
//
// This section gives the application options for turning on or off
// features that affect the amount of flash used.

// *******************************************************************
// Defines needed for enabling security
//

// Unless we are not using security, our stack profile is 2 (ZigBee Pro).  The
// stack will set up other configuration values based on profile.
#ifndef SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_NONE
  #ifndef SL_ZIGBEE_STACK_PROFILE
    #define SL_ZIGBEE_STACK_PROFILE 2
  #endif // SL_ZIGBEE_STACK_PROFILE
#else
  #ifndef SL_ZIGBEE_STACK_PROFILE
    #define SL_ZIGBEE_STACK_PROFILE 0
  #endif
  #ifndef SL_ZIGBEE_SECURITY_LEVEL
    #define SL_ZIGBEE_SECURITY_LEVEL 0
  #endif
#endif

// *******************************************************************
// Application Handlers
//
// By default, a number of stub handlers are automatically provided
// that have no effect.  If the application would like to implement any
// of these handlers itself, it needs to define the appropriate macro

#define SL_ZIGBEE_APPLICATION_HAS_REMOTE_BINDING_HANDLER
#define SL_ZIGBEE_APPLICATION_HAS_ENERGY_SCAN_RESULT_HANDLER
#define SL_ZIGBEE_APPLICATION_HAS_GET_ENDPOINT
#define SL_ZIGBEE_APPLICATION_HAS_TRUST_CENTER_JOIN_HANDLER
#define SL_ZIGBEE_APPLICATION_HAS_BUTTON_HANDLER
#define SL_ZIGBEE_APPLICATION_HAS_ZIGBEE_KEY_ESTABLISHMENT_HANDLER
#define SL_ZIGBEE_APPLICATION_HAS_BUFFER_MARKER

#define EZSP_APPLICATION_HAS_ENERGY_SCAN_RESULT_HANDLER
#define EZSP_APPLICATION_HAS_INCOMING_SENDER_EUI64_HANDLER
#define EZSP_APPLICATION_HAS_TRUST_CENTER_JOIN_HANDLER
#define EZSP_APPLICATION_HAS_BUTTON_HANDLER
#define EZSP_APPLICATION_HAS_ZIGBEE_KEY_ESTABLISHMENT_HANDLER

#ifndef SL_ZIGBEE_AF_MESSAGE_SENT_CALLBACK_TABLE_SIZE
  #define SL_ZIGBEE_AF_MESSAGE_SENT_CALLBACK_TABLE_SIZE SL_ZIGBEE_APS_UNICAST_MESSAGE_COUNT
#endif // SL_ZIGBEE_AF_MESSAGE_SENT_CALLBACK_TABLE_SIZE

#define SL_ZIGBEE_APPLICATION_HAS_COMMAND_ACTION_HANDLER

// *******************************************************************
// Default values for required defines
//

// define the serial port that the application uses to be 1 if this is not set
#ifndef HAL_CONFIG //HAL Config handles serial port allocation
#ifndef APP_SERIAL
  #define APP_SERIAL 1
#endif
  #ifdef SL_ZIGBEE_TEST
    #include "app/util/ezsp/uart-simulation-remap.h"
  #endif
#endif

#if defined(SL_CATALOG_ZIGBEE_ADDRESS_TABLE_PRESENT)
#include "address-table-config.h"
#else // !SL_CATALOG_ZIGBEE_ADDRESS_TABLE_PRESENT
// if address table component is disabled, we still need to define these
// #defines to some default value.
  #ifdef ZIGBEE_STACK_ON_HOST
  #define SL_ZIGBEE_AF_PLUGIN_ADDRESS_TABLE_SIZE 64
  #define SL_ZIGBEE_AF_PLUGIN_ADDRESS_TABLE_TRUST_CENTER_CACHE_SIZE 64
  #else
  #define SL_ZIGBEE_AF_PLUGIN_ADDRESS_TABLE_SIZE 2
  #define SL_ZIGBEE_AF_PLUGIN_ADDRESS_TABLE_TRUST_CENTER_CACHE_SIZE 2
  #endif
#endif // SL_CATALOG_ZIGBEE_ADDRESS_TABLE_PRESENT
#ifndef SL_ZIGBEE_ADDRESS_TABLE_SIZE
  #define SL_ZIGBEE_ADDRESS_TABLE_SIZE    \
  (SL_ZIGBEE_AF_PLUGIN_ADDRESS_TABLE_SIZE \
   + SL_ZIGBEE_AF_PLUGIN_ADDRESS_TABLE_TRUST_CENTER_CACHE_SIZE)
#endif //SL_ZIGBEE_ADDRESS_TABLE_SIZE

#ifndef SL_ZIGBEE_AF_DEFAULT_APS_OPTIONS
// BUGZID 12261: Concentrators use MTORRs for route discovery and should not
// enable route discovery in the APS options.
#if (defined(SL_ZIGBEE_AF_PLUGIN_CONCENTRATOR) || defined (SL_CATALOG_ZIGBEE_CONCENTRATOR_PRESENT))
    #define SL_ZIGBEE_AF_DEFAULT_APS_OPTIONS \
  (SL_ZIGBEE_APS_OPTION_RETRY                \
   | SL_ZIGBEE_APS_OPTION_ENABLE_ADDRESS_DISCOVERY)
  #else
    #define SL_ZIGBEE_AF_DEFAULT_APS_OPTIONS     \
  (SL_ZIGBEE_APS_OPTION_RETRY                    \
   | SL_ZIGBEE_APS_OPTION_ENABLE_ROUTE_DISCOVERY \
   | SL_ZIGBEE_APS_OPTION_ENABLE_ADDRESS_DISCOVERY)
  #endif
#endif

// *******************************************************************
// // Default values for required defines
// //

#ifdef SL_ZIGBEE_AF_DEFAULT_RESPONSE_POLICY_NEVER
  #define SL_ZIGBEE_AF_DEFAULT_RESPONSE_POLICY_REQUESTS ZCL_DISABLE_DEFAULT_RESPONSE_MASK
  #define SL_ZIGBEE_AF_DEFAULT_RESPONSE_POLICY_RESPONSES ZCL_DISABLE_DEFAULT_RESPONSE_MASK
#elif defined(SL_ZIGBEE_AF_DEFAULT_RESPONSE_POLICY_CONDITIONAL)
  #define SL_ZIGBEE_AF_DEFAULT_RESPONSE_POLICY_REQUESTS 0
  #define SL_ZIGBEE_AF_DEFAULT_RESPONSE_POLICY_RESPONSES ZCL_DISABLE_DEFAULT_RESPONSE_MASK
#else
  #define SL_ZIGBEE_AF_DEFAULT_RESPONSE_POLICY_REQUESTS 0
  #define SL_ZIGBEE_AF_DEFAULT_RESPONSE_POLICY_RESPONSES 0
#endif // SL_ZIGBEE_AF_DEFAULT_RESPONSE_POLICY_NEVER

#ifdef SL_ZIGBEE_AF_CUSTOM_NETWORK_INIT_OPTIONS
  #ifdef SL_ZIGBEE_AF_USE_STANDARD_NETWORK_INIT
    #error "Custom options cannot be used with the standard network init"
  #endif
#else
  #ifdef SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_Z3 // Z3 Compliant end devices must send a rejoin request on reboot
    #define Z3_NETWORK_INIT_BEHAVIOR SL_ZIGBEE_NETWORK_INIT_END_DEVICE_REJOIN_ON_REBOOT
  #else // SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_Z3
    #define Z3_NETWORK_INIT_BEHAVIOR SL_ZIGBEE_NETWORK_INIT_NO_OPTIONS
  #endif // SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_Z3

// We always want to store our parent info in a token. This prevents doing an
// orphan scan upon reboot, which can suffer from the multiple-parent-
// responses issue
  #define SL_ZIGBEE_AF_CUSTOM_NETWORK_INIT_OPTIONS (SL_ZIGBEE_NETWORK_INIT_PARENT_INFO_IN_TOKEN | Z3_NETWORK_INIT_BEHAVIOR)
#endif // SL_ZIGBEE_AF_CUSTOM_NETWORK_INIT_OPTIONS

#endif // __EMBER_AF_CONFIG_H__
