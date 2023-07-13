#include "bno08x.h"
#include "i2c.h"
#include "logger.h"
#include "parsers.h"
#include "q_points.h"
#include "sensors.h"
#include "response_sizes.h"


float scale_q(uint8_t q){
  if(q == 0) return 1;
  return (1.0f / (1 << q));
}

uint16_t read_16(uint8_t* p){
  return (*p | (*(p + 1) << 8));
}

float read_16_scale(uint8_t* p, uint8_t q){
  return (read_16(p) * scale_q(q));
}

uint32_t read_32(uint8_t* p){
  return (*p | (*(p + 1) << 8) | (*(p + 2) << 16) | (*(p + 3) << 24));
}

float read_32_scale(uint8_t* p, uint8_t q){
  return (read_32(p) * scale_q(q));
}

void parse_accelerometer_data(struct i2c_message msg){
  if(msg.length != RES_ACCELEROMETER){
    warn("Invalid accelerometer report, expected 10 bytes, received %d bytes\n", msg.length);
    return;
  }

  accelerometer->input_report.accelerometer.report_id = msg.payload[0];
  accelerometer->input_report.accelerometer.seq_num = msg.payload[1];
  accelerometer->input_report.accelerometer.status = msg.payload[2];
  accelerometer->input_report.accelerometer.delay = msg.payload[3];
  accelerometer->input_report.accelerometer.x = read_16_scale(&msg.payload[4], Q_ACCELEROMETER);
  accelerometer->input_report.accelerometer.y = read_16_scale(&msg.payload[6], Q_ACCELEROMETER);
  accelerometer->input_report.accelerometer.z = read_16_scale(&msg.payload[8], Q_ACCELEROMETER);

  last_received = msg.payload[0];
  info("Successfully parsed accelerometer data\n");
}

void parse_gyroscope_data(struct i2c_message msg){
  if(msg.length != RES_GYROSCOPE){
    warn("Invalid gyroscope report, expected 10 bytes, received %d bytes\n", msg.length);
    return;
  }

  gyroscope->input_report.gyroscope.report_id = msg.payload[0];
  gyroscope->input_report.gyroscope.seq_num = msg.payload[1];
  gyroscope->input_report.gyroscope.status = msg.payload[2];
  gyroscope->input_report.gyroscope.delay = msg.payload[3];
  gyroscope->input_report.gyroscope.x = read_16_scale(&msg.payload[4], Q_GYROSCOPE);
  gyroscope->input_report.gyroscope.y = read_16_scale(&msg.payload[6], Q_GYROSCOPE);
  gyroscope->input_report.gyroscope.z = read_16_scale(&msg.payload[8], Q_GYROSCOPE);

  last_received = msg.payload[0];
  info("Successfully parsed gyroscope data\n");
}

void parse_magnetic_field_data(struct i2c_message msg){
  if(msg.length != RES_MAGNETIC_FIELD){
    warn("Invalid magnetic field report, expected 10 bytes, received %d bytes\n", msg.length);
    return;
  }

  magnetic_field->input_report.magnetic_field.report_id = msg.payload[0];
  magnetic_field->input_report.magnetic_field.seq_num = msg.payload[1];
  magnetic_field->input_report.magnetic_field.status = msg.payload[2];
  magnetic_field->input_report.magnetic_field.delay = msg.payload[3];
  magnetic_field->input_report.magnetic_field.x = read_16_scale(&msg.payload[4], Q_MAGNETIC_FIELD);
  magnetic_field->input_report.magnetic_field.y = read_16_scale(&msg.payload[6], Q_MAGNETIC_FIELD);
  magnetic_field->input_report.magnetic_field.z = read_16_scale(&msg.payload[8], Q_MAGNETIC_FIELD);

  last_received = msg.payload[0];
  info("Successfully parsed magnetic field data\n");
}

void parse_linear_acceleration_data(struct i2c_message msg){
  if(msg.length != RES_LINEAR_ACCELERATION){
    warn("Invalid linear acceleration report, expected 10 bytes, received %d bytes\n", msg.length);
    return;
  }

  linear_acceleration->input_report.linear_acceleration.report_id = msg.payload[0];
  linear_acceleration->input_report.linear_acceleration.seq_num = msg.payload[1];
  linear_acceleration->input_report.linear_acceleration.status = msg.payload[2];
  linear_acceleration->input_report.linear_acceleration.delay = msg.payload[3];
  linear_acceleration->input_report.linear_acceleration.x = read_16_scale(&msg.payload[4], Q_LINEAR_ACCELERATION);
  linear_acceleration->input_report.linear_acceleration.y = read_16_scale(&msg.payload[6], Q_LINEAR_ACCELERATION);
  linear_acceleration->input_report.linear_acceleration.z = read_16_scale(&msg.payload[8], Q_LINEAR_ACCELERATION);

  last_received = msg.payload[0];
  info("Successfully parsed linear acceleration data\n");
}

void parse_rotation_vector_data(struct i2c_message msg){
  if(msg.length != RES_ROTATION_VECTOR){
    warn("Invalid rotation vector report, expected 14 bytes, received %d bytes\n", msg.length);
    return;
  }

  rotation_vector->input_report.rotation_vector.report_id = msg.payload[0];
  rotation_vector->input_report.rotation_vector.seq_num = msg.payload[1];
  rotation_vector->input_report.rotation_vector.status = msg.payload[2];
  rotation_vector->input_report.rotation_vector.delay = msg.payload[3];
  rotation_vector->input_report.rotation_vector.i = read_16_scale(&msg.payload[4], Q_ROTATION_VECTOR);
  rotation_vector->input_report.rotation_vector.j = read_16_scale(&msg.payload[6], Q_ROTATION_VECTOR);
  rotation_vector->input_report.rotation_vector.k = read_16_scale(&msg.payload[8], Q_ROTATION_VECTOR);
  rotation_vector->input_report.rotation_vector.real = read_16_scale(&msg.payload[10], Q_ROTATION_VECTOR);
  rotation_vector->input_report.rotation_vector.accuracy = read_16_scale(&msg.payload[12], Q_ROTATION_VECTOR_ACCURACY);

  last_received = msg.payload[0];
  info("Successfully parsed linear acceleration data\n");
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