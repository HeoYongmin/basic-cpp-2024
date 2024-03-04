#include <iostream>
using namespace std;

class Person
{
public: //이하 멤버들을 외부에서 접근 가능한 공개(public) 멤버로 지정합니다.
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
	//Student * ptr0 = new Student(); 동일한 타입으로 사용하는 것이 원칙이다.
	/*
	부모타입의 객체 포인터로 자식 객체를 가리킬 수 있다.
	하지만 자식타입의 객체 포인터로 부모 객체는 가리킬 수 없다.
	그리고 접근은 객체 포인터의 타입을 따른다.
	*/
	Person* ptr1 = new Student(); //Student 클래스의 동적 인스턴스를 생성하고, 이를 Person 포인터로 가리키는 ptr1에 할당합니다.
	Person* ptr2 = new PartTimeStudent(); //PartTimeStudent 클래스의 동적 인스턴스를 생성하고, 이를 Person 포인터로 가리키는 ptr2에 할당합니다.
	Student* ptr3 = new PartTimeStudent(); //PartTimeStudent 클래스의 동적 인스턴스를 생성하고, 이를 Student 포인터로 가리키는 ptr3에 할당합니다.
	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Sleep();
	delete ptr1; delete ptr2; delete ptr3;
	return 0;
}
