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
 * The acceleration of the device, including gravity. Units are m/s^2 and the Q point is 8.
 * 
 * @brief Holds the report data for the accelerometer.
 */
struct accelerometer_report {
  uint8_t report_id;    /**< The ID of the report - 0x01 for acceleration */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
  float x;    /**< x component of the acceleration */
  float y;    /**< y component of the acceleration */
  float z;    /**< z component of the acceleration */
};

/**
 * @struct gyroscope_report
 *
 * The calibrated gyroscope (drift-compensated rotational velocity). Units are rad/s and the Q point is 9.
 * 
 * @brief Holds the report data for the gyroscope.
 */
struct gyroscope_report {
  uint8_t report_id;    /**< The ID of the report - 0x02 for the calibrated gyroscope */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
  float x;    /**< x component of the calibrated gyroscope */
  float y;    /**< y component of the calibrated gyroscope */
  float z;    /**< z component of the calibrated gyroscope */
};

/**
 * @struct magnetic_field_report
 *
 * The calibrated magentic field sensor; calibrated for hard and soft iron effects such that the vector is aligned with the declination and heading of Earth's magnetic field. Untis are uTesla and the Q point is 4.
 * 
 * @brief Holds the report data for the magnetic field.
 */
struct magnetic_field_report {
  uint8_t report_id;    /**< The ID of the report - 0x03 for the calibrated magnetic field sensor */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
  float x;    /**< x component of the calibrated magnetic field */
  float y;    /**< y component of the calibrated magnetic field */
  float z;    /**< z component of the calibrated magnetic field */
};

/**
 * @struct linear_acceleration_report
 *
 * The linear acceleration of the device, does not include gravity. Units are m/s^2 and the Q point is 8.
 * 
 * @brief Holds the report data for the linear acceleration.
 */
struct linear_acceleration_report {
  uint8_t report_id;    /**< The ID of the report - 0x04 for linear acceleration */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
  float x;    /**< x component of the linear acceleration */
  float y;    /**< y component of the linear acceleration */
  float z;    /**< z component of the linear acceleration */
};

/**
 * @struct rotation_vector_report
 *
 * The orientation of the device. The format is a unit quaternion. The Q point is 14. An estimate of the heading accuracy is report. The units for the accuracy estimate are radians and the Q point is 12. 
 * 
 * @brief Holds the report data for the rotation vector.
 */
struct rotation_vector_report {
  uint8_t report_id;    /**< The ID of the report - 0x05 for the rotation vector */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
  float i;    /**< The unit quaternion i component */
  float j;    /**< The unit quaternion j component */
  float k;    /**< The unit quaternion k component */
  float real;	/**< The unit quaternion real component */
  int16_t accuracy;   /**< An accuracy estimate */
};

/**
 * @struct gravity_report
 *
 * The gravity in the device's coordinate frame. Units are m/s^2 and the Q point is 8.
 * 
 * @brief Holds the report data for the gravity.
 */
struct gravity_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
  float x;    /**< x component of gravity */
  float y;    /**< y component of gravity */
  float z;    /**< z component of gravity */
};

/**
 * @struct uncalibrated_gyroscope_report
 *
 * The rotational velocity without drift compensation. An estimate of drift is also provided. Units are rad/s and the Q point is 9.
 * 
 * @brief Holds the report data for the uncalibrated gyroscope.
 */
struct uncalibrated_gyroscope_report {
  uint8_t report_id;    /**< The ID of the report - 0x07 for the uncalibrated gyroscope */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
  float x;    /**< x component of the acceleration */
  float y;    /**< y component of the acceleration */
  float z;    /**< z component of the acceleration */
  float x_bias;    /**< x drift rate */
  float y_bias;    /**< y drift rate */
  float z_bias;    /**< z drift rate */
};

/**
 * @struct game_rotation_vector_report
 *
 * Reports the orientation of the device. The format is a unit quaternion and the Q point is 14.
 * 
 * @brief Holds the report data for the game rotation vector.
 */
struct game_rotation_vector_report {
  uint8_t report_id;    /**< The ID of the report - 0x08 for the game rotation vector */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
  float i;    /**< The unit quaternion i component */
  float j;    /**< The unit quaternion j component */
  float k;    /**< The unit quaternion k component */
  float real;	/**< The unit quaternion real component */
};

/**
 * @struct geomagnetic_rotation_vector_report
 *
 * Reports the orientation of the device. The format is a unit quaternion and the Q point is 14. An estimate of heading accuracy is also reported. The units for the estimate of accuracy are radians and the Q point is 12. 
 *
 * @brief Holds the report data for the geomagnetic rotation vector.
 */
