/***************************************************************************//**
 * @file
 * @brief Ember data type definitions.
 *
 *  See @ref ember_types for details.
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

#ifndef SILABS_EMBER_TYPES_H
#define SILABS_EMBER_TYPES_H

// TODO: temporary hack
#define SIGNED_ENUM

#ifdef PLATFORM_HEADER
 #include PLATFORM_HEADER
#endif // PLATFORM_HEADER

#define MAX_IPC_VEC_ARG_CAPACITY 127

/**
 * @addtogroup ember_types
 *
 * See sl_zigbee_types.h for source code.
 * @{
 */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include "stack/config/sl_zigbee_configuration_defaults.h"
#endif //DOXYGEN_SHOULD_SKIP_THIS

#include "mac-types.h"

/**
 * @name Miscellaneous Ember Types
 */
//@{

/**
 * @brief Type of Ember software version
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_version_type_t
#else
typedef uint8_t sl_zigbee_version_type_t;
enum
#endif
{
  SL_ZIGBEE_VERSION_TYPE_PRE_RELEASE = 0x00,

  //Alpha, should be used rarely
  SL_ZIGBEE_VERSION_TYPE_ALPHA_1     = 0x11,
  SL_ZIGBEE_VERSION_TYPE_ALPHA_2     = 0x12,
  SL_ZIGBEE_VERSION_TYPE_ALPHA_3     = 0x13,
  // Leave space in case we decide to add other types in the future.
  SL_ZIGBEE_VERSION_TYPE_BETA_1      = 0x21,
  SL_ZIGBEE_VERSION_TYPE_BETA_2      = 0x22,
  SL_ZIGBEE_VERSION_TYPE_BETA_3      = 0x23,

  // Anything other than 0xAA is considered pre-release
  // Silicon Labs may define other types in the future (e.g. beta, alpha)
  // Silicon Labs chose an arbitrary number (0xAA) to allow for expansion, but
  // to prevent ambiguity in case 0x00 or 0xFF is accidentally retrieved
  // as the version type.
  SL_ZIGBEE_VERSION_TYPE_GA = 0xAA,
};

/**
 * @brief A structure relating version types to human readable strings.
 */
typedef struct {
  sl_zigbee_version_type_t typeNum;
  const char *typeString;
} sl_zigbee_release_type_struct_t;

/**
 * @brief ::sl_zigbee_release_type_struct_t Data that relates release type to the correct string.
 */
#define SL_ZIGBEE_RELEASE_TYPE_TO_STRING_STRUCT_DATA     \
  { SL_ZIGBEE_VERSION_TYPE_PRE_RELEASE, "Pre-Release" }, \
  { SL_ZIGBEE_VERSION_TYPE_ALPHA_1, "Alpha 1" },         \
  { SL_ZIGBEE_VERSION_TYPE_ALPHA_2, "Alpha 2" },         \
  { SL_ZIGBEE_VERSION_TYPE_ALPHA_3, "Alpha 3" },         \
  { SL_ZIGBEE_VERSION_TYPE_BETA_1, "Beta 1" },           \
  { SL_ZIGBEE_VERSION_TYPE_BETA_2, "Beta 2" },           \
  { SL_ZIGBEE_VERSION_TYPE_BETA_3, "Beta 3" },           \
  { SL_ZIGBEE_VERSION_TYPE_GA, "GA" },                   \
  { 0xFF, NULL },

/**
 * @brief A version structure containing all version information.
 */
typedef struct {
  uint16_t build;
  uint8_t major;
  uint8_t minor;
  uint8_t patch;
  uint8_t special;
  sl_zigbee_version_type_t type;
} sl_zigbee_version_t;

/**
 * @brief A structure containing the version information.
 */
extern const sl_zigbee_version_t sl_zigbee_version;

#ifdef ZIGBEE_STACK_ON_HOST

/**
 * @brief A structure for storing build date and time.
 */
typedef struct {
  const char *date;
  const char *time;
} sl_zigbee_stack_build_date_time_t;

/**
 * @brief A structure containing the build date and time information.
 */
extern const sl_zigbee_stack_build_date_time_t sl_zigbee_stack_build_date_time;

#endif //ZIGBEE_STACK_ON_HOST

/**
 * @brief Size of EUI64 (an IEEE address) in bytes (8).
 */
#define EUI64_SIZE 8

/**
 * @brief Size of an extended PAN identifier in bytes (8).
 */
#define EXTENDED_PAN_ID_SIZE 8

/**
 * @brief Size of an encryption key in bytes (16).
 */
#define SL_ZIGBEE_ENCRYPTION_KEY_SIZE 16

/**
 * @brief Size of Implicit Certificates used for Certificate-based
 * Key Exchange(CBKE).
 */
#define SL_ZIGBEE_CERTIFICATE_SIZE 48

/**
 * @brief Size of Public Keys used in Elliptical Cryptography ECMQV algorithms.
 */
#define SL_ZIGBEE_PUBLIC_KEY_SIZE 22

/**
 * @brief Size of Private Keys used in Elliptical Cryptography ECMQV algorithms.
 */
#define SL_ZIGBEE_PRIVATE_KEY_SIZE 21

/**
 * @brief Size of the SMAC used in Elliptical Cryptography ECMQV algorithms.
 */
#define SL_ZIGBEE_SMAC_SIZE 16

/**
 * @brief Size of the DSA signature used in Elliptical Cryptography
 *   Digital Signature Algorithms.
 */
#define SL_ZIGBEE_SIGNATURE_SIZE 42

/** @brief The size of AES-128 MMO hash is 16-bytes.  This is defined in the core.
 *  ZigBee specification.
 */
#define SL_ZIGBEE_AES_HASH_BLOCK_SIZE 16

/**
 * @brief Size of Implicit Certificates used for Certificate Based
 * Key Exchange using the ECC283K1 curve in bytes.
 */
#define SL_ZIGBEE_CERTIFICATE_283K1_SIZE 74

/**
 * @brief Size of Public Keys used in SECT283k1 Elliptical Cryptography ECMQV algorithms
 */
#define SL_ZIGBEE_PUBLIC_KEY_283K1_SIZE 37

/**
 * @brief Size of Private Keys used SECT283k1 in Elliptical Cryptography ECMQV algorithms
 */
#define SL_ZIGBEE_PRIVATE_KEY_283K1_SIZE 36

/**
 * @brief Size of the DSA signature used in SECT283k1 Elliptical Cryptography
 *   Digital Signature Algorithms.
 */
#define SL_ZIGBEE_SIGNATURE_283K1_SIZE 72

#include "buffer_manager/buffer-management.h"

/**
 * @brief EUI 64-bit ID (an IEEE address).
 */
//typedef uint8_t sl_802154_long_addr_t[EUI64_SIZE];

/**
 * @brief Incoming and outgoing messages are stored in buffers.
 * These buffers are allocated and freed as needed.
 *
 * Buffers are 32 bytes in length and can be linked together to hold
 * longer messages.
 *
 * See packet-buffer.h for APIs related to stack and linked buffers.
 */
//typedef uint16_t sli_buffer_manager_buffer_t;
//typedef uint16_t Buffer;

#define NULL_BUFFER 0x0000u

/**
 * @brief 16-bit ZigBee network address.
 */
//typedef uint16_t sl_802154_short_addr_t;

/** @brief 16-bit ZigBee multicast group identifier. */
typedef uint16_t sl_zigbee_multicast_id_t;

/**
 * @brief 802.15.4 PAN ID.
 */
//typedef uint16_t sl_802154_pan_id_t;

/**
 * @brief The percent of duty cycle for a limit.
 *
 * Duty cycle, limits, and thresholds are reported in units of
 * percent * 100 (i.e., 10000 = 100.00%, 1 = 0.01%).
 */
typedef uint16_t sl_zigbee_duty_cycle_hecto_pct_t;

/**
 * @brief The maximum 802.15.4 channel number is 26.
 */
#define SL_ZIGBEE_MAX_802_15_4_CHANNEL_NUMBER 26

/**
 * @brief The minimum 2.4GHz 802.15.4 channel number is 11.
 */
#define SL_ZIGBEE_MIN_802_15_4_CHANNEL_NUMBER 11

/**
 * @brief The minimum SubGhz channel number is 0.
 */
#define SL_ZIGBEE_MIN_SUBGHZ_CHANNEL_NUMBER 0

/**
 * ZigBee protocol specifies that active scans have a duration of 3 (138 msec).
 * See documentation for sl_zigbee_start_scan in include/network-formation.h
 * for more info on duration values.
 */
#define SL_ZIGBEE_ACTIVE_SCAN_DURATION  3

/**
 * @brief The SubGhz scan duration is 5.
 */
#define SL_ZIGBEE_SUB_GHZ_SCAN_DURATION 5

/**
 * @brief There are sixteen 802.15.4 channels.
 */
#define SL_ZIGBEE_NUM_802_15_4_CHANNELS \
  (SL_ZIGBEE_MAX_802_15_4_CHANNEL_NUMBER - SL_ZIGBEE_MIN_802_15_4_CHANNEL_NUMBER + 1)

/**
 * @brief A bitmask to scan all 2.4 GHz 802.15.4 channels.
 */
#define SL_ZIGBEE_ALL_802_15_4_CHANNELS_MASK 0x07FFF800UL

/**
 * @brief The maximum channels per page are 27
 * page bits 31...27, channel bits 26...0.
 */
#define SL_ZIGBEE_MAX_CHANNELS_PER_PAGE   27

/**
 * @brief Sub-GHz channel bitmasks for pages 28, 30, 31.
 */
#define SL_ZIGBEE_ALL_SUBGHZ_CHANNELS_MASK_FOR_PAGES_28_30_31 0x07FFFFFFUL

/**
 * @brief The maximum SubGhz channel number on pages 28, 30, 31 is 26.
 */
#define SL_ZIGBEE_MAX_SUBGHZ_CHANNEL_NUMBER_ON_PAGES_28_30_31   26
/**
 * @brief SubGhz channel bitmasks for page 29.
 */
#define SL_ZIGBEE_ALL_SUBGHZ_CHANNELS_MASK_FOR_PAGES_29 0x1FF

/**
 * @brief The maximum SubGhz channel number on page 29 is 8.
 */
#define SL_ZIGBEE_MAX_SUBGHZ_CHANNEL_NUMBER_ON_PAGE_29   8

/**
 * @brief The minimum SubGhz page number is 28.
 */
#define SL_ZIGBEE_MIN_SUGBHZ_PAGE_NUMBER  28

/**
 * @brief The maximum SubGhz page number is 31.
 */
#define SL_ZIGBEE_MAX_SUGBHZ_PAGE_NUMBER  31

/**
 * @brief A bitmask for the channel page within a channel mask.
 */
#define SL_ZIGBEE_ALL_CHANNEL_PAGE_MASK 0xF8000000UL

/**
 * @brief A page-channel mask for a given page and channel mask.
 */
#define SL_ZIGBEE_PAGE_CHANNEL_MASK_FROM_CHANNEL_MASK(page, mask)                              \
  (((((uint32_t)(page)) << SL_ZIGBEE_MAX_CHANNELS_PER_PAGE) & SL_ZIGBEE_ALL_CHANNEL_PAGE_MASK) \
   | (((uint32_t)(mask)) & ~SL_ZIGBEE_ALL_CHANNEL_PAGE_MASK))

/**
 * @brief A page-channel mask for a given page and channel.
 */
#define SL_ZIGBEE_PAGE_CHANNEL_MASK_FROM_CHANNEL_NUMBER(page, channel) \
  SL_ZIGBEE_PAGE_CHANNEL_MASK_FROM_CHANNEL_MASK(page, BIT32(channel))

/**
 * @brief The network ID of the coordinator in a ZigBee network is 0x0000.
 */
#define SL_ZIGBEE_ZIGBEE_COORDINATOR_ADDRESS 0x0000u

/**
 * @brief A distinguished network ID that will never be assigned
 * to any node. It is used to indicate the absence of a node ID.
 */
#define SL_ZIGBEE_NULL_NODE_ID 0xFFFFu

/**
 * @brief The channel page value used to indicate just the 2.4GHz channels.
 */
#define SL_ZIGBEE_NO_CHANNEL_PAGE_IN_USE           0
/**
 * @brief A distinguished EUI64 that is commonly used to indicate an invalid
 * EUI64.
 */
#define SL_ZIGBEE_NULL_EUI64 { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }

/**
 * @brief A distinguished binding index used to indicate the absence
 * of a binding.
 */
#define SL_ZIGBEE_NULL_BINDING 0xFFu

/**
 * @brief A distinguished network ID that will never be assigned
 * to any node.
 *
 * This value is used when setting or getting the remote
 * node ID in the address table or getting the remote node ID from the
 * binding table.  It indicates that the address or binding table entry is
 * not in use.
 */
#define SL_ZIGBEE_TABLE_ENTRY_UNUSED_NODE_ID  0xFFFFu

/**
 * @brief A distinguished network ID that will never be assigned
 * to any node.  This value is returned when getting the remote node
 * ID from the binding table and the given binding table index refers
 * to a multicast binding entry.
 */
#define SL_ZIGBEE_MULTICAST_NODE_ID           0xFFFEu

/**
 * @brief A distinguished network ID that will never be assigned
 * to any node.  This value is used when getting the remote node ID
 * from the address or binding tables.  It indicates that the address
 * or binding table entry is currently in use but the node ID
 * corresponding to the EUI64 in the table is currently unknown.
 */
#define SL_ZIGBEE_UNKNOWN_NODE_ID             0xFFFDu

/**
 * @brief A distinguished network ID that will never be assigned
 * to any node.  This value is used when getting the remote node ID
 * from the address or binding tables.  It indicates that the address
 * or binding table entry is currently in use and network address
 * discovery is underway.
 */
#define SL_ZIGBEE_DISCOVERY_ACTIVE_NODE_ID    0xFFFCu

/**
 * @brief A distinguished address table index used to indicate the
 * absence of an address table entry.
 */
#define SL_ZIGBEE_NULL_ADDRESS_TABLE_INDEX 0xFFu

/**
 * @brief The endpoint where the ZigBee Device Object (ZDO) resides.
 */
#define SL_ZIGBEE_ZDO_ENDPOINT 0u

/**
 * @brief The broadcast endpoint, as defined in the ZigBee spec.
 */
#define SL_ZIGBEE_BROADCAST_ENDPOINT 0xFFu

/**
 * @brief The GP endpoint, as defined in the ZigBee spec.
 */
#define SL_ZIGBEE_GP_ENDPOINT 0xF2u

/**
 * @brief The profile ID used by the ZigBee Device Object (ZDO).
 */
#define SL_ZIGBEE_ZDO_PROFILE_ID  0x0000u

/**
 * @brief The profile ID used to address all the public profiles.
 */
#define SL_ZIGBEE_WILDCARD_PROFILE_ID  0xFFFFu

/**
 * @brief The maximum value for a profile ID in the standard profile range.
 */
#define SL_ZIGBEE_MAXIMUM_STANDARD_PROFILE_ID  0x7FFFu

/**
 * @brief The broadcast table entry timeout, which specifies, in quarter
 * seconds, how long an entry persists in the local device's broadcast table.
 */
#define SL_ZIGBEE_BROADCAST_TABLE_TIMEOUT_QS (20 * 4)

/**
 * @brief Ember's Manufacturer ID.
 */
#define SL_ZIGBEE_MANUFACTURER_ID 0x1002u

/**
 * @brief An invalid network index.
 */
#define SL_ZIGBEE_NULL_NETWORK_INDEX 0xFFu

/**
 * @brief Use Ember's default duty cycle limit configurations.
 */
#define SL_ZIGBEE_DC_LIMIT_USE_DEFAULT 0

/**
 * @brief Use in case zigbee leave network with options.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_leave_network_option_t
#else
typedef uint8_t sl_zigbee_leave_network_option_t;
enum
#endif
{
  /** Leave with no option. */
  SL_ZIGBEE_LEAVE_NWK_WITH_NO_OPTION      = 0x00,
  /** Leave with option rejoin. */
  SL_ZIGBEE_LEAVE_NWK_WITH_OPTION_REJOIN  = 0x20,
  /** Leave is requested. */
  SL_ZIGBEE_LEAVE_NWK_IS_REQUESTED        = 0x40,
};

#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_stack_profile_t
#else
typedef uint8_t sl_zigbee_stack_profile_t;
enum
#endif
{
  SL_ZIGBEE_STACK_PROFILE_NONE       = 0x00,
  SL_ZIGBEE_STACK_PROFILE_ZIGBEE_PRO = 0x02,
};

#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_security_level_t
#else
typedef uint8_t sl_zigbee_security_level_t;
enum
#endif
{
  SL_ZIGBEE_SECURITY_LEVEL_NONE = 0x00,
  SL_ZIGBEE_SECURITY_LEVEL_Z3   = 0x05,
};

#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_leave_request_flags_t
#else
typedef uint8_t sl_zigbee_leave_request_flags_t;
enum
#endif
{
  /** Leave and rejoin. */
  SL_ZIGBEE_ZIGBEE_LEAVE_AND_REJOIN     = 0x80,

  // Note: removeChildren is treated to be deprecated and should not be used!
  // CCB 2047
  // - CCB makes the first step to deprecate the 'leave and remove children' functionality.
  // - We were proactive here and deprecated it right away.
  // SL_ZIGBEE_ZIGBEE_LEAVE_AND_REMOVE_CHILDREN = 0x40,

  /** Leave. */
  SL_ZIGBEE_ZIGBEE_LEAVE_WITHOUT_REJOIN = 0x00,
};

