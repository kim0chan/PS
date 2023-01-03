#include <bits/stdc++.h>

using namespace std;

#define X	first
#define Y	second

int game_map[101][101];
int visited[101][101];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

queue<pair<int, int>> qu;
vector<int> sizesize;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int M, N, K;
	int count = 0;

	cin >> M >> N >> K;

	while (K--) {
		int left_x, left_y, right_x, right_y;
		cin >> left_x >> left_y >> right_x >> right_y;

		for (int i = left_x; i < right_x; i++) {
			for (int j = left_y; j < right_y; j++) {
				game_map[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int auswjr = 0;
			if (visited[i][j] == 1 || game_map[i][j] == 1) { continue; }
			visited[i][j] = 1;
			qu.push({ i, j });
			count++;

			while (!qu.empty()) {
				pair<int, int> cur = qu.front();	qu.pop();
				auswjr++;

				for (int dir = 0; dir < 4; dir++) {
					int nx, ny;
					nx = cur.X + dx[dir];
					ny = cur.Y + dy[dir];

					if (nx < 0 || ny < 0 || nx >= M || ny >= N) { continue; }
					if (visited[nx][ny] == 1 || game_map[nx][ny] == 1) { continue; }
					visited[nx][ny] = 1;
					qu.push({ nx, ny });
				}
			}
			sizesize.push_back(auswjr);
		}
	}
	cout << count << '\n';
	sort(sizesize.begin(), sizesize.end());

	for (auto c : sizesize) {
		cout << c << ' ';
	}
}