#include <string>
#include <iostream>

#include "singleton.hpp"

// ========== Globals ==========
Globals::Globals(int systemState, int numberOfFiles) :
    systemState(systemState),
    numberOfFiles(numberOfFiles)
{ }

Globals * Globals::getInstance()
{
    // checking if no instance of class
    if (pGlobals == nullptr) {
        std::cout << "Creating a new Globals object" << std::endl;

        // We can access private members within the class.
        pGlobals = new Globals(); 
        
        return pGlobals; 
    }
    else {
        std::cout << "Globals object exists, returning existing Globals object" << std::endl;

        // if instancePtr != NULL that means the class already has an instance. 
        // So, we are returning that known instance and not creating new one.
        return pGlobals;
    }
}

// ========== Client ==========
static void PrintAllGlobals(Globals * globals) {
    std::cout << "System State: " << globals->GetSystemState() << std::endl;
    std::cout << "Number of Files: " << globals->GetNumberOfFiles() << std::endl;
}

// ========== Main ==========
// initializing member pointer to itself
Globals * Globals::pGlobals = nullptr;

int main() {
    // directly calling the getInstance() method which act as the constructor
    Globals * pMainGlobals = Globals::getInstance();

    // use the singleton as normal
    PrintAllGlobals(pMainGlobals);

    pMainGlobals->SetNumberOfFiles(3);
    pMainGlobals->SetSystemState(state::calibrationMode);

    PrintAllGlobals(pMainGlobals);

    // forgot that Globals class exists, now trying to create other 'Globals' class
    Globals * pOtherGlobals = Globals::getInstance();

    // prints out the existing instance of the 'Globals' class
    PrintAllGlobals(pOtherGlobals);

    return 0;
}