#include <algorithm>

#include "strategy.hpp"

// ========== Concrete Strategy ==========
// ---------- IncreasingSort ----------
std::vector<int>* IncreasingSort::doAlgorithm(std::vector<int>* data) {
	std::sort(data->begin(), data->end(), std::greater<int>());
	return data;
}

// ---------- DecreasingSort ----------
std::vector<int>* DecreasingSort::doAlgorithm(std::vector<int>* data) {
	std::sort(data->rbegin(), data->rend(), std::greater<int>());
	return data;
}

// ========== Context ==========
Data::Data(std::unique_ptr<iAlgorithmStrategy>&& strategy)
{
	this->strategy = std::move(strategy);
}

void Data::setStrategy(std::unique_ptr<iAlgorithmStrategy>&& strategy) {
	this->strategy = std::move(strategy);
}

void Data::setVector(std::vector<int>*data) {
	this->data = data;
}

void Data::doAlgorithm(std::vector<int>* data) {
	strategy->doAlgorithm(data);
}

std::vector<int>* Data::sort() {
	std::vector<int>* v = this->strategy->doAlgorithm(this->data);

	return v;
}

int main() {
	std::vector<int> v { 7, 3, 8, 19, -23, 11, 11, -2, 3 };

	// testing -- IncreasingSort
	Data* data1 = new Data(std::make_unique<IncreasingSort>());
	data1->setVector(&v);
	data1->doAlgorithm(&v);

	// testing -- DecreasingSort
	Data* data2 = new Data(std::make_unique<DecreasingSort>());
	data2->setVector(&v);
	data2->doAlgorithm(&v);

	return 0;
}
