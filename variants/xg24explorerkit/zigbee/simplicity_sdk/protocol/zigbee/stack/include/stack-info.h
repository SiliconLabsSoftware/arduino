/***************************************************************************//**
 * @file
 * @brief EmberZNet API for accessing and setting stack information.
 * See @ref stack_info for documentation.
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

#ifndef SILABS_STACK_INFO_H
#define SILABS_STACK_INFO_H

#include "stack/include/sl_zigbee_types.h"
#include "lower-mac-common.h"

/**
 * @addtogroup stack_info
 *
 * See stack-info.h for source code.
 * @{
 */

/** @brief A callback invoked when the status of the stack changes.
 * If the status parameter equals ::SL_STATUS_NETWORK_UP, the
 * ::sl_zigbee_get_network_parameters()
 * function can be called to get the new network parameters. If any of the
 * parameters are stored in nonvolatile memory by the application, the
 * stored values should be updated.
 *
 * The application is free to begin messaging after it receives the
 * ::SL_STATUS_NETWORK_UP status.  However, routes discovered immediately after
 * the stack comes up may be suboptimal because the routes are based
 * on the neighbor table's information about two-way links with neighboring nodes,
 * which is obtained from periodic ZigBee Link Status messages.  It can take
 * two or three link status exchange periods (of 16 seconds each) before the
 * neighbor table has a good estimate of link quality to neighboring nodes.
 * Therefore, the application may improve the quality of initially discovered
 * routes by waiting after startup to give the neighbor table time
 * to be populated.
 *
 * @param status  Stack status. One of the following:
 * - ::SL_STATUS_NETWORK_UP
 * - ::SL_STATUS_NETWORK_DOWN
 * - ::SL_STATUS_NOT_JOINED
 * - ::SL_STATUS_ZIGBEE_MOVE_FAILED
 * - ::EMBER_CANNOT_JOIN_AS_ROUTER
 * - ::SL_STATUS_ZIGBEE_NODE_ID_CHANGED
 * - ::SL_STATUS_ZIGBEE_PAN_ID_CHANGED
 * - ::SL_STATUS_ZIGBEE_CHANNEL_CHANGED
 * - ::SL_STATUS_ZIGBEE_NETWORK_OPENED
 * - ::SL_STATUS_ZIGBEE_NETWORK_CLOSED
 * - ::SL_STATUS_NO_BEACONS
 * - ::SL_STATUS_ZIGBEE_RECEIVED_KEY_IN_THE_CLEAR
 * - ::SL_STATUS_ZIGBEE_NO_NETWORK_KEY_RECEIVED
 * - ::SL_STATUS_ZIGBEE_NO_LINK_KEY_RECEIVED
 * - ::SL_STATUS_ZIGBEE_PRECONFIGURED_KEY_REQUIRED
 */
void sl_zigbee_stack_status_handler(sl_status_t status);

/** @brief Return the current join status.
 *
 *   Returns a value indicating whether the node is joining,
 *   joined to, or leaving a network.
 *
 * @return An ::sl_zigbee_network_status_t value indicating the current join status.
 */
sl_zigbee_network_status_t sl_zigbee_network_state(void);

/** @brief Indicate whether the stack is currently up.
 *
 *   Returns true if the stack is joined to a network and
 *   ready to send and receive messages.  This reflects only the state
 *   of the local node; it does not indicate whether other nodes are
 *   able to communicate with this node.
 *
 * @return True if the stack is up, false otherwise.
 */
bool sl_zigbee_stack_is_up(void);

/** @brief Write node data to the stack token.
 *
 * @param bool Indicates whether the node type should be erased.
 *
 * @return The status of the operation and an error code if unsuccessful.
 */
sl_status_t sl_zigbee_write_node_data(bool erase);

/**
 * @brief Check when the next stack event is scheduled to run.
 * @return
 *   Returns the number of milliseconds before the next stack event is
 *   scheduled to run.
 */
uint32_t sl_zigbee_ms_to_next_stack_event(void);

/** @brief Set the power descriptor to the specified value. The power
 * descriptor is a dynamic value, therefore this function should be called
 * whenever the value changes.
 *
 * @param descriptor  The new power descriptor for the local node.
 */
sl_status_t sl_zigbee_set_power_descriptor(uint16_t descriptor);

/** @brief Gets the manufacturer code. The manufacturer code is one of
 * the fields of the node descriptor.
 *
 * @return  The manufacturer code for the local node.
 */
uint16_t sl_zigbee_get_manufacturer_code(void);

/** @brief Determine whether \c eui64 is the local node's EUI64 ID.
 *
 * @param eui64  An EUI64 ID.
 *
 * @return True if \c eui64 is the local node's ID, otherwise false.
 */
bool sl_zigbee_is_local_eui64(sl_802154_long_addr_t eui64);

/** @brief Set the maximum incoming transfer size,  maximum outgoing transfer size,
 * and descriptor capability field of the node. All these being different fields of
 * sl_zigbee_node_descriptor_info_t.
 *
 * @param sl_zigbee_node_descriptor_info_t
 *  max_incoming_transfer_size  The maximum incoming transfer size for the local node in bytes. A value of 0xFFFF means that this value is not changed.
 *  max_outgoing_transfer_size  The maximum outgoing transfer size for the local node in bytes. A value of 0xFFFF means that this value is not changed.
 *  capability The descriptor capability of the local node < 0xFF
 */
