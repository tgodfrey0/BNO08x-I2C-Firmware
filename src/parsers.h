/**
 * @file parsers.h
 * @author Toby Godfrey (me@tgodfrey.com)
 * @brief BNO08x data frame parser definitions.
 * @version 0.1
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "i2c.h"

/**
 * @brief Parses a raw sensor data frame into the relevant sensor struct.
 * 
 * @param msg is the raw sensor data frame received from the sensor
 * @return true if the message was successfully parsed
 * @return false if the message could not be parsed
 */
bool parse_sensor_msg(struct i2c_message msg);

/**
 * @brief Parses a raw command response frame into the relevant sensor struct.
 * 
 * @param msg is the raw command response frame received from the sensor
 * @return true if the message was successfully parsed
 * @return false if the message could not be parsed
 */
bool parse_cmd_res_msg(struct i2c_message msg);

/**
 * @brief Parses a raw get feature response frame into the relevant sensor struct.
 * 
 * @param msg is the raw get feature response frame received from the sensor
 * @return true if the message was successfully parsed
 * @return false if the message could not be parsed
 */
bool parse_get_feat_res_msg(struct i2c_message msg);

/**
 * @brief Scale a value relative to the sensor's Q point.
 * 
 * @param q is the Q point of the sensor
 * @return The proportional scale value
 */
float scale_q(uint8_t q);