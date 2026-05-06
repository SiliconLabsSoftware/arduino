/***************************************************************************//**
 * @file
 * @brief User-configurable stack memory allocation defaults
 *
 * @note Application developers should \b not modify any portion
 * of this file. Doing so may cause mysterious bugs. Allocations should be
 * adjusted only by defining the appropriate macros in the application's
 * CONFIGURATION_HEADER.
 *
 * See @ref configuration for documentation.
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

//  Todo:
//  - explain how to use a configuration header
//  - the documentation of the custom handlers should
//    go in config/sl_zigbee_configuration.c, not here
//  - the stack profile documentation is out of date

/**
 * @addtogroup configuration
 *
 * All configurations have defaults. Therefore, many applications may not need
 * to do anything custom.  However, these defaults can be overridden
 * by creating a CONFIGURATION_HEADER or within this header,
 * defining the appropriate macro to a different size. For example, to
 * reduce the amount of memory allocated for child management (from default 6) to 3:
 * @code
 * #define SL_ZIGBEE_MAX_END_DEVICE_CHILDREN 3
 * @endcode
 *
 * The convenience stubs provided in @c config/sl_zigbee_configuration.c can be overridden
 * by defining the appropriate macro and providing the corresponding callback
 * function. For example, an application with custom debug channel input must
 * implement @c sl_zigbee_debug_handler() to process it. Along with
 * the function definition, the application should provide the following
 * line in its CONFIGURATION_HEADER:
 * @code
 * #define SL_ZIGBEE_APPLICATION_HAS_DEBUG_HANDLER
 * @endcode
 *
 * See sl_zigbee_configuration_defaults.h for source code.

 * @{
 */

#ifndef SILABS_EMBER_CONFIGURATION_DEFAULTS_H
#define SILABS_EMBER_CONFIGURATION_DEFAULTS_H

#ifdef CONFIGURATION_HEADER
  #include CONFIGURATION_HEADER
#endif

#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif

#if defined(SL_CATALOG_ZIGBEE_GREEN_POWER_PRESENT)
#include "sl_zigbee_green_power_config.h"
#endif

#if defined(SL_CATALOG_ZIGBEE_SECURITY_LINK_KEYS_PRESENT)
#include "sl_zigbee_security_link_keys_config.h"
#endif

#if defined(SL_CATALOG_ZIGBEE_SOURCE_ROUTE_PRESENT)
#include "sl_zigbee_source_route_config.h"
#endif

#if defined(SL_CATALOG_ZIGBEE_DEVICE_CONFIG_PRESENT)
#include "zigbee_device_config.h"
#endif

#if defined(SL_CATALOG_RADIO_PRIORITY_15_4_PRESENT)
#include "sl_802154_radio_priority_config.h"
#endif

#if defined(SL_CATALOG_ZIGBEE_PRO_STACK_PRESENT)                         \
  || defined(SL_CATALOG_ZIGBEE_PRO_STACK_MAC_TEST_CMDS_PRESENT)          \
  || defined(SL_CATALOG_ZIGBEE_PRO_STACK_ALT_MAC_PRESENT)                \
  || defined(SL_CATALOG_ZIGBEE_PRO_STACK_NON_DEFAULT_MAC_PRESENT)        \
  || defined(SL_CATALOG_ZIGBEE_PRO_STACK_RAIL_MUX_PRESENT)               \
  || defined(SL_CATALOG_ZIGBEE_PRO_STACK_WITH_HIGH_DATARATE_PHY_PRESENT) \
  || defined(SL_CATALOG_ZIGBEE_PRO_ROUTER_STACK_PRESENT)                 \
  || defined(SL_CATALOG_ZIGBEE_PRO_STACK_WITH_HIGH_DATARATE_PHY_RAIL_MUX)
#include "sl_zigbee_pro_stack_config.h"
#elif defined(SL_CATALOG_ZIGBEE_PRO_LEAF_STACK_PRESENT)         \
  || defined(SL_CATALOG_ZIGBEE_PRO_LEAF_STACK_WITH_CSL_PRESENT) \
  || defined(SL_CATALOG_ZIGBEE_PRO_LEAF_STACK_MAC_TEST_CMDS_PRESENT)
#include "sl_zigbee_pro_leaf_stack_config.h"
#elif defined(SL_ZIGBEE_SCRIPTED_TEST) || defined(ZAPTEST) || defined(IMAGE_BUILDER) || defined(SLI_ZIGBEE_LIBRARY_BUILD) || defined(EZSP_HOST) || defined(RAIL_MAKE_TEST)
#else
#error "No stack configuration header included"
#endif

#if defined(SL_CATALOG_ZIGBEE_LIGHT_LINK_PRESENT)
#include "sl_zigbee_light_link_config.h"
#endif

#if defined(SL_CATALOG_ZIGBEE_NCP_CONFIGURATION_PRESENT)
#include "ncp-configuration-config.h"
#endif

#ifndef SL_ZIGBEE_API_MAJOR_VERSION
/** @brief The major version number of the Ember stack release
 * that the application is built against.
 */
  #define SL_ZIGBEE_API_MAJOR_VERSION 2
#endif

#ifndef SL_ZIGBEE_API_MINOR_VERSION
/** @brief The minor version number of the Ember stack release
 * that the application is built against.
 */
  #define SL_ZIGBEE_API_MINOR_VERSION 0
