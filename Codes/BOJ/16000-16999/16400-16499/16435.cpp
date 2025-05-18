#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	vector<int> v;

	int N, L;
	cin >> N >> L;

	while (N--) {
		int input;
		cin >> input;

		v.push_back(input);
	}

	sort(v.rbegin(), v.rend());

	while (!v.empty()) {
		if (L < v.back()) {
			break;
		}

		L++;
		v.pop_back();
	}

	cout << L << '\n';
	
}