#include "RectangleLawn.h"

lab5::RectangleLawn::RectangleLawn(double width, double height)
	: Lawn(width, height)
{
}

lab5::RectangleLawn::~RectangleLawn()
{
}

unsigned int lab5::RectangleLawn::GetArea() const
{
	double area = mWidth * mHeight;

	unsigned int intValue = static_cast<unsigned int>(area);

	if (static_cast<double>(intValue) == area)
	{
		return intValue;
	}
	return intValue + 1;
}

unsigned int lab5::RectangleLawn::GetMinimumFencesCount() const
{
	return 0;
}

unsigned int lab5::RectangleLawn::GetFencePrice(eFenceType fenceType) const
{
	return 0;
}
