/***************************************************************************//**
 * @file
 * @brief Interface for querying library status.
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

#ifndef SILABS_LIBRARY_H
#define SILABS_LIBRARY_H

#include "stack/include/sl_zigbee_types.h"

/**
 * @addtogroup stack_info
 *
 * This file provides definitions relevant to libraries. A running image may
 * probe information about included libraries using the APIs defined in this
 * section.
 *
 * See library.h for more information.
 * @{
 */

// A library's status is an 8-bit value with information about it.
// The high bit indicates whether the library is present (1), or if it is a
// stub (0).  The lower 7-bits can be used for codes specific to the library.
// This allows a library, like the security library, to specify what additional
// features are present.
// A value of 0xFF is reserved, it indicates an error in retrieving the
// library status.

/** @brief This indicates the presence, absence, or status of an Ember
 *    stack library.
 */#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_library_status_t
#else
typedef uint8_t sl_zigbee_library_status_t;
enum {
  // Base return codes. These may be ORed with statuses further below.
  SL_ZIGBEE_LIBRARY_PRESENT_MASK  = 0x80,
  SL_ZIGBEE_LIBRARY_IS_STUB       = 0x00,
  SL_ZIGBEE_LIBRARY_ERROR         = 0xFF,

  // The ZigBee Pro library uses the following to indicate additional
  // functionality:
  SL_ZIGBEE_ZIGBEE_PRO_LIBRARY_END_DEVICE_ONLY        = 0x00, // no router capability
  SL_ZIGBEE_ZIGBEE_PRO_LIBRARY_HAVE_ROUTER_CAPABILITY = 0x01,
  SL_ZIGBEE_ZIGBEE_PRO_LIBRARY_ZLL_SUPPORT            = 0x02,

  // The Security library uses the following to indicate additional
  // functionality:
  SL_ZIGBEE_SECURITY_LIBRARY_END_DEVICE_ONLY      = 0x00,
  SL_ZIGBEE_SECURITY_LIBRARY_HAVE_ROUTER_SUPPORT  = 0x01,  // router or trust center support

  // The Packet Validate library may be globally turned on/off.
  // Bit 0 indicates whether the library is enabled/disabled.
  SL_ZIGBEE_PACKET_VALIDATE_LIBRARY_DISABLED      = 0x00,
  SL_ZIGBEE_PACKET_VALIDATE_LIBRARY_ENABLED       = 0x01,
  SL_ZIGBEE_PACKET_VALIDATE_LIBRARY_ENABLE_MASK   = 0x01
};
#endif

/** @brief An enumerated list of library identifiers.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_library_id_t
#else
typedef uint8_t sl_zigbee_library_id_t;
enum {
  SL_ZIGBEE_FIRST_LIBRARY_ID              = 0x00,

  SL_ZIGBEE_ZIGBEE_PRO_LIBRARY_ID         = 0x00,
  SL_ZIGBEE_BINDING_LIBRARY_ID            = 0x01,
  SL_ZIGBEE_END_DEVICE_BIND_LIBRARY_ID    = 0x02,
  SL_ZIGBEE_SECURITY_CORE_LIBRARY_ID      = 0x03,
  SL_ZIGBEE_SECURITY_LINK_KEYS_LIBRARY_ID = 0x04,
  SL_ZIGBEE_ALARM_LIBRARY_ID              = 0x05,
  SL_ZIGBEE_CBKE_LIBRARY_ID               = 0x06,
  SL_ZIGBEE_CBKE_DSA_SIGN_LIBRARY_ID      = 0x07,
  SL_ZIGBEE_ECC_LIBRARY_ID                = 0x08,
  SL_ZIGBEE_CBKE_DSA_VERIFY_LIBRARY_ID    = 0x09,
  SL_ZIGBEE_PACKET_VALIDATE_LIBRARY_ID    = 0x0A,
  SL_ZIGBEE_INSTALL_CODE_LIBRARY_ID       = 0x0B,
  SL_ZIGBEE_ZLL_LIBRARY_ID                = 0x0C,
  SL_ZIGBEE_CBKE_LIBRARY_283K1_ID         = 0x0D,
  SL_ZIGBEE_ECC_LIBRARY_283K1_ID          = 0x0E,
  SL_ZIGBEE_CBKE_CORE_LIBRARY_ID          = 0x0F,
  SL_ZIGBEE_NCP_LIBRARY_ID                = 0x10,
  SL_ZIGBEE_MULTI_NETWORK_LIBRARY_ID      = 0x11,
  SL_ZIGBEE_ENHANCED_BEACON_REQUEST_LIBRARY_ID = 0x12,
  SL_ZIGBEE_CBKE_283K1_DSA_VERIFY_LIBRARY_ID   = 0x13,
  SL_ZIGBEE_MULTI_PAN_LIBRARY_ID          = 0x14,

  SL_ZIGBEE_NUMBER_OF_LIBRARIES           = 0x15,
  SL_ZIGBEE_NULL_LIBRARY_ID               = 0xFF
};
#endif

#define SL_ZIGBEE_LIBRARY_NAMES \
  "Zigbee Pro",                 \
  "Binding",                    \
  "", /*"End Device Bind"*/     \
  "Security Core",              \
  "Security Link Keys",         \
  "",  /*"Alarm",*/             \
  "CBKE 163K1",                 \
  "CBKE DSA Sign",              \
  "ECC",                        \
  "CBKE DSA Verify",            \
  "Packet Validate",            \
  "Install Code",               \
  "ZLL",                        \
  "CBKE 283K1",                 \
  "ECC 283K1",                  \
  "CBKE core",                  \
  "NCP",                        \
  "Multi network",              \
  "Enhanced Beacon Req",        \
  "CBKE 283K1 DSA Verify",      \
  "Multi-PAN",                  \

#if !defined(EZSP_HOST)
// This will be defined elsewhere for the EZSP Host applications.

/** @brief This routine takes a library identifier and returns whether the
 * library is enabled or not. See ::sl_zigbee_library_status_t for return codes.
 */
sl_zigbee_library_status_t sl_zigbee_get_library_status(sl_zigbee_library_id_t libraryId);
#endif

#endif // SILABS_LIBRARY_H