sl_status_t sl_zigbee_set_node_descriptor(sl_zigbee_node_descriptor_info_t *descriptor);

/** @brief Get the maximum incoming transfer size,  maximum outgoing transfer size,
 * and descriptor capability field of the node. All these being different fields of
 * sl_zigbee_node_descriptor_info_t.
 *
 * @param  *sl_zigbee_node_descriptor_info_t
 *  max_incoming_transfer_size  The maximum incoming transfer size for the local node in bytes.
 *  max_outgoing_transfer_size  The maximum outgoing transfer size for the local node in bytes.
 *  capability The descriptor capability of the local node < 0xFF
 * @return  status of whether the pointers were set correctly.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# descriptor #}
 */
sl_status_t sl_zigbee_get_node_descriptor(sl_zigbee_node_descriptor_info_t *descriptor);

#ifdef DOXYGEN_SHOULD_SKIP_THIS

/** @brief Return the EUI64 ID of the local node.
 *
 * @return The 64-bit ID.
 */
sl_802154_long_addr_t sl_zigbee_get_eui64(void);

/** @brief Return the 16-bit node ID of local node on the current logical
 * network.
 *
 * @return The 16-bit ID.
 */
sl_802154_short_addr_t sl_zigbee_get_node_id(void);

#else   // Doxygen ignores the following
uint8_t* sl_zigbee_get_eui64(void);
sl_802154_short_addr_t sl_zigbee_get_node_id(void);

enum {
  SL_ZIGBEE_ROUTE_ERROR_NO_ROUTE_AVAILABLE    = 0x00,
  SL_ZIGBEE_ROUTE_ERROR_TREE_LINK_FAILURE     = 0x01,
  SL_ZIGBEE_ROUTE_ERROR_NON_TREE_LINK_FAILURE = 0x02,
  SL_ZIGBEE_ROUTE_ERROR_LOW_BATTERY_LEVEL     = 0x03,
  SL_ZIGBEE_ROUTE_ERROR_NO_ROUTING_CAPACITY   = 0x04,
  SL_ZIGBEE_ROUTE_ERROR_NO_INDIRECT_CAPACITY  = 0x05,
  SL_ZIGBEE_ROUTE_ERROR_INDIRECT_TRANSACTION_EXPIRY = 0x06,
  SL_ZIGBEE_ROUTE_ERROR_TARGET_DEVICE_UNAVAILABLE = 0x07,
  SL_ZIGBEE_ROUTE_ERROR_TARGET_ADDRESS_UNALLOCATED = 0x08,
  SL_ZIGBEE_ROUTE_ERROR_PARENT_LINK_FAILURE   = 0x09,
  SL_ZIGBEE_ROUTE_ERROR_VALIDATE_ROUTE        = 0x0A,
  SL_ZIGBEE_ROUTE_ERROR_SOURCE_ROUTE_FAILURE  = 0x0B,
  SL_ZIGBEE_ROUTE_ERROR_MANY_TO_ONE_ROUTE_FAILURE = 0x0C,
  SL_ZIGBEE_ROUTE_ERROR_ADDRESS_CONFLICT      = 0x0D,
  SL_ZIGBEE_ROUTE_ERROR_VERIFY_ADDRESSES      = 0x0E,
  SL_ZIGBEE_ROUTE_ERROR_PAN_IDENTIFIER_UPDATE = 0x0F,
  ZIGBEE_NETWORK_STATUS_NETWORK_ADDRESS_UPDATE = 0x10,
  ZIGBEE_NETWORK_STATUS_BAD_FRAME_COUNTER = 0x11,
  ZIGBEE_NETWORK_STATUS_BAD_KEY_SEQUENCE_NUMBER = 0x12,
  ZIGBEE_NETWORK_STATUS_UNKNOWN_COMMAND = 0x13
};

/** @brief Set the error code that a router uses to notify
 * the message initiator about a broken route.
 *
 * @param errorCode one of the 2 error codes that the stack can handle:
 * SL_ZIGBEE_ROUTE_ERROR_NO_ROUTE_AVAILABLE(0x00) or
 * SL_ZIGBEE_ROUTE_ERROR_NON_TREE_LINK_FAILURE(0x02) .
 *
 * @return ::SL_STATUS_INVALID_PARAMETER if error code is neither
 * SL_ZIGBEE_ROUTE_ERROR_NO_ROUTE_AVAILABLE(0x00) nor
 * SL_ZIGBEE_ROUTE_ERROR_NON_TREE_LINK_FAILURE(0x02)
 *  Returns ::SL_STATUS_OK otherwise
 */
sl_status_t sl_zigbee_set_broken_route_error_code(uint8_t errorCode);

#endif

/** @brief Copy the current network parameters into the structure
 * provided by the caller.
 *
 * @param parameters  A pointer to an sl_zigbee_network_parameters_t value
 *  into which the current network parameters will be copied.
 *
 * @return An ::sl_status_t value indicating the success or
 *  failure of the command.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# node_type #}
 * {# parameters #}
 */
