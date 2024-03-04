#include <iostream>
using namespace std;

class Remotecontrol
{
public:
	virtual void on() { cout << "Remotecontrol on" << endl; }
	
};

class SamsungTv : public Remotecontrol
{
public:
	void on() { cout << "SamsungTv on" << endl; }
	
};

class LGTv : public Remotecontrol
{
public:
	void on() { cout << "LGTv on" << endl; }

};

int main(void)
{
	SamsungTv* samsungPtr = new SamsungTv();
	Remotecontrol* remotePtr = samsungPtr;

	remotePtr->on();
	samsungPtr->on();
	delete remotePtr;

	LGTv* lgPtr = new LGTv();
	remotePtr = lgPtr;
	remotePtr->on();
	lgPtr->on();
	delete remotePtr;
	return 0;
}
