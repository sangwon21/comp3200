#pragma once

#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(unsigned int maxPassengersCount, const Person** people1, unsigned int people1Size,const Person** people2, unsigned int people2Size);
		Vehicle(const Vehicle& rhs);
		Vehicle& operator = (const Vehicle& rhs);
		virtual ~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		void CalculateTravelDistance();
		bool IsThere(const Person* person) const;
		void IncreaseTravelCounts();

		unsigned int GetSumOfWeight() const;
		const Person* GetPassenger(unsigned int i) const;
		void SetPassenger(unsigned int index, const Person* person);
		unsigned int GetPassengersCount() const;
		void SetPassengersCount(unsigned int count);
		const Person** GetPassengers();
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