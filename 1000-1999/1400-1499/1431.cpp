#include <bits/stdc++.h>
using namespace std;

vector<string> v;
string input;

bool compare(string& a, string& b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	
	int a_sum = 0, b_sum = 0;
	for (int i = 0; i < a.length(); i++) {
		if (isdigit(a[i])) {
			a_sum += (a[i] - '0');
		}
	}
	for (int i = 0; i < b.length(); i++) {
		if (isdigit(b[i])) {
			b_sum += (b[i] - '0');
		}
	}

	if (a_sum != b_sum) {
		return a_sum < b_sum;
	}

	return a < b;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	while (N--) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end(), compare);

	for (auto a : v) {
		cout << a << '\n';
	}
}
