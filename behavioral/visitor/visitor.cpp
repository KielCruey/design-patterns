#define _USE_MATH_DEFINES
#include "visitor.hpp"

#include <math.h> // M_PI'

#include <iostream>
#include <vector>

// ========= Ring =========
Ring::Ring(double radius) : radius(radius) {}

void Ring::accept(iShapeVisitor *visitor) { visitor->visit(this); }

// ========= Square =========
Square::Square(double side) : side(side) {}

void Square::accept(iShapeVisitor *visitor) { visitor->visit(this); }

// ========= Rectangle =========
Rectangle::Rectangle(double length, double width)
    : length(length), width(width) {}

void Rectangle::accept(iShapeVisitor *visitor) { visitor->visit(this); }

// ========= AreaVisitor=========
AreaVisitor::AreaVisitor(double area) : area(area) {}

void AreaVisitor::visit(Ring *Ring) { area = M_PI * pow(Ring->getRadius(), 2); }

void AreaVisitor::visit(Square *square) { area = pow(square->getSide(), 2); }

void AreaVisitor::visit(Rectangle *rectangle) {
  area = rectangle->getLength() * rectangle->getWidth();
}

// ========= PerimeterVisitor =========
PerimeterVisitor::PerimeterVisitor(double perimeter) : perimeter(perimeter) {}

void PerimeterVisitor::visit(Ring *Ring) {
  perimeter = 2 * M_PI * Ring->getRadius();
}

void PerimeterVisitor::visit(Square *square) {
  perimeter = 4 * square->getSide();
}

void PerimeterVisitor::visit(Rectangle *rectangle) {
  perimeter = 2 * rectangle->getLength() + 2 * rectangle->getWidth();
}

// ========= Main =========
int main() {
  Ring *ring = new Ring(4);
  Square *square = new Square(20);
  Rectangle *rectangle = new Rectangle(5, 3);

  AreaVisitor *aVisitor = new AreaVisitor();
  PerimeterVisitor *pVisitor = new PerimeterVisitor();

  std::vector<double> values;

  // ===== Ring =====
  ring->accept(aVisitor);
  auto areaRing = aVisitor->getArea();

  ring->accept(pVisitor);
  auto perimeterRing = pVisitor->getPerimeter();

  // ===== square =====
  square->accept(aVisitor);
  auto areaSquare = aVisitor->getArea();

  square->accept(pVisitor);
  auto perimeterSquare = pVisitor->getPerimeter();

  // ===== rectangle =====
  rectangle->accept(aVisitor);
  auto areaRectangle = aVisitor->getArea();

  rectangle->accept(pVisitor);
  auto perimeterRectangle = pVisitor->getPerimeter();

  // ===== printing =====
  values.push_back(areaRing);
  values.push_back(perimeterRing);
  values.push_back(areaSquare);
  values.push_back(perimeterSquare);
  values.push_back(areaRectangle);
  values.push_back(perimeterRectangle);

  for (int i = 0; i < values.size(); i++) {
    std::cout << values.at(i) << std::endl;
  }

  return 0;
}