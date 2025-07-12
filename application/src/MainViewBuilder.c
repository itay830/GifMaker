#include "includeSrc/MainViewBuilder.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void MainViewBuilderDestroy(MainViewBuilder *viewBuilder) {
  viewBuilder->btn->Release(viewBuilder->btn);
  free(viewBuilder);
}


MainViewBuilder *createMainViewBuilder(MainModel *mainModel) {
  printf("Creating MainViewBuilder\n");
  MainViewBuilder *pMainViewBuilder = malloc(sizeof(MainViewBuilder));
  assert(pMainViewBuilder != NULL);
  pMainViewBuilder->Destroy = &MainViewBuilderDestroy;
  pMainViewBuilder->Render = &MainViewBuilderRender;
  pMainViewBuilder->model = mainModel;
  pMainViewBuilder->btn = NewButton(20, 20, 120, 40, "Title");
  return pMainViewBuilder;
}

void MainViewBuilderRender(MainViewBuilder *viewBuilder, long double dt) {
  BeginDrawing();
  ClearBackground(BLACK);
  viewBuilder->btn->Render(viewBuilder->btn);

  EndDrawing();
}
