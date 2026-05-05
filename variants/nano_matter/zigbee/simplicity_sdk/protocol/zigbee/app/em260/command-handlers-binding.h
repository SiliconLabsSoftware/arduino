/***************************************************************************//**
 * @file
 * @brief Declarations for binding table related command handlers.
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

// Ezsp Command Handlers

sl_status_t sl_zigbee_af_ezsp_set_binding_command_cb(uint8_t index,
                                                     sl_zigbee_binding_table_entry_t *value);

sl_status_t sl_zigbee_af_ezsp_delete_binding_command_cb(uint8_t index);

void sl_zigbee_xncp_binding_policy_command_cb(sl_zigbee_af_plugin_ezsp_policy_command_context_t* context);
void sl_zigbee_xncp_binding_configuration_value_command_cb(sl_zigbee_af_plugin_ezsp_configuration_value_command_context_t* context);
void sl_zigbee_xncp_binding_policy_command_cb(sl_zigbee_af_plugin_ezsp_policy_command_context_t* context);
void sl_zigbee_xncp_binding_configuration_value_command_cb(sl_zigbee_af_plugin_ezsp_configuration_value_command_context_t* context);
void sl_zigbee_xncp_binding_policy_command_cb(sl_zigbee_af_plugin_ezsp_policy_command_context_t* context);
// -----------------------------------------------------------------------------
// Framework callbacks

void sl_zigbee_xncp_binding_permit_host_to_ncp_frame_cb(bool *permit);
