#include <iostream>
    
#include "composite.hpp"  

// ============= Component =============
ComputerComponent::ComputerComponent(ComputerComponent* parent) :
    parent(parent)
{
    std::cout << "ComputerComponent created" << std::endl;
}

ComputerComponent::~ComputerComponent() {
    std::cout << "ComputerComponent destroyed" << std::endl;
}

// --------------- getters/setters ---------------
ComputerComponent * ComputerComponent::GetParent() const {
    return this->parent;
}

void ComputerComponent::SetParent(ComputerComponent * parent) {
    this->parent = parent;
}

// --------------- virtuals ---------------
bool ComputerComponent::IsComposite() {
    return false;
}

void ComputerComponent::Print() {
    std::cout << "Parent: " << GetParent() << std::endl;
}

// ============= Abstract Leaf =============
Part::Part(std::string brandName, std::string modelName) :
    brandName(brandName),
    modelName(modelName)
{
    std::cout << "Part created" << std::endl;
}

Part::~Part() {
    std::cout << "Part destroyed" << std::endl;
}

std::string Part::GetBrandName() const {
    return this->brandName;
}

std::string Part::GetModelName() const {
    return this->modelName;
}

void Part::SetBrandName(std::string brandName) {
    this->brandName = brandName;
}

void Part::SetModelName(std::string modelName) {
    this->modelName = modelName;
}

// --------------- virtuals ---------------
bool Part::IsComposite() {
    return false;
}

void Part::Print() {
    std::cout << "Brand Name: " << GetBrandName() << std::endl;
    std::cout << "Model Name: " << GetModelName() << std::endl;
}

// ============= Concrete Leaves -- Mouse =============
Mouse::Mouse(int dpi,
                std::string brandName, 
                std::string modelName) :
    Part(brandName, modelName),
    dpi(dpi)
{
    std::cout << "Mouse created" << std::endl;
}

Mouse::~Mouse() {
    std::cout << "Mouse destroyed" << std::endl;
}

int Mouse::GetDPI() const {
    return this->dpi;
}

void Mouse::SetDPI(int dpi) {
    this->dpi = dpi;
}

// ------ virtuals ------
bool Mouse::IsComposite() {
    return false;
}

void Mouse::Print() {
    std::cout << "Mouse Stats" << std::endl;
    std::cout << "DPI: " << GetDPI() << std::endl;
} 

// ============= Concrete Leaf -- Keyboard =============
Keyboard::Keyboard(bool hasClickyKeys, 
                    std::string brandName, 
                    std::string modelName) :
    Part(brandName, modelName),
    hasClickyKeys(hasClickyKeys)
{
    std::cout << "Keyboard created" << std::endl;
}

Keyboard::~Keyboard() {
    std::cout << "Keyboard destroyed" << std::endl;
}

bool Keyboard::GetHasClickyKeys() const {
    return this->hasClickyKeys;
}

void Keyboard::SetHasClickyKeys(bool HasClickyKeys) {
    this->hasClickyKeys = hasClickyKeys;
}

// ------ virtuals ------
bool Keyboard::IsComposite() {
    return false;
}

void Keyboard::Print() {
    std::cout << "Keyboard Stats" << std::endl;
    std::cout << "HasClickyKeys: " << GetHasClickyKeys() << std::endl;
}

// ============= Concrete Leaf -- Monitor =============
Monitor::Monitor(double length, 
                double width,
                std::string brandName,
                std::string modelName) :
    Part(brandName, modelName),
    length(length),
    width(width)
{
    std::cout << "Monitor created" << std::endl;
}

Monitor::~Monitor() {
    std::cout << "Monitor deleted" << std::endl;
}

double Monitor::GetLength() const {
    return this->length;
}

double Monitor::GetWidth() const {
    return this->width;
}

void Monitor::SetLength(double length) {
    this->length = length;
}

void Monitor::SetWidth(double width) {
    this->width = width;
}

// ------ virtuals ------
bool Monitor::IsComposite() { 
    return false;
}

void Monitor::Print() {
    std::cout << "Monitor Length: " << GetLength() << std::endl;
    std::cout << "Monitor Width: " << GetWidth() << std::endl;
}

// ============= Concrete Leaf -- Speakers =============
Speakers::Speakers(bool isPowered, 
                    int volume,
                    std::string brandName,
                    std::string modelName) :
    Part(brandName, modelName),
    isPowered(isPowered),
    volume(volume)
{
    std::cout << "Speakers created" << std::endl;
}

