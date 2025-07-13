#include "includeSrc/MainModel.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void Destroy(MainModel* this);

void Destroy(MainModel *this) {
  free(this);
}

MainModel *NewMainModel() {
  printf("Creating MainModel\n");
  MainModel *pMainModel = malloc(sizeof(MainModel));
  assert(pMainModel != NULL);
  pMainModel->WIDTH = 800;
  pMainModel->HEIGHT = 800;
  pMainModel->TARGET_FPS = 60;
  pMainModel->TITLE = "GifMaker";
  pMainModel->Destroy = &Destroy;

  return pMainModel;
}
