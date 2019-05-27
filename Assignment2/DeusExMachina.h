#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		bool IsThere(const Vehicle* vehicle);
		const Vehicle* GetFurthestTravelled() const;
		Vehicle* GetVehicle(unsigned int i);
	private:
		DeusExMachina();
		~DeusExMachina();
		const unsigned int MAX_VEHICLE_COUNTS = 10;
		Vehicle** mVehicles;
		unsigned int mSize;
	};
}