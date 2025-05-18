#include <bits/stdc++.h>
using namespace std;

int T, N, K, A, B, W;
int duration[1001], indegree[1001];
vector<int> adj[1001];

class cmp {
public:
	bool operator() (pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> T;
	while (T--) {
		memset(duration, 0, sizeof(duration));
		memset(indegree, 0, sizeof(indegree));
		for (int i = 0; i < 1001; i++) {
			adj[i].clear();
		}

		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> duration[i];
		}
		for (int i = 0; i < K; i++) {
			cin >> A >> B;
			adj[A].push_back(B);
			indegree[B]++;
		}
		cin >> W;

		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
		for (int i = 1; i <= N; i++) {
			if (!indegree[i])	pq.push({ i, duration[i] });
		}

		while (!pq.empty()) {
			pair<int, int> cur = pq.top();	pq.pop();
			if (cur.first == W) {
				cout << cur.second << '\n';
				break;
			}

			for (int next : adj[cur.first]) {
				indegree[next]--;
				if (!indegree[next]) {
					pq.push({ next, cur.second + duration[next] });
				}
			}
		}
	}
}
