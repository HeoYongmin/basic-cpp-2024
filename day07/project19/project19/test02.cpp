#include <iostream>
using namespace std;

class Myclass
{

private:
	char name[30];
	int age;

public:
	Myclass(const char* myname, int myage):age(myage)		// 초기화
	{
		strcpy(name, myname);								// 문자열 초기화
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

		cout << "나의 이름은 "<<name << "이고 나이는 ""<<   <<"살이며 전화번호는 "<<   <<" 입니다."<< endl;
	}
};

int main()
{

	return 0;
}
// MyInfo 객체를 생성
// MyInfo개체.printMyInfo(); 를 호출