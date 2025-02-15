#include <iostream>

#include "memento.hpp"

static void printToConsole(std::string toConsole) {
	std::cout << toConsole << std::endl;
}

template<typename t>
static void printContentToConsole(std::string output, t variable) {
	std::cout << output << variable << std::endl;
}

static void printSavedData(Memento * memento) {
	printContentToConsole("Name: ", memento->getName());
	printContentToConsole("Specialization: ", memento->getSpecialization());
	printContentToConsole("State: ", memento->getState());
	printContentToConsole("Health: ", memento->getHealth());
	printContentToConsole("Mana: ", memento->getMana());
	printContentToConsole("Level: ", memento->getLevel());
}

// ======== Memento ========
Memento::Memento(std::string name,
				 std::string specialization,
				 std::string state,
				 int level,
				 int health,
				 int mana) :
	name(name),
	specialization(specialization),
	state(state),
	level(level),
	health(health),
	mana(mana)
{
	// need to initialize date and time variables
	date = "";
	time = "";

	printToConsole("Memento created");
}

Memento::~Memento() {
	printToConsole("Memento deleted");
}

// ======== Originator ========
Originator::Originator(std::string name,
					   std::string specialization,
					   std::string state,
					   int level,
					   int health,
					   int mana) :
	name(name),
	specialization(specialization),
	state(state),
	level(level),
	health(health),
	mana(mana)
{
	// checks value ranges for max/min
	if (getLevel() > MAXIMUM_LEVEL) setLevel(MAXIMUM_LEVEL);
	else if(getLevel() < MINIMUM_LEVEL) setLevel(MINIMUM_LEVEL);

	if (getHealth() > MAXIMUM_VALUE) setHealth(MAXIMUM_VALUE);
	else if (getHealth() < MINIMUM_VALUE) setHealth(MINIMUM_LEVEL);

	if (getMana() > MAXIMUM_VALUE) setMana(MAXIMUM_VALUE);
	else if (getHealth() < MINIMUM_VALUE) setMana(MINIMUM_VALUE);

	printToConsole("Originator created");
}

Originator::~Originator() {
	printToConsole("Originator deleted");
}

void Originator::changeName(std::string newName) {
	setName(newName);
}

void Originator::changeSpecialization(std::string newSpecialization) {
	setSpecialization(newSpecialization);
}

void Originator::changeState(std::string newState) {
	setState(newState);
}

void Originator::levelUp() {
	if (getLevel() < MAXIMUM_LEVEL) {
		setLevel(getLevel() + 1);
	}
}

void Originator::levelDown() {
	if (getLevel() > MINIMUM_LEVEL) {
		setLevel(getLevel() - 1);
	}
	
}

void Originator::healUp() {
	if (getHealth() < MAXIMUM_VALUE) {
		setHealth(getHealth() + 1);
	}
}

void Originator::healDown() {
	if (getHealth() > MINIMUM_VALUE) {
		setHealth(getHealth() - 1);
	}
}

void Originator::manaUp() {
	if (getMana() < MAXIMUM_VALUE) {
		setMana(getMana() + 1);
	}
}

void Originator::manaDown() {
	if (getMana() > MINIMUM_VALUE) {
		setMana(getMana() - 1);
	}
}

Memento * Originator::save() {
	return new Memento(this->getName(), 
					   this->getSpecialization(),
					   this->getState(), 
					   this->getLevel(),
					   this->getHealth(),
					   this->getMana());
}

void Originator::restore(Memento* memento) {
	setName(memento->getName());
	setSpecialization(memento->getSpecialization());
	setState(memento->getState());
	setLevel(memento->getLevel());
	setHealth(memento->getHealth());
	setMana(memento->getMana());
}

// ======== Caretaker ========
Caretaker::Caretaker(Originator * originator) :
	originator(originator)
{
	printToConsole("Originator created");
}

Caretaker::~Caretaker() {
	printToConsole("Originator deleted");
}

// saves a snapshot of the current state of the originator
void Caretaker::backup() {
	getMementos().push_back(getOriginator()->save());
}

// deletes the last snapshot, and reverts to last snapshot
void Caretaker::undo() {
	// checks if vector is empty
	if (!getMementos().size()) {
		return;
	}
	
	Memento * memento = getMementos().back(); // gets last element
	getMementos().pop_back(); // deletes last element

	try {
		getOriginator()->restore(memento); // places last save data into current data
	}
	catch (...) {
		undo();
	}
}

void Caretaker::showHistory() {
	printToConsole("List of Memento Saves:");

	for (Memento * memento : getMementos())	{
		printSavedData(memento);
	}
}

// ======== Main ========
int main() {

	Originator * originator = new Originator("George", "Monk", "Happy", 1, 100, 100);
	Caretaker * caretaker = new Caretaker(originator);

	// manipulating the 'originator' class and saving snapshots
	caretaker->backup();
	caretaker->showHistory();

	originator->levelUp();
	caretaker->backup();
	caretaker->showHistory();

	originator->manaDown();
	originator->healDown();
	caretaker->backup();
	caretaker->showHistory();

	originator->manaUp();
	originator->healUp();
	caretaker->backup();
	caretaker->showHistory();

	originator->changeState("Sad");
	caretaker->backup();
	caretaker->showHistory();

	originator->changeSpecialization("Bard");
	caretaker->backup();
	caretaker->showHistory();

	originator->changeName("Georgia");
	caretaker->backup();
	caretaker->showHistory();

	return 0;
}