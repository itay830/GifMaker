#include "includeSrc/MainInteractor.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void MainInteractorAddFrame(MainInteractor *this) {
  printf("AddedFrame\n");
}

void DestroyMainInteractor(MainInteractor* this) {
  free(this);
}

MainInteractor* NewMainInteractor(MainModel* mainModel) {
  printf("Creating MainInteractor\n");
  MainInteractor *const pMainInteractor = malloc(sizeof(MainInteractor));
  assert(pMainInteractor != NULL);
  pMainInteractor->Model = mainModel;
  pMainInteractor->Destroy = &DestroyMainInteractor;
  pMainInteractor->Update = &MainInteractorUpdate;

  pMainInteractor->AddFrame = &MainInteractorAddFrame;
  return pMainInteractor;
}

void MainInteractorUpdate(MainInteractor* this, long double dt) {

}