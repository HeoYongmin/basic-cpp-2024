#include "Car.h"

int main(void)
{
	Car run99;                          // class car타입의 객체 run99 생성
	run99.InitMembers("run99", 100);    // run99객체의 InitMembers() 매서드 호출
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;
}
