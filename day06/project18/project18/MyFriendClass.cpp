#include <iostream>
#include <cstring>             // strcpy�Լ��� ����ϱ� ���ؼ�
using namespace std;

class Girl;

class Boy
{
private:
	int height;
	friend class Girl;						// Girl Ŭ������ Boy Ŭ������ private ����� ������ �� �ֵ��� �մϴ�.
public:
	Boy(int len) : height(len)				// Boy Ŭ������ �����ڸ� �����մϴ�. �� �����ڴ� ������ �Ű����� len�� �޾Ƶ鿩 height ��� ������ �ʱ�ȭ
	{ }
	void ShowYourFriendInfo(Girl& frn);
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char* num)			// Girl Ŭ������ �����ڸ� �����մϴ�. �� �����ڴ� ���ڿ� �Ű����� num�� �޾Ƶ鿩 phNum ��� ������ ����
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

