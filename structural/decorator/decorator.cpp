#include <iostream>

#include "decorator.hpp"

const int ATTACK_FATIGUE = 10;
const int BLOCK_FATIGUE = 10;
const int FAITH_MAGIC_USED = 5;
const int DARK_MAGIC_USED = 5;
const int FINESSE_POINTS_USED = 5;

// =========== Entity ===========
Entity::Entity(int health, int mana, int fatigue) :
    health(health),
    mana(mana),
    fatigue(fatigue)
{
    std::cout << "Entity created" << std::endl;
}

Entity::~Entity() {
    std::cout << "Entity destroyed" << std::endl;
}

void Entity::SetHealth(int health) {
    if(0 > health) {
        this->health = 0;
        std::cout << "Entity dead -- Health at zero" << std::endl;
    }
    else this->health = health;
}

void Entity::SetMana(int mana) {
    if(0 > mana) {
        this->mana = 0;
        std::cout << "Entity drained -- Mana at zero" << std::endl;
    }
    else this->mana = mana;
}

void Entity::SetFatigue(int fatigue) {
    if(0 > fatigue) {
        this->fatigue = 0;
        std::cout << "Entity tired -- Fatigue at zero" << std::endl;
    } 
    else this->fatigue = fatigue;
}

// =========== Knight ===========
Knight::Knight(int health, int mana, int fatigue) :
    Entity(health, mana, fatigue)
{
    std::cout << "Knight created" << std::endl;
}

Knight::~Knight() {
    std::cout << "Knight destroyed" << std::endl;
}

void Knight::EquipArmor() {
    std::cout << "Armor equipped" << std::endl;
}

void Knight::EquipGreaves() {
    std::cout << "Greaves equipped" << std::endl;
}

void Knight::EquipHelmet() {
    std::cout << "Helmet equipped" << std::endl;
}

void Knight::EquipMainHand() {
    std::cout << "Sword equipped" << std::endl;
}

void Knight::EquipSecondaryHand() {
    std::cout << "Shield equipped" << std::endl;
}

void Knight::EquipSabaton() {
    std::cout << "Sabatons equipped" << std::endl;
}

int Knight::Attack() {
    SetFatigue(GetFatigue() - ATTACK_FATIGUE);

    if (0 > GetFatigue()) {
        std::cout << "Too Fatigued, Knight didn't attack" << std::endl;
    }
    else {
        std::cout << "Sword swung" << std::endl;
    }

    return GetFatigue();
}

int Knight::Block() {  
    SetFatigue(GetFatigue() - BLOCK_FATIGUE);

    if (0 > GetFatigue()) {
        std::cout << "Too Fatigued, Knight didn't block" << std::endl;
    }
    else {
        std::cout << "Blocked with shield" << std::endl;
    }

    return GetFatigue();
}

void Knight::Reload() {
    std::cout << "Knight don't reload!" << std::endl;
}

// =========== Archer ===========
Archer::Archer(int arrowsEquip, int health, int mana, int fatigue) :
    arrowsEquip(arrowsEquip),
    Entity(health, mana, fatigue)
{
    std::cout << "Archer created" << std::endl;
}

Archer::~Archer() {
    std::cout << "Archer destroyed" << std::endl;
}

void Archer::EquipArmor() {
    std::cout << "Armor equipped" << std::endl;
}

void Archer::EquipGreaves() {
    std::cout << "Greaves equipped" << std::endl;
}

void Archer::EquipHelmet() {
    std::cout << "Helmet equipped" << std::endl;
}

void Archer::EquipMainHand() {
    std::cout << "Bow equipped" << std::endl;
}

void Archer::EquipSecondaryHand() {
    std::cout << "Arrows equipped" << std::endl;
}

void Archer::EquipSabaton() {
    std::cout << "Sabatons equipped" << std::endl;
}

int Archer::Attack() {
    SetFatigue(GetFatigue() - ATTACK_FATIGUE);

    if (0 > GetFatigue()) {
        std::cout << "Too Fatigued, Archer didn't attack" << std::endl;
    }
    else {
        std::cout << "Shot bow" << std::endl;
    }

    return GetFatigue();
}

int Archer::Block() {
    std::cout << "Archer don't block" << std::endl;
    return GetFatigue();
}

