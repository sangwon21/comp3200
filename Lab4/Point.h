#pragma once

namespace lab4
{
	class Point
	{
	public:
		Point();
		Point(float x, float y);
		~Point();

		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		float Dot(const Point& other) const;
		Point operator*(float operand) const;

		float GetX() const;
		float GetY() const;
		void SetX(const float x);
		void SetY(const float y);

		friend Point operator*(float operand, const Point& rhs);
	private:
		float mX;
		float mY;
	};
}