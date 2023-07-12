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

void parse_accelerometer_data(struct i2c_message msg){
  warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
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
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case GYROSCOPE:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case MAGNETIC_FIELD:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case LINEAR_ACCELERATION:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case ROTATION_VECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case GRAVITY:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case UNCALIBRATED_GYROSCOPE:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case GAME_ROTATION_VECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case GEOMAGNETIC_ROTATION_VECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case PRESSURE:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case AMBIENT_LIGHT:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case HUMIDITY:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case PROXIMITY:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case TEMPERATURE:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case UNCALIBRATED_MAGNETIC_FIELD:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case TAP_DETECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case STEP_COUNTER:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case SIGNIFICANT_MOTION:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case STABILITY_CLASSIFIER:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case RAW_ACCELEROMETER:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case RAW_GYROSCOPE:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case RAW_MAGNETOMETER:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case RESERVED:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case STEP_DETECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case SHAKE_DETECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case FLIP_DETECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case PICKUP_DETECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case STABILITY_DETECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case PERSONAL_ACTIVITY_CLASSIFIER:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case SLEEP_DETECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case TILT_DETECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case POCKET_DETECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case CIRCLE_DETECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case HEART_RATE_MONITOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case ARVR_STABILISED_ROTATION_VECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case ARVR_STABILISED_GAME_ROTATION_VECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case GYRO_INTEGRATED_ROTATION_VECTOR:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case MOTION_REQUEST:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case OPTICAL_FLOW:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    case DEAD_RECKONING_POSE:
      warn("Parser for frames from sensor %d has not yet been implemented", msg.payload[0]);
      break;
    default:
      warn("Unrecognised sensor msg.payload[0] - %d", msg.payload[0]);
      break;
  }
}