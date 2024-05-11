#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
	//anything else useful
public:
	Point();
	Point(const Point &rhs);
	~Point();
	Point &operator=(const Point &rhs);

	Point(const Fixed x, const Fixed y);
	const Fixed &getX() const;
	const Fixed &getY() const;
	//anything else useful
};

Fixed checkTrinagle(Point const &a, Point const &b, Point const &c);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif