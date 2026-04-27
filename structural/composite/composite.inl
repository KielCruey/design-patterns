// ======== Abstract Component ========
inline ComputerComponent* ComputerComponent::GetParent() const {
    return this->parent;
}

inline void ComputerComponent::SetParent(ComputerComponent* parent) {
    this->parent = parent;
}

// ======== Part ========
inline std::string Part::GetBrandName() const {
    return this->brandName;
}

inline std::string Part::GetModelName() const {
    return this->modelName;
}

// ======== Mouse ========
inline int Mouse::GetDPI() const {
    return this->dpi;
}

// ======== Keyboard ========
inline bool Keyboard::GetHasClickyKeys() const {
    return this->hasClickyKeys;
}

// ======== Monitor ========
inline double Monitor::GetLength() const {
    return this->length;
}

inline double Monitor::GetWidth() const {
    return this->width;
}

// ======== Speakers ========
bool Speakers::GetIsPowered() const {
    return this->isPowered;
}

int Speakers::GetVolume() const {
    return this->volume;
}

void Speakers::SetVolume(int volume) {
    this->volume = volume;
}

// ======== SSD ========
inline double SSD::GetCurrentStorage() const {
    return this->currentStorage;
}

inline double SSD::GetTotalStorage() const {
    return this->totalStorage;
}

// ======== RAM ========
inline double RAM::GetCapacity() const {
    return this->capacity;
}

// ======== CPU ========
inline int CPU::GetCores() const {
    return this->cores;
}

// ======== GPU ========
double GPU::GetMemory() const {
    return this->memory;
}

// ======== Composite ========
std::list<ComputerComponent*> Computer::GetChilden() const {
    return this->children;
}

// ======== Peripherals ========
// calls the print function for all the items in the 'children' list
std::list<ComputerComponent*> Peripherals::GetChilden() const {
    return this->children;
}

// ======== Tower ========
// calls the print function for all the items in the 'children' list
std::list<ComputerComponent*> Tower::GetChilden() const {
    return this->children;
}

// ======== Motherboard ========
std::list<ComputerComponent*> Motherboard::GetChilden() const {
    return this->children;
}