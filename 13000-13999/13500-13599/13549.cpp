#include <bits/stdc++.h>

using namespace std;

#define pos		first
#define secs	second
#define MAX_ELEM	100001

int visited[100001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> qu;

	visited[N] = 1;
	qu.push({ N, 0 });

	while (!qu.empty()) {
		pair<int, int> cur = qu.front();	qu.pop();
		if (cur.pos == K) { cout << cur.secs; break; }

		int dpos;
		int warp;

		warp = cur.pos * 2;
		while (warp < 100001) {
			if (visited[warp]) break;
			visited[warp] = 1;
			qu.push({ warp, cur.secs });

			warp *= 2;
		}

		dpos = cur.pos + 1;
		if (dpos >= 0 && dpos < MAX_ELEM) {
			if (visited[dpos] == 0) {
				visited[dpos] = 1;
				qu.push({ dpos, cur.secs + 1 });
			}
		}

		dpos = cur.pos - 1;
		if (dpos >= 0 && dpos < MAX_ELEM) {
			if (visited[dpos] == 0) {
				visited[dpos] = 1;
				qu.push({ dpos, cur.secs + 1 });
			}
		}
	}
}