#endif

/** @brief Specify the stack profile.  The default is Profile 0.
 *
 * You can set this to Profile 1 (Zigbee) or Profile 2 (Zigbee Pro) in your
 * application's configuration header (.h) file using:
 * @code
 * #define SL_ZIGBEE_STACK_PROFILE 1
 * @endcode
 * or
 * @code
 * #define SL_ZIGBEE_STACK_PROFILE 2
 * @endcode
 */
#ifndef SL_ZIGBEE_STACK_PROFILE
  #define SL_ZIGBEE_STACK_PROFILE 0
#endif

#if (SL_ZIGBEE_STACK_PROFILE == 2)
#define SL_ZIGBEE_MAX_DEPTH                  15
#define SL_ZIGBEE_SECURITY_LEVEL              5
#define SL_ZIGBEE_MIN_DISCOVERY_TABLE_SIZE    4
#define SL_ZIGBEE_INDIRECT_TRANSMISSION_TIMEOUT 7680
#define SL_ZIGBEE_SEND_MULTICASTS_TO_SLEEPY_ADDRESS false
#ifndef SL_ZIGBEE_MIN_ROUTE_TABLE_SIZE // this value is set to zero on leaf stack
#define SL_ZIGBEE_MIN_ROUTE_TABLE_SIZE       10
#endif
#endif

#ifndef SL_ZIGBEE_STACK_COMPLIANCE_REVISION
  #define SL_ZIGBEE_STACK_COMPLIANCE_REVISION 22
#endif

#ifndef SL_ZIGBEE_MAX_END_DEVICE_CHILDREN
/** @brief The maximum number of end device children that a router
 * will support.*/
  #define SL_ZIGBEE_MAX_END_DEVICE_CHILDREN 6
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/* Need to put in a compile time check to make sure that too many child devices
 * aren't specified.
 */

#if SL_ZIGBEE_MAX_END_DEVICE_CHILDREN > 64
  #error "SL_ZIGBEE_MAX_END_DEVICE_CHILDREN can not exceed 64."
#endif

#endif // DOXYGEN_SHOULD_SKIP_THIS

#ifndef SL_ZIGBEE_SECURITY_LEVEL
/** @brief The security level used for security at the MAC and network
 * layers.  The supported values are 0 (no security) and 5 (payload is
 * encrypted and a four-byte MIC is used for authentication).
 */
  #define SL_ZIGBEE_SECURITY_LEVEL 5
#endif

#if !(SL_ZIGBEE_SECURITY_LEVEL == 0 \
      || SL_ZIGBEE_SECURITY_LEVEL == 5)
  #error "Unsupported security level"
#endif

#ifdef SL_ZIGBEE_CHILD_TABLE_SIZE
  #if (SL_ZIGBEE_MAX_END_DEVICE_CHILDREN < SL_ZIGBEE_CHILD_TABLE_SIZE)
    #undef SL_ZIGBEE_CHILD_TABLE_SIZE
  #endif
#endif

#ifndef SL_ZIGBEE_CHILD_TABLE_SIZE
/** @brief The maximum number of children that a node may have.
 *
 * For the mesh stack, this defaults to the value of
 * ::SL_ZIGBEE_MAX_END_DEVICE_CHILDREN.
 * In the mesh stack router children are not stored in the child table.
 *
 * Each child table entry requires 4 bytes of RAM and a 10 byte token.
 *
 * Application definitions for ::SL_ZIGBEE_CHILD_TABLE_SIZE that are larger
 * than the default value
 * are ignored and the default value used instead.
 */
  #define SL_ZIGBEE_CHILD_TABLE_SIZE SL_ZIGBEE_MAX_END_DEVICE_CHILDREN
#endif

/** @brief The maximum number of link and master keys that a node can
 *  store, <b>not</b> including the Trust Center Link Key.
 *  The stack maintains special storage for the Trust Center
 *  Link Key.
 *
 *  For the Trust Center, this controls how many totally unique
 *  Trust Center Link Keys may be stored.  The rest of the devices
 *  in the network will use a global or hashed link key.
 *
 *  For normal nodes, this controls the number of Application
 *  Link Keys it can store. The Trust Center Link Key
 *  is stored separately from this table.
 *
 *  This value is only applicable for images where the stack is running, such as SoC, NCP, or zigbeed images.
 */
#ifndef EZSP_HOST
#ifndef SL_ZIGBEE_KEY_TABLE_SIZE
  #define SL_ZIGBEE_KEY_TABLE_SIZE 0
#endif
#elif defined(EZSP_HOST) && defined(SL_ZIGBEE_KEY_TABLE_SIZE)
#warning "SL_ZIGBEE_KEY_TABLE_SIZE must be configured on the NCP using the zigbee_security_link_keys component. The user-supplied SL_ZIGBEE_KEY_TABLE_SIZE value is being ignored."
#endif // EZSP_HOST

/** @brief The number of entries for the field upgradeable
 *  certificate table. Normally, certificates, such as SE certs, are stored
 *  in the runtime-unmodifiable MFG area. However, those devices wishing to
 *  add new certificates after manufacturing will have to use the normal
 *  token space. This defines the size of that table. For most devices 0 is
 *  appropriate since there is no need to change certificates in the field.
 *  For those wishing to field upgrade devices with new certificates,
 *  1 is the correct size.  Anything more is wasting storage.
 */
