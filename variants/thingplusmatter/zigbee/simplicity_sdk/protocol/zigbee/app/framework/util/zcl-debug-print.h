/***************************************************************************//**
 * @file
 * @brief Defines debug print macros for application framework and ZCL clusters
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

#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif
#include "app/framework/util/print.h"
#if defined(SL_CATALOG_ZIGBEE_DEBUG_PRINT_PRESENT) && !defined(SL_ZIGBEE_SCRIPTED_TEST)
#include "sl_zigbee_debug_print_config.h"
#endif // SL_CATALOG_ZIGBEE_DEBUG_PRINT_PRESENT
// Generic print area.
#define SL_ZIGBEE_AF_PRINT_GENERIC 0x0000

// SL_ZIGBEE_AF_PRINT_ constants are not used in print macros (e.g. sl_zigbee_af_core_print) with UC. However there's
// still some code outside of these macros that explicitly references these contants. TODO: This should be
// cleaned up at some point.
#define SL_ZIGBEE_AF_PRINT_CORE 0x0001

// Debug print macros for the application framework and ZCL clusters.
// We are using area 0x00 in the sl_zigbee_af_print* calls below because with UC we don't (yet) have
// the per-cluster print granularity, sl_zigbee_af_print_enabled() always returns TRUE.

// We have a separate config switch (ZIGBEE_DEBUG_PRINTS_AF_DEBUG) for AF Debug because we want it off by default
#if (defined(SL_CATALOG_ZIGBEE_DEBUG_PRINT_PRESENT) && (SL_ZIGBEE_DEBUG_ZCL_GROUP_ENABLED == 1) && (SL_ZIGBEE_DEBUG_PRINTS_ZCL_LEGACY_AF_DEBUG_ENABLED == 1))
// Prints messages for random debugging
#define sl_zigbee_af_debug_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_debug_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_debug_flush()
#define sl_zigbee_af_debug_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_debug_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_debug_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#else

#define sl_zigbee_af_debug_print(...)
#define sl_zigbee_af_debug_println(...)
#define sl_zigbee_af_debug_flush()
#define sl_zigbee_af_debug_debug_exec(x)
#define sl_zigbee_af_debug_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_debug_print_string(buffer)

#endif // (defined(SL_CATALOG_ZIGBEE_DEBUG_PRINT_PRESENT) && (SL_ZIGBEE_DEBUG_ZCL_GROUP_ENABLED == 1) && (SL_ZIGBEE_DEBUG_PRINTS_ZCL_LEGACY_AF_DEBUG_ENABLED == 1))

#if (defined(SL_CATALOG_ZIGBEE_DEBUG_PRINT_PRESENT) && (SL_ZIGBEE_DEBUG_ZCL_GROUP_ENABLED == 1))
// Printing macros for Application
// Prints messages for application part
#define sl_zigbee_af_app_print(...)    sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_app_println(...)  sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_app_flush()
#define sl_zigbee_af_app_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_app_print_buffer(buffer, len, withSpace)   sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_app_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

// Printing macros for Core
// Prints messages for global flow of the receive/send
#define sl_zigbee_af_core_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_core_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
// Blocking IO is enabled for all serial ports, therefore flush calls are unnecessary.
#define sl_zigbee_af_core_flush()
#define sl_zigbee_af_core_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_core_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_core_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

// Printing macros for Reporting
// Prints messages related to reporting
#define sl_zigbee_af_reporting_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_reporting_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
// Blocking IO is enabled for all serial ports, therefore flush calls are unnecessary.
#define sl_zigbee_af_reporting_flush()
#define sl_zigbee_af_reporting_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_reporting_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_reporting_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

// Printing macros for Service discovery
// Prints messages related to service discovery
#define sl_zigbee_af_service_discovery_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_service_discovery_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
// Blocking IO is enabled for all serial ports, therefore flush calls are unnecessary.
#define sl_zigbee_af_service_discovery_flush()
#define sl_zigbee_af_service_discovery_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_service_discovery_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_service_discovery_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

// Printing macros for Attributes
// Prints messages related to attributes
#define sl_zigbee_af_attributes_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_attributes_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
// Blocking IO is enabled for all serial ports, therefore flush calls are unnecessary.
#define sl_zigbee_af_attributes_flush()
#define sl_zigbee_af_attributes_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_attributes_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_attributes_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

// Printing macros for Security
// Prints messages related to security
#define sl_zigbee_af_security_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_security_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
// Blocking IO is enabled for all serial ports, therefore flush calls are unnecessary.
#define sl_zigbee_af_security_flush()
#define sl_zigbee_af_security_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_security_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_security_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

// Printing macros for ZDO (ZigBee Device Object)
// Prints messages related to ZDO functionality
#define sl_zigbee_af_zdo_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_zdo_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
// Blocking IO is enabled for all serial ports, therefore flush calls are unnecessary.
#define sl_zigbee_af_zdo_flush()
#define sl_zigbee_af_zdo_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_zdo_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_zdo_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

// Printing macros for Registration
#define sl_zigbee_af_registration_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_registration_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
// Blocking IO is enabled for all serial ports, therefore flush calls are unnecessary.
#define sl_zigbee_af_registration_flush()
#define sl_zigbee_af_registration_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_registration_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_registration_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

// Printing macros for clusters

#define sl_zigbee_af_basic_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_basic_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_basic_cluster_flush()
#define sl_zigbee_af_basic_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_basic_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_basic_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_power_config_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_power_config_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_power_config_cluster_flush()
#define sl_zigbee_af_power_config_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_power_config_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_power_config_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_device_temp_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_device_temp_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_device_temp_cluster_flush()
#define sl_zigbee_af_device_temp_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_device_temp_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_device_temp_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_identify_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_identify_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_identify_cluster_flush()
#define sl_zigbee_af_identify_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_identify_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_identify_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_groups_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_groups_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_groups_cluster_flush()
#define sl_zigbee_af_groups_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_groups_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_groups_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_scenes_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_scenes_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_scenes_cluster_flush()
#define sl_zigbee_af_scenes_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_scenes_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_scenes_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_on_off_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_on_off_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_on_off_cluster_flush()
#define sl_zigbee_af_on_off_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_on_off_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_on_off_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_on_off_switch_config_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_on_off_switch_config_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_on_off_switch_config_cluster_flush()
#define sl_zigbee_af_on_off_switch_config_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_on_off_switch_config_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_on_off_switch_config_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_level_control_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_level_control_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_level_control_cluster_flush()
#define sl_zigbee_af_level_control_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_level_control_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_level_control_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_alarm_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_alarm_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_alarm_cluster_flush()
#define sl_zigbee_af_alarm_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_alarm_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_alarm_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_time_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_time_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_time_cluster_flush()
#define sl_zigbee_af_time_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_time_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_time_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_rssi_location_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_rssi_location_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_rssi_location_cluster_flush()
#define sl_zigbee_af_rssi_location_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_rssi_location_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_rssi_location_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_binary_input_basic_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_binary_input_basic_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_binary_input_basic_cluster_flush()
#define sl_zigbee_af_binary_input_basic_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_binary_input_basic_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_binary_input_basic_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_commissioning_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_commissioning_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_commissioning_cluster_flush()
#define sl_zigbee_af_commissioning_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_commissioning_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_commissioning_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_partition_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_partition_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_partition_cluster_flush()
#define sl_zigbee_af_partition_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_partition_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_partition_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_ota_bootload_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_ota_bootload_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_ota_bootload_cluster_flush()
#define sl_zigbee_af_ota_bootload_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_ota_bootload_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_ota_bootload_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_power_profile_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_power_profile_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_power_profile_cluster_flush()
#define sl_zigbee_af_power_profile_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_power_profile_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_power_profile_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_appliance_control_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_appliance_control_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_appliance_control_cluster_flush()
#define sl_zigbee_af_appliance_control_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_appliance_control_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_appliance_control_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_poll_control_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_poll_control_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_poll_control_cluster_flush()
#define sl_zigbee_af_poll_control_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_poll_control_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_poll_control_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_gas_proxy_function_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_gas_proxy_function_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_gas_proxy_function_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_gas_proxy_function_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_gas_proxy_function_print_string(buffer)  sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_green_power_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_green_power_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_green_power_cluster_flush()
#define sl_zigbee_af_green_power_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_green_power_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_green_power_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_keepalive_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_keepalive_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_keepalive_cluster_flush()
#define sl_zigbee_af_keepalive_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_keepalive_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_keepalive_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_shade_config_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_shade_config_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_shade_config_cluster_flush()
#define sl_zigbee_af_shade_config_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_shade_config_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_shade_config_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_door_lock_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_door_lock_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_door_lock_cluster_flush()
#define sl_zigbee_af_door_lock_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_door_lock_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_door_lock_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_window_covering_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_window_covering_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_window_covering_cluster_flush()
#define sl_zigbee_af_window_covering_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_window_covering_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_window_covering_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_barrier_control_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_barrier_control_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_barrier_control_cluster_flush()
#define sl_zigbee_af_barrier_control_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_barrier_control_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_barrier_control_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_pump_config_control_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_pump_config_control_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_pump_config_control_cluster_flush()
#define sl_zigbee_af_pump_config_control_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_pump_config_control_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_pump_config_control_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_thermostat_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_thermostat_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_thermostat_cluster_flush()
#define sl_zigbee_af_thermostat_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_thermostat_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_thermostat_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_fan_control_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_fan_control_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_fan_control_cluster_flush()
#define sl_zigbee_af_fan_control_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_fan_control_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_fan_control_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_dehumid_control_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_dehumid_control_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_dehumid_control_cluster_flush()
#define sl_zigbee_af_dehumid_control_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_dehumid_control_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_dehumid_control_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_thermostat_ui_config_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_thermostat_ui_config_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_thermostat_ui_config_cluster_flush()
#define sl_zigbee_af_thermostat_ui_config_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_thermostat_ui_config_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_thermostat_ui_config_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_color_control_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_color_control_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_color_control_cluster_flush()
#define sl_zigbee_af_color_control_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_color_control_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_color_control_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_ballast_configuration_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_ballast_configuration_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_ballast_configuration_cluster_flush()
#define sl_zigbee_af_ballast_configuration_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_ballast_configuration_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_ballast_configuration_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_illum_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_illum_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_illum_measurement_cluster_flush()
#define sl_zigbee_af_illum_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_illum_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_illum_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_illum_level_sensing_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_illum_level_sensing_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_illum_level_sensing_cluster_flush()
#define sl_zigbee_af_illum_level_sensing_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_illum_level_sensing_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_illum_level_sensing_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_temp_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_temp_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_temp_measurement_cluster_flush()
#define sl_zigbee_af_temp_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_temp_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_temp_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_pressure_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_pressure_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_pressure_measurement_cluster_flush()
#define sl_zigbee_af_pressure_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_pressure_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_pressure_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_flow_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_flow_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_flow_measurement_cluster_flush()
#define sl_zigbee_af_flow_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_flow_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_flow_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_relative_humidity_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_relative_humidity_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_relative_humidity_measurement_cluster_flush()
#define sl_zigbee_af_relative_humidity_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_relative_humidity_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_relative_humidity_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_occupancy_sensing_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_occupancy_sensing_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_occupancy_sensing_cluster_flush()
#define sl_zigbee_af_occupancy_sensing_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_occupancy_sensing_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_occupancy_sensing_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_carbon_monoxide_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_carbon_monoxide_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_carbon_monoxide_concentration_measurement_cluster_flush()
#define sl_zigbee_af_carbon_monoxide_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_carbon_monoxide_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_carbon_monoxide_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_carbon_dioxide_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_carbon_dioxide_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_carbon_dioxide_concentration_measurement_cluster_flush()
#define sl_zigbee_af_carbon_dioxide_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_carbon_dioxide_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_carbon_dioxide_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_ethylene_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_ethylene_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_ethylene_concentration_measurement_cluster_flush()
#define sl_zigbee_af_ethylene_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_ethylene_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_ethylene_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_ethylene_oxide_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_ethylene_oxide_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_ethylene_oxide_concentration_measurement_cluster_flush()
#define sl_zigbee_af_ethylene_oxide_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_ethylene_oxide_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_ethylene_oxide_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_hydrogen_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_hydrogen_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_hydrogen_concentration_measurement_cluster_flush()
#define sl_zigbee_af_hydrogen_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_hydrogen_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_hydrogen_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_hydrogen_sulphide_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_hydrogen_sulphide_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_hydrogen_sulphide_concentration_measurement_cluster_flush()
#define sl_zigbee_af_hydrogen_sulphide_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_hydrogen_sulphide_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_hydrogen_sulphide_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_nitric_oxide_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_nitric_oxide_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_nitric_oxide_concentration_measurement_cluster_flush()
#define sl_zigbee_af_nitric_oxide_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_nitric_oxide_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_nitric_oxide_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_nitrogen_dioxide_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_nitrogen_dioxide_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_nitrogen_dioxide_concentration_measurement_cluster_flush()
#define sl_zigbee_af_nitrogen_dioxide_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_nitrogen_dioxide_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_nitrogen_dioxide_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_oxygen_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_oxygen_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_oxygen_concentration_measurement_cluster_flush()
#define sl_zigbee_af_oxygen_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_oxygen_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_oxygen_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_ozone_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_ozone_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_ozone_concentration_measurement_cluster_flush()
#define sl_zigbee_af_ozone_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_ozone_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_ozone_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_sulfur_dioxide_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_sulfur_dioxide_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_sulfur_dioxide_concentration_measurement_cluster_flush()
#define sl_zigbee_af_sulfur_dioxide_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_sulfur_dioxide_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_sulfur_dioxide_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_dissolved_oxygen_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_dissolved_oxygen_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_dissolved_oxygen_concentration_measurement_cluster_flush()
#define sl_zigbee_af_dissolved_oxygen_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_dissolved_oxygen_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_dissolved_oxygen_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_bromate_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_bromate_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_bromate_concentration_measurement_cluster_flush()
#define sl_zigbee_af_bromate_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_bromate_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_bromate_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_chloramines_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_chloramines_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_chloramines_concentration_measurement_cluster_flush()
#define sl_zigbee_af_chloramines_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_chloramines_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_chloramines_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_chlorine_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_chlorine_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_chlorine_concentration_measurement_cluster_flush()
#define sl_zigbee_af_chlorine_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_chlorine_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_chlorine_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_fecal_coliform_and_e_coli_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_fecal_coliform_and_e_coli_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_fecal_coliform_and_e_coli_concentration_measurement_cluster_flush()
#define sl_zigbee_af_fecal_coliform_and_e_coli_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_fecal_coliform_and_e_coli_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_fecal_coliform_and_e_coli_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_fluoride_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_fluoride_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_fluoride_concentration_measurement_cluster_flush()
#define sl_zigbee_af_fluoride_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_fluoride_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_fluoride_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_haloacetic_acids_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_haloacetic_acids_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_haloacetic_acids_concentration_measurement_cluster_flush()
#define sl_zigbee_af_haloacetic_acids_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_haloacetic_acids_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_haloacetic_acids_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_total_trihalomethanes_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_total_trihalomethanes_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_total_trihalomethanes_concentration_measurement_cluster_flush()
#define sl_zigbee_af_total_trihalomethanes_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_total_trihalomethanes_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_total_trihalomethanes_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_total_coliform_bacteria_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_total_coliform_bacteria_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_total_coliform_bacteria_concentration_measurement_cluster_flush()
#define sl_zigbee_af_total_coliform_bacteria_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_total_coliform_bacteria_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_total_coliform_bacteria_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_turbidity_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_turbidity_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_turbidity_concentration_measurement_cluster_flush()
#define sl_zigbee_af_turbidity_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_turbidity_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_turbidity_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_copper_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_copper_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_copper_concentration_measurement_cluster_flush()
#define sl_zigbee_af_copper_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_copper_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_copper_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_lead_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_lead_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_lead_concentration_measurement_cluster_flush()
#define sl_zigbee_af_lead_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_lead_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_lead_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_manganese_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_manganese_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_manganese_concentration_measurement_cluster_flush()
#define sl_zigbee_af_manganese_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_manganese_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_manganese_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_sulfate_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_sulfate_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_sulfate_concentration_measurement_cluster_flush()
#define sl_zigbee_af_sulfate_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_sulfate_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_sulfate_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_bromodichloromethane_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_bromodichloromethane_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_bromodichloromethane_concentration_measurement_cluster_flush()
#define sl_zigbee_af_bromodichloromethane_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_bromodichloromethane_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_bromodichloromethane_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_bromoform_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_bromoform_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_bromoform_concentration_measurement_cluster_flush()
#define sl_zigbee_af_bromoform_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_bromoform_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_bromoform_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_chlorodibromomethane_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_chlorodibromomethane_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_chlorodibromomethane_concentration_measurement_cluster_flush()
#define sl_zigbee_af_chlorodibromomethane_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_chlorodibromomethane_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_chlorodibromomethane_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_chloroform_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_chloroform_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_chloroform_concentration_measurement_cluster_flush()
#define sl_zigbee_af_chloroform_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_chloroform_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_chloroform_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_sodium_concentration_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_sodium_concentration_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_sodium_concentration_measurement_cluster_flush()
#define sl_zigbee_af_sodium_concentration_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_sodium_concentration_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_sodium_concentration_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_ias_zone_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_ias_zone_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_ias_zone_cluster_flush()
#define sl_zigbee_af_ias_zone_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_ias_zone_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_ias_zone_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_ias_ace_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_ias_ace_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_ias_ace_cluster_flush()
#define sl_zigbee_af_ias_ace_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_ias_ace_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_ias_ace_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_ias_wd_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_ias_wd_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_ias_wd_cluster_flush()
#define sl_zigbee_af_ias_wd_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_ias_wd_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_ias_wd_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_generic_tunnel_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_generic_tunnel_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_generic_tunnel_cluster_flush()
#define sl_zigbee_af_generic_tunnel_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_generic_tunnel_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_generic_tunnel_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_bacnet_protocol_tunnel_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_bacnet_protocol_tunnel_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_bacnet_protocol_tunnel_cluster_flush()
#define sl_zigbee_af_bacnet_protocol_tunnel_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_bacnet_protocol_tunnel_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_bacnet_protocol_tunnel_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_11073_protocol_tunnel_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_11073_protocol_tunnel_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_11073_protocol_tunnel_cluster_flush()
#define sl_zigbee_af_11073_protocol_tunnel_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_11073_protocol_tunnel_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_11073_protocol_tunnel_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_iso7816_protocol_tunnel_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_iso7816_protocol_tunnel_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_iso7816_protocol_tunnel_cluster_flush()
#define sl_zigbee_af_iso7816_protocol_tunnel_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_iso7816_protocol_tunnel_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_iso7816_protocol_tunnel_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_price_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_price_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_price_cluster_flush()
#define sl_zigbee_af_price_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_price_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_price_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_demand_response_load_control_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_demand_response_load_control_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_demand_response_load_control_cluster_flush()
#define sl_zigbee_af_demand_response_load_control_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_demand_response_load_control_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_demand_response_load_control_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_simple_metering_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_simple_metering_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_simple_metering_cluster_flush()
#define sl_zigbee_af_simple_metering_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_simple_metering_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_simple_metering_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_messaging_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_messaging_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_messaging_cluster_flush()
#define sl_zigbee_af_messaging_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_messaging_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_messaging_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_tunneling_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_tunneling_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_tunneling_cluster_flush()
#define sl_zigbee_af_tunneling_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_tunneling_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_tunneling_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_prepayment_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_prepayment_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_prepayment_cluster_flush()
#define sl_zigbee_af_prepayment_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_prepayment_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_prepayment_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_energy_management_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_energy_management_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_energy_management_cluster_flush()
#define sl_zigbee_af_energy_management_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_energy_management_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_energy_management_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_calendar_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_calendar_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_calendar_cluster_flush()
#define sl_zigbee_af_calendar_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_calendar_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_calendar_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_device_management_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_device_management_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_device_management_cluster_flush()
#define sl_zigbee_af_device_management_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_device_management_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_device_management_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_events_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_events_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_events_cluster_flush()
#define sl_zigbee_af_events_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_events_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_events_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_mdu_pairing_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_mdu_pairing_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_mdu_pairing_cluster_flush()
#define sl_zigbee_af_mdu_pairing_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_mdu_pairing_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_mdu_pairing_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_sub_ghz_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_sub_ghz_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_sub_ghz_cluster_flush()
#define sl_zigbee_af_sub_ghz_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_sub_ghz_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_sub_ghz_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_key_establishment_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_key_establishment_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_key_establishment_cluster_flush()
#define sl_zigbee_af_key_establishment_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_key_establishment_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_key_establishment_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_information_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_information_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_information_cluster_flush()
#define sl_zigbee_af_information_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_information_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_information_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_data_sharing_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_data_sharing_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_data_sharing_cluster_flush()
#define sl_zigbee_af_data_sharing_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_data_sharing_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_data_sharing_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_gaming_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_gaming_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_gaming_cluster_flush()
#define sl_zigbee_af_gaming_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_gaming_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_gaming_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_data_rate_control_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_data_rate_control_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_data_rate_control_cluster_flush()
#define sl_zigbee_af_data_rate_control_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_data_rate_control_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_data_rate_control_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_voice_over_zigbee_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_voice_over_zigbee_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_voice_over_zigbee_cluster_flush()
#define sl_zigbee_af_voice_over_zigbee_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_voice_over_zigbee_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_voice_over_zigbee_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_chatting_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_chatting_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_chatting_cluster_flush()
#define sl_zigbee_af_chatting_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_chatting_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_chatting_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_payment_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_payment_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_payment_cluster_flush()
#define sl_zigbee_af_payment_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_payment_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_payment_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_billing_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_billing_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_billing_cluster_flush()
#define sl_zigbee_af_billing_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_billing_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_billing_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_appliance_identification_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_appliance_identification_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_appliance_identification_cluster_flush()
#define sl_zigbee_af_appliance_identification_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_appliance_identification_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_appliance_identification_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_meter_identification_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_meter_identification_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_meter_identification_cluster_flush()
#define sl_zigbee_af_meter_identification_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_meter_identification_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_meter_identification_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_appliance_events_and_alert_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_appliance_events_and_alert_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_appliance_events_and_alert_cluster_flush()
#define sl_zigbee_af_appliance_events_and_alert_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_appliance_events_and_alert_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_appliance_events_and_alert_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_appliance_statistics_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_appliance_statistics_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_appliance_statistics_cluster_flush()
#define sl_zigbee_af_appliance_statistics_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_appliance_statistics_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_appliance_statistics_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_electrical_measurement_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_electrical_measurement_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_electrical_measurement_cluster_flush()
#define sl_zigbee_af_electrical_measurement_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_electrical_measurement_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_electrical_measurement_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_diagnostics_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_diagnostics_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_diagnostics_cluster_flush()
#define sl_zigbee_af_diagnostics_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_diagnostics_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_diagnostics_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_zll_commissioning_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_zll_commissioning_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_zll_commissioning_cluster_flush()
#define sl_zigbee_af_zll_commissioning_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_zll_commissioning_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_zll_commissioning_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_sample_mfg_specific_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_sample_mfg_specific_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_sample_mfg_specific_cluster_flush()
#define sl_zigbee_af_sample_mfg_specific_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_sample_mfg_specific_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_sample_mfg_specific_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_ota_configuration_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_ota_configuration_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_ota_configuration_cluster_flush()
#define sl_zigbee_af_ota_configuration_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_ota_configuration_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_ota_configuration_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_mfglib_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_mfglib_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_mfglib_cluster_flush()
#define sl_zigbee_af_mfglib_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_mfglib_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_mfglib_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#define sl_zigbee_af_sl_wwah_cluster_print(...) sl_zigbee_af_print(0x00, __VA_ARGS__)
#define sl_zigbee_af_sl_wwah_cluster_println(...) sl_zigbee_af_println(0x00, __VA_ARGS__)
#define sl_zigbee_af_sl_wwah_cluster_flush()
#define sl_zigbee_af_sl_wwah_cluster_debug_exec(x) if ( sl_zigbee_af_print_enabled(0x00) ) { x; }
#define sl_zigbee_af_sl_wwah_cluster_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0x00, (buffer), (len), (withSpace))
#define sl_zigbee_af_sl_wwah_cluster_print_string(buffer) sl_zigbee_af_print_string(0x00, (buffer))

#else // (SL_ZIGBEE_DEBUG_ZCL_GROUP_ENABLED == 1)

#define sl_zigbee_af_app_print(...)
#define sl_zigbee_af_app_println(...)
#define sl_zigbee_af_app_flush()
#define sl_zigbee_af_app_debug_exec(x)
#define sl_zigbee_af_app_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_app_print_string(buffer)

#define sl_zigbee_af_core_print(...)
#define sl_zigbee_af_core_println(...)
#define sl_zigbee_af_core_flush()
#define sl_zigbee_af_core_debug_exec(x)
#define sl_zigbee_af_core_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_core_print_string(buffer)

#define sl_zigbee_af_reporting_print(...)
#define sl_zigbee_af_reporting_println(...)
#define sl_zigbee_af_reporting_flush()
#define sl_zigbee_af_reporting_debug_exec(x)
#define sl_zigbee_af_reporting_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_reporting_print_string(buffer)

#define sl_zigbee_af_service_discovery_print(...)
#define sl_zigbee_af_service_discovery_println(...)
#define sl_zigbee_af_service_discovery_flush()
#define sl_zigbee_af_service_discovery_debug_exec(x)
#define sl_zigbee_af_service_discovery_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_service_discovery_print_string(buffer)

#define sl_zigbee_af_attributes_print(...)
#define sl_zigbee_af_attributes_println(...)
#define sl_zigbee_af_attributes_flush()
#define sl_zigbee_af_attributes_debug_exec(x)
#define sl_zigbee_af_attributes_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_attributes_print_string(buffer)

#define sl_zigbee_af_security_print(...)
#define sl_zigbee_af_security_println(...)
#define sl_zigbee_af_security_flush()
#define sl_zigbee_af_security_debug_exec(x)
#define sl_zigbee_af_security_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_security_print_string(buffer)

#define sl_zigbee_af_zdo_print(...)
#define sl_zigbee_af_zdo_println(...)
#define sl_zigbee_af_zdo_flush()
#define sl_zigbee_af_zdo_debug_exec(x)
#define sl_zigbee_af_zdo_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_zdo_print_string(buffer)

// Printing macros for Registration
#define sl_zigbee_af_registration_print(...)
#define sl_zigbee_af_registration_println(...)
#define sl_zigbee_af_registration_flush()
#define sl_zigbee_af_registration_debug_exec(x)
#define sl_zigbee_af_registration_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_registration_print_string(buffer)

// Printing macros for clusters

#define sl_zigbee_af_basic_cluster_print(...)
#define sl_zigbee_af_basic_cluster_println(...)
#define sl_zigbee_af_basic_cluster_flush()
#define sl_zigbee_af_basic_cluster_debug_exec(x)
#define sl_zigbee_af_basic_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_basic_cluster_print_string(buffer)

#define sl_zigbee_af_power_config_cluster_print(...)
#define sl_zigbee_af_power_config_cluster_println(...)
#define sl_zigbee_af_power_config_cluster_flush()
#define sl_zigbee_af_power_config_cluster_debug_exec(x)
#define sl_zigbee_af_power_config_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_power_config_cluster_print_string(buffer)

#define sl_zigbee_af_device_temp_cluster_print(...)
#define sl_zigbee_af_device_temp_cluster_println(...)
#define sl_zigbee_af_device_temp_cluster_flush()
#define sl_zigbee_af_device_temp_cluster_debug_exec(x)
#define sl_zigbee_af_device_temp_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_device_temp_cluster_print_string(buffer)

#define sl_zigbee_af_identify_cluster_print(...)
#define sl_zigbee_af_identify_cluster_println(...)
#define sl_zigbee_af_identify_cluster_flush()
#define sl_zigbee_af_identify_cluster_debug_exec(x)
#define sl_zigbee_af_identify_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_identify_cluster_print_string(buffer)

#define sl_zigbee_af_groups_cluster_print(...)
#define sl_zigbee_af_groups_cluster_println(...)
#define sl_zigbee_af_groups_cluster_flush()
#define sl_zigbee_af_groups_cluster_debug_exec(x)
#define sl_zigbee_af_groups_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_groups_cluster_print_string(buffer)

#define sl_zigbee_af_scenes_cluster_print(...)
#define sl_zigbee_af_scenes_cluster_println(...)
#define sl_zigbee_af_scenes_cluster_flush()
#define sl_zigbee_af_scenes_cluster_debug_exec(x)
#define sl_zigbee_af_scenes_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_scenes_cluster_print_string(buffer)

#define sl_zigbee_af_on_off_cluster_print(...)
#define sl_zigbee_af_on_off_cluster_println(...)
#define sl_zigbee_af_on_off_cluster_flush()
#define sl_zigbee_af_on_off_cluster_debug_exec(x)
#define sl_zigbee_af_on_off_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_on_off_cluster_print_string(buffer)

#define sl_zigbee_af_on_off_switch_config_cluster_print(...)
#define sl_zigbee_af_on_off_switch_config_cluster_println(...)
#define sl_zigbee_af_on_off_switch_config_cluster_flush()
#define sl_zigbee_af_on_off_switch_config_cluster_debug_exec(x)
#define sl_zigbee_af_on_off_switch_config_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_on_off_switch_config_cluster_print_string(buffer)

#define sl_zigbee_af_level_control_cluster_print(...)
#define sl_zigbee_af_level_control_cluster_println(...)
#define sl_zigbee_af_level_control_cluster_flush()
#define sl_zigbee_af_level_control_cluster_debug_exec(x)
#define sl_zigbee_af_level_control_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_level_control_cluster_print_string(buffer)

#define sl_zigbee_af_alarm_cluster_print(...)
#define sl_zigbee_af_alarm_cluster_println(...)
#define sl_zigbee_af_alarm_cluster_flush()
#define sl_zigbee_af_alarm_cluster_debug_exec(x)
#define sl_zigbee_af_alarm_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_alarm_cluster_print_string(buffer)

#define sl_zigbee_af_time_cluster_print(...)
#define sl_zigbee_af_time_cluster_println(...)
#define sl_zigbee_af_time_cluster_flush()
#define sl_zigbee_af_time_cluster_debug_exec(x)
#define sl_zigbee_af_time_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_time_cluster_print_string(buffer)

#define sl_zigbee_af_rssi_location_cluster_print(...)
#define sl_zigbee_af_rssi_location_cluster_println(...)
#define sl_zigbee_af_rssi_location_cluster_flush()
#define sl_zigbee_af_rssi_location_cluster_debug_exec(x)
#define sl_zigbee_af_rssi_location_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_rssi_location_cluster_print_string(buffer)

#define sl_zigbee_af_binary_input_basic_cluster_print(...)
#define sl_zigbee_af_binary_input_basic_cluster_println(...)
#define sl_zigbee_af_binary_input_basic_cluster_flush()
#define sl_zigbee_af_binary_input_basic_cluster_debug_exec(x)
#define sl_zigbee_af_binary_input_basic_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_binary_input_basic_cluster_print_string(buffer)

#define sl_zigbee_af_commissioning_cluster_print(...)
#define sl_zigbee_af_commissioning_cluster_println(...)
#define sl_zigbee_af_commissioning_cluster_flush()
#define sl_zigbee_af_commissioning_cluster_debug_exec(x)
#define sl_zigbee_af_commissioning_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_commissioning_cluster_print_string(buffer)

#define sl_zigbee_af_partition_cluster_print(...)
#define sl_zigbee_af_partition_cluster_println(...)
#define sl_zigbee_af_partition_cluster_flush()
#define sl_zigbee_af_partition_cluster_debug_exec(x)
#define sl_zigbee_af_partition_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_partition_cluster_print_string(buffer)

#define sl_zigbee_af_ota_bootload_cluster_print(...)
#define sl_zigbee_af_ota_bootload_cluster_println(...)
#define sl_zigbee_af_ota_bootload_cluster_flush()
#define sl_zigbee_af_ota_bootload_cluster_debug_exec(x)
#define sl_zigbee_af_ota_bootload_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_ota_bootload_cluster_print_string(buffer)

#define sl_zigbee_af_power_profile_cluster_print(...)
#define sl_zigbee_af_power_profile_cluster_println(...)
#define sl_zigbee_af_power_profile_cluster_flush()
#define sl_zigbee_af_power_profile_cluster_debug_exec(x)
#define sl_zigbee_af_power_profile_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_power_profile_cluster_print_string(buffer)

#define sl_zigbee_af_appliance_control_cluster_print(...)
#define sl_zigbee_af_appliance_control_cluster_println(...)
#define sl_zigbee_af_appliance_control_cluster_flush()
#define sl_zigbee_af_appliance_control_cluster_debug_exec(x)
#define sl_zigbee_af_appliance_control_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_appliance_control_cluster_print_string(buffer)

#define sl_zigbee_af_poll_control_cluster_print(...)
#define sl_zigbee_af_poll_control_cluster_println(...)
#define sl_zigbee_af_poll_control_cluster_flush()
#define sl_zigbee_af_poll_control_cluster_debug_exec(x)
#define sl_zigbee_af_poll_control_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_poll_control_cluster_print_string(buffer)

#define sl_zigbee_af_gas_proxy_function_print(...)
#define sl_zigbee_af_gas_proxy_function_println(...)
#define sl_zigbee_af_gas_proxy_function_debug_exec(x)
#define sl_zigbee_af_gas_proxy_function_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_gas_proxy_function_print_string(buffer)

#define sl_zigbee_af_green_power_cluster_print(...)
#define sl_zigbee_af_green_power_cluster_println(...)
#define sl_zigbee_af_green_power_cluster_flush()
#define sl_zigbee_af_green_power_cluster_debug_exec(x)
#define sl_zigbee_af_green_power_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_green_power_cluster_print_string(buffer)

#define sl_zigbee_af_keepalive_cluster_print(...)
#define sl_zigbee_af_keepalive_cluster_println(...)
#define sl_zigbee_af_keepalive_cluster_flush()
#define sl_zigbee_af_keepalive_cluster_debug_exec(x)
#define sl_zigbee_af_keepalive_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_keepalive_cluster_print_string(buffer)

#define sl_zigbee_af_shade_config_cluster_print(...)
#define sl_zigbee_af_shade_config_cluster_println(...)
#define sl_zigbee_af_shade_config_cluster_flush()
#define sl_zigbee_af_shade_config_cluster_debug_exec(x)
#define sl_zigbee_af_shade_config_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_shade_config_cluster_print_string(buffer)

#define sl_zigbee_af_door_lock_cluster_print(...)
#define sl_zigbee_af_door_lock_cluster_println(...)
#define sl_zigbee_af_door_lock_cluster_flush()
#define sl_zigbee_af_door_lock_cluster_debug_exec(x)
#define sl_zigbee_af_door_lock_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_door_lock_cluster_print_string(buffer)

#define sl_zigbee_af_window_covering_cluster_print(...)
#define sl_zigbee_af_window_covering_cluster_println(...)
#define sl_zigbee_af_window_covering_cluster_flush()
#define sl_zigbee_af_window_covering_cluster_debug_exec(x)
#define sl_zigbee_af_window_covering_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_window_covering_cluster_print_string(buffer)

#define sl_zigbee_af_barrier_control_cluster_print(...)
#define sl_zigbee_af_barrier_control_cluster_println(...)
#define sl_zigbee_af_barrier_control_cluster_flush()
#define sl_zigbee_af_barrier_control_cluster_debug_exec(x)
#define sl_zigbee_af_barrier_control_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_barrier_control_cluster_print_string(buffer)

#define sl_zigbee_af_pump_config_control_cluster_print(...)
#define sl_zigbee_af_pump_config_control_cluster_println(...)
#define sl_zigbee_af_pump_config_control_cluster_flush()
#define sl_zigbee_af_pump_config_control_cluster_debug_exec(x)
#define sl_zigbee_af_pump_config_control_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_pump_config_control_cluster_print_string(buffer)

#define sl_zigbee_af_thermostat_cluster_print(...)
#define sl_zigbee_af_thermostat_cluster_println(...)
#define sl_zigbee_af_thermostat_cluster_flush()
#define sl_zigbee_af_thermostat_cluster_debug_exec(x)
#define sl_zigbee_af_thermostat_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_thermostat_cluster_print_string(buffer)

#define sl_zigbee_af_fan_control_cluster_print(...)
#define sl_zigbee_af_fan_control_cluster_println(...)
#define sl_zigbee_af_fan_control_cluster_flush()
#define sl_zigbee_af_fan_control_cluster_debug_exec(x)
#define sl_zigbee_af_fan_control_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_fan_control_cluster_print_string(buffer)

#define sl_zigbee_af_dehumid_control_cluster_print(...)
#define sl_zigbee_af_dehumid_control_cluster_println(...)
#define sl_zigbee_af_dehumid_control_cluster_flush()
#define sl_zigbee_af_dehumid_control_cluster_debug_exec(x)
#define sl_zigbee_af_dehumid_control_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_dehumid_control_cluster_print_string(buffer)

#define sl_zigbee_af_thermostat_ui_config_cluster_print(...)
#define sl_zigbee_af_thermostat_ui_config_cluster_println(...)
#define sl_zigbee_af_thermostat_ui_config_cluster_flush()
#define sl_zigbee_af_thermostat_ui_config_cluster_debug_exec(x)
#define sl_zigbee_af_thermostat_ui_config_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_thermostat_ui_config_cluster_print_string(buffer)

#define sl_zigbee_af_color_control_cluster_print(...)
#define sl_zigbee_af_color_control_cluster_println(...)
#define sl_zigbee_af_color_control_cluster_flush()
#define sl_zigbee_af_color_control_cluster_debug_exec(x)
#define sl_zigbee_af_color_control_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_color_control_cluster_print_string(buffer)

#define sl_zigbee_af_ballast_configuration_cluster_print(...)
#define sl_zigbee_af_ballast_configuration_cluster_println(...)
#define sl_zigbee_af_ballast_configuration_cluster_flush()
#define sl_zigbee_af_ballast_configuration_cluster_debug_exec(x)
#define sl_zigbee_af_ballast_configuration_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_ballast_configuration_cluster_print_string(buffer)

#define sl_zigbee_af_illum_measurement_cluster_print(...)
#define sl_zigbee_af_illum_measurement_cluster_println(...)
#define sl_zigbee_af_illum_measurement_cluster_flush()
#define sl_zigbee_af_illum_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_illum_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_illum_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_illum_level_sensing_cluster_print(...)
#define sl_zigbee_af_illum_level_sensing_cluster_println(...)
#define sl_zigbee_af_illum_level_sensing_cluster_flush()
#define sl_zigbee_af_illum_level_sensing_cluster_debug_exec(x)
#define sl_zigbee_af_illum_level_sensing_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_illum_level_sensing_cluster_print_string(buffer)

#define sl_zigbee_af_temp_measurement_cluster_print(...)
#define sl_zigbee_af_temp_measurement_cluster_println(...)
#define sl_zigbee_af_temp_measurement_cluster_flush()
#define sl_zigbee_af_temp_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_temp_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_temp_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_pressure_measurement_cluster_print(...)
#define sl_zigbee_af_pressure_measurement_cluster_println(...)
#define sl_zigbee_af_pressure_measurement_cluster_flush()
#define sl_zigbee_af_pressure_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_pressure_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_pressure_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_flow_measurement_cluster_print(...)
#define sl_zigbee_af_flow_measurement_cluster_println(...)
#define sl_zigbee_af_flow_measurement_cluster_flush()
#define sl_zigbee_af_flow_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_flow_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_flow_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_relative_humidity_measurement_cluster_print(...)
#define sl_zigbee_af_relative_humidity_measurement_cluster_println(...)
#define sl_zigbee_af_relative_humidity_measurement_cluster_flush()
#define sl_zigbee_af_relative_humidity_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_relative_humidity_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_relative_humidity_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_occupancy_sensing_cluster_print(...)
#define sl_zigbee_af_occupancy_sensing_cluster_println(...)
#define sl_zigbee_af_occupancy_sensing_cluster_flush()
#define sl_zigbee_af_occupancy_sensing_cluster_debug_exec(x)
#define sl_zigbee_af_occupancy_sensing_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_occupancy_sensing_cluster_print_string(buffer)

#define sl_zigbee_af_carbon_monoxide_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_carbon_monoxide_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_carbon_monoxide_concentration_measurement_cluster_flush()
#define sl_zigbee_af_carbon_monoxide_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_carbon_monoxide_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_carbon_monoxide_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_carbon_dioxide_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_carbon_dioxide_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_carbon_dioxide_concentration_measurement_cluster_flush()
#define sl_zigbee_af_carbon_dioxide_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_carbon_dioxide_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_carbon_dioxide_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_ethylene_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_ethylene_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_ethylene_concentration_measurement_cluster_flush()
#define sl_zigbee_af_ethylene_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_ethylene_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_ethylene_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_ethylene_oxide_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_ethylene_oxide_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_ethylene_oxide_concentration_measurement_cluster_flush()
#define sl_zigbee_af_ethylene_oxide_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_ethylene_oxide_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_ethylene_oxide_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_hydrogen_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_hydrogen_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_hydrogen_concentration_measurement_cluster_flush()
#define sl_zigbee_af_hydrogen_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_hydrogen_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_hydrogen_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_hydrogen_sulphide_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_hydrogen_sulphide_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_hydrogen_sulphide_concentration_measurement_cluster_flush()
#define sl_zigbee_af_hydrogen_sulphide_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_hydrogen_sulphide_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_hydrogen_sulphide_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_nitric_oxide_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_nitric_oxide_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_nitric_oxide_concentration_measurement_cluster_flush()
#define sl_zigbee_af_nitric_oxide_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_nitric_oxide_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_nitric_oxide_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_nitrogen_dioxide_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_nitrogen_dioxide_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_nitrogen_dioxide_concentration_measurement_cluster_flush()
#define sl_zigbee_af_nitrogen_dioxide_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_nitrogen_dioxide_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_nitrogen_dioxide_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_oxygen_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_oxygen_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_oxygen_concentration_measurement_cluster_flush()
#define sl_zigbee_af_oxygen_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_oxygen_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_oxygen_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_ozone_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_ozone_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_ozone_concentration_measurement_cluster_flush()
#define sl_zigbee_af_ozone_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_ozone_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_ozone_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_sulfur_dioxide_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_sulfur_dioxide_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_sulfur_dioxide_concentration_measurement_cluster_flush()
#define sl_zigbee_af_sulfur_dioxide_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_sulfur_dioxide_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_sulfur_dioxide_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_dissolved_oxygen_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_dissolved_oxygen_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_dissolved_oxygen_concentration_measurement_cluster_flush()
#define sl_zigbee_af_dissolved_oxygen_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_dissolved_oxygen_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_dissolved_oxygen_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_bromate_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_bromate_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_bromate_concentration_measurement_cluster_flush()
#define sl_zigbee_af_bromate_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_bromate_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_bromate_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_chloramines_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_chloramines_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_chloramines_concentration_measurement_cluster_flush()
#define sl_zigbee_af_chloramines_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_chloramines_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_chloramines_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_chlorine_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_chlorine_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_chlorine_concentration_measurement_cluster_flush()
#define sl_zigbee_af_chlorine_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_chlorine_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_chlorine_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_fecal_coliform_and_e_coli_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_fecal_coliform_and_e_coli_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_fecal_coliform_and_e_coli_concentration_measurement_cluster_flush()
#define sl_zigbee_af_fecal_coliform_and_e_coli_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_fecal_coliform_and_e_coli_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_fecal_coliform_and_e_coli_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_fluoride_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_fluoride_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_fluoride_concentration_measurement_cluster_flush()
#define sl_zigbee_af_fluoride_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_fluoride_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_fluoride_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_haloacetic_acids_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_haloacetic_acids_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_haloacetic_acids_concentration_measurement_cluster_flush()
#define sl_zigbee_af_haloacetic_acids_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_haloacetic_acids_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_haloacetic_acids_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_total_trihalomethanes_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_total_trihalomethanes_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_total_trihalomethanes_concentration_measurement_cluster_flush()
#define sl_zigbee_af_total_trihalomethanes_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_total_trihalomethanes_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_total_trihalomethanes_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_total_coliform_bacteria_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_total_coliform_bacteria_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_total_coliform_bacteria_concentration_measurement_cluster_flush()
#define sl_zigbee_af_total_coliform_bacteria_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_total_coliform_bacteria_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_total_coliform_bacteria_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_turbidity_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_turbidity_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_turbidity_concentration_measurement_cluster_flush()
#define sl_zigbee_af_turbidity_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_turbidity_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_turbidity_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_copper_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_copper_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_copper_concentration_measurement_cluster_flush()
#define sl_zigbee_af_copper_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_copper_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_copper_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_lead_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_lead_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_lead_concentration_measurement_cluster_flush()
#define sl_zigbee_af_lead_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_lead_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_lead_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_manganese_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_manganese_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_manganese_concentration_measurement_cluster_flush()
#define sl_zigbee_af_manganese_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_manganese_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_manganese_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_sulfate_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_sulfate_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_sulfate_concentration_measurement_cluster_flush()
#define sl_zigbee_af_sulfate_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_sulfate_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_sulfate_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_bromodichloromethane_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_bromodichloromethane_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_bromodichloromethane_concentration_measurement_cluster_flush()
#define sl_zigbee_af_bromodichloromethane_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_bromodichloromethane_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_bromodichloromethane_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_bromoform_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_bromoform_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_bromoform_concentration_measurement_cluster_flush()
#define sl_zigbee_af_bromoform_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_bromoform_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_bromoform_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_chlorodibromomethane_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_chlorodibromomethane_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_chlorodibromomethane_concentration_measurement_cluster_flush()
#define sl_zigbee_af_chlorodibromomethane_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_chlorodibromomethane_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_chlorodibromomethane_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_chloroform_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_chloroform_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_chloroform_concentration_measurement_cluster_flush()
#define sl_zigbee_af_chloroform_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_chloroform_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_chloroform_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_sodium_concentration_measurement_cluster_print(...)
#define sl_zigbee_af_sodium_concentration_measurement_cluster_println(...)
#define sl_zigbee_af_sodium_concentration_measurement_cluster_flush()
#define sl_zigbee_af_sodium_concentration_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_sodium_concentration_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_sodium_concentration_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_ias_zone_cluster_print(...)
#define sl_zigbee_af_ias_zone_cluster_println(...)
#define sl_zigbee_af_ias_zone_cluster_flush()
#define sl_zigbee_af_ias_zone_cluster_debug_exec(x)
#define sl_zigbee_af_ias_zone_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_ias_zone_cluster_print_string(buffer)

#define sl_zigbee_af_ias_ace_cluster_print(...)
#define sl_zigbee_af_ias_ace_cluster_println(...)
#define sl_zigbee_af_ias_ace_cluster_flush()
#define sl_zigbee_af_ias_ace_cluster_debug_exec(x)
#define sl_zigbee_af_ias_ace_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_ias_ace_cluster_print_string(buffer)

#define sl_zigbee_af_ias_wd_cluster_print(...)
#define sl_zigbee_af_ias_wd_cluster_println(...)
#define sl_zigbee_af_ias_wd_cluster_flush()
#define sl_zigbee_af_ias_wd_cluster_debug_exec(x)
#define sl_zigbee_af_ias_wd_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_ias_wd_cluster_print_string(buffer)

#define sl_zigbee_af_generic_tunnel_cluster_print(...)
#define sl_zigbee_af_generic_tunnel_cluster_println(...)
#define sl_zigbee_af_generic_tunnel_cluster_flush()
#define sl_zigbee_af_generic_tunnel_cluster_debug_exec(x)
#define sl_zigbee_af_generic_tunnel_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_generic_tunnel_cluster_print_string(buffer)

#define sl_zigbee_af_bacnet_protocol_tunnel_cluster_print(...)
#define sl_zigbee_af_bacnet_protocol_tunnel_cluster_println(...)
#define sl_zigbee_af_bacnet_protocol_tunnel_cluster_flush()
#define sl_zigbee_af_bacnet_protocol_tunnel_cluster_debug_exec(x)
#define sl_zigbee_af_bacnet_protocol_tunnel_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_bacnet_protocol_tunnel_cluster_print_string(buffer)

#define sl_zigbee_af_11073_protocol_tunnel_cluster_print(...)
#define sl_zigbee_af_11073_protocol_tunnel_cluster_println(...)
#define sl_zigbee_af_11073_protocol_tunnel_cluster_flush()
#define sl_zigbee_af_11073_protocol_tunnel_cluster_debug_exec(x)
#define sl_zigbee_af_11073_protocol_tunnel_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_11073_protocol_tunnel_cluster_print_string(buffer)

#define sl_zigbee_af_iso7816_protocol_tunnel_cluster_print(...)
#define sl_zigbee_af_iso7816_protocol_tunnel_cluster_println(...)
#define sl_zigbee_af_iso7816_protocol_tunnel_cluster_flush()
#define sl_zigbee_af_iso7816_protocol_tunnel_cluster_debug_exec(x)
#define sl_zigbee_af_iso7816_protocol_tunnel_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_iso7816_protocol_tunnel_cluster_print_string(buffer)

#define sl_zigbee_af_price_cluster_print(...)
#define sl_zigbee_af_price_cluster_println(...)
#define sl_zigbee_af_price_cluster_flush()
#define sl_zigbee_af_price_cluster_debug_exec(x)
#define sl_zigbee_af_price_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_price_cluster_print_string(buffer)

#define sl_zigbee_af_demand_response_load_control_cluster_print(...)
#define sl_zigbee_af_demand_response_load_control_cluster_println(...)
#define sl_zigbee_af_demand_response_load_control_cluster_flush()
#define sl_zigbee_af_demand_response_load_control_cluster_debug_exec(x)
#define sl_zigbee_af_demand_response_load_control_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_demand_response_load_control_cluster_print_string(buffer)

#define sl_zigbee_af_simple_metering_cluster_print(...)
#define sl_zigbee_af_simple_metering_cluster_println(...)
#define sl_zigbee_af_simple_metering_cluster_flush()
#define sl_zigbee_af_simple_metering_cluster_debug_exec(x)
#define sl_zigbee_af_simple_metering_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_simple_metering_cluster_print_string(buffer)

#define sl_zigbee_af_messaging_cluster_print(...)
#define sl_zigbee_af_messaging_cluster_println(...)
#define sl_zigbee_af_messaging_cluster_flush()
#define sl_zigbee_af_messaging_cluster_debug_exec(x)
#define sl_zigbee_af_messaging_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_messaging_cluster_print_string(buffer)

#define sl_zigbee_af_tunneling_cluster_print(...)
#define sl_zigbee_af_tunneling_cluster_println(...)
#define sl_zigbee_af_tunneling_cluster_flush()
#define sl_zigbee_af_tunneling_cluster_debug_exec(x)
#define sl_zigbee_af_tunneling_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_tunneling_cluster_print_string(buffer)

#define sl_zigbee_af_prepayment_cluster_print(...)
#define sl_zigbee_af_prepayment_cluster_println(...)
#define sl_zigbee_af_prepayment_cluster_flush()
#define sl_zigbee_af_prepayment_cluster_debug_exec(x)
#define sl_zigbee_af_prepayment_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_prepayment_cluster_print_string(buffer)

#define sl_zigbee_af_energy_management_cluster_print(...)
#define sl_zigbee_af_energy_management_cluster_println(...)
#define sl_zigbee_af_energy_management_cluster_flush()
#define sl_zigbee_af_energy_management_cluster_debug_exec(x)
#define sl_zigbee_af_energy_management_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_energy_management_cluster_print_string(buffer)

#define sl_zigbee_af_calendar_cluster_print(...)
#define sl_zigbee_af_calendar_cluster_println(...)
#define sl_zigbee_af_calendar_cluster_flush()
#define sl_zigbee_af_calendar_cluster_debug_exec(x)
#define sl_zigbee_af_calendar_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_calendar_cluster_print_string(buffer)

#define sl_zigbee_af_device_management_cluster_print(...)
#define sl_zigbee_af_device_management_cluster_println(...)
#define sl_zigbee_af_device_management_cluster_flush()
#define sl_zigbee_af_device_management_cluster_debug_exec(x)
#define sl_zigbee_af_device_management_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_device_management_cluster_print_string(buffer)

#define sl_zigbee_af_events_cluster_print(...)
#define sl_zigbee_af_events_cluster_println(...)
#define sl_zigbee_af_events_cluster_flush()
#define sl_zigbee_af_events_cluster_debug_exec(x)
#define sl_zigbee_af_events_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_events_cluster_print_string(buffer)

#define sl_zigbee_af_mdu_pairing_cluster_print(...)
#define sl_zigbee_af_mdu_pairing_cluster_println(...)
#define sl_zigbee_af_mdu_pairing_cluster_flush()
#define sl_zigbee_af_mdu_pairing_cluster_debug_exec(x)
#define sl_zigbee_af_mdu_pairing_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_mdu_pairing_cluster_print_string(buffer)

#define sl_zigbee_af_sub_ghz_cluster_print(...)
#define sl_zigbee_af_sub_ghz_cluster_println(...)
#define sl_zigbee_af_sub_ghz_cluster_flush()
#define sl_zigbee_af_sub_ghz_cluster_debug_exec(x)
#define sl_zigbee_af_sub_ghz_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_sub_ghz_cluster_print_string(buffer)

#define sl_zigbee_af_key_establishment_cluster_print(...)
#define sl_zigbee_af_key_establishment_cluster_println(...)
#define sl_zigbee_af_key_establishment_cluster_flush()
#define sl_zigbee_af_key_establishment_cluster_debug_exec(x)
#define sl_zigbee_af_key_establishment_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_key_establishment_cluster_print_string(buffer)

#define sl_zigbee_af_information_cluster_print(...)
#define sl_zigbee_af_information_cluster_println(...)
#define sl_zigbee_af_information_cluster_flush()
#define sl_zigbee_af_information_cluster_debug_exec(x)
#define sl_zigbee_af_information_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_information_cluster_print_string(buffer)

#define sl_zigbee_af_data_sharing_cluster_print(...)
#define sl_zigbee_af_data_sharing_cluster_println(...)
#define sl_zigbee_af_data_sharing_cluster_flush()
#define sl_zigbee_af_data_sharing_cluster_debug_exec(x)
#define sl_zigbee_af_data_sharing_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_data_sharing_cluster_print_string(buffer)

#define sl_zigbee_af_gaming_cluster_print(...)
#define sl_zigbee_af_gaming_cluster_println(...)
#define sl_zigbee_af_gaming_cluster_flush()
#define sl_zigbee_af_gaming_cluster_debug_exec(x)
#define sl_zigbee_af_gaming_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_gaming_cluster_print_string(buffer)

#define sl_zigbee_af_data_rate_control_cluster_print(...)
#define sl_zigbee_af_data_rate_control_cluster_println(...)
#define sl_zigbee_af_data_rate_control_cluster_flush()
#define sl_zigbee_af_data_rate_control_cluster_debug_exec(x)
#define sl_zigbee_af_data_rate_control_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_data_rate_control_cluster_print_string(buffer)

#define sl_zigbee_af_voice_over_zigbee_cluster_print(...)
#define sl_zigbee_af_voice_over_zigbee_cluster_println(...)
#define sl_zigbee_af_voice_over_zigbee_cluster_flush()
#define sl_zigbee_af_voice_over_zigbee_cluster_debug_exec(x)
#define sl_zigbee_af_voice_over_zigbee_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_voice_over_zigbee_cluster_print_string(buffer)

#define sl_zigbee_af_chatting_cluster_print(...)
#define sl_zigbee_af_chatting_cluster_println(...)
#define sl_zigbee_af_chatting_cluster_flush()
#define sl_zigbee_af_chatting_cluster_debug_exec(x)
#define sl_zigbee_af_chatting_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_chatting_cluster_print_string(buffer)

#define sl_zigbee_af_payment_cluster_print(...)
#define sl_zigbee_af_payment_cluster_println(...)
#define sl_zigbee_af_payment_cluster_flush()
#define sl_zigbee_af_payment_cluster_debug_exec(x)
#define sl_zigbee_af_payment_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_payment_cluster_print_string(buffer)

#define sl_zigbee_af_billing_cluster_print(...)
#define sl_zigbee_af_billing_cluster_println(...)
#define sl_zigbee_af_billing_cluster_flush()
#define sl_zigbee_af_billing_cluster_debug_exec(x)
#define sl_zigbee_af_billing_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_billing_cluster_print_string(buffer)

#define sl_zigbee_af_appliance_identification_cluster_print(...)
#define sl_zigbee_af_appliance_identification_cluster_println(...)
#define sl_zigbee_af_appliance_identification_cluster_flush()
#define sl_zigbee_af_appliance_identification_cluster_debug_exec(x)
#define sl_zigbee_af_appliance_identification_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_appliance_identification_cluster_print_string(buffer)

#define sl_zigbee_af_meter_identification_cluster_print(...)
#define sl_zigbee_af_meter_identification_cluster_println(...)
#define sl_zigbee_af_meter_identification_cluster_flush()
#define sl_zigbee_af_meter_identification_cluster_debug_exec(x)
#define sl_zigbee_af_meter_identification_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_meter_identification_cluster_print_string(buffer)

#define sl_zigbee_af_appliance_events_and_alert_cluster_print(...)
#define sl_zigbee_af_appliance_events_and_alert_cluster_println(...)
#define sl_zigbee_af_appliance_events_and_alert_cluster_flush()
#define sl_zigbee_af_appliance_events_and_alert_cluster_debug_exec(x)
#define sl_zigbee_af_appliance_events_and_alert_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_appliance_events_and_alert_cluster_print_string(buffer)

#define sl_zigbee_af_appliance_statistics_cluster_print(...)
#define sl_zigbee_af_appliance_statistics_cluster_println(...)
#define sl_zigbee_af_appliance_statistics_cluster_flush()
#define sl_zigbee_af_appliance_statistics_cluster_debug_exec(x)
#define sl_zigbee_af_appliance_statistics_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_appliance_statistics_cluster_print_string(buffer)

#define sl_zigbee_af_electrical_measurement_cluster_print(...)
#define sl_zigbee_af_electrical_measurement_cluster_println(...)
#define sl_zigbee_af_electrical_measurement_cluster_flush()
#define sl_zigbee_af_electrical_measurement_cluster_debug_exec(x)
#define sl_zigbee_af_electrical_measurement_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_electrical_measurement_cluster_print_string(buffer)

#define sl_zigbee_af_diagnostics_cluster_print(...)
#define sl_zigbee_af_diagnostics_cluster_println(...)
#define sl_zigbee_af_diagnostics_cluster_flush()
#define sl_zigbee_af_diagnostics_cluster_debug_exec(x)
#define sl_zigbee_af_diagnostics_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_diagnostics_cluster_print_string(buffer)

#define sl_zigbee_af_zll_commissioning_cluster_print(...)
#define sl_zigbee_af_zll_commissioning_cluster_println(...)
#define sl_zigbee_af_zll_commissioning_cluster_flush()
#define sl_zigbee_af_zll_commissioning_cluster_debug_exec(x)
#define sl_zigbee_af_zll_commissioning_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_zll_commissioning_cluster_print_string(buffer)

#define sl_zigbee_af_sample_mfg_specific_cluster_print(...)
#define sl_zigbee_af_sample_mfg_specific_cluster_println(...)
#define sl_zigbee_af_sample_mfg_specific_cluster_flush()
#define sl_zigbee_af_sample_mfg_specific_cluster_debug_exec(x)
#define sl_zigbee_af_sample_mfg_specific_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_sample_mfg_specific_cluster_print_string(buffer)

#define sl_zigbee_af_ota_configuration_cluster_print(...)
#define sl_zigbee_af_ota_configuration_cluster_println(...)
#define sl_zigbee_af_ota_configuration_cluster_flush()
#define sl_zigbee_af_ota_configuration_cluster_debug_exec(x)
#define sl_zigbee_af_ota_configuration_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_ota_configuration_cluster_print_string(buffer)

#define sl_zigbee_af_mfglib_cluster_print(...)
#define sl_zigbee_af_mfglib_cluster_println(...)
#define sl_zigbee_af_mfglib_cluster_flush()
#define sl_zigbee_af_mfglib_cluster_debug_exec(x)
#define sl_zigbee_af_mfglib_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_mfglib_cluster_print_string(buffer)

#define sl_zigbee_af_sl_wwah_cluster_print(...)
#define sl_zigbee_af_sl_wwah_cluster_println(...)
#define sl_zigbee_af_sl_wwah_cluster_flush()
#define sl_zigbee_af_sl_wwah_cluster_debug_exec(x)
#define sl_zigbee_af_sl_wwah_cluster_print_buffer(buffer, len, withSpace)
#define sl_zigbee_af_sl_wwah_cluster_print_string(buffer)

#endif // (defined(SL_CATALOG_ZIGBEE_DEBUG_PRINT_PRESENT) && (SL_ZIGBEE_DEBUG_ZCL_GROUP_ENABLED == 1))
