/***************************************************************************//**
 * @file
 * @brief Place for common functions / definitions shared by Green Power Client/Server
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

#ifndef _SILABS_GREEN_POWER_COMMON_H_
#define _SILABS_GREEN_POWER_COMMON_H_

/**
 * @defgroup green-power-common Green Power Common
 * @ingroup component
 * @brief API and Callbacks for the Green Power Common Component
 *
 * A component that provides common functionalities between client
 * and server sides of the Green Power components.
 *
 */

/**
 * @addtogroup green-power-common
 * @{
 */
#define GREEN_POWER_SERVER_NO_PAIRED_ENDPOINTS                    0x00
#define GREEN_POWER_SERVER_RAW_GPD_PROCESS_IN_APP_ENDPOINTS       0xFD
#define GREEN_POWER_SERVER_RESERVED_ENDPOINTS                     0xFD
#define GREEN_POWER_SERVER_SINK_DERIVES_ENDPOINTS                 0xFE
#define GREEN_POWER_SERVER_ALL_SINK_ENDPOINTS                     0xFF

#define GREEN_POWER_SERVER_MIN_VALID_APP_ENDPOINT  1
#define GREEN_POWER_SERVER_MAX_VALID_APP_ENDPOINT  240

#define SL_ZIGBEE_AF_GP_GPD_CHANNEL_REQUEST_CHANNEL_TOGGLING_BEHAVIOR_RX_CHANNEL_NEXT_ATTEMPT (0x0F)
#define SL_ZIGBEE_AF_GP_GPD_CHANNEL_REQUEST_CHANNEL_TOGGLING_BEHAVIOR_RX_CHANNEL_SECOND_NEXT_ATTEMPT (0xF0)
#define SL_ZIGBEE_AF_GP_GPD_CHANNEL_REQUEST_CHANNEL_TOGGLING_BEHAVIOR_RX_CHANNEL_SECOND_NEXT_ATTEMPT_OFFSET (4)

#define SL_ZIGBEE_AF_GP_GPD_APPLICATION_DESCRIPTION_COMMAND_REPORT_OPTIONS_TIMEOUT_PERIOD_PRESENT           (0x01)
#define SL_ZIGBEE_AF_GP_TRANSLATION_TABLE_ZB_ENDPOINT_PASS_FRAME_TO_APLLICATION (0xFC)

#define SL_ZIGBEE_AF_GP_SINK_TABLE_ENTRY_OPTIONS_MASK                      (0x03FF)

// bitmap of how the translation table is scanned when a gpd entry
// is search into it
#define GP_TRANSLATION_TABLE_SCAN_LEVEL_GPD_ID                          (0x01)
#define GP_TRANSLATION_TABLE_SCAN_LEVEL_GPD_CMD_ID                      (0x02)
#define GP_TRANSLATION_TABLE_SCAN_LEVEL_GPD_PAYLOAD                     (0x04)
#define GP_TRANSLATION_TABLE_SCAN_LEVEL_ZB_ENDPOINT                     (0x08)
#define GP_TRANSLATION_TABLE_SCAN_LEVEL_ADDITIONAL_INFO_BLOCK           (0x10)

#define SL_ZIGBEE_GP_NOTIFICATION_COMMISSIONED_GROUPCAST_SEQUENCE_NUMBER_OFFSET  (9)

#define SL_ZIGBEE_AF_GP_GPP_GPD_LINK_RSSI         (0x3F)
#define SL_ZIGBEE_AF_GP_GPP_GPD_LINK_LINK_QUALITY (0xC0)
#define SL_ZIGBEE_AF_GP_GPP_GPD_LINK_LINK_QUALITY_OFFSET (6)

#define SL_ZIGBEE_AF_GP_PAIRING_CONFIGURATION_ACTIONS_MASK          (0x0F)
#define SL_ZIGBEE_AF_GP_PAIRING_CONFIGURATION_OPTION_MASK           (0x07FF)
#define SL_ZIGBEE_AF_GP_PAIRING_CONFIGURATION_OPTION_MASK           (0x07FF)

