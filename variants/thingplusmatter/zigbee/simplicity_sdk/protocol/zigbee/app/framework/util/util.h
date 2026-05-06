/***************************************************************************//**
 * @file
 * @brief
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

// *******************************************************************
// * util.h
// *
// *
// * Copyright 2007-2017 by Silicon Laboratories. All rights reserved.      *80*
// *******************************************************************

#ifndef __AF_UTIL_H__
#define __AF_UTIL_H__

// User asserts can override SLAB_ASSERT and should be defined as follows:
// void userAssert (int file, int line);                   // declaration
// #define USER_ASSERT(file, line) userAssert(file, line)  // definition

#if defined(NO_ASSERT)
 #define SLAB_ASSERT(expr)
#else
 #if defined(USER_ASSERT)
  #define SLAB_ASSERT(expr) \
  ((expr) ? ((void)0) : USER_ASSERT(__FILE__, __LINE__))
 #else
  #define SLAB_ASSERT(expr) \
  ((expr) ? ((void)0) : slabAssert(__FILE__, __LINE__))
 #endif // USER_ASSERT
#endif // NO_ASSERT

// This controls the type of response. Normally The library sends an automatic
// response (if appropriate) on the same PAN. The reply can be disabled by
// calling sl_zigbee_af_set_no_reply_for_next_message.
#define ZCL_UTIL_RESP_NORMAL   0u
#define ZCL_UTIL_RESP_NONE     1u
#define ZCL_UTIL_RESP_INTERPAN 2u

// Write response codes for Zigbee BLE DMP
#define ES_WRITE_OK                 0
#define ES_READ_OK                  0
#define ES_ERR_CCCD_CONF            0x81
#define ES_ERR_APPLICATION_SPECIFIC 0x80
#define ES_NO_CONNECTION            0xFF

// Well-known key for distributed network
#define ZIGBEE_3_DISTRIBUTED_SECURITY_LINK_KEY         \
  {                                                    \
    { 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7,  \
      0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF } \
  }

// Well-known key for centralized network
#define ZIGBEE_3_CENTRALIZED_SECURITY_LINK_KEY         \
  {                                                    \
    { 0x5A, 0x69, 0x67, 0x42, 0x65, 0x65, 0x41, 0x6C,  \
      0x6C, 0x69, 0x61, 0x6E, 0x63, 0x65, 0x30, 0x39 } \
  }

// Cluster name structure
typedef struct {
  uint16_t id;
  uint16_t mfgCode;
  const char * name;
} sl_zigbee_af_cluster_name_t;

extern const sl_zigbee_af_cluster_name_t sl_zigbee_zcl_cluster_names[];

#define ZCL_NULL_CLUSTER_ID 0xFFFFu

#include "../include/af.h"

// Override APS retry: 0 - don't touch, 1 - always set, 2 - always unset
typedef enum {
  SL_ZIGBEE_AF_RETRY_OVERRIDE_NONE  = 0,
  SL_ZIGBEE_AF_RETRY_OVERRIDE_SET   = 1,
  SL_ZIGBEE_AF_RETRY_OVERRIDE_UNSET = 2
} sl_zigbee_af_retry_override_t;

// The default APS retry flag value is controlled by SL_ZIGBEE_AF_DEFAULT_APS_OPTIONS
// and is usually 1. In high traffic, low bandwidth networks (e.g. sub-GHz),
// the app may want to override this. Two methods are available for apps that
// may wants to do this dynamically per message:
// 1. Call sl_zigbee_af_set_retry_override each time before filling the message buffer;
// 2. Call sl_zigbee_af_set_retry_override once with a value covering most messages and
//    then toggling the flag as necessary in sl_zigbee_af_pre_message_send_cb.
void sl_zigbee_af_set_retry_override(sl_zigbee_af_retry_override_t value);

// Return the current override status
sl_zigbee_af_retry_override_t sl_zigbee_af_get_retry_override(void);

// This function applies the curent override value to the APS options.
// It is called internally by the framework in the final stages of filling the
// message buffer.
void sli_zigbee_af_apply_retry_override(sl_zigbee_aps_option_t *options);

// Override Disable Default Response flag in the ZCL Frame Control
typedef enum {
  SL_ZIGBEE_AF_DISABLE_DEFAULT_RESPONSE_NONE = 0,           // no override
  SL_ZIGBEE_AF_DISABLE_DEFAULT_RESPONSE_ONE_SHOT = 1,       // next message only
  SL_ZIGBEE_AF_DISABLE_DEFAULT_RESPONSE_PERMANENT  = 2      // until cancelled
} sl_zigbee_af_disable_default_response_t;

// The default value for the Disable Default Response flag in ZCL Frame Control
// is 0 (i.e. default responses are generated). The app can disable default
// reponses either for the next message only or for all messages until another
// call to this function.
void sl_zigbee_af_set_disable_default_response(sl_zigbee_af_disable_default_response_t value);

// Return the current status
sl_zigbee_af_disable_default_response_t sl_zigbee_af_get_disable_default_response(void);

// This function applies the curent override value to the ZCL Frame Control.
// It is called internally by the framework in the final stages of filling the
// message buffer.
void sli_zigbee_af_apply_disable_default_response(uint8_t *frame_control);

// Returns a mfg code from current command.
// This should only be used within the command parsing context.
// Wraps sl_zigbee_af_current_command(), and assumes that the current comamnd
// is either the current valid command or NULL
// In the case of NULL, then it returns SL_ZIGBEE_AF_NULL_MANUFACTURER_CODE
uint16_t sl_zigbee_af_get_mfg_code_from_current_command(void);

// SL_ZIGBEE_AF_MAXIMUM_SEND_PAYLOAD_LENGTH is defined in config.h
#define SL_ZIGBEE_AF_RESPONSE_BUFFER_LEN SL_ZIGBEE_AF_MAXIMUM_SEND_PAYLOAD_LENGTH

void sl_zigbee_af_init(uint8_t init_level);
void sl_zigbee_af_tick(void);
uint16_t sl_zigbee_af_find_cluster_name_index(uint16_t cluster);
uint16_t sl_zigbee_af_find_cluster_name_index_with_mfg_code(uint16_t cluster, uint16_t mfgCode);
void sl_zigbee_af_stack_down(void);

void sl_zigbee_af_decode_and_print_cluster(uint16_t cluster);
void sl_zigbee_af_decode_and_print_cluster_with_mfg_code(uint16_t cluster, uint16_t mfgCode);

bool sl_zigbee_af_process_message(sl_zigbee_aps_frame_t *apsFrame,
                                  sl_zigbee_incoming_message_type_t type,
                                  uint8_t *message,
                                  uint16_t msgLen,
                                  sl_802154_short_addr_t source,
                                  sli_zigbee_interpan_header_t *interPanHeader);

bool sl_zigbee_af_process_message_into_zcl_cmd(sl_zigbee_aps_frame_t* apsFrame,
                                               sl_zigbee_incoming_message_type_t type,
                                               uint8_t* message,
                                               uint16_t messageLength,
                                               sl_802154_short_addr_t source,
                                               sli_zigbee_interpan_header_t* interPanHeader,
                                               sl_zigbee_af_cluster_command_t* returnCmd);

/**
 * Retrieves the difference between the two passed values.
 * This function assumes that the two values have the same endianness.
 * On platforms that support 64-bit primitive types, this function will work
 * on data sizes up to 8 bytes. Otherwise, it will only work on data sizes of
 * up to 4 bytes.
 */
