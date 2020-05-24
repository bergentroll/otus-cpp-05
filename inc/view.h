#ifndef TINTENLANDSCHAFT_UBERSBENUTZERSCHNITTSTELLE_H
#define TINTENLANDSCHAFT_UBERSBENUTZERSCHNITTSTELLE_H

#include <iostream>
#include <string>

namespace tintenschaft {
  class Canvas {
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