#define SL_ZIGBEE_AF_GP_APPLICATION_INFORMATION_CLUSTER_LIST_NUMBER_OF_SERVER_CLUSTER_MASK (0x0F)
#define SL_ZIGBEE_AF_GP_APPLICATION_INFORMATION_CLUSTER_LIST_NUMBER_OF_CLIENT_CLUSTER_MASK (0xF0)
#define SL_ZIGBEE_AF_GP_APPLICATION_INFORMATION_CLUSTER_LIST_NUMBER_OF_CLIENT_CLUSTER_MASK_OFFSET (4)

#define SL_ZIGBEE_AF_GP_APPLICATION_INFORMATION_GPD_APPLICATION_DESCRIPTION_COMMAND_FOLLOWS (0x20)
#define SL_ZIGBEE_AF_GP_APPLICATION_INFORMATION_GPD_APPLICATION_DESCRIPTION_COMMAND_FOLLOWS_OFFSET (5)

#define SL_ZIGBEE_AF_GP_APPLICATION_INFORMATION_SWITCH_INFORMATION_CONFIGURATION_NB_OF_CONTACT   (0x0F)
#define SL_ZIGBEE_AF_GP_APPLICATION_INFORMATION_SWITCH_INFORMATION_CONFIGURATION_SWITCH_TYPE     (0x30)
#define SL_ZIGBEE_AF_GP_APPLICATION_INFORMATION_SWITCH_INFORMATION_CONFIGURATION_SWITCH_TYPE_OFFSET (4)

#define GP_COMMISSIONING_SECURITY_LEVEL_TO_OPTIONS_SHIFT (4)
#define GP_COMMISSIONING_SECURITY_KEY_TYPE_TO_OPTIONS_SHIFT (6)
#define SL_ZIGBEE_GP_NOTIFICATION_COMMISSIONED_GROUPCAST_SEQUENCE_NUMBER_OFFSET (9)
#define SL_ZIGBEE_GP_COMMISSIONING_NOTIFICATION_SEQUENCE_NUMBER_OFFSET (12)

#define SL_ZIGBEE_AF_GREEN_POWER_SERVER_GPDF_SCENE_DERIVED_GROUP_ID (0xFFFF)

#define GP_DEVICE_ANNOUNCE_SPOOF_MSG_SIZE 12

// Reserved GPD addresses
#define IS_RESERVED_GPD_SRC_ID(srcId)       (((srcId) >=  GP_GPD_SRC_ID_RESERVED_FFFFFF9) \
                                             && ((srcId) <= GP_GPD_SRC_ID_RESERVED_FFFFFFE))

// If the GPD Src Id is 0
#define IS_GPD_SRC_ID_ZERO(appId, srcId) (((appId) == SL_ZIGBEE_GP_APPLICATION_SOURCE_ID) \
                                          && ((srcId) == GP_GPD_SRC_ID_RESERVED_0))

// TT, Option byte : additional information block present or not
#define sl_zigbee_af_green_power_t_t_get_additional_info_block_present(options) ((uint8_t) (options & 0x08))
// TT update cmd, Option byte :
#define sl_zigbee_af_green_power_t_t_update_get_additional_info_block_present(options) ((uint16_t) (options & 0x0100))
// Pairing config cmd, Option byte :
#define sl_zigbee_af_green_power_pairing_config_get_application_info_present(options) ((uint16_t) (options & 0x0400))
#define sl_zigbee_af_green_power_pairing_options_get_comm_mode(options) (((options) & SL_ZIGBEE_AF_GP_PAIRING_OPTION_COMMUNICATION_MODE) >> 5)
#define sl_zigbee_af_green_power_pairing_options_get_add_sink(options) (((options) & SL_ZIGBEE_AF_GP_PAIRING_OPTION_ADD_SINK) >> 3)
#define sl_zigbee_af_green_power_get_application_id(options) ((sl_zigbee_gp_application_id_t) ((options) & 0x07))
#define sl_zigbee_af_green_power_gpd_seq_num_cap(entry)      ((entry->options >> 8) & 0x01)
#define sl_zigbee_af_green_power_security_level(entry)     ((entry->options >> 9) & 0x03)
// If the value of this sub-field is 0b1, then the GPD is not expected to change
// its position during its operation in the network.
#define sl_zigbee_af_green_power_fixed_during_operation(options) ((((options) & GP_PAIRING_OPTIONS_GPD_FIXED) >> SL_ZIGBEE_AF_GP_PAIRING_OPTION_GPD_FIXED_OFFSET) & 0x01)
#define sl_zigbee_af_green_power_mobile_cap(options)          (!((((options) & GP_PAIRING_OPTIONS_GPD_FIXED) >> SL_ZIGBEE_AF_GP_PAIRING_OPTION_GPD_FIXED_OFFSET) & 0x01))
#define sl_zigbee_af_green_power_portable_cap(options)     ((((options) & GP_PAIRING_OPTIONS_GPD_FIXED) >> 7) & 0x01)
#define sl_zigbee_af_green_power_security_key_type(options) ((((options) & GP_PAIRING_OPTIONS_SECURITY_KEY_TYPE) >> 11) & 0x07)
#define sl_zigbee_af_green_power_check_return_of_put_data_in_response(ret) \
  ({  if ((ret) == NULL) {                                                 \
        return 0;                                                          \
      }                                                                    \
   })                                                                      \
