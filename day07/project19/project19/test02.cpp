#include <iostream>
using namespace std;

class Myclass
{

private:
	char name[30];
	int age;

public:
	Myclass(const char* myname, int myage):age(myage)		// �ʱ�ȭ
	{
		strcpy(name, myname);								// ���ڿ� �ʱ�ȭ
	}
	string name()
	{
		return name;
	}
};

class MyInfo : public Myclass
{
private:
	char pNumber[20];
public:
	MyInfo(const char *myname, int myage, const char *mypNumber):Myclass(myname, myage)
	{
		strcpy(pNumber, mypNumber);
	}
	void printMyInfo()
	{

		cout << "���� �̸��� "<<name << "�̰� ���̴� ""<<   <<"���̸� ��ȭ��ȣ�� "<<   <<" �Դϴ�."<< endl;
	}
};

int main()
{

	return 0;
}
// MyInfo ��ü�� ����
// MyInfo��ü.printMyInfo(); �� ȣ��