#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(const Storage<T>& rhs);
		Storage(Storage<T>&& rhs);
		Storage<T>& operator=(const Storage<T>& rhs);
		Storage<T>& operator=(const Storage<T>&& rhs);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;
	private:
		std::unique_ptr<T[]> mList = nullptr;
		unsigned int mSize;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mList(new T[length])
		, mSize(length)
	{
		for (unsigned int i = 0; i < length; i++)
		{
			mList[i] = 0;
		}
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mList(new T[length])
		, mSize(length)
	{
		for (unsigned int i = 0; i < length; i++)
		{
			mList[i] = initialValue;
		}
	}

	template<typename T>
	inline Storage<T>::Storage(const Storage<T>& rhs)
		: mSize(rhs.mSize)
		, mList(new T[mSize])
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			mList[i] = rhs.mList[i];
		}
	}

	template<typename T>
	inline Storage<T>::Storage(Storage<T>&& rhs)
	{
		mSize = rhs.mSize;
		mList = std::move(rhs.mList);
		rhs.mList = nullptr;
		rhs.mSize = 0;
	}

	
	template<typename T>
	inline Storage<T>& Storage<T>::operator=(const Storage<T>& rhs)
	{
		if (this != &rhs)
		{
			mSize = rhs.mSize;
			for (unsigned int i = 0; i < mSize; i++)
			{
				mList[i] = rhs.mList[i];
			}
		}
		return this;
	}

	template<typename T>
	inline Storage<T>& Storage<T>::operator=(const Storage<T>&& rhs)
	{
		if (this != &rhs)
		{
			mList = std::move(rhs.mList);
			mSize = rhs.mSize;
			rhs.mList = nullptr;
			rhs.mSize = 0;
		}
		return this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index >= mSize)
		{
			return false;
		}

		mList[index] = data;

		return true;
	}


	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		//std::unique_ptr<T[]> temp = std::make_unique<T[]>(mList);
		return std::move(mList);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mSize;
	}
}