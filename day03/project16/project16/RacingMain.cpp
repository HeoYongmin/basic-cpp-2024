#include "Car.h"

int main(void)
{
	Car run99;                          // class carŸ���� ��ü run99 ����
	run99.InitMembers("run99", 100);    // run99��ü�� InitMembers() �ż��� ȣ��
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;
}