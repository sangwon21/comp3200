#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(double radius);
		~CircleLawn();

		unsigned int GetArea() const;
	private:

	};
}