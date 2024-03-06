/*
5명의 이름과 국,영,수 3과목을 입력받아 학생별 총점과 평균, 그리고 과목별 총점과 평균을 구하시오
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

    // 학생 정보 입력받기
    for (int i = 0; i < numStudents; ++i)
    {
        char name[100];
        int kr, math, english;

        cout << i + 1 << "번째 학생 이름 입력: ";
        cin >> name;
        cout << "국어 점수 입력: ";
        cin >> kr;
        cout << "수학 점수 입력: ";
        cin >> math;
        cout << "영어 점수 입력: ";
        cin >> english;

        students[i] = Grade(name, kr, math, english);
    }

    // 학생별 총점과 평균 출력
    cout << "=== 학생별 총점과 평균 ===" << endl;
    for (int i = 0; i < numStudents; ++i)
    {
        cout << students[i].getName() << "의 총점: " << students[i].getTotal() << ", 평균: " << students[i].getAverage() << endl;
    }

    // 과목별 총점과 평균 계산
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

    // 과목별 총점과 평균 출력
    cout << "=== 과목별 총점과 평균 ===" << endl;
    cout << "국어 총점: " << totalKr << ", 평균: " << avgKr << endl;
    cout << "수학 총점: " << totalMath << ", 평균: " << avgMath << endl;
    cout << "영어 총점: " << totalEnglish << ", 평균: " << avgEnglish << endl;

    return 0;
}

