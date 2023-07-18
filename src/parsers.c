#include "stdio.h"

#include "bno08x.h"
#include "i2c.h"
#include "logger.h"
#include "output.h"
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

void parse_accelerometer_data(uint8_t data[], uint8_t length){
  // if(length != RES_ACCELEROMETER){
  //   warn("Invalid accelerometer report, expected 10 bytes, received %d bytes\n", length);
  //   return;
  // }

  accelerometer->input_report.accelerometer.report_id = data[0];
  accelerometer->input_report.accelerometer.seq_num = data[1];
  accelerometer->input_report.accelerometer.status = data[2];
  accelerometer->input_report.accelerometer.delay = data[3];
  accelerometer->input_report.accelerometer.x = read_16_scale(&data[4], Q_ACCELEROMETER);
  accelerometer->input_report.accelerometer.y = read_16_scale(&data[6], Q_ACCELEROMETER);
  accelerometer->input_report.accelerometer.z = read_16_scale(&data[8], Q_ACCELEROMETER);

  last_received = data[0];
  info("Successfully parsed accelerometer data\n");
}

void parse_gyroscope_data(uint8_t data[], uint8_t length){
  if(length != RES_GYROSCOPE){
    warn("Invalid gyroscope report, expected 10 bytes, received %d bytes\n", length);
    return;
  }

  gyroscope->input_report.gyroscope.report_id = data[0];
  gyroscope->input_report.gyroscope.seq_num = data[1];
  gyroscope->input_report.gyroscope.status = data[2];
  gyroscope->input_report.gyroscope.delay = data[3];
  gyroscope->input_report.gyroscope.x = read_16_scale(&data[4], Q_GYROSCOPE);
  gyroscope->input_report.gyroscope.y = read_16_scale(&data[6], Q_GYROSCOPE);
  gyroscope->input_report.gyroscope.z = read_16_scale(&data[8], Q_GYROSCOPE);

  last_received = data[0];
  info("Successfully parsed gyroscope data\n");
}

void parse_magnetic_field_data(uint8_t data[], uint8_t length){
  if(length != RES_MAGNETIC_FIELD){
    warn("Invalid magnetic field report, expected 10 bytes, received %d bytes\n", length);
    return;
  }

  magnetic_field->input_report.magnetic_field.report_id = data[0];
  magnetic_field->input_report.magnetic_field.seq_num = data[1];
  magnetic_field->input_report.magnetic_field.status = data[2];
  magnetic_field->input_report.magnetic_field.delay = data[3];
  magnetic_field->input_report.magnetic_field.x = read_16_scale(&data[4], Q_MAGNETIC_FIELD);
  magnetic_field->input_report.magnetic_field.y = read_16_scale(&data[6], Q_MAGNETIC_FIELD);
  magnetic_field->input_report.magnetic_field.z = read_16_scale(&data[8], Q_MAGNETIC_FIELD);

  last_received = data[0];
  info("Successfully parsed magnetic field data\n");
}

void parse_linear_acceleration_data(uint8_t data[], uint8_t length){
  if(length != RES_LINEAR_ACCELERATION){
    warn("Invalid linear acceleration report, expected 10 bytes, received %d bytes\n", length);
    return;
  }

  linear_acceleration->input_report.linear_acceleration.report_id = data[0];
  linear_acceleration->input_report.linear_acceleration.seq_num = data[1];
  linear_acceleration->input_report.linear_acceleration.status = data[2];
  linear_acceleration->input_report.linear_acceleration.delay = data[3];
  linear_acceleration->input_report.linear_acceleration.x = read_16_scale(&data[4], Q_LINEAR_ACCELERATION);
  linear_acceleration->input_report.linear_acceleration.y = read_16_scale(&data[6], Q_LINEAR_ACCELERATION);
  linear_acceleration->input_report.linear_acceleration.z = read_16_scale(&data[8], Q_LINEAR_ACCELERATION);

  last_received = data[0];
  info("Successfully parsed linear acceleration data\n");
}

