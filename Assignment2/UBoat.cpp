#include "UBoat.h"
#include <cmath>

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
		this->mTravelLimits = 2;
		this->mTotalLimits = 6;
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
		const unsigned int diveSpeed = static_cast<unsigned int>(round(500 * log((sumOfWeight + 150.0) / 150.0) + 30));
		return diveSpeed;
	}

	unsigned int UBoat::GetSailSpeed()
	{
		const unsigned int compareSpeedLhs = 200;
		const unsigned int compareSpeedRhs = static_cast<unsigned int>(round(550 - this->GetSumOfWeight() / 10.0));
		const unsigned int sailSpeed = compareSpeedLhs > compareSpeedRhs ? compareSpeedLhs : compareSpeedRhs;
		return sailSpeed;
	}
}