#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
public:
	BoundCheckIntArray(int len) : arrlen(len)	// 생성자: 배열의 길이를 매개변수로 받아 동적으로 배열을 할당
	{
		printf("생성자 호출\n");
		arr = new int[len];
	}
	// [] 연산자 오버로딩: 배열 요소에 접근하는 용도로 사용
	int& operator[] (int idx)	
	{
		printf("[]연산자 함수 호출\n");
		if (idx < 0 || idx >= arrlen) // 인덱스가 유효한 범위를 벗어나면 에러 메시지 출력 후 프로그램 종료
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		// 유효한 인덱스일 경우 해당 인덱스의 배열 요소에 대한 레퍼런스 반환
		return arr[idx];
	}
	~BoundCheckIntArray()
	{
		printf("소멸자 호출\n");
		delete[]arr;
	}
};

int main(void)
{
	BoundCheckIntArray arr(5); // 길이가 5인 BoundCheckIntArray 객체 생성
	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;
	for (int i = 0; i < 6; i++) // 인덱스가 0부터 5까지 6번 반복
		cout << arr[i] << endl; // 배열의 각 요소 출력 (인덱스가 유효하지 않은 경우 에러 발생)
	return 0;
}