/***************************************************************************//**
 * @file
 * @brief declarations for common app code.
 *
 * The common library is deprecated and will be removed in a future release.
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

#ifndef SILABS_APP_UTIL_COMMON_H
#define SILABS_APP_UTIL_COMMON_H

#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif
#include "app/framework/common/sl_zigbee_system_common.h"
#ifdef SL_CATALOG_CLI_PRESENT
#include "sl_cli.h"
#define SL_CLI_COMMAND_ARG sl_cli_command_arg_t * arguments
#else // !SL_CATALOG_CLI_PRESENT
#define SL_CLI_COMMAND_ARG void
#endif // SL_CATALOG_CLI_PRESENT

#if defined(SL_CATALOG_ZIGBEE_DEBUG_PRINT_PRESENT) && !defined(SL_ZIGBEE_SCRIPTED_TEST)
#include "sl_zigbee_debug_print.h"
#endif // SL_CATALOG_ZIGBEE_DEBUG_PRINT_PRESENT

extern uint8_t serialPort;
extern SerialBaudRate serialBaudRate;

// For identifying ourselves over the serial port.
extern const char * applicationString;

// Boilerplate
void configureSerial(uint8_t port, SerialBaudRate rate);

#if !defined EZSP_HOST
extern sli_zigbee_event_t blinkEvent;
#endif

void initialize(void);
void run(sl_zigbee_event_data_t* events,
         void (* heartbeat)(void));

// Utilities
void printLittleEndianEui64(uint8_t port, sl_802154_long_addr_t eui64);
void printBigEndianEui64(uint8_t port, sl_802154_long_addr_t eui64);
#define printEui64(port, eui64) printBigEndianEui64((port), (eui64))
void printHexByteArray(uint8_t port, uint8_t *byteArray, uint8_t length);
#define printEncryptionKey(port, keyData) \
  printHexByteArray(port, keyData, SL_ZIGBEE_ENCRYPTION_KEY_SIZE)

uint8_t asciiHexToByteArray(uint8_t *bytesOut, uint8_t* asciiIn, uint8_t asciiCharLength);

void hexToEui64(uint8_t *contents, uint8_t length, sl_802154_long_addr_t returnEui64);
void hexToKeyData(uint8_t *contents, uint8_t length, sl_zigbee_key_data_t* returnKeyData);
uint8_t hexDigitValue(uint8_t digit);

// Host / Non-host specific implementations
bool setSecurityLevel(uint8_t level);
bool generateRandomBytes(uint8_t* result, uint8_t length);
bool getNetworkParameters(sl_zigbee_node_type_t* nodeType,
                          sl_zigbee_network_parameters_t* networkParams);
void initialize_sl_zigbee_stack_t(void);
sl_status_t getOnlineNodeParameters(uint8_t* childCountReturn,
                                    uint8_t* routerCountReturn,
                                    sl_zigbee_node_type_t* nodeTypeReturn,
                                    sl_802154_short_addr_t* parentNodeIdReturn,
                                    sl_802154_long_addr_t parentEuiReturn,
                                    sl_zigbee_network_parameters_t* networkParamReturn);
sl_status_t getOfflineNodeParameters(sl_802154_short_addr_t *myNodeIdReturn,
                                     sl_zigbee_node_type_t *myNodeTypeReturn,
                                     uint8_t* stackProfileReturn);
void runEvents(sli_zigbee_event_queue_t* event_queue);

#define generateRandomKey(result) \
  (SL_STATUS_OK == sl_zigbee_generate_random_key(result))

void createMulticastBinding(uint8_t index, uint8_t *multicastGroup, uint8_t endpoint);
bool findEui64Binding(sl_802154_long_addr_t key, uint8_t *index);
void printCommandStatus(sl_status_t status, const char * good, const char * bad);
void printCommandStatusWithPrefix(sl_status_t status,
                                  const char * prefix,
                                  const char * good,
                                  const char * bad);
void printOperationStatus(sl_status_t status, const char * operation);
void setCommissionParameters(SL_CLI_COMMAND_ARG);
sl_status_t joinNetwork(void);

// Common commands
void helpCommand(SL_CLI_COMMAND_ARG);
void statusCommand(SL_CLI_COMMAND_ARG);
void stateCommand(SL_CLI_COMMAND_ARG);
void rebootCommand(SL_CLI_COMMAND_ARG);
void radioCommand(SL_CLI_COMMAND_ARG);
void formNetworkCommand(SL_CLI_COMMAND_ARG);
void multiPhyStartCommand(SL_CLI_COMMAND_ARG);
void multiPhyStopCommand(SL_CLI_COMMAND_ARG);
void setExtPanIdCommand(SL_CLI_COMMAND_ARG);
void setJoinMethod(SL_CLI_COMMAND_ARG);
void joinNetworkCommand(SL_CLI_COMMAND_ARG);
void rejoinCommand(SL_CLI_COMMAND_ARG);
void networkInitCommand(SL_CLI_COMMAND_ARG);
void leaveNetworkCommand(SL_CLI_COMMAND_ARG);
void leaveWithOptionsNetworkCommand(SL_CLI_COMMAND_ARG);
void addressRequestCommand(SL_CLI_COMMAND_ARG);
void permitJoiningCommand(SL_CLI_COMMAND_ARG);
void setSecurityCommand(SL_CLI_COMMAND_ARG);
void setNetworkCommand(SL_CLI_COMMAND_ARG);
void getCurrentNwkIndexCommand(SL_CLI_COMMAND_ARG);
void getRadioParameters(SL_CLI_COMMAND_ARG);

void printCarriageReturn(void);
void printErrorMessage(const char * message);
void printErrorMessage2(const char * message, const char * message2);

#define MULTI_PHY_COMMON_COMMANDS                                              \
  sl_zigbee_command_entry_action("multi_start", multiPhyStartCommand, "uusu*", \
                                 "Start second phy"),                          \
  sl_zigbee_command_entry_action("multi_stop", multiPhyStopCommand, "u*",      \
                                 "Stop multi phy interface"),

#define COMMON_COMMANDS                                                                     \
  sl_zigbee_command_entry_action("status", statusCommand, "",                               \
                                 "Print the node's current status"),                        \
  sl_zigbee_command_entry_action("state", stateCommand, "",                                 \
                                 "Print the node's current state"),                         \
  sl_zigbee_command_entry_action("reboot", rebootCommand, "",                               \
                                 "Reboot the node"),                                        \
                                                                                            \
  /* Parameters: security bitmask, preconfigured key, network key, */                       \
  /*   network key sequence */                                                              \
  /* If security bitmask is 0x8000 then security is turned off, */                          \
  /*   nothing else is set. */                                                              \
  /* If security bitmask is 0xFFFF then security is turned on  */                           \
  /*   without setting any other security settings. */                                      \
  /* If security bitmask is anything else, security is turned on, */                        \
  /*   the bitmask is set and so are the other values. */                                   \
  /*   (as appropriate for the bitmask) */                                                  \
  /*   The higher 16-bits of the bitmask are written into the */                            \
  /*  extended security bitmask, while the lower 16-bits are written */                     \
  /*  into the security bitmask. */                                                         \
  sl_zigbee_command_entry_action("set_security", setSecurityCommand, "wbbu",                \
                                 "Set the security parameters"),                            \
                                                                                            \
  /* channel, pan id, tx power */                                                           \
  sl_zigbee_command_entry_action("form", formNetworkCommand, "uvs",                         \
                                 "Form a network"),                                         \
  /* channel, pan id, tx power, extended pan id */                                          \
  sl_zigbee_command_entry_action("form_ext", formNetworkCommand, "uvsb",                    \
                                 "Form a network with extended settings"),                  \
                                                                                            \
  /* extended pan id */                                                                     \
  sl_zigbee_command_entry_action("set_ext_pan", setExtPanIdCommand, "b",                    \
                                 "Set extended PAN ID for forming/joining"),                \
                                                                                            \
  /* Set the join method: MAC Associate (0), */                                             \
  /*   NWK Rejoin w/out security (1), */                                                    \
  /*   NWK Rejoin with Security (2) */                                                      \
  /*   NWK commission, i.e. join quietly (3) */                                             \
  sl_zigbee_command_entry_action("join_method", setJoinMethod, "u",                         \
                                 "Set the method used for joining"),                        \
                                                                                            \
  /* Set the Commissioning parameters: */                                                   \
  /*   coordinator bool (1 byte) */                                                         \
  /*   nwkManagerId (2 bytes) */                                                            \
  /*   nwkUpdateId  (1 byte) */                                                             \
  /*   channels  (lower 16-bits of 32-bit value) */                                         \
  /*   channels  (upper 16-bits of 32-bit value) */                                         \
  /*   trust center eui64 */                                                                \
  sl_zigbee_command_entry_action("commission", setCommissionParameters, "uvuvvb",           \
                                 "Set the commission parameters"),                          \
                                                                                            \
  /* channel, pan id, tx power */                                                           \
  sl_zigbee_command_entry_action("join", joinNetworkCommand, "uvs",                         \
                                 "Join a network as router"),                               \
  sl_zigbee_command_entry_action("join_end", joinNetworkCommand, "uvs",                     \
                                 "Join a network as RxOnWhenIdle end  device"),             \
  sl_zigbee_command_entry_action("join_sleepy", joinNetworkCommand, "uvs",                  \
                                 "Join a network as a sleepy end device"),                  \
                                                                                            \
  sl_zigbee_command_entry_action("nwk_init", networkInitCommand, "v",                       \
                                 "Execute sl_zigbee_network_init()"),                       \
                                                                                            \
  sl_zigbee_command_entry_action("leave", leaveNetworkCommand, "",                          \
                                 "Tell local node to Leave the network"),                   \
                                                                                            \
  sl_zigbee_command_entry_action("leave_with_options", leaveWithOptionsNetworkCommand, "u", \
                                 "Tell local node to Leave the network with options"),      \
                                                                                            \
  /* params: */                                                                             \
  /*   - have current network key? (secure vs. insecure) */                                 \
  /*   - channel mask (0 = search current channel only) */                                  \
  sl_zigbee_command_entry_action("rejoin", rejoinCommand, "uw",                             \
                                 "Execute a rejoin operation"),                             \
                                                                                            \
  /* target network id, include kids */                                                     \
  sl_zigbee_command_entry_action("ieee_address", addressRequestCommand, "vu",               \
                                 "Send a ZDO IEEE address request"),                        \
                                                                                            \
  /* target EUI64, include kids */                                                          \
  sl_zigbee_command_entry_action("nwk_address", addressRequestCommand, "bu",                \
                                 "Send a ZDO NWK address request"),                         \
                                                                                            \
  /* duration in seconds, 0 to prohibit, 0xff to allow */                                   \
  sl_zigbee_command_entry_action("permit_joins", permitJoiningCommand, "u",                 \
                                 "Change the MAC permit join flag"),                        \
                                                                                            \
  /* help commands */                                                                       \
  sl_zigbee_command_entry_action("help", helpCommand, "",                                   \
                                 "Print the list of commands"),                             \
                                                                                            \
  /* Parameter 1 -  Network index */                                                        \
  sl_zigbee_command_entry_action("set_network", setNetworkCommand, "u",                     \
                                 "Set the network index"),                                  \
                                                                                            \
  /* no params */                                                                           \
  sl_zigbee_command_entry_action("get_curr_nwk_index", getCurrentNwkIndexCommand, "",       \
                                 "Get the current network index"),                          \
                                                                                            \
  /* Optional parameter 1 -  Phy index */                                                   \
  sl_zigbee_command_entry_action("radio_params", getRadioParameters, "u*",                  \
                                 "Print the radio parameters"),

#endif // SILABS_APP_UTIL_COMMON_H