#ifndef SL_ZIGBEE_CERTIFICATE_TABLE_SIZE
  #define SL_ZIGBEE_CERTIFICATE_TABLE_SIZE 0
#else
  #if SL_ZIGBEE_CERTIFICATE_TABLE_SIZE > 1
    #error "SL_ZIGBEE_CERTIFICATE_TABLE_SIZE > 1 is not supported!"
  #endif
#endif

/** @brief The maximum depth of the tree in ZigBee 2006.
 *  This implicitly determines the maximum diameter of
 *  the network (::SL_ZIGBEE_MAX_HOPS) if that value is not
 *  overridden.
 */
#ifndef SL_ZIGBEE_MAX_DEPTH
  #define SL_ZIGBEE_MAX_DEPTH                15
#elif (SL_ZIGBEE_MAX_DEPTH > 15)
// Depth is a 4-bit field
  #error "SL_ZIGBEE_MAX_DEPTH cannot be greater than 15"
#endif

/** @brief The maximum number of hops for a message.
 *
 * The default maximum number of hops is two times the maximum depth
 * (::SL_ZIGBEE_MAX_DEPTH). This is the fallback value when the radius is not
 * supplied by the Application (i.e., 0) or the stack is sending a message.
 */
#ifndef SL_ZIGBEE_MAX_HOPS
  #define SL_ZIGBEE_MAX_HOPS (2 * SL_ZIGBEE_MAX_DEPTH)
#endif

/**
 * @brief The amount of memory to allocate for Packet Buffers available to the stack
 * the default is 4096
 *
 * Each packet buffer has an overhead of 8-bytes per buffer and can store a variable length
 * of data
 */
#ifndef SL_ZIGBEE_PACKET_BUFFER_HEAP_SIZE
  #define SL_ZIGBEE_PACKET_BUFFER_HEAP_SIZE 4096
#endif // SL_ZIGBEE_PACKET_BUFFER_HEAP_SIZE

/** @brief The maximum number of beacons to record when performing an active
 * scan to find networks. Legacy APIs such as sli_zigbee_stack_join_network and the several
 * sli_zigbee_stack_find_and_rejoin_network APIs set the number of beacons to record to 1,
 * while the Network Steering plugin will attempt to record the maximum number of
 * beacons.
 *
 * It is important not to consume all packet buffers in a system, else the
 * transmission and reception of packets will fail, since TX and RX packets are
 * held in packet buffers.
 */
#ifndef SL_ZIGBEE_MAX_BEACONS_TO_STORE
// Packet buffers can be maxed out and we dont necessarily want to cache all those
// many beacons. Cap number of beacons to a reasonable size based on buffer heap configuration
// NOTE 2048 is the 'small' packet buffer heap size
  #define SL_ZIGBEE_MAX_BEACONS_TO_STORE ( (SL_ZIGBEE_PACKET_BUFFER_HEAP_SIZE <= 2048) ? 18 : 37)
#endif
/** @brief The amount of time after which any caches beacons are purged from the
 * cache in RAM. Each beacon stored consumes one packet buffer.
 * The timeout for beacons begins once the first beacon is added to the cache.
 */
#ifndef BEACON_STORAGE_TIMEOUT_MS
  #define BEACON_STORAGE_TIMEOUT_MS    (3 * 60 * 1000)  // 3 minutes
#endif
/** @brief The maximum number of router neighbors the stack
 * can keep track of.
 *
 * A neighbor is a node within radio range.
 * The maximum allowed value is 26. End device children are
 * stored in the child table, not the neighbor table.
 * The default is 16. Setting this value lower than 8 is not
 * recommended.
 *
 * Each neighbor table entry consumes 18 bytes of RAM (6 for the table
 * itself and 12 bytes of security data).
 */
#define SL_ZIGBEE_MAX_NEIGHBOR_TABLE_SIZE 26
#ifndef SL_ZIGBEE_NEIGHBOR_TABLE_SIZE
  #define SL_ZIGBEE_NEIGHBOR_TABLE_SIZE 16
#endif
#if (SL_ZIGBEE_NEIGHBOR_TABLE_SIZE != SL_ZIGBEE_MAX_NEIGHBOR_TABLE_SIZE) && (SL_ZIGBEE_NEIGHBOR_TABLE_SIZE != 16) && (SL_ZIGBEE_NEIGHBOR_TABLE_SIZE != 1)
  #error "Unsupported neighbor table size is configured. Supported values are 1, 16 and 26."
#endif
/** @brief The maximum amount of time (in milliseconds) that the MAC
 * will hold a message for indirect transmission to a child.
 *
 * The default is 3000 milliseconds (3 sec).
 * The maximum value is 30 seconds (30000 milliseconds). Larger values
 * will cause rollover confusion.
 */
#ifndef SL_ZIGBEE_INDIRECT_TRANSMISSION_TIMEOUT
  #define SL_ZIGBEE_INDIRECT_TRANSMISSION_TIMEOUT 3000
#endif
#define SL_ZIGBEE_MAX_INDIRECT_TRANSMISSION_TIMEOUT 30000
#if (SL_ZIGBEE_INDIRECT_TRANSMISSION_TIMEOUT \
     > SL_ZIGBEE_MAX_INDIRECT_TRANSMISSION_TIMEOUT)
  #error "Indirect transmission timeout too large."
