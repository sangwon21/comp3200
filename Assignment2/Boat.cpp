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

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	unsigned int Boat::GetSailSpeed() const
	{
		int compareSpeedRhs = 20;
		int compareSpeedLhs = 800 - 10 * this->GetSumOfWeight();

		if (compareSpeedLhs < compareSpeedRhs)
		{
			return static_cast<unsigned int>(compareSpeedRhs);
		}
		else
		{
			return static_cast<unsigned int>(compareSpeedLhs);
		}
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		const unsigned int maxPassengersCount = plane.GetMaxPassengersCount() + this->GetMaxPassengersCount();
		unsigned int planePassengerCount = plane.GetPassengersCount();
		unsigned int boatPassengerCount = this->GetPassengersCount();
		plane.SetPassengersCount(0);
		this->SetPassengersCount(0);
		return Boatplane(maxPassengersCount, plane.GetPassengers(), planePassengerCount, this->GetPassengers(), boatPassengerCount);
	}
}