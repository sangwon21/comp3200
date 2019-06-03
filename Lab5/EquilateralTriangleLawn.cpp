#include "EquilateralTriangleLawn.h"
#include <cmath>
#include <iostream>
lab5::EquilateralTriangleLawn::EquilateralTriangleLawn(double side)
	: Lawn(side, sqrt(3.0) * (side / 2.0))
{
}

lab5::EquilateralTriangleLawn::~EquilateralTriangleLawn()
{
}

unsigned int lab5::EquilateralTriangleLawn::GetArea() const
{
	double area = pow(mWidth, 2.0) * sqrt(3.0) / 4.0;
	area = area * 10 + 5;
	area /= 10;

	unsigned int intValue = static_cast<unsigned int>(area);

	return intValue;
}

unsigned int lab5::EquilateralTriangleLawn::GetMinimumFencesCount() const
{
	double widthFence = mWidth / 0.25;

	unsigned int widthCount = static_cast<unsigned int>(widthFence);

	if (static_cast<double>(widthCount) != widthFence)
	{
		widthCount++;
	}

	return widthCount * 3;
}

unsigned int lab5::EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
{
	unsigned int widthDist = static_cast<unsigned int>(mWidth);

	if (static_cast<double>(widthDist) != mWidth)
	{
		widthDist++;
	}

	unsigned int circumference = widthDist * 3;
	unsigned int price = 0;

	switch (fenceType)
	{
	case eFenceType::RED_CEDAR:
		price = 6 * circumference;
		break;
	case eFenceType::SPRUCE:
		price = 7 * circumference;
		break;
	}

	return price;
}
