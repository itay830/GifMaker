#include "includeSrc/MainViewBuilder.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define BUTTONS_SPEC CLITERAL(Rectangle){10, 60, 200, 80}
#define BUTTONS_TOP_LEFT_GAP 100

void MainViewBuilderDestroy(MainViewBuilder *this);

void MainViewBuilderRender(MainViewBuilder *this, long double dt);

void MainViewBuilderDestroy(MainViewBuilder *this) {
  free(this);
}


MainViewBuilder *NewMainViewBuilder(MainModel *mainModel,
  void (*onAddFrameBtnClick)(Button*),
  void (*onRemoveFrameBtnClick)(Button*),
  void (*onSaveFramesBtnClick)(Button*)) {
  printf("Creating MainViewBuilder\n");

  MainViewBuilder *view = malloc(sizeof(MainViewBuilder));
  assert(view != NULL);
  view->Destroy = &MainViewBuilderDestroy;
  view->Render = &MainViewBuilderRender;
  view->model = mainModel;

  view->addFrameBtn = NewButton(BUTTONS_SPEC, "Add Frame");
  view->addFrameBtn->SetOnClick(view->addFrameBtn, onAddFrameBtnClick);

  view->removeFrameBtn = NewButton(BUTTONS_SPEC, "Remove Frame");
  view->removeFrameBtn->rect->y += BUTTONS_TOP_LEFT_GAP;
  view->removeFrameBtn->SetOnClick(view->removeFrameBtn, onRemoveFrameBtnClick);

  view->saveFramesBtn = NewButton(BUTTONS_SPEC, "Save Frames");
  view->saveFramesBtn->rect->y += BUTTONS_TOP_LEFT_GAP * 2;
  view->saveFramesBtn->SetOnClick(view->saveFramesBtn, onSaveFramesBtnClick);
  return view;
}

void MainViewBuilderRender(MainViewBuilder *this, long double dt) {
  BeginDrawing();
  ClearBackground(BLACK);
  DrawFPS(10, 10);
  this->addFrameBtn->Render(this->addFrameBtn);
  this->removeFrameBtn->Render(this->removeFrameBtn);
  this->saveFramesBtn->Render(this->saveFramesBtn);
  EndDrawing();
}
