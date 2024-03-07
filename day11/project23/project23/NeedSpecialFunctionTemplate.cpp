#include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b)
{
	// a�� b�� ���Ͽ� �� ū ���� ��ȯ
	return a > b ? a : b;
}

int main(void)
{
	// �� ������ �μ��� Max �Լ� ȣ���Ͽ� �� ū �� ���
	cout << Max(11, 15) << endl;
	// �� ���ڸ� �μ��� Max �Լ� ȣ���Ͽ� ASCII ���� ū ���� ���
	cout << Max('T', 'Q') << endl;
	// �� �Ǽ��� �μ��� Max �Լ� ȣ���Ͽ� �� ū �� ���
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;
	return 0;
}