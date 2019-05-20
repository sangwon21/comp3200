#include "Timesheet.h"
#include <cmath>

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mTime(nullptr),
		  mIndex(0),
		  mMaxEntries(maxEntries)
	{
		if (name == nullptr)
		{
			mName = "";
		}
		else
		{
			mName = name;
		}
		mTime = new int[maxEntries];
	}

	TimeSheet::TimeSheet(const TimeSheet& rhs)
		: mName(rhs.mName),
		  mIndex(rhs.mIndex),
		  mMaxEntries(rhs.mMaxEntries)
	{
		mTime = new int[mMaxEntries];

		for (unsigned int i = 0; i < mIndex; i++)
		{
			mTime[i] = rhs.mTime[i];
		}
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& rhs)
	{
		if (&rhs != this)
		{
			this->mName = rhs.mName;
			this->mIndex = rhs.mIndex;
			this->mMaxEntries = rhs.mMaxEntries;

			delete[] mTime;
			mTime = new int[mMaxEntries];

			for (unsigned int i = 0; i < mIndex; i++)
			{
				mTime[i] = rhs.mTime[i];
			}
		}
		return *this;
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mTime;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours < 1 || timeInHours > 10 || mIndex >= mMaxEntries)
		{
			return;
		}
		mTime[mIndex] = timeInHours;
		mIndex++;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index >= mIndex)
		{
			return -1;
		}

		return mTime[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		int sum = 0;
		for (unsigned int i = 0; i < mIndex; i++)
		{
			sum += mTime[i];
		}
		return sum;
	}

	float TimeSheet::GetAverageTime() const
	{
		return (float)GetTotalTime() / mIndex;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float sum = 0.0f;
		float average = GetAverageTime();
		for (unsigned int i = 0; i < mIndex; i++)
		{
			sum += (mTime[i] - average) * (mTime[i] - average);
		}
		float d = sum / mIndex;

		return sqrtf(d);
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}
}