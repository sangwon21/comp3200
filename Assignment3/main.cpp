#include <cassert>
#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"
#include <iostream>
#include <limits.h>

using namespace std;
using namespace assignment3;

int main() 
{

	float a = static_cast<float>(static_cast<double>(3.4f) + static_cast<double>(1.2f) + static_cast<double>(4.6f) +
		static_cast<double>(3.32f) + static_cast<double>(10.2f) + static_cast<double>(1.1f) +
		static_cast<double>(-5.9f) + static_cast<double>(1.1f) + static_cast<double>(-12.4f) +
		static_cast<double>(9.2f));

	float d = static_cast<float>(static_cast<double>(9.2f) + static_cast<double>(-12.4f) + static_cast<double>(1.1f) + static_cast<double>(-5.9f)
		+ static_cast<double>(1.1f) + static_cast<double>(10.2f) + static_cast<double>(3.32f) + static_cast<double>(4.6f) +
		static_cast<double>(1.2f) + static_cast<double>(3.4f));
	float b = 3.4f + 1.2f + 4.6f + 3.32f + 10.2f + 1.1f + -5.9f + 1.1f + -12.4f + 9.2f;
	float c = 9.2f - 12.4f + 1.1f - 5.9f + 1.1f + 10.2f + 3.32f + 4.6f + 1.2f + 3.4f;
	SmartStack<float> ss;
	
	float er = 1.1f + 2.6f + 3.7f;
	float qwe = 2.6f + 1.1f - 1.1f;
	ss.Push(3.4f);
	ss.Push(1.2f);
	ss.Push(4.6f);
	ss.Push(3.32f);
	ss.Push(10.2f);
	ss.Push(1.1f);
	ss.Push(-5.9f);
	ss.Push(1.1f);
	ss.Push(-12.4f);
	ss.Push(9.2f);

	assert(ss.GetCount() == 10U);
	assert(ss.Peek() == 9.2f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -12.4f);
	cout << ss.GetSum() << endl;
	assert(ss.GetSum() == 15.8200026f);
	double av = ss.GetAverage();
	assert(ss.GetAverage() == 1.582);
	assert(ss.GetVariance() == 39.983);
	assert(ss.GetStandardDeviation() == 6.323);
	assert(ss.Peek() == 9.2f);
	assert(!ss.IsEmpty());

	float popped1 = ss.Pop();
	float popped2 = ss.Pop();
	ss.Pop();
	ss.Pop();
	ss.Pop();
	ss.Pop();
	ss.Pop();
	ss.Pop();
	ss.Pop();
	ss.Pop();
	assert(ss.IsEmpty());
	cout << ss.GetCount() << endl;
	cout << ss.GetSum() << endl;

	ss.Push(1.0f);

	SmartStack<int> s;
	s.Push(6);
	s.Push(5);
	s.Push(-2); // [ 6, 5, -2 ]

	double average = s.GetAverage(); // 3.000

	assert(average == 3.000);
	double variance = s.GetVariance();
	assert(variance == 12.667);
	double standardDeviation = s.GetStandardDeviation(); // 3.559
	assert(standardDeviation == 3.559);

	double test = 3.4125 + 1.23124 - 2.3812 + 4.1293 + 1.23845 - 12.24845
		-3.4125 - 1.23124 + 2.3812 - 4.1293 - 1.23845 + 12.24845;
	double test2 = 3.4125 + 1.23124 - 2.3812 + 4.1293 + 1.23845 - 12.24845
		- 3.4125 - 1.23124 + 2.3812 - 4.1293 - 1.23845;
	test2 = test2 * 1000 + 0.5;
	unsigned int intValue = static_cast<unsigned int>(test2);
	double test1 = static_cast<double>(intValue) / 1000.0;

	SmartStack<double> ds;
	ds.Push(3.45);
	ds.Push(1.23);
	ds.Push(-2.38);
	ds.Push(4.12);
	ds.Push(1.23);
	ds.Push(-12.24);
	ds.Push(-3.45);
	ds.Push(-1.23);
	ds.Push(2.38);
	ds.Push(-4.12);
	ds.Push(12.24);
	ds.Push(-1.23);

	//assert(test1 == ds.GetAverage());
	double curious1 = ds.GetSum();
	double curious = ds.GetAverage();
	cout << "curious1 : " << curious1 << endl;
	cout << curious << endl;
	double test5 = -12.242 / 11.0;
	cout << -12.242 / 11.0 << endl;
	double test10 = std::numeric_limits<double>::epsilon();
	cout << (test10 < 0.0079999999999995630) << endl;

	SmartStack<int> ai;
	ai.Push(175);
	ai.Push(177);
	ai.Push(179);
	ai.Push(181);
	ai.Push(183);

	double l = 3.000;
	cout << 3.000 << endl;
	cout << ai.GetAverage() << endl;
	assert(ai.GetAverage() == 179.000);
	double k = ai.GetVariance();
	cout << k << endl;
	cout << ai.GetStandardDeviation() << endl;

	double newSum = -2.3454;

	newSum += 0.0005;
	newSum = newSum * 1000;
	long long newLongSum = static_cast<long long>(newSum);
	cout << newLongSum << endl;
	cout << static_cast<double>(newLongSum) / 1000.0 << endl;

	SmartQueue<int> iq;
	iq.Enqueue(4);
	iq.Enqueue(1);
	iq.Enqueue(1);
	iq.Enqueue(1);
	cout << "-----------------------------------------------------------" << endl;
	cout << iq.GetMax() << endl;
	cout << iq.GetMin() << endl;

	iq.Peek();
	iq.Dequeue();
	iq.Dequeue();
	iq.Dequeue();
	iq.Dequeue();

	cout << iq.GetMax() << endl;
	cout << iq.GetMin() << endl;

	cin.get();
	return 0;
}

