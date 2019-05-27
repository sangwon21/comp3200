#include "Boatplane.h"
#include <cmath>

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
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
		unsigned int sumOfWeight = this->GetSumOfWeight();
		return 150 * exp((500 - sumOfWeight) / 300);
	}
	unsigned int Boatplane::GetSailSpeed()
	{
		unsigned int compareSpeedRhs = 20;
		unsigned int compareSpeedLhs = 800 - 1.7 * this->GetSumOfWeight();
		unsigned int sailSpeed = compareSpeedLhs > compareSpeedRhs ? compareSpeedLhs : compareSpeedRhs;

		return sailSpeed;
	}
}