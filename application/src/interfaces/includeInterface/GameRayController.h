#pragma once
#include "../../includeSrc/GameLoop.h"

typedef struct GameRayController GameRayController;

struct GameRayController {
  GameLoop *gameLoop;

  void (*Destroy)(GameRayController *controller);

  void (*PressedKeyInputHandler)(GameRayController *gameRayController);
};

void GameRayControllerDestroy(GameRayController *gameRayController);

GameRayController *GameRayControllerCreate(GameLoop *gameLoop);

void GameRayControllerPressedKeyInputHandler(GameRayController *gameRayController);
