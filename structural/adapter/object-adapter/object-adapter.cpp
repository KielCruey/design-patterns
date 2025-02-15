#include "object-adapter.hpp"

// =========== Outlet ===========
Outlet::Outlet(bool HasRoundHoles, 
               int NumberOfHoles, 
               int VoltageRating,
               int FrequencyRating) :
    HasRoundHoles(HasRoundHoles),
    NumberOfHoles(NumberOfHoles),
    VoltageRating(VoltageRating),
    FrequencyRating(FrequencyRating)
{
    std::cout << "Outlet Created" << std::endl;
}

Outlet::~Outlet() {
    std::cout << "Outlet deleted" << std::endl;
}

bool Outlet::GetHasRoundHoles() const {
    return this->HasRoundHoles;
}

int Outlet::GetNumberOfHoles() const {
    return this->NumberOfHoles;
}

int Outlet::GetFrequencyRating() const {
    return this->FrequencyRating;
}

int Outlet::GetVoltageRating() const {
    return this->VoltageRating;
}

// =========== AmericanOutlet ===========
AmericanOutlet::AmericanOutlet(int VoltageRating, 
                                int FrequencyRating, 
                                bool HasRoundHoles, 
                                int NumberOfHoles) :
    Outlet(HasRoundHoles, NumberOfHoles, VoltageRating, FrequencyRating)
{
    std::cout << "AmericanOutlet Created" << std::endl;
}

AmericanOutlet::~AmericanOutlet() {
    std::cout << "AmericanOutlet deleted" << std::endl;
}

// =========== UKOutlet ===========
UKOutlet::UKOutlet(int VoltageRating, 
                    int FrequencyRating,
                    bool HasRoundHoles,
                    int NumberOfHoles) :
    Outlet(HasRoundHoles, NumberOfHoles, VoltageRating, FrequencyRating)
{
    std::cout << "UKOutlet created" << std::endl;
}

UKOutlet::~UKOutlet() {
    std::cout << "UKOutlet deleted" << std::endl;
};

// =========== JapaneseOutlet ===========
JapaneseOutlet::JapaneseOutlet(int VoltageRating, 
                                int FrequencyRating,
                                bool HasRoundHoles,
                                int NumberOfHoles) :
    Outlet(HasRoundHoles, NumberOfHoles, VoltageRating, FrequencyRating)
{
    std::cout << "JapaneseOutlet created" << std::endl;
}

JapaneseOutlet::~JapaneseOutlet() {
    std::cout << "JapaneseOutlet deleted" << std::endl;
}

// =========== Plug ===========
Plug::Plug(int PinCount, 
           bool HasRoundPins,
           int VoltageRating,
           int FrequencyRating) :
    PinCount(PinCount),
    HasRoundPins(HasRoundPins),
    VoltageRating(VoltageRating),
    FrequencyRating(FrequencyRating)
{
    std::cout << "Plug created" << std::endl;
}

Plug::~Plug() {
    std::cout << "Plug deleted" << std::endl;
}

bool Plug::GetHasRoundPins() const {
    return this->HasRoundPins;
}

int Plug::GetPinCount() const {
    return this->PinCount;
}

int Plug::GetVoltageRating() const {
    return this->VoltageRating;
}

int Plug::GetFrequencyRating() const {
    return this->FrequencyRating;
}

// =========== AmericanPlug ===========
AmericanPlug::AmericanPlug(int VoltageRating, 
                           int FrequencyRating, 
                           int PinCount, 
                           bool HasRoundPins) :
    Plug(PinCount, HasRoundPins, VoltageRating, FrequencyRating)
{
    std::cout << "American plug created" << std::endl;
}

AmericanPlug::~AmericanPlug() {
    std::cout << "American plug destroyed" << std::endl;
}

