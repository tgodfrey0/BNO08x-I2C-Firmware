/**
 * @file q_points.h
 * @author Toby Godfrey (me@tgodfrey.com)
 * @brief Stores preprocessor definitions for the Q point(s) of each sensor.
 * @version 0.1
 * @date 2023-07-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#define Q_ACCELEROMETER                               8u    /**< The Q point for the accelerometer. */
#define Q_GYROSCOPE                                   9u    /**< The Q point for the gyroscope. */
#define Q_MAGNETIC_FIELD                              4u    /**< The Q point for the magnetic field. */
#define Q_LINEAR_ACCELERATION                         8u    /**< The Q point for the linear acceleration. */
#define Q_ROTATION_VECTOR                             14u   /**< The Q point for the rotation vector. */
#define Q_ROTATION_VECTOR_ACCURACY                    12u   /**< The Q point for the rotation vector accuracy estimate. */
#define Q_GRAVITY                                     8u    /**< The Q point for the gravity. */
#define Q_GAME_ROTATION_VECTOR                        14u   /**< The Q point for the game rotation vector. */
#define Q_GEOMAGNETIC_ROTATION_VECTOR                 14u   /**< The Q point for the geomagnetic rotation vector. */
#define Q_GEOMAGNETIC_ROTATION_VECTOR_ACCURACY        12u   /**< The Q point for the geomagnetic rotation vector accuracy estimate. */
#define Q_PRESSURE                                    20u   /**< The Q point for the pressure. */
#define Q_AMBIENT_LIGHT                               8u    /**< The Q point for the ambient light. */
#define Q_HUMIDITY                                    8u    /**< The Q point for the humidity. */
#define Q_PROXIMITY                                   4u    /**< The Q point for the proximity. */
#define Q_TEMPERATURE                                 7u    /**< The Q point for the temperature. */
#define Q_ARVR_STABILISED_ROTATION_VECTOR             14u   /**< The Q point for the ARVR stabilised rotation vector. */
#define Q_ARVR_STABILISED_ROTATION_VECTOR_ACCURACY    12u   /**< The Q point for the ARVR stabilised rotation vector accuracy estimate. */
#define Q_ARVR_STABILISED_GAME_ROTATION_VECTOR        14u   /**< The Q point for the ARVR stabilised game rotation vector. */