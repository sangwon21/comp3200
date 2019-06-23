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
		std::stack<std::pair<T, std::pair<T, T>>> mNew;
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
		if (mOld.empty() == true)
		{
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
		}

		mSum += number;
		mSquaredSum += pow(static_cast<double>(number), 2);
	}

	template<typename T>
	inline T SmartQueue<T>::Peek()
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
					mNew.push(std::make_pair(top, (std::make_pair(top, top))));
					maxTop = top;
					minTop = top;
				}
				else if (top <= minTop)
				{
					mNew.push(std::make_pair(top, (std::make_pair(maxTop, top))));
					minTop = top;
				}
				else if (top >= maxTop)
				{
					mNew.push(std::make_pair(top, (std::make_pair(top, top))));
					maxTop = top;
				}
				else
				{
					mNew.push(std::make_pair(top, (std::make_pair(maxTop, minTop))));
				}
				mOld.pop();
			}
			mOldMax = std::numeric_limits<T>::min();
			mOldMin = std::numeric_limits<T>::max();
		}
		return mNew.top().first;
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
					mNew.push(std::make_pair(top, (std::make_pair(top, top))));
					maxTop = top;
					minTop = top;
				}
				else if (top <= minTop)
				{
					mNew.push(std::make_pair(top, (std::make_pair(maxTop, top))));
					minTop = top;
				}
				else if (top >= maxTop)
				{
					mNew.push(std::make_pair(top, (std::make_pair(top, top))));
					maxTop = top;
				}
				else
				{
					mNew.push(std::make_pair(top, (std::make_pair(maxTop, minTop))));
				}
				mOld.pop();
			}
			mOldMax = std::numeric_limits<T>::min();
			mOldMin = std::numeric_limits<T>::max();
		}

		T front = mNew.top().first;

		mNew.pop();
		if (front == mNew.top().second.first)
		{
			mNew.pop();
		}
		else if (front == mNew.top().second.second)
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
		if (mNew.empty() == true && mOld.empty() == true)
		{
			return std::numeric_limits<T>::min();
		}

		if (mNew.empty() != true && mOld.empty() != true)
		{
			return mNew.top().second.first > mOldMax ? mNew.top().second.first : mOldMax;
		}

		if (mNew.empty() != true)
		{
			return mNew.top().second.first;
		}

		return mOldMax;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMin()
	{
		if (mNew.empty() == true && mOld.empty() == true)
		{
			return std::numeric_limits<T>::max();
		}

		if (mNew.empty() != true && mOld.empty() != true)
		{
			return mNew.top().second.second < mOldMin ? mNew.top().second.second : mOldMin;
		}


		if (mNew.empty() != true)
		{
			return mNew.top().second.second;
		}

		return mOldMin;
	}

	template<typename T>
	inline double SmartQueue<T>::GetAverage()
	{
		double average = static_cast<double>(mSum) / (mOld.size() + mNew.size());
		average = round(average * 1000) / 1000.0;

		return average;
	}

	template<typename T>
	inline T SmartQueue<T>::GetSum()
	{
		if (mNew.empty() == true && mOld.empty() == true)
		{
			return static_cast<T>(0);
		}

		return mSum;
	}

	template<typename T>
	inline double SmartQueue<T>::GetVariance()
	{
		double average = static_cast<double>(mSum) / (mOld.size() + mNew.size());
		double squaredMean = pow(average, 2);

		double variance = mSquaredSum / (mOld.size() + mNew.size()) - squaredMean;
		variance = round(variance * 1000) / 1000.0;

		return variance;
	}

	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation()
	{
		double average = static_cast<double>(mSum) / (mOld.size() + mNew.size());
		double squaredMean = pow(average, 2);

		double variance = mSquaredSum / (mOld.size() + mNew.size()) - squaredMean;
		double standardDeviation = sqrt(variance);
		standardDeviation = round(standardDeviation * 1000) / 1000.0;

		return standardDeviation;
	}

	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount()
	{
		return mOld.size() + mNew.size();
	}
}