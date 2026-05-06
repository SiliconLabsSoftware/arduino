/***************************************************************************//**
 * @file
 * @brief Routines for configuring a multiple PHY interfaces.
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

#ifndef SILABS_MULTI_PHY_H
#define SILABS_MULTI_PHY_H

#include "stack/include/sl_zigbee_types.h"

/**@brief Network configuration for the desired radio interface
 * for multi phy network.
 *
 * Note: This configuration is not yet supported on SubGhz network
 * as specs do not, added this for future proof.
 */
enum {
  /**Enable broadcast support on Routers*/
  SL_ZIGBEE_BROADCAST_SUPPORT = 0x01
};

/**@brief This causes to initialize the desired radio interface other
 * than native and form a new network by becoming the coordinator with
 * same panId as native radio network.
 *
 * Note: It is required to form a network on native radio before
 * using this API.
 *
 * @param  phyIndex Desired index of phy interface.
 *         page     Desired channel page.
 *         channel  Desire radio channel.
 *         power    Desire radio power.
 *         bitmask  Network configuration bitmask.
 *
 *  * @return An ::sl_status_t value indicating the success or
 *  failure of the command.
 */
sl_status_t sl_zigbee_multi_phy_start(uint8_t phyIndex,
                                      uint8_t page, uint8_t channel,
                                      int8_t power,
                                      sl_zigbee_multi_phy_nwk_config_t bitmask);

/**@brief This causes to bring down the radio interface other than native.
 *
 * @param phyIndex  Desired index of phy interface, assert otherwise.
 *
 * @return An ::sl_status_t value indicating the success or
 *  failure of the command.
 */
sl_status_t sl_zigbee_multi_phy_stop(uint8_t phyIndex);

/** @brief Sets the radio output power at which a node is to operate for the
 * desired phy interface. Ember radios have discrete power settings. For a
 * list of available power settings, see the technical specification for the RF
 * communication module in your Developer Kit.
 * Note: Care should be taken when using this API on a running network,
 * as it will directly impact the established link qualities neighboring nodes
 * have with the node on which it is called.  This can lead to disruption of
 * existing routes and erratic network behavior.
 * Note: If the requested power level is not available on a given radio, this
 * function will use the next higher available power level.
 *
 * @param phyIndex  Desired index of phy interface, assert otherwise.
 *        power     Desired radio output power, in dBm.
 *
 * @return An ::sl_status_t value indicating the success or
 *  failure of the command.  Failure indicates that the requested power level
 *  is out of range.
 */
sl_status_t sl_zigbee_multi_phy_set_radio_power(uint8_t phyIndex, int8_t power);

/** @brief Sets the channel to use for sending and receiving messages on the
 * desired phy interface.
 * For a list of available radio pages and channels, see the technical
 * specification for the RF communication module in your Developer Kit.
 *
 * Note: Care should be taken when using this API,
 * as all devices on a network must use the same page and channel.
 *
 * @param phyIndex  Desired index of phy interface, assert otherwise.
 *        page      Desired radio channel page
 *        channel   Desired radio channel.
 *
 * @return An ::sl_status_t value indicating the success or
 *  failure of the command.
 */
sl_status_t sl_zigbee_multi_phy_set_radio_channel(uint8_t phyIndex,
                                                  uint8_t page, uint8_t channel);

#endif  // SILABS_MULTI_PHY_H
