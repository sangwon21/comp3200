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

	Boatplane::Boatplane(unsigned int maxPassengersCount, const Person** people1, unsigned int people1Size, const Person** people2, unsigned int people2Size)
		: Vehicle(maxPassengersCount, people1, people1Size, people2, people2Size)
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
		unsigned int flySpeed = static_cast<unsigned int>(round(150 * exp((500 - static_cast<int>(sumOfWeight)) / 300.0)));
		return flySpeed;
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		int compareSpeedRhs = 20;
		int compareSpeedLhs = static_cast<int>(round(800 - 1.7 * static_cast<int>(this->GetSumOfWeight())));

		if (compareSpeedLhs <= compareSpeedRhs)
		{
			return static_cast<unsigned int>(compareSpeedRhs);
		}
		else
		{
			return static_cast<unsigned int>(compareSpeedLhs);
		}
	}
}