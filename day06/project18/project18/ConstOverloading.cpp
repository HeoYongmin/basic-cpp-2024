#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{ }
	SoSimple& AddNum(int n) //AddNum 함수는 정수형 매개변수를 받아들여 num 멤버 변수에 값을 더한 후 객체 자신을 반환
	{
		num += n;
		return *this;
	}
	void SimpleFunc()
	{
		cout << "Simplefunc: " << num << endl;
	}
	void SimpleFunc() const
	{
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YorFunc(const SoSimple& obj)
{
	obj.SimpleFunc();
}

int main(void)
{
	SoSimple obj1(2);
	const SoSimple obj2(7);

	obj1.SimpleFunc();
	obj2.SimpleFunc();

	YorFunc(obj1);
	YorFunc(obj2);
	return 0;
}