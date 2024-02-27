/*
객체 배열
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Human
{
private:
	char name[30];
	int age;

public:
	Human(const char* pname, int age)
	{
		cout << "생성자 호출" << endl;
		strcpy(name, pname);
		this->age = age;
	}
	void HumanInfo()
	{
		cout << "이름: " << name << " ";
		cout << "나이: " << age << endl;
	}
	~Human()
	{
		cout << "소멸자 호출" << endl;
	}
};

int main()
{
	Human h[3] = {Human("홍길동", 50), Human("김철수", 40), Human("김영희", 30)};      // 객체배열

	for (int i = 0; i < 3; i++)
	{
		h[i].HumanInfo();
	}

	Human *h1 = new Human("가나다", 50);  // Human 클래스의 포인터 h1을 선언하고 new연산자를 사용하여 동적으로 Human 클래스의 객체를 생성
										  // 생성자 Human(const char* pname, int aage)를 호출하여 이름이 "가나다"이고 나이가 50인 객체를 초기화
	Human h2("라마바", 30);

	h1->HumanInfo();					  // 포인터 h1이 가리키는 객체의 HumanInfo() 함수를 호출하여 해당 객체의 정보를 출력합니다.
										  //-> 연산자는 포인터가 가리키는 객체의 멤버에 접근하는데 사용됩니다.
	h2.HumanInfo();

	delete h1;

	return 0;
}