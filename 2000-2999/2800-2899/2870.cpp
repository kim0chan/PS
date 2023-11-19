#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool cmp(string& a, string& b) {
	if (a.size() != b.size())	return a.size() < b.size();
	return a < b;
}

int main(void) {
	cin >> N;
	vector<string> ans;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		string temp = "";
		for (char c : input) {
			if (isdigit(c)) {
				temp += c;
			}
			else {
				if (temp.empty())	continue;
				while (temp.size() > 1 && temp[0] == '0') {
					temp.erase(0, 1);
				}
				ans.push_back(temp);
				temp = "";
			}
		}
		if (!temp.empty()) {
			while (temp.size() > 1 && temp[0] == '0') {
				temp.erase(0, 1);
			}
			ans.push_back(temp);
		}
	}

	sort(ans.begin(), ans.end(), cmp);
	for (string e : ans) {
		cout << e << '\n';
	}
}
