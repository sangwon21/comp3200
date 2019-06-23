#pragma once

#include <queue>
#include <limits>
#include "SmartStack.h"

namespace assignment3
{
	template <typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		QueueStack(const QueueStack<T>& rhs);
		QueueStack<T>& operator=(const QueueStack<T>& rhs);
		~QueueStack();

		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();

	private:
		std::queue<std::stack<T>*> mQueueStack;
		T mSum;
		std::stack<T>* mLastStackPointer;
		unsigned int mMaxStackSize;
		unsigned int mCount;
		unsigned int mStackCount;
	};

	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mSum(static_cast<T>(0))
		, mLastStackPointer(nullptr)
		, mMaxStackSize(maxStackSize)
		, mCount(static_cast<unsigned int>(0))
		, mStackCount(static_cast<unsigned int>(0))
	{
	}

	template<typename T>
	inline QueueStack<T>::QueueStack(const QueueStack<T>& rhs)
		: mSum(rhs.mSum)
		, mMaxStackSize(rhs.mMaxStackSize)
		, mLastStackPointer(nullptr)
		, mCount(rhs.mCount)
		, mStackCount(rhs.mStackCount)
	{
		std::queue<std::stack<T>*> tmpQueue(rhs.mQueueStack);
		for (unsigned int i = 0; i < mStackCount; i++)
		{
			std::stack<T>* stackPointer = tmpQueue.front();
			std::stack<T>* newStackPointer = new std::stack<T>(*stackPointer);
			tmpQueue.pop();
			if (i == mStackCount - 1)
			{
				mLastStackPointer = newStackPointer;
			}
			mQueueStack.push(newStackPointer);
		}
	}

	template<typename T>
	inline QueueStack<T>& QueueStack<T>::operator=(const QueueStack<T>& rhs)
	{
		if (&rhs != this)
		{
			mSum = rhs.mSum;
			mMaxStackSize = rhs.mMaxStackSize;
			mCount = rhs.mCount;
			mStackCount = rhs.mStackCount;

			std::queue<std::stack<T>*> tmpQueue(rhs.mQueueStack);
			for (unsigned int i = 0; i < mStackCount; i++)
			{
				std::stack<T>* stackPointer = tmpQueue.front();
				std::stack<T>* newStackPointer = new std::stack<T>(*stackPointer);
				tmpQueue.pop();
				if (i == mStackCount - 1)
				{
					mLastStackPointer = newStackPointer;
				}
				mQueueStack.push(newStackPointer);
			}
		}

		return *this;
	}

	template<typename T>
	inline QueueStack<T>::~QueueStack()
	{
		for (unsigned int i = 0; i < mStackCount; i++)
		{
			std::stack<T>* stackPointer = mQueueStack.front();
			mQueueStack.pop();
			delete stackPointer;
		}
	}

	template<typename T>
	inline void QueueStack<T>::Enqueue(T number)
	{
		if (mCount % mMaxStackSize == 0)
		{
			std::stack<T>* newStackPointer = new std::stack<T>;
			newStackPointer->push(number);
			mLastStackPointer = newStackPointer;
			mQueueStack.push(newStackPointer);
			mStackCount++;
		}
		else
		{
			mLastStackPointer->push(number);
		}
		mSum += number;
		mCount++;
	}

	template<typename T>
	inline T QueueStack<T>::Peek()
	{
		return mQueueStack.front()->top();
	}

	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		T number = mQueueStack.front()->top();

		if (mQueueStack.front()->size() == 1)
		{
			std::stack<T>* deletedStackPointer = mQueueStack.front();
			mQueueStack.front()->pop();
			mQueueStack.pop();
			delete deletedStackPointer;
			mStackCount--;
		}
		else
		{
			mQueueStack.front()->pop();
		}

		mSum -= number;
		mCount--;
		return number;
	}

	template<typename T>
	inline T QueueStack<T>::GetMax()
	{
		if (mCount == 0)
		{
			return std::numeric_limits<T>::lowest();
		}

		T max = std::numeric_limits<T>::lowest();
		for (unsigned int i = 0; i < mStackCount; i++)
		{
			std::stack<T>* stackPointer = mQueueStack.front();
			mQueueStack.pop();

			std::queue<T> tmpQueue;
			unsigned int stackSize = stackPointer->size();
			for (unsigned int i = 0; i < stackSize; i++)
			{
				T top = stackPointer->top();
				if (top > max)
				{
					max = top;
				}
				stackPointer->pop();
				tmpQueue.push(top);
			}
			for (unsigned int i = 0; i < stackSize; i++)
			{
				T front = tmpQueue.front();
				tmpQueue.pop();
				stackPointer->push(front);
			}

			mQueueStack.push(stackPointer);
		}

		return max;
	}

	template<typename T>
	inline T QueueStack<T>::GetMin()
	{
		if (mCount == 0)
		{
			return std::numeric_limits<T>::max();
		}

		T min = std::numeric_limits<T>::max();
		for (unsigned int i = 0; i < mStackCount; i++)
		{
			std::stack<T>* stackPointer = mQueueStack.front();
			mQueueStack.pop();

			std::queue<T> tmpQueue;
			unsigned int stackSize = stackPointer->size();
			for (unsigned int i = 0; i < stackSize; i++)
			{
				T top = stackPointer->top();
				if (top < min)
				{
					min = top;
				}
				stackPointer->pop();
				tmpQueue.push(top);
			}
			for (unsigned int i = 0; i < stackSize; i++)
			{
				T front = tmpQueue.front();
				tmpQueue.pop();
				stackPointer->push(front);
			}
			mQueueStack.push(stackPointer);
		}

		return min;
	}

	template<typename T>
	inline double QueueStack<T>::GetAverage()
	{
		double average = static_cast<double>(mSum) / mCount;
		average = round(average * 1000) / 1000.0;

		return average;
	}

	template<typename T>
	inline T QueueStack<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetCount()
	{
		return mCount;
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetStackCount()
	{
		return mStackCount;
	}
}
