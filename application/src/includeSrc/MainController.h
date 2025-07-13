#pragma once
#include "MainInteractor.h"
#include "MainViewBuilder.h"
#include "MainModel.h"
#include "../interfaces/includeInterface/GameRayController.h"

typedef struct MainController MainController;

struct MainController {
  GameRayController *gameController;
  MainModel *model;
  MainInteractor *interactor;
  MainViewBuilder *viewBuilder;

  void (*Destroy)(MainController *this);

  void (*Launch)(const MainController *this);
};

MainController *NewMainController();


