#pragma once

#include "Vehicle.h"
#include "IFlyable.h"
#include "IDrivable.h"
#include "Boatplane.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		unsigned int GetMaxSpeed();
		unsigned int GetFlySpeed();
		unsigned int GetDriveSpeed();
		Boatplane operator+(Boat& boat);
	};
}