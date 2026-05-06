/***************************************************************************//**
 * @brief Zigbee ZCL Framework Core component configuration header.
 *\n*******************************************************************************
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

// <<< Use Configuration Wizard in Context Menu >>>

// <h>Zigbee ZCL Framework Core configuration

// <q SL_ZIGBEE_AF_PLUGIN_ZCL_FRAMEWORK_CORE_CLI_ENABLED> Enable Command Line for Legacy CLI
// <i> Default: TRUE
// <i> Enable the command line when using Legacy CLI generation. This does not do anything if Legacy CLI generation is unselected.
#define SL_ZIGBEE_AF_PLUGIN_ZCL_FRAMEWORK_CORE_CLI_ENABLED   1

// <q SL_ZIGBEE_AF_PLUGIN_ZCL_CLUSTER_ENABLE_DISABLE_RUN_TIME> Enable/disable clusters at runtime
// <i> Default: FALSE
// <i> Enable the feature that allows to enable/disable clusters at runtime.
#define SL_ZIGBEE_AF_PLUGIN_ZCL_CLUSTER_ENABLE_DISABLE_RUN_TIME   0

// <q SL_ZIGBEE_AF_PLUGIN_ZCL_CLUSTER_DEFER_ATTRIBUTE_WRITES_TO_NVM_MS> Time in milliseconds to defer updating NVM when an attribute changes value
// <i> Default: 0
// <0-10000>
// <i> For attributes that are stored in NVM, this is the amount of time to defer updating NVM3. The RAM value of the attribute is always updated immediately upon change. A value of 0 for this configuration item means that NVM should be updated immediately without delay. For a nonzero delay, if the attribute changes again within this delay period, the update to the non-volatile storage will be pushed out until a full delay period has elapsed without change, upon which the value in RAM is written to NVM. Deferring of updating NVM is useful in scenarios where writing to flash is slow, such as with external flash, or when trying to reduce the amount of writes to flash.
#define SL_ZIGBEE_AF_PLUGIN_ZCL_CLUSTER_DEFER_ATTRIBUTE_WRITES_TO_NVM_MS  0

// </h>

// <<< end of configuration section >>>
