#include "includeSrc/MainViewBuilder.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void Destroy(MainViewBuilder *this);

void Render(MainViewBuilder *this, long double dt);


void Destroy(MainViewBuilder *this) {
  free(this);
}

void foo(Button *btn) {
  MainViewBuilder *obj = btn->ctx;
  printf("%i", obj->model->HEIGHT);
}

MainViewBuilder *NewMainViewBuilder(MainModel *mainModel) {
  printf("Creating MainViewBuilder\n");
  MainViewBuilder *view = malloc(sizeof(MainViewBuilder));
  assert(view != NULL);
  view->Destroy = &Destroy;
  view->Render = &Render;
  view->model = mainModel;

  view->btn = NewButton(100, 100, 200, 80, "EXPERIMENT");
  view->btn->SetOnClick(view->btn, &foo);
  view->btn->ctx = view;
  return view;
}

void Render(MainViewBuilder *this, long double dt) {
  BeginDrawing();
  ClearBackground(BLACK);
  DrawFPS(10, 10);
  this->btn->Render(this->btn);
  EndDrawing();
}
