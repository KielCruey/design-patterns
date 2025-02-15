// ============= Movie =============
inline void Movie::SetName(std::string name) {
    this->name = name;
}

inline void Movie::SetCurrentDuration(double currentDuration) {
    this->currentDuration = currentDuration;
}

inline void Movie::SetTotalDuration(double totalDuration) {
    this->totalDuration = totalDuration;
}

inline std::string Movie::GetName() const {
    return this->name;
}

inline double Movie::GetCurrentDuration() const {
    return this->currentDuration;
}

inline double Movie::GetTotalDuration() const {
    return this->totalDuration;
}

// ============= TVDevice =============
inline void TVDevice::SetMovie(Movie* movie) {
    this->movie = movie;
}

void TVDevice::SetIsPlaying(bool isPlaying) {
    this->isPlaying = isPlaying;
}

inline void TVDevice::SetIsMuted(bool isMuted) {
    this->isMuted = isMuted;
}

inline void TVDevice::SetPower(bool isPowered) {
    this->isPowered = isPowered;
}

inline void TVDevice::SetVolume(int volume) {
    this->volume = volume;
}

inline void TVDevice::SetChannel(int channel) {
    this->channel = channel;
}

inline Movie* TVDevice::GetMovie() const {
    return this->movie;
}

inline bool TVDevice::GetIsPlaying() const {
    return this->isPlaying;
}

inline bool TVDevice::GetIsMuted() const {
    return this->isMuted;
}

inline bool TVDevice::GetPower() const {
    return this->isPowered;
}

inline int TVDevice::GetVolume() const {
    return this->volume;
}

inline int TVDevice::GetChannel() const {
    return this->channel;
}

// ============= RadioDevice =============
inline void RadioDevice::SetIsMuted(bool isMuted) {
    this->isMuted = isMuted;
}

inline void RadioDevice::SetPower(bool isPowered) {
    this->isPowered = isPowered;
}

inline void RadioDevice::SetVolume(int volume) {
    this->volume = volume;
}

inline void RadioDevice::SetChannel(int channel) {
    this->channel = channel;
}

inline bool RadioDevice::GetIsMuted() const {
    return this->isMuted;
}

inline bool RadioDevice::GetPower() const {
    return this->isPowered;
}

inline int RadioDevice::GetVolume() const {
    return this->volume;
}

inline int RadioDevice::GetChannel() const {
    return this->channel;
}

// ============= Abstraction =============
inline Device* Remote::GetDevice() const {
    return this->device;
}

inline void Remote::SetDevice(Device* device) {
    this->device = device;
}