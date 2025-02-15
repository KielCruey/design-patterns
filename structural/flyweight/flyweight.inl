// =========== SharedState ===========
inline std::string SharedState::GetBrand() const {
	return this->brand;
}

inline std::string SharedState::GetModel() const {
	return  this->model;
}

inline std::string SharedState::GetColor() const {
	return this->color;
}

// =========== UnsharedState ===========
inline std::string UnsharedState::GetOwner() const {
	return this->owner;
}

inline std::string UnsharedState::GetPlateNumber() const {
	return this->plateNumber;
}

inline void UnsharedState::SetOwner(std::string owner) {
	this->owner = owner;
}

inline void UnsharedState::SetPlateNumber(std::string plateNumber) {
	this->plateNumber = plateNumber;
}

// =========== Car ===========
inline SharedState* Car::GetSharedState() const {
	return this->sharedState;
}