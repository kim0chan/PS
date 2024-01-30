#include<bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;

	while (T--) {
		string input;
		cin >> input;
		stack<int> st;
		bool valid = true;

		for (auto c : input) {
			if (c == '(') {
				st.push(1);
			}
			else if (c == ')') {
				if (st.empty()) {
					valid = false;
					break;
				}
				else {
					st.pop();
				}
			}
		}
		if (!st.empty()) valid = false;

		if (valid) cout << "YES\n";
		else cout << "NO\n";
	}
}