#pragma once
#include "Clock.h"
#include "MainViewBuilder.h"
#include "MainInteractor.h"

typedef struct GameLoop GameLoop;

struct GameLoop {
  Clock *clock;

  void (*Destroy)(GameLoop *gameLoop);

  void (*Update)(MainInteractor *interactor, long double dt);

  void (*Render)(MainViewBuilder *viewBuilder, long double dt);

  void (*Start)(const GameLoop *gameLoop,
                MainInteractor *interactor,
                MainViewBuilder *viewBuilder);
};

GameLoop *GameLoopCreate(void (*update)(MainInteractor *interactor, long double dt),
                         void (*render)(MainViewBuilder *viewBuilder, long double dt));

void GameLoopDestroy(GameLoop *gameLoop);

void GameLoopStart(const GameLoop *gameLoop,
                   MainInteractor *interactor,
                   MainViewBuilder *viewBuilder);
