#include "src/include/MainController.h"

int main() {
  MainController *mainController = MainControllerCreate();
  mainController->Launch(mainController);
  mainController->Destroy(mainController);
  return 0;
}
