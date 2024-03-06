#include <iostream>
using namespace std;

class AAA
{
private:
	int num;			// AAA 클래스의 private 멤버 변수로, 정수를 저장
public:
	AAA(int n = 0) : num(n)	// 생성자로, 정수를 매개변수로 받아 멤버 변수 num에 초기화합니다. 이 생성자는 매개변수를 받지 않을 경우 기본값으로 0을 사용
	{
		cout << "AAA(int n=0)" << endl;
	}
	AAA(const AAA& ref) : num(ref.num)	// 복사 생성자로, AAA 클래스의 객체를 복사하여 새로운 객체를 생성
	{
		cout << "AAA(const AAA& ref)" << endl;	// 대입 연산자 오버로딩 함수로, AAA 클래스의 객체에 다른 AAA 객체를 대입할 때 호출되는 함수
	}
	AAA& operator=(const AAA& ref)
	{
		num = ref.num;
		cout << "operator=(const AAA& ref)" << endl;
		return *this;
	}
};

class BBB
{
private:
	AAA mem;		// AAA 클래스의 객체를 멤버로 갖습니다.
public:
	BBB(const AAA& ref): mem(ref) { }	// AAA 클래스의 객체를 매개변수로 받아 멤버 객체 mem을 초기화 / 멤버 이니셜라이즈(콜론 초기화)를 통해서 초기화
};

class CCC
{
private:
	AAA mem;
public:
	CCC(const AAA& ref) { mem = ref; }	// AAA 클래스의 객체를 매개변수로 받아, 대입 연산자를 이용하여 멤버 객체 mem을 초기화
};

int main(void)
{
	AAA obj1(12);
	cout << "**********************" << endl;
	BBB obj2(obj1);
	cout << "************************" << endl;
	CCC obj3(obj1);
	return 0;
}

// 배열이름 ary는 배열의 시작주소이다.
int ary[3]; // 배열선언부에서 배열 인덱스에 있는 숫자는 방의크기
ary[2]; //코드 실행에서 배열 인덱스에 있는 숫자는 방 번호를 나타낸다.

ary[0] = 10;	//0번방, 첫번째방의 데이터
*(ary + 0) = 10;  // *(배열의 시작주소 + 0) = 10

*(ary + 1) = 20; == ary[1] = 20;		// 1번방에다가 20을 집어넣어라

ary의 주소가 0x0011 이라면 다음방, 1번방(두번째방) 주소는 0x0115이다.