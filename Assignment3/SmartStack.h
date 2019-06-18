#pragma once

#include <stack>
#include <limits>
#include <cmath>
#include <iostream>

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
private:
	std::stack<T> smartStack;
	std::stack<T> maxStack;
	std::stack<T> minStack;
	T max;
	T min;
	T sum;
	T squaredSum;
	unsigned int count;
};

template<typename T>
inline SmartStack<T>::SmartStack()
	: count(0),
	max(std::numeric_limits<T>::min()),
	min(std::numeric_limits<T>::max()),
	sum(static_cast<T>(0)),
	squaredSum(static_cast<T>(0))
{
}

template<typename T>
inline void SmartStack<T>::Push(T number)
{
	if (count == 0)
	{
		max = number;
		min = number;
		maxStack.push(number);
		minStack.push(number);
		smartStack.push(number);
	}
	else
	{
		if (number > max)
		{
			max = number;
			maxStack.push(number);
		}
		else if (number == max)
		{
			maxStack.push(number);
		}
		else if (number < min)
		{
			min = number;
			minStack.push(number);
		}
		else if (number == min)
		{
			minStack.push(number);
		}
		smartStack.push(number);
	}

	count++;
	sum += number;
	squaredSum += number * number;
}

template<typename T>
inline T SmartStack<T>::Pop()
{
	T top = smartStack.top();
	smartStack.pop();

	if (count == 1)
	{
		maxStack.pop();
		minStack.pop();
		max = std::numeric_limits<T>::min();
		min = std::numeric_limits<T>::max();
	}
	else if (top == max)
	{
		maxStack.pop();
		max = maxStack.top();
	}
	else if (top == min)
	{
		minStack.pop();
		min = minStack.top();
	}

	count--;
	sum -= top;
	squaredSum -= top * top;

	return top;
}

template<typename T>
inline T SmartStack<T>::Peek()
{
	return smartStack.top();
}

template<typename T>
inline T SmartStack<T>::GetMax()
{
	if (count == 0)
	{
		return std::numeric_limits<T>::min();
	}
	return max;
}

template<typename T>
inline T SmartStack<T>::GetMin()
{
	if (count == 0)
	{
		return std::numeric_limits<T>::max();
	}
	return min;
}

template<typename T>
inline double SmartStack<T>::GetAverage()
{
	double average = static_cast<double>(sum / count);
	average = average * 1000 + 0.5;
	unsigned int intValue = static_cast<unsigned int>(average);

	return static_cast<double>(intValue) / 1000.0;
}

template<typename T>
inline T SmartStack<T>::GetSum()
{
	return sum;
}

template<typename T>
inline double SmartStack<T>::GetVariance()
{
	double average = GetAverage();
	double squaredMean = average * average;

	double variance = static_cast<double>(squaredSum / static_cast<double>(count)) - squaredMean;
	variance = variance * 1000 + 0.5;
	unsigned int intValue = static_cast<unsigned int>(variance);
	return static_cast<double>(intValue) / 1000.0;
}

template<typename T>
inline double SmartStack<T>::GetStandardDeviation()
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
inline unsigned int SmartStack<T>::GetCount()
{
	return count;
}

