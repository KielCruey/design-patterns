#include "template-method.hpp"

static void printToConsole(std::string toConsole) {
	std::cout << toConsole << std::endl;
}

// =========== Extras ===========
Extras::Extras(int sugarShot,
				int creamShot,
				int milkShot,
				int chocolateShot) :
	sugarShot(sugarShot),
	creamShot(creamShot),
	milkShot(milkShot),
	chocolateShot(chocolateShot)
{ }

// =========== Teas ===========
Teas::Teas(int greenTea,
			int blackTea,
			int chiaTea) :
	greenTea(greenTea),
	blackTea(blackTea),
	chiaTea(chiaTea)
{ }

// =========== Coffees ===========
Coffees::Coffees(int lightRoast,
		int mediumRoast,
		int darkRoast) :
	lightRoast(lightRoast),
	mediumRoast(mediumRoast),
	darkRoast(darkRoast)
{ }

// =========== BeverageMaker ===========
BeverageMaker::BeverageMaker(Extras * extras,
							Teas * teas,
							Coffees * coffees,
							int cups,
							double waterAmount) :
	extras(new Extras(*extras)),
	cups(cups),
	waterAmount(waterAmount)
{
	if (teas != nullptr) {
		this->teas = new Teas(*teas);
	}

	if (coffees != nullptr) {
		this->coffees = new Coffees(*coffees);
	}

	printToConsole("BeverageMaker created");
}

BeverageMaker::~BeverageMaker() {
	delete extras;

	// only TeaMaker class needs to delete
	if (this->teas != nullptr) {
		delete teas;
	}

	if (this->coffees != nullptr) {
		delete coffees;
	}

	printToConsole("BeverageMaker deleted");
}

void BeverageMaker::restockExtras() {
	getExtras()->setSugarShot(MAX_EXTRAS_AMOUNT);
	getExtras()->setCreamShot(MAX_EXTRAS_AMOUNT);
	getExtras()->setMilkShot(MAX_EXTRAS_AMOUNT);
	getExtras()->setChocolateShot(MAX_EXTRAS_AMOUNT);

	printToConsole("Restocked extras");
}

void BeverageMaker::restockTeas() {
	getTeas()->setGreenTea(MAX_BEVERAGE_AMOUNT);
	getTeas()->setBlackTea(MAX_BEVERAGE_AMOUNT);
	getTeas()->setChiaTea(MAX_BEVERAGE_AMOUNT);

	printToConsole("Restocked teas");
}

void BeverageMaker::restockCoffees() {
	getCoffees()->setLightRoast(MAX_BEVERAGE_AMOUNT);
	getCoffees()->setMediumRoast(MAX_BEVERAGE_AMOUNT);
	getCoffees()->setDarkRoast(MAX_BEVERAGE_AMOUNT);

	printToConsole("Restocked coffees");
}

void BeverageMaker::placeCup() {
	setCups(getCups() - 1);

	printToConsole("Cup placed");
}

void BeverageMaker::boilWater() {
	printToConsole("Water boiled");
}

void BeverageMaker::pourInCup() {
	setWaterAmount(getWaterAmount() - BEVERAGE_WATER);

	printToConsole("Beverage poured in cup");
}

void BeverageMaker::restockCups() {
	setCups(MAX_CUPS);
}

void BeverageMaker::restockWater() {
	setWaterAmount(MAX_WATER_AMOUNT);
}

// =========== TeaMaker ===========
TeaMaker::TeaMaker(Extras* extras,
					Teas* teas,
					int cups,
					double waterAmount) :
	BeverageMaker(extras, teas, nullptr, cups, waterAmount)
{ }

TeaMaker::~TeaMaker() {
	printToConsole("TeaMaker deleted");
}

// calls template methods
void TeaMaker::makeBeverage(std::string beverageSelected) {
	placeCup();
	boilWater();
	brew(beverageSelected);
	pourInCup();
	addExtras();
}

