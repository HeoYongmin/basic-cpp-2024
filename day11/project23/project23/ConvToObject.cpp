#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n = 0) : num(n) // 생성자 정의: 인자로 받은 값으로 num을 초기화
	{
		cout << "Number(int n=0)" << endl;
	}
	Number& operator=(const Number& ref)	// 대입 연산자 오버로딩 정의
	{
		cout << "operator=()" << endl;
		num = ref.num;		 // num에 ref.num 값을 대입
		return *this;		// 현재 객체의 참조를 반환
	}
	void ShowNumber() { cout << num << endl; }
};

int main(void)
{
	Number num;		// Number 클래스의 객체 생성, 매개변수를 전달하지 않아 기본값으로 초기화
	num = 30;
	num.ShowNumber();
	return 0;
}