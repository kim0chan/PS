#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].second >> v[i].first;
	}

	sort(v.begin(), v.end());

	for (auto e : v) {
		cout << e.second << ' ' << e.first << '\n';
	}
}