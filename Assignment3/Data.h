#pragma once

template<typename T>
class Data
{
public:
	Data(T value, T sum, T squaredSum);

	T GetValue();
	T GetSum();
	T GetSquaredSum();
private:
	T mValue;
	T mSum;
	T mSquardSum;
};

template<typename T>
inline Data<T>::Data(T value, T sum, T squaredSum)
	: mValue(value),
	  mSum(sum),
	  mSquardSum(squaredSum)
{
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
	return mSquardSum;
}
