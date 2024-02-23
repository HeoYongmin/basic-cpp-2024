#include <iostream>
#include <string.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

char* MakeStrAdr(int len)
{
	// char * str = (char*)malloc(sizeof(char) * len);// C:heap영역에 20Byte크기로 메모리 할당
	char* str = new char[len];
	return str;
}

int main(void)
{
	char* str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout << str << endl;
	//free(str);
	delete[]str;                                  // C++: 할당받은 메모리를 반환ㅂ
	return 0;
}