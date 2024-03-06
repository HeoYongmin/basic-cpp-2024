#include <iostream>

int main()
{
	int arr[5] = { 1, 2, 3, 4 ,5 };			//int형 배열선언
	int* parr = arr;						// 배열의 이름은 주소이다.

	printf("arr 주소: %p\n", arr);			// 배열 시작 주소를 출력
	printf("arr 크기: %u\n", sizeof(arr));	// int크기 4 x 방 갯수 5 = 20byte

	printf("arr[0] 주소: %p\n", &arr[0]);	// 배열의 첫 번째 요소의 주소를 출력
	printf("arr[1] 주소: %p\n", &arr[1]);	// 배열의 두 번째 요소의 주소를 출력
	printf("arr + 1: %p\n", arr + 1);		// 배열의 시작 주소에 1을 더한 값의 주소를 출력
	//=======================================

	printf("parr 주소: %p\n", &parr);
	printf("parr 데이터: %p\n", parr);	// 배열 arr의 주소를 저장하고 있다.
	printf("parr + 1: %p\n", parr + 1);		// arr 배열의 첫 번째 요소(arr[0])의 크기만큼 더한 주소를 출력
	printf("parr[0]: %d *pa: %d arr[0]: %d\n", parr[0], *parr, arr[0]);


	return 0;
}