#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_leave_reason_t
#else
typedef uint8_t sl_zigbee_leave_reason_t;
enum
#endif
{
  SL_ZIGBEE_LEAVE_REASON_NONE               = 0,
  SL_ZIGBEE_LEAVE_DUE_TO_NWK_LEAVE_MESSAGE  = 1,
  SL_ZIGBEE_LEAVE_DUE_TO_APS_REMOVE_MESSAGE = 2,
  // Currently, the stack does not process the ZDO leave message since it is optional.
  SL_ZIGBEE_LEAVE_DUE_TO_ZDO_LEAVE_MESSAGE  = 3,
  SL_ZIGBEE_LEAVE_DUE_TO_ZLL_TOUCHLINK      = 4,

  SL_ZIGBEE_LEAVE_DUE_TO_APP_EVENT_1        = 0xFF,
};

//@} \\END Misc. Ember Types

/**
 * @name ZigBee Broadcast Addresses
 *@{
 *  ZigBee specifies three different broadcast addresses that
 *  reach different collections of nodes.  Broadcasts are normally sent only
 *  to routers.  Broadcasts can also be forwarded to end devices, either
 *  all of them or only those that do not sleep.  Broadcasting to end
 *  devices is both significantly more resource-intensive and significantly
 *  less reliable than broadcasting to routers.
 */

/** Broadcast to all routers. */
#define SL_ZIGBEE_BROADCAST_ADDRESS 0xFFFCu
/** Broadcast to all non-sleepy devices. */
#define SL_ZIGBEE_RX_ON_WHEN_IDLE_BROADCAST_ADDRESS 0xFFFDu
/** Broadcast to all devices, including sleepy end devices. */
#define SL_ZIGBEE_SLEEPY_BROADCAST_ADDRESS 0xFFFFu

/** @} END Broadcast Addresses */

// From table 3.51 of 053474r14
// When sending many-to-one route requests, the following
// addresses are used
// 0xFFF9 indicates a non-memory-constrained many-to-one route request
// 0xFFF8 indicates a memory-constrained many-to-one route request
#define SL_ZIGBEE_MIN_BROADCAST_ADDRESS 0xFFF8u

/**
 * @brief Returns true if nodeId (short address) is a broadcast address
 */
#define sl_zigbee_is_zigbee_broadcast_address(address) \
  (SL_ZIGBEE_MIN_BROADCAST_ADDRESS <= ((uint16_t) (address)))

/**
 * @brief Defines the possible types of nodes and the roles that a
 * node might play in a network.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_node_type_t
#else
typedef uint8_t sl_zigbee_node_type_t;
enum
#endif
{
  /** The device is not joined. */
  SL_ZIGBEE_UNKNOWN_DEVICE = 0,
  /** Device type has not changed since last join.*/
  SL_ZIGBEE_DEVICE_TYPE_UNCHANGED = SL_ZIGBEE_UNKNOWN_DEVICE,
  /** Will relay messages and can act as a parent to other nodes. */
  SL_ZIGBEE_COORDINATOR = 1,
  /** Will relay messages and can act as a parent to other nodes. */
  SL_ZIGBEE_ROUTER = 2,
  /** Communicates only with its parent and will not relay messages. */
  SL_ZIGBEE_END_DEVICE = 3,
  /** An end device whose radio can be turned off to save power.
   *  The application must call ::sl_zigbee_poll_for_data() to receive messages.
   */
  SL_ZIGBEE_SLEEPY_END_DEVICE = 4,
  /** Sleepy end device which transmits with wake up frames (CSL). */
  SL_ZIGBEE_S2S_INITIATOR_DEVICE = 5,
  /** Sleepy end device which duty cycles the radio Rx (CSL). */
  SL_ZIGBEE_S2S_TARGET_DEVICE = 6,
};

/**
 * @brief The configuration advertised by the end device to the parent when joining/rejoining.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_end_device_configuration_t
#else
typedef uint8_t sl_zigbee_end_device_configuration_t;
enum
#endif
{
  SL_ZIGBEE_END_DEVICE_CONFIG_NONE                   = 0x00,
  SL_ZIGBEE_END_DEVICE_CONFIG_PERSIST_DATA_ON_PARENT = 0x01,
};

/**
 * @brief Defines a ZigBee network and the associated parameters.
 */
typedef struct {
  uint16_t panId;
  uint8_t channel;
  bool allowingJoin;
  uint8_t extendedPanId[EXTENDED_PAN_ID_SIZE];
  uint8_t stackProfile;
  uint8_t nwkUpdateId;
} sl_zigbee_zigbee_network_t;

/**
 * @brief Defines the options that should be used when initializing the
 *   node's network configuration.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_network_init_bitmask_t
#else
typedef uint16_t sl_zigbee_network_init_bitmask_t;
enum
#endif
{
  SL_ZIGBEE_NETWORK_INIT_NO_OPTIONS           = 0x0000,
  /** The Parent Node ID and EUI64 are stored in a token.
      This prevents the need to perform an Orphan scan on startup.
   */
  SL_ZIGBEE_NETWORK_INIT_PARENT_INFO_IN_TOKEN = 0x0001,
  /** Z3 compliant end devices on a network must send a rejoin request on reboot. */
  SL_ZIGBEE_NETWORK_INIT_END_DEVICE_REJOIN_ON_REBOOT = 0x0002,
};

/**
 * @brief Defines the network initialization configuration that should be used
 *   when ::sl_zigbee_network_init() is called by the application.
 */
typedef struct {
  sl_zigbee_network_init_bitmask_t bitmask;
} sl_zigbee_network_init_struct_t;

/**
 * @brief Defines a result of a network beacon survey
 *
 */
typedef struct {
  uint16_t nodeId;
  int8_t rssi;
  uint8_t classificationMask;
} sl_zigbee_beacon_survey_t;

/**
 * @brief Defines a beacon entry that is processed when scanning, joining, or
 *   rejoining.
 */
typedef struct {
  sl_802154_pan_id_t panId;
  sl_802154_short_addr_t sender;
  uint8_t channel;
  uint8_t lqi;
  int8_t rssi;
  uint8_t depth;
  uint8_t nwkUpdateId;
  int8_t power;           // Only valid if enhanced beacon
  int8_t parentPriority;  // TC connectivity and long uptime from capacity field
  uint8_t supportedKeyNegotiationMethods;
  bool extended_beacon;
  bool enhanced             : 1;  // Enhanced or regular beacon
  bool permitJoin           : 1;
  bool hasCapacity          : 1;
  bool tcConnectivity       : 1;
  bool longUptime           : 1;
  bool preferParent         : 1;
  bool macDataPollKeepalive : 1;
  bool endDeviceKeepalive   : 1;
  uint8_t extendedPanId[EXTENDED_PAN_ID_SIZE];
} sl_zigbee_beacon_data_t;

/**
 * @brief Options to allow/disallow rejoins using the default link key.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_aps_rejoin_mode_t
#else
typedef uint8_t sl_zigbee_aps_rejoin_mode_t;
enum
#endif
{
  NO_REJOIN,
  REJOIN_ANY_LINK_KEY,
  REJOIN_NON_DEFAULT_LINK_KEY
};

/**
 * @brief Options to use when sending a message.
 *
 * The discover-route, APS-retry, and APS-indirect options may be used together.
 * Poll response cannot be combined with any other options.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_aps_option_t
#else
typedef uint16_t sl_zigbee_aps_option_t;
enum
#endif
{
  /** No options. */
  SL_ZIGBEE_APS_OPTION_NONE                     = 0x0000,

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  SL_ZIGBEE_APS_OPTION_ENCRYPT_WITH_TRANSIENT_KEY = 0x0001,
  SL_ZIGBEE_APS_OPTION_USE_ALIAS_SEQUENCE_NUMBER = 0x0002,
#endif

  /** This signs the application layer message body (APS Frame not included)
      and appends the ECDSA signature to the end of the message, which is needed by
      Smart Energy applications and requires the CBKE and ECC libraries.
      The ::sl_zigbee_dsa_sign_handler() function is called after DSA signing
      is complete but before the message has been sent by the APS layer.
      Note that when passing a buffer to the stack for DSA signing, the final
      byte in the buffer has a special significance as an indicator of how many
      leading bytes should be ignored for signature purposes. See the API
      documentation of sl_zigbee_dsa_sign() or the dsaSign EZSP command for more
      details about this requirement.
   */
  SL_ZIGBEE_APS_OPTION_DSA_SIGN                 = 0x0010,
  /** Send the message using APS Encryption using the Link Key shared
      with the destination node to encrypt the data at the APS Level. */
  SL_ZIGBEE_APS_OPTION_ENCRYPTION               = 0x0020,
  /** Resend the message using the APS retry mechanism.
      This option and the enable route discovery option must be enabled for
      an existing route to be repaired automatically. */
  SL_ZIGBEE_APS_OPTION_RETRY                    = 0x0040,
  /** Send the message with the NWK 'enable route discovery' flag, which
      causes a route discovery to be initiated if no route to the destination
      is known.  Note that in the mesh stack, this option and the APS retry
      option must be enabled an existing route to be repaired
      automatically. */
  SL_ZIGBEE_APS_OPTION_ENABLE_ROUTE_DISCOVERY   = 0x0100,
  /** Send the message with the NWK 'force route discovery' flag, which causes
      a route discovery to be initiated even if one is known. */
  SL_ZIGBEE_APS_OPTION_FORCE_ROUTE_DISCOVERY    = 0x0200,
  /** Include the source EUI64 in the network frame. */
  SL_ZIGBEE_APS_OPTION_SOURCE_EUI64             = 0x0400,
  /** Include the destination EUI64 in the network frame. */
  SL_ZIGBEE_APS_OPTION_DESTINATION_EUI64        = 0x0800,
  /** Send a ZDO request to discover the node ID of the destination if it is
      not already known. */
  SL_ZIGBEE_APS_OPTION_ENABLE_ADDRESS_DISCOVERY = 0x1000,
  /** This message is being sent in response to a call to
      ::sl_zigbee_poll_handler().  It causes the message to be sent
      immediately instead of being queued up until the next poll from the
      (end device) destination. */
  SL_ZIGBEE_APS_OPTION_POLL_RESPONSE            = 0x2000,
  /** This incoming message is a valid ZDO request and the application
   *   is responsible for sending a ZDO response. This flag is used only
   *   within sl_zigbee_incoming_message_handler() when
   *   EMBER_APPLICATION_RECEIVES_UNSUPPORTED_ZDO_REQUESTS is defined. */
  SL_ZIGBEE_APS_OPTION_ZDO_RESPONSE_REQUIRED    = 0x4000,
  /** This message is part of a fragmented message.  This option may only
      be set for unicasts.  The groupId field gives the index of this
      fragment in the low-order byte.  If the low-order byte is zero this
      is the first fragment and the high-order byte contains the number
      of fragments in the message. */
  SL_ZIGBEE_APS_OPTION_FRAGMENT                 = SIGNED_ENUM 0x8000
};

/**
 * @brief Defines the possible incoming message types.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_incoming_message_type_t
#else
typedef uint8_t sl_zigbee_incoming_message_type_t;
enum
#endif
{
  /** Unicast. */
  SL_ZIGBEE_INCOMING_UNICAST,
  /** Unicast reply. */
  SL_ZIGBEE_INCOMING_UNICAST_REPLY,
  /** Multicast. */
  SL_ZIGBEE_INCOMING_MULTICAST,
  /** Multicast sent by the local device. */
  SL_ZIGBEE_INCOMING_MULTICAST_LOOPBACK,
  /** Broadcast. */
  SL_ZIGBEE_INCOMING_BROADCAST,
  /** Broadcast sent by the local device. */
  SL_ZIGBEE_INCOMING_BROADCAST_LOOPBACK
};

/**
 * @brief Defines the possible outgoing message types.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_outgoing_message_type_t
#else
typedef uint8_t sl_zigbee_outgoing_message_type_t;
enum
#endif
{
  /** Unicast sent directly to an sl_802154_short_addr_t. */
  SL_ZIGBEE_OUTGOING_DIRECT,
  /** Unicast sent using an entry in the address table. */
  SL_ZIGBEE_OUTGOING_VIA_ADDRESS_TABLE,
  /** Unicast sent using an entry in the binding table. */
  SL_ZIGBEE_OUTGOING_VIA_BINDING,
  /** Multicast message.  This value is passed to sl_zigbee_message_sent_handler() only.
   * It may not be passed to sl_zigbee_send_unicast(). */
  SL_ZIGBEE_OUTGOING_MULTICAST,
  /** An aliased multicast message.  This value is passed to sl_zigbee_message_sent_handler() only.
   * It may not be passed to sl_zigbee_send_unicast(). */
  SL_ZIGBEE_OUTGOING_MULTICAST_WITH_ALIAS,
  /** An aliased Broadcast message.  This value is passed to sl_zigbee_message_sent_handler() only.
   * It may not be passed to sl_zigbee_send_unicast(). */
  SL_ZIGBEE_OUTGOING_BROADCAST_WITH_ALIAS,
  /** A broadcast message.  This value is passed to sl_zigbee_message_sent_handler() only.
   * It may not be passed to sl_zigbee_send_unicast(). */
  SL_ZIGBEE_OUTGOING_BROADCAST
};

// OLD API
/** @brief A type of command received by the stack.
 *
 * This enumeration indicates which protocol layer in the Ember
 * stack an incoming command was meant for, or from which protocol layer
 * an outgoing command is being sent.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_zigbee_command_type_t
#else
typedef uint8_t sl_zigbee_zigbee_command_type_t;
enum
#endif
{
  /** Describes an 802.15.4 raw MAC message, unprocessed by the stack. */
  SL_ZIGBEE_ZIGBEE_COMMAND_TYPE_RAW_MAC,
  /** Describes an 802.15.4 MAC layer command. */
  SL_ZIGBEE_ZIGBEE_COMMAND_TYPE_MAC_COMMAND,
  /** Describes a ZigBee Network layer command. */
  SL_ZIGBEE_ZIGBEE_COMMAND_TYPE_NWK,
  /** Describes a ZigBee Application Support layer command. */
  SL_ZIGBEE_ZIGBEE_COMMAND_TYPE_APS,
  /** Describes a ZigBee Device Object command. */
  SL_ZIGBEE_ZIGBEE_COMMAND_TYPE_ZDO,
  /** Describes a ZigBee Cluster Library command. */
  SL_ZIGBEE_ZIGBEE_COMMAND_TYPE_ZCL,
  /** Not a MAC command, but enumerated here for simplicity. */
  SL_ZIGBEE_ZIGBEE_COMMAND_TYPE_BEACON,
};

/** @brief indication of the action taken on a packet */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_packet_action_t
#else
typedef uint8_t sl_zigbee_packet_action_t;
enum
#endif
{
  SL_ZIGBEE_DROP_PACKET   = 0,
  SL_ZIGBEE_ACCEPT_PACKET = 1,
  SL_ZIGBEE_MANGLE_PACKET,

  /** This action allows unencrypted packets to pass through the stack.
      We only support this action in the network layer for now.
      WARNING: Using this packet handler action may have serious security implications*/
  SL_ZIGBEE_ACCEPT_PACKET_OVERRIDE_SECURITY,

  /** This action allows unencrypted incoming packets to skip NWK decryption
      as well as outgoing packets to skip NWK encryption
      irrespective of the encryption flag in the NWK header.
      We only support this action in the network layer for now. */
  SL_ZIGBEE_ACCEPT_PACKET_SKIP_NWK_CRYPTO,
};

/** @brief A type of packet received by the stack
 *
 * This enum provides a way to indicate which protocol layer in the Ember
 * stack an incoming packet is meant for, or from which protocol layer
 * an outgoing command is being sent from.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_zigbee_packet_type_t
#else
typedef uint8_t sl_zigbee_zigbee_packet_type_t;
enum
#endif
{
  /** Describes an 802.15.4 raw MAC message, unprocessed by the stack. */
  SL_ZIGBEE_ZIGBEE_PACKET_TYPE_RAW_MAC,
  /** Describes an 802.15.4 MAC layer command. */
  SL_ZIGBEE_ZIGBEE_PACKET_TYPE_MAC_COMMAND,
  /** Describes a ZigBee Network layer data message. */
  SL_ZIGBEE_ZIGBEE_PACKET_TYPE_NWK_DATA,
  /** Describes a ZigBee Network layer command. */
  SL_ZIGBEE_ZIGBEE_PACKET_TYPE_NWK_COMMAND,
  /** Describes a ZigBee Application Support layer data message. */
  SL_ZIGBEE_ZIGBEE_PACKET_TYPE_APS_DATA,
  /** Describes a ZigBee Application Support layer command. */
  SL_ZIGBEE_ZIGBEE_PACKET_TYPE_APS_COMMAND,
  /** Describes a ZigBee Device Object command. */
  SL_ZIGBEE_ZIGBEE_PACKET_TYPE_ZDO,
  /** Describes a ZigBee Cluster Library command. */
  SL_ZIGBEE_ZIGBEE_PACKET_TYPE_ZCL,
  /** Distinguishing between raw MAC and beacons for simplicity */
  SL_ZIGBEE_ZIGBEE_PACKET_TYPE_BEACON,
  /** Describes a ZigBee Light Link message. */
  SL_ZIGBEE_ZIGBEE_PACKET_TYPE_INTERPAN,
  /** Describes a ZigBee Network layer data message prior to (potential) decryption. */
  SL_ZIGBEE_ZIGBEE_PACKET_TYPE_NWK_DATA_PRE_DECRYPTION,
  /** Describes a ZigBee Network layer command prior to (potential) decryption. */
  SL_ZIGBEE_ZIGBEE_PACKET_TYPE_NWK_COMMAND_PRE_DECRYPTION,
};

