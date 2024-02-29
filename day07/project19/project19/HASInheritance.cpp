#include <iostream>
#include <cstring>
using namespace std;

class Gun
	// Gun(부모클래스)에서 변수를 private으로 선언하면 변수를 자식 클래스에서 쓸수없음
			// 부모클래스의 변수를 쓰기 위해서 변수 선언을 protected로 선언한다
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void shot()
	{
		cout << "BBANG!" << endl;	//총을 발사하는 메서드입니다. "BBANG!"을 출력하고 총알의 개수를 감소시킵니다.
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
	int handcuffs;							// 소유한 수갑의 수
public:
	Police(int bnum, int bcuff) //생성자를 정의합니다. 인자로 받은 총알 개수와 수갑 개수를 각각 Gun 클래스의 생성자와 초기화 리스트를 통해 초기화
		: Gun(bnum), handcuffs(bcuff)
	{ }
	void PutHandcuff() //갑을 채우는 메서드입니다. "SNAP!"을 출력하고 수갑의 개수를 감소
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

