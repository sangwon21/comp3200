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

	assert(popped1 == 9.2f);
	assert(popped2 == -12.4f);
	assert(ss.GetSum() == 3.4f);

	SmartQueue<float> sw;

	sw.Enqueue(3.4f);
	sw.Enqueue(1.2f);
	sw.Enqueue(4.6f);
	sw.Enqueue(3.32f);
	sw.Enqueue(10.2f);
	sw.Enqueue(1.1f);
	sw.Enqueue(-5.9f);
	sw.Enqueue(1.1f);
	sw.Enqueue(-12.4f);
	sw.Enqueue(9.2f);

	assert(sw.GetCount() == 10U);
	assert(sw.Peek() == 3.4f);
	assert(sw.GetMax() == 10.2f);
	assert(sw.GetMin() == -12.4f);
	assert(sw.GetSum() == 15.8200026f);
	assert(sw.GetAverage() == 1.582);
	assert(sw.GetVariance() == 39.983);
	assert(sw.GetStandardDeviation() == 6.323);
//	assert(sw.Peek() == 9.2f);

	/*float popped1 = sw.Pop();
	float popped2 = sw.Pop();

	assert(popped1 == 9.2f);
	assert(popped2 == -12.4f);*/

	QueueStack<int> qs(3);
	qs.Enqueue(1); // [ [ 1 ] ]
	qs.Enqueue(2); // [ [ 1, 2 ] ]
	qs.Enqueue(3); // [ [ 1, 2, 3 ] ]
	qs.Enqueue(4); // [ [ 1, 2, 3 ], [ 4 ] ]
	qs.Enqueue(5); // [ [ 1, 2, 3 ], [ 4, 5 ] ]

	int peeked = qs.Peek();
	cout << peeked << endl;
	int dequeued = qs.Dequeue();
	//dequeued = qs.Dequeue();
//	dequeued = qs.Dequeue();
	//dequeued = qs.Dequeue();
	//dequeued = qs.Dequeue();
	cout << dequeued << endl;
	int max1 = qs.GetMax();
	cout << max1 << endl;
	//assert(peeked == 3);
	int min = qs.GetMin(); // 1
	cout << min << endl;
	//double average = qs.GetAverage();
	//cout << average << endl;
	cout << qs.GetSum() << endl;
	cout << qs.GetCount() << endl;
	cout << qs.GetStackCount() << endl;

	QueueStack<int> qw(qs);
	QueueStack<int> qz(3);
	qs = qw;
	cin.get();
	return 0;
}

