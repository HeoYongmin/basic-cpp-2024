#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	// ���ڿ� �ʱ�ȭ
	string str1 = "I like";
	string str2 = "string class";
	// ���ڿ� ����
	string str3 = str1+str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;			// str1 �ڿ� str2�� �߰��Ͽ� str1�� ����
	if (str1 == str3)
		cout << "���� ���ڿ�!" << endl;
	else
		cout << "�������� ���� ���ڿ�!" << endl;

	string str4;				// ����� �Է��� ������ ���ڿ� ���� str4 ����
	cout << "���ڿ� �Է�: ";
	cin >> str4;				// ����� �Է��� str4�� ����
	cout << "�Է��� ���ڿ�: " << str4 << endl;
	return 0;
}