sl_status_t sl_zigbee_get_network_parameters(sl_zigbee_node_type_t *node_type,
                                             sl_zigbee_network_parameters_t *parameters);

/** @brief Copy the current radio parameters into the structure
 * provided by the caller.
 *
 * @param phyIndex  The index of the PHY interface for radio parameters.
 *            - For 2.4 or SubGHz only (switched) device, index will be ignored.
 *            - For simultaneous dual radio, returns radio parameters based on
 *              the provided PHY index.
 *  parameters  A pointer to an sl_zigbee_multi_phy_radio_parameters_t value
 *  into which the current radio parameters will be copied.
 *
 * @return An ::sl_status_t value indicating the success or
 *  failure of the command.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# parameters #}
 */
sl_status_t sl_zigbee_get_radio_parameters(uint8_t phyIndex,
                                           sl_zigbee_multi_phy_radio_parameters_t *parameters);

/** @brief Set the channel to use for sending and receiving messages on the
 * current logical network.
 * For a list of available radio channels, see the technical specification for
 * the RF communication module in your Developer Kit.
 *
 * Note: When using this API,
 * all devices on a network must use the same channel.
 *
 * @param channel  The desired radio channel.
 *
 * @return An ::sl_status_t value indicating the success or
 *  failure of the command.
 */
sl_status_t sl_zigbee_set_radio_channel(uint8_t channel);

/**
 * @brief Set the current logical and physical channel.
 */
sl_status_t sl_zigbee_set_logical_and_radio_channel(uint8_t channel);

/** @brief Get the radio channel to which a node is set on the current
 * logical network. The possible return values depend on the radio in use.
 * For a list of available radio channels, see the technical specification
 * for the RF communication module in your Developer Kit.
 *
 * @return The current radio channel.
 */
uint8_t sl_zigbee_get_radio_channel(void);

/** @brief Set the radio output power at which a node is to operate for the
 * current logical network. Ember radios have discrete power settings. For a
 * list of available power settings, see the technical specification for the RF
 * communication module in your Developer Kit.
 * Note that using this API on a running network
 * will directly impact the established link qualities which the neighboring nodes
 * have with the node on which it is called.  This can lead to disruption of
 * existing routes and erratic network behavior.
 * Note that, if the requested power level is not available on a given radio, this
 * function will use the next higher available power level.
 *
 * @param power  A desired radio output power, in dBm.
 *
 * @return An ::sl_status_t value indicating the success or
 *  failure of the command.  Failure indicates that the requested power level
 *  is out of range.
 */
sl_status_t sl_zigbee_set_radio_power(int8_t power);

/** @brief Get the radio output power of the current logical network at which
 * a node is operating. Ember radios have discrete power settings. For a list of
 * available power settings, see the technical specification for the RF
 * communication module in your Developer Kit.
 *
 * @return The current radio output power, in dBm.
 */
int8_t sl_zigbee_get_radio_power(void);

/** @brief Return the RAIL level handle required to make RAIL API calls. Will
 * return NULL if RAIL is not in use.
 *
 * @return A RAIL handle
 */
void *sl_zigbee_get_rail_handle(void);

/** @brief Return the local node's PAN ID of the current logical network.
 *
 * @return A PAN ID.
 */
sl_802154_pan_id_t sl_zigbee_get_pan_id(void);

/** @brief Set the configured 802.15.4 CCA mode in the radio. For a list of
 * CCA modes, please refer to RAIL documentation regarding
 * RAIL_IEEE802154_CcaMode_t.
 *
 * @param ccaMode  A RAIL_IEEE802154_CcaMode_t value
 *
 * @return SL_STATUS_OK upon success, SL_STATUS_FAIL otherwise.
 *
 * @note The default CCA mode for Zigbee is RAIL_IEEE802154_CCA_MODE_RSSI.
 *
 * @note As mentioned in the RAIL documentation, on platforms that don't support
 * different CCA modes, a call to this function will do nothing.
 */
sl_status_t sl_zigbee_set_radio_ieee802154_cca_mode(uint8_t ccaMode);

/** @brief Fetch a node's 8 byte Extended PAN identifier. If this is called
 *  when a device is not currently on a network (see ::sl_zigbee_network_state),
 *  the Extended PAN ID returned will be an invalid value.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# resultLocation | length: 16 | max: 16 #}
 */
void sl_zigbee_get_extended_pan_id(uint8_t *resultLocation);

/** @brief The application must provide a definition for this variable. */
extern const uint8_t sl_zigbee_stack_profile_id[];

/** @brief Give the endpoint information for a particular endpoint.
 */

typedef struct {
  /** An endpoint of the application on this node. */
  uint8_t endpoint;
  /** The endpoint's description. */
  sl_zigbee_endpoint_description_t const * description;
  /** Input clusters the endpoint will accept. */
  uint16_t const * inputClusterList;
  /** Output clusters the endpoint may send. */
  uint16_t const * outputClusterList;
} sl_zigbee_endpoint_t;

/** @brief The application must provide a definition for this variable. */
extern uint8_t sl_zigbee_endpoint_count;

