#ifndef TINTENLANDSCHAFT_MAIN_WINDOW_H
#define TINTENLANDSCHAFT_MAIN_WINDOW_H

#include <iostream>
#include <memory>
#include <string>

#include "sketch.h"
#include "shape.h"

namespace tintenschaft {
  class Widget {
  public:
    virtual void show() = 0;
  };

  class Canvas: public Widget {
  public:
    Sketch &getSketch() { return sketch; }

    void setBackgroundColor(Color color) { backgroundColor = color; }

    virtual void show() override {
      std::cout << "Show Canvas" << std::endl;
    }

    void addShape(std::shared_ptr<Shape> shape) {
      std::cout << "Add Shape to Canvas" << std::endl;
      shape->show();
    }

  private:
    Sketch sketch { };
    Color backgroundColor { colors::WHITE };
  };

  class MainWindow: public Widget {
  public:
    MainWindow(): canvas() { }

    MainWindow(std::string title): canvas(),title(title) { }

    virtual void show() override {
      std::cout << "Show the MainWindow" << std::endl;
    }

    Canvas &getCanvas() { return canvas; }

  private:
    Canvas canvas;
    std::string title;
  };
}

#endif
