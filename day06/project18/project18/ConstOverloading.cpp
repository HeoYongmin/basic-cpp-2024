#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{ }
	SoSimple& AddNum(int n) //AddNum �Լ��� ������ �Ű������� �޾Ƶ鿩 num ��� ������ ���� ���� �� ��ü �ڽ��� ��ȯ
	{
		num += n;
		return *this;
	}
	void SimpleFunc()
	{
		cout << "Simplefunc: " << num << endl;
	}
	void SimpleFunc() const
	{
		cout << "const SimpleFunc: " << num << endl;
	}
};

void YorFunc(const SoSimple& obj)
{
	obj.SimpleFunc();
}

int main(void)
{
	SoSimple obj1(2);
	const SoSimple obj2(7);

	obj1.SimpleFunc();
	obj2.SimpleFunc();

	YorFunc(obj1);
	YorFunc(obj2);
	return 0;
}