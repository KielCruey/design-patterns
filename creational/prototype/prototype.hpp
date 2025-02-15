// For the prototype design pattern, the use of the copy constructs is a must.
// That's the mechanism that clones the same instance of already initialized object.
// It appears that using the 'rule of three' would be good enough for the prototype design pattern.

// The use of deep copy is important, because creating a new object with own independent member variables.
// This is true if you use pointers for your member variables, deep copy is required.
// https://stackoverflow.com/questions/33142935/prototype-design-pattern-example-c

#include <iostream>
#include <string>
#include <unordered_map>

// helpful enum to determine what the derived class type is
enum RobotTypes {
    MILITARY = 0,
    CIVILIAN
};

// ============== Abstract Product ==============
class RobotPrototype
{
public:
    RobotPrototype(int serialNumber = 0);
    virtual ~RobotPrototype();

    virtual RobotPrototype * Clone() const = 0; // creates heap memory robot
    virtual void PrintInfo(); // prints all member variables

    // getters/setters
    inline virtual int GetRobotType() = 0;

    inline void SetSerialNumber(int serialNumber);
    inline int GetSerialNumber() const;

private:
    int serialNumber;
};

// ============== Concrete Product ==============
class ConcreteCivilianRobotPrototype : public RobotPrototype
{
public:
    ConcreteCivilianRobotPrototype(int serialNumber, std::string name);
    ~ConcreteCivilianRobotPrototype() override;

    RobotPrototype * Clone() const override; // creates heap memory robot
    
    void PrintInfo() override; // prints all member variables

    // getters/setters 
    inline int GetRobotType() override;

    inline void SetName(std::string name);
    inline std::string GetName();

private:
    std::string name; 
};

class ConcreteMilitaryRobotPrototype : public RobotPrototype
{
public:
    ConcreteMilitaryRobotPrototype(int serialNumber, std::string rank);
    ~ConcreteMilitaryRobotPrototype() override;

    RobotPrototype * Clone() const override; // creates heap memory robot
    
    void PrintInfo() override; // prints all member variables

    // getters/setters 
    inline int GetRobotType() override;

    inline void SetRank(std::string rank);
    inline std::string GetRank();

private:
    std::string rank;
};

// ============== Factory ==============
class PrototypeFactory
{
private:
    std::unordered_map<RobotTypes, RobotPrototype *> robotMap;

public:
    PrototypeFactory();
    ~PrototypeFactory();

    RobotPrototype * CreatePrototype(RobotTypes rType);
};

#include "prototype.inl"