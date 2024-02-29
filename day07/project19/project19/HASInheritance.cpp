#include <iostream>
#include <cstring>
using namespace std;

class Gun
	// Gun(�θ�Ŭ����)���� ������ private���� �����ϸ� ������ �ڽ� Ŭ�������� ��������
			// �θ�Ŭ������ ������ ���� ���ؼ� ���� ������ protected�� �����Ѵ�
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void shot()
	{
		cout << "BBANG!" << endl;	//���� �߻��ϴ� �޼����Դϴ�. "BBANG!"�� ����ϰ� �Ѿ��� ������ ���ҽ�ŵ�ϴ�.
		bullet--;
	}
	int getbullet()
	{
		return bullet;
	}
};

class Police : public Gun
{
private:
	int handcuffs;							// ������ ������ ��
public:
	Police(int bnum, int bcuff) //�����ڸ� �����մϴ�. ���ڷ� ���� �Ѿ� ������ ���� ������ ���� Gun Ŭ������ �����ڿ� �ʱ�ȭ ����Ʈ�� ���� �ʱ�ȭ
		: Gun(bnum), handcuffs(bcuff)
	{ }
	void PutHandcuff() //���� ä��� �޼����Դϴ�. "SNAP!"�� ����ϰ� ������ ������ ����
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void state()
	{
		cout << getbullet() << ", " << handcuffs << endl;
	}
		
};

int main(void)
{
	Police pman(5, 3);
	pman.state();
	pman.shot();
	pman.PutHandcuff();
	pman.state();
	return 0;
}

