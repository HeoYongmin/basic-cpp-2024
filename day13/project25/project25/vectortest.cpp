/*
vector ��ü�� �����ϰ� ������ �Է� ���������� ���Ϳ� �����ϰ� ����� ����Ͻÿ�
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	int input;
	double sum = 0;

	while (true){
		cout << "���� �Ѱ� �Է�(0����): ";
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

	cout << "���α׷��� �����մϴ�." << endl;

	
	return 0;
}