#include "Lawn.h"
#include "eGrassType.h"

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::Lawn(double width)
		: mWidth(width),
		  mHeight(width)
	{
	}

	Lawn::Lawn(double width, double height)
		: mWidth(width),
		  mHeight(height)
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		unsigned int area = this->GetArea();

		double price = 0.0;
		switch (grassType)
		{
		case eGrassType::BAHIA:
			price *= 5;
			break;
		case eGrassType::BERMUDA:
			price *= 8;
			break;
		case eGrassType::BENTGRASS:
			price *= 3;
			break;
		case eGrassType::PERENNIAL_RYEGRASS:
			price *= 2.5;
			break;
		case eGrassType::ST_AUGUSTINE:
			price *= 4.5;
			break;
		}

		price = price * 10 + 0.5;
		unsigned int intValue = static_cast<unsigned int>(price);

		return intValue;
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		unsigned int area = this->GetArea();

		double rollsCount = area / 0.3;
		rollsCount = rollsCount * 10 + 0.5;
		
		unsigned int intValue = static_cast<unsigned int>(rollsCount);

		if (static_cast<double>(intValue) == rollsCount)
		{
			return intValue;
		}

		return intValue + 1;
	}
}