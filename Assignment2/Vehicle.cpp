#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount),
		  mSize(0),
		  mCurrentCounts(0),
		  mTravelLimits(0),
		  mTravelDistance(0),
		  mTotalLimits(0)
	{
		mPassengers = new const Person * [mMaxPassengersCount];

		for (unsigned int i = 0; i < mMaxPassengersCount; i++)
		{
			mPassengers[i] = nullptr;
		}
	}

	Vehicle::Vehicle(unsigned int maxPassengersCount, const Person** people1, unsigned int people1Size ,const Person** people2, unsigned int people2Size)
		: mMaxPassengersCount(maxPassengersCount),
		  mCurrentCounts(0),
		  mSize(0),
		  mTravelLimits(0),
		  mTravelDistance(0),
		  mTotalLimits(0)
	{
		mPassengers = new const Person * [mMaxPassengersCount];

		for (unsigned int i = 0; i < people1Size; i++)
		{
			AddPassenger(people1[i]);
			people1[i] = nullptr;
		}

		for (unsigned int i = 0; i < people2Size; i++)
		{
			AddPassenger(people2[i]);
			people2[i] = nullptr;
		}

		for (unsigned int i = mSize; i < mMaxPassengersCount; i++)
		{
			mPassengers[i] = nullptr;
		}
	}

	Vehicle::Vehicle(const Vehicle& rhs)
		: mMaxPassengersCount(rhs.mMaxPassengersCount),
		  mSize(rhs.mSize),
		  mCurrentCounts(rhs.mCurrentCounts),
		  mTravelLimits(rhs.mTravelLimits),
		  mTravelDistance(rhs.mTravelDistance),
		  mTotalLimits(rhs.mTotalLimits)
	{
		mPassengers = new const Person * [mMaxPassengersCount];

		for (unsigned int i = 0; i < mSize; i++)
		{
			mPassengers[i] = new Person(rhs.mPassengers[i]->GetName().c_str(), rhs.mPassengers[i]->GetWeight());
		}

		for (unsigned int i = mSize; i < mMaxPassengersCount; i++)
		{
			mPassengers[i] = nullptr;
		}
	}

	Vehicle& Vehicle::operator=(const Vehicle& rhs)
	{
		if (&rhs != this)
		{
			for (unsigned int i = 0; i < mMaxPassengersCount; i++)
			{
				delete mPassengers[i];
			}

			delete[] mPassengers;

			mMaxPassengersCount = rhs.mMaxPassengersCount;
			mSize = rhs.mSize;
			mCurrentCounts = rhs.mCurrentCounts;
			mTravelLimits = rhs.mTravelLimits;
			mTravelDistance = rhs.mTravelDistance;
			mTotalLimits = rhs.mTotalLimits;

			mPassengers = new const Person * [mMaxPassengersCount];

			for (unsigned int i = 0; i < mSize; i++)
			{
				mPassengers[i] = new Person(rhs.mPassengers[i]->GetName().c_str(), rhs.mPassengers[i]->GetWeight());
			}

			for (unsigned int i = mSize; i < mMaxPassengersCount; i++)
			{
				mPassengers[i] = nullptr;
			}
		}

		return *this;
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < mMaxPassengersCount; i++)
		{
			delete mPassengers[i];
		}

		delete[] mPassengers;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mSize >= mMaxPassengersCount || person == nullptr)
		{
			return false;
		}

		if (IsThere(person))
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
		mPassengers[i] = nullptr;

		for (unsigned int j = i; j < mSize - 1; j++)
		{
			mPassengers[j] = mPassengers[j + 1];
		}

		for (unsigned int j = mSize - 1; j < mMaxPassengersCount; j++)
		{
			mPassengers[j] = nullptr;
		}

		mSize--;
		return true;
	}

	void Vehicle::CalculateTravelDistance()
	{
		mTravelDistance += GetMaxSpeed();
	}

	bool Vehicle::IsThere(const Person* person) const
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			if (mPassengers[i] == person)
			{
				return true;
			}
		}
		return false;
	}

	void Vehicle::IncreaseTravelCounts()
	{
		mCurrentCounts++;

		if (mCurrentCounts == mTotalLimits)
		{
			mCurrentCounts = 0;
		}
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

	void Vehicle::SetPassengersCount(unsigned int count)
	{
		mSize = count;
	}

	const Person** Vehicle::GetPassengers() 
	{
		return mPassengers;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	unsigned int Vehicle::GetCurrentCounts() const
	{
		return mCurrentCounts;
	}

	unsigned int Vehicle::GetTravelLimits() const
	{
		return mTravelLimits;
	}

	unsigned int Vehicle::GetTravelDistance() const
	{
		return mTravelDistance;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i > mSize - 1)
		{
			return nullptr;
		}

		return mPassengers[i];
	}
	void Vehicle::SetPassenger(unsigned int index, const Person* person)
	{
		mPassengers[index] = person;
	}
}