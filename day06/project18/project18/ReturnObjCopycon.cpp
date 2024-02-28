#include <iostream>
using namespace std;

class SoSimple
{
private:				// 정수형 멤버 변수 num을 선언
	int num;
public:					// 생성자, 복사 생성자, 멤버 함수를 선언
	SoSimple(int n) : num(n)
	{ }
	SoSimple(const SoSimple& copy) : num(copy.num) 
		//복사 생성자는 다른 SoSimple 객체를 받아들여 num 멤버 변수를 복사 이때 복사 생성자가 호출되면 "Called SoSimple(const SoSimple& copy)" 메시지가 출력됩니다.
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}
	SoSimple& AddNum(int n)
		// AddNum 함수는 정수형 매개변수를 받아들여 num 멤버 변수에 값을 더한 후 객체 자신(*this)을 반환
	{
		num += n;				//num = num + n;
		return *this;
	}
	void ShowData()
	{
		cout << "num: " << num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)
{
	cout << "return 이전" << endl;
	return ob;
}

int main(void)
{
	SoSimple obj(7);
	// main 함수에서는 SoSimple 클래스의 객체 obj를 생성, 값 7을 인자로 전달하여 생성자를 호출하여 num 멤버 변수에 값을 할당합니다.
	SimpleFuncObj(obj).AddNum(30).ShowData();
	// 반환된 객체에 대해 AddNum 함수를 호출하여 값 30을 더한 후 ShowData 함수를 호출하여 num 값을 출력
	obj.ShowData();
	return 0;
}