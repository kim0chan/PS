#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, M;
int dist[101][101];
bool board[101][101];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		string input;
		cin >> input;
		for (int j = 1; j <= M; j++) {
			board[i][j] = input[j - 1] - '0';
		}
	}
	for (int i = 1; i <= N; i++) {
		fill(dist[i], dist[i] + M + 1, INF);
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	dist[1][1] = 0;
	pq.push({ 0, 1, 1 });
	while (!pq.empty()) {
		int cur_cost, cur_xpos, cur_ypos;
		tie(cur_cost, cur_xpos, cur_ypos) = pq.top();	pq.pop();
		if (cur_cost != dist[cur_xpos][cur_ypos])	continue;

		for (int dir = 0; dir < 4; dir++) {
			int new_xpos = cur_xpos + dx[dir];
			int new_ypos = cur_ypos + dy[dir];
			if (new_xpos < 1 || new_xpos > N || new_ypos < 1 || new_ypos > M)	continue;
			int new_cost = cur_cost + board[new_xpos][new_ypos];
			if (new_cost >= dist[new_xpos][new_ypos])	continue;
			dist[new_xpos][new_ypos] = new_cost;
			pq.push({ new_cost, new_xpos, new_ypos });
		}
	}

	cout << dist[N][M] << '\n';
}