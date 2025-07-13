#pragma once
#include "MainModel.h"

typedef struct MainInteractor MainInteractor;

struct MainInteractor {
  MainModel *Model;

  void (*Destroy)(MainInteractor *this);

  void (*Update)(MainInteractor *this, long double dt);

  void (*AddFrame)(MainInteractor *this);
};

MainInteractor *NewMainInteractor(MainModel *mainModel);

