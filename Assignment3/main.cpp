#include <cassert>
#include "SmartStack.h"
#include "SmartQueue.h"
#include <iostream>
#include <limits.h>

using namespace std;

int main() 
{
	SmartQueue<float> ss;

	ss.Enqueue(3.4f);
	ss.Enqueue(1.2f);
	ss.Enqueue(4.6f);
	ss.Enqueue(3.32f);
	ss.Enqueue(10.2f);
	ss.Enqueue(1.1f);
	ss.Enqueue(-5.9f);
	ss.Enqueue(1.1f);
	ss.Enqueue(-12.4f);
	ss.Enqueue(9.2f);

	assert(ss.GetCount() == 10U);
	assert(ss.Peek() == 3.4f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -12.4f);
	assert(ss.GetSum() == 15.8200026f);
	assert(ss.GetAverage() == 1.582);
	assert(ss.GetVariance() == 39.983);
	assert(ss.GetStandardDeviation() == 6.323);
//	assert(ss.Peek() == 9.2f);

	/*float popped1 = ss.Pop();
	float popped2 = ss.Pop();

	assert(popped1 == 9.2f);
	assert(popped2 == -12.4f);*/

	cin.get();
	return 0;
}