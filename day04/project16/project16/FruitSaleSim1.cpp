#include <iostream>
using namespace std;    // 이름 공간 설정 cout와 endl을 사용하기 위해서

class FruitSeller
{
private:                // 속성
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:   
	void InitMembers(int price, int num, int money)    // InitMembers: 위에 있는값들을 초기화    나중에 배울 생성자의 개념과 비슷(기능: 객체를 생성하고 초기화)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)    // money라는 값을 입력
	{
		int num = money / APPLE_PRICE;   // 판매 갯수
		numOfApples -= num;              // 남은 사과 갯수  /  -=: 복합대비 연산자
		myMoney += money;                // 번 돈, myMoney = myMoney + money;
		return num;
	}
	void ShowSalesResult()
	{
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매수익: " << myMoney << endl << endl;
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
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);   

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}