#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}
	Point operator+(const Point &ref) //operator+ 함수는 두 점의 좌표를 더한 새로운 점을 반환합니다. 이는 연산자 오버로딩을 통해 + 연산자를 재정의한 것, 객체끼리 연산 가능하도록
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);	// 새로운 객체 생성
		return pos;
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1.operator+(pos2);

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}