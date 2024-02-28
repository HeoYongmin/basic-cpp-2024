#include <iostream>
using namespace std;

class Point;

class PointOP
{
private:
	int opcnt;				// ������ ��� ���� opcnt�� ����
public:
	PointOP() : opcnt(0)		// PointOP Ŭ������ �⺻ �����ڸ� �����մϴ�. �� �����ڴ� opcnt ��� ������ 0���� �ʱ�ȭ
	{ }

	Point PointAdd(const Point&, const Point&);			//PointOP Ŭ������ ��� �Լ� PointAdd�� ���� / �Լ����𿡼��� �Ű������� �̸��� ���� �����ϳ�
	Point PointSub(const Point&, const Point&);			//PointOP Ŭ������ ��� �Լ� PointSub�� ���� / �Ű����� Ÿ���� ������ �� ����.
	~PointOP()
	{
		cout << "Operation times: " << opcnt << endl;
	}
};

class Point
{
private:
	int x;
	int y;
public:
	Point(const int &xpos, const int &ypos) : x(xpos), y(ypos)
	{ }
	//Point Ŭ������ �����ڸ� �����մϴ�. �� �����ڴ� ������ �Ű����� xpos�� ypos�� �޾Ƶ鿩 x�� y ��� ������ �ʱ�ȭ
	friend Point PointOP::PointAdd(const Point&, const Point&);
	friend Point PointOP::PointSub(const Point&, const Point&);
	friend void ShowPointPos(const Point&);		// ����Լ�, �����
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2)
{
	opcnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2)
{
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

int main(void)
{
	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos2, pos1));
	return 0;
}

void ShowPointPos(const Point& pos)
{
	cout << "x: " << pos.x << ", ";
	cout << "y: " << pos.y << endl;
}

