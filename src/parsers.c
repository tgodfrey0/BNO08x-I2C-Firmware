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

void parse_msg(struct i2c_message msg){
  uint8_t id = msg.payload[0];
  switch (id) {
    case ACCELEROMETER:
      break;
    case GYROSCOPE:
      break;
    case MAGNETIC_FIELD:
      break;
    case LINEAR_ACCELERATION:
      break;
    case ROTATION_VECTOR:
      break;
    case GRAVITY:
      break;
    case UNCALIBRATED_GYROSCOPE:
      break;
    case GAME_ROTATION_VECTOR:
      break;
    case GEOMAGNETIC_ROTATION_VECTOR:
      break;
    case PRESSURE:
      break;
    case AMBIENT_LIGHT:
      break;
    case HUMIDITY:
      break;
    case PROXIMITY:
      break;
    case TEMPERATURE:
      break;
    case UNCALIBRATED_MAGNETIC_FIELD:
      break;
    case TAP_DETECTOR:
      break;
    case STEP_COUNTER:
      break;
    case SIGNIFICANT_MOTION:
      break;
    case STABILITY_CLASSIFIER:
      break;
    case RAW_ACCELEROMETER:
      break;
    case RAW_GYROSCOPE:
      break;
    case RAW_MAGNETOMETER:
      break;
    case RESERVED:
      break;
    case STEP_DETECTOR:
      break;
    case SHAKE_DETECTOR:
      break;
    case FLIP_DETECTOR:
      break;
    case PICKUP_DETECTOR:
      break;
    case STABILITY_DETECTOR:
      break;
    case PERSONAL_ACTIVITY_CLASSIFIER:
      break;
    case SLEEP_DETECTOR:
      break;
    case TILT_DETECTOR:
      break;
    case POCKET_DETECTOR:
      break;
    case CIRCLE_DETECTOR:
      break;
    case HEART_RATE_MONITOR:
      break;
    case ARVR_STABILISED_ROTATION_VECTOR:
      break;
    case ARVR_STABILISED_GAME_ROTATION_VECTOR:
      break;
    case GYRO_INTEGRATED_ROTATION_VECTOR:
      break;
    case MOTION_REQUEST:
      break;
    case OPTICAL_FLOW:
      break;
    case DEAD_RECKONING_POSE:
      break;
    default:
      break;
  }
}