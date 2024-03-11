/*
vector 객체를 생성하고 정수를 입력 받을때마다 벡터에 삽입하고 평균을 출력하시오
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int input;
	double sum = 0;

	while (true){
		cout << "정수 한개 입력(0종료): ";
		cin >> input;
		if (!input) {
			break;
		}
		v.push_back(input);
		for (int i = 0; i < v.size(); i++) {
			cout << v.at(i) << endl;
		}
		sum += input;
		cout << sum / v.size() << endl;
	}

	cout << "프로그램을 종료합니다." << endl;

	
	return 0;
}