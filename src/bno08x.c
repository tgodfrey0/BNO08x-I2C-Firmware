#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bno08x.h"
#include "i2c.h"
#include "logger.h"
#include "output.h"
#include "parsers.h"
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

struct sensor_collection populate_struct(){
  struct sensor_collection sc = {
    .accelerometer = (struct sensor) {
      .name = "Accelerometer",
      .id = ACCELEROMETER,
      .enabled = false
    },
    .gyroscope = (struct sensor) {
      .name = "Gyroscope",
      .id = GYROSCOPE,
      .enabled = false
    },
    .magnetic_field = (struct sensor) {
      .name = "Magnetic Field",
      .id = MAGNETIC_FIELD,
      .enabled = false
    },
    .linear_acceleration = (struct sensor) {
      .name = "Linear Acceleration",
      .id = LINEAR_ACCELERATION,
      .enabled = false
    },
    .rotation_vector = (struct sensor) {
      .name = "Rotation Vector",
      .id = ROTATION_VECTOR,
      .enabled = false
    },
    .gravity = (struct sensor) {
      .name = "Gravity",
      .id = GRAVITY,
      .enabled = false
    },
    .uncalibrated_gyroscope = (struct sensor) {
      .name = "Uncalibrated Gyroscope",
      .id = UNCALIBRATED_GYROSCOPE,
      .enabled = false
    },
    .game_rotation_vector = (struct sensor) {
      .name = "Game Rotation Vector",
      .id = GAME_ROTATION_VECTOR,
      .enabled = false
    },
    .geomagnetic_rotation_vector = (struct sensor) {
      .name = "Geomagnetic Rotation Vector",
      .id = GEOMAGNETIC_ROTATION_VECTOR,
      .enabled = false
    },
    .pressure = (struct sensor) {
      .name = "Pressure",
      .id = PRESSURE,
      .enabled = false
    },
    .ambient_light = (struct sensor) {
      .name = "Ambient Light",
      .id = AMBIENT_LIGHT,
      .enabled = false
    },
    .humidity = (struct sensor) {
      .name = "Humidity",
      .id = HUMIDITY,
      .enabled = false
    },
    .proximity = (struct sensor) {
      .name = "Proximity",
      .id = PROXIMITY,
      .enabled = false
    },
    .temperature = (struct sensor) {
      .name = "Temperature",
      .id = TEMPERATURE,
      .enabled = false
    },
    .uncalibrated_magnetic_field = (struct sensor) {
      .name = "Uncalibrated Magnetic Field",
      .id = UNCALIBRATED_GYROSCOPE,
      .enabled = false
    },
    .tap_detector = (struct sensor) {
      .name = "Tap Detector",
      .id = TAP_DETECTOR,
      .enabled = false
    },
    .step_counter = (struct sensor) {
      .name = "Step Counter",
      .id = STEP_COUNTER,
      .enabled = false
    },
    .significant_motion = (struct sensor) {
      .name = "Significant Motion",
      .id = SIGNIFICANT_MOTION,
      .enabled = false
    },
    .stability_classifier = (struct sensor) {
      .name = "Stability Classifier",
      .id = STABILITY_CLASSIFIER,
      .enabled = false
    },
    .raw_accelerometer = (struct sensor) {
      .name = "Raw Accelerometer",
      .id = RAW_ACCELEROMETER,
      .enabled = false
    },
    .raw_gyroscope = (struct sensor) {
      .name = "Raw Gyroscope",
      .id = RAW_GYROSCOPE,
      .enabled = false
    },
    .raw_magnetometer = (struct sensor) {
      .name = "Raw Magnetometer",
      .id = RAW_MAGNETOMETER,
      .enabled = false
    },
    .step_detector = (struct sensor) {
      .name = "Step Detector",
      .id = STEP_DETECTOR,
      .enabled = false
    },
    .shake_detector = (struct sensor) {
      .name = "Shake Detector",
      .id = SHAKE_DETECTOR,
      .enabled = false
    },
    .flip_detector = (struct sensor) {
      .name = "Flip Detector",
      .id = FLIP_DETECTOR,
      .enabled = false
    },
    .pickup_detector = (struct sensor) {
      .name = "Pickup Detector",
      .id = PICKUP_DETECTOR,
      .enabled = false
    },
    .stability_detector = (struct sensor) {
      .name = "Stability Detector",
      .id = STABILITY_DETECTOR,
      .enabled = false
    },
    .personal_activity_classifier = (struct sensor) {
      .name = "Personal Activity Classifier",
      .id = PERSONAL_ACTIVITY_CLASSIFIER,
      .enabled = false
    },
    .sleep_detector = (struct sensor) {
      .name = "Sleep Detector",
      .id = SLEEP_DETECTOR,
      .enabled = false
    },
    .tilt_detector = (struct sensor) {
      .name = "Tilt Detector",
      .id = TILT_DETECTOR,
      .enabled = false
    },
    .pocket_detector = (struct sensor) {
      .name = "Pocket Detector",
      .id = POCKET_DETECTOR,
      .enabled = false
    },
    .circle_detector = (struct sensor) {
      .name = "Circle Detector",
      .id = CIRCLE_DETECTOR,
      .enabled = false
    },
    .heart_rate_monitor = (struct sensor) {
      .name = "Heart Rate Monitor",
      .id = HEART_RATE_MONITOR,
      .enabled = false
    },
    .arvr_stabilised_rotation_vector = (struct sensor) {
      .name = "ARVR Stabilised Rotation Vector",
      .id = ARVR_STABILISED_ROTATION_VECTOR,
      .enabled = false
    },
    .arvr_stabilised_game_rotation_vector = (struct sensor) {
      .name = "ARVR Stabilised Game Rotation Vector",
      .id = ARVR_STABILISED_GAME_ROTATION_VECTOR,
      .enabled = false
    },
    .gyro_integrated_rotation_vector = (struct sensor) {
      .name = "Gyro-Integrated Rotation Vector",
      .id = GYRO_INTEGRATED_ROTATION_VECTOR,
      .enabled = false
    },
    .motion_request = (struct sensor) {
      .name = "Motion Request",
      .id = MOTION_REQUEST,
      .enabled = false
    },
    .dead_reckoning_pose = (struct sensor) {
      .name = "Dead Reckoning Pose",
      .id = DEAD_RECKONING_POSE,
      .enabled = false
    }
  };

