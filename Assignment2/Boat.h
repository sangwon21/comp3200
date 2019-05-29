#pragma once

#include "ISailable.h"
#include "Vehicle.h"
#include "Boatplane.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();
	
		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;
		Boatplane operator+(Airplane& plane);
	};
}