void parse_rotation_vector_data(uint8_t data[], uint8_t length){
  if(length != RES_ROTATION_VECTOR){
    warn("Invalid rotation vector report, expected 14 bytes, received %d bytes\n", length);
    return;
  }

  rotation_vector->input_report.rotation_vector.report_id = data[0];
  rotation_vector->input_report.rotation_vector.seq_num = data[1];
  rotation_vector->input_report.rotation_vector.status = data[2];
  rotation_vector->input_report.rotation_vector.delay = data[3];
  rotation_vector->input_report.rotation_vector.i = read_16_scale(&data[4], Q_ROTATION_VECTOR);
  rotation_vector->input_report.rotation_vector.j = read_16_scale(&data[6], Q_ROTATION_VECTOR);
  rotation_vector->input_report.rotation_vector.k = read_16_scale(&data[8], Q_ROTATION_VECTOR);
  rotation_vector->input_report.rotation_vector.real = read_16_scale(&data[10], Q_ROTATION_VECTOR);
  rotation_vector->input_report.rotation_vector.accuracy = read_16_scale(&data[12], Q_ROTATION_VECTOR_ACCURACY);

  last_received = data[0];
  info("Successfully parsed linear acceleration data\n");
}

void parse_gravity_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_uncalibrated_gyroscope_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_game_rotation_vector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_geomagnetic_rotation_vector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_pressure_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_ambient_light_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_humidity_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_proximity_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_temperature_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_uncalibrated_magnetic_field_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_tap_detector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_step_counter_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_significant_motion_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_stability_classifier_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_raw_accelerometer_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_raw_gyroscope_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_raw_magnetometer_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_step_detector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_shake_detector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_flip_detector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_pickup_detector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_stability_detector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_personal_activity_classifier_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_sleep_detector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_tilt_detector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_pocket_detector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_circle_detector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_heart_rate_monitor_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_arvr_stabilised_rotation_vector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_arvr_stabilised_game_rotation_vector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_gyro_integrated_rotation_vector_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_motion_request_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

void parse_dead_reckoning_pose_data(uint8_t data[], uint8_t length){
  warn("Parser for frames from sensor 0x%x has not yet been implemented\n", data[0]);
}

bool parse_cmd_res_msg(uint8_t data[], uint8_t length){
  print_raw_cmd_res_msg(create_msg(data, length));
  return true;
}

bool parse_get_feat_res_msg(uint8_t data[], uint8_t length){
  print_raw_get_feat_res_msg(create_msg(data, length));
  return true;
}

