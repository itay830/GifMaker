#include "includeSrc/MainViewBuilder.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void MainViewBuilderDestroy(MainViewBuilder *this) {
  free(this);
}

MainViewBuilder *NewMainViewBuilder(MainModel *mainModel) {
  printf("Creating MainViewBuilder\n");
  MainViewBuilder *view = malloc(sizeof(MainViewBuilder));
  assert(view != NULL);
  view->Destroy = &MainViewBuilderDestroy;
  view->Render = &MainViewBuilderRender;
  view->model = mainModel;

  return view;
}

void MainViewBuilderRender(MainViewBuilder *this, long double dt) {
  BeginDrawing();
  ClearBackground(BLACK);
  EndDrawing();
}
