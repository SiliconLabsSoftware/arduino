/***************************************************************************//**
 * @file
 * @brief ZLL specific EZSP command handler declarations.
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

//------------------------------------------------------------------------------
// Ezsp Command Handlers

sl_status_t sl_zigbee_af_ezsp_zll_network_ops_command_cb(sl_zigbee_zll_network_t* networkInfo,
                                                         sl_zigbee_ezsp_zll_network_operation_t op,
                                                         int8_t radioTxPower);

void sl_zigbee_xncp_zll_policy_command_cb(sl_zigbee_af_plugin_ezsp_policy_command_context_t* context);
void sl_zigbee_xncp_zll_configuration_value_command_cb(sl_zigbee_af_plugin_ezsp_configuration_value_command_context_t* context);

// #ezsp command-handler genearted does  not pick up these exceptions
#define sli_zigbee_stack_zll_get_tokens sli_zigbee_stack_zll_get_tokens_stack_zll
#define sli_zigbee_stack_zll_set_data_token sli_zigbee_stack_zll_set_token_stack_zll_data
