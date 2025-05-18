#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	bool isConsistent = true;
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<string> vec;
		while (n--) {
			string input;
			cin >> input;
			vec.push_back(input);
		}

		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size() - 1; i++) {
			string cur = vec[i];
			string next = vec[i + 1];
			if (cur == next.substr(0, cur.length())) {
				isConsistent = false;
				break;
			}
		}
		if (isConsistent) { cout << "YES\n"; }
		else { cout << "NO\n"; }
		isConsistent = true;
	}
}