#include <iostream>
#include <stdlib.h>
using namespace std;

class Simple
{
public:
	Simple()                     // 생성자(클래스이름과 같은 매서드)
	{
		cout << "I'm simple constructor!" << endl;
	}
};

int main(void)
{
	cout << "case 1: ";
	Simple* sp1 = new Simple;             // new 연산자를 통한 객체생성

	cout << "case 2:";
	Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);

	cout << endl << "end of main" << endl;
	delete sp1;           //객체를 반환한다
	free(sp2);
	return 0;
}