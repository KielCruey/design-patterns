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
	UniqueState();
	~UniqueState();

	int GetAge();
	double GetHeight();
	
private:
	std::string owner;
	std::string plateNumber;
};


// =========== Flyweight ===========
class Car
{
public: 
	Car();
	~Car();

	SharedState * GetSharedState() const;

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