/***************************************************************************//**
 * @file
 * @brief EmberZNet AES-MMO Hash API.
 * See @ref security for documentation.
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

#ifndef SILABS_AES_MMO_H
#define SILABS_AES_MMO_H

#include "stack/include/sl_zigbee_types.h"

/**
 * @addtogroup security
 *
 * This file describes the functions for performing an AES-MMO hash on a
 * block of data.  The block of data may be small and contiguous, in which
 * case the sl_zigbee_aes_hash_simple() routine can be used.  Or large and
 * discontiguous (such as a file stored in EEPROM), in which case the
 * application must pass chunks to sl_zigbee_aes_mmo_hash_update() routine
 * and use sl_zigbee_aes_mmo_hash_final() on the last chunk.
 *
 * @{
 */

/** @brief
 *  This routine clears the passed context so that a new hash calculation
 *  can be performed.
 *
 *  @param context A pointer to the location of hash context to clear.
 */
void sl_zigbee_aes_mmo_hash_init(sl_zigbee_aes_mmo_hash_context_t* context);

/** @brief
 *  This routine processes the passed chunk of data and updates
 *  the hash calculation based on it.  The data passed in MUST
 *  have a length that is a multiple of 16.
 *
 * @param context A pointer to the location of the hash context to update.
 * @param length The length of the passed data.
 * @param data A pointer to the location of the data to hash.
 *
 * @return An ::sl_status_t value indicating SL_STATUS_OK if the hash was
 *   calculated successfully.  SL_STATUS_INVALID_STATE if the block size is not a
 *   multiple of 16 bytes, and SL_STATUS_INVALID_INDEX is returned when the
 *   data exceeds the maximum limits of the hash function.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# data | length: length | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
sl_status_t sl_zigbee_aes_mmo_hash_update(sl_zigbee_aes_mmo_hash_context_t* context,
                                          uint32_t length,
                                          const uint8_t* data);

/** @brief
 *  This routine processes the passed chunk of data (if non-NULL)
 *  and update the hash context that is passed in.  In then performs
 *  the final calculations on the hash and returns the final answer
 *  in the result parameter of the ::sl_zigbee_aes_mmo_hash_context_t structure.
 *  The length of the data passed in may be any value, it does not have
 *  to be a multiple of 16.
 *
 * @param context A pointer to the location of the hash context to finalize.
 * @param length The length of the finalData parameter.
 * @param finalData A pointer to the location of data to hash.  May be NULL.
 *
 * @return An ::sl_status_t value indicating SL_STATUS_OK if the hash was
 *   calculated successfully.  SL_STATUS_INVALID_STATE if the block size is not a
 *   multiple of 16 bytes, and SL_STATUS_INVALID_INDEX is returned when the
 *   data exceeds the maximum limits of the hash function.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# finalData | length: length | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
sl_status_t sl_zigbee_aes_mmo_hash_final(sl_zigbee_aes_mmo_hash_context_t* context,
                                         uint32_t length,
                                         const uint8_t* finalData);

/** @brief
 *  This is a convenience method when the hash data is less than 255
 *  bytes.  It inits, updates, and finalizes the hash in one function call.
 *
 * @param totalLength The length of the data.
 * @param data The data to hash.
 * @param result The location where the result of the hash will be written.
 *
 * @return An ::sl_status_t value indicating SL_STATUS_OK if the hash was
 *   calculated successfully.  SL_STATUS_INVALID_STATE if the block size is not a
 *   multiple of 16 bytes, and SL_STATUS_INVALID_INDEX is returned when the
 *   data exceeds the maximum limits of the hash function.
 * @internal SL_ZIGBEE_IPC_ARGS
 * {# data | length: totalLength | max: MAX_IPC_VEC_ARG_CAPACITY #}
 * {# result | length: SL_ZIGBEE_AES_HASH_BLOCK_SIZE | max: MAX_IPC_VEC_ARG_CAPACITY #}
 */
sl_status_t sl_zigbee_aes_hash_simple(uint8_t totalLength,
                                      const uint8_t* data,
                                      uint8_t* result);

// @} END addtogroup

#endif // SILABS_AES_MMO_H
