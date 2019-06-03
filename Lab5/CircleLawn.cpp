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

	area = area * 10 + 5;
	area /= 10;

	unsigned int intValue = static_cast<unsigned int>(area);

	return intValue;
}