#endif

/** @brief Define the behavior for the address that the multicasts are sent to.
 *    The normal address is RxOnWhenIdle=true (0xFFFD). However, setting this
 *    to true can change locally generated multicasts to be sent to the sleepy
 *    broadcast address (0xFFFF). Changing the default is NOT Zigbee Pro
 *    compliant and may not be inter-operable.
 */
#ifndef SL_ZIGBEE_SEND_MULTICASTS_TO_SLEEPY_ADDRESS
  #define SL_ZIGBEE_SEND_MULTICASTS_TO_SLEEPY_ADDRESS false
#endif

/* @brief End Device keep alive support mode
 */
#ifndef SL_ZIGBEE_END_DEVICE_KEEP_ALIVE_SUPPORT_MODE
  #define SL_ZIGBEE_END_DEVICE_KEEP_ALIVE_SUPPORT_MODE  SL_ZIGBEE_KEEP_ALIVE_SUPPORT_ALL
#endif

/** @brief The default index into the R21 Child Aging timeout
 * The default value is a timeout of 256 minutes
 */
#define SECONDS_10              0
#define MINUTES_2               1
#define MINUTES_4               2
#define MINUTES_8               3
#define MINUTES_16              4
#define MINUTES_32              5
#define MINUTES_64              6
#define MINUTES_128             7
#define MINUTES_256             8
#define MINUTES_512             9
#define MINUTES_1024            10
#define MINUTES_2048            11
#define MINUTES_4096            12
#define MINUTES_8192            13
#define MINUTES_16384           14

#ifndef SL_ZIGBEE_END_DEVICE_POLL_TIMEOUT
  #define SL_ZIGBEE_END_DEVICE_POLL_TIMEOUT MINUTES_256
#endif

/** @brief The temporary, short timeout that is given to a joining or insecurely
 * rejoining child. The child is expected to send a network encrypted packet to
 * set its timeout to the default value.
 */
#ifndef SL_ZIGBEE_SHORT_CHILD_TIMEOUT
  #if (SL_ZIGBEE_END_DEVICE_POLL_TIMEOUT == SECONDS_10)
    #define SL_ZIGBEE_SHORT_CHILD_TIMEOUT SECONDS_10
  #else // (SL_ZIGBEE_END_DEVICE_POLL_TIMEOUT == SECONDS_10)
    #define SL_ZIGBEE_SHORT_CHILD_TIMEOUT MINUTES_2
  #endif // (SL_ZIGBEE_END_DEVICE_POLL_TIMEOUT == SECONDS_10)
#endif // SL_ZIGBEE_SHORT_CHILD_TIMEOUT

#ifndef SL_ZIGBEE_LINK_POWER_DELTA_INTERVAL
  #define SL_ZIGBEE_LINK_POWER_DELTA_INTERVAL 300
#endif
/** @brief The maximum number of APS retried messages that the
 * stack can transmit at any time.
 * Here, transmitting describes
 * the time between the call to ::sli_zigbee_stack_send_unicast() and the subsequent
 * callback to ::sli_zigbee_stack_message_sent_handler().
 *
 * @note  A message will
 * typically use one packet buffer for the message header and one or
 * more packet buffers for the payload. The default is 10 messages.
 *
 * Each APS retried message consumes 6 bytes of RAM and
 * two or more packet buffers.
 */
#ifndef SL_ZIGBEE_APS_UNICAST_MESSAGE_COUNT
  #define SL_ZIGBEE_APS_UNICAST_MESSAGE_COUNT 10
#endif

/** @brief Size of 1 is basically the same thing as no duplicate rejection
 */
#ifndef SL_ZIGBEE_APS_DUPLICATE_REJECTION_MAX_ENTRIES
// NOTE a size of 1 is basically the same thing as no duplicate rejection
#define SL_ZIGBEE_APS_DUPLICATE_REJECTION_MAX_ENTRIES 5
#endif

/** @brief The maximum number of bindings supported by the stack.
 * The default is 0 bindings. Each binding consumes 2 bytes of RAM.
 */
#ifndef SL_ZIGBEE_BINDING_TABLE_SIZE
  #define SL_ZIGBEE_BINDING_TABLE_SIZE 0
#endif
/** @brief The maximum number of EUI64<->network address associations
 * that the stack can maintain.  The default value is 8.
 *
 * Address table entries are 10 bytes in size.
 */
#ifndef SL_ZIGBEE_ADDRESS_TABLE_SIZE
  #define SL_ZIGBEE_ADDRESS_TABLE_SIZE 8
#endif
/** @brief The maximum number of destinations to which a node can
 * route messages. This include both messages originating at this node
 * and those relayed for others. The default value is 16.
 *
 * Route table entries are 6 bytes in size.
 */

#ifndef SL_ZIGBEE_ROUTE_TABLE_SIZE //in leaf stack this value is defined to be 0
    #define SL_ZIGBEE_ROUTE_TABLE_SIZE 16
#elif defined(SL_ZIGBEE_MIN_ROUTE_TABLE_SIZE) \
  && SL_ZIGBEE_ROUTE_TABLE_SIZE < SL_ZIGBEE_MIN_ROUTE_TABLE_SIZE
  #error "SL_ZIGBEE_ROUTE_TABLE_SIZE is less than required by stack profile."
