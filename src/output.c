#include "bno08x.h"
#include "logger.h"
#include "output.h"

char* print_status(uint8_t s){
  uint8_t status = s & 0x03; // Only want the firs two bits
  switch (status) {
    case 0:
      return "Unreliable";
    case 1:
      return "Accuracy Low";
    case 2:
      return "Accuracy Medium";
    case 3:
      return "Accuracy High";
  }
}

void print_accelerometer_data(){
  info("Accelerometer Frame:\n");
  info("Sensor status is \"%s\", delay is %d us", print_status(accelerometer.input_report.accelerometer.status), (accelerometer.input_report.accelerometer.delay * 100));
  info("(x, y, z) m/s^2: (%d, %d, %d) m/s^2", accelerometer.input_report.accelerometer.x, accelerometer.input_report.accelerometer.y, accelerometer.input_report.accelerometer.z);
}

void print_gyroscope_data(){
  info("Gyroscope Frame:\n");
  info("Sensor status is \"%s\", delay is %d us", print_status(gyroscope.input_report.gyroscope.status), (gyroscope.input_report.gyroscope.delay * 100));
  info("(x, y, z) rad/s: (%d, %d, %d) rad/s", gyroscope.input_report.gyroscope.x, gyroscope.input_report.gyroscope.y, gyroscope.input_report.gyroscope.z);
}

void print_magnetic_field_data(){
  info("Magnetic Field Frame:\n");
  info("Sensor status is \"%s\", delay is %d us", print_status(magnetic_field.input_report.magnetic_field.status), (magnetic_field.input_report.magnetic_field.delay * 100));
  info("(x, y, z) uT: (%d, %d, %d) uT", magnetic_field.input_report.magnetic_field.x, magnetic_field.input_report.magnetic_field.y, magnetic_field.input_report.magnetic_field.z);
}

void print_linear_acceleration_data(){
  info("Linear Accelerometer Frame:\n");
  info("Sensor status is \"%s\", delay is %d us", print_status(linear_acceleration.input_report.linear_acceleration.status), (linear_acceleration.input_report.linear_acceleration.delay * 100));
  info("(x, y, z) m/s^2: (%d, %d, %d) m/s^2", linear_acceleration.input_report.linear_acceleration.x, linear_acceleration.input_report.linear_acceleration.y, linear_acceleration.input_report.linear_acceleration.z);
}

void print_rotation_vector_data(){
  info("Rotation Vector Frame:\n");
  info("Sensor status is \"%s\", delay is %d us", print_status(rotation_vector.input_report.rotation_vector.status), (rotation_vector.input_report.rotation_vector.delay * 100));
  info("Quaternion: %d + %di + %dj + %dk", rotation_vector.input_report.rotation_vector.rea;, rotation_vector.input_report.rotation_vector.i, rotation_vector.input_report.rotation_vector.j, rotation_vector.input_report.rotation_vector.k);
  info("Accuracy: %d rad", rotation_vector.input_report.rotation_vector.accuracy);
}

void print_gravity_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_uncalibrated_gyroscope_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_game_rotation_vector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_geomagnetic_rotation_vector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_pressure_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_ambient_light_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_humidity_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_proximity_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_temperature_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_uncalibrated_magnetic_field_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_tap_detector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_step_counter_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_significant_motion_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_stability_classifier_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_raw_accelerometer_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_raw_gyroscope_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_raw_magnetometer_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_step_detector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_shake_detector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_flip_detector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_pickup_detector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_stability_detector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_personal_activity_classifier_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_sleep_detector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_tilt_detector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_pocket_detector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_circle_detector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_heart_rate_monitor_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_arvr_stabilised_rotation_vector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_arvr_stabilised_game_rotation_vector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_gyro_integrated_rotation_vector_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_motion_request_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_dead_reckoning_pose_data(){
  warn("Printer for frames from sensor %d has not yet been implemented", msg.payload[0]);
}

void print_last_frame(){
  switch (last_received) {
    case ACCELEROMETER:
      print_accelerometer_data();
      break;
    case GYROSCOPE:
      print_gyroscope_data();
      break;
    case MAGNETIC_FIELD:
      print_magnetic_field_data();
      break;
    case LINEAR_ACCELERATION:
      print_linear_acceleration_data();
      break;
    case ROTATION_VECTOR:
      print_rotation_vector_data();
      break;
    case GRAVITY:
      print_gravity_data();
      break;
    case UNCALIBRATED_GYROSCOPE:
      print_uncalibrated_gyroscope_data();
      break;
    case GAME_ROTATION_VECTOR:
      print_game_rotation_vector_data();
      break;
    case GEOMAGNETIC_ROTATION_VECTOR:
      print_geomagnetic_rotation_vector_data();
      break;
    case PRESSURE:
      print_pressure_data();
      break;
    case AMBIENT_LIGHT:
      print_ambient_light_data();
      break;
    case HUMIDITY:
      print_humidity_data();
      break;
    case PROXIMITY:
      print_proximity_data();
      break;
    case TEMPERATURE:
      print_temperature_data();
      break;
    case UNCALIBRATED_MAGNETIC_FIELD:
      print_uncalibrated_magnetic_field_data();
      break;
    case TAP_DETECTOR:
      print_tap_detector_data();
      break;
    case STEP_COUNTER:
      print_step_counter_data();
      break;
    case SIGNIFICANT_MOTION:
      print_significant_motion_data();
      break;
    case STABILITY_CLASSIFIER:
      print_stability_classifier_data();
      break;
    case RAW_ACCELEROMETER:
      print_raw_accelerometer_data();
      break;
    case RAW_GYROSCOPE:
      print_raw_gyroscope_data();
      break;
    case RAW_MAGNETOMETER:
      print_raw_magnetometer_data();
      break;
    case STEP_DETECTOR:
      print_step_detector_data();
      break;
    case SHAKE_DETECTOR:
      print_shake_detector_data();
      break;
    case FLIP_DETECTOR:
      print_flip_detector_data();
      break;
    case PICKUP_DETECTOR:
      print_pickup_detector_data();
      break;
    case STABILITY_DETECTOR:
      print_stability_detector_data();
      break;
    case PERSONAL_ACTIVITY_CLASSIFIER:
      print_personal_activity_classifier_data();
      break;
    case SLEEP_DETECTOR:
      print_sleep_detector_data();
      break;
    case TILT_DETECTOR:
      print_tilt_detector_data();
      break;
    case POCKET_DETECTOR:
      print_pocket_detector_data();
      break;
    case CIRCLE_DETECTOR:
      print_circle_detector_data();
      break;
    case HEART_RATE_MONITOR:
      print_heart_rate_monitor_data();
      break;
    case ARVR_STABILISED_ROTATION_VECTOR:
      print_arvr_stabilised_rotation_vector_data();
      break;
    case ARVR_STABILISED_GAME_ROTATION_VECTOR:
      print_arvr_stabilised_game_rotation_vector_data();
      break;
    case GYRO_INTEGRATED_ROTATION_VECTOR:
      print_gyro_integrated_rotation_vector_data();
      break;
    case MOTION_REQUEST:
      print_motion_request_data();
      break;
    case OPTICAL_FLOW:
      warn("Optical flow frames are not supported\n");
      break;
    case DEAD_RECKONING_POSE:
      print_dead_reckoning_pose_data();
      break;
    default:
      warn("Unrecognised sensor msg.payload[0] - %d", msg.payload[0]);
      break;
  }
}