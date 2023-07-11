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
	\defgroup Sensors Structs storing the instance of each sensor
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
	.enabled = false,
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
	}
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
	.enabled = false,
	.input_report = (union input_report) {
		.gyroscope = (struct gyroscope_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.x = 0,
			.y = 0,
			.z = 0
		} 
	}
};


/**
 * @struct magnetic_field
 * 
 * @brief The magnetic field instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* magnetic_field = &(struct sensor) {
	.name = "Magnetic Field",
	.id = MAGNETIC_FIELD,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.magnetic_field = (struct magnetic_field_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.x = 0,
			.y = 0,
			.z = 0
		}
	}
};

/**
 * @struct linear_acceleration
 * 
 * @brief The linear acceleration instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* linear_acceleration = &(struct sensor) {
	.name = "Linear Acceleration",
	.id = LINEAR_ACCELERATION,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.linear_acceleration = (struct linear_acceleration_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.x = 0,
			.y = 0,
			.z = 0
		}
	}
};

/**
 * @struct rotation_vector
 * 
 * @brief The rotation vector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* rotation_vector = &(struct sensor) {
	.name = "Rotation Vector",
	.id = ROTATION_VECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.rotation_vector = (struct rotation_vector_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.i = 0,
			.j = 0,
			.k = 0,
			.real = 0,
			.accuracy = 0
		}
	}
};

/**
 * @struct gravity
 * 
 * @brief The gravity instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* gravity = &(struct sensor) {
	.name = "Gravity",
	.id = GRAVITY,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.gravity = (struct gravity_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.x = 0,
			.y = 0,
			.z = 0
		}
	}
};

/**
 * @struct uncalibrated_gyroscope
 * 
 * @brief The uncalibrated gyroscope instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* uncalibrated_gyroscope = &(struct sensor) {
	.name = "Uncalibrated Gyroscope",
	.id = UNCALIBRATED_GYROSCOPE,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.uncalibrated_gyroscope = (struct uncalibrated_gyroscope_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.x = 0,
			.y = 0,
			.z = 0,
			.x_bias = 0,
			.y_bias = 0,
			.z_bias = 0
		}
	}
};

/**
 * @struct game_rotation_vector
 * 
 * @brief The game rotation vector instance instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* game_rotation_vector = &(struct sensor){
	.name = "Game Rotation Vector",
	.id = GAME_ROTATION_VECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.game_rotation_vector = (struct game_rotation_vector_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.i = 0,
			.j = 0,
			.k = 0,
			.real = 0
		}
	}
};

/**
 * @struct geomagnetic_rotation_vector
 * 
 * @brief The geomagnetic rotation vector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* geomagnetic_rotation_vector = &(struct sensor) {
	.name = "Geomagnetic Rotation Vector",
	.id = GEOMAGNETIC_ROTATION_VECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.geomagnetic_rotation_vector = (struct geomagnetic_rotation_vector_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.i = 0,
			.j = 0,
			.k = 0,
			.real = 0,
			.accuracy = 0
		}
	}
};

/**
 * @struct pressure
 * 
 * @brief The pressure instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* pressure = &(struct sensor) {
	.name = "Pressure",
	.id = PRESSURE,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.pressure = (struct pressure_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.value = 0
		}
	}
};

/**
 * @struct ambient_light
 * 
 * @brief The ambient light instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* ambient_light = &(struct sensor) {
	.name = "Ambient Light",
	.id = AMBIENT_LIGHT,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.ambient_light = (struct ambient_light_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.value = 0
		}
	}
};

/**
 * @struct humidity
 * 
 * @brief The humidity instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* humidity = &(struct sensor) {
	.name = "Humidity",
	.id = HUMIDITY,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.humidity = (struct humidity_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.value = 0
		}
	}
};

/**
 * @struct proximity
 * 
 * @brief The proximity instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* proximity = &(struct sensor) {
	.name = "Proximity",
	.id = PROXIMITY,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.proximity = (struct proximity_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.value = 0
		}
	}
};

/**
 * @struct temperature
 * 
 * @brief The temperature instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* temperature = &(struct sensor) {
	.name = "Temperature",
	.id = TEMPERATURE,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.temperature = (struct temperature_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.value = 0
		}
	}
};

/**
 * @struct uncalibrated_magnetic_field
 * 
 * @brief The uncalibrated magnetic field instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* uncalibrated_magnetic_field = &(struct sensor) {
	.name = "Uncalibrated Magnetic Field",
	.id = UNCALIBRATED_MAGNETIC_FIELD,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.uncalibrated_magnetic_field = (struct uncalibrated_magnetic_field_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.x = 0,
			.y = 0,
			.z = 0,
			.x_bias = 0,
			.y_bias = 0,
			.z_bias = 0
		}
	}
};

/**
 * @struct tap_detector
 * 
 * @brief The tap_detector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* tap_detector = &(struct sensor) {
	.name = "Tap Detector",
	.id = TAP_DETECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.tap_detector = (struct tap_detector_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.taps = 0
		}
	}
};

/**
 * @struct step_counter
 * 
 * @brief The step counter instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* step_counter = &(struct sensor) {
	.name = "Step Counter",
	.id = STEP_COUNTER,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.step_counter = (struct step_counter_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.steps = 0
		}
	}
};

/**
 * @struct significant_motion
 * 
 * @brief The significant motion instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* significant_motion = &(struct sensor) {
	.name = "Significant Motion",
	.id = SIGNIFICANT_MOTION,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.significant_motion = (struct significant_motion_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.motion = 0
		}
	}
};

/**
 * @struct stability_classifier
 * 
 * @brief The stability classifier instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* stability_classifier = &(struct sensor) {
	.name = "Stability Classifier",
	.id = STABILITY_CLASSIFIER,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.stability_classifier = (struct stability_classifier_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.classification = 0
		}
	}
};

/**
 * @struct raw_accelerometer
 * 
 * @brief The raw accelerometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* raw_accelerometer = &(struct sensor) {
	.name = "Raw Accelerometer",
	.id = RAW_ACCELEROMETER,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.raw_accelerometer = (struct raw_accelerometer_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.x = 0,
			.y = 0,
			.z = 0,
			.timestamp = 0
		}
	}
};

/**
 * @struct raw_gyroscope
 * 
 * @brief The raw gyroscope instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* raw_gyroscope = &(struct sensor) {
	.name = "Raw Gyroscope",
	.id = RAW_GYROSCOPE,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.raw_gyroscope = (struct raw_gyroscope_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.x = 0,
			.y = 0,
			.z = 0,
			.timestamp = 0
		}
	}
};

/**
 * @struct raw_magnetometer
 * 
 * @brief The raw magnetometer instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* raw_magnetometer = &(struct sensor) {
	.name = "Raw Magnetometer",
	.id = RAW_MAGNETOMETER,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.raw_magnetometer = (struct raw_magnetometer_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.x = 0,
			.y = 0,
			.z = 0,
			.timestamp = 0
		}
	}
};

/**
 * @struct step_detector
 * 
 * @brief The step detector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* step_detector = &(struct sensor) {
	.name = "Step Detector",
	.id = STEP_DETECTOR,
	.channel = 0,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.step_detector = (struct step_detector_report){
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.latency = 0
		}
	}
};

/**
 * @struct shake_detector
 * 
 * @brief The shake detector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* shake_detector = &(struct sensor) {
	.name = "Shake Detector",
	.id = SHAKE_DETECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.shake_detector = (struct shake_detector_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.shake = 0
		}
	}
};

/**
 * @struct flip_detector
 * 
 * @brief The flip detector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* flip_detector = &(struct sensor) {
	.name = "Flip Detector",
	.id = FLIP_DETECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.flip_detector = (struct flip_detector_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.flip = 0
		}
	}
};

/**
 * @struct pickup_detector
 * 
 * @brief The pickup detector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* pickup_detector = &(struct sensor) {
	.name = "Pickup Detector",
	.id = PICKUP_DETECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.pickup_detector = (struct pickup_detector_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.pickup = 0
		}
	}
};

/**
 * @struct stability_detector
 * 
 * @brief The stability detector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* stability_detector = &(struct sensor) {
	.name = "Stability Detector",
	.id = STABILITY_DETECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.stability_detector = (struct stability_detector_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.stability = 0
		}
	}
};

/**
 * @struct personal_activity_classifier
 * 
 * @brief The personal activity classifier instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* personal_activity_classifier = &(struct sensor) {
	.name = "Personal Activity Classifier",
	.id = PERSONAL_ACTIVITY_CLASSIFIER,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.personal_activity_classifier = (struct personal_activity_classifier_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.page_number = 0,
			.most_likely_state = 0,
			.confidence = 0
		}
	}
};

/**
 * @struct sleep_detector
 * 
 * @brief The sleep detector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* sleep_detector = &(struct sensor) {
	.name = "Sleep Detector",
	.id = SLEEP_DETECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.sleep_detector = (struct sleep_detector_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.state = 0
		}
	}
};

/**
 * @struct tilt_detector
 * 
 * @brief The tilt detector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* tilt_detector = &(struct sensor) {
	.name = "Tilt Detector",
	.id = TILT_DETECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.tilt_detector = (struct tilt_detector_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.tilt = 0
		}
	}
};

/**
 * @struct pocket_detector
 * 
 * @brief The pocket detector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* pocket_detector = &(struct sensor) {
	.name = "Pocket Detector",
	.id = POCKET_DETECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.pocket_detector = (struct pocket_detector_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.pocket = 0
		}
	}
};

/**
 * @struct circle_detector
 * 
 * @brief The circle detector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* circle_detector = &(struct sensor) {
	.name = "Circle Detector",
	.id = CIRCLE_DETECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.circle_detector = (struct circle_detector_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.circle = 0
		}
	}
};

/**
 * @struct heart_rate_monitor
 * 
 * @brief The heart rate monitor instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* heart_rate_monitor = &(struct sensor) {
	.name = "Heart Rate Monitor",
	.id = HEART_RATE_MONITOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.heart_rate_monitor = (struct heart_rate_monitor_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.hr = 0
		}
	}
};

/**
 * @struct arvr_stabilised_rotation_vector
 * 
 * @brief The ARVR stabilised rotation vector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* arvr_stabilised_rotation_vector = &(struct sensor) {
	.name = "ARVR Stabilised Rotation Vector",
	.id = ARVR_STABILISED_ROTATION_VECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.arvr_stabilised_rotation_vector = (struct arvr_stabilised_rotation_vector_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.i = 0,
			.j = 0,
			.k = 0,
			.real = 0,
			.accuracy = 0
		}
	}
};

/**
 * @struct arvr_stabilised_game_rotation_vector
 * 
 * @brief The ARVR stabilised game rotation vector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* arvr_stabilised_game_rotation_vector = &(struct sensor) {
	.name = "ARVR Stabilised Game Rotation Vector",
	.id = ARVR_STABILISED_GAME_ROTATION_VECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.arvr_stabilised_game_rotation_vector = (struct arvr_stabilised_game_rotation_vector_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.i = 0,
			.j = 0,
			.k = 0,
			.real = 0,
		}
	}
};

/**
 * @struct gyro_integrated_rotation_vector
 * 
 * @brief The gyro-integrated rotation vector instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* gyro_integrated_rotation_vector = &(struct sensor) {
	.name = "Gyro-Integrated Rotation Vector",
	.id = GYRO_INTEGRATED_ROTATION_VECTOR,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.gyro_integrated_rotation_vector = (struct gyro_integrated_rotation_vector_report) {
			.i = 0,
			.j = 0,
			.k = 0,
			.real = 0,
			.x = 0,
			.y = 0,
			.z = 0
		}
	}
};

/**
 * @struct motion_request
 * 
 * @brief The motion request instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* motion_request = &(struct sensor) {
	.name = "Motion Request",
	.id = MOTION_REQUEST,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.motion_request = (struct motion_request_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.intent = 0,
			.request = 0
		}
	}
};

/**
 * @struct dead_reckoning_pose
 * 
 * @brief The dead reckoning pose instance.
 * 
 * @ingroup Sensors
 */
const struct sensor* dead_reckoning_pose = &(struct sensor) {
	.name = "Dead Reckoning Pose",
	.id = DEAD_RECKONING_POSE,
	.channel = 255,
	.q_point = 0,
	.enabled = false,
	.input_report = (union input_report) {
		.dead_reckoning_pose = (struct dead_reckoning_pose_report) {
			.report_id = 0,
			.seq_num = 0,
			.status = 0,
			.delay = 0,
			.timestamp = 0,
			.x_linear_pos = 0,
			.y_linear_pos = 0,
			.z_linear_pos = 0,
			.i_angular_pos = 0,
			.j_angular_pos = 0,
			.k_angular_pos = 0,
			.real_angular_pos = 0,
			.x_linear_vel = 0,
			.y_linear_vel = 0,
			.z_linear_vel = 0,
			.x_angular_vel = 0,
			.y_angular_vel = 0,
			.z_angular_vel = 0
		}
	}
};

