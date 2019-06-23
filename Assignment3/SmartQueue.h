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
		
		struct Data
		{
			T max;
			T min;
		};

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
		std::stack<Data> mNew;
		std::stack<T> mOld;
		T mOldMax;
		T mOldMin;
		T mSum;
		double mSquaredSum;
	};

	template<typename T>
	inline SmartQueue<T>::SmartQueue()
		: mOldMax(std::numeric_limits<T>::min())
		, mOldMin(std::numeric_limits<T>::max())
		, mSum(static_cast<T>(0))
		, mSquaredSum(static_cast<double>(0))
	{
	}

	template<typename T>
	inline void SmartQueue<T>::Enqueue(T number)
	{
		if (mSmartQueue.empty() == true)
		{
			mSmartQueue.push(number);
			mOld.push(number);
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
			mOld.push(number);
			mSmartQueue.push(number);
		}

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
		if (mNew.empty() == true)
		{
			T maxTop = mOld.top();
			T minTop = mOld.top();
			while (mOld.empty() == false)
			{
				T top = mOld.top();
				if (top >= maxTop && top <= minTop)
				{
					Data newData(top, top);
					mNew.push(newData);
					maxTop = top;
					minTop = top;
				}
				else if (top <= minTop)
				{
					Data newData(maxTop, top);
					mNew.push(newData);
					minTop = top;
				}
				else if (top >= maxTop)
				{
					Data newData(top, minTop);
					mNew.push(newData);
					maxTop = top;
				}
				mOld.pop();
			}
			mOldMax = std::numeric_limits<T>::min();
			mOldMin = std::numeric_limits<T>::max();
		}

		T front = mSmartQueue.front();

		mSmartQueue.pop();
		if (front == mNew.top())
		{
			mNew.pop();
		}
		else if (front == mNew.top())
		{
			mNew.pop();
		}

		mSum -= front;
		mSquaredSum -= pow(static_cast<double>(front), 2);

		return front;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMax()
	{
		if (mSmartQueue.size() == 0)
		{
			return std::numeric_limits<T>::min();
		}

		if (mNew.empty() != true && mOld.empty() != true)
		{
			return mNew.top().max > mOldMax ? mNew.top().max : mOldMax;
		}

		if (mNew.empty() != true)
		{
			return mNew.top().max;
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

		if (mNew.empty() != true && mOld.empty() != true)
		{
			return mNew.top().min < mOldMin ? mNew.top().min : mOldMin;
		}


		if (mNew.empty() != true)
		{
			return mNew.top().min;
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