/** @brief If sl_zigbee_endpoint_count is nonzero, the application must
 * provide descriptions for each endpoint.
 *
 * This can be done either
 * by providing a definition of sl_zigbee_endpoints or by providing definitions
 * of ::sl_zigbee_get_endpoint(), ::sl_zigbee_get_endpoint_description() and
 * ::sl_zigbee_get_endpoint_cluster().  Using the array is often simpler, but consumes
 * large amounts of memory if sl_zigbee_endpoint_count is large.
 *
 * If the application provides definitions for the three functions, it must
 * define SL_ZIGBEE_APPLICATION_HAS_GET_ENDPOINT in its
 * CONFIGURATION_HEADER.
 */
extern sl_zigbee_endpoint_t sl_zigbee_endpoints[];

/** @brief Retrieve the endpoint number for
 * the index'th endpoint.  <code> index </code> must be less than
 * the value of sl_zigbee_endpoint_count.
 *
 * This function is provided by the stack, using the data from
 * sl_zigbee_endpoints, unless the application defines
 * SL_ZIGBEE_APPLICATION_HAS_GET_ENDPOINT in its CONFIGURATION_HEADER.
 *
 * @param index  The index of an endpoint (as distinct from its endpoint
 * number).  This must be less than the value of sl_zigbee_endpoint_count.
 *
 * @return The endpoint number for the index'th endpoint.
 */
uint8_t sl_zigbee_get_endpoint(uint8_t index);

/** @brief Retrieve the number of configured endpoints.
 *
 * the value of sl_zigbee_endpoint_count.
 *
 * This function return the number of configured endpoints on SoC,
 * or the number of configured endpoints on Host + on NCP.
 *
 * @return The number of configured endpoint.
 */
uint8_t sl_zigbee_get_endpoint_count(void);

/** @brief Retrieve the endpoint description for the
 * given endpoint.
 *
 * This function is provided by the stack, using the data from
 * sl_zigbee_endpoints, unless the application defines
 * ::SL_ZIGBEE_APPLICATION_HAS_GET_ENDPOINT in its ::CONFIGURATION_HEADER.
 *
 * @param endpoint  The endpoint whose description is to be returned.
 *
 * @param result    A pointer to the location to which to copy the endpoint
 *    description.
 *
 * @return True if the description was copied to result, or false if the
 * endpoint is not active.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# result #}
 */
bool sl_zigbee_get_endpoint_description(uint8_t endpoint,
                                        sl_zigbee_endpoint_description_t *result);

/** @brief Retrieve a cluster ID from one of the cluster lists associated
 * with the given endpoint.
 *
 * This function is provided by the stack, using the data from
 * sl_zigbee_endpoints, unless the application defines
 * ::SL_ZIGBEE_APPLICATION_HAS_GET_ENDPOINT in its CONFIGURATION_HEADER.
 *
 * @param endpoint   The endpoint from which the cluster ID is to be read.
 *
 * @param listId     The list from which the cluster ID is to be read.
 *
 * @param listIndex  The index of the desired cluster ID in the list. This value
 * must be less than the length of the list. The length can be found in the
 * sl_zigbee_endpoint_description_t for this endpoint.
 *
 * @return The cluster ID at position listIndex in the specified endpoint
 * cluster list.
 */
uint16_t sl_zigbee_get_endpoint_cluster(uint8_t endpoint,
                                        sl_zigbee_cluster_list_id_t listId,
                                        uint8_t listIndex);

/** @brief Determine whether \c nodeId is valid.
 *
 * @param nodeId  A node ID.
 *
 * @return True if \c nodeId is valid, false otherwise.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
bool sl_zigbee_is_node_id_valid(sl_802154_short_addr_t nodeId);
#else
#define sl_zigbee_is_node_id_valid(nodeId) ((nodeId) < SL_ZIGBEE_DISCOVERY_ACTIVE_NODE_ID)
#endif

/** @brief Return the node ID that corresponds to the specified EUI64.
 * The node ID is found by searching through all stack tables for the specified
 * EUI64.
 *
 * @param eui64  The EUI64 of the node to look up.
 *
 * @param The short ID of the node or ::SL_ZIGBEE_NULL_NODE_ID if the short ID
 * is not known.
 *
 * @return An ::sl_status_t value:\n\n
 * - ::SL_STATUS_OK - short ID Return has been set to the short ID of the node; An error code otherwise.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# node_id #}
 */
sl_status_t sl_zigbee_lookup_node_id_by_eui64(sl_802154_long_addr_t eui64,
                                              sl_802154_short_addr_t *node_id);

/** @brief Return the EUI64 that corresponds to the specified node ID.
 * The EUI64 is found by searching through all stack tables for the specified
 * node ID.
 *
 * @param nodeId       The short ID of the node to look up.
 *
 * @param eui64Return  The EUI64 of the node is copied here if it is known.
 *
 * @return An ::sl_status_t value:\n\n
 * - ::SL_STATUS_OK - eui64Return has been set to the EUI64 of the node.
 * - ::SL_STATUS_FAIL - The EUI64 of the node is not known.
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# eui64Return #}
 */
sl_status_t sl_zigbee_lookup_eui64_by_node_id(sl_802154_short_addr_t nodeId,
                                              sl_802154_long_addr_t eui64Return);

