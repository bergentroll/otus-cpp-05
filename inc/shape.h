#ifndef TINTENLANDSCHAFT_WUNDERSHAPE_H
#define TINTENLANDSCHAFT_WUNDERSHAPE_H

#include <cstdint>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

namespace tintenschaft {
  using byte = uint8_t;

  class Color;
  std::ostream &operator <<(std::ostream &s, Color);

  class Color {
  public:
    Color(byte red, byte green, byte blue, byte alpha = 255):
    red(red), green(green), blue(blue), alpha(alpha) {
      std::cout << "Construct color " << *this << " by integer values" << std::endl;
    }

    Color(std::string htmlCode, byte alpha = 255): alpha(alpha) {
      std::cout << "Construct color " << *this << " by HTML code" << std::endl;
      std::tie(red, green, blue) = html2int(htmlCode);
    }

    operator std::string() {
      return std::string(
        "RGBA(" +
        std::to_string(red) + ", " +
        std::to_string(green) + ", " +
        std::to_string(blue) + ", " +
        std::to_string(alpha) + ')');
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

  std::ostream &operator <<(std::ostream &s, Color color) {
    s << std::string(color);
    return s;
  }

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
    virtual ~Shape() {
      std::cout << "Destruct Shape" << std::endl;
    };
    virtual void show() = 0;

    virtual void setStrokeColor(Color color) {
      std::cout << "Setting shape stroke color to " << color << std::endl;
      strokeColor = color;
      changeSignal();
    }

    void setStrokeWidth(unsigned int widthPX) {
      std::cout << "Setting shape stroke width to " << widthPX << std::endl;
      strokeWidth = widthPX;
      changeSignal();
    }

    void setFillColor(Color color) {
      std::cout << "Setting shape fill color to " << color << std::endl;
      fillColor = color;
      changeSignal();
    }

    void changeSignal() {
      std::cout << "Shape has emitted changeSignal";
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
        std::cout << "Construct Dot with strokeColor " << strokeColor << std::endl;
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
        std::cout << "Construct Rectangle with strokeColor " << strokeColor << std::endl;
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
        std::cout << "Construct Ellipse with strokeColor " << strokeColor << std::endl;
    }

    virtual void show() override { }
  };

  class Polyline: public Shape {
  public:
    Polyline(
      std::vector<Coordinate> coordinates,
      Color strokeColor = colors::BLACK,
      Color fillColor = colors::NONE ) {
        std::cout << "Construct Polyline with strokeColor " << strokeColor << std::endl;
    }

    virtual void show() override { }
  };
}

#endif
