#include "includeInterface/GameRayController.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void GameRayControllerDestroy(GameRayController *gameRayController) {
  gameRayController->gameLoop->Destroy(gameRayController->gameLoop);
  free(gameRayController);
}

GameRayController *GameRayControllerCreate(GameLoop *gameLoop) {
  GameRayController *gameRayController = malloc(sizeof(GameRayController));
  assert(gameRayController != NULL);
  gameRayController->PressedKeyInputHandler = &GameRayControllerPressedKeyInputHandler;
  gameRayController->Destroy = &GameRayControllerDestroy;
  gameRayController->gameLoop = gameLoop;
  return gameRayController;
}




void GameRayControllerPressedKeyInputHandler(GameRayController *gameRayController) {
  printf("PressedKeyInputHandler\n");
}
