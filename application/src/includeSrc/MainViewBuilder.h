#pragma once

#include "MainModel.h"

#include "../gui/includeGui/Button.h"


typedef struct MainViewBuilder MainViewBuilder;

struct MainViewBuilder {
  MainModel *model;

  void (*Destroy)(MainViewBuilder *viewBuilder);

  void (*Render)(MainViewBuilder *viewBuilder, long double dt);

  // Experiment
  Button *btn;
};

void MainViewBuilderDestroy(MainViewBuilder *this);

MainViewBuilder *NewMainViewBuilder(MainModel *mainModel);

void MainViewBuilderRender(MainViewBuilder *this, long double dt);
