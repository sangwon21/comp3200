#pragma once

#include "Vehicle.h"
#include "IDivable.h"
#include "ISailable.h"

namespace assignment2
{
	class UBoat : public Vehicle, public IDivable, public ISailable
	{
	public:
		UBoat();
		~UBoat();

		unsigned int GetMaxSpeed();
		unsigned int GetDiveSpeed();
		unsigned int GetSailSpeed();
	};
}