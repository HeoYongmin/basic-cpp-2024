#include <iostream>
using namespace std;

class StudentClass {
    const int ID;             // 학번을 상수화
    char name[20];            // 문자열배열을 선언하고 바로 초기화하지 않는경우는 ctrcpy()를 통하여 초기화 한다.
    char major[20];
    int age;

public:
    // 문자열은 주소기 때문에 포인터 변수에 넣어서 사용한다. - 문장열의 첫번째 문자 주소가 저장된다.
    // 멤버이니셜라이즈는 객체 생성시 초기화되지않는 멤버들을 초기화할때 사용한다. 즉 객체 생성과 상관없이 미리 초기화가 되는 멤버들에 초기화
    StudentClass(int myid, const char* mname, const char* mmajor, int myage) : ID(myid) {    // 멤버 이니셜라이즈
       // ID = myid;
        strcpy_s(name, mname);                   // 문자열 배열을 선언하고 바로 초기화하지 않는경우는 strcpy()를 통하여 초기화 한다.
        strcpy_s(major, mmajor);
        age = myage;
    }
    // 문자열 배열을 선언하고 strcpy() 를 통해 
    void Showdata() const {

        cout << ID << ' ' << name << ' ' << major << ' ' << age << endl;

    }
};

int main(void) {
    StudentClass me(2052699, "허용민", "전자공학", 27);        // 객체를 생성하면 생성자를 호출해야 한다.
    me.Showdata();

    return 0;

}
