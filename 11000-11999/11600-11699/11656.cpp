#include <bits/stdc++.h>
using namespace std;

string input;
vector<string> v;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> input;
	for (int i = 0; i < (int)input.length(); i++) {
		string temp = input.substr(i);
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	for (auto e : v) {
		cout << e << '\n';
	}
}