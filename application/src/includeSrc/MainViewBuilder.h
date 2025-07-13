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

MainViewBuilder *NewMainViewBuilder(MainModel *mainModel);

