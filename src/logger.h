#pragma once


enum LEVEL {
  INFO = 0,
  WARN = 1,
  CRIT = 2
};

void info(const char* message, ...);
void warn(const char* message, ...);
void crit(const char* message, ...);