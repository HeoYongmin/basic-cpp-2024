#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n): num(n) { }
	void ShowData() { cout << num << endl; }

	Number* operator->()	// -> ������ �����ε�: ��ü �����͸� ��ȯ
	{
		return this;
	}

	Number& operator*()		// * ������ �����ε�: ��ü�� ���۷����� ��ȯ
	{
		return *this;
	}
};

int main(void)
{
	Number num(20);
	num.ShowData();

	(*num) = 30;		// * �����ڸ� �̿��Ͽ� ��ü�� ��� ������ �����Ͽ� �� ����
	num->ShowData();
	(*num).ShowData();
	return 0;
}