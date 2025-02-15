// ========== Extras ========== 
inline int Extras::getSugarShot() const {
	return this->sugarShot;
}

inline int Extras::getCreamShot() const {
	return this->creamShot;
}

inline int Extras::getMilkShot() const {
	return this->milkShot;
}

inline int Extras::getChocolateShot() const {
	return this->chocolateShot;
}

inline void Extras::setSugarShot(int sugarShot) {
	this->sugarShot = sugarShot;
}

inline void Extras::setCreamShot(int creamShot) {
	this->creamShot = creamShot;
}

inline void Extras::setMilkShot(int milkShot) {
	this->milkShot = milkShot;
}

inline void Extras::setChocolateShot(int chocolateShot) {
	this->chocolateShot = chocolateShot;
}

// ========== Teas ========== 
inline int Teas::getGreenTea() const {
	return this->greenTea;
}

inline int Teas::getBlackTea() const {
	return this->blackTea;
}

inline int Teas::getChiaTea() const {
	return this->chiaTea;
}

inline void Teas::setGreenTea(int greenTea) {
	this->greenTea = greenTea;
}

inline void Teas::setBlackTea(int blackTea) {
	this->blackTea = blackTea;
}

inline void Teas::setChiaTea(int chiaTea) {
	this->chiaTea = chiaTea;
}

// ========== Coffees ==========
inline int Coffees::getLightRoast() const {
	return this->lightRoast;
}

inline int Coffees::getMediumRoast() const {
	return this->mediumRoast;
}

inline int Coffees::getDarkRoast() const {
	return this->darkRoast;
}

inline void Coffees::setLightRoast(int lightRoast) {
	this->lightRoast = lightRoast;
}

inline void Coffees::setMediumRoast(int mediumRoast) {
	this->mediumRoast = mediumRoast;
}

inline void Coffees::setDarkRoast(int darkRoast) {
	this->darkRoast = darkRoast;
}

// ========== Beverage Maker ==========
inline Extras* BeverageMaker::getExtras() const {
	return this->extras;
}

inline Teas* BeverageMaker::getTeas() const {
	return this->teas;
}

inline Coffees* BeverageMaker::getCoffees() const {
	return this->coffees;
}

inline int BeverageMaker::getCups() const {
	return this->cups;
}

inline double BeverageMaker::getWaterAmount() const {
	return this->waterAmount;
}

inline void BeverageMaker::setExtras(Extras* extras) {
	this->extras = extras;
}

inline void BeverageMaker::setTeas(Teas* teas) {
	this->teas = teas;
}

inline void BeverageMaker::setCoffees(Coffees* coffees) {
	this->coffees = coffees;
}

inline void BeverageMaker::setCups(int cups) {
	if(cups > 0) this->cups = cups;
}

inline void BeverageMaker::setWaterAmount(double waterAmount) {
	if(waterAmount > 0) this->waterAmount = waterAmount;
}