// =========== UKPlug ===========
UKPlug::UKPlug(int VoltageRating, 
               int FrequencyRating, 
               int PinCount, 
               bool HasRoundPins) :
    Plug(PinCount, HasRoundPins, VoltageRating, FrequencyRating)
{
    std::cout << "UK plug created" << std::endl;
}

UKPlug::~UKPlug() {
    std::cout << "UK plug destroyed" << std::endl;
}

// =========== JapanesePlug ===========
JapanesePlug::JapanesePlug(int VoltageRating, 
                           int FrequencyRating, 
                           int PinCount,
                           bool HasRoundPins) :
    Plug(PinCount, HasRoundPins, VoltageRating, FrequencyRating)
{
    std::cout << "Japanese plug created" << std::endl;
}

JapanesePlug::~JapanesePlug() {
    std::cout << "Japanese plug destroyed" << std::endl;
}

// =========== Adapter ===========
Adapter::Adapter(Plug * pPlug, Outlet * pOutlet) :
    pPlug(pPlug),
    Outlet(pOutlet->GetHasRoundHoles(), pOutlet->GetNumberOfHoles())
{
    std::cout << "Adapter created" << std::endl;
}

Adapter::~Adapter() {
    std::cout << "Adapter deleted" << std::endl;
}

bool Adapter::CheckNeedsAdapter(Outlet * pOutlet) {
    if(CheckOutletCompatibility(pOutlet)) {
        std::cout << "No Adapter Needed!" << std::endl;
        return false;
    }
    else {
        std::cout << "Adapter Needed!" << std::endl;
        return true;
    }
}

bool Adapter::CheckOutletCompatibility(Outlet * pOutlet) {
    // logic -- checking plug and outlet needs an adapter
    if(GetPlug()->GetHasRoundPins() == pOutlet->GetHasRoundHoles()
        && GetPlug()->GetPinCount() <= pOutlet->GetNumberOfHoles()
        && GetPlug()->GetFrequencyRating() == pOutlet->GetFrequencyRating()
        && GetPlug()->GetVoltageRating() == pOutlet->GetVoltageRating())
    {
        return true;
    }
    else
        return false;
}

void Adapter::SetPlug(Plug * pPlug) {
    this->pPlug = pPlug;
}

Plug * Adapter::GetPlug() {
    return this->pPlug;
}

// =========== Client code ===========
static void CheckPlugAndOutlet(Plug & pPlug, Outlet & pOutlet) {
    // checks if adapter is needed
    Adapter * pAdapter = new Adapter(&pPlug, &pOutlet);
    bool needsAnAdapter = pAdapter->CheckNeedsAdapter(&pOutlet);
    std::cout << needsAnAdapter << std::endl;
}

// =========== Main code ===========
int main() {
    AmericanPlug * pAmericanPlug = new AmericanPlug();
    UKPlug * pUKPlug = new UKPlug();
    JapanesePlug * pJapanesePlug = new JapanesePlug();
    
    AmericanOutlet * pAmericanOutlet = new AmericanOutlet();
    UKOutlet * pUKOutlet = new UKOutlet();
    JapaneseOutlet * pJapaneseOutlet = new JapaneseOutlet();

    CheckPlugAndOutlet(*pAmericanPlug, *pAmericanOutlet);
    CheckPlugAndOutlet(*pAmericanPlug, *pUKOutlet);
    CheckPlugAndOutlet(*pAmericanPlug, *pJapaneseOutlet);

    CheckPlugAndOutlet(*pUKPlug, *pAmericanOutlet);
    CheckPlugAndOutlet(*pUKPlug, *pUKOutlet);
    CheckPlugAndOutlet(*pUKPlug, *pJapaneseOutlet);

    CheckPlugAndOutlet(*pJapanesePlug, *pAmericanOutlet);
    CheckPlugAndOutlet(*pJapanesePlug, *pUKOutlet);
    CheckPlugAndOutlet(*pJapanesePlug, *pJapaneseOutlet);

    return 0;
}