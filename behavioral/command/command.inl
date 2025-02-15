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
inline void PowerOn::setTV() {
	this->tv = tv;
}

inline TV * PowerOn::getTV() {
	return this->tv;
}

// ============ PowerOff ============
inline void PowerOff::setTV() {
	this->tv = tv;
}

inline TV * PowerOff::getTV() {
	return this->tv;
}

// ============ VolumeUp ============
inline void VolumeUp::setTV() {
	this->tv = tv;
}

inline TV * VolumeUp::getTV() {
	return this->tv;
}

// ============ VolumeDown ============
inline void VolumeDown::setTV() {
	this->tv = tv;
}

inline TV * VolumeDown::getTV() {
	return this->tv;
}

// ============ ChannelUp ============
inline void ChannelUp::setTV() {
	this->tv = tv;
}

inline TV * ChannelUp::getTV() {
	return this->tv;
}

// ============ ChannelDown ============
inline void ChannelDown::setTV() {
	this->tv = tv;
}

inline TV * ChannelDown::getTV() {
	return this->tv;
}

// ============ Invoker ============
inline void TVRemote::setTVCommand(TVCommand* tvCommand) {
	this->tvCommand = tvCommand;
}

inline TVCommand * TVRemote::getTVCommand() {
	return this->tvCommand;
}

