/****************************************************************************************************
* @file sensors.h
* @brief Global sensor struct instances.
*
* @author Toby Godfrey
****************************************************************************************************/

#include "bno08x.h"
#include "sensor_reports.h"

/*! 
	\defgroup Sensors
		Structs storing the instance of each sensor
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
const struct sensor* accelerometer = &(struct sensor) {
	.name = "Accelerometer",
	.id = ACCELEROMETER,
	.channel = 255,
	.q_point = 0,
	.input_report = (union input_report) {
		.accelerometer = (struct accelerometer_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.x = 0,
			.y = 0,
			.z = 0
		} 
	},
	.enabled = false
};

/**
 * @struct gyroscope
 * 
 * @brief The gyroscope instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* gyroscope = &(struct sensor) {
	.name = "Gyroscope",
	.id = GYROSCOPE,
	.channel = 255,
	.q_point = 0,
	.input_report = (union input_report) {
		.accelerometer = (struct accelerometer_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.x = 0,
			.y = 0,
			.z = 0
		} 
	},
	.enabled = false
};


/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* magnetic_field;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* linear_acceleration;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* rotation_vector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* gravity;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* uncalibrated_gyroscope;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* game_rotation_vector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* geomagnetic_rotation_vector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* pressure;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* ambient_light;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* humidity;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* proximity;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* temperature;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* uncalibrated_magnetic_field;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* tap_detector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* step_counter;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* significant_motion;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* stability_classifier;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* raw_accelerometer;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* raw_gyroscope;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* raw_magnetometer;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* step_detector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* shake_detector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* flip_detector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* pickup_detector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* stability_detector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* personal_activity_classifier;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* sleep_detector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* tilt_detector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* pocket_detector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* circle_detector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* heart_rate_monitor;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* arvr_stabilised_rotation_vector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* arvr_stabilised_game_rotation_vector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* gyro_integrated_rotation_vector;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* motion_request;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* optical_flow;

/**
 * @struct accelerometer
 * 
 * @brief The accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* dead_reckoning_pose;