struct geomagnetic_rotation_vector_report {
  uint8_t report_id;    /**< The ID of the report - 0x09 for the geomagnetic rotation vector */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
  float i;    /**< The unit quaternion i component */
  float j;    /**< The unit quaternion j component */
  float k;    /**< The unit quaternion k component */
  float real;	/**< The unit quaternion real component */
  float accuracy;   /**< The accuracy estimate */
};

/**
 * @struct pressure_report
 * 
 * @brief Holds the report data for the pressure.
 */
struct pressure_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct ambient_light_report
 * 
 * @brief Holds the report data for the ambient light.
 */
struct ambient_light_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct humidity_report
 * 
 * @brief Holds the report data for the humidity.
 */
struct humidity_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct proximity_report
 * 
 * @brief Holds the report data for the proximity.
 */
struct proximity_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct temperature_report
 * 
 * @brief Holds the report data for the temperature.
 */
struct temperature_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct uncalibrated_magnetic_field_report
 *
 * Uncalibrated magnetic field reading; reports the geomagnetic field calibrated for soft iron effects only. Estimates for the hard iron bias are also reported. Units are in uTesla and the Q point is 4.
 * 
 * @brief Holds the report data for the uncalibrated magnetic field.
 */
struct uncalibrated_magnetic_field_report {
  uint8_t report_id;    /**< The ID of the report - 0x0F for the uncalibrated magnetic field */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
  float x;    /**< x component of the uncalibrated gyroscope */
  float y;    /**< y component of the uncalibrated gyroscope */
  float z;    /**< z component of the uncalibrated gyroscope */
  float x_bias;    /**< x hard iron bias */
  float y_bias;    /**< y hard iron bias */
  float z_bias;    /**< z hard iron bias */
};

/**
 * @struct tap_detector_report
 * 
 * @brief Holds the report data for the tap detector.
 */
struct tap_detector_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct step_counter_report
 * 
 * @brief Holds the report data for the step counter.
 */
struct step_counter_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct significant_motion_report
 * 
 * @brief Holds the report data for the significant motion.
 */
struct significant_motion_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct stability_classifier_report
 * 
 * @brief Holds the report data for the stability classifier.
 */
struct stability_classifier_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct raw_accelerometer_report
 * 
 * @brief Holds the report data for the raw accelerometer.
 */
struct raw_accelerometer_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct raw_gyroscope_report
 *
 * Raw readings from the physical gyroscope MEMS sensor. Units are ADCs. Interpretation of the reported values is sensor dependent.
 * 
 * @brief Holds the report data for the raw gyroscope.
 */
struct raw_gyroscope_report {
  uint8_t report_id;    /**< The ID of the report - 0x15 for the raw gyroscope */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
  int16_t x;    /**< x component of the raw gyroscope */
  int16_t y;    /**< y component of the raw gyroscope */
  int16_t z;    /**< z component of the raw gyroscope */
  int16_t temperature;    /**< The sensor temperature */
  uint32_t timestamp;    /**< The time the sample was measured, in us */
};

/**
 * @struct raw_magnetometer_report
 *
 * Raw readings from the physical magnetometer sensor. Units are ADCs. Interpretation of the reported values is sensor dependent.
 * 
 * @brief Holds the report data for the raw magnetometer.
 */
struct raw_magnetometer_report {
  uint8_t report_id;    /**< The ID of the report - 0x16 for the raw magnetometer */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
  int16_t x;    /**< x component of the raw gyroscope */
  int16_t y;    /**< y component of the raw gyroscope */
  int16_t z;    /**< z component of the raw gyroscope */
  uint32_t timestamp;    /**< The time the sample was measured, in us */
};

/**
 * @struct sar_report
 * 
 * @brief Holds the report data for the SAR.
 */
struct sar_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct step_detector_report
 * 
 * @brief Holds the report data for the step detector.
 */
struct step_detector_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct shake_detector_report
 * 
 * @brief Holds the report data for the shake detector.
 */
struct shake_detector_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct flip_detector_report
 * 
 * @brief Holds the report data for the flip detector.
 */
struct flip_detector_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct pickup_detector_report
 * 
 * @brief Holds the report data for the pickup detector.
 */
struct pickup_detector_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct stability_detector_report
 * 
 * @brief Holds the report data for the stability detector.
 */
struct stability_detector_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct personal_activity_classifier_report
 * 
 * @brief Holds the report data for the personal activity classifier.
 */
struct personal_activity_classifier_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct sleep_detector_report
 * 
 * @brief Holds the report data for the sleep detector.
 */
struct sleep_detector_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct tilt_detector_report
 * 
 * @brief Holds the report data for the tilt detector.
 */
