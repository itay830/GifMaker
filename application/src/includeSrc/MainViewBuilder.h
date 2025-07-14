#pragma once

#include "MainModel.h"

#include "../gui/includeGui/Button.h"


typedef struct MainViewBuilder MainViewBuilder;

struct MainViewBuilder {
  MainModel *model;

  void (*Destroy)(MainViewBuilder *viewBuilder);

  void (*Render)(MainViewBuilder *viewBuilder, long double dt);

  Button *addFrameBtn;
  Button *removeFrameBtn;
  Button *saveFramesBtn;
};

MainViewBuilder *NewMainViewBuilder(
  MainModel *mainModel,
  void (*onAddFrameBtnClick)(Button *),
  void (*onRemoveFrameBtnClick)(Button *),
  void (*onSaveFramesBtnClick)(Button *));
