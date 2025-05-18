#include <bits/stdc++.h>
using namespace std;

const int time_limit = 60 * 24;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	int N;
	cin >> N;
	priority_queue<int> pq;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		pq.push(input);
	}

	while (!pq.empty()) {
		ans++;
		if (ans > time_limit) {
			ans = -1;
			break;
		}

		int cur = pq.top();	pq.pop();
		if (!pq.empty()) {
			int pair = pq.top();	pq.pop();
			--pair;
			if (pair)	pq.push(pair);
		}
		--cur;
		if (cur)	pq.push(cur);
	}

	cout << ans << '\n';

}