/**
 * @brief Read and clear Zigbee stack counters.
 *
 * This function reads and clears the specified Zigbee stack counters. The counter values are stored in the provided
 * counter_array, which should have a length of len. The maximum number of counters that can be read is defined by
 * SL_ZIGBEE_COUNTER_TYPE_COUNT.
 *
 * @param counter_array Pointer to an array where the counter values will be stored.
 * @param len The length of the counter_array.
 *
 * @note This function is used to retrieve the current values of Zigbee stack counters and clear them to zero.
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# counter_array | length: len | max: SL_ZIGBEE_COUNTER_TYPE_COUNT #}
 */
void sl_zigbee_read_and_clear_counters(uint16_t *counter_array, uint8_t len);

/**
 * @brief Retrieves Zigbee stack counters.
 *
 * This function retrieves the values of the specified Zigbee stack counters. The counter values are stored in the provided
 * counter_array, which should have a length of len. The maximum number of counters that can be read is defined by
 * SL_ZIGBEE_COUNTER_TYPE_COUNT.
 *
 * @param counter_array Pointer to an array where the counter values will be stored.
 * @param len The length of the counter_array.
 *
 * @note This function is used to retrieve the current values of Zigbee stack counters without clearing them.
 * @return A list of all counter values ordered according to the sl_zigbee_counter_type_t enumeration.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# counter_array | length: len | max: SL_ZIGBEE_COUNTER_TYPE_COUNT #}
 */
void sl_zigbee_read_counters(uint16_t *counter_array, uint8_t len);

/**
 * @brief Clear all Zigbee stack counters.
 *
 * @return Status code indicating the success or failure of the operation.
 */
sl_status_t sl_zigbee_clear_counters(void);

/**
 * @brief Reset all Zigbee stack counter thresholds to their default values.
 *
 * @return Status code indicating the success or failure of the operation.
 */
sl_status_t sl_zigbee_reset_counters_thresholds(void);

/**
 * @brief Set the threshold value for a specific Zigbee stack counter.
 *
 * @param type The type of the counter.
 * @param threshold The threshold value to set.
 * @return Status code indicating the success or failure of the operation.
 */
sl_status_t sl_zigbee_set_counter_threshold(sl_zigbee_counter_type_t type, uint16_t threshold);

/**
 * @brief Checks if a specific Zigbee stack counter requires a PHY index.
 *
 * @param type The type of the counter.
 * @return True if the counter requires a PHY index, false otherwise.
 */
bool sl_zigbee_counter_requires_phy_index(sl_zigbee_counter_type_t type);

/**
 * @brief Check if a specific Zigbee stack counter requires a destination node ID.
 *
 * @param type The type of the counter.
 * @return True if the counter requires a destination node ID, false otherwise.
 */
bool sl_zigbee_counter_requires_destination_node_id(sl_zigbee_counter_type_t type);

/** @brief A callback invoked to inform the application that a stack token has
 * changed.
 *
 * @param tokenAddress  The address of the stack token that has changed.
 */
void sl_zigbee_stack_token_changed_handler(uint16_t tokenAddress);

#ifndef ZNET_HEADER_SCRIPT
/** @brief A callback to request the application to wake up the stack task.
 */
void sl_zigbee_rtos_stack_wakeup_isr_handler(void);
#endif

/** @brief Copy a neighbor table entry to the structure that
 * \c result points to.  Neighbor table entries are stored in
 * ascending order by node ID, with all unused entries at the end
 * of the table.  The number of active neighbors can be obtained
 * using ::sl_zigbee_neighbor_count().
 *
 * @param index   The index of a neighbor table entry.
 *
 * @param result  A pointer to the location to which to copy the neighbor
 * table entry.
 *
 * @return ::SL_STATUS_FAIL if the index is greater or equal to the
 * number of active neighbors, or if the device is an end device.
 * Returns ::SL_STATUS_OK otherwise.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# result #}
 */
sl_status_t sl_zigbee_get_neighbor(uint8_t index,
                                   sl_zigbee_neighbor_table_entry_t *result);

/** @brief Set the routing shortcut threshold to directly use a neighbor instead of
 * performing routing.
 *
 * @param costThresh the routing shortcut value that should be used to directly use a neighbor
 * instead of performing routing.
 *
 * @return ::return SL_STATUS_INVALID_PARAMETER if the costThresh is not 1, 3, 5, 7
 * Returns ::SL_STATUS_OK otherwise.
 */
sl_status_t sl_zigbee_set_routing_shortcut_threshold(uint8_t costThresh);

/** @brief Get the routing shortcut threshold used to separate between directly using a neighbor
 * vs. performing routing.
 *
 * @return the routingShortcutThresh which takes one of the following values: 1, 3, 5, or 7.
 *
 */
uint8_t sl_zigbee_get_routing_shortcut_threshold(void);

/** @brief Set neighbor's initial outgoing link cost
 *  @param cost The new default cost.
 *
 *  @return ::SL_STATUS_INVALID_PARAMETER if the cost is not any of 0, 1, 3, 5, or 7.
 *  Returns ::SL_STATUS_OK otherwise
 *  NOTE: There is no EZSP version of this function yet.
 */
sl_status_t sl_zigbee_set_initial_neighbor_outgoing_cost(uint8_t cost);

/** @brief Get neighbor's initial outgoing link cost.
 *
 *  @return The default cost associated with new neighbor's outgoing links.
 *  NOTE: There is no EZSP version of this function yet.
 */
