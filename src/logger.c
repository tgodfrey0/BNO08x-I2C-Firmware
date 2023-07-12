#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "logger.h"

static enum LEVEL log_level = INFO;

void info(const char* msg, ...){
  if(INFO < log_level){
    return;
  }

  va_list argp;
  va_start(argp, msg);

  time_t now;
  time(&now);
  printf("%s [INFO]: ", ctime(&now));
  vprintf(msg, argp);

  va_end(argp);
}

void warn(const char* msg, ...){
  if(WARN < log_level){
    return;
  }

  va_list argp;
  va_start(argp, msg);

  time_t now;
  time(&now);
  printf("%s [WARN]: ", ctime(&now));
  vprintf(msg, argp);

  va_end(argp);
}

void crit(const char* msg, ...){
  if(CRIT < log_level){
    return;
  }

  va_list argp;
  va_start(argp, msg);

  time_t now;
  time(&now);
  printf("%s [CRIT]: ", ctime(&now));
  vprintf(msg, argp);

  va_end(argp);
}

void set_log_level(enum LEVEL level){
  log_level = level;
}