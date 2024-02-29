#include <iostream>
#include<string>
using namespace std;

class Person {
private:
    char* name;
    int age;

public:
    Person(const char* myname, int myage) {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    Person(const Person& copy) : age(copy.age) {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
    }
    ~Person() {
        delete name;
        cout << "������ ����" << this << endl;
    }

    void personInfo() {
        cout << "�̸� : " << name << endl;
        cout << "���� : " << age << endl;
    }
};





int main(void) {

    Person p("����", 27);
    p.personInfo();

    Person copyp(p);
    copyp.personInfo();

    return 0;
}
