#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
		this->mTravelLimits = 5;
		this->mTotalLimits = 6;
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetMaxSpeed()
	{
		return GetDriveSpeed();
	}

	unsigned int Motorcycle::GetDriveSpeed()
	{
		int sumOfWeight = this->GetSumOfWeight();
		int compareSpeedLhs = round(400.0 + 2.0 * sumOfWeight - pow((sumOfWeight / 15.0), 3.0));

		if (compareSpeedLhs < 0)
		{
			return 0;
		}
		else
		{
			return static_cast<unsigned int>(compareSpeedLhs);
		}
	}
}