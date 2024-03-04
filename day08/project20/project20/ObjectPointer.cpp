#include <iostream>
using namespace std;

class Person
{
public: //���� ������� �ܺο��� ���� ������ ����(public) ����� �����մϴ�.
	void Sleep() { cout << "Sleep" << endl; }
};

class Student : public Person
{
public:
	void Study(){cout<<"Study"<<endl;}
};

class PartTimeStudent : public Student
{
public:
	void Work() { cout << "Work" << endl; }
};

int main(void)
{
	//Student * ptr0 = new Student(); ������ Ÿ������ ����ϴ� ���� ��Ģ�̴�.
	/*
	�θ�Ÿ���� ��ü �����ͷ� �ڽ� ��ü�� ����ų �� �ִ�.
	������ �ڽ�Ÿ���� ��ü �����ͷ� �θ� ��ü�� ����ų �� ����.
	�׸��� ������ ��ü �������� Ÿ���� ������.
	*/
	Person* ptr1 = new Student(); //Student Ŭ������ ���� �ν��Ͻ��� �����ϰ�, �̸� Person �����ͷ� ����Ű�� ptr1�� �Ҵ��մϴ�.
	Person* ptr2 = new PartTimeStudent(); //PartTimeStudent Ŭ������ ���� �ν��Ͻ��� �����ϰ�, �̸� Person �����ͷ� ����Ű�� ptr2�� �Ҵ��մϴ�.
	Student* ptr3 = new PartTimeStudent(); //PartTimeStudent Ŭ������ ���� �ν��Ͻ��� �����ϰ�, �̸� Student �����ͷ� ����Ű�� ptr3�� �Ҵ��մϴ�.
	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Sleep();
	delete ptr1; delete ptr2; delete ptr3;
	return 0;
}
