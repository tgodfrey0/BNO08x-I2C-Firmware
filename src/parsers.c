/****************************************************************************************************
* @file parsers.c
* @brief BNO08x frame parsers.
*
* @author Toby Godfrey
****************************************************************************************************/

#include "bno08x.h"
#include "i2c.h"
#include "logger.h"
#include "parsers.h"
#include "sensors.h"

uint16_t read_two_bytes(uint8_t* p){
  return (*p | (*(p + 1) << 8));
}

uint32_t read_four_bytes(uint8_t* p){
  return (*p | (*(p + 1) << 8) | (*(p + 2) << 16) | (*(p + 3) << 24));
}

void parse_accelerometer_data(struct i2c_message msg){
  accelerometer.input_report.accelerometer.report_id = msg.payload[0];
}

void parse_gyroscope_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_magnetic_field_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_linear_acceleration_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_rotation_vector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_gravity_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_uncalibrated_gyroscope_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_game_rotation_vector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_geomagnetic_rotation_vector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_pressure_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_ambient_light_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_humidity_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_proximity_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_temperature_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_uncalibrated_magnetic_field_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_tap_detector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_step_counter_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_significant_motion_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_stability_classifier_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_raw_accelerometer_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_raw_gyroscope_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_raw_magnetometer_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_step_detector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_shake_detector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_flip_detector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_pickup_detector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_stability_detector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_personal_activity_classifier_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_sleep_detector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_tilt_detector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_pocket_detector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_circle_detector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_heart_rate_monitor_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_arvr_stabilised_rotation_vector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_arvr_stabilised_game_rotation_vector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_gyro_integrated_rotation_vector_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_motion_request_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_dead_reckoning_pose_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void parse_msg(struct i2c_message msg){
  info("Message received from sensor with msg.payload[0] %d", msg.payload[0]);
  switch (msg.payload[0]) {
    case ACCELEROMETER:
      parse_accelerometer_data(msg);
      break;
    case GYROSCOPE:
      parse_gyroscope_data(msg);
      break;
    case MAGNETIC_FIELD:
      parse_magnetic_field_data(msg);
      break;
    case LINEAR_ACCELERATION:
      parse_linear_acceleration_data(msg);
      break;
    case ROTATION_VECTOR:
      parse_rotation_vector_data(msg);
      break;
    case GRAVITY:
      parse_gravity_data(msg);
      break;
    case UNCALIBRATED_GYROSCOPE:
      parse_uncalibrated_gyroscope_data(msg);
      break;
    case GAME_ROTATION_VECTOR:
      parse_game_rotation_vector_data(msg);
      break;
    case GEOMAGNETIC_ROTATION_VECTOR:
      parse_geomagnetic_rotation_vector_data(msg);
      break;
    case PRESSURE:
      parse_pressure_data(msg);
      break;
    case AMBIENT_LIGHT:
      parse_ambient_light_data(msg);
      break;
    case HUMIDITY:
      parse_humidity_data(msg);
      break;
    case PROXIMITY:
      parse_proximity_data(msg);
      break;
    case TEMPERATURE:
      parse_temperature_data(msg);
      break;
    case UNCALIBRATED_MAGNETIC_FIELD:
      parse_uncalibrated_magnetic_field_data(msg);
      break;
    case TAP_DETECTOR:
      parse_tap_detector_data(msg);
      break;
    case STEP_COUNTER:
      parse_step_counter_data(msg);
      break;
    case SIGNIFICANT_MOTION:
      parse_significant_motion_data(msg);
      break;
    case STABILITY_CLASSIFIER:
      parse_stability_classifier_data(msg);
      break;
    case RAW_ACCELEROMETER:
      parse_raw_accelerometer_data(msg);
      break;
    case RAW_GYROSCOPE:
      parse_raw_gyroscope_data(msg);
      break;
    case RAW_MAGNETOMETER:
      parse_raw_magnetometer_data(msg);
      break;
    case STEP_DETECTOR:
      parse_step_detector_data(msg);
      break;
    case SHAKE_DETECTOR:
      parse_shake_detector_data(msg);
      break;
    case FLIP_DETECTOR:
      parse_flip_detector_data(msg);
      break;
    case PICKUP_DETECTOR:
      parse_pickup_detector_data(msg);
      break;
    case STABILITY_DETECTOR:
      parse_stability_detector_data(msg);
      break;
    case PERSONAL_ACTIVITY_CLASSIFIER:
      parse_personal_activity_classifier_data(msg);
      break;
    case SLEEP_DETECTOR:
      parse_sleep_detector_data(msg);
      break;
    case TILT_DETECTOR:
      parse_tilt_detector_data(msg);
      break;
    case POCKET_DETECTOR:
      parse_pocket_detector_data(msg);
      break;
    case CIRCLE_DETECTOR:
      parse_circle_detector_data(msg);
      break;
    case HEART_RATE_MONITOR:
      parse_heart_rate_monitor_data(msg);
      break;
    case ARVR_STABILISED_ROTATION_VECTOR:
      parse_arvr_stabilised_rotation_vector_data(msg);
      break;
    case ARVR_STABILISED_GAME_ROTATION_VECTOR:
      parse_arvr_stabilised_game_rotation_vector_data(msg);
      break;
    case GYRO_INTEGRATED_ROTATION_VECTOR:
      parse_gyro_integrated_rotation_vector_data(msg);
      break;
    case MOTION_REQUEST:
      parse_motion_request_data(msg);
      break;
    case OPTICAL_FLOW:
      warn("Optical flow frames are not supported\n");
      break;
    case DEAD_RECKONING_POSE:
      parse_dead_reckoning_pose_data(msg);
      break;
    default:
      warn("Unrecognised sensor msg.payload[0] - %d", msg.payload[0]);
      break;
  }
}