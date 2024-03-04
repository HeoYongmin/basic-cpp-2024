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

class TemporaryWorker : public Employee
{
private:
    int workTime; // �� �޿� ���� �ð��� �հ�
    int payPerHour; // �ð��� �޿�
public:
    TemporaryWorker(const char* name, int pay)
        : Employee(name), workTime(0), payPerHour(pay)
    { }
    void AddWorkTime(int time)  // ���� �ð��� �߰�
    {
        workTime += time;
    }
    int GetPay() const // �� ���� �޿�
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
    int salesResult;  // �� �ǸŽ���
    double bonusRatio;  // �󿩱� ����
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
        cout << "SalesWorker" << endl;          // �������̵��� ����Լ��� �ڽİ��� ����ȴ�.
        return PermanentWorker::GetPay()        // ���� �����ǵ� �θ���� ȣ���ҷ��� PermanentWorker(�θ�)�� GetPay �Լ� ȣ��
            + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary:" << GetPay() << endl << endl;      // SalesWorker�� GetPay �Լ��� ȣ��
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
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    // ��ϵ� ��� ������ �� ������ ����ϴ� �Լ�
    void ShowTotalSalary() const
    {
        int sum = 0; // �� ������ �����ϴ� ���� �ʱ�ȭ
        // ��ϵ� ��� ������ ������ ����
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
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
    // ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü ����
    EmployeeHandler handler;

    // ���� ���
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    // �ӽ��� ���
    TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);   // 5�ð� ���Ѱ�� ���
    handler.AddEmployee(alba);

    // ������ ���
    SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);       // �������� 7000
    handler.AddEmployee(seller);

    // �̹� �޿� �����ؾ� �� �޿��� ����
    handler.ShowAllSalaryInfo();

    // �̹� �޿� �����ؾ� �� �޿��� ����
    handler.ShowTotalSalary();
    return 0;
}