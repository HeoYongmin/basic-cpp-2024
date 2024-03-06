#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
public:
	BoundCheckIntArray(int len) : arrlen(len)	// ������: �迭�� ���̸� �Ű������� �޾� �������� �迭�� �Ҵ�
	{
		printf("������ ȣ��\n");
		arr = new int[len];
	}
	// [] ������ �����ε�: �迭 ��ҿ� �����ϴ� �뵵�� ���
	int& operator[] (int idx)	
	{
		printf("[]������ �Լ� ȣ��\n");
		if (idx < 0 || idx >= arrlen) // �ε����� ��ȿ�� ������ ����� ���� �޽��� ��� �� ���α׷� ����
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		// ��ȿ�� �ε����� ��� �ش� �ε����� �迭 ��ҿ� ���� ���۷��� ��ȯ
		return arr[idx];
	}
	~BoundCheckIntArray()
	{
		printf("�Ҹ��� ȣ��\n");
		delete[]arr;
	}
};

int main(void)
{
	BoundCheckIntArray arr(5); // ���̰� 5�� BoundCheckIntArray ��ü ����
	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;
	for (int i = 0; i < 6; i++) // �ε����� 0���� 5���� 6�� �ݺ�
		cout << arr[i] << endl; // �迭�� �� ��� ��� (�ε����� ��ȿ���� ���� ��� ���� �߻�)
	return 0;
}