/** @brief as the proxy table response status present in enum.h, this is for the sink
 *
 */
typedef enum {
  SL_ZIGBEE_ZCL_GP_GPD_GPP_LINK_QUALITY_POOR       = 0x00,
  SL_ZIGBEE_ZCL_GP_GPD_GPP_LINK_QUALITY_MODERATE   = 0x01,
  SL_ZIGBEE_ZCL_GP_GPD_GPP_LINK_QUALITY_HIGH       = 0x02,
  SL_ZIGBEE_ZCL_GP_GPD_GPP_LINK_QUALITY_EXCELLENT  = 0x03,
}sl_zigbee_af_g_p_gpd_gpp_link_quality_t;

/** @brief new enum for enum.h
 *
 */
typedef enum {
  SL_ZIGBEE_ZCL_GP_UNKNOWN_SWITCH_TYPE        = 0x00,
  SL_ZIGBEE_ZCL_GP_BUTTON_SWITCH_TYPE         = 0x01,
  SL_ZIGBEE_ZCL_GP_ROCKER_SWITCH_TYPE         = 0x02,
  SL_ZIGBEE_ZCL_GP_RESERVED_SWITCH_TYPE       = 0x03,
} sl_zigbee_af_g_p_generic_sw_switch_type_t;

/** @brief enum: sl_zigbee_af_gp_gpd_device_id_t
 *
 */
typedef enum {
  SL_ZIGBEE_GP_DEVICE_ID_GPD_SIMPLE_GENERIC_ONE_STATE_SWITCH   = 0x00,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_SIMPLE_GENERIC_TWO_STATE_SWITCH   = 0x01,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_ON_OFF_SWITCH                     = 0x02,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_LEVEL_CONTROL_SWITCH              = 0x03,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_SIMPLE_SENSOR_SWITCH              = 0x04,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_ADVANCED_GENERIC_ONE_STATE_SWITCH = 0x05,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_ADVANCED_GENERIC_TWO_STATE_SWITCH = 0x06,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_GENERIC_SWITCH                    = 0x07,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_COLOR_DIMMER_SWITCH               = 0x10,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_LIGHT_SENSOR_SWITCH               = 0x11,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_OCCUPANCY_SENSOR_SWITCH           = 0x12,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_DOOR_LOCK_CONTROLLER_SWITCH       = 0x20,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_TEMPERATURE_SENSOR_SWITCH         = 0x30,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_PRESSURE_SENSOR_SWITCH            = 0x31,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_FLOW_SENSOR_SWITCH                = 0x32,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_INDOOR_ENVIRONMENT_SENSOR         = 0x33,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_SCENCES                           = 0xFE,
  SL_ZIGBEE_GP_DEVICE_ID_GPD_UNDEFINED                         = 0xFE,
} sl_zigbee_af_gp_device_id_gpd_t;

/**
 * @name API
 * @{
 */

/** @brief Prepare a GP proxy commissioning mode command buffer.
 *
 * This function prepares an application framework ZCL command buffer for the GP
 * proxy commissioning mode command with supplied arguments and returns the buffer length.
 *
 * @param options Options Ver.: always
 * @param commissioningWindow Commissioning window in seconds Ver.: always
 * @param channel Proxy channel field Ver.: always
 *
 * @returns Length of the constructed command buffer
 */
