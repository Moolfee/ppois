#include "FractalSquare.h"

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <utility>
#include <vector>

namespace {
struct Vec {
  double x = 0.0;
  double y = 0.0;
  Vec operator+(const Vec &o) const { return {x + o.x, y + o.y}; }
  Vec operator-(const Vec &o) const { return {x - o.x, y - o.y}; }
  Vec operator*(double k) const { return {x * k, y * k}; }
};

std::vector<Vec> corners(const FractalSquare::Square &sq) {
  const double half = sq.side / 2.0;
  const Vec u{std::cos(sq.angleRad), std::sin(sq.angleRad)};
  const Vec v{-u.y, u.x};
  const Vec c{sq.centerX, sq.centerY};

  return {c + u * (-half) + v * (-half), c + u * (half) + v * (-half),
          c + u * (half) + v * (half), c + u * (-half) + v * (half)};
}

std::string toColor(std::size_t index, std::size_t total) {
  const double t = total == 0 ? 0.0 : static_cast<double>(index) / total;
  const int channel = static_cast<int>(180 - 80 * t);
  std::ostringstream os;
  os << '#' << std::hex << std::setw(2) << std::setfill('0') << channel
     << std::setw(2) << channel << std::setw(2) << channel;
  return os.str();
}
}

int main() {
  const int depth = 7;
  const double side = 200.0;

  auto squares = FractalSquare::generate(depth, side);
  if (squares.empty()) {
    std::cout << "Nothing to draw\n";
    return 0;
  }

  double minX = std::numeric_limits<double>::max();
  double minY = std::numeric_limits<double>::max();
  double maxX = std::numeric_limits<double>::lowest();
  double maxY = std::numeric_limits<double>::lowest();

  std::vector<std::vector<Vec>> allCorners;
  allCorners.reserve(squares.size());
  for (const auto &sq : squares) {
    auto pts = corners(sq);
    for (const auto &p : pts) {
      minX = std::min(minX, p.x);
      minY = std::min(minY, p.y);
      maxX = std::max(maxX, p.x);
      maxY = std::max(maxY, p.y);
    }
    allCorners.push_back(std::move(pts));
  }

  const double margin = 10.0;
  const double width = (maxX - minX) + 2 * margin;
  const double height = (maxY - minY) + 2 * margin;

  std::ofstream out("fractal_square.svg");
  out << "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"" << 0 << ' '
      << 0 << ' ' << width << ' ' << height << "\">\n";
  out << "<rect x=\"0\" y=\"0\" width=\"" << width << "\" height=\""
      << height << "\" fill=\"white\"/>\n";

  for (std::size_t i = 0; i < allCorners.size(); ++i) {
    out << "<polygon points=\"";
    for (const auto &p : allCorners[i]) {
      out << p.x - minX + margin << ',' << height - (p.y - minY + margin)
          << ' ';
    }
    out << "\" fill=\"" << toColor(i, allCorners.size())
        << "\" stroke=\"#222\" stroke-width=\"0.5\"/>\n";
  }

  out << "</svg>\n";
  std::cout << "Saved fractal_square.svg with " << squares.size()
            << " squares\n";
  return 0;
}
