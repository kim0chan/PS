#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	deque<int> dq;
	int N, M;
	int ans = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		dq.push_back(i + 1);
	}

	while (M--) {
		int arg;
		cin >> arg;
		int idx;
		idx = find(dq.begin(), dq.end(), arg) - dq.begin();

		while (dq.front() != arg) {
			if (2 * idx < dq.size()) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			ans++;
		}
		dq.pop_front();
	}

	cout << ans;
}