/**
 * @file output.h
 * @author Toby Godfrey (me@tgodfrey.com)
 * @brief Functions to print data to `stdout`.
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

/**
 * @brief Outputs the data from the last received frame to `stdout`.
 * 
 */
void print_last_frame();

/**
 * @brief Outputs a raw command response frame to `stdout`.
 * 
 * @param msg is the raw command response frame received from the sensor
 */
void print_raw_cmd_res_msg(struct i2c_message msg);

/**
 * @brief Outputs a raw get feature response frame to `stdout`.
 * 
 * @param msg is the raw get feature response frame received from the sensor
 */
void print_raw_get_feat_res_msg(struct i2c_message msg);