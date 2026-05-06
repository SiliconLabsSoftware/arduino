/***************************************************************************//**
 * @file
 * @brief Zigbee Green Power types and defines.
 * See @ref greenpower for documentation.
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

/**
 * @addtogroup gp_types
 *
 * This file defines data types relevant to the Green Power implementation.
 *
 * See gp-types.h for source code.
 * @{
 */

#ifndef SILABS_GP_TYPES_H
#define SILABS_GP_TYPES_H

#include "stack/include/sl_zigbee_types.h"

/**
 * @brief Mask used in the green power endpoint incoming message handler to pass bidirectional information.
 * Incoming GPDF has rxAfterTx bit set
 */
#define SL_ZIGBEE_GP_BIDIRECTION_INFO_RX_AFTER_TX_MASK        0x01

/**
 * @brief Mask to test if transmit queue is available at green power stub layer to hold an outgoing GPDF.
 */
#define SL_ZIGBEE_GP_BIDIRECTION_INFO_TX_QUEUE_AVAILABLE_MASK 0x02

/**
 * @brief Number of GP sink list entries. Minimum is 2 sink list entries.
 */
#define GP_SINK_LIST_ENTRIES 2

/**
 * @brief The size of the SinkList entries in sink table in form of octet string that has a format of [<1 byte length>, <n bytes for sink groups>]
 */
#define GP_SIZE_OF_SINK_LIST_ENTRIES_OCTET_STRING (1 + (GP_SINK_LIST_ENTRIES * (sizeof(sl_zigbee_gp_sink_group_t))))

/**
 * @brief GP parameters list represented as a macro for GP endpoint incoming message handler and callbacks prototypes.
 */
#define GP_PARAMS                                  \
  sl_zigbee_gp_status_t status,                    \
  uint8_t gpdLink,                                 \
  uint8_t sequenceNumber,                          \
  sl_zigbee_gp_address_t * addr,                   \
  sl_zigbee_gp_security_level_t gpdfSecurityLevel, \
  sl_zigbee_gp_key_type_t gpdfSecurityKeyType,     \
  bool autoCommissioning,                          \
  uint8_t bidirectionalInfo,                       \
  uint32_t gpdSecurityFrameCounter,                \
  uint8_t gpdCommandId,                            \
  uint32_t mic,                                    \
  uint8_t proxyTableIndex,                         \
  uint8_t gpdCommandPayloadLength,                 \
  uint8_t * gpdCommandPayload,                     \
  sl_zigbee_rx_packet_info_t * packetInfo

/**
 * @brief GP arguments list represented as a macro while calling GP endpoint incoming message handler and callbacks.
 */
#define GP_ARGS            \
  status,                  \
  gpdLink,                 \
  sequenceNumber,          \
  addr,                    \
  gpdfSecurityLevel,       \
  gpdfSecurityKeyType,     \
  autoCommissioning,       \
  bidirectionalInfo,       \
  gpdSecurityFrameCounter, \
  gpdCommandId,            \
  mic,                     \
  proxyTableIndex,         \
  gpdCommandPayloadLength, \
  gpdCommandPayload,       \
  packetInfo

/**
 * @brief GP arguments list with void type cast represented as a macro to be used in callback stubs.
 */
#define GP_UNUSED_ARGS           \
  (void)status;                  \
  (void)gpdLink;                 \
  (void)sequenceNumber;          \
  (void)addr;                    \
  (void)gpdfSecurityLevel;       \
  (void)gpdfSecurityKeyType;     \
  (void)autoCommissioning;       \
  (void)rxAfterTx;               \
  (void)gpdSecurityFrameCounter; \
  (void)gpdCommandId;            \
  (void)mic;                     \
  (void)proxyTableIndex;         \
  (void)gpdCommandPayloadLength; \
  (void)gpdCommandPayload;

/**
 * @brief Bit mask for the proxy table ebtry option bit representing in-range bit field.
 */
#define GP_PROXY_TABLE_OPTIONS_IN_RANGE (BIT(10))

/**
 * @brief Maximum number of bytes in a green power commissioning frame excluding 3 bytes for device ID, option and application information fields.
 */
#define GP_COMMISSIONING_MAX_BYTES (55 - 3)

