#pragma once

#include <cstdint>
//#include <iostream>
//#include <bitset>
namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		FixedVector(const FixedVector<bool, N>& bRhs);
		FixedVector<bool, N>& operator=(const FixedVector<bool, N>& bRhs);
		~FixedVector();

		bool Add(const bool bT);
		bool Remove(const bool bT);
		bool Get(unsigned int index);
		bool operator[](unsigned int index);
		int GetIndex(bool bT);
		size_t GetSize();
		size_t GetCapacity();
	private:
		int32_t mArray[N / 32 + 1];
		size_t mSize;
	};

	template<size_t N>
	inline FixedVector<bool, N>::FixedVector()
		: mSize(0)
	{
	}

	template<size_t N>
	inline FixedVector<bool, N>::FixedVector(const FixedVector<bool, N>& bRhs)
		: mSize(bRhs.mSize)
	{
		for (size_t i = 0; i < (N / 32 + 1); i++)
		{
			mArray[i] = bRhs.mArray[i];
		}
	}

	template<size_t N>
	inline FixedVector<bool, N>& FixedVector<bool, N>::operator=(const FixedVector<bool, N>& bRhs)
	{
		if (&bRhs != this)
		{
			mSize = bRhs.mSize;
			for (size_t i = 0; i < (N / 32 + 1); i++)
			{
				mArray[i] = bRhs.mArray[i];
			}
		}

		return *this;
	}

	template<size_t N>
	inline FixedVector<bool, N>::~FixedVector<bool, N>()
	{
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Add(const bool bT)
	{
		if (mSize >= N)
		{
			return false;
		}

		unsigned int index = mSize / 32;

		if (bT == true)
		{
			mArray[index] |= (1 << mSize++);
		}
		else
		{
			mArray[index] &= ~(1 << mSize++);
		}

		return true;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Remove(const bool bT)
	{
		int index = GetIndex(bT);
		if (index == -1)
		{
			return false;
		}

		if (mSize == 0)
		{
			return false;
		}
		
		for (unsigned int i = index; i < mSize - 1; i++)
		{
			int32_t tmp = mArray[(i + 1) / 32] & (1 << (i + 1) % 32);
			tmp >>= ((i + 1) % 32);
			mArray[i / 32] &= ~(1 << i % 32);
			mArray[i / 32] |= (tmp << i);
			
		}

		mSize--;
		return true;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Get(unsigned int index)
	{
		return static_cast<bool>(mArray[index / 32] & (1 << (index % 32)));
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		return static_cast<bool>(mArray[index / 32] & (1 << (index % 32)));
	}

	template<size_t N>
	inline int FixedVector<bool, N>::GetIndex(bool bT)
	{
		if (bT == true)
		{
			for (unsigned int i = 0; i < mSize; i++)
			{
				if (mArray[i / 32] & (1 << (i % 32)))
				{
					return static_cast<int>(i);
				}
			}
		}
		else
		{
			for (unsigned int i = 0; i < mSize; i++)
			{
				if ((~mArray[i / 32]) & (1 << (i % 32)))
				{
					return static_cast<int>(i);
				}
			}
		}
		return -1;
	}

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetSize()
	{
		return mSize;
	}

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetCapacity()
	{
		return N;
	}
}
