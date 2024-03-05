#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{ }
	void viewPoint() const
	{
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}
	Point operator+(const Point& ref) const
	{
		return Point(xpos +ref.xpos, ypos + ref.ypos);
	}
	Point operator+(int num)
	{
		return Point(xpos + num, ypos + num);
	}
	friend ostream& operator<<(ostream&, const Point);
};
ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' <<pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}



int main()
{
	Point a(10, 20);
	Point b(30, 20);
	Point c = a + b;
	Point d = a + 100;
	Point e = 100 + a;

	d.viewPoint();
	e.viewPoint();

	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	return 0;
}