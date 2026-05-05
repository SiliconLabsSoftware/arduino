/***************************************************************************//**
 * @file mfglib_ipc_command_messages.h
 * @brief defines structured format for 'mfglib' ipc messages
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
#ifndef MFGLIB_IPC_COMMAND_MESSAGES_H
#define MFGLIB_IPC_COMMAND_MESSAGES_H

#include "stack/include/mfglib.h"
#include "stack/internal/inc/mfglib_internal_def.h"

typedef struct {
  sl_status_t result;
} mfglibInternalEnd_ipc_rsp_t;

typedef struct {
  mfglibInternalEnd_ipc_rsp_t response;
} mfglibInternalEnd_ipc_msg_t;

typedef struct {
  uint8_t result;
} mfglibInternalGetChannel_ipc_rsp_t;

typedef struct {
  mfglibInternalGetChannel_ipc_rsp_t response;
} mfglibInternalGetChannel_ipc_msg_t;

typedef struct {
  uint16_t result;
} mfglibInternalGetCtune_ipc_rsp_t;

typedef struct {
  mfglibInternalGetCtune_ipc_rsp_t response;
} mfglibInternalGetCtune_ipc_msg_t;

typedef struct {
  uint8_t result;
} mfglibInternalGetOptions_ipc_rsp_t;

typedef struct {
  mfglibInternalGetOptions_ipc_rsp_t response;
} mfglibInternalGetOptions_ipc_msg_t;

typedef struct {
  int8_t result;
} mfglibInternalGetPower_ipc_rsp_t;

typedef struct {
  mfglibInternalGetPower_ipc_rsp_t response;
} mfglibInternalGetPower_ipc_msg_t;

typedef struct {
  int8_t result;
} mfglibInternalGetSynOffset_ipc_rsp_t;

typedef struct {
  mfglibInternalGetSynOffset_ipc_rsp_t response;
} mfglibInternalGetSynOffset_ipc_msg_t;

typedef struct {
  uint8_t packet[MAX_IPC_VEC_ARG_CAPACITY];
  uint16_t repeat;
} mfglibInternalSendPacket_ipc_req_t;

typedef struct {
  sl_status_t result;
} mfglibInternalSendPacket_ipc_rsp_t;

typedef struct {
  mfglibInternalSendPacket_ipc_req_t request;
  mfglibInternalSendPacket_ipc_rsp_t response;
} mfglibInternalSendPacket_ipc_msg_t;

typedef struct {
  uint8_t chan;
} mfglibInternalSetChannel_ipc_req_t;

typedef struct {
  sl_status_t result;
} mfglibInternalSetChannel_ipc_rsp_t;

typedef struct {
  mfglibInternalSetChannel_ipc_req_t request;
  mfglibInternalSetChannel_ipc_rsp_t response;
} mfglibInternalSetChannel_ipc_msg_t;

typedef struct {
  uint16_t ctune;
} mfglibInternalSetCtune_ipc_req_t;

typedef struct {
  sl_status_t result;
} mfglibInternalSetCtune_ipc_rsp_t;

typedef struct {
  mfglibInternalSetCtune_ipc_req_t request;
  mfglibInternalSetCtune_ipc_rsp_t response;
} mfglibInternalSetCtune_ipc_msg_t;

typedef struct {
  uint8_t options;
} mfglibInternalSetOptions_ipc_req_t;

typedef struct {
  sl_status_t result;
} mfglibInternalSetOptions_ipc_rsp_t;

typedef struct {
  mfglibInternalSetOptions_ipc_req_t request;
  mfglibInternalSetOptions_ipc_rsp_t response;
} mfglibInternalSetOptions_ipc_msg_t;

typedef struct {
  uint16_t txPowerMode;
  int8_t power;
} mfglibInternalSetPower_ipc_req_t;

typedef struct {
  sl_status_t result;
} mfglibInternalSetPower_ipc_rsp_t;

typedef struct {
  mfglibInternalSetPower_ipc_req_t request;
  mfglibInternalSetPower_ipc_rsp_t response;
} mfglibInternalSetPower_ipc_msg_t;

typedef struct {
  int8_t synOffset;
} mfglibInternalSetSynOffset_ipc_req_t;

typedef struct {
  mfglibInternalSetSynOffset_ipc_req_t request;
} mfglibInternalSetSynOffset_ipc_msg_t;

typedef struct {
  MfglibRxCallback mfglibRxCallback;
} mfglibInternalStart_ipc_req_t;

typedef struct {
  sl_status_t result;
} mfglibInternalStart_ipc_rsp_t;

typedef struct {
  mfglibInternalStart_ipc_req_t request;
  mfglibInternalStart_ipc_rsp_t response;
} mfglibInternalStart_ipc_msg_t;

typedef struct {
  sl_status_t result;
} mfglibInternalStartStream_ipc_rsp_t;

typedef struct {
  mfglibInternalStartStream_ipc_rsp_t response;
} mfglibInternalStartStream_ipc_msg_t;

typedef struct {
  sl_status_t result;
} mfglibInternalStartTone_ipc_rsp_t;

typedef struct {
  mfglibInternalStartTone_ipc_rsp_t response;
} mfglibInternalStartTone_ipc_msg_t;

typedef struct {
  sl_status_t result;
} mfglibInternalStopStream_ipc_rsp_t;

typedef struct {
  mfglibInternalStopStream_ipc_rsp_t response;
} mfglibInternalStopStream_ipc_msg_t;

typedef struct {
  sl_status_t result;
} mfglibInternalStopTone_ipc_rsp_t;

typedef struct {
  mfglibInternalStopTone_ipc_rsp_t response;
} mfglibInternalStopTone_ipc_msg_t;

#endif // MFGLIB_IPC_COMMAND_MESSAGES_H
