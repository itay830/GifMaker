#pragma once

#include "MainModel.h"

typedef struct MainViewBuilder MainViewBuilder;

struct MainViewBuilder {
  MainModel *model;

  void (*Destroy)(MainViewBuilder *viewBuilder);
  void (*Render)(MainViewBuilder *viewBuilder, long double dt);
};

void MainViewBuilderDestroy(MainViewBuilder *viewBuilder);

MainViewBuilder *createMainViewBuilder(MainModel *mainModel);

void MainViewBuilderRender(MainViewBuilder *viewBuilder, long double dt);
