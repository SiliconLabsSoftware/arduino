/***************************************************************************//**
 * @file
 * @brief See @ref binding_table for documentation.
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

#ifndef SILABS_BINDING_TABLE_H
#define SILABS_BINDING_TABLE_H

#include "stack/include/sl_zigbee_types.h"

/**
 * @addtogroup binding_table
 * @brief EmberZNet binding table API.
 *
 * See binding-table.h for source code.
 * @{
 */

/** @brief Set an entry in the binding table by copying the structure
 * pointed to by \c value into the binding table.
 * @note You do not need to reserve memory for \c value.
 *
 * @param index  The index of a binding table entry.
 *
 * @param value  A pointer to a structure.
 *
 * @return An ::sl_status_t value that indicates the success
 * or failure of the command.
 */
sl_status_t sl_zigbee_set_binding(uint8_t index, sl_zigbee_binding_table_entry_t *value);

/** @brief Copy a binding table entry to the structure that the
 * \c result points to.
 *
 * @param index  The index of a binding table entry.
 *
 * @param result A pointer to the location to which to copy the binding
 * table entry.
 *
 * @return An ::sl_status_t value that indicates the success
 * or failure of the command.
 *
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# result #}
 */
sl_status_t sl_zigbee_get_binding(uint8_t index,
                                  sl_zigbee_binding_table_entry_t *result);

/** @brief Delete a binding table entry.
 *
 * @param index  The index of a binding table entry.
 *
 * @return An ::sl_status_t value that indicates the success
 * or failure of the command.
 */
sl_status_t sl_zigbee_delete_binding(uint8_t index);

/** @brief Indicate whether any messages are currently being sent using
 * this binding table entry.
 *
 * Note that this function does not indicate whether a binding is clear.
 * To determine whether a binding is clear, check the
 * ::sl_zigbee_binding_table_entry_t structure that defines the binding.
 * The type field should have the value ::SL_ZIGBEE_UNUSED_BINDING.
 *
 * @param index  The index of a binding table entry.
 *
 * @return True if the binding table entry is active, false otherwise.
 */
bool sl_zigbee_binding_is_active(uint8_t index);

/** @brief Return the node ID for the binding's destination if the ID
 * is known.
 *
 * If a message is sent using the binding and the destination's
 * ID is not known, the stack will discover the ID by broadcasting a ZDO
 * address request. The application can avoid the need for this discovery
 * by calling ::sl_zigbee_note_senders_binding() whenever a message arrives from
 * the binding's destination, or by calling ::sl_zigbee_set_binding_remote_node_id()
 * when it knows the correct ID via some other means, such as having saved
 * it in nonvolatile memory.
 *
 * The destination's node ID is forgotten when the binding is changed,
 * when the local node reboots
 * or, much more rarely, when the destination node changes its ID in response
 * to an ID conflict.
 *
 * @param index  The index of a binding table entry.
 *
 * @return The short ID of the destination node or ::SL_ZIGBEE_NULL_NODE_ID
 *   if no destination is known.
 */
sl_802154_short_addr_t sl_zigbee_get_binding_remote_node_id(uint8_t index);

/** @brief Set the node ID for the binding's destination.
 * See ::sl_zigbee_get_binding_remote_node_id() for a description.
 *
 * @param index  The index of a binding table entry.
 *
 * @param id     The ID of the binding's destination.
 */
void sl_zigbee_set_binding_remote_node_id(uint8_t index, sl_802154_short_addr_t id);

/** @brief Delete all binding table entries.
 *
 * @return An ::sl_status_t value that indicates the success
 * or failure of the command.
 */
sl_status_t sl_zigbee_clear_binding_table(void);

/** @brief A callback invoked when a remote node requests that
 * a binding be added to the local binding table (via the ZigBee
 * Device Object at endpoint 0).
 *
 * This handler is invoked after a decision has already been made;
 * an application wishing to make the decision itself must implement either
 * sl_zigbee_internal_remote_set_binding_handler (if not using
 * AppFramework), or ::sl_zigbee_af_remote_set_binding_permission_cb
 * if using it.  The callback making the decision runs as part of the
 * stack task context, like other callbacks with non-void return values.
 *
 * The application is free to add the
 * binding to the binding table, ignore the request, or take some other
 * action.  It is recommended that nonvolatile bindings be used for
 * remote provisioning applications.
 *
 * The binding's type defaults to ::SL_ZIGBEE_UNICAST_BINDING. The application
 * should set the type as appropriate for the binding's local endpoint and
 * cluster ID.
 *
 * If the application includes sl_zigbee_internal_remote_set_binding_handler(),
 * the privileged handler making the decision for ::sl_zigbee_remote_set_binding_handler(),
 * it must define SL_ZIGBEE_APPLICATION_HAS_REMOTE_BINDING_HANDLER in its
 * CONFIGURATION_HEADER and also include sl_zigbee_internal_remote_delete_binding_handler().
 *
 * @param entry   A pointer to a new binding table entry.
 *
 * @return ::SL_ZIGBEE_ZDP_SUCCESS if the binding was added to the table
 * ::SL_ZIGBEE_ZDP_NOT_AUTHORIZED if permission was denied or binding is active
 * ::SL_ZIGBEE_ZDP_INVALID_ENDPOINT if the endpoint is 0 or in the reserved range
 * ::SL_ZIGBEE_ZDP_TABLE_FULL if there is no more space in the binding table
 */
