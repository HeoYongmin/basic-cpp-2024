#include <iostream>
#include "Filedivi.h"

class human {
private:
	char name[20];
	int age;
	char job;

	void showHuman()
	{
		printf("name: %s age: %d job: %s\n", name, age, job);
	}
}Human;

AClass::AClass(int anum) {
	num = anum;

}
void AClass::Alnfo() {
	std::cout << "AClass::num " << num <<  std::endl;
}

int main()
{
	AClass a(10);

	Human h("홍길동", 50, "백수");     // 객체생성방법
	h.humanlnfo();					   // 나는 50살인 백수 홍길동입니다.

	return 0;
}