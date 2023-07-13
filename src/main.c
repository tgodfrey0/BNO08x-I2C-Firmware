#include <string.h>

#include "boards/pico.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "pico/platform.h"
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#include "bno08x.h"
#include "defs.h"
#include "i2c.h"
#include "logger.h"
#include "output.h"

enum I2C_RESPONSE write_i2c(const uint8_t addr, const struct i2c_message* message){
	if(i2c_write_blocking(I2C_INST, addr, message->payload, message->length, false) != PICO_ERROR_GENERIC){
		return SUCCESS;
  } else return ERROR_GENERIC;
}

enum I2C_RESPONSE read_i2c(const uint8_t addr, struct i2c_message* message, const uint16_t n){
	uint8_t buf[n];

	uint8_t res = i2c_read_blocking(I2C_INST, addr, buf, n, false);

  if(res == PICO_ERROR_GENERIC){
    return ERROR_GENERIC;
  } else {
    memcpy(message->payload, buf, n);
		message->length = n;
		return SUCCESS;
  }
}

enum I2C_RESPONSE init_i2c(struct i2c_interface* self){
	i2c_init(I2C_INST, FREQ_HZ);

  gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
  gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);

  gpio_pull_up(SCL_PIN);
  gpio_pull_up(SDA_PIN);

  info("I2C interface successfully configured\n");
	return SUCCESS;
}

int main(){

	stdio_init_all();

	gpio_init(PICO_DEFAULT_LED_PIN);
	gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
	gpio_pull_down(PICO_DEFAULT_LED_PIN);
	gpio_put(PICO_DEFAULT_LED_PIN, 1);

	info("Initialising data structures\n");

	struct i2c_interface i2c = {
		.sda_pin = SDA_PIN,
		.scl_pin = SCL_PIN,
		.baud_rate_hz = FREQ_HZ,
		.initialise = false,
		.write = &write_i2c,
		.read = &read_i2c,
		.initialise = &init_i2c
	};

	i2c.initialise(&i2c);

	init(i2c);

	enable_sensor(i2c, ACCELEROMETER, 100);
	enable_sensor(i2c, GYROSCOPE, 100);
	enable_sensor(i2c, MAGNETIC_FIELD, 100);
	enable_sensor(i2c, LINEAR_ACCELERATION, 100);
	enable_sensor(i2c, ROTATION_VECTOR, 100);

	for(;;){
		if(read_sensors(i2c)) print_last_frame();
		sleep_ms(50);
	}
	
	return 0;
}
