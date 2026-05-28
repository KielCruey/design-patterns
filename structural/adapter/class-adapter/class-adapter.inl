#define M_PI 3.14159265358979323846 // pi constant

#include <cmath> // pow

// ======= Circle =======
inline double Circle::CalculateArea() { return M_PI * pow(GetRadius(), 2); }

inline double Circle::CalculatePerimeter() { return 2 * M_PI * GetRadius(); }

inline int Circle::GetShapeType() { return ShapeType::circle; }

inline double Circle::GetArea() const { return this->area; }

inline double Circle::GetPerimeter() const { return this->perimeter; }

inline double Circle::GetRadius() const { return this->radius; }

inline void Circle::SetArea(double area) { this->area = area; }

inline void Circle::SetPerimeter(double perimeter) {
  this->perimeter = perimeter;
}

inline void Circle::SetRadius(double radius) { this->radius = radius; }

// ======= Triangle =======
inline int Triangle::GetShapeType() { return ShapeType::triangle; }

inline double Triangle::GetSide1() { return this->side1; }

inline double Triangle::GetSide2() { return this->side2; }

inline double Triangle::GetHypotenuse() { return this->hypotenuse; }

inline double Triangle::GetAngle() { return this->angle; }

inline double Triangle::GetArea() { return this->area; }

inline double Triangle::GetPerimeter() { return this->perimeter; }

inline void Triangle::SetSide1(double side1) { this->side1 = side1; }

inline void Triangle::SetSide2(double side2) { this->side2 = side2; }

inline void Triangle::SetHypotenuse(double hypotenuse) {
  this->hypotenuse = hypotenuse;
}

inline void Triangle::SetAngle(double angle) { this->angle = angle; }

inline void Triangle::SetArea(double area) { this->area = area; }

inline void Triangle::SetPerimeter(double perimeter) {
  this->perimeter = perimeter;
}