#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:        // 접근제어자
	char * name;
	int age;
public:
	Person(const char* myname, int myage)       // 입력 2개를 갖는 생성자
	{
		int len = strlen(myname) + 1;           // strlen()은 문자열의 길이를 구하는 함수
		name = new char[len];
		std::cout << "char 크기:" << sizeof(char) << std::endl;
		strcpy(name, myname);            // scrcpy 초기화
		age = myage;
	}
	void ShowPersonInfo() const       // 객체의 정보를 출력
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age  << endl;
	}
	~Person()     // 소멸자
	{
		delete[]name;
		cout << "called destrucor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Jang dong hun", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}