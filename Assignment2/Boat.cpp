#include "Boat.h"
#include "Airplane.h"
#include <cmath>

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetMaxSpeed()
	{
		return GetSailSpeed();
	}

	unsigned int Boat::GetSailSpeed()
	{
		unsigned int compareNumber = 20;
		unsigned int sumOfWeight = this->GetSumOfWeight();
		unsigned int sailSpeed = sumOfWeight > compareNumber ? sumOfWeight : compareNumber;
		
		return sailSpeed;
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		
		unsigned int passengerCounts = plane.GetPassengersCount() + this->GetPassengersCount();
		Boatplane bp(passengerCounts);
		return bp;
	}
}