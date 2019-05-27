#include "Point.h"

namespace lab4
{
	Point::Point()
		: mX(0.0f),
		  mY(0.0f)
	{
	}

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

	void Point::SetX(const float x)
	{
		mX = x;
	}

	void Point::SetY(const float y)
	{
		mY = y;
	}

	Point operator*(float operand, const Point& rhs)
	{
		Point result(rhs.mX * operand, rhs.mY * operand);
		return result;
	}
}