Speakers::~Speakers() {
    std::cout << "Speakers destroyed" << std::endl;
}

bool Speakers::GetIsPowered() const {
    return this->isPowered;
}

int Speakers::GetVolume() const {
    return this->volume;
}

void Speakers::SetIsPowered(bool isPowered) {
    this->isPowered = isPowered;
}

void Speakers::SetVolume(int volume) {
    this->volume = volume;
}

// ------ virtuals ------
bool Speakers::IsComposite() {
    return false;
}

void Speakers::Print() {
    std::cout << "Speakers Stats" << std::endl;
    std::cout << "Speakers Powered: " << GetIsPowered() << std::endl;
    std::cout << "Speakers Volume: " << GetVolume() << std::endl;
}

// ============= Concrete Leaf -- SSD =============
SSD::SSD(double currentStorage, 
            double totalStorage,
            std::string brandName,
            std::string modelName) :
    Part(brandName, modelName),
    currentStorage(currentStorage),
    totalStorage(totalStorage)
{
    std::cout << "SSD created" << std::endl;
}

SSD::~SSD() {
    std::cout << "SSD destroyed" << std::endl;
}

double SSD::GetCurrentStorage() const {
    return this->currentStorage;
}

double SSD::GetTotalStorage() const {
    return this->totalStorage;
}

void SSD::SetCurrentStorage(double currentStorage) {
    this->currentStorage = currentStorage;
}

void SSD::SetTotalStorage(double totalStorage) {
    this->totalStorage = totalStorage;
}

// ------ virtuals ------
bool SSD::IsComposite() {
    return false;
}

void SSD::Print() {
    std::cout << "SSD Stats" << std::endl;
    std::cout << "SSD Current Storage: " << GetCurrentStorage() << std::endl;
    std::cout << "SSD Total Storage: " << GetTotalStorage() << std::endl;
}

// ============= Concrete Leaf -- RAM =============
RAM::RAM(double capacity,
            std::string brandName,
            std::string modelName) :
    Part(brandName, modelName),
    capacity(capacity)
{
    std::cout << "RAM created" << std::endl;
}

RAM::~RAM() {
    std::cout << "RAM destroyed" << std::endl;
}

double RAM::GetCapacity() const {
    return this->capacity;
}

void RAM::SetCapacity(double capacity) {
    this->capacity = capacity;
}

// ------ virtuals ------
bool RAM::IsComposite() {
    return false;
}

void RAM::Print() {
    std::cout << "RAM Stats" << std::endl;
    std::cout << "RAM Capacity: " << GetCapacity() << std::endl;
}

// ============= Concrete Leaf -- CPU =============
CPU::CPU(int cores,
        std::string brandName,
        std::string modelName) :
    Part(brandName, modelName),
    cores(cores)
{
    std::cout << "CPU created" << std::endl;
}

CPU::~CPU() {
    std::cout << "CPU destroyed" << std::endl;
}

int CPU::GetCores() const {
    return this->cores;
}

void CPU::SetCores(int cores) {
    this->cores = cores;
}

// ------ virtuals ------
bool CPU::IsComposite() {
    return false;
}

void CPU::Print() {
    std::cout << "CPU Stats" << std::endl;
    std::cout << "CPU Cores: " << GetCores() << std::endl;
}

// ============= Concrete Leaf -- GPU =============
GPU::GPU(double memory,
        std::string brandName,
        std::string modelName) :
    Part(brandName, modelName),
    memory(memory)
{
    std::cout << "GPU created" << std::endl;
}

GPU::~GPU() {
    std::cout << "GPU destroyed" << std::endl;
}

double GPU::GetMemory() const {
    return this->memory;
}

void GPU::SetMemory(double memory) {
    this->memory = memory;
}

// ------ virtuals ------
bool GPU::IsComposite() {
    return false;
}

void GPU::Print() {
    std::cout << "GPU Stats" << std::endl;
    std::cout << "GPU Memory: " << GetMemory() << std::endl;
}

// ============= Computer -- Composite =============
Computer::Computer() {
    std::cout << "Computer composite object created" << std::endl;
}

Computer::~Computer() {
    std::cout << "Computer composite object created" << std::endl;
}

std::list<ComputerComponent*> Computer::GetChilden() const {
    return this->children;
}

void Computer::Add(ComputerComponent * computerComponent) {
    children.push_back(computerComponent);
    computerComponent->SetParent(this);
}

void Computer::Remove(ComputerComponent * computerComponent) {
    children.remove(computerComponent);
    computerComponent->SetParent(nullptr);
}