void TeaMaker::brew(std::string beverageSelected) {
	if (beverageSelected == "green tea")
		this->getTeas()->setGreenTea(this->getTeas()->getGreenTea() - 1);
	else if (beverageSelected == "black tea")
		this->getTeas()->setBlackTea(this->getTeas()->getBlackTea() - 1);
	else if (beverageSelected == "chia tea")
		this->getTeas()->setChiaTea(this->getTeas()->getChiaTea() - 1);

	printToConsole("Brewing tea");
}

void TeaMaker::addExtras() {
	printToConsole("Tea extras added");
}

// =========== CoffeeMaker ===========
CoffeeMaker::CoffeeMaker(Extras* extras,
						Coffees* coffees,
						int cups,
						double waterAmount) :
	BeverageMaker(extras, nullptr, coffees, cups, waterAmount)
{ }

CoffeeMaker::~CoffeeMaker() {
	printToConsole("CoffeeMaker deleted");
}

// calls template methods
void CoffeeMaker::makeBeverage(std::string beverageSelected) {
	placeCup();
	boilWater();
	brew(beverageSelected);
	pourInCup();
	addExtras();
}

void CoffeeMaker::brew(std::string beverageSelected) {
	if (beverageSelected == "light roast")
		this->getCoffees()->setLightRoast(this->getCoffees()->getLightRoast() - 1);
	else if (beverageSelected == "medium roast")
		this->getCoffees()->setMediumRoast(this->getCoffees()->getMediumRoast() - 1);
	else if (beverageSelected == "dark roast")
		this->getCoffees()->setDarkRoast(this->getCoffees()->getDarkRoast() - 1);

	printToConsole("Brewing coffee");
}

void CoffeeMaker::addExtras() {
	printToConsole("Coffee extras added");
}

// =========== Client Code ===========
static TeaMaker * createTeaMaker() {
	Extras * extras = new Extras();
	Teas * teas = new Teas();

	TeaMaker * teaMaker = new TeaMaker(extras, teas);

	delete extras;
	delete teas;

	return teaMaker;
}

static CoffeeMaker * createCoffeeMaker() {
	Extras * extras = new Extras();
	Coffees * coffees = new Coffees();

	CoffeeMaker * coffeeMaker = new CoffeeMaker(extras, coffees);

	delete extras;
	delete coffees;

	return coffeeMaker;
}

static TeaMaker * refillMachine(TeaMaker & teaMaker) {
	if (teaMaker.getTeas() != nullptr)
		teaMaker.restockTeas();

	teaMaker.restockExtras();
	teaMaker.restockCups();
	teaMaker.restockWater();

	return &teaMaker;
}

static CoffeeMaker * refillMachine(CoffeeMaker & coffeeMaker) {
	if (coffeeMaker.getCoffees() != nullptr)
		coffeeMaker.restockCoffees();

	coffeeMaker.restockExtras();
	coffeeMaker.restockCups();
	coffeeMaker.restockWater();

	return &coffeeMaker;
}

// =========== Main ===========
int main() {
	// client code 'factories'
	TeaMaker * teaMaker = createTeaMaker();
	CoffeeMaker * coffeeMaker = createCoffeeMaker();

	// brewing different beverage calls the template method function called 'makeBeverage'
	// depending on if it's a tea or coffee maker, it will call the derived class's functions
	teaMaker->makeBeverage("green tea");
	teaMaker->makeBeverage("black tea");
	teaMaker->makeBeverage("chia tea");

	coffeeMaker->makeBeverage("light roast");
	coffeeMaker->makeBeverage("medium roast");
	coffeeMaker->makeBeverage("dark roast");

	// refill all of the machines
	teaMaker = refillMachine(*teaMaker);
	coffeeMaker = refillMachine(*coffeeMaker);

	delete teaMaker;
	delete coffeeMaker;

	return 0;
}