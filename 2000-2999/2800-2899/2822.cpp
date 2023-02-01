#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	priority_queue<pair<int, int>> pq;

	for (int i = 1; i <= 8; i++) {
		int input;
		cin >> input;

		pq.push({ input, i });
	}

	int sum = 0;
	int ans[5];

	for (int i = 0; i < 5; i++) {
		pair<int, int> cur;
		cur = pq.top();	pq.pop();
		sum += cur.first;
		ans[i] = cur.second;
	}

	cout << sum << '\n';
	sort(ans, ans + 5);
	for (int i = 0; i < 5; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}