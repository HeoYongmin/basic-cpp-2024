#include <iostream>
#include <cstring>             // strcpy함수를 사용하기 위해서
using namespace std;

class Girl;

class Boy
{
private:
	int height;
	friend class Girl;						// Girl 클래스가 Boy 클래스의 private 멤버에 접근할 수 있도록 합니다.
public:
	Boy(int len) : height(len)				// Boy 클래스의 생성자를 정의합니다. 이 생성자는 정수형 매개변수 len을 받아들여 height 멤버 변수를 초기화
	{ }
	void ShowYourFriendInfo(Girl& frn);
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char* num)			// Girl 클래스의 생성자를 정의합니다. 이 생성자는 문자열 매개변수 num을 받아들여 phNum 멤버 변수에 복사
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl& frn)
{
	cout << "Her phone number: " << frn.phNum << endl;
}
void Girl::ShowYourFriendInfo(Boy& frn)
{
	cout << "His height: " << frn.height << endl;
}

int main(void)
{
	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	return 0;
}

