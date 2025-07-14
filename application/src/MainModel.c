#include "includeSrc/MainModel.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void MainModelDestroy(MainModel *this);

void MainModelDestroy(MainModel *this) {
  free(this);
}

MainModel *NewMainModel() {
  printf("Creating MainModel\n");
  MainModel *this = malloc(sizeof(MainModel));
  assert(this != NULL);
  this->WIDTH = 800;
  this->HEIGHT = 800;
  this->TARGET_FPS = 60;
  this->TITLE = "GifMaker";
  this->Destroy = &MainModelDestroy;

  // Experiment
  FrameNode *node = malloc(sizeof(FrameNode));
  node->value = 4;
  node->next = nullptr;
  free(node);
  return this;
}
