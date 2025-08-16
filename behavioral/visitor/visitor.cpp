#define _USE_MATH_DEFINES
#include <math.h> // M_PI'

#include <vector>
#include <iostream>
#include <iomanip> // setprecision

#include "visitor.hpp"

// ========= concrete elements =========
// ========= concrete Circle =========
Circle::Circle(double radius = 1) 
	: radius(radius)
{ }
    
double Circle::getRadius() {
	return this->radius;
}

void Circle::accept(iShapeVisitor* visitor) {
	visitor->visit(this);
}

// ========= concrete Square =========
Square::Square(double side) 
	: side(side)
{ }

double Square::getSide() {
	return this->side;
}

void Square::accept(iShapeVisitor* visitor) {
	visitor->visit(this);
}

// ========= concrete Rectangle =========
Rectangle::Rectangle(double length, double width)
	: length(length), width(width)
{ }

double Rectangle::getLength() {
	return this->length;
}

double Rectangle::getWidth() {
	return this->width;
}

void Rectangle::accept(iShapeVisitor* visitor) {
	visitor->visit(this);
}

// ========= concrete vistor =========
// ========= area vistor =========
void AreaVisitor::visit(Circle* circle) {
	area = M_PI * pow(circle->getRadius(),2);
}

void AreaVisitor::visit(Square* square) {
	area = pow(square->getSide(), 2);
}

void AreaVisitor::visit(Rectangle* rectangle) {
	area = rectangle->getLength() * rectangle->getWidth();
}

double AreaVisitor::getArea() {
	return this->area;
}

// ========= parameter vistor =========
void PerimeterVisitor::visit(Circle* circle) {
	perimeter = 2 * M_PI * circle->getRadius();
}

void PerimeterVisitor::visit(Square* square) {
	perimeter = 4 * square->getSide();
}

void PerimeterVisitor::visit(Rectangle* rectangle) {
	perimeter = 2 * rectangle->getLength() + 2 * rectangle->getWidth();
}

double PerimeterVisitor::getPerimeter() {
	return this->perimeter;
}

// ========= Main =========
int main() {
	Circle *circle = new Circle(4);
	Square *square = new Square(20);
	Rectangle *rectangle = new Rectangle(5,3);

	AreaVisitor *aVisitor = new AreaVisitor();
	PerimeterVisitor *pVisitor = new PerimeterVisitor();

	std::vector<double> values;

	// ===== circle =====
	circle->accept(aVisitor);
	auto areaCircle = aVisitor->getArea();

	circle->accept(pVisitor);
	auto perimeterCircle = pVisitor->getPerimeter();

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
	values.push_back(areaCircle);
	values.push_back(perimeterCircle);
	values.push_back(areaSquare);
	values.push_back(perimeterSquare);
	values.push_back(areaRectangle);
	values.push_back(perimeterRectangle);

	for (int i = 0; i < values.size(); i++) {
		std::cout << values.at(i) << std::endl;
	}

	return 0;
}