/****************************************************************************************************
* @file bno085.h
* @brief BNO085 related definitions
*
* @author Toby Godfrey
****************************************************************************************************/

#pragma once

#include <stdint.h>
#include <stdbool.h>

//=================================================================================================//
//	Structs
//=================================================================================================//

//**********************************************************************//
//	Sensor Report Structs
//**********************************************************************//

/**
 * @struct accelerometer_report
 *
 * The acceleration of the device, including gravity. Units are in m/s^2 and the Q point is 8.
 * 
 * @brief Holds the report data for the accelerometer.
 */
struct accelerometer_report {
	uint8_t report_id;		/**< The ID of the report - 0x01 for the accelerometer */
	uint8_t seq_num;		/**< The sequence number of the report */
	uint8_t status;		/**< The status of the sensor */
	uint8_t delay;		/**< Report delay in 100us */
	float x;		/**< x component of the acceleration */
	float y;		/**< y component of the acceleration */
	float z;		/**< z component of the acceleration */
};

/**
 * @struct gyroscope_report
 * 
 * @brief Holds the report data for the gyroscope.
 */
struct gyroscope_report {};

/**
 * @struct magnetic_field_report
 * 
 * @brief Holds the report data for the magnetic field.
 */
struct magnetic_field_report {};

/**
 * @struct linear_acceleration_report
 *
 * The linear acceleration of the device, does not include gravity. Units are in m/s^2 and the Q point is 8.
 * 
 * @brief Holds the report data for the linear acceleration.
 */
struct linear_acceleration_report {
	uint8_t report_id;		/**< The ID of the report - 0x04 for the accelerometer */
	uint8_t seq_num;		/**< The sequence number of the report */
	uint8_t status;		/**< The status of the sensor */
	uint8_t delay;		/**< Report delay in 100us */
	float x;		/**< x component of the acceleration */
	float y;		/**< y component of the acceleration */
	float z;		/**< z component of the acceleration */
};

/**
 * @struct rotation_vector_report
 * 
 * @brief Holds the report data for the rotation vector.
 */
struct rotation_vector_report {};

/**
 * @struct gravity_report
 * 
 * @brief Holds the report data for the gravity.
 */
struct gravity_report {};

/**
 * @struct uncalibrated_gyroscope_report
 * 
 * @brief Holds the report data for the uncalibrated gyroscope.
 */
struct uncalibrated_gyroscope_report {};

/**
 * @struct game_rotation_vector_report
 * 
 * @brief Holds the report data for the game rotation vector.
 */
struct game_rotation_vector_report {};

/**
 * @struct geomagnetic_rotation_vector_report
 * 
 * @brief Holds the report data for the geomagnetic rotation vector.
 */
struct geomagnetic_rotation_vector_report {};

/**
 * @struct pressure_report
 * 
 * @brief Holds the report data for the pressure.
 */
struct pressure_report {};

/**
 * @struct ambient_light_report
 * 
 * @brief Holds the report data for the ambient light.
 */
struct ambient_light_report {};

/**
 * @struct humidity_report
 * 
 * @brief Holds the report data for the humidity.
 */
struct humidity_report {};

/**
 * @struct proximity_report
 * 
 * @brief Holds the report data for the proximity.
 */
struct proximity_report {};

/**
 * @struct temperature_report
 * 
 * @brief Holds the report data for the temperature.
 */
struct temperature_report {};

/**
 * @struct uncalibrated_magnetic_field_report
 * 
 * @brief Holds the report data for the uncalibrated magnetic field.
 */
struct uncalibrated_magnetic_field_report {};

/**
 * @struct tap_detector_report
 * 
 * @brief Holds the report data for the tap detector.
 */
struct tap_detector_report {};

/**
 * @struct step_counter_report
 * 
 * @brief Holds the report data for the step counter.
 */
struct step_counter_report {};

/**
 * @struct significant_motion_report
 * 
 * @brief Holds the report data for the significant motion.
 */
struct significant_motion_report {};

/**
 * @struct stability_classifier_report
 * 
 * @brief Holds the report data for the stability classifier.
 */
struct stability_classifier_report {};

/**
 * @struct raw_accelerometer_report
 * 
 * @brief Holds the report data for the raw accelerometer.
 */
struct raw_accelerometer_report {};

/**
 * @struct raw_gyroscope_report
 * 
 * @brief Holds the report data for the raw gyroscope.
 */
struct raw_gyroscope_report {};

/**
 * @struct raw_magnetometer_report
 * 
 * @brief Holds the report data for the raw magnetometer.
 */
struct raw_magnetometer_report {};

/**
 * @struct sar_report
 * 
 * @brief Holds the report data for the SAR.
 */
struct sar_report {};

/**
 * @struct step_detector_report
 * 
 * @brief Holds the report data for the step detector.
 */
struct step_detector_report {};

/**
 * @struct shake_detector_report
 * 
 * @brief Holds the report data for the shake detector.
 */
struct shake_detector_report {};

/**
 * @struct flip_detector_report
 * 
 * @brief Holds the report data for the flip detector.
 */
struct flip_detector_report {};

