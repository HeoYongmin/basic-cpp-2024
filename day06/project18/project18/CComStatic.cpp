#include <iostream>
using namespace std;

void Counter()
{
	static int cnt; //���� ���� ���� cnt�� �����մϴ�. �� ������ �Լ��� ȣ��� ������ �ʱ�ȭ���� �ʰ�, ������ ����� ���� ����
	// int cnt = 0; �� ��� ����ϸ� cnt�� �Ź� �Լ��� ȣ��� ������ 0���� �ʱ�ȭ �ǹǷ� cnt�� 1�� ���� �׷��� ��������� ��µǴ� ���� �׻� 1
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main(void)
{
	for (int i = 0; i < 10; i++)	// i�� 0���� 9���� 1�� �����ϸ� �ݺ�
		Counter();
	return 0;
}