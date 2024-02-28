#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	// 생성자를 통해 num 멤버 변수를 초기화하고 객체가 생성될 때 "create obj: "와 해당 객체의 num 값을 출력
	{
		cout << "create obj: " << num << endl;
	}
	~Temporary()
	// 소멸자를 통해 객체가 소멸될 때 "destroy obj: "와 해당 객체의 num 값을 출력
		{
			cout << "destory obj: " << num << endl;
		}
	void ShowTempInfo() 
	{
		cout << "My num is " << num << endl;
		}
};
int main(void)
{
	Temporary(100);   // Temporary t(100) 임시객체
	// Temporary 클래스의 임시 객체를 생성, 생성자가 호출되어 "create obj: 100"이 출력됩니다. 그러나 이 객체에 대한 참조나 포인터가 없으므로, 이후에 사용되지 않고 즉시 파괴
	cout << "********** after make!" << endl << endl;

	Temporary(200).ShowTempInfo();
	// 임시 객체를 생성하고 ShowTempInfo() 함수를 호출하여 해당 객체의 num 값을 출력
	cout << "********** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);
	cout << "********** end of main!" << endl << endl;
	return 0;
}