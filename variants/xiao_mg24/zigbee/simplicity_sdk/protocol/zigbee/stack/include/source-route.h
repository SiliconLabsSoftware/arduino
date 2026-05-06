/***************************************************************************//**
 * @file
 * @brief Concentrator configuration and source route table management
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

#ifndef SILABS_SOURCE_ROUTE_H
#define SILABS_SOURCE_ROUTE_H

#include "stack/include/sl_zigbee_types.h"

/**
 * @addtogroup source_route
 *
 * This file provides routines pertaining to source routing. Source routing is
 * only available for routers and coordinators that have the source routing
 * library included.
 *
 * See source-route.h for more information.
 * @{
 */

/** @brief initializing the node to act as a concentrator with:
 *
 * @params discovery mode on/off
 *  concentratorTypeParam
 *  min time between MTORRs
 *  max time between MTORRs
 *  threshodl to react to route error message
 *  threshodl to react to delivery failures
 *  max number of hops for MTORR
 */
sl_status_t sl_zigbee_set_concentrator(bool on,
                                       uint16_t concentratorTypeParam,
                                       uint16_t minTime,
                                       uint16_t maxTime,
                                       uint8_t routeErrorThresholdParam,
                                       uint8_t deliveryFailureThresholdParam,
                                       uint8_t maxHopsParam);

/** @brief Return the number of used entries in the source route table.
 */
uint8_t sl_zigbee_get_source_route_table_filled_size(void);

/** @brief Return the size of the source route table.
 */
uint8_t sl_zigbee_get_source_route_table_total_size(void);

/** @brief Returns the number of bytes needed in a packet for source routing.
 * Since each hop consumes 2 bytes in the packet, this routine calculates the
 * total number of bytes needed based on number of hops to reach the destination.
 * @param destination The destination's short address.
 * @return uint8_t The number of bytes needed for source routing in a packet or
 * SL_ZIGBEE_SOURCE_ROUTE_OVERHEAD_UNKNOWN (no source route overhead).
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# return | default: SL_ZIGBEE_SOURCE_ROUTE_OVERHEAD_UNKNOWN #}
 */
uint8_t sl_zigbee_get_source_route_overhead(sl_802154_short_addr_t destination);

/** @brief Set source route discovery mode(MTORR scheduling mode)
 *   to on/off/reschedule
 *
 *  @params:  mode:
 *  SL_ZIGBEE_SOURCE_ROUTE_DISCOVERY_OFF = 0x00,
 *  SL_ZIGBEE_SOURCE_ROUTE_DISCOVERY_ON = 0x01,
 *  SL_ZIGBEE_SOURCE_ROUTE_DISCOVERY_RESCHEDULE = 0x02,
 */
uint32_t sl_zigbee_set_source_route_discovery_mode(sl_zigbee_source_route_discovery_mode_t mode);

//--------------------legacy APIs, with no direct ezsp tranlation, will be deprecated

/** @brief Legacy API  Starts periodic many-to-one route discovery.
 * Periodic discovery is started by default on bootup,
 * but this function may be used if discovery has been
 * stopped by a call to ::sl_zigbee_concentrator_stop_discovery().
 */
void sl_zigbee_concentrator_start_discovery(void);

/** @brief Legacy API. Stops periodic many-to-one route discovery. */
void sl_zigbee_concentrator_stop_discovery(void);

/** @brief Legacy API. Notes when a packet fails to deliver.
 */
void sl_zigbee_concentrator_note_delivery_failure(sl_zigbee_outgoing_message_type_t type, sl_status_t status);

/** @brief Legacy API. Notes when a route error has occurred.
 */
void sl_zigbee_concentrator_note_route_error(sl_status_t status,
                                             sl_802154_short_addr_t nodeId);

/** @brief Send a route request packet that creates routes from
 * every node in the network back to this node.
 *
 * This function should be
 * called by an application that wants to communicate with
 * many nodes, for example, a gateway, central monitor, or controller.
 * A device using this function was referred to as an "aggregator" in
 * EmberZNet 2.x and earlier, and is referred to as a "concentrator"
 * in the ZigBee specification and EmberZNet 3.
 *
 * This function enables large scale networks because the other devices
 * do not have to individually perform bandwidth-intensive route discoveries.
 * Instead, when a remote node sends an APS unicast to a concentrator, its
 * network layer automatically delivers a special route record packet first,
 * which lists the network IDs of all intermediate relays.
 * The concentrator can then use source routing to send outbound APS unicasts.
 * (A source routed message is one in which the entire route is listed in
 * the network layer header.) This allows the concentrator to communicate
 * with thousands of devices without requiring large route tables on
 * neighboring nodes.
 *
 * This function is only available in ZigBee Pro (stack profile 2),
 * and cannot be called on end devices. Any router can be a concentrator
 * (not just the coordinator), and there can be multiple concentrators on
 * a network.
 *
 * Note that a concentrator does not automatically obtain routes to all network
 * nodes after calling this function. Remote applications must first initiate
 * an inbound APS unicast.
 *
 * Many-to-one routes are not repaired automatically. Instead, the concentrator
 * application must call this function to rediscover the routes as necessary,
 * for example, upon failure of a retried APS message. This is necessary because
 * there is no scalable one-size-fits-all route repair strategy.
 * A common and recommended strategy is for the concentrator application to
 * refresh the routes by calling this function periodically.
 *
 * @param concentratorType   Must be either ::SL_ZIGBEE_HIGH_RAM_CONCENTRATOR or
 * ::SL_ZIGBEE_LOW_RAM_CONCENTRATOR. The former is used when the caller has
 * enough memory to store source routes for the whole network. In that
 * case, remote nodes stop sending route records once the concentrator has
 * successfully received one. The latter is used when the concentrator
 * has insufficient RAM to store all outbound source routes. In that
 * case, route records are sent to the concentrator prior to every inbound
 * APS unicast.
 *
 * @param radius             The maximum number of hops the route request will be
 * relayed.  A radius of zero is converted to ::SL_ZIGBEE_MAX_HOPS.
 *
 * @return ::SL_STATUS_OK if the route request was successfully submitted to
 * the transmit queue, and ::SL_STATUS_FAIL otherwise.
 */
sl_status_t sl_zigbee_send_many_to_one_route_request(uint16_t concentratorType,
                                                     uint8_t radius);

/** @brief Return the source route table entry fields.
 * @param index        The index of the source route table entry.
 * @param destination  The value of the destination field in that entry.
 * @param closerIndex  The value of the closer index entry field in that entry.
 */

sl_status_t sl_zigbee_get_source_route_table_entry(uint8_t index,
                                                   sl_802154_short_addr_t *destination,
                                                   uint8_t *closerIndex);

/** @brief To configure non trust center node to assume a concentrator type
 * of the trust center it join to, until it receive many-to-one route request
 * from the trust center. For the trust center node, concentrator type is
 * configured from the concentrator plugin.
 * The stack by default assumes trust center be a low RAM concentrator that make
 * other devices send route record to the trust center even without receiving
 * a many-to-one route request. The assumed concentrator type can be changed by
 * setting appropriate config value with sl_zigbee_set_assumed_trust_center_concentrator_type().
 */
sl_zigbee_assume_trust_center_concentrator_type_t sl_zigbee_get_assumed_trust_center_concentrator_type(void);
void sl_zigbee_set_assumed_trust_center_concentrator_type(sl_zigbee_assume_trust_center_concentrator_type_t type);

/** @} END addtogroup */

#endif // SILABS_SOURCE_ROUTE_H
