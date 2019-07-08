#include <cassert>
#include <iostream>

#include "FixedVector.h"
#include "FixedBoolVector.h"

using namespace lab8;
using namespace std;

int main()
{
	int i1 = 23;
	int i2 = 25;
	int i3 = 10;
	int i4 = -4;
	int i5 = 70;

	FixedVector<int, 33> iv;

	assert(iv.GetCapacity() == 33);

	iv.Add(i1);
	iv.Add(i2);
	iv.Add(i3);
	iv.Add(i4);

	assert(iv.GetSize() == 4);
	assert(iv.GetIndex(i2) == 1);
	assert(iv.Get(1) == i2);
	assert(iv[1] == i2);

	bool bRemoved = iv.Remove(i5);
	assert(!bRemoved);
	assert(iv.GetSize() == 4);

	bRemoved = iv.Remove(i2);
	assert(bRemoved);
	assert(iv.GetSize() == 3);
	assert(iv.GetIndex(i2) == -1);


	cin.get();
	return 0;
}