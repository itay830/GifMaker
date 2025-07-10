#include "include/GameRayController.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

GameRayController *GameRayControllerCreate(GameLoop *gameLoop) {
  GameRayController *gameRayController = malloc(sizeof(GameRayController));
  assert(gameRayController != NULL);
  gameRayController->PressedKeyInputHandler = &GameRayControllerPressedKeyInputHandler;
  gameRayController->Destroy = &GameRayControllerDestroy;
  gameRayController->gameLoop = gameLoop;
  return gameRayController;
}

void GameRayControllerDestroy(GameRayController *gameRayController) {
  gameRayController->gameLoop->Destroy(gameRayController->gameLoop);
  free(gameRayController);
}


void GameRayControllerPressedKeyInputHandler(GameRayController *gameRayController) {
  printf("PressedKeyInputHandler\n");
}
