#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:        // ����������
	char * name;
	int age;
public:
	Person(const char* myname, int myage)       // �Է� 2���� ���� ������
	{
		int len = strlen(myname) + 1;           // strlen()�� ���ڿ��� ���̸� ���ϴ� �Լ�
		name = new char[len];
		std::cout << "char ũ��:" << sizeof(char) << std::endl;
		strcpy(name, myname);            // scrcpy �ʱ�ȭ
		age = myage;
	}
	void ShowPersonInfo() const       // ��ü�� ������ ���
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age  << endl;
	}
	~Person()     // �Ҹ���
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