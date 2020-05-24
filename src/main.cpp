#include <memory>

#include "main_window.h"

using namespace tintenschaft;

int main() {
  MainWindow mainWindow { };
  mainWindow.show();

  auto &canvas { mainWindow.getCanvas() };

  auto &doc { canvas.getSketch() };
  doc.newFile("Mono Lisa.svg");

  canvas.setBackgroundColor(Color(colors::WHITE));
  std::shared_ptr<Ellipse> ellipse {
    new Ellipse(Coordinate{20, 20}, Coordinate{80, 80}, colors::BLACK) };
  canvas.addShape(ellipse);

  doc.saveFile();
}
