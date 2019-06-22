#include <cassert>
#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"
#include "Data.h"
#include <iostream>
#include <limits.h>
#include <cmath>

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
	b += 12.4f;
	float b1 = 3.4f + 1.2f + 4.6f + 3.32f + 10.2f + 1.1f + -5.9f + 1.1f + 9.2f;
	assert(b == b1);
	float c = 9.2f - 12.4f + 1.1f - 5.9f + 1.1f + 10.2f + 3.32f + 4.6f + 1.2f + 3.4f;
	SmartStack<float> ss;
	cout << "Max is : " << ss.GetMax() << endl;
	cout << "Min is : " << ss.GetMin() << endl;
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
	cout << av << endl;
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
	cout << "Max is : " << ss.GetMax() << endl;
	cout << "Min is : " << ss.GetMin() << endl;
	cout << "===================================================" << endl;


	ss.Push(-2.395f);
	ss.Push(-2.2542f);
	ss.Push(-1.9374f);
	ss.Push(1.2f);
	ss.Push(2.2f);
	ss.Push(5.6267487f);
	ss.Push(3.9f);
	ss.Push(2.563f);
	ss.Push(-4.32113f);
	ss.Push(-3.7812f);
	ss.Push(0.0f);
	ss.Pop();
	ss.Push(1.2357f);
	ss.Push(-2.3814565f);
	ss.Push(-3.586813f);
	ss.Push(-23.12874f);
	cout << "Count is : " << ss.GetCount() << endl;
	cout << "Average is : " << ss.GetAverage() << endl;
	cout << "Sum is : " << ss.GetSum() << endl;
	cout << "Max is : " << ss.GetMax() << endl;
	cout << "Min is : " << ss.GetMin() << endl;
	cout << "===================================================" << endl;

	
	SmartQueue<float> sq;

	sq.Enqueue(-10.2f);
	sq.Enqueue(10.2f);
	sq.Enqueue(-10.2f);
	sq.Enqueue(10.2f);
	sq.Enqueue(-10.2f);
	sq.Enqueue(10.2f);
	sq.Enqueue(10.2f);
	sq.Enqueue(10.2f);
	sq.Enqueue(10.2f);
	sq.Enqueue(10.2f);

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << sq.Dequeue() << endl;
	cout << "Max is : " << sq.GetMax() << endl;
	cout << "Min is : " << sq.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << sq.Dequeue() << endl;
	cout << "Max is : " << sq.GetMax() << endl;
	cout << "Min is : " << sq.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << sq.Dequeue() << endl;
	cout << "Max is : " << sq.GetMax() << endl;
	cout << "Min is : " << sq.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << sq.Dequeue() << endl;
	cout << "Max is : " << sq.GetMax() << endl;
	cout << "Min is : " << sq.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << sq.Dequeue() << endl;
	cout << "Max is : " << sq.GetMax() << endl;
	cout << "Min is : " << sq.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << sq.Dequeue() << endl;
	cout << "Max is : " << sq.GetMax() << endl;
	cout << "Min is : " << sq.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << sq.Dequeue() << endl;
	cout << "Max is : " << sq.GetMax() << endl;
	cout << "Min is : " << sq.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << sq.Dequeue() << endl;
	cout << "Max is : " << sq.GetMax() << endl;
	cout << "Min is : " << sq.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << sq.Dequeue() << endl;
	cout << "Max is : " << sq.GetMax() << endl;
	cout << "Min is : " << sq.GetMin() << endl;

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << sq.Dequeue() << endl;
	cout << "Max is : " << sq.GetMax() << endl;
	cout << "Min is : " << sq.GetMin() << endl;
	
	sq.Enqueue(2.3f);

	cout << "------------------------------------------" << endl;
	cout << "Popped One is  " << sq.Dequeue() << endl;
	cout << "Max is : " << sq.GetMax() << endl;
	cout << "Min is : " << sq.GetMin() << endl;

	double o = 2.4576 * 2.4576;
	double o1 = pow(2.4567, 2);

	cin.get();
	return 0;
}

