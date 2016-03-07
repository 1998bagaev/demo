#include <iostream>
#include <string>

class ComplexNum
{
	double _x, _iy;
public:
	ComplexNum()
	{
		std::cout << "default";
	}
	void print()
	{
		std::cout << _x << "+" << _iy << "i" << std::endl;
	}
	ComplexNum(double x, double iy)
		:_x(x), _iy(iy)
	{
	}
	ComplexNum &operator +=(const ComplexNum &a)
	{
		_x += a._x;
		_x += a._iy;
		return *this;
	}
	ComplexNum &operator +=(const ComplexNum &b)
	{
		_x += b._x;
		_x += b._iy;
		return *this;
	}
};

ComplexNum operator+(const ComplexNum &a, const ComplexNum &b)
{
	ComplexNum c(a);
	c = a + b;
	return c;
}

ComplexNum operator-(const ComplexNum &a, const ComplexNum &b)
{
	ComplexNum c(a);
	c = a - b;
	return c;
}

ComplexNum operator*(const ComplexNum &a, const ComplexNum &b)
{
	ComplexNum c(a);
	c = a * b;
	return c;
}

ComplexNum operator/(const ComplexNum &a, const ComplexNum &b)
{
	ComplexNum c(a);
	c = a / b;
	return c;
}
