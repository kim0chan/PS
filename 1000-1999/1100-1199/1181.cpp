#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else {
		return a.size() < b.size();
	}
}

int main() {
	int N;
	vector<string> v;
	string str;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), compare);

	cout << v[0] << '\n';
	for (int i = 1; i < N; i++) {
		if (v[i].compare(v[i - 1])) {
			cout << v[i] << '\n';
		}
	}

	return 0;
}