/**
 * @brief GPD Source ID when requesting channel request.
 */
#define GP_GPD_SRC_ID_FOR_CAHNNEL_CONFIG 0x00000000

/**
 * @brief GPD wildcard Source ID.
 */
#define GP_GPD_SRC_ID_WILDCARD           0xFFFFFFFF

/**
 * @brief GPD Reserved Source ID. Used in maintenance frame.
 */
#define GP_GPD_SRC_ID_RESERVED_0 0x00000000

/**
 * @brief GPD Reserved Source ID. All addresses between 0xFFFFFFF9 and 0xFFFFFFFE are reserved.
 */
#define GP_GPD_SRC_ID_RESERVED_FFFFFF9 0xFFFFFFF9

/**
 * @brief GPD Reserved Source ID. All addresses between 0xFFFFFFF9 and 0xFFFFFFFE are reserved.
 */
#define GP_GPD_SRC_ID_RESERVED_FFFFFFE 0xFFFFFFFE

/**
 * @brief Default value for derived group ID when alias is not used.
 */
#define GP_DERIVED_GROUP_ALIAS_NOT_USED 0xffff

/**
 * @brief Tunneling delay constant Dmin_b in milliseconds. Ref green power specification for more information on this constant.
 */
#define GP_DMIN_B 32

/**
 * @brief Tunneling delay constant Dmin_u in milliseconds. Ref green power specification for more information on this constant.
 */
#define GP_DMIN_U 5

/**
 * @brief Tunneling delay constant Dmax in milliseconds. Ref green power specification for more information on this constant.
 */
#define GP_DMAX 100

/**
 * @name GP Types
 */
//@{
/** 32-bit GPD source identifier */
typedef uint32_t sl_zigbee_gp_source_id_t;
/** 32-bit security frame counter */
typedef uint32_t sl_zigbee_gp_security_frame_counter_t;
/** 32-bit MIC code */
typedef uint32_t sl_zigbee_gp_mic_t;

#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_gp_status_t
#else
typedef uint8_t sl_zigbee_gp_status_t;
enum
#endif
{
  /** Success Status */
  SL_ZIGBEE_GP_STATUS_OK,
  /** Match Frame */
  SL_ZIGBEE_GP_STATUS_MATCH,
  /** Drop Frame */
  SL_ZIGBEE_GP_STATUS_DROP_FRAME,
  /** Frame Unprocessed */
  SL_ZIGBEE_GP_STATUS_UNPROCESSED,
  /** Frame Pass Unprocessed */
  SL_ZIGBEE_GP_STATUS_PASS_UNPROCESSED,
  /** Frame TX Then Drop */
  SL_ZIGBEE_GP_STATUS_TX_THEN_DROP,
  /** No Security */
  SL_ZIGBEE_GP_STATUS_NO_SECURITY,
  /** Security Failure */
  SL_ZIGBEE_GP_STATUS_AUTH_FAILURE,
};

/**
 * @brief Green Power Security Level
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_gp_security_level_t
#else
typedef uint8_t sl_zigbee_gp_security_level_t;
enum
#endif
{
  /** No Security  */
  SL_ZIGBEE_GP_SECURITY_LEVEL_NONE = 0x00,
  /** Reserved  */
  SL_ZIGBEE_GP_SECURITY_LEVEL_RESERVED = 0x01,
  /** 4 Byte Frame Counter and 4 Byte MIC */
  SL_ZIGBEE_GP_SECURITY_LEVEL_FC_MIC = 0x02,
  /** 4 Byte Frame Counter and 4 Byte MIC with encryption */
  SL_ZIGBEE_GP_SECURITY_LEVEL_FC_MIC_ENCRYPTED = 0x03,
};
/**
 * @brief Green Power Security Security Key Type
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_gp_key_type_t
#else
typedef uint8_t sl_zigbee_gp_key_type_t;
enum
#endif
{
  /** No Key */
  SL_ZIGBEE_GP_SECURITY_KEY_NONE = 0x00,
  /** GP Security Key Type is Zigbee Network Key */
  SL_ZIGBEE_GP_SECURITY_KEY_NWK = 0x01,
  /** GP Security Key Type is Group Key */
  SL_ZIGBEE_GP_SECURITY_KEY_GPD_GROUP = 0x02,
  /** GP Security Key Type is Derived Network Key */
  SL_ZIGBEE_GP_SECURITY_KEY_NWK_DERIVED = 0x03,
  /** GP Security Key Type is Out Of Box Key */
  SL_ZIGBEE_GP_SECURITY_KEY_GPD_OOB = 0x04,
  /** GP Security Key Type is GPD Derived Key */
  SL_ZIGBEE_GP_SECURITY_KEY_GPD_DERIVED = 0x07,
};
/**
 * @brief Green Power Application ID
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_gp_application_id_t
#else
typedef uint8_t sl_zigbee_gp_application_id_t;
enum
#endif
{
  /** Source identifier. */
  SL_ZIGBEE_GP_APPLICATION_SOURCE_ID = 0x00,
  /** IEEE address. */
  SL_ZIGBEE_GP_APPLICATION_IEEE_ADDRESS = 0x02,
};

