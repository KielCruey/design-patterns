#include <list>
#include <string>

// ============= Abstract Component =============
// The base Component class declares common operations for both simple and complex objects of a composition.
// In this case, it's a base for the 'leaf' and 'composite' classes
class ComputerComponent
{
public:
    explicit ComputerComponent(ComputerComponent * parent = nullptr);
    ~ComputerComponent();
    
    inline ComputerComponent * GetParent() const;
    inline void SetParent(ComputerComponent * parent);

    // ------ virtuals ------
    virtual void Add(ComputerComponent * computerComponent) = 0;
    virtual void Remove(ComputerComponent * computerComponent) = 0;
    virtual bool IsComposite() = 0;
    virtual void Print() = 0;

protected:
    ComputerComponent * parent;
};

// ============= "Abstract" Leaf =============
class Part : public ComputerComponent
{
public:
    explicit Part(std::string& brandName, 
       std::string& modelName);
    ~Part();

    inline std::string GetBrandName() const;
    inline std::string GetModelName() const;

    // ------ virtuals ------
    virtual void Add(ComputerComponent * computerComponent) override;
    virtual void Remove(ComputerComponent * computerComponent) override;
    virtual bool IsComposite() override = 0;
    virtual void Print() override = 0;

private:
    std::string& brandName;
    std::string& modelName;
};

// ============= Concrete Leaves =============
class Mouse : public Part
{
public:
    explicit Mouse(std::string& brandName, 
        std::string& modelName,
        int dpi = 1000);
    ~Mouse();

    inline int GetDPI() const;

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;   

private:   
    int dpi;
};

class Keyboard : public Part
{
public:
    explicit Keyboard(bool hasClickyKeys = false, std::string brandName = "N/A", std::string modelName = "N/A");
    ~Keyboard();

    inline bool GetHasClickyKeys() const;

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;

private:   
    bool hasClickyKeys;
};

class Monitor : public Part
{
public:
    explicit Monitor(double length = 0.0, double width = 0.0,
            std::string brandName = "N/A", std::string modelName = "N/A");

    ~Monitor();

    inline double GetLength() const;
    inline double GetWidth() const;

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;

private:   
    double length;
    double width;
};

class Speakers : public Part
{
public:
    explicit Speakers(bool isPowered = false, int volume = 0.0,
                std::string brandName = "N/A", std::string modelName = "N/A");
    ~Speakers(); 

    inline bool GetIsPowered() const;
    inline int GetVolume() const;
    inline void SetVolume(int volume);

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;

private:
    bool isPowered;
    int volume;
};

class SSD : public Part
{
public:
    explicit SSD(double currentStorage = 0, double totalStorage = 0,
        std::string brandName = "N/A", std::string modelName = "N/A");
    ~SSD(); 

    inline double GetCurrentStorage() const;
    inline double GetTotalStorage() const;

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;

private:
    double currentStorage;
    double totalStorage;
};

class RAM : public Part
{
public:
    explicit RAM(double capacity = 0,
        std::string brandName = "N/A",
        std::string modelName = "N/A");   // in GB
    ~RAM(); 

    inline double GetCapacity() const;

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;

private:
    double capacity;
};

class CPU : public Part
{
public:
    explicit CPU(int cores = 0,
        std::string brandName = "N/A",
        std::string modelName = "N/A");
    ~CPU(); 

    inline int GetCores() const;

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;

private:
    int cores;
};

class GPU : public Part
{
public:
    explicit GPU(double memory = 0,
        std::string brandName = "N/A",
        std::string modelName = "N/A");
    ~GPU();

    inline double GetMemory() const;

    // ------ virtuals ------
    bool IsComposite() override;
    void Print() override;

private:
    double memory;
};

// ============= Composite =============
// The Composite class represents the complex components that may have children.
class Computer : public ComputerComponent
{
public: 
    Computer();
    ~Computer();

    inline std::list<ComputerComponent *> GetChilden() const;

    // ------ virtuals ------
    void Add(ComputerComponent * computerComponent) override;
    void Remove(ComputerComponent * computerComponent) override;
    bool IsComposite() override;
    void Print() override;

protected:
    std::list<ComputerComponent*> children;
};

class Peripherals : public ComputerComponent
{
protected: 
    std::list<ComputerComponent *> children;

public: 
    Peripherals();
    ~Peripherals();

    inline std::list<ComputerComponent*> GetChilden() const;

    // ------ virtuals ------
    void Add(ComputerComponent * computerComponent) override;
    void Remove(ComputerComponent * computerComponent) override;
    bool IsComposite() override;
    void Print() override;
};

class Tower : public ComputerComponent
{
protected: 
    std::list<ComputerComponent *> children;

public: 
    Tower();
    ~Tower();

    inline std::list<ComputerComponent*> GetChilden() const;

    // ------ virtuals ------
    void Add(ComputerComponent * computerComponent) override;
    void Remove(ComputerComponent * computerComponent) override;
    bool IsComposite() override;
    void Print() override;
};

class Motherboard : public ComputerComponent
{
protected: 
    std::list<ComputerComponent *> children;

public: 
    Motherboard();
    ~Motherboard();

    inline std::list<ComputerComponent*> GetChilden() const;

    // ------ virtuals ------
    void Add(ComputerComponent * computerComponent) override;
    void Remove(ComputerComponent * computerComponent) override;
    bool IsComposite() override;
    void Print() override;
};

#include "composite.inl"