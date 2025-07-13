#pragma once
#include <stdint.h>
#include <time.h>
#define FPS_TICK_CHECK 64 // 2^n

typedef struct timespec TimeSpec;

typedef struct Clock Clock;

struct Clock {
  TimeSpec sTime;
  TimeSpec eTime;

  uint64_t ticks;
  uint64_t lastTicks[FPS_TICK_CHECK];
  uint32_t lastTickIndex;
  double FPS;

  void (*Destroy)(Clock *this);

  long double (*Tick)(Clock *this);

  double (*UpdateFPS)(Clock *this, long double dt);

  long double (*GetElapsedTimeNano)(Clock *this);
};

Clock *NewClock();


