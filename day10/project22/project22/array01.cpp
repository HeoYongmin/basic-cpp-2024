#include <iostream>

int main()
{
	int arr[5] = { 1, 2, 3, 4 ,5 };			//int�� �迭����
	int* parr = arr;						// �迭�� �̸��� �ּ��̴�.

	printf("arr �ּ�: %p\n", arr);			// �迭 ���� �ּҸ� ���
	printf("arr ũ��: %u\n", sizeof(arr));	// intũ�� 4 x �� ���� 5 = 20byte

	printf("arr[0] �ּ�: %p\n", &arr[0]);	// �迭�� ù ��° ����� �ּҸ� ���
	printf("arr[1] �ּ�: %p\n", &arr[1]);	// �迭�� �� ��° ����� �ּҸ� ���
	printf("arr + 1: %p\n", arr + 1);		// �迭�� ���� �ּҿ� 1�� ���� ���� �ּҸ� ���
	//=======================================

	printf("parr �ּ�: %p\n", &parr);
	printf("parr ������: %p\n", parr);	// �迭 arr�� �ּҸ� �����ϰ� �ִ�.
	printf("parr + 1: %p\n", parr + 1);		// arr �迭�� ù ��° ���(arr[0])�� ũ�⸸ŭ ���� �ּҸ� ���
	printf("parr[0]: %d *pa: %d arr[0]: %d\n", parr[0], *parr, arr[0]);


	return 0;
}