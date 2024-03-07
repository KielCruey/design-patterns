#include "flyweight.hpp"

// =========== SharedState ===========
SharedState::SharedState(const std::string& brand,
						const std::string& model,
						const std::string& color) :
	brand(brand),
	model(model),
	color(color)	
{
	printToConsole("SharedState created");
}

SharedState::~SharedState() {
	printToConsole("SharedState deleted");
}

std::ostream& operator<<(std::ostream& os, const SharedState& ss) {
	return os << "[ " << ss.brand << " , " << ss.model << " , " << ss.color << " ]";
}

// =========== UniqueState ===========
UniqueState::UniqueState(std::string owner, std::string plateNumber) :
	owner(owner),
	plateNumber(plateNumber)
{
	printToConsole("UniqueState created");
}

UniqueState::~UniqueState() {
	printToConsole("UniqueState deleted");
}

std::ostream& operator<<(std::ostream& os, const UniqueState& us) {
	return os << "[ " << us.owner << " , " << us.plateNumber << " ]";
}

// =========== Flyweight ===========
Car::Car(const SharedState* sharedState) :
	sharedState(new SharedState(*sharedState))
{
	printToConsole("Car created");
}

// copy constructor -- creates a dynamic memory object
Car::Car(const Car& car) :
	sharedState(new SharedState(*car.sharedState))
{
	printToConsole("Car's Copy constructor");
}

Car::~Car() {
	delete sharedState;
	printToConsole("Car deleted");
}

void Car::Print(const UniqueState& uniqueState) const {
	std::cout << "Car flyweight: Displaying shared (" << *GetSharedState() << ") and unique (" << uniqueState << " state" << std::endl;
}

// =========== CarFactory ===========
CarFactory::CarFactory(std::initializer_list<SharedState> shareStates) {
	printToConsole("CarFactory created");

	for (const SharedState& ss : shareStates) {
		cars.insert(std::make_pair<std::string, Car>(getKey(ss), Car(&ss)));
	}
}

CarFactory::~CarFactory() {
	printToConsole("CarFactory destroyed");
}

Car CarFactory::GetCar(const SharedState& sharedState) {
	std::string key = getKey(sharedState);

	// check if a Car with a certain key exists in unordered_map
	if (cars.find(key) == cars.end()) {
		printToConsole("FlyweightFactory: Can't find a flyweight, creating new one.");
		cars.insert(std::make_pair(key, Car(&sharedState)));
	}
	else {
		printToConsole("FlyweightFactory: Reusing existing flyweight.");
	}

	return cars.at(key);
}

void CarFactory::ListCars() const {
	size_t count = cars.size();

	std::cout << "CarFactory: has " << count << " cars:" << std::endl;
	for (std::pair<std::string, Car> pair : cars) {
		std::cout << pair.first << std::endl;
	}
}

std::string CarFactory::getKey(const SharedState& ss) const {
	return ss.GetBrand() + "_" + ss.GetModel() + "_" + ss.GetColor();
}

// =========== Main ===========
int main() {
	CarFactory * factory = new CarFactory({ {"Subaru", "BRZ", "Red"}, { "Subaru", "WRX", "Blue" } });

	factory->ListCars();

	return 0;
}