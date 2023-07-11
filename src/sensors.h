/****************************************************************************************************
* @file sensors.h
* @brief Global sensor struct instances.
*
* @author Toby Godfrey
****************************************************************************************************/

#include "bno08x.h"
#include "sensor_reports.h"

//=================================================================================================//
//		Sensor Struct Declarations
//=================================================================================================//

const struct sensor* accelerometer = &(struct sensor) {
	.name = "Accelerometer",
	.id = ACCELEROMETER,
	.channel = 3,
	.q_point = 12,
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
};		/**< A pointer to the instance of the accelerometer. */

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

