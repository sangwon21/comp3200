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
	float b = static_cast<float>(static_cast<double>(3.4f + 1.2f + 4.6f + 3.32f + 10.2f + 1.1f + -5.9f + 1.1f + -12.4f + 9.2f));
	float c = static_cast<float>(static_cast<double>(9.2f + -12.4f + 1.1f + -5.9f + 1.1f + 10.2f + 3.32f + 4.6f + 1.2f + 3.4f));
	SmartStack<float> ss;
	
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
	assert(ss.GetAverage() == 1.582);
	assert(ss.GetVariance() == 39.983);
	assert(ss.GetStandardDeviation() == 6.323);
	assert(ss.Peek() == 9.2f);

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

	cout << ss.GetCount() << endl;
	cout << ss.GetSum() << endl;

	ss.Push(1.0f);

	cout << ss.GetSum() << endl;
	cout << ss.GetAverage() << endl;

	ss.Pop();

	ss.Push(2.5f);
	ss.Push(3.1f);

	SmartQueue<float> sw;

	sw.Enqueue(9.2f);
	sw.Enqueue(-12.4f);
	sw.Enqueue(1.1f);
	sw.Enqueue(-5.9f);
	sw.Enqueue(1.1f);
	sw.Enqueue(10.2f);
	sw.Enqueue(3.32f);
	sw.Enqueue(4.6f);
	sw.Enqueue(1.2f);
	sw.Enqueue(3.4f);

	assert(sw.GetCount() == 10U);
	assert(sw.Peek() == 3.4f);
	assert(sw.GetMax() == 10.2f);
	assert(sw.GetMin() == -12.4f);
	cout << sw.GetSum() << endl;
	cout << 15.8200026f << endl;
	assert(sw.GetSum() == 15.8200026f);
	assert(sw.GetAverage() == 1.582);
	assert(sw.GetVariance() == 39.983);
	assert(sw.GetStandardDeviation() == 6.323);
	//	assert(sw.Peek() == 9.2f);

	cin.get();
	return 0;
}

