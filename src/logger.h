/**
 * @file logger.h
 * @author Toby Godfrey (me@tgodfrey.com)
 * @brief A very basic logger implementation.
 * @version 0.1
 * @date 2023-07-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

/**
 * @brief Possible log levels.
 * 
 * @ingroup Enumerations
 * 
 */
enum LEVEL {
  DEBUG = 0,
  INFO = 1,
  DATA = 2,
  WARN = 3,
  CRIT = 4
};

static enum LEVEL log_level = DEBUG; /**< The current log level. This level and all higher-priority levels will be shown. */

/**
 * @brief Print a message with the debug log level prepended with the [DBUG] tag.
 * 
 * @param message is the format string to print
 * @param ... contains any other arguments for the formatting
 */
void debug(const char* message, ...);

/**
 * @brief Print a message with the info log level prepended with the [INFO] tag.
 * 
 * @param message is the format string to print
 * @param ... contains any other arguments for the formatting
 */
void info(const char* message, ...);

/**
 * @brief Print a message with the data log level prepended with the [DATA] tag.
 * 
 * @param message is the format string to print
 * @param ... contains any other arguments for the formatting
 */
void data(const char* message, ...);

/**
 * @brief Print a message with the warning log level prepended with the [WARN] tag.
 * 
 * @param message is the format string to print
 * @param ... contains any other arguments for the formatting
 */
void warn(const char* message, ...);

/**
 * @brief Print a message with the critical log level prepended with the [CRIT] tag.
 * 
 * @param message is the format string to print
 * @param ... contains any other arguments for the formatting
 */
void crit(const char* message, ...);

/**
 * @brief Print a message with the debug log level without the [DBUG] tag.
 * 
 * @param message is the format string to print
 * @param ... contains any other arguments for the formatting
 */
void debug_quiet(const char* message, ...);

/**
 * @brief Print a message with the info log level without the [INFO] tag.
 * 
 * @param message is the format string to print
 * @param ... contains any other arguments for the formatting
 */
void info_quiet(const char* message, ...);

/**
 * @brief Print a message with the data log level without the [DATA] tag.
 * 
 * @param message is the format string to print
 * @param ... contains any other arguments for the formatting
 */
void data_quiet(const char* message, ...);

/**
 * @brief Print a message with the warning log level without the [WARN] tag.
 * 
 * @param message is the format string to print
 * @param ... contains any other arguments for the formatting
 */
void warn_quiet(const char* message, ...);

/**
 * @brief Print a message with the critical log level without the [CRIT] tag.
 * 
 * @param message is the format string to print
 * @param ... contains any other arguments for the formatting
 */
void crit_quiet(const char* message, ...);