/**
 * @brief GP proxy table entry status.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_gp_proxy_table_entry_status_t
#else
typedef uint8_t sl_zigbee_gp_proxy_table_entry_status_t;
enum
#endif
{
  /**
   * The GP table entry is in use for a Proxy Table Entry.
   */
  SL_ZIGBEE_GP_PROXY_TABLE_ENTRY_STATUS_ACTIVE = 0x01,
  /**
   * The proxy table entry is not in use.
   */
  SL_ZIGBEE_GP_PROXY_TABLE_ENTRY_STATUS_UNUSED = 0xFF,
};

/**
 * @brief GP sink table entry status.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_gp_sink_table_entry_status_t
#else
typedef uint8_t sl_zigbee_gp_sink_table_entry_status_t;
enum
#endif
{
  /**
   * The GP table entry is in use for a Sink Table Entry.
   */
  SL_ZIGBEE_GP_SINK_TABLE_ENTRY_STATUS_ACTIVE = 0x01,
  /**
   * The proxy table entry is not in use.
   */
  SL_ZIGBEE_GP_SINK_TABLE_ENTRY_STATUS_UNUSED = 0xFF,
};

/**
 * @brief GPD Address for sending and receiving a GPDF.
 */
typedef struct {
  union {
    /** The IEEE address is used when the application identifier is
     *  ::SL_ZIGBEE_GP_APPLICATION_IEEE_ADDRESS.
     */
    sl_802154_long_addr_t gpdIeeeAddress;
    /** The 32-bit source identifier is used when the application identifier is
     *  ::SL_ZIGBEE_GP_APPLICATION_SOURCE_ID.
     */
    sl_zigbee_gp_source_id_t sourceId;
  } id;
  /** Application identifier of the GPD. */
  sl_zigbee_gp_application_id_t applicationId;
  /** Application endpoint , only used when application identifier is
   * ::SL_ZIGBEE_GP_APPLICATION_IEEE_ADDRESS
   */
  uint8_t endpoint;
} sl_zigbee_gp_address_t;

/**
 * @brief GP Sink Type.
 */
typedef enum {
  /** Sink Type is Full Unicast */
  SL_ZIGBEE_GP_SINK_TYPE_FULL_UNICAST,
  /** Sink Type is Derived groupcast, the group ID is derived from the GpdId during commissioning.
   * The sink is added to the APS group with that groupId.
   */
  SL_ZIGBEE_GP_SINK_TYPE_D_GROUPCAST,
  /** Sink type SL_ZIGBEE_GP_SINK_TYPE_GROUPCAST, the groupId can be obtained from the APS group table
   * or from the sink table.
   */
  SL_ZIGBEE_GP_SINK_TYPE_GROUPCAST,
  /** Sink Type is Light Weight Unicast. */
  SL_ZIGBEE_GP_SINK_TYPE_LW_UNICAST,
  /** Unused sink type */
  SL_ZIGBEE_GP_SINK_TYPE_UNUSED = 0xFF
} sl_zigbee_gp_sink_type_t;

/**
 * @brief GP Sink Address.
 */
typedef struct {
  /** EUI64 or long address of the sink */
  sl_802154_long_addr_t sinkEUI;
  /** Node ID or network address of the sink */
  sl_802154_short_addr_t sinkNodeId;
} sl_zigbee_gp_sink_address_t;

