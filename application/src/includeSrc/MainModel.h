#pragma once

#define LINKEDLIST_TYPE int
#define LINKEDLIST_TAG FramesInt
#include "LinkedList.h"

#define LINKEDLIST_TYPE double
#define LINKEDLIST_TAG FramesDouble
#include "LinkedList.h"


typedef struct MainModel MainModel;

struct MainModel {
  // FramesInt *frames;
  // FramesDouble *framesDouble;

  int WIDTH;
  int HEIGHT;
  char *TITLE;
  int TARGET_FPS;
  void (*Destroy)(MainModel* this);
};

MainModel* NewMainModel();

