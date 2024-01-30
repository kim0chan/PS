#include <bits/stdc++.h>

using namespace std;

#define X	first
#define Y	second

int board[301][301];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		int N, cpos_x, cpos_y, dpos_x, dpos_y;
		cin >> N;
		cin >> cpos_x >> cpos_y;
		cin >> dpos_x >> dpos_y;
		
		queue<pair<int, int>> qu;
		board[cpos_x][cpos_y] = 1;
		qu.push({ cpos_x, cpos_y });

		while (!qu.empty()) {
			bool found = false;
			pair<int, int> cur = qu.front();
			qu.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx, ny;
				nx = cur.X + dx[dir];
				ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) { continue; }
				if (board[nx][ny] != 0) { continue; }
				board[nx][ny] = board[cur.X][cur.Y] + 1;
				if (nx == dpos_x && ny == dpos_y) { found = true; break; }
				qu.push({ nx, ny });
			}
			if (found) break;
		}
		while (!qu.empty()) { qu.pop();	}
		cout << board[dpos_x][dpos_y] - 1 << '\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				board[i][j] = 0;
			}
		}
	}
}