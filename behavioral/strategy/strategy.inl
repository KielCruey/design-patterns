// ========= CommuteStrategy =========
inline const double CommuteStrategy::getAverageRateOfTravel() const {
	return this->averageRateOfTravel;
}

inline double CommuteStrategy::getCostToTravel() const {
	return this->costToTravel;
}

inline double CommuteStrategy::getTotalTimeCommuted() const {
	return this->totalTimeCommuted;
}

inline void CommuteStrategy::setCostToTravel(double costToTravel) {
	this->costToTravel = costToTravel;
}