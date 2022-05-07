#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<pair<int, string>> result;
	int n;
	cout << "1000원 미만의 거스름돈을 입력하시오:";
	cin >> n;
	
	result.push_back(pair<int, string>(n / 500, "500원"));
	n %= 500;
	result.push_back(pair<int, string>(n / 100, "100원"));
	n %= 100;
	result.push_back(pair<int, string>(n / 50, "50원"));
	n %= 50;
	result.push_back(pair<int, string>(n / 10, "10원"));
	n %= 10;
	result.push_back(pair<int, string>(n / 1, "1원"));
	cout << "거스름돈은";
	for (auto& tmp : result) {
		cout << tmp.second << tmp.first << "개,";
	}
	cout << "입니다" << endl;

}