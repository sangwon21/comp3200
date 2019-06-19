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
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;
		T mMax;
		T mMin;
		unsigned int mCount;
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
		: mCount(0),
		  mMax(std::numeric_limits<T>::min()),
		  mMin(std::numeric_limits<T>::max())
	{
	}

	template<typename T>
	inline void SmartStack<T>::Push(T number)
	{
		if (mCount == 0)
		{
			mMax = number;
			mMin = number;
			mMaxStack.push(number);
			mMinStack.push(number);
			mSmartStack.push(Data{ number, number, number * number });
		}
		else
		{
			if (number > mMax)
			{
				mMax = number;
				mMaxStack.push(number);
			}
			else if (number == mMax)
			{
				mMaxStack.push(number);
			}
			else if (number < mMin)
			{
				mMin = number;
				mMinStack.push(number);
			}
			else if (number == mMin)
			{
				mMinStack.push(number);
			}
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

		if (mCount == 1)
		{
			mMaxStack.pop();
			mMinStack.pop();
			mMax = std::numeric_limits<T>::min();
			mMin = std::numeric_limits<T>::max();
		}
		else if (top.GetValue() == mMax)
		{
			mMaxStack.pop();
			mMax = mMaxStack.top();
		}
		else if (top.GetValue() == mMin)
		{
			mMinStack.pop();
			mMin = mMinStack.top();
		}

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
		if (mCount == 0)
		{
			return std::numeric_limits<T>::min();
		}
		return mMax;
	}

	template<typename T>
	inline T SmartStack<T>::GetMin()
	{
		if (mCount == 0)
		{
			return std::numeric_limits<T>::max();
		}
		return mMin;
	}

	template<typename T>
	inline double SmartStack<T>::GetAverage()
	{
		double average = static_cast<double>(mSmartStack.top().GetSum() / mCount);
		average = average * 1000 + 0.5;
		unsigned int intValue = static_cast<unsigned int>(average);

		return static_cast<double>(intValue) / 1000.0;
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
		double average = static_cast<double>(mSmartStack.top().GetSum() / mCount);
		double squaredMean = average * average;

		double variance = static_cast<double>(mSmartStack.top().GetSquaredSum() / static_cast<double>(mCount)) - squaredMean;
		variance = variance * 1000 + 0.5;
		unsigned int intValue = static_cast<unsigned int>(variance);
		return static_cast<double>(intValue) / 1000.0;
	}

	template<typename T>
	inline double SmartStack<T>::GetStandardDeviation()
	{
		double average = static_cast<double>(mSmartStack.top().GetSum() / mCount);
		double squaredMean = average * average;

		double variance = static_cast<double>(mSmartStack.top().GetSquaredSum() / static_cast<double>(mCount)) - squaredMean;

		double standardDeviation = sqrt(variance);
		standardDeviation = standardDeviation * 1000 + 0.5;
		unsigned int intValue = static_cast<unsigned int>(standardDeviation);

		return static_cast<double>(intValue) / 1000.0;
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
			return static_cast<unsigned int>(0);
		}
		return mSmartStack.top().GetSquaredSum();
	}
}
