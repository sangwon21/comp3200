#pragma once

#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Boat;
	class Airplane;

	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		Boatplane(unsigned int maxPassengersCount, const Person** people1, unsigned int people1Size, const Person** people2, unsigned int people2Size);
		~Boatplane();

		unsigned int GetMaxSpeed() const;
		unsigned int GetFlySpeed() const;
		unsigned int GetSailSpeed() const;
	};
}