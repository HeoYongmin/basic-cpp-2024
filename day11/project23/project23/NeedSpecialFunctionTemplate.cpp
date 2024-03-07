#include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b)
{
	// a와 b를 비교하여 더 큰 값을 반환
	return a > b ? a : b;
}

int main(void)
{
	// 두 정수를 인수로 Max 함수 호출하여 더 큰 값 출력
	cout << Max(11, 15) << endl;
	// 두 문자를 인수로 Max 함수 호출하여 ASCII 값이 큰 문자 출력
	cout << Max('T', 'Q') << endl;
	// 두 실수를 인수로 Max 함수 호출하여 더 큰 값 출력
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;
	return 0;
}