bool Computer::IsComposite() {
    return true;
}

void Computer::Print() {
    for (auto i : GetChilden()) {
         i->Print();
    }
}

// ============= Peripherals -- Composite =============
Peripherals::Peripherals() {
    std::cout << "Peripherals composite object created" << std::endl;
}

Peripherals::~Peripherals() {
    std::cout << "Peripherals composite object destroyed" << std::endl;
}

// calls the print function for all the items in the 'children' list
std::list<ComputerComponent*> Peripherals::GetChilden() const {
    return this->children;
}

// this Composite class adds an object to its list and assigns that object to its parent Component
void Peripherals::Add(ComputerComponent * computerComponent) {
    children.push_back(computerComponent);
    computerComponent->SetParent(this);
}

// this Composite class deletes an object from its list and removes that object from its parent Component
void Peripherals::Remove(ComputerComponent * computerComponent) {
    children.remove(computerComponent);
    computerComponent->SetParent(nullptr);
}

bool Peripherals::IsComposite() {
    return true;
}

// calls the print function for all the items in the 'children' list
void Peripherals::Print() {
    for (auto i : GetChilden()) {
        i->Print();
    }
}

// ============= Tower -- Composite =============
Tower::Tower() {
    std::cout << "Tower composite object created" << std::endl;
}

Tower::~Tower() {
    std::cout << "Tower composite object destroyed" << std::endl;
}

// calls the print function for all the items in the 'children' list
std::list<ComputerComponent*> Tower::GetChilden() const {
    return this->children;
}

// this Composite class adds an object to its list and assigns that object to its parent Component
void Tower::Add(ComputerComponent * computerComponent) {
    children.push_back(computerComponent);
    computerComponent->SetParent(this);
}

// this Composite class deletes an object from its list and removes that object from its parent Component
void Tower::Remove(ComputerComponent * computerComponent) {
    children.remove(computerComponent);
    computerComponent->SetParent(nullptr);
}

bool Tower::IsComposite() {
    return true;
}

// calls the print function for all the items in the 'children' list
void Tower::Print() {
    for (auto i : GetChilden()) {
        i->Print();
    }
}

// ============= Motherboard -- Composite =============
Motherboard::Motherboard() {
    std::cout << "Motherboard composite object created" << std::endl;
}

Motherboard::~Motherboard() {
    std::cout << "Motherboard composite object destroyed" << std::endl;
}

std::list<ComputerComponent*> Motherboard::GetChilden() const {
    return this->children;
}

void Motherboard::Add(ComputerComponent * computerComponent) {
    children.push_back(computerComponent);
    computerComponent->SetParent(this);
}

void Motherboard::Remove(ComputerComponent * computerComponent) {
    children.remove(computerComponent);
    computerComponent->SetParent(nullptr);
}

bool Motherboard::IsComposite() {
    return true;
}

// calls the print function for all the items in the 'children' list
void Motherboard::Print() {
    for (auto i : GetChilden()) {
        i->Print();
    }
}

// ================== Client Code ==================
void CreateComputer(Computer * computer) {
    // building a computer
    Peripherals * peripherals = new Peripherals();
    Tower * tower = new Tower();

    computer->Add(peripherals);
    computer->Add(tower);

    Motherboard * motherboard = new Motherboard();

    tower->Add(motherboard);

    Mouse * mouse = new Mouse(1000, "Logitech", "G502 Hero");
    Keyboard * keyboard = new Keyboard(false, "Cool Master", "Quick Fire");
    Monitor * monitor = new Monitor(9, 16, "Asus", "42069 Gaming");
    Speakers* speakers = new Speakers(true, 5, "Adams", "A7V");

    peripherals->Add(mouse);
    peripherals->Add(keyboard);
    peripherals->Add(monitor);
    peripherals->Add(speakers);

    SSD * ssd = new SSD(10, 25, "Samsung", "Sandybridge");
    RAM * ram = new RAM(32, "Corsair", "Vengeance");
    CPU * cpu = new CPU(8, "AMD", "PM9C1a");
    GPU * gpu = new GPU(16, "ASUS", "TUF Gaming GeForce RTX");

    motherboard->Add(ssd);
    motherboard->Add(ram);
    motherboard->Add(cpu);
    motherboard->Add(gpu);
}

// ================== Main ==================
int main()
{
    std::cout << "Hello World" << std::endl;

    Computer * computer = new Computer();
    CreateComputer(computer);
    
    computer->Print();

    return 0;
}