/**
 * @brief Defines the possible join states for a node.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_network_status_t
#else
typedef uint8_t sl_zigbee_network_status_t;
enum
#endif
{
  /** The node is not associated with a network in any way. */
  SL_ZIGBEE_NO_NETWORK,
  /** The node is currently attempting to join a network. */
  SL_ZIGBEE_JOINING_NETWORK,
  /** The node is joined to a network. */
  SL_ZIGBEE_JOINED_NETWORK,
  /** The node is an end device joined to a network but its parent
      is not responding. */
  SL_ZIGBEE_JOINED_NETWORK_NO_PARENT,
  /** The node is a Sleepy-to-Sleepy initiator */
  SL_ZIGBEE_JOINED_NETWORK_S2S_INITIATOR,
  /** The node is a Sleepy-to-Sleepy target */
  SL_ZIGBEE_JOINED_NETWORK_S2S_TARGET,
  /** The node is in the process of leaving its current network. */
  SL_ZIGBEE_LEAVING_NETWORK
};

/**
 * @brief Type for a network scan.
 */

// The RADIO_OFF scan is not really a scan at all.  It is used to
// temporarily turn off the radio to use the TX and RX
// buffers for other purposes.
// Start the scan with:
//   sl_zigbee_start_scan(SL_ZIGBEE_START_RADIO_OFF_SCAN, 0, 0);
// Call sl_zigbee_stop_scan() to restart the radio and the MAC.

#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_network_scan_type_t
#else
typedef uint8_t sl_zigbee_network_scan_type_t;
enum
#endif
{
  /** An energy scan scans each channel for its RSSI value. */
  SL_ZIGBEE_ENERGY_SCAN,
  /** An active scan scans each channel for available networks. Use this scan type during network-steering to filter for beacons with
     available child capacity. The network found callback sl_zigbee_af_network_found_cb fires for all received beacons, while only beacons
     matching the capacity criteria and therefore viable for joining are cached */
  SL_ZIGBEE_ACTIVE_SCAN,
  /** A fake scan that is used to turn off the radio. */
  SL_ZIGBEE_START_RADIO_OFF_SCAN,
  /** A green power channel delivery scan. */
  SL_ZIGBEE_STACK_GP_CHANNEL_DELIVERY_SCAN,
  /** An active scan scans each channel for available networks. Use this scan type during network-steering to filter for and cache beacons
     with available router capacity - Note that this scan type temporarily sets nodeType to SL_ZIGBEE_ROUTER for the duration of the scan process.
     The network found callback sl_zigbee_af_network_found_cb fires for all received beacons, while only beacons matching the capacity
     criteria and therefore viable for joining are cached */
  SL_ZIGBEE_ACTIVE_SCAN_ROUTER,
  SL_ZIGBEE_LAST_SCAN_TYPE = SL_ZIGBEE_ACTIVE_SCAN_ROUTER
};

/**
 * @brief Defines binding types.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_binding_type_t
#else
typedef uint8_t sl_zigbee_binding_type_t;
enum
#endif
{
  /** A binding that is currently not in use. */
  SL_ZIGBEE_UNUSED_BINDING         = 0,
  /** A unicast binding whose 64-bit identifier is the destination EUI64. */
  SL_ZIGBEE_UNICAST_BINDING        = 1,
  /** A unicast binding whose 64-bit identifier is the many-to-one
   * destination EUI64.  Route discovery should be disabled when sending
   * unicasts via many-to-one bindings. */
  SL_ZIGBEE_MANY_TO_ONE_BINDING    = 2,
  /** A multicast binding whose 64-bit identifier is the group address. This
   * binding can be used to send messages to the group and to receive
   * messages sent to the group. */
  SL_ZIGBEE_MULTICAST_BINDING      = 3,
};

/**
 * @name Ember Concentrator Types
 *@{
 */

/** An inactive concentrator. */
#define SL_ZIGBEE_INACTIVE_CONCENTRATOR 0xFFFFu
/** A concentrator with insufficient memory to store source routes for
 * the entire network. Route records are sent to the concentrator prior
 * to every inbound APS unicast. */
#define SL_ZIGBEE_LOW_RAM_CONCENTRATOR 0xFFF8u
/** A concentrator with sufficient memory to store source routes for
 * the entire network. Remote nodes stop sending route records once
 * the concentrator has successfully received one.
 */
#define SL_ZIGBEE_HIGH_RAM_CONCENTRATOR 0xFFF9u

//@} \\END Ember Concentrator Types

/**
 * @brief To configure non trust center node to assume a concentrator type
 * of the trust center it join to, until it receive many-to-one route request
 * from the trust center. For the trust center node, concentrator type is
 * configured from the concentrator plugin.
 * The stack by default assumes trust center be a low RAM concentrator that make
 * other devices send route record to the trust center even without receiving
 * a many-to-one route request. The assumed concentrator type can be changed by
 * setting appropriate value in sl_zigbee_set_assumed_trust_center_concentrator_type().
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_assume_trust_center_concentrator_type_t
#else
typedef uint8_t sl_zigbee_assume_trust_center_concentrator_type_t;
enum
#endif
{
  /** To assume trust center is not a concentrator. */
  SL_ZIGBEE_ASSUME_TRUST_CENTER_IS_NOT_A_CONCENTRATOR = 0,
  /** To assume trust center is a low RAM concentrator. */
  SL_ZIGBEE_ASSUME_TRUST_CENTER_IS_LOW_RAM_CONCENTRATOR = 1,
  /** To assume trust center is a high RAM concentrator. */
  SL_ZIGBEE_ASSUME_TRUST_CENTER_IS_HIGH_RAM_CONCENTRATOR = 2
};

/**
 * @brief The decision made by the Trust Center when a node attempts to join.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_join_decision_t
#else
typedef uint8_t sl_zigbee_join_decision_t;
enum
#endif
{
  /** Allow the node to join. The node has the key. */
  SL_ZIGBEE_USE_PRECONFIGURED_KEY = 0,
  /** Allow the node to join. Send the key to the node. */
  SL_ZIGBEE_SEND_KEY_IN_THE_CLEAR,
  /** Deny join. */
  SL_ZIGBEE_DENY_JOIN,
  /** Take no action. */
  SL_ZIGBEE_NO_ACTION,
  /** Allow rejoins only.*/
  SL_ZIGBEE_ALLOW_REJOINS_ONLY
};

/**
 * @ brief Defines the CLI enumerations for the ::sl_zigbee_join_decision_t enum.
 */
#define SL_ZIGBEE_JOIN_DECISION_STRINGS \
  "use preconfigured key",              \
  "send key in the clear",              \
  "deny join",                          \
  "no action",                          \
  "allow rejoins only",

/** @brief The Status of the Update Device message sent to the Trust Center.
 *  The device may have joined or rejoined insecurely, rejoined securely, or
 *  left.  MAC Security has been deprecated and therefore there is no secure
 *  join.
 */
// These map to the actual values within the APS Command frame so they cannot
// be arbitrarily changed.
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_device_update_t
#else
typedef uint8_t sl_zigbee_device_update_t;
enum
#endif
{
  SL_ZIGBEE_STANDARD_SECURITY_SECURED_REJOIN   = 0,
  SL_ZIGBEE_STANDARD_SECURITY_UNSECURED_JOIN   = 1,
  SL_ZIGBEE_DEVICE_LEFT                        = 2,
  SL_ZIGBEE_STANDARD_SECURITY_UNSECURED_REJOIN = 3,
};

/**
 * @ brief Defines the CLI enumerations for the ::sl_zigbee_device_update_t enum.
 */
#define SL_ZIGBEE_DEVICE_UPDATE_STRINGS \
  "secured rejoin",                     \
  "UNsecured join",                     \
  "device left",                        \
  "UNsecured rejoin",

/**
 * @brief Notes the last rejoin reason.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_rejoin_reason_t
#else
typedef uint8_t sl_zigbee_rejoin_reason_t;
enum
#endif
{
  SL_ZIGBEE_REJOIN_REASON_NONE           = 0,
  SL_ZIGBEE_REJOIN_DUE_TO_NWK_KEY_UPDATE = 1,
  SL_ZIGBEE_REJOIN_DUE_TO_LEAVE_MESSAGE  = 2,
  SL_ZIGBEE_REJOIN_DUE_TO_NO_PARENT      = 3,
  SL_ZIGBEE_REJOIN_DUE_TO_ZLL_TOUCHLINK  = 4,
  SL_ZIGBEE_REJOIN_DUE_TO_END_DEVICE_REBOOT = 5,

  // App. Framework events
  // 0xA0 - 0xE0
  // See af.h for a subset of defined rejoin reasons

  // Customer-defined Events
  //   These are numbered down from 0xFF so their assigned values
  //   need not change if more application events are needed.
  SL_ZIGBEE_REJOIN_DUE_TO_APP_EVENT_5       = 0xFB,
  SL_ZIGBEE_REJOIN_DUE_TO_APP_EVENT_4       = 0xFC,
  SL_ZIGBEE_REJOIN_DUE_TO_APP_EVENT_3       = 0xFD,
  SL_ZIGBEE_REJOIN_DUE_TO_APP_EVENT_2       = 0xFE,
  SL_ZIGBEE_REJOIN_DUE_TO_APP_EVENT_1       = 0xFF,
};

/**
 * @brief Defines the lists of clusters that must be provided for each endpoint.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_cluster_list_id_t
#else
typedef uint8_t sl_zigbee_cluster_list_id_t;
enum
#endif
{
  /** Input clusters the endpoint will accept. */
  SL_ZIGBEE_INPUT_CLUSTER_LIST            = 0,
  /** Output clusters the endpoint can send. */
  SL_ZIGBEE_OUTPUT_CLUSTER_LIST           = 1
};

/**
 * @brief Either marks an event as inactive or specifies the units for the
 * event execution time.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_event_units_t
#else
typedef uint8_t sl_zigbee_event_units_t;
enum
#endif
{
  /** The event is not scheduled to run. */
  SL_ZIGBEE_EVENT_INACTIVE = 0,
  /** The execution time is in approximate milliseconds.  */
  SL_ZIGBEE_EVENT_MS_TIME,
  /** The execution time is in 'binary' quarter seconds (256 approximate
      milliseconds each). */
  SL_ZIGBEE_EVENT_QS_TIME,
  /** The execution time is in 'binary' minutes (65536 approximate milliseconds
      each). */
  SL_ZIGBEE_EVENT_MINUTE_TIME,
  /** The event is scheduled to run at the earliest opportunity. */
  SL_ZIGBEE_EVENT_ZERO_DELAY
};

/** @brief The type of method used for joining.
 *
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_join_method_t
#else
typedef uint8_t sl_zigbee_join_method_t;
enum
#endif
{
  /** Devices normally use MAC association to join a network, which respects
   *  the "permit joining" flag in the MAC beacon.
   *  This value should be used by default.
   */
  SL_ZIGBEE_USE_MAC_ASSOCIATION         = 0,

  /** For networks where the "permit joining" flag is never turned
   *  on, devices will need to use a ZigBee NWK Rejoin.  This value causes the
   *  rejoin to be sent withOUT NWK security and the Trust Center will be
   *  asked to send the NWK key to the device.  The NWK key sent to the device
   *  can be encrypted with the device's corresponding Trust Center link key.
   *  That is determined by the ::sl_zigbee_join_decision_t on the Trust Center
   *  returned by the ::sl_zigbee_internal_trust_center_join_handler().
   */
  SL_ZIGBEE_USE_NWK_REJOIN              = 1,

  /* For networks where the "permit joining" flag is never turned
   * on, devices will need to use a NWK Rejoin.  If those devices have been
   * preconfigured with the  NWK key (including sequence number), they can use
   * a secured rejoin.  This is only necessary for end devices since they need
   * a parent.  Routers can simply use the ::SL_ZIGBEE_USE_CONFIGURED_NWK_STATE
   * join method below.
   */
  SL_ZIGBEE_USE_NWK_REJOIN_HAVE_NWK_KEY = 2,

  /** For networks where all network and security information is known
      ahead of time, a router device may be commissioned such that it does
      not need to send any messages to begin communicating on the network.
   */
  SL_ZIGBEE_USE_CONFIGURED_NWK_STATE    = 3,

  /** This enumeration causes an unencrypted Network Commissioning Request to be
      sent out with joinType set to initial join. The trust center may respond
      by establishing a new dynamic link key and then sending the network key.
      Network Commissioning Requests should only be sent to parents that support
      processing of the command.
   */
  SL_ZIGBEE_USE_NWK_COMMISSIONING_JOIN = 4,

  /** This enumeration causes an unencrypted Network Commissioning Request to be
      sent out with joinType set to rejoin. The trust center may respond
      by establishing a new dynamic link key and then sending the network key.
      Network Commissioning Requests should only be sent to parents that support
      processing of the command.
   */
  SL_ZIGBEE_USE_NWK_COMMISSIONING_REJOIN = 5,

  /** This enumeration causes an encrypted Network Commissioning Request to be
      sent out with joinType set to rejoin. This enumeration is used by devices
      that already have the network key and wish to recover connection to a
      parent or the network in general.
      Network Commissioning Requests should only be sent to parents that support
      processing of the command.
   */
  SL_ZIGBEE_USE_NWK_COMMISSIONING_REJOIN_HAVE_NWK_KEY = 6,
};

/** @brief Holds network parameters.
 *
 * For information about power settings and radio channels,
 * see the technical specification for the
 * RF communication module in your Developer Kit.
 */
typedef struct {
  /** The network's extended PAN identifier.*/
  uint8_t   extendedPanId[EXTENDED_PAN_ID_SIZE];
  /** The network's PAN identifier.*/
  uint16_t  panId;
  /** A power setting, in dBm.*/
  int8_t   radioTxPower;
  /** A radio channel. Be sure to specify a channel supported by the radio. */
  uint8_t   radioChannel;
  /** Join method: The protocol messages used to establish an initial parent.  It is
   *  ignored when forming a ZigBee network, or when querying the stack for its
      network parameters.
   */
  sl_zigbee_join_method_t joinMethod;

  /** NWK Manager ID.  The ID of the network manager in the current network.
      This may only be set at joining when using SL_ZIGBEE_USE_CONFIGURED_NWK_STATE
      as the join method.
   */
  sl_802154_short_addr_t nwkManagerId;
  /** An NWK Update ID.  The value of the ZigBee nwkUpdateId known by the stack.
      It is used to determine the newest instance of the network after a PAN
      ID or channel change.  This may only be set at joining when using
      SL_ZIGBEE_USE_CONFIGURED_NWK_STATE as the join method.
   */
  uint8_t nwkUpdateId;
  /** The NWK channel mask.  The list of preferred channels that the NWK manager
      has told this device to use when searching for the network.
      This may only be set at joining when using SL_ZIGBEE_USE_CONFIGURED_NWK_STATE
      as the join method.
   */
  uint32_t channels;
} sl_zigbee_network_parameters_t;

#if defined(DOXYGEN_SHOULD_SKIP_THIS) || defined(ZNET_HEADER_SCRIPT)
#define sl_zigbee_initialize_network_parameters(parameters) \
  (memset(parameters, 0, sizeof(sl_zigbee_network_parameters_t)))
#else
void sl_zigbee_initialize_network_parameters(sl_zigbee_network_parameters_t* parameters);
#endif

/** @brief Holds radio parameters.
 *
 * This is mainly useful for dual PHY and switched radio
 * device (2.4 GHz or SubGHz) to retrieve radio parameters.
 */
typedef struct {
  int8_t radioTxPower;
  uint8_t radioPage;
  uint8_t radioChannel;
} sl_zigbee_multi_phy_radio_parameters_t;

/** @brief An in-memory representation of a ZigBee APS frame
 * of an incoming or outgoing message.
 */
typedef struct {
  /** The application profile ID that describes the format of the message. */
  uint16_t profileId;
  /** The cluster ID for this message. */
  uint16_t clusterId;
  /** The source endpoint. */
  uint8_t sourceEndpoint;
  /** The destination endpoint. */
  uint8_t destinationEndpoint;
  /** A bitmask of options from the enumeration above. */
  sl_zigbee_aps_option_t options;
  /** The group ID for this message, if it is multicast mode. */
  uint16_t groupId;
  /** The sequence number. */
  uint8_t sequence;
  uint8_t radius;
} sl_zigbee_aps_frame_t;

/** @brief This structure contains information about child nodes.
 *
 */
typedef struct {
  sl_802154_long_addr_t eui64;
  sl_zigbee_node_type_t type;
  sl_802154_short_addr_t id;
  uint8_t phy;
  uint8_t power;
  uint8_t timeout;
  uint32_t remainingTimeout;
} sl_zigbee_child_data_t;

/** @brief Defines an entry in the binding table.
 *
 * A binding entry specifies a local endpoint, a remote endpoint, a
 * cluster ID and either the destination EUI64 (for unicast bindings) or the
 * 64-bit group address (for multicast bindings).
 */