/**
 * @struct pickup_detector_report
 * 
 * @brief Holds the report data for the pickup detector.
 */
struct pickup_detector_report {};

/**
 * @struct stability_detector_report
 * 
 * @brief Holds the report data for the stability detector.
 */
struct stability_detector_report {};

/**
 * @struct personal_activity_classifier_report
 * 
 * @brief Holds the report data for the personal activity classifier.
 */
struct personal_activity_classifier_report {};

/**
 * @struct sleep_detector_report
 * 
 * @brief Holds the report data for the sleep detector.
 */
struct sleep_detector_report {};

/**
 * @struct tilt_detector_report
 * 
 * @brief Holds the report data for the tilt detector.
 */
struct tilt_detector_report {};

/**
 * @struct pocket_detector_report
 * 
 * @brief Holds the report data for the pocket detector.
 */
struct pocket_detector_report {};

/**
 * @struct circle_detector_report
 * 
 * @brief Holds the report data for the circle detector.
 */
struct circle_detector_report {};

/**
 * @struct heart_rate_monitor_report
 * 
 * @brief Holds the report data for the heart rate monitor.
 */
struct heart_rate_monitor_report {};

/**
 * @struct arvr_stabilised_rotation_vector_report
 * 
 * @brief Holds the report data for the ARVR stabilised rotation vector.
 */
struct arvr_stabilised_rotation_vector_report {};

/**
 * @struct arvr_stabilised_game_rotation_vector_report
 * 
 * @brief Holds the report data for the ARVR stabilised game rotation vector.
 */
struct arvr_stabilised_game_rotation_vector_report {};

//**********************************************************************//
//	Sensor report union
//**********************************************************************//

/**
 * @union report		Stores a report struct for a single sensor
 *
 * @brief Stores a single report struct.
 */
union report {
	struct accelerometer_report accelerometer;		/**< Stores the accelerometer report */
	struct gyroscope_report gyroscope;		/**< Stores the gyroscope report */
	struct magnetic_field_report magnetic_field;		/**< Stores the magnetic field report */
	struct linear_acceleration_report linear_acceleration;		/**< Stores the linear acceleration report */
	struct rotation_vector_report rotation_vector;		/**< Stores the rotation vector report */
	struct gravity_report gravity;		/**< Stores the gravity report */
	struct uncalibrated_gyroscope_report uncalibrated_gyroscope;		/**< Stores the uncalibrated gyroscope report */
	struct game_rotation_vector_report game_rotation_vector;		/**< Stores the game rotation vector report */
	struct geomagnetic_rotation_vector_report geomagnetic_rotation_vector;		/**< Stores the geomagnetic rotation vector report */
	struct pressure_report pressure;		/**< Stores the pressure report */
	struct ambient_light_report ambient_light;		/**< Stores the ambient light report */
	struct humidity_report humidity;		/**< Stores the humidity report */
	struct proximity_report proximity;		/**< Stores the proximity report */
	struct temperature_report temperature;		/**< Stores the temperature report */
	struct uncalibrated_magnetic_field_report uncalibrated_magnetic_field;		/**< Stores the uncalibrated magnetic field report */
	struct tap_detector_report tap_detector;		/**< Stores the tap detector report */
	struct step_counter_report step_counter;		/**< Stores the step counter report */
	struct significant_motion_report significant_motion;		/**< Stores the significant motion report */
	struct stability_classifier_report stability_classifier;		/**< Stores the stability classifier report */
	struct raw_accelerometer_report raw_accelerometer;		/**< Stores the raw accelerometer report */
	struct raw_gyroscope_report raw_gyroscope;		/**< Stores the raw gyroscope report */
	struct raw_magnetometer_report raw_magnetometer;		/**< Stores the raw magnetometer report */
	struct sar_report sar;		/**< Stores the SAR report */
	struct step_detector_report step_detector;		/**< Stores the step detector report */
	struct shake_detector_report shake_detector;		/**< Stores the shake detector report */
	struct flip_detector_report flip_detector;		/**< Stores the flip detector report */
	struct pickup_detector_report pickup_detector;		/**< Stores the pickup detector report */
	struct stability_detector_report stability_detector;		/**< Stores the stability detector report */
	struct personal_activity_classifier_report personal_activity_classifier;		/**< Stores the personal activity classifier report */
	struct sleep_detector_report sleep_detector;		/**< Stores the sleep detector report */
	struct tilt_detector_report tilt_detector;		/**< Stores the tilt detector report */
	struct pocket_detector_report pocket_detector;		/**< Stores the pocket detector report */
	struct circle_detector_report circle_detector;		/**< Stores the circle detector report */
	struct heart_rate_monitor_report heart_rate_monitor;		/**< Stores the hear rate monitor report */
	struct arvr_stabilised_rotation_vector_report arvr_stabilised_rotation_vector;		/**< Stores the ARVR stabilised rotation vector report */
	struct arvr_stabilised_game_rotation_vector_report arvr_stabilised_game_rotation_vector;		/**< Stores the ARVR stabilised game rotation vector report */
};

//=================================================================================================//
//	Functions
//=================================================================================================//


