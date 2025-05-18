#include <bits/stdc++.h>

using namespace std;

const int INF = 2147483647;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;

	while (T--) {
		vector<pair<int, int>> v;
		int audi_min = INF;
		int cnt = 0;

		int N;
		cin >> N;

		while (N--) {
			int docu, audi;
			cin >> docu >> audi;

			v.push_back({ docu, audi });
		}
		sort(v.rbegin(), v.rend());

		while (!v.empty()) {
			pair<int, int> cur = v.back();	v.pop_back();
			if (cur.second < audi_min) {
				cnt++;
				audi_min = cur.second;
			}
		}

		cout << cnt << '\n';
	}
}