#include "../includeSrc/Clock.h"
#include <assert.h>
#include <stdlib.h>

Clock *NewClock() {
  Clock *const clock = malloc(sizeof(Clock));
  assert(clock != NULL);
  clock->UpdateFPS = &ClockUpdateFPS;
  clock->Tick = &ClockTick;
  clock->Destroy = &ClockDestroy;
  clock->GetElapsedTimeNano = &ClockGetElapsedTimeNano;

  clock->sTime;
  clock->eTime;
  clock->ticks = 0;
  clock->lastTickIndex = 0;
  clock->lastTicks;
  clock->FPS = 0;
  return clock;
}

void ClockDestroy(Clock *const this) {
  free(this);
}

long double ClockTick(Clock *this) {
  if (this->sTime.tv_nsec == 0) {
    clock_gettime(CLOCK_MONOTONIC, &this->sTime);
  }
  const long double dt = this->GetElapsedTimeNano(this) / 1000000000L;
  this->ticks++;
  return dt;
}

double ClockUpdateFPS(Clock *this, const long double now) {
  assert(false);
  // if (clock->lastTickIndex == FPS_TICK_CHECK) {
  //   clock->FPS = 1; // TODO: nano to ms :3
  //   clock->lastTicks[0] = clock->lastTicks[FPS_TICK_CHECK - 1];
  //   clock->lastTickIndex = 1;
  // }
  // clock->lastTicks[clock->lastTickIndex] = now;
  // clock->lastTickIndex++;
  // if (clock->lastTickIndex >= 2) {
  //   return clock->lastTicks[clock->lastTickIndex - 2];
  // }
  // return now;
}

long double ClockGetElapsedTimeNano(Clock *this) {
  clock_gettime(CLOCK_MONOTONIC, &this->eTime);
  const long double dt = (long double) ((this->eTime.tv_sec - this->sTime.tv_sec) * 1000000000L +
                                        (this->eTime.tv_nsec - this->sTime.tv_nsec));
  clock_gettime(CLOCK_MONOTONIC, &this->sTime);
  return dt;
}
