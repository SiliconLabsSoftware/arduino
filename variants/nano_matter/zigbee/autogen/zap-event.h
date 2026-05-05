/***************************************************************************//**
 * @file  zap-event.h
 * @brief Generated file for zcl events using ZAP. Do not update file manually.
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

#ifdef SL_CATALOG_ZIGBEE_ZCL_FRAMEWORK_CORE_PRESENT
#include "app/framework/include/af.h"

#define SL_ZIGBEE_AF_GENERATED_UC_EVENTS_DEF \
sl_zigbee_af_event_t sl_zigbee_af_identify_cluster_server_tick_cbEvent1; \
sl_zigbee_af_event_t sl_zigbee_af_on_off_cluster_server_tick_cbEvent1; \
sl_zigbee_af_event_t sl_zigbee_af_level_control_cluster_server_tick_cbEvent1; \
sl_zigbee_af_event_t sl_zigbee_af_ota_bootload_cluster_client_tick_cbEvent1; \
sl_zigbee_af_event_t sl_zigbee_af_identify_cluster_server_tick_cbEvent2; \
sl_zigbee_af_event_t sl_zigbee_af_on_off_cluster_server_tick_cbEvent2; \
sl_zigbee_af_event_t sl_zigbee_af_level_control_cluster_server_tick_cbEvent2; \
sl_zigbee_af_event_t sl_zigbee_af_ota_bootload_cluster_client_tick_cbEvent2; \
sl_zigbee_af_event_t sl_zigbee_af_color_control_cluster_server_tick_cbEvent2; \


#define SL_ZIGBEE_AF_GENERATED_UC_EVENTS_INIT \
extern void sl_zigbee_af_identify_cluster_server_tick_cb(uint8_t endpoint); \
extern void sl_zigbee_af_on_off_cluster_server_tick_cb(uint8_t endpoint); \
extern void sl_zigbee_af_level_control_cluster_server_tick_cb(uint8_t endpoint); \
extern void sl_zigbee_af_ota_bootload_cluster_client_tick_cb(uint8_t endpoint); \
extern void sl_zigbee_af_color_control_cluster_server_tick_cb(uint8_t endpoint); \
sl_zigbee_af_endpoint_event_init(&sl_zigbee_af_identify_cluster_server_tick_cbEvent1, (void *)sl_zigbee_af_identify_cluster_server_tick_cb, 1); \
sl_zigbee_af_endpoint_event_init(&sl_zigbee_af_on_off_cluster_server_tick_cbEvent1, (void *)sl_zigbee_af_on_off_cluster_server_tick_cb, 1); \
sl_zigbee_af_endpoint_event_init(&sl_zigbee_af_level_control_cluster_server_tick_cbEvent1, (void *)sl_zigbee_af_level_control_cluster_server_tick_cb, 1); \
sl_zigbee_af_endpoint_event_init(&sl_zigbee_af_ota_bootload_cluster_client_tick_cbEvent1, (void *)sl_zigbee_af_ota_bootload_cluster_client_tick_cb, 1); \
sl_zigbee_af_endpoint_event_init(&sl_zigbee_af_identify_cluster_server_tick_cbEvent2, (void *)sl_zigbee_af_identify_cluster_server_tick_cb, 2); \
sl_zigbee_af_endpoint_event_init(&sl_zigbee_af_on_off_cluster_server_tick_cbEvent2, (void *)sl_zigbee_af_on_off_cluster_server_tick_cb, 2); \
sl_zigbee_af_endpoint_event_init(&sl_zigbee_af_level_control_cluster_server_tick_cbEvent2, (void *)sl_zigbee_af_level_control_cluster_server_tick_cb, 2); \
sl_zigbee_af_endpoint_event_init(&sl_zigbee_af_ota_bootload_cluster_client_tick_cbEvent2, (void *)sl_zigbee_af_ota_bootload_cluster_client_tick_cb, 2); \
sl_zigbee_af_endpoint_event_init(&sl_zigbee_af_color_control_cluster_server_tick_cbEvent2, (void *)sl_zigbee_af_color_control_cluster_server_tick_cb, 2); \

// sl_zigbee_event_context_t structs used to populate the sli_zigbee_app_event_context table
#define SL_ZIGBEE_AF_GENERATED_UC_EVENT_CONTEXT \
{ 1, 0x3, false, SL_ZIGBEE_AF_LONG_POLL, SL_ZIGBEE_AF_OK_TO_SLEEP, &sl_zigbee_af_identify_cluster_server_tick_cbEvent1 },     \
{ 1, 0x6, false, SL_ZIGBEE_AF_LONG_POLL, SL_ZIGBEE_AF_OK_TO_SLEEP, &sl_zigbee_af_on_off_cluster_server_tick_cbEvent1 },     \
{ 1, 0x8, false, SL_ZIGBEE_AF_LONG_POLL, SL_ZIGBEE_AF_OK_TO_SLEEP, &sl_zigbee_af_level_control_cluster_server_tick_cbEvent1 },     \
{ 1, 0x19, true, SL_ZIGBEE_AF_LONG_POLL, SL_ZIGBEE_AF_OK_TO_SLEEP, &sl_zigbee_af_ota_bootload_cluster_client_tick_cbEvent1 },     \
{ 2, 0x3, false, SL_ZIGBEE_AF_LONG_POLL, SL_ZIGBEE_AF_OK_TO_SLEEP, &sl_zigbee_af_identify_cluster_server_tick_cbEvent2 },     \
{ 2, 0x6, false, SL_ZIGBEE_AF_LONG_POLL, SL_ZIGBEE_AF_OK_TO_SLEEP, &sl_zigbee_af_on_off_cluster_server_tick_cbEvent2 },     \
{ 2, 0x8, false, SL_ZIGBEE_AF_LONG_POLL, SL_ZIGBEE_AF_OK_TO_SLEEP, &sl_zigbee_af_level_control_cluster_server_tick_cbEvent2 },     \
{ 2, 0x19, true, SL_ZIGBEE_AF_LONG_POLL, SL_ZIGBEE_AF_OK_TO_SLEEP, &sl_zigbee_af_ota_bootload_cluster_client_tick_cbEvent2 },     \
{ 2, 0x300, false, SL_ZIGBEE_AF_LONG_POLL, SL_ZIGBEE_AF_OK_TO_SLEEP, &sl_zigbee_af_color_control_cluster_server_tick_cbEvent2 },     \


#endif // SL_CATALOG_ZIGBEE_ZCL_FRAMEWORK_CORE_PRESENT
#define SL_ZIGBEE_AF_GENERATED_UC_EVENT_CONTEXT_COUNT 9
