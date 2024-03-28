#include "strategy.hpp"

// ========== Tavel Plans ==========
TravelPlans::TravelPlans(std::string citysName,
						 int milesToTravel) :
	citysName(citysName),
	milesToTravel(milesToTravel)
{ }

// ========== Commute Strategy ==========
CommuteStrategy::CommuteStrategy(std::unique_ptr<TravelPlans*> travelPlans,
								 double averageRateOfTravel,
								 double costToTravel) :
	travelPlans(std::make_unique<TravelPlans *>(travelPlans)),
	averageRateOfTravel(averageRateOfTravel),
	costToTravel(costToTravel)
{ }

// ========== Commute Strategy ==========
Bike::Bike(TravelPlans * travelPlans,
		   double totalTimeCommuted) :
	CommuteStrategy(BIKE_RATE, BIKE_FARE),
	totalTimeCommuted(totalTimeCommuted)
{ }

void Bike::travelToDestination() {

}

int main() {
	TravelTrip travelTrip(std::make_unique<Bike>());

	return 0;
}