#define sl_zigbee_af_fill_command_green_power_cluster_gp_proxy_table_response_smart(status,                                 \
                                                                                    totalNumberOfNonEmptyProxyTableEntries, \
                                                                                    startIndex,                             \
                                                                                    entriesCount)                           \
  sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND                                                           \
                                     | ZCL_DISABLE_DEFAULT_RESPONSE_MASK                                                    \
                                     | ZCL_FRAME_CONTROL_CLIENT_TO_SERVER),                                                 \
                                    ZCL_GREEN_POWER_CLUSTER_ID,                                                             \
                                    ZCL_GP_PROXY_TABLE_RESPONSE_COMMAND_ID,                                                 \
                                    "uuuu",                                                                                 \
                                    status,                                                                                 \
                                    totalNumberOfNonEmptyProxyTableEntries,                                                 \
                                    startIndex,                                                                             \
                                    entriesCount)

/** @brief Prepare a GP sink table response command buffer.
 *
 * This function prepares an application framework ZCL command buffer for the GP
 * sink table response command with supplied arguments and returns the buffer length.
 *
 * @param status Sink table response status Ver.: always
 * @param totalNumberofNonEmptySinkTableEntries Total number of entires in the sink table Ver.: always
 * @param startIndex Start index in the response Ver.: always
 * @param sinkTableEntriesCount Number of entries in the response Ver.: always
 *
 * @returns Length of the constructed command buffer
 */
#define sl_zigbee_af_fill_command_green_power_cluster_gp_sink_table_response_smart(status,                                \
                                                                                   totalNumberofNonEmptySinkTableEntries, \
                                                                                   startIndex,                            \
                                                                                   sinkTableEntriesCount)                 \
  sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND                                                         \
                                     | ZCL_DISABLE_DEFAULT_RESPONSE_MASK                                                  \
                                     | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT),                                               \
                                    ZCL_GREEN_POWER_CLUSTER_ID,                                                           \
                                    ZCL_GP_SINK_TABLE_RESPONSE_COMMAND_ID,                                                \
                                    "uuuu",                                                                               \
                                    status,                                                                               \
                                    totalNumberofNonEmptySinkTableEntries,                                                \
                                    startIndex,                                                                           \
                                    sinkTableEntriesCount)

/** @brief To provide GPD Command Translation Table content.
 *
 * Cluster: Green Power, The Green Power cluster defines the format of the commands exchanged when handling GPDs.
 * Command: GpTranslationTableResponse
 * @param status uint8_t
 * @param options uint8_t
 * @param totalNumberOfEntries uint8_t
 * @param startIndex uint8_t
 * @param entriesCount uint8_t
 * @param translationTableList uint8_t*
 * @param translationTableListLen uint16_t
 */
#define sl_zigbee_af_fill_command_green_power_cluster_gp_translation_table_response_smart(status,                  \
                                                                                          options,                 \
                                                                                          totalNumberOfEntries,    \
                                                                                          startIndex,              \
                                                                                          entriesCount,            \
                                                                                          translationTableList,    \
                                                                                          translationTableListLen) \
  sl_zigbee_af_fill_external_buffer((ZCL_CLUSTER_SPECIFIC_COMMAND                                                  \
                                     | ZCL_DISABLE_DEFAULT_RESPONSE_MASK                                           \
                                     | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT),                                        \
                                    ZCL_GREEN_POWER_CLUSTER_ID,                                                    \
                                    ZCL_GP_TRANSLATION_TABLE_RESPONSE_COMMAND_ID,                                  \
                                    "uuuuub",                                                                      \
                                    status,                                                                        \
                                    options,                                                                       \
                                    totalNumberOfEntries,                                                          \
                                    startIndex,                                                                    \
                                    entriesCount,                                                                  \
                                    translationTableList,                                                          \
                                    translationTableListLen)

/** @brief Prepare a GP notification command buffer.
 *
 * This function prepares an application framework ZCL command buffer for the GP
 * notification command with supplied arguments and returns the buffer length.
 *
 * @param options Options Ver.: always
 * @param gpdSrcId GPD Source Id Ver.: always
 * @param gpdIeee GPD IEEE address Ver.: always
 * @param gpdEndpoint GPD endpoint Ver.: always
 * @param gpdSecurityFrameCounter GPD security frame counter Ver.: always
 * @param gpdCommandId GPD command Id Ver.: always
 * @param gpdCommandPayloadLength Command payload length Ver.: always
 * @param gpdCommandPayload GPD command payload Ver.: always
 * @param gppShortAddress GP Proxy short address Ver.: always
 * @param gppDistance GP Proxy distance Ver.: always
 *
 * @returns Length of the constructed command buffer
 */
