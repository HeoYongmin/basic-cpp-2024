#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "New Object: " << this << endl;
	}
	SoSimple(const SoSimple& copy) : num(copy.num)
	{
		cout << "New Copy obj:" << this << endl;
	}
	~SoSimple()
	{
		cout << "Destory obj: " << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)
{
	cout << "Parm ADR: " << &ob << endl;
	return ob;
}

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj);

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj);				// �ӽð�ü �ּ�����
	cout << "Return obj " << &tempRef << endl;
	return 0;
}


//New Object: 0000000C4F9AFA44: ��ü obj�ּ�
//New Copy obj : 0000000C4F9AFB44: ��ü ob�ּ�
//Parm ADR : 0000000C4F9AFB44: ��üob�ּ�
//New Copy obj : 0000000C4F9AFB84: �ӽð�ü �ּ�
//Destory obj : 0000000C4F9AFB44: ��üob�Ҹ�
//Destory obj : 0000000C4F9AFB84: �ӽð�ü �Ҹ�

//New Copy obj : 0000000C4F9AFBA4 : ��ü ob�ּ�
//Parm ADR : 0000000C4F9AFBA4 : SimpleFuncObj ������ �Ű������� ���� ��üob�� �ּ�
//New Copy obj : 0000000C4F9AFA64 : SimpleFuncObj�� �������� ��, ��ȯ�� ��ü�� ���纻�� ����, �ӽð�ü �ּ�
//Destory obj : 0000000C4F9AFBA4 : ������ ������ ��ü�� �Ҹ�� ��, �ش� ��ü�� �޸� �ּ�, ��üob�Ҹ�
//Return obj 0000000C4F9AFA64: SimpleFuncObj �Լ��� ��ȯ������ ������ ��ü�� �ּ�
//Destory obj : 0000000C4F9AFA64 : �ӽð�ü �Ҹ�
//Destory obj : 0000000C4F9AFA44 : ��üobj�Ҹ