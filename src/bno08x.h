/****************************************************************************************************
* @file bno08x.h
* @brief BNO08x related definitions.
*
* @author Toby Godfrey
****************************************************************************************************/

/**
 * @mainpage BNO08x I2C Library
 * 
 * This library is designed to be platform independent and allow for a microcontroller to communicate with a BNO08x sensor over I2C. 
 * 
 * @section instructions Instructions for Use
 * 
 * In order to use the library, several functions must be declared before use. These are the I2C functions found in the \ref i2c_interface. The initialise function must also be run before any communication takes place.
 * 
 * A `MAX_PAYLOAD_SIZE` value must also be defined.
 * 
 * Before sensors can be read, the \ref init_sensors function must be run.
 */

/*! 
	\defgroup Enumerations Public enumeration types
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "i2c.h"
#include "sensor_reports.h"

//=================================================================================================//
//		Enums
//=================================================================================================//

/**
 * @enum SENSOR_ID
 *
 * @brief Stores the ID for each sensor.
 * 
 * @ingroup Enumerations
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
	union input_report input_report;		/**< Stores the returned data from the sensor. */
};

//=================================================================================================//
//    Functions
//=================================================================================================//

/**
 * @fn enable_sensor
 * 
 * @brief Enable a sensor and populate the struct pointer.
 *
 * @param i2c		The I2C interface struct to send the data on
 * @param sensor		The sensor to enable
 * @param sample_rate_ms		The sample rate of the sensor in microseconds
 */
bool enable_sensor(const struct i2c_interface i2c, struct sensor* sensor, uint32_t sample_rate_ms);

/**
 * @fn read_sensor
 * 
 * @brief Read the next sensor message on the bus and store the result in the input report in the struct. 
 *
 * @param i2c		The I2C interface struct to send the data on
 */ 
bool read_sensor(const struct i2c_interface i2c);
