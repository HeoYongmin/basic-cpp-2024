#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "New Object: " << this << endl;
	}
	SoSimple(const SoSimple& copy) : num(copy.num)
	{
		cout << "New Copy obj:" << this << endl;
	}
	~SoSimple()
	{
		cout << "Destory obj: " << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)
{
	cout << "Parm ADR: " << &ob << endl;
	return ob;
}

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj);

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj);				// 임시객체 주소저장
	cout << "Return obj " << &tempRef << endl;
	return 0;
}


//New Object: 0000000C4F9AFA44: 객체 obj주소
//New Copy obj : 0000000C4F9AFB44: 객체 ob주소
//Parm ADR : 0000000C4F9AFB44: 겍체ob주소
//New Copy obj : 0000000C4F9AFB84: 임시객체 주소
//Destory obj : 0000000C4F9AFB44: 객체ob소멸
//Destory obj : 0000000C4F9AFB84: 임시객체 소멸

//New Copy obj : 0000000C4F9AFBA4 : 객체 ob주소
//Parm ADR : 0000000C4F9AFBA4 : SimpleFuncObj 내에서 매개변수로 받은 객체ob의 주소
//New Copy obj : 0000000C4F9AFA64 : SimpleFuncObj를 빠져나올 때, 반환된 객체의 복사본이 생성, 임시객체 주소
//Destory obj : 0000000C4F9AFBA4 : 이전에 생성된 객체가 소멸될 때, 해당 객체의 메모리 주소, 객체ob소멸
//Return obj 0000000C4F9AFA64: SimpleFuncObj 함수의 반환값으로 생성된 객체의 주소
//Destory obj : 0000000C4F9AFA64 : 임시객체 소멸
//Destory obj : 0000000C4F9AFA44 : 객체obj소멸