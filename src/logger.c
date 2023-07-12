#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "logger.h"

static enum LEVEL log_level = INFO;

void logger(enum LEVEL level, const char* tag, const char* message) {
  if(level < log_level){
    return;
  }

   time_t now;
   time(&now);
   printf("%s [%s]: %s\n", ctime(&now), tag, message);
}

void info(const char* message){
  logger(INFO, "INFO", message);
}

void warn(const char* message){
  logger(WARN, "WARN", message);
}

void crit(const char* message){
  logger(CRIT, "CRIT", message);
}

void set_log_level(enum LEVEL level){
  log_level = level;
}