uint16_t sl_zigbee_af(uint16_t options,
                      uint32_t gpdSrcId,
                      uint8_t* gpdIeee,
                      uint8_t  gpdEndpoint,
                      uint32_t gpdSecurityFrameCounter,
                      uint8_t  gpdCommandId,
                      uint8_t gpdCommandPayloadLength,
                      const uint8_t* gpdCommandPayload,
                      uint16_t gppShortAddress,
                      uint8_t  gppDistance);
/** @brief Prepare a GP pairing search command buffer.
 *
 * This function prepares an application framework ZCL command buffer for the GP
 * pairing search command with supplied arguments and returns the buffer length.
 *
 * @param options Options Ver.: always
 * @param gpdSrcId GPD Source Id Ver.: always
 * @param gpdIeee GPD IEEE address Ver.: always
 * @param gpdEndpoint GPD endpoint Ver.: always
 *
 * @returns Length of the constructed command buffer
 */
uint16_t sl_zigbee_af_fill_command_green_power_cluster_gp_pairing_search_smart(uint16_t options,
                                                                               uint32_t gpdSrcId,
                                                                               uint8_t* gpdIeee,
                                                                               uint8_t gpdEndpoint);
/** @brief Prepare a GP tunneling stop command buffer.
 *
 * This function prepares an application framework ZCL command buffer for the GP
 * tunneling stop command with supplied arguments and returns the buffer length.
 *
 * @param options Options Ver.: always
 * @param gpdSrcId GPD Source Id Ver.: always
 * @param gpdIeee GPD IEEE address Ver.: always
 * @param gpdEndpoint GPD endpoint Ver.: always
 * @param gpdSecurityFrameCounter GPD security frame counter Ver.: always
 * @param gppShortAddress GP Proxy short address Ver.: always
 * @param gppDistance GP Proxy distance Ver.: always
 *
 * @returns Length of the constructed command buffer
 */
uint16_t sl_zigbee_af_fill_command_green_power_cluster_gp_tunneling_stop_smart(uint8_t options,
                                                                               uint32_t gpdSrcId,
                                                                               uint8_t* gpdIeee,
                                                                               uint8_t gpdEndpoint,
                                                                               uint32_t gpdSecurityFrameCounter,
                                                                               uint16_t gppShortAddress,
                                                                               int8_t gppDistance);
/** @brief Prepare a GP commissioning notification command buffer.
 *
 * This function prepares an application framework ZCL command buffer for the GP
 * commissioning notification command with supplied arguments and returns the
 * buffer length.
 *
 * @param options Options Ver.: always
 * @param gpdSrcId GPD Source Id Ver.: always
 * @param gpdIeee GPD IEEE address Ver.: always
 * @param gpdEndpoint GPD endpoint Ver.: always
 * @param sequenceNumber MAC Sequence to be used in security counter field for GPD security level 0 Ver.: always
 * @param gpdfSecurityLevel GPD security level Ver.: always
 * @param gpdSecurityFrameCounter GPD security frame counter Ver.: always
 * @param gpdCommandId GPD command Id Ver.: always
 * @param gpdCommandPayloadLength Command payload length Ver.: always
 * @param gpdCommandPayload GPD command payload Ver.: always
 * @param gppShortAddress GP Proxy short address Ver.: always
 * @param gppLink GPD-GP Proxy link Ver.: always
 * @param mic Message Integrity Code when security level is 2 or 3 Ver.: always
 *
 * @returns Length of the constructed command buffer
 */
uint16_t sl_zigbee_af_fill_command_green_power_cluster_gp_commissioning_notification_smart(uint16_t options,
                                                                                           uint32_t gpdSrcId,
                                                                                           uint8_t* gpdIeee,
                                                                                           uint8_t gpdEndpoint,
                                                                                           uint8_t sequenceNumber,
                                                                                           sl_zigbee_gp_security_level_t gpdfSecurityLevel,
                                                                                           sl_zigbee_gp_security_frame_counter_t gpdSecurityFrameCounter,
                                                                                           uint8_t gpdCommandId,
                                                                                           uint8_t gpdCommandPayloadLength,
                                                                                           const uint8_t *gpdCommandPayload,
                                                                                           sl_802154_short_addr_t gppShortAddress,
                                                                                           uint8_t gppLink,
                                                                                           sl_zigbee_gp_mic_t mic);
