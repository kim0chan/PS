#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string ans;
	stack<int> st;
	int n, cur;

	cur = 1;
	cin >> n;
	while (n--) {
		int arg;
		cin >> arg;

		while (cur <= arg) {
			st.push(cur);
			ans += '+';
			cur++;
		}

		if (!st.empty()) {
			int pop = st.top();
			st.pop();
			ans += '-';

			if (pop != arg) {
				cout << "NO";
				return 0;
			}
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	for (auto x : ans) {
		cout << x << '\n';
	}
	return 0;
}