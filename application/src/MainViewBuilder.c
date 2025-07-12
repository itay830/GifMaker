#include "includeSrc/MainViewBuilder.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void MainViewBuilderDestroy(MainViewBuilder *viewBuilder) {
  viewBuilder->btn->Release(viewBuilder->btn);
  free(viewBuilder);
}

void btnClicked();

MainViewBuilder *createMainViewBuilder(MainModel *mainModel) {
  printf("Creating MainViewBuilder\n");
  MainViewBuilder *view = malloc(sizeof(MainViewBuilder));
  assert(view != NULL);
  view->Destroy = &MainViewBuilderDestroy;
  view->Render = &MainViewBuilderRender;
  view->model = mainModel;


  view->btn = NewButton(mainModel->WIDTH/2 - 200, mainModel->HEIGHT/2 - 80, 400, 160, "Button");
  view->btn->SetOnClick(view->btn, &btnClicked);


  return view;
}

void btnClicked() {
  printf("Click!!");
}

void MainViewBuilderRender(MainViewBuilder *viewBuilder, long double dt) {
  BeginDrawing();
  ClearBackground(BLACK);
  viewBuilder->btn->Render(viewBuilder->btn);

  EndDrawing();
}
