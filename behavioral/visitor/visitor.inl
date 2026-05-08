// ========= Ring =========
inline double Ring::getRadius() const { return this->radius; }

// ========= Square =========
inline double Square::getSide() const { return this->side; }

// ========= Rectangle =========
inline double Rectangle::getLength() const { return this->length; }

inline double Rectangle::getWidth() const { return this->width; }

// ========= AreaVisitor =========
inline double AreaVisitor::getArea() const { return this->area; }

// ========= PerimeterVisitor =========
inline double PerimeterVisitor::getPerimeter() const { return this->perimeter; }
