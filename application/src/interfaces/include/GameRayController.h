#pragma once
#include "../../include/GameLoop.h"

typedef struct GameRayController GameRayController;

struct GameRayController {
  GameLoop *gameLoop;
  void (*Destroy)(GameRayController *controller);
  void (*PressedKeyInputHandler)(GameRayController *gameRayController);
};


GameRayController *GameRayControllerCreate(GameLoop *gameLoop);

void GameRayControllerDestroy(GameRayController *gameRayController);

void GameRayControllerPressedKeyInputHandler(GameRayController *gameRayController);
