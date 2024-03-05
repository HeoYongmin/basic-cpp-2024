#include <iostream>
using namespace std;


class Myclass
{
private:
	int num;
public:
	// 생성자 Myclass(int n=0)은 객체를 초기화할 때 사용되며, 매개변수 n을 받아 객체의 num 멤버 변수에 값을 할당. 매개변수가 전달되지 않으면 기본값으로 0이 할당됩니다.
	Myclass(int n=0) : num(n)
	{ }
	Myclass operator+(const Myclass& other) const	// operator+ 함수는 두 개의 Myclass 객체를 더한 결과를 반환하는 연산자 오버로딩 함수
	{
		return Myclass(num + other.num);
	}
	void print() const
	{
		cout << "num: " << num << endl;
	}

};

int main()
{
	Myclass a(10);
	a.print();				// value: 10

	Myclass b(a);
	b.print();				// value: 10

	Myclass c = b;
	b.print();				// value: 10

	Myclass d = a + b + c;
	d.print();				// value: 30
	return 0;
}