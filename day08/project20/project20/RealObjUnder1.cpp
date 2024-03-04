#include <iostream>
using namespace std;

class Data
{
private:
	int data;
public:
	Data(int num): data(num)		// 생성자 정의 int형 인자를 받아 data 멤버 변수에 해당 값을 할당
	{ }
	void ShowData() { cout << "Data:" << data << endl; }
	void Add(int num) { data += num; } // num 인자를 data 멤버 변수에 더합니다
};

int main(void)
{
	Data obj(15);	// Data 클래스의 객체 obj를 생성하고, int형 매개변수 15를 가지고 있는 생성자를 호출하여 초기화합니다.
	obj.Add(17);	// obj 객체의 Add() 메서드를 호출하여 17을 인수로 전달하고, 이를 data 멤버 변수에 더합니다.
	obj.ShowData();
	return 0;
}