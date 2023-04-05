#include <bits/stdc++.h>
using namespace std;

struct cmp {
public:
	bool operator() (pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

int N, A, iter, solve;
vector<int> adj[10001];
int duration[10001];
int indegree[10001];


int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> duration[i] >> indegree[i];
		for (int j = 0; j < indegree[i]; j++) {
			cin >> A;
			adj[A].push_back(i);
		}
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	for (int i = 1; i <= N; i++) if (!indegree[i])	pq.push({ i, duration[i] });

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();	pq.pop();
		//cout << cur.first << '\n';
		solve = cur.second;

		for (int next : adj[cur.first]) {
			indegree[next]--;
			if (!indegree[next])	pq.push({ next, duration[next] + cur.second });
		}
	}

	cout << solve << '\n';

}