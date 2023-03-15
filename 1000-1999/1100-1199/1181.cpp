#include <bits/stdc++.h>
using namespace std;

int N;
string input;
vector<string> v;

bool compare(string& a, string& b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	
	return a < b;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	while (N--) {
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end(), compare);
	
	cout << v[0] << '\n';
	for (int i = 1; i < v.size(); i++) {
		if (v[i].compare(v[i - 1])) {
			cout << v[i] << '\n';
		}
	}
}