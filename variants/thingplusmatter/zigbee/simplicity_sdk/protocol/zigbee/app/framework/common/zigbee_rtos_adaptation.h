/***************************************************************************//**
 * @brief ZigBee CMSIS RTOS support code.
 *******************************************************************************
 * # License
 * <b>Copyright 2023 Silicon Laboratories Inc. www.silabs.com</b>
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

#include PLATFORM_HEADER
#ifdef SL_COMPONENT_CATALOG_PRESENT
#include "sl_component_catalog.h"
#endif

#include "sl_zigbee.h"

#include "cmsis_os2.h"
#include "sl_cmsis_os2_common.h"

#if defined(SL_ZIGBEE_AF_NCP) && defined(SL_CATALOG_IOSTREAM_UART_COMMON_PRESENT)
#include "sl_iostream.h"
#endif

#include "sl_zigbee_system_common.h"
#include "sl_zigbee_rtos_task_config.h"
#ifdef SL_CATALOG_ZIGBEE_REAL_IPC_PRESENT
#include "zigbee_ipc_command_messages.h"
#include "sl_event_system.h"
#include "sl_memory_manager.h"
#endif //SL_COMPONENT_CATALOG_ZIGBEE_REAL_IPC_PRESENT
// NOTE: Why is this sempahore max count 2?
// In zigbee_stack_task_yield, there is some time between when we check to see
// if we can yield and when we actually yield. Between those 2 lines of code,
// there can be an ISR that fires that needs the zigbee task to wake up
// If the count is 1, this event will get missed.
// To prevent the race condition, we set the count to 2.
// By doing this, if the race condition occurs, the zigbee task
// will yield, but because the count is not yet 0, it will run one more
// time and therefore process the ISR related event right away.
#define ZIGBEE_TASK_SEMAPHORE_MAX_COUNT 2
#define ZIGBEE_TASK_SEMAPHORE_INITIAL_COUNT 0

#define ZIGBEE_IPC_COMMAND_AVAILABLE_FLAG 0x0001U
#define ZIGBEE_IPC_COMMAND_PROCESSED_FLAG 0x0002U

void sl_zigbee_wakeup_stack_task(void);

#if defined(SL_CATALOG_ZIGBEE_SYSTEM_COMMON_APP_FRAMEWORK_PRESENT)
extern sl_event_queue_t callback_event_queue;
#endif //defined(SL_CATALOG_ZIGBEE_SYSTEM_COMMON_APP_FRAMEWORK_PRESENT)