/**
 * @brief GP Sink Group.
 */
typedef struct {
  /** Group ID of the sink */
  uint16_t groupID;
  /** Alias ID of the sink */
  uint16_t alias;
} sl_zigbee_gp_sink_group_t;

/**
 * @brief GP Sink List Entry.
 */
typedef struct {
  /** Sink Type */
  sl_zigbee_gp_sink_type_t type;

  union {
    sl_zigbee_gp_sink_address_t unicast;
    sl_zigbee_gp_sink_group_t groupcast;
    sl_zigbee_gp_sink_group_t groupList;   // Entry for Sink Group List
  } target;
} sl_zigbee_gp_sink_list_entry_t;

/**
 * @brief The internal representation of a proxy table entry.
 */
typedef struct {
  /**
   * Internal status. Defines if the entry is unused or used as a proxy entry
   */
  sl_zigbee_gp_proxy_table_entry_status_t status;
  /**
   * The tunneling options (this contains both options and extendedOptions from the spec)
   */
  uint32_t options;
  /**
   * The addressing info of the GPD
   */
  sl_zigbee_gp_address_t gpd;
  /**
   * The assigned alias for the GPD
   */
  sl_802154_short_addr_t assignedAlias;
  /**
   * The security options field
   */
  uint8_t securityOptions;
  /**
   * The SFC of the GPD
   */
  sl_zigbee_gp_security_frame_counter_t gpdSecurityFrameCounter;
  /**
   * The key for the GPD.
   */
  sl_zigbee_key_data_t gpdKey;
  /**
   * The list of sinks; hardcoded to 2, which is the spec minimum
   */
  sl_zigbee_gp_sink_list_entry_t sinkList[GP_SINK_LIST_ENTRIES];
  /**
   * The groupcast radius
   */
  uint8_t groupcastRadius;
  /**
   * The search counter
   */
  uint8_t searchCounter;
} sl_zigbee_gp_proxy_table_entry_t;

/**
 * @brief The internal representation of a sink table entry.
 */
typedef struct {
  /**
   * Internal status. Defines if the entry is unused or used as a sink table entry
   */
  sl_zigbee_gp_sink_table_entry_status_t status;
  /**
   * The tunneling options (this contains both options and extendedOptions from the spec)
   */
  uint16_t options;
  /**
   * The addressing info of the GPD
   */
  sl_zigbee_gp_address_t gpd;
  /**
   * The device ID for the GPD
   */
  uint8_t deviceId;
  /**
   * The list of sinks; hardcoded to 2, which is the spec minimum
   */
  sl_zigbee_gp_sink_list_entry_t sinkList[GP_SINK_LIST_ENTRIES];
  /**
   * The assigned alias for the GPD
   */
  sl_802154_short_addr_t assignedAlias;
  /**
   * The groupcast radius
   */
  uint8_t groupcastRadius;
  /**
   * The security options field
   */
  uint8_t securityOptions;
  /**
   * The SFC of the GPD
   */
  sl_zigbee_gp_security_frame_counter_t gpdSecurityFrameCounter;
  /**
   * The GPD key associated with this entry.
   */
  sl_zigbee_key_data_t gpdKey;
} sl_zigbee_gp_sink_table_entry_t;

/**
 * @brief CGp Transmit options.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_c_gp_tx_option_t
#else
typedef uint8_t sl_zigbee_c_gp_tx_option_t;
enum
#endif
{
  /** No options. */
  SL_ZIGBEE_CGP_TX_OPTION_NONE = 0x00,
  /** Use CSMA/CA. */
  SL_ZIGBEE_CGP_TX_OPTION_USE_CSMA_CA = 0x01,
  /** Use MAC ACK. */
  SL_ZIGBEE_CGP_TX_OPTION_USE_MAC_ACK = 0x02,
  /** Reserved. */
  SL_ZIGBEE_CGP_TX_OPTION_RESERVED = 0xFC,
};

