#include <bits/stdc++.h>

using namespace std;

#define X	first
#define Y	second

int field[51][51];
int visited[51][51];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T, M, N, K;
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		while (K--) {
			int xpos, ypos;
			cin >> ypos >> xpos;
			field[xpos][ypos] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (field[i][j] == 0 || visited[i][j] == 1) { continue; }
				queue<pair<int, int>> qu;
				cnt++;
				visited[i][j] = 1;
				qu.push({ i, j });

				while (!qu.empty()) {
					pair<int, int> cur = qu.front();
					qu.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx, ny;
						nx = cur.X + dx[dir];
						ny = cur.Y + dy[dir];
						if (nx < 0 || ny < 0 || nx >= N || ny >= M) { continue; }
						if (field[nx][ny] == 0 || visited[nx][ny] == 1) { continue; }
						visited[nx][ny] = 1;
						qu.push({ nx, ny });
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				field[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		cout << cnt << '\n';
	}
}