#include "Point.h"

namespace lab4
{
	Point::Point(float x, float y)
		: mX(x),
		  mY(y)
	{
	}

	Point::~Point()
	{
	}

	Point Point::operator+(const Point& other) const
	{
		Point result(mX + other.mX, mY + other.mY);
		return result;
	}

	Point Point::operator-(const Point& other) const
	{
		Point result(mX - other.mX, mY - other.mY);
		return result;
	}

	float Point::Dot(const Point& other) const
	{
		float result = 0.0f;
		result = (mX * other.mX) + (mY * other.mY);
		return result;
	}

	Point Point::operator*(float operand) const
	{
		Point result(mX * operand, mY * operand);
		return result;
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}
}