void Archer::Reload() {
    SetArrowsEquip(GetArrowsEquip() - 1);

    if(0 > GetArrowsEquip()) {
        SetArrowsEquip(0);
        std::cout << "Insufficient arrows" << std::endl;
    }
    else {
        std::cout << "Reloaded bow and arrow" << std::endl;
    }
}

// =========== Entity Specialization ===========
EntitySpecialization::EntitySpecialization(Entity * entity) :
    Entity(),
    entity(entity)
{
    std::cout << "EntitySpecialization created" << std::endl;
}

EntitySpecialization::~EntitySpecialization() {
    std::cout << "EntitySpecialization destroyed" << std::endl;
}

// =========== Holy Knight ===========
HolyKnight::HolyKnight(Entity * entity, int faithMagic) :
    EntitySpecialization(entity),
    faithMagic(faithMagic)
{
    std::cout << "Holy Knight created" << std::endl;
}

HolyKnight::~HolyKnight() {
    std::cout << "Holy Knight destroyed" << std::endl;
}

void HolyKnight::ClassAttack() {
    std::cout << "Holy Knight's Ultimate Attack!" << std::endl;
}

void HolyKnight::EquipArmor() {
    std::cout << "Holy Armor equipped" << std::endl;
}

void HolyKnight::EquipGreaves() {
    std::cout << "Holy Greaves equipped" << std::endl;
}

void HolyKnight::EquipHelmet() {
    std::cout << "Holy Helmet equipped" << std::endl;
}

void HolyKnight::EquipMainHand() {
    std::cout << "Holy Sword equipped" << std::endl;
}

void HolyKnight::EquipSecondaryHand() {
    std::cout << "Holy Shield equipped" << std::endl;
}

void HolyKnight::EquipSabaton() {
    std::cout << "Holy Sabatons equipped" << std::endl;
}

int HolyKnight::Attack() {
    if (0 > GetFaithMagic()) {
        std::cout << "Insufficient faith magic" << std::endl;
    }
    else {
        std::cout << "Holy attack -- uses smite" << std::endl;
        SetFaithMagic(GetFaithMagic() - FAITH_MAGIC_USED);
    }

    return GetFaithMagic();
}

int HolyKnight::Block() {
    if (0 > GetFaithMagic()) {
        std::cout << "Insufficient faith magic" << std::endl;
    }
    else {
        std::cout << "Holy block -- bubble shield" << std::endl;
        SetFaithMagic(GetFaithMagic() - FAITH_MAGIC_USED);
    }

    return GetFaithMagic();
}

void HolyKnight::Reload() {
    std::cout << "Holy Knight doesn't reload" << std::endl;
}

// =========== Dark Knight ===========
DarkKnight::DarkKnight(Entity * entity, int darkMagic) :
    EntitySpecialization(entity),
    darkMagic(darkMagic)
{
    std::cout << "Dark Knight created" << std::endl;
}

DarkKnight::~DarkKnight() {
    std::cout << "Dark Knight destroyed" << std::endl;
}

void DarkKnight::ClassAttack() {
    std::cout << "Dark Knight's Ultimate Attack!" << std::endl;
}

void DarkKnight::EquipArmor() {
    std::cout << "Dark Armor equipped" << std::endl;
}

void DarkKnight::EquipGreaves() {
    std::cout << "Dark Greaves equipped" << std::endl;
}

void DarkKnight::EquipHelmet() {
    std::cout << "Dark Helmet equipped" << std::endl;
}

void DarkKnight::EquipMainHand() {
    std::cout << "Dark Sword equipped" << std::endl;
}

void DarkKnight::EquipSecondaryHand() {
    std::cout << "Dark Shield equipped" << std::endl;
}

void DarkKnight::EquipSabaton() {
    std::cout << "Dark Sabaton equipped" << std::endl;
}

int DarkKnight::Attack() {
    if (0 > GetDarkMagic()) {
        std::cout << "Insufficient dark magic" << std::endl;
    }
    else {
        std::cout << "Dark attack -- uses blight" << std::endl;
        SetDarkMagic(GetDarkMagic() - DARK_MAGIC_USED);
    }

    return GetDarkMagic();
}

