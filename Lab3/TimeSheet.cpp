#include "Timesheet.h"

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
		return 0;
	}

	float TimeSheet::GetAverageTime() const
	{
		return 0.0f;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		return 0.0f;
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}
}