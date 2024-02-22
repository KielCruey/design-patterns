#include <string>
#include <iostream>
#include <unordered_map>

// =========== States ===========
// intrinsic state class
class SharedState
{
public:
	SharedState(const std::string &brand, 
				const std::string &model, 
				const std::string  &color);
	~SharedState();

	friend std::ostream& operator<<(std::ostream& os, const SharedState& ss);

	std::string GetBrand();
	std::string GetModel();
	std::string GetColor();

	void GetBrand(std::string brand);
	void GetModel(std::string model);
	void GetColor(std::string color);

private:
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

	std::string GetOwner();
	std::string GetPlateNumber();
	
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

	void Print(const UniqueState& unique_state) const;

private:
	SharedState * sharedState;
};

class FlyweightFactory
{
public:


private:
	std::unordered_map<std::string, Car> flyweight;
	std::string GetKey(const SharedState &ss);
};