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

#ifndef SILABS_AF_MAIN_H
#define SILABS_AF_MAIN_H

#include CONFIGURATION_HEADER
#include PLATFORM_HEADER     // Micro and compiler specific typedefs and macros
#include "stack/include/sl_zigbee_types.h"

#define MFG_STRING_MAX_LENGTH 16

typedef struct {
  sl_zigbee_af_message_sent_function_t callback;
  uint16_t tag;
} sli_zigbee_callback_table_entry_t;

#if defined(EZSP_HOST)
bool sl_zigbee_af_memory_byte_compare(const uint8_t* pointer, uint8_t count, uint8_t byteValue);
#else
bool sli_zigbee_af_memory_byte_compare(const uint8_t *bytes, uint8_t count, uint8_t target);

#define sl_zigbee_af_memory_byte_compare(pointer, count, byteValue) \
  sli_zigbee_af_memory_byte_compare((pointer), (count), (byteValue))
#endif

// returnData must be MFG_STRING_MAX_LENGTH in length and
// is NOT expected to be NULL terminated (could be though)
void sl_zigbee_af_get_mfg_string(uint8_t* returnData);

// Functions common to both SOC and Host versions of the application.
void sli_zigbee_af_initialize_message_sent_callback_array(void);
uint8_t sli_zigbee_get_permit_joining_remaining_duration_sec(void);

sl_zigbee_af_cbke_key_establishment_suite_t sl_zigbee_af_is_full_smart_energy_security_present(void);

#if defined(EZSP_HOST)
void sli_zigbee_af_clear_network_cache(uint8_t networkIndex);
#else
  #define sli_zigbee_af_clear_network_cache(index)
uint8_t sli_zigbee_af_copy_message_into_ram_buffer(sli_buffer_manager_buffer_t message,
                                                   uint8_t *buffer,
                                                   uint16_t bufLen);
#endif

#if defined EZSP_HOST
// utility for setting an EZSP config value and printing the result
sl_status_t sl_zigbee_af_set_ezsp_config_value(sl_zigbee_ezsp_config_id_t configId,
                                               uint16_t value,
                                               const char * configIdName);

// utility for setting an EZSP policy and printing the result
sl_status_t sl_zigbee_af_set_ezsp_policy(sl_zigbee_ezsp_policy_id_t policyId,
                                         sl_zigbee_ezsp_decision_id_t decisionId,
                                         const char * policyName,
                                         const char * decisionName);

// utility for setting an EZSP value and printing the result
sl_status_t sl_zigbee_af_set_ezsp_value(sl_zigbee_ezsp_value_id_t valueId,
                                        uint8_t valueLength,
                                        uint8_t *value,
                                        const char * valueName);

bool sl_zigbee_af_ncp_needs_reset(void);

#endif // EZSP_HOST

void sli_zigbee_af_print_status(const char * task,
                                sl_status_t status);

uint8_t sl_zigbee_af_get_security_level(void);
uint8_t sl_zigbee_af_get_key_table_size(void);
uint8_t sl_zigbee_af_get_binding_table_size(void);
uint8_t sl_zigbee_af_get_address_table_size(void);
uint8_t sl_zigbee_af_get_child_table_size(void);
uint8_t sl_zigbee_af_get_route_table_size(void);
uint8_t sl_zigbee_af_get_neighbor_table_size(void);
uint8_t sl_zigbee_af_get_stack_profile(void);
uint8_t sl_zigbee_af_get_sleepy_multicast_config(void);

uint16_t sli_zigbee_af_get_packet_buffer_free_space(void);
uint16_t sli_zigbee_af_get_packet_buffer_total_space(void);
uint8_t sl_zigbee_af_get_open_network_duration_sec(void);

sl_status_t sl_zigbee_af_get_source_route_table_entry(
  uint8_t index,
  sl_802154_short_addr_t *destination,
  uint8_t *closerIndex);

uint8_t sl_zigbee_af_get_source_route_table_total_size(void);
uint8_t sl_zigbee_af_get_source_route_table_filled_size(void);

sl_status_t sl_zigbee_af_get_child_data(uint8_t index,
                                        sl_zigbee_child_data_t* childData);

void sli_zigbee_af_cli_version_command(void);

sl_status_t sli_zigbee_af_permit_join(uint8_t duration,
                                      bool broadcastMgmtPermitJoin);
void sli_zigbee_af_stop_smart_energy_startup(void);

bool sli_zigbee_af_process_zdo(sl_802154_short_addr_t sender,
                               sl_zigbee_aps_frame_t* apsFrame,
                               uint8_t* message,
                               uint16_t length);

void sli_zigbee_af_incoming_message_handler(sl_zigbee_incoming_message_type_t type,
                                            sl_zigbee_aps_frame_t *apsFrame,
                                            sl_zigbee_rx_packet_info_t *packetInfo,
                                            uint16_t messageLength,
                                            uint8_t *message);
sl_status_t sli_zigbee_af_send(sl_zigbee_outgoing_message_type_t type,
                               uint16_t indexOrDestination,
                               sl_zigbee_aps_frame_t *apsFrame,
                               uint8_t messageLength,
                               uint8_t *message,
                               uint16_t *messageTag,
                               sl_802154_short_addr_t alias,
                               uint8_t sequence);
void sli_zigbee_af_message_sent_handler(sl_status_t status,
                                        sl_zigbee_outgoing_message_type_t type,
                                        uint16_t indexOrDestination,
                                        sl_zigbee_aps_frame_t *apsFrame,
                                        uint16_t messageTag,
                                        uint16_t messageLength,
                                        uint8_t *messageContents);

void sli_zigbee_af_stack_status_handler(sl_status_t status);

void sli_zigbee_af_network_security_init(void);
void sli_zigbee_af_network_init(uint8_t init_level);

void sli_zigbee_af_schedule_find_and_rejoin_event(void);

extern const sl_802154_long_addr_t sl_zigbee_af_null_eui64;

void sl_zigbee_af_format_mfg_string(uint8_t* mfgString);

extern bool sl_zigbee_af_print_received_messages;

void sli_zigbee_af_parse_and_print_version(sl_zigbee_version_t versionStruct);
void sli_zigbee_af_print_ezsp_endpoint_flags(uint8_t endpoint);

uint16_t sli_zigbee_af_calculate_message_tag_hash(uint8_t *messageContents,
                                                  uint8_t messageLength);
bool sli_zigbee_af_get_endpoint_description(uint8_t endpoint,
                                            sl_zigbee_endpoint_description_t *result);
uint16_t sli_zigbee_af_get_endpoint_cluster(uint8_t endpoint,
                                            sl_zigbee_cluster_list_id_t listId,
                                            uint8_t listIndex);
uint8_t sli_zigbee_af_get_endpoint(uint8_t index);

// Old names
#define sl_zigbee_af_move_in_progress() sl_zigbee_af_move_in_progress_cb()
#define sl_zigbee_af_start_move()      sl_zigbee_af_start_move_cb()
#define sl_zigbee_af_stop_move()       sl_zigbee_af_stop_move_cb()

#endif // SILABS_AF_MAIN_H
