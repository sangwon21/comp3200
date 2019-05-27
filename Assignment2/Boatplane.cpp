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
		return 0;
	}

	unsigned int Boatplane::GetFlySpeed()
	{
		const unsigned int sumOfWeight = this->GetSumOfWeight();
		const unsigned int flySpeed = static_cast<unsigned int>(150 * exp((500 - sumOfWeight) / 300.0));
		return flySpeed;
	}

	unsigned int Boatplane::GetSailSpeed()
	{
		const unsigned int compareSpeedRhs = 20;
		const unsigned int compareSpeedLhs = static_cast<unsigned int>(800 - 1.7 * this->GetSumOfWeight());
		const unsigned int sailSpeed = compareSpeedLhs > compareSpeedRhs ? compareSpeedLhs : compareSpeedRhs;
		return sailSpeed;
	}
}