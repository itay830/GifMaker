#include "include/MainModel.h"

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

  pMainModel->frames = malloc(sizeof(FramesInt));
  pMainModel->framesDouble = malloc(sizeof(FramesDouble));

  pMainModel->frames->items = 321;
  pMainModel->framesDouble->items = 0.123;

  printf("int: %i", pMainModel->frames->items);
  printf("double: %f", pMainModel->framesDouble->items);

  free(pMainModel->frames);
  free(pMainModel->framesDouble);
  return pMainModel;
}
