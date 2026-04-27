// ============== RobotPrototype ==============
inline int RobotPrototype::GetSerialNumber() const {
    return this->serialNumber;
}

// ============== ConcreteCivilianRobotPrototype ==============
inline std::string ConcreteCivilianRobotPrototype::GetName() {
    return this->name;
}

inline int ConcreteCivilianRobotPrototype::GetRobotType() {
    return RobotTypes::CIVILIAN;
}

// ============== ConcreteMilitaryRobotPrototype ==============
inline std::string ConcreteMilitaryRobotPrototype::GetRank() {
    return this->rank;
}

inline int ConcreteMilitaryRobotPrototype::GetRobotType() {
    return RobotTypes::MILITARY;
}