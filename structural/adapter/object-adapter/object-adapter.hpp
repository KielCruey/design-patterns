#include <iostream>
#include <memory>

enum NumberOfPinholes { One = 1, Two, Three };
enum HasRoundPinholes { False = 0, True };
enum JapaneseVoltage { Residential = 100, Commercial = 200 };
enum JapaneseHerts { Eastern = 50, Western = 60 };
const int AMERICAN_HERTS = 60;
const int UK_HERTS = 50;

// =========== Abstract Target ===========
class Outlet {
public:
  explicit Outlet(bool RoundHoles = false, int NumberOfHoles = 0,
                  int VoltageRating = 0, int FrequencyRating = 0);
  virtual ~Outlet();

  inline bool GetHasRoundHoles() const;
  inline int GetNumberOfHoles() const;
  inline int GetVoltageRating() const;
  inline int GetFrequencyRating() const;

private:
  bool HasRoundHoles;
  int NumberOfHoles;
  int VoltageRating;
  int FrequencyRating;
};

// =========== Concrete Target ===========
class AmericanOutlet : public Outlet {
public:
  enum AmericanVoltage { Residential = 120, Commercial = 240 };

  explicit AmericanOutlet(int VoltageRating = AmericanVoltage::Residential,
                          int FrequencyRating = AMERICAN_HERTS,
                          bool HasRoundHoles = HasRoundPinholes::False,
                          int NumberOfHoles = NumberOfPinholes::Two);
  ~AmericanOutlet() override;
};

class UKOutlet : public Outlet {
public:
  enum UKVoltage { Residential = 230, Commercial = 415 };

  explicit UKOutlet(int VoltageRating = UKVoltage::Residential,
                    int FrequencyRating = UK_HERTS,
                    bool HasRoundHoles = HasRoundPinholes::False,
                    int NumberOfHoles = NumberOfPinholes::Three);
  ~UKOutlet() override;
};

class JapaneseOutlet : public Outlet {
public:
  explicit JapaneseOutlet(int VoltageRating = JapaneseVoltage::Residential,
                          int FrequencyRating = JapaneseHerts::Eastern,
                          bool HasRoundHoles = HasRoundPinholes::True,
                          int NumberOfHoles = NumberOfPinholes::Two);
  ~JapaneseOutlet() override;
};

// =========== Abstract Adaptee ===========
class Plug {
public:
  explicit Plug(int PinCount = 0, bool HasRoundPins = false,
                int VoltageRating = 0, int FrequencyRating = 0);
  virtual ~Plug();

  inline bool GetHasRoundPins() const;
  inline int GetPinCount() const;
  inline int GetVoltageRating() const;
  inline int GetFrequencyRating() const;

private:
  bool HasRoundPins;
  int PinCount;
  int VoltageRating;
  int FrequencyRating;
};

class AmericanPlug : public Plug {
public:
  enum AmericanVoltage { Residential = 120, Commercial = 240 };

  explicit AmericanPlug(int VoltageRating = AmericanVoltage::Residential,
                        int FrequencyRating = AMERICAN_HERTS,
                        int PinCount = NumberOfPinholes::Two,
                        bool HasRoundPins = HasRoundPinholes::False);
  virtual ~AmericanPlug() override;
};

class UKPlug : public Plug {
public:
  enum UKVoltage { Residential = 230, Commercial = 415 };

  explicit UKPlug(int VoltageRating = UKVoltage::Residential,
                  int FrequencyRating = UK_HERTS,
                  int PinCount = NumberOfPinholes::Three,
                  bool HasRoundPins = HasRoundPinholes::False);
  virtual ~UKPlug() override;
};

class JapanesePlug : public Plug {
public:
  explicit JapanesePlug(int VoltageRating = JapaneseVoltage::Residential,
                        int FrequencyRating = JapaneseHerts::Eastern,
                        int PinCount = NumberOfPinholes::Two,
                        bool HasRoundPins = HasRoundPinholes::True);
  virtual ~JapanesePlug() override;
};

// =========== Adapter ===========
class Adapter : public Outlet {
public:
  explicit Adapter(Plug *pPlug = nullptr, Outlet *pOutlet = nullptr);
  ~Adapter() override;

  bool CheckNeedsAdapter(
      Outlet const *pOutlet); // determines if an adapter is needed
  bool CheckOutletCompatibility(
      Outlet const *pOutlet); // logic -- plug/outlet needs an adapter

  Plug *GetPlug();

private:
  Plug *pPlug;
};

#include "object-adapter.inl"