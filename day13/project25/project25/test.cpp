/*
char ary[] = {'a', 'b', 'c', 'd', 'e', 'f'};
����: while���� if�� ������ �迭 ������ �ٲپ� ���� ����ϼ���
*/
#include <iostream>
using namespace std;

int main() {
    char ary[] = { 'a', 'b', 'c', 'd', 'e', 'f'};       // ���� �迭 ����
    char result[6];                                     // ����� ������ �迭�� ����
    // ��� �迭�� �ε����� ���� �迭�� �ε����� �ʱ�ȭ
    int index = 0;
    int i = 5; 

    // ���� �迭�� �������� ��� �迭�� ����
    while (i >= 0) {
        if (i < 6) {
        // ��� �迭�� ���� ���� �迭�� ��Ҹ� ����
        result[index] = ary[i];                 
        // ��� �迭�� ���� �ε����� �̵�
        index++;
        }
        // ���� �迭�� ���� �ε����� �̵�
        i--;
    }
    cout << "���� �迭 : \n ";
    for (int j = 0; j < 6; j++) {
        cout << result[j] << " " << endl;
    }
    return 0;
}
