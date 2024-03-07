#include <iostream>
using namespace std;

template <typename T>
T Add(T num1, T num2)
{
    cout << "T Add(T num1, T num2)" << endl;
    return num1 + num2;
}

int Add(int num1, int num2)
{
    cout << "Add(int num1, int num2)" << endl;
    return num1 + num2;
}

double Add(double num1, double num2)
{
    cout << "Add(double num1, double num2)" << endl;
    return num1 + num2;
}

int main(void)
{
    cout << Add(5, 7) << endl; // int 타입의 Add(int, int) 호출
    cout << Add(3.7, 7.5) << endl; // double 타입의 Add(double, double) 호출
    cout << Add<int>(5, 7) << endl; // 템플릿 함수인 T Add(T, T) 호출
    cout << Add<double>(3.7, 7.5) << endl; // 템플릿 함수인 T Add(T, T) 호출
    return 0;
}