typedef struct {
  /** The type of binding. */
  sl_zigbee_binding_type_t type;
  /** The endpoint on the local node. */
  uint8_t local;
  /** A cluster ID that matches one from the local endpoint's simple descriptor.
   * This cluster ID is set by the provisioning application to indicate which
   * part an endpoint's functionality is bound to this particular remote node
   * and is used to distinguish between unicast and multicast bindings. Note
   * that a binding can be used to to send messages with any cluster ID, not
   * just that listed in the binding.
   */
  uint16_t clusterId;
  /** The endpoint on the remote node (specified by \c identifier). */
  uint8_t remote;
  /** A 64-bit identifier.  This is either:
   * - The destination EUI64, for unicasts.
   * - A 16-bit multicast group address, for multicasts.
   */
  sl_802154_long_addr_t identifier;
  /** The index of the network the binding belongs to. */
  uint8_t networkIndex;
} sl_zigbee_binding_table_entry_t;

/** @brief Defines an entry in the neighbor table.
 *
 * A neighbor table entry stores information about the
 * reliability of RF links to and from neighboring nodes.
 */
typedef struct {
  /** The neighbor's two-byte network ID.*/
  uint16_t shortId;
  /** Filtered Link Quality indicator */
  uint8_t  averageLqi;
  /** The incoming cost for this neighbor, computed from the average LQI.
   *  Values range from 1 for a good link to 7 for a bad link.*/
  uint8_t  inCost;
  /** The outgoing cost for this neighbor, obtained from the most recently
   *  received neighbor exchange message from the neighbor.  A value of zero
   *  means that a neighbor exchange message from the neighbor has not been
   *  received recently enough, or that our ID was not present in the most
   *  recently received one.  EmberZNet Pro only.
   */
  uint8_t  outCost;
  /** In EmberZNet Pro, the number of aging periods elapsed since a neighbor
   *  exchange message was last received from this neighbor.  In stack profile 1,
   *  the number of aging periods since any packet was received.
   *  An entry with an age greater than 6 is considered stale and may be
   *  reclaimed. In case the entry is used by a routing table entry it is
   *  considered stale with an age of 8. The aging period is 16 seconds.
   *  On receiving an incoming packet from the neighbor, the age is set to 3.*/
  uint8_t  age;
  /** The 8 byte EUI64 of the neighbor. */
  sl_802154_long_addr_t longId;
} sl_zigbee_neighbor_table_entry_t;

/** @brief Defines an entry in the route table.
 *
 * A route table entry stores information about the next
 * hop along the route to the destination.
 */
typedef struct {
  /** The short ID of the destination. */
  uint16_t destination;
  /** The short ID of the next hop to this destination. */
  uint16_t nextHop;
  /** Indicates whether this entry is active (0), being discovered (1),
   * or unused (3). */
  uint8_t status;
  /** The number of seconds since this route entry was last used to send
   * a packet. */
  uint8_t age;
  /** Indicates whether this destination is a High-RAM Concentrator (2),
   * a Low-RAM Concentrator (1), or not a concentrator (0). */
  uint8_t concentratorType;
  /** For a High-RAM Concentrator, indicates whether a route record
   * is needed (2), has been sent (1), or is no long needed (0) because
   * a source routed message from the concentrator has been received.
   */
  uint8_t routeRecordState;
} sl_zigbee_route_table_entry_t;

/** @brief Defines an entry in the multicast table.
 *
 * A multicast table entry indicates that a particular
 * endpoint is a member of a particular multicast group.  Only devices
 * with an endpoint in a multicast group will receive messages sent to
 * that multicast group.
 */
typedef struct {
  /** The multicast group ID. */
  sl_zigbee_multicast_id_t multicastId;
  /** The endpoint that is a member, or 0 if this entry is not in use
   *  (the ZDO is not a member of any multicast groups).
   */
  uint8_t endpoint;
  /** The network index of the network the entry is related to. */
  uint8_t networkIndex;
} sl_zigbee_multicast_table_entry_t;

/**
 * @brief Defines the events reported to the application
 * by the ::sl_zigbee_counters_handler().  Usage of the destinationNodeId
 * or data fields found in the sl_zigbee_counter_info_t or sl_zigbee_extra_counters_info_t
 * structs is denoted for counter types that use them. (See comments
 * accompanying enum definitions in this source file for details.)
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_counter_type_t
#else
typedef uint8_t sl_zigbee_counter_type_t;
enum
#endif
{
  /** The MAC received a broadcast Data frame, Command frame, or Beacon
   * destinationNodeId: BROADCAST_ADDRESS or Data frames or
   *                    sender node ID for Beacon frames
   * data: not used
   */
  SL_ZIGBEE_COUNTER_MAC_RX_BROADCAST = 0,
  /** The MAC transmitted a broadcast Data frame, Command frame or Beacon.
   * destinationNodeId: BROADCAST_ADDRESS
   * data: not used
   */
  SL_ZIGBEE_COUNTER_MAC_TX_BROADCAST = 1,
  /** The MAC received a unicast Data or Command frame
   * destinationNodeId: MAC layer source or SL_ZIGBEE_UNKNOWN_NODE_ID
   *                    if no 16-bit source node ID is present in the frame
   * data: not used
   */
  SL_ZIGBEE_COUNTER_MAC_RX_UNICAST = 2,
  /** The MAC successfully transmitted a unicast Data or Command frame
   *   Note: Only frames with a 16-bit destination node ID are counted.
   * destinationNodeId: MAC layer destination address
   * data: not used
   */
  SL_ZIGBEE_COUNTER_MAC_TX_UNICAST_SUCCESS = 3,
  /** The MAC retried a unicast Data or Command frame after initial Tx attempt.
   *   Note: CSMA-related failures are tracked separately via
   *   SL_ZIGBEE_COUNTER_PHY_CCA_FAIL_COUNT.
   * destinationNodeId: MAC layer destination or SL_ZIGBEE_UNKNOWN_NODE_ID
   *                    if no 16-bit destination node ID is present in the frame
   * data: number of retries (after initial Tx attempt) accumulated so far
   *       for this packet. (Should always be >0.)
   */
  SL_ZIGBEE_COUNTER_MAC_TX_UNICAST_RETRY = 4,
  /** The MAC unsuccessfully transmitted a unicast Data or Command frame.
   *   Note: Only frames with a 16-bit destination node ID are counted.
   * destinationNodeId: MAC layer destination address
   * data: not used
   */
  SL_ZIGBEE_COUNTER_MAC_TX_UNICAST_FAILED = 5,

  /** The APS layer received a data broadcast.
   * destinationNodeId: sender's node ID
   * data: not used
   */
  SL_ZIGBEE_COUNTER_APS_DATA_RX_BROADCAST = 6,
  /** The APS layer transmitted a data broadcast. */
  SL_ZIGBEE_COUNTER_APS_DATA_TX_BROADCAST = 7,
  /** The APS layer received a data unicast.
   * destinationNodeId: sender's node ID
   * data: not used
   */
  SL_ZIGBEE_COUNTER_APS_DATA_RX_UNICAST = 8,
  /** The APS layer successfully transmitted a data unicast.
   * destinationNodeId: NWK destination address
   * data: number of APS retries (>=0) consumed for this unicast.
   */
  SL_ZIGBEE_COUNTER_APS_DATA_TX_UNICAST_SUCCESS = 9,
  /** The APS layer retried a unicast Data frame.  This is a placeholder
   * and is not used by the @c ::sl_zigbee_counters_handler() callback.  Instead,
   * the number of APS retries are returned in the data parameter
   * of the callback for the @c ::SL_ZIGBEE_COUNTER_APS_DATA_TX_UNICAST_SUCCESS
   * and @c ::SL_ZIGBEE_COUNTER_APS_DATA_TX_UNICAST_FAILED types.
   * However, our supplied Counters component code will attempt to collect this
   * information from the aforementioned counters and populate this counter.
   * Note that this counter's behavior differs from that of
   * @c ::SL_ZIGBEE_COUNTER_MAC_TX_UNICAST_RETRY .
   */
  SL_ZIGBEE_COUNTER_APS_DATA_TX_UNICAST_RETRY = 10,
  /* The APS layer unsuccessfully transmitted a data unicast.
   * destinationNodeId: NWK destination address
   * data: number of APS retries (>=0) consumed for this unicast.
   */
  SL_ZIGBEE_COUNTER_APS_DATA_TX_UNICAST_FAILED = 11,

  /** The network layer successfully submitted a new route discovery
   * to the MAC. */
  SL_ZIGBEE_COUNTER_ROUTE_DISCOVERY_INITIATED = 12,

  /** An entry was added to the neighbor table. */
  SL_ZIGBEE_COUNTER_NEIGHBOR_ADDED = 13,
  /** An entry was removed from the neighbor table. */
  SL_ZIGBEE_COUNTER_NEIGHBOR_REMOVED = 14,
  /** A neighbor table entry became stale because it had not been heard from. */
  SL_ZIGBEE_COUNTER_NEIGHBOR_STALE = 15,

  /** A node joined or rejoined to the network via this node.
   * destinationNodeId: node ID of child
   * data: not used
   */
  SL_ZIGBEE_COUNTER_JOIN_INDICATION = 16,
  /** An entry was removed from the child table.
   * destinationNodeId: node ID of child
   * data: not used
   */
  SL_ZIGBEE_COUNTER_CHILD_REMOVED = 17,

  /** EZSP-UART only. An overflow error occurred in the UART. */
  SL_ZIGBEE_COUNTER_ASH_OVERFLOW_ERROR = 18,
  /** EZSP-UART only. A framing error occurred in the UART. */
  SL_ZIGBEE_COUNTER_ASH_FRAMING_ERROR = 19,
  /** EZSP-UART only. An overrun error occurred in the UART. */
  SL_ZIGBEE_COUNTER_ASH_OVERRUN_ERROR = 20,

  /** A message was dropped at the Network layer because the NWK frame
      counter was not higher than the last message seen from that source. */
  SL_ZIGBEE_COUNTER_NWK_FRAME_COUNTER_FAILURE = 21,

  /** A message was dropped at the APS layer because the APS frame counter
      was not higher than the last message seen from that source.
      destinationNodeId: node ID of MAC source that relayed the message
      data: not used
   */
  SL_ZIGBEE_COUNTER_APS_FRAME_COUNTER_FAILURE = 22,

  /** EZSP-UART only. An XOFF was transmitted by the UART. */
  SL_ZIGBEE_COUNTER_ASH_XOFF = 23,

  /** An encrypted message was dropped by the APS layer because
   *  the sender's key has not been authenticated.
   *  As a result, the key is not authorized for use in APS data messages.
   *  destinationNodeId: SL_ZIGBEE_NULL_NODE_ID
   *  data: APS key table index related to the sender
   */
  SL_ZIGBEE_COUNTER_APS_LINK_KEY_NOT_AUTHORIZED = 24,

  /** A NWK encrypted message was received but dropped because decryption
   * failed.
   * destinationNodeId: sender of the dropped packet
   * data: not used
   */
  SL_ZIGBEE_COUNTER_NWK_DECRYPTION_FAILURE = 25,

  /** An APS encrypted message was received but dropped because decryption
   * failed.
   * destinationNodeId: sender of the dropped packet
   * data: not used
   */
  SL_ZIGBEE_COUNTER_APS_DECRYPTION_FAILURE = 26,

  /** The number of failures to allocate a set of linked packet buffers.
      This doesn't necessarily mean that the packet buffer count was
      0 at the time, but that the number requested was greater than the
      number free. */
  SL_ZIGBEE_COUNTER_ALLOCATE_PACKET_BUFFER_FAILURE = 27,

  /** The number of relayed unicast packets.
      destinationId: NWK layer destination address of relayed packet
      data: not used
   */
  SL_ZIGBEE_COUNTER_RELAYED_UNICAST = 28,

  /** The number of times a packet was dropped due to reaching the preset
   *  PHY-to-MAC queue limit (sli_mac_phy_to_mac_queue_length).  The limit will
   *  determine how many messages are accepted by the PHY between calls to
   *  sl_zigbee_tick(). After that limit is reached, packets will be dropped.
   *  The counter records the number of dropped packets.
   *
   *  NOTE: For each call to sl_zigbee_counters_handler() there may be more
   *  than 1 packet that was dropped due to the limit reached.  The
   *  actual number of packets dropped will be returned in the 'data'
   *  parameter passed to that function.
   *
   *  destinationNodeId: not used
   *  data: number of dropped packets represented by this counter event
   *  phyIndex: present
   */
  SL_ZIGBEE_COUNTER_PHY_TO_MAC_QUEUE_LIMIT_REACHED = 29,

  /** The number of times a packet was dropped due to the packet-validate
      library checking a packet and rejecting it due to length or
      other formatting problems.
      destinationNodeId: not used
      data: type of validation condition that failed
   */
  SL_ZIGBEE_COUNTER_PACKET_VALIDATE_LIBRARY_DROPPED_COUNT = 30,

  /** The number of times the NWK retry queue is full and a new
      message failed to be added.
      destinationNodeId; not used
      data: NWK retry queue size that has been exceeded
   */
  SL_ZIGBEE_COUNTER_TYPE_NWK_RETRY_OVERFLOW = 31,

  /** The number of times the PHY layer was unable to transmit due to
   * a failed CCA (Clear Channel Assessment) attempt.  See also:
   * SL_ZIGBEE_COUNTER_MAC_TX_UNICAST_RETRY.
   * destinationNodeId: MAC layer destination or SL_ZIGBEE_UNKNOWN_NODE_ID
   *                    if no 16-bit destination node ID is present in the frame
   * data: not used
   */
  SL_ZIGBEE_COUNTER_PHY_CCA_FAIL_COUNT = 32,

  /** The number of times a NWK broadcast was dropped because
      the broadcast table was full.
   */
  SL_ZIGBEE_COUNTER_BROADCAST_TABLE_FULL = 33,

  /** The number of times a low-priority packet traffic arbitration
      request has been made.
   */
  SL_ZIGBEE_COUNTER_PTA_LO_PRI_REQUESTED = 34,

  /** The number of times a high-priority packet traffic arbitration
      request has been made.
   */
  SL_ZIGBEE_COUNTER_PTA_HI_PRI_REQUESTED = 35,

  /** The number of times a low-priority packet traffic arbitration
      request has been denied.
   */
  SL_ZIGBEE_COUNTER_PTA_LO_PRI_DENIED = 36,

  /** The number of times a high-priority packet traffic arbitration
      request has been denied.
   */
  SL_ZIGBEE_COUNTER_PTA_HI_PRI_DENIED = 37,

  /** The number of times a low-priority packet traffic arbitration
      transmission has been aborted.
   */
  SL_ZIGBEE_COUNTER_PTA_LO_PRI_TX_ABORTED = 38,

  /** The number of times a high-priority packet traffic arbitration
      transmission has been aborted.
   */
  SL_ZIGBEE_COUNTER_PTA_HI_PRI_TX_ABORTED = 39,

  /** The number of times an address conflict has caused node_id change, and an address conflict error is sent
   */
  SL_ZIGBEE_COUNTER_ADDRESS_CONFLICT_SENT = 40,

  /** The number of times CSL failed to schedule Rx on target
   */
  SL_ZIGBEE_COUNTER_CSL_RX_SCHEDULE_FAILED = 41,

  /** A placeholder giving the number of Ember counter types. */
  SL_ZIGBEE_COUNTER_TYPE_COUNT = 42,
};

/**
 * @ brief Struct used to specify priorities for Zigbee radio operations
 */
typedef struct sl_802154_radio_priorities {
  /** The priority of a Zigbee RX operation while not receiving a packet. */
  uint8_t background_rx;
  /** Starting priority of a Zigbee TX operation. The first transmit of the packet, before retries, uses this priority */
  uint8_t min_tx_priority;
  /** The increase in TX priority (which is a decrement in value) for each retry */
  uint8_t tx_step;
  /** Maximum priority of a Zigbee TX operation. Retried messages have priorities bumped by tx_step, up to a maximum of max_tx_priority */
  uint8_t max_tx_priority;
  /** The priority of a Zigbee RX operation while receiving a packet */
  uint8_t active_rx;
} sl_802154_radio_priorities_t;

/**
 * @ brief Defines the CLI enumerations for the ::sl_zigbee_counter_type_t enum.
 */
#define SL_ZIGBEE_COUNTER_STRINGS    \
  "Mac Rx Bcast",                    \
  "Mac Tx Bcast",                    \
  "Mac Rx Ucast",                    \
  "Mac Tx Ucast",                    \
  "Mac Tx Ucast Retry",              \
  "Mac Tx Ucast Fail",               \
  "APS Rx Bcast",                    \
  "APS Tx Bcast",                    \
  "APS Rx Ucast",                    \
  "APS Tx Ucast Success",            \
  "APS Tx Ucast Retry",              \
  "APS Tx Ucast Fail",               \
  "Route Disc Initiated",            \
  "Neighbor Added",                  \
  "Neighbor Removed",                \
  "Neighbor Stale",                  \
  "Join Indication",                 \
  "Child Moved",                     \
  "ASH Overflow",                    \
  "ASH Frame Error",                 \
  "ASH Overrun Error",               \
  "NWK FC Failure",                  \
  "APS FC Failure",                  \
  "ASH XOff",                        \
  "APS Unauthorized Key",            \
  "NWK Decrypt Failures",            \
  "APS Decrypt Failures",            \
  "Packet Buffer Allocate Failures", \
  "Relayed Ucast",                   \
  "Phy to MAC queue limit reached",  \
  "Packet Validate drop count",      \
  "NWK retry overflow",              \
  "CCA Failures",                    \
  "Broadcast table full",            \
  "PTA Lo Pri Req",                  \
  "PTA Hi Pri Req",                  \
  "PTA Lo Pri Denied",               \
  "PTA Hi Pri Denied",               \
  "PTA Lo Pri Tx Abrt",              \
  "PTA Hi Pri Tx Abrt",              \
  "Address Conflict Sent",           \
  "CSL Rx schedule failed",          \
  NULL

