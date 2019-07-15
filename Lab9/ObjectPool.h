#pragma once

#include <queue>
namespace lab9
{
	template<typename T>
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize);
		ObjectPool(const ObjectPool& rhs) = delete;
		bool operator=(const ObjectPool& rhs) = delete;
		~ObjectPool();

		T* Get();
		void Return(T* pointer);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();
	private:
		std::queue<T*> mPool;
		size_t mMaxPoolSize;
		size_t mCurrentPoolSize;
	};


	template<typename T>
	inline ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
	{
	}
	template<typename T>
	inline ObjectPool<T>::~ObjectPool()
	{
		while (mPool.empty() == false)
		{
			T* tmp = mPool.front();
			mPool.pop();
			delete tmp;
		}
	}
	template<typename T>
	inline T* ObjectPool<T>::Get()
	{
		if (mPool.size() == 0)
		{
			return new T();
		}
		T* tmp = mPool.front();
		mPool.pop();
		return tmp;
	}

	template<typename T>
	inline void ObjectPool<T>::Return(T* pointer)
	{
		if (mPool.size() == mMaxPoolSize)
		{
			delete pointer;
			return;
		}

		mPool.push(pointer);
	}

	template<typename T>
	inline size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return static_cast<size_t>(mPool.size());
	}

	template<typename T>
	inline size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxPoolSize;
	}
}