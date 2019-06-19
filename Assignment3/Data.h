#pragma once

template<typename T>
class Data
{
public:
	Data(T value);
	Data(T value, T sum, T squaredSum);

	Data<T> AddNumber(T number);
	T GetValue();
	T GetSum();
	T GetSquaredSum();
private:
	T mValue;
	T mSum;
	T mSquaredSum;
};

template<typename T>
inline Data<T>::Data(T value)
	: mValue(value)
	, mSum(value)
	, mSquaredSum(value* value)
{
}

template<typename T>
inline Data<T>::Data(T value, T sum, T squaredSum)
	: mValue(value)
	, mSum(sum)
	, mSquaredSum(squaredSum)
{
}

template<typename T>
inline Data<T> Data<T>::AddNumber(T number)
{
	Data newData(number, mSum + number, mSquaredSum + number * number);
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
