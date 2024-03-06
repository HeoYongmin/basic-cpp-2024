#include <iostream>
using namespace std;

class AAA
{
private:
	int num;			// AAA Ŭ������ private ��� ������, ������ ����
public:
	AAA(int n = 0) : num(n)	// �����ڷ�, ������ �Ű������� �޾� ��� ���� num�� �ʱ�ȭ�մϴ�. �� �����ڴ� �Ű������� ���� ���� ��� �⺻������ 0�� ���
	{
		cout << "AAA(int n=0)" << endl;
	}
	AAA(const AAA& ref) : num(ref.num)	// ���� �����ڷ�, AAA Ŭ������ ��ü�� �����Ͽ� ���ο� ��ü�� ����
	{
		cout << "AAA(const AAA& ref)" << endl;	// ���� ������ �����ε� �Լ���, AAA Ŭ������ ��ü�� �ٸ� AAA ��ü�� ������ �� ȣ��Ǵ� �Լ�
	}
	AAA& operator=(const AAA& ref)
	{
		num = ref.num;
		cout << "operator=(const AAA& ref)" << endl;
		return *this;
	}
};

class BBB
{
private:
	AAA mem;		// AAA Ŭ������ ��ü�� ����� �����ϴ�.
public:
	BBB(const AAA& ref): mem(ref) { }	// AAA Ŭ������ ��ü�� �Ű������� �޾� ��� ��ü mem�� �ʱ�ȭ / ��� �̴ϼȶ�����(�ݷ� �ʱ�ȭ)�� ���ؼ� �ʱ�ȭ
};

class CCC
{
private:
	AAA mem;
public:
	CCC(const AAA& ref) { mem = ref; }	// AAA Ŭ������ ��ü�� �Ű������� �޾�, ���� �����ڸ� �̿��Ͽ� ��� ��ü mem�� �ʱ�ȭ
};

int main(void)
{
	AAA obj1(12);
	cout << "**********************" << endl;
	BBB obj2(obj1);
	cout << "************************" << endl;
	CCC obj3(obj1);
	return 0;
}

// �迭�̸� ary�� �迭�� �����ּ��̴�.
int ary[3]; // �迭����ο��� �迭 �ε����� �ִ� ���ڴ� ����ũ��
ary[2]; //�ڵ� ���࿡�� �迭 �ε����� �ִ� ���ڴ� �� ��ȣ�� ��Ÿ����.

ary[0] = 10;	//0����, ù��°���� ������
*(ary + 0) = 10;  // *(�迭�� �����ּ� + 0) = 10

*(ary + 1) = 20; == ary[1] = 20;		// 1���濡�ٰ� 20�� ����־��

ary�� �ּҰ� 0x0011 �̶�� ������, 1����(�ι�°��) �ּҴ� 0x0115�̴�.