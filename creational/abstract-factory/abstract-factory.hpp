#include <iostream>

// ============ ABSTRACT PRODUCT ============
class AbstractPerson
{
public:
    virtual ~AbstractPerson() = default;

    virtual void Attack() = 0;
    virtual void CheckHealth() = 0;
};

// ============ CONCRETE PRODUCTS -- will be created by concrete factories ============
class ConcreteSoldier : public AbstractPerson
{ 
public:
    ConcreteSoldier();
    ~ConcreteSoldier() override;

    void Attack() override;
    void CheckHealth() override;
};

class ConcreteArcher : public AbstractPerson
{
public:
    ConcreteArcher();
    ~ConcreteArcher() override;

    void Attack() override;
    void CheckHealth() override;
};

class ConcreteCalvary : public AbstractPerson
{
public:
    ConcreteCalvary();
    ~ConcreteCalvary() override;

    void Attack() override;
    void CheckHealth() override;
};

// ============ ABSTRACT FACTORY ============
class AbstractRaceFactory
{
public:
    virtual ~AbstractRaceFactory() = default;
    
    virtual AbstractPerson * MakeSoldier() = 0;
    virtual AbstractPerson * MakeArcher() = 0;
    virtual AbstractPerson * MakeCalvary() = 0;
};

// ============ CONCRETE FACTORIES ============
class ConcreteHumanFactory : public AbstractRaceFactory
{
public:
    ConcreteHumanFactory();
    ~ConcreteHumanFactory() override;

    AbstractPerson * MakeSoldier() override;
    AbstractPerson * MakeArcher() override;
    AbstractPerson * MakeCalvary() override;
};

class ConcreteOrcFactory : public AbstractRaceFactory
{
public:
    ConcreteOrcFactory();
    ~ConcreteOrcFactory() override;

    AbstractPerson * MakeSoldier() override;
    AbstractPerson * MakeArcher() override;
    AbstractPerson * MakeCalvary() override;
};

