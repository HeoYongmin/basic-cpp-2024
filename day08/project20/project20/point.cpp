/*
객체 포인터 변수
*/
#include <iostream>
using namespace std;

Person* ptr;					// Person 탑입의 객체 포인터 선언
Person* ptr = new Person();		// o	

Person p = new Person();		// x

// 부모는 자식을 가리킬 수 있다!