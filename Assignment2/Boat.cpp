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
		unsigned int compareSpeedRhs = 20;
		unsigned int compareSpeedLhs = 800 - 10 * this->GetSumOfWeight();
		unsigned int sailSpeed = compareSpeedLhs > compareNumberRhs ? compareSpeedLhs : compareNumberRhs;
		
		return sailSpeed;
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		
		unsigned int passengerCounts = plane.GetPassengersCount() + this->GetPassengersCount();
		Boatplane bp(passengerCounts);
		return bp;
	}
}