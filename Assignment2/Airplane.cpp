#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include <cmath>

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		
	}

	Airplane::~Airplane()
	{
	}

	unsigned int Airplane::GetMaxSpeed()
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int driveSpeed = GetDriveSpeed();

		unsigned int maxSpeed = flySpeed > driveSpeed ? flySpeed : driveSpeed;
		return maxSpeed;
	}

	unsigned int Airplane::GetFlySpeed()
	{
		unsigned int sumOfWeight = this->GetSumOfWeight();
		return 200 * exp((-sumOfWeight + 800) / 500);
	}

	unsigned int Airplane::GetDriveSpeed()
	{
		unsigned int sumOfWeight = this->GetSumOfWeight();
		return 4 * exp((-sumOfWeight + 400) / 70);
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(0);
		return bp;
	}
}
