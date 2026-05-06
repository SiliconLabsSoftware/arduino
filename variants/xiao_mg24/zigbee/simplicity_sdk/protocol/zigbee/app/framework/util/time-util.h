/***************************************************************************//**
 * @file
 * @brief
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

#ifndef __TIME_UTIL_H__
#define __TIME_UTIL_H__

#define SECONDS_IN_MINUTE (60u)
#define SECONDS_IN_HOUR (3600u)
#define SECONDS_IN_DAY   (SECONDS_IN_MINUTE * 60u * 24u)
#define SECONDS_IN_WEEK  (SECONDS_IN_DAY * 7u)
#define DURATION_FOREVER_U32  0xFFFFFFFFU

/**
 * @brief ZCL Date comparison function.
 * The results are undefined for dates that contain the do not care value
 * in any of the subfields.
 * @return -1, if val1 is smaller
 *          0, if they are the same
 *          1, if val2 is smaller
 */
int8_t sl_zigbee_af_compare_dates(sl_zigbee_af_date_t* date1, sl_zigbee_af_date_t* date2);

/**
 * @brief function that copies a ZigBee Date into a buffer
 */
void sl_zigbee_af_copy_date(uint8_t *data, uint16_t index, sl_zigbee_af_date_t *src);

/**
 * @brief Decode the given uint32_t into a ZCL Date object where
 * the uint32_t is formatted as follows:
 *
 * (0xFF000000 & value) = year
 * (0x00FF0000 & value) = month
 * (0x0000FF00 & value) = day of month
 * (0x000000FF & value) = day of week
 *
 */
void sl_zigbee_af_decode_date(uint32_t src, sl_zigbee_af_date_t* dest);

/**
 * @brief Encode and return the given ZCL Date object as an uint32_t.
 * Refer to sl_zigbee_af_decode_date for details on how the information is stored
 * within an uint32_t.
 */
uint32_t sl_zigbee_af_encode_date(sl_zigbee_af_date_t* date);

/**
 * @brief Fills the a time structure based on the passed UTC time.
 *
 */
void sl_zigbee_af_fill_time_struct_from_utc(uint32_t utcTime,
                                            sl_zigbee_af_time_struct_t* returnTime);
/**
 * @brief Returns the number of days in the month specified in the sl_zigbee_af_time_struct_t.
 *
 */
uint8_t sl_zigbee_af_get_number_days_in_month(sl_zigbee_af_time_struct_t *time);

/**
 * @brief Calculate a UTC time from the passed time structure.
 *
 */
uint32_t sl_zigbee_af_get_utc_from_time_struct(sl_zigbee_af_time_struct_t *time);

/**
 * @brief Determine the week day (Monday=0 ... Sunday=6) based on
 * a specified UTC time.
 */
uint8_t sl_zigbee_af_get_weekday_from_utc(uint32_t utcTime);

/*
 * @brief Prints out a human readable date form from the given ZCL data type.
 */
void sl_zigbee_af_print_date(const sl_zigbee_af_date_t * date);
void sl_zigbee_af_print_dateln(const sl_zigbee_af_date_t * date);

/**
 * @brief Sets current time.
 * Convenience function for setting the time to a value.
 * If the time server cluster is implemented on this device,
 * then this call will be passed along to the time cluster server
 * which will update the time. Otherwise the sl_zigbee_af_set_time_cb
 * is called, which in the case of the stub does nothing.
 *
 * @param utcTime: A ZigBee time, the number of seconds since the
 *                 year 2000.
 */
void sl_zigbee_af_set_time(uint32_t utcTime);

/**
 * @brief Retrieves current time.
 *
 * Convienience function for retrieving the current time.
 * If the time server cluster is implemented, then the time
 * is retrieved from that cluster's time attribute. Otherwise,
 * the sl_zigbee_af_get_current_time_cb is called.
 *
 * A real time is expected to in the ZigBee time format, the number
 * of seconds since the year 2000.
 */
uint32_t sl_zigbee_af_get_current_time(void);

/**
 * @brief Prints time.
 *
 * Convenience function for all clusters to print time.
 * This function expects to be passed a ZigBee time which
 * is the number of seconds since the year 2000. If
 * SL_ZIGBEE_AF_PRINT_CORE is defined, this function will print
 * a human readable time from the passed value. If not, this
 * function will print nothing.
 *
 * @param utcTime: A ZigBee time, the number of seconds since the
 *                 year 2000.
 */
void sl_zigbee_af_print_time(uint32_t utcTime);

/**
 * @brief Prints the time in ISO 8601 format
 * yyyy-mm-dd hh:mm:ss
 *
 * @param utcTime: A ZigBee time, the number of seconds since the
 *                 year 2000.
 */
void sl_zigbee_af_print_time_iso_format(uint32_t utcTime);

#endif // __TIME_UTIL_H__
