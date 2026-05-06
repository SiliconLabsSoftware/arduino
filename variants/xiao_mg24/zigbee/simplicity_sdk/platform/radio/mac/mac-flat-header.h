/***************************************************************************//**
 * @file mac-flat-header.h
 * @brief Definitions and macros of PHY and MAC headers, represented as flat
 * (over-the-air) packets.
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef MAC_FLAT_HEADER_H
#define MAC_FLAT_HEADER_H
#include "mac-header.h"
// -----------------------------------------------------------------------------
// Internal APIs

enum {
  SL_ZIGBEE_PH_FIELD_PHY_HEADER                    = 0, // the first (and only)
  SL_ZIGBEE_PH_FIELD_PHY_HEADER_PAYLOAD_LENGTH     = 0, // field of the PHY header
  // is the phy payload length
  SL_ZIGBEE_PH_FIELD_PHY_PAYLOAD                   = 1, // the MAC frame control is
  SL_ZIGBEE_PH_FIELD_MAC_HEADER                    = 1, // the first field of the
  SL_ZIGBEE_PH_FIELD_MAC_HEADER_FRAME_CONTROL      = 1, // MAC header, which is the
  // the beginning of the PHY
  // payload
  SL_ZIGBEE_PH_FIELD_MAC_HEADER_SEQUENCE_NUMBER    = 2,
  SL_ZIGBEE_PH_FIELD_MAC_HEADER_DEST_PAN_ID        = 3,
  SL_ZIGBEE_PH_FIELD_MAC_HEADER_DEST_ADDR          = 4,
  SL_ZIGBEE_PH_FIELD_MAC_HEADER_SRC_PAN_ID         = 5,
  SL_ZIGBEE_PH_FIELD_MAC_HEADER_SRC_ADDR           = 6,
  SL_ZIGBEE_PH_FIELD_MAC_AUXILIARY_HEADER          = 7,
  SL_ZIGBEE_PH_FIELD_MAC_AUX_SECURITY_CONTROL      = 7,
  SL_ZIGBEE_PH_FIELD_MAC_AUX_FRAME_COUNTER         = 8,
  SL_ZIGBEE_PH_FIELD_MAC_PAYLOAD                   = 9,
  SL_ZIGBEE_PH_FIELD_MAC_MIC                       = 13,
};

// -----------------------------------------------------------------------------
// PHY Header definitions

#define SL_ZIGBEE_PHY_HEADER_OFFSET             0
#define SL_ZIGBEE_PHY_PAYLOAD_LENGTH_OFFSET     (SL_ZIGBEE_PHY_HEADER_OFFSET)
#define SL_ZIGBEE_PHY_HEADER_LENGTH             1
#define SL_ZIGBEE_PHY_PAYLOAD_OFFSET            (SL_ZIGBEE_PHY_HEADER_LENGTH)
#define SL_ZIGBEE_PHY_PREAMBLE_LENGTH           4
#define SL_ZIGBEE_PHY_SFD_LENGTH                2
#define SL_ZIGBEE_PHY_CRC_LENGTH                2
#define SL_ZIGBEE_PHY_MAX_PACKET_LENGTH         128
#define SL_ZIGBEE_PHY_MAX_PAYLOAD_LENGTH        (SL_ZIGBEE_PHY_MAX_PACKET_LENGTH \
                                                 - SL_ZIGBEE_PHY_HEADER_LENGTH   \
                                                 - SL_ZIGBEE_PHY_CRC_LENGTH)

// -----------------------------------------------------------------------------
// MAC Header definitions

#define SL_802154_HEADER_OFFSET                 (SL_ZIGBEE_PHY_HEADER_LENGTH)
#define SL_802154_HEADER_FRAME_CONTROL_OFFSET   (SL_802154_HEADER_OFFSET)
#define SL_802154_HEADER_SEQUENCE_NUMBER_OFFSET (SL_802154_HEADER_OFFSET + 2)

// Frame control defs
#define SL_802154_HEADER_FC_FRAME_TYPE_MASK                 0x0007
#define SL_802154_HEADER_FC_FRAME_TYPE_OFFSET               0
#define SL_802154_HEADER_FC_SECURITY_ENABLED_BIT            0x0008
#define SL_802154_HEADER_FC_FRAME_PENDING_BIT               0x0010
#define SL_802154_HEADER_FC_ACK_REQUEST_BIT                 0x0020
#define SL_802154_HEADER_FC_PAN_ID_COMPRESS_BIT             0x0040
#define SL_802154_HEADER_FC_RESERVED_BITS_MASK              0x0380
#define SL_802154_HEADER_FC_RESERVED_BITS_OFFSET            7

// 802.15.4E-2012 introduced these flags for Frame Version 2 frames
// which are reserved bit positions in earlier Frame Version frames:
#define SL_802154_HEADER_FC_SEQ_SUPPRESSION_BIT             0x0100
#define SL_802154_HEADER_FC_IE_LIST_PRESENT_BIT             0x0200

// Address modes
#define SL_802154_HEADER_FC_DEST_ADDR_MODE_MASK             0x0C00
#define SL_802154_HEADER_FC_DEST_ADDR_MODE_NONE             0x0000
#define SL_802154_HEADER_FC_DEST_ADDR_MODE_RESERVED         0x0400
#define SL_802154_HEADER_FC_DEST_ADDR_MODE_SHORT            0x0800
#define SL_802154_HEADER_FC_DEST_ADDR_MODE_LONG             0x0C00
#define SL_802154_HEADER_FC_DEST_ADDR_MODE_OFFSET           10

#define SL_802154_HEADER_FC_SRC_ADDR_MODE_MASK              0xC000
#define SL_802154_HEADER_FC_SRC_ADDR_MODE_NONE              0x0000
#define SL_802154_HEADER_FC_SRC_ADDR_MODE_RESERVED          0x4000
#define SL_802154_HEADER_FC_SRC_ADDR_MODE_SHORT             0x8000
#define SL_802154_HEADER_FC_SRC_ADDR_MODE_LONG              0xC000
#define SL_802154_HEADER_FC_SRC_ADDR_MODE_OFFSET            14

// Version types
#define SL_802154_HEADER_FC_FRAME_VERSION_MASK              0x3000
#define SL_802154_HEADER_FC_FRAME_VERSION_2003              0x0000
#define SL_802154_HEADER_FC_FRAME_VERSION_2006              0x1000
#define SL_802154_HEADER_FC_FRAME_VERSION_2012              0x2000
#define SL_802154_HEADER_FC_FRAME_VERSION_OFFSET            12

// Frame control frame type
#define SL_802154_HEADER_FC_FRAME_TYPE_BEACON               0x00
#define SL_802154_HEADER_FC_FRAME_TYPE_DATA                 0x01
#define SL_802154_HEADER_FC_FRAME_TYPE_ACK                  0x02
#define SL_802154_HEADER_FC_FRAME_TYPE_COMMAND              0x03
#define SL_802154_HEADER_FC_FRAME_TYPE_CONTROL              SL_802154_HEADER_FC_FRAME_TYPE_COMMAND // (synonym)
#define SL_802154_HEADER_FC_FRAME_TYPE_MULTIPURPOSE         0x05

// Frame version
#define SL_802154_HEADER_FC_FRAME_VERSION_15_4_2003         0x00
#define SL_802154_HEADER_FC_FRAME_VERSION_15_4              0x01

// IEEE's definition of multipurpose frames differ from the standard MAC frame

#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_SEQUENCE_NUMBER_OFFSET        (SL_802154_HEADER_SEQUENCE_NUMBER_OFFSET)
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_IE_OFFSET                     (10)

// Frame control defs
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_LONG_FRAME_CONTROL_BIT     0x0008
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_SECURITY_ENABLED_BIT       0x0200
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_PAN_ID_PRESENT_BIT         0x0100
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_FRAME_PENDING_BIT          0x0800
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_ACK_REQUEST_BIT            0x4000
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_IE_PRESENT_BIT             0x8000

#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_DEST_ADDR_MODE_MASK        0x0030
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_DEST_ADDR_MODE_NONE        0x0000
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_DEST_ADDR_MODE_RESERVED    0x0010
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_DEST_ADDR_MODE_SHORT       0x0020
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_DEST_ADDR_MODE_LONG        0x0030
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_DEST_ADDR_MODE_OFFSET      4

#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_SRC_ADDR_MODE_MASK         0x00C0
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_SRC_ADDR_MODE_NONE         0x0000
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_SRC_ADDR_MODE_RESERVED     0x0040
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_SRC_ADDR_MODE_SHORT        0x0080
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_SRC_ADDR_MODE_LONG         0x00C0
#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_SRC_ADDR_MODE_OFFSET       6

#define SL_ZIGBEE_MULTIPURPOSE_MAC_HEADER_FC_FRAME_VERSION              0

#define SL_ZIGBEE_802_15_4_IE_HEADER_LENGTH_RENDEZVOUS_TIME             0x04
#define SL_ZIGBEE_802_15_4_IE_HEADER_LENGTH_RENDEZVOUS_TIME_OFFSET      0
#define SL_ZIGBEE_802_15_4_IE_HEADER_ELEMENT_ID_RENDEZVOUS_TIME         0x1D
#define SL_ZIGBEE_802_15_4_IE_HEADER_ELEMENT_ID_RENDEZVOUS_TIME_OFFSET  7
// -----------------------------------------------------------------------------
// MAC Auxiliary Security Header definitions

#define SL_802154_AUX_HEADER_SECURITY_CONTROL_FIELD_OFFSET  0

// Security control field defs
#define SL_802154_AUX_HEADER_SECURITY_LEVEL_MASK            0x07
#define SL_802154_AUX_HEADER_SECURITY_LEVEL_OFFSET          0

// 15.4-2011 - Key identifier mode
// 00 - Key is determined implicitly from the originator and recipient(s) of the
//      frame, as indicated in the frame header.
// 01 - Key is determined from the Key Index field in conjunction with
//      macDefaultKeySource.
// 10 - Key is determined explicitly from the 4-octet Key Source field and the
//      Key Index field.
// 11 - Key is determined explicitly from the 8-octet Key Source field and the
//      Key Index field.
#define SL_802154_AUX_HEADER_KEY_ID_MODE_MASK               0x18
#define SL_802154_AUX_HEADER_KEY_ID_MODE_OFFSET             3

// Some security suites we support (namely XXTEA), need to have the payload
// padded. We allow up to 3 bytes padding. We use the 2 of the 3 reserved bits
// in the security control field to inform the destination about the extra bytes
// included in the MAC payload because of the security padding requirement.
#define SL_802154_AUX_HEADER_PADDING_SIZE_MASK              0x60
#define SL_802154_AUX_HEADER_PADDING_SIZE_OFFSET            5

// We use the most significant reserved bit to distinguish between the two
// security suites we support (AES or XXTEA).
#define SL_802154_AUX_HEADER_XXTEA_SECURITY_BIT             0x80
#define SL_802154_AUX_HEADER_XXTEA_SECURITY_OFFSET          7

// Frame counter
#define SL_802154_AUX_HEADER_FRAME_COUNTER_SIZE             4
#define SL_802154_AUX_HEADER_FRAME_COUNTER_OFFSET           1

// 15.4-2011 - Key identifier
// The Key Identifier field has a variable length and identifies the key that is
// used for cryptographic protection of outgoing frames, either explicitly or in
// conjunction with implicitly defined side information. The Key Identifier
// field shall be present only if the Key Identifier Mode field, as defined in
// 7.4.1.2, is set to a value different from 0x00.
// -------------
// We always use key identifier mode 00, which means that the key identifier
// field is not present.
#define SL_802154_AUX_HEADER_KEY_IDENTIFIER_OFFSET          5

// Security control (1 byte) + frame counter (4 bytes)
#define SL_802154_AUX_HEADER_SIZE                           5

// -----------------------------------------------------------------------------
// Frame Control definitions

#define SL_802154_DATA_FRAME_CONTROL         \
  (SL_802154_HEADER_FC_FRAME_TYPE_DATA       \
   | SL_802154_HEADER_FC_PAN_ID_COMPRESS_BIT \
   | SL_802154_HEADER_FC_SRC_ADDR_MODE_SHORT \
   | SL_802154_HEADER_FC_DEST_ADDR_MODE_SHORT)

#define SL_802154_BEACON_SHORT_FRAME_CONTROL \
  (SL_802154_HEADER_FC_FRAME_TYPE_BEACON     \
   | SL_802154_HEADER_FC_SRC_ADDR_MODE_SHORT \
   | SL_802154_HEADER_FC_DEST_ADDR_MODE_NONE)

#define SL_802154_BEACON_LONG_FRAME_CONTROL \
  (SL_802154_HEADER_FC_FRAME_TYPE_BEACON    \
   | SL_802154_HEADER_FC_SRC_ADDR_MODE_LONG \
   | SL_802154_HEADER_FC_DEST_ADDR_MODE_NONE)

#define SL_802154_BEACON_ENHANCED_FRAME_CONTROL \
  (SL_802154_HEADER_FC_FRAME_TYPE_BEACON        \
   | SL_802154_HEADER_FC_FRAME_VERSION_2012     \
   | SL_802154_HEADER_FC_IE_LIST_PRESENT_BIT    \
   | SL_802154_HEADER_FC_SRC_ADDR_MODE_LONG     \
   | SL_802154_HEADER_FC_DEST_ADDR_MODE_NONE)

// -----------------------------------------------------------------------------
// Phy header macros

#define sli_mac_flat_phy_header(phy_packet) \
  (phy_packet + SL_ZIGBEE_PHY_HEADER_OFFSET)

#define sli_mac_flat_phy_payload_length(phy_packet) \
  ((phy_packet)[SL_ZIGBEE_PHY_HEADER_OFFSET])

#define sli_mac_flat_phy_payload(phy_packet) \
  ((phy_packet) + SL_ZIGBEE_PHY_PAYLOAD_LENGTH_OFFSET)

#define sli_mac_flat_phy_packet_length(phy_packet) \
  (SL_ZIGBEE_PHY_HEADER_LENGTH + sli_mac_flat_phy_payload_length(phy_packet))

// -----------------------------------------------------------------------------
// MAC header macros

#define sli_mac_flat_mac_header_offset(packet, hasPhyHeader) \
  (sli_mac_flat_field_offset((packet), (hasPhyHeader), SL_ZIGBEE_PH_FIELD_MAC_HEADER))

// Returns the size of the MAC header (included the auxiliary MAC header if
// present).
#define sli_mac_flat_mac_header_length(packet, hasPhyHeader)                           \
  (sli_mac_flat_field_offset((packet), (hasPhyHeader), SL_ZIGBEE_PH_FIELD_MAC_PAYLOAD) \
   - ((hasPhyHeader) ? SL_ZIGBEE_PHY_HEADER_LENGTH : 0))

#define sli_mac_flat_mac_header(packet, hasPhyHeader) \
  ((packet) + sli_mac_flat_mac_header_offset((packet), (hasPhyHeader)))

// Frame control
#define sli_mac_flat_mac_frame_control(packet, hasPhyHeader)             \
  (sl_util_fetch_low_high_int16u((packet)                                \
                                 + SL_802154_HEADER_FRAME_CONTROL_OFFSET \
                                 - ((hasPhyHeader) ? 0 : 1)))

#define sli_mac_flat_set_mac_frame_control(packet, hasPhyHeader, frameControl) \
  (sl_util_store_low_high_int16u((packet)                                      \
                                 + SL_802154_HEADER_FRAME_CONTROL_OFFSET       \
                                 - ((hasPhyHeader) ? 0 : 1),                   \
                                 (frameControl)))

#define sli_mac_flat_frame_type(packet, hasPhyHeader) \
  (sli_mac_flat_mac_frame_control((packet), (hasPhyHeader)) & SL_802154_HEADER_FC_FRAME_TYPE_MASK)

#define sli_mac_flat_security_enabled(packet, hasPhyHeader)  \
  ((sli_mac_flat_mac_frame_control((packet), (hasPhyHeader)) \
    & SL_802154_HEADER_FC_SECURITY_ENABLED_BIT) > 0)

#define sli_mac_flat_frame_pending(packet, hasPhyHeader)     \
  ((sli_mac_flat_mac_frame_control((packet), (hasPhyHeader)) \
    & SL_802154_HEADER_FC_FRAME_PENDING_BIT) > 0)

#define sli_mac_flat_ack_requested(packet, hasPhyHeader)     \
  ((sli_mac_flat_mac_frame_control((packet), (hasPhyHeader)) \
    & SL_802154_HEADER_FC_ACK_REQUEST_BIT) > 0)

#define sli_mac_flat_panid_compressed(packet, hasPhyHeader)  \
  ((sli_mac_flat_mac_frame_control((packet), (hasPhyHeader)) \
    & SL_802154_HEADER_FC_PAN_ID_COMPRESS_BIT) > 0)

#define sli_mac_flat_dest_addr_mode(packet, hasPhyHeader)   \
  (sli_mac_flat_mac_frame_control((packet), (hasPhyHeader)) \
   & SL_802154_HEADER_FC_DEST_ADDR_MODE_MASK)

#define sli_mac_flat_frame_version(packet, hasPhyHeader)    \
  (sli_mac_flat_mac_frame_control((packet), (hasPhyHeader)) \
   & SL_802154_HEADER_FC_FRAME_VERSION_MASK)

#define sli_mac_flat_src_addr_mode(packet, hasPhyHeader)    \
  (sli_mac_flat_mac_frame_control((packet), (hasPhyHeader)) \
   & SL_802154_HEADER_FC_SRC_ADDR_MODE_MASK)

// Sequence number
#define sli_mac_flat_sequence_number(packet, hasPhyHeader) \
  ((packet)[SL_802154_HEADER_SEQUENCE_NUMBER_OFFSET - ((hasPhyHeader) ? 0 : 1)])

// Destination PAN ID
#define sli_mac_flat_dest_panid_offset(packet, hasPhyHeader) \
  (sli_mac_flat_field_offset((packet), (hasPhyHeader), SL_ZIGBEE_PH_FIELD_MAC_HEADER_DEST_PAN_ID))

// 15.4-2011 - "This field shall be included in the MAC frame only if the
// Destination Addressing Mode field is nonzero".
#define sli_mac_flat_dest_panid_present(packet, hasPhyHeader) \
  (sli_mac_flat_dest_addr_mode((packet), (hasPhyHeader))      \
   != SL_802154_HEADER_FC_DEST_ADDR_MODE_NONE)

#define sli_mac_flat_dest_panid(packet, hasPhyHeader) \
  (sl_util_fetch_low_high_int16u((packet) + sli_mac_flat_dest_panid_offset((packet), (hasPhyHeader))))

// Destination address
#define sli_mac_flat_dest_addr_offset(packet, hasPhyHeader) \
  (sli_mac_flat_field_offset((packet), (hasPhyHeader), SL_ZIGBEE_PH_FIELD_MAC_HEADER_DEST_ADDR))

// 15.4-2011 - "This field shall be included in the MAC frame only if the
// Destination Addressing Mode field is nonzero".
#define sli_mac_flat_dest_addr_present(packet, hasPhyHeader) \
  (sli_mac_flat_dest_addr_mode((packet), (hasPhyHeader))     \
   != SL_802154_HEADER_FC_DEST_ADDR_MODE_NONE)

#define sli_mac_flat_dest_addr_is_short(packet, hasPhyHeader) \
  (sli_mac_flat_dest_addr_mode((packet), (hasPhyHeader))      \
   == SL_802154_HEADER_FC_DEST_ADDR_MODE_SHORT)

#define sli_mac_flat_dest_addr_is_long(packet, hasPhyHeader) \
  (sli_mac_flat_dest_addr_mode((packet), (hasPhyHeader))     \
   == SL_802154_HEADER_FC_DEST_ADDR_MODE_LONG)

#define sli_mac_flat_dest_short_address(packet, hasPhyHeader) \
  (sl_util_fetch_low_high_int16u((packet) + sli_mac_flat_dest_addr_offset((packet), (hasPhyHeader))))

#define sli_mac_flat_dest_long_address(packet, hasPhyHeader) \
  ((packet) + sli_mac_flat_dest_addr_offset((packet), (hasPhyHeader)))

// Source PAN ID
#define sli_mac_flat_src_panid_offset(packet, hasPhyHeader) \
  (sli_mac_flat_field_offset((packet), (hasPhyHeader), SL_ZIGBEE_PH_FIELD_MAC_HEADER_SRC_PAN_ID))

// 15.4-2011 - "This field shall be included in the MAC frame only if the Source
// Addressing Mode field is nonzero and the PAN ID Compression field is equal to
// zero".
#define sli_mac_flat_src_panid_present(packet, hasPhyHeader) \
  ((sli_mac_flat_src_addr_mode((packet), (hasPhyHeader))     \
    != SL_802154_HEADER_FC_SRC_ADDR_MODE_NONE)               \
   && !sli_mac_flat_panid_compressed((packet), (hasPhyHeader)))

#define sli_mac_flat_src_panid(packet, hasPhyHeader) \
  (sl_util_fetch_low_high_int16u((packet) + sli_mac_flat_src_panid_offset((packet), (hasPhyHeader))))

// Source address
#define sli_mac_flat_src_addr_offset(packet, hasPhyHeader) \
  (sli_mac_flat_field_offset((packet), (hasPhyHeader), SL_ZIGBEE_PH_FIELD_MAC_HEADER_SRC_ADDR))

// 15.4-2011 - "This field shall be included in the MAC frame only if the Source
// Addressing Mode field is nonzero".
#define sli_mac_flat_src_addr_present(packet, hasPhyHeader) \
  (sli_mac_flat_src_addr_mode((packet), (hasPhyHeader))     \
   != SL_802154_HEADER_FC_SRC_ADDR_MODE_NONE)

#define sli_mac_flat_src_addr_is_short(packet, hasPhyHeader) \
  (sli_mac_flat_src_addr_mode((packet), (hasPhyHeader))      \
   == SL_802154_HEADER_FC_SRC_ADDR_MODE_SHORT)

#define sli_mac_flat_src_addr_is_long(packet, hasPhyHeader) \
  (sli_mac_flat_src_addr_mode((packet), (hasPhyHeader))     \
   == SL_802154_HEADER_FC_SRC_ADDR_MODE_LONG)

#define sli_mac_flat_src_short_address(packet, hasPhyHeader) \
  (sl_util_fetch_low_high_int16u((packet) + sli_mac_flat_src_addr_offset((packet), (hasPhyHeader))))

#define sli_mac_flat_src_long_address(packet, hasPhyHeader) \
  ((packet) + sli_mac_flat_src_addr_offset((packet), (hasPhyHeader)))

// -----------------------------------------------------------------------------
// MAC auxiliary security header macros

#define sli_mac_flat_aux_security_header_offset(packet, hasPhyHeader) \
  (sli_mac_flat_field_offset((packet), (hasPhyHeader), SL_ZIGBEE_PH_FIELD_MAC_AUXILIARY_HEADER))

#define sli_mac_flat_aux_security_header_present(packet, hasPhyHeader) \
  (sli_mac_flat_security_enabled((packet), (hasPhyHeader)))

#define sli_mac_flat_aux_security_header(packet, hasPhyHeader) \
  ((packet) + sli_mac_flat_aux_security_header_offset((packet), (hasPhyHeader)))

#define sli_mac_flat_aux_security_control_offset(packet, hasPhyHeader) \
  (sli_mac_flat_field_offset((packet), (hasPhyHeader), SL_ZIGBEE_PH_FIELD_MAC_AUX_SECURITY_CONTROL))

#define sli_mac_flat_aux_security_control(packet, hasPhyHeader) \
  (*((packet) + sli_mac_flat_aux_security_control_offset((packet), (hasPhyHeader))))

#define sli_mac_flat_aux_security_frame_counter_offset(packet, hasPhyHeader) \
  (sli_mac_flat_field_offset((packet), (hasPhyHeader), SL_ZIGBEE_PH_FIELD_MAC_AUX_FRAME_COUNTER))

#define sli_mac_flat_aux_security_frame_counter(packet, hasPhyHeader) \
  (sl_util_fetch_low_high_int32u(((packet), (hasPhyHeader)) + sli_mac_flat_aux_security_frame_counter_offset((packet), (hasPhyHeader))))

#define sli_mac_flat_aux_security_level(packet, hasPhyHeader) \
  (sli_mac_flat_aux_security_control((packet), (hasPhyHeader)) & SL_802154_AUX_HEADER_SECURITY_LEVEL_MASK)

#define sli_mac_flat_aux_security_key_id_mode(packet, hasPhyHeader)                                      \
  ((sli_mac_flat_aux_security_control((packet), (hasPhyHeader)) & SL_802154_AUX_HEADER_KEY_ID_MODE_MASK) \
   >> SL_802154_AUX_HEADER_KEY_ID_MODE_OFFSET)

#define sli_mac_flat_aux_security_padding_size(packet, hasPhyHeader)                                      \
  ((sli_mac_flat_aux_security_control((packet), (hasPhyHeader)) & SL_802154_AUX_HEADER_PADDING_SIZE_MASK) \
   >> SL_802154_AUX_HEADER_PADDING_SIZE_OFFSET)

#define sli_mac_flat_aux_security_is_xxtea(packet, hasPhyHeader) \
  ((sli_mac_flat_aux_security_control((packet), (hasPhyHeader)) & SL_802154_AUX_HEADER_XXTEA_SECURITY_BIT) > 0)

#define sli_mac_flat_aux_security_is_aes(packet, hasPhyHeader) \
  (!sli_mac_flat_aux_security_is_xxtea((packet), (hasPhyHeader)))

// -----------------------------------------------------------------------------
// MAC payload macros and functions

uint8_t sli_mac_flat_field_offset(uint8_t *packet, bool hasPhyHeader, uint8_t field);

#define sli_mac_flat_payload_offset(packet, hasPhyHeader) \
  (sli_mac_flat_field_offset((packet), (hasPhyHeader), SL_ZIGBEE_PH_FIELD_MAC_PAYLOAD))

// TODO: Calculate payload length for a flat packet starting at the MAC header.
uint8_t sli_mac_flat_payload_length(uint8_t *phy_packet);

#define sli_mac_flat_payload(packet, hasPhyHeader) \
  ((packet) + sli_mac_flat_payload_offset((packet), (hasPhyHeader)))

#define SL_802154_PAYLOAD_COMMAND_ID_OFFSET   0

// -----------------------------------------------------------------------------
// MAC MIC macros

#define sli_mac_flat_mic_offset(packet, hasPhyHeader) \
  (sli_mac_flat_field_offset((packet), SL_ZIGBEE_PH_FIELD_MAC_MIC))

#define sli_mac_flat_mic(packet, hasPhyHeader) \
  (sl_util_fetch_low_high_int32u(((packet), (hasPhyHeader)) + sli_mac_flat_mic_offset((packet), (hasPhyHeader))))

#define SL_802154_SECURITY_MIC_SIZE           4
#define SL_802154_SECURITY_2006_ENC_MIC_32    5

#endif //MAC_FLAT_HEADER_H
