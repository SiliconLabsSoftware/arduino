/***************************************************************************//**
 * @file
 * @brief See @ref debug for documentation.
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

#ifndef SILABS_EMBER_DEBUG_H
#define SILABS_EMBER_DEBUG_H

/**
 * @addtogroup debug
 * @brief EmberZNet debugging utilities.
 *
 * See sl_zigbee_debug.h for source code.
 * @{
 */

// Define the values for DEBUG_LEVEL
#define NO_DEBUG    0
#define BASIC_DEBUG 1
#define FULL_DEBUG  2

/** @brief This function is obsolete and no longer required to
 *  initialize the debug system.
 *
 * @param port Ignored because the port used for debug communication
 *  is automatically determined for each platform.
 */
#define sl_zigbee_debug_init(port) do {} while (false)

#if (defined(DEBUG_LEVEL) && defined(BASIC_DEBUG) && (DEBUG_LEVEL >= BASIC_DEBUG)) || defined(DOXYGEN_SHOULD_SKIP_THIS) || !defined(SL_ZIGBEE_SCRIPTED_TEST)

#define DEBUG_ROUTINES_PRESENT

/** @brief Print the filename and line number to the debug serial port.
 *
 * @param filename    The name of the file where the assert occurred.
 *
 * @param linenumber  The line number in the file where the assert occurred.
 */
void sl_zigbee_debug_assert(const char * filename, int linenumber);

/** @brief Print the contents of RAM to the debug serial port.
 *
 * @param start  The start address of the block of RAM to dump.
 *
 * @param end    The end address of the block of RAM to dump (address of the
 *  last byte).
 */
void sl_zigbee_debug_memory_dump(uint8_t *start, uint8_t *end);

/** @brief Print binary data to the debug channel.
 *
 * This function does not use the normal printf format conventions. To print
 * text debug messages, use ::sl_zigbee_debug_printf(). The format string must
 * contain only these conversion specification characters:
 * - B - uint8_t value.
 * - W - uint16_t value, printed least significant byte first.
 * - D - uint32_t value, printed least significant byte first.
 * - F - pointer to null terminated string in Flash (const char *).
 * - xxxp - pointer to RAM, length is xxx (max 255).
 * - lp - pointer to RAM, length is uint8_t argument.
 * - xxxf - pointer to Flash (const char *), length is xxx (max 255).
 * - lf - pointer to Flash (const char *), length is uint8_t argument.
 * - b - sli_buffer_manager_buffer_t.
 *
 * Examples:
 * @code
 * sl_zigbee_debug_binary_printf("BWD", status, panId, channelMask);
 * sl_zigbee_debug_binary_printf("F8p", "string example", eui64);
 * sl_zigbee_debug_binary_printf("lp64fb", length, bytes, dataTable, buffer);
 * @endcode
 *
 * @param formatString  A string of conversion specification characters
 *                      describing the arguments to be printed.
 * @param ...           The arguments to be printed.
 */
void sl_zigbee_debug_binary_printf(const char * formatString, ...);

/** @brief Send VUART data out the debug channel.
 *
 * @param buff A pointer to the data to send.
 *
 * @param len The length of the data to send.
 */
void sli_util_debug_send_vuart_message(uint8_t *buff, uint8_t len);

//#if (DEBUG_LEVEL == FULL_DEBUG) || defined(DOXYGEN_SHOULD_SKIP_THIS)
/** @brief Print an ::sl_status_t return code to the serial port.
 *
 * @param code  The ::sl_status_t code to print.
 */
void sl_zigbee_debug_error(sl_status_t code);

/** @brief Turn off all debug output.
 *
 * @return The current state (true for on, false for off).
 */
bool sl_zigbee_debug_report_off(void);

/** @brief Restore the state of the debug output.
 *
 * @param state  The state returned from ::sl_zigbee_debug_report_off().
 * This is done so that debug output is not blindly turned on.
 */
void sl_zigbee_debug_report_restore(bool state);

// Format: Same as sli_legacy_serial_printf
// sl_zigbee_debug_printf("format string"[, parameters ...])
/** @brief Prints text debug messages.
 *
 * @param formatString  Takes the following:
 *
 * <table border=0>
 * <tr><td align="right">%%</td><td>Percent sign</td></tr>
 * <tr><td align="right">%%c</td><td>Single-byte char</td></tr>
 * <tr><td align="right">%%s</td><td>RAM string</td></tr>
 * <tr><td align="right">%%s</td><td>Flash string (does not follow the printf standard)</td></tr>
 * <tr><td align="right">%%u</td><td>Two-byte unsigned decimal</td></tr>
 * <tr><td align="right">%%d</td><td>Two-byte signed decimal</td></tr>
 * <tr><td align="right">%%02X, %%04X, %%08X </td><td>1-, 2-, 4-byte hex value (always 0 padded;
 *         does not follow the printf standard)</td></tr>
 * </table>
 */
void sl_zigbee_debug_printf(const char * formatString, ...);

#else // (DEBUG_LEVEL >= BASIC_DEBUG) || defined(DOXYGEN_SHOULD_SKIP_THIS) || !defined(SL_ZIGBEE_SCRIPTED_TEST)
  #define sl_zigbee_debug_assert(filename, linenumber) do {} while (false)
  #define sl_zigbee_debug_memory_dump(start, end) do {} while (false)
  #define sl_zigbee_debug_binary_printf(formatstring, ...) do {} while (false)
  #define sli_util_debug_send_vuart_message(buff, len) do {} while (false)
  #define sl_zigbee_debug_error(code) do {} while (false)
// Note the following doesn't have a do{}while(false)
//   because it has a return value
  #define sl_zigbee_debug_report_off() (false)
  #define sl_zigbee_debug_report_restore(state) do {} while (false)
  #define sl_zigbee_debug_printf(...) do {} while (false)
#endif // (defined(DEBUG_LEVEL) && defined(BASIC_DEBUG) && (DEBUG_LEVEL >= BASIC_DEBUG)) || defined(DOXYGEN_SHOULD_SKIP_THIS) || !defined(SL_ZIGBEE_SCRIPTED_TEST)

/** @} END addtogroup */

#endif // SILABS_EMBER_DEBUG_H
