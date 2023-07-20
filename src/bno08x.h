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
 * @mainpage Overview
 * 
 * This library is designed to be platform independent and allow for a microcontroller to communicate with a BNO08x sensor over I2C.
 * 
 * - \ref pcbs
 * 
 * - \ref gs
 *
 */

/**
 * @page pcbs Hardware Designs
 * 
 * PCB designs can be found [on my GitHub](https://github.com/tgodfrey0/BNO085-I2C-PCBs).
 * 
 * Several PCBs were created to use the BNO08x sensor. The main driving force behind these designs is the eventual use in tactile sensing modules, therefore the PCBs were designed to be as small as possible.
 * 
 * A more generic rectangular version exists within the designs.
 * 
 */

/**
 * @page gs Getting Started
 * 
 * In order to use the library, several functions must be declared before use. These are the I2C functions found in the \ref i2c_interface "i2c_interface". The initialise function must also be run before any communication takes place.
 * 
 * A `MAX_PAYLOAD_SIZE` value must also be defined.
 * 
 * Before sensors can be read, the sensor must be enabled (found in \ref sensors.h).
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "i2c.h"
#include "sensor_reports.h"

#define OPEN_ATTEMPTS		5u /**< The number of tries to open a channel to the sensor. */
#define min(a,b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; }) /**< Macro to return the smaller of two numbers. */
#define HEADER_SIZE		4u /**< The number of bytes used for the header. */
#define TIMEBASE_SIZE		5u /**< The number of bytes used for the timebase reference. */

//=================================================================================================//
//		Enums
//=================================================================================================//

/**
 * @enum REPORT_ID
 *
 * @brief Stores the ID for each sensor.
 * 
 * @ingroup Enumerations
 */
enum REPORT_ID {
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
	CMD_RESPONSE = 0xF1,
	CMD_REQUEST = 0xF2,
	TIMEBASE = 0xFB,
	GET_FEATURE_RESPONSE = 0xFC,
	SET_FEATURE_COMMAND = 0xFD,
	GET_FEATURE_REQUEST = 0xFE
};

// static enum REPORT_ID last_received; 

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
	const enum REPORT_ID id;		/**< The sensor ID. This should be the same as the report_id in the report returned from the sensor. */
	//const uint8_t channel;		/**< The channel the sensor communicates on. */
	bool enabled;		/**< Boolean flag as to whether the sensor has been enabled. */
	union input_report input_report;		/**< Stores the returned data from the sensor. */
};

/**
 * @struct sensor_collection
 * 
 * @brief Stores the collection of sensors.
 * 
 * Stores a struct for each sensor.
 * 
 */
struct sensor_collection {
	struct sensor accelerometer;    /**< Stores the accelerometer sensor struct. */
  struct sensor gyroscope;    /**< Stores the gyroscope sensor struct. */
  struct sensor magnetic_field;    /**< Stores the magnetic field sensor struct. */
  struct sensor linear_acceleration;    /**< Stores the linear acceleration sensor struct. */
  struct sensor rotation_vector;    /**< Stores the rotation vector sensor struct. */
  struct sensor gravity;    /**< Stores the gravity sensor struct. */
  struct sensor uncalibrated_gyroscope;    /**< Stores the uncalibrated gyroscope sensor struct. */
  struct sensor game_rotation_vector;    /**< Stores the game rotation vector sensor struct. */
  struct sensor geomagnetic_rotation_vector;    /**< Stores the geomagnetic rotation vector sensor struct. */
  struct sensor pressure;    /**< Stores the pressure sensor struct. */
  struct sensor ambient_light;    /**< Stores the ambient light sensor struct. */
  struct sensor humidity;    /**< Stores the humidity sensor struct. */
  struct sensor proximity;    /**< Stores the proximity sensor struct. */
  struct sensor temperature;    /**< Stores the temperature sensor struct. */
  struct sensor uncalibrated_magnetic_field;    /**< Stores the uncalibrated magnetic field sensor struct. */
  struct sensor tap_detector;    /**< Stores the tap detector sensor struct. */
  struct sensor step_counter;    /**< Stores the step counter sensor struct. */
  struct sensor significant_motion;    /**< Stores the significant motion sensor struct. */
  struct sensor stability_classifier;    /**< Stores the stability classifier sensor struct. */
  struct sensor raw_accelerometer;    /**< Stores the raw accelerometer sensor struct. */
  struct sensor raw_gyroscope;    /**< Stores the raw gyroscope sensor struct. */
  struct sensor raw_magnetometer;    /**< Stores the raw magnetometer sensor struct. */
  struct sensor step_detector;    /**< Stores the step detector sensor struct. */
  struct sensor shake_detector;    /**< Stores the shake detector sensor struct. */
  struct sensor flip_detector;    /**< Stores the flip detector sensor struct. */
  struct sensor pickup_detector;    /**< Stores the pickup detector sensor struct. */
  struct sensor stability_detector;    /**< Stores the stability detector sensor struct. */
  struct sensor personal_activity_classifier;    /**< Stores the personal activity classifier sensor struct. */
  struct sensor sleep_detector;    /**< Stores the sleep detector sensor struct. */
  struct sensor tilt_detector;    /**< Stores the tilt detector sensor struct. */
  struct sensor pocket_detector;    /**< Stores the pocket detector sensor struct. */
  struct sensor circle_detector;    /**< Stores the circle detector sensor struct. */
  struct sensor heart_rate_monitor;    /**< Stores the hear rate monitor sensor struct. */
  struct sensor arvr_stabilised_rotation_vector;    /**< Stores the ARVR stabilised rotation vector sensor struct. */
  struct sensor arvr_stabilised_game_rotation_vector;    /**< Stores the ARVR stabilised game rotation vector sensor struct. */
  struct sensor gyro_integrated_rotation_vector;    /**< Stores the gyro-integrated rotation vector sensor struct. */
  struct sensor motion_request;    /**< Stores the motion request sensor struct. */
  struct sensor dead_reckoning_pose;    /**< Stores the dead reckoning pose sensor struct. */
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
 * @return the `sensor_collection` struct
 */
struct sensor_collection init(const struct i2c_interface* i2c);

/**
 * @brief Enables a specified sensor with a fixed report rate.
 * 
 * @param i2c is the I2C interface to communicate with the sensor on
 * @param sc is the pointer to the `sensor_collection` struct
 * @param id is the ID of the sensor to enable
 * @param sample_rate_ms is the desired report rate in miliseconds 
 * @return `true` if the sensor was successfully enabled
 * @return `false` if the sensor could not be enabled
 */
bool enable_sensor(const struct i2c_interface* i2c, struct sensor_collection* sc, const enum REPORT_ID id, const uint32_t sample_rate_ms);

/**
 * @brief Read the latest sensor report on the bus.
 * 
 * @param i2c is the I2C interface to communicate with the sensor on
 * @param sc is the pointer to the `sensor_collection` struct
 * @return `true`	if the read was successful
 * @return `false` if an error occurred
 */
bool read_sensors(const struct i2c_interface* i2c, struct sensor_collection* sc);