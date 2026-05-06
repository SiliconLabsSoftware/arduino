/***************************************************************************//**
 * @file
 * @brief EmberZNet APIs for Duty Cycle support.
 *  These apis are intended to use on SubGhz network only.
 *  For multi phy interface, these apis are only apply to SugGhz interface.
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

#ifndef SILABS_EMBER_DUTY_CYCLE_H
#define SILABS_EMBER_DUTY_CYCLE_H

#include "stack/include/sl_zigbee_types.h"

/**
 * @brief Per device duty cycle monitor feature limits to 32 connected end devices
 *    (excluding a local device).
 */
#define SL_ZIGBEE_MAX_CHILDREN_FOR_PER_DEVICE_DUTY_CYCLE_MONITOR  32
/**
 * @addtogroup ember_duty_cycle
 *
 * See sl_zigbee_duty_cycle.h for source code.
 * @{
 */

/** @brief Obtains the current duty cycle state.
 *
 * @param returnedState The current duty cycle state in effect.
 *
 * @return An ::sl_status_t value.
 * - ::SL_STATUS_OK
 * - ::SL_STATUS_INVALID_PARAMETER if
 *                 - returnedState is NULL (SoC only).
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# returnedState #}
 */
sl_status_t sl_zigbee_get_duty_cycle_state(sl_zigbee_duty_cycle_state_t* returnedState);

/** @brief Set the current duty cycle limits configuration.
 *        The Default limits set by stack if this call is
 *        not made.
 *
 * @param limits The duty cycle limits configuration to utilize.
 *
 * @return An ::sl_status_t value.
 * - ::SL_STATUS_OK If config looks kosher.
 * - ::SL_STATUS_INVALID_PARAMETER if
 *             - limits is NULL
 *             - set illegal value such as setting only one of the limits
 *               to default.
 *             - violates constraints Susp > Crit > Limi.
 * - ::SL_STATUS_INVALID_STATE if
 *             - device is operating on 2.4Ghz
 */
sl_status_t sl_zigbee_set_duty_cycle_limits_in_stack(const sl_zigbee_duty_cycle_limits_t* limits);

/** @brief Obtains the current duty cycle limits that were previously set by a
 *        call to sl_zigbee_set_duty_cycle_limits_in_stack(), or the defaults set by the
 *        stack if no set call was made.
 *
 * @param returnedLimits Return current duty cycle limits if returnedLimits
 *                       is not NULL.
 *
 * @return An ::sl_status_t value.
 * - ::SL_STATUS_OK
 * - ::SL_STATUS_INVALID_PARAMETER if
 *                 - returnedLimits is NULL (SoC only).
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# returnedLimits #}
 */
sl_status_t sl_zigbee_get_duty_cycle_limits(sl_zigbee_duty_cycle_limits_t* returnedLimits);

/** @brief Returns the duty cycle of the stack's connected children
 *        that are being monitored, up to maxDevices. It indicates the
 *        amount of overall duty cycle they have consumed (up to the
 *        suspend limit). The first entry is always the local stack's nodeId,
 *        and thus the total aggregate duty cycle for the device.
 *        The passed pointer arrayOfDeviceDutyCycles MUST have space
 *        for maxDevices.
 *
 * @param maxDevices Number of devices to retrieve consumed duty cycle.
 *        arrayOfDeviceDutyCycles Consumed duty cycles up to maxDevices.
 *                                When the number of children that are being
 *                                monitored is less than maxDevices, the
 *                                sl_802154_short_addr_t element in the sl_zigbee_per_device_duty_cycle_t
 *                                will be 0xFFFF.
 *
 * @return An ::sl_status_t value.
 * - ::SL_STATUS_OK
 * - ::SL_STATUS_INVALID_PARAMETER if
 *                 - maxDevices is greater than SL_ZIGBEE_MAX_CHILDREN_FOR_PER_DEVICE_DUTY_CYCLE_MONITOR + 1.
 *                 - arrayOfDeviceDutyCycles is NULL.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# arrayOfDeviceDutyCycles | length: maxDevices | max: SL_ZIGBEE_MAX_CHILDREN_FOR_PER_DEVICE_DUTY_CYCLE_MONITOR #}
 */
sl_status_t sl_zigbee_get_current_duty_cycle(uint8_t maxDevices,
                                             sl_zigbee_per_device_duty_cycle_t* arrayOfDeviceDutyCycles);

/** @brief Callback fires when the duty cycle state has changed.
 *
 * If the application includes ::sl_zigbee_duty_cycle_handler(), it must
 * define SL_ZIGBEE_APPLICATION_HAS_DUTY_CYCLE_HANDLER in its CONFIGURATION_HEADER.
 *
 * @param channelPage             The channel page whose duty cycle state has changed.
 *        channel                 The channel number whose duty cycle state has changed.
 *        state                   The current duty cycle state.
 *        totalDevices            The total number of end devices that are being monitored
 *                                for each duty cycle.
 *        arrayOfDeviceDutyCycles Consumed duty cycles of end devices that are being monitored.
 *                                The first entry is always the local stack's node ID, and thus the
 *                                total aggregate duty cycle for the device.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# arrayOfDeviceDutyCycles | length: totalDevices | max: SL_ZIGBEE_MAX_CHILDREN_FOR_PER_DEVICE_DUTY_CYCLE_MONITOR #}
 */
void sl_zigbee_duty_cycle_handler(uint8_t channelPage,
                                  uint8_t channel,
                                  sl_zigbee_duty_cycle_state_t state,
                                  uint8_t totalDevices,
                                  sl_zigbee_per_device_duty_cycle_t *arrayOfDeviceDutyCycles);

/** @} END addtogroup */

#endif // SILABS_EMBER_DUTY_CYCLE_H