  return sc;
}

enum I2C_RESPONSE open_channel(const struct i2c_interface* i2c){
  /*
   *  Byte  | Value
   *   0,1  | Length = 5
   *   2    | Channel = 1 (Executable)
   *   3    | Sequence Number = 0
   *   4    | Payload = CMD 2 (On)
   */
  uint8_t pkt[] = {5, 0, 1, get_seq_num(), 2};
  enum REPORT_ID res;

  struct i2c_message msg = create_msg(pkt, 5);

  for(uint8_t i = 0; i < OPEN_ATTEMPTS; i++){
    res = i2c->write(BNO08x_ADDR, &msg);

    if(res == SUCCESS) break;
  }

  return res; 
}

struct sensor_collection init(const struct i2c_interface* i2c){
  if(!i2c->initialised){
    crit("I2C interface must be initialised first\n");
    for(;;);
  }
  
  if(open_channel(i2c) != SUCCESS){
    crit("Failed to open channel to sensor\n");
    for(;;);
  }

  info("Sensor channel opened\n");

  return populate_struct();
}

bool enable_sensor(const struct i2c_interface* i2c, struct sensor_collection* sc, const enum REPORT_ID id, const uint32_t sample_rate_ms){

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

  struct i2c_message msg;
  memcpy(msg.payload, pkt, 0x15);
  msg.length = 0x15;

  enum I2C_RESPONSE res = i2c->write(BNO08x_ADDR, &msg);

  if(res == ERROR_GENERIC || res == ERROR_TIMEOUT){
    warn("Sensor 0x%x could not be enabled\n", id);
    return false;
  } else {
    info("Sensor 0x%x has been successfully enabled\n", id);
    return true;
  }
}

bool read_sensors(const struct i2c_interface* i2c, struct sensor_collection* sc){
  struct i2c_message head;

  if (i2c->read(BNO08x_ADDR, &head, 4) != SUCCESS) {
    warn("Failed to read header\n");
    return false;
  }

  // Determine amount to read
  uint16_t packet_size = (uint16_t)head.payload[0] | (uint16_t)head.payload[1] << 8;
  // Unset the "continue" bit
  packet_size &= ~0x8000u;
  debug("Packet size:     %d / 0x%x\n", packet_size, packet_size);

  if (packet_size > MAX_PAYLOAD_SIZE) {
    warn("Packet too large for buffer\n");
    return false;
  }

  // the number of non-header bytes to read
  uint16_t cargo_remaining = packet_size;
  uint16_t read_size;
  uint16_t cargo_read_amount = 0;
  bool first_read = true;

  struct i2c_message cargo_tmp;
  uint8_t* cargo_ptr = cargo_tmp.payload;
  struct i2c_message final;
  uint8_t* final_ptr = final.payload;

  while (cargo_remaining > 0) {
    if (first_read) {
      read_size = min(MAX_PAYLOAD_SIZE, (uint32_t)cargo_remaining);
    } else {
      read_size = min(MAX_PAYLOAD_SIZE, (uint32_t)cargo_remaining + 4);
    }

    debug("Reading from I2C: %d\n", read_size);
    debug("Remaining to read: %d\n", cargo_remaining);

    if (i2c->read(BNO08x_ADDR, &cargo_tmp, read_size) != SUCCESS) {
      warn("Failed to read the remaining data\n");
      return false;
    }

    if (first_read) {
      // If it's the first time we need to save the header
      cargo_read_amount = read_size;
      memcpy(final_ptr, cargo_ptr, cargo_read_amount);
      first_read = false;
    } else {
      // We can now skip the header
      cargo_read_amount = read_size - 4;
      memcpy(final_ptr, cargo_ptr + 4, cargo_read_amount);
    }
    final_ptr += cargo_read_amount;
    cargo_remaining -= cargo_read_amount;
  }

  final.length = packet_size;

  info("Data successfully read from bus: [");
  for(uint8_t i = 0; i < final.length-1; i++) info_quiet("0x%x, ", final.payload[i]);
  info_quiet("0x%x]\n", final.payload[final.length-1]);

  return parse_msg(sc, final);
}