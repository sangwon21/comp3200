#include "UBoat.h"
#include <cmath>

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetMaxSpeed()
	{
		const unsigned int compareSpeedLhs = GetDiveSpeed();
		const unsigned int compareSpeedRhs = GetSailSpeed();
		const unsigned int maxSpeed = compareSpeedLhs > compareSpeedRhs ? compareSpeedLhs : compareSpeedRhs;
		return maxSpeed;
	}

	unsigned int UBoat::GetDiveSpeed()
	{
		const unsigned int sumOfWeight = this->GetSumOfWeight();
		return 500 * log((sumOfWeight + 150) / 150) + 30;
	}

	unsigned int UBoat::GetSailSpeed()
	{
		const unsigned int compareSpeedLhs = 200;
		const unsigned int compareSpeedRhs = 550 - this->GetSumOfWeight() / 10;
		const unsigned int sailSpeed = compareSpeedLhs > compareSpeedRhs ? compareSpeedLhs : compareSpeedRhs;
		return sailSpeed;
	}
}