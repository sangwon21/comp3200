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
		unsigned int sumOfWeight = this->GetSumOfWeight();
		unsigned int compareSpeedLhs = static_cast<unsigned int>(round(400.0 + 2.0 * sumOfWeight - pow((sumOfWeight / 15.0), 3.0)));
		unsigned int driveSpeed = compareSpeedLhs > 0 ? compareSpeedLhs : 0;

		return driveSpeed;
	}
}