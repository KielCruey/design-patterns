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

// =========== UniqueState ===========
inline std::string UniqueState::GetOwner() const {
	return this->owner;
}

inline std::string UniqueState::GetPlateNumber() const {
	return this->plateNumber;
}

inline void UniqueState::SetOwner(std::string owner) {
	this->owner = owner;
}

inline void UniqueState::SetPlateNumber(std::string plateNumber) {
	this->plateNumber = plateNumber;
}

// =========== Car ===========
inline SharedState* Car::GetSharedState() const {
	return this->sharedState;
}