/**
 * @brief Addressing modes for CGp messages.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_c_gp_address_mode_t
#else
typedef uint8_t sl_zigbee_c_gp_address_mode_t;
enum
#endif
{
  /** No address (PAN identifier and address omitted). */
  SL_ZIGBEE_CGP_ADDRESS_MODE_NONE = 0x00,
  /** Reserved. */
  SL_ZIGBEE_CGP_ADDRESS_MODE_RESERVED = 0x01,
  /** 16-bit short address. */
  SL_ZIGBEE_CGP_ADDRESS_MODE_SHORT = 0x02,
  /** 64-bit extended address. */
  SL_ZIGBEE_CGP_ADDRESS_MODE_EXTENDED = 0x03,
};

/**
 * @brief Address for sending and receiving a CGp message.
 */
typedef struct {
  /** The address. */
  union {
    /** The 16-bit short address is used when the mode is
     *  ::SL_ZIGBEE_CGP_ADDRESS_MODE_SHORT.
     */
    sl_802154_short_addr_t shortId;
    /** The 64-bit extended address is used when the mode is
     *  ::SL_ZIGBEE_CGP_ADDRESS_MODE_EXTENDED.
     */
    sl_802154_long_addr_t extendedId;
  } address;
  /** The PAN identifier is used when the mode is not
   *  ::SL_ZIGBEE_CGP_ADDRESS_MODE_NONE.
   */
  sl_802154_pan_id_t panId;
  /** The addressing mode. */
  sl_zigbee_c_gp_address_mode_t mode;
} sl_zigbee_c_gp_address_t;
/**
 * @brief Transmit options for DGp messages.
 */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum sl_zigbee_d_gp_tx_option_t
#else
typedef uint8_t sl_zigbee_d_gp_tx_option_t;
enum
#endif
{
  /** No options. */
  SL_ZIGBEE_DGP_TX_OPTION_NONE = 0x00,
  /** Use gpTxQueue. */
  SL_ZIGBEE_DGP_TX_OPTION_USE_GP_TX_QUEUE = 0x01,
  /** Use CSMA/CA. */
  SL_ZIGBEE_DGP_TX_OPTION_USE_CSMA_CA = 0x02,
  /** Use MAC ACK. */
  SL_ZIGBEE_DGP_TX_OPTION_USE_MAC_ACK = 0x04,
  /** Data frame. */
  SL_ZIGBEE_DGP_TX_OPTION_FRAME_TYPE_DATA = 0x00,
  /** Maintenance frame. */
  SL_ZIGBEE_DGP_TX_OPTION_FRAME_TYPE_MAINTENANCE = 0x08,
  /** Reserved. */
  SL_ZIGBEE_DGP_TX_OPTION_RESERVED = 0xE0,
};

typedef struct {
  uint8_t foo;
} sl_zigbee_gp_proxy_cluster_attributes_t;

/**
 * @brief GP Tx queue entry.
 */
typedef struct {
  /** The entry in use */
  bool inUse;
  /** Use CCA during transmit */
  bool useCca;
  /** GP address */
  sl_zigbee_gp_address_t addr;
  /** GPD Command ID */
  uint8_t gpdCommandId;
  /** Handle for the outgoing message */
  uint8_t gpepHandle;
  /** Life time in milliseconds for the entry to expire, 0 indicates no expiry */
  uint16_t queueEntryLifetimeMs;
} sl_zigbee_gp_tx_queue_entry_t;

/**
 * @brief Application information.
 * During the commissioning of GPD that supports generic switch, multi sensor extension and compact report attribute
 * the application information is exchanged as part of the GPD commissioning command 0xE0 and 0xE4. This structure
 * holds the information for the commissioned GPD.
 */
typedef struct {
  /** Device ID of the GPD */
  uint8_t deviceId;
  /** Application Information bitmap */
  uint8_t applInfoBitmap;
  /** Manufacturer ID of the GPD */
  uint16_t manufacturerId;
  /** Model ID of the GPD */
  uint16_t modelId;
  /** Number of GPD commands supported by the GPD */
  uint8_t numberOfGpdCommands;
  /** Supported GPD Commands */
  uint8_t gpdCommands[GP_COMMISSIONING_MAX_BYTES - 1];
  /** Number of paired endpoints for the GPD */
  uint8_t numberOfPairedEndpoints;
  /** Paired endpoints */
  uint8_t pairedEndpoints[GP_COMMISSIONING_MAX_BYTES - 1];
  /** Number of operational client clusters present on the GPD, maximum is 15. */
  uint8_t numberOfGpdClientCluster;
  /** Number of operational server clusters present on the GPD, maximum is 15. */
  uint8_t numberOfGpdServerCluster;
  /** Operational server clusters present on the GPD */
  uint16_t serverClusters[15];
  /** Operational client clusters present on the GPD */
  uint16_t clientClusters[15];
} sl_zigbee_gp_application_info_t;

