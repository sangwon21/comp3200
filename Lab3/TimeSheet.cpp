#include "Timesheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mName(nullptr),
		  mTime(nullptr),
		  mIndex(0),
		  mMaxEntries(maxEntries)
	{
		int length = GetLength(name);
		mName = new char[length];
		Strcpy(name, mName);
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
		return 0;
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
		return "temporary";
	}
	int TimeSheet::GetLength(const char* name)
	{
		int length = 0;
		if (name == nullptr)
		{
			return length;
		}
		for (; (*name) != '\0'; name++)
		{
			length++;
		}

		return length;
	}
	void TimeSheet::Strcpy(const char* src, char*& dest)
	{
		if (src == nullptr || src == "")
		{
			dest[0] = '\0';
			return;
		}

		for (int i = 0; (*src) != '\0'; src++)
		{
			dest[i] = src[i];
			i++;
		}
	}
}