uint8_t sl_zigbee_get_initial_neighbor_outgoing_cost(void);

/** @brief Indicate whether a rejoining neighbor's incoming FC should be reset.
 *  @param reset True or False.
 *
 *  @return ::void
 *  NOTE: There is no EZSP version of this function yet.
 */
void sl_zigbee_reset_rejoining_neighbors_frame_counter(bool reset);

/** @brief Check whether resetting the incoming FC for a rejoining neighbor is enabled.
 *  @param void
 *
 *  @return ::True or False.
 *  NOTE: There is no EZSP version of this function yet.
 */
bool sl_zigbee_is_reset_rejoining_neighbors_frame_counter_enabled(void);

/** @brief Get the last received frame counter as found in the
 *   Network Auxiliary header for the specified neighbor or child.
 *  @param nodeEui64  The neighbor or child EUI to search.
 *  @param returnFrameCounter  The frame counter variable to fill in.
 *
 *  @return sl_status_t depending on whether the frame counter is found in the
 *   neighbor or child table.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# returnFrameCounter #}
 */
sl_status_t sl_zigbee_get_neighbor_frame_counter(sl_802154_long_addr_t nodeEui64,
                                                 uint32_t *returnFrameCounter);

/** @brief Set the frame counter for the specified neighbor or child.
 *  @param nodeEui64  The neighbor or child EUI to search.
 *  @param frameCounter  The frame counter to set.
 *
 *  @return sl_status_t depending on whether the frame counter is set in the
 *   neighbor or child table.
 */
sl_status_t sl_zigbee_set_neighbor_frame_counter(sl_802154_long_addr_t nodeEui64,
                                                 uint32_t frameCounter);

/** @brief Copy a route table entry to the structure that the
 * \c result points to. Unused route table entries have a destination
 * of 0xFFFF.  The route table size
 * can be obtained via ::sl_zigbee_get_route_table_size().
 *
 * @param index   The index of a route table entry.
 *
 * @param result  A pointer to the location to which to copy the route
 * table entry.
 *
 * @return ::SL_STATUS_FAIL if the index is out of range or the device
 * is an end device, and ::SL_STATUS_OK otherwise.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# result #}
 */
sl_status_t sl_zigbee_get_route_table_entry(uint8_t index, sl_zigbee_route_table_entry_t *result);

/** @brief Return the stack profile of the network which the
 * node has joined.
 *
 * @return  The stack profile.
 */
uint8_t sl_zigbee_stack_profile(void);

/** @brief Return the security level of the network which the
 * node has joined.
 *
 * @return  The security level.
 */
uint8_t sl_zigbee_security_level(void);

/// named constants for supported stack revisions

#define R21_COMPLIANCE_REVISION       21
#define R22_COMPLIANCE_REVISION       22
#define R23_COMPLIANCE_REVISION       23
#define PRE_R21_COMPLIANCE_REVISION   0

/**
 * @brief return the value of the stack compliance revision,
 *        as is reflected in the node descriptor
 * @return integer value of the compliance revision
 */
uint8_t sl_zigbee_get_stack_compliance_revision(void);

/** @brief Return the number of active entries in the neighbor table.
 *
 * @return The number of active entries in the neighbor table.
 */
uint8_t sl_zigbee_neighbor_count(void);

/** @brief Return the size of the route table.
 *
 * @return The size of the route table.
 */
uint8_t sl_zigbee_get_route_table_size(void);

/** @brief Sets the size of the route table.
 *
 * @param size The size of the route table.
 */
void sl_zigbee_set_route_table_size(uint8_t size);

/** @brief Return the size of the source route table.
 *
 * @return The size of the source route table.
 */
uint8_t sl_zigbee_get_source_route_table_size(void);

/** @brief Sets the size of the source route table.
 *
 * @param size The size of the source route table.
 */
void sl_zigbee_set_source_route_table_size(uint8_t size);

/** @brief Set the stack profile of the network.
 *
 * @param ::SL_ZIGBEE_STACK_PROFILE_NONE or
 * ::SL_ZIGBEE_STACK_PROFILE_ZIGBEE_PRO.
 *
 */
void sl_zigbee_set_stack_profile(uint8_t stackProfile);

/** @brief Set the security level of the network.
 *
 * @param ::SL_ZIGBEE_SECURITY_LEVEL_NONE or
 * ::SL_ZIGBEE_SECURITY_LEVEL_Z3.
 */
void sl_zigbee_set_security_level(uint8_t securityLevel);

/** @brief Increment and returns the Zigbee sequence number.
 *
 * @return The next Zigbee sequence number.
 */
uint8_t sl_zigbee_next_zigbee_sequence_number(void);

/**@brief Get maximum number of NWK retries.
 *
 * Returns the maximum number of NWK retries that will be attempted
 *
 * @return uint8_t Max NWK retries
 */
uint8_t sl_zigbee_get_max_nwk_retries(void);

/** @name Radio-specific Functions*/
//@{

