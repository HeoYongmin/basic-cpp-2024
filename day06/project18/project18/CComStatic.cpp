#include <iostream>
using namespace std;

void Counter()
{
	static int cnt; //정적 지역 변수 cnt를 선언합니다. 이 변수는 함수가 호출될 때마다 초기화되지 않고, 이전에 저장된 값을 유지
	// int cnt = 0; 를 대신 사용하면 cnt는 매번 함수가 호출될 때마다 0으로 초기화 되므로 cnt가 1씩 증가 그래서 결과적으로 출력되는 값은 항상 1
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main(void)
{
	for (int i = 0; i < 10; i++)	// i가 0부터 9까지 1씩 증가하며 반복
		Counter();
	return 0;
}