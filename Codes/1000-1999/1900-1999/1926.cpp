#include <bits/stdc++.h>

using namespace std;

#define X	first
#define Y	second

int _map[501][501];
int visited[501][501];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n, m;
	int pic_count = 0;
	int area_max = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> _map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (_map[i][j] == 0 || visited[i][j] == 1) { continue; }
			queue<pair<int, int>> qu;
			pic_count++;
			int area = 0;
			visited[i][j] = 1;
			qu.push({ i, j });

			while(!qu.empty()) {
				area++;
				pair<int, int> cur = qu.front();	qu.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }
					if (_map[nx][ny] == 0 || visited[nx][ny] == 1) { continue; }
					visited[nx][ny] = 1;
					qu.push({ nx, ny });
				}
			}
			area_max = (area_max > area) ? area_max : area;
		}
	}
	cout << pic_count << '\n' << area_max;
}