typedef struct {
  uint8_t data;   // For now, might be number of retries or other values that previously were assigned to data.
  void *otherFields;  // For now, this might be destination nodeId, or phyIndex or both(extraCounterInfo).
} sl_zigbee_counter_info_t;

typedef struct {
  uint8_t phy_index;
  sl_802154_short_addr_t destinationNodeId;
  void *otherExtraFields;   //For now, this is NULL.
} sl_zigbee_extra_counters_info_t;

/** brief An identifier for a task. */
typedef uint8_t sl_zigbee_task_id_t;

//----------------------------------------------------------------
// Events and event queues.

/** @brief The control structure for events.
 *
 * This structure should not be accessed directly.
 * It holds the event status (one of the @e EMBER_EVENT_ values)
 * and the time left before the event fires.
 */
typedef struct {
  /** The event's status, either inactive or the units for timeToExecute. */
  sl_zigbee_event_units_t status;
  /** The ID of the task this event belongs to. */
  sl_zigbee_task_id_t taskid;
  /** Indicates how long before the event fires.
   *  Units are milliseconds.
   */
  uint32_t timeToExecute;
} sl_zigbee_event_control_t;

/** @brief Complete events with a control and a handler procedure.
 *
 * An application typically creates an array of events
 * along with their handlers.
 * The main loop passes the array to ::sl_zigbee_run_events() to call
 * the handlers of any events whose time has arrived.
 */
typedef struct {
  /** The control structure for the event. */
  sl_zigbee_event_control_t *control;
  /** The procedure to call when the event fires. */
  void (*handler)(void);
} sl_zigbee_event_data_t;

/** @brief The control structure for tasks.
 *
 * This structure should not be accessed directly.
 */
typedef struct {
  // The time when the next event associated with this task will fire.
  uint32_t nextEventTime;
  // The list of events associated with this task.
  sl_zigbee_event_data_t *events;
  // A flag that indicates the task has something to do other than events.
  bool busy;
} sl_zigbee_task_control_t;

/**
 * @name txPowerModes for sl_802154_set_tx_power_mode and mfglibSetPower
 */
//@{

/** @brief The application should call ::sl_802154_set_tx_power_mode() with the
 * txPowerMode parameter set to this value to disable all power mode options,
 * resulting in normal power mode and bi-directional RF transmitter output.
 */
#define SL_ZIGBEE_TX_POWER_MODE_DEFAULT             0x0000
/** @brief The application should call ::sl_802154_set_tx_power_mode() with the
 * txPowerMode parameter set to this value to enable boost power mode.
 */
#define SL_ZIGBEE_TX_POWER_MODE_BOOST               0x0001
/** @brief The application should call ::sl_802154_set_tx_power_mode() with the
 * txPowerMode parameter set to this value to enable the alternate transmitter
 * output.
 */
#define SL_ZIGBEE_TX_POWER_MODE_ALTERNATE           0x0002
/** @brief The application should call ::sl_802154_set_tx_power_mode() with the
 * txPowerMode parameter set to this value to enable both boost mode and the
 * alternate transmitter output.
 */
#define SL_ZIGBEE_TX_POWER_MODE_BOOST_AND_ALTERNATE (SL_ZIGBEE_TX_POWER_MODE_BOOST \
                                                     | SL_ZIGBEE_TX_POWER_MODE_ALTERNATE)
#ifndef DOXYGEN_SHOULD_SKIP_THIS
// The application does not ever need to call sl_802154_set_tx_power_mode() with the
// txPowerMode parameter set to this value.  This value is used internally by
// the stack to indicate that the default token configuration has not been
// overridden by a prior call to sl_802154_set_tx_power_mode().
#define SL_ZIGBEE_TX_POWER_MODE_USE_TOKEN           0x8000
#endif //DOXYGEN_SHOULD_SKIP_THIS

//@} \\END  Definitions

/**
 * @name Counters Request Definitions
 */
//@{

/** @brief This is a ZigBee application profile ID that has been
 * assigned to Ember Corporation.
 *
 * It is used to send for sending messages
 * that have a specific, non-standard, interaction with the Ember stack.
 * Its only current use is for stack counters requests.
 */
#define SL_ZIGBEE_PRIVATE_PROFILE_ID  0xC00Eu

/**
 * @brief Ember's first private profile ID.
 */
#define SL_ZIGBEE_PRIVATE_PROFILE_ID_START 0xC00Du

/**
 * @brief Ember's last private profile ID.
 */
#define SL_ZIGBEE_PRIVATE_PROFILE_ID_END   0xC016u

/** The cluster ID used to request that a node respond with a report of its
 * Ember stack counters.  See app/util/counters/counters-ota.h.
 */
#define SL_ZIGBEE_REPORT_COUNTERS_REQUEST 0x0003u

/** The cluster ID used to respond to an SL_ZIGBEE_REPORT_COUNTERS_REQUEST. */
#define SL_ZIGBEE_REPORT_COUNTERS_RESPONSE 0x8003u

/** The cluster ID used to request that a node respond with a report of its
 * Ember stack counters.  The node will also reset its clusters to zero after
 * a successful response.  See app/util/counters/counters-ota.h.
 */
#define SL_ZIGBEE_REPORT_AND_CLEAR_COUNTERS_REQUEST 0x0004u

/** The cluster ID used to respond to an SL_ZIGBEE_REPORT_AND_CLEAR_COUNTERS_REQUEST. */
#define SL_ZIGBEE_REPORT_AND_CLEAR_COUNTERS_RESPONSE 0x8004u

/** The cluster ID used to send and receive over the air certificate messages.
 *  This is used to field upgrade devices with Smart Energy Certificates and
 *  other security data.
 */
#define SL_ZIGBEE_OTA_CERTIFICATE_UPGRADE_CLUSTER 0x0005u

//@} \\END Counters Request Definitions

/** @brief This data structure contains the key data that is passed
 *   into various other functions. */
typedef struct {
  /** This is the key byte data. */
  uint8_t contents[SL_ZIGBEE_ENCRYPTION_KEY_SIZE];
} sl_zigbee_key_data_t;

/** @brief This data structure contains the certificate data that is used
    for Certificate Based Key Exchange (CBKE). */
typedef struct {
  uint8_t contents[SL_ZIGBEE_CERTIFICATE_SIZE];
} sl_zigbee_certificate_data_t;

/** @brief This data structure contains the public key data that is used
    for Certificate Based Key Exchange (CBKE). */
typedef struct {
  uint8_t contents[SL_ZIGBEE_PUBLIC_KEY_SIZE];
} sl_zigbee_public_key_data_t;

/** @brief This data structure contains the private key data that is used
    for Certificate Based Key Exchange (CBKE). */
typedef struct {
  uint8_t contents[SL_ZIGBEE_PRIVATE_KEY_SIZE];
} sl_zigbee_private_key_data_t;

/** @brief This data structure contains the Shared Message Authentication Code
    (SMAC) data that is used for Certificate Based Key Exchange (CBKE). */
typedef struct {
  uint8_t contents[SL_ZIGBEE_SMAC_SIZE];
} sl_zigbee_smac_data_t;

/** @brief This data structure contains a DSA signature.  It is the bit
      concatenation of the 'r' and 's' components of the signature.
 */
typedef struct {
  uint8_t contents[SL_ZIGBEE_SIGNATURE_SIZE];
} sl_zigbee_signature_data_t;

/** @brief This data structure contains an AES-MMO Hash (the message digest).
 */
typedef struct {
  uint8_t contents[SL_ZIGBEE_AES_HASH_BLOCK_SIZE];
} sl_zigbee_message_digest_t;

/** @brief This data structure contains the context data when calculating
 *  an AES MMO hash (message digest).
 */
typedef struct {
  uint8_t result[SL_ZIGBEE_AES_HASH_BLOCK_SIZE];
  uint32_t length;
} sl_zigbee_aes_mmo_hash_context_t;

/** @brief This data structure contains the certificate data that is used
    for Certificate Based Key Exchange (CBKE) in SECT283k1 Elliptical Cryptography. */
typedef struct {
  /* This is the certificate byte data. */
  uint8_t contents[SL_ZIGBEE_CERTIFICATE_283K1_SIZE];
} sl_zigbee_certificate_283k1_data_t;

/** @brief This data structure contains the public key data that is used
    for Certificate Based Key Exchange (CBKE) in SECT283k1 Elliptical Cryptography. */
typedef struct {
  uint8_t contents[SL_ZIGBEE_PUBLIC_KEY_283K1_SIZE];
} sl_zigbee_public_key_283k1_data_t;

/** @brief This data structure contains the private key data that is used
    for Certificate Based Key Exchange (CBKE) in SECT283k1 Elliptical Cryptography. */
typedef struct {
  uint8_t contents[SL_ZIGBEE_PRIVATE_KEY_283K1_SIZE];
} sl_zigbee_private_key_283k1_data_t;

/** @brief This data structure contains a DSA signature used in SECT283k1
    Elliptical Cryptography.
    It is the bit concatenation of the 'r' and 's' components of the signature.
 */
typedef struct {
  uint8_t contents[SL_ZIGBEE_SIGNATURE_283K1_SIZE];
} sl_zigbee_signature_283k1_data_t;

/** @brief This is an ::sl_zigbee_initial_security_bitmask_t value but it does not
 *    actually set anything.  It is the default mode used by the ZigBee Pro
 *    stack.  It is defined here so that no legacy code is broken by referencing
 *    it.
 */
#define SL_ZIGBEE_STANDARD_SECURITY_MODE 0x0000

/** @brief The short address of the trust center.
 * This address never changes dynamically.
 */
#define SL_ZIGBEE_TRUST_CENTER_NODE_ID 0x0000u

/** @brief This is the Initial Security Bitmask that controls the use of various
 *  security features.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_initial_security_bitmask_t
#else
typedef uint16_t sl_zigbee_initial_security_bitmask_t;
enum
#endif
{
  /** Enables Distributed Trust Center Mode for the device forming the
      network. (Previously known as ::SL_ZIGBEE_NO_TRUST_CENTER_MODE) */
  SL_ZIGBEE_DISTRIBUTED_TRUST_CENTER_MODE       = 0x0002,
  /** Enables a Global Link Key for the Trust Center. All nodes will share
      the same Trust Center Link Key. */
  SL_ZIGBEE_TRUST_CENTER_GLOBAL_LINK_KEY        = 0x0004,
  /** Enables devices that perform MAC Association with a pre-configured
      Network Key to join the network.  It is only set on the Trust Center. */
  SL_ZIGBEE_PRECONFIGURED_NETWORK_KEY_MODE      = 0x0008,

#if !defined DOXYGEN_SHOULD_SKIP_THIS
  // Hidden fields used internally.
  SL_ZIGBEE_HAVE_TRUST_CENTER_UNKNOWN_KEY_TOKEN = 0x0010,
  SL_ZIGBEE_HAVE_TRUST_CENTER_LINK_KEY_TOKEN    = 0x0020,
#endif
  /** This denotes that the ::sl_zigbee_initial_security_state_t::preconfiguredTrustCenterEui64
      has a value in it containing the trust center EUI64.  The device will only
      join a network and accept commands from a trust center with that EUI64.
      Normally this bit is NOT set and the EUI64 of the trust center is learned
      during the join process.  When commissioning a device to join onto
      an existing network that is using a trust center and without sending any
      messages, this bit must be set and the field
      ::sl_zigbee_initial_security_state_t::preconfiguredTrustCenterEui64 must be
      populated with the appropriate EUI64.
   */
  SL_ZIGBEE_HAVE_TRUST_CENTER_EUI64             = 0x0040,

  /** This denotes that the ::sl_zigbee_initial_security_state_t::preconfiguredKey
      is not the actual Link Key but a Root Key known only to the Trust Center.
      It is hashed with the IEEE Address of the destination device
      to create the actual Link Key used in encryption.  This is bit is only
      used by the Trust Center.  The joining device need not set this.
   */
  SL_ZIGBEE_TRUST_CENTER_USES_HASHED_LINK_KEY   = 0x0084,

  /** This denotes that the ::sl_zigbee_initial_security_state_t::preconfiguredKey
   *  element has valid data that should be used to configure the initial
   *  security state. */
  SL_ZIGBEE_HAVE_PRECONFIGURED_KEY              = 0x0100,
  /** This denotes that the ::sl_zigbee_initial_security_state_t::networkKey
   *  element has valid data that should be used to configure the initial
   *  security state. */
  SL_ZIGBEE_HAVE_NETWORK_KEY                    = 0x0200,
  /** This denotes to a joining node that it should attempt to
   *  acquire a Trust Center Link Key during joining. This is
   *  necessary if the device does not have a pre-configured
   *  key, or wants to obtain a new one (since it may be using a
   *  well-known key during joining). */
  SL_ZIGBEE_GET_LINK_KEY_WHEN_JOINING           = 0x0400,
  /** This denotes that a joining device should only accept an encrypted
   *  network key from the Trust Center (using its pre-configured key).
   *  A key sent in-the-clear by the Trust Center will be rejected
   *  and the join will fail.  This option is only valid when using
   *  a pre-configured key. */
  SL_ZIGBEE_REQUIRE_ENCRYPTED_KEY               = 0x0800,
  /** This denotes whether the device should NOT reset its outgoing frame
   *  counters (both NWK and APS) when ::sl_zigbee_set_initial_security_state() is
   *  called.  Normally it is advised to reset the frame counter before
   *  joining a new network.  However, when a device is joining
   *  to the same network again (but not using ::emberRejoinNetwork()),
   *  it should keep the NWK and APS frame counters stored in its tokens.
   *
   *  NOTE: The application is allowed to dynamically change the behavior
   *  via SL_ZIGBEE_EXT_NO_FRAME_COUNTER_RESET field.
   */
  SL_ZIGBEE_NO_FRAME_COUNTER_RESET              = 0x1000,
  /** This denotes that the device should obtain its pre-configured key from
   *  an installation code stored in the manufacturing token.  The token
   *  contains a value that will be hashed to obtain the actual
   *  pre-configured key.  If that token is not valid, the call
   *  to ::sl_zigbee_set_initial_security_state() will fail. */
  SL_ZIGBEE_GET_PRECONFIGURED_KEY_FROM_INSTALL_CODE = 0x2000,

#if !defined DOXYGEN_SHOULD_SKIP_THIS
  // Internal data
  EM_SAVED_IN_TOKEN                         = 0x4000,
  #define EM_SECURITY_INITIALIZED           0x00008000L
#else
  /* All other bits are reserved and must be zero. */
#endif
};

/** @brief This is the Extended Security Bitmask that controls the use
 *  of various extended security features.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_extended_security_bitmask_t
#else
typedef uint16_t sl_zigbee_extended_security_bitmask_t;
enum
#endif
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  // If this bit is set, the 'key token data' field is set in the Initial
  // Security Bitmask to 0 (No Preconfig Key token). Otherwise, the
  // field is left as is.
  SL_ZIGBEE_PRECONFIG_KEY_NOT_VALID       = 0x0001,
#endif

  // bits 2-3 are unused.
  /** This denotes that the network key update can only happen if the network
      key update request is unicast and encrypted i.e. broadcast network key update
      requests will not be processed if bit 1 is set*/
  SL_ZIGBEE_SECURE_NETWORK_KEY_ROTATION   = 0x0002,

  /** This denotes whether a joiner node (router or end-device) uses a Global
      Link Key or a Unique Link Key. */
  SL_ZIGBEE_JOINER_GLOBAL_LINK_KEY        = 0x0010,

  /** This denotes whether the device's outgoing frame counter is allowed to
      be reset during forming or joining. If the flag is set, the outgoing frame
      counter is not allowed to be reset. If the flag is not set, the frame
      counter is allowed to be reset. */

  SL_ZIGBEE_EXT_NO_FRAME_COUNTER_RESET    = 0x0020,

  /** This denotes whether a device should discard or accept network leave
      without rejoin commands. */
  SL_ZIGBEE_NWK_LEAVE_WITHOUT_REJOIN_NOT_ALLOWED = 0x0040,

  // Bit 7 reserved for future use (stored in TOKEN).

  /** This denotes whether a router node should discard or accept network Leave
      Commands. */
  SL_ZIGBEE_NWK_LEAVE_REQUEST_NOT_ALLOWED = 0x0100,

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** This denotes whether a node is running the latest stack specification or
      is emulating R18 specs behavior. If this flag is enabled, a router
      node should only send encrypted Update Device messages while the TC should
      only accept encrypted Updated Device messages.*/
  SL_ZIGBEE_R18_STACK_BEHAVIOR            = 0x0200,
#endif

  // Bit 10 is reserved for future use (stored in TOKEN).
  // Bit 11 is reserved for future use(stored in RAM).

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  // Bit 12 - This denotes whether an end device should discard or accept ZDO Leave
  // from a network node other than its parent.
  SL_ZIGBEE_ZDO_LEAVE_FROM_NON_PARENT_NOT_ALLOWED = 0x1000,
#endif

  // Bits 13-15 are unused.
};

/** @brief This denotes that the device can require a resync of the APS frame counter.
 */
#define SL_ZIGBEE_TC_SUPPORTS_FC_SYNC   0x00800000UL

/** @brief This is the legacy name for the Distributed Trust Center Mode.
 */
#define SL_ZIGBEE_NO_TRUST_CENTER_MODE   SL_ZIGBEE_DISTRIBUTED_TRUST_CENTER_MODE

