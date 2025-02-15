#include "chain-of-responsibility.hpp"

// =========== BaseHandler ===========
BaseHandler::BaseHandler(Handler * nextHandler) :
    nextHandler(nextHandler)
{
    std::cout << "BaseHandler created" << std::endl;
}

BaseHandler::~BaseHandler() {
    std::cout << "BaseHandler deleted" << std::endl;
}

Handler * BaseHandler::setNext(Handler * handler) {
    this->nextHandler = handler;
    
    return handler;
}

std::string BaseHandler::Handle(std::string request) {
    if(nextHandler) {
        return nextHandler->Handle(request);
    }
    
    return "";
}

// =========== RobotBodyHandler ===========
RobotBodyHandler::RobotBodyHandler(bool hasRobotChest,
                                   bool hasRobotPelvis) :
    hasRobotChest(hasRobotChest),
    hasRobotPelvis(hasRobotPelvis)                                
{
    std::cout << "RobotBodyHandler created" << std::endl;
}

RobotBodyHandler::~RobotBodyHandler() {
    std::cout << "RobotBodyHandler deleted" << std::endl;
}

std::string RobotBodyHandler::Handle(std::string request) {
    if (request == "Chest" && getHasRobotChest()) {
        setHasRobotChest(false);
        return "Robot's chest assembled!";
    }
    else if (request == "Pelvis" && getHasRobotPelvis()) {
        setHasRobotPelvis(false);
        return "Robot's pelvis assembled!";
    }
    else {
        return BaseHandler::Handle(request); // defaults to base handler
    }
}

// =========== RobotLimbHandler ===========
RobotLimbHandler::RobotLimbHandler(bool hasRobotRightArm,
                                   bool hasRobotLeftArm,
                                   bool hasRobotRightLeg,
                                   bool hasRobotLeftLeg) :
    hasRobotRightArm(hasRobotRightArm),
    hasRobotLeftArm(hasRobotLeftArm),
    hasRobotRightLeg(hasRobotRightLeg),
    hasRobotLeftLeg(hasRobotLeftLeg)
{
    std::cout << "RobotLimbHandler created" << std::endl;
}

RobotLimbHandler::~RobotLimbHandler() {
    std::cout << "RobotLimbHandler destroyed" << std::endl;
}

std::string RobotLimbHandler::Handle(std::string request) {

    if (request == "Right Arm" && getHasRobotRightArm()) {
        setHasRobotRightArm(false);
        return "Robot's right arm assembled!";
    }
    else if (request == "Left Arm" && getHasRobotLeftArm()) {
        setHasRobotLeftArm(false);
        return "Robot's left arm assembled!";
    }
    else if (request == "Right Leg" && getHasRobotRightLeg()) {
        setHasRobotRightLeg(false);
        return "Robot's right leg assembled!";
    }
    else if (request == "Left Leg" && getHasRobotLeftLeg()) {
        setHasRobotLeftLeg(false);
        return "Robot's left leg assembled!";
    }
    else {
        return BaseHandler::Handle(request); // defaults to base handler
    }
}

// =========== RobotCraniumHandler ===========
RobotCraniumHandler::RobotCraniumHandler(bool hasRobotCranium) :
    hasRobotCranium(hasRobotCranium)
{
    std::cout << "RobotCraniumHandler created" << std::endl;
}

RobotCraniumHandler::~RobotCraniumHandler() {
    std::cout << "RobotCraniumHandler deleted" << std::endl;
}

std::string RobotCraniumHandler::Handle(std::string request) {
    if (request == "Cranium" && getHasRobotCranium()) {
        setHasRobotCranium(false);
        return "Robot's cranium assembled!";
    }
    else {
        return BaseHandler::Handle(request);
    }
}

// =========== Client Code ===========
void HandleTheChain(Handler & handler) {
    // requesting all the part for a 'completed' robot assembly
    std::vector<std::string> assemblyInstructions = { "Chest", "Pelvis",
                                                     "Right Arm", "Left Arm", "Right Leg", "Left Leg",
                                                     "Cranium" };

    for (auto& i : assemblyInstructions) {
        auto assemblyResults = handler.Handle(i);
        std::cout << assemblyResults << std::endl;
    }
}

// =========== Main ===========
int main() {
    RobotBodyHandler * bodyHandler = new RobotBodyHandler(true, true);
    RobotLimbHandler * limbHandler = new RobotLimbHandler(true, true, true, true);
    RobotCraniumHandler * craniumHandler = new RobotCraniumHandler(true);

    bodyHandler->setNext(limbHandler)->setNext(craniumHandler);

    HandleTheChain(*bodyHandler);

    delete bodyHandler;
    delete limbHandler;
    delete craniumHandler;

    return 0;
}