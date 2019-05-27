#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount),
		  mSize(0)
	{
		mPassengers = new const Person * [mMaxPassengersCount];

		for (unsigned int i = 0; i < mMaxPassengersCount; i++)
		{
			mPassengers[i] = nullptr;
		}
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < mMaxPassengersCount; i++)
		{
			if (mPassengers != nullptr)
			{
				delete mPassengers[i];
			}
		}
		
		delete[] mPassengers;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mSize >= mMaxPassengersCount || person == nullptr)
		{
			return false;
		}

		mPassengers[mSize] = person;
		mSize++;
		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (mSize < MIN_PASSENGER_NUMBER)
		{
			return false;
		}
		if (i > mSize - 1)
		{
			return false;
		}

		delete mPassengers[i];
		mPassengers = nullptr;

		for (unsigned int j = i; j < mSize; j++)
		{
			mPassengers[j] = mPassengers[j + 1];
		}

		for (unsigned int j = mSize; j < mMaxPassengersCount; j++)
		{
			if (mPassengers != nullptr)
			{
				delete mPassengers[j];
			}
		}

		mSize--;
		return true;
	}

	unsigned int Vehicle::GetSumOfWeight() const
	{
		unsigned int sumOfWeight = 0;
		
		for (unsigned int i = 0; i < mSize; i++)
		{
			sumOfWeight += mPassengers[i]->GetWeight();
		}
		return sumOfWeight;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mSize;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i > mSize - 1)
		{
			return nullptr;
		}

		return mPassengers[i];
	}
}