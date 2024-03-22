#include <vector>

// ========== Abstract Strategy ==========
class Sorting
{
public:
	virtual ~Sorting() = default;

	// returns the sorted 
	virtual std::vector<int> algorithm() = 0;
};

// ========== Context ==========
class Context
{

};

// ========== Concrete Strategy ==========
class Select
{

};

class Bubble
{

};

#include "strategy.inl"