/** @brief Prepare a GP translation table update command buffer.
 *
 * This function prepares an application framework ZCL command buffer for the GP
 * translation table update command with supplied arguments and returns the
 * buffer length.
 *
 * @param options Options Ver.: always
 * @param gpdSrcId GPD Source Id Ver.: always
 * @param gpdIeee GPD IEEE address Ver.: always
 * @param gpdEndpoint GPD endpoint Ver.: always
 * @param translationsLength Length of the translations packet Ver.: always
 * @param translations On or more number of translations Ver.: always
 * @param additionnalInfoBlock Additional Information block used along with the translations Ver.: always
 *
 * @returns Length of the constructed command buffer
 */
uint16_t sl_zigbee_af_fill_command_green_power_cluster_gp_translation_table_update_smart(uint16_t options,
                                                                                         uint32_t gpdSrcId,
                                                                                         uint8_t* gpdIeee,
                                                                                         uint8_t gpdEndpoint,
                                                                                         uint8_t translationsLength,
                                                                                         sl_zigbee_zcl_gp_translation_table_update_translation_t* translations,
                                                                                         sl_zigbee_gp_translation_table_additional_info_block_option_record_field_t* additionnalInfoBlock);
/** @brief Prepare a GP pairing configuration command buffer.
 *
 * This function prepares an application framework ZCL command buffer for the GP
 * pairing configuration command with supplied arguments and returns the
 * buffer length.
 *
 * @param actions GP Pairing actions field Ver.: always
 * @param options Options Ver.: always
 * @param gpdSrcId GPD Source Id Ver.: always
 * @param gpdIeee GPD IEEE address Ver.: always
 * @param gpdEndpoint GPD endpoint Ver.: always
 * @param gpdDeviceId GPD Device Id Ver.: always
 * @param groupListCount Group list count Ver.: always
 * @param groupList Group list Ver.: always
 * @param gpdAssignedAlias GPD assigned alias Ver.: always
 * @param groupcastRadius Group cast radius Ver.: always
 * @param securityOptions Security options Ver.: always
 * @param gpdSecurityFrameCounter Security frame counter Ver.: always
 * @param gpdSecurityKey Security key Ver.: always
 * @param numberOfPairedEndpoints Number of paired endpoints Ver.: always
 * @param pairedEndpoints Paired endpoint list Ver.: always
 * @param applicationInformation Application information field Ver.: always
 * @param manufacturerId GPD Manufacture Id Ver.: always
 * @param modeId GPD Model Id Ver.: always
 * @param numberOfGpdCommands Number of GPD commands Ver.: always
 * @param gpdCommandIdList GPD commands list Ver.: always
 * @param clusterIdListCount Cluster List count Ver.: always
 * @param clusterListServer Server cluster list Ver.: always
 * @param clusterListClient Client cluster list Ver.: always
 * @param switchInformationLength Generic switch information length Ver.: always
 * @param genericSwitchConfiguration GGeneric switch configuration Ver.: always
 * @param currentContactStatus Current contact status Ver.: always
 * @param totalNumberOfReports Total number of reports configured Ver.: always
 * @param numberOfReports Number of reports in the report present in descriptor Ver.: always
 * @param reportDescriptor Report descriptors list Ver.: always
 *
 * @returns Length of the constructed command buffer
 */
