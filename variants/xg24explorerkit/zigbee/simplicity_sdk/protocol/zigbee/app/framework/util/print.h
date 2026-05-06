/***************************************************************************//**
 * @file
 * @brief Macros for functional area and per-cluster debug printing
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

#ifndef __AF_DEBUG_PRINT__
#define __AF_DEBUG_PRINT__

#include "zcl-debug-print.h"

#if !defined(SL_ZIGBEE_AF_PRINT_OUTPUT) && defined(APP_SERIAL)
  #define SL_ZIGBEE_AF_PRINT_OUTPUT APP_SERIAL
#endif

extern uint16_t sl_zigbee_af_print_active_area;

// These print functions are required by the CBKE crypto engine.
#define sl_zigbee_af_print_zigbee_key printZigbeeKey
#define sl_zigbee_af_print_cert      printCert
#define sl_zigbee_af_print_key       printKey
#define sl_zigbee_af_print_ieee_line  printIeeeLine
#define sl_zigbee_af_print_text_line  printTextLine

#define sl_zigbee_af_print_public_key(key)  printKey(true, key)
#define sl_zigbee_af_print_private_key(key) printKey(false, key)

/** @name Printing */
// @{

// Guaranteed print
/**
 * @brief Print that can't be turned off.
 *
 */
#define sl_zigbee_af_guaranteed_print(...)   sl_zigbee_af_print(0xFFFF, __VA_ARGS__)

/**
 * @brief Println that can't be turned off.
 */
#define sl_zigbee_af_guaranteed_println(...) sl_zigbee_af_println(0xFFFF, __VA_ARGS__)

/**
 * @brief Buffer print that can't be turned off.
 */
#define sl_zigbee_af_guaranteed_print_buffer(buffer, len, withSpace) sl_zigbee_af_print_buffer(0xFFFF, (buffer), (len), (withSpace))

/**
 * @brief String print that can't be turned off.
 */
#define sl_zigbee_af_guaranteed_print_string(buffer) sl_zigbee_af_print_string(0xFFFF, (buffer))

/**
 * @brief Long string print that can't be turned off.
 */
#define sl_zigbee_af_guaranteed_print_long_string(buffer) sl_zigbee_af_print_long_string(0xFFFF, (buffer))

/**
 * @brief returns true if certain debug area is enabled.
 */
bool sl_zigbee_af_print_enabled(uint16_t functionality);

/**
 * @brief Useful function to print a buffer
 */
void sl_zigbee_af_print_buffer(uint16_t area, const uint8_t *buffer, uint16_t bufferLen, bool withSpaces);

/**
 * @brief Useful function to print character strings.  The first byte of the
 * buffer specifies the length of the string.
 */
void sl_zigbee_af_print_string(uint16_t area, const uint8_t *buffer);

/**
 * @brief Useful function to print long character strings.  The first two bytes
 * of the buffer specify the length of the string.
 */
void sl_zigbee_af_print_long_string(uint16_t area, const uint8_t *buffer);

/**
 * @brief prints the specified text if certain debug are is enabled
 * @param functionality: one of the EMBER_AF_PRINT_xxx macros as defined by AppBuilder
 * @param formatString: formatString for varargs
 */
void sl_zigbee_af_print(uint16_t functionality, const char * formatString, ...);

/**
 * @brief prints the specified text if certain debug are is enabled.
 * Print-out will include the newline character at the end.
 * @param functionality: one of the EMBER_AF_PRINT_xxx macros as defined by AppBuilder
 * @param formatString: formatString for varargs
 */
void sl_zigbee_af_println(uint16_t functionality, const char * formatString, ...);

/**
 * @brief turns on debugging for certain functional area
 */
void sl_zigbee_af_print_on(uint16_t functionality);

/**
 * @brief turns off debugging for certain functional area
 */
void sl_zigbee_af_print_off(uint16_t functionality);

#if !defined(SL_ZIGBEE_AF_GENERATE_CLI)
/** @brief turns on debugging for all functional areas
 */
void sl_zigbee_af_print_all_on(void);

/**
 * @brief turns off debugging for all functional areas
 */
void sl_zigbee_af_print_all_off(void);

/**
 * @brief prints current status of functional areas
 */
void sl_zigbee_af_print_status(void);
#endif

/**
 * @brief prints eui64 stored in little endian format
 */
void sl_zigbee_af_print_little_endian_eui64(const sl_802154_long_addr_t eui64);

/**
 * @brief prints eui64 stored in big endian format
 */
void sl_zigbee_af_print_big_endian_eui64(const sl_802154_long_addr_t eui64);

/**
 * @brief prints all message data in message format
 */
void sl_zigbee_af_print_message_data(uint8_t* data, uint16_t length);

/** @} END Printing */

void sl_zigbee_af_print_zigbee_key(const uint8_t *key);
void sl_zigbee_af_print_cert(const uint8_t *cert);
void sl_zigbee_af_print_cert_283k1(const uint8_t *cert);
void sl_zigbee_af_print_key(bool publicKey, const uint8_t *key);
void sl_zigbee_af_print_key_283k1(bool publickKey, const uint8_t *key);
void sl_zigbee_af_print_ieee_line(const sl_802154_long_addr_t ieee);
void sl_zigbee_af_print_text_line(const char * text);

void sl_zigbee_af_print8_byte_blocks(uint8_t numBlocks,
                                     const uint8_t *block,
                                     bool crBetweenBlocks);
void sl_zigbee_af_print_issuer(const uint8_t *issuer);

void sl_zigbee_af_print_channel_list_from_mask(uint32_t channelMask);

#endif // __AF_DEBUG_PRINT__
