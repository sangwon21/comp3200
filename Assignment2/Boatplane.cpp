#include "Boatplane.h"
#include <cmath>
#include "Boat.h"
#include "Airplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		this->mTravelLimits = 1;
		this->mTotalLimits = 4;
	}

	Boatplane::Boatplane(unsigned int maxPassengersCount, const Person** people1, const Person** people2)
		: Vehicle(maxPassengersCount, people1, people2)
	{
		this->mTravelLimits = 1;
		this->mTotalLimits = 4;
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int sailSpeed = GetSailSpeed();

		unsigned int maxSpeed = flySpeed > sailSpeed ? flySpeed : sailSpeed;
		return maxSpeed;
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		unsigned int sumOfWeight = this->GetSumOfWeight();
		unsigned int flySpeed = static_cast<unsigned int>(round(150 * exp((500 - sumOfWeight) / 300.0)));
		return flySpeed;
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		int compareSpeedRhs = 20;
		int compareSpeedLhs = static_cast<int>(round(800 - 1.7 * this->GetSumOfWeight()));

		if (compareSpeedLhs <= compareSpeedRhs)
		{
			return static_cast<unsigned int>(compareSpeedRhs);
		}
		else
		{
			return static_cast<unsigned int>(compareSpeedLhs);
		}
	}
	Boatplane Boatplane::MoveTo(Boat& boat)
	{
		for (unsigned int i = mSize; i < mSize + boat.GetPassengersCount(); i++)
		{
			mPassengers[i] = boat.GetPassenger(i - mSize);
			boat.SetPassenger(i - mSize, nullptr);
		}
		mSize += boat.GetPassengersCount();
		boat.SetPassengersCount(0);

		return *this;

	}
	Boatplane Boatplane::MoveTo(Airplane& airplane)
	{
		for (unsigned int i = mSize; i < mSize + airplane.GetPassengersCount(); i++)
		{
			mPassengers[i] = airplane.GetPassenger(i - mSize);
			airplane.SetPassenger(i - mSize, nullptr);
		}
		mSize += airplane.GetPassengersCount();
		airplane.SetPassengersCount(0);

		return *this;
	}
}