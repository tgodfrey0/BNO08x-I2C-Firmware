/****************************************************************************************************
* @file bno08x.h
* @brief BNO08x related definitions.
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
	bool enabled;		/**< Whether the sensor has been configured and enabled. */
	union input_report input_report;		/**< Stores the retured data from the sensor. */
};

//=================================================================================================//
//    Functions
//=================================================================================================//

/**
 * @brief Enable a sensor and populate the struct pointer.
 *
 * @param id		The ID of the sensor to enable
 */
bool enable_sensor(const enum SENSOR_ID id);

/**
 * @brief Read a sensor and store the restult in the input report in the struct. 
 *
 * @param sensor		The sensor struct to read
 */ 
bool read_sensor(const struct sensor* sensor);