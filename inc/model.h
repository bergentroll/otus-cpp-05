#ifndef TINTENLANDSCHAFT_AUSGEZEICHNETBAUFORM_H
#define TINTENLANDSCHAFT_AUSGEZEICHNETBAUFORM_H

namespace tintenschaft {
  class Scetch {
    void loadFile(std::string filename) {
      std::cout << "Scetch loaded from file \"" << filename << '"' << std::endl;
    }

    void saveFile() { }
  };
}

#endif
