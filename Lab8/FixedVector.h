#pragma once

namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		FixedVector(const FixedVector<T, N>& rhs);
		FixedVector<T, N>& operator=(const FixedVector<T, N>& rhs);
		~FixedVector();

		bool Add(const T& t);
		bool Remove(const T& t);
		const T& Get(unsigned int index);
		T& operator[](unsigned int index);
		int GetIndex(const T& t);
		size_t GetSize();
		size_t GetCapacity();
	private:
		T mArray[N];
		size_t mSize;
	};

	template<typename T, size_t N>
	inline FixedVector<T, N>::FixedVector()
		: mSize(0)
	{
	}

	template<typename T, size_t N>
	inline FixedVector<T, N>::FixedVector(const FixedVector<T, N>& rhs)
		: mSize(rhs.mSize)
	{
		for (size_t i = 0; i < N; i++)
		{
			mArray[i] = rhs.mArray[i];
		}
	}

	template<typename T, size_t N>
	inline FixedVector<T, N>& FixedVector<T, N>::operator=(const FixedVector<T, N>& rhs)
	{
		if (&rhs != this)
		{
			mSize = rhs.mSize;
			for (size_t i = 0; i < N; i++)
			{
				mArray[i] = rhs.mArray[i];
			}
		}

		return *this;
	}

	template<typename T, size_t N>
	inline FixedVector<T, N>::~FixedVector<T, N>()
	{
	}

	template<typename T, size_t N>
	inline bool FixedVector<T, N>::Add(const T& t)
	{
		if (mSize >= N)
		{
			return false;
		}

		mArray[mSize++] = t;
		return true;
	}

	template<typename T, size_t N>
	inline bool FixedVector<T, N>::Remove(const T& t)
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

		for (unsigned int i = static_cast<size_t>(index); i < mSize - 1; i++)
		{
			mArray[i] = mArray[i + 1];
		}
		mSize--;

		return true;
	}

	template<typename T, size_t N>
	inline const T& FixedVector<T, N>::Get(unsigned int index)
	{
		return mArray[index];
	}

	template<typename T, size_t N>
	inline T& FixedVector<T, N>::operator[](unsigned int index)
	{
		return mArray[index];
	}

	template<typename T, size_t N>
	inline int FixedVector<T, N>::GetIndex(const T& t)
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			if (mArray[i] == t)
			{
				return static_cast<int>(i);
			}
		}
		return -1;
	}

	template<typename T, size_t N>
	inline size_t FixedVector<T, N>::GetSize()
	{
		return mSize;
	}

	template<typename T, size_t N>
	inline size_t FixedVector<T, N>::GetCapacity()
	{
		return N;
	}
}
