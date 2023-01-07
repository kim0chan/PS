#include <bits/stdc++.h>

using namespace std;

int visited[1000001];
queue<pair<int, int>> st;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int solve = -1;
	int X;
	cin >> X;

	visited[X] = 1;
	st.push({ X, 0 });

	while (!st.empty()) {
		pair<int, int> cur = st.front();	st.pop();
		if (cur.first == 1) {
			solve = cur.second;
			break;
		}

		if (visited[cur.first - 1] != 1) {
			visited[cur.first - 1] = 1;
			st.push({ cur.first - 1 , cur.second + 1 });
		}

		if (cur.first % 2 == 0) {
			if (visited[cur.first / 2] != 1) {
				visited[cur.first / 2] = 1;
				st.push({ cur.first / 2, cur.second + 1 });
			}
		}

		if (cur.first % 3 == 0) {
			if (visited[cur.first / 3] != 1) {
				visited[cur.first / 3] = 1;
				st.push({ cur.first / 3, cur.second + 1 });
			}
		}
	}

	cout << solve;
}