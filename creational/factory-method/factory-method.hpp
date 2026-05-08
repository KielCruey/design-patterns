// ============ Product ============
class AbstractAnimal {
public:
  virtual ~AbstractAnimal();

  // functions concrete classes must have
  virtual std::string SoundsOfYourPeople() = 0;
  virtual void Sleeps() = 0;
  virtual void Eats() = 0;
};

// ============ Concrete Products ============
class Cow : public AbstractAnimal {
public:
  Cow();
  explicit Cow(const std::string &name);
  ~Cow() override;

  std::string SoundsOfYourPeople() override;
  void Sleeps() override;
  void Eats() override;

  inline std::string GetName() const;

private:
  std::string name;
};

class Sheep : public AbstractAnimal {
public:
  Sheep();
  explicit Sheep(const std::string &name);
  ~Sheep() override;

  std::string SoundsOfYourPeople() override;
  void Sleeps() override;
  void Eats() override;

  inline std::string GetName() const;

private:
  std::string name;
};

class Pig : public AbstractAnimal {
public:
  Pig();
  explicit Pig(const std::string &name);
  ~Pig() override;

  std::string SoundsOfYourPeople() override;
  void Sleeps() override;
  void Eats() override;

  inline std::string GetName() const;

private:
  std::string name;
};

// ============ Creator ============
// the point of the creator is to not create products, but to call the
// FactoryMethod() function which then creates the subclass objects we need
class AnimalCreator {
public:
  // functions that can be overriden by derived class
  virtual ~AnimalCreator();

  // virtual functions that must be override by derived class
  virtual AbstractAnimal *FactoryMethod() = 0;
  virtual AbstractAnimal *FactoryMethod(std::string name) = 0;

  // non-virtual function to call the virtual FactoryMethod(), which will be
  // overwritten by the subclass "products" the subclasses will use the new
  // keyword to create their own object
  AbstractAnimal *CreateAnimal();
  AbstractAnimal *CreateAnimal(const std::string &name);
};

// ============ Concrete Creators ============
// only need these subclasses to override the virtual FactoryMethod() function
// they are all using the default constructor/destructor
class ConcreteCowCreator : public AnimalCreator {
public:
  ~ConcreteCowCreator() override;

  AbstractAnimal *FactoryMethod() override;
  AbstractAnimal *FactoryMethod(std::string name) override;
};

class ConcreteSheepCreator : public AnimalCreator {
public:
  ~ConcreteSheepCreator() override;

  AbstractAnimal *FactoryMethod() override;
  AbstractAnimal *FactoryMethod(std::string name) override;
};

class ConcretePigCreator : public AnimalCreator {
public:
  ~ConcretePigCreator() override;

  AbstractAnimal *FactoryMethod() override;
  AbstractAnimal *FactoryMethod(std::string name) override;
};

#include "factory-method.inl"