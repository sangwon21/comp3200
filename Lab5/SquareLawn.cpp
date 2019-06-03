#include "SquareLawn.h"

lab5::SquareLawn::SquareLawn(double width)
	: Lawn(width)
{
}

lab5::SquareLawn::~SquareLawn()
{
}

unsigned int lab5::SquareLawn::GetArea() const
{
	double area = mWidth * mHeight;

	area = area * 10 + 5;
	area /= 10;

	unsigned int intValue = static_cast<unsigned int>(area);

	return intValue;
}

unsigned int lab5::SquareLawn::GetMinimumFencesCount() const
{

	double widthFence = mWidth / 0.25;
	double heightFence = mHeight / 0.25;

	unsigned int widthCount = static_cast<unsigned int>(widthFence);

	if (static_cast<double>(widthCount) != widthFence)
	{
		widthCount++;
	}

	unsigned int heightCount = static_cast<unsigned int>(heightFence);

	if (static_cast<double>(heightCount) != heightFence)
	{
		heightCount++;
	}

	return widthCount * 2 + heightCount * 2;
}

unsigned int lab5::SquareLawn::GetFencePrice(eFenceType fenceType) const
{
	unsigned int widthDist = static_cast<unsigned int>(mWidth);

	if (static_cast<double>(widthDist) != mWidth)
	{
		widthDist++;
	}

	unsigned int heightDist = static_cast<unsigned int>(mHeight);

	if (static_cast<double>(heightDist) != mHeight)
	{
		heightDist++;
	}

	unsigned int circumference = widthDist * 2 + heightDist * 2;
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
