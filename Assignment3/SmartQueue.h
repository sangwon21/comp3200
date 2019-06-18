#pragma once


#include <limits>
#include <cmath>
#include "SmartStack.h"

template <typename T>
class SmartQueue
{
public:
	SmartQueue();
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
	SmartStack<T> front;
	SmartStack<T> back;
	T max;
	T min;
	T sum;
	T squaredSum;
	unsigned int count;
};

template<typename T>
inline SmartQueue<T>::SmartQueue()
	:count(0),
	max(std::numeric_limits<T>::min()),
	min(std::numeric_limits<T>::max()),
	sum(static_cast<T>(0)),
	squaredSum(static_cast<T>(0))
{
}

template<typename T>
inline void SmartQueue<T>::Enqueue(T number)
{
	back.Push(number);
	count++;
	sum += number;
	squaredSum += number * number;
}

template<typename T>
inline T SmartQueue<T>::Peek()
{
	if (front.IsEmpty() == true)
	{
		while (back.IsEmpty() != true)
		{
			T top = back.Pop();
			front.Push(top);
		}
	}

	return front.Peek();
}

template<typename T>
inline T SmartQueue<T>::Dequeue()
{
	if (front.IsEmpty() == true)
	{
		while (back.IsEmpty() != true)
		{
			T top = back.Pop();
			front.Push(top);
		}
	}
	T number = front.Pop();

	count--;
	sum -= number;
	squaredSum -= number * number;

	return number;
}

template<typename T>
inline T SmartQueue<T>::GetMax()
{
	if (front.IsEmpty() != true)
	{
		return front.GetMax() > back.GetMax() ? front.GetMax() : back.GetMax();
	}
	return back.GetMax();
}

template<typename T>
inline T SmartQueue<T>::GetMin()
{
	if (front.IsEmpty() != true)
	{
		return front.GetMin() < back.GetMin() ? front.GetMin() : back.GetMin();
	}
	return back.GetMin();
}

template<typename T>
inline double SmartQueue<T>::GetAverage()
{
	double average = static_cast<double>(sum / count);
	average = average * 1000 + 0.5;
	unsigned int intValue = static_cast<unsigned int>(average);

	return static_cast<double>(intValue) / 1000.0;
}

template<typename T>
inline T SmartQueue<T>::GetSum()
{
	return sum;
}

template<typename T>
inline double SmartQueue<T>::GetVariance()
{
	double average = GetAverage();
	double squaredMean = average * average;

	double variance = static_cast<double>(squaredSum / static_cast<double>(count)) - squaredMean;
	variance = variance * 1000 + 0.5;
	unsigned int intValue = static_cast<unsigned int>(variance);
	return static_cast<double>(intValue) / 1000.0;
}

template<typename T>
inline double SmartQueue<T>::GetStandardDeviation()
{
	double average = GetAverage();
	double squaredMean = average * average;

	double variance = static_cast<double>(squaredSum / static_cast<double>(count)) - squaredMean;

	double standardDeviation = sqrt(variance);
	standardDeviation = standardDeviation * 1000 + 0.5;
	unsigned int intValue = static_cast<unsigned int>(standardDeviation);

	return static_cast<double>(intValue) / 1000.0;
}

template<typename T>
inline unsigned int SmartQueue<T>::GetCount()
{
	return count;
}
