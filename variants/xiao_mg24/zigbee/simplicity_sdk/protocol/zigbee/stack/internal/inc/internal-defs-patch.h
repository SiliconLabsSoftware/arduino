/***************************************************************************//**
 * @file
 * @brief The master include file for the EmberZNet API.
 *
 *  See @ref ember for documentation.
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

/**
 * @addtogroup ember EmberZNet Stack API Reference
 * This documentation describes the application programming interface (API)
 * for the EmberZNet stack.
 * The file ember-internal-def.h is the master include file for the EmberZNet API modules.
 */

#ifndef SILABS_INTERNAL_DEFS_H
#define SILABS_INTERNAL_DEFS_H

#ifndef SL_ZIGBEE_TEST
#define EVENT_NAME(x) ""
#else
#define EVENT_NAME(x) x
#endif

//For conditionalizing header includes
#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif

#include "stack/include/sl_zigbee_types.h"
#include "stack-info-internal-def.h"
#include "network-formation-internal-def.h"
#include "message_internal_def.h"
#include "child_internal_def.h"
#include "security_internal_def.h"
#include "aes-mmo-internal-def.h"
#include "binding-table-internal-def.h"
#include "bootload_internal_def.h"
#include "zigbee-device-stack-internal-def.h"
#include "library_internal_def.h"
#if !defined(SL_COMPONENT_CATALOG_PRESENT) || defined(SL_CATALOG_ZIGBEE_LIGHT_LINK_PRESENT)
#include "zll-api-internal-def.h"
#endif
#include "multi-phy-internal-def.h"
#include "sl_zigbee_duty_cycle_internal_def.h"
#include "mac-layer-internal-def.h"
#include "sl_zigbee_random_api_internal_def.h"
#if !defined(SL_COMPONENT_CATALOG_PRESENT) || defined(SL_CATALOG_ZIGBEE_PRO_STACK_ALT_MAC_PRESENT)
#include "sl_zigbee_alternate_mac_internal_def.h"
#endif
#include "raw-message-internal-def.h"
#include "multi-network-internal-def.h"
//#include "sl_zigbee_zdo_dlk_negotiation_internal_def.h"
#if !defined(SL_COMPONENT_CATALOG_PRESENT) || defined(SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT)
#include "sl_zigbee_stack_specific_tlv_internal_def.h"
#endif
#include "sl_zigbee_address_info_internal_def.h"
//#include "sl_zigbee_security_manager_dlk_ecc_internal_def.h"
//#include "sl_zigbee_dlk_negotiation_internal_def.h"
#if !defined(SL_COMPONENT_CATALOG_PRESENT) || defined(SL_CATALOG_ZIGBEE_R23_SUPPORT_PRESENT)
#include "sl_zigbee_zdo_security_internal_def.h"
#endif
#include "zigbee-security-manager-internal-def.h"
#if !defined (SL_COMPONENT_CATALOG_PRESENT) || defined(SL_CATALOG_ZIGBEE_SOURCE_ROUTE_PRESENT)
#include "source-route-internal-def.h"
#endif
#include "trust-center-internal-def.h"
#if !defined (SL_COMPONENT_CATALOG_PRESENT) || defined(SL_CATALOG_ZIGBEE_CBKE_CORE_PRESENT)
#include "cbke-crypto-engine-internal-def.h"
#endif
#if !defined (SL_COMPONENT_CATALOG_PRESENT) || defined(SL_CATALOG_ZIGBEE_GREEN_POWER_PRESENT)
#include "gp-types-internal-def.h"
#include "gp-sink-table-internal-def.h"
#include "gp-proxy-table-internal-def.h"
#endif
#include "internal-callbacks-patch.h"

