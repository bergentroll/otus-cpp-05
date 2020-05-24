#include "main_window.h"

using namespace tintenschaft;

int main() {
  MainWindow mainWindow { };
  mainWindow.show();

  auto &canvas { mainWindow.getCanvas() };

  auto &doc { canvas.getSketch() };
  doc.newFile("Mono Lisa.svg");

  canvas.setBackgroundColor(Color(colors::WHITE));
  canvas.addShape(Circle, { Dot(100, 100), 75, Color(Color::BLACK));

  doc.saveFile();
}