/** @brief This is the legacy name for the Trust Center Global Link Key.
 */
#define SL_ZIGBEE_GLOBAL_LINK_KEY   SL_ZIGBEE_TRUST_CENTER_GLOBAL_LINK_KEY

#if !defined DOXYGEN_SHOULD_SKIP_THIS
  #define NO_TRUST_CENTER_KEY_TOKEN        0x0000
  #define TRUST_CENTER_KEY_TOKEN_MASK      0x0030
  #define SECURITY_BIT_TOKEN_MASK          0x71FF
// If this bit is on, it indicates that the TC token does not hold the TC key
// It lives in PSA at a fixed ID (see ZB SM)
  #define TRUST_CENTER_KEY_LIVES_IN_PSA    0x8000

  #define SECURITY_LOWER_BIT_MASK          0x000000FF  // ""
  #define SECURITY_UPPER_BIT_MASK          0x00FF0000L // ""
#endif

/** @brief This describes the Initial Security features and requirements that
 *  will be used when forming or joining the network.  */
typedef struct {
  /** This bitmask enumerates which security features should be used
      and the presence of valid data within other elements of the
      ::sl_zigbee_initial_security_state_t data structure.  For more details, see the
      ::sl_zigbee_initial_security_bitmask_t. */
  uint16_t bitmask;
  /** This is the pre-configured key that can be used by devices when joining the
   *  network if the Trust Center does not send the initial security data
   *  in-the-clear.
   *  For the Trust Center, it will be the global link key and <b>must</b> be set
   *  regardless of whether joining devices are expected to have a pre-configured
   *  Link Key.
   *  This parameter will only be used if the sl_zigbee_initial_security_state_t::bitmask
   *  sets the bit indicating ::SL_ZIGBEE_HAVE_PRECONFIGURED_KEY. */
  sl_zigbee_key_data_t preconfiguredKey;
  /** This is the Network Key used when initially forming the network.
   *  It must be set on the Trust Center and is not needed for devices
   *  joining the network.  This parameter will only be used if the
   *  sl_zigbee_initial_security_state_t::bitmask sets the bit indicating
   *  ::SL_ZIGBEE_HAVE_NETWORK_KEY.  */
  sl_zigbee_key_data_t networkKey;
  /** This is the sequence number associated with the network key.  It must
   *  be set if the Network Key is set and is used to indicate a particular
   *  of the network key for updating and switching.  This parameter will
   *  only be used if the ::SL_ZIGBEE_HAVE_NETWORK_KEY is set. Generally, it should
   *  be set to 0 when forming the network; joining devices can ignore
   *  this value.  */
  uint8_t networkKeySequenceNumber;
  /** This is the long address of the trust center on the network that will
   *  be joined.  It is usually NOT set prior to joining the network and
   *  is learned during the joining message exchange.  This field
   *  is only examined if ::SL_ZIGBEE_HAVE_TRUST_CENTER_EUI64 is set in the
   *  sl_zigbee_initial_security_state_t::bitmask.  Most devices should clear that
   *  bit and leave this field alone.  This field must be set when using
   *  commissioning mode.  It is required to be in little-endian format. */
  sl_802154_long_addr_t preconfiguredTrustCenterEui64;
} sl_zigbee_initial_security_state_t;

/** @brief This is the Current Security Bitmask that details the use of various
 *  security features.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_current_security_bitmask_t
#else
typedef uint16_t sl_zigbee_current_security_bitmask_t;
enum
#endif
{
#if defined DOXYGEN_SHOULD_SKIP_THIS
  // These options are the same for Initial and Current Security state.

  /** This denotes that the device is running in a network with ZigBee
   *  Standard Security. */
  SL_ZIGBEE_STANDARD_SECURITY_MODE_             = 0x0000,
  /** This denotes that the device is running in a network without
   *  a centralized Trust Center. */
  SL_ZIGBEE_DISTRIBUTED_TRUST_CENTER_MODE_      = 0x0002,
  /** This denotes that the device has a Global Link Key.  The Trust Center
   *  Link Key is the same across multiple nodes. */
  SL_ZIGBEE_TRUST_CENTER_GLOBAL_LINK_KEY_       = 0x0004,
#else
  // Bit 3 reserved
#endif
  /** This denotes that the node has a Trust Center Link Key. */
  SL_ZIGBEE_HAVE_TRUST_CENTER_LINK_KEY          = 0x0010,

  /** This denotes that the Trust Center is using a Hashed Link Key. */
  SL_ZIGBEE_TRUST_CENTER_USES_HASHED_LINK_KEY_   = 0x0084,

  // Bits 1, 5, 6, and 8-15 reserved.
};

#if !defined DOXYGEN_SHOULD_SKIP_THIS
  #define INITIAL_AND_CURRENT_BITMASK         0x00FF
#endif

/** @brief This describes the security features used by the stack for a
 *  joined device. */
typedef struct {
  /** This bitmask indicates the security features currently in use
   *  on this node. */
  sl_zigbee_current_security_bitmask_t bitmask;
  /** This indicates the EUI64 of the Trust Center.  It will be all zeroes
      if the Trust Center Address is not known (i.e., the device is in a
      Distributed Trust Center network). */
  sl_802154_long_addr_t trustCenterLongAddress;
} sl_zigbee_current_security_state_t;

/** @brief This bitmask describes the presence of fields within the
 *  ::sl_zigbee_key_struct_t. */

#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_key_struct_bitmask_t
#else
typedef uint16_t sl_zigbee_key_struct_bitmask_t;
enum
#endif
{
  /** This indicates that the key has a sequence number associated with it.
      (i.e., a Network Key). */
  SL_ZIGBEE_KEY_HAS_SEQUENCE_NUMBER        = 0x0001,
  /** This indicates that the key has an outgoing frame counter and the
      corresponding value within the ::sl_zigbee_key_struct_t has been populated.*/
  SL_ZIGBEE_KEY_HAS_OUTGOING_FRAME_COUNTER = 0x0002,
  /** This indicates that the key has an incoming frame counter and the
      corresponding value within the ::sl_zigbee_key_struct_t has been populated.*/
  SL_ZIGBEE_KEY_HAS_INCOMING_FRAME_COUNTER = 0x0004,
  /** This indicates that the key has an associated Partner EUI64 address and
      the corresponding value within the ::sl_zigbee_key_struct_t has been populated.*/
  SL_ZIGBEE_KEY_HAS_PARTNER_EUI64          = 0x0008,
  /** This indicates the key is authorized for use in APS data messages.
      If the key is not authorized for use in APS data messages it has not
      yet gone through a key agreement protocol, such as CBKE (i.e., ECC). */
  SL_ZIGBEE_KEY_IS_AUTHORIZED              = 0x0010,
  /** This indicates that the partner associated with the link is a sleepy
      end device.  This bit is set automatically if the local device
      hears a device announce from the partner indicating it is not
      an 'RX on when idle' device.  */
  SL_ZIGBEE_KEY_PARTNER_IS_SLEEPY          = 0x0020,
  /** This indicates that the transient key which is being added is unconfirmed.
     This bit is set when we add a transient key while the sl_zigbee_tc_link_key_request_policy_t
     is SL_ZIGBEE_ALLOW_TC_LINK_KEY_REQUEST_AND_GENERATE_NEW_KEY*/
  SL_ZIGBEE_UNCONFIRMED_TRANSIENT_KEY      = 0x0040,
  /** This indicates that the actual key data is stored in PSA, and the
   * respective PSA ID is recorded in the psa_id field. */
  SL_ZIGBEE_KEY_HAS_PSA_ID                 = 0x0080,
  /** This indicates that the keyData field has valid data. On certain parts and
   * depending on the security configuration, keys may live in secure storage
   * and are not exportable. In such cases, keyData will not house the actual
   * key contents. */
  SL_ZIGBEE_KEY_HAS_KEY_DATA               = 0x0100,
  /** This indicates that the key represents a Device Authentication Token
   * and is not an encryption key.  The Authentication token is persisted
   * for the lifetime of the device on the network and used to validate
   * and update the device connection. It is only removed when the device
   * leaves or is decommissioned from the network
   */
  SL_ZIGBEE_KEY_IS_AUTHENTICATION_TOKEN    = 0x0200,
  /** This indicates that the key has been derived by the Dynamic Link Key
   * feature.
   */
  SL_ZIGBEE_DLK_DERIVED_KEY                = 0x0400,
  /** This indicates that the device this key is being used to communicate with
   * supports the APS frame counter synchronization procedure.
   */
  SL_ZIGBEE_KEY_FC_SYNC_SUPPORTED           = 0x0800,
};

/** @brief This data structure contains the transient key data that is used
    during Zigbee 3.0 joining. */
typedef struct {
  sl_802154_long_addr_t eui64;
  uint32_t incomingFrameCounter;
  sl_zigbee_key_struct_bitmask_t bitmask;
  uint16_t remainingTimeSeconds;
  uint8_t networkIndex;
  union {
    sl_zigbee_key_data_t keyData; // valid only if bitmask & SL_ZIGBEE_KEY_HAS_KEY_DATA (on some parts, keys are stored in secure storage and not RAM)
    uint32_t psa_id;      // valid only if bitmask & SL_ZIGBEE_KEY_HAS_PSA_ID (on some parts, keys are stored in secure storage and not RAM)
  };
} sl_zigbee_transient_key_data_t;

/** @brief This denotes the type of security key. */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_key_type_t
#else
typedef uint8_t sl_zigbee_key_type_t;
enum
#endif
{
  /** This denotes that the key is a Trust Center Link Key. */
  SL_ZIGBEE_TRUST_CENTER_LINK_KEY         = 1,
  /** This denotes that the key is the Current Network Key. */
  SL_ZIGBEE_CURRENT_NETWORK_KEY           = 3,
  /** This denotes that the key is the Next Network Key. */
  SL_ZIGBEE_NEXT_NETWORK_KEY              = 4,
  /** This denotes that the key is an Application Link Key. */
  SL_ZIGBEE_APPLICATION_LINK_KEY          = 5,
};

/** @brief This describes a one of several different types of keys and its
 *   associated data.
 */
typedef struct {
  /** This bitmask indicates whether various fields in the structure
   *  contain valid data. It also contains the index of the network
   *  the key belongs to. */
  sl_zigbee_key_struct_bitmask_t bitmask;
  /** This indicates the type of the security key. */
  sl_zigbee_key_type_t type;
  union {
    /** This is the actual key data. It will contain valid data based on the
     *  ::sl_zigbee_key_struct_bitmask_t. */
    sl_zigbee_key_data_t key;
    /** Internal only: the PSA ID that this key struct maps to. It will contain
     *  valid data based on the ::sl_zigbee_key_struct_bitmask_t. */
    uint32_t psa_id;
  };
  /** This is the outgoing frame counter associated with the key.  It will
   *  contain valid data based on the ::sl_zigbee_key_struct_bitmask_t. */
  uint32_t outgoingFrameCounter;
  /** This is the incoming frame counter associated with the key.  It will
   *  contain valid data based on the ::sl_zigbee_key_struct_bitmask_t. */
  uint32_t incomingFrameCounter;
  /** This is the sequence number associated with the key.  It will
   *  contain valid data based on the ::sl_zigbee_key_struct_bitmask_t. */
  uint8_t sequenceNumber;
  /** This is the Partner EUI64 associated with the key.  It will
   *  contain valid data based on the ::sl_zigbee_key_struct_bitmask_t. */
  sl_802154_long_addr_t partnerEUI64;
} sl_zigbee_key_struct_t;

/** @brief This denotes the status of an attempt to establish
 *  a key with another device.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_key_status_t
#else
typedef uint8_t sl_zigbee_key_status_t;
enum
#endif
{
  SL_ZIGBEE_KEY_STATUS_NONE                    = 0x00,
  SL_ZIGBEE_APP_LINK_KEY_ESTABLISHED           = 0x01,
  SL_ZIGBEE_TRUST_CENTER_LINK_KEY_ESTABLISHED  = 0x03,

  SL_ZIGBEE_KEY_ESTABLISHMENT_TIMEOUT          = 0x04,
  SL_ZIGBEE_KEY_TABLE_FULL                     = 0x05,

  // These are success status values applying only to the
  // Trust Center answering key requests.
  SL_ZIGBEE_TC_RESPONDED_TO_KEY_REQUEST        = 0x06,
  SL_ZIGBEE_TC_APP_KEY_SENT_TO_REQUESTER       = 0x07,

  // These are failure status values applying only to the
  // Trust Center answering key requests.
  SL_ZIGBEE_TC_RESPONSE_TO_KEY_REQUEST_FAILED  = 0x08,
  SL_ZIGBEE_TC_REQUEST_KEY_TYPE_NOT_SUPPORTED  = 0x09,
  SL_ZIGBEE_TC_NO_LINK_KEY_FOR_REQUESTER       = 0x0A,
  SL_ZIGBEE_TC_REQUESTER_EUI64_UNKNOWN         = 0x0B,
  SL_ZIGBEE_TC_RECEIVED_FIRST_APP_KEY_REQUEST  = 0x0C,
  SL_ZIGBEE_TC_TIMEOUT_WAITING_FOR_SECOND_APP_KEY_REQUEST = 0x0D,
  SL_ZIGBEE_TC_NON_MATCHING_APP_KEY_REQUEST_RECEIVED      = 0x0E,
  SL_ZIGBEE_TC_FAILED_TO_SEND_APP_KEYS         = 0x0F,
  SL_ZIGBEE_TC_FAILED_TO_STORE_APP_KEY_REQUEST = 0x10,
  SL_ZIGBEE_TC_REJECTED_APP_KEY_REQUEST        = 0x11,
  SL_ZIGBEE_TC_FAILED_TO_GENERATE_NEW_KEY      = 0x12,
  SL_ZIGBEE_TC_FAILED_TO_SEND_TC_KEY           = 0x13,

  // These are generic status values for a key requester.
  SL_ZIGBEE_TRUST_CENTER_IS_PRE_R21            = 0x1E,

  // These are status values applying only to the Trust Center
  // verifying link keys.
  SL_ZIGBEE_TC_REQUESTER_VERIFY_KEY_TIMEOUT    = 0x32,
  SL_ZIGBEE_TC_REQUESTER_VERIFY_KEY_FAILURE    = 0x33,
  SL_ZIGBEE_TC_REQUESTER_VERIFY_KEY_SUCCESS    = 0x34,

  // These are status values applying only to the key requester
  // verifying link keys.
  SL_ZIGBEE_VERIFY_LINK_KEY_FAILURE            = 0x64,
  SL_ZIGBEE_VERIFY_LINK_KEY_SUCCESS            = 0x65,
};

/** @brief This enumeration determines whether or not a Trust Center
 *  answers trust center link key requests.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_tc_link_key_request_policy_t
#else
typedef uint8_t sl_zigbee_tc_link_key_request_policy_t;
enum
#endif
{
  SL_ZIGBEE_DENY_TC_LINK_KEY_REQUESTS  = 0x00,
  SL_ZIGBEE_ALLOW_TC_LINK_KEY_REQUEST_AND_SEND_CURRENT_KEY = 0x01,
  // When using the following mode a unique random link key is created.
  // The key which is generated due to this mode is added to the link
  // key table. Therefore make sure that the link key table size is not
  // zero as this can result in the newly generated key not being saved
  // and communication breaking between the trust center and the nodes.
  SL_ZIGBEE_ALLOW_TC_LINK_KEY_REQUEST_AND_GENERATE_NEW_KEY = 0x02
};

/** @brief This enumeration determines whether or not a Trust Center
 *  answers app link key requests.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_app_link_key_request_policy_t
#else
typedef uint8_t sl_zigbee_app_link_key_request_policy_t;
enum
#endif
{
  SL_ZIGBEE_DENY_APP_LINK_KEY_REQUESTS  = 0x00,
  SL_ZIGBEE_ALLOW_APP_LINK_KEY_REQUEST = 0x01
};

/** @brief This function allows access
 *  to the actual key data bytes of the sl_zigbee_key_data_t structure.
 *
 * @param key  A pointer to an sl_zigbee_key_data_t structure.
 *
 * @return uint8_t* Returns a pointer to the first byte of the Key data.
 */
#if defined DOXYGEN_SHOULD_SKIP_THIS
uint8_t* sl_zigbee_key_contents(sl_zigbee_key_data_t *key);
#else
#define sl_zigbee_key_contents(key) ((key)->contents)
#endif

/** @brief Get access
 *  to the actual certificate data bytes of the sl_zigbee_certificate_data_t structure.
 *
 * @param cert  A pointer to an ::sl_zigbee_certificate_data_t structure.
 *
 * @return uint8_t* Returns a pointer to the first byte of the certificate data.
 */
#if defined DOXYGEN_SHOULD_SKIP_THIS
uint8_t* sl_zigbee_certificate_contents(sl_zigbee_certificate_data_t *cert);
#else
#define sl_zigbee_certificate_contents(cert) ((cert)->contents)
#endif

/** @brief Get access
 *  to the actual public key data bytes of the sl_zigbee_public_key_data_t structure.
 *
 * @param key  A pointer to an sl_zigbee_public_key_data_t structure.
 *
 * @return uint8_t* Returns a pointer to the first byte of the public key data.
 */
#if defined DOXYGEN_SHOULD_SKIP_THIS
uint8_t* sl_zigbee_public_key_contents(sl_zigbee_public_key_data_t *key);
#else
#define sl_zigbee_public_key_contents(key) ((key)->contents)
#endif

