/****************************************************************************************************
* @file parsers.h
* @brief BNO08x frame parser definitions.
*
* @author Toby Godfrey
****************************************************************************************************/

#pragma once

#include "i2c.h"

/**
 * @brief Receives a raw frame and forwards it to the sensor-specific function
 * 
 * @param msg   The raw data frame
 */
void parse_msg(struct i2c_message msg);