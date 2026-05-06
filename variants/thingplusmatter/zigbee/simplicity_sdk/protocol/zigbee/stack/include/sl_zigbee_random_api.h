/***************************************************************************//**
 * @file
 * @brief EmberZNet APIs for pseudo and true random number generation.
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

#ifndef SL_ZIGBEE_RANDOM_API_H
#define SL_ZIGBEE_RANDOM_API_H

#include "stack/include/sl_zigbee_types.h"

/**
 * @addtogroup security
 *
 * This file describes routines for getting pseudo- and strong-random numbers.
 *
 * @{
 */

/** @brief Wrapper for the HAL API to generate pseudo-random numbers.
 *
 * @return uint16_t pseudo random number
 */
uint16_t sl_zigbee_get_pseudo_random_number(void);

/** @brief Get ::count number of true random numbers. The method of obtaining
 *        and quality of the random varies by chip family and the configuration used.
 *        For high security applications, please verify that that the generator's
 *        properties match your needs.
 *
 * @return An ::sl_status_t value.
 * - ::SL_STATUS_OK If success.
 * - ::SL_STATUS_ZIGBEE_INSUFFICIENT_RANDOM_DATA In case of any error.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# randomNumber | length: count | max: MAX_IPC_VEC_ARG_CAPACITY / sizeof(uint16_t) #}
 */
sl_status_t sl_zigbee_get_strong_random_number_array(uint16_t *randomNumber,
                                                     uint8_t count);

#define sl_zigbee_get_true_random_number_array(randomNumber, count) \
  (sl_zigbee_get_strong_random_number_array((randomNumber), (count)))

/** @brief Generate one true random number.
 *         For more info check ::sl_zigbee_get_strong_random_number_array.
 */
#define sl_zigbee_get_strong_random_number(randomNumber) \
  (sl_zigbee_get_strong_random_number_array((randomNumber), 1))

#define sl_zigbee_get_true_random_number(randomNumber) \
  (sl_zigbee_get_strong_random_number((randomNumber)))

/** @brief Return the entropy source used for true random number generation.
 *
 * @return An ::sl_zigbee_entropy_source_t value.
 * - ::SL_ZIGBEE_ENTROPY_SOURCE_ERROR If there is any error identifying the entroypy source.
 * - ::SL_ZIGBEE_ENTROPY_SOURCE_RADIO Entropy source is the chips that support this. The method of obtaining
 *                                and quality of the random varies by chip family. For high security
 *                                applications, please verify that that the generator's properties match
 *                                the requirements.
 * - ::SL_ZIGBEE_ENTROPY_SOURCE_MBEDTLS_TRNG Entropy source is the TRNG hardware module (if applicable)
 *                                       and the interface driver is powered by mbed TLS.
 * - ::SL_ZIGBEE_ENTROPY_SOURCE_MBEDTLS Entropy source is not the TRNG hardware module
 *                                  but the interface driver is powered by mbed TLS.
 */
sl_zigbee_entropy_source_t sl_zigbee_get_strong_random_entropy_source(void);

// @} END addtogroup

#ifndef EZSP_HOST
#define sl_zigbee_get_true_random_entropy_source() \
  (sl_zigbee_get_strong_random_entropy_source())
#endif

#endif // SL_ZIGBEE_RANDOM_API_H