sl_zigbee_af_difference_type_t sl_zigbee_af_get_difference(uint8_t* pData,
                                                           sl_zigbee_af_difference_type_t value,
                                                           uint8_t dataSize,
                                                           sl_zigbee_af_attribute_type_t dataType);

/**
 * Retrieves an uint32_t from the given Zigbee payload. The integer retrieved
 * may be cast into an integer of the appropriate size depending on the
 * number of bytes requested from the message. In Zigbee, all integers are
 * passed over the air in LSB form. LSB to MSB conversion is
 * done within this function automatically before the integer is returned.
 *
 * Obviously (due to return value) this function can only handle
 * the retrieval of integers between 1 and 4 bytes in length.
 *
 */
uint32_t sl_zigbee_af_get_int(const uint8_t* message, uint16_t currentIndex, uint16_t msgLen, uint8_t bytes);

uint8_t sli_decode_parse_one_byte(sl_zigbee_af_cluster_command_t *cmd, uint16_t payloadOffset);
uint16_t sli_decode_parse_two_bytes(sl_zigbee_af_cluster_command_t *cmd, uint16_t payloadOffset);
uint32_t sli_decode_parse_three_bytes(sl_zigbee_af_cluster_command_t *cmd, uint16_t payloadOffset);
uint32_t sli_decode_parse_four_bytes(sl_zigbee_af_cluster_command_t *cmd, uint16_t payloadOffset);
uint8_t *sli_decode_string(sl_zigbee_af_cluster_command_t * cmd, uint16_t payloadOffset);
uint8_t * sli_decode_long_string(sl_zigbee_af_cluster_command_t * cmd, uint16_t payloadOffset);
uint8_t * sli_decode_bytes(sl_zigbee_af_cluster_command_t * cmd, uint16_t payloadOffset);

