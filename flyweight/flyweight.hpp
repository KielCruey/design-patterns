#include <string>
#include <unordered_map>

// =========== States ===========
// intrinsic state class
class SharedState
{
public:
	SharedState();
	~SharedState();

	std::string GetTreeType();
	std::string GetTreeSpecies();

private:
	std::string treeType;
	std::string treeSpecies;
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
	int age;
	double height;
};

/**
 * The Flyweight stores a common portion of the state (also called intrinsic
 * state) that belongs to multiple real entities. The Flyweight accepts
 * the rest of the state (extrinsic state, unique for each entity) via its
 * method parameters.
 */

class Flyweight
{
public: 
	Flyweight();
	~Flyweight();

	SharedState * GetSharedState() const;

private:
	SharedState * sharedState;
};

class FlyweightFactory
{
public:


private:
	std::unordered_map<std::string, Flyweight> flyweight;
};