#include <iostream>
#include <string>
#include <unordered_map>

// =========== utility functions ===========
static void printToConsole(std::string string) {
	std::cout << string << std::endl;
}

// =========== States - intrinsic state class ===========
// intrinsic states in this class can only be read only member variables and not written 
// since they are all common for all the objects of this class
class SharedState
{
public:
	SharedState(const std::string &brand = nullptr, 
				const std::string &model = nullptr,
				const std::string &color = nullptr);
	~SharedState();

	friend std::ostream& operator<<(std::ostream& os, const SharedState& ss);

	// can't set member variables because intrensic class
	std::string GetBrand() const;
	std::string GetModel() const;
	std::string GetColor() const;

private:
	// read only variables
	std::string brand;
	std::string model;
	std::string color;
};

// extrinsic state class
class UniqueState
{
public:
	UniqueState(std::string owner, std::string plateNumber);
	~UniqueState();

	friend std::ostream& operator<<(std::ostream& os, const UniqueState& us);

	std::string GetOwner() const;
	std::string GetPlateNumber() const;
	
	void SetOwner(std::string owner);
	void SetPlateNumber(std::string plateNumber);

private:
	std::string owner;
	std::string plateNumber;
};

// =========== Flyweight ===========
class Car
{
public: 
	Car(const SharedState * sharedState);
	Car(const Car & car); // copy constructor
	~Car();

	SharedState * GetSharedState() const;

	void Print(const UniqueState& uniqueState) const; // prints shared

private:
	SharedState * sharedState;
};

class CarFactory
{
public:
	CarFactory(std::initializer_list<SharedState> shareStates);
	~CarFactory();

	Car GetCar(const SharedState & sharedState); // gets a Car object with some key
	void ListCars() const;

private:
	std::string getKey(const SharedState& ss) const; // gets object with unique key or creates a new key 
	std::unordered_map<std::string, Car> cars; // stores all the extrensic state classes
};