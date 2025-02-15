// ======== Memento ========
inline std::string Memento::getDate() {
	return this->date;
}

inline std::string Memento::getTime() {
	return this->time;
}

inline std::string Memento::getName() {
	return this->name;
}

inline std::string Memento::getSpecialization() {
	return this->specialization;
}

inline std::string Memento::getState() {
	return this->state;
}

inline int Memento::getHealth() {
	return this->health;
}

inline int Memento::getMana() {
	return this->mana;
}

inline int Memento::getLevel() {
	return this->level;
}

// ======== Originator ========
inline std::string Originator::getName() {
	return this->name;
}

inline std::string Originator::getSpecialization() {
	return this->specialization;
}

inline std::string Originator::getState() {
	return this->state;
}

inline int Originator::getLevel() {
	return this->level;
}

inline int Originator::getHealth() {
	return this->health;
}

inline int Originator::getMana() {
	return this->mana;
}

inline void Originator::setName(std::string name) {
	this->name = name;
}

inline void Originator::setSpecialization(std::string specialization) {
	this->specialization = specialization;
}

inline void Originator::setState(std::string state) {
	this->state = state;
}

inline void Originator::setLevel(int level) {
	this->level = level;
}

inline void Originator::setHealth(int health) {
	this->health = health;
}

inline void Originator::setMana(int mana) {
	this->mana = mana;
}

// ======== Caretaker ========
inline Originator * Caretaker::getOriginator() {
	return this->originator;
}

inline void Caretaker::setOriginator(std::vector<Memento*> mementos) {
	this->originator = originator;
}

inline std::vector<Memento*> &Caretaker::getMementos() {
	return this->mementos;
}