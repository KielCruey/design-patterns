enum ShapeType { circle = 0, triangle };

// =============== Targets ===============
class AbstractShapes
{
public:
    virtual ~AbstractShapes() = 0;
    virtual double CalculateArea() = 0;
    virtual double CalculatePerimeter() = 0;

    virtual void print() = 0;
    virtual int GetShapeType() = 0;
};

class Circle : public AbstractShapes
{
public:
    Circle(double radius = 1.0); // assumes unit circle
    ~Circle() override;

    void print() override;

    double CalculateArea() override;
    double CalculatePerimeter() override;

    int GetShapeType() override;
    double GetArea();
    double GetPerimeter();
    double GetRadius();

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
    Triangle(double side1 = 1.0, double side2 = 1.0, double angleInDegrees = 90); // assumes unit right triangle
    ~Triangle() override;

    void print() override;

    double CalculateArea() override;
    double CalculatePerimeter() override;
    double CalculateHypotenuse();

    double ConvertDegreesToRadians(double degrees);

    int GetShapeType() override;
    double GetSide1();
    double GetSide2();
    double GetHypotenuse();
    double GetAngle();
    double GetArea();
    double GetPerimeter();

    void SetSide1(double side1);
    void SetSide2(double side2);
    void SetHypotenuse(double hypotenuse);
    void SetAngle(double angle);
    void SetArea(double area);
    void SetPerimeter(double perimeter);

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
    ShapeAdapter(AbstractShapes * abstractShapes = NULL);
    ~ShapeAdapter();

    Triangle * ConvertCircleToTriangle(Circle * circle);
    Circle * ConvertTriangleToCircle(Triangle * triangle);

    void SetCircle(Circle * pCircle);
    void SetTriangle(Triangle * pTriangle);

    Circle * GetCircle();
    Triangle * GetTriangle();

private:
    Circle * pCircle;
    Triangle * pTriangle;
};