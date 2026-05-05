/***************************************************************************//**
 * @brief Zigbee System common code.
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SL_ZIGBEE_SYSTEM_COMMON_H
#define SL_ZIGBEE_SYSTEM_COMMON_H
#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif
#include "zigbee_app_framework_event.h"

#define SL_ZIGBEE_INIT_LEVEL_EVENT      0x00
#define SL_ZIGBEE_INIT_LEVEL_LOCAL_DATA 0x01
#define SL_ZIGBEE_INIT_LEVEL_DONE       0x02

#if defined(SL_CATALOG_POWER_MANAGER_PRESENT)
#include "sl_power_manager.h"
#ifdef SL_CATALOG_ZIGBEE_SYSTEM_COMMON_APP_FRAMEWORK_PRESENT
sl_power_manager_on_isr_exit_t sli_zigbee_af_sleep_on_isr_exit(void);
#endif //SL_CATALOG_ZIGBEE_SYSTEM_COMMON_APP_FRAMEWORK_PRESENT
sl_power_manager_on_isr_exit_t sli_zigbee_stack_sleep_on_isr_exit(void);

#endif //#if defined(SL_CATALOG_POWER_MANAGER_PRESENT)

void sli_zigbee_stack_init_callback(void);
void sli_zigbee_app_framework_init_callback(void);
void sli_zigbee_ncp_init_callback(void);

void sli_zigbee_stack_tick_callback(void);
void sli_zigbee_app_framework_tick_callback(void);
void sli_zigbee_ncp_tick_callback(void);

void sli_zigbee_app_framework_sleep_init(void);
bool sli_zigbee_app_framework_is_ok_to_sleep(void);

void sli_zigbee_stack_sleep_init(void);
bool sli_zigbee_stack_is_ok_to_sleep(void);

extern void sli_zigbee_stack_rtos_task_init_cb(void);
extern void sli_zigbee_app_framework_rtos_task_init_cb(void);

uint32_t sli_zigbee_app_framework_set_pm_requirements_and_get_ms_to_next_wakeup(void);
uint32_t sli_zigbee_stack_get_ms_to_next_wakeup(void);

#ifdef SL_CATALOG_ZIGBEE_FORCE_SLEEP_AND_WAKEUP_PRESENT
bool sli_zigbee_stack_is_force_sleep(void);
bool sli_zigbee_app_framework_is_force_sleep(void);
#endif // SL_CATALOG_ZIGBEE_FORCE_SLEEP_AND_WAKEUP_PRESENT

#ifdef EZSP_SPI
void sl_zigbee_ncp_spi_sleep_tick();
#endif // EZSP_SPI

//------------------------------------------------------------------------------
// Internal debug print stub macros

#ifndef SL_CATALOG_ZIGBEE_DEBUG_PRINT_PRESENT
#define sl_zigbee_stack_debug_print(...)
#define sl_zigbee_stack_debug_println(...)
#define sl_zigbee_stack_debug_print_buffer(...)
#define sl_zigbee_stack_debug_print_string(...)
#define sl_zigbee_stack_debug_print_long_string(...)

#define sl_zigbee_core_debug_print(...)
#define sl_zigbee_core_debug_println(...)
#define sl_zigbee_core_debug_print_buffer(...)
#define sl_zigbee_core_debug_print_string(...)
#define sl_zigbee_core_debug_print_long_string(...)

#define sl_zigbee_app_debug_print(...)
#define sl_zigbee_app_debug_println(...)
#define sl_zigbee_app_debug_print_buffer(...)
#define sl_zigbee_app_debug_print_string(...)
#define sl_zigbee_app_debug_print_long_string(...)

#define sl_zigbee_zcl_debug_print(...)
#define sl_zigbee_zcl_debug_println(...)
#define sl_zigbee_zcl_debug_print_buffer(...)
#define sl_zigbee_zcl_debug_print_string(...)
#define sl_zigbee_zcl_debug_print_long_string(...)

#define sl_zigbee_legacy_af_debug_print(...)
#define sl_zigbee_legacy_af_debug_println(...)
#define sl_zigbee_legacy_af_debug_print_buffer(...)
#define sl_zigbee_legacy_af_debug_print_string(...)
#define sl_zigbee_legacy_af_debug_print_long_string(...)

#endif // SL_CATALOG_ZIGBEE_DEBUG_PRINT_PRESENT

#endif // SL_ZIGBEE_SYSTEM_COMMON_H
