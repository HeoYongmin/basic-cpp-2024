#include <iostream>
using namespace std;

class SoSimple
{
private:				// ������ ��� ���� num�� ����
	int num;
public:					// ������, ���� ������, ��� �Լ��� ����
	SoSimple(int n) : num(n)
	{ }
	SoSimple(const SoSimple& copy) : num(copy.num) 
		//���� �����ڴ� �ٸ� SoSimple ��ü�� �޾Ƶ鿩 num ��� ������ ���� �̶� ���� �����ڰ� ȣ��Ǹ� "Called SoSimple(const SoSimple& copy)" �޽����� ��µ˴ϴ�.
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}
	SoSimple& AddNum(int n)
		// AddNum �Լ��� ������ �Ű������� �޾Ƶ鿩 num ��� ������ ���� ���� �� ��ü �ڽ�(*this)�� ��ȯ
	{
		num += n;				//num = num + n;
		return *this;
	}
	void ShowData()
	{
		cout << "num: " << num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)
{
	cout << "return ����" << endl;
	return ob;
}

int main(void)
{
	SoSimple obj(7);
	// main �Լ������� SoSimple Ŭ������ ��ü obj�� ����, �� 7�� ���ڷ� �����Ͽ� �����ڸ� ȣ���Ͽ� num ��� ������ ���� �Ҵ��մϴ�.
	SimpleFuncObj(obj).AddNum(30).ShowData();
	// ��ȯ�� ��ü�� ���� AddNum �Լ��� ȣ���Ͽ� �� 30�� ���� �� ShowData �Լ��� ȣ���Ͽ� num ���� ���
	obj.ShowData();
	return 0;
}