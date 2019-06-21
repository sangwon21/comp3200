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
		std::stack<T> mSmartStack;
		std::stack<T> mSumStack;
		std::stack<T> mSquaredSumStack;
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;
		T mMax;
		T mMin;
		T mSum;
		T mSquaredSum;
		unsigned int mCount;
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
		: mCount(0)
		, mMax(std::numeric_limits<T>::min())
		, mMin(std::numeric_limits<T>::max())
		, mSum(static_cast<T>(0))
		, mSquaredSum(static_cast<T>(0))
	{
	}

	template<typename T>
	inline void SmartStack<T>::Push(T number)
	{
		if (mCount == 0)
		{
			mMax = number;
			mMin = number;
			mSmartStack.push(number);
			mSquaredSumStack.push(number * number);
			mSumStack.push(number);
			mMaxStack.push(number);
			mMinStack.push(number);
			//mSum = mSmartStack.top().GetSum();
			//mSquaredSum = mSmartStack.top().GetSquaredSum();
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
			//Data<T> topData = mSmartStack.top();
			//Data<T> newData = topData.AddNumber(number);
			mSmartStack.push(number);
			T topSum = mSumStack.top();
			mSumStack.push(number + topSum);
			T topSquaredSum = mSquaredSumStack.top();
			mSquaredSumStack.push(number * number + topSquaredSum);
			//mSum = mSmartStack.top().GetSum();
			//mSquaredSum = mSmartStack.top().GetSquaredSum();
		}
		mCount++;
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		T top = mSmartStack.top();
		mSmartStack.pop();
		mSumStack.pop();
		mSquaredSumStack.pop();
		if (mCount == 1)
		{
			mMaxStack.pop();
			mMinStack.pop();
			mMax = std::numeric_limits<T>::min();
			mMin = std::numeric_limits<T>::max();
			mSum = static_cast<T>(0);
			mSquaredSum = static_cast<T>(0);

		}
		else if (top == mMax)
		{
			mMaxStack.pop();
			mMax = mMaxStack.top();
		}
		else if (top == mMin)
		{
			mMinStack.pop();
			mMin = mMinStack.top();
		}

		mCount--;

		return top;
	}

	template<typename T>
	inline T SmartStack<T>::Peek()
	{
		return mSmartStack.top();
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
		double average = static_cast<double>(mSumStack.top()) / mCount;
		average += 0.0005;
		average = average * 1000;
		int longAverage = static_cast<int>(average);

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
		
		return mSumStack.top();
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance()
	{
		double average = static_cast<double>(mSumStack.top()) / static_cast<double>(mCount);
		double squaredMean = average * average;

		double variance = static_cast<double>(mSquaredSumStack.top()) / static_cast<double>(mCount) - squaredMean;

		variance += 0.0005;
		variance = variance * 1000;
		long long longVariance = static_cast<long long>(variance);

		variance = static_cast<double>(longVariance);
		return variance / 1000.0;
	}

	template<typename T>
	inline double SmartStack<T>::GetStandardDeviation()
	{
		double average = static_cast<double>(mSumStack.top()) / static_cast<double>(mCount);
		double squaredMean = average * average;

		double variance = static_cast<double>(mSquaredSumStack.top()) / static_cast<double>(mCount) - squaredMean;

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
		return mSquaredSum.top();
	}
}
