/****************************************************************************************************
* @file i2c.h
* @brief I2C related definitions
*
* @author Toby Godfrey
****************************************************************************************************/

#pragma once

#include <stdint.h>
#include <stdbool.h>

/**
 * @struct i2c_message
 *
 * @brief Contains the relevant data about messages on the bus
 */
struct i2c_message {
	uint8_t* payload;		/**< The data itself */
	uint8_t* length;		/**< The length of the data */
};

/**
* @struct i2c_interface
*
* @brief Holds the data relevant to the I2C interface configuration
*/
struct i2c_interface {
	uint8_t sda_pin;		/**< The SDA pin number */
	uint8_t scl_pin;		/**< The SCL pin number */
	uint8_t freq_hz;		/**< The desired I2C bus speed in Hertz */
	bool initialised;		/**< Stores true if the interface has been successfully initialised */

	/**
	* @brief Callback to write data on to the I2C bus
	*
	* @param[in] message		A message struct to send on the bus
	*/
	uint8_t (*write)(const struct i2c_message* message);

	/**
	* @brief Callback to read data from the I2C bus
	*
	* @param[in] message		The message struct to store the resulting data
	* @param[in] n				The number of bytes to read from the bus
	*/
	uint8_t (*read)(struct i2c_message* message, const uint16_t n);

};
