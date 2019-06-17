#include <stack>
#include <limits>

template<typename T>
class SmartStack
{
public:
	SmartStack();
	SmartStack(const SmartStack& rhs);
	~SmartStack();
	void Push(T number);
	T Pop();
	T Peek();
	T GetMax();
	T GetMin();
	double GetAverage();
	T GetSum();
	double GetVariance();
	double GetStandardDeviation();
	unsigned int GetCount();
private:
	std::stack<T> smartStack;
	T max;
	T min;
	T sum;
	T squaredSum;
	unsigned int count;
};

template<typename T>
inline SmartStack<T>::SmartStack()
	: count(0),
	  max(std::numeric_limits<T>::max()),
	  min(std::numeric_limits<T>::min()),
	  sum(static_cast<T>(0)),
	  squaredSum(static_cast<T>(0))
{
}

template<typename T>
inline void SmartStack<T>::Push(T number)
{
	smartStack.push(number);
	count++;
	sum += number;
	squaredSum += number * number;
}

template<typename T>
inline T SmartStack<T>::Pop()
{
	T top = smartStack.top();
	smartStack.pop();
	count--;
	sum -= top;
	squaredSum -= top * top;
	return top;
}

template<typename T>
inline T SmartStack<T>::Peek()
{
	return smartStack.top();
}

