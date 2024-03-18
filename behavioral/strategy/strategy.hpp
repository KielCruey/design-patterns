#include <memory> // unique_ptr
#include <vector>
#include <string>


// ========== Abstract Strategy ==========
class iAlgorithmStrategy
{
public:
	~iAlgorithmStrategy() = default;

	virtual std::vector<int>* doAlgorithm(std::vector<int>* data) = 0;
};

// ========== Concrete Strategy ==========
class IncreasingSort : public iAlgorithmStrategy
{
public:
	std::vector<int>* doAlgorithm(std::vector<int>* data) override;
};

class DecreasingSort : public iAlgorithmStrategy
{
public:
	std::vector<int>* doAlgorithm(std::vector<int>* data) override;
};

// ========== Context ==========
class Data
{
public:
	Data() = default;
	Data(std::unique_ptr<iAlgorithmStrategy>&& strategy); // move constructor -- for ownership
	
	void setStrategy(std::unique_ptr<iAlgorithmStrategy>&& strategy);
	void setVector(std::vector<int>* data);
	void doAlgorithm(std::vector<int>* data);

	std::vector<int>* sort();

private:
	std::unique_ptr<iAlgorithmStrategy> strategy;
	std::vector<int>* data;
};

// ========== Concrete Strategies ==========
#include "strategy.inl"
