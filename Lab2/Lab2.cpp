#include "Lab2.h"
#include <string>
#include <iomanip>
#include <limits>
#include <iostream>

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		out << std::setw(12) << std::right << "oct" << std::setw(11) << std::right << "dec" << std::setw(9) << std::right << "hex" << std::endl;
		out << std::setfill('-') << std::setw(13) << std::right << ' ' << std::setw(11) << std::right << ' ' << std::setw(8) << "-" << std::endl;
		out << std::setfill(' ');
		std::string tmp;
		int number;
		while (!in.eof())
		{
			in >> number;
			if (in.fail())
			{
				in.clear();
				in >> tmp;
			}
			else
			{
				out << std::setw(12) << std::right << std::oct << number << std::setw(11) << std::right << std::dec << number << std::setw(9) << std::right << std::uppercase << std::hex << number << std::endl;
			}
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{	
		std::string tmp;
		float number = 0.0f;
		float maxNumber = std::numeric_limits<float>::lowest();
		out.setf(std::ios::fixed);
		out.setf(std::ios::showpoint);
		out.precision(3);

		while (!in.eof())
		{
			in >> number;
			if (in.fail())
			{
				in.clear();
				in >> tmp;
			}
			else
			{
				if (maxNumber < number)
				{
					maxNumber = number;
				}
				if (number >= 0)
				{
					out << std::setw(6) << std::right << '+' << std::setw(14) << std::right << number << std::endl;
				}
				else
				{
					out << std::setw(6) << std::right << '-' << std::setw(14) << std::right << std::abs(number) << std::endl;
				}
			}
		}

		if (maxNumber >= 0)
		{
			out << std::setw(4) << "max:" << std::setw(2) << std::right << '+' << std::setw(14) << std::right << std::setprecision(3) << maxNumber << std::endl;
		}
		else
		{
			out << std::setw(4) << "max:" << std::setw(2) << std::right << '-' << std::setw(14) << std::right << std::setprecision(3) << std::abs(maxNumber) << std::endl;
		}
	}
}