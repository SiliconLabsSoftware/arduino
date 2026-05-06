/***************************************************************************//**
 * @file
 * @brief Definitions for the Scenes plugin.
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
 * @defgroup scenes-server  Scenes Server
 * @ingroup component cluster
 * @brief API and Callbacks for the Scenes Cluster Server Component
 *
 * Silicon Labs implementation of the Scenes server cluster.
 * This component supports commands for setting up and recalling scenes.
 * Scenes are stored in a table and each scene consists of a set of
 * values for attributes in other clusters. Clusters that extend the
 * scene table do so through extension field sets. This component supports
 * extensions for the On/Off, Level Control, Thermostat, Color Control,
 * Door Lock, and Window Covering clusters. If the application includes
 * any of these clusters, the component automatically includes and manages
 * the attributes in those clusters. For example, if the application
 * includes the On/Off server cluster, the component saves and recalls
 * the On/Off attribute as part of saving or recalling scenes.
 * Some ZLL extensions are implemented in this component and will be
 * included automatically for ZLL applications. If the ZLL Scenes
 * server cluster component is also enabled, this component uses it for
 * handling some additional ZLL enhancements. Otherwise, these ZLL
 * extensions are disabled. This component requires extending in order
 * to interact with the actual hardware.
 *
 */

/**
 * @addtogroup scenes-server
 * @{
 */

#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif
#include "scenes-config.h"
#if (SL_ZIGBEE_AF_PLUGIN_SCENES_NAME_SUPPORT == 1)
#define NAME_SUPPORT
#endif

sl_zigbee_af_status_t sl_zigbee_af_scenes_set_scene_count_attribute(uint8_t endpoint,
                                                                    uint8_t newCount);
sl_zigbee_af_status_t sl_zigbee_af_scenes_make_valid(uint8_t endpoint,
                                                     uint8_t sceneId,
                                                     uint16_t groupId);

// DEPRECATED.
#define sl_zigbee_af_scenes_make_invalid sl_zigbee_af_scenes_cluster_make_invalid_cb

extern uint8_t sl_zigbee_af_scenes_server_entries_in_use;
#if (SL_ZIGBEE_AF_PLUGIN_SCENES_USE_TOKENS == 1) && !defined(EZSP_HOST)
// In this case, we use token storage
  #define sl_zigbee_af_scenes_server_retrieve_scene_entry(entry, i) \
  halCommonGetIndexedToken(&(entry), TOKEN_SCENES_TABLE, (i))
  #define sl_zigbee_af_scenes_server_save_scene_entry(entry, i) \
  halCommonSetIndexedToken(TOKEN_SCENES_TABLE, (i), &(entry))
  #define sl_zigbee_af_scenes_server_num_scene_entries_in_use()                             \
  (halCommonGetToken(&sl_zigbee_af_scenes_server_entries_in_use, TOKEN_SCENES_NUM_ENTRIES), \
   sl_zigbee_af_scenes_server_entries_in_use)
  #define sl_zigbee_af_scenes_server_set_num_scene_entries_in_use(x) \
  (sl_zigbee_af_scenes_server_entries_in_use = (x),                  \
   halCommonSetToken(TOKEN_SCENES_NUM_ENTRIES, &sl_zigbee_af_scenes_server_entries_in_use))
  #define sl_zigbee_af_scenes_server_incr_num_scene_entries_in_use()                         \
  ((halCommonGetToken(&sl_zigbee_af_scenes_server_entries_in_use, TOKEN_SCENES_NUM_ENTRIES), \
    ++sl_zigbee_af_scenes_server_entries_in_use),                                            \
   halCommonSetToken(TOKEN_SCENES_NUM_ENTRIES, &sl_zigbee_af_scenes_server_entries_in_use))
  #define sl_zigbee_af_scenes_server_decr_num_scene_entries_in_use()                         \
  ((halCommonGetToken(&sl_zigbee_af_scenes_server_entries_in_use, TOKEN_SCENES_NUM_ENTRIES), \
    --sl_zigbee_af_scenes_server_entries_in_use),                                            \
   halCommonSetToken(TOKEN_SCENES_NUM_ENTRIES, &sl_zigbee_af_scenes_server_entries_in_use))
