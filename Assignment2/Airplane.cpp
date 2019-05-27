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
		return 200 * exp((800 - sumOfWeight) / 500);
	}

	unsigned int Airplane::GetDriveSpeed()
	{
		unsigned int sumOfWeight = this->GetSumOfWeight();
		return 4 * exp((400 - sumOfWeight) / 70);
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		unsigned int passengerCounts = boat.GetPassengersCount() + this->GetPassengersCount();
		Boatplane bp(passengerCounts);
		return bp;
	}
}
