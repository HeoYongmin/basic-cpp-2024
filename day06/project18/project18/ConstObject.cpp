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
	void ShowData() const
	{
		cout << "num: " << num << endl;
	}
};

int main(void)
{
	const SoSimple obj(7);
	// obj.AddNum(20);
	obj.ShowData();
	return 0;
}