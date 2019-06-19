#include <cassert>
#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"
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

	QueueStack<int> qs(3);
	qs.Enqueue(1); // [ [ 1 ] ]
	qs.Enqueue(2); // [ [ 1, 2 ] ]
	qs.Enqueue(3); // [ [ 1, 2, 3 ] ]
	qs.Enqueue(4); // [ [ 1, 2, 3 ], [ 4 ] ]
	qs.Enqueue(5); // [ [ 1, 2, 3 ], [ 4, 5 ] ]

	int peeked = qs.Peek();
	cout << peeked << endl;
	int dequeued = qs.Dequeue();
	dequeued = qs.Dequeue();
	dequeued = qs.Dequeue();
	dequeued = qs.Dequeue();
	dequeued = qs.Dequeue();
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
	cin.get();
	return 0;
}

