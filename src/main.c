#include <stdio.h>

#include "defs.h"
#include "bno08x.h"
#include "i2c.h"

enum I2C_RESPONSE write_i2c(const uint8_t addr, const struct i2c_message* message){
	return ERROR_GENERIC;
}

enum I2C_RESPONSE read_i2c(const uint8_t addr, struct i2c_message* message, const uint16_t n){
	return ERROR_GENERIC;
}

enum I2C_RESPONSE init_i2c(struct i2c_interface* self){
	return ERROR_GENERIC;
}

int main(){

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
	
	return 0;
}