struct tilt_detector_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct pocket_detector_report
 * 
 * @brief Holds the report data for the pocket detector.
 */
struct pocket_detector_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct circle_detector_report
 * 
 * @brief Holds the report data for the circle detector.
 */
struct circle_detector_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct heart_rate_monitor_report
 * 
 * @brief Holds the report data for the heart rate monitor.
 */
struct heart_rate_monitor_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct arvr_stabilised_rotation_vector_report
 * 
 * @brief Holds the report data for the ARVR stabilised rotation vector.
 */
struct arvr_stabilised_rotation_vector_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

/**
 * @struct arvr_stabilised_game_rotation_vector_report
 * 
 * @brief Holds the report data for the ARVR stabilised game rotation vector.
 */
struct arvr_stabilised_game_rotation_vector_report {
  uint8_t report_id;    /**< The ID of the report - 0x06 for gravity */
  uint8_t seq_num;    /**< The sequence number of the report */
  uint8_t status;    /**< The status of the sensor */
  uint8_t delay;    /**< Report delay in 100us */
};

//**********************************************************************//
//	Sensor report union
//**********************************************************************//

/**
 * @union report    Stores a report struct for a single sensor
 *
 * @brief Stores a single report struct.
 */
union report {
  struct accelerometer_report accelerometer;    /**< Stores the accelerometer report */
  struct gyroscope_report gyroscope;    /**< Stores the gyroscope report */
  struct magnetic_field_report magnetic_field;    /**< Stores the magnetic field report */
  struct linear_acceleration_report linear_acceleration;    /**< Stores the linear acceleration report */
  struct rotation_vector_report rotation_vector;    /**< Stores the rotation vector report */
  struct gravity_report gravity;    /**< Stores the gravity report */
  struct uncalibrated_gyroscope_report uncalibrated_gyroscope;    /**< Stores the uncalibrated gyroscope report */
  struct game_rotation_vector_report game_rotation_vector;    /**< Stores the game rotation vector report */
  struct geomagnetic_rotation_vector_report geomagnetic_rotation_vector;    /**< Stores the geomagnetic rotation vector report */
  struct pressure_report pressure;    /**< Stores the pressure report */
  struct ambient_light_report ambient_light;    /**< Stores the ambient light report */
  struct humidity_report humidity;    /**< Stores the humidity report */
  struct proximity_report proximity;    /**< Stores the proximity report */
  struct temperature_report temperature;    /**< Stores the temperature report */
  struct uncalibrated_magnetic_field_report uncalibrated_magnetic_field;    /**< Stores the uncalibrated magnetic field report */
  struct tap_detector_report tap_detector;    /**< Stores the tap detector report */
  struct step_counter_report step_counter;    /**< Stores the step counter report */
  struct significant_motion_report significant_motion;    /**< Stores the significant motion report */
  struct stability_classifier_report stability_classifier;    /**< Stores the stability classifier report */
  struct raw_accelerometer_report raw_accelerometer;    /**< Stores the raw accelerometer report */
  struct raw_gyroscope_report raw_gyroscope;    /**< Stores the raw gyroscope report */
  struct raw_magnetometer_report raw_magnetometer;    /**< Stores the raw magnetometer report */
  struct sar_report sar;    /**< Stores the SAR report */
  struct step_detector_report step_detector;    /**< Stores the step detector report */
  struct shake_detector_report shake_detector;    /**< Stores the shake detector report */
  struct flip_detector_report flip_detector;    /**< Stores the flip detector report */
  struct pickup_detector_report pickup_detector;    /**< Stores the pickup detector report */
  struct stability_detector_report stability_detector;    /**< Stores the stability detector report */
  struct personal_activity_classifier_report personal_activity_classifier;    /**< Stores the personal activity classifier report */
  struct sleep_detector_report sleep_detector;    /**< Stores the sleep detector report */
  struct tilt_detector_report tilt_detector;    /**< Stores the tilt detector report */
  struct pocket_detector_report pocket_detector;    /**< Stores the pocket detector report */
  struct circle_detector_report circle_detector;    /**< Stores the circle detector report */
  struct heart_rate_monitor_report heart_rate_monitor;    /**< Stores the hear rate monitor report */
  struct arvr_stabilised_rotation_vector_report arvr_stabilised_rotation_vector;    /**< Stores the ARVR stabilised rotation vector report */
  struct arvr_stabilised_game_rotation_vector_report arvr_stabilised_game_rotation_vector;    /**< Stores the ARVR stabilised game rotation vector report */
};

//=================================================================================================//
//	Functions
//=================================================================================================//