/** @brief Enable boost power mode and/or the alternate transmit path.
 *
 * Boost power mode is a high-performance radio mode,
 * which offers increased transmit power and receive sensitivity at the cost of
 * an increase in power consumption. ::sl_zigbee_init() calls this
 * function using the power mode and transmitter output settings as specified
 * in the MFG_PHY_CONFIG token (with each bit inverted so that the default
 * token value of 0xffff corresponds to normal power mode and bi-directional RF
 * transmitter output). The application only needs to call
 * ::sl_802154_set_tx_power_mode() to use a power mode or transmitter output
 * setting different than specified in the MFG_PHY_CONFIG token.
 * After the initial call to ::sl_802154_set_tx_power_mode(), the stack
 * will automatically maintain the specified power mode configuration across
 * sleep/wake cycles.
 *
 * @param txPowerMode Specifies which transmit power mode options should
 * be activated. This parameter should be set to one of the literal values
 * described in stack/include/sl_zigbee_types.h. Any power option not specified
 * in the txPowerMode parameter will be deactivated.
 *
 * @return ::SL_STATUS_OK if successful; an error code otherwise.
 */
sl_status_t sl_802154_set_tx_power_mode(uint16_t txPowerMode);

/** @brief Return the current configuration of boost power mode and alternate
 * transmitter output.
 *
 * @return The current TX power mode.
 */
uint16_t sl_802154_get_tx_power_mode(void);

/** @brief Set the short node ID of the node. Notice that it can
 * only be set if the stack is in the INITAL state.
 *
 * @param nodeId Specifies the short ID to be assigned to the node.
 *
 * @return ::SL_STATUS_OK if successful; an error code otherwise.
 */
sl_status_t sl_zigbee_set_node_id(sl_802154_short_addr_t nodeId);

/** @brief Return the number of PHY interfaces present.
 *
 * @return The number of PHY interface(s).
 */
uint8_t sl_zigbee_get_phy_interface_count(void);

/** @brief The radio calibration callback function.
 *
 * The Voltage Controlled Oscillator (VCO) can drift with
 * temperature changes. During every call to ::sl_zigbee_tick(), the stack will
 * check to see if the VCO has drifted. If the VCO has drifted, the stack
 * will call ::sl_zigbee_radio_needs_calibrating_handler() to inform the application
 * that it should perform calibration of the current channel as soon as
 * possible. Calibration can take up to 150 ms. The default callback function
 * implementation provided here performs the calibration immediately. The
 * application can define its own callback by defining
 * ::EMBER_APPLICATION_HAS_CUSTOM_RADIO_CALIBRATION_CALLBACK in its
 * CONFIGURATION_HEADER. It can then failsafe any critical processes or
 * peripherals before calling ::sl_802154_calibrate_current_channel(). The
 * application must call ::sl_802154_calibrate_current_channel() in
 * response to this callback to maintain expected radio performance.
 */
void sl_zigbee_radio_needs_calibrating_handler(void);

/** @brief Calibrate the current channel. The stack will notify the
 * application of the need for channel calibration via the
 * ::sl_zigbee_radio_needs_calibrating_handler() callback function during
 * ::sl_zigbee_tick().  This function should only be called from within the context
 * of the ::sl_zigbee_radio_needs_calibrating_handler() callback function. Calibration
 * can take up to 150 ms. Note if this function is called when the radio is
 * off, it will turn the radio on and leave it on.
 */
void sl_mac_calibrate_current_channel(void);

/**
 * @brief Get the current scheduler priorities used for Zigbee
 * radio operations.
 * @param priorities A pointer to a structure to store the current priorities
 * in. This must not be NULL.
 * @return ::SL_STATUS_OK if called in a multiprotocol app and
 * ::SL_STATUS_INVALID_STATE otherwise.
 *
 * For more details on what these priorities are and how to use them see UG305,
 * the Dynamic Multiprotocol User Guide.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# priorities #}
 */
sl_status_t sl_802154_radio_get_scheduler_priorities(sl_802154_radio_priorities_t *priorities);

/**
 * @brief Set the current scheduler priorities used for Zigbee
 * multiprotocol operations.
 * @param priorities A pointer to a structure of the new priorities to use. This
 * must not be NULL.
 * @return ::SL_STATUS_OK if called in a multiprotocol app and
 * ::SL_STATUS_INVALID_STATE otherwise.
 *
 * For more details on what these priorities are and how to use them see UG305,
 * the Dynamic Multiprotocol User Guide.
 */
sl_status_t sl_802154_radio_set_scheduler_priorities(const sl_802154_radio_priorities_t *priorities);

/**
 * @brief Set the multiprotocol slip time.
 * @param slipTime The value to set the slip time to for each transmit.
 * @return ::SL_STATUS_OK if called in a multiprotocol app and
 * ::SL_STATUS_INVALID_STATE otherwise.
 *
 * Use this to update the slip time passed to the radio scheduler for each
 * transmit from the PHY layer. The smaller this is set the lower the potential
 * multi-protocol induced latency is, but it makes packets more likely to fail
 * to be transmitted. For more details on slip time see UG305.
 */
sl_status_t sl_802154_radio_set_scheduler_sliptime(uint32_t slipTime);

/**
 * @brief Get the multiprotocol slip time.
 * @param slipTime A pointer to the place to store the current slip time
 * @return ::SL_STATUS_OK if called in a multiprotocol app and
 * ::SL_STATUS_INVALID_STATE otherwise.
 *
 * Use this to get the current value of the multiprotocol slip time used for
 * each transmit at the PHY layer. For more details on slip time see UG305.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# slipTime #}
 */
