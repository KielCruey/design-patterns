// ============ TV ============
inline bool TV::getIsPowered() const {
	return this->isPowered;
}

inline int TV::getChannel() const {
	return this->channel;
}

inline int TV::getVolume() const {
	return this->volume;
}

inline void TV::setIsPowered(bool isPowered) {
	this->isPowered = isPowered;
}

inline void TV::setChannel(bool channel) {
	this->channel = channel;
}

inline void TV::setVolume(bool volume) {
	this->volume = volume;
}

// ============ PowerOn ============
inline TV * PowerOn::getTV() {
	return this->tv;
}

// ============ PowerOff ============
inline TV * PowerOff::getTV() {
	return this->tv;
}

// ============ VolumeUp ============
inline TV * VolumeUp::getTV() {
	return this->tv;
}

// ============ VolumeDown ============
inline TV * VolumeDown::getTV() {
	return this->tv;
}

// ============ ChannelUp ============
inline TV * ChannelUp::getTV() {
	return this->tv;
}

// ============ ChannelDown ============
inline TV * ChannelDown::getTV() {
	return this->tv;
}

// ============ Invoker ============
inline TVCommand * TVRemote::getTVCommand() {
	return this->tvCommand;
}