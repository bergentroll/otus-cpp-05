#include "view.h"
#include "controller.h"

using namespace tintenschaft;

int main() {
  Controller controller { };
  MainWindow mainWindow { };

  mainWindow.show();

  auto &doc { controller.createScetch("New document") };
  auto &shape { controller.createShape(Circle, { Dot(100, 100), 75, Color::BLACK}); }
  doc.saveScetch("export.file");
}
