// =========== Entity ===========
inline int Entity::GetHealth() const {
    return this->health;
}

inline int Entity::GetMana() const {
    return this->mana;
}

inline int Entity::GetFatigue() const {
    return this->fatigue;
}

// =========== Archer ===========
inline int Archer::GetArrowsEquip() const {
    return this->arrowsEquip;
}

inline void Archer::SetArrowsEquip(int arrowsEquip) {
    this->arrowsEquip = arrowsEquip;
}

// =========== Entity Specialization ===========
inline Entity * EntitySpecialization::GetEntity() const {
    return this->entity;
}

inline void EntitySpecialization::SetEntity(Entity* entity) {
    this->entity = entity;
}

// =========== Holy Knight ===========
inline int HolyKnight::GetFaithMagic() const {
    return this->faithMagic;
}

inline void HolyKnight::SetFaithMagic(int faithMagic) {
    this->faithMagic = faithMagic;
}

// =========== Dark Knight ===========
inline int DarkKnight::GetDarkMagic() const {
    return this->darkMagic;
}

inline void DarkKnight::SetDarkMagic(int darkMagic) {
    this->darkMagic = darkMagic;
}

// =========== Cross Bow Archer ===========
inline int CrossBowArcher::GetFinessePoints() const {
    return this->finessePoints;
}

inline void CrossBowArcher::SetFinessePoints(int finessePoints) {
    this->finessePoints = finessePoints;
}