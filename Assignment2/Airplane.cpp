#include "Airplane.h"
#include "Boat.h"
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

	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int driveSpeed = GetDriveSpeed();

		unsigned int maxSpeed = flySpeed > driveSpeed ? flySpeed : driveSpeed;
		return maxSpeed;
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		unsigned int sumOfWeight = this->GetSumOfWeight();
		unsigned int flySpeed = static_cast<unsigned int>(round(200 * exp((800 - sumOfWeight) / 500.0)));
		return flySpeed;
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		unsigned int sumOfWeight = this->GetSumOfWeight();
		unsigned int driveSpeed = static_cast<unsigned int>(round(4 * exp((400 - sumOfWeight) / 70.0)));
		return driveSpeed;
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		unsigned int maxPassengersCount = boat.GetMaxPassengersCount() + this->GetMaxPassengersCount();
		boat.SetPassengersCount(0);
		this->SetPassengersCount(0);
		return Boatplane(maxPassengersCount, this->GetPassengers(), boat.GetPassengers());
	}
}
