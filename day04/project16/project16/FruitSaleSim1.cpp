#include <iostream>
using namespace std;    // �̸� ���� ���� cout�� endl�� ����ϱ� ���ؼ�

class FruitSeller
{
private:                // �Ӽ�
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:   
	void InitMembers(int price, int num, int money)    // InitMembers: ���� �ִ°����� �ʱ�ȭ    ���߿� ��� �������� ����� ���(���: ��ü�� �����ϰ� �ʱ�ȭ)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)    // money��� ���� �Է�
	{
		int num = money / APPLE_PRICE;   // �Ǹ� ����
		numOfApples -= num;              // ���� ��� ����  /  -=: ���մ�� ������
		myMoney += money;                // �� ��, myMoney = myMoney + money;
		return num;
	}
	void ShowSalesResult()
	{
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹż���: " << myMoney << endl << endl;
	}
};

class FruitBuyer
{
	int myMoney;
	int numOfApples;

public:
	void InitMembers(int money)
	{
		myMoney = money;    // private:
		numOfApples = 0;    // private:
	}
	void BuyApples(FruitSeller& refseller, int money)        // int& num = n;
	{
		numOfApples += refseller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult()
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);   

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return 0;
}