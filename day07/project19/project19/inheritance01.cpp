#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	char name[50];
	int age;
public:
		Person(const char* myname, int myage)
		{
			cout << "부모생성자 실행" << endl;
			age = myage;
			strcpy(name, myname);
		}
		void whatYouName() const
		{
			cout << "My name is " << name << endl;
		}
		void howOldAreYou() const
		{
			cout << "I'm" << age << "yours old" << endl;
		}
};

class UnivStuent :public Person
{
	string major;
public:
	UnivStuent(const char* myname, int myage, string major) : Person(myname, myage)
	{
		cout << "자식 생성자 실행" << endl;
		this->major = major;
	}
	void whoAreYour() const
	{
		whatYouName();
		howOldAreYou();
	}
};
int main()
{
	UnivStuent s("허용민", 50, "백수");
	s.whoAreYour();



	return 0;
}