uint16_t sl_zigbee_af_fill_command_green_power_cluster_gp_pairing_configuration_smart(uint8_t actions,
                                                                                      uint16_t options,
                                                                                      uint32_t gpdSrcId,
                                                                                      uint8_t* gpdIeee,
                                                                                      uint8_t gpdEndpoint,
                                                                                      uint8_t gpdDeviceId,
                                                                                      uint8_t groupListCount,
                                                                                      uint8_t* groupList,
                                                                                      uint16_t gpdAssignedAlias,
                                                                                      uint8_t groupcastRadius,
                                                                                      uint8_t securityOptions,
                                                                                      uint32_t gpdSecurityFrameCounter,
                                                                                      uint8_t* gpdSecurityKey,
                                                                                      uint8_t numberOfPairedEndpoints,
                                                                                      uint8_t* pairedEndpoints,
                                                                                      uint8_t applicationInformation,
                                                                                      uint16_t manufacturerId,
                                                                                      uint16_t modeId,
                                                                                      uint8_t numberOfGpdCommands,
                                                                                      uint8_t * gpdCommandIdList,
                                                                                      uint8_t clusterIdListCount,
                                                                                      uint16_t * clusterListServer,
                                                                                      uint16_t * clusterListClient,
                                                                                      uint8_t switchInformationLength,
                                                                                      uint8_t genericSwitchConfiguration,
                                                                                      uint8_t currentContactStatus,
                                                                                      uint8_t totalNumberOfReports,
                                                                                      uint8_t numberOfReports,
                                                                                      uint8_t* reportDescriptor);
/** @brief Prepare a GP sink table request command buffer.
 *
 * This function prepares an application framework ZCL command buffer for the GP
 * sink table request command with supplied arguments and returns the
 * buffer length.
 *
 * @param options Options Ver.: always
 * @param gpdSrcId GPD Source Id Ver.: always
 * @param gpdIeee GPD IEEE address Ver.: always
 * @param gpdEndpoint GPD endpoint Ver.: always
 * @param index Requested table index to start Ver.: always
 *
 * @returns Length of the constructed command buffer
 */
uint16_t sl_zigbee_af_fill_command_green_power_cluster_gp_sink_table_request_smart(uint8_t options,
                                                                                   uint32_t gpdSrcId,
                                                                                   uint8_t* gpdIeee,
                                                                                   uint8_t gpdEndpoint,
                                                                                   uint8_t index);
/** @brief Prepare a GP notification response command buffer.
 *
 * This function prepares an application framework ZCL command buffer for the GP
 * notification response command with supplied arguments and returns the
 * buffer length.
 *
 * @param options Options Ver.: always
 * @param gpdSrcId GPD Source Id Ver.: always
 * @param gpdIeee GPD IEEE address Ver.: always
 * @param gpdEndpoint GPD endpoint Ver.: always
 * @param gpdSecurityFrameCounter GPD security frame counter Ver.: always
 *
 * @returns Length of the constructed command buffer
 */
uint32_t sl_zigbee_af_fill_command_green_power_cluster_gp_notification_response_smart(uint8_t options,
                                                                                      uint32_t gpdSrcId,
                                                                                      uint8_t* gpdIeee,
                                                                                      uint8_t gpdEndpoint,
                                                                                      uint32_t gpdSecurityFrameCounter);
/** @brief Prepare a GP pairing command buffer.
 *
 * This function prepares an application framework ZCL command buffer for the GP
 * pairing command with supplied arguments and returns the buffer length.
 *
 * @param options Options Ver.: always
 * @param gpdSrcId GPD Source Id Ver.: always
 * @param gpdIeee GPD IEEE address Ver.: always
 * @param gpdEndpoint GPD endpoint Ver.: always
 * @param sinkIeeeAddress Sink IEEE address Ver.: always
 * @param sinkNwkAddress Sink network address Ver.: always
 * @param sinkGroupId Sink group Id Ver.: always
 * @param deviceId GPD Device Id Ver.: always
 * @param gpdSecurityFrameCounter GPD security frame counter Ver.: always
 * @param gpdKey GPD security key Ver.: always
 * @param assignedAlias GPD assigned alias Ver.: always
 * @param groupcastRadius Group cast radius of this message Ver.: always
 *
 * @returns Length of the constructed command buffer
 */
uint16_t sl_zigbee_af_fill_command_green_power_cluster_gp_pairing_smart(uint32_t options,
                                                                        uint32_t gpdSrcId,
                                                                        uint8_t* gpdIeee,
                                                                        uint8_t gpdEndpoint,
                                                                        uint8_t* sinkIeeeAddress,
                                                                        uint16_t sinkNwkAddress,
                                                                        uint16_t sinkGroupId,
                                                                        uint8_t deviceId,
                                                                        uint32_t gpdSecurityFrameCounter,
                                                                        uint8_t* gpdKey,
                                                                        uint16_t assignedAlias,
                                                                        uint8_t groupcastRadius);
