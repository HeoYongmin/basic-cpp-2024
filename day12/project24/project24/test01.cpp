#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product
{
protected:
	int id;
	double price;
	string producer;
public:
	Product(int mid, double mprice, string mproducer) : id(mid), price(mprice), producer(mproducer) {}  // 생성자, 멤버 변수들을 초기화
	// virtual을 사용하여 이 함수가 파생 클래스에 재정의 될 수 있음을 나타냄
    virtual void ShowInfo() const {
		cout << "ID" << id << ", Price " << price << ", Producer" << producer << endl;
	}
};

class Book : public Product {
private:
	string ISBN;
	string author;
	string title;
public:
	Book(int mid, double mprice, string mproducer, string mISBN, string mauthor, string mtitle):
		Product(mid, mprice, mproducer), ISBN(mISBN), author(mauthor), title(mtitle) {}
	void ShowInfo() const override {	// 13행에 virtual 사용해야 오류 안뜸
		Product::ShowInfo();	
		cout << "ISBN" << ISBN << ", Author" << author << ", Title" << title << endl;
	}
};

class Handphone : public Product {
private:
	string model;
	int RAM;
public:
	Handphone(int mid, double mprice, string mprodeucer, string mmodel, int mRAM) :
		Product(mid, mprice, mprodeucer), model(mmodel), RAM(mRAM) {}
	void ShowInfo() const override {
		Product::ShowInfo();
		cout << "Model" << model << ", RAM" << RAM << endl;
	}
};

class Computer : public Product {
private:
	string model;
	string cpu;
	int RAM;
public:
	Computer(int mid, double mprice, string mproducer, string mmodel, string mcpu, int mRAM):
		Product(mid, mprice, mproducer), model(mmodel), cpu(mcpu), RAM(mRAM) {}
	void ShowInfo() const override {
		Product::ShowInfo();
		cout << "Model" << model << ", CPU" << cpu << ", RAM" << RAM << endl;
	}
};

int main() {
    Product* products[100];
    int numProducts = 0;

    while (true) {
        cout << "-----상품관리 프로그램-----" << endl;
        cout << "1. 상품 추가" << endl;
        cout << "2. 상품 출력" << endl;
        cout << "3. 상품 조회" << endl;
        cout << "0. 종료" << endl;
        cout << "메뉴를 선택하세요: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "1. 책 추가 2. 핸드폰 추가 3. 컴퓨터 추가" << endl;
            cout << "추가할 상품을 선택하세요: ";
            int productChoice;
            cin >> productChoice;

            int id;
            double price;
            string producer;
            string model;
            int RAM;
            string ISBN;
            string author;
            string title;

            cout << "ID를 입력하세요: ";
            cin >> id;
            cout << "가격을 입력하세요: ";
            cin >> price;
            cout << "생산자를 입력하세요: ";
            cin >> producer;

            switch (productChoice) {
            case 1:
                cout << "ISBN을 입력하세요: ";
                cin >> ISBN;
                cout << "저자를 입력하세요: ";
                cin >> author;
                cout << "제목을 입력하세요: ";
                cin >> title;
                products[numProducts++] = new Book(id, price, producer, ISBN, author, title);
                break;
            case 2:
                cout << "모델을 입력하세요: ";
                cin >> model;
                cout << "RAM을 입력하세요: ";
                cin >> RAM;
                products[numProducts++] = new Handphone(id, price, producer, model, RAM);
                break;
            case 3:
                cout << "모델을 입력하세요: ";
                cin >> model;
                cout << "CPU를 입력하세요: ";
                cin >> model;
                cout << "RAM을 입력하세요: ";
                cin >> RAM;
                products[numProducts++] = new Computer(id, price, producer, model, model, RAM);
                break;
            default:
                cout << "잘못된 선택입니다." << endl;
            }
            break;
        }
        case 2:
            cout << "상품 목록 출력" << endl;
            for (int i = 0; i < numProducts; ++i) {
                cout << i + 1 << ". ";
                products[i]->ShowInfo();
            }
            break;
        case 3:
            cout << "상품 조회" << endl;
            // 여기에 상품 조회 기능을 추가하세요.
            break;
        case 0:
            cout << "프로그램을 종료합니다." << endl;
            return 0;
        default:
            cout << "잘못된 선택입니다." << endl;
        }
    }

    return 0;
}