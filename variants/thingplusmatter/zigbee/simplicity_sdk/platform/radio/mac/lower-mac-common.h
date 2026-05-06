/***************************************************************************//**
 * @file
 * @brief Lower MAC common file
 * See @ref mac_layer for documentation.
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SILABS_LOWER_MAC_COMMON_H
#define SILABS_LOWER_MAC_COMMON_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
  uint8_t maxCcaAttempts;
  uint8_t minBackoffExp;
  uint8_t maxBackoffExp;
  uint8_t maxRetries;
  bool checkCca;
} sl_mac_csma_parameters_t;

#endif // SILABS_LOWER_MAC_COMMON_H
