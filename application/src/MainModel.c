#include "includeSrc/MainModel.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


void destroyMainModel(MainModel *pMainModel) {
  free(pMainModel);
}

MainModel *createMainModel() {
  printf("Creating MainModel\n");
  MainModel *pMainModel = malloc(sizeof(MainModel));
  assert(pMainModel != NULL);
  pMainModel->WIDTH = 800;
  pMainModel->HEIGHT = 800;
  pMainModel->TARGET_FPS = 60;
  pMainModel->TITLE = "GifMaker";
  pMainModel->Destroy = &destroyMainModel;

  return pMainModel;
}
