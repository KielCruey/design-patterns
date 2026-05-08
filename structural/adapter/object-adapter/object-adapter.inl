// =========== Outlet ===========
inline bool Outlet::GetHasRoundHoles() const { return this->HasRoundHoles; }

inline int Outlet::GetNumberOfHoles() const { return this->NumberOfHoles; }

inline int Outlet::GetFrequencyRating() const { return this->FrequencyRating; }

inline int Outlet::GetVoltageRating() const { return this->VoltageRating; }

// =========== Plug ===========
inline bool Plug::GetHasRoundPins() const { return this->HasRoundPins; }

inline int Plug::GetPinCount() const { return this->PinCount; }

inline int Plug::GetVoltageRating() const { return this->VoltageRating; }

inline int Plug::GetFrequencyRating() const { return this->FrequencyRating; }