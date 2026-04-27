#include <iostream>

// ============ THE PRODUCT ============
// acts like a normal class, define everything that your "product" has
class Car
{
public:
    explicit Car(const std::string& make = "N/A", const std::string& model = "N/A");
    ~Car();

    void printMake() const;
    void printModel() const;

    inline std::string GetMake() const;
    inline std::string GetModel() const;

private:
    std::string make;
    std::string model;
};

// ============ Abstract Builder ============
class CarBuilder
{
public:
    virtual ~CarBuilder() = default;
    virtual void ProduceEngine() = 0;
    virtual void ProduceChassis() = 0;
    virtual void ProduceTransmission() = 0;
};

// ============ Concrete Builder ============
class ConcreteCarBuilder : public CarBuilder
{
public:
    explicit ConcreteCarBuilder(const std::string& make = "N/A", const std::string& model = "N/A");
    ~ConcreteCarBuilder() override;

    // ============ car constructors ============
    void CreateCar(const std::string& make = "N/A", const std::string& model = "N/A");

    // ============ car components builds ============
    void ProduceEngine() override;
    void ProduceChassis() override;
    void ProduceTransmission() override;

    // ============ getters/setters ============
    inline void SetCar(Car* car);
    inline Car* GetCar();
    
private:
    Car* car;
};

// ============ Director ============
class CarDirector
{
public:
	explicit CarDirector(CarBuilder* carBuilder = nullptr);

    inline void SetBuilder(CarBuilder* carBuilder);

    // ============ construction functions ============
    // functions that help create a "recipe" for the director to trigger the builder
    void BuildMinimalViableCar();
    void BuildMaximumViableCar();

private:
    CarBuilder* carBuilder;
};

#include "builder.inl"