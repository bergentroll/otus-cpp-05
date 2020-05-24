#ifndef TINTENLANDSCHAFT_WUNDERSHAPE_H
#define TINTENLANDSCHAFT_WUNDERSHAPE_H

#include <cstdint>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

namespace tintenschaft {
  using byte = uint8_t;

  class Color {
  public:
    Color(byte red, byte green, byte blue, byte alpha = 255):
    red(red), green(green), blue(blue), alpha(alpha) { }

    Color(std::string htmlCode, byte alpha = 255): alpha(alpha) {
      std::tie(red, green, blue) = html2int(htmlCode);
    }

  private:
    byte
      red,
      green,
      blue,
      alpha;

    std::tuple<byte, byte, byte> html2int(std::string htmlCode) {
      std::cout << "Convert HMTL color code to integer values" << std::endl;
      return std::make_tuple(0, 0, 0);
    }
  };

  namespace colors {
    Color
      NONE { 0, 0, 0, 0 },
      BLACK { 0, 0, 0 },
      RED { 255, 0, 0 },
      GREEN { 0, 255, 0 },
      BLUE { 0, 0, 255 },
      WHITE { 255, 255, 255 };
  }

  struct Coordinate { long x, y; };

  class Shape {
  public:
    virtual ~Shape() { };
    virtual void show() = 0;

    virtual void setStrokeColor(Color color) {
      strokeColor = color;
      // TODO notify
    }

    void setStrokeWidth(unsigned int widthPX) {
      strokeWidth = widthPX;
      // TODO notify
    }

    void setFillColor(Color color) {
      fillColor = color;
      // TODO notify
    }

  protected:
    Color strokeColor { colors::BLACK };
    Color fillColor { colors::NONE };
    unsigned int strokeWidth { 1 };
  };

  class Dot: public Shape {
  public:
    Dot(
      Coordinate coordinate,
      Color strokeColor = colors::BLACK) {
        std::cout << "Construct Dot with strokeColor ";
    }

    virtual void show() override { }
  };

  class Rectangle: public Shape {
  public:
    Rectangle(
      Coordinate corner1,
      Coordinate corner2,
      Color strokeColor = colors::BLACK,
      Color fillColor = colors::NONE ) {
        std::cout << "Construct Rectangle with strokeColor ";
    }

    virtual void show() override { }
  };

  class Ellipse: public Shape {
  public:
    Ellipse(
      Coordinate corner1,
      Coordinate corner2,
      Color strokeColor = colors::BLACK,
      Color fillColor = colors::NONE ) {
        std::cout << "Construct Ellipse with strokeColor ";
    }

    virtual void show() override { }
  };

  class Polyline: public Shape {
  public:
    Polyline(
      std::vector<Coordinate> coordinates,
      Color strokeColor = colors::BLACK,
      Color fillColor = colors::NONE ) {
        std::cout << "Construct Polyline with strokeColor ";
    }

    virtual void show() override { }
  };
}

#endif
