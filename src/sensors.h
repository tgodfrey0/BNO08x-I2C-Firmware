/**
 * @file sensors.h
 * @author Toby Godfrey (me@tgodfrey.com)
 * @brief Sensor related definitions.
 * @version 0.1
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <stddef.h>

#include "bno08x.h"

/*! 
	\defgroup Sensors Sensor instances
*/

//=================================================================================================//
//		Sensor Struct Declarations
//=================================================================================================//

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
struct sensor* accelerometer = NULL;

/**
 * @struct gyroscope
 * 
 * @brief The gyroscope instance.
 * 
 * @ingroup Sensors
 */
struct sensor* gyroscope = NULL;


/**
 * @struct magnetic_field
 * 
 * @brief The magnetic field instance.
 * 
 * @ingroup Sensors
 */
struct sensor* magnetic_field = NULL;

/**
 * @struct linear_acceleration
 * 
 * @brief The linear acceleration instance.
 * 
 * @ingroup Sensors
 */
struct sensor* linear_acceleration = NULL;

/**
 * @struct rotation_vector
 * 
 * @brief The rotation vector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* rotation_vector = NULL;

/**
 * @struct gravity
 * 
 * @brief The gravity instance.
 * 
 * @ingroup Sensors
 */
struct sensor* gravity = NULL;

/**
 * @struct uncalibrated_gyroscope
 * 
 * @brief The uncalibrated gyroscope instance.
 * 
 * @ingroup Sensors
 */
struct sensor* uncalibrated_gyroscope = NULL;

/**
 * @struct game_rotation_vector
 * 
 * @brief The game rotation vector instance instance.
 * 
 * @ingroup Sensors
 */
struct sensor* game_rotation_vector = NULL;

/**
 * @struct geomagnetic_rotation_vector
 * 
 * @brief The geomagnetic rotation vector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* geomagnetic_rotation_vector = NULL;

/**
 * @struct pressure
 * 
 * @brief The pressure instance.
 * 
 * @ingroup Sensors
 */
struct sensor* pressure = NULL;

/**
 * @struct ambient_light
 * 
 * @brief The ambient light instance.
 * 
 * @ingroup Sensors
 */
struct sensor* ambient_light = NULL;

/**
 * @struct humidity
 * 
 * @brief The humidity instance.
 * 
 * @ingroup Sensors
 */
struct sensor* humidity = NULL;

/**
 * @struct proximity
 * 
 * @brief The proximity instance.
 * 
 * @ingroup Sensors
 */
struct sensor* proximity = NULL;

/**
 * @struct temperature
 * 
 * @brief The temperature instance.
 * 
 * @ingroup Sensors
 */
struct sensor* temperature = NULL;

/**
 * @struct uncalibrated_magnetic_field
 * 
 * @brief The uncalibrated magnetic field instance.
 * 
 * @ingroup Sensors
 */
struct sensor* uncalibrated_magnetic_field = NULL;

/**
 * @struct tap_detector
 * 
 * @brief The tap_detector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* tap_detector = NULL;

/**
 * @struct step_counter
 * 
 * @brief The step counter instance.
 * 
 * @ingroup Sensors
 */
struct sensor* step_counter = NULL;

/**
 * @struct significant_motion
 * 
 * @brief The significant motion instance.
 * 
 * @ingroup Sensors
 */
struct sensor* significant_motion = NULL;

/**
 * @struct stability_classifier
 * 
 * @brief The stability classifier instance.
 * 
 * @ingroup Sensors
 */
struct sensor* stability_classifier = NULL;

/**
 * @struct raw_accelerometer
 * 
 * @brief The raw accelerometer instance.
 * 
 * @ingroup Sensors
 */
struct sensor* raw_accelerometer = NULL;

/**
 * @struct raw_gyroscope
 * 
 * @brief The raw gyroscope instance.
 * 
 * @ingroup Sensors
 */
struct sensor* raw_gyroscope = NULL;

/**
 * @struct raw_magnetometer
 * 
 * @brief The raw magnetometer instance.
 * 
 * @ingroup Sensors
 */
struct sensor* raw_magnetometer = NULL;

/**
 * @struct step_detector
 * 
 * @brief The step detector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* step_detector = NULL;

/**
 * @struct shake_detector
 * 
 * @brief The shake detector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* shake_detector = NULL;

/**
 * @struct flip_detector
 * 
 * @brief The flip detector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* flip_detector = NULL;

/**
 * @struct pickup_detector
 * 
 * @brief The pickup detector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* pickup_detector = NULL;

/**
 * @struct stability_detector
 * 
 * @brief The stability detector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* stability_detector = NULL;

/**
 * @struct personal_activity_classifier
 * 
 * @brief The personal activity classifier instance.
 * 
 * @ingroup Sensors
 */
struct sensor* personal_activity_classifier = NULL;

/**
 * @struct sleep_detector
 * 
 * @brief The sleep detector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* sleep_detector = NULL;

/**
 * @struct tilt_detector
 * 
 * @brief The tilt detector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* tilt_detector = NULL;

/**
 * @struct pocket_detector
 * 
 * @brief The pocket detector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* pocket_detector = NULL;

/**
 * @struct circle_detector
 * 
 * @brief The circle detector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* circle_detector = NULL;

/**
 * @struct heart_rate_monitor
 * 
 * @brief The heart rate monitor instance.
 * 
 * @ingroup Sensors
 */
struct sensor* heart_rate_monitor = NULL;

/**
 * @struct arvr_stabilised_rotation_vector
 * 
 * @brief The ARVR stabilised rotation vector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* arvr_stabilised_rotation_vector = NULL;

/**
 * @struct arvr_stabilised_game_rotation_vector
 * 
 * @brief The ARVR stabilised game rotation vector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* arvr_stabilised_game_rotation_vector = NULL;

/**
 * @struct gyro_integrated_rotation_vector
 * 
 * @brief The gyro-integrated rotation vector instance.
 * 
 * @ingroup Sensors
 */
struct sensor* gyro_integrated_rotation_vector = NULL;

/**
 * @struct motion_request
 * 
 * @brief The motion request instance.
 * 
 * @ingroup Sensors
 */
struct sensor* motion_request = NULL;

/**
 * @struct dead_reckoning_pose
 * 
 * @brief The dead reckoning pose instance.
 * 
 * @ingroup Sensors
 */
struct sensor* dead_reckoning_pose = NULL;