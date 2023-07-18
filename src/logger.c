#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "logger.h"

void debug(const char* msg, ...){
  if(DEBUG < log_level){
    return;
  }

  va_list argp;
  va_start(argp, msg);

  printf("[DBUG]: ");
  vprintf(msg, argp);

  va_end(argp);
}

void info(const char* msg, ...){
  if(INFO < log_level){
    return;
  }

  va_list argp;
  va_start(argp, msg);

  printf("[INFO]: ");
  vprintf(msg, argp);

  va_end(argp);
}

void data(const char* msg, ...){
  if(DATA < log_level){
    return;
  }

  va_list argp;
  va_start(argp, msg);

  printf("[DATA]: ");
  vprintf(msg, argp);

  va_end(argp);
}

void warn(const char* msg, ...){
  if(WARN < log_level){
    return;
  }

  va_list argp;
  va_start(argp, msg);

  printf("[WARN]: ");
  vprintf(msg, argp);

  va_end(argp);
}

void crit(const char* msg, ...){
  if(CRIT < log_level){
    return;
  }

  va_list argp;
  va_start(argp, msg);

  printf("[CRIT]: ");
  vprintf(msg, argp);

  va_end(argp);
}