#endif

/** @brief The number of simultaneous route discoveries that a node
 * will support.
 *
 * Discovery table entries are 9 bytes in size.
 */
#ifndef SL_ZIGBEE_DISCOVERY_TABLE_SIZE
  #ifdef SL_ZIGBEE_MIN_DISCOVERY_TABLE_SIZE
    #define SL_ZIGBEE_DISCOVERY_TABLE_SIZE SL_ZIGBEE_MIN_DISCOVERY_TABLE_SIZE
  #else
    #define SL_ZIGBEE_DISCOVERY_TABLE_SIZE 8
  #endif
#elif defined(SL_ZIGBEE_MIN_DISCOVERY_TABLE_SIZE) \
  && SL_ZIGBEE_DISCOVERY_TABLE_SIZE < SL_ZIGBEE_MIN_DISCOVERY_TABLE_SIZE
  #error "SL_ZIGBEE_DISCOVERY_TABLE_SIZE is less than required by stack profile."
#endif

/** @brief The maximum number of multicast groups that the device may be
 * a member of.  The default value is 8.
 *
 * Multicast table entries are 3 bytes in size.
 */
#ifndef SL_ZIGBEE_MULTICAST_TABLE_SIZE
  #define SL_ZIGBEE_MULTICAST_TABLE_SIZE 8
#endif
/** @brief The number of source route table entries if the source route library
 * is not included. The maximum source route table
 * size is 255 entries, since a one-byte index is used, and the index 0xFF is
 * reserved. The default value is 0.
 *
 * Source route table entries are 4 bytes in size.
 */
#ifndef SL_ZIGBEE_SOURCE_ROUTE_TABLE_SIZE
  #define SL_ZIGBEE_SOURCE_ROUTE_TABLE_SIZE 0
#endif

#ifndef SL_ZIGBEE_MAX_SOURCE_ROUTE_RELAY_COUNT
  #define SL_ZIGBEE_MAX_SOURCE_ROUTE_RELAY_COUNT  11
#endif

/** @brief The maximum number of broadcasts during a single broadcast timeout
 * period. The minimum and default value is 15 and can only be changed
 * on compatible Ember stacks. Be very careful when changing the broadcast
 * table size as it affects timing of the broadcasts and the number of
 * possible broadcasts.  Additionally, this value must be universal for
 * all devices in the network. Otherwise, a single router can overwhelm
 * all its neighbors with more broadcasts than they can support.
 * In general, this value should be left alone.
 *
 * Broadcast table entries are 6 bytes in size.
 */

/* The minimum broadcast table size per the Zigbee Pro spec is 9. */
#define SL_ZIGBEE_DEFAULT_BROADCAST_TABLE_SIZE 15

#ifndef SL_ZIGBEE_BROADCAST_TABLE_SIZE
  #define SL_ZIGBEE_BROADCAST_TABLE_SIZE SL_ZIGBEE_DEFAULT_BROADCAST_TABLE_SIZE
#elif SL_ZIGBEE_BROADCAST_TABLE_SIZE < SL_ZIGBEE_DEFAULT_BROADCAST_TABLE_SIZE
  #error "SL_ZIGBEE_BROADCAST_TABLE_SIZE is less than the minimum value of 15."
#elif 254 < SL_ZIGBEE_BROADCAST_TABLE_SIZE
  #error "SL_ZIGBEE_BROADCAST_TABLE_SIZE is larger than the maximum value of 254."
#endif

#ifndef SL_ZIGBEE_RETRY_QUEUE_SIZE
  #define SL_ZIGBEE_RETRY_QUEUE_SIZE 16
#endif

#ifndef SL_ZIGBEE_STORE_AND_FORWARD_QUEUE_SIZE
    #define SL_ZIGBEE_STORE_AND_FORWARD_QUEUE_SIZE 5
#endif

/** @brief Settings to control if and where assert information will
 * be printed.
 *
 * The output can be suppressed by defining @c SL_ZIGBEE_ASSERT_OUTPUT_DISABLED.
 * The serial port to which the output is sent
 * can be changed by defining ::SL_ZIGBEE_ASSERT_SERIAL_PORT as the desired port.
 *
 * The default is to have the assert output on and sent to serial port 1.
 */
#if !defined(SL_ZIGBEE_ASSERT_OUTPUT_DISABLED) \
  && !defined(SL_ZIGBEE_ASSERT_SERIAL_PORT)
  #define SL_ZIGBEE_ASSERT_SERIAL_PORT 1
#endif

/** @brief The time the stack will wait (in milliseconds) between sending blocks
 * of a fragmented message. The default value is 0.
 */
#ifndef SL_ZIGBEE_FRAGMENT_DELAY_MS
  #define SL_ZIGBEE_FRAGMENT_DELAY_MS 0
#endif

/** @brief The maximum number of blocks of a fragmented message that can be sent
 * in a single window is defined to be 8.
 */
#define SL_ZIGBEE_FRAGMENT_MAX_WINDOW_SIZE 8

/** @brief The number of blocks of a fragmented message that can be sent in a
 * single window. The maximum is ::SL_ZIGBEE_FRAGMENT_MAX_WINDOW_SIZE. The default
 * value is 1.
 */