#else
// Use normal RAM storage
extern sl_zigbee_af_scene_table_entry_t sl_zigbee_af_scenes_server_scene_table[];
  #define sl_zigbee_af_scenes_server_retrieve_scene_entry(entry, i) \
  ((entry) = sl_zigbee_af_scenes_server_scene_table[(i)])
  #define sl_zigbee_af_scenes_server_save_scene_entry(entry, i) \
  (sl_zigbee_af_scenes_server_scene_table[(i)] = (entry))
  #define sl_zigbee_af_scenes_server_num_scene_entries_in_use() \
  (sl_zigbee_af_scenes_server_entries_in_use)
  #define sl_zigbee_af_scenes_server_set_num_scene_entries_in_use(x) \
  (sl_zigbee_af_scenes_server_entries_in_use = (x))
  #define sl_zigbee_af_scenes_server_incr_num_scene_entries_in_use() \
  (++sl_zigbee_af_scenes_server_entries_in_use)
  #define sl_zigbee_af_scenes_server_decr_num_scene_entries_in_use() \
  (--sl_zigbee_af_scenes_server_entries_in_use)
#endif // (SL_ZIGBEE_AF_PLUGIN_SCENES_USE_TOKENS == 1) && !defined(EZSP_HOST)

sl_zigbee_af_zcl_request_status_t sl_zigbee_af_scenes_server_parse_add_scene(const sl_zigbee_af_cluster_command_t *cmd,
                                                                             uint16_t groupId,
                                                                             uint8_t sceneId,
                                                                             uint16_t transitionTime,
                                                                             uint8_t *sceneName,
                                                                             uint8_t *extensionFieldSets);
sl_zigbee_af_zcl_request_status_t sl_zigbee_af_scenes_server_parse_view_scene(const sl_zigbee_af_cluster_command_t *cmd,
                                                                              uint16_t groupId,
                                                                              uint8_t sceneId);

/** @brief Scenes Server Custom Recall Scene
 *
 * Customize the implementation of the Scenes cluster RecallScene command
 * for desired behavior when gradually transitioning to the specified scene
 * over the specified transition time interval.
 *
 * Upon entry to this callback, the presented scene table entry has been verified
 * to be valid for the endpoint, group ID, and scene ID referenced in the received
 * ZCL Scenes cluster RecallScene command.
 *
 * NOTE: If this callback is implemented, the expectation is that it will INITIATE
 * the scene transition behavior and return promptly with prospective success or
 * failure status, rather than execute through the full duration of the transition
 * time before returning.
 *
 * NOTE: The scene table entry pointer, and the information in the scene
 * table entry, are available only during the execution of this callback
 * function. The scene table entry information (NOT the pointer) must be copied
 * and saved before returning from this callback function if it will need to be
 * referenced at other times to perform the desired transition behavior
 * (for example, by a timer-based periodic handler launched by this callback).
 *
 * If the value of transitionTimeDs is 0xFFFF, the transition time information
 * configured in the scene table entry should be used.
 *
 * Upon arriving at the target scene configuration, the custom implementation
 * should set the Scenes cluster attributes CurrentScene and CurrentGroup to
 * the scene ID and group ID values contained in the sceneEntry, and set the
 * SceneValid attribute to true.
 *
 * Returns true if a customization of this callback HAS been IMPLEMENTED.
 * This REQUIRES that a valid ::sl_zigbee_af_status_t value has been written to the status
 * argument. Status will be ::SL_ZIGBEE_ZCL_STATUS_SUCCESS if the scene transition has
 * been initiated successfully, even though the transition time has not fully elapsed
 * and the full effect of the scene transition over the transition time has not
 * yet completed. Otherwise, a suitable error status value should be returned
 * in the status argument.
 *
 * Returns false if a customization of this callback HAS NOT been implemented.
 * In this case, the Scenes plugin will perform default handling (apply target
 * scene settings immediately without regard for the specified transition time).
 *
 * @param sceneEntry pointer to ::sl_zigbee_af_scene_table_entry_t for recalled scene Ver.: always
 * @param transitionTimeDs transition time in deci-seconds (1/10 sec) Ver.: always
 * @param status pointer to return ::sl_zigbee_af_status_t Ver.: always
 *
 * @return true if custom callback is implemented
 *         false if custom callback is not implemented (apply default handling)
 */
bool sl_zigbee_af_scenes_server_custom_recall_scene_cb(
  const sl_zigbee_af_scene_table_entry_t * const sceneEntry,
  uint16_t transitionTimeDs,
  sl_zigbee_af_status_t * const status);

/** @} */ // end of name API
/** @} */ // end of scenes-server

void sli_zigbee_af_scenes_server_print_info(void);
