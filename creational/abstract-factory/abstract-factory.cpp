#include "abstract-factory.hpp"

// ================ ConcreteSoldier ================
ConcreteSoldier::ConcreteSoldier() {
    std::cout << "Soldier Created" << std::endl; 
}

ConcreteSoldier::~ConcreteSoldier() {
    std::cout << "Soldier Destroyed" << std::endl; 
}

void ConcreteSoldier::Attack() {
    std::cout << "Soldier Attacked" << std::endl;
}

void ConcreteSoldier::CheckHealth() { 
    std::cout << "Soldier Checked Health" << std::endl; 
}

// ================ ConcreteArcher ================
ConcreteArcher::ConcreteArcher() { 
    std::cout << "Archer Created" << std::endl; 
}

ConcreteArcher::~ConcreteArcher() { 
    std::cout << "Archer Destroyed" << std::endl; 
}

void ConcreteArcher::Attack() { 
    std::cout << "Archer Attacked" << std::endl; 
}

void ConcreteArcher::CheckHealth() { 
    std::cout << "Archer Checked Health" << std::endl; 
}

// ================ ConcreteCalvary ================
ConcreteCalvary::ConcreteCalvary() { 
    std::cout << "Calvary Created" << std::endl; 
}

ConcreteCalvary::~ConcreteCalvary() { 
    std::cout << "Calvary Destroyed" << std::endl; 
}

void ConcreteCalvary::Attack() { 
    std::cout << "Calvary Attacked" << std::endl; 
}

void ConcreteCalvary::CheckHealth() { 
    std::cout << "Calvary Checked Health" << std::endl; 
}

// ============ ConcreteHumanFactory ============
ConcreteHumanFactory::ConcreteHumanFactory() { 
    std::cout << "Human Factory Created" << std::endl; 
}

ConcreteHumanFactory::~ConcreteHumanFactory() { 
    std::cout << "Human Factory Destroyed" << std::endl; 
}

AbstractPerson * ConcreteHumanFactory::MakeSoldier() {
    return new ConcreteSoldier();
}

AbstractPerson * ConcreteHumanFactory::MakeArcher() {
    return new ConcreteArcher();
}

AbstractPerson * ConcreteHumanFactory::MakeCalvary() {
    return new ConcreteCalvary();
}

// ============ ConcreteOrcFactory ============
ConcreteOrcFactory::ConcreteOrcFactory() {
    std::cout << "Orc Factory Created" << std::endl; 
}

ConcreteOrcFactory::~ConcreteOrcFactory() { 
    std::cout << "Orc Factory Destroyed" << std::endl; 
}

AbstractPerson * ConcreteOrcFactory::MakeSoldier() {
    return new ConcreteSoldier();
}

AbstractPerson * ConcreteOrcFactory::MakeArcher() {
    return new ConcreteArcher();
}

AbstractPerson * ConcreteOrcFactory::MakeCalvary() {
    return new ConcreteCalvary();
}

// ============ CLIENT CODE ============ 
void CreateHumanArmy(AbstractRaceFactory * factory)
{
    AbstractPerson * humanSoldier = factory->MakeSoldier(); 
    AbstractPerson * humanArcher = factory->MakeArcher();
    AbstractPerson * humanCalvary = factory->MakeCalvary();
}

void CreateOrcArmy(AbstractRaceFactory * factory)
{
    AbstractPerson * orcSoldier = factory->MakeSoldier(); 
    AbstractPerson * orcArcher = factory->MakeArcher();
    AbstractPerson * orcCalvary = factory->MakeCalvary();
}

// ============ MAIN ============
int main()
{
    // factory creating humans
    ConcreteHumanFactory * humanFactory = new ConcreteHumanFactory();
    CreateHumanArmy(humanFactory);
    delete humanFactory;

    // factory creating orcs
    ConcreteOrcFactory * orcFactory = new ConcreteOrcFactory();
    CreateHumanArmy(orcFactory);
    delete orcFactory;
}