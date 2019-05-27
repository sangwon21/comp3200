#pragma once

#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		virtual ~Vehicle();

		virtual unsigned int GetMaxSpeed() = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		unsigned int GetSumOfWeight() const;
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
	protected:
		const unsigned int MIN_PASSENGER_NUMBER = 1;
		unsigned int mMaxPassengersCount;
		unsigned int mSize;
		const Person** mPassengers;
	};
}