/*
char ary[] = {'a', 'b', 'c', 'd', 'e', 'f'};
조건: while문과 if문 만으로 배열 순서를 바꾸어 저장 출력하세요
*/
#include <iostream>
using namespace std;

int main() {
    char ary[] = { 'a', 'b', 'c', 'd', 'e', 'f'};       // 원본 배열 정의
    char result[6];                                     // 결과를 저장할 배열을 정의
    // 결과 배열의 인덱스와 원본 배열의 인덱스를 초기화
    int index = 0;
    int i = 5; 

    // 원본 배열을 역순으로 결과 배열에 저장
    while (i >= 0) {
        if (i < 6) {
        // 결과 배열에 현재 원본 배열의 요소를 저장
        result[index] = ary[i];                 
        // 결과 배열의 다음 인덱스로 이동
        index++;
        }
        // 원본 배열의 다음 인덱스로 이동
        i--;
    }
    cout << "역순 배열 : \n ";
    for (int j = 0; j < 6; j++) {
        cout << result[j] << " " << endl;
    }
    return 0;
}
