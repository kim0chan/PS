#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	vector<int> v;

	int N;
	cin >> N;

	while (N--) {
		int input;
		cin >> input;

		if (binary_search(v.begin(), v.end(), input)) { continue; }
		v.push_back(input);
		sort(v.begin(), v.end());
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';

}