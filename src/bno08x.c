#include <stdio.h>

#include "bno08x.h"
#include "i2c.h"
#include "logger.h"
#include "parsers.h"
#include "sensors.h"
#include "sensor_reports.h"

const uint8_t BNO08x_ADDR = 0x4A; 
uint8_t sequence_number = 0;

#include "boards/pico.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "pico/platform.h"
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"

void flashh(uint8_t n){
	for(uint8_t i = 0; i < n; i++){
		gpio_put(PICO_DEFAULT_LED_PIN, 1);
		sleep_ms(500);
		gpio_put(PICO_DEFAULT_LED_PIN, 0);
		sleep_ms(500);
	}
	sleep_ms(1000);
}

enum I2C_RESPONSE open_channel(const struct i2c_interface i2c){
  /*
   *  Byte  | Value
   *   0,1  | Length = 5
   *   2    | Channel = 1 (Executable)
   *   3    | Sequence Number = 0
   *   4    | Payload = CMD 2 (On)
   */
  uint8_t pkt[] = {5, 0, 1, get_seq_num(), 2};
  enum SENSOR_ID res;

  for(uint8_t i = 0; i < OPEN_ATTEMPTS; i++){
    res = i2c.write(BNO08x_ADDR, &(struct i2c_message) {
      .payload = pkt,
      .length = 5
    });

    if(res == SUCCESS) break;
  }

  return res; 
}

void init(const struct i2c_interface i2c){
  flashh(4);
  if(!i2c.initialised){
    crit("I2C interface must be initialised first\n");
    flashh(2);
    for(;;);
  }

  flashh(4);
  
  if(open_channel(i2c) != SUCCESS){
    crit("Failed to open channel to sensor\n");
    flashh(3);
    for(;;);
  }

  info("Sensor channel opened\n");
}

struct sensor* get_sensor(enum SENSOR_ID id){
  switch (id) {
    case ACCELEROMETER:
      return accelerometer;
    case GYROSCOPE:
      return gyroscope;
    case MAGNETIC_FIELD:
      return magnetic_field;
    case LINEAR_ACCELERATION:
      return linear_acceleration;
    case ROTATION_VECTOR:
      return rotation_vector;
    case GRAVITY:
      return gravity;
    case UNCALIBRATED_GYROSCOPE:
      return uncalibrated_gyroscope;
    case GAME_ROTATION_VECTOR:
      return game_rotation_vector;
    case GEOMAGNETIC_ROTATION_VECTOR:
      return geomagnetic_rotation_vector;
    case PRESSURE:
      return pressure;
    case AMBIENT_LIGHT:
      return ambient_light;
    case HUMIDITY:
      return humidity;
    case PROXIMITY:
      return proximity;
    case TEMPERATURE:
      return temperature;
    case UNCALIBRATED_MAGNETIC_FIELD:
      return uncalibrated_magnetic_field;
    case TAP_DETECTOR:
      return tap_detector;
    case STEP_COUNTER:
      return step_counter;
    case SIGNIFICANT_MOTION:
      return significant_motion;
    case STABILITY_CLASSIFIER:
      return stability_classifier;
    case RAW_ACCELEROMETER:
      return raw_accelerometer;
    case RAW_GYROSCOPE:
      return raw_gyroscope;
    case RAW_MAGNETOMETER:
      return raw_magnetometer;
    case STEP_DETECTOR:
      return step_detector;
    case SHAKE_DETECTOR:
      return shake_detector;
    case FLIP_DETECTOR:
      return flip_detector;
    case PICKUP_DETECTOR:
      return pickup_detector;
    case STABILITY_DETECTOR:
      return stability_detector;
    case PERSONAL_ACTIVITY_CLASSIFIER:
      return personal_activity_classifier;
    case SLEEP_DETECTOR:
      return sleep_detector;
    case TILT_DETECTOR:
      return tilt_detector;
    case POCKET_DETECTOR:
      return pocket_detector;
    case CIRCLE_DETECTOR:
      return circle_detector;
    case HEART_RATE_MONITOR:
      return heart_rate_monitor;
    case ARVR_STABILISED_ROTATION_VECTOR:
      return arvr_stabilised_rotation_vector;
    case ARVR_STABILISED_GAME_ROTATION_VECTOR:
      return arvr_stabilised_game_rotation_vector;
    case GYRO_INTEGRATED_ROTATION_VECTOR:
      return gyro_integrated_rotation_vector;
    case MOTION_REQUEST:
      return motion_request;
    case OPTICAL_FLOW:
      warn("Optical flow frames are not supported\n");
      return NULL;
    case DEAD_RECKONING_POSE:
      return dead_reckoning_pose;
    default:
      warn("Unrecognised sensor msg.payload[0] - %d", id);
      return NULL;
  }
}