void sl_zigbee_remote_set_binding_handler(sl_zigbee_binding_table_entry_t *entry, sl_zigbee_zdo_status_t status);

/** @brief Invoked when a remote node requests that
 * a binding be removed from the local binding table (via the ZigBee
 * Device Object at endpoint 0).
 *
 * If the application wants to make the decision itself it must implement
 * either sl_zigbee_internal_remote_delete_binding_handler or
 * ::sl_zigbee_af_remote_delete_binding_permission_cb.
 * The application is free to remove the
 * binding from the binding table, ignore the request, or take some other
 * action.
 *
 * If the application includes sl_zigbee_internal_remote_delete_binding_handler(),
 * it must define SL_ZIGBEE_APPLICATION_HAS_REMOTE_BINDING_HANDLER in its
 * CONFIGURATION_HEADER and also include sl_zigbee_internal_remote_set_binding_handler().
 *
 * @param index  The index of the binding entry to be removed.
 *
 * @return ::SL_ZIGBEE_ZDP_SUCCESS if the binding was removed from the table
 * ::SL_ZIGBEE_ZDP_NOT_AUTHORIZED if permission was denied or binding is active
 * ::SL_STATUS_INVALID_PARAMETER if the endpoint is 0 or in the reserved range
 * ::SL_ZIGBEE_ZDP_NO_ENTRY if the binding doesn't exist
 */
void sl_zigbee_remote_delete_binding_handler(uint8_t index, sl_zigbee_zdo_status_t status);

/** @brief Create a binding table entry for the sender of a message,
 * which can be used to send messages to that sender.
 *
 * This function is identical to ::sl_zigbee_set_binding() except that
 * calling it tells the stack that this binding corresponds to the given
 * node ID (intended to be that of a message's sender ). The stack uses
 * this information to associate the sender's routing info with the binding table entry.
 *
 * @param index  The index of the binding to set.
 *
 * @param entry  A pointer to data for the binding.
 *
 * @param source Node ID of the message sender
 *
 * @return An ::sl_status_t value that indicates the success
 * or failure of the command.
 */
sl_status_t sl_zigbee_set_reply_binding(uint8_t index,
                                        sl_zigbee_binding_table_entry_t *entry,
                                        sl_802154_short_addr_t source);

/** @brief Update the routing information associated with a binding
 * table entry for the sender of a message.
 *
 * This function should be used in place of ::sl_zigbee_set_reply_binding() when a
 * message arrives from a remote endpoint for which a binding already exists.
 *
 * @param index  The index of the binding to update.
 *
 * @param source Node ID of the message's sender.
 *
 * @return An ::sl_status_t value that indicates the success
 * or failure of the command.
 */
sl_status_t sl_zigbee_note_senders_binding(uint8_t index, sl_802154_short_addr_t source);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// Set or get the binding table size
sl_status_t sl_zigbee_set_binding_table_size(uint8_t size);
uint8_t sl_zigbee_get_binding_table_size(void);

//Privileged callbacks for remote node requests to add/delete a binding.
sl_zigbee_zdo_status_t sl_zigbee_internal_remote_set_binding_handler(sl_zigbee_binding_table_entry_t *entry);
sl_zigbee_zdo_status_t sl_zigbee_internal_remote_delete_binding_handler(uint8_t index);
#endif

/** @} END addtogroup */

/**
 * <!-- HIDDEN
 * @page 2p5_to_3p0
 * <hr>
 * The file binding-table.h is new and is described in @ref binding_table.
 * <ul>
 * <li> <b>New items</b>
 * <ul>
 * <li> sl_zigbee_get_binding_remote_node_id()
 * <li> sl_zigbee_set_binding_remote_node_id()
 * </ul>
 * <li> <b>Changed items</b>
 * <ul>
 * </ul>
 * <li> <b>Items moved from sl_zigbee.h</b>
 *  - sl_zigbee_binding_is_active()
 *  - sl_zigbee_clear_binding_table()
 *  - sl_zigbee_delete_binding()
 *  - sl_zigbee_get_binding()
 *  - sl_zigbee_note_senders_binding()
 *  - sl_zigbee_remote_delete_binding_handler()
 *  - sl_zigbee_remote_set_binding_handler()
 *  - sl_zigbee_set_binding()
 *  - sl_zigbee_set_reply_binding()
 *  .
 * </ul>
 * HIDDEN -->
 */

#endif // SILABS_BINDING_TABLE_H
