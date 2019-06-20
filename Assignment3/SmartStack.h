#pragma once

#include <stack>
#include <limits>
#include <cmath>
#include "Data.h"

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();

		void Push(T number);
		T Pop();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();

		bool IsEmpty();
		T GetSquaredSum();
	private:
		std::stack<Data<T>> mSmartStack;
		unsigned int mCount;
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
		: mCount(static_cast<unsigned int>(0))
	{
	}

	template<typename T>
	inline void SmartStack<T>::Push(T number)
	{
		if (mCount == static_cast<unsigned int>(0))
		{
			mSmartStack.push(Data<T>(number));
		}
		else
		{
			Data<T> topData = mSmartStack.top();
			Data<T> newData = topData.AddNumber(number);
			mSmartStack.push(newData);
		}
		mCount++;
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		Data<T> top = mSmartStack.top();
		mSmartStack.pop();

		mCount--;

		return top.GetValue();
	}

	template<typename T>
	inline T SmartStack<T>::Peek()
	{
		return mSmartStack.top().GetValue();
	}

	template<typename T>
	inline T SmartStack<T>::GetMax()
	{
		if (mCount == static_cast<unsigned int>(0))
		{
			return std::numeric_limits<T>::min();
		}
		return mSmartStack.top().GetMax();
	}

	template<typename T>
	inline T SmartStack<T>::GetMin()
	{
		if (mCount == static_cast<unsigned int>(0))
		{
			return std::numeric_limits<T>::max();
		}
		return mSmartStack.top().GetMin();
	}

	template<typename T>
	inline double SmartStack<T>::GetAverage()
	{
		double average = static_cast<double>(mSmartStack.top().GetSum()) / mCount;
		average += 0.0005;
		average = average * 1000;
		long long longAverage = static_cast<long long>(average);

		average = static_cast<double>(longAverage);
		return average / 1000.0;
	}

	template<typename T>
	inline T SmartStack<T>::GetSum()
	{
		if (mCount == static_cast<unsigned int>(0))
		{
			return static_cast<T>(0);
		}
		return mSmartStack.top().GetSum();
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance()
	{
		double average = static_cast<double>(mSmartStack.top().GetSum()) / mCount;
		double squaredMean = average * average;

		double variance = static_cast<double>(mSmartStack.top().GetSquaredSum()) / mCount - squaredMean;

		variance += 0.0005;
		variance = variance * 1000;
		long long longVariance = static_cast<long long>(variance);

		variance = static_cast<double>(longVariance);
		return variance / 1000.0;
	}

	template<typename T>
	inline double SmartStack<T>::GetStandardDeviation()
	{
		double average = static_cast<double>(mSmartStack.top().GetSum()) / mCount;
		double squaredMean = average * average;

		double variance = static_cast<double>(mSmartStack.top().GetSquaredSum()) / mCount - squaredMean;

		double standardDeviation = sqrt(variance);
		standardDeviation += 0.0005;
		standardDeviation = standardDeviation * 1000;
		long long longStandardDeviation = static_cast<long long>(standardDeviation);

		standardDeviation = static_cast<double>(longStandardDeviation);
		return standardDeviation / 1000.0;
	}

	template<typename T>
	inline unsigned int SmartStack<T>::GetCount()
	{
		return mCount;
	}

	template<typename T>
	inline bool SmartStack<T>::IsEmpty()
	{
		return mCount == static_cast<unsigned int>(0);
	}

	template<typename T>
	inline T SmartStack<T>::GetSquaredSum()
	{
		if (mCount == static_cast<unsigned int>(0))
		{
			return static_cast<T>(0);
		}
		return mSmartStack.top().GetSquaredSum();
	}
}
