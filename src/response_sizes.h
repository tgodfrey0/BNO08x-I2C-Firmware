/**
 * @file response_sizes.h
 * @author Toby Godfrey (me@tgodfrey.com)
 * @brief Stores preprocessor definitions for the expected response size for each sensor.
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#define RES_ACCELEROMETER                               10u   /**< The expected input report size for the accelerometer. */
#define RES_GYROSCOPE                                   10u   /**< The expected input report size for the gyroscope. */
#define RES_MAGNETIC_FIELD                              10u   /**< The expected input report size for the magnetic field. */
#define RES_LINEAR_ACCELERATION                         10u   /**< The expected input report size for the linear acceleration. */
#define RES_ROTATION_VECTOR                             14u   /**< The expected input report size for the rotation vector. */
#define RES_GRAVITY                                     10u   /**< The expected input report size for the gravity. */
#define RES_UNCALIBRATED_GYROSCOPE                      16u   /**< The expected input report size for the uncalibrated gyroscope. */
#define RES_GAME_ROTATION_VECTOR                        12u   /**< The expected input report size for the game rotation vector. */
#define RES_GEOMAGNETIC_ROTATION_VECTOR                 14u   /**< The expected input report size for the geomagnetic rotation vector. */
#define RES_PRESSURE                                    8u    /**< The expected input report size for the pressure. */
#define RES_AMBIENT_LIGHT                               8u    /**< The expected input report size for the ambient light. */
#define RES_HUMIDITY                                    6u    /**< The expected input report size for the humidity. */
#define RES_PROXIMITY                                   6u    /**< The expected input report size for the proximity. */
#define RES_TEMPERATURE                                 6u    /**< The expected input report size for the temperature. */
#define RES_UNCALIBRATED_MAGNETIC_FIELD                 16u   /**< The expected input report size for the uncalibrated magnetic field. */
#define RES_TAP_DETECTOR                                5u    /**< The expected input report size for the tap detector. */
#define RES_STEP_COUNTER                                12u   /**< The expected input report size for the step counter. */
#define RES_SIGNIFICANT_MOTION                          6u    /**< The expected input report size for the significant motion. */
#define RES_STABILITY_CLASSIFIER                        6u    /**< The expected input report size for the stability classifier. */
#define RES_RAW_ACCELERATION                            16u   /**< The expected input report size for the raw acceleration. */
#define RES_RAW_GYROSCOPE                               16u   /**< The expected input report size for the raw gyroscope. */
#define RES_RAW_MAGNETOMETER                            16u   /**< The expected input report size for the raw magnetometer. */
#define RES_STEP_DETECTOR                               8u    /**< The expected input report size for the step detector. */
#define RES_SHAKE_DETECTOR                              6u    /**< The expected input report size for the shake detector. */
#define RES_FLIP_DETECTOR                               6u    /**< The expected input report size for the flip detector. */
#define RES_PICKUP_DETECTOR                             6u    /**< The expected input report size for the pickup detector. */
#define RES_STABILITY_DETECTOR                          6u    /**< The expected input report size for the stability detector. */
#define RES_PERSONAL_ACTIVITY_CLASSIFIER                16u   /**< The expected input report size for the personal activity classifier. */
#define RES_SLEEP_DETECTOR                              6u    /**< The expected input report size for the sleep detector. */
#define RES_TILT_DETECTOR                               6u    /**< The expected input report size for the tilt detector. */
#define RES_POCKET_DETECTOR                             6u    /**< The expected input report size for the pocket detector. */
#define RES_CIRCLE_DETECTOR                             6u    /**< The expected input report size for the circle detector. */
#define RES_HEART_RATE_MONITOR                          6u    /**< The expected input report size for the heart rate monitor. */
#define RES_ARVR_STABILISED_ROTATION_VECTOR             14u   /**< The expected input report size for the ARVR stabilised rotation vector. */
#define RES_ARVR_STABILISED_GAME_ROTATION_VECTOR        12u   /**< The expected input report size for the ARVR stabilised game rotation vector. */
#define RES_GYRO_INTEGRATED_ROTATION_VECTOR             14u   /**< The expected input report size for the gyro-integrated rotation vector. */
#define RES_MOTION_REQUEST                              6u    /**< The expected input report size for the motion request. */
#define RES_DEAD_RECKONING_POSE                         60u   /**< The expected input report size for the dead reckoning pose. */