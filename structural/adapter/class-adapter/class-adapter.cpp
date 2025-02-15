#include <math.h>
#include <iostream>

#include "class-adapter.hpp"

#define M_PI    3.14159265358979323846 // pi constant

// ==================== AbstractShapes ====================
AbstractShapes::~AbstractShapes()
{
    
}

// ==================== Circle ====================
Circle::Circle(double radius) {
    std::cout << "Circle created" << std::endl;

    // populates all private variables
    SetRadius(radius);
    SetArea(CalculateArea());
    SetPerimeter(CalculatePerimeter());
}

Circle::~Circle() {
    std::cout << "Circle destroyed" << std::endl;
}

void Circle::print() {
    std::cout << "Circle's variables!" << std::endl;
    std::cout << "radius: " << GetRadius() << std::endl;
    std::cout << "perimeter: " << GetPerimeter() << std::endl;
    std::cout << "area: " << GetArea() << std::endl;
}

double Circle::CalculateArea() {
    return M_PI * pow(GetRadius(), 2);
}

double Circle::CalculatePerimeter() {
    return 2 * M_PI * GetRadius(); 
}

int Circle::GetShapeType() {
    return ShapeType::circle;
}

double Circle::GetArea() {
    return this->area;
}

double Circle::GetPerimeter() {
    return this->perimeter;
}

double Circle::GetRadius() {
    return this->radius;
}

void Circle::SetArea(double area) {
    this->area = area;
}

void Circle::SetPerimeter(double perimeter) {
    this->perimeter = perimeter;
}

void Circle::SetRadius(double radius) {
    this->radius = radius;
}

// ==================== Triangle ====================
Triangle::Triangle(double side1, double side2, double angleInDegrees) {
    std::cout << "Triangle created" << std::endl;

    /* given variables */
    SetSide1(side1);
    SetSide2(side2);

    // makes sure angle is between 0-360 degrees
    angleInDegrees = abs(angleInDegrees);
    while(angleInDegrees > 360)
    {
        angleInDegrees = angleInDegrees - 360;
    }
    SetAngle(ConvertDegreesToRadians(angleInDegrees));

    // calculated variables
    SetHypotenuse(CalculateHypotenuse());
    SetArea(CalculateArea());
    SetPerimeter(CalculatePerimeter());
}

Triangle::~Triangle() {
    std::cout << "Triangle destroyed" << std::endl;
}

void Triangle::print() {
    std::cout << "Triangle's variables!" << std::endl;
    std::cout << "side1: " << GetSide1() << std::endl;
    std::cout << "side2: " << GetSide2() << std::endl;
    std::cout << "angle: " << GetAngle() << std::endl;
    std::cout << "hypotenuse: " << GetHypotenuse() << std::endl;
    std::cout << "perimeter: " << GetPerimeter() << std::endl;
    std::cout << "area: " << GetArea() << std::endl;
}

double Triangle::CalculateArea() {
    return GetSide1() * GetSide2() * sin(GetAngle()) / 2 ;
}

double Triangle::CalculatePerimeter() {
    return GetSide1() + GetSide2() + GetHypotenuse();
}

// law of cosines -- 2 side and 1 angle given by constructor
double Triangle::CalculateHypotenuse() {
    return abs( sqrt( pow(GetSide1(), 2) + pow(GetSide2(), 2) - 2 * GetSide1() * GetSide2() * cos(GetAngle()) ));
}

double Triangle::ConvertDegreesToRadians(double degrees) {
    return degrees * M_PI / 180; // radians
}

int Triangle::GetShapeType() {
    return ShapeType::triangle;
}

double Triangle::GetSide1() {
    return this->side1;
}

double Triangle::GetSide2() {
    return this->side2;
}

double Triangle::GetHypotenuse() {
    return this->hypotenuse;
}

double Triangle::GetAngle() {
    return this->angle;
}

double Triangle::GetArea() {
    return this->area;
}

double Triangle::GetPerimeter() {
    return this->perimeter;
}

void Triangle::SetSide1(double side1) {
    this->side1 = side1;
}

void Triangle::SetSide2(double side2) {
    this->side2 = side2;
}

void Triangle::SetHypotenuse(double hypotenuse) {
    this->hypotenuse = hypotenuse;
}

void Triangle::SetAngle(double angle) {
    this->angle = angle;
}

void Triangle::SetArea(double area) {
    this->area = area;
}

void Triangle::SetPerimeter(double perimeter) {
    this->perimeter = perimeter;
}

// ==================== Adapter ====================
ShapeAdapter::ShapeAdapter(AbstractShapes * abstractShapes) :
    pTriangle(nullptr),
    pCircle(nullptr)
{
    std::cout << "ShapeAdapter created" << std::endl;

    if(abstractShapes->GetShapeType() == ShapeType::circle)
    {
        std::cout << "ShapeAdapter converts circle to triangle" << std::endl;
        SetCircle(dynamic_cast<Circle *>(abstractShapes));  // sets circle

        Triangle * triangle = ConvertCircleToTriangle(GetCircle());
        SetTriangle(triangle);
    }
    else if(abstractShapes->GetShapeType() == ShapeType::triangle)
    {
        std::cout << "ShapeAdapter converts triangle to circle" << std::endl;
        SetTriangle(dynamic_cast<Triangle *>(abstractShapes)); // sets triangle

        Circle * circle = ConvertTriangleToCircle(GetTriangle());
        SetCircle(circle);
    }
}

ShapeAdapter::~ShapeAdapter() {
    std::cout << "ShapeAdapter Destroyed" << std::endl;
}

// the area of the circle helps convert all dimensions of the new triangle
Triangle * ShapeAdapter::ConvertCircleToTriangle(Circle * circle) {
    double triangleArea = circle->GetArea(); 
    double triangleSideCalculation = sqrt(2 * triangleArea); // Area = a * b / 2 where a = b, because right triangle legs are the same

    return new Triangle(triangleSideCalculation, triangleSideCalculation);
}

// the area of the triangle helps convert all dimensions of the new circle
Circle * ShapeAdapter::ConvertTriangleToCircle(Triangle * triangle) {
    double circleArea = triangle->GetArea();
    double circleRadius = sqrt(circleArea / M_PI); // area = pi * r^2

    return new Circle(circleRadius);
}

void ShapeAdapter::SetCircle(Circle * pCircle) {
    this->pCircle = pCircle;
}

void ShapeAdapter::SetTriangle(Triangle * pTriangle) {
    this->pTriangle = pTriangle;
}
    
Circle * ShapeAdapter::GetCircle() {
    return this->pCircle;
}

Triangle * ShapeAdapter::GetTriangle() {
    return this->pTriangle;
}

// ==================== Main ====================
int main() {
    Triangle * triangle = new Triangle();
    triangle->print();

    Circle * circle = new Circle();
    circle->print();

    ShapeAdapter * shapeAdapter1 = new ShapeAdapter(triangle);
    shapeAdapter1->GetTriangle()->print();
    shapeAdapter1->GetCircle()->print();
    
    ShapeAdapter * shapeAdapter2 = new ShapeAdapter(circle);
    shapeAdapter2->GetCircle()->print();
    shapeAdapter2->GetTriangle()->print();

    delete triangle;
    delete circle;
    
    delete shapeAdapter1;
    delete shapeAdapter2;

    return 0;
}