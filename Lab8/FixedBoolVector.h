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
		FixedVector(const FixedVector<bool, N>& rhs);
		FixedVector<bool, N>& operator=(const FixedVector<bool, N>& rhs);
		~FixedVector();

		bool Add(const bool t);
		bool Remove(const bool t);
		bool Get(unsigned int index);
		bool operator[](unsigned int index);
		int GetIndex(bool t);
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
	inline FixedVector<bool, N>::FixedVector(const FixedVector<bool, N>& rhs)
		: mSize(rhs.mSize)
	{
		for (size_t i = 0; i < (N / 32 + 1); i++)
		{
			mArray[i] = rhs.mArray[i];
		}
	}

	template<size_t N>
	inline FixedVector<bool, N>& FixedVector<bool, N>::operator=(const FixedVector<bool, N>& rhs)
	{
		if (&rhs != this)
		{
			mSize = rhs.mSize;
			for (size_t i = 0; i < (N / 32 + 1); i++)
			{
				mArray[i] = rhs.mArray[i];
			}
		}

		return *this;
	}

	template<size_t N>
	inline FixedVector<bool, N>::~FixedVector<bool, N>()
	{
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Add(const bool t)
	{
		if (mSize >= N)
		{
			return false;
		}

		unsigned int index = mSize / 32;

		if (t == true)
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
	inline bool FixedVector<bool, N>::Remove(const bool t)
	{
		int index = GetIndex(t);
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
			//std::cout << "1 : "<< std::bitset<8>(mArray[(i + 1) / 32]) << std::endl;
			//std::cout << "2 : "<< std::bitset<8>((1 << (i + 1) % 32)) << std::endl;
			int32_t tmp = mArray[(i + 1) / 32] & (1 << (i + 1) % 32);
			tmp >>= ((i + 1) % 32);
			//std::cout <<"3 : "<< std::bitset<8>(tmp) << std::endl;
			mArray[i / 32] &= ~(1 << i % 32);
			//std::cout << "4 : " << std::bitset<8>(mArray[i / 32]) << std::endl;
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
	inline int FixedVector<bool, N>::GetIndex(bool t)
	{
		if (t == true)
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