void sl_zigbee_af_clear_response_data(void);
uint8_t  * sl_zigbee_af_put_int8u_in_resp(uint8_t value);
uint16_t * sl_zigbee_af_put_int16u_in_resp(uint16_t value);
uint32_t * sl_zigbee_af_put_int32u_in_resp(uint32_t value);
uint32_t * sl_zigbee_af_put_int24u_in_resp(uint32_t value);
uint8_t * sl_zigbee_af_put_block_in_resp(const uint8_t* data, uint16_t length);
uint8_t * sl_zigbee_af_put_string_in_resp(const uint8_t *buffer);
uint8_t * sl_zigbee_af_put_date_in_resp(sl_zigbee_af_date_t *value);

bool sl_zigbee_af_is_this_my_eui64(sl_802154_long_addr_t eui64);

uint32_t sl_zigbee_af_get_buffer_crc(uint8_t *pbuffer, uint16_t length, uint32_t initialValue);

// If the variable has not been set, APS_TEST_SECURITY_DEFAULT will
// eventually return false.
enum {
  APS_TEST_SECURITY_ENABLED = 0,
  APS_TEST_SECURITY_DISABLED = 1,
  APS_TEST_SECURITY_DEFAULT = 2,
};
extern uint8_t sli_zigbee_af_test_aps_security_override;

sl_802154_short_addr_t sli_zigbee_af_get_sender(void);
sl_status_t sli_zigbee_af_get_sender_eui64(sl_802154_long_addr_t sender_eui64);
sl_status_t sli_zigbee_af_get_last_hop_lqi(uint8_t *lqi);
sl_status_t sli_zigbee_af_get_last_hop_rssi(int8_t *rssi);
uint8_t sli_zigbee_af_get_binding_index(void);
uint8_t sli_zigbee_af_get_address_index(void);

// DEPRECATED.
extern uint8_t sl_zigbee_af_incoming_zcl_sequence_number;

// the caller to the library can set a flag to say do not respond to the
// next ZCL message passed in to the library. Passing true means disable
// the reply for the next ZCL message. Setting to false re-enables the
// reply (in the case where the app disables it and then doesnt send a
// message that gets parsed).
void sl_zigbee_af_set_no_reply_for_next_message(bool set);

// this function determines if APS Link key should be used to secure
// the message. It is based on the clusterId and specified in the SE
// app profile.  If the message is outgoing then the
bool sl_zigbee_af_determine_if_link_security_is_required(uint8_t commandId,
                                                         bool incoming,
                                                         bool broadcast,
                                                         sl_zigbee_af_profile_id_t profileId,
                                                         sl_zigbee_af_cluster_id_t clusterId,
                                                         sl_802154_short_addr_t remoteNodeId);

#define isThisDataTypeSentLittleEndianOTA(dataType) \
  (!(sl_zigbee_af_is_this_data_type_a_string_type(dataType)))

bool sli_zigbee_af_process_global_command(sl_zigbee_af_cluster_command_t *cmd);
bool sli_zigbee_af_process_cluster_specific_command(sl_zigbee_af_cluster_command_t *cmd);

extern uint8_t sl_zigbee_af_response_type;

uint16_t sl_zigbee_af_strnlen(const uint8_t* string, uint16_t maxLength);

/* @brief Append characters to a ZCL string.
 *
 * Appending characters to an existing ZCL string. If it is an invalid string
 * (length byte equals 0xFF), no characters will be appended.
 *
 * @param zclString - pointer to the zcl string
 * @param zclStringMaxLen - length of zcl string (does not include zcl length byte)
 * @param src - pointer to plain text characters
 * @param srcLen - length of plain text characters
 *
 * @return number of characters appended
 *
 */
