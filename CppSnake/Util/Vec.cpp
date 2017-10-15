#include "Vec.h"

bool Vec2f::operator==(Vec2f &other) const 
{ 
	return this->x == other.x && this->y == other.y;
}