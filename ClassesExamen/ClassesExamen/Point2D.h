#ifndef _Point2D_H
#define  _Point2D_H
template<typename TYPE>
class Point2D
{
public:
		TYPE x;
		TYPE y;
//Constructors & destructors


		Point2D()
		{
			x = 0;
			y = 0;
		}

		Point2D(TYPE _x, TYPE _y)
		{
			x = _x;
			y = _y;
		}

		~Point2D()
		{
			
		}

//Methods
		void PrintXY()
		{
			printf("\nx: %f\ny: %f\n----------------------", x, y);
		}
		const TYPE DistanceTo(Point2D p)
		{
			p.x = (p.x - x)*(p.x - x);
			p.y = (p.x - x)*(p.x - x);

			return sqrt(p.x + p.y);
		}

//Operators

		Point2D operator+(Point2D& p)
		{
			p.x = p.x + x;
			p.y = p.y + y;

			return p;
		}

		Point2D operator-(Point2D& p)
		{
			p.x = x - p.x;
			p.y = y - p.y;

			return p;
		}

		bool operator==(const Point2D& p)
		{
			return (p.x == x && p.y == y);

		}

		bool operator!=(const Point2D& p)
		{
			return (p.x != x && p.y != y);
		}

		Point2D& operator+=(Point2D& p)
		{
			x += p.x;
			y += p.y;

			return (*this);
		}

		Point2D& operator-=(Point2D& p)
		{
			x -= p.x;
			y -= p.y;

			return (*this);
		}
		


//Utilities

		void setTo(TYPE _x, TYPE _y)//You can set the values you need
		{
			x = _x;
			y = _y;
		}

		void Clear()//Sets to 0 basically
		{
			setTo(0, 0);
		}

		

};

#endif