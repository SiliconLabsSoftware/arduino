/***************************************************************************//**
 * @file
 * @brief EmberZNet API for multi-network support.
 * See @ref multi_network for documentation.
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

#ifndef SILABS_ZIGBEE_MULTI_NETWORK_H
#define SILABS_ZIGBEE_MULTI_NETWORK_H

#include "stack/include/sl_zigbee_types.h"

/**
 * @addtogroup multi_network
 *
 * SL_ZIGBEE_MULTI_NETWORK_STRIPPED is an optional #define
 * that is used on flash-space constrained chips
 * to conditionally compile out multi-network related source code.
 * @{
 */
#ifndef SL_ZIGBEE_MULTI_NETWORK_STRIPPED
/** @brief Return the current network index.
 */
uint8_t sl_zigbee_get_current_network(void);

/** @brief Set the current network.
 *
 * @param index   The network index.
 *
 * @return ::SL_STATUS_INVALID_INDEX if the index does not correspond to a
 * valid network, and ::SL_STATUS_OK otherwise.
 */
sl_status_t sl_zigbee_set_current_network(uint8_t index);

/** @brief Can only be called inside an application callback.
 *
 * @return the index of the network the callback refers to. If this function
 * is called outside of a callback, it returns 0xFF.
 */
uint8_t sl_zigbee_get_callback_network(void);

/** @} END addtogroup */
#else // SL_ZIGBEE_MULTI_NETWORK_STRIPPED
#define sl_zigbee_get_current_network()  0
// (void)index to avoid compiler warning.
#define sl_zigbee_set_current_network(index) SL_STATUS_INVALID_STATE
#define sl_zigbee_get_callback_network() 0
#endif  // SL_ZIGBEE_MULTI_NETWORK_STRIPPED

#endif // SILABS_ZIGBEE_MULTI_NETWORK_H