uint8_t sl_zigbee_af_append_characters(uint8_t * zclString,
                                       uint8_t zclStringMaxLen,
                                       const uint8_t * appendingChars,
                                       uint8_t appendingCharsLen);

extern uint8_t sli_zigbee_af_extended_pan_id[];

// A boolean utility flag to indicate if a command response created and submitted during
// a message handling (by global or cluster specific command handlers) within sl_zigbee_af_process_message.
// This is cleared at the start of the sl_zigbee_af_process_message function and is set by the
// command response call sl_zigbee_af_send_response_with_cb. This flag is checked in function
// sli_zigbee_af_process_cluster_specific_command as a qualifier to call sl_zigbee_af_send_response_with_cb.
extern bool sli_command_or_default_response_submitted;

sl_status_t sli_zigbee_af_validate_channel_pages(uint8_t page, uint8_t channel);

/* @brief A Silicon Labs assert function
 *
 * This function is provided to call an assert function in the application code.
 * It starts an infinite loop that provokes the watchdog to fire.
 *
 * @param file - the source file that calls this assert
 * @param line - the line that calls this assert
 *
 * @return void
 *
 */
void slabAssert(const char * file, int line);

/* @brief Get the page number from an 8-bit encoded channel-page
 *
 * The top three bits denote the page number, like this:
 *   000x xxxx = page 0
 *   100x xxxx = page 28
 *   101x xxxx = page 29
 *   110x xxxx = page 30
 *   111x xxxx = page 31
 *
 * @param chanPg - 8-bit encoded channel and page
 *
 * @return page number (0, 28-31, 0xFF if invalid)
 */
uint8_t sl_zigbee_af_get_page_from_8bit_encoded_chan_pg(uint8_t chanPg);

/* @brief Get the channel number from an 8-bit encoded channel-page
 *
 * The bottom 5 bits denote the channel within the page.
 *
 * Provided for symmetry with the above sl_zigbee_af_get_page_from_8bit_encoded_chan_pg().
 * It simply masks the bottom 5 bits.
 *
 * @param chanPg - 8-bit encoded channel and page
 *
 * @return channel number (0-8, 0-26, 11-26, depending on the page)
 */
uint8_t sl_zigbee_af_get_channel_from_8bit_encoded_chan_pg(uint8_t chanPg);

/* @brief Make an 8-bit encoded channel-page from channel and page arguments
 *
 * @param page
 * @param channel
 *
 * @return 8-bit encoded channel-page, 0xFF if invalid
 */
uint8_t sl_zigbee_af_make_8bit_encoded_chan_pg(uint8_t page, uint8_t channel);

/* @brief Suppress all automatic responses from specified cluster.
 *
 * @param cluster - cluster id
 * @param serverClient - server (0) or client (1)
 *
 * @return SL_ZIGBEE_ZCL_STATUS_SUCCESS if successful, SL_ZIGBEE_ZCL_STATUS_INSUFFICIENT_SPACE
 * if no room in command table
 */
sl_zigbee_af_status_t sl_zigbee_af_set_suppress_cluster(uint16_t clusterId, bool isClientCluster);

/* @brief Gets current suppression state for specified cluster.
 *
 * @param cluster - cluster id
 * @param serverClient - server (0) or client (1)
 *
 * @return TRUE if cluster responses are being suppressed
 */
bool sl_zigbee_af_get_suppress_cluster(uint16_t clusterId, bool isClientCluster);

/* @brief Suppress all automatic responses from specified cluster command.
 *
 * @param cluster - cluster id
 * @param serverClient - server (0) or client (1)
 * @param command - command id
 *
 * @return SL_ZIGBEE_ZCL_STATUS_SUCCESS if successful, SL_ZIGBEE_ZCL_STATUS_INSUFFICIENT_SPACE
 * if no room in command table
 */
sl_zigbee_af_status_t sl_zigbee_af_set_suppress_command(uint16_t clusterId, bool serverClient, uint8_t commandId);

/* @brief Gets current suppression state for specified command.
 *
 * @param cluster - cluster id
 * @param serverClient - server (0) or client (1)
 * @param command - command id
 *
 * @return TRUE if command responses are being suppressed
 */
bool sl_zigbee_af_get_suppress_command(uint16_t clusterId, bool serverClient, uint8_t commandId);

/* @brief Print cluster/command suppression table.
 */
void sl_zigbee_af_print_suppression_table(void);

#endif // __AF_UTIL_H__
