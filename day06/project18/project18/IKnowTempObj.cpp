#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	// �����ڸ� ���� num ��� ������ �ʱ�ȭ�ϰ� ��ü�� ������ �� "create obj: "�� �ش� ��ü�� num ���� ���
	{
		cout << "create obj: " << num << endl;
	}
	~Temporary()
	// �Ҹ��ڸ� ���� ��ü�� �Ҹ�� �� "destroy obj: "�� �ش� ��ü�� num ���� ���
		{
			cout << "destory obj: " << num << endl;
		}
	void ShowTempInfo() 
	{
		cout << "My num is " << num << endl;
		}
};
int main(void)
{
	Temporary(100);   // Temporary t(100) �ӽð�ü
	// Temporary Ŭ������ �ӽ� ��ü�� ����, �����ڰ� ȣ��Ǿ� "create obj: 100"�� ��µ˴ϴ�. �׷��� �� ��ü�� ���� ������ �����Ͱ� �����Ƿ�, ���Ŀ� ������ �ʰ� ��� �ı�
	cout << "********** after make!" << endl << endl;

	Temporary(200).ShowTempInfo();
	// �ӽ� ��ü�� �����ϰ� ShowTempInfo() �Լ��� ȣ���Ͽ� �ش� ��ü�� num ���� ���
	cout << "********** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);
	cout << "********** end of main!" << endl << endl;
	return 0;
}