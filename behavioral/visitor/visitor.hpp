class iShapeVisitor;

// ========= element =========
class iShape
{
    public:
    virtual void accept(iShapeVisitor* visitor) = 0;
};

// ========= concrete elements =========
class Circle : public iShape
{
public:
    Circle(double radius);
    
    double getRadius();
    void accept(iShapeVisitor* visitor);

private:
    double radius;
};

class Square : public iShape
{
public:
	Square(double side);

	double getSide();
	void accept(iShapeVisitor* visitor);

private:
	double side;
};

class Rectangle : public iShape
{
public:
	Rectangle(double length, double width);

	double getLength();
	double getWidth();
	void accept(iShapeVisitor* visitor);

private:
	double length;
	double width;
};

// ========= visitor =========
class iShapeVisitor
{
public:
    virtual void visit(Circle* circle) = 0;
    virtual void visit(Square* square) = 0;
    virtual void visit(Rectangle* rectangle) = 0;
};

// ========= concrete vistor =========
class AreaVisitor : public iShapeVisitor
{
public:
    void visit(Circle* circle);
    void visit(Square* square);
    void visit(Rectangle* rectangle);

    double getArea();

private:
    double area;
};

class PerimeterVisitor : public iShapeVisitor
{
public:
    void visit(Circle* circle);
    void visit(Square* square);
    void visit(Rectangle* rectangle);

    double getPerimeter();

private:
    double perimeter;
};