#include <bits/stdc++.h>

using namespace std;

#define X	first
#define Y	second
int box[1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int M, N;
	queue<pair<int, int>> qu;
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				qu.push({ i, j });
			}
		}
	}

	while (!qu.empty()) {
		pair<int, int> cur = qu.front();
		qu.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) { continue; }
			if (box[nx][ny] != 0) { continue; }
			box[nx][ny] = box[cur.X][cur.Y] + 1;
			qu.push({ nx, ny });
		}
	}

	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) { cout << -1; return 0; }
			max = (max > box[i][j]) ? max : box[i][j];
		}
	}

	cout << max - 1;
}