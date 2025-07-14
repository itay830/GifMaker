#include "includeSrc/MainInteractor.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void MainInteractorDestroy(MainInteractor *this);

void MainInteractorUpdate(MainInteractor *this, long double dt);

void MainInteractorAddFrame(MainInteractor *this);
void MainInteractorRemoveFrame(MainInteractor *this);
void MainInteractorSaveFrames(MainInteractor *this);



void MainInteractorDestroy(MainInteractor *this) {
  free(this);
}

MainInteractor *NewMainInteractor(MainModel *mainModel) {
  printf("Creating MainInteractor\n");
  MainInteractor *const pMainInteractor = malloc(sizeof(MainInteractor));
  assert(pMainInteractor != NULL);
  pMainInteractor->Model = mainModel;
  pMainInteractor->Destroy = &MainInteractorDestroy;
  pMainInteractor->Update = &MainInteractorUpdate;

  pMainInteractor->AddFrame = &MainInteractorAddFrame;
  pMainInteractor->RemoveFrame = &MainInteractorRemoveFrame;
  pMainInteractor->SaveFrames = &MainInteractorSaveFrames;
  return pMainInteractor;
}

void MainInteractorUpdate(MainInteractor *this, long double dt) {

}

void MainInteractorAddFrame(MainInteractor *this) {
  printf("AddedFrame\n");
}

void MainInteractorRemoveFrame(MainInteractor *this) {
  printf("RemoveFrames\n");
}

void MainInteractorSaveFrames(MainInteractor *this) {
  printf("SaveFrames\n");
}