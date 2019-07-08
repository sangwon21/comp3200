#pragma once

template<typename T, size_t N>
class FixedVector
{
public:
	FixedVector();
	FixedVector(const FixedVector<T, N>& rhs);
	FixedVector<T, N>& operator=(const FixedVector<T, N>& rhs);
	~FixedVector();

	bool Add(const T& t);
private:
	T mArray[N];
	size_t mCapacity;
	size_t mSize;
};

template<typename T, size_t N>
inline FixedVector<T, N>::FixedVector()
	: mCapacity(N)
	, mSize(0)
{
}

template<typename T, size_t N>
inline FixedVector<T, N>::FixedVector(const FixedVector<T, N>& rhs)
	: mCapacity(rhs.mCapacity)
	, mSize(rhs.mSize)
{
	for (size_t i = 0; i < mCapacity; i++)
	{
		mArray[i] = rhs.mArray[i];
	}
}

template<typename T, size_t N>
inline FixedVector<T, N>& FixedVector<T, N>::operator=(const FixedVector<T, N>& rhs)
{
	if (rhs != *this)
	{
		mCapacity = rhs.mCapacity;
		mSize = rhs.mSize;
		for (size_t i = 0; i < mCapacity; i++)
		{
			mArray[i] = rhs.mArray[i];
		}
	}

	return *this;
}

template<typename T, size_t N>
inline FixedVector<T, N>::~FixedVector<T, N>()
{
	for (size_t i = 0; i < mCapacity; i++)
	{
		delete mArray[i];
	}

	delete mArray;
}

template<typename T, size_t N>
inline bool FixedVector<T, N>::Add(const T& t)
{
	return false;
}
