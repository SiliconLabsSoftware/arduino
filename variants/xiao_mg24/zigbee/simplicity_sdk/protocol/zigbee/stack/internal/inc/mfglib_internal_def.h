/***************************************************************************//**
 * @file mfglib_internal_def.h
 * @brief internal names for 'mfglib' declarations
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
// automatically generated from mfglib.h.  Do not manually edit
#ifndef MFGLIB_INTERNAL_DEF_H
#define MFGLIB_INTERNAL_DEF_H

#include "stack/include/mfglib.h"

// Command Indirection

sl_status_t mfglibInternalEnd(void);

uint8_t mfglibInternalGetChannel(void);

uint16_t mfglibInternalGetCtune(void);

uint8_t mfglibInternalGetOptions(void);

int8_t mfglibInternalGetPower(void);

int8_t mfglibInternalGetSynOffset(void);

sl_status_t mfglibInternalSendPacket(uint8_t *packet,
                                     uint16_t repeat);

sl_status_t mfglibInternalSetChannel(uint8_t chan);

sl_status_t mfglibInternalSetCtune(uint16_t ctune);

sl_status_t mfglibInternalSetOptions(uint8_t options);

sl_status_t mfglibInternalSetPower(uint16_t txPowerMode,
                                   int8_t power);

void mfglibInternalSetSynOffset(int8_t synOffset);

sl_status_t mfglibInternalStart(MfglibRxCallback mfglibRxCallback);

sl_status_t mfglibInternalStartStream(void);

sl_status_t mfglibInternalStartTone(void);

sl_status_t mfglibInternalStopStream(void);

sl_status_t mfglibInternalStopTone(void);

#endif // MFGLIB_INTERNAL_DEF_H
