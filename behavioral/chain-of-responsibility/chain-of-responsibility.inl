// ========= Base Handler =========
inline void BaseHandler::setHandler(Handler* nextHandler) {
    this->nextHandler = nextHandler;
}

inline Handler* BaseHandler::getHandler() const {
    return this->nextHandler;
}

// =========== RobotBodyHandler ===========
inline void RobotBodyHandler::setHasRobotChest(bool hasRobotChest) {
    this->hasRobotChest = hasRobotChest;
}

inline void RobotBodyHandler::setHasRobotPelvis(bool hasRobotPelvis) {
    this->hasRobotPelvis = hasRobotPelvis;
}

inline bool RobotBodyHandler::getHasRobotChest() const {
    return this->hasRobotChest;
}

inline bool RobotBodyHandler::getHasRobotPelvis() const {
    return this->hasRobotPelvis;
}

// =========== RobotBodyHandler ===========
inline void RobotLimbHandler::setHasRobotRightArm(bool hasRobotRightArm) {
    this->hasRobotRightArm = hasRobotRightArm;
}

inline void RobotLimbHandler::setHasRobotLeftArm(bool hasRobotLeftArm) {
    this->hasRobotLeftArm = hasRobotLeftArm;
}

inline void RobotLimbHandler::setHasRobotRightLeg(bool hasRobotRightLeg) {
    this->hasRobotRightLeg = hasRobotRightLeg;
}

inline void RobotLimbHandler::setHasRobotLeftLeg(bool hasRobotLeftLeg) {
    this->hasRobotLeftLeg = hasRobotLeftLeg;
}

inline bool RobotLimbHandler::getHasRobotRightArm() const {
    return this->hasRobotRightArm;
}

inline bool RobotLimbHandler::getHasRobotLeftArm() const {
    return this->hasRobotLeftArm;
}

inline bool RobotLimbHandler::getHasRobotRightLeg() const {
    return this->hasRobotRightLeg;
}

inline bool RobotLimbHandler::getHasRobotLeftLeg() const {
    return this->hasRobotLeftLeg;
}

// =========== RobotCraniumHandler ===========
inline void RobotCraniumHandler::setHasRobotCranium(bool hasRobotCranium) {
    this->hasRobotCranium = hasRobotCranium;
}

inline bool RobotCraniumHandler::getHasRobotCranium() const {
    return this->hasRobotCranium;
}