#ifndef TINTENLANDSCHAFT_AUSGEZEICHNETSKETCH_H
#define TINTENLANDSCHAFT_AUSGEZEICHNETSKETCH_H

#include <iostream>
#include <string>

namespace tintenschaft {
  class Sketch {
  public:
    void newFile(std::string filename) {
      std::cout << "Scetch assigned to new file \"" << filename << '"' << std::endl;
    }

    void loadFile(std::string filename) {
      std::cout << "Scetch loaded from file \"" << filename << '"' << std::endl;
    }

    void saveFile() {
      std::cout << "Scetch saved to file" << std::endl;
    }

    void saveFileAs(std::string filename) {
      std::cout << "Scetch saved as file \"" << filename << '"' << std::endl;
    }

  private:
  };
}

#endif
