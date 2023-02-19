#include <bits/stdc++.h>

#define X	first
#define Y	second
#define MAX(a, b)	a>b ? a:b

using namespace std;

bool _map[51][51];
int dist[51][51];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int cnt = 0;
	int R, C;
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < C; j++) {
			_map[i][j] = (input[j] == 'L') ? 1 : 0;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (_map[i][j] == 0 || dist[i][j] != 0) { continue; }

			queue<pair<int, int>> qu;
			dist[i][j] = 1;
			qu.push({ i, j });

			while (!qu.empty()) {
				pair<int, int> cur = qu.front();	qu.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx, ny;
					nx = cur.X + dx[dir];
					ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= R || ny < 0 || ny >= C) { continue; }
					if (_map[nx][ny] == 0 || dist[nx][ny] != 0) { continue; }
					dist[nx][ny] = dist[cur.X][cur.Y] + 1;
					qu.push({ nx, ny });
					cnt = MAX(cnt, dist[nx][ny]);
				}
			}
			memset(dist, 0, sizeof(dist));
		}
	}

	cout << cnt-1 << '\n';
}