#include "view.h"
#include "controller.h"

using namespace tintenschaft;

int main() {
  MainWindow mainWindow { };
  mainWindow.show();

  auto &canvas { mainWindow.getCanvas() };

  auto &doc { canvas.createScetch("Mono Liza") };
  canvas.setBackgroundColor(Color(Color::WHITE));
  canvas.addShape(Circle, { Dot(100, 100), 75, Color(Color::BLACK));

  doc.saveScetch("export.file");
}
