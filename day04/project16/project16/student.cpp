#include <iostream>
using namespace std;

class StudentClass {
    const int ID;             // �й��� ���ȭ
    char name[20];            // ���ڿ��迭�� �����ϰ� �ٷ� �ʱ�ȭ���� �ʴ°��� ctrcpy()�� ���Ͽ� �ʱ�ȭ �Ѵ�.
    char major[20];
    int age;

public:
    // ���ڿ��� �ּұ� ������ ������ ������ �־ ����Ѵ�. - ���忭�� ù��° ���� �ּҰ� ����ȴ�.
    // ����̴ϼȶ������ ��ü ������ �ʱ�ȭ�����ʴ� ������� �ʱ�ȭ�Ҷ� ����Ѵ�. �� ��ü ������ ������� �̸� �ʱ�ȭ�� �Ǵ� ����鿡 �ʱ�ȭ
    StudentClass(int myid, const char* mname, const char* mmajor, int myage) : ID(myid) {    // ��� �̴ϼȶ�����
       // ID = myid;
        strcpy_s(name, mname);                   // ���ڿ� �迭�� �����ϰ� �ٷ� �ʱ�ȭ���� �ʴ°��� strcpy()�� ���Ͽ� �ʱ�ȭ �Ѵ�.
        strcpy_s(major, mmajor);
        age = myage;
    }
    // ���ڿ� �迭�� �����ϰ� strcpy() �� ���� 
    void Showdata() const {

        cout << ID << ' ' << name << ' ' << major << ' ' << age << endl;

    }
};

int main(void) {
    StudentClass me(2052699, "����", "���ڰ���", 27);        // ��ü�� �����ϸ� �����ڸ� ȣ���ؾ� �Ѵ�.
    me.Showdata();

    return 0;

}
