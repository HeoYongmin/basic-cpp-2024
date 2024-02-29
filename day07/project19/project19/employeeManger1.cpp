#include<iostream>
using namespace std;

class PermanentWorker {
private:
    char name[100];
    int salary;

public:
    PermanentWorker(const char* name, int money) : salary(money) {
        strcpy(this->name, name);
    }

    int GetPay()const {
        return salary;
    }

    void ShowSalaryInfo()const {

        cout << "name : " << name << endl;
        cout << " salary : " << GetPay() << endl << endl;
    }
};

class EmployeeHandler {
private:
    PermanentWorker* empList[50];           // 객체 포인터 배열
    int empNum;

public:
    EmployeeHandler() : empNum(0) {}

    void AddEmployee(PermanentWorker* emp) {        // 정규직 객체를 받아서 empList 배열에 집어넣는다

        empList[empNum++] = emp;
    }

    void ShowAllSalaryInfo() const {
        for (int i = 0; i < empNum; i++) {
            empList[i]->ShowSalaryInfo();           // empList배열의 요소값을 통해서 멤버함수에 접근
        }
    }

    void ShowTotalSalary() const {
        int sum = 0;

        for (int i = 0; i < empNum; i++) {
            sum += empList[i]->GetPay();
        }
        cout << "salary Sum : " << sum << endl;

    }
    ~EmployeeHandler() {

        for (int i = 0; i < empNum; i++) {
            delete empList[i];
        }
    }
};

int main(void) {

    EmployeeHandler handler;


    // 직원 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("Lee", 2000));
    handler.AddEmployee(new PermanentWorker("Hwang", 3000));

    // 이번달에 지불해야할 급여의 정보

    handler.ShowAllSalaryInfo();

    //이번 달에 지불해야할 급여의 총합
    handler.ShowTotalSalary();
    return 0;

}