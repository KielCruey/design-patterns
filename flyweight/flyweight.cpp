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

std::string SharedState::GetBrand() {
	return this->brand;
}
std::string SharedState::GetModel() {
	return  this->model;
}

std::string SharedState::GetColor() {
	return this->color;
}

void SharedState::GetBrand(std::string brand) {
	this->brand = brand;
}

void SharedState::GetModel(std::string model) {
	this->model = model;
}

void SharedState::GetColor(std::string color) {
	this->color = color;
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

std::string UniqueState::GetOwner() {
	return this->owner;
}

std::string UniqueState::GetPlateNumber() {
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

SharedState* Car::GetSharedState() const {
	this->sharedState;
}

void Car::Print(const UniqueState& uniqueState) const {
	std::cout << "Car flyweight: Displaying shared (" << *GetSharedState() << ") and unique (" << uniqueState << " state" << std::endl;
}

// =========== Main ===========
int main() {
	return 0;
}