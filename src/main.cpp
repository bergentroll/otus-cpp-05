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
  std::shared_ptr<Ellipse> face { new Ellipse({20, 0}, {80, 100}, colors::BLACK) };
  std::shared_ptr<Ellipse> leftEye { new Ellipse({30, 30}, {40, 40}, colors::BLACK) };
  std::shared_ptr<Ellipse> rightEye { new Ellipse({60, 30}, {70, 40}, colors::BLACK) };

  canvas.addShape(face);
  canvas.addShape(leftEye);
  auto rightEyeUid { canvas.addShape(rightEye) };

  canvas.deleteShape(rightEyeUid);

  doc.saveFile();
}
