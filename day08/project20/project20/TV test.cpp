#include <iostream>
using namespace std;

class Remotecontrol
{
public:
	virtual void on() { std::cout << "TV�� �մϴ�" << std::endl; }   //�����Լ��� ������ ������ TV�� �մϴٰ� ��µȴ�

};

class SamsungTv : public Remotecontrol
{
public:
	void on() { std::cout << "�ＺTV�� �մϴ�." << std::endl; }

};

class LGTv : public Remotecontrol
{
public:
	void on() { std::cout << "LG TV�� �մϴ�." << std::endl; }

};

int main()
{
	Remotecontrol* remote = new SamsungTv();		// Remotecontrol�� �θ��Լ����� �װ� ���󰡰� �ȴ�.
	remote->on();

	remote = new LGTv();
	remote->on();

	delete remote;
}
