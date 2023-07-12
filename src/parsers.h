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
 * @brief Parses a raw data frame into the relevant sensor struct.
 * 
 * @param msg is the raw frame received from the sensor
 */
void parse_msg(struct i2c_message msg);