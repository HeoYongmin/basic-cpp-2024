#include <iostream>
using namespace std;

class Remotecontrol
{
public:
	virtual void on() { std::cout << "TV를 켭니다" << std::endl; }   //가상함수로 만들지 않으면 TV를 켭니다가 출력된다

};

class SamsungTv : public Remotecontrol
{
public:
	void on() { std::cout << "삼성TV를 켭니다." << std::endl; }

};

class LGTv : public Remotecontrol
{
public:
	void on() { std::cout << "LG TV를 켭니다." << std::endl; }

};

int main()
{
	Remotecontrol* remote = new SamsungTv();		// Remotecontrol이 부모함수여서 그걸 따라가게 된다.
	remote->on();

	remote = new LGTv();
	remote->on();

	delete remote;
}
