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

	Human h("ȫ�浿", 50, "���");     // ��ü�������
	h.humanlnfo();					   // ���� 50���� ��� ȫ�浿�Դϴ�.

	return 0;
}