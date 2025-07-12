#include "../includeSrc/GameLoop.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includeSrc/MainViewBuilder.h"
#include "../includeSrc/MainInteractor.h"


GameLoop *NewGameLoop(
  void (*update)(MainInteractor *, long double),
  void (*render)(MainViewBuilder *, long double)) {
  printf("Creating GameLoop\n");
  GameLoop *gameLoop = malloc(sizeof(GameLoop));
  assert(gameLoop != NULL);
  gameLoop->Destroy = &GameLoopDestroy;
  gameLoop->Update = update;
  gameLoop->Render = render;
  gameLoop->Start = &GameLoopStart;

  gameLoop->clock = NewClock();

  return gameLoop;
}

void GameLoopDestroy(GameLoop *this) {
  this->clock->Destroy(this->clock);
  free(this);
}

void GameLoopStart(const GameLoop *this,
            MainInteractor *interactor,
            MainViewBuilder *viewBuilder) {
  printf("Starting GameLoop\n");
  while (!WindowShouldClose()) {
    // const long double dt = gameLoop->clock->Tick(gameLoop->clock);
    this->Update(interactor, 1);
    this->Render(viewBuilder, 1);
  }

  CloseWindow();
}
