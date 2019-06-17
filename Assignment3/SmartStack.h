#include <stack>

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