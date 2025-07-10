#pragma once

typedef struct MainModel MainModel;

struct MainModel {
  int WIDTH;
  int HEIGHT;
  char *TITLE;
  int TARGET_FPS;
  void (*Destroy)(MainModel* pMainModel);
};

void destroyMainModel(MainModel* pMainModel);
MainModel* createMainModel();
