#include "../include/GameLoop.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "../include/MainViewBuilder.h"
#include "../include/MainInteractor.h"


GameLoop *GameLoopCreate(
  void (*update)(MainInteractor *, long double),
  void (*render)(MainViewBuilder *, long double)) {
  printf("Creating GameLoop\n");
  GameLoop *const gameLoop = malloc(sizeof(GameLoop));
  assert(gameLoop != NULL);
  gameLoop->Update = update;
  gameLoop->Render = render;
  gameLoop->Start = &GameLoopStart;
  gameLoop->Destroy = &GameLoopDestroy;

  return gameLoop;
}

void GameLoopDestroy(GameLoop *gameLoop) {
  gameLoop->clock->Destroy(gameLoop->clock);
  free(gameLoop);
}

void GameLoopStart(const GameLoop *gameLoop,
            MainInteractor *interactor,
            MainViewBuilder *viewBuilder) {
  printf("Starting GameLoop\n");
  while (!WindowShouldClose()) {
    // const long double dt = gameLoop->clock->Tick(gameLoop->clock);
    gameLoop->Update(interactor, 1);
    gameLoop->Render(viewBuilder, 1);
  }

  CloseWindow();
}
