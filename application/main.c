#include <stdlib.h>

#include "src/includeSrc/MainController.h"

int main() {
  MainController *mainController = NewMainController();
  mainController->Launch(mainController);
  mainController->Destroy(mainController);
  return EXIT_SUCCESS;
}