#ifndef SL_ZIGBEE_FRAGMENT_WINDOW_SIZE
  #define SL_ZIGBEE_FRAGMENT_WINDOW_SIZE 1
#elif SL_ZIGBEE_FRAGMENT_MAX_WINDOW_SIZE < SL_ZIGBEE_FRAGMENT_WINDOW_SIZE
  #error "SL_ZIGBEE_FRAGMENT_WINDOW_SIZE is too large."
#endif

/** @brief The length of time that the device will wait for an answer
 *  to its Application Key Request. For the Trust Center, this is the time
 *  it will hold the first request and wait for a second matching request.
 *  If both arrive within this time period, the Trust Center will reply to
 *  both with the new key. If both requests are not received, the
 *  Trust Center will discard the request. The time is in minutes,
 *  with the maximum time being 10 minutes. A value of 0 minutes indicates that the
 *  Trust Center will not buffer the request but instead respond immediately.
 *  Only 1 outstanding request is supported at a time.
 *
 *  The Zigbee Pro Compliant value is 0.
 */
#ifndef SL_ZIGBEE_REQUEST_KEY_TIMEOUT
  #define SL_ZIGBEE_REQUEST_KEY_TIMEOUT 0
#elif SL_ZIGBEE_REQUEST_KEY_TIMEOUT > 10
  #error "SL_ZIGBEE_REQUEST_KEY_TIMEOUT is too large."
#endif

/** @brief The length of time, in seconds, that a trust center will store
 *  a transient link key that a device can use to join its network. A
 *  transient key is added with a call to sli_zigbee_stack_sec_man_import_transient_key. After the
 *  transient key is added, it will be removed once this amount of time has
 *  passed. A joining device will not be able to use that key to join until
 *  it is added again on the trust center. The default value is 300 seconds,
 *  i.e., 5 minutes.
 */
#ifndef SL_ZIGBEE_TRANSIENT_KEY_TIMEOUT_S
  #define SL_ZIGBEE_TRANSIENT_KEY_TIMEOUT_S (300)
#endif

/** @brief A reserved transient key timeout value that, when stored with
 *  a "transient" key, prevents its removal from the transient key table
 *  when the session is active. Note that some standard security procedures
 *  (e.g. Zigbee Direct) require session keys to remain active indefinitely
 *  for the duration of the of the exchange.
 */
#ifndef SL_ZIGBEE_TRANSIENT_KEY_SESSION_TIMEOUT_VAL
  #define SL_ZIGBEE_TRANSIENT_KEY_SESSION_TIMEOUT_VAL 0xFFFF
#endif

/** @brief The number of PAN ID conflict reports that must be received by
 * the network manager within one minute to trigger a PAN ID change.
 * Very rarely, a corrupt beacon can pass the CRC check and trigger a
 * false PAN id conflict. This is more likely to happen in very large
 * dense networks. Setting this value to 2 or 3 dramatically reduces
 * the chances of a spurious PAN ID change. The maximum value is 63.
 * The default value is 2.
 */
#ifndef SL_ZIGBEE_PAN_ID_CONFLICT_REPORT_THRESHOLD
  #define SL_ZIGBEE_PAN_ID_CONFLICT_REPORT_THRESHOLD 2
#endif

/** @brief The number of network level retries before network layer gives up
 *  sending a message, and return with an error. This could be seen as an
 *  extension to mac retries, and can take a range between 0..15. Setting
 *  the value to 0 disables network retries.
 */
#define SL_ZIGBEE_MAX_NETWORK_RETRIES 15
#ifndef SL_ZIGBEE_ZIGBEE_NUM_NETWORK_RETRIES_DEFAULT
  #define SL_ZIGBEE_ZIGBEE_NUM_NETWORK_RETRIES_DEFAULT 15
#endif
#if (SL_ZIGBEE_ZIGBEE_NUM_NETWORK_RETRIES_DEFAULT > SL_ZIGBEE_MAX_NETWORK_RETRIES)
  #error "Unsupported network retry attempts is configured. Supported values are 0..15"
#endif

/** @brief The number of event tasks that can be tracked for the purpose of
 *  processor idling. The Ember Zigbee Pro Stack requires two tasks,
 *  an application and associated libraries may use additional tasks,
 *  though typically no more than 5 are needed for most applications.
 */
#ifndef SL_ZIGBEE_TASK_COUNT
 #define SL_ZIGBEE_TASK_COUNT (5)
#endif

/** @brief The number of networks supported by the stack.
 */
#define SL_ZIGBEE_MAX_SUPPORTED_NETWORKS 2
#ifndef SL_ZIGBEE_SCRIPTED_TEST
#if (SLI_ZIGBEE_SECONDARY_NETWORK_ENABLED == 0)
#define SL_ZIGBEE_SUPPORTED_NETWORKS 1
#else
#define SL_ZIGBEE_SUPPORTED_NETWORKS 2
#endif
#else
#ifndef SL_ZIGBEE_SUPPORTED_NETWORKS
 #define SL_ZIGBEE_SUPPORTED_NETWORKS 2