/** @brief Get access
 *  to the actual private key data bytes of the sl_zigbee_private_key_data_t structure.
 *
 * @param key  A pointer to an sl_zigbee_private_key_data_t structure.
 *
 * @return uint8_t* Returns a pointer to the first byte of the private key data.
 */
#if defined DOXYGEN_SHOULD_SKIP_THIS
uint8_t* sl_zigbee_private_key_contents(sl_zigbee_private_key_data_t *key);
#else
#define sl_zigbee_private_key_contents(key) ((key)->contents)
#endif

/** @brief Get access to the
 *  actual SMAC (Secured Message Authentication Code) data of the
 *  sl_zigbee_smac_data_t structure.
 */
#if defined DOXYGEN_SHOULD_SKIP_THIS
uint8_t* sl_zigbee_smac_contents(sl_zigbee_smac_data_t *key);
#else
#define sl_zigbee_smac_contents(key) ((key)->contents)
#endif

/** @brief Get access to the
 *  actual ECDSA signature data of the sl_zigbee_signature_data_t structure.
 */
#if defined DOXYGEN_SHOULD_SKIP_THIS
uint8_t* sl_zigbee_signature_contents(sl_zigbee_signature_data_t *sig);
#else
#define sl_zigbee_signature_contents(sig) ((sig)->contents)
#endif

/** @brief Get access
 *  to the actual certificate data bytes of the sl_zigbee_283k1_certificate_data_t structure.
 *
 * @param cert  A pointer to an ::sl_zigbee_283k1_certificate_data_t structure.
 *
 * @return uint8_t* Returns a pointer to the first byte of the certificate data.
 */
#if defined DOXYGEN_SHOULD_SKIP_THIS
uint8_t* sl_zigbee_certificate_283k1_contents(sl_zigbee_certificate_283k1_data_t *cert);
#else
#define sl_zigbee_certificate_283k1_contents(cert) ((cert)->contents)
#endif

/** @brief Get access
 *  to the actual public key data bytes of the sl_zigbee_283k1_public_key_data_t structure.
 *
 * @param key  A pointer to an sl_zigbee_283k1_public_key_data_t structure.
 *
 * @return uint8_t* Returns a pointer to the first byte of the public key data.
 */
#if defined DOXYGEN_SHOULD_SKIP_THIS
uint8_t* sl_zigbee_public_key_283k1_contents(sl_zigbee_public_key_283k1_data_t *key);
#else
#define sl_zigbee_public_key_283k1_contents(key) ((key)->contents)
#endif

/** @brief Get access
 *  to the actual private key data bytes of the sl_zigbee_283k1_private_key_data_t structure.
 *
 * @param key  A pointer to an sl_zigbee_283k1_private_key_data_t structure.
 *
 * @return uint8_t* Returns a pointer to the first byte of the private key data.
 */
#if defined DOXYGEN_SHOULD_SKIP_THIS
uint8_t* sl_zigbee_private_key_283k1_contents(sl_zigbee_private_key_283k1_data_t *key);
#else
#define sl_zigbee_private_key_283k1_contents(key) ((key)->contents)
#endif

/** @brief Get access to the
 *  actual ECDSA signature data of the sl_zigbee_signature_283k1_data_t structure.
 */
#if defined DOXYGEN_SHOULD_SKIP_THIS
uint8_t* ember283k1SignatureContents(sl_zigbee_signature_283k1_data_t *sig);
#else
#define ember283k1SignatureContents(sig) ((sig)->contents)
#endif

#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_key_settings_t
#else
typedef uint16_t sl_zigbee_key_settings_t;
enum
#endif
{
  SL_ZIGBEE_KEY_PERMISSIONS_NONE            = 0x0000,
  SL_ZIGBEE_KEY_PERMISSIONS_READING_ALLOWED = 0x0001,
  SL_ZIGBEE_KEY_PERMISSIONS_HASHING_ALLOWED = 0x0002,
};

/** @brief This structure is used to get/set the security configuration that
 *    is stored in manufacturing tokens.
 */
typedef struct {
  sl_zigbee_key_settings_t keySettings;
} sl_zigbee_mfg_security_struct_t;

/** @brief This magic number prevents accidentally changing the key settings.
 *    The ::sl_zigbee_set_mfg_security_config() API will return SL_ZIGBEE_INVALID_CALL
 *    unless it is passed in.
 */
#define SL_LEGACY_SECURITY_CONFIG_MAGIC_NUMBER 0xCABAD11FUL

/**
 * @brief A structure containing duty cycle limit configurations.
 *
 * All limits are absolute and are required to be as follows: suspLimit > critThresh > limitThresh
 * For example:  suspLimit = 250 (2.5%), critThresh = 180 (1.8%), limitThresh 100 (1.00%).
 */
typedef struct {
  /** The Limited Threshold in % * 100. */
  sl_zigbee_duty_cycle_hecto_pct_t limitThresh;
  /** The Critical Threshold in % * 100. */
  sl_zigbee_duty_cycle_hecto_pct_t critThresh;
  /** The Suspended Limit (LBT) in % * 100. */
  sl_zigbee_duty_cycle_hecto_pct_t suspLimit;
} sl_zigbee_duty_cycle_limits_t;

/**
 * @brief Duty cycle states
 *
 * Applications have no control over the state but the callback exposes
 * state changes to the application.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_duty_cycle_state_t
#else
typedef uint8_t sl_zigbee_duty_cycle_state_t;
enum
#endif
{
  /** No duty cycle tracking or metrics are taking place. */
  SL_ZIGBEE_DUTY_CYCLE_TRACKING_OFF                    = 0,
  /** Duty Cycle is tracked and has not exceeded any thresholds. */
  SL_ZIGBEE_DUTY_CYCLE_LBT_NORMAL                      = 1,
  /** The limited threshold of the total duty cycle allotment was exceeded. */
  SL_ZIGBEE_DUTY_CYCLE_LBT_LIMITED_THRESHOLD_REACHED   = 2,
  /** The critical threshold of the total duty cycle allotment was exceeded. */
  SL_ZIGBEE_DUTY_CYCLE_LBT_CRITICAL_THRESHOLD_REACHED  = 3,
  /** The suspend limit was reached and all outbound transmissions are blocked. */
  SL_ZIGBEE_DUTY_CYCLE_LBT_SUSPEND_LIMIT_REACHED       = 4,
};

/**
 * @brief A structure containing, per device, overall duty cycle consumed
 * (up to the suspend limit).
 */
typedef struct {
  /** Node ID of the device whose duty cycle is reported. */
  sl_802154_short_addr_t nodeId;
  /** The amount of overall duty cycle consumed (up to suspend limit). */
  sl_zigbee_duty_cycle_hecto_pct_t dutyCycleConsumed;
} sl_zigbee_per_device_duty_cycle_t;

/**
 * @brief A structure containing information needed to exchange a packet at
 * the NWK layer
 */
typedef struct {
  /** Node ID of the source or destination. */
  sl_802154_short_addr_t nwk_short_address;
  /** A bitmask for configuration options. */
  uint8_t bitmask;
  /** The MAC Interface ID. */
  uint8_t mac_interface_id;
  /** The Network Index. */
  uint8_t nwk_index;
  /** A pointer to the actual packet. */
  uint8_t *network_packet;
  /** The length of the packet. */
  uint8_t network_packet_length;
} sl_nwk_packet_exchange_t;

/**
 * @brief The types of MAC passthrough messages that an application may
 * receive.  This is a bitmask.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_mac_passthrough_type_t
#else
typedef uint8_t sl_zigbee_mac_passthrough_type_t;
enum
#endif
{
  /** No MAC passthrough messages. */
  SL_802154_PASSTHROUGH_NONE             = 0x00,
  /** SE InterPAN messages. */
  SL_802154_PASSTHROUGH_SE_INTERPAN      = 0x01,
  /** EmberNet and first generation (v1) standalone bootloader messages. */
  SL_802154_PASSTHROUGH_EMBERNET         = 0x02,
  /** EmberNet messages filtered by their source address. */
  SL_802154_PASSTHROUGH_EMBERNET_SOURCE  = 0x04,
  /** Application-specific passthrough messages. */
  SL_802154_PASSTHROUGH_APPLICATION      = 0x08,
  /** Custom inter-pan filter. */
  SL_802154_PASSTHROUGH_CUSTOM           = 0x10,

#if !defined DOXYGEN_SHOULD_SKIP_THIS
  /** Internal Stack passthrough. */
  EM_MAC_PASSTHROUGH_INTERNAL_ZLL        = 0x80,
  EM_MAC_PASSTHROUGH_INTERNAL_GP         = 0x40
#endif
};

/** @brief This structure indicates a matching raw MAC message has been
 *    received by the application configured MAC filters.
 */
typedef struct {
  uint8_t filterIndexMatch;
  sl_zigbee_mac_passthrough_type_t legacyPassthroughType;
  sli_buffer_manager_buffer_t message;
} sl_zigbee_mac_filter_match_struct_t;

/**
 * @name ZigBee Device Object (ZDO) Definitions
 */
//@{

/** @name ZDO response status.
 *
 * Most responses to ZDO commands contain a status byte.
 * The meaning of this byte is defined by the ZigBee Device Profile.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_zdo_status_t
#else
typedef uint8_t sl_zigbee_zdo_status_t;
enum
#endif
{
  // These values are taken from Table 48 of ZDP Errata 043238r003 and Table 2
  // of NWK 02130r10.
  SL_ZIGBEE_ZDP_SUCCESS                    = 0x00,
  // 0x01 to 0x7F are reserved
  SL_ZIGBEE_ZDP_INVALID_REQUEST_TYPE       = 0x80,
  SL_ZIGBEE_ZDP_DEVICE_NOT_FOUND           = 0x81,
  SL_ZIGBEE_ZDP_INVALID_ENDPOINT           = 0x82,
  SL_ZIGBEE_ZDP_NOT_ACTIVE                 = 0x83,
  SL_ZIGBEE_ZDP_NOT_SUPPORTED              = 0x84,
  SL_ZIGBEE_ZDP_TIMEOUT                    = 0x85,
  SL_ZIGBEE_ZDP_NO_MATCH                   = 0x86,
  // 0x87 is reserved                  = 0x87,
  SL_ZIGBEE_ZDP_NO_ENTRY                   = 0x88,
  SL_ZIGBEE_ZDP_NO_DESCRIPTOR              = 0x89,
  SL_ZIGBEE_ZDP_INSUFFICIENT_SPACE         = 0x8a,
  SL_ZIGBEE_ZDP_NOT_PERMITTED              = 0x8b,
  SL_ZIGBEE_ZDP_TABLE_FULL                 = 0x8c,
  SL_ZIGBEE_ZDP_NOT_AUTHORIZED             = 0x8d,
  SL_ZIGBEE_ZDP_DEVICE_BINDING_TABLE_FULL  = 0x8e,
  SL_ZIGBEE_ZDP_INVALID_INDEX              = 0x8f,
  SL_ZIGBEE_ZDP_FRAME_TOO_LARGE            = 0x90,
  SL_ZIGBEE_ZDP_BAD_KEY_NEGOTIATION_METHOD = 0x91,
  SL_ZIGBEE_ZDP_TEMPORARY_FAILURE          = 0x92,

  SL_ZIGBEE_APS_SECURITY_FAIL              = 0xad,

  SL_ZIGBEE_NWK_ALREADY_PRESENT            = 0xc5,
  SL_ZIGBEE_NWK_TABLE_FULL                 = 0xc7,
  SL_ZIGBEE_NWK_UNKNOWN_DEVICE             = 0xc8,

  SL_ZIGBEE_NWK_MISSING_TLV                = 0xd6,
  SL_ZIGBEE_NWK_INVALID_TLV                = 0xd7,
};

/// @name ZDO server mask bits
/// <br> @{
///  These are used in server discovery
/// requests and responses.
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_zdo_server_mask_t
#else
typedef uint16_t sl_zigbee_zdo_server_mask_t;
enum
#endif
{
  SL_ZIGBEE_ZDP_PRIMARY_TRUST_CENTER          = 0x0001,
  SL_ZIGBEE_ZDP_SECONDARY_TRUST_CENTER        = 0x0002,
  SL_ZIGBEE_ZDP_PRIMARY_BINDING_TABLE_CACHE   = 0x0004,
  SL_ZIGBEE_ZDP_SECONDARY_BINDING_TABLE_CACHE = 0x0008,
  SL_ZIGBEE_ZDP_PRIMARY_DISCOVERY_CACHE       = 0x0010, /** DEPRECATED */
  SL_ZIGBEE_ZDP_SECONDARY_DISCOVERY_CACHE     = 0x0020, /** DEPRECATED */
  SL_ZIGBEE_ZDP_NETWORK_MANAGER               = 0x0040,
  // Bits 0x0080 to 0x8000 are reserved.
};

/** @name ZDO configuration flags.
 *
 * Control which ZDO requests are passed to the application.
 * These are normally controlled via the following configuration definitions:
 *
 * SL_ZIGBEE_APPLICATION_RECEIVES_SUPPORTED_ZDO_REQUESTS
 * SL_ZIGBEE_APPLICATION_HANDLES_UNSUPPORTED_ZDO_REQUESTS
 * SL_ZIGBEE_APPLICATION_HANDLES_ENDPOINT_ZDO_REQUESTS
 * SL_ZIGBEE_APPLICATION_HANDLES_BINDING_ZDO_REQUESTS
 *
 * See ember-configuration.h for more information.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_zdo_configuration_flags_t
#else
typedef uint8_t sl_zigbee_zdo_configuration_flags_t;
enum
#endif

{
  SL_ZIGBEE_APP_RECEIVES_SUPPORTED_ZDO_REQUESTS  = 0x01,
  SL_ZIGBEE_APP_HANDLES_UNSUPPORTED_ZDO_REQUESTS = 0x02,
  SL_ZIGBEE_APP_HANDLES_ZDO_ENDPOINT_REQUESTS    = 0x04,
  SL_ZIGBEE_APP_HANDLES_ZDO_BINDING_REQUESTS     = 0x08
};

//@} \\END ZigBee Device Object (ZDO) Definitions

typedef struct {
  sl_802154_short_addr_t destination;        // SL_ZIGBEE_NULL_NODE_ID if entry is marked for removal
  uint8_t closerIndex;            // The entry one hop closer to the gateway.
  uint8_t olderIndex;             // The entry touched before this one.
} sl_zigbee_source_route_table_entry_t;

#if defined(SL_ZIGBEE_SCRIPTED_TEST)
#define WEAK_TEST WEAK()//__attribute__((weak))
#else
#define WEAK_TEST
#endif

#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_multi_phy_nwk_config_t
#else
typedef uint8_t sl_zigbee_multi_phy_nwk_config_t;
enum
#endif
{
  SL_ZIGBEE_MULTI_PHY_ROUTERS_ALLOWED = 0x01,
  SL_ZIGBEE_MULTI_PHY_BROADCASTS_ENABLED = 0x02,
  SL_ZIGBEE_MULTI_PHY_DISABLED = 0x80
};

/**
 * @brief Defines the maximum number of counters that are specified as reporting either
 * on 2.4 GHz or Sub-GHz.
 */
#define SL_ZIGBEE_MAX_MAC_ONLY_COUNTERS 33u

/**
 * @brief Defines the maximum number of PHYs supported.
 *
 */
#define SL_ZIGBEE_MAX_NUM_PHYS 2u

/**
 * @brief PHY index for 2.4 GHz radio interface, valid for simultaneous multi radio network.
 */
#define PHY_INDEX_NATIVE        0u

/**
 * @brief PHY index for Sub-GHz radio interface, valid for simultaneous multi radio network.
 */
#define PHY_INDEX_PRO2PLUS      1u

/**
 * @brief Radio power mode.
 */
typedef uint8_t sl_zigbee_radio_power_mode_t;

typedef struct {
  int8_t minRssiForReceivingPkts;
  uint16_t beaconClassificationMask;
} sl_zigbee_beacon_classification_params_t;

