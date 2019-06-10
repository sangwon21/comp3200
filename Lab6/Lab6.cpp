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
		SortDescending(v);

		int count = 0;
		int prev = v[0];
		int maxOccurrence = 0;
		int maxOccurrenceNumber = 0;

		for (int i = 1; i < v.size(); i++)
		{
			if (prev != v[i])
			{
				if (count > maxOccurrence)
				{
					maxOccurrence = count;
					maxOccurrenceNumber = prev;
				}
				count = 0;
				prev = v[i];
			}
			else
			{
				count++;
			}
		}

		return maxOccurrenceNumber;
	}

	void SortDescending(std::vector<int>& v)
	{
		for (int i = 0; i < v.size() - 1; i++)
		{
			int tmp = i;
			for (int j = i + 1; j < v.size() - 1; j++)
			{
				if (v[tmp] < v[j])
				{
					tmp = j;
				}
			}
			int swap = v[i];
			v[i] = v[tmp];
			v[tmp] = swap;
		}
	}

}