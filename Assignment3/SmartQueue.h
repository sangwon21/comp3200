#pragma once

#include <limits>
#include <cmath>
#include "SmartStack.h"

namespace assignment3
{
	template <typename T>
	class SmartQueue
	{
	public:
		SmartQueue();

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
		SmartStack<T> mFront;
		SmartStack<T> mBack;
		T mMax;
		T mMin;
		T mSum;
		T mSquaredSum;
		unsigned int mCount;
	};

	template<typename T>
	inline SmartQueue<T>::SmartQueue()
		: mCount(0),
		mMax(std::numeric_limits<T>::min()),
		mMin(std::numeric_limits<T>::max()),
		mSum(static_cast<T>(0)),
		mSquaredSum(static_cast<T>(0))
	{
	}

	template<typename T>
	inline void SmartQueue<T>::Enqueue(T number)
	{
		mBack.Push(number);
		mCount++;
		mSum += number;
		mSquaredSum += number * number;
	}

	template<typename T>
	inline T SmartQueue<T>::Peek()
	{
		if (mFront.IsEmpty() == true)
		{
			while (mBack.IsEmpty() != true)
			{
				T top = mBack.Pop();
				mFront.Push(top);
			}
		}

		return mFront.Peek();
	}

	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		if (mFront.IsEmpty() == true)
		{
			while (mBack.IsEmpty() != true)
			{
				T top = mBack.Pop();
				mFront.Push(top);
			}
		}
		T number = mFront.Pop();

		mCount--;
		mSum -= number;
		mSquaredSum -= number * number;

		return number;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMax()
	{
		if (mCount == 0)
		{
			return std::numeric_limits<T>::min();
		}

		if (mFront.IsEmpty() != true)
		{
			return mFront.GetMax() > mBack.GetMax() ? mFront.GetMax() : mBack.GetMax();
		}
		return mBack.GetMax();
	}

	template<typename T>
	inline T SmartQueue<T>::GetMin()
	{
		if (mCount == 0)
		{
			return std::numeric_limits<T>::max();
		}

		if (mFront.IsEmpty() != true)
		{
			return mFront.GetMin() < mBack.GetMin() ? mFront.GetMin() : mBack.GetMin();
		}
		return mBack.GetMin();
	}

	template<typename T>
	inline double SmartQueue<T>::GetAverage()
	{
		double average = static_cast<double>(mSum / mCount);
		average = average * 1000 + 0.5;
		unsigned int intValue = static_cast<unsigned int>(average);

		return static_cast<double>(intValue) / 1000.0;
	}

	template<typename T>
	inline T SmartQueue<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	inline double SmartQueue<T>::GetVariance()
	{
		double average = GetAverage();
		double squaredMean = average * average;

		double variance = static_cast<double>(mSquaredSum / static_cast<double>(mCount)) - squaredMean;
		variance = variance * 1000 + 0.5;
		unsigned int intValue = static_cast<unsigned int>(variance);
		return static_cast<double>(intValue) / 1000.0;
	}

	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation()
	{
		double average = GetAverage();
		double squaredMean = average * average;

		double variance = static_cast<double>(mSquaredSum / static_cast<double>(mCount)) - squaredMean;

		double standardDeviation = sqrt(variance);
		standardDeviation = standardDeviation * 1000 + 0.5;
		unsigned int intValue = static_cast<unsigned int>(standardDeviation);

		return static_cast<double>(intValue) / 1000.0;
	}

	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount()
	{
		return mCount;
	}
}