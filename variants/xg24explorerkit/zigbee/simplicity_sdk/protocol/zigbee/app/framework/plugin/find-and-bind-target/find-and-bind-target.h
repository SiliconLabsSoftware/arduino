/***************************************************************************//**
 * @file
 * @brief APIs and defines for the Find and Bind Target plugin.
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

#ifndef SILABS_FIND_AND_BIND_TARGET_H
#define SILABS_FIND_AND_BIND_TARGET_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup find-and-bind-target Find and Bind Target
 * @ingroup component
 * @brief API and Callbacks for the Find and Bind Target Component
 *
 * This component provides the functionality for a target device to
 * start identifying on user-defined endpoints. The target device can
 * then act as a target for a finding and binding initiator.
 *
 */

/**
 * @addtogroup find-and-bind-target
 * @{
 */

// -----------------------------------------------------------------------------
// Constants

#define SL_ZIGBEE_AF_PLUGIN_FIND_AND_BIND_TARGET_PLUGIN_NAME "Find and Bind Target"

// -----------------------------------------------------------------------------
// API

/**
 * @name API
 * @{
 */

/** @brief Start target finding and binding operations.
 *
 * A call to this function will commence the target finding and
 * binding operations. Specifically, the target will attempt to start
 * identifying on the endpoint that is passed as a parameter.
 *
 * @param endpoint The endpoint on which to begin target operations.
 *
 * @returns An ::sl_zigbee_af_status_t value describing the success of the
 * commencement of the target operations.
 */
sl_zigbee_af_status_t sl_zigbee_af_find_and_bind_target_start(uint8_t endpoint);

/** @} */ // end of name API
/** @} */ // end of find-and-bind-target

#ifdef __cplusplus
}
#endif

#endif /* __FIND_AND_BIND_TARGET_H__ */
