#include "SmartStack.h"
#include <iostream>

int main()
{

	using namespace std;

	SmartStack<int> s;
	s.Push(1);
	s.Push(3);
	s.Push(2);
	
	cout << "max number is : " << s.GetMax() << endl;
	
	s.Push(5);

	cout << "max number is : " << s.GetMax() << endl;

	s.Pop();
	s.Pop();

	cout << "max number is : " << s.GetMax() << endl;

	s.Pop();
	cout << "max number is : " << s.GetMax() << endl;

	cin.get();
	return 0;
}