#ifndef TINTENLANDSCHAFT_MAIN_WINDOW_H
#define TINTENLANDSCHAFT_MAIN_WINDOW_H

#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_map>
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

    unsigned int addShape(std::shared_ptr<Shape> shape) {
      std::cout << "Add Shape to Canvas" << std::endl;
      shapes[currentUid] = shape;
      shape->show();
      return currentUid++;
    }

    void deleteShape(unsigned int uid) {
      std::cout << "Delete Shape with uid " << uid << " from Canvas" << std::endl;
      shapes.erase(uid);
    }

    void deleteShape(std::shared_ptr<Shape> shape) {
      auto it {
        std::find_if(
          shapes.begin(),
          shapes.end(),
          [shape](auto const &item){ return item.second == shape; })
      };
      if (it != shapes.end()) {
      std::cout << "Delete Shape with uid " << it->first << " from Canvas" << std::endl;
        shapes.erase(it);
      } else {
        std::cout << "Failed to delete Shape from Canvas" << std::endl;
      }
    }

  private:
    Sketch sketch { };
    Color backgroundColor { colors::WHITE };
    unsigned int currentUid { 1 };
    std::unordered_map<unsigned int, std::shared_ptr<Shape>> shapes;
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
