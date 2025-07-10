#include "../include/Clock.h"
#include <assert.h>
#include <stdlib.h>

Clock *ClockCreate() {
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

void ClockDestroy(Clock *const clock) {
  free(clock);
}

long double ClockTick(Clock *clock) {
  if (clock->sTime.tv_nsec == 0) {
    clock_gettime(CLOCK_MONOTONIC, &clock->sTime);
  }
  const long double dt = clock->GetElapsedTimeNano(clock) / 1000000000L;
  clock->ticks++;
  return dt;
}

double ClockUpdateFPS(Clock *clock, const long double now) {
  assert(false);
  if (clock->lastTickIndex == FPS_TICK_CHECK) {
    clock->FPS = 1; // TODO: nano to ms :3
    clock->lastTicks[0] = clock->lastTicks[FPS_TICK_CHECK - 1];
    clock->lastTickIndex = 1;
  }
  clock->lastTicks[clock->lastTickIndex] = now;
  clock->lastTickIndex++;
  if (clock->lastTickIndex >= 2) {
    return clock->lastTicks[clock->lastTickIndex - 2];
  }
  return now;
}

long double ClockGetElapsedTimeNano(Clock *clock) {
  clock_gettime(CLOCK_MONOTONIC, &clock->eTime);
  const long double dt = (long double) ((clock->eTime.tv_sec - clock->sTime.tv_sec) * 1000000000L +
                                        (clock->eTime.tv_nsec - clock->sTime.tv_nsec));
  clock_gettime(CLOCK_MONOTONIC, &clock->sTime);
  return dt;
}