#define sli_zigbee_stack_is_node_id_valid(nodeId) ((nodeId) < SL_ZIGBEE_DISCOVERY_ACTIVE_NODE_ID)
#define sli_zigbee_stack_max_child_count()       sli_zigbee_stack_get_max_end_device_children()
#define sli_zigbee_stack_sec_man_aes_ccm(nonce, encrypt, input, encryption_start_index, length, output) \
  sli_zigbee_stack_sec_man_aes_ccm_extended(nonce, encrypt, input, encryption_start_index, length, 4, output)

//ezsp-regen can't factor out these
#define sli_zigbee_stack_router_child_count()    0
#define sli_zigbee_stack_max_router_child_count() 0
#define sli_zigbee_stack_ok_to_long_poll() (!sli_zigbee_stack_pending_acked_messages())

#define sli_zigbee_stack_ok_to_nap() \
  (!(sli_zigbee_stack_current_stack_tasks() & SL_ZIGBEE_HIGH_PRIORITY_TASKS))
#define sli_zigbee_stack_ok_to_hibernate() (!sli_zigbee_stack_current_stack_tasks())

#define sli_zigbee_stack_initialize_network_parameters(parameters) \
  (memset(parameters, 0, sizeof(sl_zigbee_network_parameters_t)))

/** @name PHY Information
 * Bit masks for TOKEN_MFG_RADIO_BANDS_SUPPORTED.
 */
//@{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define RADIO_BANDS_SUPPORTED_868   BIT(0)
#define RADIO_BANDS_SUPPORTED_915   BIT(1)
#define RADIO_BANDS_SUPPORTED_433   BIT(2)
#endif // DOXYGEN_SHOULD_SKIP_THIS

/** @brief 2.4 GHz band */
#define RADIO_BANDS_SUPPORTED_2400  BIT(3)

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define RADIO_BANDS_SUPPORTED_408   BIT(4)
#endif // DOXYGEN_SHOULD_SKIP_THIS

//@} //END PHY INFO

#ifndef DOXYGEN_SHOULD_SKIP_THIS

//@} //END STACK BUILD CONFIG SETTINGS

#ifdef DEBUG_ASSERT
extern bool enableFailure;
extern uint8_t rateOfFailure;
extern uint8_t failuresInARow;
static uint8_t bufferFailure;
bool generateFailure(void);
void dumpFailure(void);
#endif

#endif //DOXYGEN_SHOULD_SKIP_THIS

/**
 * <!-- HIDDEN
 * @page 2p5_to_3p0
 * <hr>
 * Many functions have been moved from ember-internal-def.h to the following files:
 * - binding-table-internal-def.h
 * - bootload-internal-def.h
 * - child-internal-def.h
 * - network-formation-internal-def.h
 * - stack-info-internal-def.h
 * - trust-center-internal-def.h
 *
 * Changes include:
 * <ul>
 * <li> <b>New items</b>
 * <li> <b>Changed items</b>
 *   - sl_zigbee_join_network()
 *   .
 * <li> <b>Removed items</b>
 *   - emberCloseConnection()
 *   - emberConnectionStatus()
 *   - emberConnectionStatusHandler()
 *   - emberCreateAggregationRoutes()
 *   - emberGetBindingDestinationNodeId()
 *   - emberGetCachedDescription()
 *   - emberIncomingRawMessageHandler()
 *   - emberIncomingSpdoMessageHandler()
 *   - emberMaximumTransportPayloadLength()
 *   - emberMobileNodeHasMoved()
 *   - emberOpenConnection()
 *   - emberSendDatagram() - now use ::sl_zigbee_send_unicast().
 *   - emberSendDiscoveryInformationToParent()
 *   - emberSendLimitedMulticast()
 *   - emberSendSequenced()
 *   - emberSendSpdoDatagramToParent()
 *   - emberSetBindingDestinationNodeId()
 *   - emberSetEncryptionKey()
 *   - emberSpdoUnicastSent()
 *   - emberUnicastSent()
 *   .
 * </ul>
 * HIDDEN -->
 */

#endif // SILABS_INTERNAL_DEFS_H
