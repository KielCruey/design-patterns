#include <iostream>
#include <string>
#include <unordered_map>

// =========== Intrinsic State ===========
// Intrinsic states in this class can only be read only member variables and not be written 
// since they are all common for all the objects of this class.
class SharedState
{
public:
	SharedState(const std::string &brand = nullptr, 
				const std::string &model = nullptr,
				const std::string &color = nullptr);
	~SharedState();

	// prints out all member variables to console
	friend std::ostream& operator<<(std::ostream& os, const SharedState& ss);

	// can't set member variables because intrensic class, all should be the same
	inline std::string GetBrand() const;
	inline std::string GetModel() const;
	inline std::string GetColor() const;

private:
	// read only variables
	std::string brand;
	std::string model;
	std::string color;
};

// =========== Extrinsic State ===========
// Extrinsic state in this class differ from object to object
class UnsharedState
{
public:
	UnsharedState(std::string owner, 
				std::string plateNumber);
	~UnsharedState();

	// prints out all member variables to console
	friend std::ostream& operator<<(std::ostream& os, const UnsharedState& us);

	// getters/setters
	inline std::string GetOwner() const;
	inline std::string GetPlateNumber() const;
	inline void SetOwner(std::string owner);
	inline void SetPlateNumber(std::string plateNumber);

private:
	std::string owner;
	std::string plateNumber;
};

// =========== Flyweight ===========
// Flyweight class stores the intrensic data and accept extrensic state as a parameter
class Car
{
public: 
	Car(const SharedState * sharedState);
	Car(const Car & car); // copy constructor
	~Car();

	inline SharedState * GetSharedState() const;

	// prints all data information
	void Print(const UnsharedState& UnsharedState) const;

private:
	// all the common data as a reference
	SharedState * sharedState;
};

// =========== Flyweight Factory ===========
// Car flyweight factor creates and magages all the flyweight objects.
// When the client requests a flyweight, the factory either returns an existing instance or creates a new one, 
// if it doesn't exist yet.
class CarFactory
{
public:
	// allows to use the curly brackets {} to define a set of data to the constructor
	CarFactory(std::initializer_list<SharedState> shareStates);
	~CarFactory();

	Car GetCar(const SharedState & sharedState); // gets a Car object with some key
	void ListCars() const;

private:
	std::string getKey(const SharedState& ss) const; // gets object with unique key or creates a new key 
	std::unordered_map<std::string, Car> cars; // stores all the extrensic state classes via a key
};

#include "flyweight.inl"