/****************************************************************************************************
* @file bno08x.c
* @brief BNO08x related implementations
*
* @author Toby Godfrey
****************************************************************************************************/

#include <stdio.h>

#include "bno08x.h"
#include "i2c.h"
#include "sensor_reports.h"

const uint8_t BNO08x_ADDR = 0x4A; 
uint8_t sequence_number = 0;

bool enable_sensor(const struct i2c_interface i2c, struct sensor* sensor, uint32_t sample_rate_ms){
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
    .length = 0x15
  });

  if(res == ERROR_GENERIC || res == ERROR_TIMEOUT){
    printf("%s could not be enabled\n", sensor->name);
    return false;
  } else {
    printf("%s has been successfully enabled\n", sensor->name);
    sensor->enabled = true;
    return true;
  }
}


bool read_sensor(const struct i2c_interface i2c, struct sensor* sensor){
  enum I2C_RESPONSE res;

#if !defined(MAX_PAYLOAD_SIZE)
  #warning MAX_PAYLOAD_SIZE required
  puts("MAX_PAYLOAD_SIZE must be defined\n");
  return false;
#endif

  uint8_t header_content[4];

  struct i2c_message header = {
    .payload = header_content,
    .length = 0
  };

  res = i2c.read(BNO08x_ADDR, &header, 4);

  if(res == ERROR_GENERIC || ERROR_TIMEOUT){
    printf("Failed to read header\n");
    return false;
  }

  if(header.length != 4){
    printf("Failed to read full header. 4 bytes should be read, but %d bytes were read\n", header.length);
    return false;
  }

  uint16_t cargo_length = header.payload[0] | (header.payload[1] << 8);
  uint8_t cargo_content[cargo_length];

  struct i2c_message cargo = {
    .payload = cargo_content,
    .length = 0
  };

  res = i2c.read(BNO08x_ADDR, &cargo, cargo_length);

  if(res == ERROR_GENERIC || res == ERROR_TIMEOUT){
    printf("Failed to read cargo\n");
    return false;
  }

  if(cargo.length != cargo_length){
    printf("Failed to read full cargo, expected %d bytes but received %d bytes\n", cargo_length, cargo.length);
    return false;
  }

  

  return true;
}