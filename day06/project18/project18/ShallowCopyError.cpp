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
		cout << "������ ȣ��" << endl;
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person(const Person& other)
	{
		this->name = new char[strlen(other.name) + 1];    // ���� ����
		strcpy(this->name, other.name);
		this->age = other.age;
		//this->name = other.name;         // ����� ��� ����
		//this->age = other.age;
	}
	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
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

int func(int a)           // a=10; num�� 10�� �����ؼ� ����Ѵ�.
{
	a = 10 + a;
	return a;			  // a�� �����Ѵ�
}

int num = 10;            // ������ ���� num�� �����ϰ� ���� 10���� �ʱ�ȭ
int res = func(num);	// func �Լ��� ȣ���Ͽ� num�� ���� �����ϰ� ��ȯ�� ����� ������ ���� res�� ����