sl_status_t sl_802154_radio_get_scheduler_sliptime(uint32_t *slipTime);
//@}//END Radio-specific functions

/**
 * @brief Set the route record policy.
 * @param slipTime A pointer to the place to store the current slip time
 * @return ::SL_STATUS_OK if route record policy was successfully set
 * ::SL_STATUS_INVALID_PARAMETER otherwise.
 *
 * Use this to set the policy for sending a route record message to a concentrator
 * Note that policies other than the default ROUTE_RECORD_POLICY_ACK_BY_SOURCE_ROUTED_MESSAGE
 * may result in behavior not compliant with the Zigbee specification
 */
sl_status_t slx_zigbee_routing_set_route_record_policy(sl_zigbee_route_record_policy_type_t policy);

/**
 * @brief Get the route record policy.
 * @return The route record policy
 *
 * Use this to get the current value of the route record policy
 */
uint8_t slx_zigbee_routing_get_route_record_policy(void);

/**
 * @brief Get the total count of the tokens configured.
 * @return The token count.
 *
 * Use this to get the number of tokens configured in a node.
 */
uint8_t sl_zigbee_get_token_count(void);

/**
 * @brief Get information of a token by providing the index.
 * @param index An index to configured token array that ranges from 0 to sl_zigbee_get_token_count() - 1;
 * @param tokenInfo A pointer to hold the information in a structure provided by the caller.
 * @return Status of the call, SL_STATUS_OK upon success or SL_STATUS_INVALID_INDEX for bad index.
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# tokenInfo #}
 */
sl_status_t sl_zigbee_get_token_info(uint8_t index,
                                     sl_zigbee_token_info_t *tokenInfo);
/**
 * @brief Get token data by providing the token key and index for the indexed token.
 * @param token A valid token key, which may be obtained using sl_zigbee_get_token_info.
 * @param index An index in case the token is an indexed token, if token is indexed can be obtained
 *              from sl_zigbee_get_token_info.
 * @param tokenData A pointer pointing to memory storage information, must be allocated and provided by the caller.
 * @return Status of the call, SL_STATUS_OK upon success or SL_STATUS_FAIL for errors.
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# tokenData #}
 */
sl_status_t sl_zigbee_get_token_data(uint32_t token,
                                     uint32_t index,
                                     sl_zigbee_token_data_t *tokenData);
/**
 * @brief Set token data by providing the token key, index for an indexed token and token data.
 * @param token A valid token key, which may be obtained using sl_zigbee_get_token_info.
 * @param index An index in case the token is an indexed token, if token is indexed can be obtained
 *              from sl_zigbee_get_token_info.
 * @param tokenData A pointer pointing to memory storage holding the token data provided by the caller.
 * @return Status of the call, SL_STATUS_OK upon success or SL_STATUS_FAIL for errors.
 *
 */
sl_status_t sl_zigbee_set_token_data(uint32_t token,
                                     uint32_t index,
                                     sl_zigbee_token_data_t *tokenData);

/**
 * @brief Callback to allow the user configuration of a Multi-MAC end device to update
 * channel mask for the scenario where a rejoin is initiated due to end device
 * timeout event. Based on the Multi-MAC end device configuration this call is expected to update
 * the mask so that the rejoin interface will be selected. As per the SE 1.4 errata, the
 * "Multi-MAC Selection" end device can change the rejoin interface where as the Multi-MAC Joining
 * end devices shall not.
 * This callback may be run in either the stack or application task context depending on where it
 * was called from, so implementations of this should make only thread-safe calls.
 * @param rejoinChannelMask Initial 32-bit channel mask to be used.
 * @return The 32-bit channel mask to be used based on user input.
 *
 */
uint32_t sl_zigbee_internal_update_multi_mac_rejoin_channel_mask_for_selection_or_joining_device_handler(uint32_t rejoinChannelMask);

/**
 * @brief Factory reset all configured zigbee tokens
 * @param exclude_outgoing_fc Exclude network and APS outgoing frame counter tokens
 * @param exclude_boot_counter Exclude stack boot counter token
 *
 */
void sl_zigbee_token_factory_reset(bool exclude_outgoing_fc, bool exclude_boot_counter);

/**
 * @brief Set lower MAC CCA threshold
 * @param threshold new CCA threshold
 *
 */
void sl_mac_set_cca_threshold(int8_t threshold);

/**
 * @brief Get lower MAC ED CCA threshold
 * @return ED CCA threshold
 *
 */
int8_t sl_mac_get_ed_cca_threshold(void);

/**
 * @brief Set lower MAC CSMA config
 * @param csma_param new CSMA config
 *
 */
void sl_mac_set_csma_params(sl_mac_csma_parameters_t *csma_params);

/**
 * @brief Get lower MAC CSMA param
 * @param csma_params a pointer pointing to memory storage information, must be allocated and provided by the caller.
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# csma_params #}
 */
void sl_mac_get_csma_params(sl_mac_csma_parameters_t *csma_params);

/** @} END addtogroup */

#endif // SILABS_STACK_INFO_H