/**
 * @brief Attribute Record.
 * A compact attribute reporting feature, which uses the following information to translate the reports.
 */
typedef struct {
  /** Attribute ID */
  uint16_t              attributeID;
  /** Attribute data type */
  uint8_t               attributeDataType;
  /** Remaining attribute record length */
  /** Note: it is "N-1" i.e. total number of octet -1 of following attribute record field.
   * Therefore, 0b0000 indicates that 1 octet follows, which allows sink to skip equivalent
   * number of octets.
   */
  uint8_t               remainingAttributRecordLength; // on 4 bits
  /** Reported flag for the direction of if it is reported or received */
  uint8_t               reported;
  /** Attribute value preset flag */
  uint8_t               attrValuePresent;
  /** Offset of the attribute value in the report message */
  uint8_t               attrOffsetWithinReport;
  // TODO change "attrValue" from u32 to a pointer, as the data could be up to a string
  // the field "attributeDataType" tell with format it is, among  more than 55 possibilities)
  // so a add a private field which just tell the length of attrValue to easier
  // process it
  /** Attribute Value */
  uint32_t              attrValue;
  /** Attribute size */
  uint8_t               attrValueSize;
} sl_zigbee_gp_attribute_record_t;
/**
 * @brief Data point descriptor.
 * Compact attribute, Multi sensor or Generic switch feature uses this as descriptor to interpret the
 * incoming data from the GPD. This descriptor is set up at the sink during the commissioning.
 */
typedef struct {
  /** Number of attribute records */
  // Note: it is "N-1", if there is 2 attr record then nbAttrRecord=1 and not 2 !
  uint8_t               nbAttrRecord;
  /** Client or Server flag */
  uint8_t               clientServer;
  /** Manufacture ID present */
  uint8_t               ManIdPresent;
  /** Data point options */
  uint8_t               datapointOptions;
  /** Cluster ID */
  uint16_t              clusterID;
  /** Manufacture ID */
  uint16_t              manufacturerID;
  /** Attribute Record */
  sl_zigbee_gp_attribute_record_t attrRecord;
} sl_zigbee_gp_data_point_descriptor_t;

/**
 * @brief Report descriptor.
 * Compact attribute or Multi sensor feature uses this as descriptor to interpret the
 * incoming report from the GPD. This descriptor is set up at the sink during the commissioning.
 */
typedef struct {
  /** Report ID */
  uint8_t               repId;
  /** Report options */
  uint8_t               reportOptions;
  /** Report timeout period */
  uint16_t              timeoutPeriod;
  /** Total length of report */
  uint8_t               totalLength;
  /** Report data point descriptor */
  sl_zigbee_gp_data_point_descriptor_t  dataPoint;
} sl_zigbee_gp_report_descriptor_t;
/**
 * @brief Generic Switch Information.
 * Generic switch feature uses this as descriptor to interpret the
 * incoming switch command from the GPD. This information is set up at the sink during the commissioning.
 */
typedef struct {
  /** Switch Information Length */
  uint8_t switchInfoLength;
  /** Number of contacts in the switch */
  uint8_t nbOfContacts;
  /** Switch type */
  uint8_t switchType;
  /** Current contact */
  uint8_t currentContact;
  /** Saved contacts */
  uint8_t savedContact;
}sl_zigbee_gp_switch_information_t;

/**
 * @brief Switch Information.
 */
typedef struct {
  /** provides button information of the Generic switch for the current contacts status */
  uint8_t       currentStatus;
  /** Provides the bitmask to evaluate the received contact. As a result, the bitmask only
   * depends on the number of contacts of the current GPD.
   */
  uint8_t       contactBitmask;
} sl_zigbee_gp_generic_switch_data_t;

/**
 * @brief Additional Information Block Option Record Fields.
 * Provides information regarding the record fields from the linked translation table. Typically, a translation table,
 * which contains the generic switch, multi sensor or the compact attribute reporting GPD, needs to populate the information
 * during commissioning and use it to translate the shorter GPDF to the longer ZCL payload.
 */
