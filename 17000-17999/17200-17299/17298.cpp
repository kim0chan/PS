#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	stack<int> st;
	int a[1000001];
	int ans[1000001];
	int N, val;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = N - 1; i > -1; i--) {
		while (!st.empty()) {
			val = st.top();
			if (val > a[i]) { break; }
			st.pop();
		}

		if (st.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = val;
		}

		st.push(a[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}