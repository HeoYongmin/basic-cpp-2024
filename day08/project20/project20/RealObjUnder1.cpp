#include <iostream>
using namespace std;

class Data
{
private:
	int data;
public:
	Data(int num): data(num)		// ������ ���� int�� ���ڸ� �޾� data ��� ������ �ش� ���� �Ҵ�
	{ }
	void ShowData() { cout << "Data:" << data << endl; }
	void Add(int num) { data += num; } // num ���ڸ� data ��� ������ ���մϴ�
};

int main(void)
{
	Data obj(15);	// Data Ŭ������ ��ü obj�� �����ϰ�, int�� �Ű����� 15�� ������ �ִ� �����ڸ� ȣ���Ͽ� �ʱ�ȭ�մϴ�.
	obj.Add(17);	// obj ��ü�� Add() �޼��带 ȣ���Ͽ� 17�� �μ��� �����ϰ�, �̸� data ��� ������ ���մϴ�.
	obj.ShowData();
	return 0;
}