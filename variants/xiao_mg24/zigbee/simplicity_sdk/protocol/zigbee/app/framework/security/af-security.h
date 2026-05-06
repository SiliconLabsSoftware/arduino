/***************************************************************************//**
 * @file
 * @brief Header file for App. Framework security code
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

#ifndef SILABS_AF_SECURITY_H
#define SILABS_AF_SECURITY_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief The size of the CRC that is appended to an installation code.
 */
#define SL_ZIGBEE_INSTALL_CODE_CRC_SIZE 2

/**
 * @brief The number of sizes of acceptable installation codes used in
 *  Certificate Based Key Establishment (CBKE).
 */
#define SL_ZIGBEE_NUM_INSTALL_CODE_SIZES 4

/**
 * @brief Various sizes of valid installation codes that are stored in the
 *  manufacturing tokens. Note that each size includes 2 bytes of CRC appended
 *  to the end of the installation code.
 */
#define SL_ZIGBEE_INSTALL_CODE_SIZES { 6  + SL_ZIGBEE_INSTALL_CODE_CRC_SIZE, \
                                       8  + SL_ZIGBEE_INSTALL_CODE_CRC_SIZE, \
                                       12 + SL_ZIGBEE_INSTALL_CODE_CRC_SIZE, \
                                       16 + SL_ZIGBEE_INSTALL_CODE_CRC_SIZE }

void getLinkKeyFromCli(sl_zigbee_key_data_t* returnData);
void getNetworkKeyFromCli(sl_zigbee_key_data_t* returnData);

// If this flag is true we clear the link key table before forming or joining.
// If false, we skip clearing the link key once and we set this flag back to
// true.
extern bool sl_zigbee_af_clear_link_key_table_upon_forming_or_joining;

extern const sl_zigbee_af_security_profile_data_t sli_zigbee_af_security_profile_data[];
const sl_zigbee_af_security_profile_data_t *sli_zigbee_af_get_current_security_profile_data(void);

void sli_zigbee_af_clear_link_key_table(void);

sl_status_t sli_zigbee_af_install_code_to_key(uint8_t* installCode, // includes CRC
                                              uint8_t length, // includes CRC length
                                              sl_zigbee_key_data_t *key);

sl_status_t zaTrustCenterSetJoinPolicy(sl_zigbee_join_decision_t decision);

#if !(defined(SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_HA)     \
  || defined(SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_HA12)    \
  || defined(SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_SE_TEST) \
  || defined(SL_ZIGBEE_AF_HAS_SECURITY_PROFILE_SE_FULL))
// For no security, simply #define the security init routines to no-ops.
// For ZigBee 3.0 security, plugins handle the initialization of security.
// We need to include the real ones for any of the non-z3, non-none types.
// The logic is inverted like this because of the multi-network case.
  #ifndef USE_REAL_SECURITY_PROTOTYPES
    #define zaNodeSecurityInit(centralizedNetwork)
    #define zaTrustCenterSecurityInit(centralizedNetwork)
    #define zaTrustCenterSecurityPolicyInit()
  #endif
#else // All other security profiles.
sl_status_t zaNodeSecurityInit(bool centralizedNetwork);
sl_status_t zaTrustCenterSecurityInit(bool centralizedNetwork);
sl_status_t zaTrustCenterSecurityPolicyInit(void);
#endif

#ifdef __cplusplus
}
#endif

#endif // SILABS_AF_SECURITY_H
