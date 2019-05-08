#include <iostream>
#include "MyString.h"
#include <conio.h>

using namespace assignment1;

int main()
{
	using namespace std;

	MyString s("Hello");
	MyString s1(s);

	cout << s.GetCString() << endl;
	cout << s1.GetCString() << endl;
	cout << s.GetLength() << endl;
	cout << s1.GetLength() << endl;

	cin.get();
	return 0;
}