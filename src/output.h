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

//=================================================================================================//
//    Sensor Print Functions
//=================================================================================================//

/**
 * @brief Output the accelerometer data to `stdout`.
 * 
 */
void print_accelerometer_data();

/**
 * @brief Output the gyroscope data to `stdout`.
 * 
 */
void print_gyroscope_data();

/**
 * @brief Output the magnetic field data to `stdout`.
 * 
 */
void print_magnetic_field_data();

/**
 * @brief Output the linear accelerometer data to `stdout`.
 * 
 */
void print_linear_acceleration_data();

/**
 * @brief Output the rotation vector data to `stdout`.
 * 
 */
void print_rotation_vector_data();

/**
 * @brief Output the gravity data to `stdout`.
 * 
 */
void print_gravity_data();

/**
 * @brief Output the uncalibrated gyroscope data to `stdout`.
 * 
 */
void print_uncalibrated_gyroscope_data();

/**
 * @brief Output the game rotation vector data to `stdout`.
 * 
 */
void print_game_rotation_vector_data();

/**
 * @brief Output the geomagnetic rotation vector data to `stdout`.
 * 
 */
void print_geomagnetic_rotation_vector_data();

/**
 * @brief Output the pressure data to `stdout`.
 * 
 */
void print_pressure_data();

/**
 * @brief Output the ambient light data to `stdout`.
 * 
 */
void print_ambient_light_data();

/**
 * @brief Output the humidity data to `stdout`.
 * 
 */
void print_humidity_data();

/**
 * @brief Output the proximity data to `stdout`.
 * 
 */
void print_proximity_data();

/**
 * @brief Output the temperature data to `stdout`.
 * 
 */
void print_temperature_data();

/**
 * @brief Output the uncalibrated magnetic field data to `stdout`.
 * 
 */
void print_uncalibrated_magnetic_field_data();

/**
 * @brief Output the tap detector data to `stdout`.
 * 
 */
void print_tap_detector_data();

/**
 * @brief Output the step counter data to `stdout`.
 * 
 */
void print_step_counter_data();

/**
 * @brief Output the significant motion data to `stdout`.
 * 
 */
void print_significant_motion_data();

/**
 * @brief Output the stability classifier data to `stdout`.
 * 
 */
void print_stability_classifier_data();

/**
 * @brief Output the raw accelerometer data to `stdout`.
 * 
 */
void print_raw_accelerometer_data();

/**
 * @brief Output the raw gyroscope data to `stdout`.
 * 
 */
void print_raw_gyroscope_data();

/**
 * @brief Output the raw magnetometer data to `stdout`.
 * 
 */
void print_raw_magnetometer_data();

/**
 * @brief Output the step detector data to `stdout`.
 * 
 */
void print_step_detector_data();

/**
 * @brief Output the shake detector data to `stdout`.
 * 
 */
void print_shake_detector_data();

/**
 * @brief Output the flip detector data to `stdout`.
 * 
 */
void print_flip_detector_data();

/**
 * @brief Output the pickup detector data to `stdout`.
 * 
 */
void print_pickup_detector_data();

/**
 * @brief Output the stability detector data to `stdout`.
 * 
 */
void print_stability_detector_data();

/**
 * @brief Output the personal activity classifier data to `stdout`.
 * 
 */
void print_personal_activity_classifier_data();

/**
 * @brief Output the sleep detector data to `stdout`.
 * 
 */
void print_sleep_detector_data();

/**
 * @brief Output the tilt detector data to `stdout`.
 * 
 */
void print_tilt_detector_data();

/**
 * @brief Output the pocket detector data to `stdout`.
 * 
 */
void print_pocket_detector_data();

/**
 * @brief Output the circle detector data to `stdout`.
 * 
 */
void print_circle_detector_data();

/**
 * @brief Output the heart rate monitor data to `stdout`.
 * 
 */
void print_heart_rate_monitor_data();

/**
 * @brief Output the ARVR stabilised rotation vector data to `stdout`.
 * 
 */
void print_arvr_stabilised_rotation_vector_data();

/**
 * @brief Output the ARVR stabilised game rotation vector data to `stdout`.
 * 
 */
void print_arvr_stabilised_game_rotation_vector_data();

/**
 * @brief Output the gyro-integrated rotation vector data to `stdout`.
 * 
 */
void print_gyro_integrated_rotation_vector_data();

/**
 * @brief Output the motion request data to `stdout`.
 * 
 */
void print_motion_request_data();

/**
 * @brief Output the dead reckoning pose data to `stdout`.
 * 
 */
void print_dead_reckoning_pose_data();