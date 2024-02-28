#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		cout << "생성자 호출" << endl;
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person(const Person& other)
	{
		this->name = new char[strlen(other.name) + 1];    // 깊은 복사
		strcpy(this->name, other.name);
		this->age = other.age;
		//this->name = other.name;         // 멤버대 멤버 복사
		//this->age = other.age;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}

int func(int a)           // a=10; num의 10을 복사해서 사용한다.
{
	a = 10 + a;
	return a;			  // a를 리턴한다
}

int num = 10;            // 정수형 변수 num을 선언하고 값을 10으로 초기화
int res = func(num);	// func 함수를 호출하여 num의 값을 전달하고 반환된 결과를 정수형 변수 res에 저장