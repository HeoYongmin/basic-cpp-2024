#include <iostream>
#include <cstring> 
using namespace std;
// name 필드는 힙영역에 메모리를  할당하여 저장한다.
// 자기 객체를 생성하고 객체 복사를 하시오

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage) : age(myage)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	Person(const Person& other) : age(other.age)
	{
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << ", 나이: " << age << endl;
	}

	~Person()
	{
		delete[] name;
	}
	
};

int main()
{
	Person p("허용민", 27);
	p.ShowPersonInfo();

	Person copyp(p);
	copyp.ShowPersonInfo();

	return 0;
}

