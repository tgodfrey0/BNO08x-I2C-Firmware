/****************************************************************************************************
* @file bno08x.c
* @brief BNO08x related implementations
*
* @author Toby Godfrey
****************************************************************************************************/

#include "bno08x.h"
#include "i2c.h"
#include "sensor_reports.h"

const uint8_t BNO08x_ADDR = 0x4A; 
uint8_t sequence_number = 0;

bool enable_sensor(const struct i2c_interface i2c, struct sensor* sensor, uint32_t sample_rate_ms){
  uint64_t period_us = sample_rate_ms * 1000;

  uint8_t len = 4;

  uint8_t period[len];
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
    sensor->id,
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
    .length = &len
  });

  if(res == ERROR_GENERIC || res == ERROR_TIMEOUT){
    return false;
  } else {
    sensor->enabled = true;
    return true;
  }
}


bool read_sensor(struct sensor* sensor){
  return false;
}