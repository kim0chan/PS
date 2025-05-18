#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	int ans = 0;

	cin >> N;
	while (N--) {
		string input;
		stack<int> st;

		cin >> input;
		for (auto c : input) {
			if (c == 'A') {
				if (st.empty()) {
					st.push(1);
				}
				else {
					if (st.top() == 2) {
						st.push(1);
					}
					else if (st.top() == 1) {
						st.pop();
					}
				}
			}
			else if (c == 'B') {
				if (st.empty()) {
					st.push(2);
				}
				else {
					if (st.top() == 1) {
						st.push(2);
					}
					else if (st.top() == 2) {
						st.pop();
					}
				}
			}
			else cout << "error\n";
		}

		if (st.empty()) { ans++; }
	}
	cout << ans;
}