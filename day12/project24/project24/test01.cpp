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
	Product(int mid, double mprice, string mproducer) : id(mid), price(mprice), producer(mproducer) {}  // ������, ��� �������� �ʱ�ȭ
	// virtual�� ����Ͽ� �� �Լ��� �Ļ� Ŭ������ ������ �� �� ������ ��Ÿ��
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
	void ShowInfo() const override {	// 13�࿡ virtual ����ؾ� ���� �ȶ�
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
        cout << "-----��ǰ���� ���α׷�-----" << endl;
        cout << "1. ��ǰ �߰�" << endl;
        cout << "2. ��ǰ ���" << endl;
        cout << "3. ��ǰ ��ȸ" << endl;
        cout << "0. ����" << endl;
        cout << "�޴��� �����ϼ���: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "1. å �߰� 2. �ڵ��� �߰� 3. ��ǻ�� �߰�" << endl;
            cout << "�߰��� ��ǰ�� �����ϼ���: ";
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

            cout << "ID�� �Է��ϼ���: ";
            cin >> id;
            cout << "������ �Է��ϼ���: ";
            cin >> price;
            cout << "�����ڸ� �Է��ϼ���: ";
            cin >> producer;

            switch (productChoice) {
            case 1:
                cout << "ISBN�� �Է��ϼ���: ";
                cin >> ISBN;
                cout << "���ڸ� �Է��ϼ���: ";
                cin >> author;
                cout << "������ �Է��ϼ���: ";
                cin >> title;
                products[numProducts++] = new Book(id, price, producer, ISBN, author, title);
                break;
            case 2:
                cout << "���� �Է��ϼ���: ";
                cin >> model;
                cout << "RAM�� �Է��ϼ���: ";
                cin >> RAM;
                products[numProducts++] = new Handphone(id, price, producer, model, RAM);
                break;
            case 3:
                cout << "���� �Է��ϼ���: ";
                cin >> model;
                cout << "CPU�� �Է��ϼ���: ";
                cin >> model;
                cout << "RAM�� �Է��ϼ���: ";
                cin >> RAM;
                products[numProducts++] = new Computer(id, price, producer, model, model, RAM);
                break;
            default:
                cout << "�߸��� �����Դϴ�." << endl;
            }
            break;
        }
        case 2:
            cout << "��ǰ ��� ���" << endl;
            for (int i = 0; i < numProducts; ++i) {
                cout << i + 1 << ". ";
                products[i]->ShowInfo();
            }
            break;
        case 3:
            cout << "��ǰ ��ȸ" << endl;
            // ���⿡ ��ǰ ��ȸ ����� �߰��ϼ���.
            break;
        case 0:
            cout << "���α׷��� �����մϴ�." << endl;
            return 0;
        default:
            cout << "�߸��� �����Դϴ�." << endl;
        }
    }

    return 0;
}