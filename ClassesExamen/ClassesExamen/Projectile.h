#include "Point2D.h"


class Projectile
{
	//Properties
public:
	Point2D<float> point;
	Point2D<float> speed;

	const Point2D<float>& GetCurrentPosition(const float time) const 
	{
		Point2D<float> tmp;

		tmp.x = point.x + speed.x*time; //x = x0 + vx * t
		tmp.y = point.y + speed.y*time; //y = y0 + vy * t

		return tmp;
			
	}

};