#ifndef _Circle_H
#define  _Circle_H
#include <iostream>
#include "Point2D.h"
#define PI 3.1415



template <typename TYPE>
class Circle
{
public:
	//Properties
	Point2D<TYPE> center;
	int radius;

	//Constructor
	Circle(Point2D<TYPE> _center, int _radius){ center = _center; radius = _radius; }
	//Methods

	TYPE CalculateSurface()const
	{
		return (PI*(radius*radius));
	
	}

	bool CircleIntersection(Circle<TYPE>& secondCircle)
	{
		if (radius + secondCircle.radius < center.DistanceTo(secondCircle.center))
			return true;
		return false;
	
	}



};

#endif