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
		std::queue<T> q;
		/*std::stack<T> mOld;
		std::stack<T> mNew;
		std::stack<T> mMaxNew;
		std::stack<T> mMinNew;*/
		T mOldMax;
		T mOldMin;
		T mSum;
		T mSquaredSum;
	};

	template<typename T>
	inline SmartQueue<T>::SmartQueue()
		: mOldMax(std::numeric_limits<T>::lowest())
		, mOldMin(std::numeric_limits<T>::max())
		, mSum(static_cast<T>(0))
		, mSquaredSum(static_cast<T>(0))
	{
	}

	template<typename T>
	inline void SmartQueue<T>::Enqueue(T number)
	{
		//if (mOld.empty() == true)
		//{
		//	mOld.push(number);
		//	mOldMin = number;
		//	mOldMax = number;
		//}
		//else
		//{
		//	if (number > mOldMax)
		//	{
		//		mOldMax = number;
		//	}
		//	else if (number < mOldMin)
		//	{
		//		mOldMin = number;
		//	}
		//	mOld.push(number);
		//}
		q.push(number);
		mSum += number;
		mSquaredSum += number * number;
	}

	template<typename T>
	inline T SmartQueue<T>::Peek()
	{
		/*if (mNew.empty() == true)
		{
			T maxTop = mOld.top();
			T minTop = mOld.top();
			while (mOld.empty() == false)
			{
				T top = mOld.top();
				if (top >= maxTop && top <= minTop)
				{
					mMaxNew.push(top);
					mMinNew.push(top);
					maxTop = top;
					minTop = top;
				}
				else if (top <= minTop)
				{
					mMinNew.push(top);
					minTop = top;
				}
				else if (top >= maxTop)
				{
					mMaxNew.push(top);
					maxTop = top;
				}
				mOld.pop();
			}
			mOldMax = std::numeric_limits<T>::lowest();
			mOldMin = std::numeric_limits<T>::max();
		}*/

		return q.front();
	}

	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		//if (mNew.empty() == true)
		//{
		//	T maxTop = mOld.top();
		//	T minTop = mOld.top();
		//	while (mOld.empty() == false)
		//	{
		//		T top = mOld.top();
		//		if (top >= maxTop && top <= minTop)
		//		{
		//			mMaxNew.push(top);
		//			mMinNew.push(top);
		//			maxTop = top;
		//			minTop = top;
		//		}
		//		else if (top <= minTop)
		//		{
		//			mMinNew.push(top);
		//			minTop = top;
		//		}
		//		else if (top >= maxTop)
		//		{
		//			mMaxNew.push(top);
		//			maxTop = top;
		//		}
		//		mNew.push(top);
		//		mOld.pop();
		//	}
		//	mOldMax = std::numeric_limits<T>::lowest();
		//	mOldMin = std::numeric_limits<T>::max();
		//}

		//T front = mNew.top();

		//mNew.pop();
		//if (front == mMaxNew.top())
		//{
		//	mMaxNew.pop();
		//}
		//if (front == mMinNew.top())
		//{
		//	mMinNew.pop();
		//}

		//mSum -= front;
		//mSquaredSum -= front * front;
		T front = q.front();
		q.pop();
		return front;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMax()
	{
		/*if (mNew.empty() == true && mOld.empty() == true)
		{
			return std::numeric_limits<T>::lowest();
		}

		if (mMaxNew.empty() != true && mOld.empty() != true)
		{
			return mMaxNew.top() > mOldMax ? mMaxNew.top() : mOldMax;
		}

		if (mMaxNew.empty() != true)
		{
			return mMaxNew.top();
		}*/

		return mOldMax;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMin()
	{
		/*if (mNew.empty() == true && mOld.empty() == true)
		{
			return std::numeric_limits<T>::max();
		}

		if (mMinNew.empty() != true && mOld.empty() != true)
		{
			return mMinNew.top() < mOldMin ? mMinNew.top() : mOldMin;
		}


		if (mMinNew.empty() != true)
		{
			return mMinNew.top();
		}*/

		return mOldMin;
	}

	template<typename T>
	inline double SmartQueue<T>::GetAverage()
	{
		//double average = static_cast<double>(mSum) / (mNew.size() + mOld.size());
		//average = round(average * 1000) / 1000.0;

		return 0;
	}

	template<typename T>
	inline T SmartQueue<T>::GetSum()
	{
		/*if (mNew.empty() == true && mOld.empty() == true)
		{
			return static_cast<T>(0);
		}*/

		return 0;
	}

	template<typename T>
	inline double SmartQueue<T>::GetVariance()
	{
		/*double average = static_cast<double>(mSum) / (mNew.size() + mOld.size());
		double squaredMean = pow(average, 2.0);

		double variance = static_cast<double>(mSquaredSum) / (mNew.size() + mOld.size()) - squaredMean;
		variance = round(variance * 1000) / 1000.0;*/

		return 0;
	}

	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation()
	{
		/*double average = static_cast<double>(mSum) / (mNew.size() + mOld.size());
		double squaredMean = pow(average, 2.0);

		double variance = static_cast<double>(mSquaredSum) / (mNew.size() + mOld.size()) - squaredMean;
		double standardDeviation = sqrt(variance);
		standardDeviation = round(standardDeviation * 1000) / 1000.0;*/

		return 0;
	}

	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount()
	{
		return q.size();
	}
}