#include <bits/stdc++.h>
using namespace std;

int board[8][8];
bool visited[8][8];
int N, M;
int walls;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int ans = 0;

	vector<pair<int, int>> startingPoints;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				startingPoints.push_back({ i, j });
			}
			else if (board[i][j] == 1) {
				walls++;
			}
		}
	}

	for (int i = 0; i < N * M - 2; i++) {
		int x1 = i / M;
		int y1 = i % M;
		if (board[x1][y1])	continue;
		for (int j = i + 1; j < N * M - 1; j++) {
			int x2 = j / M;
			int y2 = j % M;
			if (board[x2][y2])	continue;
			for (int k = j + 1; k < N * M; k++) {
				int x3 = k / M;
				int y3 = k % M;
				if (board[x3][y3])	continue;

				board[x1][y1] = 1;
				board[x2][y2] = 1;
				board[x3][y3] = 1;

				int infested = 0;
				queue<pair<int, int>> qu;
				for (pair<int, int> coord : startingPoints) {
					qu.push({ coord.first, coord.second });
					visited[coord.first][coord.second] = true;
				}
				while (!qu.empty()) {
					pair<int, int> cur = qu.front();	qu.pop();
					infested++;

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (visited[nx][ny])	continue;
						if (board[nx][ny])		continue;
						if (nx < 0 || nx >= N || ny < 0 || ny >= M)	continue;

						qu.push({ nx, ny });
						visited[nx][ny] = true;
					}
				}

				ans = max(ans, N * M - walls - 3 - infested);


				board[x1][y1] = 0;
				board[x2][y2] = 0;
				board[x3][y3] = 0;
				for (int i = 0; i < N; i++) {
					memset(visited[i], false, sizeof(bool) * M);
				}
			}
		}
	}


	cout << ans << '\n';
	
}