#ifndef TINTENLANDSCHAFT_MAIN_WINDOW_H
#define TINTENLANDSCHAFT_MAIN_WINDOW_H

#include <iostream>
#include <string>

#include "sketch.h"
#include "shape.h"

namespace tintenschaft {
  class Canvas {
  public:
    Sketch &getSketch() { return sketch; }

    void setBackgroundColor(Color color) { backgroundColor = color; }

  private:
    Sketch sketch { };
    Color backgroundColor { colors::WHITE };
  };

  class Window {
    virtual void show() = 0;
  };

  class MainWindow: public Window {
  public:
    MainWindow(): canvas() { }

    MainWindow(std::string title): canvas(),title(title) { }

    virtual void show() {
      std::cout << "Show the MainWindow" << std::endl;
    }

    Canvas &getCanvas() { return canvas; }

  private:
    [[ maybe_unused ]] Canvas canvas;
    std::string title;
  };
}

#endif
