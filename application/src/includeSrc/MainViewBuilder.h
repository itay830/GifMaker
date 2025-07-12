#pragma once

#include "MainModel.h"

#include "../gui/includeGui/Button.h"


typedef struct MainViewBuilder MainViewBuilder;

struct MainViewBuilder {
  MainModel *model;
  Button *btn;

  void (*Destroy)(MainViewBuilder *viewBuilder);
  void (*Render)(MainViewBuilder *viewBuilder, long double dt);
};

void MainViewBuilderDestroy(MainViewBuilder *viewBuilder);

MainViewBuilder *createMainViewBuilder(MainModel *mainModel);

void MainViewBuilderRender(MainViewBuilder *viewBuilder, long double dt);