#endif //!defined(SL_ZIGBEE_SUPPORTED_NETWORKS)
#endif //!SL_ZIGBEE_SCRIPTED_TEST
#if (defined(SL_CATALOG_ZIGBEE_NCP_FRAMEWORK_PRESENT) \
  && (defined(SL_CATALOG_ZIGBEE_MULTI_PAN_PRESENT) || defined(SL_CATALOG_ZIGBEE_MULTI_NETWORK_PRESENT)))
#undef SL_ZIGBEE_SUPPORTED_NETWORKS
#define SL_ZIGBEE_SUPPORTED_NETWORKS 2
#endif

#ifndef SL_ZIGBEE_ZLL_GROUP_ADDRESSES
/** @brief The number of unique group identifiers that this device requires.
 */
  #define SL_ZIGBEE_ZLL_GROUP_ADDRESSES 1
#endif

#ifndef SL_ZIGBEE_ZLL_RSSI_THRESHOLD
/** @brief The RSSI threshold applied to incoming scan requests.
 */
  #define SL_ZIGBEE_ZLL_RSSI_THRESHOLD -128
#endif

#ifndef EZSP_HOST
#ifndef SL_ZIGBEE_GP_PROXY_TABLE_SIZE
/** @brief The number of proxy table entries supported. Only on SoC images.
 */
  #define SL_ZIGBEE_GP_PROXY_TABLE_SIZE 5
#endif

#ifndef SL_ZIGBEE_GP_SINK_TABLE_SIZE
/** @brief The number of sink table entries supported.  Only on SoC images.
 */
  #define SL_ZIGBEE_GP_SINK_TABLE_SIZE 0
#endif
#endif //EZSP_HOST

#ifndef SL_ZIGBEE_GP_INCOMING_FC_TOKEN_TIMEOUT
/** @brief The timeout (seconds) to restore the GPD incoming security frame counter in the Flash (0 being never).
 */
#define SL_ZIGBEE_GP_INCOMING_FC_TOKEN_TIMEOUT 7 // between 0 seconds (never) to 4294967 seconds
#endif

#ifndef SL_ZIGBEE_GP_INCOMING_FC_TOKEN_TABLE_SIZE
/** @brief The maximum table size to restore the GPD incoming security frame counter in the Flash (being either 0 or SL_ZIGBEE_GP_PROXY_TABLE_SIZE).
 */
#define SL_ZIGBEE_GP_INCOMING_FC_TOKEN_TABLE_SIZE 0 //SL_ZIGBEE_GP_PROXY_TABLE_SIZE
#endif

#ifndef SL_ZIGBEE_GP_INCOMING_FC_IN_SINK_TOKEN_TIMEOUT
/** @brief The timeout (seconds) to restore the GPD incoming security frame counter in the Flash (0 being never).
 */
#define SL_ZIGBEE_GP_INCOMING_FC_IN_SINK_TOKEN_TIMEOUT 7 // between 0 seconds (never) to 60 seconds
#endif

#ifndef SL_ZIGBEE_GP_INCOMING_FC_IN_SINK_TOKEN_TABLE_SIZE
/** @brief The maximum table size to restore the GPD incoming security frame counter in the Flash (being either 0 or SL_ZIGBEE_GP_SINK_TABLE_SIZE).
 */
#define SL_ZIGBEE_GP_INCOMING_FC_IN_SINK_TOKEN_TABLE_SIZE 0 //SL_ZIGBEE_GP_SINK_TABLE_SIZE
#endif

/** @brief The maximum number of ZC and ZR devices can be supported in a multi network mode.
 * All the ZC and ZR devices are expected to be on the same channel with different PAN IDs.
 * Multi network with multiple ZC and ZR devices are supported only on EFR platform.
 */
#define SL_ZIGBEE_MULTI_NETWORK_MAX_ZC_AND_ZR_DEVICES_SUPPORTED 2
#if SL_ZIGBEE_MULTI_NETWORK_MAX_ZC_AND_ZR_DEVICES_SUPPORTED > SL_ZIGBEE_SUPPORTED_NETWORKS
  #undef SL_ZIGBEE_MULTI_NETWORK_MAX_ZC_AND_ZR_DEVICES_SUPPORTED
  #define SL_ZIGBEE_MULTI_NETWORK_MAX_ZC_AND_ZR_DEVICES_SUPPORTED SL_ZIGBEE_SUPPORTED_NETWORKS
#endif

/** @brief The number of ZC and ZR device types are present in the application.
 * This configuration is used to expand the various stack tables and events
 * required to support the multi PAN application.
 * Note that for SoC, this define is generated by app builder based on the
 * device type(s) present in the application.
 */

#if (SLI_ZIGBEE_PRIMARY_NETWORK_DEVICE_TYPE == SLI_ZIGBEE_NETWORK_DEVICE_TYPE_COORDINATOR_OR_ROUTER \
     || SLI_ZIGBEE_PRIMARY_NETWORK_DEVICE_TYPE == SLI_ZIGBEE_NETWORK_DEVICE_TYPE_ROUTER)
// Primary network is coordinator or router
  #define NETWORK_0_ZC_AND_ZR_COUNT (1)
#else
// Primary network is end device
  #define NETWORK_0_ZC_AND_ZR_COUNT (0)
#endif