/** @brief Prepare a GP proxy commissioning mode command buffer.
 *
 * This function prepares an application framework ZCL command buffer for the GP
 * proxy commissioning mode command with supplied arguments and returns the buffer length.
 *
 * @param options Options Ver.: always
 * @param commissioningWindow Commissioning window in seconds Ver.: always
 * @param channel Proxy channel field Ver.: always
 *
 * @returns Length of the constructed command buffer
 */
uint16_t sl_zigbee_af_fill_command_green_power_cluster_gp_proxy_commissioning_mode_smart(uint8_t options,
                                                                                         uint16_t commissioningWindow,
                                                                                         uint8_t channel);
/** @brief Prepare a GP response command buffer.
 *
 * This function prepares an application framework ZCL command buffer for the GP
 * response command with supplied arguments and returns the buffer length.
 *
 * @param options Options Ver.: always
 * @param tempMasterShortAddress Proxy Temp Master short address Ver.: always
 * @param tempMasterTxChannel Proxy Temp Master transmit channel Ver.: always
 * @param gpdSrcId GPD Source Id Ver.: always
 * @param gpdIeee GPD IEEE address Ver.: always
 * @param gpdEndpoint GPD endpoint Ver.: always
 * @param gpdCommandId GPD command id Ver.: always
 * @param gpdCommandPayloadLength GPD command length Ver.: always
 * @param gpdCommandPayload GPD command payload Ver.: always
 *
 * @returns Length of the constructed command buffer
 */
uint16_t sl_zigbee_af_fill_command_green_power_cluster_gp_response_smart(uint8_t  options,
                                                                         uint16_t tempMasterShortAddress,
                                                                         uint8_t  tempMasterTxChannel,
                                                                         uint32_t gpdSrcId,
                                                                         uint8_t* gpdIeee,
                                                                         uint8_t  gpdEndpoint,
                                                                         uint8_t  gpdCommandId,
                                                                         uint8_t gpdCommandPayloadLength,
                                                                         uint8_t* gpdCommandPayload);
/** @brief Prepare a GP proxy table request command buffer.
 *
 * This function prepares an application framework ZCL command buffer for the GP
 * proxy table request command with supplied arguments and returns the buffer length.
 *
 * @param options Options Ver.: always
 * @param gpdSrcId GPD Source Id Ver.: always
 * @param gpdIeee GPD IEEE address Ver.: always
 * @param gpdEndpoint GPD endpoint Ver.: always
 * @param index Requested table index to start Ver.: always
 *
 * @returns Length of the constructed command buffer
 */
uint16_t sl_zigbee_af_fill_command_green_power_cluster_gp_proxy_table_request_smart(uint8_t options,
                                                                                    uint32_t gpdSrcId,
                                                                                    uint8_t* gpdIeee,
                                                                                    uint8_t gpdEndpoint,
                                                                                    uint8_t index);
/** @brief Compare two GP Addresses.
 *
 * This function compares two GP Addresses and returns true if they are the same.
 *
 * @param a1 First address to compare Ver.: always
 * @param a2 Second address to compare Ver.: always
 *
 * @returns True if the address are same
 */
bool sl_zigbee_af_green_power_common_gp_addr_compare(const sl_zigbee_gp_address_t * a1,
                                                     const sl_zigbee_gp_address_t * a2);

/** @} */ // end of name API
/** @} */ // end of green-power-common

sl_802154_short_addr_t sli_zigbee_gpd_alias(sl_zigbee_gp_address_t *addr);

bool sli_zigbee_af_gp_make_addr(sl_zigbee_gp_address_t *addr,
                                sl_zigbee_gp_application_id_t appId,
                                sl_zigbee_gp_source_id_t srcId,
                                uint8_t *gpdIeee,
                                uint8_t endpoint);
uint16_t sli_zigbee_af_copy_additional_info_block_structure_to_array(uint8_t commandId,
                                                                     sl_zigbee_gp_translation_table_additional_info_block_option_record_field_t *additionalInfoBlockIn,
                                                                     uint8_t *additionalInfoBlockOut);
void sli_zigbee_af_gp_spoof_device_annce(uint16_t nodeId,
                                         sl_802154_long_addr_t eui64,
                                         uint8_t capabilities);

sl_status_t sli_zigbee_af_gp_send_response_unicast(void);
#endif //_GREEN_POWER_COMMON_H_
