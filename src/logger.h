#pragma once

enum LEVEL {
  INFO = 0,
  WARN = 1,
  CRIT = 2
};

static enum LEVEL log_level = INFO;

void info(const char* message, ...);
void warn(const char* message, ...);
void crit(const char* message, ...);