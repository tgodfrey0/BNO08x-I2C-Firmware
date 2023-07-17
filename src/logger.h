#pragma once

enum LEVEL {
  INFO = 0,
  DATA = 1,
  WARN = 2,
  CRIT = 3
};

static enum LEVEL log_level = INFO;

void info(const char* message, ...);
void data(const char* message, ...);
void warn(const char* message, ...);
void crit(const char* message, ...);