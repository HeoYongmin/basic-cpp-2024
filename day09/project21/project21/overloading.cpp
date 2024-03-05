#include <iostream>
using namespace std;


class Myclass
{
private:
	int num;
public:
	// ������ Myclass(int n=0)�� ��ü�� �ʱ�ȭ�� �� ���Ǹ�, �Ű����� n�� �޾� ��ü�� num ��� ������ ���� �Ҵ�. �Ű������� ���޵��� ������ �⺻������ 0�� �Ҵ�˴ϴ�.
	Myclass(int n=0) : num(n)
	{ }
	Myclass operator+(const Myclass& other) const	// operator+ �Լ��� �� ���� Myclass ��ü�� ���� ����� ��ȯ�ϴ� ������ �����ε� �Լ�
	{
		return Myclass(num + other.num);
	}
	void print() const
	{
		cout << "num: " << num << endl;
	}

};

int main()
{
	Myclass a(10);
	a.print();				// value: 10

	Myclass b(a);
	b.print();				// value: 10

	Myclass c = b;
	b.print();				// value: 10

	Myclass d = a + b + c;
	d.print();				// value: 30
	return 0;
}