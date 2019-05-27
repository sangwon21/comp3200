#pragma once

#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(const Vehicle& rhs);
		Vehicle& operator = (const Vehicle& rhs);
		virtual ~Vehicle();

		virtual unsigned int GetMaxSpeed() = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		void CalculateTravelDistance();
		bool IsThere(const Person* person) const;
		void MoveTo(Vehicle&rhs);
		void IncreaseTravelCounts();

		unsigned int GetSumOfWeight() const;
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetCurrentCounts() const;
		unsigned int GetTravelLimits() const;
		unsigned int GetTravelDistance() const;
	protected:
		const unsigned int MIN_PASSENGER_NUMBER = 1;
		const Person** mPassengers;
		unsigned int mMaxPassengersCount;
		unsigned int mSize;
		unsigned int mCurrentCounts;
		unsigned int mTravelLimits;
		unsigned int mTravelDistance;
		unsigned int mTotalLimits;
	};
}