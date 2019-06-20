#pragma once

#include <limits>

template<typename T>
class Data
{
public:
	Data(T value);
	Data(T value, T sum, T squaredSum, T max, T min);

	Data<T> AddNumber(T number);
	T GetValue();
	T GetSum();
	T GetSquaredSum();
	T GetMax();
	T GetMin();
private:
	T mValue;
	T mSum;
	T mSquaredSum;
	T mMax;
	T mMin;
};

template<typename T>
inline Data<T>::Data(T value)
	: mValue(value)
	, mSum(value)
	, mSquaredSum(value* value)
	, mMax(std::numeric_limits<T>::min())
	, mMin(std::numeric_limits<T>::max())
{
}

template<typename T>
inline Data<T>::Data(T value, T sum, T squaredSum, T max, T min)
	: mValue(value)
	, mSum(sum)
	, mSquaredSum(squaredSum)
	, mMax(max)
	, mMin(min)
{
}

template<typename T>
inline Data<T> Data<T>::AddNumber(T number)
{
	T tmpMax = mMax;
	T tmpMin = mMin;

	if (tmpMax < number)
	{
		tmpMax = number;
	}
	else if (tmpMin > number)
	{
		tmpMin = number;
	}

	Data newData(number, mSum + number, mSquaredSum + number * number, tmpMax, tmpMin);
	return newData;
}

template<typename T>
inline T Data<T>::GetValue()
{
	return mValue;
}

template<typename T>
inline T Data<T>::GetSum()
{
	return mSum;
}

template<typename T>
inline T Data<T>::GetSquaredSum()
{
	return mSquaredSum;
}

template<typename T>
inline T Data<T>::GetMax()
{
	return mMax;
}

template<typename T>
inline T Data<T>::GetMin()
{
	return mMin;
}
