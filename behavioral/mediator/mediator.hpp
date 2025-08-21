#include <string>
#include <vector>

// ========== Abstract Mediator ==========
class iTeacherMediator
{
public:
    ~iTeacherMediator() = default;

    virtual std::string lectures() = 0;
    virtual std::string preparesClass() = 0;
    virtual std::vector<std::string> assignsStudentsToProject() = 0;
};

// ========== Concrete Mediator ==========
// ---------- Math Teacher ----------
class MathTeacherMediator : public iTeacherMediator
{
public:
    MathTeacherMediator();
    ~MathTeacherMediator();

    std::string lectures() override;
    std::string preparesClass() override;
    std::vector<std::string> assignsStudentsToProject() override;

private:
    std::string sLecture;
    std::string sClass;
    std::vector<std::string> studentsInClass;
};

// ---------- Language Teacher ----------
class LanguageTeacherMediator : public iTeacherMediator
{
public:
    LanguageTeacherMediator();
    ~LanguageTeacherMediator();

    std::string lectures() override;
    std::string preparesClass() override;
    std::vector<std::string> assignsStudentsToProject() override;

private:
    std::string sLanguage;
    std::string sLecture;
    std::string sClass;
    std::vector<std::string> studentsInClass;
};

// ========== Abstract Component ==========
class iStudent
{
public:
    ~iStudent();
    
    virtual void addClass();
    virtual void dropClass();    
};

// ========== Concrete Component ==========
// ---------- Math Student ----------
class MathStudent : public iStudent
{
public:
    MathStudent();
    ~MathStudent();
    
    virtual void addClass();
    virtual void dropClass();    

private:
    iTeacherMediator* mediator;

    std::string firstName;
    std::string lastName;
    std::vector<std::string> vClasses;
    std::vector<std::string> projectMates;
};