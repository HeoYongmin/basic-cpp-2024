#include <iostream>
using namespace std;

class First
{
public:
	void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }
};

class Second : public First
{
public:
	void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
};

class Third : public Second
{
public:
	void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

int main(void)
{
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();	
	obj.SimpleFunc();		// 객체obj는 Third 클래스의 객체이므로 Third's SimpleFunc() 출력

	Second& sref = obj;		// 참조자 생성
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();		// 객체obj는 Third 클래스의 객체이므로 Third's SimpleFunc() 출력

	First& fref = obj;
	fref.FirstFunc();
	fref.SimpleFunc();		// 객체obj는 Third 클래스의 객체이므로 Third's SimpleFunc() 출력
	return 0;

}