#pragma once

#include <queue>
#include <limits>
#include "SmartStack.h"

template <typename T>
class QueueStack
{
public:
	QueueStack(unsigned int limit);
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
	std::queue<SmartStack<T>*> mQueueStack;
	T mMax;
	T mMin;
	T mSum;
	SmartStack<T>* mLastStackPointer;
	unsigned int mMaxStackSize;
	unsigned int mCount;
	unsigned int mStackCount;
};

template<typename T>
inline QueueStack<T>::QueueStack(unsigned int maxStackSize)
	: mMax(std::numeric_limits<T>::min()),
	mMin(std::numeric_limits<T>::max()),
	mSum(static_cast<T>(0)),
	mLastStackPointer(nullptr),
	mMaxStackSize(maxStackSize),
	mCount(static_cast<unsigned int>(0)),
	mStackCount(static_cast<unsigned int>(0))
{
}

template<typename T>
inline QueueStack<T>::QueueStack(const QueueStack<T>& rhs)
	:mMax(rhs.max),
	mMin(rhs.min),
	mSum(rhs.mSum),
	mMaxStackSize(rhs.mMaxStackSize),
	mLastStackPointer(nullptr),
	mCount(rhs.mCount),
	mStackCount(rhs.mStackCount)
{
	for (int i = 0; i < mStackCount; i++)
	{
		SmartStack<T>* stackPointer = rhs.mQueueStack.front();
		rhs.mQueueStack.pop();
		SmartStack<T>* newStackPointer = new SmartStack<T>(stackPointer);
		if (i == mStackCount - 1)
		{
			mLastStackPointer = newStackPointer;
		}
		rhs.mQueueStack.push(stackPointer);
		mQueueStack.push(newStackPointer);
	}
}

template<typename T>
inline QueueStack<T>& QueueStack<T>::operator=(const QueueStack<T>& rhs)
{
	mMax = rhs.max;
	mMin = rhs.min;
	mSum = rhs.mSum;
	mMaxStackSize = rhs.mMaxStackSize;
	mCount = rhs.mCount;
	mStackCount = rhs.mStackCount;

	for (unsigned int i = 0; i < mStackCount; i++)
	{
		SmartStack<T>* stackPointer = rhs.mQueueStack.front();
		rhs.mQueueStack.pop();
		SmartStack<T>* newStackPointer = new SmartStack<T>(stackPointer);
		if (i == mStackCount - 1)
		{
			mLastStackPointer = newStackPointer;
		}
		rhs.mQueueStack.push(stackPointer);
		mQueueStack.push(newStackPointer);
	}
}

template<typename T>
inline QueueStack<T>::~QueueStack()
{
	for (unsigned int i = 0; i < mStackCount; i++)
	{
		SmartStack<T>* stackPointer = mQueueStack.front();
		mQueueStack.pop();
		delete stackPointer;
	}
}

template<typename T>
inline void QueueStack<T>::Enqueue(T number)
{
	if (mCount % mMaxStackSize == 0)
	{
		SmartStack<T>* newStackPointer = new SmartStack<T>;
		newStackPointer->Push(number);
		mLastStackPointer = newStackPointer;
		mQueueStack.push(newStackPointer);
		mStackCount++;
	}
	else
	{
		mLastStackPointer->Push(number);
	}

	mCount++;
	mSum += number;
}

template<typename T>
inline T QueueStack<T>::Peek()
{
	return mQueueStack.front()->Peek();
}

template<typename T>
inline T QueueStack<T>::Dequeue()
{
	T number = mQueueStack.front()->Peek();

	if (mQueueStack.front()->GetCount() == 1)
	{
		SmartStack<T>* deletedStackPointer = mQueueStack.front();
		mQueueStack.front()->Pop();
		mQueueStack.pop();
		delete deletedStackPointer;
		mStackCount--;
	}
	else
	{
		mQueueStack.front()->Pop();
	}

	mCount--;
	mSum -= number;

	return number;
}

template<typename T>
inline T QueueStack<T>::GetMax()
{
	for (unsigned int i = 0; i < mStackCount; i++)
	{
		SmartStack<T>* stackPointer = mQueueStack.front();
		mQueueStack.pop();

		T number = stackPointer->GetMax();
		if (number > mMax)
		{
			mMax = number;
		}

		mQueueStack.push(stackPointer);
	}

	return mMax;
}

template<typename T>
inline T QueueStack<T>::GetMin()
{
	for (unsigned int i = 0; i < mStackCount; i++)
	{
		SmartStack<T>* stackPointer = mQueueStack.front();
		mQueueStack.pop();

		T number = stackPointer->GetMin();
		if (number < mMin)
		{
			mMin = number;
		}

		mQueueStack.push(stackPointer);
	}

	return mMin;
}

template<typename T>
inline double QueueStack<T>::GetAverage()
{
	double average = static_cast<double>(mSum / mCount);
	average = average * 1000 + 0.5;
	unsigned int intValue = static_cast<unsigned int>(average);

	return static_cast<double>(intValue) / 1000.0;
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
