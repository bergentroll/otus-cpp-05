#ifndef TINTENLANDSCHAFT_UBERSHAPE_H
#define TINTENLANDSCHAFT_UBERSHAPE_H

namespace tintenschaft {
  class Dot {
  };

  class Shape {
  public:
    virtual void show() = 0;
    virtual ~Shape() = 0;
  };

  class Rectangle: public Shape {
  };

  class Ellipse: public Shape {
  };
}

#endif
