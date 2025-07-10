#pragma once
#include "MainModel.h"

typedef struct MainInteractor MainInteractor;
struct MainInteractor {
  MainModel* Model;
  void (*Destroy)(MainInteractor* mainInteractor);

  void (*Update)(MainInteractor* mainInteractor, long double dt);
};

void destroyMainInteractor(MainInteractor* PMainInteractor);

MainInteractor* createMainInteractor(MainModel *mainModel);

void MainInteractorUpdate(MainInteractor* mainInteractor, long double dt);

