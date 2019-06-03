#include "CircleLawn.h"

lab5::CircleLawn::CircleLawn(double radius)
	: Lawn(radius)
{
}

lab5::CircleLawn::~CircleLawn()
{
}

unsigned int lab5::CircleLawn::GetArea() const
{
	double area = mWidth * mHeight * 3.14;

	unsigned int intValue = static_cast<unsigned int>(area);

	if (static_cast<double>(intValue) == area)
	{
		return intValue;
	}

	return intValue + 1;
}
