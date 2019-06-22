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
		std::stack<T> mMaxNew;
		std::stack<T> mMaxOld;
		std::stack<T> mMinNew;
		std::stack<T> mMinOld;
		T mOldMax;
		T mOldMin;
		T mSum;
		T mSquaredSum;
	};

	template<typename T>
	inline SmartQueue<T>::SmartQueue()
		: mOldMax(std::numeric_limits<T>::min())
		, mOldMin(std::numeric_limits<T>::max())
		, mSum(static_cast<T>(0))
		, mSquaredSum(static_cast<T>(0))
	{
	}

	template<typename T>
	inline void SmartQueue<T>::Enqueue(T number)
	{
		if (mSmartQueue.empty() == true)
		{
			mSmartQueue.push(number);
			mMaxOld.push(number);
			mMinOld.push(number);
			mOldMin = number;
			mOldMax = number;
		}
		else
		{
			if (number > mOldMax)
			{
				mOldMax = number;
			}
			else if (number < mOldMin)
			{
				mOldMin = number;
			}
			mMinOld.push(number);
			mMaxOld.push(number);
			mSmartQueue.push(number);
		}

		mSum += number;
		mSquaredSum += number * number;
	}

	template<typename T>
	inline T SmartQueue<T>::Peek()
	{
		return mSmartQueue.front();
	}

	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		if (mMaxNew.empty() == true || mMinNew.empty() == true)
		{
			T maxTop = mMaxOld.top();
			while (mMaxOld.empty() == false)
			{
				T top = mMaxOld.top();
				if (top >= maxTop)
				{
					mMaxNew.push(top);
					maxTop = top;
				}
				mMaxOld.pop();
			}
			mOldMax = std::numeric_limits<T>::min();
			T minTop = mMinOld.top();
			while (mMinOld.empty() == false)
			{
				T top = mMinOld.top();
				if (top <= minTop)
				{
					mMinNew.push(top);
					minTop = top;
				}
				mMinOld.pop();
			}
			mOldMin = std::numeric_limits<T>::max();
		}

		T front = mSmartQueue.front();

		mSmartQueue.pop();
		if (front == mMaxNew.top())
		{
			mMaxNew.pop();
		}
		if (front == mMinNew.top())
		{
			mMinNew.pop();
		}

		mSum -= front;
		mSquaredSum -= front * front;

		return front;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMax()
	{
		if (mSmartQueue.size() == 0)
		{
			return std::numeric_limits<T>::min();
		}

		if (mMaxNew.empty() != true && mMaxOld.empty() != true)
		{
			return mMaxNew.top() > mOldMax ? mMaxNew.top() : mOldMax;
		}

		if (mMaxNew.empty() != true)
		{
			return mMaxNew.top();
		}

		return mOldMax;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMin()
	{
		if (mSmartQueue.size() == 0)
		{
			return std::numeric_limits<T>::max();
		}

		if (mMinNew.empty() != true && mMinOld.empty() != true)
		{
			return mMinNew.top() < mOldMin ? mMinNew.top() : mOldMin;
		}


		if (mMinNew.empty() != true)
		{
			return mMinNew.top();
		}

		return mOldMin;
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
		double squaredMean = pow(average, 2.0);

		double variance = static_cast<double>(mSquaredSum) / mSmartQueue.size() - squaredMean;
		variance = round(variance * 1000) / 1000.0;

		return variance;
	}

	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation()
	{
		double average = static_cast<double>(mSum) / mSmartQueue.size();
		double squaredMean = pow(average, 2.0);

		double variance = static_cast<double>(mSquaredSum) / mSmartQueue.size() - squaredMean;
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