typedef struct {
  /** Total Length of the additional information block */
  uint8_t       totalLengthOfAddInfoBlock;
  /** Option selector */
  uint8_t       optionSelector;
  union {
    /** Compact Attribute Reporting or Multi sensor */
    struct {
      uint8_t       reportIdentifier;
      uint8_t       attrOffsetWithinReport;
      uint16_t      clusterID;
      uint16_t      attributeID;
      uint8_t       attributeDataType;
      uint8_t       attributeOptions; //clientServer bit0 manufacturerIdPresent bit1
      uint16_t      manufacturerID;
    } compactAttr;
    /** Generic switch information */
    struct {
      /** Provides button information of the Generic switch for contacts status */
      uint8_t       contactStatus;
      /** Provides the bitmask to evaluate the received contact. As a result, the bitmask only
       * depends on the number of contacts of the current GPD.
       */
      uint8_t       contactBitmask;
    } genericSwitch;
  } optionData;//sl_zigbee_gp_translation_table_additional_info_block_option_record_option_data_field_t;
} sl_zigbee_gp_translation_table_additional_info_block_option_record_field_t;

//@} \\END GP Types

/**
 * @name API
 * @{
 */

// -----------------------------------------------------------------------------
// API

/** @brief DGp Send.
 *
 * This API adds or removes an outgoing GPDF (passed as ASDU) in the GP stub layer.
 * As part of Gp Response command processing by green power client cluster, this API
 * submits a outgoing a channel configuration or a commissioning reply GPDF. Similarly,
 * it is called with appropriate action to clear the Tx queue upon channel request timeout.
 *
 * @param action Action to add (true) or remove (false)
 * @param useCca Use CCA for GPDF transmission.
 * @param addr The gpd address ::sl_zigbee_gp_address_t.
 * @param gpdCommandId GPD Command ID
 * @param gpdAsduLength ASDU Length.
 * @param gpdAsdu The ASDU buffer that holds the outgoing GPDF as payload.
 * @param gpepHandle Handle for the asdu.
 * @param gpTxQueueEntryLifetimeMs Life time in milliseconds in Tx queue after which it gets cleared.
 *
 * @return An ::sl_status_t as status.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# gpdAsdu | length: gpdAsduLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */

sl_status_t sl_zigbee_d_gp_send(bool action,
                                bool useCca,
                                sl_zigbee_gp_address_t *addr,
                                uint8_t gpdCommandId,
                                uint8_t gpdAsduLength,
                                uint8_t const *gpdAsdu,
                                uint8_t gpepHandle,
                                uint16_t gpTxQueueEntryLifetimeMs);

// Tx Queue APIs

/** @brief Gets tx queue head
 *
 * This function gets the head pointer of the tx queue.
 * Note : since it returns a pointer to memory the head, it 'll not be useful on host.
 *
 * @return pointer to head of tx queue ::sli_zigbee_message_buffer_queue_t
 */
sli_zigbee_message_buffer_queue_t * sl_zigbee_gp_get_tx_queue_head(void);

/** @brief Sets maximum limit for number of entries in the tx queue
 *
 * This function sets the maximum number of entries the tx queue is supposed to grow.
 */
void sl_zigbee_gp_set_max_tx_queue_entry(uint16_t maxEntries);

/** @brief Gets the limit set for maximum number of entries in the tx queue
 *
 * This function gets the limit set for the maximum number of entries the tx queue is supposed to hold.
 *
 * @return limit to the maximum number of entries.
 */
uint16_t sl_zigbee_get_gp_max_tx_q_list_count(void);

/** @brief Gets the number of entries in the tx queue
 *
 * This function gets the number of entries present in tx queue.
 *
 * @return number of entries.
 */
uint16_t sl_zigbee_get_gp_tx_q_list_count(void);

