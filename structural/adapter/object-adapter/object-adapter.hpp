#include <iostream>
#include <memory>

enum NumberOfPinholes { One = 1, Two, Three };
enum HasRoundPinholes { False = 0, True };
enum JapaneseVoltage { Residential = 100, Commercial = 200 };
enum JapaneseHerts { Eastern = 50, Western = 60 };
const int AMERICAN_HERTS = 60;
const int UK_HERTS = 50;

// =========== Abstract Target ===========
class Outlet
{
public:
    Outlet(bool RoundHoles = NULL, 
           int NumberOfHoles = NULL,
           int VoltageRating = NULL,
           int FrequencyRating = NULL);
    virtual ~Outlet();

    bool GetHasRoundHoles() const;
    int GetNumberOfHoles() const;
    int GetVoltageRating() const;
    int GetFrequencyRating() const;

private:
    bool HasRoundHoles;
    int NumberOfHoles;
    int VoltageRating;
    int FrequencyRating;
};

// =========== Concrete Target ===========
class AmericanOutlet : public Outlet
{
public:
    enum AmericanVoltage { Residential = 120, Commercial = 240 };

    AmericanOutlet(int VoltageRating = AmericanVoltage::Residential, 
                    int FrequencyRating = AMERICAN_HERTS,
                    bool HasRoundHoles = HasRoundPinholes::False,
                    int NumberOfHoles = NumberOfPinholes::Two);
    ~AmericanOutlet();
};

class UKOutlet : public Outlet
{
public:
    enum UKVoltage { Residential = 230, Commercial = 415 };

    UKOutlet(int VoltageRating = UKVoltage::Residential, 
                int FrequencyRating = UK_HERTS,
                bool HasRoundHoles = HasRoundPinholes::False,
                int NumberOfHoles = NumberOfPinholes::Three);
    ~UKOutlet();
};

class JapaneseOutlet : public Outlet
{
public:
    JapaneseOutlet(int VoltageRating = JapaneseVoltage::Residential, 
                    int FrequencyRating = JapaneseHerts::Eastern,
                    bool HasRoundHoles = HasRoundPinholes::True,
                    int NumberOfHoles = NumberOfPinholes::Two);
    ~JapaneseOutlet();
};

// =========== Abstract Adaptee ===========
class Plug
{
public:
    Plug(int PinCount = NULL, 
        bool HasRoundPins = NULL,
        int VoltageRating = NULL,
        int FrequencyRating = NULL);
    virtual ~Plug();

    bool GetHasRoundPins() const;
    int GetPinCount() const;
    int GetVoltageRating() const;
    int GetFrequencyRating() const;

private:
    bool HasRoundPins;
    int PinCount;
    int VoltageRating;
    int FrequencyRating;
};

class AmericanPlug : public Plug
{
public:
    enum AmericanVoltage { Residential = 120, Commercial = 240 };

    AmericanPlug(int VoltageRating = AmericanVoltage::Residential,
                 int FrequencyRating = AMERICAN_HERTS,
                 int PinCount = NumberOfPinholes::Two, 
                 bool HasRoundPins = HasRoundPinholes::False);
    virtual ~AmericanPlug() override;
};

class UKPlug : public Plug
{
public:
    enum UKVoltage { Residential = 230, Commercial = 415 };

    UKPlug(int VoltageRating = UKVoltage::Residential, 
           int FrequencyRating = UK_HERTS,
           int PinCount = NumberOfPinholes::Three, 
           bool HasRoundPins = HasRoundPinholes::False);
    virtual ~UKPlug() override;
};

class JapanesePlug : public Plug
{
public:
    JapanesePlug(int VoltageRating =  JapaneseVoltage::Residential, 
                 int FrequencyRating = JapaneseHerts::Eastern, 
                 int PinCount =  NumberOfPinholes::Two, 
                 bool HasRoundPins = HasRoundPinholes::True);
    virtual ~JapanesePlug() override;
};

// =========== Adapter ===========
class Adapter : public Outlet
{
public:
    Adapter(Plug * pPlug = nullptr, Outlet * pOutlet = nullptr);
    ~Adapter();

    bool CheckNeedsAdapter(Outlet * pOutlet); // determines if an adapter is needed
    bool CheckOutletCompatibility(Outlet * pOutlet); // logic -- plug/outlet needs an adapter

    void SetPlug(Plug * pPlug);
    Plug * GetPlug();

private:
    Plug * pPlug;
};
