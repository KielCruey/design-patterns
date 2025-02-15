// ============ Car ============
inline void Car::SetMake(std::string make) {
    this->make = make;
}

inline void Car::SetModel(std::string model) {
    this->model = model;
}

inline std::string Car::GetMake() const {
    return this->make;
}

inline std::string Car::GetModel() const {
    return this->model;
}

// ============ ConcreteCarBuilder ============
inline void ConcreteCarBuilder::SetCar(Car* car) {
    this->car = car;
}

inline Car* ConcreteCarBuilder::GetCar() {
    Car* result = this->car;
    CreateCar();
    return result;
}

// ============ Director ============
inline void CarDirector::SetBuilder(CarBuilder* carBuilder) {
    this->carBuilder = carBuilder;
}