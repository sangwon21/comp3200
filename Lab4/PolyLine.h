#pragma once

#include "Point.h"

namespace lab4
{
	class PolyLine
	{
	public:
		PolyLine();
		PolyLine(const PolyLine& other);
		PolyLine& operator=(const PolyLine& rhs);
		~PolyLine();

		bool AddPoint(float x, float y);
		bool AddPoint(const Point* point);
		bool RemovePoint(unsigned int i);
		bool TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const;

		const Point* operator[](unsigned int i) const;
	private:
		const unsigned int MAX_POINT_NUMBER = 10;
		const unsigned int MIN_POINT_NUMBER = 1;
		const Point** mPoints;
		unsigned int mSize = 0;
	};
}
