#pragma once

#include <iostream>
#include "vector.hpp"

namespace Color {
  void write(std::ostream& out, color color) {
    out << static_cast<int>(color.r() * 255.99) << " "
        << static_cast<int>(color.g() * 255.99) << " "
        << static_cast<int>(color.b() * 255.99) << std::endl;
  }
}