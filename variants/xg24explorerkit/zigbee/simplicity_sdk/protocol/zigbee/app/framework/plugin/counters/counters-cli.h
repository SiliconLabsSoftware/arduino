/***************************************************************************//**
 * @file
 * @brief CLI APIs for the Counters plugin.
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

#ifndef SILABS_PLUGIN_COUNTERS_CLI_H
#define SILABS_PLUGIN_COUNTERS_CLI_H
void sl_zigbee_af_counters_print_command(sl_cli_command_arg_t *args);
void sl_zigbee_af_counters_simple_print_command(sl_cli_command_arg_t *args);
void sl_zigbee_af_counters_print_thresholds_command(sl_cli_command_arg_t *args);
void sl_zigbee_af_counters_set_threshold_command(sl_cli_command_arg_t *args);
void sl_zigbee_af_counters_send_request_command(sl_cli_command_arg_t *args);
void sl_zigbee_af_counters_clear_command(sl_cli_command_arg_t *args);
void sl_zigbee_af_counters_reset_thresholds_command(sl_cli_command_arg_t *args);

/** Args: destination id, clearCounters (bool) */
void sendCountersRequestCommand(void);

/** Utility function for printing out the OTA counters response. */
void printCountersResponse(uint8_t messageLength, uint8_t *message);

#endif // SILABS_PLUGIN_COUNTERS_CLI_H
