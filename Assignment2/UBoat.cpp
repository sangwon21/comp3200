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
		unsigned int compareSpeedLhs = GetDiveSpeed();
		unsigned int compareSpeedRhs = GetSailSpeed();
		unsigned int maxSpeed = compareSpeedLhs > compareSpeedRhs ? compareSpeedLhs : compareSpeedRhs;
		return maxSpeed;
	}

	unsigned int UBoat::GetDiveSpeed()
	{
		unsigned int sumOfWeight = this->GetSumOfWeight();
		unsigned int diveSpeed = static_cast<unsigned int>(round(500 * log((sumOfWeight + 150.0) / 150.0) + 30));
		return diveSpeed;
	}

	unsigned int UBoat::GetSailSpeed()
	{
		unsigned int compareSpeedLhs = 200;
		unsigned int compareSpeedRhs = static_cast<unsigned int>(round(550 - this->GetSumOfWeight() / 10.0));
		unsigned int sailSpeed = compareSpeedLhs > compareSpeedRhs ? compareSpeedLhs : compareSpeedRhs;
		return sailSpeed;
	}
}