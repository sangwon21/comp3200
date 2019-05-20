#include <iostream>

#include "TimeSheet.h"

int main()
{
	using namespace lab3;
	TimeSheet p("Pope", 10);

	std::cout << p.GetTimeEntry(2) << std::endl; // returns 10
	std::cout << p.GetTimeEntry(6) << std::endl; // returns -1
	std::cout << p.GetTimeEntry(0) << std::endl; // returns 2

	p.AddTime(4);
	p.AddTime(7);
	p.AddTime(6);
	p.AddTime(5);
	p.AddTime(1);
	p.AddTime(2);

	std::cout << p.GetAverageTime() << std::endl;
	std::cout << p.GetStandardDeviation() << std::endl;

	TimeSheet m = p;
	std::cout << "-----------------p---------" << std::endl;
	std::cout << p.GetAverageTime() << std::endl;
	std::cout << p.GetStandardDeviation() << std::endl;

	std::cout << "-----------------m---------" << std::endl;
	std::cout << m.GetAverageTime() << std::endl;
	std::cout << m.GetStandardDeviation() << std::endl;

	std::cin.get();
	return 0;
}