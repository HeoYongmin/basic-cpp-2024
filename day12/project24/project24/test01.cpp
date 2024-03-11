#include <iostream>
#include <string>
using namespace std;

class Product {             // ��ü ����
protected:
    string id;
    int price;
    string producer;

public:
    Product(string id, int price, string producer) {
        this->id = id;                      // �Էµ� id�� ��� ������ �Ҵ�
        this->price = price;                // �Էµ� price�� ��� ������ �Ҵ�
        this->producer = producer;          // �Էµ� producer�� ��� ������ �Ҵ�
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
    Book* book=nullptr;               //  Book ������ �ʱ�ȭ
    Handphone* handphone = nullptr;     // Handphone ������ �ʱ�ȭ
    Computer* computer = nullptr;       // Computer ������ �ʱ�ȭ

    while (true) {
        cout << "------------ ��ǰ���� ���α׷� ------------" << endl;
        cout << "1. ��ǰ�߰�     2.��ǰ��ȸ         3. ����" << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "ID�� �Է����ּ���" << endl;
            cin >> id;
            cout << " ������ �Է����ּ���" << endl;
            cin >> price;
            cout << "�����縦 �Է����ּ���" << endl;
            cin >> producer;

            cout << " �߰��� ��ǰ�� �������ּ���" << endl;
            cout << "1. å      2. �ڵ���       3.��ǻ��" << endl;
            cin >> choice;
            if (choice == 1) {
                int ISBN;
                string title;
                cout << "å�� �����Ͽ����ϴ�." << endl;
                cout << "ISBN�� �Է����ּ���" << endl;
                cin >> ISBN;
                cout << "������ �Է����ּ���" << endl;
                cin >> title;
                book = new Book(id, price, producer, ISBN, title);  // �������� �Ҵ�� �޸� ������ ���ο� Book ��ü�� ����
                bcount += 1;
            }
            else if (choice == 2) {
                string model;
                int RAM;
                cout << " �ڵ����� �����Ͽ����ϴ�." << endl;
                cout << "Model�� �Է����ּ���" << endl;
                cin >> model;
                cout << "RAM�� �Է����ּ���" << endl;
                cin >> RAM;
                handphone = new Handphone(id, price, producer, model, RAM);
                hcount += 1;
            }
            else if (choice == 3) {
                string model;
                int cpu;
                int RAM;
                cout << "��ǻ�͸� �����Ͽ����ϴ�." << endl;
                cout << "���� �Է����ּ���" << endl;
                cin >> model;
                cout << "RAM�� �Է����ּ���" << endl;
                cin >> RAM;
                cout << "CPU�� �Է����ּ���" << endl;
                cin >> cpu;
                computer = new Computer(id, price, producer, model, RAM, cpu);
                ccount += 1;
            }
        }
        else if (choice == 2) {
            cout << "��ǰ��ȸ�� �����Ͽ����ϴ�." << endl;
            // nullptr�� �ƴ϶��, �� �̹� � ��ü�� ����Ű�� �ִٸ� �ش� ��ü�� �����Ǿ����� �ǹ� �� ��쿡�� �ش� ��ü�� ������ ���
            if (book != nullptr) {
                cout << "å ����:" << endl;
                for (int i = 0; i < bcount; i++) {

                    book->ShowBookInfo();
                }
            }
            if (handphone != nullptr) {
                cout << "�ڵ��� ����:" << endl;
                handphone->ShowHandphoneInfo();
            }
            if (computer != nullptr) {
                cout << "��ǻ�� ����:" << endl;
                computer->ShowComputerInfo();
            }
        }
        else if (choice == 3) {
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }
    }
    // new�� ����Ͽ� �������� �Ҵ�� ��ü�� ����Ų ���� delete�� ��������ν� �������� �Ҵ�� �޸𸮸� ����
    delete book;
    delete handphone;
    delete computer;

    return 0;
}