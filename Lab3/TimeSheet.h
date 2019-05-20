#pragma once
#include <string>
#include <vector>

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;

	private:
		std::string mName;
		int* mTime;
		unsigned int mIndex;
		unsigned int mMaxEntries;
	};
}