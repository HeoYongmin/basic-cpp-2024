#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
    char name[100]; // 직원의 이름을 저장하는 문자열 배열
public:
    // 직원 객체를 생성할 때 이름을 초기화하는 생성자
    Employee(const char* name)
    {
        strcpy(this->name, name);
    }
    // 직원의 이름을 출력하는 함수
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
};

class PermanentWorker : public Employee
{
private:
    int salary; // 직원의 월급을 저장하는 변수
public:
    // PermanentWorker 객체를 생성할 때 이름과 월급을 초기화하는 생성자
    PermanentWorker(const char* name, int money)
        : Employee(name), salary(money)
    { }
    // 직원의 월급을 반환하는 함수
    int GetPay() const
    {
        return salary;
    }
    // 직원의 이름과 월급을 출력하는 함수
    void ShowSalaryInfo() const
    {
        ShowYourName(); // 직원의 이름 출력
        cout << "salary: " << GetPay() << endl << endl; // 직원의 월급 출력
    }
};

class EmployeeHandler
{
private:
    Employee* empList[50]; // Employee 객체의 포인터 배열
    int empNum; // 등록된 직원 수를 저장하는 변수
public:
    // EmployeeHandler 객체를 생성할 때 직원 수를 초기화하는 생성자
    EmployeeHandler() : empNum(0)
    { }
    // 직원을 등록하는 함수
    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp; // 직원을 배열에 등록하고 직원 수를 증가시킴
    }
    // 등록된 모든 직원의 월급 정보를 출력하는 함수
    void ShowAllSalaryInfo() const
    {
        // 등록된 모든 직원의 월급 정보 출력
        /*for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();*/
    }
    // 등록된 모든 직원의 총 월급을 출력하는 함수
    void ShowTotalSalary() const
    {
        int sum = 0; // 총 월급을 저장하는 변수 초기화
        // 등록된 모든 직원의 월급을 더함
        /*for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();*/
        cout << "salary sum: " << sum << endl; // 총 월급 출력
    }
    // 소멸자: 등록된 모든 직원 객체를 메모리에서 해제
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main(void)
{
    // 직원 관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
    EmployeeHandler handler;

    // 직원 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    // 이번 달에 지불해야 할 급여의 정보 출력
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 총 급여 출력
    handler.ShowTotalSalary();

    return 0;
}
