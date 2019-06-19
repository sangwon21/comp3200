#pragma once

template<typename T>
class Data
{
public:
	T GetValue();
	T GetSum();
	T GetSquaredSum();
private:
	T mValue;
	T mSum;
	T mSquardSum;
};

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
