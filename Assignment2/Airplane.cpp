#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include <cmath>

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		this->mTravelLimits = 1;
		this->mTotalLimits = 4;
	}

	Airplane::~Airplane()
	{
	}

	unsigned int Airplane::GetMaxSpeed()
	{
		const unsigned int flySpeed = GetFlySpeed();
		const unsigned int driveSpeed = GetDriveSpeed();

		const unsigned int maxSpeed = flySpeed > driveSpeed ? flySpeed : driveSpeed;
		return maxSpeed;
	}

	unsigned int Airplane::GetFlySpeed()
	{
		const unsigned int sumOfWeight = this->GetSumOfWeight();
		const unsigned int flySpeed = static_cast<unsigned int>(round(200 * exp((800 - sumOfWeight) / 500.0)));
		return flySpeed;
	}

	unsigned int Airplane::GetDriveSpeed()
	{
		const unsigned int sumOfWeight = this->GetSumOfWeight();
		const unsigned int driveSpeed = static_cast<unsigned int>(round(4 * exp((400 - sumOfWeight) / 70.0)));
		return driveSpeed;
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		const unsigned int maxPassengersCount = boat.GetMaxPassengersCount() + this->GetMaxPassengersCount();
		Boatplane bp(maxPassengersCount);
		bp.MoveTo(*this);
		bp.MoveTo(boat);
		return bp;
	}
}
