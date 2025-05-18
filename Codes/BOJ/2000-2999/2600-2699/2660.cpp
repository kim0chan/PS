#include <bits/stdc++.h>
using namespace std;

int N, A, B;
vector<int> adj[51];
int visited[51];
int score[51];

int BFS(int V) {
	queue<int> qu;
	qu.push(V);
	visited[V] = 1;
	int max = 1;

	while (!qu.empty()) {
		int cur = qu.front();	qu.pop();
		max = visited[cur];

		for (auto next : adj[cur]) {
			if (visited[next])	continue;
			visited[next] = visited[cur] + 1;
			qu.push(next);
		}
	}
	
	return max - 1;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int min_score = 0x7fffffff;
	int count = 0;
	vector<int> solve;
	cin >> N;
	while (1) {
		cin >> A >> B;
		if (A == -1 && B == -1)	break;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	for (int i = 1; i <= N; i++) {
		score[i] = BFS(i);
		min_score = min(min_score, score[i]);
		fill(visited + 1, visited + N + 1, 0);
	}
	
	for (int i = 1; i <= N; i++) {
		if (score[i] == min_score) {
			count++;
			solve.push_back(i);
		}
	}

	cout << min_score << ' ' << count << '\n';
	for (auto elem : solve) {
		cout << elem << ' ';
	}
	cout << '\n';
}