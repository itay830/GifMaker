#include "includeSrc/MainInteractor.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void destroyMainInteractor(MainInteractor* PMainInteractor) {
  free(PMainInteractor);
}

MainInteractor* createMainInteractor(MainModel* mainModel) {
  printf("Creating MainInteractor\n");
  MainInteractor *const pMainInteractor = malloc(sizeof(MainInteractor));
  assert(pMainInteractor != NULL);
  pMainInteractor->Model = mainModel;
  pMainInteractor->Destroy = &destroyMainInteractor;
  pMainInteractor->Update = &MainInteractorUpdate;
  return pMainInteractor;
}


void MainInteractorUpdate(MainInteractor* mainInteractor, long double dt) {

}