#pragma once;

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
	}
	else
	{
		T maxNumber, minNumber;
		if (number > max)
		{
			maxNumber = 2 * number - max;
			max = number;
			maxStack.push(maxNumber);
		}
		else
		{
			maxStack.push(number);
		}

		if (number < min)
		{
			minNumber = 2 * number - min;
			min = number;
			minStack.push(minNumber);
		}
		else
		{
			minStack.push(number);
		}
	}

	smartStack.push(number);
	count++;
	sum += number;
	squaredSum += number * number;
}

template<typename T>
inline T SmartStack<T>::Pop()
{
	T top = smartStack.top();
	T maxTop = maxStack.top();
	T minTop = minStack.top();

	if (maxTop > max)
	{
		std::cout << "maxTop is : " << maxTop << std::endl;
		std::cout << "max is : " << max << std::endl;

		max = 2 * max - maxTop;
	}

	if (minTop < min)
	{
		min = 2 * min - minTop;
	}

	maxStack.pop();
	minStack.pop();
	smartStack.pop();
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
	return max;
}

template<typename T>
inline T SmartStack<T>::GetMin()
{
	return min;
}

template<typename T>
inline double SmartStack<T>::GetAverage()
{
	return static_cast<T>(sum / count);
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
	double squaredAverage = average * average;
	double meanSquaredSum = static_cast<double>(squaredSum / (double)count);
	
	return squaredAverage - meanSquaredSum;
}

template<typename T>
inline double SmartStack<T>::GetStandardDeviation()
{
	double variance = GetVariance();

	return sqrt(variance);
}

template<typename T>
inline unsigned int SmartStack<T>::GetCount()
{
	return count;
}

