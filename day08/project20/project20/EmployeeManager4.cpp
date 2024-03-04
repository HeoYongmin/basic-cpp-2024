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
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
    virtual int GetPay() const
    {
        return 0;
    }
    virtual void ShowSalaryInfo() const
    { }
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

class TemporaryWorker : public Employee
{
private:
    int workTime; // 이 달에 일한 시간의 합계
    int payPerHour; // 시간당 급여
public:
    TemporaryWorker(const char* name, int pay)
        : Employee(name), workTime(0), payPerHour(pay)
    { }
    void AddWorkTime(int time)  // 일한 시간의 추가
    {
        workTime += time;
    }
    int GetPay() const // 이 달의 급여
    {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary:" << GetPay() << endl << endl;
    }
};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult;  // 월 판매실적
    double bonusRatio;  // 상여금 비율
public:
    SalesWorker(const char* name, int money, double ratio)
        : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    { }
    void AddSalesResult(int value)
    {
        salesResult += value;
    }
    int GetPay() const
    {
        cout << "SalesWorker" << endl;          // 오버라이딩된 멤버함수는 자식것이 실행된다.
        return PermanentWorker::GetPay()        // 따라서 재정의된 부모것을 호출할려면 PermanentWorker(부모)의 GetPay 함수 호출
            + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary:" << GetPay() << endl << endl;      // SalesWorker의 GetPay 함수가 호출
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
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    // 등록된 모든 직원의 총 월급을 출력하는 함수
    void ShowTotalSalary() const
    {
        int sum = 0; // 총 월급을 저장하는 변수 초기화
        // 등록된 모든 직원의 월급을 더함
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
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
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
    EmployeeHandler handler;

    // 직원 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    // 임시직 등록
    TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);   // 5시간 일한결과 등록
    handler.AddEmployee(alba);

    // 영업직 등록
    SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);       // 영업실적 7000
    handler.AddEmployee(seller);

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalary();
    return 0;
}