#include <iostream>
#include <cstring> 
using namespace std;
// name �ʵ�� �������� �޸𸮸�  �Ҵ��Ͽ� �����Ѵ�.
// �ڱ� ��ü�� �����ϰ� ��ü ���縦 �Ͻÿ�

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
		cout << "�̸�: " << name << ", ����: " << age << endl;
	}

	~Person()
	{
		delete[] name;
	}
	
};

int main()
{
	Person p("����", 27);
	p.ShowPersonInfo();

	Person copyp(p);
	copyp.ShowPersonInfo();

	return 0;
}

