#include "DeusExMachina.h"

namespace assignment2
{

	DeusExMachina* DeusExMachina::GetInstance()
	{
		static DeusExMachina mSingleton;
		return &mSingleton;
	}

	void DeusExMachina::Travel() const
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			unsigned int CurrentCounts = mVehicles[i]->GetCurrentCounts();
			unsigned int travelLimits = mVehicles[i]->GetTravelLimits();

			if (CurrentCounts < travelLimits)
			{
				mVehicles[i]->CalculateTravelDistance();
			}

			mVehicles[i]->IncreaseTravelCounts();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (vehicle == nullptr || mSize >= MAX_VEHICLE_COUNTS)
		{
			return false;
		}
		if (IsThere(vehicle))
		{
			return false;
		}

		mVehicles[mSize] = vehicle;
		mSize++;
		
		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mSize)
		{
			return false;
		}

		delete mVehicles[i];
		mVehicles[i] = nullptr;

		for (unsigned int j = i; j < mSize - 1; j++)
		{
			mVehicles[j] = mVehicles[j + 1];
		}

		for (unsigned int j = mSize - 1; j < MAX_VEHICLE_COUNTS; j++)
		{
			mVehicles[j] = nullptr;
		}

		mSize--;
		return true;
	}

	bool DeusExMachina::IsThere(const Vehicle* vehicle)
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			if (mVehicles[i] == vehicle)
			{
				return true;
			}
		}
		return false;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mSize == 0)
		{
			return nullptr;
		}
		unsigned int furthestIndex = 0;
		unsigned int furthestTravelled = mVehicles[0]->GetTravelDistance();

		for (unsigned int i = 1; i < mSize; i++)
		{
			unsigned int travelDistance = mVehicles[i]->GetTravelDistance();

			if (furthestTravelled < travelDistance)
			{
				furthestTravelled = travelDistance;
				furthestIndex = i;
			}
		}

		if (furthestTravelled == 0)
		{
			return mVehicles[0];
		}
		else
		{
			return mVehicles[furthestIndex];
		}
	}

	Vehicle* DeusExMachina::GetVehicle(unsigned int i)
	{
		return mVehicles[i];
	}

	DeusExMachina::DeusExMachina()
	{
		mVehicles = new Vehicle * [10];
		for (unsigned int i = 0; i < MAX_VEHICLE_COUNTS; i++)
		{
			mVehicles[i] = nullptr;
		}
		mSize = 0;
	}

	DeusExMachina::~DeusExMachina()
	{
		for (unsigned int i = 0; i < MAX_VEHICLE_COUNTS; i++)
		{
			if (mVehicles[i] != nullptr)
			{
				delete mVehicles[i];
			}
			mVehicles[i] = nullptr;
		}
		delete mVehicles;
	}

}
