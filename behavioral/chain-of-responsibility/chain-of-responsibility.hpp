#include <iostream>
#include <string>
#include <vector>

// ========= Handler =========
class Handler 
{
public: 
    virtual Handler * setNext(Handler * handler) = 0; // function chains the next handling check
    virtual std::string Handle(std::string request) = 0;
};

// ========= Base Handler =========
class BaseHandler : public Handler
{
public: 
    BaseHandler(Handler * nextHandler = nullptr);
    virtual ~BaseHandler();

    virtual Handler * setNext(Handler * handler) override;
    virtual std::string Handle(std::string request) override;

    inline void setHandler(Handler* nextHandler);
    inline Handler* getHandler() const;

private:
    Handler * nextHandler;
};

// ========= Concrete Handler(s) =========
class RobotBodyHandler : public BaseHandler 
{
public: 
    RobotBodyHandler(bool hasRobotChest = NULL, 
                     bool hasRobotPelvis = NULL);
    virtual ~RobotBodyHandler() override;

    virtual std::string Handle(std::string request) override;

    inline void setHasRobotChest(bool hasRobotChest);
    inline void setHasRobotPelvis(bool hasRobotPelvis);
    inline bool getHasRobotChest() const;
    inline bool getHasRobotPelvis() const;

private:
    bool hasRobotChest;
    bool hasRobotPelvis;
};

class RobotLimbHandler : public BaseHandler 
{
public: 
    RobotLimbHandler(bool hasRobotRightArm = NULL,
                     bool hasRobotLeftArm = NULL,
                     bool hasRobotRightLeg = NULL,
                     bool hasRobotLeftLeg = NULL);
    virtual ~RobotLimbHandler() override;

    virtual std::string Handle(std::string request) override;

    inline void setHasRobotRightArm(bool hasRobotRightArm);
    inline void setHasRobotLeftArm(bool hasRobotLeftArm);
    inline void setHasRobotRightLeg(bool hasRobotRightLeg);
    inline void setHasRobotLeftLeg(bool hasRobotLeftLeg);
    inline bool getHasRobotRightArm() const;
    inline bool getHasRobotLeftArm() const;
    inline bool getHasRobotRightLeg() const;
    inline bool getHasRobotLeftLeg() const;

private:
    bool hasRobotRightArm;
    bool hasRobotLeftArm;
    bool hasRobotRightLeg;
    bool hasRobotLeftLeg;
};

class RobotCraniumHandler : public BaseHandler 
{
public: 
    RobotCraniumHandler(bool hasRobotCranium = NULL);
    virtual ~RobotCraniumHandler() override;

    virtual std::string Handle(std::string request) override;

    inline void setHasRobotCranium(bool hasRobotCranium);
    inline bool getHasRobotCranium() const;

private:
    bool hasRobotCranium;
};

#include "chain-of-responsibility.inl"