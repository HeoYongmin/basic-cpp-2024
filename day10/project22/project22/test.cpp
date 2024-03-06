/*
5���� �̸��� ��,��,�� 3������ �Է¹޾� �л��� ������ ���, �׸��� ���� ������ ����� ���Ͻÿ�
*/
#include <iostream>
#include <cstring>
using namespace std;

class Grade
{
private:
    char* name;
    int kr;
    int math;
    int english;

public:
    Grade() : name(nullptr), kr(0), math(0), english(0) {}
    Grade(const char* n, int k, int m, int e) : kr(k), math(m), english(e)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    ~Grade()
    {
        delete[] name;
    }

    int getTotal() const { return kr + math + english; }

    double getAverage() const { return getTotal() / 3.0; }

    const char* getName() const { return name; }

    int getKorean() const { return kr; }
    int getMath() const { return math; }
    int getEnglish() const { return english; }
};

int main()
{
    const int numStudents = 5;
    Grade students[numStudents];

    // �л� ���� �Է¹ޱ�
    for (int i = 0; i < numStudents; ++i)
    {
        char name[100];
        int kr, math, english;

        cout << i + 1 << "��° �л� �̸� �Է�: ";
        cin >> name;
        cout << "���� ���� �Է�: ";
        cin >> kr;
        cout << "���� ���� �Է�: ";
        cin >> math;
        cout << "���� ���� �Է�: ";
        cin >> english;

        students[i] = Grade(name, kr, math, english);
    }

    // �л��� ������ ��� ���
    cout << "=== �л��� ������ ��� ===" << endl;
    for (int i = 0; i < numStudents; ++i)
    {
        cout << students[i].getName() << "�� ����: " << students[i].getTotal() << ", ���: " << students[i].getAverage() << endl;
    }

    // ���� ������ ��� ���
    int totalKr = 0, totalMath = 0, totalEnglish = 0;
    for (int i = 0; i < numStudents; ++i)
    {
        totalKr += students[i].getKorean();
        totalMath += students[i].getMath();
        totalEnglish += students[i].getEnglish();
    }
    double avgKr = static_cast<double>(totalKr) / numStudents;
    double avgMath = static_cast<double>(totalMath) / numStudents;
    double avgEnglish = static_cast<double>(totalEnglish) / numStudents;

    // ���� ������ ��� ���
    cout << "=== ���� ������ ��� ===" << endl;
    cout << "���� ����: " << totalKr << ", ���: " << avgKr << endl;
    cout << "���� ����: " << totalMath << ", ���: " << avgMath << endl;
    cout << "���� ����: " << totalEnglish << ", ���: " << avgEnglish << endl;

    return 0;
}

