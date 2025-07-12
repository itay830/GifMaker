#include "includeSrc/MainController.h"
#include "interfaces/includeInterface/GameRayController.h"
#include "includeSrc/GameLoop.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void MainControllerDestroy(MainController *controller) {
  controller->model->Destroy(controller->model);
  controller->interactor->Destroy(controller->interactor);
  controller->viewBuilder->Destroy(controller->viewBuilder);
  controller->gameController->Destroy(controller->gameController);
  free(controller);
}

MainController *MainControllerCreate() {
  printf("Creating MainController\n");
  MainController *pMainController = malloc(sizeof(MainController));
  assert(pMainController != NULL);

  pMainController->Destroy = &MainControllerDestroy;
  pMainController->Launch = &MainControllerLaunch;

  pMainController->model = createMainModel();
  pMainController->interactor = createMainInteractor(pMainController->model);
  pMainController->viewBuilder = createMainViewBuilder(pMainController->model);
  pMainController->gameController = GameRayControllerCreate(
    GameLoopCreate(
      pMainController->interactor->Update,
      pMainController->viewBuilder->Render)
  );
  return pMainController;
}

void MainControllerLaunch(const MainController *controller) {
  InitWindow(controller->model->WIDTH,
             controller->model->HEIGHT,
             controller->model->TITLE);
  SetTargetFPS(controller->model->TARGET_FPS);
  controller->gameController->gameLoop->Start(
    controller->gameController->gameLoop,
    controller->interactor,
    controller->viewBuilder
  );
}
