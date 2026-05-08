class iShapeVisitor;

// ========= element =========
class iShape {
public:
  virtual void accept(iShapeVisitor *visitor) = 0;
};

// ========= concrete elements =========
class Ring : public iShape {
public:
  explicit Ring(double radius = 1);

  void accept(iShapeVisitor *visitor) override;

  inline double getRadius() const;

private:
  double radius;
};

class Square : public iShape {
public:
  explicit Square(double side = 1);

  void accept(iShapeVisitor *visitor) override;

  inline double getSide() const;

private:
  double side;
};

class Rectangle : public iShape {
public:
  explicit Rectangle(double length = 1, double width = 1);

  void accept(iShapeVisitor *visitor) override;

  inline double getLength() const;
  inline double getWidth() const;

private:
  double length;
  double width;
};

// ========= visitor =========
class iShapeVisitor {
public:
  virtual void visit(Ring *Ring) = 0;
  virtual void visit(Square *square) = 0;
  virtual void visit(Rectangle *rectangle) = 0;
};

// ========= concrete vistor =========
class AreaVisitor : public iShapeVisitor {
public:
  explicit AreaVisitor(double area = 0);

  void visit(Ring *Ring) override;
  void visit(Square *square) override;
  void visit(Rectangle *rectangle) override;

  inline double getArea() const;

private:
  double area;
};

class PerimeterVisitor : public iShapeVisitor {
public:
  explicit PerimeterVisitor(double perimeter = 0);

  void visit(Ring *Ring) override;
  void visit(Square *square) override;
  void visit(Rectangle *rectangle) override;

  inline double getPerimeter() const;

private:
  double perimeter;
};

#include "visitor.inl"