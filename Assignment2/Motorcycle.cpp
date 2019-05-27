#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
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
		unsigned int compareSpeedLhs = 400 + 2 * sumOfWeight - pow((sumOfWeight / 15), 3);
		unsigned int driveSpeed = compareSpeedLhs > 0 ? compareSpeedLhs : 0;
		
		return driveSpeed;
	}
}