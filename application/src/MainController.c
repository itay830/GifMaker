#include "includeSrc/MainController.h"
#include "interfaces/includeInterface/GameRayController.h"
#include "includeSrc/GameLoop.h"
#include  "includeSrc/MainViewBuilder.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void Destroy(MainController *this);

void Launch(const MainController *this);

void Destroy(MainController *this) {
  this->model->Destroy(this->model);
  this->interactor->Destroy(this->interactor);
  this->viewBuilder->Destroy(this->viewBuilder);
  this->gameController->Destroy(this->gameController);
  free(this);
}

MainController *NewMainController() {
  printf("Creating MainController\n");
  MainController *pMainController = malloc(sizeof(MainController));
  assert(pMainController != NULL);

  pMainController->Destroy = &Destroy;
  pMainController->Launch = &Launch;

  pMainController->model = NewMainModel();
  pMainController->interactor = NewMainInteractor(pMainController->model);
  pMainController->viewBuilder = NewMainViewBuilder(
    pMainController->model);
  pMainController->gameController = GameRayControllerCreate(
    NewGameLoop(
      pMainController->interactor->Update,
      pMainController->viewBuilder->Render)
  );
  return pMainController;
}

void Launch(const MainController *this) {
  InitWindow(this->model->WIDTH,
             this->model->HEIGHT,
             this->model->TITLE);
  SetTargetFPS(this->model->TARGET_FPS);
  this->gameController->gameLoop->Start(
    this->gameController->gameLoop,
    this->interactor,
    this->viewBuilder
  );
}
