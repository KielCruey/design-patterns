#include "prototype.hpp"

// ============== RobotPrototype ==============
RobotPrototype::RobotPrototype(int serialNumber) :
    serialNumber(serialNumber)
{ 
    std::cout << "Robot Prototype created" << std::endl;
}

RobotPrototype::~RobotPrototype() {
    std::cout << "Robot Prototype destroyed" << std::endl;
}

void RobotPrototype::PrintInfo() {
    std::cout << "Robot's serial number: " + GetSerialNumber() << std::endl;
}

// ============== ConcreteCivilianRobotPrototype ==============
ConcreteCivilianRobotPrototype::ConcreteCivilianRobotPrototype(int serialNumber, std::string name) :
    RobotPrototype(serialNumber), 
    name(name)
{
    std::cout << "Concrete Civilian Robot created" << std::endl;
}

ConcreteCivilianRobotPrototype::~ConcreteCivilianRobotPrototype() {
    std::cout << "Concrete Civilian Robot destroyed" << std::endl;
}

void ConcreteCivilianRobotPrototype::PrintInfo() {
    std::cout << "Concrete Civilian Robot is named " + GetName() + " with the serial number " << GetSerialNumber() << "." << std::endl;
}

RobotPrototype * ConcreteCivilianRobotPrototype::Clone() const {
    return new ConcreteCivilianRobotPrototype(*this); // calling default copy constructor -- shallow copy only
}

// ============== ConcreteMilitaryRobotPrototype ==============
ConcreteMilitaryRobotPrototype::ConcreteMilitaryRobotPrototype(int serialNumber, std::string rank) :
    RobotPrototype(serialNumber),
    rank(rank)
{
    std::cout << "Concrete Military Robot created" << std::endl;
}

ConcreteMilitaryRobotPrototype::~ConcreteMilitaryRobotPrototype() {
    std::cout << "Concrete Military Robot destroyed" << std::endl;
}

void ConcreteMilitaryRobotPrototype::PrintInfo() {
    std::cout << "Concrete Military Robot rank is " + GetRank() + " with the serial number " << GetSerialNumber() << "." << std::endl;
}

RobotPrototype * ConcreteMilitaryRobotPrototype::Clone() const {
    return new ConcreteMilitaryRobotPrototype(*this); // calling default copy constructor -- shallow copy only
}

// ============== Factory ==============
PrototypeFactory::PrototypeFactory() {
    robotMap[RobotTypes::CIVILIAN] = new ConcreteCivilianRobotPrototype(0, "No Name");
    robotMap[RobotTypes::MILITARY] = new ConcreteMilitaryRobotPrototype(0, "No Rank");
}

PrototypeFactory::~PrototypeFactory() {
    delete robotMap[RobotTypes::CIVILIAN];
    delete robotMap[RobotTypes::MILITARY];
}

RobotPrototype * PrototypeFactory::CreatePrototype(RobotTypes rType) {
    std::cout << "Prototype created of type " << rType  << std::endl;

    return robotMap[rType]->Clone();
}

// ============== Client Code ==============
static RobotPrototype * CloneAndPrintMilitaryRobot(ConcreteMilitaryRobotPrototype * mRobot) {
    // cloning miliary robot
    RobotPrototype * protoMilitary = mRobot->Clone();
    // printing out member variables
    protoMilitary->PrintInfo();

    return protoMilitary;
}

static RobotPrototype * CloneAndPrintCivilianRobot(ConcreteCivilianRobotPrototype * cRobot) {
    // cloning civilian robot
    RobotPrototype * protoCivilian = cRobot->Clone();
    // printing out member variables
    cRobot->PrintInfo();

    return cRobot;
}

static void SimpleMiliaryClone() {
    ConcreteMilitaryRobotPrototype * mRobot = new ConcreteMilitaryRobotPrototype(123, "Private");
    mRobot->PrintInfo();

    // cloning
    RobotPrototype * milRobot = CloneAndPrintMilitaryRobot(mRobot);
}

static void SimpleCivilianClone() {
    ConcreteCivilianRobotPrototype * cRobot = new ConcreteCivilianRobotPrototype(321, "Dawn");
    cRobot->PrintInfo();

    // cloning
    RobotPrototype * civRobot = CloneAndPrintCivilianRobot(cRobot);
}

static void CheckRobotType(RobotPrototype * r) {
    if(r->GetRobotType() == RobotTypes::CIVILIAN) {
        std::cout << r->GetSerialNumber() << " is a civilian robot" << std::endl;
    }
    else if(r->GetRobotType() == RobotTypes::MILITARY) {
        std::cout << r->GetSerialNumber() << " is a military robot" << std::endl;
    }
    else {
        std::cout << "This isn't a robot, sorry!" << std::endl;
    }
}

static void FactoryMilitaryClone(PrototypeFactory * pFactory) {
    RobotPrototype * pMilRobot = pFactory->CreatePrototype(RobotTypes::MILITARY);

    pMilRobot->PrintInfo();
}

static void FactoryCivilianClone(PrototypeFactory * pFactory) {
    RobotPrototype * pCivRobot = pFactory->CreatePrototype(RobotTypes::CIVILIAN);

    pCivRobot->PrintInfo();
}

// ============== main ==============
int main() {
    // creating a prototype, using just prototype design pattern
    ConcreteCivilianRobotPrototype * rJim = new ConcreteCivilianRobotPrototype(9, "Jim");
    ConcreteMilitaryRobotPrototype * rBob = new ConcreteMilitaryRobotPrototype(888, "General");

    CheckRobotType(rJim);
    CheckRobotType(rBob);

    // cloning military robot without a factory
    SimpleMiliaryClone();

    // cloning civilian robot without a factory
    SimpleCivilianClone();

    // ===================================================
    // using the factory/prototype design pattern together
    PrototypeFactory * pFactory = new PrototypeFactory();
    FactoryMilitaryClone(pFactory);
    FactoryCivilianClone(pFactory);

    return 0;
}