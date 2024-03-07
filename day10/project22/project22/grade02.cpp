/*
5명의 이름과 국,영,수 3과목을 입력받아 학생별 총점과 평균, 그리고 과목별 총점과 평균을 구하시오.
1. 객체 포인터 배열 사용
2. 객체 배열 사용
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;


class Grade
{
    char* name;               // 포인터를 사용하고 있다
    int ko;
    int eng;
    int math;
public:
    Grade(const char* name, int ko, int eng, int math)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->ko = ko;
        this->eng = eng;
        this->math = math;

    }
    Grade() {
        cout << "생성자 호출" << endl;
 
    }
    ~Grade()
    {
        printf("소멸자 호출\n");
        delete[] name;
    }
    int getko()
    {
        return ko;
    }
    int geteng()
    {
        return eng;
    }
    int getmath()
    {
        return math;
    }
    int sum()
    {
        int sum = ko + eng + math;
        return sum;
    }
    double avr()
    {
        double avr = sum() / 3.0;
        return avr;
    }

};


int main()
{

   // Grade gradeAry[100];            // 객체 배열

    char name[20] = {};
    int inKo;
    int inEng;
    int inMath;
    int kosum = 0;
    int Engsum = 0;
    int Mathsum = 0;
    double koavr = 0;
    double Engavr = 0;
    double Mathavr = 0;
    int num;

    cout << "성적처리 학생수: " << endl;
    cin >> num;

    //vector<Grade*> gradeAry(num);     객체 포인터 배열일 때 사용
    vector<Grade> gradeAry(num);        // 객체 배열일 때 사용

    //1. 입력을 받는다.
    for (int i = 0; i < num; i++)
    {
        cout << "이름 : ";
        cin >> name;
        cout << "국어점수 : ";
        cin >> inKo;
        cout << "영어점수 : ";
        cin >> inEng;
        cout << "수학점수 : ";
        cin >> inMath;

        cout << name << inKo << inEng << inMath << endl;
        //2. 객체생성: 5개의 객체를 생성(2). 객체배열 or 객체 포인터 배열
        gradeAry[i] =  Grade(name, inKo, inEng, inMath);
        kosum = kosum + inKo;
        Engsum = Engsum + inEng;
        Mathsum = Mathsum + inMath;
        koavr = kosum / 3.0;
        Engavr = Engsum / 3.0;
        Mathavr = Mathsum / 3.0;
    }

    for (int i = 0; i < 50; i++)
    {
        //cout << "총점: " << gradeAry[i]->sum() << " 평균:  " << gradeAry[i]->avr() << endl;
        printf("%d째 학생 총점: %d, 평점: %.1lf\n", i + 1, gradeAry[i].sum(), gradeAry[i].avr());
    }

    /*
    for (int i = 0; i < 3; i++)
    {
       kosum = kosum + inKo;
       cout << kosum << endl;
    }
    */
    //printf("국어총점 : %d, 수학총점 : %d, 영어총점 : %d\n", kosum, Engsum, Mathsum);
    cout << "국어총점 : " << kosum << " " << "수학총점 : " << Mathsum << " " << "영어총점 : " << Engsum << " " << endl;
    cout << "국어평균 : " << koavr << " " << "수학평균 : " << Mathavr << " " << "영어평균 : " << Engavr << " " << endl;
    //cout << kosum << endl;
    //cout << gradeAry[1]->getko() << endl;
    
    /* new 있을 때 사용!
    for (int i = 0; i < 3; i++)
    {
        printf("객체 할당 소멸자 호출\n");
        delete [i]gradeAry;
    }
    */
    return 0;
}