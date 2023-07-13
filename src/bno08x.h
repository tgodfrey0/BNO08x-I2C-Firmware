/**
 * @file bno08x.h
 * @author Toby Godfrey (me@tgodfrey.com)
 * @brief Defines the top level entities for the library.
 * @version 0.1
 * @date 2023-07-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @mainpage BNO08x I2C Library
 * 
 * This library is designed to be platform independent and allow for a microcontroller to communicate with a BNO08x sensor over I2C. 
 * 
 * @section instructions Instructions for Use
 * 
 * In order to use the library, several functions must be declared before use. These are the I2C functions found in the \ref i2c_interface "i2c_interface". The initialise function must also be run before any communication takes place.
 * 
 * A `MAX_PAYLOAD_SIZE` value must also be defined.
 * 
 * Before sensors can be read, the sensor initialisation function must be run (found in \ref sensors.h).
 */

/*! 
	\defgroup Enumerations Public enumeration types
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "i2c.h"
#include "sensors.h"
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

static enum SENSOR_ID last_received; 

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
	//const uint8_t channel;		/**< The channel the sensor communicates on. */
	union input_report input_report;		/**< Stores the returned data from the sensor. */
};

//=================================================================================================//
//    Functions
//=================================================================================================//

/**
 * @brief Turn on the sensor and open the channel.
 * 
 * This *must* be run before any other sensor operation.
 * 
 * @param i2c is the I2C interface to communicate with the sensor on
 */
void init(const struct i2c_interface i2c);

/**
 * @brief Enables a specified sensor with a fixed report rate.
 * 
 * @param i2c is the I2C interface to communicate with the sensor on
 * @param id is the ID of the sensor to enable
 * @param sample_rate_ms is the desired report rate in miliseconds 
 * @return `true` if the sensor was successfully enabled
 * @return `false` if the sensor could not be enabled
 */
bool enable_sensor(const struct i2c_interface i2c, enum SENSOR_ID id, uint32_t sample_rate_ms);

/**
 * @brief Read the latest sensor report on the bus.
 * 
 * @param i2c is the I2C interface to communicate with the sensor on
 * @return `true`	if the read was successful
 * @return `false` if an error occurred
 */
bool read_sensor(const struct i2c_interface i2c);

/**
 * @brief Get the sensor struct from a given ID.
 * 
 * @param id is the ID of the sensor
 * @return the sensor struct pointer
 */
struct sensor* get_sensor(enum SENSOR_ID id);

//=================================================================================================//
//		Sensor struct instances
//=================================================================================================//

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* accelerometer;

/**
 * @struct gyroscope
 * 
 * @brief The gyroscope instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* gyroscope;


/**
 * @struct magnetic_field
 * 
 * @brief The magnetic field instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* magnetic_field;

/**
 * @struct linear_acceleration
 * 
 * @brief The linear acceleration instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* linear_acceleration;

/**
 * @struct rotation_vector
 * 
 * @brief The rotation vector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* rotation_vector;

/**
 * @struct gravity
 * 
 * @brief The gravity instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* gravity;

/**
 * @struct uncalibrated_gyroscope
 * 
 * @brief The uncalibrated gyroscope instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* uncalibrated_gyroscope;

/**
 * @struct game_rotation_vector
 * 
 * @brief The game rotation vector instance instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* game_rotation_vector;

/**
 * @struct geomagnetic_rotation_vector
 * 
 * @brief The geomagnetic rotation vector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* geomagnetic_rotation_vector;

/**
 * @struct pressure
 * 
 * @brief The pressure instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* pressure;

/**
 * @struct ambient_light
 * 
 * @brief The ambient light instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* ambient_light;

/**
 * @struct humidity
 * 
 * @brief The humidity instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* humidity;

/**
 * @struct proximity
 * 
 * @brief The proximity instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* proximity;

/**
 * @struct temperature
 * 
 * @brief The temperature instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* temperature;

/**
 * @struct uncalibrated_magnetic_field
 * 
 * @brief The uncalibrated magnetic field instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* uncalibrated_magnetic_field;

/**
 * @struct tap_detector
 * 
 * @brief The tap_detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* tap_detector;

/**
 * @struct step_counter
 * 
 * @brief The step counter instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* step_counter;

/**
 * @struct significant_motion
 * 
 * @brief The significant motion instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* significant_motion;

/**
 * @struct stability_classifier
 * 
 * @brief The stability classifier instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* stability_classifier;

/**
 * @struct raw_accelerometer
 * 
 * @brief The raw accelerometer instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* raw_accelerometer;

/**
 * @struct raw_gyroscope
 * 
 * @brief The raw gyroscope instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* raw_gyroscope;

/**
 * @struct raw_magnetometer
 * 
 * @brief The raw magnetometer instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* raw_magnetometer;

/**
 * @struct step_detector
 * 
 * @brief The step detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* step_detector;

/**
 * @struct shake_detector
 * 
 * @brief The shake detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* shake_detector;

/**
 * @struct flip_detector
 * 
 * @brief The flip detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* flip_detector;

/**
 * @struct pickup_detector
 * 
 * @brief The pickup detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* pickup_detector;

/**
 * @struct stability_detector
 * 
 * @brief The stability detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* stability_detector;

/**
 * @struct personal_activity_classifier
 * 
 * @brief The personal activity classifier instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* personal_activity_classifier;

/**
 * @struct sleep_detector
 * 
 * @brief The sleep detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* sleep_detector;

/**
 * @struct tilt_detector
 * 
 * @brief The tilt detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* tilt_detector;

/**
 * @struct pocket_detector
 * 
 * @brief The pocket detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* pocket_detector;

/**
 * @struct circle_detector
 * 
 * @brief The circle detector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* circle_detector;

/**
 * @struct heart_rate_monitor
 * 
 * @brief The heart rate monitor instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* heart_rate_monitor;

/**
 * @struct arvr_stabilised_rotation_vector
 * 
 * @brief The ARVR stabilised rotation vector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* arvr_stabilised_rotation_vector;

/**
 * @struct arvr_stabilised_game_rotation_vector
 * 
 * @brief The ARVR stabilised game rotation vector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* arvr_stabilised_game_rotation_vector;

/**
 * @struct gyro_integrated_rotation_vector
 * 
 * @brief The gyro-integrated rotation vector instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* gyro_integrated_rotation_vector;

/**
 * @struct motion_request
 * 
 * @brief The motion request instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* motion_request;

/**
 * @struct dead_reckoning_pose
 * 
 * @brief The dead reckoning pose instance.
 * 
 * @ingroup Sensors
 */
extern struct sensor* dead_reckoning_pose;
