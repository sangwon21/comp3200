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
		virtual unsigned int GetTravelCounts() const = 0;
		virtual unsigned int SetTravelCounts() = 0;
		virtual unsigned int GetTravelLimits() const = 0;

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
		unsigned int mTravelCounts;
		unsigned int mTravelLimits;
		const Person** mPassengers;
	};
}