int DarkKnight::Block() {
    if (0 > GetDarkMagic()) {
        std::cout << "Insufficient dark magic" << std::endl;
    }
    else {
        std::cout << "Dark block -- terror shield" << std::endl;
        SetDarkMagic(GetDarkMagic() - DARK_MAGIC_USED);
    }

    return GetDarkMagic();
}

void DarkKnight::Reload() {
    std::cout << "Dark Knight doesn't reload" << std::endl;
}

// =========== Cross Bow Archer ===========
CrossBowArcher::CrossBowArcher(Entity * entity, int finessePoints) :
    EntitySpecialization(entity),
    finessePoints(finessePoints)
{
    std::cout << "Cross Bow Archer created" << std::endl;
}

CrossBowArcher::~CrossBowArcher() {
    std::cout << "Cross Bow Archer destroyed" << std::endl;
}

void CrossBowArcher::ClassAttack() {
    std::cout << "Cross Bow Archers's Ultimate Attack!" << std::endl;
}

void CrossBowArcher::EquipArmor() {
    std::cout << "Cross Bow Armor equipped" << std::endl;
}

void CrossBowArcher::EquipGreaves() {
    std::cout << "Cross Bow Greaves equipped" << std::endl;
}

void CrossBowArcher::EquipHelmet() {
    std::cout << "Cross Bow Helmet equipped" << std::endl;
}

void CrossBowArcher::EquipMainHand() {
    std::cout << "Cross Bow equipped" << std::endl;
}

void CrossBowArcher::EquipSecondaryHand() {
    std::cout << "Cross Bow Arrows equipped" << std::endl;
}

void CrossBowArcher::EquipSabaton() {
    std::cout << "Cross Bow Sabaton equipped" << std::endl;
}

int CrossBowArcher::Attack() {
    if (0 > GetFinessePoints()) {
        std::cout << "Insufficient finesse points" << std::endl;
    }
    else {
        std::cout << "Cross Bow Attack -- uses sniper arrow" << std::endl;
        SetFinessePoints(GetFinessePoints() - FINESSE_POINTS_USED);
    }

    return GetFinessePoints();
}

int CrossBowArcher::Block() {
    std::cout << "Cross Bow Archer can't block" << std::endl;
    return GetFinessePoints();
}

void CrossBowArcher::Reload() {
    Archer * archer = dynamic_cast<Archer *>(GetEntity());

    if (archer != nullptr) {
        if (0 > archer->GetArrowsEquip()) {
            std::cout << "No more arrows, can't reload" << std::endl;
        }
        else {
            std::cout << "Reloaded a cross bow bolt" << std::endl;
            archer->SetArrowsEquip(archer->GetArrowsEquip() - 1);
        }
    }
    else
    {
        // maybe throw an exception?
    }
}

// =========== Client Code ===========
// testing "vanilla" class
void TestEntity(Entity * entity) {
    entity->EquipArmor();
    entity->EquipGreaves();
    entity->EquipHelmet();
    entity->EquipMainHand();
    entity->EquipSecondaryHand();
    entity->EquipSabaton();

    entity->Attack();
    entity->Block();
    entity->Reload();
}

void TestClassSpecialization(EntitySpecialization* specialization) {
    specialization->ClassAttack();
}

// =========== Main ===========
int main()
{
    Knight * knight = new Knight();
    TestEntity(knight);

    Archer * archer = new Archer();
    TestEntity(archer);

    // decorating knight to a holy knight
    HolyKnight * holyKnight = new HolyKnight(knight);
    TestEntity(holyKnight);
    TestClassSpecialization(holyKnight); // wrapping the HolyKnight around the Knight class

    // decorating knight to a dark knight
    DarkKnight * darkKnight = new DarkKnight(knight);
    TestEntity(darkKnight);
    TestClassSpecialization(darkKnight); // wrapping the DarkKnight around the Knight class

    // decorating archer to a cross bow archer
    CrossBowArcher * crossBowArcher = new CrossBowArcher(archer);
    TestEntity(crossBowArcher);
    TestClassSpecialization(crossBowArcher); // wrapping the CrossBowArcher around the Archer class

    delete holyKnight;
    delete darkKnight;
    delete crossBowArcher;

    delete knight;
    delete archer;

    return 0;
}