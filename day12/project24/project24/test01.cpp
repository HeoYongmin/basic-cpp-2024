#include <iostream>
#include <string>
using namespace std;

class Product {             // 객체 변수
protected:
    string id;
    int price;
    string producer;

public:
    Product(string id, int price, string producer) {
        this->id = id;                      // 입력된 id를 멤버 변수에 할당
        this->price = price;                // 입력된 price를 멤버 변수에 할당
        this->producer = producer;          // 입력된 producer를 멤버 변수에 할당
    }

    void ShowProductInfo() {
        cout << "ID : " << id << "  Price : " << price << "  Producer : " << producer << endl;
    }
    string GetID() {
        return id;
    }
};

class Book : public Product {
private:
    int ISBN;
    string title;

public:
    Book(string id, int price, string producer, int ISBN, string title) : Product(id, price, producer) {
        this->ISBN = ISBN;
        this->title = title;
    }
    void ShowBookInfo() {
        ShowProductInfo();
        cout << "ISBN : " << ISBN << "  Title : " << title << endl;
    }

};

class Handphone : public Product {
private:
    string model;
    int RAM;

public:
    Handphone(string id, int price, string producer, string model, int RAM) : Product(id, price, producer) {
        this->model = model;
        this->RAM = RAM;
    }
    void ShowHandphoneInfo() {
        ShowProductInfo();
        cout << "Model : " << model << " RAM : " << RAM << endl;
    }
};

class Computer : public Product {
private:
    string model;
    int RAM;
    int cpu;

public:
    Computer(string id, int price, string producer, string model, int RAM, int cpu) : Product(id, price, producer) {
        this->model = model;
        this->RAM = RAM;
        this->cpu = cpu;
    }
    void ShowComputerInfo() {
        ShowProductInfo();
        cout << "Model : " << model << "  RAM : " << RAM << " CPU : " << cpu << endl;
    }
};

int main()
{
    string id;
    int price;
    string producer;
    int choice;
    int bcount = 0;
    int hcount = 0;
    int ccount = 0;
    Book* book=nullptr;               //  Book 포인터 초기화
    Handphone* handphone = nullptr;     // Handphone 포인터 초기화
    Computer* computer = nullptr;       // Computer 포인터 초기화

    while (true) {
        cout << "------------ 상품관리 프로그램 ------------" << endl;
        cout << "1. 상품추가     2.상품조회         3. 종료" << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "ID를 입력해주세요" << endl;
            cin >> id;
            cout << " 가격을 입력해주세요" << endl;
            cin >> price;
            cout << "제조사를 입력해주세요" << endl;
            cin >> producer;

            cout << " 추가할 상품을 선택해주세요" << endl;
            cout << "1. 책      2. 핸드폰       3.컴퓨터" << endl;
            cin >> choice;
            if (choice == 1) {
                int ISBN;
                string title;
                cout << "책을 선택하였습니다." << endl;
                cout << "ISBN을 입력해주세요" << endl;
                cin >> ISBN;
                cout << "제목을 입력해주세요" << endl;
                cin >> title;
                book = new Book(id, price, producer, ISBN, title);  // 동적으로 할당된 메모리 공간에 새로운 Book 객체를 생성
                bcount += 1;
            }
            else if (choice == 2) {
                string model;
                int RAM;
                cout << " 핸드폰을 선택하였습니다." << endl;
                cout << "Model을 입력해주세요" << endl;
                cin >> model;
                cout << "RAM을 입력해주세요" << endl;
                cin >> RAM;
                handphone = new Handphone(id, price, producer, model, RAM);
                hcount += 1;
            }
            else if (choice == 3) {
                string model;
                int cpu;
                int RAM;
                cout << "컴퓨터를 선택하였습니다." << endl;
                cout << "모델을 입력해주세요" << endl;
                cin >> model;
                cout << "RAM을 입력해주세요" << endl;
                cin >> RAM;
                cout << "CPU를 입력해주세요" << endl;
                cin >> cpu;
                computer = new Computer(id, price, producer, model, RAM, cpu);
                ccount += 1;
            }
        }
        else if (choice == 2) {
            cout << "상품조회를 선택하였습니다." << endl;
            // nullptr이 아니라면, 즉 이미 어떤 객체를 가리키고 있다면 해당 객체가 생성되었음을 의미 이 경우에는 해당 객체의 정보를 출력
            if (book != nullptr) {
                cout << "책 정보:" << endl;
                for (int i = 0; i < bcount; i++) {

                    book->ShowBookInfo();
                }
            }
            if (handphone != nullptr) {
                cout << "핸드폰 정보:" << endl;
                handphone->ShowHandphoneInfo();
            }
            if (computer != nullptr) {
                cout << "컴퓨터 정보:" << endl;
                computer->ShowComputerInfo();
            }
        }
        else if (choice == 3) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
    }
    // new를 사용하여 동적으로 할당된 객체를 가리킨 것을 delete를 사용함으로써 동적으로 할당된 메모리를 해제
    delete book;
    delete handphone;
    delete computer;

    return 0;
}