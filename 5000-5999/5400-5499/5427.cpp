#include <bits/stdc++.h>

using namespace std;

#define X	first
#define Y	second

string building[1001];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int fire_map[1001][1001];
int geun_map[1001][1001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;

	while (T--) {
		int w, h;
		int gx, gy;
		bool found = false;
		queue<pair<int, int>> qu;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			cin >> building[i];
			for (int j = 0; j < w; j++) {
				if (building[i][j] == '*') {
					fire_map[i][j] = 1;
					qu.push({ i, j });
				}
				if (building[i][j] == '@') {
					gx = i;
					gy = j;
				}
			}
		}
		while (!qu.empty()) {
			pair<int, int> cur = qu.front(); qu.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx, ny;
				nx = cur.X + dx[dir];
				ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) { continue; }
				if (building[nx][ny] == '#' || fire_map[nx][ny] != 0) { continue; }
				fire_map[nx][ny] = fire_map[cur.X][cur.Y] + 1;
				qu.push({ nx, ny });
			}
		}
		geun_map[gx][gy] = 1;
		qu.push({ gx, gy });

		while (!qu.empty()) {
			pair<int, int> cur = qu.front(); qu.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx, ny;
				nx = cur.X + dx[dir];
				ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					cout << geun_map[cur.X][cur.Y] << '\n';
					found = true;
					break;
				}
				if (building[nx][ny] == '#' || (fire_map[nx][ny] != 0 ) && (fire_map[nx][ny] <= geun_map[cur.X][cur.Y] + 1) || geun_map[nx][ny] != 0) { continue; }
				geun_map[nx][ny] = geun_map[cur.X][cur.Y] + 1;
				qu.push({ nx, ny });
			}
			if (found) break;
		}
		while (!qu.empty()) { qu.pop(); }
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				geun_map[i][j] = 0;
				fire_map[i][j] = 0;
			}
		}
		if (!found) { cout << "IMPOSSIBLE\n"; }
	}

}