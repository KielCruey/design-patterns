// ======== Boss ========
inline Mood * Boss::getMood() {
	return this->mood;
}

inline void Boss::setMood(Mood * mood) {
	this->mood = mood;
}

// ======== Mood ========
void Mood::setBoss(Boss * boss) {
	this->boss = boss;
}