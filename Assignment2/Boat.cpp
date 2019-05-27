#include "Boat.h"
#include "Airplane.h"
#include <cmath>

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		this->mTravelLimits = 2;
		this->mTotalLimits = 3;
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
		const unsigned int compareSpeedRhs = 20;
		const unsigned int compareSpeedLhs = 800 - 10 * this->GetSumOfWeight();
		const unsigned int sailSpeed = compareSpeedLhs > compareSpeedRhs ? compareSpeedLhs : compareSpeedRhs;
		
		return sailSpeed;
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		const unsigned int maxPassengersCount = plane.GetMaxPassengersCount() + this->GetMaxPassengersCount();
		Boatplane bp(maxPassengersCount);
		bp.MoveTo(plane);
		bp.MoveTo(*this);
		return bp;
	}
}