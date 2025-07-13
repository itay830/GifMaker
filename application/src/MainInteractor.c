#include "includeSrc/MainInteractor.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



void Destroy(MainInteractor *this);

void Update(MainInteractor *this, long double dt);

void AddFrame(MainInteractor *this);


void AddFrame(MainInteractor *this) {
  printf("AddedFrame\n");
}

void Destroy(MainInteractor *this) {
  free(this);
}

MainInteractor *NewMainInteractor(MainModel *mainModel) {
  printf("Creating MainInteractor\n");
  MainInteractor *const pMainInteractor = malloc(sizeof(MainInteractor));
  assert(pMainInteractor != NULL);
  pMainInteractor->Model = mainModel;
  pMainInteractor->Destroy = &Destroy;
  pMainInteractor->Update = &Update;

  pMainInteractor->AddFrame = &AddFrame;
  return pMainInteractor;
}

void Update(MainInteractor *this, long double dt) {
}

