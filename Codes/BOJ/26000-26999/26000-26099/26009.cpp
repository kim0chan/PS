#include <bits/stdc++.h>
#define X	first
#define Y	second
using namespace std;

int dist[3001][3001];
bool visited[3001][3001];
int N, M, K;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void makeObstacle(int R, int C, int D) {
	visited[R][C] = true;
	for (int j = 0; j < D; j++) {
		if (!(R + D - j < 1 || R + D - j > N || C + j < 1 || C + j > M))		visited[R + D - j][C + j] = true;
		if (!(C + D - j < 1 || C + D - j > M || R - j < 1 || R - j > N))		visited[R - j][C + D - j] = true;
		if (!(R - (D - j) < 1 || R - (D - j) > N || C - j < 1 || C - j > M))	visited[R - (D - j)][C - j] = true;
		if (!(C - (D - j) < 1 || C - (D - j) > M || R + j < 1 || R + j > N))	visited[R + j][C - (D - j)] = true;
	}
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	while (K--) {
		int R, C, D;
		cin >> R >> C >> D;
		makeObstacle(R, C, D);
	}

	queue<pair<int, int>> qu;
	qu.push({ 1, 1 });
	dist[1][1] = 1;
	visited[1][1] = true;

	while (!qu.empty()) {
		pair<int, int> cur = qu.front();	qu.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 1 || nx > N || ny < 1 || ny > M)	continue;
			if (visited[nx][ny])						continue;
			qu.push({ nx, ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			visited[nx][ny] = true;
		}
	}

	if (dist[N][M]) {
		cout << "YES\n";
		cout << dist[N][M] - 1 << '\n';
	}
	else {
		cout << "NO\n";
	}
}