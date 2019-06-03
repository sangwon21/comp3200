#pragma once

#include "RectangleLawn.h"
#include "IFenceable.h"

namespace lab5
{
	class SquareLawn : public RectangleLawn, public IFenceable
	{
	public:
		SquareLawn(double width);
		~SquareLawn();

		unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
	private:

	};
}