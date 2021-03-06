template <class TYPE>
class Rectangle
{
public:

	TYPE x;
	TYPE y;
	TYPE h;
	TYPE w;

	Rectangle(TYPE _x, TYPE _y, TYPE _h, TYPE _w){ x = _x; y = _y; h = _h; w = _w; }

	//Rectangle(Rectangle<TYPE> r){ x = r.x; y = r.y; h = r.h; w = r.w;}


	TYPE GetArea()
	{
		return h * w;
	}

	bool Intersects(Rectangle r)
	{
		if (abs(x - r.x) < w || abs(y - r.y) < h)
			return true;
		else
			return false;
	}


};