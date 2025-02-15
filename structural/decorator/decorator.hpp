
// =========== Abstract Component ===========
class Entity
{
public:
    Entity(int health = 100, 
           int mana = 100, 
           int fatigue = 100);
    virtual ~Entity();

    // concrete decorator's virtual responsibilities
    virtual void EquipArmor() = 0;
    virtual void EquipGreaves() = 0;
    virtual void EquipHelmet() = 0;
    virtual void EquipMainHand() = 0;
    virtual void EquipSecondaryHand() = 0;
    virtual void EquipSabaton() = 0; // feet

    // concrete component's virtual responsibilities
    virtual int Attack() = 0;
    virtual int Block() = 0;
    virtual void Reload() = 0;
    
    // getters/setters
    inline int GetHealth() const;
    inline int GetMana() const;
    inline int GetFatigue() const;
    void SetHealth(int health);
    void SetMana(int mana);
    void SetFatigue(int fatigue);

private:
    int health;
    int mana;
    int fatigue;
};

// =========== Concrete Component ===========
class Knight : public Entity
{
public:
    Knight(int health = 100, 
           int mana = 100,
           int fatigue = 100);
    ~Knight();

    // virtuals
    void EquipArmor() override;
    void EquipGreaves() override;
    void EquipHelmet() override;
    void EquipMainHand() override;
    void EquipSecondaryHand() override;
    void EquipSabaton() override;

    int Attack() override;
    int Block() override;
    void Reload() override;
};

class Archer : public Entity
{
public:
    Archer(int arrowsEquip = 100, 
           int health = 100, 
           int mana = 100, 
           int fatigue = 100);
    ~Archer();

    // virtuals
    void EquipArmor() override;
    void EquipGreaves() override;
    void EquipHelmet() override;
    void EquipMainHand() override;
    void EquipSecondaryHand() override;
    void EquipSabaton() override;

    int Attack() override;
    int Block() override;
    void Reload() override;

    // getters/setters
    inline int GetArrowsEquip() const;
    inline void SetArrowsEquip(int ArrowsEquip);

private:
    int arrowsEquip;
};

// =========== Abstract Decorator ===========
class EntitySpecialization : public Entity
{
public:
    EntitySpecialization(Entity * entity);
    ~EntitySpecialization();

    // virtuals
    virtual void ClassAttack() = 0;

    // getters/setters
    inline Entity * GetEntity() const;
    inline void SetEntity(Entity* entity);

protected:
    Entity * entity;
};

// =========== Concrete Decorator ===========
class HolyKnight : public EntitySpecialization
{
public:
    HolyKnight(Entity * entity = nullptr, 
               int faithMagic = 100);
    ~HolyKnight();

    // from 'entity specialization' class
    void ClassAttack() override;

    // from entity class
    void EquipArmor() override;
    void EquipGreaves() override;
    void EquipHelmet() override;
    void EquipMainHand() override;
    void EquipSecondaryHand() override;
    void EquipSabaton() override; // feet

    // concrete component's virtual responsibilities
    int Attack() override;
    int Block() override;
    void Reload() override;

    // getters/setters
    inline int GetFaithMagic() const;
    inline void SetFaithMagic(int faithMagic);

private:
    int faithMagic;
};

class DarkKnight : public EntitySpecialization
{
public:
    DarkKnight(Entity* entity = nullptr, 
               int darkMagic = 100);
    ~DarkKnight();

    // from 'entity specialization' class
    void ClassAttack() override;

    // from entity class
    void EquipArmor() override;
    void EquipGreaves() override;
    void EquipHelmet() override;
    void EquipMainHand() override;
    void EquipSecondaryHand() override;
    void EquipSabaton() override; // feet

    // concrete component's virtual responsibilities
    int Attack() override;
    int Block() override;
    void Reload() override;

    // getters/setters
    int GetDarkMagic() const;
    void SetDarkMagic(int darkMagic);

private:
    int darkMagic;
};

class CrossBowArcher : public EntitySpecialization
{
public:
    CrossBowArcher(Entity * entity = nullptr, 
                   int finessePoints = 100);
    ~CrossBowArcher();

    // from 'entity specialization' class
    void ClassAttack() override;

    // from entity class
    void EquipArmor() override;
    void EquipGreaves() override;
    void EquipHelmet() override;
    void EquipMainHand() override;
    void EquipSecondaryHand() override;
    void EquipSabaton() override; // feet

    // concrete component's virtual responsibilities
    int Attack() override;
    int Block() override;
    void Reload() override;

    // getters/setters
    int GetFinessePoints() const;
    void SetFinessePoints(int finessePoints);

private:
    int finessePoints;
};

#include "decorator.inl"