bool parse_msg(struct i2c_message msg){
  // info("Message received from sensor with ID %d\n", data[0]);
  
  data("Length 1: %d\n", msg.length);
  data("Data 1: ");
  for(uint8_t i = 0; i < msg.length; i++){
    printf("(0x%x - %p) ", msg.payload[i], &(msg.payload[i]));
  }
  printf("\n");

  if(msg.length < HEADER_SIZE){
    warn("No header found\n");
    return false;
  }

  uint8_t l; // Length of payload + header (+ timebase)
  l = msg.length - HEADER_SIZE;

  uint8_t* d = msg.payload;

  d += HEADER_SIZE;

  if(d[0] == TIMEBASE){ // Remove the timebase fields
    l -= TIMEBASE_SIZE; // Length of payload only
    d += TIMEBASE_SIZE;
  }

  data("Length 2: %d\n", l);
  data("Data 2: ");
  for(uint8_t i = 0; i < l; i++){
    printf("(0x%x - %p) ", *(d+i), d+i);
  }
  printf("\n\n");

  return false;

  if(d[0] == GET_FEATURE_RESPONSE) return parse_get_feat_res_msg(d, l);
  else if(d[0] == CMD_RESPONSE) return parse_cmd_res_msg(d, l);
  else {
    switch (d[0]) {
      case ACCELEROMETER:
        parse_accelerometer_data(d, l);
        break;
      case GYROSCOPE:
        parse_gyroscope_data(d, l);
        break;
      case MAGNETIC_FIELD:
        parse_magnetic_field_data(d, l);
        break;
      case LINEAR_ACCELERATION:
        parse_linear_acceleration_data(d, l);
        break;
      case ROTATION_VECTOR:
        parse_rotation_vector_data(d, l);
        break;
      case GRAVITY:
        parse_gravity_data(d, l);
        break;
      case UNCALIBRATED_GYROSCOPE:
        parse_uncalibrated_gyroscope_data(d, l);
        break;
      case GAME_ROTATION_VECTOR:
        parse_game_rotation_vector_data(d, l);
        break;
      case GEOMAGNETIC_ROTATION_VECTOR:
        parse_geomagnetic_rotation_vector_data(d, l);
        break;
      case PRESSURE:
        parse_pressure_data(d, l);
        break;
      case AMBIENT_LIGHT:
        parse_ambient_light_data(d, l);
        break;
      case HUMIDITY:
        parse_humidity_data(d, l);
        break;
      case PROXIMITY:
        parse_proximity_data(d, l);
        break;
      case TEMPERATURE:
        parse_temperature_data(d, l);
        break;
      case UNCALIBRATED_MAGNETIC_FIELD:
        parse_uncalibrated_magnetic_field_data(d, l);
        break;
      case TAP_DETECTOR:
        parse_tap_detector_data(d, l);
        break;
      case STEP_COUNTER:
        parse_step_counter_data(d, l);
        break;
      case SIGNIFICANT_MOTION:
        parse_significant_motion_data(d, l);
        break;
      case STABILITY_CLASSIFIER:
        parse_stability_classifier_data(d, l);
        break;
      case RAW_ACCELEROMETER:
        parse_raw_accelerometer_data(d, l);
        break;
      case RAW_GYROSCOPE:
        parse_raw_gyroscope_data(d, l);
        break;
      case RAW_MAGNETOMETER:
        parse_raw_magnetometer_data(d, l);
        break;
      case STEP_DETECTOR:
        parse_step_detector_data(d, l);
        break;
      case SHAKE_DETECTOR:
        parse_shake_detector_data(d, l);
        break;
      case FLIP_DETECTOR:
        parse_flip_detector_data(d, l);
        break;
      case PICKUP_DETECTOR:
        parse_pickup_detector_data(d, l);
        break;
      case STABILITY_DETECTOR:
        parse_stability_detector_data(d, l);
        break;
      case PERSONAL_ACTIVITY_CLASSIFIER:
        parse_personal_activity_classifier_data(d, l);
        break;
      case SLEEP_DETECTOR:
        parse_sleep_detector_data(d, l);
        break;
      case TILT_DETECTOR:
        parse_tilt_detector_data(d, l);
        break;
      case POCKET_DETECTOR:
        parse_pocket_detector_data(d, l);
        break;
      case CIRCLE_DETECTOR:
        parse_circle_detector_data(d, l);
        break;
      case HEART_RATE_MONITOR:
        parse_heart_rate_monitor_data(d, l);
        break;
      case ARVR_STABILISED_ROTATION_VECTOR:
        parse_arvr_stabilised_rotation_vector_data(d, l);
        break;
      case ARVR_STABILISED_GAME_ROTATION_VECTOR:
        parse_arvr_stabilised_game_rotation_vector_data(d, l);
        break;
      case GYRO_INTEGRATED_ROTATION_VECTOR:
        parse_gyro_integrated_rotation_vector_data(d, l);
        break;
      case MOTION_REQUEST:
        parse_motion_request_data(d, l);
        break;
      case OPTICAL_FLOW:
        warn("Optical flow frames are not supported\n");
        break;
      case DEAD_RECKONING_POSE:
        parse_dead_reckoning_pose_data(d, l);
        break;
      default:
        warn("Unrecognised sensor ID 0x%x\n", d[0]);
        return false;
    }

    return true;
  }
}
