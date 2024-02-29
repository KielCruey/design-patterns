#include "flyweight.hpp"

// =========== SharedState ===========
SharedState::SharedState(const std::string& brand,
						const std::string& model,
						const std::string& color) :
	brand(brand),
	model(model),
	color(color)	
{
	std::cout << "SharedState created" << std::endl;
}

SharedState::~SharedState() {
	std::cout << "SharedState deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SharedState& ss)
{
	return os << "[ " << ss.brand << " , " << ss.model << " , " << ss.color << " ]";
}

std::string SharedState::GetBrand() const {
	return this->brand;
}

std::string SharedState::GetModel() const {
	return  this->model;
}

std::string SharedState::GetColor() const {
	return this->color;
}

// =========== UniqueState ===========
UniqueState::UniqueState(std::string owner, std::string plateNumber) :
	owner(owner),
	plateNumber(plateNumber)
{
	std::cout << "UniqueState created" << std::endl;
}

UniqueState::~UniqueState() {
	std::cout << "UniqueState deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const UniqueState& us) {
	return os << "[ " << us.owner << " , " << us.plateNumber << " ]";
}

std::string UniqueState::GetOwner() const {
	return this->owner;
}

std::string UniqueState::GetPlateNumber() const {
	return this->plateNumber;
}

void UniqueState::SetOwner(std::string owner) {
	this->owner = owner;
}

void UniqueState::SetPlateNumber(std::string plateNumber) {
	this->plateNumber = plateNumber;
}

// =========== Flyweight ===========
Car::Car(const SharedState* sharedState) :
	sharedState(new SharedState(*sharedState))
{
	std::cout << "Car created" << std::endl;
}

// copy constructor
Car::Car(const Car& car) :
	sharedState(new SharedState(*car.sharedState))
{
	std::cout << "Copy constructor" << std::endl;
}

Car::~Car() {
	delete sharedState;
	std::cout << "Car deleted" << std::endl;
}

SharedState * Car::GetSharedState() const {
	return this->sharedState;
}

void Car::Print(const UniqueState& uniqueState) const {
	std::cout << "Car flyweight: Displaying shared (" << *GetSharedState() << ") and unique (" << uniqueState << " state" << std::endl;
}

// =========== CarFactory ===========
CarFactory::CarFactory(std::initializer_list<SharedState> shareStates) {
	std::cout << "CarFactory created" << std::endl;
}

CarFactory::~CarFactory() {
	std::cout << "CarFactory destroyed" << std::endl;
}

Car CarFactory::GetCar(const SharedState& sharedState) {
	std::string key = getKey(sharedState);

	// check if a Car with a certain key exists in unordered_map
	if (cars.find(key) == cars.end()) {
		std::cout << "FlyweightFactory: Can't find a flyweight, creating new one." << std::endl;
		cars.insert(std::make_pair(key, Car(&sharedState)));
	}
	else {
		std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
	}

	return cars.at(key);
}

void CarFactory::ListCars() const {
	size_t count = cars.size();

	std::cout << "CarFactory: has " << count << " cars:" << std::endl;
	for (std::pair<std::string, Car> pair : cars)
	{
		std::cout << pair.first << std::endl;
	}
}

std::string CarFactory::getKey(const SharedState& ss) const {
	return ss.GetBrand() + "_" + ss.GetModel() + "_" + ss.GetColor();
}

// =========== Main ===========
int main() {
	SharedState * sharedState = new SharedState("Subaru", "BRZ", "Red");

	return 0;
}