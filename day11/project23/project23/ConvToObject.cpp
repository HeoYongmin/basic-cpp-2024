#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n = 0) : num(n) // ������ ����: ���ڷ� ���� ������ num�� �ʱ�ȭ
	{
		cout << "Number(int n=0)" << endl;
	}
	Number& operator=(const Number& ref)	// ���� ������ �����ε� ����
	{
		cout << "operator=()" << endl;
		num = ref.num;		 // num�� ref.num ���� ����
		return *this;		// ���� ��ü�� ������ ��ȯ
	}
	void ShowNumber() { cout << num << endl; }
};

int main(void)
{
	Number num;		// Number Ŭ������ ��ü ����, �Ű������� �������� �ʾ� �⺻������ �ʱ�ȭ
	num = 30;
	num.ShowNumber();
	return 0;
}