/**
 * @brief Defines beacon classification flags.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_beacon_classification_flags_t
#else
typedef uint16_t sl_zigbee_beacon_classification_flags_t;
enum
#endif
{
  NO_PARENT_CLASSIFICATION_AND_NO_TC_CONNECTIVITY_PRIORITY = 0x0000, // this indicates that the classification mode is disabled
  PRIORITIZE_BEACONS_BASED_ON_PARENT_CLASSIFICATION  = 0x0001,  // this means we also advertise the TC connectivity and long/short uptime
  PRIORITIZE_BEACONS_BASED_ON_TC_CONNECTVITY  = 0x0002,   //this means we also advertise TC connectivity
  // The following two bits are only ADVERTISED in a beacon if Parent Classification
  // is enabled (bit 0), or tcBasedCassification (bit 1) is enabled
  TC_CONNECTIVITY       = 0x0010,
  LONG_UPTIME            = 0x0020,
  BAD_PARENT_CONNECTIVITY = 0x0040, // it indicates if the paren connection is bad.
  // Meaning rolling avg of RSSI over the last window of packets (16 for now) have been
  // lower than minRssiForReceivingPkts.
  // The rolling average is (re)initiated after the last successful (re)join.
  PREFERRED_PARENT        = 0x60  // This is information we provide for routers.
};

/**
 * @brief Defines the entropy source used by the stack.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_entropy_source_t
#else
typedef uint8_t sl_zigbee_entropy_source_t;
enum
#endif
{
  SL_ZIGBEE_ENTROPY_SOURCE_ERROR        = 0x00, // Error in identifying the entropy source.
  SL_ZIGBEE_ENTROPY_SOURCE_RADIO        = 0x01, // The default radio entropy source.
  SL_ZIGBEE_ENTROPY_SOURCE_MBEDTLS_TRNG = 0x02, // TRNG with mbed TLS support.
  SL_ZIGBEE_ENTROPY_SOURCE_MBEDTLS      = 0x03, // Other mbed TLS entropy source.
};

enum {
  SL_ZIGBEE_POLL_TIMEOUT_10_SECONDS    =  0,
  SL_ZIGBEE_POLL_TIMEOUT_2_MINUTES     =  1,
  SL_ZIGBEE_POLL_TIMEOUT_4_MINUTES     =  2,
  SL_ZIGBEE_POLL_TIMEOUT_8_MINUTES     =  3,
  SL_ZIGBEE_POLL_TIMEOUT_16_MINUTES    =  4,
  SL_ZIGBEE_POLL_TIMEOUT_32_MINUTES    =  5,
  SL_ZIGBEE_POLL_TIMEOUT_64_MINUTES    =  6,
  SL_ZIGBEE_POLL_TIMEOUT_128_MINUTES   =  7,
  SL_ZIGBEE_POLL_TIMEOUT_256_MINUTES   =  8,
  SL_ZIGBEE_POLL_TIMEOUT_512_MINUTES   =  9,
  SL_ZIGBEE_POLL_TIMEOUT_1024_MINUTES  = 10,
  SL_ZIGBEE_POLL_TIMEOUT_2048_MINUTES  = 11,
  SL_ZIGBEE_POLL_TIMEOUT_4096_MINUTES  = 12,
  SL_ZIGBEE_POLL_TIMEOUT_8192_MINUTES  = 13,
  SL_ZIGBEE_POLL_TIMEOUT_16384_MINUTES = 14,
};

/**
 * @brief Defines the trust center APS encryption mode when sending a newer
 * (alternate) network key to a device. The value settings below do not take
 * effect when sending the initial network key during joining or rejoining.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_tc_aps_encrypt_mode_t
#else
typedef uint8_t sl_zigbee_tc_aps_encrypt_mode_t;
enum
#endif
{
  /** Default: don't encrypt broadcasts, encrypt unicasts */
  TC_APS_ENCRYPT_DEFAULT = 0x00,
  /** Encrypt both broadcasts and unicasts */
  TC_APS_ENCRYPT_ENABLE = 0x01,
  /** Do not encrypt broadcasts and unicasts */
  TC_APS_ENCRYPT_DISABLE = 0x02,
};

/**
 * @brief A structure containing the information of a token.
 */
typedef struct {
  /** NVM3 token key. */
  uint32_t nvm3Key;
  /** The token is a counter token type. */
  bool isCnt;
  /** The token is an indexed token type. */
  bool isIdx;
  /** Size of the object of the token. */
  uint8_t size;
  /** The array size for the token when it is an indexed token. */
  uint8_t arraySize;
} sl_zigbee_token_info_t;

/**
 * @brief A structure containing the information of a token data.
 */
typedef struct {
  /** The size of the token data in number of bytes. */
  uint32_t size;
  /** A data pointer pointing to the storage for the token data of above size. */
  void *data;
} sl_zigbee_token_data_t;

/** @} END addtogroup
 */

/**
 * @brief Type of Ember keep alive method
 * defining the keep alive message type that a parent accepts to prevent child aging.
 * This is configured in a parent router and communicated and stored in an end-device.
 *
 *  SL_ZIGBEE_KEEP_ALIVE_SUPPORT_UNKNOWN which is initialized at end-device boot time,
 *  means parent's keep alive mechanism is unknown to end-device.
 *
 *  SL_802154_DATA_POLL_KEEP_ALIVE means that the parent does not need explicit keep alive messages
 *  and will use incoming mac data polls as a sign that a child should not be aged out.
 *
 *  SL_ZIGBEE_END_DEVICE_TIMEOUT_KEEP_ALIVE means that the parent needs explicit keep alive messages
 *  (net work timeout requests) to keep the child in its child table.
 *
 *  SL_ZIGBEE_KEEP_ALIVE_SUPPORT_ALL basically maps to SL_802154_DATA_POLL_KEEP_ALIVE
 *  as the preferred  approach between the two.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_keep_alive_mode_t
#else
typedef uint8_t sl_zigbee_keep_alive_mode_t;
enum
#endif
{
  SL_ZIGBEE_KEEP_ALIVE_SUPPORT_UNKNOWN     = 0x00,
  SL_802154_DATA_POLL_KEEP_ALIVE       = 0x01,
  SL_ZIGBEE_END_DEVICE_TIMEOUT_KEEP_ALIVE  = 0x02,
  SL_ZIGBEE_KEEP_ALIVE_SUPPORT_ALL         = 0x03,
};

/**
 * @brief Types of source route discovery modes used by the concentrator.
 *
 * SL_ZIGBEE_SOURCE_ROUTE_DISCOVERY_OFF no source route discovery is scheduled
 * SL_ZIGBEE_SOURCE_ROUTE_DISCOVERY_ON source routes discovery is scheduled, and it is triggered periodically
 * SL_ZIGBEE_SOURCE_ROUTE_DISCOVERY_RESCHEDULE  source routes discoveries are re-scheduled to be
 * sent once immediately and then triggered periodically
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_source_route_discovery_mode_t
#else
typedef uint8_t sl_zigbee_source_route_discovery_mode_t;
enum
#endif
{
  /** off  */
  SL_ZIGBEE_SOURCE_ROUTE_DISCOVERY_OFF = 0x00,
  /** on  */
  SL_ZIGBEE_SOURCE_ROUTE_DISCOVERY_ON = 0x01,
  /** reschedule */
  SL_ZIGBEE_SOURCE_ROUTE_DISCOVERY_RESCHEDULE = 0x02,
};

/**
 * @brief Source route overhead unknown
 */
#define SL_ZIGBEE_SOURCE_ROUTE_OVERHEAD_UNKNOWN 0xFFu

/**
 * @brief Packet transmit priorities in terms of getting into the MAC queue.
 *
 * SL_802154_TRANSMIT_PRIORITY_HIGH High priority headers go on the front of the queue.
 * SL_802154_TRANSMIT_PRIORITY_NORMAL  Normal priority headers go on the back of the queue.
 * SL_802154_TRANSMIT_PRIORITY_SCAN_OKAY Normally, only beacon requests and orphan notifications can be
 * sent during a scan.  They are submitted with SCAN_OKAY
 * and go on the front of the queue. Other packets could be submitted with this priority, but it is not recommended.
 */

#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_transmit_priority_t
#else
typedef uint8_t sl_zigbee_transmit_priority_t;
enum
#endif
{
  SL_802154_TRANSMIT_PRIORITY_HIGH,
  SL_802154_TRANSMIT_PRIORITY_NORMAL,
  SL_802154_TRANSMIT_PRIORITY_SCAN_OKAY
};

/**
 * @brief Policies for sending a route record to the concentrator.
 *
 * When sending a unicast to a concentrator, the message may be preceded by a route record packet
 * depending on the type of concentrator and the route record policy
 */

#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_route_record_policy_type_t
#else
typedef uint8_t sl_zigbee_route_record_policy_type_t;
enum
#endif
{
  /** ROUTE_RECORD_POLICY_ACK_BY_SOURCE_ROUTED_MESSAGE is the default policy
   * A low RAM concentrator will be sent a route record ahead of any unicast
   * A high RAM concentrator will be sent a route record ahead of any unicast
   * until a source routed unicast is received from it. */
  ROUTE_RECORD_POLICY_ACK_BY_SOURCE_ROUTED_MESSAGE           = 0,
  /** ROUTE_RECORD_POLICY_DONT_SEND policy means that the local node never sends
   * a route record message (Note: Non-compliant) */
  ROUTE_RECORD_POLICY_DONT_SEND               = 1,
  /** ROUTE_RECORD_POLICY_NO_ACK_REQUIRED
   * A low RAM concentrator will be sent a route record ahead of any unicast
   * A high RAM concentrator will be sent a route record ahead of any unicast
   * (Note: Non-compliant) */
  ROUTE_RECORD_POLICY_NO_ACK_REQUIRED = 2,
};

/**
 * @brief Passive ack config enum
 *
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_passive_ack_config_enum_t
#else
typedef uint8_t sl_passive_ack_config_enum_t;
enum
#endif
{
  SL_PASSIVE_ACK_DEFAULT_CONFIG = 0,
  SL_PASSIVE_ACK_DISABLE,
  SL_PASSIVE_ACK_THRESHOLD_WITH_REBROADCAST,
  SL_PASSIVE_ACK_THRESHOLD_NO_REBROADCAST,
  SL_PASSIVE_ACK_THRESHOLD_WITH_REBROADCAST_ALL_NODES
};

/**
 * @brief represents a single entry in the APS duplicate rejection table
 */
typedef struct aps_duplicate_msg_entry {
  uint32_t crc_digest;
} sl_zigbee_aps_duplicate_msg_entry_t;

/** @} END addtogroup
 */

// an entry in the neighbor table.  nodes directly measure the incoming
// link quality, but rely on the neighbors to tell them their outgoing link
// quality.
//
// we use an uint16_t rather than an uint8_t for the incoming link quality
// value in order to have the needed precision to perform rolling averages.
//
// the age field is incremented every neighbor exchange period, and set
// to zero upon reception of a neighbor exchange message which lists us.
// thus it indicates the time since last obtaining a valid outgoing cost.
//
// the overlap count is used in the neighbor selection algorithm
// to favor neighborhoods that have low overlap with ours.
//
// the active network key bit is used to indicate whether our neighbors
// are using the active network key (my key) or the alternate
// one.  this is important for knowing when to reset their frame counter.
// for children's frame counters, see 'child.h'.

// the neighbor association bit indicates whether the device was added to the
// neighbor table because it associated to the local node (vs link status
// message).  it is used to help pick which neighbor to remove from the
// neighbor table.

typedef struct {
  sl_802154_short_addr_t id;
  uint16_t incoming;
  uint8_t exchange;      // 0xf0 age in neighbor exchange periods
                         // 0x07 outgoing cost (bottom 3 bits)
                         // bit 0x08 is unused
  uint8_t connectivity;  // overlap in bits 0,1
                         // bits 2 and 3 are used to store information about
                         // the previous incoming cost which can be 1,3,5,7
                         // neighbor using my active network key in bit 4
                         // bit 5 is reserved
                         // neighbor association in bit 6
                         // neighbor security capability in bit 7 (1 = high,
                         //   0 = standard)
  sl_802154_long_addr_t eui64;
  uint8_t mac_interface_table_index;
  uint8_t lqi_for_median[3];
} sl_zigbee_neighbor_table_entry_info_t;

typedef struct {
  uint16_t source;
  uint8_t  sequence;
  uint8_t  numAcks;
  uint32_t neighborBitmask;
} sl_zigbee_broadcast_table_entry_t;

typedef struct {
  // Child Table Info
  sl_mac_child_entry_t *childTable;
  uint16_t *childStatus;
  uint32_t *childTimers;
  uint16_t *childLqi;

  // Routing Table Info
  uint8_t *routeRecordTable;

  // Child Table End Device Info
  uint8_t *endDeviceTimeout;
  uint8_t endDeviceChildCount;

  // Used for sending link status more quickly at startup
  // and only used by routers.
  uint8_t fastLinkStatusCount;

  // Broadcast Table Info
  uint8_t broadcastHead;
  uint8_t inInitialBroadcastTimeout;
  uint32_t broadcastAgeCutoffIndexes;
  sl_zigbee_broadcast_table_entry_t *broadcastTable;

  // Association info
  bool permitJoining;
  bool macPermitAssociation;
  bool allowRejoinsWithWellKnownKey;

  // Parent announcement
  uint8_t parentAnnounceIndex;
  uint8_t totalInitialChildren;

  // PanId conflict info
  sl_802154_pan_id_t newPanId;
} sl_zigbee_pan_info_t;

typedef struct {
  uint8_t stackProfile;
  uint8_t nodeType;
  uint8_t zigbeeState;
  uint8_t dynamicCapabilities;

  uint8_t zigbeeNetworkSecurityLevel;
  uint32_t securityStateBitmask;
  uint8_t zigbeeSequenceNumber;
  uint8_t apsSequenceNumber;

  // Network security stuff
  uint8_t securityKeySequenceNumber;
  uint32_t nextNwkFrameCounter;

  // APS security stuff
  uint32_t incomingTcLinkKeyFrameCounter;

  // Neighbor table
  sl_zigbee_neighbor_table_entry_info_t *neighborTable;
  uint8_t neighborTableSize;
  uint8_t neighborCount;

  // Incoming frame counters table
  uint32_t* frameCounters;

  // The number of ticks since our last successful poll.  Ticks are
  // in seconds.
  uint32_t ticksSinceLastPoll; // for timing out our parent
  uint32_t msSinceLastPoll;   // for APS retry timeout adjustment

  // Transmission statistics that are reported in NWK_UPDATE_RESPONSE ZDO
  // messages.
  uint16_t unicastTxAttempts;
  uint16_t unicastTxFailures;
  uint16_t parentNwkInformation;

  // Child aging stuff
  //----------------------------------------------------------------
  // The last time we updated the child timers for each unit.
  // The milliseconds needs to be larger because we use it on children, who
  // may go a long time between calls to sl_zigbee_tick().
  uint16_t lastChildAgeTimeSeconds;
  uint32_t lastChildAgeTimeMs;

  // PAN info contains collection of elements needed to accommodate
  // single network, multi network and multi PAN use cases.
  sl_zigbee_pan_info_t *panInfoData;
} sl_zigbee_network_info_t;

// Note:
// For single network case:
//  - sl_zigbee_network_info_t and sli_zigbee_pan_info: Single instance present.
// For multi network case:
//  - sl_zigbee_network_info_t: Instance present for each network.
//  - sli_zigbee_pan_info: Single Instance present.
// For multi PAN case"
//  - sl_zigbee_network_info_t and sli_zigbee_pan_info: Instance present for each network.

#define MANUFACTURING_STRING_SIZE            16
typedef uint8_t sl_zigbee_manufacturing_string_t[MANUFACTURING_STRING_SIZE];

/** @brief Endpoint information (a ZigBee Simple Descriptor).
 *
 * This is a ZigBee Simple Descriptor and contains information
 * about an endpoint.  This information is shared with other nodes in the
 * network by the ZDO.
 */
typedef struct {
  /** Identifies the endpoint's application profile. */
  uint16_t profileId;
  /** The endpoint's device ID within the application profile. */
  uint16_t deviceId;
  /** The endpoint's device version. */
  uint8_t deviceVersion;
  /** The number of input clusters. */
  uint8_t inputClusterCount;
  /** The number of output clusters. */
  uint8_t outputClusterCount;
} sl_zigbee_endpoint_description_t;

/** @brief Basic node descriptor information.
 *
 * This is a ZigBee Node Descriptor and contains information
 * about incoming, and outgoing transfer size, as well as descriptor capability.
 */
typedef struct {
  /** The maximum incoming transfer size for the local node */
  uint16_t max_incoming_transfer_size;
  /** The maximum outgoing transfer size for the local node */
  uint16_t max_outgoing_transfer_size;
  /** descriptor capability field of the node */
  uint8_t capability;
} sl_zigbee_node_descriptor_info_t;

/** @brief Received packet information.
 *
 * Contains information about the incoming packet.
 */
typedef struct {
  /** Short ID of the sender of the message */
  sl_802154_short_addr_t sender_short_id;
  /** EUI64 of the sender of the message if the sender chose to include this
      information in the message. The ::SL_ZIGBEE_APS_OPTION_SOURCE_EUI64 bit in
      the options field of the APS frame of the incoming message indicates that
      the EUI64 is present in the message. Also, when not set, the sender long ID
      is set to all zeros */
  sl_802154_long_addr_t sender_long_id;
  /** The index of the entry in the binding table that matches the sender of
   *  the message or 0xFF if there is no matching entry. A binding matches the message if:
   *   - The binding's source endpoint is the same as the message's destination endpoint
   *   - The binding's destination endpoint is the same as the message's source endpoint
   *   - The source of the message has been previously identified as the binding's remote
   *     node by a successful address discovery or by the application via a call to either
   *     ::sl_zigbee_set_reply_binding() or ::sl_zigbee_note_senders_binding() */
  uint8_t binding_index;
  /** The index of the entry in the address table that matches the sender of
      the message or 0xFF if there is no matching entry */
  uint8_t address_index;
  /** Link quality of the node that last relayed the current message */
  uint8_t last_hop_lqi;
  /** Received signal strength indicator (RSSI) of the node that last
   *  relayed the message */
  int8_t last_hop_rssi;
  /* Timestamp of the moment when Start Frame Delimiter (SFD) was received */
  uint32_t last_hop_timestamp;
} sl_zigbee_rx_packet_info_t;

// Note:
// For single network case:
//  - sl_zigbee_network_info_t and sli_zigbee_pan_info: Single instance present.
// For multi network case:
//  - sl_zigbee_network_info_t: Instance present for each network.
//  - sli_zigbee_pan_info: Single Instance present.
// For multi PAN case"
//  - sl_zigbee_network_info_t and sli_zigbee_pan_info: Instance present for each network.

#endif // SLABS_EMBER_TYPES_H

#include "stack/include/zll-types.h"
#include "stack/include/gp-types.h"
#include "stack/include/zigbee-security-manager-types.h"
