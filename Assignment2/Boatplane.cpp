#include "Boatplane.h"
#include <cmath>

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		this->mTravelLimits = 1;
		this->mTotalLimits = 4;
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetMaxSpeed()
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int sailSpeed = GetSailSpeed();

		unsigned maxSpeed = flySpeed > sailSpeed ? flySpeed : sailSpeed;
		return maxSpeed;
	}

	unsigned int Boatplane::GetFlySpeed()
	{
		unsigned int sumOfWeight = this->GetSumOfWeight();
		unsigned int flySpeed = static_cast<unsigned int>(round(150 * exp((500 - sumOfWeight) / 300.0)));
		return flySpeed;
	}

	unsigned int Boatplane::GetSailSpeed()
	{
		unsigned int compareSpeedRhs = 20;
		unsigned int compareSpeedLhs = static_cast<unsigned int>(round(800 - 1.7 * this->GetSumOfWeight()));
		unsigned int sailSpeed = compareSpeedLhs > compareSpeedRhs ? compareSpeedLhs : compareSpeedRhs;
		return sailSpeed;
	}
}