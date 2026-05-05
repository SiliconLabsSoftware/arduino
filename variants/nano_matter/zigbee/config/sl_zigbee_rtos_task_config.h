/***************************************************************************//**
 * @brief Zigbee System common component configuration header.
 *\n*******************************************************************************
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

// <<< Use Configuration Wizard in Context Menu >>>

// <h>Zigbee stack RTOS task configuration
// <o SL_ZIGBEE_STACK_RTOS_TASK_STACK_SIZE> Zigbee-stack RTOS task stack size in bytes <1000-20000>
// <i> Default: 2800
// <i> Defines the RTOS stack size of the Zigbee-stack RTOS task. The value is in bytes and
// <i> and will be word aligned when it is applied at the task creation.
#define SL_ZIGBEE_STACK_RTOS_TASK_STACK_SIZE 2800

// <o SL_ZIGBEE_STACK_RTOS_TASK_PRIORITY> Zigbee stack RTOS task priority <41-49>
// <i> Default: 49
// <i> Defines the priority of the Zigbee RTOS stack task - CAUTION: Change not recommended!
#define SL_ZIGBEE_STACK_RTOS_TASK_PRIORITY 49

// </h>

// <h>Zigbee app framework RTOS task configuration
// <o SL_ZIGBEE_APP_FRAMEWORK_RTOS_TASK_STACK_SIZE> Zigbee AF RTOS task stack size in bytes <1000-20000>
// <i> Default: 2000
// <i> Defines the RTOS stack size of the Zigbee AF RTOS task. The value is in bytes and
// <i> and will be word aligned when it is applied at the task creation.
#define SL_ZIGBEE_APP_FRAMEWORK_RTOS_TASK_STACK_SIZE 2000

// <o SL_ZIGBEE_APP_FRAMEWORK_RTOS_TASK_PRIORITY> Zigbee AF RTOS task priority <41-49>
// <i> Default: 48
// <i> Defines the priority of the Zigbee AF RTOS stack task - CAUTION: Change not recommended!
#define SL_ZIGBEE_APP_FRAMEWORK_RTOS_TASK_PRIORITY 48

// </h>
// <<< end of configuration section >>>
