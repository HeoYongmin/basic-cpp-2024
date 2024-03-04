#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
    char name[100]; // ������ �̸��� �����ϴ� ���ڿ� �迭
public:
    // ���� ��ü�� ������ �� �̸��� �ʱ�ȭ�ϴ� ������
    Employee(const char* name)
    {
        strcpy(this->name, name);
    }
    // ������ �̸��� ����ϴ� �Լ�
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
};

class PermanentWorker : public Employee
{
private:
    int salary; // ������ ������ �����ϴ� ����
public:
    // PermanentWorker ��ü�� ������ �� �̸��� ������ �ʱ�ȭ�ϴ� ������
    PermanentWorker(const char* name, int money)
        : Employee(name), salary(money)
    { }
    // ������ ������ ��ȯ�ϴ� �Լ�
    int GetPay() const
    {
        return salary;
    }
    // ������ �̸��� ������ ����ϴ� �Լ�
    void ShowSalaryInfo() const
    {
        ShowYourName(); // ������ �̸� ���
        cout << "salary: " << GetPay() << endl << endl; // ������ ���� ���
    }
};

class EmployeeHandler
{
private:
    Employee* empList[50]; // Employee ��ü�� ������ �迭
    int empNum; // ��ϵ� ���� ���� �����ϴ� ����
public:
    // EmployeeHandler ��ü�� ������ �� ���� ���� �ʱ�ȭ�ϴ� ������
    EmployeeHandler() : empNum(0)
    { }
    // ������ ����ϴ� �Լ�
    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp; // ������ �迭�� ����ϰ� ���� ���� ������Ŵ
    }
    // ��ϵ� ��� ������ ���� ������ ����ϴ� �Լ�
    void ShowAllSalaryInfo() const
    {
        // ��ϵ� ��� ������ ���� ���� ���
        /*for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();*/
    }
    // ��ϵ� ��� ������ �� ������ ����ϴ� �Լ�
    void ShowTotalSalary() const
    {
        int sum = 0; // �� ������ �����ϴ� ���� �ʱ�ȭ
        // ��ϵ� ��� ������ ������ ����
        /*for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();*/
        cout << "salary sum: " << sum << endl; // �� ���� ���
    }
    // �Ҹ���: ��ϵ� ��� ���� ��ü�� �޸𸮿��� ����
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main(void)
{
    // ���� ������ �������� ����� ��Ʈ�� Ŭ������ ��ü ����
    EmployeeHandler handler;

    // ���� ���
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    // �̹� �޿� �����ؾ� �� �޿��� ���� ���
    handler.ShowAllSalaryInfo();

    // �̹� �޿� �����ؾ� �� �� �޿� ���
    handler.ShowTotalSalary();

    return 0;
}
