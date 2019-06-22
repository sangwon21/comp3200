#pragma once

#include <stack>
#include <limits>
#include <cmath>

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
		double GetSquaredSum();
	private:
		std::stack<T> mSmartStack;
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;
		T mSum;
		double mSquaredSum;
	};

	template<typename T>
	inline SmartStack<T>::SmartStack()
		: mSum(static_cast<T>(0))
		, mSquaredSum(static_cast<T>(0))
	{
	}

	template<typename T>
	inline void SmartStack<T>::Push(T number)
	{
		if (mSmartStack.empty() == true)
		{
			mSmartStack.push(number);
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
			mSmartStack.push(number);
		}
		mSum += number;
		mSquaredSum += pow(static_cast<double>(number), 2);
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		T top = mSmartStack.top();
		mSmartStack.pop();

		if (mSmartStack.empty() == true)
		{
			mMaxStack.pop();
			mMinStack.pop();
		}
		else if (top == mMaxStack.top())
		{
			mMaxStack.pop();
		}
		else if (top == mMinStack.top())
		{
			mMinStack.pop();
		}

		mSum -= top;
		mSquaredSum -= top * top;
		if (mSmartStack.empty() == true)
		{
			mSum = static_cast<T>(0);
			mSquaredSum = static_cast<T>(0);
		}
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
		double average = static_cast<double>(mSum) / mSmartStack.size();
		average = round(average * 1000) / 1000.0;

		return average;
	}

	template<typename T>
	inline T SmartStack<T>::GetSum()
	{
		if (mSmartStack.empty() == true)
		{
			return static_cast<T>(0);
		}

		return mSum;
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance()
	{
		double average = static_cast<double>(mSum) / mSmartStack.size();
		double squaredMean = pow(average, 2);

		double variance = mSquaredSum / mSmartStack.size() - squaredMean;
		variance = round(variance * 1000) / 1000.0;

		return variance;
	}

	template<typename T>
	inline double SmartStack<T>::GetStandardDeviation()
	{
		double average = static_cast<double>(mSum) / mSmartStack.size();
		double squaredMean = pow(average, 2);

		double variance = mSquaredSum / mSmartStack.size() - squaredMean;
		double standardDeviation = sqrt(variance);
		standardDeviation = round(standardDeviation * 1000) / 1000.0;

		return standardDeviation;
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
	inline double SmartStack<T>::GetSquaredSum()
	{
		if (mSmartStack.empty() == true)
		{
			return static_cast<double>(0);
		}
		return mSquaredSum;
	}
}