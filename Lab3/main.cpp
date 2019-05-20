#include <iostream>

#include "TimeSheet.h"

int main()
{
	using namespace lab3;
	TimeSheet s(nullptr, 10);
	std::cout << s.GetName().size();
	std::cin.get();
	return 0;
}