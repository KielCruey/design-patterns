// Templates as defined in the C++ language are a feature of the C++ programming
// language is not related to the Template Method pattern.C++ define templates
// for data types whereas the Template Method pattern define a template for an
// algorithm.

#include <iostream>
#include <string>

const int MIN_AMOUNT = 0;

const int MAX_EXTRAS_AMOUNT = 15;
const int MAX_BEVERAGE_AMOUNT = 30;

const int MAX_CUPS = 60;
const int MAX_WATER_AMOUNT = 600; // about 75 cups at 8 fl oz

const int BEVERAGE_WATER = 8;

// ============ Support Classes ============
class Extras {
public:
  explicit Extras(int sugarShot = MAX_EXTRAS_AMOUNT,
                  int creamShot = MAX_EXTRAS_AMOUNT,
                  int milkShot = MAX_EXTRAS_AMOUNT,
                  int chocolateShot = MAX_EXTRAS_AMOUNT);
  ~Extras() = default;

  // getters/setters
  inline void setSugarShot(int sugarShot);
  inline void setCreamShot(int creamShot);
  inline void setMilkShot(int milkShot);
  inline void setChocolateShot(int chocolateShot);

private:
  int sugarShot;
  int creamShot;
  int milkShot;
  int chocolateShot;
};

class Teas {
public:
  explicit Teas(int greenTea = MAX_BEVERAGE_AMOUNT,
                int blackTea = MAX_BEVERAGE_AMOUNT,
                int chiaTea = MAX_BEVERAGE_AMOUNT);
  ~Teas() = default;

  // getters/setters
  inline int getGreenTea() const;
  inline int getBlackTea() const;
  inline int getChiaTea() const;

  inline void setGreenTea(int greenTea);
  inline void setBlackTea(int blackTea);
  inline void setChiaTea(int chiaTea);

private:
  int greenTea;
  int blackTea;
  int chiaTea;
};

class Coffees {
public:
  explicit Coffees(int lightRoast = MAX_BEVERAGE_AMOUNT,
                   int mediumRoast = MAX_BEVERAGE_AMOUNT,
                   int darkRoast = MAX_BEVERAGE_AMOUNT);
  ~Coffees() = default;

  // getters/setters
  inline int getLightRoast() const;
  inline int getMediumRoast() const;
  inline int getDarkRoast() const;

  inline void setLightRoast(int lightRoast);
  inline void setMediumRoast(int mediumRoast);
  inline void setDarkRoast(int darkRoast);

private:
  int lightRoast;
  int mediumRoast;
  int darkRoast;
};

// ========== Abstract Template ==========
// The BeverageMaker class will take control over scope of the Extra, Teas, and
// Coffees classes via dynamic memory.
class BeverageMaker {
public:
  BeverageMaker(const Extras *extras = nullptr, const Teas *teas = nullptr,
                const Coffees *coffees = nullptr, int cups = MAX_CUPS,
                double waterAmount = MAX_WATER_AMOUNT);
  ~BeverageMaker();

  BeverageMaker(const BeverageMaker &beverageMaker); // copy constructor
  BeverageMaker &
  operator=(const BeverageMaker &beverageMaker); // copy assignment

  // class actions
  virtual void makeBeverage(std::string beverageSelected) = 0;
  void restockExtras();
  void restockTeas();
  void restockCoffees();
  void restockCups();
  void restockWater();

  // getters/setters
  inline Extras *getExtras() const;
  inline Teas *getTeas() const;
  inline Coffees *getCoffees() const;
  inline int getCups() const;
  inline double getWaterAmount() const;

  inline void setCups(int cups);
  inline void setWaterAmount(double waterAmount); // in fl oz

protected:
  // template actions
  virtual void placeCup();
  virtual void boilWater();
  virtual void brew(std::string beverageSelected) = 0;
  virtual void pourInCup();
  virtual void addExtras() = 0;

  Extras *extras;
  Teas *teas;
  Coffees *coffees;

private:
  int cups;
  double waterAmount;
};

// ========== Concrete Templates ==========
// only makes teas
class TeaMaker : public BeverageMaker {
public:
  TeaMaker(const Extras *extras, const Teas *teas, int cups = MAX_CUPS,
           double waterAmount = MAX_WATER_AMOUNT);
  ~TeaMaker();

  // user gives the tea choice they want
  void makeBeverage(std::string beverageSelected) override;

  // override strickly for the TeaMaker classes
  void brew(std::string beverageSelected) override;
  void addExtras() override;
};

// only makes coffee
class CoffeeMaker : public BeverageMaker {
public:
  CoffeeMaker(const Extras *extras, const Coffees *coffees, int cups = MAX_CUPS,
              double waterAmount = MAX_WATER_AMOUNT);
  ~CoffeeMaker();

  // user gives the coffee choice they want
  virtual void makeBeverage(std::string beverageSelected) override;

  // override strickly for the CoffeeMaker classes
  void brew(std::string beverageSelected) override;
  void addExtras() override;
};

#include "template-method.inl"