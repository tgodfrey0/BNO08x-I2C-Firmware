/****************************************************************************************************
* @file bno08x.h
* @brief BNO08x related definitions
*
* @author Toby Godfrey
****************************************************************************************************/

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "sensor_reports.h"

//=================================================================================================//
//    Structs
//=================================================================================================//

/**
 * @struct sensor
 *
 * Stores the relevant data for a single sensor. A new struct must exist for each sensor in use.
 *
 * @brief Stores an instance of a single sensor.
 */ 
struct sensor {
	const char* name;		/**< A human-readable name for the sensor. Useful for outputting results. */
	const uint8_t id;		/**< The sensor ID. This should be the same as the report_id in the report returned from the sensor. */
	const uint8_t channel;		/**< The channel the sensor communicates on. */
	const int8_t q_point;		/**< The Q point of the sensor. Values <0 indicate no Q point. */
	union input_report* input_report;		/**< Stores the retured data from the sensor. */
	bool enabled;		/**< Whether the sensor has been configured and enabled. */
};

//=================================================================================================//
//    Functions
//=================================================================================================//


