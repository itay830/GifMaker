#include "includeSrc/MainController.h"
#include "interfaces/includeInterface/GameRayController.h"
#include "includeSrc/GameLoop.h"
#include  "includeSrc/MainViewBuilder.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "raygui.h"

void MainControllerDestroy(MainController *this);

void MainControllerLaunch(const MainController *this);

void MainControllerAddFrame(Button *btn);

void MainControllerRemoveFrame(Button *btn);

void MainControllerSaveFrames(Button *btn);

void MainControllerDestroy(MainController *this) {
  this->model->Destroy(this->model);
  this->interactor->Destroy(this->interactor);
  this->viewBuilder->Destroy(this->viewBuilder);
  this->gameController->Destroy(this->gameController);
  free(this);
}

MainController *NewMainController() {
  printf("Creating MainController\n");
  MainController *this = malloc(sizeof(MainController));
  assert(this != NULL);

  this->Destroy = &MainControllerDestroy;
  this->Launch = &MainControllerLaunch;
  this->AddFrame = &MainControllerAddFrame;
  this->RemoveFrame = &MainControllerRemoveFrame;
  this->SaveFrames = &MainControllerSaveFrames;

  this->model = NewMainModel();
  this->interactor = NewMainInteractor(this->model);

  this->viewBuilder = NewMainViewBuilder(
    this->model,
    this->AddFrame,
    this->RemoveFrame,
    this->SaveFrames);

  this->viewBuilder->addFrameBtn->ctx = this;
  this->viewBuilder->removeFrameBtn->ctx = this;
  this->viewBuilder->saveFramesBtn->ctx = this;

  this->gameController = GameRayControllerCreate(
    NewGameLoop(
      this->interactor->Update,
      this->viewBuilder->Render)
  );
  return this;
}

void MainControllerLaunch(const MainController *this) {
  InitWindow(this->model->WIDTH,
             this->model->HEIGHT,
             this->model->TITLE);
  SetTargetFPS(this->model->TARGET_FPS);

  GuiSetStyle(DEFAULT, TEXT_SIZE, 25);

  this->gameController->gameLoop->Start(
    this->gameController->gameLoop,
    this->interactor,
    this->viewBuilder
  );
}

void MainControllerAddFrame(Button *btn) {
  const MainController *ctx = btn->ctx;
  ctx->interactor->AddFrame(ctx->interactor);
}

void MainControllerRemoveFrame(Button *btn) {
  const MainController *ctx = btn->ctx;
  ctx->interactor->RemoveFrame(ctx->interactor);
}

void MainControllerSaveFrames(Button *btn) {
  const MainController *ctx = btn->ctx;
  ctx->interactor->SaveFrames(ctx->interactor);
}
