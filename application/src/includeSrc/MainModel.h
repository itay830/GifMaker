#pragma once

#define LINKEDLIST_TAG Frames
#define LINKEDLIST_NODE_TAG FrameNode
#define LINKEDLIST_TYPE int
#include "LinkedList.h"



typedef struct MainModel MainModel;

struct MainModel {
  Frames frames;
  int WIDTH;
  int HEIGHT;
  char *TITLE;
  int TARGET_FPS;
  void (*Destroy)(MainModel* this);
};

MainModel* NewMainModel();