void populate_struct(enum SENSOR_ID id){
  switch (id) {
    case ACCELEROMETER:
      accelerometer = &(struct sensor) {
        .name = "Accelerometer",
        .id = id
      };
      break;
    case GYROSCOPE:
      gyroscope = &(struct sensor) {
        .name = "Gyroscope",
        .id = id
      };
      break;
    case MAGNETIC_FIELD:
      magnetic_field = &(struct sensor) {
        .name = "Magnetic Field",
        .id = id
      };
      break;
    case LINEAR_ACCELERATION:
      linear_acceleration = &(struct sensor) {
        .name = "Linear Acceleration",
        .id = id
      };
      break;
    case ROTATION_VECTOR:
      rotation_vector = &(struct sensor) {
        .name = "Rotation Vector",
        .id = id
      };
      break;
    case GRAVITY:
      gravity = &(struct sensor) {
        .name = "Gravity",
        .id = id
      };
      break;
    case UNCALIBRATED_GYROSCOPE:
      uncalibrated_gyroscope = &(struct sensor) {
        .name = "Uncalibrated Gyroscope",
        .id = id
      };
      break;
    case GAME_ROTATION_VECTOR:
      game_rotation_vector = &(struct sensor) {
        .name = "Game Rotation Vector",
        .id = id
      };
      break;
    case GEOMAGNETIC_ROTATION_VECTOR:
      geomagnetic_rotation_vector = &(struct sensor) {
        .name = "Geomagnetic Rotation Vector",
        .id = id
      };
      break;
    case PRESSURE:
      pressure = &(struct sensor) {
        .name = "Pressure",
        .id = id
      };
      break;
    case AMBIENT_LIGHT:
      ambient_light = &(struct sensor) {
        .name = "Ambient Light",
        .id = id
      };
      break;
    case HUMIDITY:
      humidity = &(struct sensor) {
        .name = "Humidity",
        .id = id
      };
      break;
    case PROXIMITY:
      proximity = &(struct sensor) {
        .name = "Proximity",
        .id = id
      };
      break;
    case TEMPERATURE:
      temperature = &(struct sensor) {
        .name = "Temperature",
        .id = id
      };
      break;
    case UNCALIBRATED_MAGNETIC_FIELD:
      uncalibrated_magnetic_field = &(struct sensor) {
        .name = "Uncalibrated Magnetic Field",
        .id = id
      };
      break;
    case TAP_DETECTOR:
      tap_detector = &(struct sensor) {
        .name = "Tap Detector",
        .id = id
      };
      break;
    case STEP_COUNTER:
      step_counter = &(struct sensor) {
        .name = "Step Counter",
        .id = id
      };
      break;
    case SIGNIFICANT_MOTION:
      significant_motion = &(struct sensor) {
        .name = "Significant Motion",
        .id = id
      };
      break;
    case STABILITY_CLASSIFIER:
      stability_classifier = &(struct sensor) {
        .name = "Stability Classifier",
        .id = id
      };
      break;
    case RAW_ACCELEROMETER:
      raw_accelerometer = &(struct sensor) {
        .name = "Raw Accelerometer",
        .id = id
      };
      break;
    case RAW_GYROSCOPE:
      raw_gyroscope = &(struct sensor) {
        .name = "Raw Gyroscope",
        .id = id
      };
      break;
    case RAW_MAGNETOMETER:
      raw_magnetometer = &(struct sensor) {
        .name = "Raw Magnetometer",
        .id = id
      };
      break;
    case STEP_DETECTOR:
      step_detector = &(struct sensor) {
        .name = "Step Detector",
        .id = id
      };
      break;
    case SHAKE_DETECTOR:
      shake_detector = &(struct sensor) {
        .name = "Shake Detector",
        .id = id
      };
      break;
    case FLIP_DETECTOR:
      flip_detector = &(struct sensor) {
        .name = "Flip Detector",
        .id = id
      };
      break;
    case PICKUP_DETECTOR:
      pickup_detector = &(struct sensor) {
        .name = "Pickup Detector",
        .id = id
      };
      break;
    case STABILITY_DETECTOR:
      stability_detector = &(struct sensor) {
        .name = "Stability Detector",
        .id = id
      };
      break;
    case PERSONAL_ACTIVITY_CLASSIFIER:
      personal_activity_classifier = &(struct sensor) {
        .name = "Personal Activity Classifier",
        .id = id
      };
      break;
    case SLEEP_DETECTOR:
      sleep_detector = &(struct sensor) {
        .name = "Sleep Detector",
        .id = id
      };
      break;
    case TILT_DETECTOR:
      tilt_detector = &(struct sensor) {
        .name = "Tilt Detector",
        .id = id
      };
      break;
    case POCKET_DETECTOR:
      pocket_detector = &(struct sensor) {
        .name = "Pocket Detector",
        .id = id
      };
      break;
    case CIRCLE_DETECTOR:
      circle_detector = &(struct sensor) {
        .name = "Circle Detector",
        .id = id
      };
      break;
    case HEART_RATE_MONITOR:
      heart_rate_monitor = &(struct sensor) {
        .name = "Heart Rate Monitor",
        .id = id
      };
      break;
    case ARVR_STABILISED_ROTATION_VECTOR:
      arvr_stabilised_rotation_vector = &(struct sensor) {
        .name = "ARVR Stabilised Rotation Vector",
        .id = id
      };
      break;
    case ARVR_STABILISED_GAME_ROTATION_VECTOR:
      arvr_stabilised_game_rotation_vector = &(struct sensor) {
        .name = "ARVR Stabilised Game Rotation Vector",
        .id = id
      };
      break;
    case GYRO_INTEGRATED_ROTATION_VECTOR:
      gyro_integrated_rotation_vector = &(struct sensor) {
        .name = "Gyro-Integrated Rotation Vector",
        .id = id
      };
      break;
    case MOTION_REQUEST:
      motion_request = &(struct sensor) {
        .name = "Motion Request",
        .id = id
      };
      break;
    case OPTICAL_FLOW:
      warn("Optical flow frames are not supported\n");
      break;
    case DEAD_RECKONING_POSE:
      dead_reckoning_pose = &(struct sensor) {
        .name = "Dead Reckoning Pose",
        .id = id
      };
      break;
    default:
      warn("Unrecognised sensor msg.payload[0] - %d", id);
      return;
  }

  info("Struct for sensor with ID 0x%x has been created\n", id);
}

