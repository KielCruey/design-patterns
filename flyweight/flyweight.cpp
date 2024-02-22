#include "flyweight.hpp"

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

int main() {
	return 0;
}
