/***************************************************************************//**
 * @file
 * @brief APIs and defines for the Level Control plugin, which implements the
 *        Level Control cluster.
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

#ifndef SILABS_ZIGBEE_LEVEL_CONTROL_H
#define SILABS_ZIGBEE_LEVEL_CONTROL_H

/**
 * @defgroup level-control Level Control Server
 * @ingroup component cluster
 * @brief API and Callbacks for the Level Control Cluster Server Component
 *
 * Silicon Labs implementation of the Level Control server cluster.
 * If the ZLL Level Control server cluster component is also enabled,
 * this component uses it to handle ZLL enhancements.
 * Otherwise, all ZLL extensions are disabled.
 * It is not intended for production but provides
 * sample code to show how the cluster could be implemented.
 *
 */

/**
 * @addtogroup level-control
 * @{
 */

// Rate of level control tick execution.
// To increase tick frequency (for more granular updates of device state based
// on level), redefine SL_ZIGBEE_AF_PLUGIN_LEVEL_CONTROL_TICKS_PER_SECOND.
#ifndef SL_ZIGBEE_AF_PLUGIN_LEVEL_CONTROL_TICKS_PER_SECOND
  #define SL_ZIGBEE_AF_PLUGIN_LEVEL_CONTROL_TICKS_PER_SECOND 32
#endif
#define SL_ZIGBEE_AF_PLUGIN_LEVEL_CONTROL_TICK_TIME \
  (MILLISECOND_TICKS_PER_SECOND / SL_ZIGBEE_AF_PLUGIN_LEVEL_CONTROL_TICKS_PER_SECOND)

/**
 * @name Callbacks
 * @{
 */

/**
 * @defgroup level_control_cb Level Control
 * @ingroup af_callback
 * @brief Callbacks for Level Control Component
 *
 */

/**
 * @addtogroup level_control_cb
 * @{
 */

/** @brief Level control cluster server post init.
 *
 * Following the resolution of the current level at startup for this endpoint,
 * perform any additional initialization needed, e.g., synchronize hardware
 * state.
 *
 * @param endpoint Endpoint that is being initialized  Ver.: always
 */
void sl_zigbee_af_level_control_cluster_server_post_init_cb(uint8_t endpoint);

/** @brief Level control coupled color temp change.
 *
 * Adjust color control cluster color temperature in response to a change in
 * level control cluster CurrentLevel.
 *
 * @param endpoint Endpoint that is being initialized  Ver.: always
 */
void sl_zigbee_af_level_control_coupled_color_temp_change_cb(uint8_t endpoint);

/** @} */ // end of level_control_cb
/** @} */ // end of name Callbacks
/** @} */ // end of level-control

#endif // SILABS_ZIGBEE_LEVEL_CONTROL_H