/** @brief Gets an entry from Tx Queue
 * The function searches the tx queue using gpd address pointed by supplied in the input/output argument txQueue
 * and returns the message buffer that currently holding the outgoing gpdf information, returns SL_ZIGBEE_NULL_MESSAGE_BUFFER if not found.
 *
 * @param txQueue ::sl_zigbee_gp_tx_queue_entry_t A pointer to an allocated memory to get a copy of the tx queue entry from the buffer queue.
 *                The caller populates the addr field of this parameter which is used as a search key.
 * @param data A pointer to an allocated memory to get a copy of the gpd command payload if an entry is found.
 *                This can be passed as NULL if payload is not required by caller.
 * @param dataLength A pointer to hold the length of the gpd command payload when an entry is found and the data collector is non-NULL.
 * @param allocatedDataLength Size in bytes for the allocated memory for the data collector.
 *                        If this value is smaller compared to length of the data in the queue, no data gets copied out.
 * @return Buffer ::sli_buffer_manager_buffer_t that holds the entry if found, null message buffer if not found.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# data | length: allocatedDataLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 * {# dataLength #}
 */
sli_buffer_manager_buffer_t sl_zigbee_gp_get_tx_queue_entry_from_queue(sl_zigbee_gp_tx_queue_entry_t *txQueue,
                                                                       uint8_t *data,
                                                                       uint16_t *dataLength,
                                                                       uint16_t allocatedDataLength);

/** @brief Gets the entry at the specified index of Tx Queue
 * The function goes through the tx queue and populates the output parameters with the relevant entry
 * if it exists.
 *
 * @param index The index in the queue to retrieve from.
 * @param txQueue ::sl_zigbee_gp_tx_queue_entry_t A pointer to an allocated memory to get a copy of the tx queue entry from the buffer queue.
 *                The caller populates the addr field of this parameter which is used as a search key.
 * @param payload A pointer to an allocated memory to get a copy of the gpd command payload if an entry is found.
 *                This can be passed as NULL if payload is not required by caller.
 * @param payloadLength A pointer to hold the length of the gpd command payload when an entry is found and the data collector is non-NULL.
 * @param allocatedDataLength Size in bytes for the allocated memory for the data collector.
 *                        If this value is smaller compared to length of the data in the queue, no data gets copied out.
 * @return sl_status_t  SL_STATUS_OK if a valid entry was retrieved, SL_STATUS_NOT_FOUND if not.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# payload | length: *payload_len | max: MAX_IPC_VEC_ARG_CAPACITY #}
 * {# payload_len #}
 */
sl_status_t sl_zigbee_gp_get_tx_queue_entry_from_queue_index(uint8_t index,
                                                             sl_zigbee_gp_tx_queue_entry_t *txQueue,
                                                             uint8_t *payload,
                                                             uint16_t *payload_len);

/** @brief Adds an entry to Tx Queue
 * This function adds an entry along with supplied payload data to the Buffer queue. Returns the buffer handle
 * if success else null message buffer upon failure.
 * @param txQueue ::sl_zigbee_gp_tx_queue_entry_t A pointer to an allocated memory holding the entry with all the members of the structure assigned as needed.
 * @param data A pointer holding the data payload. Can be supplied as NULL if there is no data payload.
 * @param dataLength Length of the data.
 *
 * @return Buffer ::sli_buffer_manager_buffer_t that holds the entry upon success else null message buffer.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# data | length: dataLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
sli_buffer_manager_buffer_t sl_zigbee_gp_add_gp_tx_queue_entry_with_payload(sl_zigbee_gp_tx_queue_entry_t *txQueue,
                                                                            uint8_t *data,
                                                                            uint16_t dataLength);
/** @brief Remove an entry from Tx Queue
 * This function searches and removes the entry provided.
 *
 * @param txQueue ::sl_zigbee_gp_tx_queue_entry_t A pointer to an allocated memory holding the entry with gpd addr field assigned, which is used as for searching the tx queue.
 *                 NOTE : Use of wildcard gpd addr (AppId = 0,SrcId = 0xFFFFFFFF) , removes all the entries of the tx queue.
 * @return True upon success else false.
 */
bool sl_zigbee_gp_remove_from_tx_queue(sl_zigbee_gp_tx_queue_entry_t *txQueue);

/** @brief Purges Tx Queue
 * This function purges the tx queue.
 *
 */
void sl_zigbee_gp_clear_tx_queue(void);

#endif // SILABS_GP_TYPES_H

/** @} */ // end of name API

/** @} END addtogroup
 */
