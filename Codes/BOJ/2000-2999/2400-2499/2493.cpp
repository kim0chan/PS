#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	stack<pair<int, int>> st;
	int N;
	int i = 0;

	cin >> N;
	st.push({ 100000001, 0 });

	for (int i = 0; i < N; i++) {
		int height;
		cin >> height;

		while (st.top().first < height) {
			st.pop();
		}
		cout << st.top().second << ' ';
		st.push({ height, i + 1 });
	}

	return 0;
}