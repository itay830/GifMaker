#include "include/MainViewBuilder.h"

#include <assert.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

void MainViewBuilderDestroy(MainViewBuilder *viewBuilder) {
  free(viewBuilder);
}


MainViewBuilder *createMainViewBuilder(MainModel *mainModel) {
  printf("Creating MainViewBuilder\n");
  MainViewBuilder *pMainViewBuilder = malloc(sizeof(MainViewBuilder));
  assert(pMainViewBuilder != NULL);
  pMainViewBuilder->Destroy = &MainViewBuilderDestroy;
  pMainViewBuilder->Render = &MainViewBuilderRender;
  pMainViewBuilder->model = mainModel;
  return pMainViewBuilder;
}

void MainViewBuilderRender(MainViewBuilder *viewBuilder, long double dt) {
  BeginDrawing();
  ClearBackground(BLACK);
  EndDrawing();
}
