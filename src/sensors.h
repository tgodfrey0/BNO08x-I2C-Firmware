/****************************************************************************************************
* @file sensors.h
* @brief Global sensor struct instances.
*
* @author Toby Godfrey
****************************************************************************************************/

#pragma once

#include "bno08x.h"
#include "sensor_reports.h"

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
extern struct sensor accelerometer;

/**
 * @struct gyroscope
 * 
 * @brief The gyroscope instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor gyroscope;


/**
 * @struct magnetic_field
 * 
 * @brief The magnetic field instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor magnetic_field;

/**
 * @struct linear_acceleration
 * 
 * @brief The linear acceleration instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor linear_acceleration;

/**
 * @struct rotation_vector
 * 
 * @brief The rotation vector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor rotation_vector;

/**
 * @struct gravity
 * 
 * @brief The gravity instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor gravity;

/**
 * @struct uncalibrated_gyroscope
 * 
 * @brief The uncalibrated gyroscope instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor uncalibrated_gyroscope;

/**
 * @struct game_rotation_vector
 * 
 * @brief The game rotation vector instance instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor game_rotation_vector;

/**
 * @struct geomagnetic_rotation_vector
 * 
 * @brief The geomagnetic rotation vector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor geomagnetic_rotation_vector;

/**
 * @struct pressure
 * 
 * @brief The pressure instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor pressure;

/**
 * @struct ambient_light
 * 
 * @brief The ambient light instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor ambient_light;

/**
 * @struct humidity
 * 
 * @brief The humidity instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor humidity;

/**
 * @struct proximity
 * 
 * @brief The proximity instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor proximity;

/**
 * @struct temperature
 * 
 * @brief The temperature instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor temperature;

/**
 * @struct uncalibrated_magnetic_field
 * 
 * @brief The uncalibrated magnetic field instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor uncalibrated_magnetic_field;

/**
 * @struct tap_detector
 * 
 * @brief The tap_detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor tap_detector;

/**
 * @struct step_counter
 * 
 * @brief The step counter instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor step_counter;

/**
 * @struct significant_motion
 * 
 * @brief The significant motion instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor significant_motion;

/**
 * @struct stability_classifier
 * 
 * @brief The stability classifier instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor stability_classifier;

/**
 * @struct raw_accelerometer
 * 
 * @brief The raw accelerometer instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor raw_accelerometer;

/**
 * @struct raw_gyroscope
 * 
 * @brief The raw gyroscope instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor raw_gyroscope;

/**
 * @struct raw_magnetometer
 * 
 * @brief The raw magnetometer instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor raw_magnetometer;

/**
 * @struct step_detector
 * 
 * @brief The step detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor step_detector;

/**
 * @struct shake_detector
 * 
 * @brief The shake detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor shake_detector;

/**
 * @struct flip_detector
 * 
 * @brief The flip detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor flip_detector;

/**
 * @struct pickup_detector
 * 
 * @brief The pickup detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor pickup_detector;

/**
 * @struct stability_detector
 * 
 * @brief The stability detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor stability_detector;

/**
 * @struct personal_activity_classifier
 * 
 * @brief The personal activity classifier instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor personal_activity_classifier;

/**
 * @struct sleep_detector
 * 
 * @brief The sleep detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor sleep_detector;

/**
 * @struct tilt_detector
 * 
 * @brief The tilt detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor tilt_detector;

/**
 * @struct pocket_detector
 * 
 * @brief The pocket detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor pocket_detector;

/**
 * @struct circle_detector
 * 
 * @brief The circle detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor circle_detector;

/**
 * @struct heart_rate_monitor
 * 
 * @brief The heart rate monitor instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor heart_rate_monitor;

/**
 * @struct arvr_stabilised_rotation_vector
 * 
 * @brief The ARVR stabilised rotation vector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor arvr_stabilised_rotation_vector;

/**
 * @struct arvr_stabilised_game_rotation_vector
 * 
 * @brief The ARVR stabilised game rotation vector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor arvr_stabilised_game_rotation_vector;

/**
 * @struct gyro_integrated_rotation_vector
 * 
 * @brief The gyro-integrated rotation vector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor gyro_integrated_rotation_vector;

/**
 * @struct motion_request
 * 
 * @brief The motion request instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor motion_request;

/**
 * @struct dead_reckoning_pose
 * 
 * @brief The dead reckoning pose instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor dead_reckoning_pose;

//=================================================================================================//
//		Functions
//=================================================================================================//

/**
 * @brief Initialise the struct for each sensor.
 * 
 * This function populates the struct for each sensor with default value. This should be run once before any other operations.
 * 
 */
void init_sensors();

