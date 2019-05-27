#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mSize(0)
	{
		mPoints = new const Point * [MAX_POINT_NUMBER];
		for (unsigned int i = 0; i < MAX_POINT_NUMBER; i++)
		{
			mPoints[i] = nullptr;
		}
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mSize(other.mSize)
	{
		mPoints = new const Point * [MAX_POINT_NUMBER];
		for (unsigned int i = 0; i < other.mSize; i++)
		{
			mPoints[i] = new const Point(*(other.mPoints[i]));
		}
	}

	PolyLine& PolyLine::operator=(const PolyLine& rhs)
	{
		if (this != &rhs)
		{
			delete[] mPoints;

			mPoints = new const Point * [MAX_POINT_NUMBER];
			for (unsigned int i = 0; i < MAX_POINT_NUMBER; i++)
			{
				mPoints[i] = nullptr;
			}

			for (unsigned int i = 0; i < rhs.mSize; i++)
			{
				mPoints[i] = new const Point(*(rhs.mPoints[i]));
			}

			mSize = rhs.mSize;
		}
		return *this;
	}

	PolyLine::~PolyLine()
	{
		delete[] mPoints;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mSize >= MAX_POINT_NUMBER)
		{
			return false;
		}
		mPoints[mSize] = new Point(x, y);
		mSize++;

		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mSize > MAX_POINT_NUMBER || point == nullptr)
		{
			return false;
		}
		mPoints[mSize] = point;
		mSize++;

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (mSize < MIN_POINT_NUMBER)
		{
			return false;
		}

		if (i > mSize - 1)
		{
			return false;
		}

		for (unsigned int j = i; j < mSize; j++)
		{
			mPoints[j] = mPoints[j + 1];
		}

		for (unsigned int j = mSize; j < MAX_POINT_NUMBER; j++)
		{
			if (mPoints[j] != nullptr)
			{
				delete mPoints[j];
			}
			mPoints[j] = nullptr;
		}

		mSize--;

		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mSize < MIN_POINT_NUMBER)
		{
			return false;
		}

		float maxX = (*mPoints[0]).GetX();
		float maxY = (*mPoints[0]).GetY();
		float minX = (*mPoints[0]).GetX();
		float minY = (*mPoints[0]).GetY();

		if (mSize > MIN_POINT_NUMBER)
		{
			for (unsigned int i = 1; i < mSize; i++)
			{
				float tmpX = (*mPoints[i]).GetX();
				float tmpY = (*mPoints[i]).GetY();

				if (maxX < tmpX)
				{
					maxX = tmpX;
				}
				if (minX > tmpX)
				{
					minX = tmpX;
				}
				if (maxY < tmpY)
				{
					maxY = tmpY;
				}
				if (minY > tmpY)
				{
					minY = tmpY;
				}
			}
		}

		outMin->SetX(minX);
		outMin->SetY(minY);
		outMax->SetX(maxX);
		outMax->SetY(maxY);

		return true;;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= mSize)
		{
			return nullptr;
		}

		return mPoints[i];
	}
}