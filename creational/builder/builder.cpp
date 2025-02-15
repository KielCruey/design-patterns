#include "builder.hpp"

// ============ Car ============
Car::Car(std::string make, std::string model) :
    make(make),
    model(model)
{
    std::cout << "Constructor -- Car" << std::endl; 
}

Car::~Car() { 
    std::cout << "Deconstructor -- Car" << std::endl; 
}

void Car::printMake() const {
    std::cout << "Make: " + GetMake() << std::endl;
}

void Car::printModel() const {
    std::cout << "Model: " + GetModel() << std::endl;
}

// ============ Concrete Builder ============
ConcreteCarBuilder::ConcreteCarBuilder(std::string make, std::string model){
    this->CreateCar(make, model);
}

ConcreteCarBuilder::~ConcreteCarBuilder() {
    delete this->car;
}

void ConcreteCarBuilder::CreateCar(std::string make, std::string model) {
    SetCar(new Car(make, model));
}

void ConcreteCarBuilder::ProduceEngine() { 
    std::cout << "Engine Created! -- Car" << std::endl;
}

void ConcreteCarBuilder::ProduceChassis() {
    std::cout << "Chassis Created! -- Car" << std::endl;
}

void ConcreteCarBuilder::ProduceTransmission() {
    std::cout << "Transmission Created! -- Car" << std::endl;
}

// ============ Director ============
void CarDirector::BuildMinimalViableCar() {
    this->carBuilder->ProduceChassis();
}

void CarDirector::BuildMaximumViableCar() {
    this->carBuilder->ProduceEngine();
    this->carBuilder->ProduceTransmission();
    this->carBuilder->ProduceChassis();
}

// ============ Client Code ============
// implemented with the CarDirector class
static void SeasonalProjectCars(CarDirector * carDirector) {
    // concreteCalBuilder makes the car object
    ConcreteCarBuilder * builder = new ConcreteCarBuilder();
    // director calls what type of car 'setting' it should have once assigned a concreteCarBuilder as parameter
    carDirector->SetBuilder(builder);

    // director creating a new "winter" build
    std::cout << "Winter Project Car Built!" << std::endl;
    // carDirector creates a Car object
    carDirector->BuildMinimalViableCar(); 

    // creating a Car object and assigning the Car object to the "favor" of car created but the concreteCarBuilder
    Car * winterCar = builder->GetCar();
    winterCar->printMake();
    winterCar->printModel();
    delete winterCar;

    // director creating a new "summer" build
    std::cout << "Summer Project Car Built!" << std::endl;
    // carDirector creates a Car object
    carDirector->BuildMaximumViableCar(); 

    // creating a Car object and assigning the Car object to the "favor" of car created but the concreteCarBuilder
    Car * summerCar = builder->GetCar();
    summerCar->printMake();
    summerCar->printModel();
    delete summerCar;

    delete builder;
}

// used without the CarDirector class
static void ProjectCars(CarDirector * carDirector) {
    ConcreteCarBuilder * builder = new ConcreteCarBuilder();
    carDirector->SetBuilder(builder);

    // now created "products" that car will have
    std::cout << "Spring Project Car Built!" << std::endl;
    builder->ProduceEngine();
    builder->ProduceChassis();

    // creating an Car object then populating that object via ConcreteCarBuilder
    Car * springCar = builder->GetCar();
    springCar->printMake();
    springCar->printModel();
    delete builder;
}

static void CarProject_MakeAndModel(CarDirector * carDirector) {
    ConcreteCarBuilder * builder = new ConcreteCarBuilder("Ford", "Mustang");
    carDirector->SetBuilder(builder);

    // director creating a new "summer" build
    std::cout << "Car Built!" << std::endl;
    // carDirector creates a Car object
    carDirector->BuildMaximumViableCar();

    // creating a Car object and assigning the Car object to the "favor" of car created but the concreteCarBuilder
    Car * completedCar = builder->GetCar();
    completedCar->printMake();
    completedCar->printModel();
    delete completedCar;
}

// ============ MAIN ============
int main() {
    CarDirector * director = new CarDirector();

    SeasonalProjectCars(director);
    ProjectCars(director);
    CarProject_MakeAndModel(director);

    delete director;
    return 0;
}
