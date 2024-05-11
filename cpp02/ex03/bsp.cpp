#include "Point.hpp"

Fixed checkTrinagle(Point const &a, Point const &b, Point const &c)
{
	Fixed result;

	result = ( a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()) ) / Fixed(2);
	
	if (result.getRawBits() < 0) {
        result = result * Fixed(-1);  // Converti -1 in Fixed e moltiplica il risultato per -1
    }
	return result;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	(void)point;
	Fixed A = checkTrinagle(a, b, c);

    Fixed A1 = checkTrinagle(a, b, point);
    Fixed A2 = checkTrinagle(b, c, point);
    Fixed A3 = checkTrinagle(c, a, point);

	std::cout << A << std::endl;
	std::cout << A1 << " + " << A2 << " + " << A3 << " = " << A1 + A2 + A3 << std::endl;

	if (A == A1 + A2 + A3)
		return true;
	return false;
}