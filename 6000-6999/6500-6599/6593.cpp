#include <bits/stdc++.h>
#define X	first
#define Y	second
using namespace std;

int L, R, C;
int board[31][31][31];
int dist[31][31][31];
int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> L >> R >> C;
		if (!(L + R + C))	break;

		for (int floor = 0; floor < L; floor++) {
			for (int row = 0; row < R; row++) {
				fill(board[floor][row], board[floor][row] + C, 0);
				fill(dist[floor][row], dist[floor][row] + C, 0);
			}
		}

		int st_z, st_x, st_y;
		int en_z, en_x, en_y;

		for (int floor = 0; floor < L; floor++) {
			for (int row = 0; row < R; row++) {
				for (int col = 0; col < C; col++) {
					char input;
					cin >> input;
					if (input == '#') {
						board[floor][row][col] = 1;
						continue;
					}

					if (input == 'S') {
						st_z = floor;
						st_x = row;
						st_y = col;
					}
					if (input == 'E') {
						en_z = floor;
						en_x = row;
						en_y = col;
					}
				}
			}
		}

		queue<tuple<int, int, int>> qu;
		qu.push({ st_z, st_x, st_y });
		dist[st_z][st_x][st_y] = 1;
		while (!qu.empty()) {
			int cur_z, cur_x, cur_y;
			tie(cur_z, cur_x, cur_y) = qu.front();	qu.pop();

			for (int dir = 0; dir < 6; dir++) {
				int nxt_z = cur_z + dz[dir];
				int nxt_x = cur_x + dx[dir];
				int nxt_y = cur_y + dy[dir];
				if (nxt_z < 0 || nxt_x < 0 || nxt_y < 0 ||
					nxt_z >= L || nxt_x >= R || nxt_y >= C)	continue;
				if (board[nxt_z][nxt_x][nxt_y] || dist[nxt_z][nxt_x][nxt_y])	continue;
				qu.push({ nxt_z, nxt_x, nxt_y });
				dist[nxt_z][nxt_x][nxt_y] = dist[cur_z][cur_x][cur_y] + 1;
			}
		}

		if (!dist[en_z][en_x][en_y]) {
			cout << "Trapped!\n";
			continue;
		}
		cout << "Escaped in " << dist[en_z][en_x][en_y] - 1 << " minute(s).\n";

	}
}