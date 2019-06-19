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
		SmartStack<T> mFront;
		SmartStack<T> mBack;
		T mMax;
		T mMin;
		unsigned int mCount;
	};

	template<typename T>
	inline SmartQueue<T>::SmartQueue()
		: mCount(0),
		  mMax(std::numeric_limits<T>::min()),
		  mMin(std::numeric_limits<T>::max())
	{
	}

	template<typename T>
	inline void SmartQueue<T>::Enqueue(T number)
	{
		mBack.Push(number);
		mCount++;
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
		T sum = mFront.GetSum() + mBack.GetSum();
		double average = static_cast<double>(sum / mCount);
		average = average * 1000 + 0.5;
		unsigned int intValue = static_cast<unsigned int>(average);

		return static_cast<double>(intValue) / 1000.0;
	}

	template<typename T>
	inline T SmartQueue<T>::GetSum()
	{
		return mFront.GetSum() + mBack.GetSum();
	}

	template<typename T>
	inline double SmartQueue<T>::GetVariance()
	{
		T sum = mFront.GetSum() + mBack.GetSum();
		double average = static_cast<double>(sum / mCount);
		double squaredMean = average * average;

		T squaredSum = mFront.GetSquaredSum() + mBack.GetSquaredSum();
		double variance = static_cast<double>(squaredSum / static_cast<double>(mCount)) - squaredMean;
		variance = variance * 1000 + 0.5;
		unsigned int intValue = static_cast<unsigned int>(variance);
		return static_cast<double>(intValue) / 1000.0;
	}

	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation()
	{
		T sum = mFront.GetSum() + mBack.GetSum();
		double average = static_cast<double>(sum / mCount);
		double squaredMean = average * average;

		T squaredSum = mFront.GetSquaredSum() + mBack.GetSquaredSum();
		double variance = static_cast<double>(squaredSum / static_cast<double>(mCount)) - squaredMean;

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