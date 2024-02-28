#include <iostream>
using namespace std;

class Point;

class PointOP
{
private:
	int opcnt;				// 정수형 멤버 변수 opcnt를 선언
public:
	PointOP() : opcnt(0)		// PointOP 클래스의 기본 생성자를 정의합니다. 이 생성자는 opcnt 멤버 변수를 0으로 초기화
	{ }

	Point PointAdd(const Point&, const Point&);			//PointOP 클래스의 멤버 함수 PointAdd를 선언 / 함수선언에서는 매개변수의 이름은 생략 가능하나
	Point PointSub(const Point&, const Point&);			//PointOP 클래스의 멤버 함수 PointSub를 선언 / 매개변수 타입은 생략할 수 없다.
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
	//Point 클래스의 생성자를 정의합니다. 이 생성자는 정수형 매개변수 xpos와 ypos를 받아들여 x와 y 멤버 변수를 초기화
	friend Point PointOP::PointAdd(const Point&, const Point&);
	friend Point PointOP::PointSub(const Point&, const Point&);
	friend void ShowPointPos(const Point&);		// 멤버함수, 선언부
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