#if (SLI_ZIGBEE_SECONDARY_NETWORK_ENABLED > 0                                                             \
     && (SLI_ZIGBEE_SECONDARY_NETWORK_DEVICE_TYPE == SLI_ZIGBEE_NETWORK_DEVICE_TYPE_COORDINATOR_OR_ROUTER \
         || SLI_ZIGBEE_SECONDARY_NETWORK_DEVICE_TYPE == SLI_ZIGBEE_NETWORK_DEVICE_TYPE_ROUTER))
// Secondary network is coordinator or router
  #define NETWORK_1_ZC_AND_ZR_COUNT (1)
#else
// Secondary network not enabled or it is end device
  #define NETWORK_1_ZC_AND_ZR_COUNT (0)
#endif
// Handle the NCP Multi pan case and set the SL_ZIGBEE_ZC_AND_ZR_DEVICE_COUNT to 2
#if defined(SL_CATALOG_ZIGBEE_NCP_FRAMEWORK_PRESENT) && defined(SL_CATALOG_ZIGBEE_MULTI_PAN_PRESENT)
  #undef SL_ZIGBEE_ZC_AND_ZR_DEVICE_COUNT
  #define SL_ZIGBEE_ZC_AND_ZR_DEVICE_COUNT 2
#elif (defined(SL_ZIGBEE_NO_STACK) && !defined(SL_ZIGBEE_ZC_AND_ZR_DEVICE_COUNT))
// For no stack application such nodetest/sniffer.
#define SL_ZIGBEE_ZC_AND_ZR_DEVICE_COUNT (1)
#else
#define SL_ZIGBEE_ZC_AND_ZR_DEVICE_COUNT (NETWORK_0_ZC_AND_ZR_COUNT + NETWORK_1_ZC_AND_ZR_COUNT)
#endif

#if (SL_ZIGBEE_ZC_AND_ZR_DEVICE_COUNT > SL_ZIGBEE_MULTI_NETWORK_MAX_ZC_AND_ZR_DEVICES_SUPPORTED)
  #error "Exceeded the maximum number of supported ZC and ZR devices."
#endif

// This table temporarily keeps track of devices that are joining
// To allow "n" devices to join simulataneously, this table needs to be capable of
// holding n entries. Since this space is only used when necessary and times out fairly
// quickly, we set it to 64 (same as max child table size) to prevent all the additional
// code to allow configuration of this table size
#ifndef SL_ZIGBEE_TRANSIENT_DEVICE_MGMT_MAX_CAPACITY
  #define SL_ZIGBEE_TRANSIENT_DEVICE_MGMT_MAX_CAPACITY 64
#endif

#ifndef SL_ZIGBEE_TRANSIENT_DEVICE_DEFAULT_TIMEOUT_MS
  #ifdef SL_CATALOG_ZIGBEE_DELAYED_JOIN_PRESENT
    #define SL_ZIGBEE_TRANSIENT_DEVICE_DEFAULT_TIMEOUT_MS (65535u)
    #define SL_ZIGBEE_TRANSIENT_DEVICE_MINIMUM_TIMEOUT_MS (10000u)
  #else
    #define SL_ZIGBEE_TRANSIENT_DEVICE_DEFAULT_TIMEOUT_MS (10000u)
  #endif
#endif

//Allows the aps acks for APSME commands to be turned off or on
//This should be "true" by default but to keep it consistend with the current stack behaviour this is "false" by default.
#ifndef SL_ZIGBEE_ENABLE_APS_ACKS_FOR_COMMANDS
  #define SL_ZIGBEE_ENABLE_APS_ACKS_FOR_COMMANDS (false)
#endif

#ifndef SL_ZIGBEE_CUSTOM_MAC_FILTER_TABLE_SIZE
  #define SL_ZIGBEE_CUSTOM_MAC_FILTER_TABLE_SIZE 2
#endif

/** @brief The 802.15.4 CCA mode that should be used at startup. The default
 * value is RAIL_IEEE802154_CCA_MODE_RSSI.
 * This value is configured in the radio during initialization. The user may
 * override this value at runtime using ::sli_zigbee_stack_set_radio_ieee802154_cca_mode.
 *
 * @note The value of this macro is used at startup for SoC and NCP
 * applications only. A host application does not use this value, nor does it
 * set the CCA mode at startup by default.
 */
#ifdef SL_CATALOG_RAIL_LIB_PRESENT
  #include "rail_ieee802154.h"
  #ifndef SL_ZIGBEE_RADIO_802154_CCA_MODE
    #define SL_ZIGBEE_RADIO_802154_CCA_MODE RAIL_IEEE802154_CCA_MODE_RSSI
  #endif // SL_ZIGBEE_RADIO_802154_CCA_MODE
#endif // SL_CATALOG_RAIL_LIB_PRESENT

#if defined(SL_ZIGBEE_TEST) || defined(ZIGBEE_STACK_ON_HOST)
  #undef SL_ZIGBEE_RADIO_802154_CCA_MODE
  #define SL_ZIGBEE_RADIO_802154_CCA_MODE 0
#endif

/**
 * @brief the number of beacons to store when performing a beacon survey scan
 */
#ifndef SL_ZIGBEE_ZDO_BEACON_SURVEY_MAX_UNIQUE_NETWORKS
  #define SL_ZIGBEE_ZDO_BEACON_SURVEY_MAX_UNIQUE_NETWORKS 8
#endif

/** @} END addtogroup */

#endif //__EMBER_CONFIGURATION_DEFAULTS_H__
