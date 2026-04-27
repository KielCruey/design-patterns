enum ShapeType { circle = 0, triangle };

// =============== Targets ===============
class AbstractShapes
{
public:
    virtual ~AbstractShapes() = default;
    virtual double CalculateArea() = 0;
    virtual double CalculatePerimeter() = 0;

    virtual void print() = 0;
    virtual int GetShapeType() = 0;
};

class Circle : public AbstractShapes
{
public:
    explicit Circle(double radius = 1.0); // assumes unit circle
    ~Circle() override;

    double CalculateArea() override;
    double CalculatePerimeter() override;

    void print() override;
    int GetShapeType() override;

    double GetArea() const;
    double GetPerimeter() const;
    double GetRadius() const;

    void SetArea(double area);
    void SetPerimeter(double perimeter);
    void SetRadius(double radius);

private:
    double radius;
    double area;
    double perimeter;
};

class Triangle : public AbstractShapes
{
public:
    explicit Triangle(double side1 = 1.0, double side2 = 1.0, double angleInDegrees = 90); // assumes unit right triangle
    ~Triangle() override;

    void print() override;

    double CalculateArea() override;
    double CalculatePerimeter() override;
    double CalculateHypotenuse();

    static double ConvertDegreesToRadians(double degrees);

    inline int GetShapeType() override;
    inline double GetSide1();
    inline double GetSide2();
    inline double GetHypotenuse();
    inline double GetAngle();
    inline double GetArea();
    inline double GetPerimeter();

    inline void SetSide1(double side1);
    inline void SetSide2(double side2);
    inline void SetHypotenuse(double hypotenuse);
    inline void SetAngle(double angle);
    inline void SetArea(double area);
    inline void SetPerimeter(double perimeter);

private:
    // given parameters
    double side1;
    double side2;
    double angle; // in [rads]

    // calculated parameters
    double hypotenuse;
    double area;
    double perimeter;
};

// =============== Adapter ===============
class ShapeAdapter : public Circle, public Triangle
{
public:
    explicit ShapeAdapter(AbstractShapes * abstractShapes = NULL);
    ~ShapeAdapter() override;

    Triangle * ConvertCircleToTriangle(Circle const* circle);
    Circle * ConvertTriangleToCircle(Triangle * triangle);

    void SetCircle(Circle * pCircle);
    void SetTriangle(Triangle * pTriangle);

    Circle * GetCircle();
    Triangle * GetTriangle();

private:
    Circle * pCircle;
    Triangle * pTriangle;
};

#include "class-adapter.inl"