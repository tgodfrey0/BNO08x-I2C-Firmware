#include "sensors.h"

void init_sensors(){

  struct sensor accelerometer = {
    .name = "Accelerometer",
    .id = ACCELEROMETER,
    .channel = 255,
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

  struct sensor gyroscope = {
    .name = "Gyroscope",
    .id = GYROSCOPE,
    .channel = 255,
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

  struct sensor magnetic_field = {
    .name = "Magnetic Field",
    .id = MAGNETIC_FIELD,
    .channel = 255,
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

  struct sensor linear_acceleration = {
    .name = "Linear Acceleration",
    .id = LINEAR_ACCELERATION,
    .channel = 255,
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

  struct sensor rotation_vector = {
    .name = "Rotation Vector",
    .id = ROTATION_VECTOR,
    .channel = 255,
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

  struct sensor gravity = {
    .name = "Gravity",
    .id = GRAVITY,
    .channel = 255,
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

  struct sensor uncalibrated_gyroscope = {
    .name = "Uncalibrated Gyroscope",
    .id = UNCALIBRATED_GYROSCOPE,
    .channel = 255,
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

  struct sensor game_rotation_vector = {
    .name = "Game Rotation Vector",
    .id = GAME_ROTATION_VECTOR,
    .channel = 255,
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

  struct sensor geomagnetic_rotation_vector = {
    .name = "Geomagnetic Rotation Vector",
    .id = GEOMAGNETIC_ROTATION_VECTOR,
    .channel = 255,
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

  struct sensor pressure = {
    .name = "Pressure",
    .id = PRESSURE,
    .channel = 255,
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

  struct sensor ambient_light = {
    .name = "Ambient Light",
    .id = AMBIENT_LIGHT,
    .channel = 255,
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

  struct sensor humidity = {
    .name = "Humidity",
    .id = HUMIDITY,
    .channel = 255,
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

  struct sensor proximity = {
    .name = "Proximity",
    .id = PROXIMITY,
    .channel = 255,
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

  struct sensor temperature = {
    .name = "Temperature",
    .id = TEMPERATURE,
    .channel = 255,
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

  struct sensor uncalibrated_magnetic_field = {
    .name = "Uncalibrated Magnetic Field",
    .id = UNCALIBRATED_MAGNETIC_FIELD,
    .channel = 255,
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

  struct sensor tap_detector = {
    .name = "Tap Detector",
    .id = TAP_DETECTOR,
    .channel = 255,
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

  struct sensor step_counter = {
    .name = "Step Counter",
    .id = STEP_COUNTER,
    .channel = 255,
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

  struct sensor significant_motion = {
    .name = "Significant Motion",
    .id = SIGNIFICANT_MOTION,
    .channel = 255,
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

  struct sensor stability_classifier = {
    .name = "Stability Classifier",
    .id = STABILITY_CLASSIFIER,
    .channel = 255,
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

  struct sensor raw_accelerometer = {
    .name = "Raw Accelerometer",
    .id = RAW_ACCELEROMETER,
    .channel = 255,
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

  struct sensor raw_gyroscope = {
    .name = "Raw Gyroscope",
    .id = RAW_GYROSCOPE,
    .channel = 255,
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

  struct sensor raw_magnetometer = {
    .name = "Raw Magnetometer",
    .id = RAW_MAGNETOMETER,
    .channel = 255,
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

  struct sensor step_detector = {
    .name = "Step Detector",
    .id = STEP_DETECTOR,
    .channel = 0,
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

  struct sensor shake_detector = {
    .name = "Shake Detector",
    .id = SHAKE_DETECTOR,
    .channel = 255,
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

  struct sensor flip_detector = {
    .name = "Flip Detector",
    .id = FLIP_DETECTOR,
    .channel = 255,
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

  struct sensor pickup_detector = {
    .name = "Pickup Detector",
    .id = PICKUP_DETECTOR,
    .channel = 255,
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

  struct sensor stability_detector = {
    .name = "Stability Detector",
    .id = STABILITY_DETECTOR,
    .channel = 255,
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

  struct sensor personal_activity_classifier = {
    .name = "Personal Activity Classifier",
    .id = PERSONAL_ACTIVITY_CLASSIFIER,
    .channel = 255,
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

  struct sensor sleep_detector = {
    .name = "Sleep Detector",
    .id = SLEEP_DETECTOR,
    .channel = 255,
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

  struct sensor tilt_detector = {
    .name = "Tilt Detector",
    .id = TILT_DETECTOR,
    .channel = 255,
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

  struct sensor pocket_detector = {
    .name = "Pocket Detector",
    .id = POCKET_DETECTOR,
    .channel = 255,
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

  struct sensor circle_detector = {
    .name = "Circle Detector",
    .id = CIRCLE_DETECTOR,
    .channel = 255,
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

  struct sensor heart_rate_monitor = {
    .name = "Heart Rate Monitor",
    .id = HEART_RATE_MONITOR,
    .channel = 255,
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

  struct sensor arvr_stabilised_rotation_vector = {
    .name = "ARVR Stabilised Rotation Vector",
    .id = ARVR_STABILISED_ROTATION_VECTOR,
    .channel = 255,
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

  struct sensor arvr_stabilised_game_rotation_vector = {
    .name = "ARVR Stabilised Game Rotation Vector",
    .id = ARVR_STABILISED_GAME_ROTATION_VECTOR,
    .channel = 255,
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

  struct sensor gyro_integrated_rotation_vector = {
    .name = "Gyro-Integrated Rotation Vector",
    .id = GYRO_INTEGRATED_ROTATION_VECTOR,
    .channel = 255,
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

  struct sensor motion_request = {
    .name = "Motion Request",
    .id = MOTION_REQUEST,
    .channel = 255,
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

  struct sensor dead_reckoning_pose = {
    .name = "Dead Reckoning Pose",
    .id = DEAD_RECKONING_POSE,
    .channel = 255,
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
}