#include <iostream>
#include <string>
#include <vector>

#include "factory-method.hpp"

// ============ animal ============
AbstractAnimal::~AbstractAnimal() {
    std::cout << "Abstract Animal destroyed" << std::endl;   
};

// ======= Cow =======
Cow::Cow() {
    std::cout << "I'm a cow!" << std::endl; 
}

Cow::Cow(std::string name) { 
    std::cout << "I'm a cow, and my name is " + name + "!" << std::endl; 
}

Cow::~Cow() { 
    std::cout << "No more cow!" << std::endl; 
}

std::string Cow::SoundsOfYourPeople() {
    return "Moo!"; 
}

void Cow::Sleeps() { 
    std::cout << "zzZZzz. Counting cows." << std::endl; 
}

void Cow::Eats() { 
    std::cout << "Starts to eat hay." << std::endl; 
}

std::string Cow::GetName() const { 
    return this->name; 
}

void Cow::SetName(std::string name) { 
    this->name = name; 
}

// ======= Sheep =======
Sheep::Sheep() { 
    std::cout << "I'm a sheep!" << std::endl; 
}

Sheep::Sheep(std::string name) { 
    std::cout << "I'm a sheep, and my name is " + name + "!" << std::endl; 
} 

Sheep::~Sheep() { 
    std::cout << "No more sheep!" << std::endl; 
}

std::string Sheep::SoundsOfYourPeople() { 
    return "Baa!"; 
}

void Sheep::Sleeps() { 
    std::cout << "zzZZzz. Counting Sheep." << std::endl; 
}

void Sheep::Eats() { 
    std::cout << "Starts to eat grass." << std::endl; 
}

std::string Sheep::GetName() const { 
    return this->name; 
}

void Sheep::SetName(std::string name) { 
    this->name = name; 
}

// ======= Pig =======
Pig::Pig() { 
    std::cout << "I'm a pig!" << std::endl; 
}

Pig::Pig(std::string name) { 
    std::cout << "I'm a pig, and my name is " + name + "!" << std::endl; 
}

Pig::~Pig() { 
    std::cout << "No more pig!" << std::endl; 
}

std::string Pig::SoundsOfYourPeople() { 
    return "Oink!"; 
}

void Pig::Sleeps() { 
    std::cout << "zzZZZzz. Counting pigs." << std::endl; 
}

void Pig::Eats()  { 
    std::cout << "Starts to eat slop." << std::endl; 
}

std::string Pig::GetName() const { 
    return this->name; 
}

void Pig::SetName(std::string name) { 
    this->name = name; 
}

// ============ Creator ============
AnimalCreator::~AnimalCreator() {
    std::cout << "AnimalCreator destroyed" << std::endl;
}

AbstractAnimal * AnimalCreator::CreateAnimal() {
    AbstractAnimal * animal = this->FactoryMethod();
    return animal;
}

AbstractAnimal * AnimalCreator::CreateAnimal(std::string name) {
    AbstractAnimal * animal = this->FactoryMethod(name);
    return animal;
}

// ============ Cow Creators ============
ConcreteCowCreator::~ConcreteCowCreator() {
    std::cout << "ConcreteCowCreator destroyed" << std::endl;
}

AbstractAnimal * ConcreteCowCreator::FactoryMethod() {
    return new Cow();
}

AbstractAnimal * ConcreteCowCreator::FactoryMethod(std::string name) {
    return new Cow(name);
}

// ============ Sheep Creators ============
ConcreteSheepCreator::~ConcreteSheepCreator() {
    std::cout << "ConcreteSheepCreator destroyed" << std::endl;
}

AbstractAnimal * ConcreteSheepCreator::FactoryMethod() {
    return new Sheep();
}

AbstractAnimal * ConcreteSheepCreator::FactoryMethod(std::string name) {
    return new Sheep(name);
}

// ============ Pig Creators ============
ConcretePigCreator::~ConcretePigCreator() {
    std::cout << "ConcretePigCreator destroyed" << std::endl;
}

AbstractAnimal* ConcretePigCreator::FactoryMethod() {
    return new Pig();
}

AbstractAnimal * ConcretePigCreator::FactoryMethod(std::string name) {
    return new Pig(name);
}

// ============ Client Code ============
// AnimalCreator knows to create the concrete animals because creator is of type ConcreteCowCreator's "FactoryMethod"
std::vector<AbstractAnimal *> CreateOneOfEachAnimals_NoNames(AnimalCreator * pAnimalCreator) {
    std::vector<AbstractAnimal *> vAnimals;

    pAnimalCreator = new ConcreteCowCreator();  
    AbstractAnimal * cow = pAnimalCreator->CreateAnimal(); // creates Cow object -- calls the Cow() constructor
    vAnimals.push_back(cow);

    pAnimalCreator = new ConcreteSheepCreator();
    AbstractAnimal * sheep = pAnimalCreator->FactoryMethod(); // creates a sheep -- calls the Sheep() constructor
    vAnimals.push_back(sheep);

    pAnimalCreator = new ConcretePigCreator();
    AbstractAnimal * pig = pAnimalCreator->CreateAnimal(); // creates a pig -- calls the Pig() constructor
    vAnimals.push_back(pig);

    return vAnimals;
}

void PrintAnimalSounds(std::vector<AbstractAnimal *> v) {
    for(int i = 0; i < v.size(); i++)
    {
        std::cout << v[i]->SoundsOfYourPeople() << std::endl;
    }
}

std::vector<AbstractAnimal *> CreateOneOfEachAnimals_Names(AnimalCreator * pAnimalCreator) {
    std::vector<AbstractAnimal *> vAnimals;

    pAnimalCreator = new ConcreteCowCreator(); 
    AbstractAnimal * cow = pAnimalCreator->CreateAnimal("Daisy"); // creates Cow object -- calls the Cow() constructor
    vAnimals.push_back(cow); 

    pAnimalCreator = new ConcreteSheepCreator();
    AbstractAnimal * sheep = pAnimalCreator->FactoryMethod("Grant"); // creates a sheep -- calls the Sheep() constructor
    vAnimals.push_back(sheep);

    pAnimalCreator = new ConcretePigCreator();
    AbstractAnimal * pig = pAnimalCreator->CreateAnimal("Luigi"); // creates a pig -- calls the Pig() constructor
    vAnimals.push_back(pig);

    return vAnimals;
}

// ============ Main ============
int main() {
    AnimalCreator * animalCreator;
    std::vector<AbstractAnimal *> animals_NoNames;
    std::vector<AbstractAnimal *> animals_Names;

    // vector of each farm animals -- with no names
    animals_NoNames = CreateOneOfEachAnimals_NoNames(animalCreator);
    PrintAnimalSounds(animals_NoNames);

    // vector of each farm animals -- with names 
    animals_Names = CreateOneOfEachAnimals_Names(animalCreator);
    PrintAnimalSounds(animals_Names);

    return 0;
}