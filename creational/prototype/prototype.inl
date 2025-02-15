// ============== RobotPrototype ==============
inline void RobotPrototype::SetSerialNumber(int serialNumber) {
    this->serialNumber = serialNumber;
}

inline int RobotPrototype::GetSerialNumber() const {
    return this->serialNumber;
}

// ============== ConcreteCivilianRobotPrototype ==============
inline void ConcreteCivilianRobotPrototype::SetName(std::string name) {
    this->name = name;
}

inline std::string ConcreteCivilianRobotPrototype::GetName() {
    return this->name;
}

inline int ConcreteCivilianRobotPrototype::GetRobotType() {
    return RobotTypes::CIVILIAN;
}

// ============== ConcreteMilitaryRobotPrototype ==============
inline void ConcreteMilitaryRobotPrototype::SetRank(std::string rank) {
    this->rank = rank;
}

inline std::string ConcreteMilitaryRobotPrototype::GetRank() {
    return this->rank;
}

inline int ConcreteMilitaryRobotPrototype::GetRobotType() {
    return RobotTypes::MILITARY;
}