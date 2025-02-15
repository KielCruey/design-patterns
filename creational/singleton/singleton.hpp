enum state { standardMode, calibrationMode, maintenanceMode, idleMode } state;

class Globals
{
private:
    // creating private constructor, since only static methods can access the constructor only
    Globals(int systemState = static_cast<int>(state::standardMode), int numberOfFiles = 0);

    // ========== member variables ==========
    static Globals * pGlobals; // need a pointer that references the unique instance of that class
    
    int systemState;
    int numberOfFiles;
    
public:
    Globals(const Globals& obj) = delete; // deleting copy constructor -- can't be clone-able
    void operator=(const Globals &) = delete; // deleting assignment operator -- can't use the "=" operator

    static Globals * getInstance(); // functions calls the private constructor -- effectively is the constructor

    // getters/setters
    inline int GetSystemState();
    inline int GetNumberOfFiles();
    inline void SetSystemState(int systemState);
    inline void SetNumberOfFiles(int numberOfFiles);
};

#include "singleton.inl"
