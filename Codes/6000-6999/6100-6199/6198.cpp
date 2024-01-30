#include <bits/stdc++.h>
#define ll	long long
using namespace std;

const int MX = 0x7fffffff;
int N;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll ans = 0;

	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[N - 1 - i];
	}

	stack<pair<int, int>> st;
	st.push({ MX, 0 });

	for (int i = 0; i < N; i++) {
		int local = 0;
		while (st.top().first < v[i] && !st.empty()) {
			local += st.top().second;
			st.pop();
		}

		ans += local;
		st.push({ v[i], local + 1 });
	}

	cout << ans << '\n';
}