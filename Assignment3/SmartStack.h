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
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
	{
	}

	template<typename T>
	inline void SmartStack<T>::Push(T number)
	{
		if (mSmartStack.empty() == true)
		{
			mSmartStack.push(Data<T>(number));
			mMaxStack.push(number);
			mMinStack.push(number);
		}
		else
		{
			if (number > mMaxStack.top())
			{
				mMaxStack.push(number);
			}
			else if (number == mMaxStack.top())
			{
				mMaxStack.push(number);
			}
			else if (number < mMinStack.top())
			{
				mMinStack.push(number);
			}
			else if (number == mMinStack.top())
			{
				mMinStack.push(number);
			}
			Data<T> topData = mSmartStack.top();
			Data<T> newData = topData.AddNumber(number);
			mSmartStack.push(newData);
		}
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		Data<T> top = mSmartStack.top();
		mSmartStack.pop();

		if (mSmartStack.empty() == true)
		{
			mMaxStack.pop();
			mMinStack.pop();
		}
		else if (top.GetValue() == mMaxStack.top())
		{
			mMaxStack.pop();
		}
		else if (top.GetValue() == mMinStack.top())
		{
			mMinStack.pop();
		}

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
		if (mMaxStack.empty() == true)
		{
			return std::numeric_limits<T>::min();
		}
		return mMaxStack.top();
	}

	template<typename T>
	inline T SmartStack<T>::GetMin()
	{
		if (mMinStack.empty() == true)
		{
			return std::numeric_limits<T>::max();
		}
		return mMinStack.top();
	}

	template<typename T>
	inline double SmartStack<T>::GetAverage()
	{
		double average = static_cast<double>(mSmartStack.top().GetSum()) / mSmartStack.size();
		average += 0.0005;
		average = average * 1000;
		int longAverage = static_cast<int>(average);

		average = static_cast<double>(longAverage);
		return average / 1000.0;
	}

	template<typename T>
	inline T SmartStack<T>::GetSum()
	{
		if (mSmartStack.empty() == true)
		{
			return static_cast<T>(0);
		}
		else if (std::fabs(mSmartStack.top().GetSum() - static_cast<T>(0)) < std::numeric_limits<double>::epsilon())
		{
			return static_cast<T>(0);
		}

		return mSmartStack.top().GetSum();
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance()
	{
		double average = static_cast<double>(mSmartStack.top().GetSum()) / mSmartStack.size();
		double squaredMean = average * average;

		double variance = static_cast<double>(mSmartStack.top().GetSquaredSum()) / mSmartStack.size() - squaredMean;

		variance += 0.0005;
		variance = variance * 1000;
		long long longVariance = static_cast<long long>(variance);

		variance = static_cast<double>(longVariance);
		return variance / 1000.0;
	}

	template<typename T>
	inline double SmartStack<T>::GetStandardDeviation()
	{
		double average = static_cast<double>(mSmartStack.top().GetSum()) / mSmartStack.size();
		double squaredMean = average * average;

		double variance = static_cast<double>(mSmartStack.top().GetSquaredSum()) / mSmartStack.size() - squaredMean;

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
		return mSmartStack.size();
	}

	template<typename T>
	inline bool SmartStack<T>::IsEmpty()
	{
		return mSmartStack.empty();
	}

	template<typename T>
	inline T SmartStack<T>::GetSquaredSum()
	{
		if (mSmartStack.empty() == true)
		{
			return static_cast<T>(0);
		}
		return mSmartStack.top().GetSquaredSum();
	}
}