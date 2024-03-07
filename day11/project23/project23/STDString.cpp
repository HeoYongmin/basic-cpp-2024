#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	// 문자열 초기화
	string str1 = "I like";
	string str2 = "string class";
	// 문자열 연결
	string str3 = str1+str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;			// str1 뒤에 str2를 추가하여 str1에 저장
	if (str1 == str3)
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	string str4;				// 사용자 입력을 저장할 문자열 변수 str4 선언
	cout << "문자열 입력: ";
	cin >> str4;				// 사용자 입력을 str4에 저장
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}