#include <iostream>
using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{ }
	void ShowData() { cout << num1 << "," << num2 << endl; }
};

class Second
{
private:
	int num3, num4;
public:
	Second(int n3=0, int n4=0):num3(n3), num4(n4)
	{ }
	void ShowData() { cout << num3 << "," << num4 << endl; }

	Second& operator=(const Second& ref)
	{
		cout << "Second& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};

int main(void)
	{
		First fsrc(111, 222);	// fsrc 객체는 First 클래스의 객체로 생성되며 생성자에 111과 222를 전달하여 객체를 초기화합니다. 즉, num1에는 111이, num2에는 222가 할당
		First fcpy;				// fcpy 객체는 기본 생성자를 통해 생성되고, 객체가 생성되면 num1과 num2는 0으로 초기화
		Second ssrc(333, 444);
		Second scpy;
		fcpy = fsrc;			// 디폴트 대입연산자 호출, 멤버별로 복사를 수행
		scpy = ssrc;			// 명시적으로 작성한 대입연산자 호출
		fcpy.ShowData();
		scpy.ShowData();

		First fob1, fob2;	// 객체가 생성되면 num1과 num2는 0으로 초기화
		Second sob1, sob2;  // 객체가 생성되면 num3과 num4는 0으로 초기화
		fob1 = fob2 = fsrc;
		sob1 = sob2 = ssrc;

		fob1.ShowData();
		fob2.ShowData();
		sob1.ShowData();
		sob2.ShowData();
		return 0;
	}