#include "Sedan.h"
#include "Trailer.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4),
		  mTrailer(nullptr)
	{
		this->mTravelLimits = 5;
		this->mTotalLimits = 6;
	}

	Sedan::~Sedan()
	{
		delete mTrailer;
		mTrailer = nullptr;
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mTrailer != nullptr)
		{
			return false;
		}

		this->mTravelLimits = 5;
		this->mTotalLimits = 7;

		mTrailer = trailer;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer == nullptr)
		{
			return false;
		}
		delete mTrailer;
		mTrailer = nullptr;

		this->mTravelLimits = 5;
		this->mTotalLimits = 6;

		return true;
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int sumOfWeight = this->GetSumOfWeight();
		if (mTrailer != nullptr)
		{
			sumOfWeight += mTrailer->GetWeight();
		}
		unsigned int driveSpeed = 0;

		if (sumOfWeight > 350)
		{
			driveSpeed = 300;
		}
		else if (sumOfWeight > 260)
		{
			driveSpeed = 380;
		}
		else if (sumOfWeight > 160)
		{
			driveSpeed = 400;
		}
		else if (sumOfWeight > 80)
		{
			driveSpeed = 458;
		}
		else if (sumOfWeight <= 80)
		{
			driveSpeed = 480;
		}
		
		return driveSpeed;
	}
}