#pragma once

#include <limits>
#include <cmath>
#include <queue>
#include "SmartStack.h"

namespace assignment3
{
	template <typename T>
	class SmartQueue
	{
	public:
		SmartQueue<T>();

		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();

	private:
		std::queue<T> mSmartQueue;
		T mSum;
		double mSquaredSum;
	};

	template<typename T>
	inline SmartQueue<T>::SmartQueue()
		: mSum(static_cast<T>(0))
		, mSquaredSum(static_cast<double>(0))
	{
	}

	template<typename T>
	inline void SmartQueue<T>::Enqueue(T number)
	{
		mSmartQueue.push(number);
		mSum += number;
		mSquaredSum += pow(static_cast<double>(number), 2);
	}

	template<typename T>
	inline T SmartQueue<T>::Peek()
	{
		return mSmartQueue.front();
	}

	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		T front = mSmartQueue.front();
		mSmartQueue.pop();
		mSum -= front;
		mSquaredSum -= pow(static_cast<double>(front), 2);

		return front;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMax()
	{
		if (mSmartQueue.size() == 0)
		{
			return std::numeric_limits<T>::lowest();
		}

		unsigned int size = mSmartQueue.size();

		T max = mSmartQueue.front();

		for (unsigned int i = 0; i < size; i++)
		{
			T front = mSmartQueue.front();
			mSmartQueue.pop();

			if (max < front)
			{
				max = front;
			}

			mSmartQueue.push(front);
		}

		return max;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMin()
	{
		if (mSmartQueue.size() == 0)
		{
			return std::numeric_limits<T>::max();
		}
		unsigned int size = mSmartQueue.size();

		T min = mSmartQueue.front();

		for (unsigned int i = 0; i < size; i++)
		{
			T front = mSmartQueue.front();
			mSmartQueue.pop();

			if (min > front)
			{
				min = front;
			}

			mSmartQueue.push(front);
		}

		return min;
	}

	template<typename T>
	inline double SmartQueue<T>::GetAverage()
	{
		double average = static_cast<double>(mSum) / mSmartQueue.size();
		average = round(average * 1000) / 1000.0;

		return average;
	}

	template<typename T>
	inline T SmartQueue<T>::GetSum()
	{
		if (mSmartQueue.empty() == true)
		{
			return static_cast<T>(0);
		}

		return mSum;
	}

	template<typename T>
	inline double SmartQueue<T>::GetVariance()
	{
		double average = static_cast<double>(mSum) / mSmartQueue.size();
		double squaredMean = pow(average, 2);

		double variance = mSquaredSum / mSmartQueue.size() - squaredMean;
		variance = round(variance * 1000) / 1000.0;

		return variance;
	}

	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation()
	{
		double average = static_cast<double>(mSum) / mSmartQueue.size();
		double squaredMean = pow(average, 2);

		double variance = mSquaredSum / mSmartQueue.size() - squaredMean;
		double standardDeviation = sqrt(variance);
		standardDeviation = round(standardDeviation * 1000) / 1000.0;

		return standardDeviation;
	}

	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount()
	{
		return mSmartQueue.size();
	}
}