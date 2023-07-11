/****************************************************************************************************
* @file bno08x.h
* @brief BNO08x related definitions
*
* @author Toby Godfrey
****************************************************************************************************/


/*! 
	\defgroup Enumerations
		Public enumeration types
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "sensor_reports.h"

//=================================================================================================//
//		Enums
//=================================================================================================//

/**
 * @enum SENSOR_ID
 *
 * @ingroup Enumerations
 *
 * @brief Stores the ID for each sensor.
 */
enum SENSOR_ID {
	ACCELEROMETER = 0x01,
	GYROSCOPE = 0x02,
	MAGNETIC_FIELD = 0x03,
	LINEAR_ACCELERATION = 0x04,
	ROTATION_VECTOR = 0x05,
	GRAVITY = 0x06,
	UNCALIBRATED_GYROSCOPE = 0x07,
	GAME_ROTATION_VECTOR = 0x08,
	GEOMAGNETIC_ROTATION_VECTOR = 0x09,
	PRESSURE = 0x0A,
	AMBIENT_LIGHT = 0x0B,
	HUMIDITY = 0x0C,
	PROXIMITY = 0x0D,
	TEMPERATURE = 0x0E,
	UNCALIBRATED_MAGNETIC_FIELD = 0x0F,
	TAP_DETECTOR = 0x10,
	STEP_COUNTER = 0x11,
	SIGNIFICANT_MOTION = 0x12,
	STABILITY_CLASSIFIER = 0x13,
	RAW_ACCELEROMETER = 0x14,
	RAW_GYROSCOPE = 0x15,
	RAW_MAGNETOMETER = 0x16,
	RESERVED = 0x17,
	STEP_DETECTOR = 0x18,
	SHAKE_DETECTOR = 0x19,
	FLIP_DETECTOR = 0x1A,
	PICKUP_DETECTOR = 0x1B,
	STABILITY_DETECTOR = 0x1C,
	PERSONAL_ACTIVITY_CLASSIFIER = 0x1E,
	SLEEP_DETECTOR = 0x1F,
	TILT_DETECTOR = 0x20,
	POCKET_DETECTOR = 0x21,
	CIRCLE_DETECTOR = 0x22,
	HEART_RATE_MONITOR = 0x23,
	ARVR_STABILISED_ROTATION_VECTOR = 0x28,
	ARVR_STABILISED_GAME_ROTATION_VECTOR = 0x29,
	GYRO_INTEGRATED_ROTATION_VECTOR = 0x2A,
	MOTION_REQUEST = 0x2B,
	OPTICAL_FLOW = 0x2C,
	DEAD_RECKONING_POSE = 0x2D,
};

//=================================================================================================//
//    Structs
//=================================================================================================//

//**********************************************************************//
//    Struct Definition
//**********************************************************************//

/**
 * @struct sensor
 *
 * Stores the relevant data for a single sensor. A new struct must exist for each sensor in use.
 *
 * @brief Stores an instance of a single sensor.
 */ 
struct sensor {
	const char* name;		/**< A human-readable name for the sensor. Useful for outputting results. */
	const enum SENSOR_ID id;		/**< The sensor ID. This should be the same as the report_id in the report returned from the sensor. */
	const uint8_t channel;		/**< The channel the sensor communicates on. */
	const int8_t q_point;		/**< The Q point of the sensor. Values <0 indicate no Q point. */
	union input_report* input_report;		/**< Stores the retured data from the sensor. */
	bool enabled;		/**< Whether the sensor has been configured and enabled. */
};

//=================================================================================================//
//		Sensor Struct Declarations
//=================================================================================================//

const struct sensor* accelerometer;		/**< A pointer to the instance of the accelerometer. */
const struct sensor* gyroscope;		/**< A pointer to the instance of the gyroscope. */
const struct sensor* magnetic_field;		/**< A pointer to the instance of the magnetic_field. */
const struct sensor* linear_acceleration;		/**< A pointer to the instance of the linear_acceleration. */
const struct sensor* rotation_vector;		/**< A pointer to the instance of the rotation vector. */
const struct sensor* gravity;		/**< A pointer to the instance of the gravity. */
const struct sensor* uncalibrated_gyroscope;		/**< A pointer to the instance of the uncalibrated gyroscope. */
const struct sensor* game_rotation_vector;		/**< A pointer to the instance of the game rotation vector. */
const struct sensor* geomagnetic_rotation_vector;		/**< A pointer to the instance of the geomagnetic rotation vector. */
const struct sensor* pressure;		/**< A pointer to the instance of the pressure. */
const struct sensor* ambient_light;		/**< A pointer to the instance of the ambient light. */
const struct sensor* humidity;		/**< A pointer to the instance of the humidity. */
const struct sensor* proximity;		/**< A pointer to the instance of the proximity. */
const struct sensor* temperature;		/**< A pointer to the instance of the temperature. */
const struct sensor* uncalibrated_magnetic_field;		/**< A pointer to the instance of the uncalibrated magnetic field. */
const struct sensor* tap_detector;		/**< A pointer to the instance of the tap detector. */
const struct sensor* step_counter;		/**< A pointer to the instance of the step counter. */
const struct sensor* significant_motion;		/**< A pointer to the instance of the significant motion. */
const struct sensor* stability_classifier;		/**< A pointer to the instance of the stability classifier. */
const struct sensor* raw_accelerometer;		/**< A pointer to the instance of the raw accelerometer. */
const struct sensor* raw_gyroscope;		/**< A pointer to the instance of the raw gyroscope. */
const struct sensor* raw_magnetometer;		/**< A pointer to the instance of the raw magnetometer. */
const struct sensor* step_detector;		/**< A pointer to the instance of the step detector. */
const struct sensor* shake_detector;		/**< A pointer to the instance of the shake detector. */
const struct sensor* flip_detector;		/**< A pointer to the instance of the flip detector. */
const struct sensor* pickup_detector;		/**< A pointer to the instance of the pickup detector. */
const struct sensor* stability_detector;		/**< A pointer to the instance of the stability detector. */
const struct sensor* personal_activity_classifier;		/**< A pointer to the instance of the personal activity classifier. */
const struct sensor* sleep_detector;		/**< A pointer to the instance of the sleep detector. */
const struct sensor* tilt_detector;		/**< A pointer to the instance of the tilt detector. */
const struct sensor* pocket_detector;		/**< A pointer to the instance of the pocket detector. */
const struct sensor* circle_detector;		/**< A pointer to the instance of the circle detector. */
const struct sensor* heart_rate_monitor;		/**< A pointer to the instance of the heart rate monitor. */
const struct sensor* arvr_stabilised_rotation_vector;		/**< A pointer to the instance of the ARVR stabilised rotation vector. */
const struct sensor* arvr_stabilised_game_rotation_vector;		/**< A pointer to the instance of the ARVR stabilised game rotation vector. */
const struct sensor* gyro_integrated_rotation_vector;		/**< A pointer to the instance of the gyro-integrated rotation vector. */
const struct sensor* motion_request;		/**< A pointer to the instance of the motion request. */
const struct sensor* optical_flow;		/**< A pointer to the instance of the optical flow. */
const struct sensor* dead_reckoning_pose;		/**< A pointer to the instance of the dead reckoning pose. */

//=================================================================================================//
//    Functions
//=================================================================================================//

/**
 * @brief Enable a sensor and populate the struct pointer.
 *
 * @param[in] SENSOR_ID		The ID of the sensor to enable
 */
bool enable_sensor(const SENSOR_ID);
