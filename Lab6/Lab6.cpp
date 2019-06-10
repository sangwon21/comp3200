#include "Lab6.h"
#include <cmath>

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int sum = 0;
		for (unsigned int i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}

		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return INT_MIN;
		}
		int min = v[0];

		for (unsigned int i = 1; i < v.size(); i++)
		{
			if (v[i] < min)
			{
				min = v[i];
			}
		}
		return min;
	}

	int Max(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return INT_MAX;
		}
		int max = v[0];

		for (unsigned int i = 1; i < v.size(); i++)
		{
			if (v[i] > max)
			{
				max = v[i];
			}
		}
		return max;
	}

	float Average(const std::vector<int>& v)
	{
		float sum = static_cast<float>(Sum(v));
		
		return sum / v.size();
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		return 0;
	}

	void SortDescending(std::vector<int>& v)
	{

	}

}