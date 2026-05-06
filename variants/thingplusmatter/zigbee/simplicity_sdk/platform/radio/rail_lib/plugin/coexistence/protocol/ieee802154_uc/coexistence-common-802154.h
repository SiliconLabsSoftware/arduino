/***************************************************************************//**
 * @file
 * @brief Common header file for COEX 802.15.4 protocols
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef __COEXISTENCE_COMMON_802154_H__
#define __COEXISTENCE_COMMON_802154_H__

#if defined(DEBUG_PTA) || defined(RHO_GPIO) || defined(SL_RAIL_UTIL_COEX_RHO_PORT)
#define COEX_RHO_SUPPORT 1
#endif //defined(DEBUG_PTA) || defined(RHO_GPIO) || defined(SL_RAIL_UTIL_COEX_RHO_PORT)

#if defined(DEBUG_PTA) || defined(SL_RAIL_UTIL_COEX_REQ_GPIO) || defined(SL_RAIL_UTIL_COEX_REQ_PORT) \
  || defined(SL_RAIL_UTIL_COEX_GNT_GPIO) || defined(SL_RAIL_UTIL_COEX_GNT_PORT) || SL_RAIL_UTIL_COEX_RUNTIME_PHY_SELECT
#define COEX_SUPPORT 1
#endif

#define COEX_STACK_EVENT_SUPPORT \
  (COEX_SUPPORT                  \
   || COEX_RHO_SUPPORT)          \

#endif //__COEXISTENCE_COMMON_802154_H__