bool enable_sensor(const struct i2c_interface i2c, enum SENSOR_ID id, uint32_t sample_rate_ms){
  populate_struct(id);

  uint64_t period_us = sample_rate_ms * 1000;

  uint8_t period[4];
  period[0] = period_us & 0xFF;
  period[1] = (period_us >> 8) & 0xFF;
  period[2] = (period_us >> 16) & 0xFF;
  period[3] = (period_us >> 24) & 0xFF;

  uint8_t pkt[] = {
    0x15, // Length LSB
    0x00, // Length MSB
    0x02, // Channel
    get_seq_num(),
    0xFD, // Report ID
    id,
    0, // Feature flags
    0, // Change sensitivity LSB
    0, // Change sensitivity MSB
    period[0], // Report interval LSB
    period[1],
    period[2],
    period[3], // Report interval MSB
    0, // Batch interval LSB
    0,
    0,
    0, // Batch interval MSB
    0, // Sensor-specific configuration word LSB
    0,
    0,
    0  // Sensor-specific configuration word MSB
  };

  enum I2C_RESPONSE res = i2c.write(BNO08x_ADDR, &(struct i2c_message) {
    .payload = pkt,
    .length = 0x15
  });

  if(res == ERROR_GENERIC || res == ERROR_TIMEOUT){
    warn("%s could not be enabled\n", get_sensor(id)->name);
    return false;
  } else {
    info("%s has been successfully enabled\n", get_sensor(id)->name);
    return true;
  }
}

bool read_sensors(const struct i2c_interface i2c){
  enum I2C_RESPONSE res;

  uint8_t header_content[4];

  struct i2c_message header = {
    .payload = header_content,
    .length = 0
  };

  res = i2c.read(BNO08x_ADDR, &header, 4);

  if(res != SUCCESS){
    warn("Failed to read header\n");
    return false;
  }

  if(header.length != 4){
    warn("Failed to read full header. 4 bytes should be read, but %d bytes were read\n", header.length);
    return false;
  }

  uint16_t cargo_length = (header.payload[0] | (header.payload[1] << 8)) & ~0x8000;
  uint8_t cargo_content[cargo_length];

  struct i2c_message cargo = {
    .payload = cargo_content,
    .length = 0
  };

  res = i2c.read(BNO08x_ADDR, &cargo, cargo_length);

  if(res != SUCCESS){
    warn("Failed to read cargo\n");
    return false;
  }

  if(cargo.length != cargo_length){
    warn("Failed to read full cargo, expected %d bytes but received %d bytes\n", cargo_length, cargo.length);
    return false;
  }

  parse_msg(cargo);

  return true;
}