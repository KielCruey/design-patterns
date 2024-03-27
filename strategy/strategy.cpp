#include "strategy.hpp"

// ========== Commute Strategy ==========
CommuteStrategy::CommuteStrategy(double averageRateOfTravel,
								 double costToTravel) :
	averageRateOfTravel(averageRateOfTravel),
	costToTravel(costToTravel)
{

}

// ========== Commute Strategy ==========
Bike::Bike() :
	CommuteStrategy(BIKE_RATE, BIKE_FARE)
{ }

void Bike::travelToDestination() {

}

int main() {
	TravelTrip * travelTrip = new TravelTrip(new Bike());


	return 0;
}