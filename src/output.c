#include "bno08x.h"
#include "logger.h"
#include "output.h"
#include "sensors.h"

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

void print_accelerometer_data(struct sensor_collection* sc){
  data("Accelerometer Frame:\n");
  data("\tSensor status is \"%s\", delay is %d us\n", print_status(sc->accelerometer.input_report.accelerometer.status), (sc->accelerometer.input_report.accelerometer.delay * 100));
  data("\t(x, y, z) m/s^2: (%d, %d, %d) m/s^2\n", sc->accelerometer.input_report.accelerometer.x, sc->accelerometer.input_report.accelerometer.y, sc->accelerometer.input_report.accelerometer.z);
  data_quiet("\n");
}

void print_gyroscope_data(struct sensor_collection* sc){
  data("Gyroscope Frame:\n");
  data("\tSensor status is \"%s\", delay is %d us\n", print_status(sc->gyroscope.input_report.gyroscope.status), (sc->gyroscope.input_report.gyroscope.delay * 100));
  data("\t(x, y, z) rad/s: (%d, %d, %d) rad/s\n", sc->gyroscope.input_report.gyroscope.x, sc->gyroscope.input_report.gyroscope.y, sc->gyroscope.input_report.gyroscope.z);
  data_quiet("\n");
}

void print_magnetic_field_data(struct sensor_collection* sc){
  data("Magnetic Field Frame:\n");
  data("\tSensor status is \"%s\", delay is %d us\n", print_status(sc->magnetic_field.input_report.magnetic_field.status), (sc->magnetic_field.input_report.magnetic_field.delay * 100));
  data("\t(x, y, z) uT: (%d, %d, %d) uT\n", sc->magnetic_field.input_report.magnetic_field.x, sc->magnetic_field.input_report.magnetic_field.y, sc->magnetic_field.input_report.magnetic_field.z);
  data_quiet("\n");
}

void print_linear_acceleration_data(struct sensor_collection* sc){
  data("Linear Accelerometer Frame:\n");
  data("\tSensor status is \"%s\", delay is %d us\n", print_status(sc->linear_acceleration.input_report.linear_acceleration.status), (sc->linear_acceleration.input_report.linear_acceleration.delay * 100));
  data("\t(x, y, z) m/s^2: (%d, %d, %d) m/s^2\n", sc->linear_acceleration.input_report.linear_acceleration.x, sc->linear_acceleration.input_report.linear_acceleration.y, sc->linear_acceleration.input_report.linear_acceleration.z);
  data_quiet("\n");
}

void print_rotation_vector_data(struct sensor_collection* sc){
  data("Rotation Vector Frame:\n");
  data("\tSensor status is \"%s\", delay is %d us\n", print_status(sc->rotation_vector.input_report.rotation_vector.status), (sc->rotation_vector.input_report.rotation_vector.delay * 100));
  data("\tQuaternion: %d + %di + %dj + %dk\n", sc->rotation_vector.input_report.rotation_vector.real, sc->rotation_vector.input_report.rotation_vector.i, sc->rotation_vector.input_report.rotation_vector.j, sc->rotation_vector.input_report.rotation_vector.k);
  data("\tAccuracy: %d rad\n", sc->rotation_vector.input_report.rotation_vector.accuracy);
  data_quiet("\n");
}

void print_gravity_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", gravity->id);
}

void print_uncalibrated_gyroscope_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", uncalibrated_gyroscope->id);
}

void print_game_rotation_vector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", game_rotation_vector->id);
}

void print_geomagnetic_rotation_vector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", geomagnetic_rotation_vector->id);
}

void print_pressure_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", pressure->id);
}

void print_ambient_light_data(struct sensor_collection* sc){
  data("Ambient Light Frame:\n");
  data("\tSensor status is \"%s\", delay is %d us\n", print_status(sc->ambient_light.input_report.raw_accelerometer.status), (sc->ambient_light.input_report.raw_accelerometer.delay * 100));
  data("\tValue (lux): %d lux\n", sc->ambient_light.input_report.ambient_light.value);
  data_quiet("\n");
}

void print_humidity_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", humidity->id);
}

void print_proximity_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", proximity->id);
}

void print_temperature_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", temperature->id);
}

void print_uncalibrated_magnetic_field_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", uncalibrated_magnetic_field->id);
}

void print_tap_detector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", tap_detector->id);
}

void print_step_counter_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", step_counter->id);
}

void print_significant_motion_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", significant_motion->id);
}

void print_stability_classifier_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", stability_classifier->id);
}

void print_raw_accelerometer_data(struct sensor_collection* sc){
  data("Raw Accelerometer Frame:\n");
  data("\tSensor status is \"%s\", delay is %d us\n", print_status(sc->raw_accelerometer.input_report.raw_accelerometer.status), (sc->raw_accelerometer.input_report.raw_accelerometer.delay * 100));
  data("\t(x, y, z) ADCs: (%d, %d, %d) ADCs\n", sc->raw_accelerometer.input_report.raw_accelerometer.x, sc->raw_accelerometer.input_report.raw_accelerometer.y, sc->raw_accelerometer.input_report.raw_accelerometer.z);
  data("\tTimestamp: %d\n", sc->raw_accelerometer.input_report.raw_accelerometer.timestamp);
  data_quiet("\n");
}

void print_raw_gyroscope_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", raw_gyroscope->id);
}

void print_raw_magnetometer_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", raw_magnetometer->id);
}

void print_step_detector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", step_detector->id);
}

void print_shake_detector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", shake_detector->id);
}

void print_flip_detector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", flip_detector->id);
}

void print_pickup_detector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", pickup_detector->id);
}

void print_stability_detector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", stability_detector->id);
}

void print_personal_activity_classifier_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", personal_activity_classifier->id);
}

void print_sleep_detector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", sleep_detector->id);
}

void print_tilt_detector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", tilt_detector->id);
}

void print_pocket_detector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", pocket_detector->id);
}

void print_circle_detector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", circle_detector->id);
}

void print_heart_rate_monitor_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", heart_rate_monitor->id);
}

void print_arvr_stabilised_rotation_vector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", arvr_stabilised_rotation_vector->id);
}

void print_arvr_stabilised_game_rotation_vector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", arvr_stabilised_game_rotation_vector->id);
}

void print_gyro_integrated_rotation_vector_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", gyro_integrated_rotation_vector->id);
}

void print_motion_request_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", motion_request->id);
}

void print_dead_reckoning_pose_data(struct sensor_collection* sc){
  warn("Printer for frames from sensor 0x%x has not yet been implemented", dead_reckoning_pose->id);
}

void print_raw_cmd_res_msg(struct i2c_message msg){
  data("Raw Command Response: [");
  for(uint8_t i = 0; i < msg.length-1; i++){
    data_quiet("0x%x, ", msg.payload[i]);
  }
  data_quiet("0x%x]\n", msg.payload[msg.length - 1]);
}

void print_raw_get_feat_res_msg(struct i2c_message msg){
  data("Raw Get Feature Response: [");
  for(uint8_t i = 0; i < msg.length-1; i++){
    data_quiet("0x%x, ", msg.payload[i]);
  }
  data_quiet("0x%x]\n", msg.payload[msg.length - 1]);
}