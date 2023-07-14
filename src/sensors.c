#include <stddef.h>

#include "sensors.h"

/*! 
	\defgroup Sensors Sensor instances
*/

//=================================================================================================//
//		Sensor Struct Declarations
//=================================================================================================//

struct sensor* accelerometer = NULL;
struct sensor* gyroscope = NULL;
struct sensor* magnetic_field = NULL;
struct sensor* linear_acceleration = NULL;
struct sensor* rotation_vector = NULL;
struct sensor* gravity = NULL;
struct sensor* uncalibrated_gyroscope = NULL;
struct sensor* game_rotation_vector = NULL;
struct sensor* geomagnetic_rotation_vector = NULL;
struct sensor* pressure = NULL;
struct sensor* ambient_light = NULL;
struct sensor* humidity = NULL;
struct sensor* proximity = NULL;
struct sensor* temperature = NULL;
struct sensor* uncalibrated_magnetic_field = NULL;
struct sensor* tap_detector = NULL;
struct sensor* step_counter = NULL;
struct sensor* significant_motion = NULL;
struct sensor* stability_classifier = NULL;
struct sensor* raw_accelerometer = NULL;
struct sensor* raw_gyroscope = NULL;
struct sensor* raw_magnetometer = NULL;
struct sensor* step_detector = NULL;
struct sensor* shake_detector = NULL;
struct sensor* flip_detector = NULL;
struct sensor* pickup_detector = NULL;
struct sensor* stability_detector = NULL;
struct sensor* personal_activity_classifier = NULL;
struct sensor* sleep_detector = NULL;
struct sensor* tilt_detector = NULL;
struct sensor* pocket_detector = NULL;
struct sensor* circle_detector = NULL;
struct sensor* heart_rate_monitor = NULL;
struct sensor* arvr_stabilised_rotation_vector = NULL;
struct sensor* arvr_stabilised_game_rotation_vector = NULL;
struct sensor* gyro_integrated_rotation_vector = NULL;
struct sensor* motion_request = NULL;
struct sensor* dead_reckoning_pose = NULL;
