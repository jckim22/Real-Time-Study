#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<pair<int, string>> result;
	int n;
	cout << "1000�� �̸��� �Ž������� �Է��Ͻÿ�:";
	cin >> n;
	
	result.push_back(pair<int, string>(n / 500, "500��"));
	n %= 500;
	result.push_back(pair<int, string>(n / 100, "100��"));
	n %= 100;
	result.push_back(pair<int, string>(n / 50, "50��"));
	n %= 50;
	result.push_back(pair<int, string>(n / 10, "10��"));
	n %= 10;
	result.push_back(pair<int, string>(n / 1, "1��"));
	cout << "�Ž�������";
	for (auto& tmp : result) {
		cout << tmp.second << tmp.first << "��,";
	}
	cout << "�Դϴ�" << endl;

}