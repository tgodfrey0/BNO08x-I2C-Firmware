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
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_accelerometer_data(struct sensor_collection* sc);

/**
 * @brief Output the gyroscope data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_gyroscope_data(struct sensor_collection* sc);

/**
 * @brief Output the magnetic field data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_magnetic_field_data(struct sensor_collection* sc);

/**
 * @brief Output the linear accelerometer data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_linear_acceleration_data(struct sensor_collection* sc);

/**
 * @brief Output the rotation vector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_rotation_vector_data(struct sensor_collection* sc);

/**
 * @brief Output the gravity data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_gravity_data(struct sensor_collection* sc);

/**
 * @brief Output the uncalibrated gyroscope data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_uncalibrated_gyroscope_data(struct sensor_collection* sc);

/**
 * @brief Output the game rotation vector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_game_rotation_vector_data(struct sensor_collection* sc);

/**
 * @brief Output the geomagnetic rotation vector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_geomagnetic_rotation_vector_data(struct sensor_collection* sc);

/**
 * @brief Output the pressure data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_pressure_data(struct sensor_collection* sc);

/**
 * @brief Output the ambient light data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_ambient_light_data(struct sensor_collection* sc);

/**
 * @brief Output the humidity data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_humidity_data(struct sensor_collection* sc);

/**
 * @brief Output the proximity data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_proximity_data(struct sensor_collection* sc);

/**
 * @brief Output the temperature data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_temperature_data(struct sensor_collection* sc);

/**
 * @brief Output the uncalibrated magnetic field data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_uncalibrated_magnetic_field_data(struct sensor_collection* sc);

/**
 * @brief Output the tap detector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_tap_detector_data(struct sensor_collection* sc);

/**
 * @brief Output the step counter data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_step_counter_data(struct sensor_collection* sc);

/**
 * @brief Output the significant motion data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_significant_motion_data(struct sensor_collection* sc);

/**
 * @brief Output the stability classifier data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_stability_classifier_data(struct sensor_collection* sc);

/**
 * @brief Output the raw accelerometer data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_raw_accelerometer_data(struct sensor_collection* sc);

/**
 * @brief Output the raw gyroscope data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_raw_gyroscope_data(struct sensor_collection* sc);

/**
 * @brief Output the raw magnetometer data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_raw_magnetometer_data(struct sensor_collection* sc);

/**
 * @brief Output the step detector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_step_detector_data(struct sensor_collection* sc);

/**
 * @brief Output the shake detector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_shake_detector_data(struct sensor_collection* sc);

/**
 * @brief Output the flip detector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_flip_detector_data(struct sensor_collection* sc);

/**
 * @brief Output the pickup detector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_pickup_detector_data(struct sensor_collection* sc);

/**
 * @brief Output the stability detector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_stability_detector_data(struct sensor_collection* sc);

/**
 * @brief Output the personal activity classifier data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_personal_activity_classifier_data(struct sensor_collection* sc);

/**
 * @brief Output the sleep detector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_sleep_detector_data(struct sensor_collection* sc);

/**
 * @brief Output the tilt detector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_tilt_detector_data(struct sensor_collection* sc);

/**
 * @brief Output the pocket detector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_pocket_detector_data(struct sensor_collection* sc);

/**
 * @brief Output the circle detector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_circle_detector_data(struct sensor_collection* sc);

/**
 * @brief Output the heart rate monitor data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_heart_rate_monitor_data(struct sensor_collection* sc);

/**
 * @brief Output the ARVR stabilised rotation vector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_arvr_stabilised_rotation_vector_data(struct sensor_collection* sc);

/**
 * @brief Output the ARVR stabilised game rotation vector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_arvr_stabilised_game_rotation_vector_data(struct sensor_collection* sc);

/**
 * @brief Output the gyro-integrated rotation vector data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_gyro_integrated_rotation_vector_data(struct sensor_collection* sc);

/**
 * @brief Output the motion request data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_motion_request_data(struct sensor_collection* sc);

/**
 * @brief Output the dead reckoning pose data to `stdout`.
 * 
 * @param sc is the pointer to the `sensor_collection` struct
 * 
 */
void print_dead_reckoning_pose_data(struct sensor_collection* sc);