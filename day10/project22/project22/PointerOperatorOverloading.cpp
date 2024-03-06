#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n): num(n) { }
	void ShowData() { cout << num << endl; }

	Number* operator->()	// -> 연산자 오버로딩: 객체 포인터를 반환
	{
		return this;
	}

	Number& operator*()		// * 연산자 오버로딩: 객체의 레퍼런스를 반환
	{
		return *this;
	}
};

int main(void)
{
	Number num(20);
	num.ShowData();

	(*num) = 30;		// * 연산자를 이용하여 객체의 멤버 변수에 접근하여 값 변경
	num->ShowData();
	(*num).ShowData();
	return 0;
}